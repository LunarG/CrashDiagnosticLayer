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

#include <vulkan/vulkan_core.h>
#include <vulkan/vk_icd.h>
#include <vulkan/utility/vk_safe_struct.hpp>
#include <memory>
#include <optional>
#include <vector>

#include "command_tracker.h"

namespace icd {
class Queue;
class CommandBuffer {
   public:
    CommandBuffer(VkCommandBufferLevel lvl) : level_(lvl) { set_loader_magic_value(&loader_data_); }
    VkResult Execute(Queue& queue);
    VkResult Reset(VkCommandBufferResetFlags flags);

    CommandTracker& Tracker() { return tracker_; }
    void CmdBeginDebugUtilsLabel(const VkDebugUtilsLabelEXT* pLabelInfo);

   private:
    // Common function for vkCmdWriteBufferMarker() and vkCmdWriteBufferMarker2()
    VkResult WriteBufferMarker(uint32_t id, VkPipelineStageFlagBits2 stage, VkBuffer buffer, VkDeviceSize offset,
                               uint32_t marker);

    VkResult SetCheckpoint(uint32_t id, Queue& queue, const CmdSetCheckpointNVArgs& args);
    VkResult ExecuteCommands(Queue& queue, const CmdExecuteCommandsArgs& args);

    VK_LOADER_DATA loader_data_;  // MUST be first data member
    VkCommandBufferLevel level_;
    CommandTracker tracker_;
    bool in_hang_region_{false};
    std::optional<vku::safe_VkDebugUtilsLabelEXT> fault_label_;
};

class CommandPool {
   public:
    CommandPool(const VkCommandPoolCreateInfo& create_info);

    VkResult Allocate(const VkCommandBufferAllocateInfo& alloc_info, VkCommandBuffer* cbs);
    VkResult Reset(VkCommandPoolResetFlags flags);
    void Free(uint32_t cb_count, const VkCommandBuffer* cbs);

   private:
    VkCommandPoolCreateFlags flags_;
    uint32_t qfi_;
    std::vector<std::unique_ptr<CommandBuffer>> command_buffers_;
};

}  // namespace icd
