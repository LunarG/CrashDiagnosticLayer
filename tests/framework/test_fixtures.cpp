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
#include <glslang/Public/ShaderLang.h>
#include <glslang/SPIRV/GlslangToSpv.h>
#include <glslang/Public/ResourceLimits.h>
#include <filesystem>

CDLTestBase::CDLTestBase()
    : monitor_("CDL", false),
      instance_(VK_NULL_HANDLE),
      physical_device_(VK_NULL_HANDLE),
      device_(VK_NULL_HANDLE),
      layer_settings_(monitor_.GetDebugCreateInfo()),
      compute_queue_(VK_NULL_HANDLE),
      cmd_pool_(VK_NULL_HANDLE),
      cmd_buff_(VK_NULL_HANDLE) {
    const auto* test_info = testing::UnitTest::GetInstance()->current_test_info();

    // Set default settings here rather than InitInstance(). This allows tests cases
    // to change them before calling it.
    output_path_ = kTestOutputBaseDir;
    output_path_ /= test_info->test_suite_name();
    output_path_ /= test_info->name();

    layer_settings_.SetOutputPath(output_path_.string().c_str());

    // Turn off the default logger
    layer_settings_.SetLogFile("none");
}

void CDLTestBase::InitInstance() {
    const auto* test_info = testing::UnitTest::GetInstance()->current_test_info();
    vk::ApplicationInfo app_info(test_info->test_suite_name(), 1, test_info->name(), 1, VK_API_VERSION_1_3);

    std::vector<const char*> layers{"VK_LAYER_LUNARG_crash_diagnostic"};
    std::vector<const char*> instance_extensions{"VK_EXT_debug_utils", "VK_EXT_layer_settings"};

    vk::InstanceCreateInfo ci({}, &app_info, layers, instance_extensions, layer_settings_.GetCreateInfo());

    instance_ = vk::raii::Instance(context_, ci);

    physical_device_ = vk::raii::PhysicalDevices(instance_).back();
}

void CDLTestBase::InitDevice(std::vector<const char*> extensions, const vk::PhysicalDeviceFeatures2* features2) {
    if (!*instance_) {
        InitInstance();
    }

    auto queue_properties = physical_device_.getQueueFamilyProperties();
    for (uint32_t i = 0; i < uint32_t(queue_properties.size()); i++) {
        if (queue_properties[i].queueFlags & vk::QueueFlagBits::eCompute) {
            compute_qfi_ = i;
            break;
        }
    }

    float priority = 0.0f;
    vk::DeviceQueueCreateInfo queue_ci({}, compute_qfi_, 1, &priority);
    vk::DeviceCreateInfo device_ci({}, queue_ci, {}, extensions, nullptr, features2);

    device_ = physical_device_.createDevice(device_ci);

    compute_queue_ = device_.getQueue(compute_qfi_, 0);

    vk::CommandPoolCreateInfo cmd_pool_ci({}, compute_qfi_);
    cmd_pool_ = device_.createCommandPool(cmd_pool_ci);

    vk::CommandBufferAllocateInfo cmd_alloc_info(cmd_pool_, vk::CommandBufferLevel::ePrimary, 1);
    cmd_buff_ = std::move(vk::raii::CommandBuffers(device_, cmd_alloc_info).front());
}

static EShLanguage FindLanguage(vk::ShaderStageFlagBits shader_type) {
    switch (shader_type) {
        case vk::ShaderStageFlagBits::eVertex:
            return EShLangVertex;
        case vk::ShaderStageFlagBits::eTessellationControl:
            return EShLangTessControl;
        case vk::ShaderStageFlagBits::eTessellationEvaluation:
            return EShLangTessEvaluation;
        case vk::ShaderStageFlagBits::eGeometry:
            return EShLangGeometry;
        case vk::ShaderStageFlagBits::eFragment:
            return EShLangFragment;
        case vk::ShaderStageFlagBits::eCompute:
            return EShLangCompute;
        case vk::ShaderStageFlagBits::eRaygenKHR:
            return EShLangRayGen;
        case vk::ShaderStageFlagBits::eAnyHitKHR:
            return EShLangAnyHit;
        case vk::ShaderStageFlagBits::eClosestHitKHR:
            return EShLangClosestHit;
        case vk::ShaderStageFlagBits::eMissKHR:
            return EShLangMiss;
        case vk::ShaderStageFlagBits::eIntersectionKHR:
            return EShLangIntersect;
        case vk::ShaderStageFlagBits::eCallableKHR:
            return EShLangCallable;
        case vk::ShaderStageFlagBits::eTaskEXT:
            return EShLangTask;
        case vk::ShaderStageFlagBits::eMeshEXT:
            return EShLangMesh;
        default:
            return EShLangVertex;
    }
}

static bool GLSLtoSPV(const char* source, vk::ShaderStageFlagBits shader_type, std::vector<uint32_t>& spirv) {
    glslang::TProgram program;
    const char* shaderStrings[1];

    // ProcessConfigFile(device_limits);

    EShMessages messages = EShMsgDefault;
    messages = static_cast<EShMessages>(messages | EShMsgSpvRules | EShMsgVulkanRules);

    EShLanguage stage = FindLanguage(shader_type);
    auto shader = std::make_unique<glslang::TShader>(stage);
    shader->setEnvTarget(glslang::EshTargetSpv, glslang::EShTargetSpv_1_6);
    shader->setEnvClient(glslang::EShClientVulkan, glslang::EShTargetVulkan_1_3);

    shaderStrings[0] = source;
    shader->setStrings(shaderStrings, 1);

    if (!shader->parse(GetDefaultResources(), 110, false, messages)) {
        puts(shader->getInfoLog());
        puts(shader->getInfoDebugLog());
        return false;  // something didn't work
    }

    program.addShader(shader.get());

    //
    // Program-level processing...
    //

    if (!program.link(messages)) {
        puts(shader->getInfoLog());
        puts(shader->getInfoDebugLog());
        return false;
    }
    glslang::SpvOptions spv_options;
    glslang::GlslangToSpv(*program.getIntermediate(stage), spirv, &spv_options);
    return true;
}

vk::raii::ShaderModule CreateShaderModuleGLSL(vk::raii::Device& device, const char* src,
                                              vk::ShaderStageFlagBits stage) {
    std::vector<uint32_t> spirv;
    if (!GLSLtoSPV(src, stage, spirv)) {
        return vk::raii::ShaderModule(VK_NULL_HANDLE);
    }
    vk::ShaderModuleCreateInfo ci({}, spirv);
    return device.createShaderModule(ci);
}
