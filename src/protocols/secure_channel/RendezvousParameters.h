/*
 *
 *    Copyright (c) 2020 Project CHIP Authors
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

#pragma once

#include <transport/raw/Base.h>
#include <transport/raw/PeerAddress.h>
#if CONFIG_NETWORK_LAYER_BLE
#include <ble/Ble.h>
#endif // CONFIG_NETWORK_LAYER_BLE

#include <lib/support/logging/CHIPLogging.h>
#include <protocols/secure_channel/PASESession.h>

namespace chip {

// The largest supported value for Rendezvous discriminators
const uint16_t kMaxRendezvousDiscriminatorValue = 0xFFF;

class RendezvousParameters
{
public:
    RendezvousParameters() = default;

    bool IsController() const { return HasDiscriminator() || HasConnectionObject(); }

    bool HasSetupPINCode() const { return mSetupPINCode != 0; }
    uint32_t GetSetupPINCode() const { return mSetupPINCode; }
    RendezvousParameters & SetSetupPINCode(uint32_t setupPINCode)
    {
        mSetupPINCode = setupPINCode;
        return *this;
    }

    bool HasPeerAddress() const { return mPeerAddress.IsInitialized(); }
    Transport::PeerAddress GetPeerAddress() const { return mPeerAddress; }
    RendezvousParameters & SetPeerAddress(const Transport::PeerAddress & peerAddress)
    {
        mPeerAddress = peerAddress;
        return *this;
    }

    bool HasDiscriminator() const { return mDiscriminator <= kMaxRendezvousDiscriminatorValue; }
    uint16_t GetDiscriminator() const { return mDiscriminator; }
    RendezvousParameters & SetDiscriminator(uint16_t discriminator)
    {
        mDiscriminator = discriminator;
        return *this;
    }

    bool HasPASEVerifier() const { return mHasPASEVerifier; }
    const PASEVerifier & GetPASEVerifier() const { return mPASEVerifier; }
    RendezvousParameters & SetPASEVerifier(PASEVerifier & verifier)
    {
        memmove(&mPASEVerifier, &verifier, sizeof(verifier));
        mHasPASEVerifier = true;
        return *this;
    }

#if CONFIG_NETWORK_LAYER_BLE
    bool HasBleLayer() const { return mBleLayer != nullptr; }
    Ble::BleLayer * GetBleLayer() const { return mBleLayer; }
    RendezvousParameters & SetBleLayer(Ble::BleLayer * value)
    {
        mBleLayer = value;
        return *this;
    }

    bool HasConnectionObject() const { return mConnectionObject != 0; }
    BLE_CONNECTION_OBJECT GetConnectionObject() const { return mConnectionObject; }
    RendezvousParameters & SetConnectionObject(BLE_CONNECTION_OBJECT connObj)
    {
        mConnectionObject = connObj;
        return *this;
    }
#else
    bool HasConnectionObject() const { return false; }
#endif // CONFIG_NETWORK_LAYER_BLE

private:
    Transport::PeerAddress mPeerAddress;  ///< the peer node address
    uint32_t mSetupPINCode  = 0;          ///< the target peripheral setup PIN Code
    uint16_t mDiscriminator = UINT16_MAX; ///< the target peripheral discriminator

    PASEVerifier mPASEVerifier;
    bool mHasPASEVerifier = false;

#if CONFIG_NETWORK_LAYER_BLE
    Ble::BleLayer * mBleLayer               = nullptr;
    BLE_CONNECTION_OBJECT mConnectionObject = 0;
#endif // CONFIG_NETWORK_LAYER_BLE
};

struct WifiCredentials
{
    ByteSpan ssid;
    // TODO(cecille): We should add a PII bytespan concept.
    ByteSpan password;
};

class CommissioningParameters
{
public:
    const Optional<ByteSpan> GetCSRNonce() const { return mCSRNonce; }
    // The lifetime of the buffer csrNonce is pointing to, should exceed the lifetime of RendezvousParameter object.
    CommissioningParameters & SetCSRNonce(ByteSpan csrNonce)
    {
        mCSRNonce.SetValue(csrNonce);
        return *this;
    }
    bool HasCSRNonce() const { return mCSRNonce.HasValue(); }

    const Optional<WifiCredentials> GetWifiCredentials() const { return mWifiCreds; }
    CommissioningParameters & SetWifiCredentials(WifiCredentials wifiCreds)
    {
        mWifiCreds.SetValue(wifiCreds);
        return *this;
    }
    bool HasWifiCredentials() const { return mWifiCreds.HasValue(); }
    const Optional<ByteSpan> GetThreadOperationalDataset() const { return mThreadOperationalDataset; }
    CommissioningParameters & SetThreadOperationalDataset(ByteSpan threadOperationalDataset)
    {

        mThreadOperationalDataset.SetValue(threadOperationalDataset);
        return *this;
    }
    bool HasThreadOperationalDataset() const { return mThreadOperationalDataset.HasValue(); }

private:
    Optional<ByteSpan> mCSRNonce; ///< CSR Nonce passed by the commissioner
    Optional<WifiCredentials> mWifiCreds;
    Optional<ByteSpan> mThreadOperationalDataset;
};

} // namespace chip
