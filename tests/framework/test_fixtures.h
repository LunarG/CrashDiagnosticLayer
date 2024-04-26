/*
 * Copyright (c) 2024 The Khronos Group Inc.
 * Copyright (c) 2024 Valve Corporation
 * Copyright (c) 2024 LunarG, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <gtest/gtest.h>
#include <vulkan/vulkan_raii.hpp>
#include "error_monitor.h"
// #include "layer_settings.h"

struct BoundBuffer {
    vk::raii::Buffer buffer;
    vk::raii::DeviceMemory memory;

    template <typename T>
    void set(const T& value, size_t num_elements) {
        T* mem = reinterpret_cast<T*>(memory.mapMemory(0, vk::WholeSize));
        for (size_t i = 0; i < num_elements; i++) {
            mem[i] = value;
        }
        memory.unmapMemory();
    }
};

class CDLTestBase : public ::testing::Test {
   public:
    CDLTestBase()
        : monitor_("CDL", false),
          instance_(VK_NULL_HANDLE),
          physical_device_(VK_NULL_HANDLE),
          device_(VK_NULL_HANDLE),
          compute_queue_(VK_NULL_HANDLE),
          cmd_pool_(VK_NULL_HANDLE),
          cmd_buff_(VK_NULL_HANDLE) {}
    ~CDLTestBase() {}
    void InitInstance();
    void InitDevice(std::vector<const char*> extensions = {},
                    const vk::PhysicalDeviceFeatures2 *features2 = nullptr);

    template <typename T>
    void SetObjectName(T& object, const std::string& name) {
        vk::DebugUtilsObjectNameInfoEXT info(T::objectType, reinterpret_cast<uint64_t>(typename T::CType(*object)),
                                             name.c_str());
        device_.setDebugUtilsObjectNameEXT(info);
    }
    static constexpr vk::MemoryPropertyFlags kMemoryFlags =
        vk::MemoryPropertyFlagBits::eHostVisible | vk::MemoryPropertyFlagBits::eHostCoherent;
    static constexpr vk::MemoryPropertyFlags kMemoryForbid = vk::MemoryPropertyFlagBits::eProtected;

    uint32_t FindMemoryType(const vk::MemoryRequirements& reqs, vk::MemoryPropertyFlags flags,
                            vk::MemoryPropertyFlags forbid);

    BoundBuffer AllocateMemory(vk::DeviceSize size, const std::string& name, vk::BufferUsageFlags usage,
                               vk::MemoryAllocateFlags alloc_flags = {},
                               vk::MemoryPropertyFlags flags = kMemoryFlags,
                               vk::MemoryPropertyFlags forbid = kMemoryForbid);

    vk::raii::ShaderModule CreateShaderModuleGLSL(const char* src, vk::ShaderStageFlagBits stage);

    vk::raii::Context context_;
    ErrorMonitor monitor_;
    // LayerSettings settings_;
    vk::raii::Instance instance_;

    vk::raii::PhysicalDevice physical_device_;
    vk::raii::Device device_;

    uint32_t compute_qfi_{~0u};
    vk::raii::Queue compute_queue_;

    vk::raii::CommandPool cmd_pool_;
    vk::raii::CommandBuffer cmd_buff_;
};

class GpuCrash : public CDLTestBase {};
