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
#pragma once
#include <vulkan/vulkan.hpp>
#include <string>
#include <vector>

namespace YAML {
class Emitter;
}  // namespace YAML

class Logger;

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

std::string GetSettingKey();
SettingId GetSettingId(const std::string& setting_key);

bool IsDeprecated(SettingId setting_id);

enum CrashSource {
    kDeviceLostError,
    kWatchdogTimer,
};

enum class DumpSemaphores {
    kOff = 0,
    kOnCrash
};

// Used for command buffers, commands and queue submisions
enum class DumpCommands {
    kRunning = 0,
    kPending,
    kAll,
};

enum class DumpShaders {
    kOff = 0,
    kOnCrash,
    kOnBind,
    kAll,
};

// The members of this struct should be kept in sync with
// the setting found in the layer json file.
class LayerSettings {
   public:
    LayerSettings(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, Logger& logger);
    ~LayerSettings();

    // logging section
    bool trace_on{false};

    bool sync_after_commands{false};
    bool instrument_all_commands{false};

    std::string output_path;
    bool trigger_watchdog_timer{true};
    uint64_t watchdog_timer_ms{30000};

    DumpSemaphores dump_semaphores{DumpSemaphores::kOff};
    DumpCommands dump_queue_submits{DumpCommands::kRunning};
    DumpCommands dump_command_buffers{DumpCommands::kRunning};
    DumpCommands dump_commands{DumpCommands::kRunning};
    DumpShaders dump_shaders{DumpShaders::kOff};

    VkLayerDbgActionFlags debug_action = VK_DBG_LAYER_ACTION_LOG_MSG | VK_DBG_LAYER_ACTION_DEBUG_OUTPUT;
    std::string log_filename = "cdl_log.txt";
    VkDebugReportFlagBitsEXT report_flags = VK_DEBUG_REPORT_ERROR_BIT_EXT;
    int log_trace_api{AREA_SEMAPHORES_NONE};

   private:
    std::vector<vk::LayerSettingEXT> settings_;
    vk::LayerSettingsCreateInfoEXT create_info_;
};
