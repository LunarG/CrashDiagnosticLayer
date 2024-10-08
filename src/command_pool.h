/*
 Copyright 2018 Google Inc.
 Copyright 2023-2024 LunarG, Inc.

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

#include <memory>
#include <vector>

namespace crash_diagnostic_layer {

class Device;

// =================================================================================================
// CommandPool
// =================================================================================================
class CommandPool {
   public:
    CommandPool(VkCommandPool vk_command_pool, const VkCommandPoolCreateInfo* p_create_info);

    bool CanResetBuffer() const { return m_flags & VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT; }

    void Reset();

    void AllocateCommandBuffers(const VkCommandBufferAllocateInfo* allocate_info,
                                const VkCommandBuffer* p_command_buffers);
    void FreeCommandBuffers(uint32_t command_buffer_count, const VkCommandBuffer* p_command_buffers);

    VkCommandPool GetCommandPool() const { return vk_command_pool_; }

    const std::vector<VkCommandBuffer>& GetCommandBuffers(VkCommandBufferLevel level) const;

   private:
    VkCommandPool vk_command_pool_;

    VkCommandPoolCreateFlags m_flags;

    std::vector<VkCommandBuffer> primary_command_buffers_;
    std::vector<VkCommandBuffer> secondary_command_buffers_;
};

using CommandPoolPtr = std::unique_ptr<CommandPool>;

}  // namespace crash_diagnostic_layer
