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
#include <iostream>
#include <map>

void CDLTestBase::InitArgs(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        const std::string_view current_argument = argv[i];
        if (current_argument == "--print-all") {
            print_all_ = true;
        } else if (current_argument == "--no-mock") {
            no_mock_icd_ = true;
        } else if (current_argument == "--device-index" && ((i + 1) < argc)) {
            phys_device_index_ = std::atoi(argv[++i]);
        } else if (current_argument == "--print-devices") {
            print_phys_devices_ = true;
        } else if ((current_argument == "--help") || (current_argument == "-h")) {
            std::cout << std::endl << "Other options:" << std::endl;
            std::cout << "\t--print-all" << std::endl
                      << "\t\tPrints all log messages - help see what messages will look like to a user." << std::endl;
            std::cout << "\t--device-index <physical device index>" << std::endl
                      << "\t\tIndex into VkPhysicalDevice array returned from vkEnumeratePhysicalDevices." << std::endl
                      << "\t\tThe default behavior is to automatically choose \"the most reasonable device.\""
                      << std::endl
                      << "\t\tAn invalid index (i.e., outside the range [0, *pPhysicalDeviceCount)) will result in the "
                         "default behavior"
                      << std::endl;
            std::cout << "\t--print-devices" << std::endl
                      << "\t\tPrint all physical devices during intialization." << std::endl;
            exit(0);
        }
    }
}

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

    layer_settings_.SetDumpShaders("off");

    if (print_all_) {
        layer_settings_.SetLogFile("stderr");
        layer_settings_.SetMessageSeverity("error, warn, info, verbose");
    } else {
        layer_settings_.SetLogFile("none");
    }
}

void CDLTestBase::InitInstance() {
    const auto* test_info = testing::UnitTest::GetInstance()->current_test_info();
    vk::ApplicationInfo app_info(test_info->test_suite_name(), 1, test_info->name(), 1, VK_API_VERSION_1_3);

    std::vector<const char*> layers{"VK_LAYER_LUNARG_crash_diagnostic"};
    std::vector<const char*> instance_extensions{"VK_EXT_debug_utils", "VK_EXT_layer_settings"};

    vk::InstanceCreateInfo ci({}, &app_info, layers, instance_extensions, layer_settings_.GetCreateInfo());

    instance_ = vk::raii::Instance(context_, ci);

    static std::map<vk::PhysicalDeviceType, const char*> type_names{
        {vk::PhysicalDeviceType::eDiscreteGpu, "discrete"}, {vk::PhysicalDeviceType::eIntegratedGpu, "integrated"},
        {vk::PhysicalDeviceType::eVirtualGpu, "virtual"},   {vk::PhysicalDeviceType::eCpu, "cpu"},
        {vk::PhysicalDeviceType::eOther, "other"},
    };
    auto phys_devices = vk::raii::PhysicalDevices(instance_);
    if (print_phys_devices_) {
        std::cout << "Physical Devices:" << std::endl;
        for (size_t i = 0; i < phys_devices.size(); i++) {
            auto prop = phys_devices[i].getProperties();
            std::string name = prop.deviceName;
            std::cout << i << ": " << name << ", type: " << type_names[prop.deviceType] << std::endl;
        }
    }

    if ((phys_device_index_ >= 0) && (phys_device_index_ < int(phys_devices.size()))) {
        physical_device_ = phys_devices[phys_device_index_];
    } else {
        // Specify a "physical device priority" with larger values meaning higher priority.
        std::map<vk::PhysicalDeviceType, int> device_type_rank{
            {vk::PhysicalDeviceType::eDiscreteGpu, 4}, {vk::PhysicalDeviceType::eIntegratedGpu, 3},
            {vk::PhysicalDeviceType::eVirtualGpu, 2},  {vk::PhysicalDeviceType::eCpu, 1},
            {vk::PhysicalDeviceType::eOther, 0},
        };

        // Initialize physical device and properties with first device found
        physical_device_ = phys_devices[0];
        phys_device_index_ = 0;
        auto current_props = physical_device_.getProperties();
        // See if there are any higher priority devices found
        for (size_t i = 1; i < phys_devices.size(); i++) {
            auto tmp_props = phys_devices[i].getProperties();
            if (device_type_rank[tmp_props.deviceType] > device_type_rank[current_props.deviceType]) {
                physical_device_ = phys_devices[i];
                current_props = tmp_props;
                phys_device_index_ = i;
            }
        }
    }
    if (print_phys_devices_) {
        auto props = physical_device_.getProperties();
        std::string name = props.deviceName;
        std::cout << "Selected device: " << phys_device_index_ << ": " << name
                  << ", type: " << type_names[props.deviceType] << std::endl;
    }
    // only print the first time
    print_phys_devices_ = false;
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
