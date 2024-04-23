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

#pragma once

#include "marker.h"

namespace crash_diagnostic_layer {

class CheckpointMgr;

using CheckpointId = uint32_t;
constexpr uint32_t kInvalidCheckpoint = ~0u;

class Checkpoint {
   public:
    Checkpoint(CheckpointMgr *mgr, MarkerId id);
    ~Checkpoint();

    void WriteTop(VkCommandBuffer cmd, uint32_t value);
    void WriteBottom(VkCommandBuffer cmd, uint32_t value);
    uint32_t ReadTop() const;
    uint32_t ReadBottom() const;

    CheckpointId Id() const { return id_; }

   private:
    CheckpointMgr *mgr_;
    CheckpointId id_;
};

class CheckpointMgr {
   public:
    virtual std::unique_ptr<Checkpoint> Allocate(uint32_t initial_value) = 0;
    virtual void Free(Checkpoint &) = 0;
    virtual void WriteTop(Checkpoint &, VkCommandBuffer cmd, uint32_t value) = 0;
    virtual void WriteBottom(Checkpoint &, VkCommandBuffer cmd, uint32_t value) = 0;
    virtual uint32_t ReadTop(const Checkpoint &) const = 0;
    virtual uint32_t ReadBottom(const Checkpoint &) const = 0;
    virtual void Update() {}
};

class BufferMarkerCheckpointMgr : public CheckpointMgr {
   public:
    BufferMarkerCheckpointMgr(Device &device);
    BufferMarkerCheckpointMgr(BufferMarkerCheckpointMgr &) = delete;
    BufferMarkerCheckpointMgr &operator=(BufferMarkerCheckpointMgr &) = delete;

    std::unique_ptr<Checkpoint> Allocate(uint32_t initial_value) override;
    void Free(Checkpoint &) override;
    void WriteTop(Checkpoint &, VkCommandBuffer cmd, uint32_t value) override;
    void WriteBottom(Checkpoint &, VkCommandBuffer cmd, uint32_t value) override;
    uint32_t ReadTop(const Checkpoint &) const override;
    uint32_t ReadBottom(const Checkpoint &) const override;

   private:
    struct Data {
        std::unique_ptr<Marker> top_marker, bottom_marker;
    };

    Device &device_;
    BufferMarkerMgr markers_;

    std::unordered_map<CheckpointId, Data> checkpoint_data_;
    uint32_t next_id_{1};
};

class DiagnosticCheckpointMgr : public CheckpointMgr {
   public:
    DiagnosticCheckpointMgr(Device &device);
    DiagnosticCheckpointMgr(DiagnosticCheckpointMgr &) = delete;
    DiagnosticCheckpointMgr &operator=(DiagnosticCheckpointMgr &) = delete;

    std::unique_ptr<Checkpoint> Allocate(uint32_t initial_value) override;
    void Free(Checkpoint &) override;
    void WriteTop(Checkpoint &, VkCommandBuffer cmd, uint32_t value) override;
    void WriteBottom(Checkpoint &, VkCommandBuffer cmd, uint32_t value) override;
    uint32_t ReadTop(const Checkpoint &) const override;
    uint32_t ReadBottom(const Checkpoint &) const override;
    void Update() override;

   private:
    static constexpr uintptr_t kIdShift = (sizeof(uintptr_t) * 8 / 2);
    static constexpr uintptr_t kValueMask = ((uintptr_t(1) << kIdShift) - 1);

    struct Data {
        uint32_t top_value, bottom_value;
    };

    Device &device_;
    std::unordered_map<CheckpointId, Data> checkpoint_data_;
    uint32_t next_id_{1};
};

}  // namespace crash_diagnostic_layer
