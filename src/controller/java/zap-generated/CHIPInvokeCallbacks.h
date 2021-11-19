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
#include "CHIPCallbackTypes.h"

#include <app-common/zap-generated/cluster-objects.h>
#include <jni.h>
#include <zap-generated/CHIPClientCallbacks.h>

namespace chip {

class CHIPAccountLoginClusterGetSetupPINResponseCallback
    : public Callback::Callback<CHIPAccountLoginClusterGetSetupPINResponseCallbackType>
{
public:
    CHIPAccountLoginClusterGetSetupPINResponseCallback(jobject javaCallback);

    ~CHIPAccountLoginClusterGetSetupPINResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::AccountLogin::Commands::GetSetupPINResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPApplicationLauncherClusterLaunchAppResponseCallback
    : public Callback::Callback<CHIPApplicationLauncherClusterLaunchAppResponseCallbackType>
{
public:
    CHIPApplicationLauncherClusterLaunchAppResponseCallback(jobject javaCallback);

    ~CHIPApplicationLauncherClusterLaunchAppResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::ApplicationLauncher::Commands::LaunchAppResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPContentLauncherClusterLaunchContentResponseCallback
    : public Callback::Callback<CHIPContentLauncherClusterLaunchContentResponseCallbackType>
{
public:
    CHIPContentLauncherClusterLaunchContentResponseCallback(jobject javaCallback);

    ~CHIPContentLauncherClusterLaunchContentResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::ContentLauncher::Commands::LaunchContentResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPContentLauncherClusterLaunchURLResponseCallback
    : public Callback::Callback<CHIPContentLauncherClusterLaunchURLResponseCallbackType>
{
public:
    CHIPContentLauncherClusterLaunchURLResponseCallback(jobject javaCallback);

    ~CHIPContentLauncherClusterLaunchURLResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::ContentLauncher::Commands::LaunchURLResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDiagnosticLogsClusterRetrieveLogsResponseCallback
    : public Callback::Callback<CHIPDiagnosticLogsClusterRetrieveLogsResponseCallbackType>
{
public:
    CHIPDiagnosticLogsClusterRetrieveLogsResponseCallback(jobject javaCallback);

    ~CHIPDiagnosticLogsClusterRetrieveLogsResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::DiagnosticLogs::Commands::RetrieveLogsResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterClearAllPinsResponseCallback
    : public Callback::Callback<CHIPDoorLockClusterClearAllPinsResponseCallbackType>
{
public:
    CHIPDoorLockClusterClearAllPinsResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterClearAllPinsResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::DoorLock::Commands::ClearAllPinsResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterClearAllRfidsResponseCallback
    : public Callback::Callback<CHIPDoorLockClusterClearAllRfidsResponseCallbackType>
{
public:
    CHIPDoorLockClusterClearAllRfidsResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterClearAllRfidsResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::DoorLock::Commands::ClearAllRfidsResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterClearHolidayScheduleResponseCallback
    : public Callback::Callback<CHIPDoorLockClusterClearHolidayScheduleResponseCallbackType>
{
public:
    CHIPDoorLockClusterClearHolidayScheduleResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterClearHolidayScheduleResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::DoorLock::Commands::ClearHolidayScheduleResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterClearPinResponseCallback : public Callback::Callback<CHIPDoorLockClusterClearPinResponseCallbackType>
{
public:
    CHIPDoorLockClusterClearPinResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterClearPinResponseCallback();

    static void CallbackFn(void * context, const chip::app::Clusters::DoorLock::Commands::ClearPinResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterClearRfidResponseCallback : public Callback::Callback<CHIPDoorLockClusterClearRfidResponseCallbackType>
{
public:
    CHIPDoorLockClusterClearRfidResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterClearRfidResponseCallback();

    static void CallbackFn(void * context, const chip::app::Clusters::DoorLock::Commands::ClearRfidResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterClearWeekdayScheduleResponseCallback
    : public Callback::Callback<CHIPDoorLockClusterClearWeekdayScheduleResponseCallbackType>
{
public:
    CHIPDoorLockClusterClearWeekdayScheduleResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterClearWeekdayScheduleResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::DoorLock::Commands::ClearWeekdayScheduleResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterClearYeardayScheduleResponseCallback
    : public Callback::Callback<CHIPDoorLockClusterClearYeardayScheduleResponseCallbackType>
{
public:
    CHIPDoorLockClusterClearYeardayScheduleResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterClearYeardayScheduleResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::DoorLock::Commands::ClearYeardayScheduleResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterGetHolidayScheduleResponseCallback
    : public Callback::Callback<CHIPDoorLockClusterGetHolidayScheduleResponseCallbackType>
{
public:
    CHIPDoorLockClusterGetHolidayScheduleResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterGetHolidayScheduleResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::DoorLock::Commands::GetHolidayScheduleResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterGetLogRecordResponseCallback
    : public Callback::Callback<CHIPDoorLockClusterGetLogRecordResponseCallbackType>
{
public:
    CHIPDoorLockClusterGetLogRecordResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterGetLogRecordResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::DoorLock::Commands::GetLogRecordResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterGetPinResponseCallback : public Callback::Callback<CHIPDoorLockClusterGetPinResponseCallbackType>
{
public:
    CHIPDoorLockClusterGetPinResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterGetPinResponseCallback();

    static void CallbackFn(void * context, const chip::app::Clusters::DoorLock::Commands::GetPinResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterGetRfidResponseCallback : public Callback::Callback<CHIPDoorLockClusterGetRfidResponseCallbackType>
{
public:
    CHIPDoorLockClusterGetRfidResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterGetRfidResponseCallback();

    static void CallbackFn(void * context, const chip::app::Clusters::DoorLock::Commands::GetRfidResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterGetUserTypeResponseCallback : public Callback::Callback<CHIPDoorLockClusterGetUserTypeResponseCallbackType>
{
public:
    CHIPDoorLockClusterGetUserTypeResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterGetUserTypeResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::DoorLock::Commands::GetUserTypeResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterGetWeekdayScheduleResponseCallback
    : public Callback::Callback<CHIPDoorLockClusterGetWeekdayScheduleResponseCallbackType>
{
public:
    CHIPDoorLockClusterGetWeekdayScheduleResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterGetWeekdayScheduleResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::DoorLock::Commands::GetWeekdayScheduleResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterGetYeardayScheduleResponseCallback
    : public Callback::Callback<CHIPDoorLockClusterGetYeardayScheduleResponseCallbackType>
{
public:
    CHIPDoorLockClusterGetYeardayScheduleResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterGetYeardayScheduleResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::DoorLock::Commands::GetYeardayScheduleResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterLockDoorResponseCallback : public Callback::Callback<CHIPDoorLockClusterLockDoorResponseCallbackType>
{
public:
    CHIPDoorLockClusterLockDoorResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterLockDoorResponseCallback();

    static void CallbackFn(void * context, const chip::app::Clusters::DoorLock::Commands::LockDoorResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterSetHolidayScheduleResponseCallback
    : public Callback::Callback<CHIPDoorLockClusterSetHolidayScheduleResponseCallbackType>
{
public:
    CHIPDoorLockClusterSetHolidayScheduleResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterSetHolidayScheduleResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::DoorLock::Commands::SetHolidayScheduleResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterSetPinResponseCallback : public Callback::Callback<CHIPDoorLockClusterSetPinResponseCallbackType>
{
public:
    CHIPDoorLockClusterSetPinResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterSetPinResponseCallback();

    static void CallbackFn(void * context, const chip::app::Clusters::DoorLock::Commands::SetPinResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterSetRfidResponseCallback : public Callback::Callback<CHIPDoorLockClusterSetRfidResponseCallbackType>
{
public:
    CHIPDoorLockClusterSetRfidResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterSetRfidResponseCallback();

    static void CallbackFn(void * context, const chip::app::Clusters::DoorLock::Commands::SetRfidResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterSetUserTypeResponseCallback : public Callback::Callback<CHIPDoorLockClusterSetUserTypeResponseCallbackType>
{
public:
    CHIPDoorLockClusterSetUserTypeResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterSetUserTypeResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::DoorLock::Commands::SetUserTypeResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterSetWeekdayScheduleResponseCallback
    : public Callback::Callback<CHIPDoorLockClusterSetWeekdayScheduleResponseCallbackType>
{
public:
    CHIPDoorLockClusterSetWeekdayScheduleResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterSetWeekdayScheduleResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::DoorLock::Commands::SetWeekdayScheduleResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterSetYeardayScheduleResponseCallback
    : public Callback::Callback<CHIPDoorLockClusterSetYeardayScheduleResponseCallbackType>
{
public:
    CHIPDoorLockClusterSetYeardayScheduleResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterSetYeardayScheduleResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::DoorLock::Commands::SetYeardayScheduleResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterUnlockDoorResponseCallback : public Callback::Callback<CHIPDoorLockClusterUnlockDoorResponseCallbackType>
{
public:
    CHIPDoorLockClusterUnlockDoorResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterUnlockDoorResponseCallback();

    static void CallbackFn(void * context, const chip::app::Clusters::DoorLock::Commands::UnlockDoorResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPDoorLockClusterUnlockWithTimeoutResponseCallback
    : public Callback::Callback<CHIPDoorLockClusterUnlockWithTimeoutResponseCallbackType>
{
public:
    CHIPDoorLockClusterUnlockWithTimeoutResponseCallback(jobject javaCallback);

    ~CHIPDoorLockClusterUnlockWithTimeoutResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::DoorLock::Commands::UnlockWithTimeoutResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPGeneralCommissioningClusterArmFailSafeResponseCallback
    : public Callback::Callback<CHIPGeneralCommissioningClusterArmFailSafeResponseCallbackType>
{
public:
    CHIPGeneralCommissioningClusterArmFailSafeResponseCallback(jobject javaCallback);

    ~CHIPGeneralCommissioningClusterArmFailSafeResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::GeneralCommissioning::Commands::ArmFailSafeResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPGeneralCommissioningClusterCommissioningCompleteResponseCallback
    : public Callback::Callback<CHIPGeneralCommissioningClusterCommissioningCompleteResponseCallbackType>
{
public:
    CHIPGeneralCommissioningClusterCommissioningCompleteResponseCallback(jobject javaCallback);

    ~CHIPGeneralCommissioningClusterCommissioningCompleteResponseCallback();

    static void
    CallbackFn(void * context,
               const chip::app::Clusters::GeneralCommissioning::Commands::CommissioningCompleteResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPGeneralCommissioningClusterSetRegulatoryConfigResponseCallback
    : public Callback::Callback<CHIPGeneralCommissioningClusterSetRegulatoryConfigResponseCallbackType>
{
public:
    CHIPGeneralCommissioningClusterSetRegulatoryConfigResponseCallback(jobject javaCallback);

    ~CHIPGeneralCommissioningClusterSetRegulatoryConfigResponseCallback();

    static void
    CallbackFn(void * context,
               const chip::app::Clusters::GeneralCommissioning::Commands::SetRegulatoryConfigResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPGroupsClusterAddGroupResponseCallback : public Callback::Callback<CHIPGroupsClusterAddGroupResponseCallbackType>
{
public:
    CHIPGroupsClusterAddGroupResponseCallback(jobject javaCallback);

    ~CHIPGroupsClusterAddGroupResponseCallback();

    static void CallbackFn(void * context, const chip::app::Clusters::Groups::Commands::AddGroupResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPGroupsClusterGetGroupMembershipResponseCallback
    : public Callback::Callback<CHIPGroupsClusterGetGroupMembershipResponseCallbackType>
{
public:
    CHIPGroupsClusterGetGroupMembershipResponseCallback(jobject javaCallback);

    ~CHIPGroupsClusterGetGroupMembershipResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::Groups::Commands::GetGroupMembershipResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPGroupsClusterRemoveGroupResponseCallback : public Callback::Callback<CHIPGroupsClusterRemoveGroupResponseCallbackType>
{
public:
    CHIPGroupsClusterRemoveGroupResponseCallback(jobject javaCallback);

    ~CHIPGroupsClusterRemoveGroupResponseCallback();

    static void CallbackFn(void * context, const chip::app::Clusters::Groups::Commands::RemoveGroupResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPGroupsClusterViewGroupResponseCallback : public Callback::Callback<CHIPGroupsClusterViewGroupResponseCallbackType>
{
public:
    CHIPGroupsClusterViewGroupResponseCallback(jobject javaCallback);

    ~CHIPGroupsClusterViewGroupResponseCallback();

    static void CallbackFn(void * context, const chip::app::Clusters::Groups::Commands::ViewGroupResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPIdentifyClusterIdentifyQueryResponseCallback
    : public Callback::Callback<CHIPIdentifyClusterIdentifyQueryResponseCallbackType>
{
public:
    CHIPIdentifyClusterIdentifyQueryResponseCallback(jobject javaCallback);

    ~CHIPIdentifyClusterIdentifyQueryResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::Identify::Commands::IdentifyQueryResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPKeypadInputClusterSendKeyResponseCallback : public Callback::Callback<CHIPKeypadInputClusterSendKeyResponseCallbackType>
{
public:
    CHIPKeypadInputClusterSendKeyResponseCallback(jobject javaCallback);

    ~CHIPKeypadInputClusterSendKeyResponseCallback();

    static void CallbackFn(void * context, const chip::app::Clusters::KeypadInput::Commands::SendKeyResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPMediaPlaybackClusterMediaFastForwardResponseCallback
    : public Callback::Callback<CHIPMediaPlaybackClusterMediaFastForwardResponseCallbackType>
{
public:
    CHIPMediaPlaybackClusterMediaFastForwardResponseCallback(jobject javaCallback);

    ~CHIPMediaPlaybackClusterMediaFastForwardResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::MediaPlayback::Commands::MediaFastForwardResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPMediaPlaybackClusterMediaNextResponseCallback
    : public Callback::Callback<CHIPMediaPlaybackClusterMediaNextResponseCallbackType>
{
public:
    CHIPMediaPlaybackClusterMediaNextResponseCallback(jobject javaCallback);

    ~CHIPMediaPlaybackClusterMediaNextResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::MediaPlayback::Commands::MediaNextResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPMediaPlaybackClusterMediaPauseResponseCallback
    : public Callback::Callback<CHIPMediaPlaybackClusterMediaPauseResponseCallbackType>
{
public:
    CHIPMediaPlaybackClusterMediaPauseResponseCallback(jobject javaCallback);

    ~CHIPMediaPlaybackClusterMediaPauseResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::MediaPlayback::Commands::MediaPauseResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPMediaPlaybackClusterMediaPlayResponseCallback
    : public Callback::Callback<CHIPMediaPlaybackClusterMediaPlayResponseCallbackType>
{
public:
    CHIPMediaPlaybackClusterMediaPlayResponseCallback(jobject javaCallback);

    ~CHIPMediaPlaybackClusterMediaPlayResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::MediaPlayback::Commands::MediaPlayResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPMediaPlaybackClusterMediaPreviousResponseCallback
    : public Callback::Callback<CHIPMediaPlaybackClusterMediaPreviousResponseCallbackType>
{
public:
    CHIPMediaPlaybackClusterMediaPreviousResponseCallback(jobject javaCallback);

    ~CHIPMediaPlaybackClusterMediaPreviousResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::MediaPlayback::Commands::MediaPreviousResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPMediaPlaybackClusterMediaRewindResponseCallback
    : public Callback::Callback<CHIPMediaPlaybackClusterMediaRewindResponseCallbackType>
{
public:
    CHIPMediaPlaybackClusterMediaRewindResponseCallback(jobject javaCallback);

    ~CHIPMediaPlaybackClusterMediaRewindResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::MediaPlayback::Commands::MediaRewindResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPMediaPlaybackClusterMediaSeekResponseCallback
    : public Callback::Callback<CHIPMediaPlaybackClusterMediaSeekResponseCallbackType>
{
public:
    CHIPMediaPlaybackClusterMediaSeekResponseCallback(jobject javaCallback);

    ~CHIPMediaPlaybackClusterMediaSeekResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::MediaPlayback::Commands::MediaSeekResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPMediaPlaybackClusterMediaSkipBackwardResponseCallback
    : public Callback::Callback<CHIPMediaPlaybackClusterMediaSkipBackwardResponseCallbackType>
{
public:
    CHIPMediaPlaybackClusterMediaSkipBackwardResponseCallback(jobject javaCallback);

    ~CHIPMediaPlaybackClusterMediaSkipBackwardResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::MediaPlayback::Commands::MediaSkipBackwardResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPMediaPlaybackClusterMediaSkipForwardResponseCallback
    : public Callback::Callback<CHIPMediaPlaybackClusterMediaSkipForwardResponseCallbackType>
{
public:
    CHIPMediaPlaybackClusterMediaSkipForwardResponseCallback(jobject javaCallback);

    ~CHIPMediaPlaybackClusterMediaSkipForwardResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::MediaPlayback::Commands::MediaSkipForwardResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPMediaPlaybackClusterMediaStartOverResponseCallback
    : public Callback::Callback<CHIPMediaPlaybackClusterMediaStartOverResponseCallbackType>
{
public:
    CHIPMediaPlaybackClusterMediaStartOverResponseCallback(jobject javaCallback);

    ~CHIPMediaPlaybackClusterMediaStartOverResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::MediaPlayback::Commands::MediaStartOverResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPMediaPlaybackClusterMediaStopResponseCallback
    : public Callback::Callback<CHIPMediaPlaybackClusterMediaStopResponseCallbackType>
{
public:
    CHIPMediaPlaybackClusterMediaStopResponseCallback(jobject javaCallback);

    ~CHIPMediaPlaybackClusterMediaStopResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::MediaPlayback::Commands::MediaStopResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPNetworkCommissioningClusterAddThreadNetworkResponseCallback
    : public Callback::Callback<CHIPNetworkCommissioningClusterAddThreadNetworkResponseCallbackType>
{
public:
    CHIPNetworkCommissioningClusterAddThreadNetworkResponseCallback(jobject javaCallback);

    ~CHIPNetworkCommissioningClusterAddThreadNetworkResponseCallback();

    static void
    CallbackFn(void * context,
               const chip::app::Clusters::NetworkCommissioning::Commands::AddThreadNetworkResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPNetworkCommissioningClusterAddWiFiNetworkResponseCallback
    : public Callback::Callback<CHIPNetworkCommissioningClusterAddWiFiNetworkResponseCallbackType>
{
public:
    CHIPNetworkCommissioningClusterAddWiFiNetworkResponseCallback(jobject javaCallback);

    ~CHIPNetworkCommissioningClusterAddWiFiNetworkResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::NetworkCommissioning::Commands::AddWiFiNetworkResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPNetworkCommissioningClusterDisableNetworkResponseCallback
    : public Callback::Callback<CHIPNetworkCommissioningClusterDisableNetworkResponseCallbackType>
{
public:
    CHIPNetworkCommissioningClusterDisableNetworkResponseCallback(jobject javaCallback);

    ~CHIPNetworkCommissioningClusterDisableNetworkResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::NetworkCommissioning::Commands::DisableNetworkResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPNetworkCommissioningClusterEnableNetworkResponseCallback
    : public Callback::Callback<CHIPNetworkCommissioningClusterEnableNetworkResponseCallbackType>
{
public:
    CHIPNetworkCommissioningClusterEnableNetworkResponseCallback(jobject javaCallback);

    ~CHIPNetworkCommissioningClusterEnableNetworkResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::NetworkCommissioning::Commands::EnableNetworkResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPNetworkCommissioningClusterRemoveNetworkResponseCallback
    : public Callback::Callback<CHIPNetworkCommissioningClusterRemoveNetworkResponseCallbackType>
{
public:
    CHIPNetworkCommissioningClusterRemoveNetworkResponseCallback(jobject javaCallback);

    ~CHIPNetworkCommissioningClusterRemoveNetworkResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::NetworkCommissioning::Commands::RemoveNetworkResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPNetworkCommissioningClusterScanNetworksResponseCallback
    : public Callback::Callback<CHIPNetworkCommissioningClusterScanNetworksResponseCallbackType>
{
public:
    CHIPNetworkCommissioningClusterScanNetworksResponseCallback(jobject javaCallback);

    ~CHIPNetworkCommissioningClusterScanNetworksResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::NetworkCommissioning::Commands::ScanNetworksResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPNetworkCommissioningClusterUpdateThreadNetworkResponseCallback
    : public Callback::Callback<CHIPNetworkCommissioningClusterUpdateThreadNetworkResponseCallbackType>
{
public:
    CHIPNetworkCommissioningClusterUpdateThreadNetworkResponseCallback(jobject javaCallback);

    ~CHIPNetworkCommissioningClusterUpdateThreadNetworkResponseCallback();

    static void
    CallbackFn(void * context,
               const chip::app::Clusters::NetworkCommissioning::Commands::UpdateThreadNetworkResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPNetworkCommissioningClusterUpdateWiFiNetworkResponseCallback
    : public Callback::Callback<CHIPNetworkCommissioningClusterUpdateWiFiNetworkResponseCallbackType>
{
public:
    CHIPNetworkCommissioningClusterUpdateWiFiNetworkResponseCallback(jobject javaCallback);

    ~CHIPNetworkCommissioningClusterUpdateWiFiNetworkResponseCallback();

    static void
    CallbackFn(void * context,
               const chip::app::Clusters::NetworkCommissioning::Commands::UpdateWiFiNetworkResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPOtaSoftwareUpdateProviderClusterApplyUpdateResponseCallback
    : public Callback::Callback<CHIPOtaSoftwareUpdateProviderClusterApplyUpdateResponseCallbackType>
{
public:
    CHIPOtaSoftwareUpdateProviderClusterApplyUpdateResponseCallback(jobject javaCallback);

    ~CHIPOtaSoftwareUpdateProviderClusterApplyUpdateResponseCallback();

    static void
    CallbackFn(void * context,
               const chip::app::Clusters::OtaSoftwareUpdateProvider::Commands::ApplyUpdateResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPOtaSoftwareUpdateProviderClusterQueryImageResponseCallback
    : public Callback::Callback<CHIPOtaSoftwareUpdateProviderClusterQueryImageResponseCallbackType>
{
public:
    CHIPOtaSoftwareUpdateProviderClusterQueryImageResponseCallback(jobject javaCallback);

    ~CHIPOtaSoftwareUpdateProviderClusterQueryImageResponseCallback();

    static void
    CallbackFn(void * context,
               const chip::app::Clusters::OtaSoftwareUpdateProvider::Commands::QueryImageResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPOperationalCredentialsClusterAttestationResponseCallback
    : public Callback::Callback<CHIPOperationalCredentialsClusterAttestationResponseCallbackType>
{
public:
    CHIPOperationalCredentialsClusterAttestationResponseCallback(jobject javaCallback);

    ~CHIPOperationalCredentialsClusterAttestationResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::OperationalCredentials::Commands::AttestationResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPOperationalCredentialsClusterCertificateChainResponseCallback
    : public Callback::Callback<CHIPOperationalCredentialsClusterCertificateChainResponseCallbackType>
{
public:
    CHIPOperationalCredentialsClusterCertificateChainResponseCallback(jobject javaCallback);

    ~CHIPOperationalCredentialsClusterCertificateChainResponseCallback();

    static void
    CallbackFn(void * context,
               const chip::app::Clusters::OperationalCredentials::Commands::CertificateChainResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPOperationalCredentialsClusterNOCResponseCallback
    : public Callback::Callback<CHIPOperationalCredentialsClusterNOCResponseCallbackType>
{
public:
    CHIPOperationalCredentialsClusterNOCResponseCallback(jobject javaCallback);

    ~CHIPOperationalCredentialsClusterNOCResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::OperationalCredentials::Commands::NOCResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPOperationalCredentialsClusterOpCSRResponseCallback
    : public Callback::Callback<CHIPOperationalCredentialsClusterOpCSRResponseCallbackType>
{
public:
    CHIPOperationalCredentialsClusterOpCSRResponseCallback(jobject javaCallback);

    ~CHIPOperationalCredentialsClusterOpCSRResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::OperationalCredentials::Commands::OpCSRResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPScenesClusterAddSceneResponseCallback : public Callback::Callback<CHIPScenesClusterAddSceneResponseCallbackType>
{
public:
    CHIPScenesClusterAddSceneResponseCallback(jobject javaCallback);

    ~CHIPScenesClusterAddSceneResponseCallback();

    static void CallbackFn(void * context, const chip::app::Clusters::Scenes::Commands::AddSceneResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPScenesClusterGetSceneMembershipResponseCallback
    : public Callback::Callback<CHIPScenesClusterGetSceneMembershipResponseCallbackType>
{
public:
    CHIPScenesClusterGetSceneMembershipResponseCallback(jobject javaCallback);

    ~CHIPScenesClusterGetSceneMembershipResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::Scenes::Commands::GetSceneMembershipResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPScenesClusterRemoveAllScenesResponseCallback
    : public Callback::Callback<CHIPScenesClusterRemoveAllScenesResponseCallbackType>
{
public:
    CHIPScenesClusterRemoveAllScenesResponseCallback(jobject javaCallback);

    ~CHIPScenesClusterRemoveAllScenesResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::Scenes::Commands::RemoveAllScenesResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPScenesClusterRemoveSceneResponseCallback : public Callback::Callback<CHIPScenesClusterRemoveSceneResponseCallbackType>
{
public:
    CHIPScenesClusterRemoveSceneResponseCallback(jobject javaCallback);

    ~CHIPScenesClusterRemoveSceneResponseCallback();

    static void CallbackFn(void * context, const chip::app::Clusters::Scenes::Commands::RemoveSceneResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPScenesClusterStoreSceneResponseCallback : public Callback::Callback<CHIPScenesClusterStoreSceneResponseCallbackType>
{
public:
    CHIPScenesClusterStoreSceneResponseCallback(jobject javaCallback);

    ~CHIPScenesClusterStoreSceneResponseCallback();

    static void CallbackFn(void * context, const chip::app::Clusters::Scenes::Commands::StoreSceneResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPScenesClusterViewSceneResponseCallback : public Callback::Callback<CHIPScenesClusterViewSceneResponseCallbackType>
{
public:
    CHIPScenesClusterViewSceneResponseCallback(jobject javaCallback);

    ~CHIPScenesClusterViewSceneResponseCallback();

    static void CallbackFn(void * context, const chip::app::Clusters::Scenes::Commands::ViewSceneResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPTvChannelClusterChangeChannelResponseCallback
    : public Callback::Callback<CHIPTvChannelClusterChangeChannelResponseCallbackType>
{
public:
    CHIPTvChannelClusterChangeChannelResponseCallback(jobject javaCallback);

    ~CHIPTvChannelClusterChangeChannelResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::TvChannel::Commands::ChangeChannelResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPTargetNavigatorClusterNavigateTargetResponseCallback
    : public Callback::Callback<CHIPTargetNavigatorClusterNavigateTargetResponseCallbackType>
{
public:
    CHIPTargetNavigatorClusterNavigateTargetResponseCallback(jobject javaCallback);

    ~CHIPTargetNavigatorClusterNavigateTargetResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::TargetNavigator::Commands::NavigateTargetResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPTestClusterClusterBooleanResponseCallback : public Callback::Callback<CHIPTestClusterClusterBooleanResponseCallbackType>
{
public:
    CHIPTestClusterClusterBooleanResponseCallback(jobject javaCallback);

    ~CHIPTestClusterClusterBooleanResponseCallback();

    static void CallbackFn(void * context, const chip::app::Clusters::TestCluster::Commands::BooleanResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPTestClusterClusterTestAddArgumentsResponseCallback
    : public Callback::Callback<CHIPTestClusterClusterTestAddArgumentsResponseCallbackType>
{
public:
    CHIPTestClusterClusterTestAddArgumentsResponseCallback(jobject javaCallback);

    ~CHIPTestClusterClusterTestAddArgumentsResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::TestCluster::Commands::TestAddArgumentsResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPTestClusterClusterTestEnumsResponseCallback
    : public Callback::Callback<CHIPTestClusterClusterTestEnumsResponseCallbackType>
{
public:
    CHIPTestClusterClusterTestEnumsResponseCallback(jobject javaCallback);

    ~CHIPTestClusterClusterTestEnumsResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::TestCluster::Commands::TestEnumsResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPTestClusterClusterTestListInt8UReverseResponseCallback
    : public Callback::Callback<CHIPTestClusterClusterTestListInt8UReverseResponseCallbackType>
{
public:
    CHIPTestClusterClusterTestListInt8UReverseResponseCallback(jobject javaCallback);

    ~CHIPTestClusterClusterTestListInt8UReverseResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::TestCluster::Commands::TestListInt8UReverseResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPTestClusterClusterTestNullableOptionalResponseCallback
    : public Callback::Callback<CHIPTestClusterClusterTestNullableOptionalResponseCallbackType>
{
public:
    CHIPTestClusterClusterTestNullableOptionalResponseCallback(jobject javaCallback);

    ~CHIPTestClusterClusterTestNullableOptionalResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::TestCluster::Commands::TestNullableOptionalResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

class CHIPTestClusterClusterTestSpecificResponseCallback
    : public Callback::Callback<CHIPTestClusterClusterTestSpecificResponseCallbackType>
{
public:
    CHIPTestClusterClusterTestSpecificResponseCallback(jobject javaCallback);

    ~CHIPTestClusterClusterTestSpecificResponseCallback();

    static void CallbackFn(void * context,
                           const chip::app::Clusters::TestCluster::Commands::TestSpecificResponse::DecodableType & data);

private:
    jobject javaCallbackRef;
};

} // namespace chip
