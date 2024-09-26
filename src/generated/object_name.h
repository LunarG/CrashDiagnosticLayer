// *** THIS FILE IS GENERATED - DO NOT EDIT ***
// See object_name_generator.py for modifications
// Copyright 2023-2024 The Khronos Group Inc.
// Copyright 2023-2024 Valve Corporation
// Copyright 2023-2024 LunarG, Inc.
//
// SPDX-License-Identifier: Apache-2.0

#pragma once

#ifdef __cplusplus
#include <string>
#endif
#include <vulkan/vulkan.h>
static inline const char* string_ObjectName(VkObjectType input_value) {
    switch (input_value) {
        case VK_OBJECT_TYPE_BUFFER:
            return "VkBuffer";
        case VK_OBJECT_TYPE_IMAGE:
            return "VkImage";
        case VK_OBJECT_TYPE_INSTANCE:
            return "VkInstance";
        case VK_OBJECT_TYPE_PHYSICAL_DEVICE:
            return "VkPhysicalDevice";
        case VK_OBJECT_TYPE_DEVICE:
            return "VkDevice";
        case VK_OBJECT_TYPE_QUEUE:
            return "VkQueue";
        case VK_OBJECT_TYPE_SEMAPHORE:
            return "VkSemaphore";
        case VK_OBJECT_TYPE_COMMAND_BUFFER:
            return "VkCommandBuffer";
        case VK_OBJECT_TYPE_FENCE:
            return "VkFence";
        case VK_OBJECT_TYPE_DEVICE_MEMORY:
            return "VkDeviceMemory";
        case VK_OBJECT_TYPE_EVENT:
            return "VkEvent";
        case VK_OBJECT_TYPE_QUERY_POOL:
            return "VkQueryPool";
        case VK_OBJECT_TYPE_BUFFER_VIEW:
            return "VkBufferView";
        case VK_OBJECT_TYPE_IMAGE_VIEW:
            return "VkImageView";
        case VK_OBJECT_TYPE_SHADER_MODULE:
            return "VkShaderModule";
        case VK_OBJECT_TYPE_PIPELINE_CACHE:
            return "VkPipelineCache";
        case VK_OBJECT_TYPE_PIPELINE_LAYOUT:
            return "VkPipelineLayout";
        case VK_OBJECT_TYPE_PIPELINE:
            return "VkPipeline";
        case VK_OBJECT_TYPE_RENDER_PASS:
            return "VkRenderPass";
        case VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT:
            return "VkDescriptorSetLayout";
        case VK_OBJECT_TYPE_SAMPLER:
            return "VkSampler";
        case VK_OBJECT_TYPE_DESCRIPTOR_SET:
            return "VkDescriptorSet";
        case VK_OBJECT_TYPE_DESCRIPTOR_POOL:
            return "VkDescriptorPool";
        case VK_OBJECT_TYPE_FRAMEBUFFER:
            return "VkFramebuffer";
        case VK_OBJECT_TYPE_COMMAND_POOL:
            return "VkCommandPool";
        case VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION:
            return "VkSamplerYcbcrConversion";
        case VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE:
            return "VkDescriptorUpdateTemplate";
        case VK_OBJECT_TYPE_PRIVATE_DATA_SLOT:
            return "VkPrivateDataSlot";
        case VK_OBJECT_TYPE_SURFACE_KHR:
            return "VkSurfaceKHR";
        case VK_OBJECT_TYPE_SWAPCHAIN_KHR:
            return "VkSwapchainKHR";
        case VK_OBJECT_TYPE_DISPLAY_KHR:
            return "VkDisplayKHR";
        case VK_OBJECT_TYPE_DISPLAY_MODE_KHR:
            return "VkDisplayModeKHR";
        case VK_OBJECT_TYPE_VIDEO_SESSION_KHR:
            return "VkVideoSessionKHR";
        case VK_OBJECT_TYPE_VIDEO_SESSION_PARAMETERS_KHR:
            return "VkVideoSessionParametersKHR";
        case VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR:
            return "VkDeferredOperationKHR";
        case VK_OBJECT_TYPE_PIPELINE_BINARY_KHR:
            return "VkPipelineBinaryKHR";
        case VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT:
            return "VkDebugReportCallbackEXT";
        case VK_OBJECT_TYPE_CU_MODULE_NVX:
            return "VkCuModuleNVX";
        case VK_OBJECT_TYPE_CU_FUNCTION_NVX:
            return "VkCuFunctionNVX";
        case VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT:
            return "VkDebugUtilsMessengerEXT";
        case VK_OBJECT_TYPE_VALIDATION_CACHE_EXT:
            return "VkValidationCacheEXT";
        case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV:
            return "VkAccelerationStructureNV";
        case VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL:
            return "VkPerformanceConfigurationINTEL";
        case VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV:
            return "VkIndirectCommandsLayoutNV";
        case VK_OBJECT_TYPE_CUDA_MODULE_NV:
            return "VkCudaModuleNV";
        case VK_OBJECT_TYPE_CUDA_FUNCTION_NV:
            return "VkCudaFunctionNV";
        case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR:
            return "VkAccelerationStructureKHR";
        case VK_OBJECT_TYPE_BUFFER_COLLECTION_FUCHSIA:
            return "VkBufferCollectionFUCHSIA";
        case VK_OBJECT_TYPE_MICROMAP_EXT:
            return "VkMicromapEXT";
        case VK_OBJECT_TYPE_OPTICAL_FLOW_SESSION_NV:
            return "VkOpticalFlowSessionNV";
        case VK_OBJECT_TYPE_SHADER_EXT:
            return "VkShaderEXT";
        case VK_OBJECT_TYPE_INDIRECT_EXECUTION_SET_EXT:
            return "VkIndirectExecutionSetEXT";
        case VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_EXT:
            return "VkIndirectCommandsLayoutEXT";
        default:
            return "UNKNOWN";
    }
}
