/*
 Copyright 2018 Google Inc.
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

#include "pipeline.h"

#include <sstream>

#include "cdl.h"

namespace crash_diagnostic_layer {

PipelineBoundShader PipelineBoundShader::NULL_SHADER = {static_cast<VkShaderStageFlagBits>(0), VK_NULL_HANDLE,
                                                        "<NULL>"};

// =================================================================================================
// Pipeline
// =================================================================================================
Pipeline::Pipeline(VkPipeline vk_pipeline, const VkGraphicsPipelineCreateInfo& graphics_create_info)
    : vk_pipeline_(vk_pipeline), pipeline_bind_point_(VK_PIPELINE_BIND_POINT_GRAPHICS) {
    InitFromShaderStages(graphics_create_info.pStages, graphics_create_info.stageCount);
}

Pipeline::Pipeline(VkPipeline vk_pipeline, const VkComputePipelineCreateInfo& compute_create_info)
    : vk_pipeline_(vk_pipeline), pipeline_bind_point_(VK_PIPELINE_BIND_POINT_COMPUTE) {
    InitFromShaderStages(&compute_create_info.stage, 1);
}

void Pipeline::InitFromShaderStages(const VkPipelineShaderStageCreateInfo* stages, uint32_t stage_count) {
    for (uint32_t shader_index = 0; shader_index < stage_count; ++shader_index) {
        PipelineBoundShader shader_stage = {stages[shader_index].stage, stages[shader_index].module,
                                            stages[shader_index].pName};

        shaders_.push_back(shader_stage);
    }
}

const PipelineBoundShader& Pipeline::FindShaderStage(VkShaderStageFlagBits shader_stage) const {
    for (const auto& shader : shaders_) {
        if (shader.stage == shader_stage) {
            return shader;
        }
    }

    return PipelineBoundShader::NULL_SHADER;
}

YAML::Emitter& Pipeline::PrintName(YAML::Emitter& os, const ObjectInfoDB& name_resolver) const {
    // TODO: begin / end map?
    os << name_resolver.GetObjectInfo((uint64_t)vk_pipeline_);
    auto bind_point = GetVkPipelineBindPoint();
    os << YAML::Key << "bindPoint" << YAML::Value;
    if (bind_point == VK_PIPELINE_BIND_POINT_GRAPHICS) {
        os << "graphics";
    } else if (bind_point == VK_PIPELINE_BIND_POINT_COMPUTE) {
        os << "compute";
    } else {
        os << "unknown";
    }
    return os;
}

YAML::Emitter& Pipeline::Print(YAML::Emitter& os, const ObjectInfoDB& name_resolver) const {
    // TODO: begin / end map?
    PrintName(os, name_resolver);

    const auto num_shaders = shaders_.size();
    if (num_shaders) {
        os << YAML::Key << "shaderInfos" << YAML::Value << YAML::BeginSeq;
        for (auto shader_index = 0u; shader_index < num_shaders; ++shader_index) {
            auto const& shader = shaders_[shader_index];
            os << YAML::BeginMap;
            // TODO: stream << indent2 << "- # shaderInfo:";
            os << YAML::Key << "stage" << YAML::Value;
            if (shader.stage == VK_SHADER_STAGE_VERTEX_BIT) {
                os << "vs";
            } else if (shader.stage == VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT) {
                os << "tc";
            } else if (shader.stage == VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT) {
                os << "te";
            } else if (shader.stage == VK_SHADER_STAGE_GEOMETRY_BIT) {
                os << "gs";
            } else if (shader.stage == VK_SHADER_STAGE_FRAGMENT_BIT) {
                os << "fs";
            } else if (shader.stage == VK_SHADER_STAGE_COMPUTE_BIT) {
                os << "cs";
            }
            os << YAML::Key << "module" << YAML::Value << name_resolver.GetObjectInfo((uint64_t)shader.module);
            os << YAML::Key << "entry" << YAML::Value << shader.entry_point;
            os << YAML::EndMap;
        }
        os << YAML::EndSeq;
    }

    return os;
}

VkPipeline Pipeline::GetVkPipeline() const { return vk_pipeline_; }

VkPipelineBindPoint Pipeline::GetVkPipelineBindPoint() const { return pipeline_bind_point_; }

}  // namespace crash_diagnostic_layer
