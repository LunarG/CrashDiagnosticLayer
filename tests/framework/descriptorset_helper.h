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

#include <optional>
#include <vector>

class DescriptorSetHelper {
   public:
    typedef std::vector<vk::DescriptorSetLayoutBinding> Bindings;
    DescriptorSetHelper(vk::raii::Device &device, const Bindings &bindings,
                        vk::DescriptorSetLayoutCreateFlags layout_flags = {}, void *layout_pnext = nullptr,
                        vk::DescriptorPoolCreateFlags poolFlags = vk::DescriptorPoolCreateFlagBits::eFreeDescriptorSet, void *allocate_pnext = nullptr,
                        void *create_pool_pnext = nullptr);

    vk::DescriptorSet Set() { return *set_; }
    vk::DescriptorSetLayout Layout() { return *layout_; }

    void Clear();
    void WriteDescriptorBufferInfo(int binding, vk::Buffer buffer, vk::DeviceSize offset, vk::DeviceSize range,
                                   vk::DescriptorType descriptorType = vk::DescriptorType::eUniformBuffer,
                                   uint32_t arrayElement = 0);
    void WriteDescriptorBufferView(int binding, vk::BufferView buffer_view,
                                   vk::DescriptorType descriptorType = vk::DescriptorType::eStorageTexelBuffer,
                                   uint32_t arrayElement = 0);
    void WriteDescriptorImageInfo(int binding, vk::ImageView image_view, vk::Sampler sampler,
                                  vk::DescriptorType descriptorType = vk::DescriptorType::eCombinedImageSampler,
                                  vk::ImageLayout imageLayout = vk::ImageLayout::eShaderReadOnlyOptimal,
                                  uint32_t arrayElement = 0);
    void WriteDescriptorAccelStruct(int binding, uint32_t accelerationStructureCount,
                                    const vk::AccelerationStructureKHR *pAccelerationStructures,
                                    uint32_t arrayElement = 0);
    void UpdateDescriptorSets();

   private:
    void AddDescriptorWrite(uint32_t binding, uint32_t array_element, vk::DescriptorType descriptor_type,
                            uint32_t descriptor_count = 1);

    vk::raii::Device &device_;
    vk::raii::DescriptorPool pool_;
    vk::raii::DescriptorSetLayout layout_;
    vk::raii::DescriptorSet set_;

    // Only one member of ResourceInfo object contains a value.
    // The pointers to Image/Buffer/BufferView info structures can't be stored in 'descriptor_writes'
    // during WriteDescriptor call, because subsequent calls can reallocate which invalidates stored pointers.
    // When UpdateDescriptorSets is called it's safe to initialize the pointers.
    struct ResourceInfo {
        std::optional<vk::DescriptorImageInfo> image_info;
        std::optional<vk::DescriptorBufferInfo> buffer_info;
        std::optional<vk::BufferView> buffer_view;
        std::optional<vk::WriteDescriptorSetAccelerationStructureKHR> accel_struct_info;
    };
    std::vector<ResourceInfo> resource_infos_;
    std::vector<vk::WriteDescriptorSet> descriptor_writes_;
};
