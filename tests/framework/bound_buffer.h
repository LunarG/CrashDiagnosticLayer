/*
 * Copyright (c) 2023-2024 The Khronos Group Inc.
 * Copyright (c) 2023-2024 Valve Corporation
 * Copyright (c) 2023-2024 LunarG, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 */

#pragma once

#include <vulkan/vulkan_raii.hpp>

struct BoundBuffer {
    static constexpr vk::MemoryPropertyFlags kMemoryFlags =
        vk::MemoryPropertyFlagBits::eHostVisible | vk::MemoryPropertyFlagBits::eHostCoherent;
    static constexpr vk::MemoryPropertyFlags kMemoryForbid = vk::MemoryPropertyFlagBits::eProtected;

    BoundBuffer(vk::raii::PhysicalDevice& phys_dev, vk::raii::Device& device, vk::DeviceSize size,
                const std::string& name, vk::BufferUsageFlags usage, vk::MemoryAllocateFlags alloc_flags = {},
                vk::MemoryPropertyFlags flags = kMemoryFlags, vk::MemoryPropertyFlags forbid = kMemoryForbid);

    static uint32_t FindMemoryType(vk::raii::PhysicalDevice& phys_dev, const vk::MemoryRequirements& reqs,
                                   vk::MemoryPropertyFlags flags, vk::MemoryPropertyFlags forbid);

    template <typename T>
    void Set(const T& value, size_t num_elements) {
        T* mem = reinterpret_cast<T*>(memory.mapMemory(0, vk::WholeSize));
        for (size_t i = 0; i < num_elements; i++) {
            mem[i] = value;
        }
        memory.unmapMemory();
    }

    VkDeviceAddress GetAddress(const vk::raii::Device& dev);

    vk::raii::Buffer buffer;
    vk::raii::DeviceMemory memory;
};
