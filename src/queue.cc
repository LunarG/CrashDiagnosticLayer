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

#include "device.h"
#include "cdl.h"
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
        auto pool_ci = vku::InitStruct<VkCommandPoolCreateInfo>();
        pool_ci.queueFamilyIndex = queue_family_index_;
        VkResult result =
            device_.Dispatch().CreateCommandPool(device_.GetVkDevice(), &pool_ci, nullptr, &helper_command_pool_);
        if (result != VK_SUCCESS) {
            Log().Warning("failed to create command pool for helper command buffers. VkQueue: %s, queueFamilyIndex: %d",
                          device_.GetObjectInfo((uint64_t)vk_queue_).c_str(), queue_family_index_);
        }
    }
}

void Queue::Destroy() {
    if (helper_command_pool_ != VK_NULL_HANDLE) {
        device_.Dispatch().DestroyCommandPool(device_.GetVkDevice(), helper_command_pool_, nullptr);
        helper_command_pool_ = VK_NULL_HANDLE;
    }
}

Queue::~Queue() { Destroy(); }

const Logger& Queue::Log() const { return device_.Log(); }

SubmitInfoId Queue::RegisterSubmitInfo(QueueSubmitId queue_submit_index, const VkSubmitInfo* vk_submit_info) {
    // Store the handles of command buffers and semaphores
    SubmitInfo submit_info;
    // Reserve the markers
    bool top_marker_is_valid = device_.AllocateMarker(&submit_info.top_marker);
    if (!top_marker_is_valid || !device_.AllocateMarker(&submit_info.bottom_marker)) {
        Log().Warning("Cannot acquire marker. Not tracking submit info %s",
                      device_.GetObjectName((uint64_t)vk_submit_info).c_str());
        if (top_marker_is_valid) {
            device_.FreeMarker(submit_info.top_marker);
        }
        return kInvalidSubmitInfoId;
    }
    submit_info.submit_info_id = ++submit_info_counter;
    submit_info.queue_submit_index = queue_submit_index;
    for (uint32_t i = 0; i < vk_submit_info->waitSemaphoreCount; i++) {
        submit_info.wait_semaphores.push_back(vk_submit_info->pWaitSemaphores[i]);
        submit_info.wait_semaphore_values.push_back(1);
        submit_info.wait_semaphore_pipeline_stages.push_back(vk_submit_info->pWaitDstStageMask[i]);
    }
    for (uint32_t i = 0; i < vk_submit_info->commandBufferCount; i++) {
        submit_info.command_buffers.push_back(vk_submit_info->pCommandBuffers[i]);
    }
    for (uint32_t i = 0; i < vk_submit_info->signalSemaphoreCount; i++) {
        submit_info.signal_semaphores.push_back(vk_submit_info->pSignalSemaphores[i]);
        submit_info.signal_semaphore_values.push_back(1);
    }

    // Store type and initial value of the timeline semaphores.
    const auto* timeline_semaphore_info = vku::FindStructInPNextChain<VkTimelineSemaphoreSubmitInfoKHR>(vk_submit_info);
    if (timeline_semaphore_info) {
        auto semaphore_tracker = device_.GetSemaphoreTracker();
        for (uint32_t i = 0; i < timeline_semaphore_info->waitSemaphoreValueCount; i++) {
            if (semaphore_tracker->GetSemaphoreType(vk_submit_info->pWaitSemaphores[i]) ==
                VK_SEMAPHORE_TYPE_TIMELINE_KHR) {
                submit_info.wait_semaphore_values[i] = timeline_semaphore_info->pWaitSemaphoreValues[i];
            }
        }
        for (uint32_t i = 0; i < timeline_semaphore_info->signalSemaphoreValueCount; i++) {
            if (semaphore_tracker->GetSemaphoreType(vk_submit_info->pSignalSemaphores[i]) ==
                VK_SEMAPHORE_TYPE_TIMELINE_KHR) {
                submit_info.signal_semaphore_values[i] = timeline_semaphore_info->pSignalSemaphoreValues[i];
            }
        }
    }

    {
        std::lock_guard<std::mutex> lock(submit_infos_mutex_);
        submit_infos_[submit_info.submit_info_id] = submit_info;
    }
    {
        std::lock_guard<std::mutex> lock(queue_submits_mutex_);
        queue_submits_[queue_submit_index].push_back(submit_info.submit_info_id);
    }
    return submit_info.submit_info_id;
}

SubmitInfoId Queue::RegisterSubmitInfo(QueueSubmitId queue_submit_index, const VkSubmitInfo2* vk_submit_info) {
    // Store the handles of command buffers and semaphores
    SubmitInfo submit_info;
    // Reserve the markers
    bool top_marker_is_valid = device_.AllocateMarker(&submit_info.top_marker);
    if (!top_marker_is_valid || !device_.AllocateMarker(&submit_info.bottom_marker)) {
        Log().Warning("Cannot acquire marker. Not tracking submit info %s",
                      device_.GetObjectName((uint64_t)vk_submit_info).c_str());
        if (top_marker_is_valid) {
            device_.FreeMarker(submit_info.top_marker);
        }
        return kInvalidSubmitInfoId;
    }
    submit_info.submit_info_id = ++submit_info_counter;
    submit_info.queue_submit_index = queue_submit_index;
    for (uint32_t i = 0; i < vk_submit_info->waitSemaphoreInfoCount; i++) {
        const auto& sem_info = vk_submit_info->pWaitSemaphoreInfos[i];
        submit_info.wait_semaphores.push_back(sem_info.semaphore);
        submit_info.wait_semaphore_values.push_back(sem_info.value);
        submit_info.wait_semaphore_pipeline_stages.push_back(sem_info.stageMask);
    }
    for (uint32_t i = 0; i < vk_submit_info->commandBufferInfoCount; i++) {
        submit_info.command_buffers.push_back(vk_submit_info->pCommandBufferInfos[i].commandBuffer);
    }
    for (uint32_t i = 0; i < vk_submit_info->signalSemaphoreInfoCount; i++) {
        const auto& sem_info = vk_submit_info->pSignalSemaphoreInfos[i];
        submit_info.signal_semaphores.push_back(sem_info.semaphore);
        submit_info.signal_semaphore_values.push_back(sem_info.value);
    }

    {
        std::lock_guard<std::mutex> lock(submit_infos_mutex_);
        submit_infos_[submit_info.submit_info_id] = submit_info;
    }
    {
        std::lock_guard<std::mutex> lock(queue_submits_mutex_);
        queue_submits_[queue_submit_index].push_back(submit_info.submit_info_id);
    }
    return submit_info.submit_info_id;
}

void Queue::StoreSubmitHelperCommandBuffersInfo(SubmitInfoId submit_info_id, VkCommandBuffer start_marker_cb,
                                                VkCommandBuffer end_marker_cb) {
    assert(submit_info_id != kInvalidSubmitInfoId);
    std::lock_guard<std::mutex> lock(submit_infos_mutex_);
    if (submit_infos_.find(submit_info_id) != submit_infos_.end()) {
        SubmitInfo& submit_info = submit_infos_[submit_info_id];
        submit_info.start_marker_cb = start_marker_cb;
        device_.AddObjectInfo((uint64_t)submit_info.start_marker_cb, VK_OBJECT_TYPE_COMMAND_BUFFER, "CDL start marker");
        submit_info.end_marker_cb = end_marker_cb;
        device_.AddObjectInfo((uint64_t)submit_info.end_marker_cb, VK_OBJECT_TYPE_COMMAND_BUFFER, "CDL end marker");
    }
}

void Queue::RecordSubmitStart(QueueSubmitId qsubmit_id, SubmitInfoId submit_info_id, VkCommandBuffer cb) {
    assert(submit_info_id != kInvalidSubmitInfoId);
    assert(tracking_semaphores_ == true);

    auto begin_info = vku::InitStruct<VkCommandBufferBeginInfo>();
    VkResult result = device_.Dispatch().BeginCommandBuffer(cb, &begin_info);
    assert(result == VK_SUCCESS);
    if (result != VK_SUCCESS) {
        Log().Warning("failed to begin helper command buffer. vkBeginCommandBuffer() returned 0x%08x", result);
        return;
    }

    std::lock_guard<std::mutex> slock(submit_infos_mutex_);
    if (submit_infos_.find(submit_info_id) != submit_infos_.end()) {
        SubmitInfo& submit_info = submit_infos_[submit_info_id];
        // Write the state of the submit
        device_.WriteMarker(submit_info.top_marker, SubmitState::kQueued);
        device_.WriteMarker(cb, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, submit_info.top_marker, SubmitState::kRunning);
        // Reset binary wait semaphores
        auto semaphore_tracker = device_.GetSemaphoreTracker();
        for (size_t i = 0; i < submit_info.wait_semaphores.size(); i++) {
            if (semaphore_tracker->GetSemaphoreType(submit_info.wait_semaphores[i]) == VK_SEMAPHORE_TYPE_BINARY_KHR) {
                semaphore_tracker->WriteMarker(submit_info.wait_semaphores[i], cb, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, 0,
                                               {SemaphoreModifierType::kModifierQueueSubmit, qsubmit_id});
            }
        }
    } else {
        Log().Warning("No previous record of queued submit in submit tracker: %d", submit_info_id);
    }
    result = device_.Dispatch().EndCommandBuffer(cb);
    assert(result == VK_SUCCESS);
}

void Queue::RecordSubmitFinish(QueueSubmitId qsubmit_id, SubmitInfoId submit_info_id, VkCommandBuffer cb) {
    assert(submit_info_id != kInvalidSubmitInfoId);

    auto begin_info = vku::InitStruct<VkCommandBufferBeginInfo>();
    VkResult result = device_.Dispatch().BeginCommandBuffer(cb, &begin_info);
    assert(result == VK_SUCCESS);
    if (result != VK_SUCCESS) {
        Log().Warning("failed to begin helper command buffer. vkBeginCommandBuffer() returned 0x%08x", result);
        return;
    }

    std::lock_guard<std::mutex> slock(submit_infos_mutex_);
    if (submit_infos_.find(submit_info_id) != submit_infos_.end()) {
        SubmitInfo& submit_info = submit_infos_[submit_info_id];
        // Update the value of signal semaphores
        auto semaphore_tracker = device_.GetSemaphoreTracker();
        for (size_t i = 0; i < submit_info.signal_semaphores.size(); i++) {
            semaphore_tracker->WriteMarker(submit_info.signal_semaphores[i], cb, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                           submit_info.signal_semaphore_values[i],
                                           {SemaphoreModifierType::kModifierQueueSubmit, qsubmit_id});
        }
        // Write the state of the submit
        device_.WriteMarker(cb, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, submit_info.bottom_marker,
                            SubmitState::kFinished);
    } else {
        Log().Warning("No previous record of queued submit in submit tracker.");
    }
    result = device_.Dispatch().EndCommandBuffer(cb);
    assert(result == VK_SUCCESS);
}

void Queue::CleanupSubmitInfos() {
    std::lock_guard<std::mutex> qlock(queue_submits_mutex_);
    std::lock_guard<std::mutex> slock(submit_infos_mutex_);
    for (auto qsubmit_it = queue_submits_.begin(); qsubmit_it != queue_submits_.end();) {
        auto& queue_submit_info_ids = qsubmit_it->second;
        for (auto submit_it = queue_submit_info_ids.begin(); submit_it != queue_submit_info_ids.end();) {
            auto submit_info_id = *submit_it;
            auto it = submit_infos_.find(submit_info_id);
            if (it == submit_infos_.end()) {
                Log().Warning("No previous record of queued submit in submit tracker: %d", submit_info_id);
                submit_it++;
                continue;
            }
            const SubmitInfo& submit_info = it->second;
            auto submit_status = device_.ReadMarker(submit_info.bottom_marker);
            if (submit_status == SubmitState::kFinished) {
                // Free extra command buffers used to track the state of the submit and
                // the values of the semaphores
                std::vector<VkCommandBuffer> tracking_buffers{submit_info.start_marker_cb, submit_info.end_marker_cb};
                device_.FreeCommandBuffers(helper_command_pool_, 2, tracking_buffers.data());
                submit_infos_.erase(it);
                submit_it = queue_submit_info_ids.erase(submit_it);
            } else {
                submit_it++;
            }
        }
        if (queue_submit_info_ids.size() == 0) {
            qsubmit_it = queue_submits_.erase(qsubmit_it);
        } else {
            qsubmit_it++;
        }
    }
}

void Queue::RecordBindSparseHelperSubmit(QueueBindSparseId qbind_sparse_id, const VkSubmitInfo* vk_submit_info) {
    CleanupBindSparseHelperSubmits();

    HelperSubmitInfo hsubmit_info;
    // Reserve the marker
    if (!device_.AllocateMarker(&hsubmit_info.marker)) {
        Log().Warning("Cannot acquire marker for QueueBindSparse's helper submit");
        return;
    }
    std::lock_guard<std::mutex> lock(helper_submit_infos_mutex_);
    helper_submit_infos_.push_back(hsubmit_info);
    auto& helper_submit_info = helper_submit_infos_.back();
    helper_submit_info.marker_cb = vk_submit_info->pCommandBuffers[0];

    // Write the state of the submit
    device_.WriteMarker(helper_submit_info.marker, uint32_t(SubmitState::kQueued));

    auto begin_info = vku::InitStruct<VkCommandBufferBeginInfo>();
    VkResult result = device_.Dispatch().BeginCommandBuffer(vk_submit_info->pCommandBuffers[0], &begin_info);
    assert(result == VK_SUCCESS);
    if (result != VK_SUCCESS) {
        Log().Warning("failed to begin helper command buffer. vkBeginCommandBuffer() returned 0x%08x", result);
        return;
    }

    device_.WriteMarker(helper_submit_info.marker_cb, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, helper_submit_info.marker,
                        uint32_t(SubmitState::kFinished));

    // Extract signal semaphore values from submit info
    std::unordered_map<VkSemaphore, uint64_t /*signal_value*/> signal_semaphores;
    for (uint32_t i = 0; i < vk_submit_info->signalSemaphoreCount; i++) {
        signal_semaphores[vk_submit_info->pSignalSemaphores[i]] = 1;
    }

    auto semaphore_tracker = device_.GetSemaphoreTracker();
    const auto* timeline_semaphore_info = vku::FindStructInPNextChain<VkTimelineSemaphoreSubmitInfoKHR>(vk_submit_info);
    if (timeline_semaphore_info) {
        for (uint32_t i = 0; i < timeline_semaphore_info->signalSemaphoreValueCount; i++) {
            if (semaphore_tracker->GetSemaphoreType(vk_submit_info->pSignalSemaphores[i]) ==
                VK_SEMAPHORE_TYPE_TIMELINE_KHR) {
                signal_semaphores[vk_submit_info->pSignalSemaphores[i]] =
                    timeline_semaphore_info->pSignalSemaphoreValues[i];
            }
        }
    }

    // Update the value of signal semaphores
    for (auto& it : signal_semaphores) {
        semaphore_tracker->WriteMarker(it.first, helper_submit_info.marker_cb, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                       it.second, {SemaphoreModifierType::kModifierQueueBindSparse, qbind_sparse_id});
    }

    // Reset binary wait semaphores
    for (size_t i = 0; i < vk_submit_info->waitSemaphoreCount; i++) {
        if (semaphore_tracker->GetSemaphoreType(vk_submit_info->pWaitSemaphores[i]) == VK_SEMAPHORE_TYPE_BINARY_KHR) {
            semaphore_tracker->WriteMarker(vk_submit_info->pWaitSemaphores[i], helper_submit_info.marker_cb,
                                           VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, 0,
                                           {SemaphoreModifierType::kModifierQueueBindSparse, qbind_sparse_id});
        }
    }
    result = device_.Dispatch().EndCommandBuffer(vk_submit_info->pCommandBuffers[0]);
    assert(result == VK_SUCCESS);
}

void Queue::CleanupBindSparseHelperSubmits() {
    std::lock_guard<std::mutex> lock(helper_submit_infos_mutex_);
    for (auto helper_submit_info = helper_submit_infos_.begin(); helper_submit_info != helper_submit_infos_.end();) {
        auto submit_status = device_.ReadMarker(helper_submit_info->marker);
        if (submit_status == SubmitState::kFinished) {
            // Free the command buffer used to track the state of the submit and
            // the values of the semaphores
            device_.FreeCommandBuffers(helper_command_pool_, 1, &(helper_submit_info->marker_cb));
            device_.FreeMarker(helper_submit_info->marker);
            helper_submit_info = helper_submit_infos_.erase(helper_submit_info);
        } else {
            helper_submit_info++;
        }
    }
}

bool Queue::QueuedSubmitWaitingOnSemaphores(SubmitInfoId submit_info_id) const {
    auto it = submit_infos_.find(submit_info_id);
    const SubmitInfo& submit_info = it->second;
    uint64_t semaphore_value = 0;
    bool current_value_available = false;
    auto semaphore_tracker = device_.GetSemaphoreTracker();
    for (uint32_t i = 0; i < submit_info.wait_semaphores.size(); i++) {
        current_value_available = semaphore_tracker->GetSemaphoreValue(submit_info.wait_semaphores[i], semaphore_value);
        if (current_value_available && submit_info.wait_semaphore_values[i] > semaphore_value) return true;
    }
    return false;
}

std::vector<TrackedSemaphoreInfo> Queue::GetTrackedSemaphoreInfos(SubmitInfoId submit_info_id,
                                                                  SemaphoreOperation operation) const {
    std::vector<TrackedSemaphoreInfo> tracked_semaphores;
    auto it = submit_infos_.find(submit_info_id);
    if (it == submit_infos_.end()) {
        return tracked_semaphores;
    }
    const SubmitInfo& submit_info = it->second;
    auto semaphore_tracker = device_.GetSemaphoreTracker();
    if (operation == SemaphoreOperation::kWaitOperation) {
        return semaphore_tracker->GetTrackedSemaphoreInfos(submit_info.wait_semaphores,
                                                           submit_info.wait_semaphore_values);
    }
    return semaphore_tracker->GetTrackedSemaphoreInfos(submit_info.signal_semaphores,
                                                       submit_info.signal_semaphore_values);
}

bool Queue::SubmitInfoHasSemaphores(SubmitInfoId submit_info_id) const {
    std::lock_guard<std::mutex> lock(submit_infos_mutex_);
    auto it = submit_infos_.find(submit_info_id);
    if (it == submit_infos_.end()) {
        return false;
    }
    const SubmitInfo& submit_info = it->second;
    return (submit_info.wait_semaphores.size() > 0 || submit_info.signal_semaphores.size() > 0);
}

std::string Queue::GetSubmitInfoSemaphoresLog(SubmitInfoId submit_info_id) const {
    std::lock_guard<std::mutex> lock(submit_infos_mutex_);
    std::stringstream log;
    log << "VkSubmitInfo with semaphores submitted to queue." << std::endl
        << "\tVkDevice: " << device_.GetObjectName((uint64_t)device_.GetVkDevice())
        << ", VkQueue: " << device_.GetObjectName((uint64_t)vk_queue_) << ", SubmitInfoId: " << submit_info_id
        << std::endl;
    const char* tab = "\t";
    auto wait_semaphores = GetTrackedSemaphoreInfos(submit_info_id, kWaitOperation);
    if (wait_semaphores.size() > 0) {
        log << tab << "*** Wait Semaphores ***" << std::endl;
        log << device_.GetSemaphoreTracker()->PrintTrackedSemaphoreInfos(wait_semaphores, tab);
    }
    auto signal_semaphores = GetTrackedSemaphoreInfos(submit_info_id, kSignalOperation);
    if (signal_semaphores.size() > 0) {
        log << tab << "*** Signal Semaphores ***" << std::endl;
        log << device_.GetSemaphoreTracker()->PrintTrackedSemaphoreInfos(signal_semaphores, tab);
    }
    return log.str();
}

void Queue::Print(YAML::Emitter& os) const {
    os << YAML::BeginMap;
    os << YAML::Key << "vkHandle" << YAML::Value << device_.GetObjectInfo((uint64_t)vk_queue_);
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

    std::lock_guard<std::mutex> slock(submit_infos_mutex_);
    if (submit_infos_.size() == 0) {
        os << YAML::EndMap;
        return;
    }

    std::lock_guard<std::mutex> qlock(queue_submits_mutex_);
    os << YAML::Key << "IncompleteSubmits" << YAML::Value << YAML::BeginSeq;
    for (const auto& qit : queue_submits_) {
        uint32_t incomplete_submission_counter = 0;
        os << YAML::BeginMap;
        os << YAML::Key << "submission" << YAML::Value << qit.first;
        os << YAML::Key << "batches" << YAML::Value << YAML::BeginSeq;
        for (auto& submit_info_index : qit.second) {
            auto iter = submit_infos_.find(submit_info_index);
            assert(iter != submit_infos_.end());
            const SubmitInfo& submit_info = iter->second;
            // Check submit state
            auto submit_state = device_.ReadMarker(submit_info.bottom_marker);
            if (submit_state == SubmitState::kFinished) continue;
            submit_state = device_.ReadMarker(submit_info.top_marker);
            if (submit_state == SubmitState::kFinished) continue;

            assert(submit_state != SubmitState::kInvalid);
            os << YAML::BeginMap;
            os << YAML::Key << "id" << YAML::Value << submit_info.submit_info_id;
            os << YAML::Key << "state";

            if (submit_state == SubmitState::kRunning) {
                os << YAML::Value << "[STARTED,INCOMPLETE]";
            } else if (submit_state == SubmitState::kQueued) {
                if (QueuedSubmitWaitingOnSemaphores(submit_info.submit_info_id)) {
                    os << YAML::Value << "[QUEUED,WAITING_ON_SEMAPHORES]";
                } else {
                    os << YAML::Value << "[QUEUED,NOT_WAITING_ON_SEMAPHORES]";
                }
            }
            if (submit_info.command_buffers.size() > 0) {
                os << YAML::Key << "CommandBuffers" << YAML::Value << YAML::BeginSeq;
                for (const auto& cb : submit_info.command_buffers) {
                    os << device_.GetObjectInfo((uint64_t)cb);
                }
                os << YAML::EndSeq;
            }
            auto wait_semaphores = GetTrackedSemaphoreInfos(submit_info.submit_info_id, kWaitOperation);
            if (wait_semaphores.size() > 0) {
                os << YAML::Key << "WaitSemaphores" << YAML::Value << YAML::BeginSeq;
                for (const auto& wait : wait_semaphores) {
                    os << YAML::BeginMap;
                    os << YAML::Key << "vkSemaphore" << YAML::Value << device_.GetObjectInfo((uint64_t)wait.semaphore);
                    os << YAML::Key << "type" << YAML::Value;
                    if (wait.semaphore_type == VK_SEMAPHORE_TYPE_BINARY_KHR) {
                        os << "Binary";
                    } else {
                        os << "Timeline";
                        os << YAML::Key << "waitValue" << YAML::Value << wait.semaphore_operation_value;
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
            auto signal_semaphores = GetTrackedSemaphoreInfos(submit_info.submit_info_id, kSignalOperation);
            if (signal_semaphores.size() > 0) {
                os << YAML::Key << "SignalSemaphores" << YAML::Value << YAML::BeginSeq;
                for (auto signal : signal_semaphores) {
                    os << YAML::BeginMap;
                    os << YAML::Key << "vkSemaphore" << YAML::Value
                       << device_.GetObjectInfo((uint64_t)signal.semaphore);
                    os << YAML::Key << "type" << YAML::Value;
                    if (signal.semaphore_type == VK_SEMAPHORE_TYPE_BINARY_KHR) {
                        os << "Binary";
                    } else {
                        os << "Timeline";
                        os << YAML::Key << "signalValue" << YAML::Value << signal.semaphore_operation_value;
                    }
                    os << YAML::EndMap;
                }
                os << YAML::EndSeq;
            }
            if (submit_info.fence) {
                os << YAML::Key << "Fence" << YAML::Value << device_.GetObjectInfo((uint64_t)submit_info.fence);
            }
            os << YAML::EndMap;
        }
        os << YAML::EndSeq << YAML::EndMap;
    }
    os << YAML::EndSeq;
    os << YAML::EndMap;
    assert(os.good());
}

void Queue::PostSubmit(VkResult result) {
    bool dump = IsVkError(result) || device_.GetContext().CountSubmit();
    if (dump) {
        device_.GetContext().DumpDeviceExecutionState(device_.GetVkDevice());
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

std::vector<VkCommandBuffer> Queue::AllocHelperCBs(uint32_t count) {
    std::vector<VkCommandBuffer> new_buffers(count, VK_NULL_HANDLE);

    auto cb_allocate_info = vku::InitStruct<VkCommandBufferAllocateInfo>();
    cb_allocate_info.commandPool = helper_command_pool_;
    cb_allocate_info.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    cb_allocate_info.commandBufferCount = count;

    auto result =
        device_.Dispatch().AllocateCommandBuffers(device_.GetVkDevice(), &cb_allocate_info, new_buffers.data());
    if (result != VK_SUCCESS) {
        new_buffers.clear();
        return new_buffers;
    }
    for (uint32_t i = 0; i < count; i++) {
        SetDeviceLoaderData(device_.GetVkDevice(), new_buffers[i]);
    }
    return new_buffers;
}

VkResult Queue::Submit(uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) {
    for (uint32_t submit_index = 0; submit_index < submitCount; ++submit_index) {
        const auto& submit_info = pSubmits[submit_index];
        for (uint32_t command_buffer_index = 0; command_buffer_index < submit_info.commandBufferCount;
             ++command_buffer_index) {
            auto cmd = crash_diagnostic_layer::GetCommandBuffer(submit_info.pCommandBuffers[command_buffer_index]);
            if (cmd != nullptr) {
                cmd->QueueSubmit(vk_queue_, fence);
            }
        }
    }
    VkResult result;

    if (!tracking_semaphores_) {
        return SubmitWithoutTrackingSemaphores(submitCount, pSubmits, fence);
    }
    auto queue_submit_id = GetNextQueueSubmitId();
    auto semaphore_tracking_submits = reinterpret_cast<VkSubmitInfo*>(alloca(sizeof(VkSubmitInfo) * submitCount));

    std::vector<VkCommandBuffer> new_buffers = AllocHelperCBs(2 * submitCount);
    if (new_buffers.empty()) {
        Log().Error(
            "failed to find the helper command pool to allocate helper command buffers for tracking queue submit "
            "state. Not tracking semaphores.");
        return SubmitWithoutTrackingSemaphores(submitCount, pSubmits, fence);
    }

    for (uint32_t submit_index = 0; submit_index < submitCount; ++submit_index) {
        // Add the semaphore tracking command buffers to the beginning and the end
        // of the queue submit info.
        semaphore_tracking_submits[submit_index] = pSubmits[submit_index];
        auto cb_count = pSubmits[submit_index].commandBufferCount;
        VkCommandBuffer* extended_cbs = (VkCommandBuffer*)alloca((cb_count + 2) * sizeof(VkCommandBuffer));
        semaphore_tracking_submits[submit_index].pCommandBuffers = extended_cbs;
        semaphore_tracking_submits[submit_index].commandBufferCount = cb_count + 2;

        extended_cbs[0] = new_buffers[submit_index];
        for (uint32_t cb_index = 0; cb_index < cb_count; ++cb_index) {
            extended_cbs[cb_index + 1] = pSubmits[submit_index].pCommandBuffers[cb_index];
        }
        extended_cbs[cb_count + 1] = new_buffers[submit_index + 1];

        auto submit_info_id = RegisterSubmitInfo(queue_submit_id, &semaphore_tracking_submits[submit_index]);
        StoreSubmitHelperCommandBuffersInfo(submit_info_id, extended_cbs[0], extended_cbs[cb_count + 1]);
        for (uint32_t cb_index = 0; cb_index < cb_count; ++cb_index) {
            auto command_buffer = GetCommandBuffer(pSubmits[submit_index].pCommandBuffers[cb_index]);
            assert(command_buffer != nullptr);
            if (command_buffer) {
                command_buffer->SetSubmitInfoId(submit_info_id);
            }
        }

        RecordSubmitStart(queue_submit_id, submit_info_id, extended_cbs[0]);
        RecordSubmitFinish(queue_submit_id, submit_info_id, extended_cbs[cb_count + 1]);

        if (trace_all_semaphores_) {
            LogSubmitInfoSemaphores(submit_info_id);
        }
    }

    result = device_.Dispatch().QueueSubmit(vk_queue_, submitCount, semaphore_tracking_submits, fence);
    PostSubmit(result);
    return result;
}

VkResult Queue::Submit2(uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) {
    for (uint32_t submit_index = 0; submit_index < submitCount; ++submit_index) {
        const auto& submit_info = pSubmits[submit_index];
        for (uint32_t command_buffer_index = 0; command_buffer_index < submit_info.commandBufferInfoCount;
             ++command_buffer_index) {
            auto cmd = crash_diagnostic_layer::GetCommandBuffer(
                submit_info.pCommandBufferInfos[command_buffer_index].commandBuffer);
            if (cmd != nullptr) {
                cmd->QueueSubmit(vk_queue_, fence);
            }
        }
    }
    VkResult result;

    if (!tracking_semaphores_) {
        return Submit2WithoutTrackingSemaphores(submitCount, pSubmits, fence);
    }

    auto queue_submit_id = GetNextQueueSubmitId();
    auto semaphore_tracking_submits = reinterpret_cast<VkSubmitInfo2*>(alloca(sizeof(VkSubmitInfo) * submitCount));

    std::vector<VkCommandBuffer> new_buffers = AllocHelperCBs(2 * submitCount);
    if (new_buffers.empty()) {
        Log().Error(
            "failed to find the helper command pool to allocate helper command buffers for tracking queue submit "
            "state. Not tracking semaphores.");
        return Submit2WithoutTrackingSemaphores(submitCount, pSubmits, fence);
    }

    for (uint32_t submit_index = 0; submit_index < submitCount; ++submit_index) {
        // Add the semaphore tracking command buffers to the beginning and the end
        // of the queue submit info.
        semaphore_tracking_submits[submit_index] = pSubmits[submit_index];
        auto cb_count = pSubmits[submit_index].commandBufferInfoCount;
        VkCommandBufferSubmitInfo* extended_cbs =
            (VkCommandBufferSubmitInfo*)alloca((cb_count + 2) * sizeof(VkCommandBufferSubmitInfo));
        semaphore_tracking_submits[submit_index].pCommandBufferInfos = extended_cbs;
        semaphore_tracking_submits[submit_index].commandBufferInfoCount = cb_count + 2;

        extended_cbs[0] = vku::InitStruct<VkCommandBufferSubmitInfo>();
        extended_cbs[0].commandBuffer = new_buffers[submit_index];
        for (uint32_t cb_index = 0; cb_index < cb_count; ++cb_index) {
            extended_cbs[cb_index + 1] = pSubmits[submit_index].pCommandBufferInfos[cb_index];
        }
        extended_cbs[cb_count + 1] = vku::InitStruct<VkCommandBufferSubmitInfo>();
        extended_cbs[cb_count + 1].commandBuffer = new_buffers[submit_index + 1];

        auto submit_info_id = RegisterSubmitInfo(queue_submit_id, &semaphore_tracking_submits[submit_index]);
        StoreSubmitHelperCommandBuffersInfo(submit_info_id, extended_cbs[0].commandBuffer,
                                            extended_cbs[cb_count + 1].commandBuffer);
        for (uint32_t cb_index = 0; cb_index < cb_count; ++cb_index) {
            auto command_buffer = GetCommandBuffer(pSubmits[submit_index].pCommandBufferInfos[cb_index].commandBuffer);
            assert(command_buffer != nullptr);
            if (command_buffer) {
                command_buffer->SetSubmitInfoId(submit_info_id);
            }
        }

        RecordSubmitStart(queue_submit_id, submit_info_id, extended_cbs[0].commandBuffer);
        RecordSubmitFinish(queue_submit_id, submit_info_id, extended_cbs[cb_count + 1].commandBuffer);

        if (trace_all_semaphores_) {
            LogSubmitInfoSemaphores(submit_info_id);
        }
    }

    if (device_.Dispatch().QueueSubmit2) {
        result = device_.Dispatch().QueueSubmit2(vk_queue_, submitCount, pSubmits, fence);
    } else {
        result = device_.Dispatch().QueueSubmit2KHR(vk_queue_, submitCount, pSubmits, fence);
    }

    PostSubmit(result);
    return result;
}

VkResult Queue::BindSparse(uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence) {
    VkResult result;
    // If semaphore tracking is not requested, pass the call to the dispatch table
    // as is.
    if (!tracking_semaphores_) {
        result = device_.Dispatch().QueueBindSparse(vk_queue_, bindInfoCount, pBindInfo, fence);
        PostSubmit(result);
        return result;
    }

    auto qbind_sparse_id = GetNextQueueBindSparseId();
    if (tracking_semaphores_ && trace_all_semaphores_) {
        LogBindSparseInfosSemaphores(bindInfoCount, pBindInfo);
    }

    // If we don't need to expand the bind sparse info, pass the call to dispatch
    // table.
    PackedBindSparseInfo packed_bind_sparse_info(vk_queue_, bindInfoCount, pBindInfo);
    if (!ShouldExpandQueueBindSparseToTrackSemaphores(&packed_bind_sparse_info)) {
        result = device_.Dispatch().QueueBindSparse(vk_queue_, bindInfoCount, pBindInfo, fence);
        PostSubmit(result);
        return result;
    }

    ExpandedBindSparseInfo expanded_bind_sparse_info(&packed_bind_sparse_info);
    ExpandBindSparseInfo(&expanded_bind_sparse_info);

    // For each VkSubmitInfo added to the expanded vkQueueBindSparse, check if
    // pNext should point to a VkTimelineSemaphoreSubmitInfoKHR struct.
    size_t tsinfo_it = 0;
    for (int i = 0; i < expanded_bind_sparse_info.submit_infos.size(); i++) {
        if (expanded_bind_sparse_info.has_timeline_semaphore_info[i]) {
            expanded_bind_sparse_info.submit_infos[i].pNext =
                &expanded_bind_sparse_info.timeline_semaphore_infos[tsinfo_it++];
        }
    }

    // For each VkSubmitInfo added to the expanded vkQueueBindSparse, reserve a
    // command buffer and put in the submit.
    // Allocate the required command buffers
    auto num_submits = (uint32_t)expanded_bind_sparse_info.submit_infos.size();

    std::vector<VkCommandBuffer> helper_cbs = AllocHelperCBs(num_submits);
    if (helper_cbs.empty()) {
        // Silently pass the call to the dispatch table.
        result = device_.Dispatch().QueueBindSparse(vk_queue_, bindInfoCount, pBindInfo, fence);
        PostSubmit(result);
        return result;
    }

    uint32_t next_wait_helper_submit = 0;
    for (uint32_t i = 0; i < num_submits; i++) {
        auto& exp_info = expanded_bind_sparse_info.submit_infos[i];
        exp_info.pCommandBuffers = &helper_cbs[i];
        exp_info.commandBufferCount = 1;

        RecordBindSparseHelperSubmit(qbind_sparse_id, &exp_info);

        if (exp_info.signalSemaphoreCount > 0) {
            // Rip out semaphore signal operations from signal helper submit. We
            // needed this info to correctly record the signal semaphore markers, but
            // we don't need the helper submits to signal the semaphores that are
            // already signalled in a bind sparse info.
            exp_info.signalSemaphoreCount = 0;
            exp_info.pSignalSemaphores = nullptr;
            exp_info.pNext = nullptr;
        } else {
            // This is a wait helper submit. We need to signal the wait binary
            // semaphores that the helper submit is waiting on.
            exp_info.signalSemaphoreCount =
                (uint32_t)expanded_bind_sparse_info.wait_binary_semaphores[next_wait_helper_submit].size();
            exp_info.pSignalSemaphores =
                expanded_bind_sparse_info.wait_binary_semaphores[next_wait_helper_submit].data();
            next_wait_helper_submit++;
        }
    }

    uint32_t next_bind_sparse_info_index = 0;
    uint32_t available_bind_sparse_info_counter = 0;
    uint32_t next_submit_info_index = 0;
    VkResult last_bind_result = VK_SUCCESS;
    for (int i = 0; i < expanded_bind_sparse_info.queue_operation_types.size(); i++) {
        if (expanded_bind_sparse_info.queue_operation_types[i] == crash_diagnostic_layer::kQueueSubmit) {
            // Send all the available bind sparse infos before submit info. Signal the
            // fence only if the last bind sparse info is included.
            if (available_bind_sparse_info_counter) {
                VkFence bind_fence = VK_NULL_HANDLE;
                if (bindInfoCount == next_bind_sparse_info_index + available_bind_sparse_info_counter) {
                    bind_fence = fence;
                }
                result = device_.Dispatch().QueueBindSparse(vk_queue_, available_bind_sparse_info_counter,
                                                            &pBindInfo[next_bind_sparse_info_index], bind_fence);
                if (result != VK_SUCCESS) {
                    last_bind_result = result;
                    break;
                }
                next_bind_sparse_info_index += available_bind_sparse_info_counter;
                available_bind_sparse_info_counter = 0;
            }
            // Send the submit info
            result = device_.Dispatch().QueueSubmit(
                vk_queue_, 1, &expanded_bind_sparse_info.submit_infos[next_submit_info_index], VK_NULL_HANDLE);
            if (result != VK_SUCCESS) {
                Log().Warning(
                    "helper vkQueueSubmit failed while tracking semaphores in a vkQueueBindSparse call. Semaphore "
                    "values in the final report might be wrong. Result: 0x%08x",
                    result);
                break;
            }
            next_submit_info_index++;
        } else {
            available_bind_sparse_info_counter++;
        }
    }
    if (last_bind_result != VK_SUCCESS) {
        Log().Warning(
            "QueueBindSparse: Unexpected VkResult = 0x%8x after submitting %d bind sparse infos and %d "
            " helper submit infos to the queue. Submitting the remained bind sparse infos at once.",
            last_bind_result, next_bind_sparse_info_index, next_submit_info_index);
        return device_.Dispatch().QueueBindSparse(vk_queue_, bindInfoCount - next_bind_sparse_info_index,
                                                  &pBindInfo[next_bind_sparse_info_index], fence);
    }
    // If any remaining bind sparse infos, submit them all.
    if (bindInfoCount > next_bind_sparse_info_index + available_bind_sparse_info_counter) {
        return device_.Dispatch().QueueBindSparse(vk_queue_, bindInfoCount - next_submit_info_index,
                                                  &pBindInfo[next_bind_sparse_info_index], fence);
    }
    PostSubmit(last_bind_result);
    return last_bind_result;
}

void Queue::LogSubmitInfoSemaphores(SubmitInfoId submit_info_id) {
    assert(tracking_semaphores_ == true);
    assert(trace_all_semaphores_ == true);
    if (SubmitInfoHasSemaphores(submit_info_id)) {
        std::string semaphore_log = GetSubmitInfoSemaphoresLog(submit_info_id);
        Log().Info(semaphore_log);
    }
}

bool Queue::ShouldExpandQueueBindSparseToTrackSemaphores(PackedBindSparseInfo* packed_bind_sparse_info) {
    assert(tracking_semaphores_ == true);

    packed_bind_sparse_info->semaphore_tracker = device_.GetSemaphoreTracker();
    return BindSparseUtils::ShouldExpandQueueBindSparseToTrackSemaphores(packed_bind_sparse_info);
}

void Queue::ExpandBindSparseInfo(ExpandedBindSparseInfo* bind_sparse_expand_info) {
    return BindSparseUtils::ExpandBindSparseInfo(bind_sparse_expand_info);
}

void Queue::LogBindSparseInfosSemaphores(uint32_t bind_info_count, const VkBindSparseInfo* bind_infos) {
    assert(tracking_semaphores_ == true);
    assert(trace_all_semaphores_ == true);
    auto log = BindSparseUtils::LogBindSparseInfosSemaphores(device_, device_.GetVkDevice(), vk_queue_, bind_info_count,
                                                             bind_infos);
    Log().Info(log);
}

}  // namespace crash_diagnostic_layer
