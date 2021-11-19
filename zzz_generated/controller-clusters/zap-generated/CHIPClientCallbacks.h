/*
 *
 *    Copyright (c) 2021 Project CHIP Authors
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

// THIS FILE IS GENERATED BY ZAP

#pragma once

#include <app-common/zap-generated/af-structs.h>
#include <app-common/zap-generated/cluster-objects.h>
#include <app/Command.h>
#include <app/InteractionModelEngine.h>
#include <app/data-model/DecodableList.h>
#include <app/util/af-enums.h>
#include <app/util/attribute-filter.h>
#include <app/util/im-client-callbacks.h>
#include <inttypes.h>
#include <lib/support/FunctionTraits.h>
#include <lib/support/Span.h>

// Note: The IMDefaultResponseCallback is a bridge to the old CallbackMgr before IM is landed, so it still accepts EmberAfStatus
// instead of IM status code.
// #6308 should handle IM error code on the application side, either modify this function or remove this.

// Cluster Specific Response Callbacks
typedef void (*AccountLoginClusterGetSetupPINResponseCallback)(void * context, chip::CharSpan setupPIN);
typedef void (*ApplicationLauncherClusterLaunchAppResponseCallback)(void * context, uint8_t status, chip::CharSpan data);
typedef void (*ContentLauncherClusterLaunchContentResponseCallback)(void * context, chip::CharSpan data,
                                                                    uint8_t contentLaunchStatus);
typedef void (*ContentLauncherClusterLaunchURLResponseCallback)(void * context, chip::CharSpan data, uint8_t contentLaunchStatus);
typedef void (*DiagnosticLogsClusterRetrieveLogsResponseCallback)(void * context, uint8_t status, chip::ByteSpan content,
                                                                  uint32_t timeStamp, uint32_t timeSinceBoot);
typedef void (*DoorLockClusterClearAllPinsResponseCallback)(void * context, uint8_t status);
typedef void (*DoorLockClusterClearAllRfidsResponseCallback)(void * context, uint8_t status);
typedef void (*DoorLockClusterClearHolidayScheduleResponseCallback)(void * context, uint8_t status);
typedef void (*DoorLockClusterClearPinResponseCallback)(void * context, uint8_t status);
typedef void (*DoorLockClusterClearRfidResponseCallback)(void * context, uint8_t status);
typedef void (*DoorLockClusterClearWeekdayScheduleResponseCallback)(void * context, uint8_t status);
typedef void (*DoorLockClusterClearYeardayScheduleResponseCallback)(void * context, uint8_t status);
typedef void (*DoorLockClusterGetHolidayScheduleResponseCallback)(void * context, uint8_t scheduleId, uint8_t status,
                                                                  uint32_t localStartTime, uint32_t localEndTime,
                                                                  uint8_t operatingModeDuringHoliday);
typedef void (*DoorLockClusterGetLogRecordResponseCallback)(void * context, uint16_t logEntryId, uint32_t timestamp,
                                                            uint8_t eventType, uint8_t source, uint8_t eventIdOrAlarmCode,
                                                            uint16_t userId, chip::ByteSpan pin);
typedef void (*DoorLockClusterGetPinResponseCallback)(void * context, uint16_t userId, uint8_t userStatus, uint8_t userType,
                                                      chip::ByteSpan pin);
typedef void (*DoorLockClusterGetRfidResponseCallback)(void * context, uint16_t userId, uint8_t userStatus, uint8_t userType,
                                                       chip::ByteSpan rfid);
typedef void (*DoorLockClusterGetUserTypeResponseCallback)(void * context, uint16_t userId, uint8_t userType);
typedef void (*DoorLockClusterGetWeekdayScheduleResponseCallback)(void * context, uint8_t scheduleId, uint16_t userId,
                                                                  uint8_t status, uint8_t daysMask, uint8_t startHour,
                                                                  uint8_t startMinute, uint8_t endHour, uint8_t endMinute);
typedef void (*DoorLockClusterGetYeardayScheduleResponseCallback)(void * context, uint8_t scheduleId, uint16_t userId,
                                                                  uint8_t status, uint32_t localStartTime, uint32_t localEndTime);
typedef void (*DoorLockClusterLockDoorResponseCallback)(void * context, uint8_t status);
typedef void (*DoorLockClusterSetHolidayScheduleResponseCallback)(void * context, uint8_t status);
typedef void (*DoorLockClusterSetPinResponseCallback)(void * context, uint8_t status);
typedef void (*DoorLockClusterSetRfidResponseCallback)(void * context, uint8_t status);
typedef void (*DoorLockClusterSetUserTypeResponseCallback)(void * context, uint8_t status);
typedef void (*DoorLockClusterSetWeekdayScheduleResponseCallback)(void * context, uint8_t status);
typedef void (*DoorLockClusterSetYeardayScheduleResponseCallback)(void * context, uint8_t status);
typedef void (*DoorLockClusterUnlockDoorResponseCallback)(void * context, uint8_t status);
typedef void (*DoorLockClusterUnlockWithTimeoutResponseCallback)(void * context, uint8_t status);
typedef void (*GeneralCommissioningClusterArmFailSafeResponseCallback)(void * context, uint8_t errorCode, chip::CharSpan debugText);
typedef void (*GeneralCommissioningClusterCommissioningCompleteResponseCallback)(void * context, uint8_t errorCode,
                                                                                 chip::CharSpan debugText);
typedef void (*GeneralCommissioningClusterSetRegulatoryConfigResponseCallback)(void * context, uint8_t errorCode,
                                                                               chip::CharSpan debugText);
typedef void (*GroupsClusterAddGroupResponseCallback)(void * context, uint8_t status, uint16_t groupId);
typedef void (*GroupsClusterGetGroupMembershipResponseCallback)(void * context, uint8_t capacity, uint8_t groupCount,
                                                                /* TYPE WARNING: array array defaults to */ uint8_t * groupList);
typedef void (*GroupsClusterRemoveGroupResponseCallback)(void * context, uint8_t status, uint16_t groupId);
typedef void (*GroupsClusterViewGroupResponseCallback)(void * context, uint8_t status, uint16_t groupId, chip::CharSpan groupName);
typedef void (*IdentifyClusterIdentifyQueryResponseCallback)(void * context, uint16_t timeout);
typedef void (*KeypadInputClusterSendKeyResponseCallback)(void * context, uint8_t status);
typedef void (*MediaPlaybackClusterMediaFastForwardResponseCallback)(void * context, uint8_t mediaPlaybackStatus);
typedef void (*MediaPlaybackClusterMediaNextResponseCallback)(void * context, uint8_t mediaPlaybackStatus);
typedef void (*MediaPlaybackClusterMediaPauseResponseCallback)(void * context, uint8_t mediaPlaybackStatus);
typedef void (*MediaPlaybackClusterMediaPlayResponseCallback)(void * context, uint8_t mediaPlaybackStatus);
typedef void (*MediaPlaybackClusterMediaPreviousResponseCallback)(void * context, uint8_t mediaPlaybackStatus);
typedef void (*MediaPlaybackClusterMediaRewindResponseCallback)(void * context, uint8_t mediaPlaybackStatus);
typedef void (*MediaPlaybackClusterMediaSeekResponseCallback)(void * context, uint8_t mediaPlaybackStatus);
typedef void (*MediaPlaybackClusterMediaSkipBackwardResponseCallback)(void * context, uint8_t mediaPlaybackStatus);
typedef void (*MediaPlaybackClusterMediaSkipForwardResponseCallback)(void * context, uint8_t mediaPlaybackStatus);
typedef void (*MediaPlaybackClusterMediaStartOverResponseCallback)(void * context, uint8_t mediaPlaybackStatus);
typedef void (*MediaPlaybackClusterMediaStopResponseCallback)(void * context, uint8_t mediaPlaybackStatus);
typedef void (*NetworkCommissioningClusterAddThreadNetworkResponseCallback)(void * context, uint8_t errorCode,
                                                                            chip::CharSpan debugText);
typedef void (*NetworkCommissioningClusterAddWiFiNetworkResponseCallback)(void * context, uint8_t errorCode,
                                                                          chip::CharSpan debugText);
typedef void (*NetworkCommissioningClusterDisableNetworkResponseCallback)(void * context, uint8_t errorCode,
                                                                          chip::CharSpan debugText);
typedef void (*NetworkCommissioningClusterEnableNetworkResponseCallback)(void * context, uint8_t errorCode,
                                                                         chip::CharSpan debugText);
typedef void (*NetworkCommissioningClusterRemoveNetworkResponseCallback)(void * context, uint8_t errorCode,
                                                                         chip::CharSpan debugText);
typedef void (*NetworkCommissioningClusterScanNetworksResponseCallback)(
    void * context, uint8_t errorCode, chip::CharSpan debugText,
    /* TYPE WARNING: array array defaults to */ uint8_t * wifiScanResults,
    /* TYPE WARNING: array array defaults to */ uint8_t * threadScanResults);
typedef void (*NetworkCommissioningClusterUpdateThreadNetworkResponseCallback)(void * context, uint8_t errorCode,
                                                                               chip::CharSpan debugText);
typedef void (*NetworkCommissioningClusterUpdateWiFiNetworkResponseCallback)(void * context, uint8_t errorCode,
                                                                             chip::CharSpan debugText);
typedef void (*OtaSoftwareUpdateProviderClusterApplyUpdateResponseCallback)(void * context, uint8_t action,
                                                                            uint32_t delayedActionTime);
typedef void (*OtaSoftwareUpdateProviderClusterQueryImageResponseCallback)(
    void * context, uint8_t status, uint32_t delayedActionTime, chip::CharSpan imageURI, uint32_t softwareVersion,
    chip::CharSpan softwareVersionString, chip::ByteSpan updateToken, bool userConsentNeeded, chip::ByteSpan metadataForRequestor);
typedef void (*OperationalCredentialsClusterAttestationResponseCallback)(void * context, chip::ByteSpan AttestationElements,
                                                                         chip::ByteSpan Signature);
typedef void (*OperationalCredentialsClusterCertificateChainResponseCallback)(void * context, chip::ByteSpan Certificate);
typedef void (*OperationalCredentialsClusterNOCResponseCallback)(void * context, uint8_t StatusCode, uint8_t FabricIndex,
                                                                 chip::CharSpan DebugText);
typedef void (*OperationalCredentialsClusterOpCSRResponseCallback)(void * context, chip::ByteSpan NOCSRElements,
                                                                   chip::ByteSpan AttestationSignature);
typedef void (*ScenesClusterAddSceneResponseCallback)(void * context, uint8_t status, uint16_t groupId, uint8_t sceneId);
typedef void (*ScenesClusterGetSceneMembershipResponseCallback)(void * context, uint8_t status, uint8_t capacity, uint16_t groupId,
                                                                uint8_t sceneCount,
                                                                /* TYPE WARNING: array array defaults to */ uint8_t * sceneList);
typedef void (*ScenesClusterRemoveAllScenesResponseCallback)(void * context, uint8_t status, uint16_t groupId);
typedef void (*ScenesClusterRemoveSceneResponseCallback)(void * context, uint8_t status, uint16_t groupId, uint8_t sceneId);
typedef void (*ScenesClusterStoreSceneResponseCallback)(void * context, uint8_t status, uint16_t groupId, uint8_t sceneId);
typedef void (*ScenesClusterViewSceneResponseCallback)(void * context, uint8_t status, uint16_t groupId, uint8_t sceneId,
                                                       uint16_t transitionTime, chip::CharSpan sceneName,
                                                       /* TYPE WARNING: array array defaults to */ uint8_t * extensionFieldSets);
typedef void (*TvChannelClusterChangeChannelResponseCallback)(void * context,
                                                              /* TYPE WARNING: array array defaults to */ uint8_t * ChannelMatch,
                                                              uint8_t ErrorType);
typedef void (*TargetNavigatorClusterNavigateTargetResponseCallback)(void * context, uint8_t status, chip::CharSpan data);
typedef void (*TestClusterClusterBooleanResponseCallback)(void * context, bool value);
typedef void (*TestClusterClusterTestAddArgumentsResponseCallback)(void * context, uint8_t returnValue);
typedef void (*TestClusterClusterTestEnumsResponseCallback)(void * context, chip::VendorId arg1, uint8_t arg2);
typedef void (*TestClusterClusterTestListInt8UReverseResponseCallback)(void * context,
                                                                       /* TYPE WARNING: array array defaults to */ uint8_t * arg1);
typedef void (*TestClusterClusterTestNullableOptionalResponseCallback)(void * context, bool wasPresent, bool wasNull, uint8_t value,
                                                                       uint8_t originalValue);
typedef void (*TestClusterClusterTestSpecificResponseCallback)(void * context, uint8_t returnValue);

// List specific responses
void ApplicationLauncherClusterApplicationLauncherListListAttributeFilter(chip::TLV::TLVReader * data,
                                                                          chip::Callback::Cancelable * onSuccessCallback,
                                                                          chip::Callback::Cancelable * onFailureCallback);
typedef void (*ApplicationLauncherApplicationLauncherListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<uint16_t> & data);
void AudioOutputClusterAudioOutputListListAttributeFilter(chip::TLV::TLVReader * data,
                                                          chip::Callback::Cancelable * onSuccessCallback,
                                                          chip::Callback::Cancelable * onFailureCallback);
typedef void (*AudioOutputAudioOutputListListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<chip::app::Clusters::AudioOutput::Structs::AudioOutputInfo::DecodableType> & data);
void BridgedActionsClusterActionListListAttributeFilter(chip::TLV::TLVReader * data, chip::Callback::Cancelable * onSuccessCallback,
                                                        chip::Callback::Cancelable * onFailureCallback);
typedef void (*BridgedActionsActionListListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<chip::app::Clusters::BridgedActions::Structs::ActionStruct::DecodableType> & data);
void BridgedActionsClusterEndpointListListAttributeFilter(chip::TLV::TLVReader * data,
                                                          chip::Callback::Cancelable * onSuccessCallback,
                                                          chip::Callback::Cancelable * onFailureCallback);
typedef void (*BridgedActionsEndpointListListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<chip::app::Clusters::BridgedActions::Structs::EndpointListStruct::DecodableType> &
        data);
void ContentLauncherClusterAcceptsHeaderListListAttributeFilter(chip::TLV::TLVReader * data,
                                                                chip::Callback::Cancelable * onSuccessCallback,
                                                                chip::Callback::Cancelable * onFailureCallback);
typedef void (*ContentLauncherAcceptsHeaderListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::ByteSpan> & data);
void ContentLauncherClusterSupportedStreamingTypesListAttributeFilter(chip::TLV::TLVReader * data,
                                                                      chip::Callback::Cancelable * onSuccessCallback,
                                                                      chip::Callback::Cancelable * onFailureCallback);
typedef void (*ContentLauncherSupportedStreamingTypesListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<chip::app::Clusters::ContentLauncher::ContentLaunchStreamingType> & data);
void DescriptorClusterDeviceListListAttributeFilter(chip::TLV::TLVReader * data, chip::Callback::Cancelable * onSuccessCallback,
                                                    chip::Callback::Cancelable * onFailureCallback);
typedef void (*DescriptorDeviceListListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<chip::app::Clusters::Descriptor::Structs::DeviceType::DecodableType> & data);
void DescriptorClusterServerListListAttributeFilter(chip::TLV::TLVReader * data, chip::Callback::Cancelable * onSuccessCallback,
                                                    chip::Callback::Cancelable * onFailureCallback);
typedef void (*DescriptorServerListListAttributeCallback)(void * context,
                                                          const chip::app::DataModel::DecodableList<chip::ClusterId> & data);
void DescriptorClusterClientListListAttributeFilter(chip::TLV::TLVReader * data, chip::Callback::Cancelable * onSuccessCallback,
                                                    chip::Callback::Cancelable * onFailureCallback);
typedef void (*DescriptorClientListListAttributeCallback)(void * context,
                                                          const chip::app::DataModel::DecodableList<chip::ClusterId> & data);
void DescriptorClusterPartsListListAttributeFilter(chip::TLV::TLVReader * data, chip::Callback::Cancelable * onSuccessCallback,
                                                   chip::Callback::Cancelable * onFailureCallback);
typedef void (*DescriptorPartsListListAttributeCallback)(void * context,
                                                         const chip::app::DataModel::DecodableList<chip::EndpointId> & data);
void FixedLabelClusterLabelListListAttributeFilter(chip::TLV::TLVReader * data, chip::Callback::Cancelable * onSuccessCallback,
                                                   chip::Callback::Cancelable * onFailureCallback);
typedef void (*FixedLabelLabelListListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<chip::app::Clusters::FixedLabel::Structs::LabelStruct::DecodableType> & data);
void GeneralCommissioningClusterBasicCommissioningInfoListListAttributeFilter(chip::TLV::TLVReader * data,
                                                                              chip::Callback::Cancelable * onSuccessCallback,
                                                                              chip::Callback::Cancelable * onFailureCallback);
typedef void (*GeneralCommissioningBasicCommissioningInfoListListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<
        chip::app::Clusters::GeneralCommissioning::Structs::BasicCommissioningInfoType::DecodableType> & data);
void GeneralDiagnosticsClusterNetworkInterfacesListAttributeFilter(chip::TLV::TLVReader * data,
                                                                   chip::Callback::Cancelable * onSuccessCallback,
                                                                   chip::Callback::Cancelable * onFailureCallback);
typedef void (*GeneralDiagnosticsNetworkInterfacesListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<
        chip::app::Clusters::GeneralDiagnostics::Structs::NetworkInterfaceType::DecodableType> & data);
void GeneralDiagnosticsClusterActiveHardwareFaultsListAttributeFilter(chip::TLV::TLVReader * data,
                                                                      chip::Callback::Cancelable * onSuccessCallback,
                                                                      chip::Callback::Cancelable * onFailureCallback);
typedef void (*GeneralDiagnosticsActiveHardwareFaultsListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<uint8_t> & data);
void GeneralDiagnosticsClusterActiveRadioFaultsListAttributeFilter(chip::TLV::TLVReader * data,
                                                                   chip::Callback::Cancelable * onSuccessCallback,
                                                                   chip::Callback::Cancelable * onFailureCallback);
typedef void (*GeneralDiagnosticsActiveRadioFaultsListAttributeCallback)(void * context,
                                                                         const chip::app::DataModel::DecodableList<uint8_t> & data);
void GeneralDiagnosticsClusterActiveNetworkFaultsListAttributeFilter(chip::TLV::TLVReader * data,
                                                                     chip::Callback::Cancelable * onSuccessCallback,
                                                                     chip::Callback::Cancelable * onFailureCallback);
typedef void (*GeneralDiagnosticsActiveNetworkFaultsListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<uint8_t> & data);
void GroupKeyManagementClusterGroupsListAttributeFilter(chip::TLV::TLVReader * data, chip::Callback::Cancelable * onSuccessCallback,
                                                        chip::Callback::Cancelable * onFailureCallback);
typedef void (*GroupKeyManagementGroupsListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<chip::app::Clusters::GroupKeyManagement::Structs::GroupState::DecodableType> & data);
void GroupKeyManagementClusterGroupKeysListAttributeFilter(chip::TLV::TLVReader * data,
                                                           chip::Callback::Cancelable * onSuccessCallback,
                                                           chip::Callback::Cancelable * onFailureCallback);
typedef void (*GroupKeyManagementGroupKeysListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<chip::app::Clusters::GroupKeyManagement::Structs::GroupKey::DecodableType> & data);
void MediaInputClusterMediaInputListListAttributeFilter(chip::TLV::TLVReader * data, chip::Callback::Cancelable * onSuccessCallback,
                                                        chip::Callback::Cancelable * onFailureCallback);
typedef void (*MediaInputMediaInputListListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<chip::app::Clusters::MediaInput::Structs::MediaInputInfo::DecodableType> & data);
void ModeSelectClusterSupportedModesListAttributeFilter(chip::TLV::TLVReader * data, chip::Callback::Cancelable * onSuccessCallback,
                                                        chip::Callback::Cancelable * onFailureCallback);
typedef void (*ModeSelectSupportedModesListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<chip::app::Clusters::ModeSelect::Structs::ModeOptionStruct::DecodableType> & data);
void OperationalCredentialsClusterFabricsListListAttributeFilter(chip::TLV::TLVReader * data,
                                                                 chip::Callback::Cancelable * onSuccessCallback,
                                                                 chip::Callback::Cancelable * onFailureCallback);
typedef void (*OperationalCredentialsFabricsListListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<
        chip::app::Clusters::OperationalCredentials::Structs::FabricDescriptor::DecodableType> & data);
void OperationalCredentialsClusterTrustedRootCertificatesListAttributeFilter(chip::TLV::TLVReader * data,
                                                                             chip::Callback::Cancelable * onSuccessCallback,
                                                                             chip::Callback::Cancelable * onFailureCallback);
typedef void (*OperationalCredentialsTrustedRootCertificatesListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::ByteSpan> & data);
void PowerSourceClusterActiveBatteryFaultsListAttributeFilter(chip::TLV::TLVReader * data,
                                                              chip::Callback::Cancelable * onSuccessCallback,
                                                              chip::Callback::Cancelable * onFailureCallback);
typedef void (*PowerSourceActiveBatteryFaultsListAttributeCallback)(void * context,
                                                                    const chip::app::DataModel::DecodableList<uint8_t> & data);
void SoftwareDiagnosticsClusterThreadMetricsListAttributeFilter(chip::TLV::TLVReader * data,
                                                                chip::Callback::Cancelable * onSuccessCallback,
                                                                chip::Callback::Cancelable * onFailureCallback);
typedef void (*SoftwareDiagnosticsThreadMetricsListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<chip::app::Clusters::SoftwareDiagnostics::Structs::ThreadMetrics::DecodableType> &
        data);
void TvChannelClusterTvChannelListListAttributeFilter(chip::TLV::TLVReader * data, chip::Callback::Cancelable * onSuccessCallback,
                                                      chip::Callback::Cancelable * onFailureCallback);
typedef void (*TvChannelTvChannelListListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<chip::app::Clusters::TvChannel::Structs::TvChannelInfo::DecodableType> & data);
void TargetNavigatorClusterTargetNavigatorListListAttributeFilter(chip::TLV::TLVReader * data,
                                                                  chip::Callback::Cancelable * onSuccessCallback,
                                                                  chip::Callback::Cancelable * onFailureCallback);
typedef void (*TargetNavigatorTargetNavigatorListListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<
        chip::app::Clusters::TargetNavigator::Structs::NavigateTargetTargetInfo::DecodableType> & data);
void TestClusterClusterListInt8uListAttributeFilter(chip::TLV::TLVReader * data, chip::Callback::Cancelable * onSuccessCallback,
                                                    chip::Callback::Cancelable * onFailureCallback);
typedef void (*TestClusterListInt8uListAttributeCallback)(void * context,
                                                          const chip::app::DataModel::DecodableList<uint8_t> & data);
void TestClusterClusterListOctetStringListAttributeFilter(chip::TLV::TLVReader * data,
                                                          chip::Callback::Cancelable * onSuccessCallback,
                                                          chip::Callback::Cancelable * onFailureCallback);
typedef void (*TestClusterListOctetStringListAttributeCallback)(void * context,
                                                                const chip::app::DataModel::DecodableList<chip::ByteSpan> & data);
void TestClusterClusterListStructOctetStringListAttributeFilter(chip::TLV::TLVReader * data,
                                                                chip::Callback::Cancelable * onSuccessCallback,
                                                                chip::Callback::Cancelable * onFailureCallback);
typedef void (*TestClusterListStructOctetStringListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<chip::app::Clusters::TestCluster::Structs::TestListStructOctet::DecodableType> &
        data);
void TestClusterClusterListNullablesAndOptionalsStructListAttributeFilter(chip::TLV::TLVReader * data,
                                                                          chip::Callback::Cancelable * onSuccessCallback,
                                                                          chip::Callback::Cancelable * onFailureCallback);
typedef void (*TestClusterListNullablesAndOptionalsStructListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<
        chip::app::Clusters::TestCluster::Structs::NullablesAndOptionalsStruct::DecodableType> & data);
void ThreadNetworkDiagnosticsClusterNeighborTableListListAttributeFilter(chip::TLV::TLVReader * data,
                                                                         chip::Callback::Cancelable * onSuccessCallback,
                                                                         chip::Callback::Cancelable * onFailureCallback);
typedef void (*ThreadNetworkDiagnosticsNeighborTableListListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<
        chip::app::Clusters::ThreadNetworkDiagnostics::Structs::NeighborTable::DecodableType> & data);
void ThreadNetworkDiagnosticsClusterRouteTableListListAttributeFilter(chip::TLV::TLVReader * data,
                                                                      chip::Callback::Cancelable * onSuccessCallback,
                                                                      chip::Callback::Cancelable * onFailureCallback);
typedef void (*ThreadNetworkDiagnosticsRouteTableListListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<chip::app::Clusters::ThreadNetworkDiagnostics::Structs::RouteTable::DecodableType> &
        data);
void ThreadNetworkDiagnosticsClusterSecurityPolicyListAttributeFilter(chip::TLV::TLVReader * data,
                                                                      chip::Callback::Cancelable * onSuccessCallback,
                                                                      chip::Callback::Cancelable * onFailureCallback);
typedef void (*ThreadNetworkDiagnosticsSecurityPolicyListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<
        chip::app::Clusters::ThreadNetworkDiagnostics::Structs::SecurityPolicy::DecodableType> & data);
void ThreadNetworkDiagnosticsClusterOperationalDatasetComponentsListAttributeFilter(chip::TLV::TLVReader * data,
                                                                                    chip::Callback::Cancelable * onSuccessCallback,
                                                                                    chip::Callback::Cancelable * onFailureCallback);
typedef void (*ThreadNetworkDiagnosticsOperationalDatasetComponentsListAttributeCallback)(
    void * context,
    const chip::app::DataModel::DecodableList<
        chip::app::Clusters::ThreadNetworkDiagnostics::Structs::OperationalDatasetComponents::DecodableType> & data);
void ThreadNetworkDiagnosticsClusterActiveNetworkFaultsListListAttributeFilter(chip::TLV::TLVReader * data,
                                                                               chip::Callback::Cancelable * onSuccessCallback,
                                                                               chip::Callback::Cancelable * onFailureCallback);
typedef void (*ThreadNetworkDiagnosticsActiveNetworkFaultsListListAttributeCallback)(
    void * context, const chip::app::DataModel::DecodableList<chip::app::Clusters::ThreadNetworkDiagnostics::NetworkFault> & data);
