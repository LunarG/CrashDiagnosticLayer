/*
 Copyright 2024 LunarG, Inc.

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

#include "checkpoint.h"
#include "device.h"
#include "logger.h"

#include <cassert>
#include <vulkan/utility/vk_struct_helper.hpp>

namespace crash_diagnostic_layer {

Checkpoint::Checkpoint(CheckpointMgr *mgr, CheckpointId id) : mgr_(mgr), id_(id) {}

Checkpoint::~Checkpoint() {
    if (mgr_) {
        mgr_->Free(*this);
        mgr_ = nullptr;
        id_ = kInvalidCheckpoint;
    }
}

void Checkpoint::WriteTop(VkCommandBuffer cmd, uint32_t value) { mgr_->WriteTop(*this, cmd, value); }
void Checkpoint::WriteBottom(VkCommandBuffer cmd, uint32_t value) { mgr_->WriteBottom(*this, cmd, value); }

uint32_t Checkpoint::ReadTop() const { return mgr_->ReadTop(*this); }
uint32_t Checkpoint::ReadBottom() const { return mgr_->ReadBottom(*this); }

void Checkpoint::Reset() { mgr_->Reset(*this); }

BufferMarkerCheckpointMgr::BufferMarkerCheckpointMgr(Device &device) : markers_(device) {}

std::unique_ptr<Checkpoint> BufferMarkerCheckpointMgr::Allocate(uint32_t initial_value) {
    auto checkpoint = std::make_unique<Checkpoint>(this, next_id_++);
    Data data;
    data.top_marker = markers_.Allocate(initial_value);
    data.bottom_marker = markers_.Allocate(initial_value);
    if (!data.top_marker || !data.bottom_marker) {
        return nullptr;
    }
    std::lock_guard<std::mutex> lock(checkpoint_mutex_);
    checkpoint_data_.emplace(std::make_pair(checkpoint->Id(), std::move(data)));
    return checkpoint;
}

void BufferMarkerCheckpointMgr::Free(Checkpoint &c) {
    std::lock_guard<std::mutex> lock(checkpoint_mutex_);
    checkpoint_data_.erase(c.Id());
}

void BufferMarkerCheckpointMgr::WriteTop(Checkpoint &c, VkCommandBuffer cmd, uint32_t value) {
    std::lock_guard<std::mutex> lock(checkpoint_mutex_);

    auto iter = checkpoint_data_.find(c.Id());
    assert(iter != checkpoint_data_.end());
    iter->second.top_marker->Write(cmd, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, value);
}

void BufferMarkerCheckpointMgr::WriteBottom(Checkpoint &c, VkCommandBuffer cmd, uint32_t value) {
    std::lock_guard<std::mutex> lock(checkpoint_mutex_);
    auto iter = checkpoint_data_.find(c.Id());
    assert(iter != checkpoint_data_.end());
    iter->second.bottom_marker->Write(cmd, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, value);
}

uint32_t BufferMarkerCheckpointMgr::ReadTop(const Checkpoint &c) const {
    std::lock_guard<std::mutex> lock(checkpoint_mutex_);
    auto iter = checkpoint_data_.find(c.Id());
    assert(iter != checkpoint_data_.end());
    return iter->second.top_marker->Read();
}

uint32_t BufferMarkerCheckpointMgr::ReadBottom(const Checkpoint &c) const {
    std::lock_guard<std::mutex> lock(checkpoint_mutex_);
    auto iter = checkpoint_data_.find(c.Id());
    assert(iter != checkpoint_data_.end());
    return iter->second.bottom_marker->Read();
}

void BufferMarkerCheckpointMgr::Reset(Checkpoint &c) {
    std::lock_guard<std::mutex> lock(checkpoint_mutex_);
    auto iter = checkpoint_data_.find(c.Id());
    assert(iter != checkpoint_data_.end());
    iter->second.top_marker->Write(0);
    iter->second.bottom_marker->Write(0);
}

DiagnosticCheckpointMgr::DiagnosticCheckpointMgr(Device &device) : device_(device) {}

std::unique_ptr<Checkpoint> DiagnosticCheckpointMgr::Allocate(uint32_t initial_value) {
    auto checkpoint = std::make_unique<Checkpoint>(this, next_id_++);
    Data data;
    data.top_value = initial_value;
    data.bottom_value = initial_value;
    std::lock_guard<std::mutex> lock(checkpoint_mutex_);
    checkpoint_data_.emplace(std::make_pair(checkpoint->Id(), std::move(data)));
    return checkpoint;
}

void DiagnosticCheckpointMgr::Free(Checkpoint &c) {
    std::lock_guard<std::mutex> lock(checkpoint_mutex_);
    checkpoint_data_.erase(c.Id());
}

// NV checkpoints are both top and bottom markers.
void DiagnosticCheckpointMgr::WriteTop(Checkpoint &c, VkCommandBuffer cmd, uint32_t value) {}

void DiagnosticCheckpointMgr::WriteBottom(Checkpoint &c, VkCommandBuffer cmd, uint32_t value) {
    uintptr_t checkpoint = (uintptr_t(c.Id()) << kIdShift) | value;
    device_.Dispatch().CmdSetCheckpointNV(cmd, (void *)checkpoint);
}

uint32_t DiagnosticCheckpointMgr::ReadTop(const Checkpoint &c) const {
    std::lock_guard<std::mutex> lock(checkpoint_mutex_);
    auto iter = checkpoint_data_.find(c.Id());
    assert(iter != checkpoint_data_.end());
    return iter->second.top_value;
}

uint32_t DiagnosticCheckpointMgr::ReadBottom(const Checkpoint &c) const {
    std::lock_guard<std::mutex> lock(checkpoint_mutex_);
    auto iter = checkpoint_data_.find(c.Id());
    assert(iter != checkpoint_data_.end());
    return iter->second.bottom_value;
}

void DiagnosticCheckpointMgr::Reset(Checkpoint &c) {
    std::lock_guard<std::mutex> lock(checkpoint_mutex_);
    auto iter = checkpoint_data_.find(c.Id());
    assert(iter != checkpoint_data_.end());
    iter->second.top_value = 0;
    iter->second.bottom_value = 0;
}

void DiagnosticCheckpointMgr::Update() {
    auto queues = device_.GetAllQueues();
    for (auto &q : queues) {
        device_.Log().Verbose("DiagnosticCheckpointMgr::Update queue %x begin", q->GetVkQueue());
        std::vector<VkCheckpointDataNV> checkpoints;
        uint32_t num = 0;

        device_.Dispatch().GetQueueCheckpointDataNV(q->GetVkQueue(), &num, nullptr);
        if (num == 0) {
            continue;
        }
        checkpoints.resize(num, vku::InitStruct<VkCheckpointDataNV>());
        device_.Dispatch().GetQueueCheckpointDataNV(q->GetVkQueue(), &num, checkpoints.data());
        for (const auto &cp : checkpoints) {
            auto checkpoint = reinterpret_cast<uintptr_t>(cp.pCheckpointMarker);
            auto id = static_cast<uint32_t>(checkpoint >> kIdShift);
            auto value = static_cast<uint32_t>(checkpoint & kValueMask);

            device_.Log().Verbose("checkpoint 0x%16x id=0x%x value=%d stage=%s", checkpoint, id, value,
                                  (cp.stage == VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT ? "bottom" : "top"));
            // TODO lock?
            auto iter = checkpoint_data_.find(id);
            if (iter == checkpoint_data_.end()) {
                continue;
            }

            if (cp.stage == VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT) {
                iter->second.top_value = value;
            } else if (cp.stage == VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT) {
                iter->second.bottom_value = value;
            } else {
                assert(false);
            }
        }
        device_.Log().Verbose("DiagnosticCheckpointMgr::Update queue %x end", q->GetVkQueue());
    }
}

}  // namespace crash_diagnostic_layer
