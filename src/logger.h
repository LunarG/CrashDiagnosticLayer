/*
 Copyright (c) 2023-2024 LunarG, Inc.

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

#pragma once

#include <chrono>
#include <filesystem>
#include <map>
#include <mutex>
#include <cstdio>
#include <string>
#include <shared_mutex>
#include <vulkan/vulkan_core.h>

namespace crash_diagnostic_layer {

class LogCallback {
   public:
    LogCallback(const VkDebugUtilsMessengerCreateInfoEXT& ci);
    LogCallback(const VkDebugReportCallbackCreateInfoEXT& ci);

    void Log(VkDebugUtilsMessageSeverityFlagBitsEXT severity, VkDebugUtilsMessageTypeFlagsEXT types,
             const VkDebugUtilsMessengerCallbackDataEXT* cb_data) const;

    VkDebugUtilsMessageSeverityFlagsEXT SeverityMask() const { return severity_mask_; }
    void SetSeverityMask(VkDebugUtilsMessageSeverityFlagsEXT mask) { severity_mask_ = mask; }
    VkDebugUtilsMessageTypeFlagsEXT TypeMask() const { return type_mask_; };

   private:
    VkDebugUtilsMessageSeverityFlagsEXT severity_mask_{0};
    VkDebugUtilsMessageTypeFlagsEXT type_mask_{0};
    void* user_data_{nullptr};
    PFN_vkDebugUtilsMessengerCallbackEXT utils_cb_{nullptr};
    PFN_vkDebugReportCallbackEXT report_cb_{nullptr};
};

class Logger {
   public:
    using Timepoint = std::chrono::time_point<std::chrono::system_clock>;

    Logger(const Timepoint& start_time);
    Logger(Logger&) = delete;
    Logger& operator=(Logger&) = delete;
    ~Logger();

    void LogToStdout();
    void LogToStderr();
    bool OpenLogFile(const std::filesystem::path& log_file);
    void CloseLogFile();
    const Timepoint& StartTime() const { return start_time_; }

    void SetSeverity(VkDebugUtilsMessageSeverityFlagsEXT mask);

    void Error(const char* format, ...) const;
    void Error(const std::string& message) const;

    void Warning(const char* format, ...) const;
    void Warning(const std::string& message) const;

    void Info(const char* format, ...) const;
    void Info(const std::string& message) const;

    void Verbose(const char* format, ...) const;
    void Verbose(const std::string& message) const;

    template <typename Handle, typename CreateInfo>
    void AddLogCallback(Handle handle, const CreateInfo& create_info) {
        std::lock_guard<std::shared_mutex> guard(log_cb_mutex_);
        LogCallback cb(create_info);
        log_cbs_.emplace(std::make_pair(uint64_t(handle), std::move(cb)));
        UpdateSeverityMask();
    }

    template <typename Handle>
    void RemoveLogCallback(Handle handle) {
        std::lock_guard<std::shared_mutex> guard(log_cb_mutex_);
        log_cbs_.erase(uint64_t(handle));
        UpdateSeverityMask();
    }

   private:
    static constexpr VkDebugUtilsMessageTypeFlagsEXT kMessageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT;
    void Log(VkDebugUtilsMessageSeverityFlagBitsEXT severity, const char* format, va_list argptr) const;
    void Log(VkDebugUtilsMessageSeverityFlagBitsEXT severity, const std::string& msg) const;

    static VKAPI_ATTR VkBool32 VKAPI_CALL DefaultLogCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                                             VkDebugUtilsMessageTypeFlagsEXT messageTypes,
                                                             const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
                                                             void* pUserData);
    void UpdateSeverityMask();

    const Timepoint start_time_;

    mutable std::shared_mutex log_cb_mutex_;
    std::map<uint64_t, LogCallback> log_cbs_;
    VkDebugUtilsMessageSeverityFlagsEXT severity_mask_{VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT |
                                                       VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
                                                       VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT};

    // default logging state
    LogCallback default_cb_;
    mutable FILE* log_file_{nullptr};
    mutable std::mutex file_access_mutex_;
};

}  // namespace crash_diagnostic_layer
