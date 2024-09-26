
/***************************************************************************
 *
 * Copyright (C) 2021 Google Inc.
 * Copyright (c) 2023-2024 LunarG, Inc.
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
 *
 * *** ---- WARNING! ----
 * ***   THIS FILE IS GENERATED - DO NOT EDIT
 * ***   Update source file command_printer_generator.py for modifications
 * *** ---- WARNING! ----
 *
 ****************************************************************************/

// NOLINTBEGIN

#pragma once

#include <yaml-cpp/emitter.h>
#include <vulkan/vulkan.h>

#include "command_common.h"
#include "object_name_db.h"

struct VkStruct {
    VkStructureType sType;
    void *pNext;
};

// Declare generic struct printer.
YAML::Emitter &PrintVkStruct(YAML::Emitter &os, const VkStruct *pStruct);

// Declare pNext chain printer.
YAML::Emitter &PrintNextPtr(YAML::Emitter &os, const void *pNext);

// Declare Handle stream operators

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBuffer &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkImage &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter& os, const VkInstance &a);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevice &a);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDevice &a);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkQueue &a);
#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSemaphore &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter& os, const VkCommandBuffer &a);
#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter &os, const VkFence &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkDeviceMemory &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkEvent &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkQueryPool &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkBufferView &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkImageView &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkShaderModule &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkPipelineCache &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkPipelineLayout &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkPipeline &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkRenderPass &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkDescriptorSetLayout &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkSampler &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkDescriptorSet &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkDescriptorPool &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkFramebuffer &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkCommandPool &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkSamplerYcbcrConversion &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkDescriptorUpdateTemplate &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkPrivateDataSlot &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkSurfaceKHR &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkSwapchainKHR &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkDisplayKHR &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkDisplayModeKHR &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkVideoSessionKHR &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkVideoSessionParametersKHR &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkDeferredOperationKHR &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkPipelineBinaryKHR &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkDebugReportCallbackEXT &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkCuModuleNVX &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkCuFunctionNVX &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkDebugUtilsMessengerEXT &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkValidationCacheEXT &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkAccelerationStructureNV &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkPerformanceConfigurationINTEL &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkIndirectCommandsLayoutNV &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkCudaModuleNV &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkCudaFunctionNV &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkAccelerationStructureKHR &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#ifdef VK_USE_PLATFORM_FUCHSIA
#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkBufferCollectionFUCHSIA &a);
#endif //VK_USE_64_BIT_PTR_DEFINES
#endif  // VK_USE_PLATFORM_FUCHSIA

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkMicromapEXT &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkOpticalFlowSessionNV &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkShaderEXT &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkIndirectExecutionSetEXT &a);
#endif //VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
YAML::Emitter &operator<<(YAML::Emitter& os, const VkIndirectCommandsLayoutEXT &a);
#endif //VK_USE_64_BIT_PTR_DEFINES



// Declare stream operators for enums.

YAML::Emitter &operator<<(YAML::Emitter &os, const VkResult &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkStructureType &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineCacheHeaderVersion &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageLayout &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkObjectType &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVendorId &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSystemAllocationScope &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkInternalAllocationType &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkFormat &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageTiling &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageType &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceType &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkQueryType &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSharingMode &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkComponentSwizzle &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageViewType &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBlendFactor &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBlendOp &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCompareOp &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDynamicState &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkFrontFace &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVertexInputRate &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPrimitiveTopology &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPolygonMode &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkStencilOp &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkLogicOp &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBorderColor &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkFilter &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSamplerAddressMode &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSamplerMipmapMode &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorType &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAttachmentLoadOp &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAttachmentStoreOp &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineBindPoint &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCommandBufferLevel &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkIndexType &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSubpassContents &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPointClippingBehavior &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkTessellationDomainOrigin &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSamplerYcbcrModelConversion &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSamplerYcbcrRange &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkChromaLocation &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorUpdateTemplateType &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDriverId &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkShaderFloatControlsIndependence &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSamplerReductionMode &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSemaphoreType &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPresentModeKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkColorSpaceKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkQueryResultStatusKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPerformanceCounterUnitKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPerformanceCounterScopeKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPerformanceCounterStorageKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkQueueGlobalPriorityKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkFragmentShadingRateCombinerOpKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineExecutableStatisticFormatKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeTuningModeKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkComponentTypeKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkScopeKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkLineRasterizationModeKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkTimeDomainKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceLayeredApiKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDebugReportObjectTypeEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRasterizationOrderAMD &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkShaderInfoTypeAMD &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkValidationCheckEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineRobustnessBufferBehaviorEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineRobustnessImageBehaviorEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDisplayPowerStateEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceEventTypeEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDisplayEventTypeEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkViewportCoordinateSwizzleNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDiscardRectangleModeEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkConservativeRasterizationModeEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBlendOverlapEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCoverageModulationModeNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkValidationCacheHeaderVersionEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkShadingRatePaletteEntryNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCoarseSampleOrderTypeNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRayTracingShaderGroupTypeKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkGeometryTypeKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureTypeKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCopyAccelerationStructureModeKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureMemoryRequirementsTypeNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMemoryOverallocationBehaviorAMD &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPerformanceConfigurationTypeINTEL &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkQueryPoolSamplingModeINTEL &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPerformanceOverrideTypeINTEL &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPerformanceParameterTypeINTEL &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPerformanceValueTypeINTEL &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkValidationFeatureEnableEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkValidationFeatureDisableEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCoverageReductionModeNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkProvokingVertexModeEXT &t);
#ifdef VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkFullScreenExclusiveEXT &t);
#endif  // VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkIndirectCommandsTokenTypeNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDepthBiasRepresentationEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceMemoryReportEventTypeEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkFragmentShadingRateTypeNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkFragmentShadingRateNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureMotionInstanceTypeNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceFaultAddressTypeEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceFaultVendorBinaryHeaderVersionEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceAddressBindingTypeEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMicromapTypeEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBuildMicromapModeEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCopyMicromapModeEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkOpacityMicromapFormatEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkOpacityMicromapSpecialIndexEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureCompatibilityKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureBuildTypeKHR &t);
#ifdef VK_ENABLE_BETA_EXTENSIONS
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDisplacementMicromapFormatNV &t);
#endif  // VK_ENABLE_BETA_EXTENSIONS
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSubpassMergeStatusEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDirectDriverLoadingModeLUNARG &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkOpticalFlowPerformanceLevelNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkOpticalFlowSessionBindingPointNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAntiLagModeAMD &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAntiLagStageAMD &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkShaderCodeTypeEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDepthClampModeEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRayTracingInvocationReorderModeNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkLayerSettingTypeEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkLatencyMarkerNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkOutOfBandQueueTypeNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBlockMatchWindowCompareModeQCOM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCubicFilterWeightsQCOM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkLayeredDriverUnderlyingApiMSFT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkIndirectExecutionSetInfoTypeEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkIndirectCommandsTokenTypeEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBuildAccelerationStructureModeKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkShaderGroupShaderKHR &t);

// Declare all stream operators.

YAML::Emitter &operator<<(YAML::Emitter &os, const VkExtent2D &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExtent3D &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkOffset2D &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkOffset3D &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRect2D &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBaseInStructure &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBaseOutStructure &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBufferMemoryBarrier &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDispatchIndirectCommand &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDrawIndexedIndirectCommand &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDrawIndirectCommand &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageSubresourceRange &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageMemoryBarrier &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMemoryBarrier &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineCacheHeaderVersionOne &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAllocationCallbacks &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkApplicationInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkFormatProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageFormatProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkInstanceCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMemoryHeap &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMemoryType &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceLimits &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMemoryProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceSparseProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkQueueFamilyProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceQueueCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExtensionProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkLayerProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSubmitInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMappedMemoryRange &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMemoryAllocateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMemoryRequirements &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSparseMemoryBind &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSparseBufferMemoryBindInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSparseImageOpaqueMemoryBindInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageSubresource &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSparseImageMemoryBind &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSparseImageMemoryBindInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBindSparseInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSparseImageFormatProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSparseImageMemoryRequirements &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkFenceCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSemaphoreCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkEventCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkQueryPoolCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBufferCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBufferViewCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSubresourceLayout &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkComponentMapping &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageViewCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkShaderModuleCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineCacheCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSpecializationMapEntry &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSpecializationInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineShaderStageCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkComputePipelineCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVertexInputBindingDescription &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVertexInputAttributeDescription &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineVertexInputStateCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineInputAssemblyStateCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineTessellationStateCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkViewport &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineViewportStateCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineRasterizationStateCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineMultisampleStateCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkStencilOpState &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineDepthStencilStateCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineColorBlendAttachmentState &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineColorBlendStateCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineDynamicStateCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkGraphicsPipelineCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPushConstantRange &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineLayoutCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSamplerCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCopyDescriptorSet &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorBufferInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorImageInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorPoolSize &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorPoolCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorSetAllocateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorSetLayoutBinding &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorSetLayoutCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkWriteDescriptorSet &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAttachmentDescription &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAttachmentReference &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkFramebufferCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSubpassDescription &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSubpassDependency &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRenderPassCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCommandPoolCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCommandBufferAllocateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCommandBufferInheritanceInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCommandBufferBeginInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBufferCopy &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageSubresourceLayers &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBufferImageCopy &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkClearColorValue &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkClearDepthStencilValue &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkClearValue &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkClearAttachment &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkClearRect &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageBlit &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageCopy &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageResolve &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRenderPassBeginInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceSubgroupProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBindBufferMemoryInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBindImageMemoryInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevice16BitStorageFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMemoryDedicatedRequirements &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMemoryDedicatedAllocateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMemoryAllocateFlagsInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceGroupRenderPassBeginInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceGroupCommandBufferBeginInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceGroupSubmitInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceGroupBindSparseInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBindBufferMemoryDeviceGroupInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBindImageMemoryDeviceGroupInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceGroupProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceGroupDeviceCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBufferMemoryRequirementsInfo2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageMemoryRequirementsInfo2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageSparseMemoryRequirementsInfo2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMemoryRequirements2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSparseImageMemoryRequirements2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceFeatures2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceProperties2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkFormatProperties2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageFormatProperties2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceImageFormatInfo2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkQueueFamilyProperties2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMemoryProperties2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSparseImageFormatProperties2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceSparseImageFormatInfo2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevicePointClippingProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkInputAttachmentAspectReference &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRenderPassInputAttachmentAspectCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageViewUsageCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineTessellationDomainOriginStateCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRenderPassMultiviewCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMultiviewFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMultiviewProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceVariablePointersFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceProtectedMemoryFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceProtectedMemoryProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceQueueInfo2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkProtectedSubmitInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSamplerYcbcrConversionCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSamplerYcbcrConversionInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBindImagePlaneMemoryInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImagePlaneMemoryRequirementsInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceSamplerYcbcrConversionFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSamplerYcbcrConversionImageFormatProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorUpdateTemplateEntry &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorUpdateTemplateCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExternalMemoryProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceExternalImageFormatInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExternalImageFormatProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceExternalBufferInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExternalBufferProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceIDProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExternalMemoryImageCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExternalMemoryBufferCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExportMemoryAllocateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceExternalFenceInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExternalFenceProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExportFenceCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExportSemaphoreCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceExternalSemaphoreInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExternalSemaphoreProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMaintenance3Properties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorSetLayoutSupport &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderDrawParametersFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceVulkan11Features &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceVulkan11Properties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceVulkan12Features &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkConformanceVersion &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceVulkan12Properties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageFormatListCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAttachmentDescription2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAttachmentReference2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSubpassDescription2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSubpassDependency2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRenderPassCreateInfo2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSubpassBeginInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSubpassEndInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevice8BitStorageFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDriverProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderAtomicInt64Features &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderFloat16Int8Features &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceFloatControlsProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorSetLayoutBindingFlagsCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDescriptorIndexingFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDescriptorIndexingProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorSetVariableDescriptorCountAllocateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorSetVariableDescriptorCountLayoutSupport &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSubpassDescriptionDepthStencilResolve &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDepthStencilResolveProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceScalarBlockLayoutFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageStencilUsageCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSamplerReductionModeCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceSamplerFilterMinmaxProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceVulkanMemoryModelFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceImagelessFramebufferFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkFramebufferAttachmentImageInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkFramebufferAttachmentsCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRenderPassAttachmentBeginInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceUniformBufferStandardLayoutFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAttachmentReferenceStencilLayout &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAttachmentDescriptionStencilLayout &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceHostQueryResetFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceTimelineSemaphoreFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceTimelineSemaphoreProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSemaphoreTypeCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkTimelineSemaphoreSubmitInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSemaphoreWaitInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSemaphoreSignalInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceBufferDeviceAddressFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBufferDeviceAddressInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBufferOpaqueCaptureAddressCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMemoryOpaqueCaptureAddressAllocateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceMemoryOpaqueCaptureAddressInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceVulkan13Features &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceVulkan13Properties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineCreationFeedback &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineCreationFeedbackCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderTerminateInvocationFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceToolProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevicePrivateDataFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDevicePrivateDataCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPrivateDataSlotCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevicePipelineCreationCacheControlFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMemoryBarrier2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBufferMemoryBarrier2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageMemoryBarrier2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDependencyInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSemaphoreSubmitInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCommandBufferSubmitInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSubmitInfo2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceSynchronization2Features &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceImageRobustnessFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBufferCopy2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCopyBufferInfo2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageCopy2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCopyImageInfo2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBufferImageCopy2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCopyBufferToImageInfo2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCopyImageToBufferInfo2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageBlit2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBlitImageInfo2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageResolve2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkResolveImageInfo2 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceSubgroupSizeControlFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceSubgroupSizeControlProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineShaderStageRequiredSubgroupSizeCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceInlineUniformBlockFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceInlineUniformBlockProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkWriteDescriptorSetInlineUniformBlock &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorPoolInlineUniformBlockCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceTextureCompressionASTCHDRFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRenderingAttachmentInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRenderingInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineRenderingCreateInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDynamicRenderingFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCommandBufferInheritanceRenderingInfo &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderIntegerDotProductFeatures &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderIntegerDotProductProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceTexelBufferAlignmentProperties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkFormatProperties3 &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMaintenance4Features &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMaintenance4Properties &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceBufferMemoryRequirements &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceImageMemoryRequirements &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSurfaceCapabilitiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSurfaceFormatKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSwapchainCreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPresentInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageSwapchainCreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBindImageMemorySwapchainInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAcquireNextImageInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceGroupPresentCapabilitiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceGroupPresentInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceGroupSwapchainCreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDisplayModeParametersKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDisplayModeCreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDisplayModePropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDisplayPlaneCapabilitiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDisplayPlanePropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDisplayPropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDisplaySurfaceCreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDisplayPresentInfoKHR &t);
#ifdef VK_USE_PLATFORM_XLIB_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkXlibSurfaceCreateInfoKHR &t);
#endif  // VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkXcbSurfaceCreateInfoKHR &t);
#endif  // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkWaylandSurfaceCreateInfoKHR &t);
#endif  // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAndroidSurfaceCreateInfoKHR &t);
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkWin32SurfaceCreateInfoKHR &t);
#endif  // VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkQueueFamilyQueryResultStatusPropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkQueueFamilyVideoPropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoProfileInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoProfileListInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoCapabilitiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceVideoFormatInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoFormatPropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoPictureResourceInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoReferenceSlotInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoSessionMemoryRequirementsKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBindVideoSessionMemoryInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoSessionCreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoSessionParametersCreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoSessionParametersUpdateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoBeginCodingInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEndCodingInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoCodingControlInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoDecodeCapabilitiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoDecodeUsageInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoDecodeInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH264CapabilitiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH264QpKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH264QualityLevelPropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH264SessionCreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH264SessionParametersAddInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH264SessionParametersCreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH264SessionParametersGetInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH264SessionParametersFeedbackInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH264NaluSliceInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH264PictureInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH264DpbSlotInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH264ProfileInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH264RateControlInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH264FrameSizeKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH264RateControlLayerInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH264GopRemainingFrameInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH265CapabilitiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH265SessionCreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH265QpKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH265QualityLevelPropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH265SessionParametersAddInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH265SessionParametersCreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH265SessionParametersGetInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH265SessionParametersFeedbackInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH265NaluSliceSegmentInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH265PictureInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH265DpbSlotInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH265ProfileInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH265RateControlInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH265FrameSizeKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH265RateControlLayerInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeH265GopRemainingFrameInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoDecodeH264ProfileInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoDecodeH264CapabilitiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoDecodeH264SessionParametersAddInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoDecodeH264SessionParametersCreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoDecodeH264PictureInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoDecodeH264DpbSlotInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRenderingFragmentShadingRateAttachmentInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRenderingFragmentDensityMapAttachmentInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAttachmentSampleCountInfoAMD &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMultiviewPerViewAttributesInfoNVX &t);
#ifdef VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImportMemoryWin32HandleInfoKHR &t);
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExportMemoryWin32HandleInfoKHR &t);
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMemoryWin32HandlePropertiesKHR &t);
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMemoryGetWin32HandleInfoKHR &t);
#endif  // VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImportMemoryFdInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMemoryFdPropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMemoryGetFdInfoKHR &t);
#ifdef VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkWin32KeyedMutexAcquireReleaseInfoKHR &t);
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImportSemaphoreWin32HandleInfoKHR &t);
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExportSemaphoreWin32HandleInfoKHR &t);
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkD3D12FenceSubmitInfoKHR &t);
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSemaphoreGetWin32HandleInfoKHR &t);
#endif  // VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImportSemaphoreFdInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSemaphoreGetFdInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevicePushDescriptorPropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRectLayerKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPresentRegionKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPresentRegionsKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSharedPresentSurfaceCapabilitiesKHR &t);
#ifdef VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImportFenceWin32HandleInfoKHR &t);
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExportFenceWin32HandleInfoKHR &t);
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkFenceGetWin32HandleInfoKHR &t);
#endif  // VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImportFenceFdInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkFenceGetFdInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevicePerformanceQueryFeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevicePerformanceQueryPropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPerformanceCounterKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPerformanceCounterDescriptionKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkQueryPoolPerformanceCreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPerformanceCounterResultKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAcquireProfilingLockInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPerformanceQuerySubmitInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceSurfaceInfo2KHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSurfaceCapabilities2KHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSurfaceFormat2KHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDisplayProperties2KHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDisplayPlaneProperties2KHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDisplayModeProperties2KHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDisplayPlaneInfo2KHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDisplayPlaneCapabilities2KHR &t);
#ifdef VK_ENABLE_BETA_EXTENSIONS
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevicePortabilitySubsetFeaturesKHR &t);
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevicePortabilitySubsetPropertiesKHR &t);
#endif  // VK_ENABLE_BETA_EXTENSIONS
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderClockFeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoDecodeH265ProfileInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoDecodeH265CapabilitiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoDecodeH265SessionParametersAddInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoDecodeH265SessionParametersCreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoDecodeH265PictureInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoDecodeH265DpbSlotInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceQueueGlobalPriorityCreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkQueueFamilyGlobalPriorityPropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkFragmentShadingRateAttachmentInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineFragmentShadingRateStateCreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceFragmentShadingRateFeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceFragmentShadingRatePropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceFragmentShadingRateKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRenderingAttachmentLocationInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRenderingInputAttachmentIndexInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderQuadControlFeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSurfaceProtectedCapabilitiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevicePresentWaitFeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineExecutablePropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineExecutableInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineExecutableStatisticValueKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineExecutableStatisticKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineExecutableInternalRepresentationKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMemoryMapInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMemoryUnmapInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineLibraryCreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPresentIdKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevicePresentIdFeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeCapabilitiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkQueryPoolVideoEncodeFeedbackCreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeUsageInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeRateControlLayerInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeRateControlInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeQualityLevelPropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeQualityLevelInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeSessionParametersGetInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeSessionParametersFeedbackInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkQueueFamilyCheckpointProperties2NV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCheckpointData2NV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkTraceRaysIndirectCommand2KHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMaintenance5FeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMaintenance5PropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRenderingAreaInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageSubresource2KHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceImageSubresourceInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSubresourceLayout2KHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineCreateFlags2CreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBufferUsageFlags2CreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevicePipelineBinaryFeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevicePipelineBinaryPropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDevicePipelineBinaryInternalCacheControlKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineBinaryKeyKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineBinaryDataKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineBinaryKeysAndDataKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineCreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineBinaryCreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineBinaryInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkReleaseCapturedPipelineDataInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineBinaryDataInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineBinaryHandlesInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCooperativeMatrixPropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceCooperativeMatrixFeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceCooperativeMatrixPropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoDecodeAV1ProfileInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoDecodeAV1CapabilitiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoDecodeAV1SessionParametersCreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoDecodeAV1PictureInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoDecodeAV1DpbSlotInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceVideoMaintenance1FeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoInlineQueryInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVertexInputBindingDivisorDescriptionKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineVertexInputDivisorStateCreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderFloatControls2FeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceIndexTypeUint8FeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceLineRasterizationFeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceLineRasterizationPropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineRasterizationLineStateCreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCalibratedTimestampInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderExpectAssumeFeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMaintenance6FeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMaintenance6PropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBindMemoryStatusKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBindDescriptorSetsInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPushConstantsInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPushDescriptorSetInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPushDescriptorSetWithTemplateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSetDescriptorBufferOffsetsInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBindDescriptorBufferEmbeddedSamplersInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMaintenance7FeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMaintenance7PropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceLayeredApiPropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceLayeredApiPropertiesListKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceLayeredApiVulkanPropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDebugReportCallbackCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineRasterizationStateRasterizationOrderAMD &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDebugMarkerObjectNameInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDebugMarkerObjectTagInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDebugMarkerMarkerInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDedicatedAllocationImageCreateInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDedicatedAllocationBufferCreateInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDedicatedAllocationMemoryAllocateInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceTransformFeedbackFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceTransformFeedbackPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineRasterizationStateStreamCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCuModuleCreateInfoNVX &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCuFunctionCreateInfoNVX &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCuLaunchInfoNVX &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageViewHandleInfoNVX &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageViewAddressPropertiesNVX &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkTextureLODGatherFormatPropertiesAMD &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkShaderResourceUsageAMD &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkShaderStatisticsInfoAMD &t);
#ifdef VK_USE_PLATFORM_GGP
YAML::Emitter &operator<<(YAML::Emitter &os, const VkStreamDescriptorSurfaceCreateInfoGGP &t);
#endif  // VK_USE_PLATFORM_GGP
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceCornerSampledImageFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExternalImageFormatPropertiesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExternalMemoryImageCreateInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExportMemoryAllocateInfoNV &t);
#ifdef VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImportMemoryWin32HandleInfoNV &t);
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExportMemoryWin32HandleInfoNV &t);
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkWin32KeyedMutexAcquireReleaseInfoNV &t);
#endif  // VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkValidationFlagsEXT &t);
#ifdef VK_USE_PLATFORM_VI_NN
YAML::Emitter &operator<<(YAML::Emitter &os, const VkViSurfaceCreateInfoNN &t);
#endif  // VK_USE_PLATFORM_VI_NN
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageViewASTCDecodeModeEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceASTCDecodeFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevicePipelineRobustnessFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevicePipelineRobustnessPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineRobustnessCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkConditionalRenderingBeginInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceConditionalRenderingFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCommandBufferInheritanceConditionalRenderingInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkViewportWScalingNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineViewportWScalingStateCreateInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSurfaceCapabilities2EXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDisplayPowerInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceEventInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDisplayEventInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSwapchainCounterCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRefreshCycleDurationGOOGLE &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPastPresentationTimingGOOGLE &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPresentTimeGOOGLE &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPresentTimesInfoGOOGLE &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkViewportSwizzleNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineViewportSwizzleStateCreateInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDiscardRectanglePropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineDiscardRectangleStateCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceConservativeRasterizationPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineRasterizationConservativeStateCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDepthClipEnableFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineRasterizationDepthClipStateCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkXYColorEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkHdrMetadataEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG &t);
#ifdef VK_USE_PLATFORM_IOS_MVK
YAML::Emitter &operator<<(YAML::Emitter &os, const VkIOSSurfaceCreateInfoMVK &t);
#endif  // VK_USE_PLATFORM_IOS_MVK
#ifdef VK_USE_PLATFORM_MACOS_MVK
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMacOSSurfaceCreateInfoMVK &t);
#endif  // VK_USE_PLATFORM_MACOS_MVK
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDebugUtilsLabelEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDebugUtilsObjectNameInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDebugUtilsMessengerCallbackDataEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDebugUtilsMessengerCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDebugUtilsObjectTagInfoEXT &t);
#ifdef VK_USE_PLATFORM_ANDROID_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAndroidHardwareBufferUsageANDROID &t);
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAndroidHardwareBufferPropertiesANDROID &t);
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAndroidHardwareBufferFormatPropertiesANDROID &t);
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImportAndroidHardwareBufferInfoANDROID &t);
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMemoryGetAndroidHardwareBufferInfoANDROID &t);
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExternalFormatANDROID &t);
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAndroidHardwareBufferFormatProperties2ANDROID &t);
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_ENABLE_BETA_EXTENSIONS
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderEnqueueFeaturesAMDX &t);
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderEnqueuePropertiesAMDX &t);
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExecutionGraphPipelineScratchSizeAMDX &t);
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExecutionGraphPipelineCreateInfoAMDX &t);
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceOrHostAddressConstAMDX &t);
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDispatchGraphInfoAMDX &t);
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDispatchGraphCountInfoAMDX &t);
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineShaderStageNodeCreateInfoAMDX &t);
#endif  // VK_ENABLE_BETA_EXTENSIONS
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSampleLocationEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSampleLocationsInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAttachmentSampleLocationsEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSubpassSampleLocationsEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRenderPassSampleLocationsBeginInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineSampleLocationsStateCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceSampleLocationsPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMultisamplePropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineColorBlendAdvancedStateCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineCoverageToColorStateCreateInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineCoverageModulationStateCreateInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDrmFormatModifierPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDrmFormatModifierPropertiesListEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceImageDrmFormatModifierInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageDrmFormatModifierListCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageDrmFormatModifierExplicitCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageDrmFormatModifierPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDrmFormatModifierProperties2EXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDrmFormatModifierPropertiesList2EXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkValidationCacheCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkShaderModuleValidationCacheCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkShadingRatePaletteNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineViewportShadingRateImageStateCreateInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShadingRateImageFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShadingRateImagePropertiesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCoarseSampleLocationNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCoarseSampleOrderCustomNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRayTracingShaderGroupCreateInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRayTracingPipelineCreateInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkGeometryTrianglesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkGeometryAABBNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkGeometryDataNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkGeometryNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureCreateInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBindAccelerationStructureMemoryInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkWriteDescriptorSetAccelerationStructureNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureMemoryRequirementsInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceRayTracingPropertiesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkTransformMatrixKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAabbPositionsKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureInstanceKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineRepresentativeFragmentTestStateCreateInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceImageViewImageFormatInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkFilterCubicImageViewImageFormatPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImportMemoryHostPointerInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMemoryHostPointerPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceExternalMemoryHostPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineCompilerControlCreateInfoAMD &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderCorePropertiesAMD &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceMemoryOverallocationCreateInfoAMD &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT &t);
#ifdef VK_USE_PLATFORM_GGP
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPresentFrameTokenGGP &t);
#endif  // VK_USE_PLATFORM_GGP
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMeshShaderFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMeshShaderPropertiesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDrawMeshTasksIndirectCommandNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderImageFootprintFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineViewportExclusiveScissorStateCreateInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceExclusiveScissorFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkQueueFamilyCheckpointPropertiesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCheckpointDataNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPerformanceValueDataINTEL &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPerformanceValueINTEL &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkInitializePerformanceApiInfoINTEL &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkQueryPoolPerformanceQueryCreateInfoINTEL &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPerformanceMarkerInfoINTEL &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPerformanceStreamMarkerInfoINTEL &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPerformanceOverrideInfoINTEL &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPerformanceConfigurationAcquireInfoINTEL &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevicePCIBusInfoPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDisplayNativeHdrSurfaceCapabilitiesAMD &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSwapchainDisplayNativeHdrCreateInfoAMD &t);
#ifdef VK_USE_PLATFORM_FUCHSIA
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImagePipeSurfaceCreateInfoFUCHSIA &t);
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_METAL_EXT
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMetalSurfaceCreateInfoEXT &t);
#endif  // VK_USE_PLATFORM_METAL_EXT
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceFragmentDensityMapFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceFragmentDensityMapPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRenderPassFragmentDensityMapCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderCoreProperties2AMD &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceCoherentMemoryFeaturesAMD &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMemoryBudgetPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMemoryPriorityFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMemoryPriorityAllocateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBufferDeviceAddressCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkValidationFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCooperativeMatrixPropertiesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceCooperativeMatrixFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceCooperativeMatrixPropertiesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceCoverageReductionModeFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineCoverageReductionStateCreateInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkFramebufferMixedSamplesCombinationNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceProvokingVertexFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceProvokingVertexPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineRasterizationProvokingVertexStateCreateInfoEXT &t);
#ifdef VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSurfaceFullScreenExclusiveInfoEXT &t);
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSurfaceCapabilitiesFullScreenExclusiveEXT &t);
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSurfaceFullScreenExclusiveWin32InfoEXT &t);
#endif  // VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkHeadlessSurfaceCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceHostImageCopyFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceHostImageCopyPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMemoryToImageCopyEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageToMemoryCopyEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCopyMemoryToImageInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCopyImageToMemoryInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCopyImageToImageInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkHostImageLayoutTransitionInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSubresourceHostMemcpySizeEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkHostImageCopyDevicePerformanceQueryEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMapMemoryPlacedFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMapMemoryPlacedPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMemoryMapPlacedInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSurfacePresentModeEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSurfacePresentScalingCapabilitiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSurfacePresentModeCompatibilityEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSwapchainPresentFenceInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSwapchainPresentModesCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSwapchainPresentModeInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSwapchainPresentScalingCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkReleaseSwapchainImagesInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkGraphicsShaderGroupCreateInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkGraphicsPipelineShaderGroupsCreateInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBindShaderGroupIndirectCommandNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBindIndexBufferIndirectCommandNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBindVertexBufferIndirectCommandNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSetStateFlagsIndirectCommandNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkIndirectCommandsStreamNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkIndirectCommandsLayoutTokenNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkIndirectCommandsLayoutCreateInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkGeneratedCommandsInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkGeneratedCommandsMemoryRequirementsInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceInheritedViewportScissorFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCommandBufferInheritanceViewportScissorInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRenderPassTransformBeginInfoQCOM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCommandBufferInheritanceRenderPassTransformInfoQCOM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDepthBiasControlFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDepthBiasInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDepthBiasRepresentationInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceMemoryReportCallbackDataEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceDeviceMemoryReportCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceRobustness2FeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceRobustness2PropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSamplerCustomBorderColorCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceCustomBorderColorPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceCustomBorderColorFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevicePresentBarrierFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSurfaceCapabilitiesPresentBarrierNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSwapchainPresentBarrierCreateInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDiagnosticsConfigFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceDiagnosticsConfigCreateInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCudaModuleCreateInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCudaFunctionCreateInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCudaLaunchInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceCudaKernelLaunchFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceCudaKernelLaunchPropertiesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkQueryLowLatencySupportNV &t);
#ifdef VK_USE_PLATFORM_METAL_EXT
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExportMetalObjectCreateInfoEXT &t);
#endif  // VK_USE_PLATFORM_METAL_EXT
#ifdef VK_USE_PLATFORM_METAL_EXT
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExportMetalObjectsInfoEXT &t);
#endif  // VK_USE_PLATFORM_METAL_EXT
#ifdef VK_USE_PLATFORM_METAL_EXT
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExportMetalDeviceInfoEXT &t);
#endif  // VK_USE_PLATFORM_METAL_EXT
#ifdef VK_USE_PLATFORM_METAL_EXT
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExportMetalCommandQueueInfoEXT &t);
#endif  // VK_USE_PLATFORM_METAL_EXT
#ifdef VK_USE_PLATFORM_METAL_EXT
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExportMetalBufferInfoEXT &t);
#endif  // VK_USE_PLATFORM_METAL_EXT
#ifdef VK_USE_PLATFORM_METAL_EXT
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImportMetalBufferInfoEXT &t);
#endif  // VK_USE_PLATFORM_METAL_EXT
#ifdef VK_USE_PLATFORM_METAL_EXT
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExportMetalTextureInfoEXT &t);
#endif  // VK_USE_PLATFORM_METAL_EXT
#ifdef VK_USE_PLATFORM_METAL_EXT
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImportMetalTextureInfoEXT &t);
#endif  // VK_USE_PLATFORM_METAL_EXT
#ifdef VK_USE_PLATFORM_METAL_EXT
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExportMetalIOSurfaceInfoEXT &t);
#endif  // VK_USE_PLATFORM_METAL_EXT
#ifdef VK_USE_PLATFORM_METAL_EXT
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImportMetalIOSurfaceInfoEXT &t);
#endif  // VK_USE_PLATFORM_METAL_EXT
#ifdef VK_USE_PLATFORM_METAL_EXT
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExportMetalSharedEventInfoEXT &t);
#endif  // VK_USE_PLATFORM_METAL_EXT
#ifdef VK_USE_PLATFORM_METAL_EXT
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImportMetalSharedEventInfoEXT &t);
#endif  // VK_USE_PLATFORM_METAL_EXT
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDescriptorBufferPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDescriptorBufferFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorAddressInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorBufferBindingInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorBufferBindingPushDescriptorBufferHandleEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorDataEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorGetInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBufferCaptureDescriptorDataInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageCaptureDescriptorDataInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageViewCaptureDescriptorDataInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSamplerCaptureDescriptorDataInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkOpaqueCaptureDescriptorDataCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureCaptureDescriptorDataInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkGraphicsPipelineLibraryCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineFragmentShadingRateEnumStateCreateInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceOrHostAddressConstKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureGeometryMotionTrianglesDataNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureMotionInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureMatrixMotionInstanceNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSRTDataNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureSRTMotionInstanceNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureMotionInstanceDataNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureMotionInstanceNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceFragmentDensityMap2PropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCopyCommandTransformInfoQCOM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceImageCompressionControlFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageCompressionControlEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageCompressionPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevice4444FormatsFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceFaultFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceFaultCountsEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceFaultAddressInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceFaultVendorInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceFaultInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceFaultVendorBinaryHeaderVersionOneEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT &t);
#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDirectFBSurfaceCreateInfoEXT &t);
#endif  // VK_USE_PLATFORM_DIRECTFB_EXT
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMutableDescriptorTypeListEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMutableDescriptorTypeCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVertexInputBindingDescription2EXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkVertexInputAttributeDescription2EXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDrmPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceAddressBindingReportFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceAddressBindingCallbackDataEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDepthClipControlFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineViewportDepthClipControlCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT &t);
#ifdef VK_USE_PLATFORM_FUCHSIA
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImportMemoryZirconHandleInfoFUCHSIA &t);
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMemoryZirconHandlePropertiesFUCHSIA &t);
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMemoryGetZirconHandleInfoFUCHSIA &t);
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImportSemaphoreZirconHandleInfoFUCHSIA &t);
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSemaphoreGetZirconHandleInfoFUCHSIA &t);
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBufferCollectionCreateInfoFUCHSIA &t);
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImportMemoryBufferCollectionFUCHSIA &t);
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBufferCollectionImageCreateInfoFUCHSIA &t);
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBufferCollectionConstraintsInfoFUCHSIA &t);
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBufferConstraintsInfoFUCHSIA &t);
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBufferCollectionBufferCreateInfoFUCHSIA &t);
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSysmemColorSpaceFUCHSIA &t);
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBufferCollectionPropertiesFUCHSIA &t);
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageFormatConstraintsInfoFUCHSIA &t);
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageConstraintsInfoFUCHSIA &t);
#endif  // VK_USE_PLATFORM_FUCHSIA
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSubpassShadingPipelineCreateInfoHUAWEI &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceSubpassShadingFeaturesHUAWEI &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceSubpassShadingPropertiesHUAWEI &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMemoryGetRemoteAddressInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelinePropertiesIdentifierEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevicePipelinePropertiesFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceFrameBoundaryFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkFrameBoundaryEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSubpassResolvePerformanceQueryEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMultisampledRenderToSingleSampledInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT &t);
#ifdef VK_USE_PLATFORM_SCREEN_QNX
YAML::Emitter &operator<<(YAML::Emitter &os, const VkScreenSurfaceCreateInfoQNX &t);
#endif  // VK_USE_PLATFORM_SCREEN_QNX
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceColorWriteEnableFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineColorWriteCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceImageViewMinLodFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageViewMinLodCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMultiDrawFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMultiDrawPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMultiDrawInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMultiDrawIndexedInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceImage2DViewOf3DFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderTileImageFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderTileImagePropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMicromapUsageEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceOrHostAddressKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMicromapBuildInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMicromapCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceOpacityMicromapFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceOpacityMicromapPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMicromapVersionInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCopyMicromapToMemoryInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCopyMemoryToMicromapInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCopyMicromapInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMicromapBuildSizesInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureTrianglesOpacityMicromapEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMicromapTriangleEXT &t);
#ifdef VK_ENABLE_BETA_EXTENSIONS
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDisplacementMicromapFeaturesNV &t);
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDisplacementMicromapPropertiesNV &t);
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureTrianglesDisplacementMicromapNV &t);
#endif  // VK_ENABLE_BETA_EXTENSIONS
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSamplerBorderColorComponentMappingCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderCorePropertiesARM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceQueueShaderCoreControlCreateInfoARM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceSchedulingControlsFeaturesARM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceSchedulingControlsPropertiesARM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageViewSlicedCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorSetBindingReferenceVALVE &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorSetLayoutHostMappingInfoVALVE &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDepthClampZeroOneFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceRenderPassStripedFeaturesARM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceRenderPassStripedPropertiesARM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRenderPassStripeInfoARM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRenderPassStripeBeginInfoARM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRenderPassStripeSubmitInfoARM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSubpassFragmentDensityMapOffsetEndInfoQCOM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCopyMemoryIndirectCommandNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCopyMemoryToImageIndirectCommandNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceCopyMemoryIndirectFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceCopyMemoryIndirectPropertiesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDecompressMemoryRegionNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMemoryDecompressionFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMemoryDecompressionPropertiesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkComputePipelineIndirectBufferInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineIndirectDeviceAddressInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBindPipelineIndirectCommandNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceLinearColorAttachmentFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageViewSampleWeightCreateInfoQCOM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceImageProcessingFeaturesQCOM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceImageProcessingPropertiesQCOM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceNestedCommandBufferFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceNestedCommandBufferPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExternalMemoryAcquireUnmodifiedEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceExtendedDynamicState3PropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkColorBlendEquationEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkColorBlendAdvancedEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRenderPassCreationControlEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRenderPassCreationFeedbackInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRenderPassCreationFeedbackCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRenderPassSubpassFeedbackInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRenderPassSubpassFeedbackCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDirectDriverLoadingInfoLUNARG &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDirectDriverLoadingListLUNARG &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineShaderStageModuleIdentifierCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkShaderModuleIdentifierEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceOpticalFlowFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceOpticalFlowPropertiesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkOpticalFlowImageFormatInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkOpticalFlowImageFormatPropertiesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkOpticalFlowSessionCreateInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkOpticalFlowSessionCreatePrivateDataInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkOpticalFlowExecuteInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceLegacyDitheringFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevicePipelineProtectedAccessFeaturesEXT &t);
#ifdef VK_USE_PLATFORM_ANDROID_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceExternalFormatResolveFeaturesANDROID &t);
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceExternalFormatResolvePropertiesANDROID &t);
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAndroidHardwareBufferFormatResolvePropertiesANDROID &t);
#endif  // VK_USE_PLATFORM_ANDROID_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceAntiLagFeaturesAMD &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAntiLagPresentationInfoAMD &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAntiLagDataAMD &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderObjectFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderObjectPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkShaderCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDepthClampRangeEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceTilePropertiesFeaturesQCOM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkTilePropertiesQCOM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceAmigoProfilingFeaturesSEC &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAmigoProfilingSubmitInfoSEC &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkLayerSettingEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkLayerSettingsCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkLatencySleepModeInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkLatencySleepInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSetLatencyMarkerInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkLatencyTimingsFrameReportNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkGetLatencyMarkerInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkLatencySubmissionPresentIdNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSwapchainLatencyCreateInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkOutOfBandQueueTypeInfoNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkLatencySurfaceCapabilitiesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevicePerStageDescriptorSetFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceImageProcessing2FeaturesQCOM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceImageProcessing2PropertiesQCOM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSamplerBlockMatchWindowCreateInfoQCOM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceCubicWeightsFeaturesQCOM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSamplerCubicWeightsCreateInfoQCOM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBlitImageCubicWeightsInfoQCOM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceYcbcrDegammaFeaturesQCOM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceCubicClampFeaturesQCOM &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT &t);
#ifdef VK_USE_PLATFORM_SCREEN_QNX
YAML::Emitter &operator<<(YAML::Emitter &os, const VkScreenBufferPropertiesQNX &t);
#endif  // VK_USE_PLATFORM_SCREEN_QNX
#ifdef VK_USE_PLATFORM_SCREEN_QNX
YAML::Emitter &operator<<(YAML::Emitter &os, const VkScreenBufferFormatPropertiesQNX &t);
#endif  // VK_USE_PLATFORM_SCREEN_QNX
#ifdef VK_USE_PLATFORM_SCREEN_QNX
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImportScreenBufferInfoQNX &t);
#endif  // VK_USE_PLATFORM_SCREEN_QNX
#ifdef VK_USE_PLATFORM_SCREEN_QNX
YAML::Emitter &operator<<(YAML::Emitter &os, const VkExternalFormatQNX &t);
#endif  // VK_USE_PLATFORM_SCREEN_QNX
#ifdef VK_USE_PLATFORM_SCREEN_QNX
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX &t);
#endif  // VK_USE_PLATFORM_SCREEN_QNX
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceLayeredDriverPropertiesMSFT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceRawAccessChainsFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceCommandBufferInheritanceFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceRayTracingValidationFeaturesNV &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkGeneratedCommandsMemoryRequirementsInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkIndirectExecutionSetPipelineInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkIndirectExecutionSetShaderLayoutInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkIndirectExecutionSetShaderInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkIndirectExecutionSetInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkIndirectExecutionSetCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkGeneratedCommandsInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkWriteIndirectExecutionSetPipelineEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkIndirectCommandsPushConstantTokenEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkIndirectCommandsVertexBufferTokenEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkIndirectCommandsIndexBufferTokenEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkIndirectCommandsExecutionSetTokenEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkIndirectCommandsTokenDataEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkIndirectCommandsLayoutTokenEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkIndirectCommandsLayoutCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDrawIndirectCountIndirectCommandEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBindVertexBufferIndirectCommandEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkBindIndexBufferIndirectCommandEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkGeneratedCommandsPipelineInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkGeneratedCommandsShaderInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkWriteIndirectExecutionSetShaderEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceImageAlignmentControlFeaturesMESA &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceImageAlignmentControlPropertiesMESA &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageAlignmentControlCreateInfoMESA &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceDepthClampControlFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineViewportDepthClampControlCreateInfoEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureBuildRangeInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureGeometryTrianglesDataKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureGeometryAabbsDataKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureGeometryInstancesDataKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureGeometryDataKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureGeometryKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureBuildGeometryInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureCreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkWriteDescriptorSetAccelerationStructureKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceAccelerationStructureFeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceAccelerationStructurePropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureDeviceAddressInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureVersionInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCopyAccelerationStructureToMemoryInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCopyMemoryToAccelerationStructureInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkCopyAccelerationStructureInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureBuildSizesInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRayTracingShaderGroupCreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRayTracingPipelineInterfaceCreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkRayTracingPipelineCreateInfoKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceRayTracingPipelineFeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceRayTracingPipelinePropertiesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkStridedDeviceAddressRegionKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkTraceRaysIndirectCommandKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceRayQueryFeaturesKHR &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMeshShaderFeaturesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceMeshShaderPropertiesEXT &t);
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDrawMeshTasksIndirectCommandEXT &t);

// Declare print functions.
class ObjectInfoDB;
class CommandPrinter {
   public:
    void SetNameResolver(const ObjectInfoDB *name_resolver);
    void PrintCommandParameters(YAML::Emitter &os, const Command &cmd);
    void PrintBeginCommandBufferArgs(YAML::Emitter &os, const BeginCommandBufferArgs &args);
    void PrintEndCommandBufferArgs(YAML::Emitter &os, const EndCommandBufferArgs &args);
    void PrintResetCommandBufferArgs(YAML::Emitter &os, const ResetCommandBufferArgs &args);
    void PrintCmdBindPipelineArgs(YAML::Emitter &os, const CmdBindPipelineArgs &args);
    void PrintCmdSetViewportArgs(YAML::Emitter &os, const CmdSetViewportArgs &args);
    void PrintCmdSetScissorArgs(YAML::Emitter &os, const CmdSetScissorArgs &args);
    void PrintCmdSetLineWidthArgs(YAML::Emitter &os, const CmdSetLineWidthArgs &args);
    void PrintCmdSetDepthBiasArgs(YAML::Emitter &os, const CmdSetDepthBiasArgs &args);
    void PrintCmdSetBlendConstantsArgs(YAML::Emitter &os, const CmdSetBlendConstantsArgs &args);
    void PrintCmdSetDepthBoundsArgs(YAML::Emitter &os, const CmdSetDepthBoundsArgs &args);
    void PrintCmdSetStencilCompareMaskArgs(YAML::Emitter &os, const CmdSetStencilCompareMaskArgs &args);
    void PrintCmdSetStencilWriteMaskArgs(YAML::Emitter &os, const CmdSetStencilWriteMaskArgs &args);
    void PrintCmdSetStencilReferenceArgs(YAML::Emitter &os, const CmdSetStencilReferenceArgs &args);
    void PrintCmdBindDescriptorSetsArgs(YAML::Emitter &os, const CmdBindDescriptorSetsArgs &args);
    void PrintCmdBindIndexBufferArgs(YAML::Emitter &os, const CmdBindIndexBufferArgs &args);
    void PrintCmdBindVertexBuffersArgs(YAML::Emitter &os, const CmdBindVertexBuffersArgs &args);
    void PrintCmdDrawArgs(YAML::Emitter &os, const CmdDrawArgs &args);
    void PrintCmdDrawIndexedArgs(YAML::Emitter &os, const CmdDrawIndexedArgs &args);
    void PrintCmdDrawIndirectArgs(YAML::Emitter &os, const CmdDrawIndirectArgs &args);
    void PrintCmdDrawIndexedIndirectArgs(YAML::Emitter &os, const CmdDrawIndexedIndirectArgs &args);
    void PrintCmdDispatchArgs(YAML::Emitter &os, const CmdDispatchArgs &args);
    void PrintCmdDispatchIndirectArgs(YAML::Emitter &os, const CmdDispatchIndirectArgs &args);
    void PrintCmdCopyBufferArgs(YAML::Emitter &os, const CmdCopyBufferArgs &args);
    void PrintCmdCopyImageArgs(YAML::Emitter &os, const CmdCopyImageArgs &args);
    void PrintCmdBlitImageArgs(YAML::Emitter &os, const CmdBlitImageArgs &args);
    void PrintCmdCopyBufferToImageArgs(YAML::Emitter &os, const CmdCopyBufferToImageArgs &args);
    void PrintCmdCopyImageToBufferArgs(YAML::Emitter &os, const CmdCopyImageToBufferArgs &args);
    void PrintCmdUpdateBufferArgs(YAML::Emitter &os, const CmdUpdateBufferArgs &args);
    void PrintCmdFillBufferArgs(YAML::Emitter &os, const CmdFillBufferArgs &args);
    void PrintCmdClearColorImageArgs(YAML::Emitter &os, const CmdClearColorImageArgs &args);
    void PrintCmdClearDepthStencilImageArgs(YAML::Emitter &os, const CmdClearDepthStencilImageArgs &args);
    void PrintCmdClearAttachmentsArgs(YAML::Emitter &os, const CmdClearAttachmentsArgs &args);
    void PrintCmdResolveImageArgs(YAML::Emitter &os, const CmdResolveImageArgs &args);
    void PrintCmdSetEventArgs(YAML::Emitter &os, const CmdSetEventArgs &args);
    void PrintCmdResetEventArgs(YAML::Emitter &os, const CmdResetEventArgs &args);
    void PrintCmdWaitEventsArgs(YAML::Emitter &os, const CmdWaitEventsArgs &args);
    void PrintCmdPipelineBarrierArgs(YAML::Emitter &os, const CmdPipelineBarrierArgs &args);
    void PrintCmdBeginQueryArgs(YAML::Emitter &os, const CmdBeginQueryArgs &args);
    void PrintCmdEndQueryArgs(YAML::Emitter &os, const CmdEndQueryArgs &args);
    void PrintCmdResetQueryPoolArgs(YAML::Emitter &os, const CmdResetQueryPoolArgs &args);
    void PrintCmdWriteTimestampArgs(YAML::Emitter &os, const CmdWriteTimestampArgs &args);
    void PrintCmdCopyQueryPoolResultsArgs(YAML::Emitter &os, const CmdCopyQueryPoolResultsArgs &args);
    void PrintCmdPushConstantsArgs(YAML::Emitter &os, const CmdPushConstantsArgs &args);
    void PrintCmdBeginRenderPassArgs(YAML::Emitter &os, const CmdBeginRenderPassArgs &args);
    void PrintCmdNextSubpassArgs(YAML::Emitter &os, const CmdNextSubpassArgs &args);
    void PrintCmdEndRenderPassArgs(YAML::Emitter &os, const CmdEndRenderPassArgs &args);
    void PrintCmdExecuteCommandsArgs(YAML::Emitter &os, const CmdExecuteCommandsArgs &args);
    void PrintCmdSetDeviceMaskArgs(YAML::Emitter &os, const CmdSetDeviceMaskArgs &args);
    void PrintCmdDispatchBaseArgs(YAML::Emitter &os, const CmdDispatchBaseArgs &args);
    void PrintCmdDrawIndirectCountArgs(YAML::Emitter &os, const CmdDrawIndirectCountArgs &args);
    void PrintCmdDrawIndexedIndirectCountArgs(YAML::Emitter &os, const CmdDrawIndexedIndirectCountArgs &args);
    void PrintCmdBeginRenderPass2Args(YAML::Emitter &os, const CmdBeginRenderPass2Args &args);
    void PrintCmdNextSubpass2Args(YAML::Emitter &os, const CmdNextSubpass2Args &args);
    void PrintCmdEndRenderPass2Args(YAML::Emitter &os, const CmdEndRenderPass2Args &args);
    void PrintCmdSetEvent2Args(YAML::Emitter &os, const CmdSetEvent2Args &args);
    void PrintCmdResetEvent2Args(YAML::Emitter &os, const CmdResetEvent2Args &args);
    void PrintCmdWaitEvents2Args(YAML::Emitter &os, const CmdWaitEvents2Args &args);
    void PrintCmdPipelineBarrier2Args(YAML::Emitter &os, const CmdPipelineBarrier2Args &args);
    void PrintCmdWriteTimestamp2Args(YAML::Emitter &os, const CmdWriteTimestamp2Args &args);
    void PrintCmdCopyBuffer2Args(YAML::Emitter &os, const CmdCopyBuffer2Args &args);
    void PrintCmdCopyImage2Args(YAML::Emitter &os, const CmdCopyImage2Args &args);
    void PrintCmdCopyBufferToImage2Args(YAML::Emitter &os, const CmdCopyBufferToImage2Args &args);
    void PrintCmdCopyImageToBuffer2Args(YAML::Emitter &os, const CmdCopyImageToBuffer2Args &args);
    void PrintCmdBlitImage2Args(YAML::Emitter &os, const CmdBlitImage2Args &args);
    void PrintCmdResolveImage2Args(YAML::Emitter &os, const CmdResolveImage2Args &args);
    void PrintCmdBeginRenderingArgs(YAML::Emitter &os, const CmdBeginRenderingArgs &args);
    void PrintCmdEndRenderingArgs(YAML::Emitter &os, const CmdEndRenderingArgs &args);
    void PrintCmdSetCullModeArgs(YAML::Emitter &os, const CmdSetCullModeArgs &args);
    void PrintCmdSetFrontFaceArgs(YAML::Emitter &os, const CmdSetFrontFaceArgs &args);
    void PrintCmdSetPrimitiveTopologyArgs(YAML::Emitter &os, const CmdSetPrimitiveTopologyArgs &args);
    void PrintCmdSetViewportWithCountArgs(YAML::Emitter &os, const CmdSetViewportWithCountArgs &args);
    void PrintCmdSetScissorWithCountArgs(YAML::Emitter &os, const CmdSetScissorWithCountArgs &args);
    void PrintCmdBindVertexBuffers2Args(YAML::Emitter &os, const CmdBindVertexBuffers2Args &args);
    void PrintCmdSetDepthTestEnableArgs(YAML::Emitter &os, const CmdSetDepthTestEnableArgs &args);
    void PrintCmdSetDepthWriteEnableArgs(YAML::Emitter &os, const CmdSetDepthWriteEnableArgs &args);
    void PrintCmdSetDepthCompareOpArgs(YAML::Emitter &os, const CmdSetDepthCompareOpArgs &args);
    void PrintCmdSetDepthBoundsTestEnableArgs(YAML::Emitter &os, const CmdSetDepthBoundsTestEnableArgs &args);
    void PrintCmdSetStencilTestEnableArgs(YAML::Emitter &os, const CmdSetStencilTestEnableArgs &args);
    void PrintCmdSetStencilOpArgs(YAML::Emitter &os, const CmdSetStencilOpArgs &args);
    void PrintCmdSetRasterizerDiscardEnableArgs(YAML::Emitter &os, const CmdSetRasterizerDiscardEnableArgs &args);
    void PrintCmdSetDepthBiasEnableArgs(YAML::Emitter &os, const CmdSetDepthBiasEnableArgs &args);
    void PrintCmdSetPrimitiveRestartEnableArgs(YAML::Emitter &os, const CmdSetPrimitiveRestartEnableArgs &args);
    void PrintCmdBeginVideoCodingKHRArgs(YAML::Emitter &os, const CmdBeginVideoCodingKHRArgs &args);
    void PrintCmdEndVideoCodingKHRArgs(YAML::Emitter &os, const CmdEndVideoCodingKHRArgs &args);
    void PrintCmdControlVideoCodingKHRArgs(YAML::Emitter &os, const CmdControlVideoCodingKHRArgs &args);
    void PrintCmdDecodeVideoKHRArgs(YAML::Emitter &os, const CmdDecodeVideoKHRArgs &args);
    void PrintCmdBeginRenderingKHRArgs(YAML::Emitter &os, const CmdBeginRenderingKHRArgs &args);
    void PrintCmdEndRenderingKHRArgs(YAML::Emitter &os, const CmdEndRenderingKHRArgs &args);
    void PrintCmdSetDeviceMaskKHRArgs(YAML::Emitter &os, const CmdSetDeviceMaskKHRArgs &args);
    void PrintCmdDispatchBaseKHRArgs(YAML::Emitter &os, const CmdDispatchBaseKHRArgs &args);
    void PrintCmdPushDescriptorSetKHRArgs(YAML::Emitter &os, const CmdPushDescriptorSetKHRArgs &args);
    void PrintCmdPushDescriptorSetWithTemplateKHRArgs(YAML::Emitter &os,
                                                      const CmdPushDescriptorSetWithTemplateKHRArgs &args);
    void PrintCmdBeginRenderPass2KHRArgs(YAML::Emitter &os, const CmdBeginRenderPass2KHRArgs &args);
    void PrintCmdNextSubpass2KHRArgs(YAML::Emitter &os, const CmdNextSubpass2KHRArgs &args);
    void PrintCmdEndRenderPass2KHRArgs(YAML::Emitter &os, const CmdEndRenderPass2KHRArgs &args);
    void PrintCmdDrawIndirectCountKHRArgs(YAML::Emitter &os, const CmdDrawIndirectCountKHRArgs &args);
    void PrintCmdDrawIndexedIndirectCountKHRArgs(YAML::Emitter &os, const CmdDrawIndexedIndirectCountKHRArgs &args);
    void PrintCmdSetFragmentShadingRateKHRArgs(YAML::Emitter &os, const CmdSetFragmentShadingRateKHRArgs &args);
    void PrintCmdSetRenderingAttachmentLocationsKHRArgs(YAML::Emitter &os,
                                                        const CmdSetRenderingAttachmentLocationsKHRArgs &args);
    void PrintCmdSetRenderingInputAttachmentIndicesKHRArgs(YAML::Emitter &os,
                                                           const CmdSetRenderingInputAttachmentIndicesKHRArgs &args);
    void PrintCmdEncodeVideoKHRArgs(YAML::Emitter &os, const CmdEncodeVideoKHRArgs &args);
    void PrintCmdSetEvent2KHRArgs(YAML::Emitter &os, const CmdSetEvent2KHRArgs &args);
    void PrintCmdResetEvent2KHRArgs(YAML::Emitter &os, const CmdResetEvent2KHRArgs &args);
    void PrintCmdWaitEvents2KHRArgs(YAML::Emitter &os, const CmdWaitEvents2KHRArgs &args);
    void PrintCmdPipelineBarrier2KHRArgs(YAML::Emitter &os, const CmdPipelineBarrier2KHRArgs &args);
    void PrintCmdWriteTimestamp2KHRArgs(YAML::Emitter &os, const CmdWriteTimestamp2KHRArgs &args);
    void PrintCmdWriteBufferMarker2AMDArgs(YAML::Emitter &os, const CmdWriteBufferMarker2AMDArgs &args);
    void PrintCmdCopyBuffer2KHRArgs(YAML::Emitter &os, const CmdCopyBuffer2KHRArgs &args);
    void PrintCmdCopyImage2KHRArgs(YAML::Emitter &os, const CmdCopyImage2KHRArgs &args);
    void PrintCmdCopyBufferToImage2KHRArgs(YAML::Emitter &os, const CmdCopyBufferToImage2KHRArgs &args);
    void PrintCmdCopyImageToBuffer2KHRArgs(YAML::Emitter &os, const CmdCopyImageToBuffer2KHRArgs &args);
    void PrintCmdBlitImage2KHRArgs(YAML::Emitter &os, const CmdBlitImage2KHRArgs &args);
    void PrintCmdResolveImage2KHRArgs(YAML::Emitter &os, const CmdResolveImage2KHRArgs &args);
    void PrintCmdTraceRaysIndirect2KHRArgs(YAML::Emitter &os, const CmdTraceRaysIndirect2KHRArgs &args);
    void PrintCmdBindIndexBuffer2KHRArgs(YAML::Emitter &os, const CmdBindIndexBuffer2KHRArgs &args);
    void PrintCmdSetLineStippleKHRArgs(YAML::Emitter &os, const CmdSetLineStippleKHRArgs &args);
    void PrintCmdBindDescriptorSets2KHRArgs(YAML::Emitter &os, const CmdBindDescriptorSets2KHRArgs &args);
    void PrintCmdPushConstants2KHRArgs(YAML::Emitter &os, const CmdPushConstants2KHRArgs &args);
    void PrintCmdPushDescriptorSet2KHRArgs(YAML::Emitter &os, const CmdPushDescriptorSet2KHRArgs &args);
    void PrintCmdPushDescriptorSetWithTemplate2KHRArgs(YAML::Emitter &os,
                                                       const CmdPushDescriptorSetWithTemplate2KHRArgs &args);
    void PrintCmdSetDescriptorBufferOffsets2EXTArgs(YAML::Emitter &os,
                                                    const CmdSetDescriptorBufferOffsets2EXTArgs &args);
    void PrintCmdBindDescriptorBufferEmbeddedSamplers2EXTArgs(
        YAML::Emitter &os, const CmdBindDescriptorBufferEmbeddedSamplers2EXTArgs &args);
    void PrintCmdDebugMarkerBeginEXTArgs(YAML::Emitter &os, const CmdDebugMarkerBeginEXTArgs &args);
    void PrintCmdDebugMarkerEndEXTArgs(YAML::Emitter &os, const CmdDebugMarkerEndEXTArgs &args);
    void PrintCmdDebugMarkerInsertEXTArgs(YAML::Emitter &os, const CmdDebugMarkerInsertEXTArgs &args);
    void PrintCmdBindTransformFeedbackBuffersEXTArgs(YAML::Emitter &os,
                                                     const CmdBindTransformFeedbackBuffersEXTArgs &args);
    void PrintCmdBeginTransformFeedbackEXTArgs(YAML::Emitter &os, const CmdBeginTransformFeedbackEXTArgs &args);
    void PrintCmdEndTransformFeedbackEXTArgs(YAML::Emitter &os, const CmdEndTransformFeedbackEXTArgs &args);
    void PrintCmdBeginQueryIndexedEXTArgs(YAML::Emitter &os, const CmdBeginQueryIndexedEXTArgs &args);
    void PrintCmdEndQueryIndexedEXTArgs(YAML::Emitter &os, const CmdEndQueryIndexedEXTArgs &args);
    void PrintCmdDrawIndirectByteCountEXTArgs(YAML::Emitter &os, const CmdDrawIndirectByteCountEXTArgs &args);
    void PrintCmdCuLaunchKernelNVXArgs(YAML::Emitter &os, const CmdCuLaunchKernelNVXArgs &args);
    void PrintCmdDrawIndirectCountAMDArgs(YAML::Emitter &os, const CmdDrawIndirectCountAMDArgs &args);
    void PrintCmdDrawIndexedIndirectCountAMDArgs(YAML::Emitter &os, const CmdDrawIndexedIndirectCountAMDArgs &args);
    void PrintCmdBeginConditionalRenderingEXTArgs(YAML::Emitter &os, const CmdBeginConditionalRenderingEXTArgs &args);
    void PrintCmdEndConditionalRenderingEXTArgs(YAML::Emitter &os, const CmdEndConditionalRenderingEXTArgs &args);
    void PrintCmdSetViewportWScalingNVArgs(YAML::Emitter &os, const CmdSetViewportWScalingNVArgs &args);
    void PrintCmdSetDiscardRectangleEXTArgs(YAML::Emitter &os, const CmdSetDiscardRectangleEXTArgs &args);
    void PrintCmdSetDiscardRectangleEnableEXTArgs(YAML::Emitter &os, const CmdSetDiscardRectangleEnableEXTArgs &args);
    void PrintCmdSetDiscardRectangleModeEXTArgs(YAML::Emitter &os, const CmdSetDiscardRectangleModeEXTArgs &args);
    void PrintCmdBeginDebugUtilsLabelEXTArgs(YAML::Emitter &os, const CmdBeginDebugUtilsLabelEXTArgs &args);
    void PrintCmdEndDebugUtilsLabelEXTArgs(YAML::Emitter &os, const CmdEndDebugUtilsLabelEXTArgs &args);
    void PrintCmdInsertDebugUtilsLabelEXTArgs(YAML::Emitter &os, const CmdInsertDebugUtilsLabelEXTArgs &args);
#ifdef VK_ENABLE_BETA_EXTENSIONS
    void PrintCmdInitializeGraphScratchMemoryAMDXArgs(YAML::Emitter &os,
                                                      const CmdInitializeGraphScratchMemoryAMDXArgs &args);
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
    void PrintCmdDispatchGraphAMDXArgs(YAML::Emitter &os, const CmdDispatchGraphAMDXArgs &args);
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
    void PrintCmdDispatchGraphIndirectAMDXArgs(YAML::Emitter &os, const CmdDispatchGraphIndirectAMDXArgs &args);
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
    void PrintCmdDispatchGraphIndirectCountAMDXArgs(YAML::Emitter &os,
                                                    const CmdDispatchGraphIndirectCountAMDXArgs &args);
#endif  // VK_ENABLE_BETA_EXTENSIONS
    void PrintCmdSetSampleLocationsEXTArgs(YAML::Emitter &os, const CmdSetSampleLocationsEXTArgs &args);
    void PrintCmdBindShadingRateImageNVArgs(YAML::Emitter &os, const CmdBindShadingRateImageNVArgs &args);
    void PrintCmdSetViewportShadingRatePaletteNVArgs(YAML::Emitter &os,
                                                     const CmdSetViewportShadingRatePaletteNVArgs &args);
    void PrintCmdSetCoarseSampleOrderNVArgs(YAML::Emitter &os, const CmdSetCoarseSampleOrderNVArgs &args);
    void PrintCmdBuildAccelerationStructureNVArgs(YAML::Emitter &os, const CmdBuildAccelerationStructureNVArgs &args);
    void PrintCmdCopyAccelerationStructureNVArgs(YAML::Emitter &os, const CmdCopyAccelerationStructureNVArgs &args);
    void PrintCmdTraceRaysNVArgs(YAML::Emitter &os, const CmdTraceRaysNVArgs &args);
    void PrintCmdWriteAccelerationStructuresPropertiesNVArgs(
        YAML::Emitter &os, const CmdWriteAccelerationStructuresPropertiesNVArgs &args);
    void PrintCmdWriteBufferMarkerAMDArgs(YAML::Emitter &os, const CmdWriteBufferMarkerAMDArgs &args);
    void PrintCmdDrawMeshTasksNVArgs(YAML::Emitter &os, const CmdDrawMeshTasksNVArgs &args);
    void PrintCmdDrawMeshTasksIndirectNVArgs(YAML::Emitter &os, const CmdDrawMeshTasksIndirectNVArgs &args);
    void PrintCmdDrawMeshTasksIndirectCountNVArgs(YAML::Emitter &os, const CmdDrawMeshTasksIndirectCountNVArgs &args);
    void PrintCmdSetExclusiveScissorEnableNVArgs(YAML::Emitter &os, const CmdSetExclusiveScissorEnableNVArgs &args);
    void PrintCmdSetExclusiveScissorNVArgs(YAML::Emitter &os, const CmdSetExclusiveScissorNVArgs &args);
    void PrintCmdSetCheckpointNVArgs(YAML::Emitter &os, const CmdSetCheckpointNVArgs &args);
    void PrintCmdSetPerformanceMarkerINTELArgs(YAML::Emitter &os, const CmdSetPerformanceMarkerINTELArgs &args);
    void PrintCmdSetPerformanceStreamMarkerINTELArgs(YAML::Emitter &os,
                                                     const CmdSetPerformanceStreamMarkerINTELArgs &args);
    void PrintCmdSetPerformanceOverrideINTELArgs(YAML::Emitter &os, const CmdSetPerformanceOverrideINTELArgs &args);
    void PrintCmdSetLineStippleEXTArgs(YAML::Emitter &os, const CmdSetLineStippleEXTArgs &args);
    void PrintCmdSetCullModeEXTArgs(YAML::Emitter &os, const CmdSetCullModeEXTArgs &args);
    void PrintCmdSetFrontFaceEXTArgs(YAML::Emitter &os, const CmdSetFrontFaceEXTArgs &args);
    void PrintCmdSetPrimitiveTopologyEXTArgs(YAML::Emitter &os, const CmdSetPrimitiveTopologyEXTArgs &args);
    void PrintCmdSetViewportWithCountEXTArgs(YAML::Emitter &os, const CmdSetViewportWithCountEXTArgs &args);
    void PrintCmdSetScissorWithCountEXTArgs(YAML::Emitter &os, const CmdSetScissorWithCountEXTArgs &args);
    void PrintCmdBindVertexBuffers2EXTArgs(YAML::Emitter &os, const CmdBindVertexBuffers2EXTArgs &args);
    void PrintCmdSetDepthTestEnableEXTArgs(YAML::Emitter &os, const CmdSetDepthTestEnableEXTArgs &args);
    void PrintCmdSetDepthWriteEnableEXTArgs(YAML::Emitter &os, const CmdSetDepthWriteEnableEXTArgs &args);
    void PrintCmdSetDepthCompareOpEXTArgs(YAML::Emitter &os, const CmdSetDepthCompareOpEXTArgs &args);
    void PrintCmdSetDepthBoundsTestEnableEXTArgs(YAML::Emitter &os, const CmdSetDepthBoundsTestEnableEXTArgs &args);
    void PrintCmdSetStencilTestEnableEXTArgs(YAML::Emitter &os, const CmdSetStencilTestEnableEXTArgs &args);
    void PrintCmdSetStencilOpEXTArgs(YAML::Emitter &os, const CmdSetStencilOpEXTArgs &args);
    void PrintCmdPreprocessGeneratedCommandsNVArgs(YAML::Emitter &os, const CmdPreprocessGeneratedCommandsNVArgs &args);
    void PrintCmdExecuteGeneratedCommandsNVArgs(YAML::Emitter &os, const CmdExecuteGeneratedCommandsNVArgs &args);
    void PrintCmdBindPipelineShaderGroupNVArgs(YAML::Emitter &os, const CmdBindPipelineShaderGroupNVArgs &args);
    void PrintCmdSetDepthBias2EXTArgs(YAML::Emitter &os, const CmdSetDepthBias2EXTArgs &args);
    void PrintCmdCudaLaunchKernelNVArgs(YAML::Emitter &os, const CmdCudaLaunchKernelNVArgs &args);
    void PrintCmdBindDescriptorBuffersEXTArgs(YAML::Emitter &os, const CmdBindDescriptorBuffersEXTArgs &args);
    void PrintCmdSetDescriptorBufferOffsetsEXTArgs(YAML::Emitter &os, const CmdSetDescriptorBufferOffsetsEXTArgs &args);
    void PrintCmdBindDescriptorBufferEmbeddedSamplersEXTArgs(
        YAML::Emitter &os, const CmdBindDescriptorBufferEmbeddedSamplersEXTArgs &args);
    void PrintCmdSetFragmentShadingRateEnumNVArgs(YAML::Emitter &os, const CmdSetFragmentShadingRateEnumNVArgs &args);
    void PrintCmdSetVertexInputEXTArgs(YAML::Emitter &os, const CmdSetVertexInputEXTArgs &args);
    void PrintCmdSubpassShadingHUAWEIArgs(YAML::Emitter &os, const CmdSubpassShadingHUAWEIArgs &args);
    void PrintCmdBindInvocationMaskHUAWEIArgs(YAML::Emitter &os, const CmdBindInvocationMaskHUAWEIArgs &args);
    void PrintCmdSetPatchControlPointsEXTArgs(YAML::Emitter &os, const CmdSetPatchControlPointsEXTArgs &args);
    void PrintCmdSetRasterizerDiscardEnableEXTArgs(YAML::Emitter &os, const CmdSetRasterizerDiscardEnableEXTArgs &args);
    void PrintCmdSetDepthBiasEnableEXTArgs(YAML::Emitter &os, const CmdSetDepthBiasEnableEXTArgs &args);
    void PrintCmdSetLogicOpEXTArgs(YAML::Emitter &os, const CmdSetLogicOpEXTArgs &args);
    void PrintCmdSetPrimitiveRestartEnableEXTArgs(YAML::Emitter &os, const CmdSetPrimitiveRestartEnableEXTArgs &args);
    void PrintCmdSetColorWriteEnableEXTArgs(YAML::Emitter &os, const CmdSetColorWriteEnableEXTArgs &args);
    void PrintCmdDrawMultiEXTArgs(YAML::Emitter &os, const CmdDrawMultiEXTArgs &args);
    void PrintCmdDrawMultiIndexedEXTArgs(YAML::Emitter &os, const CmdDrawMultiIndexedEXTArgs &args);
    void PrintCmdBuildMicromapsEXTArgs(YAML::Emitter &os, const CmdBuildMicromapsEXTArgs &args);
    void PrintCmdCopyMicromapEXTArgs(YAML::Emitter &os, const CmdCopyMicromapEXTArgs &args);
    void PrintCmdCopyMicromapToMemoryEXTArgs(YAML::Emitter &os, const CmdCopyMicromapToMemoryEXTArgs &args);
    void PrintCmdCopyMemoryToMicromapEXTArgs(YAML::Emitter &os, const CmdCopyMemoryToMicromapEXTArgs &args);
    void PrintCmdWriteMicromapsPropertiesEXTArgs(YAML::Emitter &os, const CmdWriteMicromapsPropertiesEXTArgs &args);
    void PrintCmdDrawClusterHUAWEIArgs(YAML::Emitter &os, const CmdDrawClusterHUAWEIArgs &args);
    void PrintCmdDrawClusterIndirectHUAWEIArgs(YAML::Emitter &os, const CmdDrawClusterIndirectHUAWEIArgs &args);
    void PrintCmdCopyMemoryIndirectNVArgs(YAML::Emitter &os, const CmdCopyMemoryIndirectNVArgs &args);
    void PrintCmdCopyMemoryToImageIndirectNVArgs(YAML::Emitter &os, const CmdCopyMemoryToImageIndirectNVArgs &args);
    void PrintCmdDecompressMemoryNVArgs(YAML::Emitter &os, const CmdDecompressMemoryNVArgs &args);
    void PrintCmdDecompressMemoryIndirectCountNVArgs(YAML::Emitter &os,
                                                     const CmdDecompressMemoryIndirectCountNVArgs &args);
    void PrintCmdUpdatePipelineIndirectBufferNVArgs(YAML::Emitter &os,
                                                    const CmdUpdatePipelineIndirectBufferNVArgs &args);
    void PrintCmdSetDepthClampEnableEXTArgs(YAML::Emitter &os, const CmdSetDepthClampEnableEXTArgs &args);
    void PrintCmdSetPolygonModeEXTArgs(YAML::Emitter &os, const CmdSetPolygonModeEXTArgs &args);
    void PrintCmdSetRasterizationSamplesEXTArgs(YAML::Emitter &os, const CmdSetRasterizationSamplesEXTArgs &args);
    void PrintCmdSetSampleMaskEXTArgs(YAML::Emitter &os, const CmdSetSampleMaskEXTArgs &args);
    void PrintCmdSetAlphaToCoverageEnableEXTArgs(YAML::Emitter &os, const CmdSetAlphaToCoverageEnableEXTArgs &args);
    void PrintCmdSetAlphaToOneEnableEXTArgs(YAML::Emitter &os, const CmdSetAlphaToOneEnableEXTArgs &args);
    void PrintCmdSetLogicOpEnableEXTArgs(YAML::Emitter &os, const CmdSetLogicOpEnableEXTArgs &args);
    void PrintCmdSetColorBlendEnableEXTArgs(YAML::Emitter &os, const CmdSetColorBlendEnableEXTArgs &args);
    void PrintCmdSetColorBlendEquationEXTArgs(YAML::Emitter &os, const CmdSetColorBlendEquationEXTArgs &args);
    void PrintCmdSetColorWriteMaskEXTArgs(YAML::Emitter &os, const CmdSetColorWriteMaskEXTArgs &args);
    void PrintCmdSetTessellationDomainOriginEXTArgs(YAML::Emitter &os,
                                                    const CmdSetTessellationDomainOriginEXTArgs &args);
    void PrintCmdSetRasterizationStreamEXTArgs(YAML::Emitter &os, const CmdSetRasterizationStreamEXTArgs &args);
    void PrintCmdSetConservativeRasterizationModeEXTArgs(YAML::Emitter &os,
                                                         const CmdSetConservativeRasterizationModeEXTArgs &args);
    void PrintCmdSetExtraPrimitiveOverestimationSizeEXTArgs(YAML::Emitter &os,
                                                            const CmdSetExtraPrimitiveOverestimationSizeEXTArgs &args);
    void PrintCmdSetDepthClipEnableEXTArgs(YAML::Emitter &os, const CmdSetDepthClipEnableEXTArgs &args);
    void PrintCmdSetSampleLocationsEnableEXTArgs(YAML::Emitter &os, const CmdSetSampleLocationsEnableEXTArgs &args);
    void PrintCmdSetColorBlendAdvancedEXTArgs(YAML::Emitter &os, const CmdSetColorBlendAdvancedEXTArgs &args);
    void PrintCmdSetProvokingVertexModeEXTArgs(YAML::Emitter &os, const CmdSetProvokingVertexModeEXTArgs &args);
    void PrintCmdSetLineRasterizationModeEXTArgs(YAML::Emitter &os, const CmdSetLineRasterizationModeEXTArgs &args);
    void PrintCmdSetLineStippleEnableEXTArgs(YAML::Emitter &os, const CmdSetLineStippleEnableEXTArgs &args);
    void PrintCmdSetDepthClipNegativeOneToOneEXTArgs(YAML::Emitter &os,
                                                     const CmdSetDepthClipNegativeOneToOneEXTArgs &args);
    void PrintCmdSetViewportWScalingEnableNVArgs(YAML::Emitter &os, const CmdSetViewportWScalingEnableNVArgs &args);
    void PrintCmdSetViewportSwizzleNVArgs(YAML::Emitter &os, const CmdSetViewportSwizzleNVArgs &args);
    void PrintCmdSetCoverageToColorEnableNVArgs(YAML::Emitter &os, const CmdSetCoverageToColorEnableNVArgs &args);
    void PrintCmdSetCoverageToColorLocationNVArgs(YAML::Emitter &os, const CmdSetCoverageToColorLocationNVArgs &args);
    void PrintCmdSetCoverageModulationModeNVArgs(YAML::Emitter &os, const CmdSetCoverageModulationModeNVArgs &args);
    void PrintCmdSetCoverageModulationTableEnableNVArgs(YAML::Emitter &os,
                                                        const CmdSetCoverageModulationTableEnableNVArgs &args);
    void PrintCmdSetCoverageModulationTableNVArgs(YAML::Emitter &os, const CmdSetCoverageModulationTableNVArgs &args);
    void PrintCmdSetShadingRateImageEnableNVArgs(YAML::Emitter &os, const CmdSetShadingRateImageEnableNVArgs &args);
    void PrintCmdSetRepresentativeFragmentTestEnableNVArgs(YAML::Emitter &os,
                                                           const CmdSetRepresentativeFragmentTestEnableNVArgs &args);
    void PrintCmdSetCoverageReductionModeNVArgs(YAML::Emitter &os, const CmdSetCoverageReductionModeNVArgs &args);
    void PrintCmdOpticalFlowExecuteNVArgs(YAML::Emitter &os, const CmdOpticalFlowExecuteNVArgs &args);
    void PrintCmdBindShadersEXTArgs(YAML::Emitter &os, const CmdBindShadersEXTArgs &args);
    void PrintCmdSetDepthClampRangeEXTArgs(YAML::Emitter &os, const CmdSetDepthClampRangeEXTArgs &args);
    void PrintCmdSetAttachmentFeedbackLoopEnableEXTArgs(YAML::Emitter &os,
                                                        const CmdSetAttachmentFeedbackLoopEnableEXTArgs &args);
    void PrintCmdPreprocessGeneratedCommandsEXTArgs(YAML::Emitter &os,
                                                    const CmdPreprocessGeneratedCommandsEXTArgs &args);
    void PrintCmdExecuteGeneratedCommandsEXTArgs(YAML::Emitter &os, const CmdExecuteGeneratedCommandsEXTArgs &args);
    void PrintCmdBuildAccelerationStructuresKHRArgs(YAML::Emitter &os,
                                                    const CmdBuildAccelerationStructuresKHRArgs &args);
    void PrintCmdBuildAccelerationStructuresIndirectKHRArgs(YAML::Emitter &os,
                                                            const CmdBuildAccelerationStructuresIndirectKHRArgs &args);
    void PrintCmdCopyAccelerationStructureKHRArgs(YAML::Emitter &os, const CmdCopyAccelerationStructureKHRArgs &args);
    void PrintCmdCopyAccelerationStructureToMemoryKHRArgs(YAML::Emitter &os,
                                                          const CmdCopyAccelerationStructureToMemoryKHRArgs &args);
    void PrintCmdCopyMemoryToAccelerationStructureKHRArgs(YAML::Emitter &os,
                                                          const CmdCopyMemoryToAccelerationStructureKHRArgs &args);
    void PrintCmdWriteAccelerationStructuresPropertiesKHRArgs(
        YAML::Emitter &os, const CmdWriteAccelerationStructuresPropertiesKHRArgs &args);
    void PrintCmdTraceRaysKHRArgs(YAML::Emitter &os, const CmdTraceRaysKHRArgs &args);
    void PrintCmdTraceRaysIndirectKHRArgs(YAML::Emitter &os, const CmdTraceRaysIndirectKHRArgs &args);
    void PrintCmdSetRayTracingPipelineStackSizeKHRArgs(YAML::Emitter &os,
                                                       const CmdSetRayTracingPipelineStackSizeKHRArgs &args);
    void PrintCmdDrawMeshTasksEXTArgs(YAML::Emitter &os, const CmdDrawMeshTasksEXTArgs &args);
    void PrintCmdDrawMeshTasksIndirectEXTArgs(YAML::Emitter &os, const CmdDrawMeshTasksIndirectEXTArgs &args);
    void PrintCmdDrawMeshTasksIndirectCountEXTArgs(YAML::Emitter &os, const CmdDrawMeshTasksIndirectCountEXTArgs &args);
};

// NOLINTEND
