/*
 Copyright 2020 Google Inc.
 Copyright 2023 LunarG, Inc.

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

#include <vulkan/vulkan.h>

#include <algorithm>
#include <thread>
#include <unordered_map>

namespace crash_diagnostic_layer {

class CommandBuffer;
using CommandBufferPtr = std::unique_ptr<CommandBuffer>;

// Thread local cache
struct ThreadLocalCommandBufferCache {
    VkCommandBuffer vkcb = VK_NULL_HANDLE;
    crash_diagnostic_layer::CommandBuffer *cdlcb = nullptr;
};

void SetCdlCommandBuffer(VkCommandBuffer vk_command_buffer, CommandBufferPtr command_buffer);

crash_diagnostic_layer::CommandBuffer *GetCdlCommandBuffer(VkCommandBuffer vk_command_buffer);

void DeleteCdlCommandBuffer(VkCommandBuffer vk_command_buffer);

}  // namespace crash_diagnostic_layer
