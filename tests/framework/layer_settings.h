/*
 * Copyright (c) 2024 The Khronos Group Inc.
 * Copyright (c) 2024 Valve Corporation
 * Copyright (c) 2024 LunarG, Inc.
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
    LayerSettings(const void* pnext = nullptr);
    ~LayerSettings();

    const vk::LayerSettingsCreateInfoEXT* GetCreateInfo() { return &create_info_; }

    void SetOutputPath(const char*);
    void SetLogFile(const char*);
    void SetMessageSeverity(const char*);
    void SetDumpShaders(const char*);
    void SetDumpQueueSubmits(const char*);
    void SetDumpCommandBuffers(const char*);
    void SetDumpCommands(const char*);

    // logging section
    vk::Bool32 trace_on{false};

    // commands section
    vk::Bool32 instrument_all_commands{false};
    vk::Bool32 sync_after_commands{false};

    // semaphores section
    vk::Bool32 track_semaphores{true};
    vk::Bool32 trace_all_semaphores{false};

    // hang detection section
    uint64_t watchdog_timeout_ms{20000};

   private:
    // these member names must match the setting name exactly.
    char* output_path{nullptr};
    char* log_file{nullptr};
    char* message_severity{nullptr};
    char* dump_shaders{nullptr};
    char* dump_queue_submits{nullptr};
    char* dump_command_buffers{nullptr};
    char* dump_commands{nullptr};

    std::vector<vk::LayerSettingEXT> settings_;
    vk::LayerSettingsCreateInfoEXT create_info_;
};
