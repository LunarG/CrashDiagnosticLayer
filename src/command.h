/*
 Copyright 2018 Google Inc.
 Copyright (c) 2023-2024 LunarG, Inc.

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
#include <mutex>
#include <stack>
#include <string>
#include <vector>

#include "command_common.h"
#include "command_tracker.h"
#include "command_printer.h"
#include "descriptor_set.h"
#include "checkpoint.h"

namespace YAML {
class Emitter;
}  // namespace YAML

namespace crash_diagnostic_layer {

class Device;
class Settings;

enum class CommandState {
    kCommandNotSubmitted,  // not submitted
    kCommandPending,       // submitted, no more information available
    kCommandNotStarted,    // submitted, not started
    kCommandIncomplete,    // submitted, started, not finished
    kCommandCompleted,     // submitted and executed
    kInvalidState,
};

enum class CommandBufferState {
    // Vulkan CommandBuffer states from the spec
    // 5.1, Figure 1. Lifecycle of a command buffer
    kInitial,     // created (we have a separate state for reset)
    kRecording,   // begin called
    kExecutable,  // end called
    kPending,     // submitted
    kInvalid,     // invalid
    // Additional state since we know if a command buffer is reset
    kInitialReset,  // reset
    // The following are extensions of kPending and only can be verified when
    // a hang or crash is detected and checkpoint values are read.
    kSubmittedExecutionNotStarted,  // submitted but not started
    kSubmittedExecutionIncomplete,  // submitted and started, but not finished
    kSubmittedExecutionCompleted,   // submitted and finished
    // The following is used for secondary command buffers when the command
    // vkCmdExecuteCommands is not submitted.
    kNotSubmitted,
};

// =================================================================================================
// CommandBuffer
// =================================================================================================
class CommandBuffer {
   public:
    CommandBuffer(Device& device, VkCommandPool vk_command_pool, VkCommandBuffer vk_command_buffer,
                  const VkCommandBufferAllocateInfo* allocate_info, bool has_checkpoints);
    ~CommandBuffer();

    Device& GetDevice() const { return device_; }
    VkQueue GetSubmittedQueue() const { return submitted_queue_; }
    VkFence GetSubmittedFence() const { return submitted_fence_; }
    VkCommandPool GetVkCommandPool() { return vk_command_pool_; }
    VkCommandBuffer GetVkCommandBuffer() { return vk_command_buffer_; }

    CommandBufferState GetCommandBufferState() const;
    std::string PrintCommandBufferState() const { return PrintCommandBufferState(GetCommandBufferState()); }

    void SetCompleted() { buffer_state_ = CommandBufferState::kSubmittedExecutionCompleted; }
    bool IsPrimaryCommandBuffer() const { return cb_level_ == VK_COMMAND_BUFFER_LEVEL_PRIMARY; }
    bool HasCheckpoints() const { return checkpoint_ != nullptr; }

    uint64_t GetQueueSeq() { return submitted_queue_seq_; }
    void SetInstrumentAllCommands(bool all) { instrument_all_commands_ = all; }

    bool WasSubmittedToQueue() const;
    bool StartedExecution() const;
    bool CompletedExecution() const;

    void Reset();
    void QueueSubmit(VkQueue queue, uint64_t queue_seq, VkFence fence);

    void DumpContents(YAML::Emitter& os, const Settings& settings, uint64_t secondary_cb_submit_info_id = 0,
                      CommandState vkcmd_execute_commands_command_state = CommandState::kInvalidState);

    // custom command buffer functions (not autogenerated)
    VkResult PreBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo);

    VkResult PostBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo,
                                    VkResult result);

    VkResult PreEndCommandBuffer(VkCommandBuffer commandBuffer);

    VkResult PostEndCommandBuffer(VkCommandBuffer commandBuffer, VkResult result);

    VkResult PreResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags);

    VkResult PostResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags, VkResult result);

    CommandBuffer& operator=(const CommandBuffer&) = delete;
    CommandBuffer(const CommandBuffer&) = delete;

// =============================================================================
// Include the generated command tracking code defines
// =============================================================================
#include "command.h.inc"

   private:
    const char* GetCommandName(const Command& command);

    std::string PrintCommandBufferState(CommandBufferState cb_state) const;
    CommandBufferState GetSecondaryCommandBufferState(CommandState vkcmd_execute_commands_command_state) const;
    CommandState GetCommandState(CommandBufferState cb_state, const Command& command) const;
    std::string PrintCommandState(CommandState cm_state) const;

    bool DumpCmdExecuteCommands(const Command& command, CommandState command_state, YAML::Emitter& os,
                                const Settings& settings);

    uint32_t GetLastStartedCommand() const;
    uint32_t GetLastCompleteCommand() const;

    bool DumpCommand(const Command& command, YAML::Emitter& os);
    void HandleIncompleteCommand(const Command& command, const class CommandBufferInternalState& state) const;

   private:
    Device& device_;
    VkCommandPool vk_command_pool_ = VK_NULL_HANDLE;
    VkCommandBuffer vk_command_buffer_ = VK_NULL_HANDLE;

    VkCommandBufferLevel cb_level_ = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    bool cb_simultaneous_use_ = false;

    // secondary command buffer inheritance info
    VkCommandBufferInheritanceInfo* scb_inheritance_info_ = nullptr;

    bool instrument_all_commands_ = false;

    std::unique_ptr<Checkpoint> checkpoint_;

    uint32_t begin_value_;
    uint32_t end_value_;

    CommandBufferState buffer_state_ = CommandBufferState::kInitial;
    VkQueue submitted_queue_ = VK_NULL_HANDLE;
    uint64_t submitted_queue_seq_ = 0;
    VkFence submitted_fence_ = VK_NULL_HANDLE;

    CommandTracker tracker_;
    CommandPrinter printer_;

    void WriteBeginCheckpoint();
    void WriteEndCheckpoint();
    void WriteCommandBeginCheckpoint(uint32_t command_id);
    void WriteCommandEndCheckpoint(uint32_t command_id);
};

using CommandBufferPtr = std::unique_ptr<CommandBuffer>;

}  // namespace crash_diagnostic_layer
