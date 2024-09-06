/*
 Copyright 2020 Google Inc.
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

#include "queue.h"

#include <cstring>
#include <iomanip>
#include <sstream>

#include "cdl.h"
#include "device.h"
#include "util.h"

#include <vulkan/utility/vk_struct_helper.hpp>
#include <yaml-cpp/emitter.h>

namespace crash_diagnostic_layer {

Queue::Queue(Device& device, VkQueue queue, uint32_t family_index, uint32_t index, const VkQueueFamilyProperties& props)
    : device_(device),
      vk_queue_(queue),
      queue_family_index_(family_index),
      queue_index_(index),
      queue_family_properties_(props),
      trace_all_semaphores_(device_.GetContext().GetSettings().trace_all_semaphores) {
    auto type_ci = vku::InitStruct<VkSemaphoreTypeCreateInfo>();
    type_ci.semaphoreType = VK_SEMAPHORE_TYPE_TIMELINE;
    type_ci.initialValue = submit_seq_;
    auto sem_ci = vku::InitStruct<VkSemaphoreCreateInfo>(&type_ci);

    VkResult result = device_.Dispatch().CreateSemaphore(device_.GetVkDevice(), &sem_ci, nullptr, &submit_sem_);
    if (result != VK_SUCCESS) {
        Log().Warning("failed to create semaphore for state tracking. Result: %d, VkQueue: %s, queueFamilyIndex: %d",
                      result, device_.GetObjectInfo((uint64_t)vk_queue_).c_str(), queue_family_index_);
    }
}

void Queue::Destroy() {
    if (submit_sem_ != VK_NULL_HANDLE) {
        device_.Dispatch().QueueWaitIdle(GetVkQueue());
        device_.Dispatch().DestroySemaphore(device_.GetVkDevice(), submit_sem_, nullptr);
        submit_sem_ = VK_NULL_HANDLE;
    }
}

Queue::~Queue() { Destroy(); }

const Logger& Queue::Log() const { return device_.Log(); }

Queue::SubmitInfo::SubmitInfo(Device& device, const VkSubmitInfo& submit_info, uint64_t seq_)
    : type(kQueueSubmit), start_seq(seq_) {
    for (uint32_t i = 0; i < submit_info.waitSemaphoreCount; i++) {
        wait_semaphores.push_back({submit_info.pWaitSemaphores[i], 1, submit_info.pWaitDstStageMask[i]});
    }
    for (uint32_t i = 0; i < submit_info.commandBufferCount; i++) {
        command_buffers.push_back(submit_info.pCommandBuffers[i]);
    }
    for (uint32_t i = 0; i < submit_info.signalSemaphoreCount; i++) {
        signal_semaphores.push_back({submit_info.pSignalSemaphores[i], 1, 0});
    }

    // Store type and initial value of the timeline semaphores.
    const auto* timeline_semaphore_info = vku::FindStructInPNextChain<VkTimelineSemaphoreSubmitInfoKHR>(&submit_info);
    auto semaphore_tracker = device.GetSemaphoreTracker();
    if (timeline_semaphore_info && semaphore_tracker) {
        for (uint32_t i = 0; i < timeline_semaphore_info->waitSemaphoreValueCount; i++) {
            if (semaphore_tracker->GetSemaphoreType(submit_info.pWaitSemaphores[i]) == VK_SEMAPHORE_TYPE_TIMELINE_KHR) {
                wait_semaphores[i].value = timeline_semaphore_info->pWaitSemaphoreValues[i];
            }
        }
        for (uint32_t i = 0; i < timeline_semaphore_info->signalSemaphoreValueCount; i++) {
            if (semaphore_tracker->GetSemaphoreType(submit_info.pSignalSemaphores[i]) ==
                VK_SEMAPHORE_TYPE_TIMELINE_KHR) {
                signal_semaphores[i].value = timeline_semaphore_info->pSignalSemaphoreValues[i];
            }
        }
    }
}

Queue::SubmitInfo::SubmitInfo(Device& device, const VkSubmitInfo2& submit_info, uint64_t seq_)
    : type(kQueueSubmit2), start_seq(seq_) {
    auto semaphore_tracker = device.GetSemaphoreTracker();

    for (uint32_t i = 0; i < submit_info.waitSemaphoreInfoCount; i++) {
        const auto& sem_info = submit_info.pWaitSemaphoreInfos[i];
        bool is_timeline = (semaphore_tracker && semaphore_tracker->GetSemaphoreType(sem_info.semaphore)) ==
                           VK_SEMAPHORE_TYPE_TIMELINE_KHR;
        wait_semaphores.push_back({sem_info.semaphore, is_timeline ? sem_info.value : 1, sem_info.stageMask});
    }
    for (uint32_t i = 0; i < submit_info.commandBufferInfoCount; i++) {
        command_buffers.push_back(submit_info.pCommandBufferInfos[i].commandBuffer);
    }
    for (uint32_t i = 0; i < submit_info.signalSemaphoreInfoCount; i++) {
        const auto& sem_info = submit_info.pSignalSemaphoreInfos[i];
        bool is_timeline = (semaphore_tracker && semaphore_tracker->GetSemaphoreType(sem_info.semaphore)) ==
                           VK_SEMAPHORE_TYPE_TIMELINE_KHR;
        signal_semaphores.push_back({sem_info.semaphore, is_timeline ? sem_info.value : 1, sem_info.stageMask});
    }
}

Queue::SubmitInfo::SubmitInfo(Device& device, const VkBindSparseInfo& sparse_info, uint64_t seq_)
    : type(kQueueBindSparse), start_seq(seq_) {
    for (uint32_t i = 0; i < sparse_info.waitSemaphoreCount; i++) {
        wait_semaphores.push_back({sparse_info.pWaitSemaphores[i], 1, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT});
    }
    // TODO should we save any of the sparse binding info?
    for (uint32_t i = 0; i < sparse_info.signalSemaphoreCount; i++) {
        signal_semaphores.push_back({sparse_info.pSignalSemaphores[i], 1, 0});
    }

    // Store type and initial value of the timeline semaphores.
    const auto* timeline_semaphore_info = vku::FindStructInPNextChain<VkTimelineSemaphoreSubmitInfoKHR>(&sparse_info);
    auto semaphore_tracker = device.GetSemaphoreTracker();
    if (timeline_semaphore_info && semaphore_tracker) {
        for (uint32_t i = 0; i < timeline_semaphore_info->waitSemaphoreValueCount; i++) {
            if (semaphore_tracker &&
                semaphore_tracker->GetSemaphoreType(sparse_info.pWaitSemaphores[i]) == VK_SEMAPHORE_TYPE_TIMELINE_KHR) {
                wait_semaphores[i].value = timeline_semaphore_info->pWaitSemaphoreValues[i];
            }
        }
        for (uint32_t i = 0; i < timeline_semaphore_info->signalSemaphoreValueCount; i++) {
            if (semaphore_tracker && semaphore_tracker->GetSemaphoreType(sparse_info.pSignalSemaphores[i]) ==
                                         VK_SEMAPHORE_TYPE_TIMELINE_KHR) {
                signal_semaphores[i].value = timeline_semaphore_info->pSignalSemaphoreValues[i];
            }
        }
    }
}

bool Queue::UpdateSeq() {
    uint64_t value = 0;
    VkResult result;
    if (device_.Dispatch().GetSemaphoreCounterValue) {
        result = device_.Dispatch().GetSemaphoreCounterValue(device_.GetVkDevice(), submit_sem_, &value);
    } else {
        result = device_.Dispatch().GetSemaphoreCounterValueKHR(device_.GetVkDevice(), submit_sem_, &value);
    }
    if (result != VK_SUCCESS) {
        Log().Warning("Failed to read submit semaphore. Result: %d, VkQueue: %s, VkSemaphore: %s", result,
                      device_.GetObjectInfo((uint64_t)vk_queue_).c_str(),
                      device_.GetObjectInfo((uint64_t)submit_sem_).c_str());
        return false;
    }
    if (value > submit_seq_) {
        Log().Info("Completed sequence number has impossible value: %lld submitted: %lld VkQueue: %s, VkSemaphore: %s",
                   value, submit_seq_.load(), device_.GetObjectInfo((uint64_t)vk_queue_).c_str(),
                   device_.GetObjectInfo((uint64_t)submit_sem_).c_str());
        return false;
    }
    assert(value >= complete_seq_);
    complete_seq_ = value;
    return true;
}

bool Queue::UpdateIdleState() {
    bool result = UpdateSeq();

    uint64_t completed_seq = CompletedSeq();

    Log().Verbose("%s completed: %lld submitted: %lld", device_.GetObjectInfo((uint64_t)vk_queue_).c_str(),
                  completed_seq, submit_seq_.load());
    std::lock_guard<std::mutex> qlock(queue_submits_mutex_);
    while (!queue_submits_.empty()) {
        auto& submission = queue_submits_.front();
        if (completed_seq < submission.start_seq) {
            break;
        }
        for (auto& submit_info : submission.submit_infos) {
            if (completed_seq >= submit_info.end_seq) {
                Log().Verbose("%s info start: %lld end: %lld FINISH",
                              device_.GetObjectInfo((uint64_t)vk_queue_).c_str(), submit_info.start_seq,
                              submit_info.end_seq);
                submit_info.state = kFinished;
                for (auto& cb : submit_info.command_buffers) {
                    auto cmd = crash_diagnostic_layer::GetCommandBuffer(cb);
                    if (cmd) {
                        cmd->SetCompleted();
                    }
                }
            } else if ((completed_seq + 1) >= submit_info.start_seq) {
                Log().Verbose("%s info start: %lld end: %lld RUNNING",
                              device_.GetObjectInfo((uint64_t)vk_queue_).c_str(), submit_info.start_seq,
                              submit_info.end_seq);
                submit_info.state = kRunning;
                bool found_running_cb = false;
                for (auto pos = submit_info.command_buffers.rbegin(); pos != submit_info.command_buffers.rend();
                     ++pos) {
                    auto cmd = crash_diagnostic_layer::GetCommandBuffer(*pos);
                    if (cmd) {
                        if (found_running_cb) {
                            cmd->SetCompleted();
                        } else if (cmd->GetCommandBufferState() == CommandBufferState::kSubmittedExecutionIncomplete) {
                            found_running_cb = true;
                        }
                    }
                }
                break;
            } else {
                Log().Verbose("%s info start: %lld end: %lld queued",
                              device_.GetObjectInfo((uint64_t)vk_queue_).c_str(), submit_info.start_seq,
                              submit_info.end_seq);
                break;
            }
        }

        if (completed_seq >= submission.end_seq) {
            queue_submits_.pop_front();
        } else {
            submission.state = kRunning;
            break;
        }
    }
    return result;
}

bool Queue::QueuedSubmitWaitingOnSemaphores(const SubmitInfo& submit_info) const {
    uint64_t semaphore_value = 0;
    bool current_value_available = false;
    auto semaphore_tracker = device_.GetSemaphoreTracker();
    if (!semaphore_tracker) {
        return false;
    }
    for (uint32_t i = 0; i < submit_info.wait_semaphores.size(); i++) {
        current_value_available =
            semaphore_tracker->GetSemaphoreValue(submit_info.wait_semaphores[i].handle, semaphore_value);
        if (current_value_available && submit_info.wait_semaphores[i].value > semaphore_value) return true;
    }
    return false;
}

std::vector<TrackedSemaphoreInfo> Queue::GetTrackedSemaphoreInfos(const SubmitInfo& submit_info,
                                                                  SemaphoreOperation operation) const {
    auto semaphore_tracker = device_.GetSemaphoreTracker();
    if (!semaphore_tracker) {
        return std::vector<TrackedSemaphoreInfo>();
    }
    if (operation == SemaphoreOperation::kWaitOperation) {
        return semaphore_tracker->GetTrackedSemaphoreInfos(submit_info.wait_semaphores);
    }
    return semaphore_tracker->GetTrackedSemaphoreInfos(submit_info.signal_semaphores);
}

bool Queue::SubmitInfoHasSemaphores(const SubmitInfo& submit_info) const {
    return (submit_info.wait_semaphores.size() > 0 || submit_info.signal_semaphores.size() > 0);
}

std::string Queue::GetSubmitInfoSemaphoresLog(const SubmitInfo& submit_info) const {
    std::stringstream log;
    switch (submit_info.type) {
        case kQueueSubmit:
            log << "VkSubmitInfo";
            break;
        case kQueueBindSparse:
            log << "VkBindSparseInfo";
            break;
        case kQueueSubmit2:
            log << "VkSubmitInfo2";
            break;
        default:
            log << "UNKNOWN";
            break;
    };
    log << " with semaphores submitted to queue." << std::endl
        << "\tVkDevice: " << device_.GetObjectName((uint64_t)device_.GetVkDevice())
        << ", VkQueue: " << device_.GetObjectName((uint64_t)vk_queue_) << ", SeqNum: " << submit_info.start_seq << " - "
        << submit_info.end_seq << std::endl;
    const char* tab = "\t";
    auto wait_semaphores = GetTrackedSemaphoreInfos(submit_info, kWaitOperation);
    if (wait_semaphores.size() > 0) {
        log << tab << "*** Wait Semaphores ***" << std::endl;
        log << device_.GetSemaphoreTracker()->PrintTrackedSemaphoreInfos(wait_semaphores, tab);
    }
    auto signal_semaphores = GetTrackedSemaphoreInfos(submit_info, kSignalOperation);
    if (signal_semaphores.size() > 0) {
        log << tab << "*** Signal Semaphores ***" << std::endl;
        log << device_.GetSemaphoreTracker()->PrintTrackedSemaphoreInfos(signal_semaphores, tab);
    }
    return log.str();
}

void Queue::Print(YAML::Emitter& os) {
    os << YAML::BeginMap << YAML::Comment("Queue");
    os << YAML::Key << "handle" << YAML::Value << device_.GetObjectInfo((uint64_t)vk_queue_);
    os << YAML::Key << "queueFamilyIndex" << YAML::Value << queue_family_index_;
    os << YAML::Key << "index" << YAML::Value << queue_index_;
    os << YAML::Key << "flags" << YAML::Value << YAML::BeginSeq;
    if (queue_family_properties_.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
        os << "graphics";
    }
    if (queue_family_properties_.queueFlags & VK_QUEUE_COMPUTE_BIT) {
        os << "compute";
    }
    if (queue_family_properties_.queueFlags & VK_QUEUE_TRANSFER_BIT) {
        os << "transfer";
    }
    if (queue_family_properties_.queueFlags & VK_QUEUE_SPARSE_BINDING_BIT) {
        os << "sparse";
    }
    if (queue_family_properties_.queueFlags & VK_QUEUE_PROTECTED_BIT) {
        os << "protected";
    }
    if (queue_family_properties_.queueFlags & VK_QUEUE_VIDEO_DECODE_BIT_KHR) {
        os << "video decode";
    }
    if (queue_family_properties_.queueFlags & VK_QUEUE_VIDEO_ENCODE_BIT_KHR) {
        os << "video encode";
    }
    if (queue_family_properties_.queueFlags & VK_QUEUE_OPTICAL_FLOW_BIT_NV) {
        os << "optical flow";
    }
    os << YAML::EndSeq;
    os << YAML::Key << "completedSeq" << YAML::Value << CompletedSeq();
    os << YAML::Key << "submittedSeq" << YAML::Value << SubmittedSeq();

    std::lock_guard<std::mutex> qlock(queue_submits_mutex_);
    if (queue_submits_.size() == 0) {
        os << YAML::EndMap;
        return;
    }
    auto dump_submits = device_.GetContext().GetSettings().dump_queue_submits;
    os << YAML::Key << "IncompleteSubmits" << YAML::Value << YAML::BeginSeq;
    for (const auto& submission : queue_submits_) {
        if (dump_submits == DumpCommands::kRunning) {
            if (submission.state != SubmitState::kRunning) {
                continue;
            }
        } else if (dump_submits == DumpCommands::kPending) {
            if (submission.state == SubmitState::kFinished) {
                continue;
            }
        }

        os << YAML::BeginMap;
        os << YAML::Key << "type";
        switch (submission.type) {
            case kQueueSubmit:
                os << YAML::Value << "vkQueueSubmit";
                break;
            case kQueueBindSparse:
                os << YAML::Value << "vkQueueBindSparse";
                break;
            case kQueueSubmit2:
                os << YAML::Value << "vkQueueSubmit2";
                break;
        }

        os << YAML::Key << "startSeq" << YAML::Value << submission.start_seq;
        os << YAML::Key << "endSeq" << YAML::Value << submission.end_seq;
        os << YAML::Key << "SubmitInfos" << YAML::Value << YAML::BeginSeq;
        for (const auto& submit_info : submission.submit_infos) {
            // Check submit state
            if (dump_submits == DumpCommands::kRunning) {
                if (submit_info.state != SubmitState::kRunning) {
                    continue;
                }
            } else if (dump_submits == DumpCommands::kPending) {
                if (submit_info.state == SubmitState::kFinished) {
                    continue;
                }
            }

            os << YAML::BeginMap;
            os << YAML::Key << "startSeq" << YAML::Value << submit_info.start_seq;
            os << YAML::Key << "endSeq" << YAML::Value << submit_info.end_seq;
            os << YAML::Key << "state";

            if (QueuedSubmitWaitingOnSemaphores(submit_info)) {
                os << YAML::Value << "WAITING_ON_SEMAPHORES";
            } else if (submit_info.state == SubmitState::kQueued) {
                os << YAML::Value << "NOT_STARTED";
            } else if (submit_info.state == SubmitState::kRunning) {
                os << YAML::Value << "INCOMPLETE";
            }

            if (submit_info.command_buffers.size() > 0) {
                os << YAML::Key << "CommandBuffers" << YAML::Value << YAML::BeginSeq;
                for (const auto& cb : submit_info.command_buffers) {
                    std::stringstream value;
                    value << device_.GetObjectInfo((uint64_t)cb);
                    auto cmd = crash_diagnostic_layer::GetCommandBuffer(cb);
                    if (cmd) {
                        value << " " << cmd->PrintCommandBufferState() << " " << cmd->GetQueueSeq();
                    }
                    os << value.str();
                }
                os << YAML::EndSeq;
            }
            auto wait_semaphores = GetTrackedSemaphoreInfos(submit_info, kWaitOperation);
            if (wait_semaphores.size() > 0) {
                os << YAML::Key << "WaitSemaphores" << YAML::Value << YAML::BeginSeq;
                for (const auto& wait : wait_semaphores) {
                    os << YAML::BeginMap;
                    os << YAML::Key << "handle" << YAML::Value << device_.GetObjectInfo((uint64_t)wait.semaphore);
                    os << YAML::Key << "type" << YAML::Value;
                    if (wait.semaphore_type == VK_SEMAPHORE_TYPE_BINARY_KHR) {
                        os << "Binary";
                    } else {
                        os << "Timeline";
                        os << YAML::Key << "value" << YAML::Value << wait.semaphore_operation_value;
                        if (wait.current_value_available) {
                            os << YAML::Key << "lastValue" << YAML::Value << wait.current_value;
                        }
                    }
                    os << YAML::EndMap;
                    assert(os.good());
                }
                os << YAML::EndSeq;
                assert(os.good());
            }
            auto signal_semaphores = GetTrackedSemaphoreInfos(submit_info, kSignalOperation);
            if (signal_semaphores.size() > 0) {
                os << YAML::Key << "SignalSemaphores" << YAML::Value << YAML::BeginSeq;
                for (auto signal : signal_semaphores) {
                    os << YAML::BeginMap;
                    os << YAML::Key << "handle" << YAML::Value << device_.GetObjectInfo((uint64_t)signal.semaphore);
                    os << YAML::Key << "type" << YAML::Value;
                    if (signal.semaphore_type == VK_SEMAPHORE_TYPE_BINARY_KHR) {
                        os << "Binary";
                    } else {
                        os << "Timeline";
                        os << YAML::Key << "value" << YAML::Value << signal.semaphore_operation_value;
                    }
                    os << YAML::EndMap;
                }
                os << YAML::EndSeq;
            }
            os << YAML::EndMap;
        }
        if (submission.fence) {
            os << YAML::Key << "Fence" << YAML::Value << device_.GetObjectInfo((uint64_t)submission.fence);
        }
        os << YAML::EndSeq << YAML::EndMap;
    }
    os << YAML::EndSeq;
    os << YAML::EndMap;
    assert(os.good());
}

void Queue::PostSubmit(VkResult result) {
    if (IsVkError(result)) {
        device_.DeviceFault();
    }
}

VkResult Queue::Submit(uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) {
    UpdateSeq();
    VkResult result = VK_SUCCESS;

    Submission submission(kQueueSubmit, ++submit_seq_);

    for (uint32_t i = 0; i < submitCount; i++) {
        SubmitInfo submit_info(device_, pSubmits[i], submit_seq_++);
        {
            auto timeline_values = vku::InitStruct<VkTimelineSemaphoreSubmitInfo>();
            timeline_values.signalSemaphoreValueCount = 1;
            timeline_values.pSignalSemaphoreValues = &submit_info.start_seq;
            auto submit = vku::InitStruct<VkSubmitInfo>(&timeline_values);
            submit.signalSemaphoreCount = 1;
            submit.pSignalSemaphores = &submit_sem_;
            if (result == VK_SUCCESS) {
                result = device_.Dispatch().QueueSubmit(vk_queue_, 1, &submit, VK_NULL_HANDLE);
            }
        }
        if (pSubmits[i].waitSemaphoreCount > 0) {
            auto submit = vku::InitStruct<VkSubmitInfo>();
            submit.pNext = pSubmits[i].pNext;
            submit.waitSemaphoreCount = pSubmits[i].waitSemaphoreCount;
            submit.pWaitSemaphores = pSubmits[i].pWaitSemaphores;
            submit.pWaitDstStageMask = pSubmits[i].pWaitDstStageMask;
            if (result == VK_SUCCESS) {
                result = device_.Dispatch().QueueSubmit(vk_queue_, 1, &submit, VK_NULL_HANDLE);
            }
        }
        for (auto& cb : submit_info.command_buffers) {
            uint64_t cb_seq = ++submit_seq_;
            auto command_buffer = GetCommandBuffer(cb);
            if (command_buffer) {
                command_buffer->QueueSubmit(vk_queue_, cb_seq, fence);
            }
            auto timeline_values = vku::InitStruct<VkTimelineSemaphoreSubmitInfo>();
            timeline_values.signalSemaphoreValueCount = 1;
            timeline_values.pSignalSemaphoreValues = &cb_seq;
            auto submit = vku::InitStruct<VkSubmitInfo>(&timeline_values);
            submit.commandBufferCount = 1;
            submit.pCommandBuffers = &cb;
            submit.signalSemaphoreCount = 1;
            submit.pSignalSemaphores = &submit_sem_;
            if (result == VK_SUCCESS) {
                result = device_.Dispatch().QueueSubmit(vk_queue_, 1, &submit, VK_NULL_HANDLE);
            }
        }
        if (pSubmits[i].signalSemaphoreCount > 0) {
            auto submit = vku::InitStruct<VkSubmitInfo>();
            submit.pNext = pSubmits[i].pNext;
            submit.signalSemaphoreCount = pSubmits[i].signalSemaphoreCount;
            submit.pSignalSemaphores = pSubmits[i].pSignalSemaphores;
            if (result == VK_SUCCESS) {
                result = device_.Dispatch().QueueSubmit(vk_queue_, 1, &submit, VK_NULL_HANDLE);
            }
        }

        submit_info.end_seq = ++submit_seq_;
        {
            auto timeline_values = vku::InitStruct<VkTimelineSemaphoreSubmitInfo>();
            timeline_values.signalSemaphoreValueCount = 1;
            timeline_values.pSignalSemaphoreValues = &submit_info.end_seq;
            auto submit = vku::InitStruct<VkSubmitInfo>(&timeline_values);
            submit.signalSemaphoreCount = 1;
            submit.pSignalSemaphores = &submit_sem_;
            if (result == VK_SUCCESS) {
                result = device_.Dispatch().QueueSubmit(vk_queue_, 1, &submit, VK_NULL_HANDLE);
            }
        }
        if (trace_all_semaphores_) {
            LogSubmitInfoSemaphores(submit_info);
        }
        submission.submit_infos.emplace_back(std::move(submit_info));
    }
    submission.end_seq = submit_seq_;  // don't increment so that this is the same as submit_infos.back().end_seq;
    Log().Verbose("%s submit: %lld to %lld", device_.GetObjectInfo((uint64_t)vk_queue_).c_str(), submission.start_seq,
                  submission.end_seq);
    {
        std::lock_guard<std::mutex> lock(queue_submits_mutex_);
        queue_submits_.emplace_back(std::move(submission));
    }
    if (fence && result == VK_SUCCESS) {
        result = device_.Dispatch().QueueSubmit(vk_queue_, 0, nullptr, fence);
    }
    PostSubmit(result);
    return result;
}

VkResult Queue::Submit2(uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) {
    auto QueueSubmit2 =
        device_.Dispatch().QueueSubmit2 ? device_.Dispatch().QueueSubmit2 : device_.Dispatch().QueueSubmit2KHR;
    UpdateSeq();
    VkResult result = VK_SUCCESS;

    Submission submission(kQueueSubmit2, ++submit_seq_);

    for (uint32_t i = 0; i < submitCount; i++) {
        SubmitInfo submit_info(device_, pSubmits[i], submit_seq_++);
        {
            auto signal_info = vku::InitStruct<VkSemaphoreSubmitInfo>();
            signal_info.semaphore = submit_sem_;
            signal_info.value = submit_info.start_seq;
            signal_info.stageMask = VK_PIPELINE_STAGE_2_BOTTOM_OF_PIPE_BIT;

            auto submit = vku::InitStruct<VkSubmitInfo2>();
            submit.signalSemaphoreInfoCount = 1;
            submit.pSignalSemaphoreInfos = &signal_info;
            if (result == VK_SUCCESS) {
                result = QueueSubmit2(vk_queue_, 1, &submit, VK_NULL_HANDLE);
            }
        }
        if (pSubmits[i].waitSemaphoreInfoCount > 0) {
            auto submit = vku::InitStruct<VkSubmitInfo2>();
            submit.waitSemaphoreInfoCount = pSubmits[i].waitSemaphoreInfoCount;
            submit.pWaitSemaphoreInfos = pSubmits[i].pWaitSemaphoreInfos;
            if (result == VK_SUCCESS) {
                result = QueueSubmit2(vk_queue_, 1, &submit, VK_NULL_HANDLE);
            }
        }
        for (auto& cb : submit_info.command_buffers) {
            uint64_t cb_seq = ++submit_seq_;
            auto command_buffer = GetCommandBuffer(cb);
            if (command_buffer) {
                command_buffer->QueueSubmit(vk_queue_, cb_seq, fence);
            }
            auto signal_info = vku::InitStruct<VkSemaphoreSubmitInfo>();
            signal_info.semaphore = submit_sem_;
            signal_info.value = cb_seq;
            signal_info.stageMask = VK_PIPELINE_STAGE_2_BOTTOM_OF_PIPE_BIT;

            auto cb_info = vku::InitStruct<VkCommandBufferSubmitInfo>();
            cb_info.commandBuffer = cb;

            auto submit = vku::InitStruct<VkSubmitInfo2>();
            submit.commandBufferInfoCount = 1;
            submit.pCommandBufferInfos = &cb_info;
            submit.signalSemaphoreInfoCount = 1;
            submit.pSignalSemaphoreInfos = &signal_info;
            if (result == VK_SUCCESS) {
                result = QueueSubmit2(vk_queue_, 1, &submit, VK_NULL_HANDLE);
            }
        }
        if (pSubmits[i].signalSemaphoreInfoCount > 0) {
            auto submit = vku::InitStruct<VkSubmitInfo2>();
            submit.signalSemaphoreInfoCount = pSubmits[i].signalSemaphoreInfoCount;
            submit.pSignalSemaphoreInfos = pSubmits[i].pSignalSemaphoreInfos;
            if (result == VK_SUCCESS) {
                result = QueueSubmit2(vk_queue_, 1, &submit, VK_NULL_HANDLE);
            }
        }

        submit_info.end_seq = ++submit_seq_;
        {
            auto signal_info = vku::InitStruct<VkSemaphoreSubmitInfo>();
            signal_info.semaphore = submit_sem_;
            signal_info.value = submit_info.end_seq;
            signal_info.stageMask = VK_PIPELINE_STAGE_2_BOTTOM_OF_PIPE_BIT;

            auto submit = vku::InitStruct<VkSubmitInfo2>();
            submit.signalSemaphoreInfoCount = 1;
            submit.pSignalSemaphoreInfos = &signal_info;
            result = QueueSubmit2(vk_queue_, 1, &submit, VK_NULL_HANDLE);
            if (result != VK_SUCCESS) {
                break;
            }
        }
        if (trace_all_semaphores_) {
            LogSubmitInfoSemaphores(submit_info);
        }
        submission.submit_infos.emplace_back(std::move(submit_info));
    }
    submission.end_seq = submit_seq_;  // don't increment so that this is the same as submit_infos.back().end_seq;
    Log().Verbose("%s submit2: %lld to %lld", device_.GetObjectInfo((uint64_t)vk_queue_).c_str(), submission.start_seq,
                  submission.end_seq);
    {
        std::lock_guard<std::mutex> lock(queue_submits_mutex_);
        queue_submits_.emplace_back(std::move(submission));
    }
    if (fence && result == VK_SUCCESS) {
        result = QueueSubmit2(vk_queue_, 0, nullptr, fence);
    }
    PostSubmit(result);
    return result;
}

VkResult Queue::BindSparse(uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfos, VkFence fence) {
    UpdateSeq();
    VkResult result = VK_SUCCESS;

    Submission submission(kQueueSubmit, ++submit_seq_);

    for (uint32_t i = 0; i < bindInfoCount; i++) {
        SubmitInfo submit_info(device_, pBindInfos[i], submit_seq_++);
        {
            auto timeline_values = vku::InitStruct<VkTimelineSemaphoreSubmitInfo>();
            timeline_values.signalSemaphoreValueCount = 1;
            timeline_values.pSignalSemaphoreValues = &submit_info.start_seq;
            auto submit = vku::InitStruct<VkSubmitInfo>(&timeline_values);
            submit.signalSemaphoreCount = 1;
            submit.pSignalSemaphores = &submit_sem_;
            if (result == VK_SUCCESS) {
                result = device_.Dispatch().QueueSubmit(vk_queue_, 1, &submit, VK_NULL_HANDLE);
            }
        }
        if (result == VK_SUCCESS) {
            result = device_.Dispatch().QueueBindSparse(vk_queue_, 1, &pBindInfos[i], VK_NULL_HANDLE);
        }
        submit_info.end_seq = ++submit_seq_;
        {
            auto timeline_values = vku::InitStruct<VkTimelineSemaphoreSubmitInfo>();
            timeline_values.signalSemaphoreValueCount = 1;
            timeline_values.pSignalSemaphoreValues = &submit_info.end_seq;
            auto submit = vku::InitStruct<VkSubmitInfo>(&timeline_values);
            submit.signalSemaphoreCount = 1;
            submit.pSignalSemaphores = &submit_sem_;
            if (result == VK_SUCCESS) {
                result = device_.Dispatch().QueueSubmit(vk_queue_, 1, &submit, VK_NULL_HANDLE);
            }
        }
        if (trace_all_semaphores_) {
            LogSubmitInfoSemaphores(submit_info);
        }
        submission.submit_infos.emplace_back(std::move(submit_info));
    }
    submission.end_seq = submit_seq_;  // don't increment so that this is the same as submit_infos.back().end_seq;
    Log().Verbose("%s bindsparse: %lld to %lld", device_.GetObjectInfo((uint64_t)vk_queue_).c_str(),
                  submission.start_seq, submission.end_seq);
    {
        std::lock_guard<std::mutex> lock(queue_submits_mutex_);
        queue_submits_.emplace_back(std::move(submission));
    }
    if (fence && result == VK_SUCCESS) {
        result = device_.Dispatch().QueueBindSparse(vk_queue_, 0, nullptr, fence);
    }
    PostSubmit(result);
    return result;
}

void Queue::LogSubmitInfoSemaphores(const SubmitInfo& submit_info) {
    assert(trace_all_semaphores_ == true);
    if (SubmitInfoHasSemaphores(submit_info)) {
        std::string semaphore_log = GetSubmitInfoSemaphoresLog(submit_info);
        Log().Info(semaphore_log);
    }
}

}  // namespace crash_diagnostic_layer
