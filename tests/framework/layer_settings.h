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

// The members of this struct should be kept in sync with
// the setting found in the layer json file.
// The values in here should be the defaults we want to use
// for testing.
class LayerSettings {
   public:
    LayerSettings(const void* pnext = nullptr) : pnext(pnext) {}
    ~LayerSettings() {}

    const vk::LayerSettingsCreateInfoEXT* BuildCreateInfo();

    vk::Bool32 sync_after_commands{false};
    vk::Bool32 instrument_all_commands{false};

    std::string output_path = "";
    bool trigger_watchdog_timer{true};
    uint64_t watchdog_timeout_ms{30000};

    std::string dump_semaphores = "off";
    std::string dump_queue_submits = "running";
    std::string dump_command_buffers = "running";
    std::string dump_commands = "running";
    std::string dump_shaders = "off";
    std::vector<std::string> debug_action;
    std::vector<std::string> message_severity = {"error"};
    std::string log_file = "cdl_log.txt";
    std::vector<std::string> message_api_trace;

   private:
    const char* output_path_info = nullptr;

    const char* dump_semaphores_info = nullptr;
    const char* dump_queue_submits_info = nullptr;
    const char* dump_command_buffers_info = nullptr;
    const char* dump_commands_info = nullptr;
    const char* dump_shaders_info = nullptr;

    std::vector<const char*> debug_action_info;
    std::vector<const char*> message_severity_info;
    const char* log_file_info = nullptr;
    std::vector<const char*> message_api_trace_info;

    std::vector<vk::LayerSettingEXT> settings_;
    const void* pnext = nullptr;
    vk::LayerSettingsCreateInfoEXT create_info_;
};
