/*
 Copyright 2020 Google Inc.

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

#ifndef GFR_COMMAND_BUFFER_TRACKER_H
#define GFR_COMMAND_BUFFER_TRACKER_H

#include <vulkan/vulkan.h>

#include <algorithm>
#include <thread>
#include <unordered_map>

namespace graphics_flight_recorder {

class CommandBuffer;
using CommandBufferPtr = std::unique_ptr<CommandBuffer>;

// Thread local cache
struct ThreadLocalCommandBufferCache {
  VkCommandBuffer vkcb = VK_NULL_HANDLE;
  graphics_flight_recorder::CommandBuffer *gfrcb = nullptr;
};

void SetGfrCommandBuffer(VkCommandBuffer vk_command_buffer,
                         CommandBufferPtr command_buffer);

graphics_flight_recorder::CommandBuffer *
GetGfrCommandBuffer(VkCommandBuffer vk_command_buffer);

void DeleteGfrCommandBuffer(VkCommandBuffer vk_command_buffer);

} // namespace graphics_flight_recorder

#endif  // GFR_COMMAND_BUFFER_TRACKER_H
