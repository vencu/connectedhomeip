/*
 *
 *    Copyright (c) 2021 Project CHIP Authors
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#include "ota-requestor.h"

#include <app/server/Server.h>
#include <app/util/util.h>
#include <lib/core/CHIPEncoding.h>
#include <platform/CHIPDeviceLayer.h>

#include "BDXDownloader.h"

#include <controller/CHIPDeviceControllerFactory.h>
#include <controller/CommissioneeDeviceProxy.h>
#include <controller/ExampleOperationalCredentialsIssuer.h>

#include <zap-generated/CHIPClientCallbacks.h>
#include <zap-generated/CHIPClusters.h>

using chip::ByteSpan;
using chip::CASESessionManager;
using chip::CASESessionManagerConfig;
using chip::CharSpan;
using chip::DeviceProxy;
using chip::EndpointId;
using chip::FabricIndex;
using chip::FabricInfo;
using chip::NodeId;
using chip::OnDeviceConnected;
using chip::OnDeviceConnectionFailure;
using chip::PeerId;
using chip::Server;
using chip::VendorId;
using chip::bdx::TransferSession;
using chip::Callback::Callback;
using chip::System::Layer;
using chip::Transport::PeerAddress;
// using namespace chip::ArgParser;
using namespace chip::Messaging;
using namespace chip::app::Clusters::OtaSoftwareUpdateProvider::Commands;

// Global instance of the OTARequestorInterface.
OTARequestorInterface * globalOTARequestorInstance = nullptr;

constexpr uint32_t kImmediateStartDelayMs = 1; // Start the timer with this value when starting OTA "immediately"

constexpr uint8_t kNodeIdHexStringMaxLen = 16;
// Callbacks for connection management
void OnConnected(void * context, chip::DeviceProxy * deviceProxy);
Callback<OnDeviceConnected> mOnConnectedCallback(OnConnected, nullptr);

void OnConnectionFailure(void * context, NodeId deviceId, CHIP_ERROR error);
Callback<OnDeviceConnectionFailure> mOnConnectionFailureCallback(OnConnectionFailure, nullptr);

void OnQueryImageResponse(void * context, const QueryImageResponse::DecodableType & response);
void OnQueryImageFailure(void * context, EmberAfStatus status);

void SetRequestorInstance(OTARequestorInterface * instance)
{
    globalOTARequestorInstance = instance;
}

OTARequestorInterface * GetRequestorInstance()
{
    return globalOTARequestorInstance;
}

void StartDelayTimerHandler(chip::System::Layer * systemLayer, void * appState)
{
    VerifyOrReturn(appState != nullptr);
    static_cast<OTARequestor *>(appState)->ConnectToProvider();
}

void OnQueryImageFailure(void * context, EmberAfStatus status)
{
    ChipLogDetail(SoftwareUpdate, "QueryImage failure response %" PRIu8, status);
}

void OnConnectionFailure(void * context, NodeId deviceId, CHIP_ERROR error)
{
    ChipLogError(SoftwareUpdate, "failed to connect to 0x%" PRIX64 ": %" CHIP_ERROR_FORMAT, deviceId, error.Format());
}
// Finds the Requestor instance and calls the corresponding OTARequestor member function
void OnQueryImageResponse(void * context, const QueryImageResponse::DecodableType & response)
{
    OTARequestor * requestorCore = static_cast<OTARequestor *>(GetRequestorInstance());

    assert(requestorCore != nullptr);

    requestorCore->mOnQueryImageResponse(context, response);
}

void OTARequestor::mOnQueryImageResponse(void * context, const QueryImageResponse::DecodableType & response)
{
    ChipLogDetail(SoftwareUpdate, "QueryImageResponse responded with action %" PRIu8, response.status);
    ChipLogDetail(SoftwareUpdate, "  status: %" PRIu8 "", response.status);
    if (response.delayedActionTime.HasValue())
    {
        ChipLogDetail(SoftwareUpdate, "  delayedActionTime: %" PRIu32 "", response.delayedActionTime.Value());
    }
    if (response.imageURI.HasValue())
    {
        ChipLogDetail(SoftwareUpdate, "  imageURI: %.*s", static_cast<int>(response.imageURI.Value().size()),
                      response.imageURI.Value().data());
    }
    if (response.softwareVersion.HasValue())
    {
        ChipLogDetail(SoftwareUpdate, "  softwareVersion: %" PRIu32 "", response.softwareVersion.Value());
    }
    if (response.softwareVersionString.HasValue())
    {
        ChipLogDetail(SoftwareUpdate, "  softwareVersionString: %.*s",
                      static_cast<int>(response.softwareVersionString.Value().size()),
                      response.softwareVersionString.Value().data());
    }
    if (response.updateToken.HasValue())
    {
        ChipLogDetail(SoftwareUpdate, "  updateToken: %zu", response.updateToken.Value().size());
    }
    if (response.userConsentNeeded.HasValue())
    {
        ChipLogDetail(SoftwareUpdate, "  userConsentNeeded: %d", response.userConsentNeeded.Value());
    }
    if (response.metadataForRequestor.HasValue())
    {
        ChipLogDetail(SoftwareUpdate, "  metadataForRequestor: %zu", response.metadataForRequestor.Value().size());
    }

    // Parse out the provider node ID from the ImageURI
    NodeId nodeId = chip::kUndefinedNodeId;
    if (response.imageURI.HasValue())
    {
        CharSpan nodeIdString = response.imageURI.Value().SubSpan(6, kNodeIdHexStringMaxLen);

        uint8_t buffer[kNodeIdHexStringMaxLen];
        if (chip::Encoding::HexToBytes(nodeIdString.data(), nodeIdString.size(), buffer, kNodeIdHexStringMaxLen) == 0)
        {
            ChipLogError(SoftwareUpdate, "Cannot convert provider Node ID: %.*s", static_cast<int>(nodeIdString.size()),
                         nodeIdString.data());
            return;
        }

        nodeId = chip::Encoding::BigEndian::Get64(buffer);
    }

    // Use the same CSM from sending of QueryImage based on the assumption that the provider node ID that will supply the OTA image
    // is on the same fabric as the sender of the QueryImageResponse
    if (mCASESessionManager != nullptr)
    {
        // Establish a CASE session with the parsed node ID to obtain exchange context and session handle for BDX transfer
        onConnectedState = kStartBDX;
        CHIP_ERROR err = mCASESessionManager->FindOrEstablishSession(nodeId, &mOnConnectedCallback, &mOnConnectionFailureCallback);
        if (err != CHIP_NO_ERROR)
        {
            ChipLogError(SoftwareUpdate, "Cannot establish connection to peer device: %" CHIP_ERROR_FORMAT, err.Format());
        }
    }
}

EmberAfStatus OTARequestor::HandleAnnounceOTAProvider(
    chip::app::CommandHandler * commandObj, const chip::app::ConcreteCommandPath & commandPath,
    const chip::app::Clusters::OtaSoftwareUpdateRequestor::Commands::AnnounceOtaProvider::DecodableType & commandData)
{
    auto & providerLocation   = commandData.providerLocation;
    auto & announcementReason = commandData.announcementReason;

    if (commandObj == nullptr || commandObj->GetExchangeContext() == nullptr)
    {
        ChipLogError(SoftwareUpdate, "Cannot access ExchangeContext for FabricIndex");
        return EMBER_ZCL_STATUS_INVALID_ARGUMENT;
    }

    mProviderNodeId      = providerLocation;
    mProviderFabricIndex = commandObj->GetExchangeContext()->GetSessionHandle().GetFabricIndex();

    ChipLogProgress(SoftwareUpdate, "OTA Requestor received AnnounceOTAProvider");
    ChipLogDetail(SoftwareUpdate, "  FabricIndex: %" PRIu8, mProviderFabricIndex);
    ChipLogDetail(SoftwareUpdate, "  ProviderNodeID: 0x" ChipLogFormatX64, ChipLogValueX64(mProviderNodeId));
    ChipLogDetail(SoftwareUpdate, "  VendorID: 0x%" PRIx16, commandData.vendorId);
    ChipLogDetail(SoftwareUpdate, "  AnnouncementReason: %" PRIu8, announcementReason);
    if (commandData.metadataForNode.HasValue())
    {
        ChipLogDetail(SoftwareUpdate, "  MetadataForNode: %zu", commandData.metadataForNode.Value().size());
    }

    // If reason is URGENT_UPDATE_AVAILABLE, we start OTA immediately. Otherwise, respect the timer value set in mOtaStartDelayMs.
    // This is done to exemplify what a real-world OTA Requestor might do while also being configurable enough to use as a test app.
    uint32_t msToStart = 0;
    switch (announcementReason)
    {
    case static_cast<uint8_t>(EMBER_ZCL_OTA_ANNOUNCEMENT_REASON_SIMPLE_ANNOUNCEMENT):
    case static_cast<uint8_t>(EMBER_ZCL_OTA_ANNOUNCEMENT_REASON_UPDATE_AVAILABLE):
        msToStart = mOtaStartDelayMs;
        break;
    case static_cast<uint8_t>(EMBER_ZCL_OTA_ANNOUNCEMENT_REASON_URGENT_UPDATE_AVAILABLE):
        msToStart = kImmediateStartDelayMs;
        break;
    default:
        ChipLogError(SoftwareUpdate, "Unexpected announcementReason: %" PRIu8, static_cast<uint8_t>(announcementReason));
        return EMBER_ZCL_STATUS_INVALID_ARGUMENT;
    }

    chip::DeviceLayer::SystemLayer().StartTimer(chip::System::Clock::Milliseconds32(msToStart), StartDelayTimerHandler, this);

    return EMBER_ZCL_STATUS_SUCCESS;
}

CHIP_ERROR OTARequestor::SetupCASESessionManager(chip::FabricIndex fabricIndex)
{
    // A previous CASE session had been established
    if (mCASESessionManager != nullptr)
    {
        if (mCASESessionManager->GetFabricInfo()->GetFabricIndex() != fabricIndex)
        {
            // CSM is per fabric so if fabric index does not match the previous session, CSM needs to be set up again
            chip::Platform::Delete(mCASESessionManager);
            mCASESessionManager = nullptr;
        }
        else
        {
            // Fabric index matches so use previous instance
            return CHIP_NO_ERROR;
        }
    }

    // CSM has not been setup so create a new instance of it
    if (mCASESessionManager == nullptr)
    {
        chip::Server * server         = &(chip::Server::GetInstance());
        chip::FabricInfo * fabricInfo = server->GetFabricTable().FindFabricWithIndex(fabricIndex);
        if (fabricInfo == nullptr)
        {
            ChipLogError(SoftwareUpdate, "Did not find fabric for index %d", fabricIndex);
            return CHIP_ERROR_INVALID_ARGUMENT;
        }

        chip::DeviceProxyInitParams initParams = {
            .sessionManager = &(server->GetSecureSessionManager()),
            .exchangeMgr    = &(server->GetExchangeManager()),
            .idAllocator    = &(server->GetSessionIDAllocator()),
            .fabricInfo     = fabricInfo,
            // TODO: Determine where this should be instantiated
            .imDelegate = chip::Platform::New<chip::Controller::DeviceControllerInteractionModelDelegate>(),
        };

        chip::CASESessionManagerConfig sessionManagerConfig = {
            .sessionInitParams = initParams,
            .dnsCache          = nullptr,
        };

        mCASESessionManager = chip::Platform::New<chip::CASESessionManager>(sessionManagerConfig);
    }

    if (mCASESessionManager == nullptr)
    {
        ChipLogError(SoftwareUpdate, "Failed in creating an instance of CASESessionManager");
        return CHIP_ERROR_NO_MEMORY;
    }

    return CHIP_NO_ERROR;
}

// Converted from SendQueryImageCommand(). Uses code from https://github.com/project-chip/connectedhomeip/pull/12013
void OTARequestor::ConnectToProvider()
{
    chip::NodeId peerNodeId           = mProviderNodeId;
    chip::FabricIndex peerFabricIndex = mProviderFabricIndex;

    CHIP_ERROR err = SetupCASESessionManager(peerFabricIndex);
    if (err != CHIP_NO_ERROR)
    {
        ChipLogError(SoftwareUpdate, "Cannot send QueryImage command without CASESessionManager: %" CHIP_ERROR_FORMAT,
                     err.Format());
    }

    onConnectedState = kQueryImage;
    err = mCASESessionManager->FindOrEstablishSession(peerNodeId, &mOnConnectedCallback, &mOnConnectionFailureCallback);
    if (err != CHIP_NO_ERROR)
    {
        ChipLogError(SoftwareUpdate, "Cannot establish connection to peer device: %" CHIP_ERROR_FORMAT, err.Format());
    }

    // Old ConnectToProvider(). Delete

    // if (mConnectToProviderCallback != nullptr)
    // {
    //     ChipLogProgress(SoftwareUpdate, "Attempting to connect to 0x" ChipLogFormatX64 " on FabricIndex 0x%" PRIu8,
    //                     ChipLogValueX64(mProviderNodeId), mProviderFabricIndex);

    //     mConnectToProviderCallback(mProviderNodeId, mProviderFabricIndex);
    // }
    // else
    // {
    //     ChipLogError(SoftwareUpdate, "ConnectToProviderCallback is not set");
    // }
}

// Called whenever FindOrEstablishSession is successful. Finds the Requestor instance
// and calls the corresponding OTARequestor member function
void OnConnected(void * context, chip::DeviceProxy * deviceProxy)
{
    OTARequestor * requestorCore = static_cast<OTARequestor *>(GetRequestorInstance());

    assert(requestorCore != nullptr);

    requestorCore->mOnConnected(context, deviceProxy);
}

// Member function called whenever FindOrEstablishSession is successful
void OTARequestor::mOnConnected(void * context, chip::DeviceProxy * deviceProxy)
{
    switch (onConnectedState)
    {
    case kQueryImage: {
        CHIP_ERROR err = CHIP_NO_ERROR;
        chip::Controller::OtaSoftwareUpdateProviderCluster cluster;
        constexpr EndpointId kOtaProviderEndpoint = 0;

        // These QueryImage params have been chosen arbitrarily
        constexpr VendorId kExampleVendorId                               = VendorId::Common;
        constexpr uint16_t kExampleProductId                              = 77;
        constexpr uint16_t kExampleHWVersion                              = 3;
        constexpr uint16_t kExampleSoftwareVersion                        = 0;
        constexpr EmberAfOTADownloadProtocol kExampleProtocolsSupported[] = { EMBER_ZCL_OTA_DOWNLOAD_PROTOCOL_BDX_SYNCHRONOUS };
        const char locationBuf[]                                          = { 'U', 'S' };
        CharSpan exampleLocation(locationBuf);
        constexpr bool kExampleClientCanConsent = false;
        ByteSpan metadata;

        err = cluster.Associate(deviceProxy, kOtaProviderEndpoint);
        if (err != CHIP_NO_ERROR)
        {
            ChipLogError(SoftwareUpdate, "Associate() failed: %" CHIP_ERROR_FORMAT, err.Format());
            return;
        }
        QueryImage::Type args;
        args.vendorId           = kExampleVendorId;
        args.productId          = kExampleProductId;
        args.softwareVersion    = kExampleSoftwareVersion;
        args.protocolsSupported = kExampleProtocolsSupported;
        args.hardwareVersion.Emplace(kExampleHWVersion);
        args.location.Emplace(exampleLocation);
        args.requestorCanConsent.Emplace(kExampleClientCanConsent);
        args.metadataForProvider.Emplace(metadata);
        err = cluster.InvokeCommand(args, /* context = */ nullptr, OnQueryImageResponse, OnQueryImageFailure);
        if (err != CHIP_NO_ERROR)
        {
            ChipLogError(SoftwareUpdate, "QueryImage() failed: %" CHIP_ERROR_FORMAT, err.Format());
        }

        break;
    }
    case kStartBDX: {
        TransferSession::TransferInitData initOptions;
        initOptions.TransferCtlFlags = chip::bdx::TransferControlFlags::kReceiverDrive;
        initOptions.MaxBlockSize     = 1024;
        char testFileDes[9]          = { "test.txt" };
        initOptions.FileDesLength    = static_cast<uint16_t>(strlen(testFileDes));
        initOptions.FileDesignator   = reinterpret_cast<uint8_t *>(testFileDes);

        if (deviceProxy != nullptr)
        {
            chip::Messaging::ExchangeManager * exchangeMgr = deviceProxy->GetExchangeManager();
            chip::Optional<chip::SessionHandle> session    = deviceProxy->GetSecureSession();
            if (exchangeMgr != nullptr && session.HasValue())
            {
                exchangeCtx = exchangeMgr->NewContext(session.Value(), &bdxDownloader);
            }

            if (exchangeCtx == nullptr)
            {
                ChipLogError(BDX, "unable to allocate ec: exchangeMgr=%p sessionExists? %u", exchangeMgr, session.HasValue());
                return;
            }
        }

        bdxDownloader.SetInitialExchange(exchangeCtx);

        // This will kick of a timer which will regularly check for updates to the bdx::TransferSession state machine.
        bdxDownloader.InitiateTransfer(&chip::DeviceLayer::SystemLayer(), chip::bdx::TransferRole::kReceiver, initOptions,
                                       chip::System::Clock::Seconds16(20));
        break;
    }
    default:
        break;
    }
}

#if 0 // LISS for now !!!!!!!!!!!!!!!!!!!!!!!


ExampleOTARequestor ExampleOTARequestor::sInstance;

constexpr uint32_t kImmediateStartDelayMs = 1; // Start the timer with this value when starting OTA "immediately"

// OTA Software Update Requestor Cluster AnnounceOtaProvider Command callback (from client)
bool emberAfOtaSoftwareUpdateRequestorClusterAnnounceOtaProviderCallback(
    chip::app::CommandHandler * commandObj, const chip::app::ConcreteCommandPath & commandPath,
    const chip::app::Clusters::OtaSoftwareUpdateRequestor::Commands::AnnounceOtaProvider::DecodableType & commandData)
{
    EmberAfStatus status = ExampleOTARequestor::GetInstance().HandleAnnounceOTAProvider(commandObj, commandPath, commandData);
    emberAfSendImmediateDefaultResponse(status);
    return true;
}

ExampleOTARequestor::ExampleOTARequestor()
{
    mOtaStartDelayMs     = 0;
    mProviderNodeId      = chip::kUndefinedNodeId;
    mProviderFabricIndex = chip::kUndefinedFabricIndex;
}

void ExampleOTARequestor::Init(uint32_t startDelayMs)
{
    mOtaStartDelayMs = startDelayMs;
}

void ExampleOTARequestor::ConnectToProvider()
{

    if (mConnectToProviderCallback != nullptr)
    {
        ChipLogProgress(SoftwareUpdate, "Attempting to connect to 0x" ChipLogFormatX64 " on FabricIndex 0x%" PRIu8,
                        ChipLogValueX64(mProviderNodeId), mProviderFabricIndex);

        mConnectToProviderCallback(mProviderNodeId, mProviderFabricIndex);
    }
    else
    {
        ChipLogError(SoftwareUpdate, "ConnectToProviderCallback is not set");
    }
}

EmberAfStatus ExampleOTARequestor::HandleAnnounceOTAProvider(
    chip::app::CommandHandler * commandObj, const chip::app::ConcreteCommandPath & commandPath,
    const chip::app::Clusters::OtaSoftwareUpdateRequestor::Commands::AnnounceOtaProvider::DecodableType & commandData)
{
    auto & providerLocation   = commandData.providerLocation;
    auto & announcementReason = commandData.announcementReason;

    if (commandObj == nullptr || commandObj->GetExchangeContext() == nullptr)
    {
        ChipLogError(SoftwareUpdate, "Cannot access ExchangeContext for FabricIndex");
        return EMBER_ZCL_STATUS_INVALID_ARGUMENT;
    }

    mProviderNodeId      = providerLocation;
    mProviderFabricIndex = commandObj->GetExchangeContext()->GetSessionHandle().GetFabricIndex();

    ChipLogProgress(SoftwareUpdate, "OTA Requestor received AnnounceOTAProvider");
    ChipLogDetail(SoftwareUpdate, "  FabricIndex: %" PRIu8, mProviderFabricIndex);
    ChipLogDetail(SoftwareUpdate, "  ProviderNodeID: 0x" ChipLogFormatX64, ChipLogValueX64(mProviderNodeId));
    ChipLogDetail(SoftwareUpdate, "  VendorID: 0x%" PRIx16, commandData.vendorId);
    ChipLogDetail(SoftwareUpdate, "  AnnouncementReason: %" PRIu8, announcementReason);
    if (commandData.metadataForNode.HasValue())
    {
        ChipLogDetail(SoftwareUpdate, "  MetadataForNode: %zu", commandData.metadataForNode.Value().size());
    }

    // If reason is URGENT_UPDATE_AVAILABLE, we start OTA immediately. Otherwise, respect the timer value set in mOtaStartDelayMs.
    // This is done to exemplify what a real-world OTA Requestor might do while also being configurable enough to use as a test app.
    uint32_t msToStart = 0;
    switch (announcementReason)
    {
    case static_cast<uint8_t>(EMBER_ZCL_OTA_ANNOUNCEMENT_REASON_SIMPLE_ANNOUNCEMENT):
    case static_cast<uint8_t>(EMBER_ZCL_OTA_ANNOUNCEMENT_REASON_UPDATE_AVAILABLE):
        msToStart = mOtaStartDelayMs;
        break;
    case static_cast<uint8_t>(EMBER_ZCL_OTA_ANNOUNCEMENT_REASON_URGENT_UPDATE_AVAILABLE):
        msToStart = kImmediateStartDelayMs;
        break;
    default:
        ChipLogError(SoftwareUpdate, "Unexpected announcementReason: %" PRIu8, static_cast<uint8_t>(announcementReason));
        return EMBER_ZCL_STATUS_INVALID_ARGUMENT;
    }

    chip::DeviceLayer::SystemLayer().StartTimer(chip::System::Clock::Milliseconds32(msToStart), StartDelayTimerHandler, this);

    return EMBER_ZCL_STATUS_SUCCESS;
}

void ExampleOTARequestor::StartDelayTimerHandler(chip::System::Layer * systemLayer, void * appState)
{
    VerifyOrReturn(appState != nullptr);
    static_cast<ExampleOTARequestor *>(appState)->ConnectToProvider();
}

#endif // LISS