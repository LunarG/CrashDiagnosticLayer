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

#pragma once

#include <memory>
#include <limits>

#include <vulkan/vulkan.h>
#include <vulkan/utility/vk_concurrent_unordered_map.hpp>

namespace crash_diagnostic_layer {

class BufferMarkerMgr;
class Device;
struct DeviceDispatchTable;
struct MarkerData;

using MarkerDataPtr = std::unique_ptr<MarkerData>;

constexpr VkDeviceSize kBufferMarkerEventCount = 1024;

using MarkerId = uint32_t;
constexpr MarkerId kInvalidId = std::numeric_limits<uint32_t>::max();

class Marker {
    friend class BufferMarkerMgr;

   public:
    Marker(BufferMarkerMgr &mgr, MarkerDataPtr &&data, uint32_t initial_value);
    Marker(Marker &) = delete;
    Marker &operator=(Marker &) = delete;
    ~Marker();

    void Write(VkCommandBuffer cmd, VkPipelineStageFlagBits stage, uint32_t value);
    void Write(uint32_t value);
    uint32_t Read() const;

   private:
    BufferMarkerMgr &mgr_;
    MarkerDataPtr data_;
};

class Marker64 {
    friend class BufferMarkerMgr;

   public:
    Marker64(BufferMarkerMgr &mgr, MarkerDataPtr &&data, uint64_t initial_value);
    Marker64(Marker64 &) = delete;
    Marker64 &operator=(Marker64 &) = delete;
    ~Marker64();

    void Write(VkCommandBuffer cmd, VkPipelineStageFlagBits stage, uint64_t value);
    void Write(uint64_t value);
    uint64_t Read() const;

   private:
    BufferMarkerMgr &mgr_;
    MarkerDataPtr data_;
};

class BufferMarkerMgr {
   public:
    BufferMarkerMgr(Device &);
    BufferMarkerMgr(BufferMarkerMgr &) = delete;
    BufferMarkerMgr &operator=(BufferMarkerMgr &) = delete;
    ~BufferMarkerMgr();

    std::unique_ptr<Marker> Allocate(uint32_t initial_value = 0);
    void Free(Marker &);

    std::unique_ptr<Marker64> Allocate(uint64_t initial_value = 0);
    void Free(Marker64 &);

    const DeviceDispatchTable &Dispatch();

   private:
    static constexpr VkDeviceSize kBufferMarkerBufferSize = kBufferMarkerEventCount * sizeof(uint32_t);
    static constexpr VkDeviceSize kBuffermarkerHeapSize = 64 * 1024 * 1024;

    VkResult AcquireMarkerBuffer();
    VkResult CreateHostBuffer(VkDeviceSize buffer_size, VkBuffer *p_buffer, VkDeviceSize heap_offset);

    MarkerDataPtr AllocateData(uint32_t num_words);

    struct MarkerBuffer {
        VkDeviceSize size{0};
        VkBuffer buffer{VK_NULL_HANDLE};
        void *cpu_mapped_address{nullptr};
        VkDeviceSize heap_offset{0};
    };

    Device &device_;

    std::mutex recycled_markers_u32_mutex_;
    std::vector<MarkerDataPtr> recycled_markers_u32_;

    std::mutex recycled_markers_u64_mutex_;
    std::vector<MarkerDataPtr> recycled_markers_u64_;

    std::mutex marker_buffers_mutex_;
    std::vector<MarkerBuffer> marker_buffers_;
    uint32_t current_marker_index_{0};

    VkDeviceMemory marker_buffers_heap_{VK_NULL_HANDLE};
    void *marker_buffers_heap_mapped_base_{nullptr};
    VkDeviceSize current_heap_offset_{0};
    VkPhysicalDeviceMemoryProperties memory_properties_{};
};

};  // namespace crash_diagnostic_layer
