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

enum LogOutputs {
    kNone,
    kStderr,
    kStdout,
};

const char* kOutputPath = "output_path";
const char* kLogFile = "log_file";

const char* SETTING_DUMP_SEMAPHORES = "dump_semaphores";
const char* SETTING_DUMP_QUEUE_SUBMITS = "dump_queue_submits";
const char* SETTING_DUMP_COMMAND_BUFFERS = "dump_command_buffers";
const char* SETTING_DUMP_COMMANDS = "dump_commands";
const char* SETTING_DUMP_SHADERS = "dump_shaders";

const char* kTriggerWatchdogTimeout = "trigger_watchdog_timeout";
const char* kWatchdogTimeout = "watchdog_timeout_ms";

const char* kInstrumentAllCommands = "instrument_all_commands";
const char* kSyncAfterCommands = "sync_after_commands";
const char *SETTING_LOG_FILENAME = "log_filename";
const char *SETTING_DEBUG_ACTION = "debug_action";
const char *SETTING_MESSAGE_SEVERITY = "message_severity";
const char *SETTING_MESSAGE_AREAS = "message_areas";

static const std::unordered_map<std::string, LogOutputs> kLogFileValues{
    {"none", LogOutputs::kNone},
    {"stderr", LogOutputs::kStderr},
    {"stdout", LogOutputs::kStdout},
};

static const std::unordered_map<std::string, VkFlags> kDebugActionValues = {
    {"VK_DBG_LAYER_ACTION_IGNORE", VK_DBG_LAYER_ACTION_IGNORE},
    {"VK_DBG_LAYER_ACTION_CALLBACK", VK_DBG_LAYER_ACTION_CALLBACK},
    {"VK_DBG_LAYER_ACTION_LOG_MSG", VK_DBG_LAYER_ACTION_LOG_MSG},
    {"VK_DBG_LAYER_ACTION_BREAK", VK_DBG_LAYER_ACTION_BREAK},
    {"VK_DBG_LAYER_ACTION_DEBUG_OUTPUT", VK_DBG_LAYER_ACTION_DEBUG_OUTPUT},
    {"VK_DBG_LAYER_ACTION_LOG_STDOUT", VK_DBG_LAYER_ACTION_LOG_STDOUT},
    {"VK_DBG_LAYER_ACTION_LOG_STDERR", VK_DBG_LAYER_ACTION_LOG_STDERR},
    {"VK_DBG_LAYER_ACTION_DEFAULT", VK_DBG_LAYER_ACTION_DEFAULT}
};

static const std::unordered_map<std::string, VkDebugUtilsMessageSeverityFlagBitsEXT> kMessageSeverityValues{
    {"error", VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT},
    {"warn", VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT},
    {"info", VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT},
    {"verbose", VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT},
};

static const std::unordered_map<std::string, MessageAreaBits> kMessageAreaValues{
    {"common", MESSAGE_AREA_COMMON_BIT},
    {"semaphore", MESSAGE_AREA_SEMAPHORE_BIT},
    {"perf", MESSAGE_AREA_PERF_BIT},
};

static const std::unordered_map<std::string, DumpSemaphores> kDumpSemaphoresValues{
    {"off", DumpSemaphores::kOff},
    {"on_crash", DumpSemaphores::kOnCrash},
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

    GetEnvVal<bool>(layer_setting_set, kSyncAfterCommands, sync_after_commands);
    GetEnvVal<bool>(layer_setting_set, kInstrumentAllCommands, instrument_all_commands);

    // output path
    if (vkuHasLayerSetting(layer_setting_set, kOutputPath)) {
        std::string output_path_string;
        vkuGetLayerSettingValue(layer_setting_set, kOutputPath, output_path_string);
        this->output_path = output_path_string;
    }

    std::filesystem::path default_output_path = System::GetOutputBasePath();
    default_output_path /= "cdl";
    {
        if (this->output_path.empty()) {
            this->output_path = default_output_path;
        }

        this->base_output_path = this->output_path;
        this->output_path /= start_time_str;
        default_output_path /= start_time_str;
    }

    GetEnvVal<bool>(layer_setting_set, kTriggerWatchdogTimeout, this->trigger_watchdog_timer);
    GetEnvVal<uint64_t>(layer_setting_set, kWatchdogTimeout, this->watchdog_timer_ms);

    GetEnumVal<DumpSemaphores>(log, layer_setting_set, SETTING_DUMP_SEMAPHORES, this->dump_semaphores, kDumpSemaphoresValues);
    GetEnumVal<DumpCommands>(log, layer_setting_set, SETTING_DUMP_QUEUE_SUBMITS, this->dump_queue_submits, kDumpCommandsValues);
    GetEnumVal<DumpCommands>(log, layer_setting_set, SETTING_DUMP_COMMAND_BUFFERS, this->dump_command_buffers, kDumpCommandsValues);
    GetEnumVal<DumpCommands>(log, layer_setting_set, SETTING_DUMP_COMMANDS, this->dump_commands, kDumpCommandsValues);
    GetEnumVal<DumpShaders>(log, layer_setting_set, SETTING_DUMP_SHADERS, this->dump_shaders, kDumpShadersValues);

    if (vkuHasLayerSetting(layer_setting_set, SETTING_DEBUG_ACTION)) {
        std::vector<std::string> debug_actions_list;
        vkuGetLayerSettingValues(layer_setting_set, SETTING_DEBUG_ACTION, debug_actions_list);

        this->debug_action = 0;
        for (const auto &element : debug_actions_list) {
            auto enum_value = kDebugActionValues.find(element);
            if (enum_value != kDebugActionValues.end()) {
                this->debug_action |= enum_value->second;
            } else {
                if (element.find(',') != std::string::npos) {
                    log.Warning(
                        "\"" + element + "\" is not a valid value for `debug_action` (ignoring).\n"
                        "If using `VkLayerSettings`, each string needs to be its own `VkLayerSettingEXT::pValues`.");
                } else {
                    log.Warning(
                        "\"" + element + "\" is not a valid value for `debug_action` (ignoring).\n"
                        "Valid values are [VK_DBG_LAYER_ACTION_IGNORE, VK_DBG_LAYER_ACTION_CALLBACK, "
                        "VK_DBG_LAYER_ACTION_LOG_MSG, VK_DBG_LAYER_ACTION_LOG_STDOUT, VK_DBG_LAYER_ACTION_LOG_STDERR, "
                        "VK_DBG_LAYER_ACTION_BREAK, VK_DBG_LAYER_ACTION_DEBUG_OUTPUT, VK_DBG_LAYER_ACTION_DEFAULT]");
                }
            }
        }

    }

    // logging
    {
        std::string log_file;
        if (GetEnvVal<std::string>(layer_setting_set, kLogFile, log_file)) {
            auto iter = kLogFileValues.find(log_file);
            if (iter != kLogFileValues.end()) {
                switch (iter->second) {
                    case LogOutputs::kNone:
                        log.CloseLogFile();
                        break;
                    case LogOutputs::kStderr:
                        log.LogToStderr();
                        break;
                    case LogOutputs::kStdout:
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

        std::string message_severity;
        if (GetEnvVal<std::string>(layer_setting_set, SETTING_MESSAGE_SEVERITY, message_severity)) {
            VkDebugUtilsMessageSeverityFlagsEXT mask{0};
            bool bad_value = false;
            if (!message_severity.empty()) {
                std::regex re("[\\s,]+");
                std::sregex_token_iterator re_iter(message_severity.begin(), message_severity.end(), re, -1);
                std::sregex_token_iterator re_end;
                for (; re_iter != re_end; ++re_iter) {
                    auto iter = kMessageSeverityValues.find(*re_iter);
                    if (iter != kMessageSeverityValues.end()) {
                        mask |= iter->second;
                    } else {
                        bad_value = true;
                        std::string value = *re_iter;
                        log.Error("Bad value for `message_severity` setting: \"%s\"", value.c_str());
                    }
                }
            }
            if (!bad_value) {
                log.SetSeverity(mask);
            }
        }

        std::string message_areas;
        if (GetEnvVal<std::string>(layer_setting_set, SETTING_MESSAGE_AREAS, message_areas)) {
            MessageAreaFlags mask{0};
            bool bad_value = false;
            if (!message_areas.empty()) {
                std::regex re("[\\s,]+");
                std::sregex_token_iterator re_iter(message_areas.begin(), message_areas.end(), re, -1);
                std::sregex_token_iterator re_end;
                for (; re_iter != re_end; ++re_iter) {
                    auto iter = kMessageAreaValues.find(*re_iter);
                    if (iter != kMessageAreaValues.end()) {
                        mask |= iter->second;
                    } else {
                        bad_value = true;
                        std::string value = *re_iter;
                        log.Error("Bad value for `message_areas` setting: \"%s\"", value.c_str());
                    }
                }
            }
            if (!bad_value) {
                log.SetAreas(mask);
            }
        }
    }

    vkuDestroyLayerSettingSet(layer_setting_set, nullptr);

    log.Info("Version %s enabled. Start time tag: %s", kCdlVersion.c_str(), start_time_str.c_str());
}

YAML::Emitter& operator<<(YAML::Emitter& os, DumpSemaphores value) {
    for (auto& entry : kDumpSemaphoresValues) {
        if (value == entry.second) {
            os << entry.first;
            return os;
        }
    }
    os << "unknown";
    return os;
}

YAML::Emitter& operator<<(YAML::Emitter& os, DumpCommands value) {
    for (auto& entry : kDumpCommandsValues) {
        if (value == entry.second) {
            os << entry.first;
            return os;
        }
    }
    os << "unknown";
    return os;
}

YAML::Emitter& operator<<(YAML::Emitter& os, DumpShaders value) {
    for (auto& entry : kDumpShadersValues) {
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
    os << YAML::Key << kOutputPath << YAML::Value << output_path.c_str();
    os << YAML::Key << kInstrumentAllCommands << YAML::Value << instrument_all_commands;
    os << YAML::Key << kSyncAfterCommands << YAML::Value << sync_after_commands;


    os << YAML::Key << kTriggerWatchdogTimeout << YAML::Value << trigger_watchdog_timer;
    os << YAML::Key << kWatchdogTimeout << YAML::Value << watchdog_timer_ms;

    os << YAML::Key << SETTING_DUMP_SEMAPHORES << YAML::Value << this->dump_semaphores;
    os << YAML::Key << SETTING_DUMP_QUEUE_SUBMITS << YAML::Value << this->dump_queue_submits;
    os << YAML::Key << SETTING_DUMP_COMMAND_BUFFERS << YAML::Value << this->dump_command_buffers;
    os << YAML::Key << SETTING_DUMP_COMMANDS << YAML::Value << this->dump_commands;
    os << YAML::Key << SETTING_DUMP_SHADERS << YAML::Value << this->dump_shaders;

    //TODO
    //os << YAML::Key << kLogFile << YAML::Value << this-> output_path.c_str();
    //os << YAML::Key << SETTING_DEBUG_ACTION << YAML::Value << this->debug_action;
    //os << YAML::Key << SETTING_LOG_FILENAME << YAML::Value << this->log_filename;

    //os << YAML::Key << SETTING_MESSAGE_SEVERITY << YAML::Value << this->message_severity;
    //os << YAML::Key << SETTING_MESSAGE_AREAS << YAML::Value << this->message_areas;

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