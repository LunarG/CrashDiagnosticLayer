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
#include "test_fixtures.h"
#include "bound_image.h"
#include "compute_pipeline.h"
#include "graphics_pipeline.h"
#include "dump_file.h"
#include "shaders.h"
#include <filesystem>
#include <fstream>
#include <vulkan/utility/vk_struct_helper.hpp>

class RayTracing : public CDLTestBase {};

TEST_F(RayTracing, BuildPositive) {
    InitInstance();

    vk::StructureChain<vk::PhysicalDeviceFeatures2, vk::PhysicalDeviceBufferDeviceAddressFeatures,
                       vk::PhysicalDeviceAccelerationStructureFeaturesKHR>
        chain;

    auto &bda_features = chain.get<vk::PhysicalDeviceBufferDeviceAddressFeatures>();
    bda_features.bufferDeviceAddress = VK_TRUE;

    auto &as_features = chain.get<vk::PhysicalDeviceAccelerationStructureFeaturesKHR>();
    as_features.accelerationStructure = VK_TRUE;

    const auto &features2 = chain.get<vk::PhysicalDeviceFeatures2>();

    [[maybe_unused]] auto prop_chain =
        physical_device_
            .getProperties2<vk::PhysicalDeviceProperties2, vk::PhysicalDeviceAccelerationStructurePropertiesKHR>();

    InitDevice({"VK_KHR_acceleration_structure", "VK_KHR_deferred_host_operations"}, &features2);

    constexpr size_t kNumElems = 256;
    constexpr VkDeviceSize kBuffSize = kNumElems * sizeof(float);

    vk::BufferUsageFlags usage = vk::BufferUsageFlagBits::eAccelerationStructureBuildInputReadOnlyKHR |
                                 vk::BufferUsageFlagBits::eShaderDeviceAddress;
    BoundBuffer vertex(physical_device_, device_, kBuffSize, "vertex", usage,
                       vk::MemoryAllocateFlagBits::eDeviceAddress);
    float *v = reinterpret_cast<float *>(vertex.memory.mapMemory(0, kBuffSize));

    v[0] = 1.0f;
    v[1] = 0.0f;
    v[2] = 0.0f;

    v[3] = 0.0f;
    v[4] = 1.0f;
    v[5] = 0.0f;

    v[6] = -1.0f;
    v[7] = 0.0f;
    v[8] = 0.0f;

    vertex.memory.unmapMemory();

    BoundBuffer index(physical_device_, device_, kBuffSize, "index", usage, vk::MemoryAllocateFlagBits::eDeviceAddress);

    uint32_t *i = reinterpret_cast<uint32_t *>(index.memory.mapMemory(0, kBuffSize));
    i[0] = 0;
    i[1] = 1;
    i[2] = 2;
    index.memory.unmapMemory();

    vk::AccelerationStructureGeometryKHR geometry(vk::GeometryTypeKHR::eTriangles);

    auto &triangles = geometry.geometry.triangles;

    triangles.vertexData.deviceAddress = vertex.GetAddress(device_);
    triangles.vertexFormat = vk::Format::eR32G32B32Sfloat;
    triangles.vertexStride = 3 * sizeof(float);

    triangles.indexData.deviceAddress = index.GetAddress(device_);
    triangles.indexType = vk::IndexType::eUint32;

    BoundBuffer as_mem(
        physical_device_, device_, 4096, "as",
        vk::BufferUsageFlagBits::eAccelerationStructureStorageKHR | vk::BufferUsageFlagBits::eShaderDeviceAddress,
        vk::MemoryAllocateFlagBits::eDeviceAddress);

    BoundBuffer scratch(physical_device_, device_, 4096, "scratch",
                        vk::BufferUsageFlagBits::eStorageBuffer | vk::BufferUsageFlagBits::eShaderDeviceAddress,
                        vk::MemoryAllocateFlagBits::eDeviceAddress);

    vk::AccelerationStructureCreateInfoKHR accel_ci({}, as_mem.buffer, 0, 4096,
                                                    vk::AccelerationStructureTypeKHR::eBottomLevel, 0);
    vk::raii::AccelerationStructureKHR accel_struct(device_, accel_ci);

    vk::AccelerationStructureBuildRangeInfoKHR range_info(1u, 0u, 0u, 0u);
    vk::AccelerationStructureBuildGeometryInfoKHR info(vk::AccelerationStructureTypeKHR::eBottomLevel, {},
                                                       vk::BuildAccelerationStructureModeKHR::eBuild, {}, accel_struct,
                                                       geometry, {}, scratch.GetAddress(device_));

    vk::CommandBufferBeginInfo begin_info;
    cmd_buff_.begin(begin_info);

    cmd_buff_.buildAccelerationStructuresKHR(info, &range_info);

    cmd_buff_.end();

    vk::SubmitInfo submit_info({}, {}, *cmd_buff_, {});

    queue_.submit(submit_info);
    queue_.waitIdle();
}

TEST_F(RayTracing, BuildCrash) {
    layer_settings_.SetDumpCommands("all");
    InitInstance();

    vk::StructureChain<vk::PhysicalDeviceFeatures2, vk::PhysicalDeviceBufferDeviceAddressFeatures,
                       vk::PhysicalDeviceAccelerationStructureFeaturesKHR>
        chain;

    auto &bda_features = chain.get<vk::PhysicalDeviceBufferDeviceAddressFeatures>();
    bda_features.bufferDeviceAddress = VK_TRUE;

    auto &as_features = chain.get<vk::PhysicalDeviceAccelerationStructureFeaturesKHR>();
    as_features.accelerationStructure = VK_TRUE;

    const auto &features2 = chain.get<vk::PhysicalDeviceFeatures2>();

    [[maybe_unused]] auto prop_chain =
        physical_device_
            .getProperties2<vk::PhysicalDeviceProperties2, vk::PhysicalDeviceAccelerationStructurePropertiesKHR>();

    InitDevice({"VK_KHR_acceleration_structure", "VK_KHR_deferred_host_operations"}, &features2);

    constexpr size_t kNumElems = 256;
    constexpr VkDeviceSize kBuffSize = kNumElems * sizeof(float);

    vk::BufferUsageFlags usage = vk::BufferUsageFlagBits::eAccelerationStructureBuildInputReadOnlyKHR |
                                 vk::BufferUsageFlagBits::eShaderDeviceAddress;
    BoundBuffer vertex(physical_device_, device_, kBuffSize, "vertex", usage,
                       vk::MemoryAllocateFlagBits::eDeviceAddress);
    float *v = reinterpret_cast<float *>(vertex.memory.mapMemory(0, kBuffSize));

    v[0] = 1.0f;
    v[1] = 0.0f;
    v[2] = 0.0f;

    v[3] = 0.0f;
    v[4] = 1.0f;
    v[5] = 0.0f;

    v[6] = -1.0f;
    v[7] = 0.0f;
    v[8] = 0.0f;

    vertex.memory.unmapMemory();

    BoundBuffer index(physical_device_, device_, kBuffSize, "index", usage, vk::MemoryAllocateFlagBits::eDeviceAddress);

    uint32_t *i = reinterpret_cast<uint32_t *>(index.memory.mapMemory(0, kBuffSize));
    i[0] = 0;
    i[1] = 1;
    i[2] = 2;
    index.memory.unmapMemory();

    vk::AccelerationStructureGeometryKHR geometry(vk::GeometryTypeKHR::eTriangles);

    auto &triangles = geometry.geometry.triangles;

    triangles.vertexData.deviceAddress = vertex.GetAddress(device_);
    triangles.vertexFormat = vk::Format::eR32G32B32Sfloat;
    triangles.vertexStride = 3 * sizeof(float);

    triangles.indexData.deviceAddress = 0xdeadbeef;
    // index.GetAddress(device_);
    triangles.indexType = vk::IndexType::eUint32;

    BoundBuffer as_mem(
        physical_device_, device_, 4096, "as",
        vk::BufferUsageFlagBits::eAccelerationStructureStorageKHR | vk::BufferUsageFlagBits::eShaderDeviceAddress,
        vk::MemoryAllocateFlagBits::eDeviceAddress);

    BoundBuffer scratch(physical_device_, device_, 4096, "scratch",
                        vk::BufferUsageFlagBits::eStorageBuffer | vk::BufferUsageFlagBits::eShaderDeviceAddress,
                        vk::MemoryAllocateFlagBits::eDeviceAddress);

    vk::AccelerationStructureCreateInfoKHR accel_ci({}, as_mem.buffer, 0, 4096,
                                                    vk::AccelerationStructureTypeKHR::eBottomLevel, 0);
    vk::raii::AccelerationStructureKHR accel_struct(device_, accel_ci);

    vk::AccelerationStructureBuildRangeInfoKHR range_info(1u, 0u, 0u, 0u);
    vk::AccelerationStructureBuildGeometryInfoKHR info(vk::AccelerationStructureTypeKHR::eBottomLevel, {},
                                                       vk::BuildAccelerationStructureModeKHR::eBuild, {}, accel_struct,
                                                       geometry, {}, scratch.GetAddress(device_));

    vk::CommandBufferBeginInfo begin_info;
    cmd_buff_.begin(begin_info);

    vk::DeviceFaultCountsEXT counts(0, 0, 0);
    vk::DebugUtilsLabelEXT label("hang-expected", {}, &counts);
    cmd_buff_.beginDebugUtilsLabelEXT(label);

    cmd_buff_.buildAccelerationStructuresKHR(info, &range_info);

    cmd_buff_.endDebugUtilsLabelEXT();

    cmd_buff_.end();

    vk::SubmitInfo submit_info({}, {}, *cmd_buff_, {});

    bool hang_detected = false;
    monitor_.SetDesiredError("Device error encountered and log being recorded");
    try {
        queue_.submit(submit_info);
        queue_.waitIdle();
    } catch (vk::SystemError &) {
        hang_detected = true;
    }
    monitor_.VerifyFound();
    ASSERT_TRUE(hang_detected);
    dump::File dump_file;
    dump::Parse(dump_file, output_path_);
}

TEST_F(RayTracing, TraceRaysPositive) {
    InitInstance();

    vk::StructureChain<vk::PhysicalDeviceFeatures2, vk::PhysicalDeviceBufferDeviceAddressFeatures,
                       vk::PhysicalDeviceAccelerationStructureFeaturesKHR,
                       vk::PhysicalDeviceRayTracingPipelineFeaturesKHR, vk::PhysicalDeviceRayQueryFeaturesKHR>
        chain;

    auto &bda_features = chain.get<vk::PhysicalDeviceBufferDeviceAddressFeatures>();
    bda_features.bufferDeviceAddress = VK_TRUE;

    auto &as_features = chain.get<vk::PhysicalDeviceAccelerationStructureFeaturesKHR>();
    as_features.accelerationStructure = VK_TRUE;

    auto &rtp_features = chain.get<vk::PhysicalDeviceRayTracingPipelineFeaturesKHR>();
    rtp_features.rayTracingPipeline = VK_TRUE;

    auto &rq_features = chain.get<vk::PhysicalDeviceRayQueryFeaturesKHR>();
    rq_features.rayQuery = VK_TRUE;

    const auto &features2 = chain.get<vk::PhysicalDeviceFeatures2>();

    auto prop_chain =
        physical_device_
            .getProperties2<vk::PhysicalDeviceProperties2, vk::PhysicalDeviceAccelerationStructurePropertiesKHR, vk::PhysicalDeviceRayTracingPipelinePropertiesKHR>();

    auto &rt_props = prop_chain.get<vk::PhysicalDeviceRayTracingPipelinePropertiesKHR>();

    InitDevice({VK_KHR_ACCELERATION_STRUCTURE_EXTENSION_NAME, VK_KHR_DEFERRED_HOST_OPERATIONS_EXTENSION_NAME,
                VK_KHR_RAY_QUERY_EXTENSION_NAME, VK_KHR_RAY_TRACING_PIPELINE_EXTENSION_NAME},
               &features2);
    static const char *minimal = R"glsl(
#version 460
#extension GL_EXT_ray_tracing : require  // Requires SPIR-V 1.5 (Vulkan 1.2)
void main() {}
)glsl";

    std::vector<vk::raii::ShaderModule> modules;
    modules.emplace_back(CreateShaderModuleGLSL(device_, minimal, vk::ShaderStageFlagBits::eRaygenKHR));
    modules.emplace_back(CreateShaderModuleGLSL(device_, minimal, vk::ShaderStageFlagBits::eClosestHitKHR));

    std::vector<vk::PipelineShaderStageCreateInfo> stages;
    stages.emplace_back(vk::PipelineShaderStageCreateInfo({}, vk::ShaderStageFlagBits::eRaygenKHR, *modules[0], "main"));
    stages.emplace_back(vk::PipelineShaderStageCreateInfo({}, vk::ShaderStageFlagBits::eClosestHitKHR, *modules[1], "main"));

    vk::RayTracingShaderGroupCreateInfoKHR group(vk::RayTracingShaderGroupTypeKHR::eGeneral);

    vk::raii::PipelineLayout pipeline_layout = device_.createPipelineLayout(vk::PipelineLayoutCreateInfo());
    vk::RayTracingPipelineCreateInfoKHR pipeline_ci({}, stages, group);
    pipeline_ci.layout = *pipeline_layout;

    auto rt_pipeline = device_.createRayTracingPipelineKHR(nullptr, nullptr, pipeline_ci);

    BoundBuffer buff(physical_device_, device_, rt_props.shaderGroupHandleAlignment, "buff",
                     vk::BufferUsageFlagBits::eShaderDeviceAddress | vk::BufferUsageFlagBits::eShaderBindingTableKHR,
                     vk::MemoryAllocateFlagBits::eDeviceAddress);

    vk::StridedDeviceAddressRegionKHR region(buff.GetAddress(device_), rt_props.shaderGroupHandleAlignment,
                                             rt_props.shaderGroupHandleAlignment);

    vk::CommandBufferBeginInfo begin_info;
    cmd_buff_.begin(begin_info);

    cmd_buff_.bindPipeline(vk::PipelineBindPoint::eRayTracingKHR, rt_pipeline);
    cmd_buff_.traceRaysKHR(region, region, region, region, 100, 100, 1);

    cmd_buff_.end();

    vk::SubmitInfo submit_info({}, {}, *cmd_buff_, {});

    queue_.submit(submit_info);
    queue_.waitIdle();
}

TEST_F(RayTracing, TraceRaysCrash) {
    InitInstance();

    vk::StructureChain<vk::PhysicalDeviceFeatures2, vk::PhysicalDeviceBufferDeviceAddressFeatures,
                       vk::PhysicalDeviceAccelerationStructureFeaturesKHR,
                       vk::PhysicalDeviceRayTracingPipelineFeaturesKHR, vk::PhysicalDeviceRayQueryFeaturesKHR>
        chain;

    auto &bda_features = chain.get<vk::PhysicalDeviceBufferDeviceAddressFeatures>();
    bda_features.bufferDeviceAddress = VK_TRUE;

    auto &as_features = chain.get<vk::PhysicalDeviceAccelerationStructureFeaturesKHR>();
    as_features.accelerationStructure = VK_TRUE;

    auto &rtp_features = chain.get<vk::PhysicalDeviceRayTracingPipelineFeaturesKHR>();
    rtp_features.rayTracingPipeline = VK_TRUE;

    auto &rq_features = chain.get<vk::PhysicalDeviceRayQueryFeaturesKHR>();
    rq_features.rayQuery = VK_TRUE;

    const auto &features2 = chain.get<vk::PhysicalDeviceFeatures2>();

    auto prop_chain =
        physical_device_
            .getProperties2<vk::PhysicalDeviceProperties2, vk::PhysicalDeviceAccelerationStructurePropertiesKHR, vk::PhysicalDeviceRayTracingPipelinePropertiesKHR>();

    auto &rt_props = prop_chain.get<vk::PhysicalDeviceRayTracingPipelinePropertiesKHR>();

    InitDevice({VK_KHR_ACCELERATION_STRUCTURE_EXTENSION_NAME, VK_KHR_DEFERRED_HOST_OPERATIONS_EXTENSION_NAME,
                VK_KHR_RAY_QUERY_EXTENSION_NAME, VK_KHR_RAY_TRACING_PIPELINE_EXTENSION_NAME},
               &features2);
    static const char *minimal = R"glsl(
#version 460
#extension GL_EXT_ray_tracing : require  // Requires SPIR-V 1.5 (Vulkan 1.2)
void main() {}
)glsl";

    std::vector<vk::raii::ShaderModule> modules;
    modules.emplace_back(CreateShaderModuleGLSL(device_, minimal, vk::ShaderStageFlagBits::eRaygenKHR));
    modules.emplace_back(CreateShaderModuleGLSL(device_, minimal, vk::ShaderStageFlagBits::eClosestHitKHR));

    std::vector<vk::PipelineShaderStageCreateInfo> stages;
    stages.emplace_back(vk::PipelineShaderStageCreateInfo({}, vk::ShaderStageFlagBits::eRaygenKHR, *modules[0], "main"));
    stages.emplace_back(vk::PipelineShaderStageCreateInfo({}, vk::ShaderStageFlagBits::eClosestHitKHR, *modules[1], "main"));

    vk::RayTracingShaderGroupCreateInfoKHR group(vk::RayTracingShaderGroupTypeKHR::eGeneral);

    vk::raii::PipelineLayout pipeline_layout = device_.createPipelineLayout(vk::PipelineLayoutCreateInfo());
    vk::RayTracingPipelineCreateInfoKHR pipeline_ci({}, stages, group);
    pipeline_ci.layout = *pipeline_layout;

    auto rt_pipeline = device_.createRayTracingPipelineKHR(nullptr, nullptr, pipeline_ci);

    BoundBuffer buff(physical_device_, device_, rt_props.shaderGroupHandleAlignment, "buff",
                     vk::BufferUsageFlagBits::eShaderDeviceAddress | vk::BufferUsageFlagBits::eShaderBindingTableKHR,
                     vk::MemoryAllocateFlagBits::eDeviceAddress);

    vk::StridedDeviceAddressRegionKHR region(buff.GetAddress(device_), rt_props.shaderGroupHandleAlignment,
                                             rt_props.shaderGroupHandleAlignment);

    vk::CommandBufferBeginInfo begin_info;
    cmd_buff_.begin(begin_info);

    cmd_buff_.bindPipeline(vk::PipelineBindPoint::eRayTracingKHR, rt_pipeline);

    vk::DeviceFaultCountsEXT counts(0, 0, 0);
    vk::DebugUtilsLabelEXT label("hang-expected", {}, &counts);
    cmd_buff_.beginDebugUtilsLabelEXT(label);

    cmd_buff_.traceRaysKHR(region, region, region, region, 100, 100, 1);

    cmd_buff_.endDebugUtilsLabelEXT();

    cmd_buff_.end();

    buff.buffer.clear();
    buff.memory.clear();

    vk::SubmitInfo submit_info({}, {}, *cmd_buff_, {});

    bool hang_detected = false;
    monitor_.SetDesiredError("Device error encountered and log being recorded");
    try {
        queue_.submit(submit_info);
        queue_.waitIdle();
    } catch (vk::SystemError &) {
        hang_detected = true;
    }
    monitor_.VerifyFound();
    ASSERT_TRUE(hang_detected);
    dump::File dump_file;
    dump::Parse(dump_file, output_path_);
}
