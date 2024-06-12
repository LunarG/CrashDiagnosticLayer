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
#include "test_icd_command.h"
#include "test_icd_memory.h"
#include "test_icd_queue.h"

#include <vulkan/utility/vk_struct_helper.hpp>

#include <cstdint>
namespace icd {

VkResult CommandBuffer::Execute(Queue &queue) {
    VkResult result = VK_SUCCESS;
    bool hang_next_cmd = false;
    auto &cmds = tracker_.GetCommands();
    for (auto &cmd : cmds) {
        switch (cmd.type) {
            case Command::Type::kCmdWriteBufferMarkerAMD: {
                auto args = reinterpret_cast<CmdWriteBufferMarkerAMDArgs *>(cmd.parameters);
                WriteBufferMarker(cmd.id, args->pipelineStage, args->dstBuffer, args->dstOffset, args->marker);
                break;
            }
            case Command::Type::kCmdWriteBufferMarker2AMD: {
                auto args = reinterpret_cast<CmdWriteBufferMarker2AMDArgs *>(cmd.parameters);
                WriteBufferMarker(cmd.id, args->stage, args->dstBuffer, args->dstOffset, args->marker);
                break;
            }
            case Command::Type::kCmdSetCheckpointNV: {
                auto args = reinterpret_cast<CmdSetCheckpointNVArgs *>(cmd.parameters);
                SetCheckpoint(cmd.id, queue, *args);
                break;
            }
            case Command::Type::kCmdBeginDebugUtilsLabelEXT: {
                auto args = reinterpret_cast<CmdBeginDebugUtilsLabelEXTArgs *>(cmd.parameters);
                if (fault_label_.has_value() && strcmp(fault_label_->pLabelName, args->pLabelInfo->pLabelName) == 0) {
                    in_hang_region_ = true;
                }
                break;
            }
            case Command::Type::kCmdEndDebugUtilsLabelEXT: {
                if (in_hang_region_) {
                    in_hang_region_ = false;
                    result = VK_ERROR_DEVICE_LOST;
                    // queue.SetFaultInfo(std::move(fault_info_);
                }
                break;
            }
            case Command::Type::kCmdExecuteCommands: {
                if (!in_hang_region_) {
                    auto args = reinterpret_cast<CmdExecuteCommandsArgs *>(cmd.parameters);
                    result = ExecuteCommands(queue, *args);
                }
                break;
            }
            default:
                break;
        }
        if (result != VK_SUCCESS) {
            break;
        }
    }
    return result;
}

VkResult CommandBuffer::WriteBufferMarker(uint32_t id, VkPipelineStageFlagBits2 stage, VkBuffer buffer,
                                          VkDeviceSize offset, uint32_t marker) {
    assert(stage == VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT || stage == VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT);
    if (!in_hang_region_ || stage == VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT) {
        auto *buf = reinterpret_cast<Buffer *>(buffer);
        assert(buf);
        buf->Write(offset, marker);
    }
    return VK_SUCCESS;
}

VkResult CommandBuffer::SetCheckpoint(uint32_t id, Queue &queue, const CmdSetCheckpointNVArgs &args) {
    auto stage = in_hang_region_ ? VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT : VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT;
    queue.TrackCheckpoint(uintptr_t(args.pCheckpointMarker), stage);
    return VK_SUCCESS;
}

VkResult CommandBuffer::ExecuteCommands(Queue &queue, const CmdExecuteCommandsArgs &args) {
    VkResult result = VK_SUCCESS;
    if (args.pCommandBuffers && args.commandBufferCount > 0) {
        for (uint32_t i = 0; i < args.commandBufferCount; i++) {
            auto *secondary = reinterpret_cast<CommandBuffer *>(args.pCommandBuffers[i]);
            assert(secondary);
            result = secondary->Execute(queue);
            if (result != VK_SUCCESS) {
                break;
            }
        }
    }
    return result;
}

VkResult CommandBuffer::Reset(VkCommandBufferResetFlags flags) {
    tracker_.Reset();
    return VK_SUCCESS;
}

void CommandBuffer::CmdBeginDebugUtilsLabel(const VkDebugUtilsLabelEXT *pLabelInfo) {
    tracker_.CmdBeginDebugUtilsLabelEXT(reinterpret_cast<VkCommandBuffer>(this), pLabelInfo);
    auto *fault_counts = vku::FindStructInPNextChain<VkDeviceFaultCountsEXT>(pLabelInfo->pNext);
    if (fault_counts) {
        assert(!fault_label_.has_value());
        fault_label_.emplace(pLabelInfo);
    }
}

CommandPool::CommandPool(const VkCommandPoolCreateInfo &create_info)
    : flags_(create_info.flags), qfi_(create_info.queueFamilyIndex) {}

VkResult CommandPool::Allocate(const VkCommandBufferAllocateInfo &alloc_info, VkCommandBuffer *cbs) {
    VkResult result = VK_SUCCESS;
    for (uint32_t i = 0; i < alloc_info.commandBufferCount; i++) {
        command_buffers_.emplace_back(std::make_unique<CommandBuffer>(alloc_info.level));
        if (!command_buffers_.back()) {
            result = VK_ERROR_OUT_OF_HOST_MEMORY;
            break;
        }
        cbs[i] = reinterpret_cast<VkCommandBuffer>(command_buffers_.back().get());
    }
    return result;
}

VkResult CommandPool::Reset(VkCommandPoolResetFlags flags) {
    VkResult result = VK_SUCCESS;
    VkCommandBufferResetFlags cb_flags = 0;
    if (flags & VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT) {
        cb_flags |= VK_COMMAND_BUFFER_RESET_RELEASE_RESOURCES_BIT;
    }
    for (auto &cb : command_buffers_) {
        result = cb->Reset(cb_flags);
        if (result != VK_SUCCESS) {
            break;
        }
    }
    return result;
}

void CommandPool::Free(uint32_t cb_count, const VkCommandBuffer *cbs) {
    for (uint32_t i = 0; i < cb_count; i++) {
        for (auto iter = command_buffers_.begin(); iter != command_buffers_.end(); ++iter) {
            if (iter->get() == reinterpret_cast<CommandBuffer *>(cbs[i])) {
                command_buffers_.erase(iter);
                break;
            }
        }
    }
}
}  // namespace icd
