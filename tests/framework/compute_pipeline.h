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
#include "descriptorset_helper.h"
#include "bound_buffer.h"

#include <vector>

class ComputePipelineHelper {
   public:
    ComputePipelineHelper(vk::raii::Device &device, const char *shader,
                          const std::vector<vk::DescriptorSetLayoutBinding> &bindings,
                          const std::vector<vk::PushConstantRange> &push_constants = {}, void *pNext = nullptr);

    vk::Pipeline Pipeline() { return *pipeline_; }
    vk::PipelineLayout PipelineLayout() { return *pipeline_layout_; }
    DescriptorSetHelper &DescriptorSet() { return descriptor_set_; }
    void InitShaderInfo();

    void LateBindPipelineInfo();
    void CreateComputePipeline(bool do_late_bind = true);

   private:
    vk::raii::Device &device_;
    vk::raii::PipelineCache pipeline_cache_;
    vk::raii::ShaderModule cs_;
    DescriptorSetHelper descriptor_set_;
    vk::raii::PipelineLayout pipeline_layout_;
    vk::raii::Pipeline pipeline_;
};

// Setup helper for the common pipeline of 1 input and 1 output buffer processed by a compute shader
struct ComputeIOTest {
    static constexpr size_t kNumElems = 256;
    static constexpr VkDeviceSize kBuffSize = kNumElems * sizeof(float);

    ComputeIOTest(vk::raii::PhysicalDevice &phys_dev, vk::raii::Device &device, const char *shader);

    ComputePipelineHelper pipeline;

    BoundBuffer input;
    BoundBuffer output;
};
