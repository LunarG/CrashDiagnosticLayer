/*
 Copyright 2020 Google Inc.
 Copyright 2023-2026 LunarG, Inc.

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

#include "marker.h"
#include "cdl.h"
#include "device.h"
#include "dispatch.h"

namespace crash_diagnostic_layer {

struct MarkerData {
    VkBuffer buffer = VK_NULL_HANDLE;
    uint32_t offset = 0;
    void* cpu_mapped_address = nullptr;
};

BufferMarkerMgr::BufferMarkerMgr(Device& device) : device_(device) {
    device_.GetContext().Dispatch().GetPhysicalDeviceMemoryProperties(device_.GetVkGpu(), &memory_properties_);
}

BufferMarkerMgr::~BufferMarkerMgr() {
    VkDevice device = device_.GetVkDevice();
    const auto& dt = device_.Dispatch();

    for (auto& marker_buffer : marker_buffers_) {
        device_.Log().Verbose("Destroy Marker buffer %llx", marker_buffer.buffer);
        dt.DestroyBuffer(device, marker_buffer.buffer, nullptr);
    }
    marker_buffers_.clear();
    if (marker_buffers_heap_ != VK_NULL_HANDLE) {
        device_.Log().Verbose("Destroy Marker memory %llx", marker_buffers_heap_);
        dt.FreeMemory(device, marker_buffers_heap_, nullptr);
        marker_buffers_heap_ = VK_NULL_HANDLE;
    }
}

const DeviceDispatchTable& BufferMarkerMgr::Dispatch() { return device_.Dispatch(); }

static bool FindMemoryType(const VkPhysicalDeviceMemoryProperties* p_mem_props, uint32_t type_bits,
                           VkMemoryPropertyFlags flags, uint32_t* p_index) {
    bool found = false;
    for (uint32_t i = 0; i < p_mem_props->memoryTypeCount; ++i) {
        if (type_bits & 1) {
            if (flags == (p_mem_props->memoryTypes[i].propertyFlags & flags)) {
                if (p_index) {
                    *p_index = i;
                }
                found = true;
                break;
            }
        }
        type_bits >>= 1;
    }
    return found;
}

VkResult BufferMarkerMgr::CreateHostBuffer(VkDeviceSize buffer_size, VkBuffer* p_buffer, VkDeviceSize heap_offset) {
    VkDevice device = device_.GetVkDevice();
    const auto& dt = device_.Dispatch();

    assert(p_buffer != nullptr);
    buffer_size = std::max<VkDeviceSize>(buffer_size, 256);
    if (heap_offset + buffer_size >= kBuffermarkerHeapSize) {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    VkBufferCreateInfo create_info = {};
    create_info.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    create_info.pNext = nullptr;
    create_info.flags = 0;
    create_info.size = buffer_size;
    create_info.usage = VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT;
    create_info.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
    create_info.queueFamilyIndexCount = 0;
    create_info.pQueueFamilyIndices = nullptr;

    VkResult vk_res = dt.CreateBuffer(device, &create_info, nullptr, p_buffer);
    assert(VK_SUCCESS == vk_res);
    if (vk_res != VK_SUCCESS) {
        return vk_res;
    }
    device_.Log().Verbose("Created Marker buffer %s", device_.GetObjectName((uint64_t)*p_buffer).c_str());

    VkMemoryRequirements mem_reqs = {};
    dt.GetBufferMemoryRequirements(device, *p_buffer, &mem_reqs);

    if (marker_buffers_heap_ == VK_NULL_HANDLE) {
        VkMemoryPropertyFlags mem_flags = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT |
                                          VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD;

        uint32_t memory_type_index = UINT32_MAX;
        bool found_memory = FindMemoryType(&memory_properties_, mem_reqs.memoryTypeBits, mem_flags, &memory_type_index);

        if (!found_memory) {
            device_.Log().Warning("No device coherent memory found, results might not be accurate.");

            mem_flags = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT;

            found_memory = FindMemoryType(&memory_properties_, mem_reqs.memoryTypeBits, mem_flags, &memory_type_index);
        }

        assert(found_memory);
        if (!found_memory) {
            dt.DestroyBuffer(device, *p_buffer, nullptr);
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        VkMemoryAllocateInfo alloc_info = {};
        alloc_info.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
        alloc_info.pNext = nullptr;
        alloc_info.allocationSize = kBuffermarkerHeapSize;
        alloc_info.memoryTypeIndex = memory_type_index;
        vk_res = dt.AllocateMemory(device, &alloc_info, nullptr, &marker_buffers_heap_);
        assert(VK_SUCCESS == vk_res);
        if (vk_res != VK_SUCCESS) {
            dt.DestroyBuffer(device, *p_buffer, nullptr);
            return VK_ERROR_INITIALIZATION_FAILED;
        }
        device_.Log().Verbose("Create Marker memory %s", device_.GetObjectName((uint64_t)marker_buffers_heap_).c_str());
    }

    vk_res = dt.BindBufferMemory(device, *p_buffer, marker_buffers_heap_, heap_offset);
    assert(VK_SUCCESS == vk_res);
    if (vk_res != VK_SUCCESS) {
        dt.FreeMemory(device, marker_buffers_heap_, nullptr);
        dt.DestroyBuffer(device, *p_buffer, nullptr);
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    return VK_SUCCESS;
}

VkResult BufferMarkerMgr::AcquireMarkerBuffer() {
    const auto& dt = device_.Dispatch();
    // No need to lock on marker_buffers_mutex_, already locked on callsite.
    MarkerBuffer marker_buffer = {};
    marker_buffer.size = kBufferMarkerBufferSize;
    marker_buffer.heap_offset = current_heap_offset_;
    current_heap_offset_ += kBufferMarkerBufferSize;

    VkResult vk_res = CreateHostBuffer(marker_buffer.size, &marker_buffer.buffer, marker_buffer.heap_offset);
    if (vk_res != VK_SUCCESS) {
        return vk_res;
    }
    VkDevice device = device_.GetVkDevice();
    if (marker_buffers_heap_mapped_base_ == nullptr) {
        vk_res =
            dt.MapMemory(device, marker_buffers_heap_, 0, kBuffermarkerHeapSize, 0, &marker_buffers_heap_mapped_base_);
        assert(VK_SUCCESS == vk_res);
        if (vk_res != VK_SUCCESS) {
            dt.FreeMemory(device, marker_buffers_heap_, nullptr);
            dt.DestroyBuffer(device, marker_buffer.buffer, nullptr);
            return VK_ERROR_INITIALIZATION_FAILED;
        }
    }
    marker_buffer.cpu_mapped_address = (void*)((uintptr_t)marker_buffers_heap_mapped_base_ + marker_buffer.heap_offset);
    marker_buffers_.push_back(marker_buffer);
    return VK_SUCCESS;
}

MarkerDataPtr BufferMarkerMgr::AllocateData(uint32_t num_words) {
    assert(num_words == 1 || num_words == 2);
    std::lock_guard<std::mutex> mlock(marker_buffers_mutex_);
    // Check if we have the required marker already allocated
    auto marker_buffer_index = (current_marker_index_ + (num_words - 1)) / kBufferMarkerEventCount;

    // Out of space, allocate a new buffer
    if (marker_buffer_index >= marker_buffers_.size()) {
        // This causes a glitch if CDL is on while a user plays
        // the game. If CDL goes to be activated for end users, this should be
        // done out of markers_buffers_mutex_ lock in a predictive mode.
        if (AcquireMarkerBuffer() != VK_SUCCESS) {
            return nullptr;
        }
        assert(marker_buffer_index < marker_buffers_.size());
        if (num_words == 2) {
            // Make sure current_marker_index_ is even
            current_marker_index_ = ((current_marker_index_ + 1u) & ~3u);
        }
    }
    auto& marker_buffer = marker_buffers_.back();
    auto data = std::make_unique<MarkerData>();
    data->buffer = marker_buffer.buffer;
    data->offset = (current_marker_index_ % kBufferMarkerEventCount) * sizeof(uint32_t);
    data->cpu_mapped_address = (void*)((uintptr_t)marker_buffer.cpu_mapped_address + data->offset);
    current_marker_index_ += num_words;
    return data;
}

std::unique_ptr<Marker> BufferMarkerMgr::Allocate(uint32_t initial_value) {
    std::unique_ptr<Marker> marker;
    // If there is a recycled marker, use it.
    {
        std::lock_guard<std::mutex> lock(recycled_markers_u32_mutex_);
        if (recycled_markers_u32_.size() > 0) {
            marker = std::make_unique<Marker>(*this, std::move(recycled_markers_u32_.back()), initial_value);
            recycled_markers_u32_.pop_back();
            return marker;
        }
    }
    auto data = AllocateData(1);
    if (data) {
        marker = std::make_unique<Marker>(*this, std::move(data), initial_value);
    }
    return marker;
}

std::unique_ptr<Marker64> BufferMarkerMgr::Allocate(uint64_t initial_value) {
    std::unique_ptr<Marker64> marker;
    // If there is a recycled marker, use it.
    {
        std::lock_guard<std::mutex> lock(recycled_markers_u64_mutex_);
        if (recycled_markers_u64_.size() > 0) {
            marker = std::make_unique<Marker64>(*this, std::move(recycled_markers_u64_.back()), initial_value);
            recycled_markers_u64_.pop_back();
            return marker;
        }
    }
    auto data = AllocateData(2);
    if (data) {
        marker = std::make_unique<Marker64>(*this, std::move(data), initial_value);
    }
    return marker;
}

void BufferMarkerMgr::Free(Marker& marker) {
    if (marker.data_) {
        std::lock_guard<std::mutex> lock(recycled_markers_u32_mutex_);
        recycled_markers_u32_.emplace_back(std::move(marker.data_));
        marker.data_.reset();
    }
}

void BufferMarkerMgr::Free(Marker64& marker) {
    if (marker.data_) {
        std::lock_guard<std::mutex> lock(recycled_markers_u64_mutex_);
        recycled_markers_u64_.emplace_back(std::move(marker.data_));
        marker.data_.reset();
    }
}

Marker::Marker(BufferMarkerMgr& mgr, MarkerDataPtr&& data, uint32_t initial_value) : mgr_(mgr), data_(std::move(data)) {
    Write(initial_value);
}

Marker::~Marker() { mgr_.Free(*this); }

void Marker::Write(VkCommandBuffer cmd, VkPipelineStageFlagBits stage, uint32_t value) {
    mgr_.Dispatch().CmdWriteBufferMarkerAMD(cmd, stage, data_->buffer, data_->offset, value);
}

void Marker::Write(uint32_t value) { *(uint32_t*)data_->cpu_mapped_address = value; }

uint32_t Marker::Read() const { return *(uint32_t*)data_->cpu_mapped_address; }

Marker64::Marker64(BufferMarkerMgr& mgr, MarkerDataPtr&& data, uint64_t initial_value)
    : mgr_(mgr), data_(std::move(data)) {
    Write(initial_value);
}

Marker64::~Marker64() { mgr_.Free(*this); }

void Marker64::Write(VkCommandBuffer cmd, VkPipelineStageFlagBits stage, uint64_t value) {
    uint32_t u32_value = value & 0xffffffff;
    mgr_.Dispatch().CmdWriteBufferMarkerAMD(cmd, stage, data_->buffer, data_->offset, u32_value);
    u32_value = value >> 32;
    mgr_.Dispatch().CmdWriteBufferMarkerAMD(cmd, stage, data_->buffer, data_->offset + sizeof(uint32_t), u32_value);
}

void Marker64::Write(uint64_t value) { *(uint64_t*)data_->cpu_mapped_address = value; }

uint64_t Marker64::Read() const { return *(uint64_t*)data_->cpu_mapped_address; }

}  // namespace crash_diagnostic_layer
