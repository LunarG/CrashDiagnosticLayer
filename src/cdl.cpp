/*
 Copyright 2018 Google Inc.
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

#include "cdl.h"
#include "util.h"
#include <regex>

#if defined(WIN32)
// For OutputDebugString
#include <process.h>
#include <windows.h>
#else
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/un.h>
#endif

#include <algorithm>
#include <chrono>
#include <fstream>
#include <inttypes.h>
#include <iostream>
#include <memory>
#include <sstream>

#include <vulkan/utility/vk_struct_helper.hpp>
#include <vulkan/vk_enum_string_helper.h>

#include <yaml-cpp/emitter.h>

#if defined(WIN32)
#include <direct.h>
#endif

namespace crash_diagnostic_layer {

const std::string kCdlVersion = std::to_string(VK_VERSION_MAJOR(VK_HEADER_VERSION_COMPLETE)) + "." +
                                std::to_string(VK_VERSION_MINOR(VK_HEADER_VERSION_COMPLETE)) + "." +
                                std::to_string(VK_VERSION_PATCH(VK_HEADER_VERSION_COMPLETE));
namespace settings {
const char* kOutputPath = "output_path";
const char* kTraceOn = "trace_on";
const char* kLogFile = "log_file";
enum LogOutputs {
    kNone,
    kStderr,
    kStdout,
};
static const std::unordered_map<std::string, LogOutputs> kLogFileValues{
    {"none", LogOutputs::kNone},
    {"stderr", LogOutputs::kStderr},
    {"stdout", LogOutputs::kStdout},
};
const char* kMessageSeverity = "message_severity";
static const std::unordered_map<std::string, VkDebugUtilsMessageSeverityFlagBitsEXT> kSeverityValues{
    {"error", VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT},
    {"warn", VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT},
    {"info", VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT},
    {"verbose", VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT},
};
const char* kDumpCommands = "dump_commands";
const char* kDumpCommandBuffers = "dump_command_buffers";
const char* kDumpQueueSubmits = "dump_queue_submits";
static const std::unordered_map<std::string, DumpCommands> kDumpCommandsValues{
    {"running", DumpCommands::kRunning},
    {"pending", DumpCommands::kPending},
    {"all", DumpCommands::kAll},
};

const char* kDumpShaders = "dump_shaders";
static const std::unordered_map<std::string, DumpShaders> kDumpShadersValues{
    {"off", DumpShaders::kOff},
    {"on_crash", DumpShaders::kOnCrash},
    {"on_bind", DumpShaders::kOnBind},
    {"all", DumpShaders::kAll},
};

const char* kWatchdogTimeout = "watchdog_timeout_ms";
const char* kDumpAllCommandBuffers = "dump_all_command_buffers";
const char* kTrackSemaphores = "track_semaphores";
const char* kTraceAllSemaphores = "trace_all_semaphores";
const char* kInstrumentAllCommands = "instrument_all_commands";
const char* kSyncAfterCommands = "sync_after_commands";
}  // namespace settings

const char* kLogTimeTag = "%Y-%m-%d-%H%M%S";

template <class T>
void GetEnvVal(VkuLayerSettingSet settings, const char* name, T& value) {
    if (vkuHasLayerSetting(settings, name)) {
        vkuGetLayerSettingValue(settings, name, value);
    }
}

template <class T>
void GetEnumVal(Logger& log, VkuLayerSettingSet settings, const char* name, T& value,
                const std::unordered_map<std::string, T>& value_map) {
    std::string value_string;
    GetEnvVal<std::string>(settings, name, value_string);
    if (!value_string.empty()) {
        auto iter = value_map.find(value_string);
        if (iter != value_map.end()) {
            value = iter->second;
        } else {
            log.Error("Bad value for %s setting: \"%s\"", name, value_string.c_str());
        }
    }
}

Settings::Settings(VkuLayerSettingSet layer_settings, Logger& log) {
    GetEnvVal<std::string>(layer_settings, settings::kOutputPath, output_path);
    GetEnvVal<bool>(layer_settings, settings::kTraceOn, trace_all);
    GetEnumVal<DumpCommands>(log, layer_settings, settings::kDumpQueueSubmits, dump_queue_submits,
                             settings::kDumpCommandsValues);
    GetEnumVal<DumpCommands>(log, layer_settings, settings::kDumpCommandBuffers, dump_command_buffers,
                             settings::kDumpCommandsValues);
    GetEnumVal<DumpCommands>(log, layer_settings, settings::kDumpCommands, dump_commands,
                             settings::kDumpCommandsValues);
    GetEnumVal<DumpShaders>(log, layer_settings, settings::kDumpShaders, dump_shaders, settings::kDumpShadersValues);
    GetEnvVal<uint64_t>(layer_settings, settings::kWatchdogTimeout, watchdog_timer_ms);
    GetEnvVal<bool>(layer_settings, settings::kTrackSemaphores, track_semaphores);
    GetEnvVal<bool>(layer_settings, settings::kTraceAllSemaphores, trace_all_semaphores);
    GetEnvVal<bool>(layer_settings, settings::kInstrumentAllCommands, instrument_all_commands);
    GetEnvVal<bool>(layer_settings, settings::kSyncAfterCommands, sync_after_commands);
}

YAML::Emitter& operator<<(YAML::Emitter& os, DumpCommands value) {
    for (auto& entry : settings::kDumpCommandsValues) {
        if (value == entry.second) {
            os << entry.first;
            return os;
        }
    }
    os << "unknown";
    return os;
}

YAML::Emitter& operator<<(YAML::Emitter& os, DumpShaders value) {
    for (auto& entry : settings::kDumpShadersValues) {
        if (value == entry.second) {
            os << entry.first;
            return os;
        }
    }
    os << "unknown";
    return os;
}

void Settings::Print(YAML::Emitter& os) const {
    os << YAML::BeginMap;
    os << YAML::Key << settings::kOutputPath << YAML::Value << output_path;
    os << YAML::Key << settings::kTraceOn << YAML::Value << trace_all;
    os << YAML::Key << settings::kDumpQueueSubmits << YAML::Value << dump_queue_submits;
    os << YAML::Key << settings::kDumpCommandBuffers << YAML::Value << dump_command_buffers;
    os << YAML::Key << settings::kDumpCommands << YAML::Value << dump_commands;
    os << YAML::Key << settings::kDumpShaders << YAML::Value << dump_shaders;
    os << YAML::Key << settings::kWatchdogTimeout << YAML::Value << watchdog_timer_ms;
    os << YAML::Key << settings::kTrackSemaphores << YAML::Value << track_semaphores;
    os << YAML::Key << settings::kTraceAllSemaphores << YAML::Value << trace_all_semaphores;
    os << YAML::Key << settings::kInstrumentAllCommands << YAML::Value << instrument_all_commands;
    os << YAML::Key << settings::kSyncAfterCommands << YAML::Value << sync_after_commands;
    os << YAML::EndMap;
}

// =============================================================================
// Context
// =============================================================================
Context::Context(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator)
    : start_time_(std::chrono::system_clock::now()), logger_(start_time_), system_(*this) {
    // Possibly create messengers for the application to recieve messages from us.
    // Note that since there aren't real handles for these messengers, we're using the create info pointers
    // as fake handles so that they can go into the logger callback map.
    auto* pnext = pCreateInfo->pNext;
    while (auto* utils_ci = vku::FindStructInPNextChain<VkDebugUtilsMessengerCreateInfoEXT>(pnext)) {
        logger_.AddLogCallback(utils_ci, *utils_ci);
        pnext = utils_ci->pNext;
    }
    pnext = pCreateInfo->pNext;
    while (auto* report_ci = vku::FindStructInPNextChain<VkDebugReportCallbackCreateInfoEXT>(pnext)) {
        logger_.AddLogCallback(report_ci, *report_ci);
        pnext = report_ci->pNext;
    }

    const std::time_t in_time_t = std::chrono::system_clock::to_time_t(start_time_);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), kLogTimeTag);
    std::string start_time_str(ss.str());

    const auto* settings_ci = vku::FindStructInPNextChain<VkLayerSettingsCreateInfoEXT>(pCreateInfo);

    VkuLayerSettingSet layer_setting_set = VK_NULL_HANDLE;
    VkResult result =
        vkuCreateLayerSettingSet("lunarg_crash_diagnostic", settings_ci, pAllocator, nullptr, &layer_setting_set);
    if (result != VK_SUCCESS) {
        Log().Error("vkuCreateLayerSettingSet failed with error %d", result);
        return;
    }
    settings_.emplace(layer_setting_set, logger_);

    // output path
    {
        if (!settings_->output_path.empty()) {
            output_path_ = settings_->output_path;
        } else {
#if defined(WIN32)
            output_path_ = getenv("USERPROFILE");
#else
            output_path_ = getenv("HOME");
#endif
            output_path_ /= "cdl";
        }

        base_output_path_ = output_path_;
        output_path_ /= start_time_str;
    }
    // logging
    {
        std::string severity;
        GetEnvVal<std::string>(layer_setting_set, settings::kMessageSeverity, severity);
        if (!severity.empty()) {
            VkDebugUtilsMessageSeverityFlagsEXT mask{0};
            std::regex re("[\\s,]+");
            std::sregex_token_iterator re_iter(severity.begin(), severity.end(), re, -1);
            std::sregex_token_iterator re_end;
            bool bad_value = false;
            for (; re_iter != re_end; ++re_iter) {
                auto iter = settings::kSeverityValues.find(*re_iter);
                if (iter != settings::kSeverityValues.end()) {
                    mask |= iter->second;
                } else {
                    bad_value = true;
                    std::string value = *re_iter;
                    Log().Error("Bad value for message_severity setting: \"%s\"", value.c_str());
                }
            }
            if (!bad_value) {
                logger_.SetSeverity(mask);
            }
        }

        std::string log_file;
        GetEnvVal<std::string>(layer_setting_set, settings::kLogFile, log_file);
        if (!log_file.empty()) {
            auto iter = settings::kLogFileValues.find(log_file);
            if (iter != settings::kLogFileValues.end()) {
                switch (iter->second) {
                    case settings::LogOutputs::kNone:
                        logger_.CloseLogFile();
                        break;
                    case settings::LogOutputs::kStderr:
                        logger_.LogToStderr();
                        break;
                    case settings::LogOutputs::kStdout:
                        logger_.LogToStdout();
                        break;
                }
            } else {
                std::filesystem::path path(log_file);
                if (!path.has_root_directory()) {
                    // "./" or ".\\" should be relative to the apps cwd, otherwise
                    // make it relative to the dump file location.
                    if (log_file[0] != '.') {
                        path = output_path_ / log_file;
                    }
                }
                logger_.OpenLogFile(path);
            }
        }
    }
    Log().Info("Version %s enabled. Start time tag: %s", kCdlVersion.c_str(), start_time_str.c_str());

    // trace mode
    {
        // setup shader loading modes
        shader_module_load_options_ = ShaderModule::LoadOptions::kNone;
        switch (settings_->dump_shaders) {
            case DumpShaders::kAll:
                shader_module_load_options_ |= ShaderModule::LoadOptions::kDumpOnCreate;
                break;
            case DumpShaders::kOnCrash:
            case DumpShaders::kOnBind:
                shader_module_load_options_ |= ShaderModule::LoadOptions::kKeepInMemory;
                break;
            default:
                break;
        }
    }

    // manage the watchdog thread
    {
        UpdateWatchdog();
        if (settings_->watchdog_timer_ms > 0) {
            StartWatchdogTimer();
            Log().Info("Begin Watchdog: %" PRId64 "ms", settings_->watchdog_timer_ms);
        }
    }

    vkuDestroyLayerSettingSet(layer_setting_set, nullptr);
}

Context::~Context() {
    StopWatchdogTimer();
    logger_.CloseLogFile();
}

Context::DevicePtr Context::GetDevice(VkDevice device) {
    std::lock_guard<std::mutex> lock(devices_mutex_);
    auto iter = devices_.find(device);
    return iter != devices_.end() ? iter->second : nullptr;
}

Context::ConstDevicePtr Context::GetDevice(VkDevice device) const {
    std::lock_guard<std::mutex> lock(devices_mutex_);
    auto iter = devices_.find(device);
    return iter != devices_.end() ? iter->second : nullptr;
}

std::vector<Context::DevicePtr> Context::GetAllDevices() {
    std::vector<DevicePtr> devs;
    std::lock_guard<std::mutex> lock(devices_mutex_);
    devs.reserve(devices_.size());
    for (auto& entry : devices_) {
        devs.push_back(entry.second);
    }
    return devs;
}

std::vector<Context::ConstDevicePtr> Context::GetAllDevices() const {
    std::vector<ConstDevicePtr> devs;
    std::lock_guard<std::mutex> lock(devices_mutex_);
    devs.resize(devices_.size());
    for (auto& entry : devices_) {
        devs.push_back(entry.second);
    }
    return devs;
}

Context::DevicePtr Context::GetQueueDevice(VkQueue queue) {
    VkDevice device;
    {
        std::lock_guard<std::mutex> lock(queue_device_tracker_mutex_);
        auto iter = queue_device_tracker_.find(queue);
        if (iter == queue_device_tracker_.end()) {
            return nullptr;
        }
        device = iter->second;
    }
    std::lock_guard<std::mutex> lock(devices_mutex_);
    auto iter = devices_.find(device);
    return iter != devices_.end() ? iter->second : nullptr;
}

Context::ConstDevicePtr Context::GetQueueDevice(VkQueue queue) const {
    VkDevice device;
    {
        std::lock_guard<std::mutex> lock(queue_device_tracker_mutex_);
        auto iter = queue_device_tracker_.find(queue);
        if (iter == queue_device_tracker_.end()) {
            return nullptr;
        }
        device = iter->second;
    }
    std::lock_guard<std::mutex> lock(devices_mutex_);
    auto iter = devices_.find(device);
    return iter != devices_.end() ? iter->second : nullptr;
}

void Context::StartWatchdogTimer() {
    // Start up the watchdog timer thread.
    watchdog_running_ = true;
    watchdog_thread_ = std::thread([&]() { this->WatchdogTimer(); });
}
void Context::UpdateWatchdog() {
    using namespace std::chrono;
    last_submit_time_ = duration_cast<milliseconds>(high_resolution_clock::now().time_since_epoch()).count();
}

void Context::StopWatchdogTimer() {
    if (watchdog_running_) {
        Log().Info("Stopping Watchdog");
        watchdog_running_ = false;  // TODO: condition variable that waits
    }
    // make sure the watchdog thread is joined even if it quit on its own.
    if (watchdog_thread_.joinable()) {
        watchdog_thread_.join();
        Log().Info("Watchdog Stopped");
    }
}

void Context::WatchdogTimer() {
    uint64_t test_interval_us = std::min((uint64_t)(1000 * 1000), settings_->watchdog_timer_ms * 500);
    while (watchdog_running_) {
        // TODO: condition variable that waits
        std::this_thread::sleep_for(std::chrono::microseconds(test_interval_us));
        if (!watchdog_running_) {
            break;
        }

        auto now = std::chrono::duration_cast<std::chrono::milliseconds>(
                       std::chrono::high_resolution_clock::now().time_since_epoch())
                       .count();
        auto ms = (int64_t)(now - last_submit_time_);

        if (ms > (int64_t)settings_->watchdog_timer_ms) {
            Log().Info("CDL: Watchdog check failed, no submit in %" PRId64 "ms", ms);

            auto devs = GetAllDevices();
            bool dump_prologue = true;
            auto file = OpenDumpFile();
            YAML::Emitter os(file.is_open() ? file : std::cerr);

            for (auto& device : devs) {
                device->WatchdogTimeout(dump_prologue, os);
                dump_prologue = false;
            }

            // Quit the thread after a hang is detected, it is unlikely that further dumps will
            // show anything more useful than the first one.
            watchdog_running_ = false;
        }
    }
}

void Context::PreApiFunction(const char* api_name) {
    if (settings_->trace_all) {
        Log().Info("{ %s", api_name);
    }
}

void Context::PostApiFunction(const char* api_name) {
    if (settings_->trace_all) {
        Log().Info("} %s", api_name);
    }
}

void Context::PostApiFunction(const char* api_name, VkResult result) {
    if (settings_->trace_all) {
        Log().Info("} %s (%s)", api_name, string_VkResult(result));
    }
}

struct RequiredExtension {
    char name[VK_MAX_EXTENSION_NAME_SIZE];
    bool enabled;
    bool* enabled_member;
};

const VkInstanceCreateInfo* Context::GetModifiedInstanceCreateInfo(const VkInstanceCreateInfo* pCreateInfo) {
    const uint32_t required_extension_count = 2;
    RequiredExtension required_extensions[] = {
        {VK_EXT_DEBUG_UTILS_EXTENSION_NAME, false, nullptr},
        {VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME, false, nullptr},
    };

    original_create_info_.initialize(pCreateInfo);
    modified_create_info_ = original_create_info_;

    for (uint32_t j = 0; j < required_extension_count; ++j) {
        vku::AddExtension(modified_create_info_, required_extensions[j].name);
    }
    return modified_create_info_.ptr();
}

static void DecodeExtensionString(DeviceExtensionsPresent& extensions, const char* name) {
    if (!strcmp(name, VK_AMD_BUFFER_MARKER_EXTENSION_NAME)) {
        extensions.amd_buffer_marker = true;
    } else if (!strcmp(name, VK_AMD_DEVICE_COHERENT_MEMORY_EXTENSION_NAME)) {
        extensions.amd_coherent_memory = true;
    } else if (!strcmp(name, VK_EXT_DEVICE_FAULT_EXTENSION_NAME)) {
        extensions.ext_device_fault = true;
    } else if (!strcmp(name, VK_EXT_DEVICE_ADDRESS_BINDING_REPORT_EXTENSION_NAME)) {
        extensions.ext_device_address_binding_report = true;
    } else if (!strcmp(name, VK_NV_DEVICE_DIAGNOSTIC_CHECKPOINTS_EXTENSION_NAME)) {
        extensions.nv_device_diagnostic_checkpoints = true;
    } else if (!strcmp(name, VK_KHR_TIMELINE_SEMAPHORE_EXTENSION_NAME)) {
        extensions.khr_timeline_semaphore = true;
    }
}

static DeviceExtensionsPresent DecodeExtensionStrings(uint32_t count, const char* const* names) {
    DeviceExtensionsPresent extensions{};

    for (uint32_t i = 0; i < count; ++i) {
        DecodeExtensionString(extensions, names[i]);
    }
    return extensions;
}

const VkDeviceCreateInfo* Context::GetModifiedDeviceCreateInfo(VkPhysicalDevice physicalDevice,
                                                               const VkDeviceCreateInfo* pCreateInfo) {
    auto extensions_enabled =
        DecodeExtensionStrings(pCreateInfo->enabledExtensionCount, pCreateInfo->ppEnabledExtensionNames);

    const auto& extensions_present = extensions_of_interest_present_[physicalDevice];
    auto device_ci = std::make_unique<DeviceCreateInfo>();
    device_ci->original.initialize(pCreateInfo);
    device_ci->modified = device_ci->original;

    // If an important extension is not enabled by default, try to enable it if it is present
    if (extensions_present.nv_device_diagnostic_checkpoints) {
        if (!extensions_enabled.nv_device_diagnostic_checkpoints) {
            // NOTE: this extension does not have a feature struct
            extensions_enabled.nv_device_diagnostic_checkpoints = true;
            vku::AddExtension(device_ci->modified, VK_NV_DEVICE_DIAGNOSTIC_CHECKPOINTS_EXTENSION_NAME);
        }
    }
    if (extensions_present.amd_buffer_marker) {
        if (!extensions_enabled.amd_buffer_marker) {
            // NOTE: this extension does not have a feature struct
            extensions_enabled.amd_buffer_marker = true;
            vku::AddExtension(device_ci->modified, VK_AMD_BUFFER_MARKER_EXTENSION_NAME);
        }
        if (extensions_present.amd_coherent_memory) {
            if (!extensions_enabled.amd_coherent_memory) {
                extensions_enabled.amd_coherent_memory = true;
                auto amd_device_coherent = vku::InitStruct<VkPhysicalDeviceCoherentMemoryFeaturesAMD>(nullptr, VK_TRUE);
                vku::AddToPnext(device_ci->modified, amd_device_coherent);
                vku::AddExtension(device_ci->modified, VK_AMD_DEVICE_COHERENT_MEMORY_EXTENSION_NAME);
            }
        } else {
            Log().Warning("No VK_AMD_device_coherent_memory extension, results may not be as accurate as possible.");
        }
    } else {
        Log().Warning("No VK_AMD_buffer_marker extension, semaphore tracking will be disabled.");
    }

    if (!extensions_present.nv_device_diagnostic_checkpoints && !extensions_present.amd_buffer_marker) {
        Log().Error(
            "No VK_NV_device_diagnostic_checkpoints or VK_AMD_buffer_marker extension, progression tracking will "
            "be "
            "disabled. ");
    }
    if (extensions_present.ext_device_fault) {
        if (!extensions_enabled.ext_device_fault) {
            extensions_enabled.ext_device_fault = true;
            // Query the feature so that we know if vendor data is supported
            auto ext_device_fault = vku::InitStruct<VkPhysicalDeviceFaultFeaturesEXT>(nullptr);
            auto features2 = vku::InitStruct<VkPhysicalDeviceFeatures2>(&ext_device_fault);
            Dispatch().GetPhysicalDeviceFeatures2(physicalDevice, &features2);

            vku::AddToPnext(device_ci->modified, ext_device_fault);
            vku::AddExtension(device_ci->modified, VK_EXT_DEVICE_FAULT_EXTENSION_NAME);
        }
    } else {
        Log().Warning("No VK_EXT_device_fault extension, vendor-specific crash dumps will not be available.");
    }
    if (extensions_present.ext_device_address_binding_report) {
        if (!extensions_enabled.ext_device_address_binding_report) {
            extensions_enabled.ext_device_address_binding_report = true;
            auto ext_device_address_binding_report =
                vku::InitStruct<VkPhysicalDeviceAddressBindingReportFeaturesEXT>(nullptr, VK_TRUE);
            vku::AddToPnext(device_ci->modified, ext_device_address_binding_report);
            vku::AddExtension(device_ci->modified, VK_EXT_DEVICE_ADDRESS_BINDING_REPORT_EXTENSION_NAME);
        }
    } else {
        Log().Warning(
            "No VK_EXT_device_address_binding_report extension, DeviceAddress information will not be available.");
    }
    if (extensions_present.khr_timeline_semaphore) {
        if (!extensions_enabled.khr_timeline_semaphore) {
            extensions_enabled.khr_timeline_semaphore = true;
            auto* vulkan12_features =
                vku::FindStructInPNextChain<VkPhysicalDeviceVulkan12Features>(&device_ci->modified);
            if (vulkan12_features) {
                vulkan12_features->timelineSemaphore = VK_TRUE;
            } else {
                auto khr_timeline_semaphore =
                    vku::InitStruct<VkPhysicalDeviceTimelineSemaphoreFeaturesKHR>(nullptr, VK_TRUE);
                vku::AddToPnext(device_ci->modified, khr_timeline_semaphore);
                vku::AddExtension(device_ci->modified, VK_KHR_TIMELINE_SEMAPHORE_EXTENSION_NAME);
            }
        }
    } else {
        Log().Warning(
            "No VK_EXT_device_address_binding_report extension, DeviceAddress information will not be available.");
    }

    extensions_of_interest_enabled_[physicalDevice] = std::move(extensions_enabled);

    // save the raw ptr before std::move of the std::unique_ptr
    const auto* ci_ptr = device_ci->modified.ptr();
    {
        std::lock_guard<std::mutex> lock(device_create_infos_mutex_);
        device_create_infos_[ci_ptr] = std::move(device_ci);
    }

    return ci_ptr;
}

void Context::DumpDeviceExecutionState(Device& device) {
    auto file = OpenDumpFile();
    YAML::Emitter os(file.is_open() ? file : std::cerr);
    DumpDeviceExecutionState(device, {}, true, kDeviceLostError, os);
}

void Context::DumpDeviceExecutionState(Device& device, bool dump_prologue, CrashSource crash_source,
                                       YAML::Emitter& os) {
    DumpDeviceExecutionState(device, {}, dump_prologue, crash_source, os);
}

void Context::DumpDeviceExecutionState(Device& device, const std::string& error_report, bool dump_prologue,
                                       CrashSource crash_source, YAML::Emitter& os) {
    if (dump_prologue) {
        DumpReportPrologue(os);
    }

    device.Print(os, error_report);
}

void Context::DumpDeviceExecutionStateValidationFailed(Device& device, YAML::Emitter& os) {
    if (device.HangDetected()) {
        return;
    }
#if 0
    // We force all command buffers to dump here because validation can be
    // from a race condition and the GPU can complete work by the time we've
    // started writing the log. (Seen in practice, not theoretical!)
    auto dump_all = debug_dump_all_command_buffers_;
    debug_dump_all_command_buffers_ = true;
    std::stringstream error_report;
    error_report << os.c_str();  // TODO does this do what we want?
    DumpDeviceExecutionState(device, error_report.str(), true /* dump_prologue */, CrashSource::kDeviceLostError, os);
    debug_dump_all_command_buffers_ = dump_all;
#endif
}

void Context::DumpReportPrologue(YAML::Emitter& os) {
    auto elapsed = std::chrono::system_clock::now() - start_time_;
    os << YAML::Comment("----------------------------------------------------------------") << YAML::Newline;
    os << YAML::Comment("-                    CRASH DIAGNOSTIC LAYER                    -") << YAML::Newline;
    os << YAML::Comment("----------------------------------------------------------------") << YAML::Newline;
    os << YAML::BeginMap;
    os << YAML::Key << "version" << YAML::Value << kCdlVersion;
    std::stringstream timestr;
    auto in_time_t = std::chrono::system_clock::to_time_t(start_time_);
    timestr << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    os << YAML::Key << "startTime" << YAML::Value << timestr.str();
    os << YAML::Key << "timeSinceStart" << YAML::Value << DurationToStr(elapsed);

    os << YAML::Key << "Settings" << YAML::Value;
    settings_->Print(os);

    os << YAML::Key << "SystemInfo" << YAML::Value << YAML::BeginMap;
    os << YAML::Key << "osName" << YAML::Value << system_.GetOsName();
    os << YAML::Key << "osVersion" << YAML::Value << system_.GetOsVersion();
    os << YAML::Key << "osBitdepth" << YAML::Value << system_.GetOsBitdepth();
    os << YAML::Key << "osAdditional" << YAML::Value << system_.GetOsAdditionalInfo();
    os << YAML::Key << "cpuName" << YAML::Value << system_.GetHwCpuName();
    os << YAML::Key << "numCpus" << YAML::Value << system_.GetHwNumCpus();
    os << YAML::Key << "totalRam" << YAML::Value << system_.GetHwTotalRam();
    os << YAML::Key << "totalDiskSpace" << YAML::Value << system_.GetHwTotalDiskSpace();
    os << YAML::Key << "availDiskSpace" << YAML::Value << system_.GetHwAvailDiskSpace();
    os << YAML::EndMap;  // SystemInfo

    os << YAML::Key << "Instance" << YAML::Value << YAML::BeginMap;
    // TODO handle debug utils names for VkInstance
    os << YAML::Key << "handle" << YAML::Value << (PtrToStr(vk_instance_) + " []");
    if (application_info_) {
        os << YAML::Key << "applicationInfo" << YAML::Value << YAML::BeginMap;
        os << YAML::Key << "application" << YAML::Value << application_info_->applicationName;
        os << YAML::Key << "applicationVersion" << YAML::Value << application_info_->applicationVersion;
        os << YAML::Key << "engine" << YAML::Value << application_info_->engineName;
        os << YAML::Key << "engineVersion" << YAML::Value << application_info_->engineVersion;

        auto majorVersion = VK_VERSION_MAJOR(application_info_->apiVersion);
        auto minorVersion = VK_VERSION_MINOR(application_info_->apiVersion);
        auto patchVersion = VK_VERSION_PATCH(application_info_->apiVersion);

        std::stringstream api;
        api << majorVersion << "." << minorVersion << "." << patchVersion << " ("
            << Uint32ToStr(application_info_->apiVersion) << ")";
        os << YAML::Key << "apiVersion" << YAML::Value << api.str();
        os << YAML::EndMap;  // ApplicationInfo
    }

    os << YAML::Key << "extensions" << YAML::Value << YAML::BeginSeq;
    for (uint32_t i = 0; i < original_create_info_.enabledExtensionCount; i++) {
        os << original_create_info_.ppEnabledExtensionNames[i];
    }
    os << YAML::EndSeq;
    os << YAML::EndMap;  // Instance
    assert(os.good());
}

std::ofstream Context::OpenDumpFile() {
    // Make sure our output directory exists.
    std::filesystem::create_directories(output_path_);

    // now write our log.
    std::filesystem::path dump_file_path(output_path_);

    // Keep the first log as cdl_dump.yaml then add a number if more than one log is
    // generated. Multiple logs are a new feature and we want to keep backward
    // compatiblity for now.
    std::stringstream ss_name;
    if (total_logs_ > 0) {
        ss_name << "cdl_dump_" << total_logs_ << ".yaml";
    } else {
        ss_name << "cdl_dump.yaml";
    }
    dump_file_path /= ss_name.str();
    total_logs_++;

#if !defined(WIN32)
    // Create a symlink from the generated log file.
    std::filesystem::path symlink_path(base_output_path_);
    symlink_path /= "cdl_dump.yaml.symlink";
    remove(symlink_path.string().c_str());
    symlink(dump_file_path.string().c_str(), symlink_path.string().c_str());
#endif

    std::stringstream ss;
    ss << "Device error encountered and log being recorded" << std::endl;
    ;
    ss << "\tOutput written to: " << dump_file_path << std::endl;
#if !defined(WIN32)
    ss << "\tSymlink to output: " << symlink_path << std::endl;
#endif
    ss << "----------------------------------------------------------------" << std::endl;
#if defined(WIN32)
    OutputDebugString(ss.str().c_str());
#endif
    Log().Error(ss.str());

    std::ofstream fs(dump_file_path);
    if (!fs.is_open()) {
        Log().Error("UNABLE TO OPEN LOG FILE");
    }
    fs << std::unitbuf;
    return fs;
}

// =============================================================================
// Define pre / post intercepted commands
// =============================================================================

static VKAPI_ATTR VkBool32 VKAPI_CALL MessengerCallback(VkDebugUtilsMessageSeverityFlagBitsEXT severity,
                                                        VkDebugUtilsMessageTypeFlagsEXT types,
                                                        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
                                                        void* pUserData) {
    if (nullptr == pCallbackData || nullptr == pUserData) {
        return VK_FALSE;
    }
    Context* context = reinterpret_cast<Context*>(pUserData);
    const auto* mem_info = vku::FindStructInPNextChain<VkDeviceAddressBindingCallbackDataEXT>(pCallbackData->pNext);
    if (!mem_info) {
        return VK_FALSE;
    }
    context->MemoryBindEvent(*mem_info, *pCallbackData->pObjects);
    return VK_FALSE;
}

void Context::MemoryBindEvent(const VkDeviceAddressBindingCallbackDataEXT& mem_info,
                              const VkDebugUtilsObjectNameInfoEXT& object) {
    DeviceAddressRecord rec{mem_info.baseAddress,
                            mem_info.size,
                            mem_info.flags,
                            mem_info.bindingType,
                            object.objectType,
                            object.objectHandle,
                            object.pObjectName ? object.pObjectName : "",
                            std::chrono::high_resolution_clock::now()};
    auto devs = GetAllDevices();

    bool multi_device = devs.size() > 1;
    for (auto& dev : devs) {
        dev->MemoryBindEvent(rec, multi_device);
    }
}

VkResult Context::PostCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                                     VkInstance* pInstance, VkResult result) {
    vk_instance_ = *pInstance;
    auto instance_layer_data = GetInstanceLayerData(crash_diagnostic_layer::DataKey(vk_instance_));
    instance_dispatch_table_ = instance_layer_data->dispatch_table;

    if (pCreateInfo->pApplicationInfo) {
        application_info_ = std::make_unique<ApplicationInfo>();

        application_info_->applicationName =
            pCreateInfo->pApplicationInfo->pApplicationName ? pCreateInfo->pApplicationInfo->pApplicationName : "";
        application_info_->applicationVersion = pCreateInfo->pApplicationInfo->applicationVersion;

        application_info_->engineName =
            pCreateInfo->pApplicationInfo->pEngineName ? pCreateInfo->pApplicationInfo->pEngineName : "";
        application_info_->engineVersion = pCreateInfo->pApplicationInfo->engineVersion;
        application_info_->apiVersion = pCreateInfo->pApplicationInfo->apiVersion;
    }
    // This messenger is for messages we recieve from the ICD for device address binding events.
    if (VK_NULL_HANDLE == utils_messenger_) {
        VkDebugUtilsMessengerCreateInfoEXT messenger_create_info = {
            VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT,
            nullptr,
            0,
            VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
                VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT,
            VK_DEBUG_UTILS_MESSAGE_TYPE_DEVICE_ADDRESS_BINDING_BIT_EXT,
            &MessengerCallback,
            this,
        };
        instance_dispatch_table_.CreateDebugUtilsMessengerEXT(vk_instance_, &messenger_create_info, nullptr,
                                                              &utils_messenger_);
    }
    return result;
}

void Context::PreDestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator) {
    if (VK_NULL_HANDLE != utils_messenger_) {
        instance_dispatch_table_.DestroyDebugUtilsMessengerEXT(vk_instance_, utils_messenger_, nullptr);
        utils_messenger_ = VK_NULL_HANDLE;
    }
}

VkResult Context::PostEnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, const char* pLayerName,
                                                         uint32_t* pPropertyCount, VkExtensionProperties* pProperties,
                                                         VkResult result) {
    if (result == VK_SUCCESS && pPropertyCount != nullptr && pProperties != nullptr && *pPropertyCount > 0) {
        DeviceExtensionsPresent extensions_present{};

        // Get the list of device extensions.
        uint32_t extension_count = *pPropertyCount;
        for (uint32_t i = 0; i < extension_count; ++i) {
            DecodeExtensionString(extensions_present, pProperties[i].extensionName);
        }
        extensions_of_interest_present_[physicalDevice] = std::move(extensions_present);
    }
    return VK_SUCCESS;
}

VkResult Context::PostCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo,
                                   const VkAllocationCallbacks* pAllocator, VkDevice* pDevice, VkResult callResult) {
    if (callResult != VK_SUCCESS) return callResult;

    auto extensions_present =
        DecodeExtensionStrings(pCreateInfo->enabledExtensionCount, pCreateInfo->ppEnabledExtensionNames);

    VkDevice vk_device = *pDevice;
    std::unique_ptr<DeviceCreateInfo> device_create_info;
    {
        std::lock_guard<std::mutex> lock(device_create_infos_mutex_);
        device_create_info = std::move(device_create_infos_[pCreateInfo]);
        device_create_infos_.erase(pCreateInfo);
    }
    auto device =
        std::make_shared<Device>(*this, physicalDevice, *pDevice, extensions_present, std::move(device_create_info));
    {
        std::lock_guard<std::mutex> lock(devices_mutex_);
        // the device pointer is used below, so no std::move() here.
        devices_[vk_device] = device;
    }

    return VK_SUCCESS;
}

void Context::PreDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator) {
    // Destroy the device state without holding devices_mutex_ to avoid possible recursive locking.
    DevicePtr device_state;
    {
        std::lock_guard<std::mutex> lock(devices_mutex_);
        auto iter = devices_.find(device);
        if (iter != devices_.end()) {
            device_state = std::move(iter->second);
            devices_.erase(iter);
        }
    }
    device_state.reset();
}

void Context::PostGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue) {
    {
        auto device_state = GetDevice(device);
        device_state->RegisterQueue(*pQueue, queueFamilyIndex, queueIndex);
    }
    std::lock_guard<std::mutex> lock(queue_device_tracker_mutex_);
    queue_device_tracker_[*pQueue] = device;
}

void Context::PostGetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue) {
    {
        auto device_state = GetDevice(device);
        device_state->RegisterQueue(*pQueue, pQueueInfo->queueFamilyIndex, pQueueInfo->queueIndex);
    }
    std::lock_guard<std::mutex> lock(queue_device_tracker_mutex_);
    queue_device_tracker_[*pQueue] = device;
}

VkResult Context::PreDeviceWaitIdle(VkDevice device) {
    (void)device;
    PreApiFunction("vkDeviceWaitIdle");
    auto device_state = GetDevice(device);
    if (!device_state->UpdateIdleState()) {
        device_state->DeviceFault();
        return VK_ERROR_DEVICE_LOST;
    }
    return VK_SUCCESS;
}
VkResult Context::PostDeviceWaitIdle(VkDevice device, VkResult result) {
    PostApiFunction("vkDeviceWaitIdle", result);

    auto device_state = GetDevice(device);
    if (!device_state->UpdateIdleState()) {
        result = VK_ERROR_DEVICE_LOST;
    }
    // some drivers return VK_TIMEOUT on a hang
    if (IsVkError(result) || result == VK_TIMEOUT) {
        device_state->DeviceFault();
    } else {
        UpdateWatchdog();
    }

    return result;
}

VkResult Context::PreQueueWaitIdle(VkQueue queue) {
    (void)queue;
    PreApiFunction("vkQueueWaitIdle");
    auto device_state = GetQueueDevice(queue);
    if (!device_state->UpdateIdleState()) {
        device_state->DeviceFault();
        return VK_ERROR_DEVICE_LOST;
    }
    return VK_SUCCESS;
}
VkResult Context::PostQueueWaitIdle(VkQueue queue, VkResult result) {
    PostApiFunction("vkQueueWaitIdle", result);

    auto device_state = GetQueueDevice(queue);
    if (!device_state->UpdateIdleState()) {
        result = VK_ERROR_DEVICE_LOST;
    }
    // some drivers return VK_TIMEOUT on a hang
    if (IsVkError(result) || result == VK_TIMEOUT) {
        device_state->DeviceFault();
    } else {
        UpdateWatchdog();
    }

    return result;
}

VkResult Context::PreQueuePresentKHR(VkQueue queue, VkPresentInfoKHR const* pPresentInfo) {
    PreApiFunction("vkQueuePresentKHR");
    UpdateWatchdog();
    auto device_state = GetQueueDevice(queue);
    device_state->UpdateIdleState();
    return VK_SUCCESS;
}
VkResult Context::PostQueuePresentKHR(VkQueue queue, VkPresentInfoKHR const* pPresentInfo, VkResult result) {
    PostApiFunction("vkQueuePresentKHR", result);

    auto device_state = GetQueueDevice(queue);
    if (!device_state->UpdateIdleState()) {
        result = VK_ERROR_DEVICE_LOST;
    }
    if (IsVkError(result)) {
        device_state->DeviceFault();
    }

    return result;
}

VkResult Context::PreWaitForFences(VkDevice device, uint32_t fenceCount, VkFence const* pFences, VkBool32 waitAll,
                                   uint64_t timeout) {
    PreApiFunction("vkWaitForFences");
    auto device_state = GetDevice(device);
    if (!device_state->UpdateIdleState()) {
        device_state->DeviceFault();
        return VK_ERROR_DEVICE_LOST;
    }
    return VK_SUCCESS;
}
VkResult Context::PostWaitForFences(VkDevice device, uint32_t fenceCount, VkFence const* pFences, VkBool32 waitAll,
                                    uint64_t timeout, VkResult result) {
    PostApiFunction("vkWaitForFences", result);

    auto device_state = GetDevice(device);
    if (!device_state->UpdateIdleState()) {
        result = VK_ERROR_DEVICE_LOST;
    }
    if (IsVkError(result)) {
        device_state->DeviceFault();
    } else if (result == VK_SUCCESS) {
        UpdateWatchdog();
    }

    return result;
}

VkResult Context::PreGetFenceStatus(VkDevice device, VkFence fence) {
    PreApiFunction("vkGetFenceStatus");
    return VK_SUCCESS;
}
VkResult Context::PostGetFenceStatus(VkDevice device, VkFence fence, VkResult result) {
    PostApiFunction("vkGetFenceStatus", result);

    auto device_state = GetDevice(device);
    if (!device_state->UpdateIdleState()) {
        result = VK_ERROR_DEVICE_LOST;
    }
    if (IsVkError(result)) {
        device_state->DeviceFault();
    }

    return result;
}

VkResult Context::PreGetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery,
                                         uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride,
                                         VkQueryResultFlags flags) {
    PostApiFunction("vkGetQueryPoolResults");
    return VK_SUCCESS;
}
VkResult Context::PostGetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery,
                                          uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride,
                                          VkQueryResultFlags flags, VkResult result) {
    PostApiFunction("vkGetQueryPoolResults", result);

    if (IsVkError(result)) {
        auto device_state = GetDevice(device);
        device_state->DeviceFault();
    }

    return result;
}

VkResult Context::PreAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout,
                                         VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex) {
    PreApiFunction("vkAcquireNextImageKHR");
    return VK_SUCCESS;
}
VkResult Context::PostAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout,
                                          VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex,
                                          VkResult result) {
    PostApiFunction("vkAcquireNextImageKHR", result);

    if (IsVkError(result)) {
        auto device_state = GetDevice(device);
        device_state->DeviceFault();
    }

    return result;
}

VkResult Context::PostCreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo,
                                         const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule,
                                         VkResult callResult) {
    if (callResult == VK_SUCCESS) {
        auto device_state = GetDevice(device);
        device_state->CreateShaderModule(pCreateInfo, pShaderModule, shader_module_load_options_);
    }
    return callResult;
}

void Context::PreDestroyShaderModule(VkDevice device, VkShaderModule shaderModule,
                                     const VkAllocationCallbacks* pAllocator) {
    auto device_state = GetDevice(device);
    device_state->DeleteShaderModule(shaderModule);
}

VkResult Context::PostCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount,
                                              const VkGraphicsPipelineCreateInfo* pCreateInfos,
                                              const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                              VkResult callResult) {
    if (callResult == VK_SUCCESS) {
        auto device_state = GetDevice(device);
        device_state->CreatePipeline(createInfoCount, pCreateInfos, pPipelines);
    }
    return callResult;
}

VkResult Context::PostCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount,
                                             const VkComputePipelineCreateInfo* pCreateInfos,
                                             const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                             VkResult callResult) {
    if (callResult == VK_SUCCESS) {
        auto device_state = GetDevice(device);
        device_state->CreatePipeline(createInfoCount, pCreateInfos, pPipelines);
    }
    return callResult;
}

void Context::PostDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator) {
    auto device_state = GetDevice(device);
    device_state->DeletePipeline(pipeline);
}

VkResult Context::PreCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo,
                                       const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool) {
    PreApiFunction("vkCreateCommandPool");
    return VK_SUCCESS;
}
VkResult Context::PostCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo,
                                        const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool,
                                        VkResult callResult) {
    if (callResult == VK_SUCCESS) {
        PostApiFunction("vkCreateCommandPool");
        auto device_state = GetDevice(device);
        CommandPoolPtr pool = std::make_unique<CommandPool>(*pCommandPool, pCreateInfo);
        device_state->SetCommandPool(*pCommandPool, std::move(pool));
    }
    return callResult;
}

void Context::PreDestroyCommandPool(VkDevice device, VkCommandPool commandPool,
                                    const VkAllocationCallbacks* pAllocator) {
    PreApiFunction("vkDestroyCommandPool");

    auto device_state = GetDevice(device);
    YAML::Emitter os;
    device_state->ValidateCommandPoolState(commandPool, os);
    if (os.size() > 0) {
        DumpDeviceExecutionStateValidationFailed(*device_state, os);
    }
}

void Context::PostDestroyCommandPool(VkDevice device, VkCommandPool commandPool,
                                     const VkAllocationCallbacks* pAllocator) {
    PostApiFunction("vkDestroyCommandPool");

    auto device_state = GetDevice(device);
    device_state->DeleteCommandPool(commandPool);
}

VkResult Context::PreResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags) {
    PreApiFunction("vkResetCommandPool");

    auto device_state = GetDevice(device);
    YAML::Emitter os;
    device_state->ValidateCommandPoolState(commandPool, os);
    if (os.size() > 0) {
        DumpDeviceExecutionStateValidationFailed(*device_state, os);
    }
    return VK_SUCCESS;
}

VkResult Context::PostResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags,
                                       VkResult callResult) {
    PostApiFunction("vkResetCommandPool");

    auto device_state = GetDevice(device);
    device_state->ResetCommandPool(commandPool);

    return callResult;
}

VkResult Context::PreAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo,
                                            VkCommandBuffer* pCommandBuffers) {
    PreApiFunction("vkAllocateCommandBuffers");
    return VK_SUCCESS;
}

VkResult Context::PostAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo,
                                             VkCommandBuffer* pCommandBuffers, VkResult callResult) {
    if (callResult == VK_SUCCESS) {
        PostApiFunction("vkAllocateCommandBuffers");

        auto device_state = GetDevice(device);

        auto vk_pool = pAllocateInfo->commandPool;
        device_state->AllocateCommandBuffers(vk_pool, pAllocateInfo, pCommandBuffers);
    }
    return callResult;
}

void Context::PreFreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount,
                                    const VkCommandBuffer* pCommandBuffers) {
    PreApiFunction("vkFreeCommandBuffers");
}
void Context::PostFreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount,
                                     const VkCommandBuffer* pCommandBuffers) {
    PostApiFunction("vkFreeCommandBuffers");

    auto device_state = GetDevice(device);
    if (!device_state->HangDetected()) {
        YAML::Emitter os;
        bool all_cb_ok = true;
        for (uint32_t i = 0; i < commandBufferCount; ++i) {
            all_cb_ok = all_cb_ok && device_state->ValidateCommandBufferNotInUse(pCommandBuffers[i], os);
        }
        if (!all_cb_ok) {
            DumpDeviceExecutionStateValidationFailed(*device_state, os);
        }
    }

    device_state->DeleteCommandBuffers(commandPool, pCommandBuffers, commandBufferCount);
}

VkResult Context::PostCreateSemaphore(VkDevice device, VkSemaphoreCreateInfo const* pCreateInfo,
                                      const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore,
                                      VkResult result) {
    if (settings_->track_semaphores && result == VK_SUCCESS) {
        uint64_t s_value = 0;
        VkSemaphoreTypeKHR s_type = VK_SEMAPHORE_TYPE_BINARY_KHR;

        const auto* semaphore_info = vku::FindStructInPNextChain<VkSemaphoreTypeCreateInfoKHR>(pCreateInfo);
        if (semaphore_info) {
            s_value = semaphore_info->initialValue;
            s_type = semaphore_info->semaphoreType;
        }
        auto device_state = GetDevice(device);
        assert(device_state);

        device_state->GetSemaphoreTracker()->RegisterSemaphore(*pSemaphore, s_type, s_value);

        if (settings_->trace_all_semaphores) {
            std::stringstream log;
            log << "Semaphore created. VkDevice:" << device_state->GetObjectName((uint64_t)device)
                << ", VkSemaphore: " << device_state->GetObjectName((uint64_t)(*pSemaphore));
            if (s_type == VK_SEMAPHORE_TYPE_BINARY_KHR) {
                log << ", Type: Binary";
            } else {
                log << ", Type: Timeline, Initial value: " << s_value;
            }
            Log().Info(log.str());
        }
    }
    return result;
}

void Context::PreDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) {
    if (settings_->track_semaphores && settings_->trace_all_semaphores) {
        auto device_state = GetDevice(device);
        assert(device_state);

        auto semaphore_tracker = device_state->GetSemaphoreTracker();

        std::stringstream log;
        log << "Semaphore destroyed. VkDevice:" << device_state->GetObjectName((uint64_t)device)
            << ", VkSemaphore: " << device_state->GetObjectName((uint64_t)(semaphore));
        if (semaphore_tracker->GetSemaphoreType(semaphore) == VK_SEMAPHORE_TYPE_BINARY_KHR) {
            log << ", Type: Binary, ";
        } else {
            log << ", Type: Timeline, ";
        }
        uint64_t semaphore_value;
        if (semaphore_tracker->GetSemaphoreValue(semaphore, semaphore_value)) {
            log << "Latest value: " << semaphore_value;
        } else {
            log << "Latest value: Unknown";
        }
        Log().Info(log.str());
    }
}

void Context::PostDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) {
    if (settings_->track_semaphores) {
        auto device_state = GetDevice(device);
        auto semaphore_tracker = device_state->GetSemaphoreTracker();
        semaphore_tracker->EraseSemaphore(semaphore);
    }
}

VkResult Context::PostSignalSemaphore(VkDevice device, const VkSemaphoreSignalInfoKHR* pSignalInfo, VkResult result) {
    if (settings_->track_semaphores && result == VK_SUCCESS) {
        auto device_state = GetDevice(device);
        device_state->GetSemaphoreTracker()->SignalSemaphore(pSignalInfo->semaphore, pSignalInfo->value,
                                                             {SemaphoreModifierType::kModifierHost});
        if (settings_->trace_all_semaphores) {
            std::string timeline_message = "Timeline semaphore signaled from host. VkDevice: ";
            timeline_message += device_state->GetObjectName((uint64_t)device) +
                                ", VkSemaphore: " + device_state->GetObjectName((uint64_t)(pSignalInfo->semaphore)) +
                                ", Signal value: " + std::to_string(pSignalInfo->value);
            Log().Info(timeline_message.c_str());
        }
    }
    return result;
}

VkResult Context::PreWaitSemaphores(VkDevice device, const VkSemaphoreWaitInfoKHR* pWaitInfo, uint64_t timeout) {
    VkResult result = VK_SUCCESS;
    auto device_state = GetDevice(device);
    if (!device_state->UpdateIdleState()) {
        result = VK_ERROR_DEVICE_LOST;
    }
    if (settings_->track_semaphores) {
#ifdef __linux__
        pid_t tid = static_cast<pid_t>(syscall(SYS_gettid));
#else
        int tid = 0;
#endif

#ifdef WIN32
        int pid = _getpid();
#else
        pid_t pid = getpid();
#endif

        device_state->GetSemaphoreTracker()->BeginWaitOnSemaphores(pid, tid, pWaitInfo);

        if (settings_->trace_all_semaphores) {
            std::stringstream log;
            log << "Waiting for timeline semaphores on host. PID: " << pid << ", TID: " << tid
                << ", VkDevice: " << device_state->GetObjectName((uint64_t)device) << std::endl;
            for (uint32_t i = 0; i < pWaitInfo->semaphoreCount; i++) {
                log << "\tVkSemaphore: " << device_state->GetObjectName((uint64_t)(pWaitInfo->pSemaphores[i]))
                    << ", Wait value: " << pWaitInfo->pValues[i] << std::endl;
            }
            Log().Info(log.str());
        }
    }
    return result;
}

VkResult Context::PostWaitSemaphores(VkDevice device, const VkSemaphoreWaitInfoKHR* pWaitInfo, uint64_t timeout,
                                     VkResult result) {
    auto device_state = GetDevice(device);
    if (!device_state->UpdateIdleState()) {
        result = VK_ERROR_DEVICE_LOST;
    }
    if (IsVkError(result)) {
        device_state->DeviceFault();
        return result;
    }
    if (settings_->track_semaphores && (result == VK_SUCCESS || result == VK_TIMEOUT)) {
#ifdef __linux__
        pid_t tid = static_cast<pid_t>(syscall(SYS_gettid));
#else
        int tid = 0;
#endif

#ifdef WIN32
        int pid = _getpid();
#else
        pid_t pid = getpid();
#endif
        {
            // Update semaphore values
            uint64_t semaphore_value;
            auto dispatch_table =
                crash_diagnostic_layer::GetDeviceLayerData(crash_diagnostic_layer::DataKey(device))->dispatch_table;
            auto semaphore_tracker = device_state->GetSemaphoreTracker();
            for (uint32_t i = 0; i < pWaitInfo->semaphoreCount; i++) {
                VkResult res;
                if (dispatch_table.GetSemaphoreCounterValue) {
                    res = dispatch_table.GetSemaphoreCounterValue(device, pWaitInfo->pSemaphores[i], &semaphore_value);
                } else {
                    res =
                        dispatch_table.GetSemaphoreCounterValueKHR(device, pWaitInfo->pSemaphores[i], &semaphore_value);
                }
                if (res == VK_SUCCESS) {
                    semaphore_tracker->SignalSemaphore(pWaitInfo->pSemaphores[i], semaphore_value,
                                                       {SemaphoreModifierType::kModifierHost});
                }
            }
            semaphore_tracker->EndWaitOnSemaphores(pid, tid, pWaitInfo);
        }

        if (settings_->trace_all_semaphores) {
            std::stringstream log;
            log << "Finished waiting for timeline semaphores on host. PID: " << pid << ", TID: " << tid
                << ", VkDevice: " << device_state->GetObjectName((uint64_t)device) << std::endl;
            for (uint32_t i = 0; i < pWaitInfo->semaphoreCount; i++) {
                log << "\tVkSemaphore: " << device_state->GetObjectName((uint64_t)(pWaitInfo->pSemaphores[i]))
                    << ", Wait value: " << pWaitInfo->pValues[i] << std::endl;
            }
            Log().Info(log.str());
        }
    }
    return result;
}

VkResult Context::PostGetSemaphoreCounterValue(VkDevice device, VkSemaphore semaphore, uint64_t* pValue,
                                               VkResult result) {
    if (IsVkError(result)) {
        auto device_state = GetDevice(device);
        device_state->DeviceFault();
    }
    return result;
}

const std::filesystem::path& Context::GetOutputPath() const { return output_path_; }

VkResult Context::PreDebugMarkerSetObjectNameEXT(VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo) {
    auto device_state = GetDevice(device);
    device_state->AddObjectInfo(pNameInfo->object, static_cast<VkObjectType>(pNameInfo->objectType),
                                pNameInfo->pObjectName);
    return VK_SUCCESS;
};

VkResult Context::PreSetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo) {
    auto device_state = GetDevice(device);
    device_state->AddObjectInfo(pNameInfo->objectHandle, pNameInfo->objectType, pNameInfo->pObjectName);
    return VK_SUCCESS;
}

// =============================================================================
// Include the generated implementation to forward commands to command buffer
// =============================================================================
#include "cdl_commands.cpp.inc"

// =============================================================================
// Define the custom pre intercepted commands
// =============================================================================
void Context::PreCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                 VkPipeline pipeline) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    if (settings_->dump_shaders == DumpShaders::kOnBind) {
        p_cmd->GetDevice().DumpShaderFromPipeline(pipeline);
    }

    p_cmd->PreCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
}

VkResult Context::PreBeginCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferBeginInfo const* pBeginInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    {
        auto& device = p_cmd->GetDevice();
        YAML::Emitter os;
        if (!device.ValidateCommandBufferNotInUse(commandBuffer, os)) {
            DumpDeviceExecutionStateValidationFailed(device, os);
        }
    }

    return p_cmd->PreBeginCommandBuffer(commandBuffer, pBeginInfo);
}

VkResult Context::PreResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    {
        auto& device = p_cmd->GetDevice();
        YAML::Emitter os;
        if (!device.ValidateCommandBufferNotInUse(commandBuffer, os)) {
            DumpDeviceExecutionStateValidationFailed(device, os);
        }
    }

    return p_cmd->PreResetCommandBuffer(commandBuffer, flags);
}

VkResult Context::QueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) {
    PreApiFunction("vkQueueSubmit");
    UpdateWatchdog();
    auto device_state = GetQueueDevice(queue);
    auto queue_state = device_state->GetQueue(queue);
    auto result = queue_state->Submit(submitCount, pSubmits, fence);
    PostApiFunction("vkQueueSubmit", result);
    if (IsVkError(result)) {
        device_state->DeviceFault();
    }
    return result;
}

VkResult Context::QueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) {
    PreApiFunction("vkQueueSubmit2");
    UpdateWatchdog();
    auto device_state = GetQueueDevice(queue);
    auto queue_state = device_state->GetQueue(queue);
    auto result = queue_state->Submit2(submitCount, pSubmits, fence);
    PostApiFunction("vkQueueSubmit2", result);
    if (IsVkError(result)) {
        device_state->DeviceFault();
    }
    return result;
}

VkResult Context::QueueSubmit2KHR(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) {
    PreApiFunction("vkQueueSubmit2KHR");
    UpdateWatchdog();
    auto device_state = GetQueueDevice(queue);
    auto queue_state = device_state->GetQueue(queue);
    auto result = queue_state->Submit2(submitCount, pSubmits, fence);
    PostApiFunction("vkQueueSubmit2KHR", result);
    if (IsVkError(result)) {
        device_state->DeviceFault();
    }
    return result;
}

VkResult Context::QueueBindSparse(VkQueue queue, uint32_t bindInfoCount, VkBindSparseInfo const* pBindInfo,
                                  VkFence fence) {
    PreApiFunction("vkQueueBindSparse");
    UpdateWatchdog();
    auto device_state = GetQueueDevice(queue);
    auto queue_state = device_state->GetQueue(queue);
    auto result = queue_state->BindSparse(bindInfoCount, pBindInfo, fence);
    PostApiFunction("vkQueueBindSparse", result);
    if (IsVkError(result)) {
        device_state->DeviceFault();
    }
    return result;
}

VkResult Context::PostCreateDebugUtilsMessengerEXT(VkInstance instance,
                                                   const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
                                                   const VkAllocationCallbacks* pAllocator,
                                                   VkDebugUtilsMessengerEXT* pMessenger, VkResult result) {
    if (result == VK_SUCCESS) {
        logger_.AddLogCallback(*pMessenger, *pCreateInfo);
    }
    return result;
}

void Context::PreDestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT messenger,
                                               const VkAllocationCallbacks* pAllocator) {
    logger_.RemoveLogCallback(messenger);
}

VkResult Context::PostCreateDebugReportCallbackEXT(VkInstance instance,
                                                   const VkDebugReportCallbackCreateInfoEXT* pCreateInfo,
                                                   const VkAllocationCallbacks* pAllocator,
                                                   VkDebugReportCallbackEXT* pCallback, VkResult result) {
    if (result == VK_SUCCESS) {
        logger_.AddLogCallback(*pCallback, *pCreateInfo);
    }
    return result;
}

void Context::PreDestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback,
                                               const VkAllocationCallbacks* pAllocator) {
    logger_.RemoveLogCallback(callback);
}

VkResult CreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                        VkInstance* pInstance, Interceptor** interceptor) {
    auto* context = new Context(pCreateInfo, pAllocator);
    *interceptor = context;
    return VK_SUCCESS;
}

}  // namespace crash_diagnostic_layer
