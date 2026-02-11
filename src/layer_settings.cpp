/*
 * Copyright (c) 2024-2026 The Khronos Group Inc.
 * Copyright (c) 2024-2026 Valve Corporation
 * Copyright (c) 2024-2026 LunarG, Inc.
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
#include "layer_settings.h"
#include "logger.h"
#include "system.h"

#include <vulkan/utility/vk_struct_helper.hpp>
#include <vulkan/layer/vk_layer_settings.hpp>

#include <regex>
#include <cstring>
#include <string>
#include <unordered_map>
#include <iostream>

const std::string kCdlVersion = std::to_string(VK_VERSION_MAJOR(VK_HEADER_VERSION_COMPLETE)) + "." +
                                std::to_string(VK_VERSION_MINOR(VK_HEADER_VERSION_COMPLETE)) + "." +
                                std::to_string(VK_VERSION_PATCH(VK_HEADER_VERSION_COMPLETE));

const char* kLogTimeTag = "%Y-%m-%d-%H%M%S";

namespace crash_diagnostic_layer {

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

const char* kTriggerWatchdogTimeout = "trigger_watchdog_timeout";
const char* kWatchdogTimeout = "watchdog_timeout_ms";
const char* kDumpAllCommandBuffers = "dump_all_command_buffers";
const char* kTrackSemaphores = "track_semaphores";
const char* kTraceAllSemaphores = "trace_all_semaphores";
const char* kInstrumentAllCommands = "instrument_all_commands";
const char* kSyncAfterCommands = "sync_after_commands";
}  // namespace settings

template <class T>
bool GetEnvVal(VkuLayerSettingSet settings, const char* name, T& value) {
    if (vkuHasLayerSetting(settings, name)) {
        vkuGetLayerSettingValue(settings, name, value);
        return true;
    }
    return false;
}

template <class T>
bool GetEnumVal(Logger& log, VkuLayerSettingSet settings, const char* name, T& value,
                const std::unordered_map<std::string, T>& value_map) {
    std::string value_string;
    if (!GetEnvVal<std::string>(settings, name, value_string)) {
        return false;
    }
    if (!value_string.empty()) {
        auto iter = value_map.find(value_string);
        if (iter != value_map.end()) {
            value = iter->second;
        } else {
            log.Error("Bad value for %s setting: \"%s\"", name, value_string.c_str());
        }
    }
    return true;
}

Settings::Settings(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, Logger& log) :
    start_time(log.StartTime()) {
    // Possibly create messengers for the application to recieve messages from us.
    // Note that since there aren't real handles for these messengers, we're using the create info pointers
    // as fake handles so that they can go into the logger callback map.
    auto* pnext = pCreateInfo->pNext;
    while (auto* utils_ci = vku::FindStructInPNextChain<VkDebugUtilsMessengerCreateInfoEXT>(pnext)) {
        log.AddLogCallback(utils_ci, *utils_ci);
        pnext = utils_ci->pNext;
    }
    pnext = pCreateInfo->pNext;
    while (auto* report_ci = vku::FindStructInPNextChain<VkDebugReportCallbackCreateInfoEXT>(pnext)) {
        log.AddLogCallback(report_ci, *report_ci);
        pnext = report_ci->pNext;
    }

    const std::time_t in_time_t = std::chrono::system_clock::to_time_t(start_time);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), kLogTimeTag);
    std::string start_time_str(ss.str());

    const auto* settings_ci = vku::FindStructInPNextChain<VkLayerSettingsCreateInfoEXT>(pCreateInfo);

    VkuLayerSettingSet layer_setting_set = VK_NULL_HANDLE;
    VkResult result =
        vkuCreateLayerSettingSet("lunarg_crash_diagnostic", settings_ci, pAllocator, nullptr, &layer_setting_set);
    if (result != VK_SUCCESS) {
        log.Error("vkuCreateLayerSettingSet failed with error %d", result);
        return;
    }

    std::string output_path_string;
    GetEnvVal<std::string>(layer_setting_set, settings::kOutputPath, output_path_string);
    this->output_path = output_path_string;
    GetEnvVal<bool>(layer_setting_set, settings::kTraceOn, trace_all);
    GetEnumVal<DumpCommands>(log, layer_setting_set, settings::kDumpQueueSubmits, dump_queue_submits,
                             settings::kDumpCommandsValues);
    GetEnumVal<DumpCommands>(log, layer_setting_set, settings::kDumpCommandBuffers, dump_command_buffers,
                             settings::kDumpCommandsValues);
    GetEnumVal<DumpCommands>(log, layer_setting_set, settings::kDumpCommands, dump_commands,
                             settings::kDumpCommandsValues);
    GetEnumVal<DumpShaders>(log, layer_setting_set, settings::kDumpShaders, dump_shaders, settings::kDumpShadersValues);
    GetEnvVal<uint64_t>(layer_setting_set, settings::kWatchdogTimeout, watchdog_timer_ms);
    GetEnvVal<bool>(layer_setting_set, settings::kTrackSemaphores, track_semaphores);
    GetEnvVal<bool>(layer_setting_set, settings::kTraceAllSemaphores, trace_all_semaphores);
    GetEnvVal<bool>(layer_setting_set, settings::kInstrumentAllCommands, instrument_all_commands);
    GetEnvVal<bool>(layer_setting_set, settings::kSyncAfterCommands, sync_after_commands);

    // output path
    std::filesystem::path default_output_path = System::GetOutputBasePath();
    default_output_path /= "cdl";
    {
        if (this->output_path.empty()) {
            this->output_path = default_output_path;
        }

        this->base_output_path = output_path;
        this->output_path /= start_time_str;
        default_output_path /= start_time_str;
    }
    // logging
    {
        std::string severity;
        if (GetEnvVal<std::string>(layer_setting_set, settings::kMessageSeverity, severity)) {
            VkDebugUtilsMessageSeverityFlagsEXT mask{0};
            bool bad_value = false;
            if (!severity.empty()) {
                std::regex re("[\\s,]+");
                std::sregex_token_iterator re_iter(severity.begin(), severity.end(), re, -1);
                std::sregex_token_iterator re_end;
                for (; re_iter != re_end; ++re_iter) {
                    auto iter = settings::kSeverityValues.find(*re_iter);
                    if (iter != settings::kSeverityValues.end()) {
                        mask |= iter->second;
                    } else {
                        bad_value = true;
                        std::string value = *re_iter;
                        log.Error("Bad value for message_severity setting: \"%s\"", value.c_str());
                    }
                }
            }
            if (!bad_value) {
                log.SetSeverity(mask);
            }
        }

        std::string log_file;
        if (GetEnvVal<std::string>(layer_setting_set, settings::kLogFile, log_file)) {
            auto iter = settings::kLogFileValues.find(log_file);
            if (iter != settings::kLogFileValues.end()) {
                switch (iter->second) {
                    case settings::LogOutputs::kNone:
                        log.CloseLogFile();
                        break;
                    case settings::LogOutputs::kStderr:
                        log.LogToStderr();
                        break;
                    case settings::LogOutputs::kStdout:
                        log.LogToStdout();
                        break;
                }
            } else {
                std::filesystem::path path(log_file);
                if (!path.has_root_directory()) {
                    // "./" or ".\\" should be relative to the apps cwd, otherwise
                    // make it relative to the dump file location.
                    if (log_file[0] != '.') {
                        path = this->output_path / log_file;
                    }
                }

                if (path.has_parent_path()) {
                    try {
                        // On Windows, if the path include an invalid drive, then filesystem crash...
                        // We need to use an exception to capture this problem
                        std::filesystem::create_directories(path.parent_path());
                    } catch (std::exception& e) {
                        std::cerr << "Failed to open log file: " << path << " - " << e.what() << std::endl;
                        // We fallback using the default path
                        this->output_path = default_output_path;
                        path = default_output_path / log_file;
                    }
                }

                log.OpenLogFile(path);
            }
        }
    }

    vkuDestroyLayerSettingSet(layer_setting_set, nullptr);

    log.Info("Version %s enabled. Start time tag: %s", kCdlVersion.c_str(), start_time_str.c_str());
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
    os << YAML::Key << settings::kOutputPath << YAML::Value << output_path.c_str();
    os << YAML::Key << settings::kTraceOn << YAML::Value << trace_all;
    os << YAML::Key << settings::kDumpQueueSubmits << YAML::Value << dump_queue_submits;
    os << YAML::Key << settings::kDumpCommandBuffers << YAML::Value << dump_command_buffers;
    os << YAML::Key << settings::kDumpCommands << YAML::Value << dump_commands;
    os << YAML::Key << settings::kDumpShaders << YAML::Value << dump_shaders;
    os << YAML::Key << settings::kTriggerWatchdogTimeout << YAML::Value << trigger_watchdog_timer;
    os << YAML::Key << settings::kWatchdogTimeout << YAML::Value << watchdog_timer_ms;
    os << YAML::Key << settings::kTrackSemaphores << YAML::Value << track_semaphores;
    os << YAML::Key << settings::kTraceAllSemaphores << YAML::Value << trace_all_semaphores;
    os << YAML::Key << settings::kInstrumentAllCommands << YAML::Value << instrument_all_commands;
    os << YAML::Key << settings::kSyncAfterCommands << YAML::Value << sync_after_commands;
    os << YAML::EndMap;
}

}  // namespace crash_diagnostic_layer

/*
enum SettingId {
    SETTING_SYNC_AFTER_COMMANDS = 0,
    SETTING_INSTRUCMENT_ALL_COMMANDS,
    SETTING_OUTPUT_PATH,
    SETTING_TRIGGER_WATCHDOG_TIMEOUT,
    SETTING_WATCHDOG_TIMEOUT_MS,
    SETTING_DUMP_SPHEMAPHORES,
    SETTING_DUMP_COMMANDS,
    SETTING_DUMP_COMMAND_BUFFERS,
    SETTING_DUMP_QUEUE_SUBMITS,
    SETTING_DUMP_SHADERS,
    SETTING_LOG_FILE, // Deprecated, replaced by `debug_action`
    SETTING_DEBUG_ACTION,
    SETTING_REPORT_FLAGS,
    SETTING_LOG_TRACE_AREAS
};

enum Area {
    AREA_SEMAPHORES = 0,
    AREA_QUEUE_SUBMITS,
    AREA_COMMAND_BUFFERS,
    AREA_COMMANDS,
    AREA_SHADERS
};

enum AreaFields {
    AREA_SEMAPHORES_NONE = 0,
    AREA_SEMAPHORES_BIT = (1 << AREA_SEMAPHORES),
    AREA_QUEUE_SUBMITS_BIT = (1 << AREA_QUEUE_SUBMITS),
    AREA_COMMAND_BUFFERS_BIT = (1 << AREA_COMMAND_BUFFERS),
    AREA_COMMANDS_BIT = (1 << AREA_COMMANDS),
    AREA_SHADERS_BIT = (1 << AREA_SHADERS)
};

std::string GetSettingKey(SettingId id) {
    static std::string TABLE[] = {
        "sync_after_commands", // 
    };

    return TABLE[id];
}

SettingId GetSettingId(const std::string& setting_key);

bool IsDeprecated(SettingId setting_id);

const char* kOutputPath = "output_path";
const char* kTraceOn = "trace_on";
const char* kLogFile = "log_file";
const char* kLogFilename = "log_filename";
const char* kReportFlags = "report_flags";
const char* kMessageSeverity = "message_severity"; // Deprecated
const char* kDumpCommands = "dump_commands";
const char* kDumpCommandBuffers = "dump_command_buffers";
const char* kDumpQueueSubmits = "dump_queue_submits";
const char* kDumpShaders = "dump_shaders";
const char* kTriggerWatchdogTimeout = "trigger_watchdog_timeout";
const char* kWatchdogTimeout = "watchdog_timeout_ms";
const char* kDumpAllCommandBuffers = "dump_all_command_buffers";
const char* kTrackSemaphores = "track_semaphores";
const char* kTraceAllSemaphores = "trace_all_semaphores";
const char* kInstrumentAllCommands = "instrument_all_commands";
const char* kSyncAfterCommands = "sync_after_commands";

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


static const std::unordered_map<std::string, VkDebugUtilsMessageSeverityFlagBitsEXT> kSeverityValues{
    {"error", VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT},
    {"warn", VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT},
    {"info", VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT},
    {"verbose", VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT},
};

static const std::unordered_map<std::string, DumpCommands> kDumpCommandsValues{
    {"running", DumpCommands::kRunning},
    {"pending", DumpCommands::kPending},
    {"all", DumpCommands::kAll},
};

static const std::unordered_map<std::string, DumpShaders> kDumpShadersValues{
    {"off", DumpShaders::kOff},
    {"on_crash", DumpShaders::kOnCrash},
    {"on_bind", DumpShaders::kOnBind},
    {"all", DumpShaders::kAll},
};



#define MakeStringSetting(_name) \
    vk::LayerSettingEXT(kLayerSettingsName, #_name, vk::LayerSettingTypeEXT::eString, 1, &_name)

#define MakeBoolSetting(_name) \
    vk::LayerSettingEXT(kLayerSettingsName, #_name, vk::LayerSettingTypeEXT::eBool32, 1, &_name)

#define MakeUint64Setting(_name) \
    vk::LayerSettingEXT(kLayerSettingsName, #_name, vk::LayerSettingTypeEXT::eUint64, 1, &_name)

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

LayerSettings::LayerSettings(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, Logger& logger) {
    const VkLayerSettingsCreateInfoEXT* settings_create_info = vku::FindStructInPNextChain<VkLayerSettingsCreateInfoEXT>(pCreateInfo);

    VkuLayerSettingSet layer_setting_set = VK_NULL_HANDLE;
    VkResult result =
        vkuCreateLayerSettingSet("lunarg_crash_diagnostic", settings_create_info, pAllocator, nullptr, &layer_setting_set);
    if (result != VK_SUCCESS) {
        logger.Error("vkuCreateLayerSettingSet failed with error %d", result);
        return;
    }

}

LayerSettings::~LayerSettings() {
}

void LayerSettings::Print(YAML::Emitter& os) const {
    os << YAML::BeginMap;
    os << YAML::Key << settings::kOutputPath << YAML::Value << output_path;
    os << YAML::Key << settings::kTraceOn << YAML::Value << trace_all;
    os << YAML::Key << settings::kDumpQueueSubmits << YAML::Value << dump_queue_submits;
    os << YAML::Key << settings::kDumpCommandBuffers << YAML::Value << dump_command_buffers;
    os << YAML::Key << settings::kDumpCommands << YAML::Value << dump_commands;
    os << YAML::Key << settings::kDumpShaders << YAML::Value << dump_shaders;
    os << YAML::Key << settings::kTriggerWatchdogTimeout << YAML::Value << trigger_watchdog_timer;
    os << YAML::Key << settings::kWatchdogTimeout << YAML::Value << watchdog_timer_ms;
    os << YAML::Key << settings::kTrackSemaphores << YAML::Value << track_semaphores;
    os << YAML::Key << settings::kTraceAllSemaphores << YAML::Value << trace_all_semaphores;
    os << YAML::Key << settings::kInstrumentAllCommands << YAML::Value << instrument_all_commands;
    os << YAML::Key << settings::kSyncAfterCommands << YAML::Value << sync_after_commands;
    os << YAML::EndMap;
}
*/