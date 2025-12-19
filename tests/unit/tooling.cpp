/*
 * Copyright (c) 2015-2025 The Khronos Group Inc.
 * Copyright (c) 2015-2025 Valve Corporation
 * Copyright (c) 2015-2025 LunarG, Inc.
 * Copyright (c) 2015-2025 Google, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 */

#include "test_fixtures.h"
#include <filesystem>
#include <regex>

class Tooling : public CDLTestBase {};


TEST_F(Tooling, InfoExt) {
    //TEST_DESCRIPTION("Basic usage calling Tooling Extension and verify layer results.");
    InitInstance();

    
    auto tool_properties = physical_device_.getToolPropertiesEXT();

    bool found_cdl = false;
    for (uint32_t i = 0; i < tool_properties.size(); i++) {
        if (strcmp(tool_properties[0].layer, "VK_LAYER_LUNARG_crash_diagnostic") == 0) {
            found_cdl = true;
            break;
        }
    }
    ASSERT_TRUE(found_cdl);
}

TEST_F(Tooling, InfoCore) {
    //TEST_DESCRIPTION("Basic usage calling Tooling Extension and verify layer results.");
    InitInstance();

    auto tool_properties = physical_device_.getToolProperties();

    bool found_cdl = false;
    for (uint32_t i = 0; i < tool_properties.size(); i++) {
        if (strcmp(tool_properties[0].layer, "VK_LAYER_LUNARG_crash_diagnostic") == 0) {
            found_cdl = true;
            break;
        }
    }
    ASSERT_TRUE(found_cdl);
}

#if 0
TEST_F(Tooling, PrivateDataExt) {
    TEST_DESCRIPTION("Basic usage calling private data extension.");
    AddRequiredExtensions(VK_EXT_PRIVATE_DATA_EXTENSION_NAME);
    AddRequiredFeature(vkt::Feature::privateData);
    RETURN_IF_SKIP(Init());

    if (IsPlatformMockICD()) {
        GTEST_SKIP() << "Private data not supported by MockICD";
    }

    VkPrivateDataSlot data_slot;
    VkPrivateDataSlotCreateInfo data_create_info = vku::InitStructHelper();
    data_create_info.flags = 0;
    vk::CreatePrivateDataSlotEXT(m_device->handle(), &data_create_info, nullptr, &data_slot);

    vkt::Sampler sampler(*m_device, SafeSaneSamplerCreateInfo());

    static const uint64_t data_value = 0x70AD;
    vk::SetPrivateDataEXT(m_device->handle(), VK_OBJECT_TYPE_SAMPLER, (uint64_t)sampler.handle(), data_slot, data_value);

    uint64_t data;
    vk::GetPrivateDataEXT(m_device->handle(), VK_OBJECT_TYPE_SAMPLER, (uint64_t)sampler.handle(), data_slot, &data);
    if (data != data_value) {
        m_errorMonitor->SetError("Got unexpected private data, %s.\n");
    }
    vk::DestroyPrivateDataSlotEXT(m_device->handle(), data_slot, nullptr);
}

TEST_F(Tooling, PrivateDataCore) {
    TEST_DESCRIPTION("Basic usage calling private data as core.");
    SetTargetApiVersion(VK_API_VERSION_1_3);
    AddRequiredFeature(vkt::Feature::privateData);
    RETURN_IF_SKIP(Init());

    if (IsPlatformMockICD()) {
        GTEST_SKIP() << "Private data not supported by MockICD";
    }

    VkPrivateDataSlot data_slot;
    VkPrivateDataSlotCreateInfo data_create_info = vku::InitStructHelper();
    data_create_info.flags = 0;
    vk::CreatePrivateDataSlot(m_device->handle(), &data_create_info, nullptr, &data_slot);

    vkt::Sampler sampler(*m_device, SafeSaneSamplerCreateInfo());

    static const uint64_t data_value = 0x70AD;
    vk::SetPrivateData(m_device->handle(), VK_OBJECT_TYPE_SAMPLER, (uint64_t)sampler.handle(), data_slot, data_value);

    uint64_t data;
    vk::GetPrivateData(m_device->handle(), VK_OBJECT_TYPE_SAMPLER, (uint64_t)sampler.handle(), data_slot, &data);
    if (data != data_value) {
        m_errorMonitor->SetError("Got unexpected private data, %s.\n");
    }
    vk::DestroyPrivateDataSlot(m_device->handle(), data_slot, nullptr);
}

TEST_F(Tooling, PrivateDataDevice) {
    TEST_DESCRIPTION("Test private data can set VkDevice.");
    SetTargetApiVersion(VK_API_VERSION_1_3);
    AddRequiredFeature(vkt::Feature::privateData);
    RETURN_IF_SKIP(Init());

    VkPrivateDataSlot data_slot;
    VkPrivateDataSlotCreateInfo data_create_info = vku::InitStructHelper();
    vk::CreatePrivateDataSlot(m_device->handle(), &data_create_info, NULL, &data_slot);

    static const uint64_t data_value = 0x70AD;
    vk::SetPrivateData(m_device->handle(), VK_OBJECT_TYPE_DEVICE, (uint64_t)device(), data_slot, data_value);
    uint64_t data;
    vk::GetPrivateData(m_device->handle(), VK_OBJECT_TYPE_DEVICE, (uint64_t)device(), data_slot, &data);

    vk::DestroyPrivateDataSlot(m_device->handle(), data_slot, nullptr);
}
#endif
