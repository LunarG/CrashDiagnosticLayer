/*
 * Copyright (c) 2015-2024 The Khronos Group Inc.
 * Copyright (c) 2015-2024 Valve Corporation
 * Copyright (c) 2015-2024 LunarG, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "error_monitor.h"
#include "test_fixtures.h"

#ifdef VK_USE_PLATFORM_ANDROID_KHR
// Note. VK_EXT_debug_report is deprecated by the VK_EXT_debug_utils extension.
// However, we still support this old extension due to CI running old Android devices.
static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(VkDebugReportFlagsEXT message_flags, VkDebugReportObjectTypeEXT,
                                                    uint64_t, size_t, int32_t, const char *prefix, const char *message,
                                                    void *user_data) {
    auto *error_monitor = reinterpret_cast<ErrorMonitor *>(user_data);

    if (error_monitor.GetPrefix() == prefix && message_flags & error_monitor->GetMessageFlags()) {
        return error_monitor->CheckForDesiredMsg(message);
    }
    return VK_FALSE;
}
#else

static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT message_severity,
                                                    VkDebugUtilsMessageTypeFlagsEXT message_types,
                                                    const VkDebugUtilsMessengerCallbackDataEXT *callback_data,
                                                    void *user_data) {
    const char *message = callback_data->pMessage;
    auto *error_monitor = reinterpret_cast<ErrorMonitor *>(user_data);

    if (error_monitor->GetPrefix() == callback_data->pMessageIdName) {
        if (ErrorMonitor::SeverityBits(message_severity) & error_monitor->GetMessageFlags()) {
            return error_monitor->CheckForDesiredMsg(message);
        } else if (error_monitor->PrintAllMessages()) {
            std::cout << message << std::endl;
        }
    }
    return VK_FALSE;
}
#endif

ErrorMonitor::ErrorMonitor(const char *prefix, bool print_all_errors)
    :
#if !defined(VK_USE_PLATFORM_ANDROID_KHR)
      debug_create_info_({},
                         SeverityBits::eError | SeverityBits::eWarning | SeverityBits::eInfo | SeverityBits::eVerbose,
                         vk::DebugUtilsMessageTypeFlagBitsEXT::eGeneral, DebugCallback, this),
#else
      debug_create_info_({}, Severity::eError | Severity::eWarning | Severity::eInfo | Severity::eVerbose,
                         DebugCallback, this),
#endif
      msg_prefix_(prefix),
      print_all_errors_(print_all_errors) {
}
void ErrorMonitor::MonitorReset() {
    message_flags_ = SeverityBits::eError;
    bailout_ = nullptr;
    message_found_ = false;
    failure_message_strings_.clear();
    desired_message_strings_.clear();
    ignore_message_strings_.clear();
    allowed_message_strings_.clear();
}

void ErrorMonitor::Reset() {
    auto guard = Lock();
    MonitorReset();
}

void ErrorMonitor::SetDesiredFailureMsg(const ErrorMonitor::Severity msg_flags, const std::string &msg) {
    SetDesiredFailureMsg(msg_flags, msg.c_str());
}

void ErrorMonitor::SetDesiredFailureMsg(const ErrorMonitor::Severity msg_flags, const char *const msg_string) {
    if (NeedCheckSuccess()) {
        VerifyNotFound();
    }

    auto guard = Lock();
    desired_message_strings_.insert(msg_string);
    message_flags_ |= msg_flags;
}

void ErrorMonitor::SetDesiredError(const char *msg, uint32_t count) {
    for (uint32_t i = 0; i < count; i++) {
        SetDesiredFailureMsg(SeverityBits::eError, msg);
    }
}

void ErrorMonitor::SetAllowedFailureMsg(const char *const msg) {
    auto guard = Lock();
    allowed_message_strings_.emplace_back(msg);
}

void ErrorMonitor::SetUnexpectedError(const char *const msg) {
    if (NeedCheckSuccess()) {
        VerifyNotFound();
    }
    auto guard = Lock();
    ignore_message_strings_.emplace_back(msg);
}

VkBool32 ErrorMonitor::CheckForDesiredMsg(const char *const msg_string) {
    VkBool32 result = VK_FALSE;
    auto guard = Lock();
    if (bailout_ != nullptr) {
        *bailout_ = true;
    }
    std::string error_string(msg_string);
    bool found_expected = false;

    if (print_all_errors_) {
        std::cout << error_string << std::endl;
    }
    if (!IgnoreMessage(error_string)) {
        for (auto desired_msg_it = desired_message_strings_.begin(); desired_msg_it != desired_message_strings_.end();
             ++desired_msg_it) {
            if (error_string.find(*desired_msg_it) != std::string::npos) {
                found_expected = true;
                failure_message_strings_.insert(error_string);
                message_found_ = true;
                result = VK_TRUE;
                // Remove a maximum of one failure message from the set
                // Multiset mutation is acceptable because `break` causes flow of control to exit the for loop
                desired_message_strings_.erase(desired_msg_it);
                break;
            }
        }

        if (!found_expected && !allowed_message_strings_.empty()) {
            for (auto allowed_msg_it = allowed_message_strings_.begin();
                 allowed_msg_it != allowed_message_strings_.end(); ++allowed_msg_it) {
                if (error_string.find(*allowed_msg_it) != std::string::npos) {
                    found_expected = true;
                    break;
                }
            }
        }

        if (!found_expected) {
            result = VK_TRUE;
            ADD_FAILURE() << error_string;
        }
    }
    return result;
}

ErrorMonitor::Severity ErrorMonitor::GetMessageFlags() const {
    auto guard = Lock();
    return message_flags_;
}

bool ErrorMonitor::AnyDesiredMsgFound() const { return message_found_; }

void ErrorMonitor::SetError(const char *const errorString) {
    auto guard = Lock();
    message_found_ = true;
    failure_message_strings_.insert(errorString);
}

void ErrorMonitor::SetBailout(std::atomic<bool> *bailout) {
    auto guard = Lock();
    bailout_ = bailout;
}

void ErrorMonitor::ExpectSuccess(const ErrorMonitor::Severity message_flag_mask) {
    // Match ANY message matching specified type
    auto guard = Lock();
    desired_message_strings_.clear();
    message_flags_ = message_flag_mask;
}

bool ErrorMonitor::ExpectingSuccess() const {
    return (desired_message_strings_.size() == 1) &&
           (desired_message_strings_.count("") == 1 && ignore_message_strings_.empty());
}

bool ErrorMonitor::NeedCheckSuccess() const { return ExpectingSuccess(); }

void ErrorMonitor::VerifyFound() {
    {
        // The lock must be released before the ExpectSuccess call at the end
        auto guard = Lock();
        // Not receiving expected message(s) is a failure.
        if (!desired_message_strings_.empty()) {
            for (const auto &desired_msg : desired_message_strings_) {
                ADD_FAILURE() << "Did not receive expected error '" << desired_msg << "'";
            }
        }
        MonitorReset();
    }

    ExpectSuccess();
}

void ErrorMonitor::Finish() {
    VerifyNotFound();
    Reset();
}

void ErrorMonitor::VerifyNotFound() {
    auto guard = Lock();
    // ExpectSuccess() configured us to match anything. Any error is a failure.
    if (AnyDesiredMsgFound()) {
        for (const auto &msg : failure_message_strings_) {
            ADD_FAILURE() << "Expected to succeed but got error: " << msg;
        }
    }
    MonitorReset();
}

bool ErrorMonitor::IgnoreMessage(std::string const &msg) const {
    if (ignore_message_strings_.empty()) {
        return false;
    }

    return std::find_if(ignore_message_strings_.begin(), ignore_message_strings_.end(), [&msg](std::string const &str) {
               return msg.find(str) != std::string::npos;
           }) != ignore_message_strings_.end();
}
