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

CommandBuffer::CommandBuffer(Device& device, VkCommandPool vk_command_pool, VkCommandBuffer vk_command_buffer,
                             const VkCommandBufferAllocateInfo* allocate_info, bool has_checkpoints)
    : device_(device),
      vk_command_pool_(vk_command_pool),
      vk_command_buffer_(vk_command_buffer),
      cb_level_(allocate_info->level) {
    if (has_checkpoints) {
        begin_value_ = 1;
        end_value_ = 0x0000FFFF;

        checkpoint_ = device_.AllocateCheckpoint(begin_value_);

        if (!checkpoint_) {
            device_.Log().Warning("Cannot acquire checkpoint. Not tracking VkCommandBuffer %s",
                                  device_.GetObjectName((uint64_t)vk_command_buffer).c_str());
        }
    }
}

CommandBuffer::~CommandBuffer() {
    if (scb_inheritance_info_) {
        delete scb_inheritance_info_;
    }
    vk_command_pool_ = VK_NULL_HANDLE;
    vk_command_buffer_ = VK_NULL_HANDLE;
}

void CommandBuffer::WriteBeginCheckpoint() {
    // CDL log lables the commands inside a command buffer as follows:
    // - vkBeginCommandBuffer: 1
    // - n vkCmd commands recorded into command buffer: 2 ... n+1
    // - vkEndCommandBuffer: n+2
    if (checkpoint_) {
        checkpoint_->WriteTop(vk_command_buffer_, begin_value_ + 1);
    }
}

void CommandBuffer::WriteEndCheckpoint() {
    if (checkpoint_) {
        checkpoint_->WriteBottom(vk_command_buffer_, end_value_);
    }
}

void CommandBuffer::WriteCommandBeginCheckpoint(uint32_t command_id) {
    if (checkpoint_) {
        checkpoint_->WriteTop(vk_command_buffer_, begin_value_ + command_id);
    }
}

void CommandBuffer::WriteCommandEndCheckpoint(uint32_t command_id) {
    if (checkpoint_) {
        checkpoint_->WriteBottom(vk_command_buffer_, begin_value_ + command_id);
    }
}

bool CommandBuffer::WasSubmittedToQueue() const { return buffer_state_ == CommandBufferState::kPending; }

bool CommandBuffer::StartedExecution() const {
    if (!checkpoint_) {
        return false;
    }
    return (checkpoint_->ReadTop() > begin_value_);
}

bool CommandBuffer::CompletedExecution() const {
    if (!checkpoint_) {
        return false;
    }
    return (checkpoint_->ReadBottom() >= end_value_);
}

void CommandBuffer::Reset() {
    buffer_state_ = CommandBufferState::kInitialReset;

    // Reset marker state.
    if (checkpoint_) {
        checkpoint_->Reset();
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

void CommandBuffer::QueueSubmit(VkQueue queue, uint64_t queue_seq, VkFence fence) {
    buffer_state_ = CommandBufferState::kPending;
    submitted_queue_ = queue;
    submitted_queue_seq_ = queue_seq;
    submitted_fence_ = fence;
}

// Custom command buffer functions (not autogenerated).
VkResult CommandBuffer::PreBeginCommandBuffer(VkCommandBuffer commandBuffer,
                                              const VkCommandBufferBeginInfo* pBeginInfo) {
    // Reset state on Begin.
    Reset();
    tracker_.BeginCommandBuffer(commandBuffer, pBeginInfo);
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
    WriteBeginCheckpoint();

    return result;
}

VkResult CommandBuffer::PreEndCommandBuffer(VkCommandBuffer commandBuffer) {
    tracker_.EndCommandBuffer(commandBuffer);

    WriteEndCheckpoint();
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
    if (!checkpoint_) {
        return 0;
    }
    return checkpoint_->ReadTop() - begin_value_;
}

uint32_t CommandBuffer::GetLastCompleteCommand() const {
    if (!checkpoint_) {
        return 0;
    }
    uint32_t marker = checkpoint_->ReadBottom();
    if (marker == end_value_) {
        return tracker_.GetCommands().back().id;
    }
    return marker - begin_value_;
}

CommandBufferState CommandBuffer::GetCommandBufferState() const {
    if (!checkpoint_ || (IsPrimaryCommandBuffer() && !WasSubmittedToQueue())) {
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
            return "SUBMITTED";
        case CommandBufferState::kInvalid:
            return "INVALID";
        case CommandBufferState::kInitialReset:
            return "RESET";
        case CommandBufferState::kSubmittedExecutionNotStarted:
            return "NOT_STARTED";
        case CommandBufferState::kSubmittedExecutionIncomplete:
            return "INCOMPLETE";
        case CommandBufferState::kSubmittedExecutionCompleted:
            return "COMPLETED";
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
    if (!checkpoint_) {
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
            return "SUBMITTED";
        case CommandState::kCommandNotStarted:
            return "NOT_STARTED";
        case CommandState::kCommandIncomplete:
            return "INCOMPLETE";
        case CommandState::kCommandCompleted:
            return "COMPLETED";
        default:
            assert(true);
            return "UNKNOWN";
    }
}

bool CommandBuffer::DumpCommand(const Command& command, YAML::Emitter& os) {
    printer_.SetNameResolver(&device_.GetObjectInfoDB());
    printer_.PrintCommandParameters(os, command);
    // TODO: does this matter?
    return true;
}

bool CommandBuffer::DumpCmdExecuteCommands(const Command& command, CommandState command_state, YAML::Emitter& os,
                                           const Settings& settings) {
    auto args = reinterpret_cast<CmdExecuteCommandsArgs*>(command.parameters);
    os << YAML::BeginMap;
    os << YAML::Key << "commandBufferCount" << YAML::Value << args->commandBufferCount;
    os << YAML::Key << "pCommandBuffers" << YAML::Value << YAML::BeginSeq;
    if (args->pCommandBuffers && args->commandBufferCount > 0) {
        for (uint32_t i = 0; i < args->commandBufferCount; i++) {
            auto secondary_command_buffer = crash_diagnostic_layer::GetCommandBuffer(args->pCommandBuffers[i]);
            if (secondary_command_buffer) {
                secondary_command_buffer->DumpContents(os, settings, submitted_queue_seq_, command_state);
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
    CommandBufferInternalState(Device& device) : device_(device) {}

    // Mutate the internal state by the command.
    void Mutate(const Command& cmd);

    // Print the relevant state for the command.
    bool Print(const Command& cmd, YAML::Emitter& os, const ObjectInfoDB& name_resolver);

    const Pipeline* GetPipeline(VkPipelineBindPoint bind_point) const { return bound_pipelines_[bind_point]; }

   private:
    static constexpr int kNumBindPoints = 2;  // graphics, compute

    Device& device_;
    std::array<const Pipeline*, kNumBindPoints> bound_pipelines_{nullptr, nullptr};
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
    auto& context = device_.GetContext();
    if (context.GetSettings().dump_shaders != DumpShaders::kOnCrash) {
        return;
    }

    // We only handle commands with pipelines.
    auto pipeline_type = GetCommandPipelineType(command);
    if (-1 == pipeline_type) {
        return;
    }

    auto pipeline = state.GetPipeline(static_cast<VkPipelineBindPoint>(pipeline_type));
    auto vk_pipeline = pipeline->GetVkPipeline();

    device_.DumpShaderFromPipeline(vk_pipeline);
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
            bound_pipelines_[args->pipelineBindPoint] = device_.FindPipeline(args->pipeline);
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
        if (bound_pipelines_[bind_point]) {
            bound_pipelines_[bind_point]->Print(os, name_resolver);
        } else {
            os << YAML::BeginMap << YAML::EndMap;
        }

        os << YAML::Key << "descriptorSets" << YAML::Value;
        bound_descriptors_[bind_point].Print(device_, os);
        os << YAML::EndMap;
        return true;
    }

    return false;
}

void CommandBuffer::DumpContents(YAML::Emitter& os, const Settings& settings, uint64_t secondary_cb_queue_seq,
                                 CommandState vkcmd_execute_commands_command_state) {
    if (vk_command_buffer_ == VK_NULL_HANDLE) {
        return;
    }
    CommandBufferState cb_state;
    if (IsPrimaryCommandBuffer()) {
        cb_state = GetCommandBufferState();
    } else {
        cb_state = GetSecondaryCommandBufferState(vkcmd_execute_commands_command_state);
    }
    auto dump_cbs = settings.dump_command_buffers;
    switch (cb_state) {
        case CommandBufferState::kSubmittedExecutionIncomplete:
            break;
        case CommandBufferState::kSubmittedExecutionNotStarted:
            if (dump_cbs == DumpCommands::kRunning) {
                return;
            }
        default:
            if (dump_cbs != DumpCommands::kAll) {
                return;
            }
    }

    auto num_commands = tracker_.GetCommands().size();
    os << YAML::BeginMap << YAML::Comment("CommandBuffer");
    os << YAML::Key << "state";
    os << YAML::Value << PrintCommandBufferState(cb_state);

    os << YAML::Key << "handle" << YAML::Value << device_.GetObjectInfo((uint64_t)vk_command_buffer_);
    os << YAML::Key << "commandPool" << YAML::Value << device_.GetObjectInfo((uint64_t)vk_command_pool_);
    if (buffer_state_ == CommandBufferState::kPending) {
        os << YAML::Key << "queue" << device_.GetObjectInfo((uint64_t)submitted_queue_);
        os << YAML::Key << "fence" << device_.GetObjectInfo((uint64_t)submitted_fence_);
    }

    os << YAML::Key << "queueSeq" << YAML::Value;
    if (IsPrimaryCommandBuffer()) {
        os << submitted_queue_seq_;
    } else {
        os << secondary_cb_queue_seq;
    }
    os << YAML::Key << "level" << YAML::Value;
    if (IsPrimaryCommandBuffer()) {
        os << "Primary";
    } else {
        os << "Secondary";
        os << YAML::Key << "stateInheritance" << YAML::Value << (scb_inheritance_info_ != nullptr);
    }
    os << YAML::Key << "simultaneousUse" << YAML::Value << cb_simultaneous_use_;

    if (checkpoint_) {
        os << YAML::Hex;
        os << YAML::Key << "beginValue" << YAML::Value << Uint32ToStr(begin_value_);
        os << YAML::Key << "endValue" << YAML::Value << Uint32ToStr(end_value_);
        os << YAML::Key << "topCheckpointValue" << YAML::Value << Uint32ToStr(checkpoint_->ReadTop());
        os << YAML::Key << "bottomCheckpointValue" << YAML::Value << Uint32ToStr(checkpoint_->ReadBottom());
        os << YAML::Dec;
    }
    auto last_started = GetLastStartedCommand();
    auto last_completed = GetLastCompleteCommand();

    if (cb_state == CommandBufferState::kSubmittedExecutionIncomplete) {
        os << YAML::Key << "lastStartedCommand" << YAML::Value << GetLastStartedCommand();
        os << YAML::Key << "lastCompletedCommand" << YAML::Value << GetLastCompleteCommand();
    }
    // Internal command buffer state that needs to be tracked.
    CommandBufferInternalState state(device_);

    auto dump_cmds = settings.dump_commands;
    os << YAML::Key << "Commands" << YAML::Value << YAML::BeginSeq;
    for (const auto& command : tracker_.GetCommands()) {
        auto command_name = Command::GetCommandName(command);
        auto command_state = GetCommandState(cb_state, command);

        if (dump_cmds == DumpCommands::kRunning) {
            if (command.id < last_completed || command.id > last_started) {
                continue;
            }
        } else if (dump_cmds == DumpCommands::kPending) {
            if (command.id < last_completed) {
                continue;
            }
        }

        os << YAML::BeginMap << YAML::Comment("Command:");
        // os << YAML::Key << "id" << YAML::Value << command.id << "/" << num_commands;
        os << YAML::Key << "id" << YAML::Value << command.id;
        os << YAML::Key << "checkpointValue" << YAML::Value
           << crash_diagnostic_layer::Uint32ToStr(begin_value_ + command.id);
        os << YAML::Key << "name" << YAML::Value << command_name;
        os << YAML::Key << "state" << YAML::Value << PrintCommandState(command_state);
        if (!command.labels.empty()) {
            os << YAML::Key << "labels" << YAML::BeginSeq;
            for (const auto& label : command.labels) {
                os << label;
            }
            os << YAML::EndSeq;
        }

        state.Mutate(command);
        // For vkCmdExecuteCommands, CDL prints all the information about the
        // recorded command buffers. For every other command, CDL prints the
        // arguments without going deep into printing objects themselves.
        os << YAML::Key << "parameters" << YAML::Value << YAML::BeginMap;
        if (strcmp(command_name, "vkCmdExecuteCommands") != 0) {
            DumpCommand(command, os);
        } else {
            DumpCmdExecuteCommands(command, command_state, os, settings);
        }
        os << YAML::EndMap;
        state.Print(command, os, device_.GetObjectInfoDB());
        if (command_state == CommandState::kCommandIncomplete) {
            HandleIncompleteCommand(command, state);
        }

        // To make this message more visible, we put it in a special
        // Command entry.
        if (cb_state == CommandBufferState::kSubmittedExecutionIncomplete) {
            if (command.id == GetLastCompleteCommand()) {
                os << YAML::Key << "message" << YAML::Value << "'>>>>>>>>>>>>>> LAST COMPLETE COMMAND <<<<<<<<<<<<<<'";
            } else if (command.id == GetLastStartedCommand()) {
                os << YAML::Key << "message" << YAML::Value << "'^^^^^^^^^^^^^^ LAST STARTED COMMAND ^^^^^^^^^^^^^^'";
            }
        }
        assert(os.good());
        os << YAML::EndMap;  // Command
        assert(os.good());
    }
    assert(os.good());
    os << YAML::EndSeq;
    assert(os.good());
    os << YAML::EndMap;  // CommandBuffer
}

// =============================================================================
// Include the generated command tracking code
// =============================================================================
#include "command.cpp.inc"

}  // namespace crash_diagnostic_layer
