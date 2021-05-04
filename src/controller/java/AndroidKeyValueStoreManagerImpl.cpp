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
#include <platform/KeyValueStoreManager.h>

#include <algorithm>
#include <string.h>

#include "CHIPJNIError.h"
#include "JniReferences.h"
#include "JniTypeWrappers.h"

#include <support/Base64.h>
#include <support/CodeUtils.h>
#include <support/logging/CHIPLogging.h>

namespace chip {
namespace DeviceLayer {
namespace PersistedStorage {
namespace {

constexpr size_t kMaxKvsValueBytes        = 1024;
constexpr size_t kMaxKvsValueEncodedChars = BASE64_ENCODED_LEN(kMaxKvsValueBytes) + 1;

} // namespace

KeyValueStoreManagerImpl KeyValueStoreManagerImpl::sInstance;

CHIP_ERROR KeyValueStoreManagerImpl::_Get(const char * key, void * value, size_t value_size, size_t * read_bytes_size,
                                          size_t offset)
{
    ReturnErrorCodeIf(mKeyValueStoreManagerClass == nullptr, CHIP_ERROR_INCORRECT_STATE);
    ReturnErrorCodeIf(mGetMethod == nullptr, CHIP_ERROR_INCORRECT_STATE);
    ReturnErrorCodeIf(offset != 0, CHIP_ERROR_INVALID_ARGUMENT);

    JNIEnv * env = GetEnvForCurrentThread();
    ReturnErrorCodeIf(env == nullptr, CHIP_ERROR_INTERNAL);

    UtfString javaKey(env, key);

    jobject javaValue = env->CallStaticObjectMethod(mKeyValueStoreManagerClass, mGetMethod, javaKey.jniValue());
    if (env->ExceptionCheck())
    {
        ChipLogError(DeviceLayer, "Java exception in KVS::Get");
        env->ExceptionDescribe();
        return CHIP_JNI_ERROR_EXCEPTION_THROWN;
    }

    if (javaValue == nullptr)
    {
        return CHIP_ERROR_KEY_NOT_FOUND;
    }

    JniUtfString utfValue(env, (jstring) javaValue);
    if (strlen(utfValue.c_str()) > kMaxKvsValueEncodedChars)
    {
        ChipLogError(DeviceLayer, "Unexpected large value received from KVS");
        return CHIP_ERROR_NO_MEMORY;
    }

    uint8_t buffer[kMaxKvsValueBytes];
    uint16_t decodedLength = chip::Base64Decode(utfValue.c_str(), strlen(utfValue.c_str()), buffer);
    if (decodedLength == UINT16_MAX)
    {
        ChipLogError(DeviceLayer, "KVS base64 decoding failed");
        return CHIP_ERROR_INTEGRITY_CHECK_FAILED;
    }

    if (read_bytes_size != nullptr)
    {
        *read_bytes_size = decodedLength;
    }

    if (value != nullptr)
    {
        memcpy(value, buffer, std::min<size_t>(value_size, decodedLength));
    }

    return CHIP_NO_ERROR;
}

CHIP_ERROR KeyValueStoreManagerImpl::_Delete(const char * key)
{
    ReturnErrorCodeIf(mKeyValueStoreManagerClass == nullptr, CHIP_ERROR_INCORRECT_STATE);
    ReturnErrorCodeIf(mDeleteMethod == nullptr, CHIP_ERROR_INCORRECT_STATE);

    JNIEnv * env = GetEnvForCurrentThread();
    ReturnErrorCodeIf(env == nullptr, CHIP_ERROR_INTERNAL);

    UtfString javaKey(env, key);

    env->CallStaticVoidMethod(mKeyValueStoreManagerClass, mDeleteMethod, javaKey.jniValue());

    if (env->ExceptionCheck())
    {
        ChipLogError(DeviceLayer, "Java exception in KVS::Delete");
        env->ExceptionDescribe();
        env->ExceptionClear();
        return CHIP_JNI_ERROR_EXCEPTION_THROWN;
    }

    return CHIP_NO_ERROR;
}

CHIP_ERROR KeyValueStoreManagerImpl::_Put(const char * key, const void * value, size_t value_size)
{
    ReturnErrorCodeIf(mKeyValueStoreManagerClass == nullptr, CHIP_ERROR_INCORRECT_STATE);
    ReturnErrorCodeIf(mSetMethod == nullptr, CHIP_ERROR_INCORRECT_STATE);
    ReturnErrorCodeIf(value_size > kMaxKvsValueBytes, CHIP_ERROR_INVALID_ARGUMENT);

    JNIEnv * env = GetEnvForCurrentThread();
    ReturnErrorCodeIf(env == nullptr, CHIP_ERROR_INTERNAL);

    char base64Buffer[kMaxKvsValueEncodedChars];

    size_t length = chip::Base64Encode(static_cast<const uint8_t *>(value), value_size, base64Buffer);

    base64Buffer[length] = 0;

    UtfString utfKey(env, key);
    UtfString utfBase64Value(env, base64Buffer);

    env->CallStaticVoidMethod(mKeyValueStoreManagerClass, mSetMethod, utfKey.jniValue(), utfBase64Value.jniValue());

    if (env->ExceptionCheck())
    {
        ChipLogError(DeviceLayer, "Java exception in KVS::Delete");
        env->ExceptionDescribe();
        env->ExceptionClear();
        return CHIP_JNI_ERROR_EXCEPTION_THROWN;
    }

    return CHIP_NO_ERROR;
}

JNIEnv * KeyValueStoreManagerImpl::GetEnvForCurrentThread()
{
    if (mJvm == nullptr)
    {
        ChipLogError(DeviceLayer, "Missing Java VM in persistent storage");
        return nullptr;
    }

    JNIEnv * env = nullptr;

    jint err = mJvm->AttachCurrentThread(&env, nullptr);
    if (err != JNI_OK)
    {
        ChipLogError(DeviceLayer, "Failed to get JNIEnv for the current thread");
        return nullptr;
    }

    return env;
}

void KeyValueStoreManagerImpl::InitializeMethodForward(JavaVM * vm, JNIEnv * env)
{
    mJvm = vm;

    CHIP_ERROR err = GetClassRef(env, "chip/devicecontroller/KeyValueStoreManager", mKeyValueStoreManagerClass);
    if (err != CHIP_NO_ERROR)
    {
        ChipLogError(DeviceLayer, "Failed to get reference to KeyValueStoreManager");
        return;
    }

    mGetMethod = env->GetStaticMethodID(mKeyValueStoreManagerClass, "get", "(Ljava/lang/String;)Ljava/lang/String;");
    if (mGetMethod == nullptr)
    {
        ChipLogError(DeviceLayer, "Failed to access KVS 'get' method");
        env->ExceptionClear();
    }

    mSetMethod = env->GetStaticMethodID(mKeyValueStoreManagerClass, "set", "(Ljava/lang/String;Ljava/lang/String;)V");
    if (mSetMethod == nullptr)
    {
        ChipLogError(DeviceLayer, "Failed to access KVS 'set' method");
        env->ExceptionClear();
    }

    mDeleteMethod = env->GetStaticMethodID(mKeyValueStoreManagerClass, "delete", "(Ljava/lang/String;)V");
    if (mDeleteMethod == nullptr)
    {
        ChipLogError(DeviceLayer, "Failed to access KVS 'delete' method");
        env->ExceptionClear();
    }
}

} // namespace PersistedStorage
} // namespace DeviceLayer
} // namespace chip
