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

#include "command.h"
#include "util.h"

#include <cassert>
#include <cstring>
#include <memory>
#include <sstream>
#include <yaml-cpp/emitter.h>

#include "device.h"
#include "cdl.h"

namespace crash_diagnostic_layer {

static std::atomic<uint16_t> command_buffer_marker_high_bits{1};

CommandBuffer::CommandBuffer(Device* p_device, VkCommandPool vk_command_pool, VkCommandBuffer vk_command_buffer,
                             const VkCommandBufferAllocateInfo* allocate_info, bool has_buffer_marker)
    : device_(p_device),
      vk_command_pool_(vk_command_pool),
      vk_command_buffer_(vk_command_buffer),
      cb_level_(allocate_info->level),
      has_buffer_marker_(has_buffer_marker) {
    if (has_buffer_marker_) {
        top_marker_.type = MarkerType::kUint32;
        bottom_marker_.type = MarkerType::kUint32;
        bool top_marker_is_valid = p_device->AllocateMarker(&top_marker_);
        if (!top_marker_is_valid || !p_device->AllocateMarker(&bottom_marker_)) {
            device_->GetContext()->GetLogger()->LogWarning("Cannot acquire markers. Not tracking VkCommandBuffer %s",
                                                           device_->GetObjectName((uint64_t)vk_command_buffer).c_str());
            has_buffer_marker_ = false;
            if (top_marker_is_valid) {
                p_device->FreeMarker(top_marker_);
            }
        } else {
            // We have top and bottom markers initialized. We need to set begin and
            // end command buffer marker values.
            begin_marker_value_ = ((uint32_t)command_buffer_marker_high_bits.fetch_add(1)) << 16;
            // Double check begin_marker_value to make sure it's not zero.
            if (!begin_marker_value_) {
                begin_marker_value_ = ((uint32_t)command_buffer_marker_high_bits.fetch_add(1)) << 16;
            }
            end_marker_value_ = begin_marker_value_ | 0x0000FFFF;
        }
    }
}

CommandBuffer::~CommandBuffer() {
    if (scb_inheritance_info_) {
        delete scb_inheritance_info_;
    }
    if (has_buffer_marker_) {
        device_->FreeMarker(top_marker_);
        device_->FreeMarker(bottom_marker_);
    }
    device_ = nullptr;
    vk_command_pool_ = VK_NULL_HANDLE;
    vk_command_buffer_ = VK_NULL_HANDLE;
    has_buffer_marker_ = false;
}

void CommandBuffer::SetSubmitInfoId(uint64_t submit_info_id) { submit_info_id_ = submit_info_id; }

void CommandBuffer::WriteMarker(MarkerPosition position, uint32_t marker_value) {
    assert(has_buffer_marker_);
    auto& marker = (position == MarkerPosition::kTop) ? top_marker_ : bottom_marker_;
    auto pipelineStage =
        (position == MarkerPosition::kTop) ? VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT : VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT;
    device_->CmdWriteBufferMarkerAMD(vk_command_buffer_, pipelineStage, marker.buffer, marker.offset, marker_value);
}

uint32_t CommandBuffer::ReadMarker(MarkerPosition position) const {
    assert(has_buffer_marker_);
    auto& marker = (position == MarkerPosition::kTop) ? top_marker_ : bottom_marker_;
    auto value = *(uint32_t*)(marker.cpu_mapped_address);
    return value;
}

void CommandBuffer::WriteBeginCommandBufferMarker() {
    if (has_buffer_marker_) {
        // CDL log lables the commands inside a command buffer as follows:
        // - vkBeginCommandBuffer: 1
        // - n vkCmd commands recorded into command buffer: 2 ... n+1
        // - vkEndCommandBuffer: n+2
        WriteMarker(MarkerPosition::kTop, begin_marker_value_ + 1);
        WriteMarker(MarkerPosition::kBottom, begin_marker_value_ + 1);
    }
}

void CommandBuffer::WriteEndCommandBufferMarker() {
    if (has_buffer_marker_) {
        WriteMarker(MarkerPosition::kBottom, end_marker_value_);
    }
}

void CommandBuffer::WriteBeginCommandExecutionMarker(uint32_t command_id) {
    if (has_buffer_marker_) {
        WriteMarker(MarkerPosition::kTop, begin_marker_value_ + command_id);
    }
}

void CommandBuffer::WriteEndCommandExecutionMarker(uint32_t command_id) {
    if (has_buffer_marker_) {
        WriteMarker(MarkerPosition::kBottom, begin_marker_value_ + command_id);
    }
}

bool CommandBuffer::WasSubmittedToQueue() const { return buffer_state_ == CommandBufferState::kPending; }

bool CommandBuffer::StartedExecution() const { return (ReadMarker(MarkerPosition::kTop) >= begin_marker_value_); }

bool CommandBuffer::CompletedExecution() const { return (ReadMarker(MarkerPosition::kBottom) == end_marker_value_); }

void CommandBuffer::Reset() {
    buffer_state_ = CommandBufferState::kInitialReset;

    // Reset marker state.
    if (has_buffer_marker_) {
        *(uint32_t*)(top_marker_.cpu_mapped_address) = 0;
        *(uint32_t*)(bottom_marker_.cpu_mapped_address) = 0;
    }

    // Clear inheritance info
    if (scb_inheritance_info_) {
        delete scb_inheritance_info_;
        scb_inheritance_info_ = nullptr;
    }

    // Clear commands and internal state.
    tracker_.Reset();
    submitted_queue_ = VK_NULL_HANDLE;
    submitted_fence_ = VK_NULL_HANDLE;
}

void CommandBuffer::QueueSubmit(VkQueue queue, VkFence fence) {
    buffer_state_ = CommandBufferState::kPending;
    submitted_queue_ = queue;
    submitted_fence_ = fence;
}

// Custom command buffer functions (not autogenerated).
VkResult CommandBuffer::PreBeginCommandBuffer(VkCommandBuffer commandBuffer,
                                              const VkCommandBufferBeginInfo* pBeginInfo) {
    // Reset state on Begin.
    Reset();
    tracker_.TrackPreBeginCommandBuffer(commandBuffer, pBeginInfo);
    return VK_SUCCESS;
}

VkResult CommandBuffer::PostBeginCommandBuffer(VkCommandBuffer commandBuffer,
                                               const VkCommandBufferBeginInfo* pBeginInfo, VkResult result) {
    // Begin recording commands.
    buffer_state_ = CommandBufferState::kRecording;

    if (pBeginInfo->flags & VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT) {
        cb_simultaneous_use_ = true;
    }

    if (cb_level_ == VK_COMMAND_BUFFER_LEVEL_SECONDARY && pBeginInfo->pInheritanceInfo) {
        if (!scb_inheritance_info_) {
            scb_inheritance_info_ = crash_diagnostic_layer::New<VkCommandBufferInheritanceInfo>();
        }
        *scb_inheritance_info_ = *pBeginInfo->pInheritanceInfo;
    }

    // All our markers go in post for begin because they must be recorded after
    // the driver starts recording
    if (has_buffer_marker_) {
        WriteBeginCommandBufferMarker();
    }

    return result;
}

VkResult CommandBuffer::PreEndCommandBuffer(VkCommandBuffer commandBuffer) {
    tracker_.TrackPreEndCommandBuffer(commandBuffer);

    if (has_buffer_marker_) {
        WriteEndCommandBufferMarker();
    }
    return VK_SUCCESS;
}

VkResult CommandBuffer::PostEndCommandBuffer(VkCommandBuffer commandBuffer, VkResult result) {

    buffer_state_ = CommandBufferState::kExecutable;

    return result;
}

VkResult CommandBuffer::PreResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) {
    Reset();
    return VK_SUCCESS;
}

VkResult CommandBuffer::PostResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags,
                                               VkResult result) {
    return result;
}

uint32_t CommandBuffer::GetLastStartedCommand() const {
    auto marker = ReadMarker(MarkerPosition::kTop);
    return marker - begin_marker_value_;
}

uint32_t CommandBuffer::GetLastCompleteCommand() const {
    auto marker = ReadMarker(MarkerPosition::kBottom);
    if (marker == end_marker_value_) {
        return tracker_.GetCommands().back().id;
    }
    return marker - begin_marker_value_;
}

CommandBufferState CommandBuffer::GetCommandBufferState() const {
    if (!has_buffer_marker_ || (IsPrimaryCommandBuffer() && !WasSubmittedToQueue())) {
        return buffer_state_;
    }
    // If the command buffer is submitted and markers can be used, determine the
    // execution state of the command buffer.
    if (!StartedExecution()) {
        return CommandBufferState::kSubmittedExecutionNotStarted;
    }
    if (!CompletedExecution()) {
        return CommandBufferState::kSubmittedExecutionIncomplete;
    }
    return CommandBufferState::kSubmittedExecutionCompleted;
}

CommandBufferState CommandBuffer::GetSecondaryCommandBufferState(
    CommandState vkcmd_execute_commands_command_state) const {
    assert(vkcmd_execute_commands_command_state != CommandState::kInvalidState);
    if (vkcmd_execute_commands_command_state == CommandState::kCommandNotSubmitted) {
        return CommandBufferState::kNotSubmitted;
    }
    if (vkcmd_execute_commands_command_state == CommandState::kCommandNotStarted) {
        return CommandBufferState::kSubmittedExecutionNotStarted;
    }
    if (vkcmd_execute_commands_command_state == CommandState::kCommandCompleted) {
        return CommandBufferState::kSubmittedExecutionCompleted;
    }
    return GetCommandBufferState();
}

std::string CommandBuffer::PrintCommandBufferState(CommandBufferState cb_state) const {
    switch (cb_state) {
        case CommandBufferState::kInitial:
            return "CREATED";
        case CommandBufferState::kRecording:
            return "BEGIN_CALLED";
        case CommandBufferState::kExecutable:
            return "END_CALLED";
        case CommandBufferState::kPending:
            return "SUBMITTED_NO_MORE_INFO";
        case CommandBufferState::kInvalid:
            return "INVALID";
        case CommandBufferState::kInitialReset:
            return "RESET";
        case CommandBufferState::kSubmittedExecutionNotStarted:
            return "SUBMITTED_EXECUTION_NOT_STARTED";
        case CommandBufferState::kSubmittedExecutionIncomplete:
            return "SUBMITTED_EXECUTION_INCOMPLETE";
        case CommandBufferState::kSubmittedExecutionCompleted:
            return "SUBMITTED_EXECUTION_COMPLETE";
        case CommandBufferState::kNotSubmitted:
            return "NOT_SUBMITTED";
        default:
            assert(true);
            return "UNKNOWN";
    }
}

CommandState CommandBuffer::GetCommandState(CommandBufferState cb_state, const Command& command) const {
    if (IsPrimaryCommandBuffer() && !WasSubmittedToQueue()) {
        return CommandState::kCommandNotSubmitted;
    }
    if (!has_buffer_marker_) {
        return CommandState::kCommandPending;
    }
    if (!IsPrimaryCommandBuffer()) {
        if (cb_state == CommandBufferState::kNotSubmitted) {
            return CommandState::kCommandNotSubmitted;
        }
        if (cb_state == CommandBufferState::kSubmittedExecutionNotStarted) {
            return CommandState::kCommandNotStarted;
        }
        if (cb_state == CommandBufferState::kSubmittedExecutionCompleted) {
            return CommandState::kCommandCompleted;
        }
        assert(cb_state == CommandBufferState::kSubmittedExecutionIncomplete);
    }
    if (command.id > GetLastStartedCommand()) {
        return CommandState::kCommandNotStarted;
    }
    if (command.id <= GetLastCompleteCommand()) {
        return CommandState::kCommandCompleted;
    }
    return CommandState::kCommandIncomplete;
}

std::string CommandBuffer::PrintCommandState(CommandState cm_state) const {
    switch (cm_state) {
        case CommandState::kCommandNotSubmitted:
            return "NOT_SUBMITTED";
        case CommandState::kCommandPending:
            return "SUBMITTED_NO_MORE_INFO";
        case CommandState::kCommandNotStarted:
            return "SUBMITTED_EXECUTION_NOT_STARTED";
        case CommandState::kCommandIncomplete:
            return "SUBMITTED_EXECUTION_INCOMPLETE";
        case CommandState::kCommandCompleted:
            return "SUBMITTED_EXECUTION_COMPLETE";
        default:
            assert(true);
            return "UNKNOWN";
    }
}

bool CommandBuffer::DumpCommand(const Command& command, YAML::Emitter& os) {
    tracker_.SetNameResolver(&device_->GetObjectInfoDB());
    tracker_.PrintCommandParameters(os, command);
    // TODO: does this matter?
    return true;
}

bool CommandBuffer::DumpCmdExecuteCommands(const Command& command, CommandState command_state, YAML::Emitter& os,
                                           CommandBufferDumpOptions options) {
    auto args = reinterpret_cast<CmdExecuteCommandsArgs*>(command.parameters);
    os << YAML::BeginMap;
    os << YAML::Key << "commandBufferCount" << YAML::Value << args->commandBufferCount;
    os << YAML::Key << "pCommandBuffers" << YAML::Value << YAML::BeginSeq;
    if (args->pCommandBuffers && args->commandBufferCount > 0) {
        for (uint32_t i = 0; i < args->commandBufferCount; i++) {
            auto secondary_command_buffer = crash_diagnostic_layer::GetCommandBuffer(args->pCommandBuffers[i]);
            if (secondary_command_buffer) {
                secondary_command_buffer->DumpContents(os, options, submit_info_id_, command_state);
            }
        }
    }
    os << YAML::EndSeq << YAML::EndMap;
    return true;
}

// Mutable internal command buffer state used to determine what the
// state should be at a given command
class CommandBufferInternalState {
   public:
    CommandBufferInternalState(Device* device) : device_(device) {}

    // Mutate the internal state by the command.
    void Mutate(const Command& cmd);

    // Print the relevant state for the command.
    bool Print(const Command& cmd, YAML::Emitter& os, const ObjectInfoDB& name_resolver);

    const Pipeline* GetPipeline(VkPipelineBindPoint bind_point) const { return bound_pipelines_[bind_point]; }

   private:
    static constexpr int kNumBindPoints = 2;  // graphics, compute

    Device* device_;
    std::array<const Pipeline*, kNumBindPoints> bound_pipelines_;
    std::array<ActiveDescriptorSets, kNumBindPoints> bound_descriptors_;
};

// Returns the pipeline used by this command or -1 if no pipeline used.
int GetCommandPipelineType(const Command& command) {
    switch (command.type) {
        case Command::Type::kCmdDraw:
        case Command::Type::kCmdDrawIndexed:
        case Command::Type::kCmdDrawIndirect:
        case Command::Type::kCmdDrawIndexedIndirect:
            return VK_PIPELINE_BIND_POINT_GRAPHICS;

        case Command::Type::kCmdDispatch:
        case Command::Type::kCmdDispatchIndirect:
            return VK_PIPELINE_BIND_POINT_COMPUTE;

        default:
            return -1;
    }
}

// Perform operations when a command is not completed.
// Currently used to dump shader SPIRV when a command is incomplete.
void CommandBuffer::HandleIncompleteCommand(const Command& command, const CommandBufferInternalState& state) const {
    // Should we write our shaders on crash?
    auto* context = device_->GetContext();
    if (!context->DumpShadersOnCrash()) {
        return;
    }

    // We only handle commands with pipelines.
    auto pipeline_type = GetCommandPipelineType(command);
    if (-1 == pipeline_type) {
        return;
    }

    auto pipeline = state.GetPipeline(static_cast<VkPipelineBindPoint>(pipeline_type));
    auto vk_pipeline = pipeline->GetVkPipeline();

    device_->DumpShaderFromPipeline(vk_pipeline);
}

void CommandBufferInternalState::Mutate(const Command& cmd) {
    if (cmd.type == Command::Type::kCmdBindDescriptorSets) {
        if (cmd.parameters) {
            // Update the active descriptorsets for this bind point.
            auto args = reinterpret_cast<CmdBindDescriptorSetsArgs*>(cmd.parameters);
            bound_descriptors_[args->pipelineBindPoint].Bind(args->firstSet, args->descriptorSetCount,
                                                             args->pDescriptorSets);
        }
    } else if (cmd.type == Command::Type::kCmdBindPipeline) {
        if (cmd.parameters) {
            // Update the currently bound pipeline.
            auto args = reinterpret_cast<CmdBindPipelineArgs*>(cmd.parameters);
            bound_pipelines_[args->pipelineBindPoint] = device_->FindPipeline(args->pipeline);
        }
    }
}

bool CommandBufferInternalState::Print(const Command& cmd, YAML::Emitter& os, const ObjectInfoDB& name_resolver) {
    int bind_point = -1;
    switch (cmd.type) {
        case Command::Type::kCmdDraw:
        case Command::Type::kCmdDrawIndexed:
        case Command::Type::kCmdDrawIndirect:
        case Command::Type::kCmdDrawIndexedIndirect:
            bind_point = VK_PIPELINE_BIND_POINT_GRAPHICS;
            break;

        case Command::Type::kCmdDispatch:
        case Command::Type::kCmdDispatchIndirect:
            bind_point = VK_PIPELINE_BIND_POINT_COMPUTE;
            break;

        default:
            break;
    }

    if (-1 != bind_point) {
        os << YAML::Key << "internalState" << YAML::Value << YAML::BeginMap;
        os << YAML::Key << "pipeline" << YAML::Value;
        bound_pipelines_[bind_point]->Print(os, name_resolver);
        os << YAML::Key << "descriptorSets" << YAML::Value;
        bound_descriptors_[bind_point].Print(device_, os);
        os << YAML::EndMap;
        return true;
    }

    return false;
}

void CommandBuffer::DumpContents(YAML::Emitter& os, CommandBufferDumpOptions options,
                                 uint64_t secondary_cb_submit_info_id,
                                 CommandState vkcmd_execute_commands_command_state) {
    if (vk_command_buffer_ == VK_NULL_HANDLE) {
        return;
    }
    auto num_commands = tracker_.GetCommands().size();
    os << YAML::BeginMap << YAML::Comment("CommandBuffer");
    os << YAML::Key << "status";
    CommandBufferState cb_state;
    if (IsPrimaryCommandBuffer()) {
        cb_state = GetCommandBufferState();
    } else {
        cb_state = GetSecondaryCommandBufferState(vkcmd_execute_commands_command_state);
    }
    os << YAML::Value << PrintCommandBufferState(cb_state);

    os << YAML::Key << "vkHandle" << YAML::Value << device_->GetObjectInfo((uint64_t)vk_command_buffer_);
    os << YAML::Key << "commandPool" << YAML::Value << device_->GetObjectInfo((uint64_t)vk_command_pool_);
    if (buffer_state_ == CommandBufferState::kPending) {
        os << YAML::Key << "queue" << device_->GetObjectInfo((uint64_t)submitted_queue_);
        os << YAML::Key << "fence" << device_->GetObjectInfo((uint64_t)submitted_fence_);
    }

    os << YAML::Key << "submitInfoId" << YAML::Value;
    if (IsPrimaryCommandBuffer()) {
        os << submit_info_id_;
    } else {
        os << secondary_cb_submit_info_id;
    }
    os << YAML::Key << "level" << YAML::Value;
    if (IsPrimaryCommandBuffer()) {
        os << "Primary";
    } else {
        os << "Secondary";
        os << YAML::Key << "stateInheritance" << YAML::Value << (scb_inheritance_info_ != nullptr);
    }
    os << YAML::Key << "simultaneousUse" << YAML::Value << cb_simultaneous_use_;

    bool dump_commands = (options & CommandBufferDumpOption::kDumpAllCommands);

    if (has_buffer_marker_) {
        os << YAML::Hex;
        os << YAML::Key << "beginMarkerValue" << YAML::Value << Uint32ToStr(begin_marker_value_);
        os << YAML::Key << "endMarkerValue" << YAML::Value << Uint32ToStr(end_marker_value_);
        os << YAML::Key << "topMarkerBuffer" << YAML::Value << Uint32ToStr(ReadMarker(MarkerPosition::kTop));
        os << YAML::Key << "bottomMarkerBuffer" << YAML::Value << Uint32ToStr(ReadMarker(MarkerPosition::kBottom));
        os << YAML::Dec;
    }
    if (cb_state == CommandBufferState::kSubmittedExecutionIncomplete) {
        os << YAML::Key << "lastStartedCommand" << YAML::Value << GetLastStartedCommand();
        os << YAML::Key << "lastCompletedCommand" << YAML::Value << GetLastCompleteCommand();
        dump_commands = true;
    }
    // Internal command buffer state that needs to be tracked.
    CommandBufferInternalState state(device_);

    if (dump_commands) {
        os << YAML::Key << "Commands" << YAML::Value << YAML::BeginSeq;
        for (const auto& command : tracker_.GetCommands()) {
            auto command_name = Command::GetCommandName(command);
            auto command_state = GetCommandState(cb_state, command);

            os << YAML::BeginMap << YAML::Comment("Command:");
            // os << YAML::Key << "id" << YAML::Value << command.id << "/" << num_commands;
            os << YAML::Key << "id" << YAML::Value << command.id;
            os << YAML::Key << "markerValue" << YAML::Value
               << crash_diagnostic_layer::Uint32ToStr(begin_marker_value_ + command.id);
            os << YAML::Key << "name" << YAML::Value << command_name;
            os << YAML::Key << "state" << YAML::Value << PrintCommandState(command_state);

            state.Mutate(command);
            // For vkCmdExecuteCommands, CDL prints all the information about the
            // recorded command buffers. For every other command, CDL prints the
            // arguments without going deep into printing objects themselves.
            os << YAML::Key << "parameters" << YAML::Value << YAML::BeginMap;
            if (strcmp(command_name, "vkCmdExecuteCommands") != 0) {
                DumpCommand(command, os);
            } else {
                DumpCmdExecuteCommands(command, command_state, os, options);
            }
            os << YAML::EndMap;
            state.Print(command, os, device_->GetObjectInfoDB());
            if (command_state == CommandState::kCommandIncomplete) {
                HandleIncompleteCommand(command, state);
            }

            // To make this message more visible, we put it in a special
            // Command entry.
            if (cb_state == CommandBufferState::kSubmittedExecutionIncomplete &&
                command.id == GetLastCompleteCommand()) {
                os << YAML::Key << "message" << YAML::Value << "'>>>>>>>>>>>>>> LAST COMPLETE COMMAND <<<<<<<<<<<<<<'";
            }
            os << YAML::EndMap;  // Command
        }
        os << YAML::EndSeq;
    }
    os << YAML::EndMap;  // CommandBuffer
}

// =============================================================================
// Include the generated command tracking code
// =============================================================================
#include "command.cc.inc"

}  // namespace crash_diagnostic_layer
