/*
 Copyright 2023-2026 LunarG, Inc.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#include "logger.h"
#include "util.h"

#include <cassert>
#include <cstdarg>
#include <iostream>

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
#include <android/log.h>
#endif

#include <vulkan/vk_enum_string_helper.h>
#include <vulkan/utility/vk_struct_helper.hpp>

namespace crash_diagnostic_layer {

LogCallback::LogCallback(const VkDebugUtilsMessengerCreateInfoEXT& ci)
    : severity_mask_(ci.messageSeverity),
      type_mask_(ci.messageType),
      user_data_(ci.pUserData),
      utils_cb_(ci.pfnUserCallback) {}

static VkDebugUtilsMessageSeverityFlagsEXT GetUtilsSeverity(VkDebugReportFlagsEXT flags) {
    VkDebugUtilsMessageSeverityFlagsEXT severity = 0;
    if (flags & VK_DEBUG_REPORT_DEBUG_BIT_EXT) {
        severity |= VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT;
    }
    if (flags & VK_DEBUG_REPORT_INFORMATION_BIT_EXT) {
        severity |= VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT;
    }
    if (flags & VK_DEBUG_REPORT_WARNING_BIT_EXT) {
        severity |= VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT;
    }
    if (flags & VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT) {
        severity |= VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT;
    }
    if (flags & VK_DEBUG_REPORT_ERROR_BIT_EXT) {
        severity |= VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
    }
    return severity;
}

static VkDebugUtilsMessageTypeFlagsEXT GetUtilsType(VkDebugReportFlagsEXT flags) {
    VkDebugUtilsMessageTypeFlagsEXT type = 0;
    if (flags & VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT) {
        type |= VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
    }
    if (flags & (VK_DEBUG_REPORT_DEBUG_BIT_EXT | VK_DEBUG_REPORT_INFORMATION_BIT_EXT | VK_DEBUG_REPORT_WARNING_BIT_EXT |
                 VK_DEBUG_REPORT_ERROR_BIT_EXT)) {
        type |= VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT;
    }
    return type;
}

LogCallback::LogCallback(const VkDebugReportCallbackCreateInfoEXT& ci)
    : severity_mask_(GetUtilsSeverity(ci.flags)),
      type_mask_(GetUtilsType(ci.flags)),
      user_data_(ci.pUserData),
      report_cb_(ci.pfnCallback) {}

static VkDebugReportFlagsEXT GetReportFlags(VkDebugUtilsMessageSeverityFlagBitsEXT severity,
                                            VkDebugUtilsMessageTypeFlagsEXT type) {
    VkDebugReportFlagsEXT flags = 0;
    if (severity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT) {
        flags |= VK_DEBUG_REPORT_DEBUG_BIT_EXT;
    }
    if (severity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT) {
        flags |= VK_DEBUG_REPORT_INFORMATION_BIT_EXT;
    }
    if (severity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT) {
        if (type & VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT) {
            flags |= VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT;
        } else {
            flags |= VK_DEBUG_REPORT_WARNING_BIT_EXT;
        }
    }
    if (severity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT) {
        flags |= VK_DEBUG_REPORT_ERROR_BIT_EXT;
    }
    return flags;
}

void LogCallback::Log(VkDebugUtilsMessageSeverityFlagBitsEXT severity, VkDebugUtilsMessageTypeFlagsEXT type,
                      const VkDebugUtilsMessengerCallbackDataEXT* cb_data) const {
    if (utils_cb_) {
        utils_cb_(severity, type, cb_data, user_data_);
    } else {
        VkDebugUtilsMessageTypeFlagsEXT flags = GetReportFlags(severity, type);

        report_cb_(flags, VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT, 0ull, 0, 0, "CDL", cb_data->pMessage, user_data_);
    }
}

Logger::Logger()
    : default_cb_(vku::InitStruct<VkDebugUtilsMessengerCreateInfoEXT>(
          nullptr, 0, severity_mask_, VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT, DefaultLogCallback, this)),
      log_stream_(&std::cerr) {
}

Logger::~Logger() { this->CloseLogFile(); }

void Logger::Init(const VkInstanceCreateInfo* pCreateInfo, const Timepoint& start_time, const Settings& settings) {
    this->start_time_ = start_time;

    // Possibly create messengers for the application to recieve messages from us.
    // Note that since there aren't real handles for these messengers, we're using the create info pointers
    // as fake handles so that they can go into the logger callback map.
    auto* pnext = pCreateInfo->pNext;
    while (auto* utils_ci = vku::FindStructInPNextChain<VkDebugUtilsMessengerCreateInfoEXT>(pnext)) {
        this->AddLogCallback(utils_ci, *utils_ci);
        pnext = utils_ci->pNext;
    }
    pnext = pCreateInfo->pNext;
    while (auto* report_ci = vku::FindStructInPNextChain<VkDebugReportCallbackCreateInfoEXT>(pnext)) {
        this->AddLogCallback(report_ci, *report_ci);
        pnext = report_ci->pNext;
    }
}

void Logger::LogToStderr() {
    CloseLogFile();

    std::lock_guard<std::mutex> lock(file_access_mutex_);
    log_stream_ = &std::cerr;
}

void Logger::LogToStdout() {
    CloseLogFile();

    std::lock_guard<std::mutex> lock(file_access_mutex_);
    log_stream_ = &std::cout;
}

bool Logger::OpenLogFile(const std::filesystem::path& path) {
    CloseLogFile();

    std::lock_guard<std::mutex> lock(file_access_mutex_);

    log_file_.open(path, std::ios::ate);
    if (!log_file_.is_open()) {
        std::cerr << "Failed to open log file: " << path << std::endl;
        return false;
    }
    log_file_ << std::unitbuf;
    log_stream_ = &log_file_;
    return true;
}

void Logger::CloseLogFile() {
    std::lock_guard<std::mutex> lock(file_access_mutex_);
    log_file_.close();
    log_stream_ = nullptr;
}

void Logger::UpdateSeverityMask() {
    // rebuild the severity mask from scratch
    severity_mask_ = default_cb_.SeverityMask();
    for (const auto& item : log_cbs_) {
        if (item.second.TypeMask() & kMessageType) {
            severity_mask_ |= item.second.SeverityMask();
        }
    }
}

void Logger::SetSeverity(VkDebugUtilsMessageSeverityFlagsEXT mask) {
    std::lock_guard<std::mutex> lock(file_access_mutex_);
    default_cb_.SetSeverityMask(mask);
    UpdateSeverityMask();
}

void Logger::SetApiTrace(MessageApiTraceFlags mask) {
    std::lock_guard<std::mutex> lock(file_access_mutex_);
    this->log_api_trace_mask_ = mask; // TODO
}

void Logger::Error(const char* format, ...) const {
    va_list argptr;
    va_start(argptr, format);
    Log(VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT, format, argptr);
    va_end(argptr);
}

void Logger::Error(const std::string& msg) const { Log(VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT, msg); }

void Logger::Warning(const char* format, ...) const {
    va_list argptr;
    va_start(argptr, format);
    Log(VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT, format, argptr);
    va_end(argptr);
}

void Logger::Warning(const std::string& msg) const { Log(VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT, msg); }

void Logger::Info(const char* format, ...) const {
    va_list argptr;
    va_start(argptr, format);
    Log(VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT, format, argptr);
    va_end(argptr);
}

void Logger::Info(const std::string& msg) const { Log(VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT, msg); }

void Logger::Verbose(const char* format, ...) const {
    va_list argptr;
    va_start(argptr, format);
    Log(VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT, format, argptr);
    va_end(argptr);
}

void Logger::Verbose(const std::string& msg) const { Log(VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT, msg); }

void Logger::InfoPreApiFunction(const char* api_name) const {
    if (this->log_api_trace_mask_ & MESSAGE_API_TRACE_COMMON_BIT) {
        this->Info("{ %s", api_name);
    }
}

void Logger::InfoPostApiFunction(const char* api_name) const {
    if (this->log_api_trace_mask_ & MESSAGE_API_TRACE_COMMON_BIT) {
        this->Info("} %s", api_name);
    }
}

void Logger::InfoPostApiFunction(const char* api_name, VkResult result) const {
    if (this->log_api_trace_mask_ & MESSAGE_API_TRACE_COMMON_BIT) {
        this->Info("} %s (%s)", api_name, string_VkResult(result));
    }
}

void Logger::Log(VkDebugUtilsMessageSeverityFlagBitsEXT severity, const char* format, va_list argptr) const {
    {
        std::shared_lock<std::shared_mutex> guard(log_cb_mutex_);
        if ((severity & severity_mask_) == 0) {
            return;
        }
    }
    // vsnprintf() returns the number of characters that *would* have been printed, if there was
    // enough space. If we have a huge message, reallocate the string and try again.
    std::string msg(256, '\0');
    size_t old_size = msg.size();
    // The va_list will be destroyed by the call to vsnprintf(), so use a copy in case we need
    // to try again.
    va_list arg_copy;
    va_copy(arg_copy, argptr);
    int result = vsnprintf(msg.data(), msg.size(), format, arg_copy);
    va_end(arg_copy);
    assert(result >= 0);
    if (result < 0) {
        msg = "Message generation failure";
    } else if (static_cast<size_t>(result) <= old_size) {
        msg.resize(static_cast<size_t>(result));
    } else {
        // Grow buffer to fit needed size. Note that the input size to vsnprintf() must
        // include space for the trailing '\0' character, but the return value DOES NOT
        // include the `\0' character.
        msg.resize(static_cast<size_t>(result) + 1);
        // consume the va_list passed to us by the caller
        result = vsnprintf(msg.data(), msg.size(), format, argptr);
        // remove the `\0' character from the string
        msg.resize(static_cast<size_t>(result));
    }
    Log(severity, msg);
}

void Logger::Log(VkDebugUtilsMessageSeverityFlagBitsEXT severity, const std::string& message) const {
    auto cb_data = vku::InitStruct<VkDebugUtilsMessengerCallbackDataEXT>();
    cb_data.pMessageIdName = "CDL";
    cb_data.messageIdNumber = 1;
    cb_data.pMessage = message.c_str();
    // TODO: queueLabelCount, pQueueLabels
    // TODO: cmdBufLabelCount, pCmdBufLabels
    // TODO: objectCount pObjects;

    std::shared_lock<std::shared_mutex> guard(log_cb_mutex_);
    if ((severity & severity_mask_) == 0) {
        return;
    }
    for (auto& entry : log_cbs_) {
        auto& logger = entry.second;
        if ((logger.TypeMask() & kMessageType) && (logger.SeverityMask() & severity)) {
            logger.Log(severity, kMessageType, &cb_data);
        }
    }
    default_cb_.Log(severity, kMessageType, &cb_data);
}

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
VKAPI_ATTR VkBool32 VKAPI_CALL Logger::DefaultLogCallback(VkDebugUtilsMessageSeverityFlagBitsEXT severity,
                                                          VkDebugUtilsMessageTypeFlagsEXT types,
                                                          const VkDebugUtilsMessengerCallbackDataEXT* cb_data,
                                                          void* user_data) {
    android_LogPriority prio = ANDROID_LOG_INFO;
    if (severity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT) {
        prio = ANDROID_LOG_ERROR;
    } else if (severity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT) {
        prio = ANDROID_LOG_WARN;
    } else if (severity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT) {
        prio = ANDROID_LOG_INFO;
    } else if (severity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT) {
        prio = ANDROID_LOG_VERBOSE;
    }
    __android_log_write(prio, "CDL", cb_data->pMessage);
    return VK_FALSE;
}
#else   // !ANDROID
VKAPI_ATTR VkBool32 VKAPI_CALL Logger::DefaultLogCallback(VkDebugUtilsMessageSeverityFlagBitsEXT severity,
                                                          VkDebugUtilsMessageTypeFlagsEXT types,
                                                          const VkDebugUtilsMessengerCallbackDataEXT* cb_data,
                                                          void* user_data) {
    const Logger& logger = *reinterpret_cast<Logger*>(user_data);
    const char* tag = "CDL INFO";
    if (severity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT) {
        tag = "CDL ERROR";
    } else if (severity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT) {
        tag = "CDL WARNING";
    } else if (severity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT) {
        tag = "CDL INFO";
    } else if (severity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT) {
        tag = "CDL VERBOSE";
    }
    auto elapsed = std::chrono::system_clock::now() - logger.StartTime();
    std::string timestamp = DurationToStr(elapsed);

    std::lock_guard<std::mutex> lock(logger.file_access_mutex_);
    if (logger.log_stream_) {
        *logger.log_stream_ << timestamp << " " << tag << ": " << cb_data->pMessage << std::endl;
    }
    return VK_FALSE;
}
#endif

}  // namespace crash_diagnostic_layer
