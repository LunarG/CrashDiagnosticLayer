/*
 * Copyright (c) 2024 The Khronos Group Inc.
 * Copyright (c) 2024-2026 Valve Corporation
 * Copyright (c) 2024-2026 LunarG, Inc.
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
#include <gtest/gtest.h>

#include <vulkan/vulkan_raii.hpp>
#include <iostream>

#include "error_monitor.h"
#include "layer_settings.h"
#include "config.h"

TEST(CreateInstance, Basic) {
    vk::raii::Context context;

    bool layer_found = false;
    for (const auto& prop : context.enumerateInstanceLayerProperties()) {
        if (strcmp(prop.layerName, kLayerName) == 0) {
            layer_found = true;
        }
    }
    ASSERT_TRUE(layer_found);
    const auto* test_info = testing::UnitTest::GetInstance()->current_test_info();
    vk::ApplicationInfo applicationInfo(test_info->test_suite_name(), 1, test_info->name(), 1, VK_API_VERSION_1_1);

    std::vector<const char*> layers{kLayerName};

    vk::InstanceCreateInfo ci({}, nullptr, layers);
    vk::raii::Instance instance(context, ci);
}

static VKAPI_ATTR vk::Bool32 VKAPI_CALL DebugUtilsCallback(vk::DebugUtilsMessageSeverityFlagBitsEXT message_severity,
                                                           vk::DebugUtilsMessageTypeFlagsEXT message_types,
                                                           const vk::DebugUtilsMessengerCallbackDataEXT* callback_data,
                                                           void* user_data) {
    bool* got_message = reinterpret_cast<bool*>(user_data);
    if (strcmp(callback_data->pMessageIdName, "CDL") == 0) {
        *got_message = true;
    }
    return VK_FALSE;
}

TEST(CreateInstance, DebugUtilsMessenger) {
    vk::raii::Context context;
    const auto* test_info = testing::UnitTest::GetInstance()->current_test_info();
    vk::ApplicationInfo applicationInfo(test_info->test_suite_name(), 1, test_info->name(), 1, VK_API_VERSION_1_1);

    std::vector<const char*> layers{kLayerName};
    std::vector<const char*> instance_extensions{"VK_EXT_debug_utils"};
    bool got_message = false;
    vk::DebugUtilsMessengerCreateInfoEXT utils_ci({}, vk::DebugUtilsMessageSeverityFlagBitsEXT::eInfo,
                                                  vk::DebugUtilsMessageTypeFlagBitsEXT::eGeneral, DebugUtilsCallback,
                                                  &got_message, nullptr);

    vk::InstanceCreateInfo ci({}, nullptr, layers, instance_extensions, &utils_ci);
    vk::raii::Instance instance(context, ci);
    ASSERT_TRUE(got_message);
}

static VKAPI_ATTR vk::Bool32 VKAPI_CALL DebugReportCallback(vk::DebugReportFlagsEXT message_flags,
                                                            vk::DebugReportObjectTypeEXT, uint64_t, size_t, int32_t,
                                                            const char* prefix, const char* message, void* user_data) {
    bool* got_message = reinterpret_cast<bool*>(user_data);
    if (strcmp(prefix, "CDL") == 0) {
        *got_message = true;
    }
    return VK_FALSE;
}

TEST(CreateInstance, DebugReportMessenger) {
    vk::raii::Context context;
    const auto* test_info = testing::UnitTest::GetInstance()->current_test_info();
    vk::ApplicationInfo applicationInfo(test_info->test_suite_name(), 1, test_info->name(), 1, VK_API_VERSION_1_1);

    std::vector<const char*> layers{kLayerName};
    std::vector<const char*> instance_extensions{"VK_EXT_debug_report"};

    bool got_message = false;
    vk::DebugReportCallbackCreateInfoEXT report_ci(vk::DebugReportFlagBitsEXT::eInformation, DebugReportCallback,
                                                   &got_message);

    vk::InstanceCreateInfo ci({}, nullptr, layers, instance_extensions, &report_ci);
    vk::raii::Instance instance(context, ci);
    ASSERT_TRUE(got_message);
}

TEST(CreateInstance, AllLayerSettings) {
    vk::raii::Context context;

    const auto* test_info = testing::UnitTest::GetInstance()->current_test_info();
    vk::ApplicationInfo applicationInfo(test_info->test_suite_name(), 1, test_info->name(), 1, VK_API_VERSION_1_1);

    std::vector<const char*> layers{kLayerName};
    std::vector<const char*> instance_extensions{"VK_EXT_debug_utils", "VK_EXT_layer_settings"};

    bool got_message = false;
    vk::DebugUtilsMessengerCreateInfoEXT utils_ci(
        {}, vk::DebugUtilsMessageSeverityFlagBitsEXT::eInfo, vk::DebugUtilsMessageTypeFlagBitsEXT::eGeneral,
        vk::PFN_DebugUtilsMessengerCallbackEXT(DebugUtilsCallback), &got_message, nullptr);

    LayerSettings layer_settings;

    vk::InstanceCreateInfo ci({}, nullptr, layers, instance_extensions, layer_settings.BuildCreateInfo());
    vk::raii::Instance instance(context, ci);
}
