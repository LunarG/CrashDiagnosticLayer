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
      tracking_semaphores_(device_.GetContext().TrackingSemaphores()),
      trace_all_semaphores_(device_.GetContext().TracingAllSemaphores()) {
    if (tracking_semaphores_) {
        auto type_ci = vku::InitStruct<VkSemaphoreTypeCreateInfo>();
        type_ci.semaphoreType = VK_SEMAPHORE_TYPE_TIMELINE;
        type_ci.initialValue = submit_seq_;
        auto sem_ci = vku::InitStruct<VkSemaphoreCreateInfo>(&type_ci);

        VkResult result = device_.Dispatch().CreateSemaphore(device_.GetVkDevice(), &sem_ci, nullptr, &submit_sem_);
        if (result != VK_SUCCESS) {
            Log().Warning(
                "failed to create semaphore for state tracking. Result: %d, VkQueue: %s, queueFamilyIndex: %d", result,
                device_.GetObjectInfo((uint64_t)vk_queue_).c_str(), queue_family_index_);
        }
    }
}

void Queue::Destroy() {
    if (submit_sem_ != VK_NULL_HANDLE) {
        device_.Dispatch().DestroySemaphore(device_.GetVkDevice(), submit_sem_, nullptr);
        submit_sem_ = VK_NULL_HANDLE;
    }
}

Queue::~Queue() { Destroy(); }

const Logger& Queue::Log() const { return device_.Log(); }

Queue::SubmitInfo::SubmitInfo(Device& device, const VkSubmitInfo& submit_info, uint64_t seq_)
    : type(kQueueSubmit), seq(seq_) {
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
    if (timeline_semaphore_info) {
        auto semaphore_tracker = device.GetSemaphoreTracker();
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
    : type(kQueueSubmit2), seq(seq_) {
    auto semaphore_tracker = device.GetSemaphoreTracker();

    for (uint32_t i = 0; i < submit_info.waitSemaphoreInfoCount; i++) {
        const auto& sem_info = submit_info.pWaitSemaphoreInfos[i];
        bool is_timeline = semaphore_tracker->GetSemaphoreType(sem_info.semaphore) == VK_SEMAPHORE_TYPE_TIMELINE_KHR;
        wait_semaphores.push_back({sem_info.semaphore, is_timeline ? sem_info.value : 1, sem_info.stageMask});
    }
    for (uint32_t i = 0; i < submit_info.commandBufferInfoCount; i++) {
        command_buffers.push_back(submit_info.pCommandBufferInfos[i].commandBuffer);
    }
    for (uint32_t i = 0; i < submit_info.signalSemaphoreInfoCount; i++) {
        const auto& sem_info = submit_info.pSignalSemaphoreInfos[i];
        bool is_timeline = semaphore_tracker->GetSemaphoreType(sem_info.semaphore) == VK_SEMAPHORE_TYPE_TIMELINE_KHR;
        signal_semaphores.push_back({sem_info.semaphore, is_timeline ? sem_info.value : 1, sem_info.stageMask});
    }
}

Queue::SubmitInfo::SubmitInfo(Device& device, const VkBindSparseInfo& sparse_info, uint64_t seq_)
    : type(kQueueBindSparse), seq(seq_) {
    for (uint32_t i = 0; i < sparse_info.waitSemaphoreCount; i++) {
        wait_semaphores.push_back({sparse_info.pWaitSemaphores[i], 1, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT});
    }
    // TODO should we save any of the sparse binding info?
    for (uint32_t i = 0; i < sparse_info.signalSemaphoreCount; i++) {
        signal_semaphores.push_back({sparse_info.pSignalSemaphores[i], 1, 0});
    }

    // Store type and initial value of the timeline semaphores.
    const auto* timeline_semaphore_info = vku::FindStructInPNextChain<VkTimelineSemaphoreSubmitInfoKHR>(&sparse_info);
    if (timeline_semaphore_info) {
        auto semaphore_tracker = device.GetSemaphoreTracker();
        for (uint32_t i = 0; i < timeline_semaphore_info->waitSemaphoreValueCount; i++) {
            if (semaphore_tracker->GetSemaphoreType(sparse_info.pWaitSemaphores[i]) == VK_SEMAPHORE_TYPE_TIMELINE_KHR) {
                wait_semaphores[i].value = timeline_semaphore_info->pWaitSemaphoreValues[i];
            }
        }
        for (uint32_t i = 0; i < timeline_semaphore_info->signalSemaphoreValueCount; i++) {
            if (semaphore_tracker->GetSemaphoreType(sparse_info.pSignalSemaphores[i]) ==
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
        Log().Warning(
            "Completed sequence number has impossible value: %lld submitted: %lld VkQueue: %s, VkSemaphore: %s", value,
            submit_seq_.load(), device_.GetObjectInfo((uint64_t)vk_queue_).c_str(),
            device_.GetObjectInfo((uint64_t)submit_sem_).c_str());
        return false;
    }
    complete_seq_ = value;
    return true;
}

bool Queue::UpdateIdleState() {
    if (!UpdateSeq()) {
        return false;
    }
    uint64_t completed_seq = CompletedSeq();

    Log().Verbose("completed: %lld submitted: %lld VkQueue: %s", completed_seq, submit_seq_.load(),
                  device_.GetObjectInfo((uint64_t)vk_queue_).c_str());
    std::lock_guard<std::mutex> qlock(queue_submits_mutex_);
    while (!queue_submits_.empty()) {
        auto& submission = queue_submits_.front();
        if (completed_seq < submission.start_seq) {
            break;
        }
        for (auto& submit_info : submission.submit_infos) {
            // Previous submit info finished so this one is
            // either running or blocked on a semaphore.
            if ((completed_seq + 1) == submit_info.seq) {
                submit_info.state = kRunning;
                break;
            }
            if (completed_seq < submit_info.seq) {
                break;
            }
            submit_info.state = kFinished;
        }

        if (completed_seq >= submission.end_seq) {
            queue_submits_.pop_front();
        } else {
            submission.state = kRunning;
            break;
        }
    }
    return true;
}

bool Queue::QueuedSubmitWaitingOnSemaphores(const SubmitInfo& submit_info) const {
    uint64_t semaphore_value = 0;
    bool current_value_available = false;
    auto semaphore_tracker = device_.GetSemaphoreTracker();
    for (uint32_t i = 0; i < submit_info.wait_semaphores.size(); i++) {
        current_value_available =
            semaphore_tracker->GetSemaphoreValue(submit_info.wait_semaphores[i].handle, semaphore_value);
        if (current_value_available && submit_info.wait_semaphores[i].value > semaphore_value) return true;
    }
    return false;
}

std::vector<TrackedSemaphoreInfo> Queue::GetTrackedSemaphoreInfos(const SubmitInfo& submit_info,
                                                                  SemaphoreOperation operation) const {
    std::vector<TrackedSemaphoreInfo> tracked_semaphores;
    auto semaphore_tracker = device_.GetSemaphoreTracker();
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
        << ", VkQueue: " << device_.GetObjectName((uint64_t)vk_queue_) << ", SeqNum: " << submit_info.seq << std::endl;
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
    os << YAML::Key << "IncompleteSubmits" << YAML::Value << YAML::BeginSeq;
    for (const auto& submission : queue_submits_) {
        uint32_t incomplete_submission_counter = 0;
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
            SubmitState submit_state = submit_info.state;
            if (submit_state == SubmitState::kFinished) continue;

            os << YAML::BeginMap;
            os << YAML::Key << "seq" << YAML::Value << submit_info.seq;
            os << YAML::Key << "state";

            if (QueuedSubmitWaitingOnSemaphores(submit_info)) {
                os << YAML::Value << "WAITING_ON_SEMAPHORES";
            } else if (submit_state == SubmitState::kQueued) {
                os << YAML::Value << "QUEUED";
            } else if (submit_state == SubmitState::kRunning) {
                os << YAML::Value << "STARTED";
            }

            if (submit_info.command_buffers.size() > 0) {
                os << YAML::Key << "CommandBuffers" << YAML::Value << YAML::BeginSeq;
                for (const auto& cb : submit_info.command_buffers) {
                    os << device_.GetObjectInfo((uint64_t)cb);
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
        device_.GetContext().DumpDeviceExecutionState(device_);
    }
}

VkResult Queue::SubmitWithoutTrackingSemaphores(uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) {
    VkResult result = device_.Dispatch().QueueSubmit(vk_queue_, submitCount, pSubmits, fence);
    PostSubmit(result);
    return result;
}

VkResult Queue::Submit2WithoutTrackingSemaphores(uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) {
    VkResult result;
    if (device_.Dispatch().QueueSubmit2) {
        result = device_.Dispatch().QueueSubmit2(vk_queue_, submitCount, pSubmits, fence);
    } else {
        result = device_.Dispatch().QueueSubmit2KHR(vk_queue_, submitCount, pSubmits, fence);
    }
    PostSubmit(result);
    return result;
}

VkResult Queue::Submit(uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) {
    for (uint32_t submit_index = 0; submit_index < submitCount; ++submit_index) {
        const auto& submit = pSubmits[submit_index];
        for (uint32_t command_buffer_index = 0; command_buffer_index < submit.commandBufferCount;
             ++command_buffer_index) {
            auto cmd = crash_diagnostic_layer::GetCommandBuffer(submit.pCommandBuffers[command_buffer_index]);
            if (cmd != nullptr) {
                cmd->QueueSubmit(vk_queue_, fence);
            }
        }
    }
    VkResult result;

    if (!tracking_semaphores_) {
        return SubmitWithoutTrackingSemaphores(submitCount, pSubmits, fence);
    }
    std::vector<uint64_t> timeline_values(submitCount + 1);
    std::vector<VkTimelineSemaphoreSubmitInfo> timeline_infos(submitCount + 1,
                                                              vku::InitStruct<VkTimelineSemaphoreSubmitInfo>());
    std::vector<VkSubmitInfo> submits(2 * submitCount + 1, vku::InitStruct<VkSubmitInfo>());

    Submission submission(kQueueSubmit, ++submit_seq_);

    // copy over the original submissions, leaving room for signal submissions in between them
    for (uint32_t i = 0; i < submitCount; i++) {
        SubmitInfo submit_info(device_, pSubmits[i], ++submit_seq_);
        for (auto& cb : submit_info.command_buffers) {
            auto command_buffer = GetCommandBuffer(cb);
            if (command_buffer) {
                command_buffer->SetQueueSeq(submit_info.seq);
            }
        }
        if (trace_all_semaphores_) {
            LogSubmitInfoSemaphores(submit_info);
        }
        // copy over the original submit
        submits[1 + (2 * i)] = pSubmits[i];
        submission.submit_infos.emplace_back(std::move(submit_info));
    }
    submission.end_seq = submit_seq_;  // don't increment so that this is the same as submit_infos.back().seq;

    // Fill in the signal submissions
    uint64_t signal_value = submission.start_seq;
    for (uint32_t i = 0; (i < submitCount + 1); i++, signal_value++) {
        auto& timeline_value = timeline_values[i];
        auto& timeline_info = timeline_infos[i];
        auto& signal_submit = submits[2 * i];

        timeline_value = signal_value;
        timeline_info.signalSemaphoreValueCount = 1;
        timeline_info.pSignalSemaphoreValues = &timeline_value;
        signal_submit.pNext = &timeline_info;
        signal_submit.signalSemaphoreCount = 1;
        signal_submit.pSignalSemaphores = &submit_sem_;
    }

    {
        std::lock_guard<std::mutex> lock(queue_submits_mutex_);
        queue_submits_.emplace_back(std::move(submission));
    }

    result = device_.Dispatch().QueueSubmit(vk_queue_, uint32_t(submits.size()), submits.data(), fence);
    PostSubmit(result);
    return result;
}

VkResult Queue::Submit2(uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) {
    for (uint32_t submit_index = 0; submit_index < submitCount; ++submit_index) {
        const auto& submit = pSubmits[submit_index];
        for (uint32_t command_buffer_index = 0; command_buffer_index < submit.commandBufferInfoCount;
             ++command_buffer_index) {
            auto cmd = crash_diagnostic_layer::GetCommandBuffer(
                submit.pCommandBufferInfos[command_buffer_index].commandBuffer);
            if (cmd != nullptr) {
                cmd->QueueSubmit(vk_queue_, fence);
            }
        }
    }
    VkResult result;

    if (!tracking_semaphores_) {
        return Submit2WithoutTrackingSemaphores(submitCount, pSubmits, fence);
    }

    Submission submission(kQueueSubmit2, submit_seq_++);
    std::vector<VkSemaphoreSubmitInfo> sem_infos(submitCount + 1);
    std::vector<VkSubmitInfo2> submits(2 * submitCount + 1, vku::InitStruct<VkSubmitInfo2>());

    // copy over the original submissions, leaving room for signal submissions in between them
    for (uint32_t i = 0; i < submitCount; i++) {
        SubmitInfo submit_info(device_, pSubmits[i], ++submit_seq_);
        for (auto& cb : submit_info.command_buffers) {
            auto command_buffer = GetCommandBuffer(cb);
            if (command_buffer) {
                command_buffer->SetQueueSeq(submit_info.seq);
            }
        }
        if (trace_all_semaphores_) {
            LogSubmitInfoSemaphores(submit_info);
        }
        // copy over the original submit
        submits[1 + (2 * i)] = pSubmits[i];
        submission.submit_infos.emplace_back(std::move(submit_info));
    }
    submission.end_seq = submit_seq_;  // don't increment so that this is the same as submit_infos.back().seq;

    // Fill in the signal submissions
    uint64_t signal_value = submission.start_seq;
    for (uint32_t i = 0; (i < submitCount + 1); i++, signal_value++) {
        auto& sem_info = sem_infos[i];
        auto& signal_submit = submits[i * 2];
        sem_info.semaphore = submit_sem_;
        sem_info.value = submission.start_seq;
        sem_info.stageMask = VK_PIPELINE_STAGE_2_BOTTOM_OF_PIPE_BIT;
        signal_submit.signalSemaphoreInfoCount = 1;
        signal_submit.pSignalSemaphoreInfos = &sem_info;
    }

    {
        std::lock_guard<std::mutex> lock(queue_submits_mutex_);
        queue_submits_.emplace_back(std::move(submission));
    }

    if (device_.Dispatch().QueueSubmit2) {
        result = device_.Dispatch().QueueSubmit2(vk_queue_, uint32_t(submits.size()), submits.data(), fence);
    } else {
        result = device_.Dispatch().QueueSubmit2KHR(vk_queue_, uint32_t(submits.size()), submits.data(), fence);
    }

    PostSubmit(result);
    return result;
}

VkResult Queue::BindSparse(uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfos, VkFence fence) {
    VkResult result;
    // If semaphore tracking is not requested, pass the call to the dispatch table
    // as is.
    if (!tracking_semaphores_) {
        result = device_.Dispatch().QueueBindSparse(vk_queue_, bindInfoCount, pBindInfos, fence);
        PostSubmit(result);
        return result;
    }
    std::vector<uint64_t> timeline_values(bindInfoCount + 1);
    std::vector<VkTimelineSemaphoreSubmitInfo> timeline_infos(bindInfoCount + 1,
                                                              vku::InitStruct<VkTimelineSemaphoreSubmitInfo>());
    std::vector<VkBindSparseInfo> binds(2 * bindInfoCount + 1, vku::InitStruct<VkBindSparseInfo>());

    Submission submission(kQueueBindSparse, ++submit_seq_);

    // copy over the original submissions, leaving room for signal submissions in between them
    for (uint32_t i = 0; i < bindInfoCount; i++) {
        SubmitInfo submit_info(device_, pBindInfos[i], ++submit_seq_);
        for (auto& cb : submit_info.command_buffers) {
            auto command_buffer = GetCommandBuffer(cb);
            if (command_buffer) {
                command_buffer->SetQueueSeq(submit_info.seq);
            }
        }
        if (trace_all_semaphores_) {
            LogSubmitInfoSemaphores(submit_info);
        }
        // copy over the original submit
        binds[1 + (2 * i)] = pBindInfos[i];
        submission.submit_infos.emplace_back(std::move(submit_info));
    }
    // don't increment so that this is the same as submit_infos.back().seq;
    submission.end_seq = submit_seq_;

    // Fill in the signal submissions
    uint64_t signal_value = submission.start_seq;
    for (uint32_t i = 0; (i < bindInfoCount + 1); i++, signal_value++) {
        auto& timeline_value = timeline_values[i];
        auto& timeline_info = timeline_infos[i];
        auto& signal_bind = binds[2 * i];

        timeline_value = submission.start_seq;
        timeline_info.signalSemaphoreValueCount = 1;
        timeline_info.pSignalSemaphoreValues = &timeline_value;
        signal_bind.pNext = &timeline_info;
        signal_bind.signalSemaphoreCount = 1;
        signal_bind.pSignalSemaphores = &submit_sem_;
    }

    {
        std::lock_guard<std::mutex> lock(queue_submits_mutex_);
        queue_submits_.emplace_back(std::move(submission));
    }
    return device_.Dispatch().QueueBindSparse(vk_queue_, uint32_t(binds.size()), binds.data(), fence);
}

void Queue::LogSubmitInfoSemaphores(const SubmitInfo& submit_info) {
    assert(tracking_semaphores_ == true);
    assert(trace_all_semaphores_ == true);
    if (SubmitInfoHasSemaphores(submit_info)) {
        std::string semaphore_log = GetSubmitInfoSemaphoresLog(submit_info);
        Log().Info(semaphore_log);
    }
}

}  // namespace crash_diagnostic_layer
