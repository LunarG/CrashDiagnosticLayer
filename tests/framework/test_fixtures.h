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

#include <vulkan/vulkan_raii.hpp>
#include <filesystem>

// Prevent conflicts between X.h and gtest
#ifdef None
#undef None
#endif
#ifdef Bool
#undef Bool
#endif
#include <gtest/gtest.h>
#include "error_monitor.h"
#include "layer_settings.h"

static const char* kTestOutputBaseDir = "cdl_test_output";

class CDLTestBase : public ::testing::Test {
   public:
    CDLTestBase();
    ~CDLTestBase() {}
    void InitInstance();
    void InitDevice(std::vector<const char*> extensions = {}, const vk::PhysicalDeviceFeatures2* features2 = nullptr);

    static void InitArgs(int argc, char* argv[]);

    static inline bool print_all_{false};
    static inline bool no_mock_icd_{false};
    static inline uint32_t phys_device_index_{~0u};
    static inline bool print_phys_devices_{false};

    vk::raii::Context context_;
    ErrorMonitor monitor_;
    // LayerSettings settings_;
    vk::raii::Instance instance_;

    vk::raii::PhysicalDevice physical_device_;
    vk::raii::Device device_;
    std::filesystem::path output_path_;
    LayerSettings layer_settings_;

    uint32_t qfi_{~0u};
    vk::raii::Queue queue_;

    vk::raii::CommandPool cmd_pool_;
    vk::raii::CommandBuffer cmd_buff_;
};

template <typename T>
void SetObjectName(vk::raii::Device& device, T& object, const std::string& name) {
    vk::DebugUtilsObjectNameInfoEXT info(T::objectType, reinterpret_cast<uint64_t>(typename T::CType(*object)),
                                         name.c_str());
    device.setDebugUtilsObjectNameEXT(info);
}

vk::raii::ShaderModule CreateShaderModuleGLSL(vk::raii::Device& device, const char* src, vk::ShaderStageFlagBits stage);
