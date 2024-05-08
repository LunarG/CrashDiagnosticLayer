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

#include "semaphore_tracker.h"

#include <cstring>
#include <iomanip>
#include <sstream>

#include "device.h"
#include "cdl.h"
#include "logger.h"

namespace crash_diagnostic_layer {

SemaphoreModifierInfo SemaphoreTracker::SemaphoreInfo::GetLastModifier(Device& device) {
    SemaphoreModifierInfo last_modifier;
    last_modifier.type = static_cast<SemaphoreModifierType>(last_type->Read());
    last_modifier.id = last_id->Read();
    return last_modifier;
}
void SemaphoreTracker::SemaphoreInfo::UpdateLastModifier(Device& device, SemaphoreModifierInfo modifier_info) {
    last_type->Write(modifier_info.type);
    last_id->Write(modifier_info.id);
}

SemaphoreTracker::SemaphoreTracker(Device& device, bool track_semaphores_last_setter)
    : device_(device), markers_(device), track_semaphores_last_setter_(track_semaphores_last_setter) {}

const Logger& SemaphoreTracker::Log() const { return device_.Log(); }

void SemaphoreTracker::RegisterSemaphore(VkSemaphore vk_semaphore, VkSemaphoreTypeKHR type, uint64_t value) {
    {
        std::lock_guard<std::mutex> lock(semaphores_mutex_);
        semaphores_.erase(vk_semaphore);
    }
    // Create a new semaphore info and add it to the semaphores container
    SemaphoreInfo semaphore_info = {};
    semaphore_info.semaphore_type = type;
    semaphore_info.marker = markers_.Allocate(uint64_t(0));
    //  Reserve a marker to track semaphore value
    if (!semaphore_info.marker) {
        device_.Log().Error("Cannot acquire marker. Not tracking semaphore %s.",
                            device_.GetObjectName((uint64_t)vk_semaphore).c_str());
        return;
    }
    if (track_semaphores_last_setter_) {
        semaphore_info.last_type = markers_.Allocate(uint32_t(0));
        semaphore_info.last_id = markers_.Allocate(uint32_t(0));
        if (!semaphore_info.last_type || !semaphore_info.last_id) {
            device_.Log().Error("Cannot acquire modifier tracking marker. Not tracking semaphore %s.",
                                device_.GetObjectName((uint64_t)vk_semaphore).c_str());
            return;
        }
    }

    {
        std::lock_guard<std::mutex> lock(semaphores_mutex_);
        semaphores_[vk_semaphore] = std::move(semaphore_info);
    }
    device_.GetSemaphoreTracker()->SignalSemaphore(vk_semaphore, value, {SemaphoreModifierType::kNotModified});
}

void SemaphoreTracker::SignalSemaphore(VkSemaphore vk_semaphore, uint64_t value, SemaphoreModifierInfo modifier_info) {
    std::lock_guard<std::mutex> slock(semaphores_mutex_);
    if (semaphores_.find(vk_semaphore) != semaphores_.end()) {
        auto& semaphore_info = semaphores_[vk_semaphore];
        semaphore_info.marker->Write(value);
        if (track_semaphores_last_setter_) {
            semaphore_info.UpdateLastModifier(device_, modifier_info);
        }
    } else {
        device_.Log().Error("Unknown semaphore signaled: %s", device_.GetObjectName((uint64_t)vk_semaphore).c_str());
    }
}

void SemaphoreTracker::EraseSemaphore(VkSemaphore vk_semaphore) {
    std::lock_guard<std::mutex> lock(semaphores_mutex_);
    semaphores_.erase(vk_semaphore);
}

void SemaphoreTracker::BeginWaitOnSemaphores(int pid, int tid, const VkSemaphoreWaitInfoKHR* pWaitInfo) {
    WaitingThreadInfo waiting_thread_info;
    waiting_thread_info.pid = pid;
    waiting_thread_info.tid = tid;
    waiting_thread_info.wait_type = SemaphoreWaitType::kAll;
    if (pWaitInfo->flags & VK_SEMAPHORE_WAIT_ANY_BIT_KHR) {
        waiting_thread_info.wait_type = SemaphoreWaitType::kAny;
    }
    for (uint32_t i = 0; i < pWaitInfo->semaphoreCount; i++) {
        waiting_thread_info.semaphores.push_back(pWaitInfo->pSemaphores[i]);
        waiting_thread_info.wait_values.push_back(pWaitInfo->pValues[i]);
    }
    std::lock_guard<std::mutex> lock(waiting_threads_mutex_);
    waiting_threads_.push_back(waiting_thread_info);
}

void SemaphoreTracker::EndWaitOnSemaphores(int pid, int tid, const VkSemaphoreWaitInfoKHR* pWaitInfo) {
    std::lock_guard<std::mutex> lock(waiting_threads_mutex_);
    for (auto it = waiting_threads_.begin(); it != waiting_threads_.end(); it++) {
        if (it->pid == pid && it->tid == tid) {
            waiting_threads_.erase(it);
            return;
        }
    }
}

bool SemaphoreTracker::GetSemaphoreValue(VkSemaphore vk_semaphore, uint64_t& value) const {
    std::lock_guard<std::mutex> slock(semaphores_mutex_);
    if (semaphores_.find(vk_semaphore) == semaphores_.end()) return false;
    auto& semaphore_info = semaphores_.find(vk_semaphore)->second;
    return semaphore_info.marker->Read();
}

VkSemaphoreTypeKHR SemaphoreTracker::GetSemaphoreType(VkSemaphore vk_semaphore) const {
    VkSemaphoreTypeKHR semaphore_type = VK_SEMAPHORE_TYPE_BINARY_KHR;
    std::lock_guard<std::mutex> lock(semaphores_mutex_);
    if (semaphores_.find(vk_semaphore) != semaphores_.end())
        semaphore_type = semaphores_.find(vk_semaphore)->second.semaphore_type;
    return semaphore_type;
}

void SemaphoreTracker::WriteMarker(VkSemaphore vk_semaphore, VkCommandBuffer vk_command_buffer,
                                   VkPipelineStageFlagBits vk_pipeline_stage, uint64_t value,
                                   SemaphoreModifierInfo modifier_info) {
    std::lock_guard<std::mutex> slock(semaphores_mutex_);
    if (semaphores_.find(vk_semaphore) == semaphores_.end()) return;
    auto& semaphore_info = semaphores_[vk_semaphore];
    semaphore_info.marker->Write(vk_command_buffer, vk_pipeline_stage, value);

    if (track_semaphores_last_setter_) {
        semaphore_info.last_type->Write(vk_command_buffer, vk_pipeline_stage, modifier_info.type);
        semaphore_info.last_id->Write(vk_command_buffer, vk_pipeline_stage, modifier_info.id);
    }
}

std::vector<TrackedSemaphoreInfo> SemaphoreTracker::GetTrackedSemaphoreInfos(const std::vector<SemInfo>& semaphores) {
    std::vector<TrackedSemaphoreInfo> tracked_semaphores;
    std::lock_guard<std::mutex> lock(semaphores_mutex_);
    for (uint32_t i = 0; i < semaphores.size(); i++) {
        if (semaphores_.find(semaphores[i].handle) == semaphores_.end()) continue;
        auto& semaphore_info = semaphores_[semaphores[i].handle];
        TrackedSemaphoreInfo tracked_semaphore;
        tracked_semaphore.semaphore = semaphores[i].handle;
        tracked_semaphore.semaphore_type = semaphore_info.semaphore_type;
        tracked_semaphore.semaphore_operation_value = semaphores[i].value;
        tracked_semaphore.current_value = semaphore_info.marker->Read();
        tracked_semaphore.current_value_available = true;
        if (track_semaphores_last_setter_) {
            tracked_semaphore.last_modifier = semaphore_info.GetLastModifier(device_);
        }
        tracked_semaphores.push_back(tracked_semaphore);
    }
    return tracked_semaphores;
}

std::string SemaphoreTracker::PrintTrackedSemaphoreInfos(const std::vector<TrackedSemaphoreInfo>& tracked_semaphores,
                                                         const char* tab) const {
    std::stringstream log;
    log << tab << std::setfill(' ') << std::left << std::setw(24) << "Semaphore" << std::left << std::setw(12) << "Type"
        << std::left << std::setw(18) << std::left << std::setw(18) << "Operation value" << std::left << std::setw(18)
        << "Last known value"
        << "Last modifier" << std::endl;
    for (auto it = tracked_semaphores.begin(); it != tracked_semaphores.end(); it++) {
        log << tab << std::left << std::setw(24) << device_.GetObjectName((uint64_t)it->semaphore, kPreferDebugName);
        if (it->semaphore_type == VK_SEMAPHORE_TYPE_BINARY_KHR) {
            log << std::setfill(' ') << std::left << std::setw(12) << "Binary";
        } else {
            log << std::setfill(' ') << std::left << std::setw(12) << "Timeline";
        }
        log << std::left << std::setw(18) << it->semaphore_operation_value;
        if (it->current_value_available) {
            log << std::setfill(' ') << std::left << std::setw(18) << it->current_value;
        } else {
            log << std::setfill(' ') << std::left << std::setw(18) << "NA";
        }
        switch (it->last_modifier.type) {
            case kModifierHost:
                log << "Host";
                break;
            case kModifierQueueSubmit:
                log << "QueueSubmit, Id: " << it->last_modifier.id;
                break;
            case kModifierQueueBindSparse:
                log << "QueueBindSparse, Id: " << it->last_modifier.id;
                break;
            default:
                log << "Not modified";
        }
        log << std::endl;
    }
    return log.str();
}

void SemaphoreTracker::DumpWaitingThreads(YAML::Emitter& os) const {
    std::lock_guard<std::mutex> lock(waiting_threads_mutex_);
    if (waiting_threads_.size() == 0) {
        return;
    }

    os << YAML::Key << "WaitingThreads" << YAML::Value << YAML::BeginSeq;
    uint64_t semaphore_value = 0;
    for (auto& it : waiting_threads_) {
        os << YAML::BeginMap;
        os << YAML::Key << "PID" << YAML::Value << it.pid;
        os << YAML::Key << "TID" << YAML::Value << it.tid;
        os << YAML::Key << "waitType" << YAML::Value
           << ((it.wait_type == SemaphoreWaitType::kAll) ? "WaitForAll" : "WaitForAny");
        os << YAML::Key << "WaitSemaphores" << YAML::Value << YAML::BeginSeq;
        for (int i = 0; i < it.semaphores.size(); i++) {
            os << YAML::BeginMap;
            os << YAML::Key << "handle" << YAML::Value << device_.GetObjectInfo((uint64_t)it.semaphores[i]);
            os << YAML::Key << "type" << YAML::Value << "Timeline";
            os << YAML::Key << "value" << YAML::Value << it.wait_values[i];
            if (GetSemaphoreValue(it.semaphores[i], semaphore_value)) {
                os << YAML::Key << "lastValue" << YAML::Value << semaphore_value;
            }
            os << YAML::EndMap;
        }
        os << YAML::EndSeq << YAML::EndMap;
    }
    os << YAML::EndSeq;
}

}  // namespace crash_diagnostic_layer
