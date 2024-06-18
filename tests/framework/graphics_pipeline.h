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

class GraphicsPipelineHelper {
   public:
    GraphicsPipelineHelper(vk::raii::Device &device, const char *vertex_shader, const char *frag_shader,
                           const std::vector<vk::DescriptorSetLayoutBinding> &bindings,
                           const std::vector<vk::PushConstantRange> &push_constants = {}, void *pNext = nullptr);

    vk::Pipeline Pipeline() { return *pipeline_; }
    vk::PipelineLayout PipelineLayout() { return *pipeline_layout_; }
    DescriptorSetHelper &DescriptorSet() { return descriptor_set_; }
    void InitShaderInfo();

    void LateBindPipelineInfo();
    void CreateGraphicsPipeline(bool do_late_bind = true);

   private:
    vk::raii::Device &device_;
    vk::raii::PipelineCache pipeline_cache_;
    vk::raii::ShaderModule vs_, fs_;
    DescriptorSetHelper descriptor_set_;
    vk::raii::PipelineLayout pipeline_layout_;
    vk::raii::Pipeline pipeline_;

    vk::PipelineVertexInputStateCreateInfo vi_ci_;
    vk::PipelineInputAssemblyStateCreateInfo ia_ci_;
    vk::PipelineTessellationStateCreateInfo tess_ci_;
    vk::Viewport viewport_;
    vk::Rect2D scissor_;
    vk::PipelineViewportStateCreateInfo vp_state_ci_;
    vk::PipelineMultisampleStateCreateInfo ms_ci_;
    vk::PipelineDynamicStateCreateInfo dyn_state_ci_;
    vk::PipelineRasterizationStateCreateInfo rs_state_ci_;
    vk::PipelineRasterizationLineStateCreateInfoKHR line_state_ci_;
    vk::PipelineColorBlendAttachmentState cb_attachments_;
    vk::PipelineColorBlendStateCreateInfo cb_ci_;
    vk::PipelineDepthStencilStateCreateInfo ds_ci_;
    vk::Format attachment_format_;
    vk::PipelineRenderingCreateInfo dynamic_rendering_ci_;
};
