
/***************************************************************************
*
* Copyright (C) 2021 Google Inc.
* Copyright (c) 2023 LunarG, Inc.
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

#include <iostream>
#include <vulkan/vulkan.h>

#include "command_common.h"
#include "object_name_db.h"

struct VkStruct {
    VkStructureType sType;
    void *pNext;
};

class ScopedOstream : public std::streambuf
{
public:
    explicit ScopedOstream(std::ostream &os, int indent = 4):
        os_(&os),
        sb_(os_->rdbuf()),
        line_start_(true),
        indent_(indent)
    {
        os_->rdbuf(this);
    }

    virtual ~ScopedOstream()
    {
        os_->rdbuf(sb_);
    }

protected:
    virtual int overflow(int ch) {
        if (line_start_ && ch != '\n'){
            for (int i = 0; i < indent_; ++i) {
                sb_->sputc(' ');
            }
        }

        line_start_ = '\n' == ch;
        return sb_->sputc(ch);
    }

private:
    std::ostream *os_;
    std::streambuf *sb_;
    bool line_start_;
    int indent_;
};

// Declare generic struct printer.
std::ostream & PrintVkStruct(std::ostream & os, const VkStruct *pStruct);

// Declare pNext chain printer.
std::ostream & PrintNextPtr(std::ostream & os, const void *pNext);


// Declare enum to string functions.

const char *VkResultToString(VkResult e);
const char *VkStructureTypeToString(VkStructureType e);
const char *VkPipelineCacheHeaderVersionToString(VkPipelineCacheHeaderVersion e);
const char *VkImageLayoutToString(VkImageLayout e);
const char *VkObjectTypeToString(VkObjectType e);
const char *VkVendorIdToString(VkVendorId e);
const char *VkSystemAllocationScopeToString(VkSystemAllocationScope e);
const char *VkInternalAllocationTypeToString(VkInternalAllocationType e);
const char *VkFormatToString(VkFormat e);
const char *VkImageTilingToString(VkImageTiling e);
const char *VkImageTypeToString(VkImageType e);
const char *VkPhysicalDeviceTypeToString(VkPhysicalDeviceType e);
const char *VkQueryTypeToString(VkQueryType e);
const char *VkSharingModeToString(VkSharingMode e);
const char *VkComponentSwizzleToString(VkComponentSwizzle e);
const char *VkImageViewTypeToString(VkImageViewType e);
const char *VkBlendFactorToString(VkBlendFactor e);
const char *VkBlendOpToString(VkBlendOp e);
const char *VkCompareOpToString(VkCompareOp e);
const char *VkDynamicStateToString(VkDynamicState e);
const char *VkFrontFaceToString(VkFrontFace e);
const char *VkVertexInputRateToString(VkVertexInputRate e);
const char *VkPrimitiveTopologyToString(VkPrimitiveTopology e);
const char *VkPolygonModeToString(VkPolygonMode e);
const char *VkStencilOpToString(VkStencilOp e);
const char *VkLogicOpToString(VkLogicOp e);
const char *VkBorderColorToString(VkBorderColor e);
const char *VkFilterToString(VkFilter e);
const char *VkSamplerAddressModeToString(VkSamplerAddressMode e);
const char *VkSamplerMipmapModeToString(VkSamplerMipmapMode e);
const char *VkDescriptorTypeToString(VkDescriptorType e);
const char *VkAttachmentLoadOpToString(VkAttachmentLoadOp e);
const char *VkAttachmentStoreOpToString(VkAttachmentStoreOp e);
const char *VkPipelineBindPointToString(VkPipelineBindPoint e);
const char *VkCommandBufferLevelToString(VkCommandBufferLevel e);
const char *VkIndexTypeToString(VkIndexType e);
const char *VkSubpassContentsToString(VkSubpassContents e);
const char *VkPointClippingBehaviorToString(VkPointClippingBehavior e);
const char *VkTessellationDomainOriginToString(VkTessellationDomainOrigin e);
const char *VkSamplerYcbcrModelConversionToString(VkSamplerYcbcrModelConversion e);
const char *VkSamplerYcbcrRangeToString(VkSamplerYcbcrRange e);
const char *VkChromaLocationToString(VkChromaLocation e);
const char *VkDescriptorUpdateTemplateTypeToString(VkDescriptorUpdateTemplateType e);
const char *VkDriverIdToString(VkDriverId e);
const char *VkShaderFloatControlsIndependenceToString(VkShaderFloatControlsIndependence e);
const char *VkSamplerReductionModeToString(VkSamplerReductionMode e);
const char *VkSemaphoreTypeToString(VkSemaphoreType e);
const char *VkPresentModeKHRToString(VkPresentModeKHR e);
const char *VkColorSpaceKHRToString(VkColorSpaceKHR e);
const char *VkQueryResultStatusKHRToString(VkQueryResultStatusKHR e);
const char *VkPerformanceCounterUnitKHRToString(VkPerformanceCounterUnitKHR e);
const char *VkPerformanceCounterScopeKHRToString(VkPerformanceCounterScopeKHR e);
const char *VkPerformanceCounterStorageKHRToString(VkPerformanceCounterStorageKHR e);
const char *VkQueueGlobalPriorityKHRToString(VkQueueGlobalPriorityKHR e);
const char *VkFragmentShadingRateCombinerOpKHRToString(VkFragmentShadingRateCombinerOpKHR e);
const char *VkPipelineExecutableStatisticFormatKHRToString(VkPipelineExecutableStatisticFormatKHR e);
const char *VkVideoEncodeTuningModeKHRToString(VkVideoEncodeTuningModeKHR e);
const char *VkComponentTypeKHRToString(VkComponentTypeKHR e);
const char *VkScopeKHRToString(VkScopeKHR e);
const char *VkTimeDomainKHRToString(VkTimeDomainKHR e);
const char *VkDebugReportObjectTypeEXTToString(VkDebugReportObjectTypeEXT e);
const char *VkRasterizationOrderAMDToString(VkRasterizationOrderAMD e);
const char *VkShaderInfoTypeAMDToString(VkShaderInfoTypeAMD e);
const char *VkValidationCheckEXTToString(VkValidationCheckEXT e);
const char *VkPipelineRobustnessBufferBehaviorEXTToString(VkPipelineRobustnessBufferBehaviorEXT e);
const char *VkPipelineRobustnessImageBehaviorEXTToString(VkPipelineRobustnessImageBehaviorEXT e);
const char *VkDisplayPowerStateEXTToString(VkDisplayPowerStateEXT e);
const char *VkDeviceEventTypeEXTToString(VkDeviceEventTypeEXT e);
const char *VkDisplayEventTypeEXTToString(VkDisplayEventTypeEXT e);
const char *VkViewportCoordinateSwizzleNVToString(VkViewportCoordinateSwizzleNV e);
const char *VkDiscardRectangleModeEXTToString(VkDiscardRectangleModeEXT e);
const char *VkConservativeRasterizationModeEXTToString(VkConservativeRasterizationModeEXT e);
const char *VkBlendOverlapEXTToString(VkBlendOverlapEXT e);
const char *VkCoverageModulationModeNVToString(VkCoverageModulationModeNV e);
const char *VkValidationCacheHeaderVersionEXTToString(VkValidationCacheHeaderVersionEXT e);
const char *VkShadingRatePaletteEntryNVToString(VkShadingRatePaletteEntryNV e);
const char *VkCoarseSampleOrderTypeNVToString(VkCoarseSampleOrderTypeNV e);
const char *VkRayTracingShaderGroupTypeKHRToString(VkRayTracingShaderGroupTypeKHR e);
const char *VkGeometryTypeKHRToString(VkGeometryTypeKHR e);
const char *VkAccelerationStructureTypeKHRToString(VkAccelerationStructureTypeKHR e);
const char *VkCopyAccelerationStructureModeKHRToString(VkCopyAccelerationStructureModeKHR e);
const char *VkAccelerationStructureMemoryRequirementsTypeNVToString(VkAccelerationStructureMemoryRequirementsTypeNV e);
const char *VkMemoryOverallocationBehaviorAMDToString(VkMemoryOverallocationBehaviorAMD e);
const char *VkPerformanceConfigurationTypeINTELToString(VkPerformanceConfigurationTypeINTEL e);
const char *VkQueryPoolSamplingModeINTELToString(VkQueryPoolSamplingModeINTEL e);
const char *VkPerformanceOverrideTypeINTELToString(VkPerformanceOverrideTypeINTEL e);
const char *VkPerformanceParameterTypeINTELToString(VkPerformanceParameterTypeINTEL e);
const char *VkPerformanceValueTypeINTELToString(VkPerformanceValueTypeINTEL e);
const char *VkValidationFeatureEnableEXTToString(VkValidationFeatureEnableEXT e);
const char *VkValidationFeatureDisableEXTToString(VkValidationFeatureDisableEXT e);
const char *VkCoverageReductionModeNVToString(VkCoverageReductionModeNV e);
const char *VkProvokingVertexModeEXTToString(VkProvokingVertexModeEXT e);
#ifdef VK_USE_PLATFORM_WIN32_KHR
const char *VkFullScreenExclusiveEXTToString(VkFullScreenExclusiveEXT e);
#endif //VK_USE_PLATFORM_WIN32_KHR
const char *VkLineRasterizationModeEXTToString(VkLineRasterizationModeEXT e);
const char *VkIndirectCommandsTokenTypeNVToString(VkIndirectCommandsTokenTypeNV e);
const char *VkDepthBiasRepresentationEXTToString(VkDepthBiasRepresentationEXT e);
const char *VkDeviceMemoryReportEventTypeEXTToString(VkDeviceMemoryReportEventTypeEXT e);
const char *VkFragmentShadingRateTypeNVToString(VkFragmentShadingRateTypeNV e);
const char *VkFragmentShadingRateNVToString(VkFragmentShadingRateNV e);
const char *VkAccelerationStructureMotionInstanceTypeNVToString(VkAccelerationStructureMotionInstanceTypeNV e);
const char *VkDeviceFaultAddressTypeEXTToString(VkDeviceFaultAddressTypeEXT e);
const char *VkDeviceFaultVendorBinaryHeaderVersionEXTToString(VkDeviceFaultVendorBinaryHeaderVersionEXT e);
const char *VkDeviceAddressBindingTypeEXTToString(VkDeviceAddressBindingTypeEXT e);
const char *VkMicromapTypeEXTToString(VkMicromapTypeEXT e);
const char *VkBuildMicromapModeEXTToString(VkBuildMicromapModeEXT e);
const char *VkCopyMicromapModeEXTToString(VkCopyMicromapModeEXT e);
const char *VkOpacityMicromapFormatEXTToString(VkOpacityMicromapFormatEXT e);
const char *VkOpacityMicromapSpecialIndexEXTToString(VkOpacityMicromapSpecialIndexEXT e);
const char *VkAccelerationStructureCompatibilityKHRToString(VkAccelerationStructureCompatibilityKHR e);
const char *VkAccelerationStructureBuildTypeKHRToString(VkAccelerationStructureBuildTypeKHR e);
#ifdef VK_ENABLE_BETA_EXTENSIONS
const char *VkDisplacementMicromapFormatNVToString(VkDisplacementMicromapFormatNV e);
#endif //VK_ENABLE_BETA_EXTENSIONS
const char *VkSubpassMergeStatusEXTToString(VkSubpassMergeStatusEXT e);
const char *VkDirectDriverLoadingModeLUNARGToString(VkDirectDriverLoadingModeLUNARG e);
const char *VkOpticalFlowPerformanceLevelNVToString(VkOpticalFlowPerformanceLevelNV e);
const char *VkOpticalFlowSessionBindingPointNVToString(VkOpticalFlowSessionBindingPointNV e);
const char *VkShaderCodeTypeEXTToString(VkShaderCodeTypeEXT e);
const char *VkRayTracingInvocationReorderModeNVToString(VkRayTracingInvocationReorderModeNV e);
const char *VkLayerSettingTypeEXTToString(VkLayerSettingTypeEXT e);
const char *VkLatencyMarkerNVToString(VkLatencyMarkerNV e);
const char *VkOutOfBandQueueTypeNVToString(VkOutOfBandQueueTypeNV e);
const char *VkBlockMatchWindowCompareModeQCOMToString(VkBlockMatchWindowCompareModeQCOM e);
const char *VkCubicFilterWeightsQCOMToString(VkCubicFilterWeightsQCOM e);
const char *VkLayeredDriverUnderlyingApiMSFTToString(VkLayeredDriverUnderlyingApiMSFT e);
const char *VkBuildAccelerationStructureModeKHRToString(VkBuildAccelerationStructureModeKHR e);
const char *VkShaderGroupShaderKHRToString(VkShaderGroupShaderKHR e);


// Declare ostream operators for enums.

std::ostream &operator<<(std::ostream & os, const VkResult &t);
std::ostream &operator<<(std::ostream & os, const VkStructureType &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineCacheHeaderVersion &t);
std::ostream &operator<<(std::ostream & os, const VkImageLayout &t);
std::ostream &operator<<(std::ostream & os, const VkObjectType &t);
std::ostream &operator<<(std::ostream & os, const VkVendorId &t);
std::ostream &operator<<(std::ostream & os, const VkSystemAllocationScope &t);
std::ostream &operator<<(std::ostream & os, const VkInternalAllocationType &t);
std::ostream &operator<<(std::ostream & os, const VkFormat &t);
std::ostream &operator<<(std::ostream & os, const VkImageTiling &t);
std::ostream &operator<<(std::ostream & os, const VkImageType &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceType &t);
std::ostream &operator<<(std::ostream & os, const VkQueryType &t);
std::ostream &operator<<(std::ostream & os, const VkSharingMode &t);
std::ostream &operator<<(std::ostream & os, const VkComponentSwizzle &t);
std::ostream &operator<<(std::ostream & os, const VkImageViewType &t);
std::ostream &operator<<(std::ostream & os, const VkBlendFactor &t);
std::ostream &operator<<(std::ostream & os, const VkBlendOp &t);
std::ostream &operator<<(std::ostream & os, const VkCompareOp &t);
std::ostream &operator<<(std::ostream & os, const VkDynamicState &t);
std::ostream &operator<<(std::ostream & os, const VkFrontFace &t);
std::ostream &operator<<(std::ostream & os, const VkVertexInputRate &t);
std::ostream &operator<<(std::ostream & os, const VkPrimitiveTopology &t);
std::ostream &operator<<(std::ostream & os, const VkPolygonMode &t);
std::ostream &operator<<(std::ostream & os, const VkStencilOp &t);
std::ostream &operator<<(std::ostream & os, const VkLogicOp &t);
std::ostream &operator<<(std::ostream & os, const VkBorderColor &t);
std::ostream &operator<<(std::ostream & os, const VkFilter &t);
std::ostream &operator<<(std::ostream & os, const VkSamplerAddressMode &t);
std::ostream &operator<<(std::ostream & os, const VkSamplerMipmapMode &t);
std::ostream &operator<<(std::ostream & os, const VkDescriptorType &t);
std::ostream &operator<<(std::ostream & os, const VkAttachmentLoadOp &t);
std::ostream &operator<<(std::ostream & os, const VkAttachmentStoreOp &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineBindPoint &t);
std::ostream &operator<<(std::ostream & os, const VkCommandBufferLevel &t);
std::ostream &operator<<(std::ostream & os, const VkIndexType &t);
std::ostream &operator<<(std::ostream & os, const VkSubpassContents &t);
std::ostream &operator<<(std::ostream & os, const VkPointClippingBehavior &t);
std::ostream &operator<<(std::ostream & os, const VkTessellationDomainOrigin &t);
std::ostream &operator<<(std::ostream & os, const VkSamplerYcbcrModelConversion &t);
std::ostream &operator<<(std::ostream & os, const VkSamplerYcbcrRange &t);
std::ostream &operator<<(std::ostream & os, const VkChromaLocation &t);
std::ostream &operator<<(std::ostream & os, const VkDescriptorUpdateTemplateType &t);
std::ostream &operator<<(std::ostream & os, const VkDriverId &t);
std::ostream &operator<<(std::ostream & os, const VkShaderFloatControlsIndependence &t);
std::ostream &operator<<(std::ostream & os, const VkSamplerReductionMode &t);
std::ostream &operator<<(std::ostream & os, const VkSemaphoreType &t);
std::ostream &operator<<(std::ostream & os, const VkPresentModeKHR &t);
std::ostream &operator<<(std::ostream & os, const VkColorSpaceKHR &t);
std::ostream &operator<<(std::ostream & os, const VkQueryResultStatusKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPerformanceCounterUnitKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPerformanceCounterScopeKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPerformanceCounterStorageKHR &t);
std::ostream &operator<<(std::ostream & os, const VkQueueGlobalPriorityKHR &t);
std::ostream &operator<<(std::ostream & os, const VkFragmentShadingRateCombinerOpKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineExecutableStatisticFormatKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeTuningModeKHR &t);
std::ostream &operator<<(std::ostream & os, const VkComponentTypeKHR &t);
std::ostream &operator<<(std::ostream & os, const VkScopeKHR &t);
std::ostream &operator<<(std::ostream & os, const VkTimeDomainKHR &t);
std::ostream &operator<<(std::ostream & os, const VkDebugReportObjectTypeEXT &t);
std::ostream &operator<<(std::ostream & os, const VkRasterizationOrderAMD &t);
std::ostream &operator<<(std::ostream & os, const VkShaderInfoTypeAMD &t);
std::ostream &operator<<(std::ostream & os, const VkValidationCheckEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineRobustnessBufferBehaviorEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineRobustnessImageBehaviorEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDisplayPowerStateEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceEventTypeEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDisplayEventTypeEXT &t);
std::ostream &operator<<(std::ostream & os, const VkViewportCoordinateSwizzleNV &t);
std::ostream &operator<<(std::ostream & os, const VkDiscardRectangleModeEXT &t);
std::ostream &operator<<(std::ostream & os, const VkConservativeRasterizationModeEXT &t);
std::ostream &operator<<(std::ostream & os, const VkBlendOverlapEXT &t);
std::ostream &operator<<(std::ostream & os, const VkCoverageModulationModeNV &t);
std::ostream &operator<<(std::ostream & os, const VkValidationCacheHeaderVersionEXT &t);
std::ostream &operator<<(std::ostream & os, const VkShadingRatePaletteEntryNV &t);
std::ostream &operator<<(std::ostream & os, const VkCoarseSampleOrderTypeNV &t);
std::ostream &operator<<(std::ostream & os, const VkRayTracingShaderGroupTypeKHR &t);
std::ostream &operator<<(std::ostream & os, const VkGeometryTypeKHR &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureTypeKHR &t);
std::ostream &operator<<(std::ostream & os, const VkCopyAccelerationStructureModeKHR &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureMemoryRequirementsTypeNV &t);
std::ostream &operator<<(std::ostream & os, const VkMemoryOverallocationBehaviorAMD &t);
std::ostream &operator<<(std::ostream & os, const VkPerformanceConfigurationTypeINTEL &t);
std::ostream &operator<<(std::ostream & os, const VkQueryPoolSamplingModeINTEL &t);
std::ostream &operator<<(std::ostream & os, const VkPerformanceOverrideTypeINTEL &t);
std::ostream &operator<<(std::ostream & os, const VkPerformanceParameterTypeINTEL &t);
std::ostream &operator<<(std::ostream & os, const VkPerformanceValueTypeINTEL &t);
std::ostream &operator<<(std::ostream & os, const VkValidationFeatureEnableEXT &t);
std::ostream &operator<<(std::ostream & os, const VkValidationFeatureDisableEXT &t);
std::ostream &operator<<(std::ostream & os, const VkCoverageReductionModeNV &t);
std::ostream &operator<<(std::ostream & os, const VkProvokingVertexModeEXT &t);
#ifdef VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream & os, const VkFullScreenExclusiveEXT &t);
#endif //VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream & os, const VkLineRasterizationModeEXT &t);
std::ostream &operator<<(std::ostream & os, const VkIndirectCommandsTokenTypeNV &t);
std::ostream &operator<<(std::ostream & os, const VkDepthBiasRepresentationEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceMemoryReportEventTypeEXT &t);
std::ostream &operator<<(std::ostream & os, const VkFragmentShadingRateTypeNV &t);
std::ostream &operator<<(std::ostream & os, const VkFragmentShadingRateNV &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureMotionInstanceTypeNV &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceFaultAddressTypeEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceFaultVendorBinaryHeaderVersionEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceAddressBindingTypeEXT &t);
std::ostream &operator<<(std::ostream & os, const VkMicromapTypeEXT &t);
std::ostream &operator<<(std::ostream & os, const VkBuildMicromapModeEXT &t);
std::ostream &operator<<(std::ostream & os, const VkCopyMicromapModeEXT &t);
std::ostream &operator<<(std::ostream & os, const VkOpacityMicromapFormatEXT &t);
std::ostream &operator<<(std::ostream & os, const VkOpacityMicromapSpecialIndexEXT &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureCompatibilityKHR &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureBuildTypeKHR &t);
#ifdef VK_ENABLE_BETA_EXTENSIONS
std::ostream &operator<<(std::ostream & os, const VkDisplacementMicromapFormatNV &t);
#endif //VK_ENABLE_BETA_EXTENSIONS
std::ostream &operator<<(std::ostream & os, const VkSubpassMergeStatusEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDirectDriverLoadingModeLUNARG &t);
std::ostream &operator<<(std::ostream & os, const VkOpticalFlowPerformanceLevelNV &t);
std::ostream &operator<<(std::ostream & os, const VkOpticalFlowSessionBindingPointNV &t);
std::ostream &operator<<(std::ostream & os, const VkShaderCodeTypeEXT &t);
std::ostream &operator<<(std::ostream & os, const VkRayTracingInvocationReorderModeNV &t);
std::ostream &operator<<(std::ostream & os, const VkLayerSettingTypeEXT &t);
std::ostream &operator<<(std::ostream & os, const VkLatencyMarkerNV &t);
std::ostream &operator<<(std::ostream & os, const VkOutOfBandQueueTypeNV &t);
std::ostream &operator<<(std::ostream & os, const VkBlockMatchWindowCompareModeQCOM &t);
std::ostream &operator<<(std::ostream & os, const VkCubicFilterWeightsQCOM &t);
std::ostream &operator<<(std::ostream & os, const VkLayeredDriverUnderlyingApiMSFT &t);
std::ostream &operator<<(std::ostream & os, const VkBuildAccelerationStructureModeKHR &t);
std::ostream &operator<<(std::ostream & os, const VkShaderGroupShaderKHR &t);


// Declare all ostream operators.

std::ostream &operator<<(std::ostream & os, const VkExtent2D &t);
std::ostream &operator<<(std::ostream & os, const VkExtent3D &t);
std::ostream &operator<<(std::ostream & os, const VkOffset2D &t);
std::ostream &operator<<(std::ostream & os, const VkOffset3D &t);
std::ostream &operator<<(std::ostream & os, const VkRect2D &t);
std::ostream &operator<<(std::ostream & os, const VkBaseInStructure &t);
std::ostream &operator<<(std::ostream & os, const VkBaseOutStructure &t);
std::ostream &operator<<(std::ostream & os, const VkBufferMemoryBarrier &t);
std::ostream &operator<<(std::ostream & os, const VkDispatchIndirectCommand &t);
std::ostream &operator<<(std::ostream & os, const VkDrawIndexedIndirectCommand &t);
std::ostream &operator<<(std::ostream & os, const VkDrawIndirectCommand &t);
std::ostream &operator<<(std::ostream & os, const VkImageSubresourceRange &t);
std::ostream &operator<<(std::ostream & os, const VkImageMemoryBarrier &t);
std::ostream &operator<<(std::ostream & os, const VkMemoryBarrier &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineCacheHeaderVersionOne &t);
std::ostream &operator<<(std::ostream & os, const VkAllocationCallbacks &t);
std::ostream &operator<<(std::ostream & os, const VkApplicationInfo &t);
std::ostream &operator<<(std::ostream & os, const VkFormatProperties &t);
std::ostream &operator<<(std::ostream & os, const VkImageFormatProperties &t);
std::ostream &operator<<(std::ostream & os, const VkInstanceCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkMemoryHeap &t);
std::ostream &operator<<(std::ostream & os, const VkMemoryType &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceLimits &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceMemoryProperties &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceSparseProperties &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceProperties &t);
std::ostream &operator<<(std::ostream & os, const VkQueueFamilyProperties &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceQueueCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkExtensionProperties &t);
std::ostream &operator<<(std::ostream & os, const VkLayerProperties &t);
std::ostream &operator<<(std::ostream & os, const VkSubmitInfo &t);
std::ostream &operator<<(std::ostream & os, const VkMappedMemoryRange &t);
std::ostream &operator<<(std::ostream & os, const VkMemoryAllocateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkMemoryRequirements &t);
std::ostream &operator<<(std::ostream & os, const VkSparseMemoryBind &t);
std::ostream &operator<<(std::ostream & os, const VkSparseBufferMemoryBindInfo &t);
std::ostream &operator<<(std::ostream & os, const VkSparseImageOpaqueMemoryBindInfo &t);
std::ostream &operator<<(std::ostream & os, const VkImageSubresource &t);
std::ostream &operator<<(std::ostream & os, const VkSparseImageMemoryBind &t);
std::ostream &operator<<(std::ostream & os, const VkSparseImageMemoryBindInfo &t);
std::ostream &operator<<(std::ostream & os, const VkBindSparseInfo &t);
std::ostream &operator<<(std::ostream & os, const VkSparseImageFormatProperties &t);
std::ostream &operator<<(std::ostream & os, const VkSparseImageMemoryRequirements &t);
std::ostream &operator<<(std::ostream & os, const VkFenceCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkSemaphoreCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkEventCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkQueryPoolCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkBufferCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkBufferViewCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkImageCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkSubresourceLayout &t);
std::ostream &operator<<(std::ostream & os, const VkComponentMapping &t);
std::ostream &operator<<(std::ostream & os, const VkImageViewCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkShaderModuleCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineCacheCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkSpecializationMapEntry &t);
std::ostream &operator<<(std::ostream & os, const VkSpecializationInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineShaderStageCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkComputePipelineCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkVertexInputBindingDescription &t);
std::ostream &operator<<(std::ostream & os, const VkVertexInputAttributeDescription &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineVertexInputStateCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineInputAssemblyStateCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineTessellationStateCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkViewport &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineViewportStateCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineRasterizationStateCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineMultisampleStateCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkStencilOpState &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineDepthStencilStateCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineColorBlendAttachmentState &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineColorBlendStateCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineDynamicStateCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkGraphicsPipelineCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPushConstantRange &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineLayoutCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkSamplerCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkCopyDescriptorSet &t);
std::ostream &operator<<(std::ostream & os, const VkDescriptorBufferInfo &t);
std::ostream &operator<<(std::ostream & os, const VkDescriptorImageInfo &t);
std::ostream &operator<<(std::ostream & os, const VkDescriptorPoolSize &t);
std::ostream &operator<<(std::ostream & os, const VkDescriptorPoolCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkDescriptorSetAllocateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkDescriptorSetLayoutBinding &t);
std::ostream &operator<<(std::ostream & os, const VkDescriptorSetLayoutCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkWriteDescriptorSet &t);
std::ostream &operator<<(std::ostream & os, const VkAttachmentDescription &t);
std::ostream &operator<<(std::ostream & os, const VkAttachmentReference &t);
std::ostream &operator<<(std::ostream & os, const VkFramebufferCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkSubpassDescription &t);
std::ostream &operator<<(std::ostream & os, const VkSubpassDependency &t);
std::ostream &operator<<(std::ostream & os, const VkRenderPassCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkCommandPoolCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkCommandBufferAllocateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkCommandBufferInheritanceInfo &t);
std::ostream &operator<<(std::ostream & os, const VkCommandBufferBeginInfo &t);
std::ostream &operator<<(std::ostream & os, const VkBufferCopy &t);
std::ostream &operator<<(std::ostream & os, const VkImageSubresourceLayers &t);
std::ostream &operator<<(std::ostream & os, const VkBufferImageCopy &t);
std::ostream &operator<<(std::ostream & os, const VkClearColorValue &t);
std::ostream &operator<<(std::ostream & os, const VkClearDepthStencilValue &t);
std::ostream &operator<<(std::ostream & os, const VkClearValue &t);
std::ostream &operator<<(std::ostream & os, const VkClearAttachment &t);
std::ostream &operator<<(std::ostream & os, const VkClearRect &t);
std::ostream &operator<<(std::ostream & os, const VkImageBlit &t);
std::ostream &operator<<(std::ostream & os, const VkImageCopy &t);
std::ostream &operator<<(std::ostream & os, const VkImageResolve &t);
std::ostream &operator<<(std::ostream & os, const VkRenderPassBeginInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceSubgroupProperties &t);
std::ostream &operator<<(std::ostream & os, const VkBindBufferMemoryInfo &t);
std::ostream &operator<<(std::ostream & os, const VkBindImageMemoryInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDevice16BitStorageFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkMemoryDedicatedRequirements &t);
std::ostream &operator<<(std::ostream & os, const VkMemoryDedicatedAllocateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkMemoryAllocateFlagsInfo &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceGroupRenderPassBeginInfo &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceGroupCommandBufferBeginInfo &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceGroupSubmitInfo &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceGroupBindSparseInfo &t);
std::ostream &operator<<(std::ostream & os, const VkBindBufferMemoryDeviceGroupInfo &t);
std::ostream &operator<<(std::ostream & os, const VkBindImageMemoryDeviceGroupInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceGroupProperties &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceGroupDeviceCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkBufferMemoryRequirementsInfo2 &t);
std::ostream &operator<<(std::ostream & os, const VkImageMemoryRequirementsInfo2 &t);
std::ostream &operator<<(std::ostream & os, const VkImageSparseMemoryRequirementsInfo2 &t);
std::ostream &operator<<(std::ostream & os, const VkMemoryRequirements2 &t);
std::ostream &operator<<(std::ostream & os, const VkSparseImageMemoryRequirements2 &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceFeatures2 &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceProperties2 &t);
std::ostream &operator<<(std::ostream & os, const VkFormatProperties2 &t);
std::ostream &operator<<(std::ostream & os, const VkImageFormatProperties2 &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceImageFormatInfo2 &t);
std::ostream &operator<<(std::ostream & os, const VkQueueFamilyProperties2 &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceMemoryProperties2 &t);
std::ostream &operator<<(std::ostream & os, const VkSparseImageFormatProperties2 &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceSparseImageFormatInfo2 &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDevicePointClippingProperties &t);
std::ostream &operator<<(std::ostream & os, const VkInputAttachmentAspectReference &t);
std::ostream &operator<<(std::ostream & os, const VkRenderPassInputAttachmentAspectCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkImageViewUsageCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineTessellationDomainOriginStateCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkRenderPassMultiviewCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceMultiviewFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceMultiviewProperties &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceVariablePointersFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceProtectedMemoryFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceProtectedMemoryProperties &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceQueueInfo2 &t);
std::ostream &operator<<(std::ostream & os, const VkProtectedSubmitInfo &t);
std::ostream &operator<<(std::ostream & os, const VkSamplerYcbcrConversionCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkSamplerYcbcrConversionInfo &t);
std::ostream &operator<<(std::ostream & os, const VkBindImagePlaneMemoryInfo &t);
std::ostream &operator<<(std::ostream & os, const VkImagePlaneMemoryRequirementsInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceSamplerYcbcrConversionFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkSamplerYcbcrConversionImageFormatProperties &t);
std::ostream &operator<<(std::ostream & os, const VkDescriptorUpdateTemplateEntry &t);
std::ostream &operator<<(std::ostream & os, const VkDescriptorUpdateTemplateCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkExternalMemoryProperties &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceExternalImageFormatInfo &t);
std::ostream &operator<<(std::ostream & os, const VkExternalImageFormatProperties &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceExternalBufferInfo &t);
std::ostream &operator<<(std::ostream & os, const VkExternalBufferProperties &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceIDProperties &t);
std::ostream &operator<<(std::ostream & os, const VkExternalMemoryImageCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkExternalMemoryBufferCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkExportMemoryAllocateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceExternalFenceInfo &t);
std::ostream &operator<<(std::ostream & os, const VkExternalFenceProperties &t);
std::ostream &operator<<(std::ostream & os, const VkExportFenceCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkExportSemaphoreCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceExternalSemaphoreInfo &t);
std::ostream &operator<<(std::ostream & os, const VkExternalSemaphoreProperties &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceMaintenance3Properties &t);
std::ostream &operator<<(std::ostream & os, const VkDescriptorSetLayoutSupport &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderDrawParametersFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceVulkan11Features &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceVulkan11Properties &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceVulkan12Features &t);
std::ostream &operator<<(std::ostream & os, const VkConformanceVersion &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceVulkan12Properties &t);
std::ostream &operator<<(std::ostream & os, const VkImageFormatListCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkAttachmentDescription2 &t);
std::ostream &operator<<(std::ostream & os, const VkAttachmentReference2 &t);
std::ostream &operator<<(std::ostream & os, const VkSubpassDescription2 &t);
std::ostream &operator<<(std::ostream & os, const VkSubpassDependency2 &t);
std::ostream &operator<<(std::ostream & os, const VkRenderPassCreateInfo2 &t);
std::ostream &operator<<(std::ostream & os, const VkSubpassBeginInfo &t);
std::ostream &operator<<(std::ostream & os, const VkSubpassEndInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDevice8BitStorageFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceDriverProperties &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderAtomicInt64Features &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderFloat16Int8Features &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceFloatControlsProperties &t);
std::ostream &operator<<(std::ostream & os, const VkDescriptorSetLayoutBindingFlagsCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceDescriptorIndexingFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceDescriptorIndexingProperties &t);
std::ostream &operator<<(std::ostream & os, const VkDescriptorSetVariableDescriptorCountAllocateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkDescriptorSetVariableDescriptorCountLayoutSupport &t);
std::ostream &operator<<(std::ostream & os, const VkSubpassDescriptionDepthStencilResolve &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceDepthStencilResolveProperties &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceScalarBlockLayoutFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkImageStencilUsageCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkSamplerReductionModeCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceSamplerFilterMinmaxProperties &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceVulkanMemoryModelFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceImagelessFramebufferFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkFramebufferAttachmentImageInfo &t);
std::ostream &operator<<(std::ostream & os, const VkFramebufferAttachmentsCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkRenderPassAttachmentBeginInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceUniformBufferStandardLayoutFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkAttachmentReferenceStencilLayout &t);
std::ostream &operator<<(std::ostream & os, const VkAttachmentDescriptionStencilLayout &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceHostQueryResetFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceTimelineSemaphoreFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceTimelineSemaphoreProperties &t);
std::ostream &operator<<(std::ostream & os, const VkSemaphoreTypeCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkTimelineSemaphoreSubmitInfo &t);
std::ostream &operator<<(std::ostream & os, const VkSemaphoreWaitInfo &t);
std::ostream &operator<<(std::ostream & os, const VkSemaphoreSignalInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceBufferDeviceAddressFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkBufferDeviceAddressInfo &t);
std::ostream &operator<<(std::ostream & os, const VkBufferOpaqueCaptureAddressCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkMemoryOpaqueCaptureAddressAllocateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceMemoryOpaqueCaptureAddressInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceVulkan13Features &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceVulkan13Properties &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineCreationFeedback &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineCreationFeedbackCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderTerminateInvocationFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceToolProperties &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDevicePrivateDataFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkDevicePrivateDataCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPrivateDataSlotCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDevicePipelineCreationCacheControlFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkMemoryBarrier2 &t);
std::ostream &operator<<(std::ostream & os, const VkBufferMemoryBarrier2 &t);
std::ostream &operator<<(std::ostream & os, const VkImageMemoryBarrier2 &t);
std::ostream &operator<<(std::ostream & os, const VkDependencyInfo &t);
std::ostream &operator<<(std::ostream & os, const VkSemaphoreSubmitInfo &t);
std::ostream &operator<<(std::ostream & os, const VkCommandBufferSubmitInfo &t);
std::ostream &operator<<(std::ostream & os, const VkSubmitInfo2 &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceSynchronization2Features &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceImageRobustnessFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkBufferCopy2 &t);
std::ostream &operator<<(std::ostream & os, const VkCopyBufferInfo2 &t);
std::ostream &operator<<(std::ostream & os, const VkImageCopy2 &t);
std::ostream &operator<<(std::ostream & os, const VkCopyImageInfo2 &t);
std::ostream &operator<<(std::ostream & os, const VkBufferImageCopy2 &t);
std::ostream &operator<<(std::ostream & os, const VkCopyBufferToImageInfo2 &t);
std::ostream &operator<<(std::ostream & os, const VkCopyImageToBufferInfo2 &t);
std::ostream &operator<<(std::ostream & os, const VkImageBlit2 &t);
std::ostream &operator<<(std::ostream & os, const VkBlitImageInfo2 &t);
std::ostream &operator<<(std::ostream & os, const VkImageResolve2 &t);
std::ostream &operator<<(std::ostream & os, const VkResolveImageInfo2 &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceSubgroupSizeControlFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceSubgroupSizeControlProperties &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineShaderStageRequiredSubgroupSizeCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceInlineUniformBlockFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceInlineUniformBlockProperties &t);
std::ostream &operator<<(std::ostream & os, const VkWriteDescriptorSetInlineUniformBlock &t);
std::ostream &operator<<(std::ostream & os, const VkDescriptorPoolInlineUniformBlockCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceTextureCompressionASTCHDRFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkRenderingAttachmentInfo &t);
std::ostream &operator<<(std::ostream & os, const VkRenderingInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineRenderingCreateInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceDynamicRenderingFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkCommandBufferInheritanceRenderingInfo &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderIntegerDotProductFeatures &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderIntegerDotProductProperties &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceTexelBufferAlignmentProperties &t);
std::ostream &operator<<(std::ostream & os, const VkFormatProperties3 &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceMaintenance4Features &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceMaintenance4Properties &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceBufferMemoryRequirements &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceImageMemoryRequirements &t);
std::ostream &operator<<(std::ostream & os, const VkSurfaceCapabilitiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkSurfaceFormatKHR &t);
std::ostream &operator<<(std::ostream & os, const VkSwapchainCreateInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPresentInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkImageSwapchainCreateInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkBindImageMemorySwapchainInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkAcquireNextImageInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceGroupPresentCapabilitiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceGroupPresentInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceGroupSwapchainCreateInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkDisplayModeParametersKHR &t);
std::ostream &operator<<(std::ostream & os, const VkDisplayModeCreateInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkDisplayModePropertiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkDisplayPlaneCapabilitiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkDisplayPlanePropertiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkDisplayPropertiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkDisplaySurfaceCreateInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkDisplayPresentInfoKHR &t);
#ifdef VK_USE_PLATFORM_XLIB_KHR
std::ostream &operator<<(std::ostream & os, const VkXlibSurfaceCreateInfoKHR &t);
#endif //VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
std::ostream &operator<<(std::ostream & os, const VkXcbSurfaceCreateInfoKHR &t);
#endif //VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
std::ostream &operator<<(std::ostream & os, const VkWaylandSurfaceCreateInfoKHR &t);
#endif //VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
std::ostream &operator<<(std::ostream & os, const VkAndroidSurfaceCreateInfoKHR &t);
#endif //VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream & os, const VkWin32SurfaceCreateInfoKHR &t);
#endif //VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream & os, const VkQueueFamilyQueryResultStatusPropertiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkQueueFamilyVideoPropertiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoProfileInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoProfileListInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoCapabilitiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceVideoFormatInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoFormatPropertiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoPictureResourceInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoReferenceSlotInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoSessionMemoryRequirementsKHR &t);
std::ostream &operator<<(std::ostream & os, const VkBindVideoSessionMemoryInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoSessionCreateInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoSessionParametersCreateInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoSessionParametersUpdateInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoBeginCodingInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEndCodingInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoCodingControlInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoDecodeCapabilitiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoDecodeUsageInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoDecodeInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH264CapabilitiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH264QpKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH264QualityLevelPropertiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH264SessionCreateInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH264SessionParametersAddInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH264SessionParametersCreateInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH264SessionParametersGetInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH264SessionParametersFeedbackInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH264NaluSliceInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH264PictureInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH264DpbSlotInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH264ProfileInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH264RateControlInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH264FrameSizeKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH264RateControlLayerInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH264GopRemainingFrameInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH265CapabilitiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH265SessionCreateInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH265QpKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH265QualityLevelPropertiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH265SessionParametersAddInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH265SessionParametersCreateInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH265SessionParametersGetInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH265SessionParametersFeedbackInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH265NaluSliceSegmentInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH265PictureInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH265DpbSlotInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH265ProfileInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH265RateControlInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH265FrameSizeKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH265RateControlLayerInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeH265GopRemainingFrameInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoDecodeH264ProfileInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoDecodeH264CapabilitiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoDecodeH264SessionParametersAddInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoDecodeH264SessionParametersCreateInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoDecodeH264PictureInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoDecodeH264DpbSlotInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkRenderingFragmentShadingRateAttachmentInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkRenderingFragmentDensityMapAttachmentInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkAttachmentSampleCountInfoAMD &t);
std::ostream &operator<<(std::ostream & os, const VkMultiviewPerViewAttributesInfoNVX &t);
#ifdef VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream & os, const VkImportMemoryWin32HandleInfoKHR &t);
#endif //VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream & os, const VkExportMemoryWin32HandleInfoKHR &t);
#endif //VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream & os, const VkMemoryWin32HandlePropertiesKHR &t);
#endif //VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream & os, const VkMemoryGetWin32HandleInfoKHR &t);
#endif //VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream & os, const VkImportMemoryFdInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkMemoryFdPropertiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkMemoryGetFdInfoKHR &t);
#ifdef VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream & os, const VkWin32KeyedMutexAcquireReleaseInfoKHR &t);
#endif //VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream & os, const VkImportSemaphoreWin32HandleInfoKHR &t);
#endif //VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream & os, const VkExportSemaphoreWin32HandleInfoKHR &t);
#endif //VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream & os, const VkD3D12FenceSubmitInfoKHR &t);
#endif //VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream & os, const VkSemaphoreGetWin32HandleInfoKHR &t);
#endif //VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream & os, const VkImportSemaphoreFdInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkSemaphoreGetFdInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDevicePushDescriptorPropertiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkRectLayerKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPresentRegionKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPresentRegionsKHR &t);
std::ostream &operator<<(std::ostream & os, const VkSharedPresentSurfaceCapabilitiesKHR &t);
#ifdef VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream & os, const VkImportFenceWin32HandleInfoKHR &t);
#endif //VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream & os, const VkExportFenceWin32HandleInfoKHR &t);
#endif //VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream & os, const VkFenceGetWin32HandleInfoKHR &t);
#endif //VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream & os, const VkImportFenceFdInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkFenceGetFdInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDevicePerformanceQueryFeaturesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDevicePerformanceQueryPropertiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPerformanceCounterKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPerformanceCounterDescriptionKHR &t);
std::ostream &operator<<(std::ostream & os, const VkQueryPoolPerformanceCreateInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPerformanceCounterResultKHR &t);
std::ostream &operator<<(std::ostream & os, const VkAcquireProfilingLockInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPerformanceQuerySubmitInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceSurfaceInfo2KHR &t);
std::ostream &operator<<(std::ostream & os, const VkSurfaceCapabilities2KHR &t);
std::ostream &operator<<(std::ostream & os, const VkSurfaceFormat2KHR &t);
std::ostream &operator<<(std::ostream & os, const VkDisplayProperties2KHR &t);
std::ostream &operator<<(std::ostream & os, const VkDisplayPlaneProperties2KHR &t);
std::ostream &operator<<(std::ostream & os, const VkDisplayModeProperties2KHR &t);
std::ostream &operator<<(std::ostream & os, const VkDisplayPlaneInfo2KHR &t);
std::ostream &operator<<(std::ostream & os, const VkDisplayPlaneCapabilities2KHR &t);
#ifdef VK_ENABLE_BETA_EXTENSIONS
std::ostream &operator<<(std::ostream & os, const VkPhysicalDevicePortabilitySubsetFeaturesKHR &t);
#endif //VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
std::ostream &operator<<(std::ostream & os, const VkPhysicalDevicePortabilitySubsetPropertiesKHR &t);
#endif //VK_ENABLE_BETA_EXTENSIONS
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderClockFeaturesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoDecodeH265ProfileInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoDecodeH265CapabilitiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoDecodeH265SessionParametersAddInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoDecodeH265SessionParametersCreateInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoDecodeH265PictureInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoDecodeH265DpbSlotInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceQueueGlobalPriorityCreateInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkQueueFamilyGlobalPriorityPropertiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkFragmentShadingRateAttachmentInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineFragmentShadingRateStateCreateInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceFragmentShadingRateFeaturesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceFragmentShadingRatePropertiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceFragmentShadingRateKHR &t);
std::ostream &operator<<(std::ostream & os, const VkSurfaceProtectedCapabilitiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDevicePresentWaitFeaturesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineExecutablePropertiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineExecutableInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineExecutableStatisticValueKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineExecutableStatisticKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineExecutableInternalRepresentationKHR &t);
std::ostream &operator<<(std::ostream & os, const VkMemoryMapInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkMemoryUnmapInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineLibraryCreateInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPresentIdKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDevicePresentIdFeaturesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeCapabilitiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkQueryPoolVideoEncodeFeedbackCreateInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeUsageInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeRateControlLayerInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeRateControlInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeQualityLevelPropertiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeQualityLevelInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeSessionParametersGetInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoEncodeSessionParametersFeedbackInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkQueueFamilyCheckpointProperties2NV &t);
std::ostream &operator<<(std::ostream & os, const VkCheckpointData2NV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkTraceRaysIndirectCommand2KHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceMaintenance5FeaturesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceMaintenance5PropertiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkRenderingAreaInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkImageSubresource2KHR &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceImageSubresourceInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkSubresourceLayout2KHR &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineCreateFlags2CreateInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkBufferUsageFlags2CreateInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkCooperativeMatrixPropertiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceCooperativeMatrixFeaturesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceCooperativeMatrixPropertiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceVideoMaintenance1FeaturesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVideoInlineQueryInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkVertexInputBindingDivisorDescriptionKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineVertexInputDivisorStateCreateInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkCalibratedTimestampInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceMaintenance6FeaturesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceMaintenance6PropertiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkBindMemoryStatusKHR &t);
std::ostream &operator<<(std::ostream & os, const VkBindDescriptorSetsInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPushConstantsInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPushDescriptorSetInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPushDescriptorSetWithTemplateInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkSetDescriptorBufferOffsetsInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkBindDescriptorBufferEmbeddedSamplersInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDebugReportCallbackCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineRasterizationStateRasterizationOrderAMD &t);
std::ostream &operator<<(std::ostream & os, const VkDebugMarkerObjectNameInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDebugMarkerObjectTagInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDebugMarkerMarkerInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDedicatedAllocationImageCreateInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkDedicatedAllocationBufferCreateInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkDedicatedAllocationMemoryAllocateInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceTransformFeedbackFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceTransformFeedbackPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineRasterizationStateStreamCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkCuModuleCreateInfoNVX &t);
std::ostream &operator<<(std::ostream & os, const VkCuFunctionCreateInfoNVX &t);
std::ostream &operator<<(std::ostream & os, const VkCuLaunchInfoNVX &t);
std::ostream &operator<<(std::ostream & os, const VkImageViewHandleInfoNVX &t);
std::ostream &operator<<(std::ostream & os, const VkImageViewAddressPropertiesNVX &t);
std::ostream &operator<<(std::ostream & os, const VkTextureLODGatherFormatPropertiesAMD &t);
std::ostream &operator<<(std::ostream & os, const VkShaderResourceUsageAMD &t);
std::ostream &operator<<(std::ostream & os, const VkShaderStatisticsInfoAMD &t);
#ifdef VK_USE_PLATFORM_GGP
std::ostream &operator<<(std::ostream & os, const VkStreamDescriptorSurfaceCreateInfoGGP &t);
#endif //VK_USE_PLATFORM_GGP
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceCornerSampledImageFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkExternalImageFormatPropertiesNV &t);
std::ostream &operator<<(std::ostream & os, const VkExternalMemoryImageCreateInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkExportMemoryAllocateInfoNV &t);
#ifdef VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream & os, const VkImportMemoryWin32HandleInfoNV &t);
#endif //VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream & os, const VkExportMemoryWin32HandleInfoNV &t);
#endif //VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream & os, const VkWin32KeyedMutexAcquireReleaseInfoNV &t);
#endif //VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream & os, const VkValidationFlagsEXT &t);
#ifdef VK_USE_PLATFORM_VI_NN
std::ostream &operator<<(std::ostream & os, const VkViSurfaceCreateInfoNN &t);
#endif //VK_USE_PLATFORM_VI_NN
std::ostream &operator<<(std::ostream & os, const VkImageViewASTCDecodeModeEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceASTCDecodeFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDevicePipelineRobustnessFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDevicePipelineRobustnessPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineRobustnessCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkConditionalRenderingBeginInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceConditionalRenderingFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkCommandBufferInheritanceConditionalRenderingInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkViewportWScalingNV &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineViewportWScalingStateCreateInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkSurfaceCapabilities2EXT &t);
std::ostream &operator<<(std::ostream & os, const VkDisplayPowerInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceEventInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDisplayEventInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkSwapchainCounterCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkRefreshCycleDurationGOOGLE &t);
std::ostream &operator<<(std::ostream & os, const VkPastPresentationTimingGOOGLE &t);
std::ostream &operator<<(std::ostream & os, const VkPresentTimeGOOGLE &t);
std::ostream &operator<<(std::ostream & os, const VkPresentTimesInfoGOOGLE &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX &t);
std::ostream &operator<<(std::ostream & os, const VkViewportSwizzleNV &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineViewportSwizzleStateCreateInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceDiscardRectanglePropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineDiscardRectangleStateCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceConservativeRasterizationPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineRasterizationConservativeStateCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceDepthClipEnableFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineRasterizationDepthClipStateCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkXYColorEXT &t);
std::ostream &operator<<(std::ostream & os, const VkHdrMetadataEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG &t);
#ifdef VK_USE_PLATFORM_IOS_MVK
std::ostream &operator<<(std::ostream & os, const VkIOSSurfaceCreateInfoMVK &t);
#endif //VK_USE_PLATFORM_IOS_MVK
#ifdef VK_USE_PLATFORM_MACOS_MVK
std::ostream &operator<<(std::ostream & os, const VkMacOSSurfaceCreateInfoMVK &t);
#endif //VK_USE_PLATFORM_MACOS_MVK
std::ostream &operator<<(std::ostream & os, const VkDebugUtilsLabelEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDebugUtilsObjectNameInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDebugUtilsMessengerCallbackDataEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDebugUtilsMessengerCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDebugUtilsObjectTagInfoEXT &t);
#ifdef VK_USE_PLATFORM_ANDROID_KHR
std::ostream &operator<<(std::ostream & os, const VkAndroidHardwareBufferUsageANDROID &t);
#endif //VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
std::ostream &operator<<(std::ostream & os, const VkAndroidHardwareBufferPropertiesANDROID &t);
#endif //VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
std::ostream &operator<<(std::ostream & os, const VkAndroidHardwareBufferFormatPropertiesANDROID &t);
#endif //VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
std::ostream &operator<<(std::ostream & os, const VkImportAndroidHardwareBufferInfoANDROID &t);
#endif //VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
std::ostream &operator<<(std::ostream & os, const VkMemoryGetAndroidHardwareBufferInfoANDROID &t);
#endif //VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
std::ostream &operator<<(std::ostream & os, const VkExternalFormatANDROID &t);
#endif //VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
std::ostream &operator<<(std::ostream & os, const VkAndroidHardwareBufferFormatProperties2ANDROID &t);
#endif //VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_ENABLE_BETA_EXTENSIONS
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderEnqueueFeaturesAMDX &t);
#endif //VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderEnqueuePropertiesAMDX &t);
#endif //VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
std::ostream &operator<<(std::ostream & os, const VkExecutionGraphPipelineScratchSizeAMDX &t);
#endif //VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
std::ostream &operator<<(std::ostream & os, const VkExecutionGraphPipelineCreateInfoAMDX &t);
#endif //VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
std::ostream &operator<<(std::ostream & os, const VkDeviceOrHostAddressConstAMDX &t);
#endif //VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
std::ostream &operator<<(std::ostream & os, const VkDispatchGraphInfoAMDX &t);
#endif //VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
std::ostream &operator<<(std::ostream & os, const VkDispatchGraphCountInfoAMDX &t);
#endif //VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
std::ostream &operator<<(std::ostream & os, const VkPipelineShaderStageNodeCreateInfoAMDX &t);
#endif //VK_ENABLE_BETA_EXTENSIONS
std::ostream &operator<<(std::ostream & os, const VkSampleLocationEXT &t);
std::ostream &operator<<(std::ostream & os, const VkSampleLocationsInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkAttachmentSampleLocationsEXT &t);
std::ostream &operator<<(std::ostream & os, const VkSubpassSampleLocationsEXT &t);
std::ostream &operator<<(std::ostream & os, const VkRenderPassSampleLocationsBeginInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineSampleLocationsStateCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceSampleLocationsPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkMultisamplePropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineColorBlendAdvancedStateCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineCoverageToColorStateCreateInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineCoverageModulationStateCreateInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkDrmFormatModifierPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDrmFormatModifierPropertiesListEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceImageDrmFormatModifierInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkImageDrmFormatModifierListCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkImageDrmFormatModifierExplicitCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkImageDrmFormatModifierPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDrmFormatModifierProperties2EXT &t);
std::ostream &operator<<(std::ostream & os, const VkDrmFormatModifierPropertiesList2EXT &t);
std::ostream &operator<<(std::ostream & os, const VkValidationCacheCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkShaderModuleValidationCacheCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkShadingRatePaletteNV &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineViewportShadingRateImageStateCreateInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShadingRateImageFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShadingRateImagePropertiesNV &t);
std::ostream &operator<<(std::ostream & os, const VkCoarseSampleLocationNV &t);
std::ostream &operator<<(std::ostream & os, const VkCoarseSampleOrderCustomNV &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkRayTracingShaderGroupCreateInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkRayTracingPipelineCreateInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkGeometryTrianglesNV &t);
std::ostream &operator<<(std::ostream & os, const VkGeometryAABBNV &t);
std::ostream &operator<<(std::ostream & os, const VkGeometryDataNV &t);
std::ostream &operator<<(std::ostream & os, const VkGeometryNV &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureCreateInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkBindAccelerationStructureMemoryInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkWriteDescriptorSetAccelerationStructureNV &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureMemoryRequirementsInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceRayTracingPropertiesNV &t);
std::ostream &operator<<(std::ostream & os, const VkTransformMatrixKHR &t);
std::ostream &operator<<(std::ostream & os, const VkAabbPositionsKHR &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureInstanceKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineRepresentativeFragmentTestStateCreateInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceImageViewImageFormatInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkFilterCubicImageViewImageFormatPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkImportMemoryHostPointerInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkMemoryHostPointerPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceExternalMemoryHostPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineCompilerControlCreateInfoAMD &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderCorePropertiesAMD &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceMemoryOverallocationCreateInfoAMD &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT &t);
#ifdef VK_USE_PLATFORM_GGP
std::ostream &operator<<(std::ostream & os, const VkPresentFrameTokenGGP &t);
#endif //VK_USE_PLATFORM_GGP
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceComputeShaderDerivativesFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceMeshShaderFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceMeshShaderPropertiesNV &t);
std::ostream &operator<<(std::ostream & os, const VkDrawMeshTasksIndirectCommandNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderImageFootprintFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineViewportExclusiveScissorStateCreateInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceExclusiveScissorFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkQueueFamilyCheckpointPropertiesNV &t);
std::ostream &operator<<(std::ostream & os, const VkCheckpointDataNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL &t);
std::ostream &operator<<(std::ostream & os, const VkPerformanceValueDataINTEL &t);
std::ostream &operator<<(std::ostream & os, const VkPerformanceValueINTEL &t);
std::ostream &operator<<(std::ostream & os, const VkInitializePerformanceApiInfoINTEL &t);
std::ostream &operator<<(std::ostream & os, const VkQueryPoolPerformanceQueryCreateInfoINTEL &t);
std::ostream &operator<<(std::ostream & os, const VkPerformanceMarkerInfoINTEL &t);
std::ostream &operator<<(std::ostream & os, const VkPerformanceStreamMarkerInfoINTEL &t);
std::ostream &operator<<(std::ostream & os, const VkPerformanceOverrideInfoINTEL &t);
std::ostream &operator<<(std::ostream & os, const VkPerformanceConfigurationAcquireInfoINTEL &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDevicePCIBusInfoPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDisplayNativeHdrSurfaceCapabilitiesAMD &t);
std::ostream &operator<<(std::ostream & os, const VkSwapchainDisplayNativeHdrCreateInfoAMD &t);
#ifdef VK_USE_PLATFORM_FUCHSIA
std::ostream &operator<<(std::ostream & os, const VkImagePipeSurfaceCreateInfoFUCHSIA &t);
#endif //VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_METAL_EXT
std::ostream &operator<<(std::ostream & os, const VkMetalSurfaceCreateInfoEXT &t);
#endif //VK_USE_PLATFORM_METAL_EXT
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceFragmentDensityMapFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceFragmentDensityMapPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkRenderPassFragmentDensityMapCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderCoreProperties2AMD &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceCoherentMemoryFeaturesAMD &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceMemoryBudgetPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceMemoryPriorityFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkMemoryPriorityAllocateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkBufferDeviceAddressCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkValidationFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkCooperativeMatrixPropertiesNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceCooperativeMatrixFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceCooperativeMatrixPropertiesNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceCoverageReductionModeFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineCoverageReductionStateCreateInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkFramebufferMixedSamplesCombinationNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceProvokingVertexFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceProvokingVertexPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineRasterizationProvokingVertexStateCreateInfoEXT &t);
#ifdef VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream & os, const VkSurfaceFullScreenExclusiveInfoEXT &t);
#endif //VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream & os, const VkSurfaceCapabilitiesFullScreenExclusiveEXT &t);
#endif //VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream & os, const VkSurfaceFullScreenExclusiveWin32InfoEXT &t);
#endif //VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream & os, const VkHeadlessSurfaceCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceLineRasterizationFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceLineRasterizationPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineRasterizationLineStateCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceIndexTypeUint8FeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceHostImageCopyFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceHostImageCopyPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkMemoryToImageCopyEXT &t);
std::ostream &operator<<(std::ostream & os, const VkImageToMemoryCopyEXT &t);
std::ostream &operator<<(std::ostream & os, const VkCopyMemoryToImageInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkCopyImageToMemoryInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkCopyImageToImageInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkHostImageLayoutTransitionInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkSubresourceHostMemcpySizeEXT &t);
std::ostream &operator<<(std::ostream & os, const VkHostImageCopyDevicePerformanceQueryEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkSurfacePresentModeEXT &t);
std::ostream &operator<<(std::ostream & os, const VkSurfacePresentScalingCapabilitiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkSurfacePresentModeCompatibilityEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkSwapchainPresentFenceInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkSwapchainPresentModesCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkSwapchainPresentModeInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkSwapchainPresentScalingCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkReleaseSwapchainImagesInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkGraphicsShaderGroupCreateInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkGraphicsPipelineShaderGroupsCreateInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkBindShaderGroupIndirectCommandNV &t);
std::ostream &operator<<(std::ostream & os, const VkBindIndexBufferIndirectCommandNV &t);
std::ostream &operator<<(std::ostream & os, const VkBindVertexBufferIndirectCommandNV &t);
std::ostream &operator<<(std::ostream & os, const VkSetStateFlagsIndirectCommandNV &t);
std::ostream &operator<<(std::ostream & os, const VkIndirectCommandsStreamNV &t);
std::ostream &operator<<(std::ostream & os, const VkIndirectCommandsLayoutTokenNV &t);
std::ostream &operator<<(std::ostream & os, const VkIndirectCommandsLayoutCreateInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkGeneratedCommandsInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkGeneratedCommandsMemoryRequirementsInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceInheritedViewportScissorFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkCommandBufferInheritanceViewportScissorInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkRenderPassTransformBeginInfoQCOM &t);
std::ostream &operator<<(std::ostream & os, const VkCommandBufferInheritanceRenderPassTransformInfoQCOM &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceDepthBiasControlFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDepthBiasInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDepthBiasRepresentationInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceMemoryReportCallbackDataEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceDeviceMemoryReportCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceRobustness2FeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceRobustness2PropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkSamplerCustomBorderColorCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceCustomBorderColorPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceCustomBorderColorFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDevicePresentBarrierFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkSurfaceCapabilitiesPresentBarrierNV &t);
std::ostream &operator<<(std::ostream & os, const VkSwapchainPresentBarrierCreateInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceDiagnosticsConfigFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceDiagnosticsConfigCreateInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkCudaModuleCreateInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkCudaFunctionCreateInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkCudaLaunchInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceCudaKernelLaunchFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceCudaKernelLaunchPropertiesNV &t);
std::ostream &operator<<(std::ostream & os, const VkQueryLowLatencySupportNV &t);
#ifdef VK_USE_PLATFORM_METAL_EXT
std::ostream &operator<<(std::ostream & os, const VkExportMetalObjectCreateInfoEXT &t);
#endif //VK_USE_PLATFORM_METAL_EXT
#ifdef VK_USE_PLATFORM_METAL_EXT
std::ostream &operator<<(std::ostream & os, const VkExportMetalObjectsInfoEXT &t);
#endif //VK_USE_PLATFORM_METAL_EXT
#ifdef VK_USE_PLATFORM_METAL_EXT
std::ostream &operator<<(std::ostream & os, const VkExportMetalDeviceInfoEXT &t);
#endif //VK_USE_PLATFORM_METAL_EXT
#ifdef VK_USE_PLATFORM_METAL_EXT
std::ostream &operator<<(std::ostream & os, const VkExportMetalCommandQueueInfoEXT &t);
#endif //VK_USE_PLATFORM_METAL_EXT
#ifdef VK_USE_PLATFORM_METAL_EXT
std::ostream &operator<<(std::ostream & os, const VkExportMetalBufferInfoEXT &t);
#endif //VK_USE_PLATFORM_METAL_EXT
#ifdef VK_USE_PLATFORM_METAL_EXT
std::ostream &operator<<(std::ostream & os, const VkImportMetalBufferInfoEXT &t);
#endif //VK_USE_PLATFORM_METAL_EXT
#ifdef VK_USE_PLATFORM_METAL_EXT
std::ostream &operator<<(std::ostream & os, const VkExportMetalTextureInfoEXT &t);
#endif //VK_USE_PLATFORM_METAL_EXT
#ifdef VK_USE_PLATFORM_METAL_EXT
std::ostream &operator<<(std::ostream & os, const VkImportMetalTextureInfoEXT &t);
#endif //VK_USE_PLATFORM_METAL_EXT
#ifdef VK_USE_PLATFORM_METAL_EXT
std::ostream &operator<<(std::ostream & os, const VkExportMetalIOSurfaceInfoEXT &t);
#endif //VK_USE_PLATFORM_METAL_EXT
#ifdef VK_USE_PLATFORM_METAL_EXT
std::ostream &operator<<(std::ostream & os, const VkImportMetalIOSurfaceInfoEXT &t);
#endif //VK_USE_PLATFORM_METAL_EXT
#ifdef VK_USE_PLATFORM_METAL_EXT
std::ostream &operator<<(std::ostream & os, const VkExportMetalSharedEventInfoEXT &t);
#endif //VK_USE_PLATFORM_METAL_EXT
#ifdef VK_USE_PLATFORM_METAL_EXT
std::ostream &operator<<(std::ostream & os, const VkImportMetalSharedEventInfoEXT &t);
#endif //VK_USE_PLATFORM_METAL_EXT
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceDescriptorBufferPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceDescriptorBufferFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDescriptorAddressInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDescriptorBufferBindingInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDescriptorBufferBindingPushDescriptorBufferHandleEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDescriptorDataEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDescriptorGetInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkBufferCaptureDescriptorDataInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkImageCaptureDescriptorDataInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkImageViewCaptureDescriptorDataInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkSamplerCaptureDescriptorDataInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkOpaqueCaptureDescriptorDataCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureCaptureDescriptorDataInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkGraphicsPipelineLibraryCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineFragmentShadingRateEnumStateCreateInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceOrHostAddressConstKHR &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureGeometryMotionTrianglesDataNV &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureMotionInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureMatrixMotionInstanceNV &t);
std::ostream &operator<<(std::ostream & os, const VkSRTDataNV &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureSRTMotionInstanceNV &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureMotionInstanceDataNV &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureMotionInstanceNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceFragmentDensityMap2PropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkCopyCommandTransformInfoQCOM &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceImageCompressionControlFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkImageCompressionControlEXT &t);
std::ostream &operator<<(std::ostream & os, const VkImageCompressionPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDevice4444FormatsFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceFaultFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceFaultCountsEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceFaultAddressInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceFaultVendorInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceFaultInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceFaultVendorBinaryHeaderVersionOneEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT &t);
#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
std::ostream &operator<<(std::ostream & os, const VkDirectFBSurfaceCreateInfoEXT &t);
#endif //VK_USE_PLATFORM_DIRECTFB_EXT
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkMutableDescriptorTypeListEXT &t);
std::ostream &operator<<(std::ostream & os, const VkMutableDescriptorTypeCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkVertexInputBindingDescription2EXT &t);
std::ostream &operator<<(std::ostream & os, const VkVertexInputAttributeDescription2EXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceDrmPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceAddressBindingReportFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceAddressBindingCallbackDataEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceDepthClipControlFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineViewportDepthClipControlCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT &t);
#ifdef VK_USE_PLATFORM_FUCHSIA
std::ostream &operator<<(std::ostream & os, const VkImportMemoryZirconHandleInfoFUCHSIA &t);
#endif //VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
std::ostream &operator<<(std::ostream & os, const VkMemoryZirconHandlePropertiesFUCHSIA &t);
#endif //VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
std::ostream &operator<<(std::ostream & os, const VkMemoryGetZirconHandleInfoFUCHSIA &t);
#endif //VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
std::ostream &operator<<(std::ostream & os, const VkImportSemaphoreZirconHandleInfoFUCHSIA &t);
#endif //VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
std::ostream &operator<<(std::ostream & os, const VkSemaphoreGetZirconHandleInfoFUCHSIA &t);
#endif //VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
std::ostream &operator<<(std::ostream & os, const VkBufferCollectionCreateInfoFUCHSIA &t);
#endif //VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
std::ostream &operator<<(std::ostream & os, const VkImportMemoryBufferCollectionFUCHSIA &t);
#endif //VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
std::ostream &operator<<(std::ostream & os, const VkBufferCollectionImageCreateInfoFUCHSIA &t);
#endif //VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
std::ostream &operator<<(std::ostream & os, const VkBufferCollectionConstraintsInfoFUCHSIA &t);
#endif //VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
std::ostream &operator<<(std::ostream & os, const VkBufferConstraintsInfoFUCHSIA &t);
#endif //VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
std::ostream &operator<<(std::ostream & os, const VkBufferCollectionBufferCreateInfoFUCHSIA &t);
#endif //VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
std::ostream &operator<<(std::ostream & os, const VkSysmemColorSpaceFUCHSIA &t);
#endif //VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
std::ostream &operator<<(std::ostream & os, const VkBufferCollectionPropertiesFUCHSIA &t);
#endif //VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
std::ostream &operator<<(std::ostream & os, const VkImageFormatConstraintsInfoFUCHSIA &t);
#endif //VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
std::ostream &operator<<(std::ostream & os, const VkImageConstraintsInfoFUCHSIA &t);
#endif //VK_USE_PLATFORM_FUCHSIA
std::ostream &operator<<(std::ostream & os, const VkSubpassShadingPipelineCreateInfoHUAWEI &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceSubpassShadingFeaturesHUAWEI &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceSubpassShadingPropertiesHUAWEI &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI &t);
std::ostream &operator<<(std::ostream & os, const VkMemoryGetRemoteAddressInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkPipelinePropertiesIdentifierEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDevicePipelinePropertiesFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceFrameBoundaryFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkFrameBoundaryEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkSubpassResolvePerformanceQueryEXT &t);
std::ostream &operator<<(std::ostream & os, const VkMultisampledRenderToSingleSampledInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT &t);
#ifdef VK_USE_PLATFORM_SCREEN_QNX
std::ostream &operator<<(std::ostream & os, const VkScreenSurfaceCreateInfoQNX &t);
#endif //VK_USE_PLATFORM_SCREEN_QNX
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceColorWriteEnableFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineColorWriteCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceImageViewMinLodFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkImageViewMinLodCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceMultiDrawFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceMultiDrawPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkMultiDrawInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkMultiDrawIndexedInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceImage2DViewOf3DFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderTileImageFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderTileImagePropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkMicromapUsageEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceOrHostAddressKHR &t);
std::ostream &operator<<(std::ostream & os, const VkMicromapBuildInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkMicromapCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceOpacityMicromapFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceOpacityMicromapPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkMicromapVersionInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkCopyMicromapToMemoryInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkCopyMemoryToMicromapInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkCopyMicromapInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkMicromapBuildSizesInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureTrianglesOpacityMicromapEXT &t);
std::ostream &operator<<(std::ostream & os, const VkMicromapTriangleEXT &t);
#ifdef VK_ENABLE_BETA_EXTENSIONS
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceDisplacementMicromapFeaturesNV &t);
#endif //VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceDisplacementMicromapPropertiesNV &t);
#endif //VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureTrianglesDisplacementMicromapNV &t);
#endif //VK_ENABLE_BETA_EXTENSIONS
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkSamplerBorderColorComponentMappingCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderCorePropertiesARM &t);
std::ostream &operator<<(std::ostream & os, const VkDeviceQueueShaderCoreControlCreateInfoARM &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceSchedulingControlsFeaturesARM &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceSchedulingControlsPropertiesARM &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkImageViewSlicedCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE &t);
std::ostream &operator<<(std::ostream & os, const VkDescriptorSetBindingReferenceVALVE &t);
std::ostream &operator<<(std::ostream & os, const VkDescriptorSetLayoutHostMappingInfoVALVE &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceDepthClampZeroOneFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceRenderPassStripedFeaturesARM &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceRenderPassStripedPropertiesARM &t);
std::ostream &operator<<(std::ostream & os, const VkRenderPassStripeInfoARM &t);
std::ostream &operator<<(std::ostream & os, const VkRenderPassStripeBeginInfoARM &t);
std::ostream &operator<<(std::ostream & os, const VkRenderPassStripeSubmitInfoARM &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM &t);
std::ostream &operator<<(std::ostream & os, const VkSubpassFragmentDensityMapOffsetEndInfoQCOM &t);
std::ostream &operator<<(std::ostream & os, const VkCopyMemoryIndirectCommandNV &t);
std::ostream &operator<<(std::ostream & os, const VkCopyMemoryToImageIndirectCommandNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceCopyMemoryIndirectFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceCopyMemoryIndirectPropertiesNV &t);
std::ostream &operator<<(std::ostream & os, const VkDecompressMemoryRegionNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceMemoryDecompressionFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceMemoryDecompressionPropertiesNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkComputePipelineIndirectBufferInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineIndirectDeviceAddressInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkBindPipelineIndirectCommandNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceLinearColorAttachmentFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkImageViewSampleWeightCreateInfoQCOM &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceImageProcessingFeaturesQCOM &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceImageProcessingPropertiesQCOM &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceNestedCommandBufferFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceNestedCommandBufferPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkExternalMemoryAcquireUnmodifiedEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceExtendedDynamicState3PropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkColorBlendEquationEXT &t);
std::ostream &operator<<(std::ostream & os, const VkColorBlendAdvancedEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkRenderPassCreationControlEXT &t);
std::ostream &operator<<(std::ostream & os, const VkRenderPassCreationFeedbackInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkRenderPassCreationFeedbackCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkRenderPassSubpassFeedbackInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkRenderPassSubpassFeedbackCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDirectDriverLoadingInfoLUNARG &t);
std::ostream &operator<<(std::ostream & os, const VkDirectDriverLoadingListLUNARG &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPipelineShaderStageModuleIdentifierCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkShaderModuleIdentifierEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceOpticalFlowFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceOpticalFlowPropertiesNV &t);
std::ostream &operator<<(std::ostream & os, const VkOpticalFlowImageFormatInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkOpticalFlowImageFormatPropertiesNV &t);
std::ostream &operator<<(std::ostream & os, const VkOpticalFlowSessionCreateInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkOpticalFlowSessionCreatePrivateDataInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkOpticalFlowExecuteInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceLegacyDitheringFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDevicePipelineProtectedAccessFeaturesEXT &t);
#ifdef VK_USE_PLATFORM_ANDROID_KHR
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceExternalFormatResolveFeaturesANDROID &t);
#endif //VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceExternalFormatResolvePropertiesANDROID &t);
#endif //VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
std::ostream &operator<<(std::ostream & os, const VkAndroidHardwareBufferFormatResolvePropertiesANDROID &t);
#endif //VK_USE_PLATFORM_ANDROID_KHR
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderObjectFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderObjectPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkShaderCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceTilePropertiesFeaturesQCOM &t);
std::ostream &operator<<(std::ostream & os, const VkTilePropertiesQCOM &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceAmigoProfilingFeaturesSEC &t);
std::ostream &operator<<(std::ostream & os, const VkAmigoProfilingSubmitInfoSEC &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV &t);
std::ostream &operator<<(std::ostream & os, const VkLayerSettingEXT &t);
std::ostream &operator<<(std::ostream & os, const VkLayerSettingsCreateInfoEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkLatencySleepModeInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkLatencySleepInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkSetLatencyMarkerInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkLatencyTimingsFrameReportNV &t);
std::ostream &operator<<(std::ostream & os, const VkGetLatencyMarkerInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkLatencySubmissionPresentIdNV &t);
std::ostream &operator<<(std::ostream & os, const VkSwapchainLatencyCreateInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkOutOfBandQueueTypeInfoNV &t);
std::ostream &operator<<(std::ostream & os, const VkLatencySurfaceCapabilitiesNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM &t);
std::ostream &operator<<(std::ostream & os, const VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDevicePerStageDescriptorSetFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceImageProcessing2FeaturesQCOM &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceImageProcessing2PropertiesQCOM &t);
std::ostream &operator<<(std::ostream & os, const VkSamplerBlockMatchWindowCreateInfoQCOM &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceCubicWeightsFeaturesQCOM &t);
std::ostream &operator<<(std::ostream & os, const VkSamplerCubicWeightsCreateInfoQCOM &t);
std::ostream &operator<<(std::ostream & os, const VkBlitImageCubicWeightsInfoQCOM &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceYcbcrDegammaFeaturesQCOM &t);
std::ostream &operator<<(std::ostream & os, const VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceCubicClampFeaturesQCOM &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT &t);
#ifdef VK_USE_PLATFORM_SCREEN_QNX
std::ostream &operator<<(std::ostream & os, const VkScreenBufferPropertiesQNX &t);
#endif //VK_USE_PLATFORM_SCREEN_QNX
#ifdef VK_USE_PLATFORM_SCREEN_QNX
std::ostream &operator<<(std::ostream & os, const VkScreenBufferFormatPropertiesQNX &t);
#endif //VK_USE_PLATFORM_SCREEN_QNX
#ifdef VK_USE_PLATFORM_SCREEN_QNX
std::ostream &operator<<(std::ostream & os, const VkImportScreenBufferInfoQNX &t);
#endif //VK_USE_PLATFORM_SCREEN_QNX
#ifdef VK_USE_PLATFORM_SCREEN_QNX
std::ostream &operator<<(std::ostream & os, const VkExternalFormatQNX &t);
#endif //VK_USE_PLATFORM_SCREEN_QNX
#ifdef VK_USE_PLATFORM_SCREEN_QNX
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX &t);
#endif //VK_USE_PLATFORM_SCREEN_QNX
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceLayeredDriverPropertiesMSFT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureBuildRangeInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureGeometryTrianglesDataKHR &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureGeometryAabbsDataKHR &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureGeometryInstancesDataKHR &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureGeometryDataKHR &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureGeometryKHR &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureBuildGeometryInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureCreateInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkWriteDescriptorSetAccelerationStructureKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceAccelerationStructureFeaturesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceAccelerationStructurePropertiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureDeviceAddressInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureVersionInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkCopyAccelerationStructureToMemoryInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkCopyMemoryToAccelerationStructureInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkCopyAccelerationStructureInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkAccelerationStructureBuildSizesInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkRayTracingShaderGroupCreateInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkRayTracingPipelineInterfaceCreateInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkRayTracingPipelineCreateInfoKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceRayTracingPipelineFeaturesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceRayTracingPipelinePropertiesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkStridedDeviceAddressRegionKHR &t);
std::ostream &operator<<(std::ostream & os, const VkTraceRaysIndirectCommandKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceRayQueryFeaturesKHR &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceMeshShaderFeaturesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkPhysicalDeviceMeshShaderPropertiesEXT &t);
std::ostream &operator<<(std::ostream & os, const VkDrawMeshTasksIndirectCommandEXT &t);


// Declare print functions.

class CommandPrinter {
 public:
  void SetNameResolver(const ObjectInfoDB *name_resolver);

  void PrintBeginCommandBufferArgs(std::ostream & os, const BeginCommandBufferArgs &args);
  void PrintEndCommandBufferArgs(std::ostream & os, const EndCommandBufferArgs &args);
  void PrintResetCommandBufferArgs(std::ostream & os, const ResetCommandBufferArgs &args);
  void PrintCmdBindPipelineArgs(std::ostream & os, const CmdBindPipelineArgs &args);
  void PrintCmdSetViewportArgs(std::ostream & os, const CmdSetViewportArgs &args);
  void PrintCmdSetScissorArgs(std::ostream & os, const CmdSetScissorArgs &args);
  void PrintCmdSetLineWidthArgs(std::ostream & os, const CmdSetLineWidthArgs &args);
  void PrintCmdSetDepthBiasArgs(std::ostream & os, const CmdSetDepthBiasArgs &args);
  void PrintCmdSetBlendConstantsArgs(std::ostream & os, const CmdSetBlendConstantsArgs &args);
  void PrintCmdSetDepthBoundsArgs(std::ostream & os, const CmdSetDepthBoundsArgs &args);
  void PrintCmdSetStencilCompareMaskArgs(std::ostream & os, const CmdSetStencilCompareMaskArgs &args);
  void PrintCmdSetStencilWriteMaskArgs(std::ostream & os, const CmdSetStencilWriteMaskArgs &args);
  void PrintCmdSetStencilReferenceArgs(std::ostream & os, const CmdSetStencilReferenceArgs &args);
  void PrintCmdBindDescriptorSetsArgs(std::ostream & os, const CmdBindDescriptorSetsArgs &args);
  void PrintCmdBindIndexBufferArgs(std::ostream & os, const CmdBindIndexBufferArgs &args);
  void PrintCmdBindVertexBuffersArgs(std::ostream & os, const CmdBindVertexBuffersArgs &args);
  void PrintCmdDrawArgs(std::ostream & os, const CmdDrawArgs &args);
  void PrintCmdDrawIndexedArgs(std::ostream & os, const CmdDrawIndexedArgs &args);
  void PrintCmdDrawIndirectArgs(std::ostream & os, const CmdDrawIndirectArgs &args);
  void PrintCmdDrawIndexedIndirectArgs(std::ostream & os, const CmdDrawIndexedIndirectArgs &args);
  void PrintCmdDispatchArgs(std::ostream & os, const CmdDispatchArgs &args);
  void PrintCmdDispatchIndirectArgs(std::ostream & os, const CmdDispatchIndirectArgs &args);
  void PrintCmdCopyBufferArgs(std::ostream & os, const CmdCopyBufferArgs &args);
  void PrintCmdCopyImageArgs(std::ostream & os, const CmdCopyImageArgs &args);
  void PrintCmdBlitImageArgs(std::ostream & os, const CmdBlitImageArgs &args);
  void PrintCmdCopyBufferToImageArgs(std::ostream & os, const CmdCopyBufferToImageArgs &args);
  void PrintCmdCopyImageToBufferArgs(std::ostream & os, const CmdCopyImageToBufferArgs &args);
  void PrintCmdUpdateBufferArgs(std::ostream & os, const CmdUpdateBufferArgs &args);
  void PrintCmdFillBufferArgs(std::ostream & os, const CmdFillBufferArgs &args);
  void PrintCmdClearColorImageArgs(std::ostream & os, const CmdClearColorImageArgs &args);
  void PrintCmdClearDepthStencilImageArgs(std::ostream & os, const CmdClearDepthStencilImageArgs &args);
  void PrintCmdClearAttachmentsArgs(std::ostream & os, const CmdClearAttachmentsArgs &args);
  void PrintCmdResolveImageArgs(std::ostream & os, const CmdResolveImageArgs &args);
  void PrintCmdSetEventArgs(std::ostream & os, const CmdSetEventArgs &args);
  void PrintCmdResetEventArgs(std::ostream & os, const CmdResetEventArgs &args);
  void PrintCmdWaitEventsArgs(std::ostream & os, const CmdWaitEventsArgs &args);
  void PrintCmdPipelineBarrierArgs(std::ostream & os, const CmdPipelineBarrierArgs &args);
  void PrintCmdBeginQueryArgs(std::ostream & os, const CmdBeginQueryArgs &args);
  void PrintCmdEndQueryArgs(std::ostream & os, const CmdEndQueryArgs &args);
  void PrintCmdResetQueryPoolArgs(std::ostream & os, const CmdResetQueryPoolArgs &args);
  void PrintCmdWriteTimestampArgs(std::ostream & os, const CmdWriteTimestampArgs &args);
  void PrintCmdCopyQueryPoolResultsArgs(std::ostream & os, const CmdCopyQueryPoolResultsArgs &args);
  void PrintCmdPushConstantsArgs(std::ostream & os, const CmdPushConstantsArgs &args);
  void PrintCmdBeginRenderPassArgs(std::ostream & os, const CmdBeginRenderPassArgs &args);
  void PrintCmdNextSubpassArgs(std::ostream & os, const CmdNextSubpassArgs &args);
  void PrintCmdEndRenderPassArgs(std::ostream & os, const CmdEndRenderPassArgs &args);
  void PrintCmdExecuteCommandsArgs(std::ostream & os, const CmdExecuteCommandsArgs &args);
  void PrintCmdSetDeviceMaskArgs(std::ostream & os, const CmdSetDeviceMaskArgs &args);
  void PrintCmdDispatchBaseArgs(std::ostream & os, const CmdDispatchBaseArgs &args);
  void PrintCmdDrawIndirectCountArgs(std::ostream & os, const CmdDrawIndirectCountArgs &args);
  void PrintCmdDrawIndexedIndirectCountArgs(std::ostream & os, const CmdDrawIndexedIndirectCountArgs &args);
  void PrintCmdBeginRenderPass2Args(std::ostream & os, const CmdBeginRenderPass2Args &args);
  void PrintCmdNextSubpass2Args(std::ostream & os, const CmdNextSubpass2Args &args);
  void PrintCmdEndRenderPass2Args(std::ostream & os, const CmdEndRenderPass2Args &args);
  void PrintCmdSetEvent2Args(std::ostream & os, const CmdSetEvent2Args &args);
  void PrintCmdResetEvent2Args(std::ostream & os, const CmdResetEvent2Args &args);
  void PrintCmdWaitEvents2Args(std::ostream & os, const CmdWaitEvents2Args &args);
  void PrintCmdPipelineBarrier2Args(std::ostream & os, const CmdPipelineBarrier2Args &args);
  void PrintCmdWriteTimestamp2Args(std::ostream & os, const CmdWriteTimestamp2Args &args);
  void PrintCmdCopyBuffer2Args(std::ostream & os, const CmdCopyBuffer2Args &args);
  void PrintCmdCopyImage2Args(std::ostream & os, const CmdCopyImage2Args &args);
  void PrintCmdCopyBufferToImage2Args(std::ostream & os, const CmdCopyBufferToImage2Args &args);
  void PrintCmdCopyImageToBuffer2Args(std::ostream & os, const CmdCopyImageToBuffer2Args &args);
  void PrintCmdBlitImage2Args(std::ostream & os, const CmdBlitImage2Args &args);
  void PrintCmdResolveImage2Args(std::ostream & os, const CmdResolveImage2Args &args);
  void PrintCmdBeginRenderingArgs(std::ostream & os, const CmdBeginRenderingArgs &args);
  void PrintCmdEndRenderingArgs(std::ostream & os, const CmdEndRenderingArgs &args);
  void PrintCmdSetCullModeArgs(std::ostream & os, const CmdSetCullModeArgs &args);
  void PrintCmdSetFrontFaceArgs(std::ostream & os, const CmdSetFrontFaceArgs &args);
  void PrintCmdSetPrimitiveTopologyArgs(std::ostream & os, const CmdSetPrimitiveTopologyArgs &args);
  void PrintCmdSetViewportWithCountArgs(std::ostream & os, const CmdSetViewportWithCountArgs &args);
  void PrintCmdSetScissorWithCountArgs(std::ostream & os, const CmdSetScissorWithCountArgs &args);
  void PrintCmdBindVertexBuffers2Args(std::ostream & os, const CmdBindVertexBuffers2Args &args);
  void PrintCmdSetDepthTestEnableArgs(std::ostream & os, const CmdSetDepthTestEnableArgs &args);
  void PrintCmdSetDepthWriteEnableArgs(std::ostream & os, const CmdSetDepthWriteEnableArgs &args);
  void PrintCmdSetDepthCompareOpArgs(std::ostream & os, const CmdSetDepthCompareOpArgs &args);
  void PrintCmdSetDepthBoundsTestEnableArgs(std::ostream & os, const CmdSetDepthBoundsTestEnableArgs &args);
  void PrintCmdSetStencilTestEnableArgs(std::ostream & os, const CmdSetStencilTestEnableArgs &args);
  void PrintCmdSetStencilOpArgs(std::ostream & os, const CmdSetStencilOpArgs &args);
  void PrintCmdSetRasterizerDiscardEnableArgs(std::ostream & os, const CmdSetRasterizerDiscardEnableArgs &args);
  void PrintCmdSetDepthBiasEnableArgs(std::ostream & os, const CmdSetDepthBiasEnableArgs &args);
  void PrintCmdSetPrimitiveRestartEnableArgs(std::ostream & os, const CmdSetPrimitiveRestartEnableArgs &args);
  void PrintCmdBeginVideoCodingKHRArgs(std::ostream & os, const CmdBeginVideoCodingKHRArgs &args);
  void PrintCmdEndVideoCodingKHRArgs(std::ostream & os, const CmdEndVideoCodingKHRArgs &args);
  void PrintCmdControlVideoCodingKHRArgs(std::ostream & os, const CmdControlVideoCodingKHRArgs &args);
  void PrintCmdDecodeVideoKHRArgs(std::ostream & os, const CmdDecodeVideoKHRArgs &args);
  void PrintCmdBeginRenderingKHRArgs(std::ostream & os, const CmdBeginRenderingKHRArgs &args);
  void PrintCmdEndRenderingKHRArgs(std::ostream & os, const CmdEndRenderingKHRArgs &args);
  void PrintCmdSetDeviceMaskKHRArgs(std::ostream & os, const CmdSetDeviceMaskKHRArgs &args);
  void PrintCmdDispatchBaseKHRArgs(std::ostream & os, const CmdDispatchBaseKHRArgs &args);
  void PrintCmdPushDescriptorSetKHRArgs(std::ostream & os, const CmdPushDescriptorSetKHRArgs &args);
  void PrintCmdPushDescriptorSetWithTemplateKHRArgs(std::ostream & os, const CmdPushDescriptorSetWithTemplateKHRArgs &args);
  void PrintCmdBeginRenderPass2KHRArgs(std::ostream & os, const CmdBeginRenderPass2KHRArgs &args);
  void PrintCmdNextSubpass2KHRArgs(std::ostream & os, const CmdNextSubpass2KHRArgs &args);
  void PrintCmdEndRenderPass2KHRArgs(std::ostream & os, const CmdEndRenderPass2KHRArgs &args);
  void PrintCmdDrawIndirectCountKHRArgs(std::ostream & os, const CmdDrawIndirectCountKHRArgs &args);
  void PrintCmdDrawIndexedIndirectCountKHRArgs(std::ostream & os, const CmdDrawIndexedIndirectCountKHRArgs &args);
  void PrintCmdSetFragmentShadingRateKHRArgs(std::ostream & os, const CmdSetFragmentShadingRateKHRArgs &args);
  void PrintCmdEncodeVideoKHRArgs(std::ostream & os, const CmdEncodeVideoKHRArgs &args);
  void PrintCmdSetEvent2KHRArgs(std::ostream & os, const CmdSetEvent2KHRArgs &args);
  void PrintCmdResetEvent2KHRArgs(std::ostream & os, const CmdResetEvent2KHRArgs &args);
  void PrintCmdWaitEvents2KHRArgs(std::ostream & os, const CmdWaitEvents2KHRArgs &args);
  void PrintCmdPipelineBarrier2KHRArgs(std::ostream & os, const CmdPipelineBarrier2KHRArgs &args);
  void PrintCmdWriteTimestamp2KHRArgs(std::ostream & os, const CmdWriteTimestamp2KHRArgs &args);
  void PrintCmdWriteBufferMarker2AMDArgs(std::ostream & os, const CmdWriteBufferMarker2AMDArgs &args);
  void PrintCmdCopyBuffer2KHRArgs(std::ostream & os, const CmdCopyBuffer2KHRArgs &args);
  void PrintCmdCopyImage2KHRArgs(std::ostream & os, const CmdCopyImage2KHRArgs &args);
  void PrintCmdCopyBufferToImage2KHRArgs(std::ostream & os, const CmdCopyBufferToImage2KHRArgs &args);
  void PrintCmdCopyImageToBuffer2KHRArgs(std::ostream & os, const CmdCopyImageToBuffer2KHRArgs &args);
  void PrintCmdBlitImage2KHRArgs(std::ostream & os, const CmdBlitImage2KHRArgs &args);
  void PrintCmdResolveImage2KHRArgs(std::ostream & os, const CmdResolveImage2KHRArgs &args);
  void PrintCmdTraceRaysIndirect2KHRArgs(std::ostream & os, const CmdTraceRaysIndirect2KHRArgs &args);
  void PrintCmdBindIndexBuffer2KHRArgs(std::ostream & os, const CmdBindIndexBuffer2KHRArgs &args);
  void PrintCmdBindDescriptorSets2KHRArgs(std::ostream & os, const CmdBindDescriptorSets2KHRArgs &args);
  void PrintCmdPushConstants2KHRArgs(std::ostream & os, const CmdPushConstants2KHRArgs &args);
  void PrintCmdPushDescriptorSet2KHRArgs(std::ostream & os, const CmdPushDescriptorSet2KHRArgs &args);
  void PrintCmdPushDescriptorSetWithTemplate2KHRArgs(std::ostream & os, const CmdPushDescriptorSetWithTemplate2KHRArgs &args);
  void PrintCmdSetDescriptorBufferOffsets2EXTArgs(std::ostream & os, const CmdSetDescriptorBufferOffsets2EXTArgs &args);
  void PrintCmdBindDescriptorBufferEmbeddedSamplers2EXTArgs(std::ostream & os, const CmdBindDescriptorBufferEmbeddedSamplers2EXTArgs &args);
  void PrintCmdDebugMarkerBeginEXTArgs(std::ostream & os, const CmdDebugMarkerBeginEXTArgs &args);
  void PrintCmdDebugMarkerEndEXTArgs(std::ostream & os, const CmdDebugMarkerEndEXTArgs &args);
  void PrintCmdDebugMarkerInsertEXTArgs(std::ostream & os, const CmdDebugMarkerInsertEXTArgs &args);
  void PrintCmdBindTransformFeedbackBuffersEXTArgs(std::ostream & os, const CmdBindTransformFeedbackBuffersEXTArgs &args);
  void PrintCmdBeginTransformFeedbackEXTArgs(std::ostream & os, const CmdBeginTransformFeedbackEXTArgs &args);
  void PrintCmdEndTransformFeedbackEXTArgs(std::ostream & os, const CmdEndTransformFeedbackEXTArgs &args);
  void PrintCmdBeginQueryIndexedEXTArgs(std::ostream & os, const CmdBeginQueryIndexedEXTArgs &args);
  void PrintCmdEndQueryIndexedEXTArgs(std::ostream & os, const CmdEndQueryIndexedEXTArgs &args);
  void PrintCmdDrawIndirectByteCountEXTArgs(std::ostream & os, const CmdDrawIndirectByteCountEXTArgs &args);
  void PrintCmdCuLaunchKernelNVXArgs(std::ostream & os, const CmdCuLaunchKernelNVXArgs &args);
  void PrintCmdDrawIndirectCountAMDArgs(std::ostream & os, const CmdDrawIndirectCountAMDArgs &args);
  void PrintCmdDrawIndexedIndirectCountAMDArgs(std::ostream & os, const CmdDrawIndexedIndirectCountAMDArgs &args);
  void PrintCmdBeginConditionalRenderingEXTArgs(std::ostream & os, const CmdBeginConditionalRenderingEXTArgs &args);
  void PrintCmdEndConditionalRenderingEXTArgs(std::ostream & os, const CmdEndConditionalRenderingEXTArgs &args);
  void PrintCmdSetViewportWScalingNVArgs(std::ostream & os, const CmdSetViewportWScalingNVArgs &args);
  void PrintCmdSetDiscardRectangleEXTArgs(std::ostream & os, const CmdSetDiscardRectangleEXTArgs &args);
  void PrintCmdSetDiscardRectangleEnableEXTArgs(std::ostream & os, const CmdSetDiscardRectangleEnableEXTArgs &args);
  void PrintCmdSetDiscardRectangleModeEXTArgs(std::ostream & os, const CmdSetDiscardRectangleModeEXTArgs &args);
  void PrintCmdBeginDebugUtilsLabelEXTArgs(std::ostream & os, const CmdBeginDebugUtilsLabelEXTArgs &args);
  void PrintCmdEndDebugUtilsLabelEXTArgs(std::ostream & os, const CmdEndDebugUtilsLabelEXTArgs &args);
  void PrintCmdInsertDebugUtilsLabelEXTArgs(std::ostream & os, const CmdInsertDebugUtilsLabelEXTArgs &args);
#ifdef VK_ENABLE_BETA_EXTENSIONS
  void PrintCmdInitializeGraphScratchMemoryAMDXArgs(std::ostream & os, const CmdInitializeGraphScratchMemoryAMDXArgs &args);
#endif //VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
  void PrintCmdDispatchGraphAMDXArgs(std::ostream & os, const CmdDispatchGraphAMDXArgs &args);
#endif //VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
  void PrintCmdDispatchGraphIndirectAMDXArgs(std::ostream & os, const CmdDispatchGraphIndirectAMDXArgs &args);
#endif //VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
  void PrintCmdDispatchGraphIndirectCountAMDXArgs(std::ostream & os, const CmdDispatchGraphIndirectCountAMDXArgs &args);
#endif //VK_ENABLE_BETA_EXTENSIONS
  void PrintCmdSetSampleLocationsEXTArgs(std::ostream & os, const CmdSetSampleLocationsEXTArgs &args);
  void PrintCmdBindShadingRateImageNVArgs(std::ostream & os, const CmdBindShadingRateImageNVArgs &args);
  void PrintCmdSetViewportShadingRatePaletteNVArgs(std::ostream & os, const CmdSetViewportShadingRatePaletteNVArgs &args);
  void PrintCmdSetCoarseSampleOrderNVArgs(std::ostream & os, const CmdSetCoarseSampleOrderNVArgs &args);
  void PrintCmdBuildAccelerationStructureNVArgs(std::ostream & os, const CmdBuildAccelerationStructureNVArgs &args);
  void PrintCmdCopyAccelerationStructureNVArgs(std::ostream & os, const CmdCopyAccelerationStructureNVArgs &args);
  void PrintCmdTraceRaysNVArgs(std::ostream & os, const CmdTraceRaysNVArgs &args);
  void PrintCmdWriteAccelerationStructuresPropertiesNVArgs(std::ostream & os, const CmdWriteAccelerationStructuresPropertiesNVArgs &args);
  void PrintCmdWriteBufferMarkerAMDArgs(std::ostream & os, const CmdWriteBufferMarkerAMDArgs &args);
  void PrintCmdDrawMeshTasksNVArgs(std::ostream & os, const CmdDrawMeshTasksNVArgs &args);
  void PrintCmdDrawMeshTasksIndirectNVArgs(std::ostream & os, const CmdDrawMeshTasksIndirectNVArgs &args);
  void PrintCmdDrawMeshTasksIndirectCountNVArgs(std::ostream & os, const CmdDrawMeshTasksIndirectCountNVArgs &args);
  void PrintCmdSetExclusiveScissorEnableNVArgs(std::ostream & os, const CmdSetExclusiveScissorEnableNVArgs &args);
  void PrintCmdSetExclusiveScissorNVArgs(std::ostream & os, const CmdSetExclusiveScissorNVArgs &args);
  void PrintCmdSetCheckpointNVArgs(std::ostream & os, const CmdSetCheckpointNVArgs &args);
  void PrintCmdSetPerformanceMarkerINTELArgs(std::ostream & os, const CmdSetPerformanceMarkerINTELArgs &args);
  void PrintCmdSetPerformanceStreamMarkerINTELArgs(std::ostream & os, const CmdSetPerformanceStreamMarkerINTELArgs &args);
  void PrintCmdSetPerformanceOverrideINTELArgs(std::ostream & os, const CmdSetPerformanceOverrideINTELArgs &args);
  void PrintCmdSetLineStippleEXTArgs(std::ostream & os, const CmdSetLineStippleEXTArgs &args);
  void PrintCmdSetCullModeEXTArgs(std::ostream & os, const CmdSetCullModeEXTArgs &args);
  void PrintCmdSetFrontFaceEXTArgs(std::ostream & os, const CmdSetFrontFaceEXTArgs &args);
  void PrintCmdSetPrimitiveTopologyEXTArgs(std::ostream & os, const CmdSetPrimitiveTopologyEXTArgs &args);
  void PrintCmdSetViewportWithCountEXTArgs(std::ostream & os, const CmdSetViewportWithCountEXTArgs &args);
  void PrintCmdSetScissorWithCountEXTArgs(std::ostream & os, const CmdSetScissorWithCountEXTArgs &args);
  void PrintCmdBindVertexBuffers2EXTArgs(std::ostream & os, const CmdBindVertexBuffers2EXTArgs &args);
  void PrintCmdSetDepthTestEnableEXTArgs(std::ostream & os, const CmdSetDepthTestEnableEXTArgs &args);
  void PrintCmdSetDepthWriteEnableEXTArgs(std::ostream & os, const CmdSetDepthWriteEnableEXTArgs &args);
  void PrintCmdSetDepthCompareOpEXTArgs(std::ostream & os, const CmdSetDepthCompareOpEXTArgs &args);
  void PrintCmdSetDepthBoundsTestEnableEXTArgs(std::ostream & os, const CmdSetDepthBoundsTestEnableEXTArgs &args);
  void PrintCmdSetStencilTestEnableEXTArgs(std::ostream & os, const CmdSetStencilTestEnableEXTArgs &args);
  void PrintCmdSetStencilOpEXTArgs(std::ostream & os, const CmdSetStencilOpEXTArgs &args);
  void PrintCmdPreprocessGeneratedCommandsNVArgs(std::ostream & os, const CmdPreprocessGeneratedCommandsNVArgs &args);
  void PrintCmdExecuteGeneratedCommandsNVArgs(std::ostream & os, const CmdExecuteGeneratedCommandsNVArgs &args);
  void PrintCmdBindPipelineShaderGroupNVArgs(std::ostream & os, const CmdBindPipelineShaderGroupNVArgs &args);
  void PrintCmdSetDepthBias2EXTArgs(std::ostream & os, const CmdSetDepthBias2EXTArgs &args);
  void PrintCmdCudaLaunchKernelNVArgs(std::ostream & os, const CmdCudaLaunchKernelNVArgs &args);
  void PrintCmdBindDescriptorBuffersEXTArgs(std::ostream & os, const CmdBindDescriptorBuffersEXTArgs &args);
  void PrintCmdSetDescriptorBufferOffsetsEXTArgs(std::ostream & os, const CmdSetDescriptorBufferOffsetsEXTArgs &args);
  void PrintCmdBindDescriptorBufferEmbeddedSamplersEXTArgs(std::ostream & os, const CmdBindDescriptorBufferEmbeddedSamplersEXTArgs &args);
  void PrintCmdSetFragmentShadingRateEnumNVArgs(std::ostream & os, const CmdSetFragmentShadingRateEnumNVArgs &args);
  void PrintCmdSetVertexInputEXTArgs(std::ostream & os, const CmdSetVertexInputEXTArgs &args);
  void PrintCmdSubpassShadingHUAWEIArgs(std::ostream & os, const CmdSubpassShadingHUAWEIArgs &args);
  void PrintCmdBindInvocationMaskHUAWEIArgs(std::ostream & os, const CmdBindInvocationMaskHUAWEIArgs &args);
  void PrintCmdSetPatchControlPointsEXTArgs(std::ostream & os, const CmdSetPatchControlPointsEXTArgs &args);
  void PrintCmdSetRasterizerDiscardEnableEXTArgs(std::ostream & os, const CmdSetRasterizerDiscardEnableEXTArgs &args);
  void PrintCmdSetDepthBiasEnableEXTArgs(std::ostream & os, const CmdSetDepthBiasEnableEXTArgs &args);
  void PrintCmdSetLogicOpEXTArgs(std::ostream & os, const CmdSetLogicOpEXTArgs &args);
  void PrintCmdSetPrimitiveRestartEnableEXTArgs(std::ostream & os, const CmdSetPrimitiveRestartEnableEXTArgs &args);
  void PrintCmdSetColorWriteEnableEXTArgs(std::ostream & os, const CmdSetColorWriteEnableEXTArgs &args);
  void PrintCmdDrawMultiEXTArgs(std::ostream & os, const CmdDrawMultiEXTArgs &args);
  void PrintCmdDrawMultiIndexedEXTArgs(std::ostream & os, const CmdDrawMultiIndexedEXTArgs &args);
  void PrintCmdBuildMicromapsEXTArgs(std::ostream & os, const CmdBuildMicromapsEXTArgs &args);
  void PrintCmdCopyMicromapEXTArgs(std::ostream & os, const CmdCopyMicromapEXTArgs &args);
  void PrintCmdCopyMicromapToMemoryEXTArgs(std::ostream & os, const CmdCopyMicromapToMemoryEXTArgs &args);
  void PrintCmdCopyMemoryToMicromapEXTArgs(std::ostream & os, const CmdCopyMemoryToMicromapEXTArgs &args);
  void PrintCmdWriteMicromapsPropertiesEXTArgs(std::ostream & os, const CmdWriteMicromapsPropertiesEXTArgs &args);
  void PrintCmdDrawClusterHUAWEIArgs(std::ostream & os, const CmdDrawClusterHUAWEIArgs &args);
  void PrintCmdDrawClusterIndirectHUAWEIArgs(std::ostream & os, const CmdDrawClusterIndirectHUAWEIArgs &args);
  void PrintCmdCopyMemoryIndirectNVArgs(std::ostream & os, const CmdCopyMemoryIndirectNVArgs &args);
  void PrintCmdCopyMemoryToImageIndirectNVArgs(std::ostream & os, const CmdCopyMemoryToImageIndirectNVArgs &args);
  void PrintCmdDecompressMemoryNVArgs(std::ostream & os, const CmdDecompressMemoryNVArgs &args);
  void PrintCmdDecompressMemoryIndirectCountNVArgs(std::ostream & os, const CmdDecompressMemoryIndirectCountNVArgs &args);
  void PrintCmdUpdatePipelineIndirectBufferNVArgs(std::ostream & os, const CmdUpdatePipelineIndirectBufferNVArgs &args);
  void PrintCmdSetTessellationDomainOriginEXTArgs(std::ostream & os, const CmdSetTessellationDomainOriginEXTArgs &args);
  void PrintCmdSetDepthClampEnableEXTArgs(std::ostream & os, const CmdSetDepthClampEnableEXTArgs &args);
  void PrintCmdSetPolygonModeEXTArgs(std::ostream & os, const CmdSetPolygonModeEXTArgs &args);
  void PrintCmdSetRasterizationSamplesEXTArgs(std::ostream & os, const CmdSetRasterizationSamplesEXTArgs &args);
  void PrintCmdSetSampleMaskEXTArgs(std::ostream & os, const CmdSetSampleMaskEXTArgs &args);
  void PrintCmdSetAlphaToCoverageEnableEXTArgs(std::ostream & os, const CmdSetAlphaToCoverageEnableEXTArgs &args);
  void PrintCmdSetAlphaToOneEnableEXTArgs(std::ostream & os, const CmdSetAlphaToOneEnableEXTArgs &args);
  void PrintCmdSetLogicOpEnableEXTArgs(std::ostream & os, const CmdSetLogicOpEnableEXTArgs &args);
  void PrintCmdSetColorBlendEnableEXTArgs(std::ostream & os, const CmdSetColorBlendEnableEXTArgs &args);
  void PrintCmdSetColorBlendEquationEXTArgs(std::ostream & os, const CmdSetColorBlendEquationEXTArgs &args);
  void PrintCmdSetColorWriteMaskEXTArgs(std::ostream & os, const CmdSetColorWriteMaskEXTArgs &args);
  void PrintCmdSetRasterizationStreamEXTArgs(std::ostream & os, const CmdSetRasterizationStreamEXTArgs &args);
  void PrintCmdSetConservativeRasterizationModeEXTArgs(std::ostream & os, const CmdSetConservativeRasterizationModeEXTArgs &args);
  void PrintCmdSetExtraPrimitiveOverestimationSizeEXTArgs(std::ostream & os, const CmdSetExtraPrimitiveOverestimationSizeEXTArgs &args);
  void PrintCmdSetDepthClipEnableEXTArgs(std::ostream & os, const CmdSetDepthClipEnableEXTArgs &args);
  void PrintCmdSetSampleLocationsEnableEXTArgs(std::ostream & os, const CmdSetSampleLocationsEnableEXTArgs &args);
  void PrintCmdSetColorBlendAdvancedEXTArgs(std::ostream & os, const CmdSetColorBlendAdvancedEXTArgs &args);
  void PrintCmdSetProvokingVertexModeEXTArgs(std::ostream & os, const CmdSetProvokingVertexModeEXTArgs &args);
  void PrintCmdSetLineRasterizationModeEXTArgs(std::ostream & os, const CmdSetLineRasterizationModeEXTArgs &args);
  void PrintCmdSetLineStippleEnableEXTArgs(std::ostream & os, const CmdSetLineStippleEnableEXTArgs &args);
  void PrintCmdSetDepthClipNegativeOneToOneEXTArgs(std::ostream & os, const CmdSetDepthClipNegativeOneToOneEXTArgs &args);
  void PrintCmdSetViewportWScalingEnableNVArgs(std::ostream & os, const CmdSetViewportWScalingEnableNVArgs &args);
  void PrintCmdSetViewportSwizzleNVArgs(std::ostream & os, const CmdSetViewportSwizzleNVArgs &args);
  void PrintCmdSetCoverageToColorEnableNVArgs(std::ostream & os, const CmdSetCoverageToColorEnableNVArgs &args);
  void PrintCmdSetCoverageToColorLocationNVArgs(std::ostream & os, const CmdSetCoverageToColorLocationNVArgs &args);
  void PrintCmdSetCoverageModulationModeNVArgs(std::ostream & os, const CmdSetCoverageModulationModeNVArgs &args);
  void PrintCmdSetCoverageModulationTableEnableNVArgs(std::ostream & os, const CmdSetCoverageModulationTableEnableNVArgs &args);
  void PrintCmdSetCoverageModulationTableNVArgs(std::ostream & os, const CmdSetCoverageModulationTableNVArgs &args);
  void PrintCmdSetShadingRateImageEnableNVArgs(std::ostream & os, const CmdSetShadingRateImageEnableNVArgs &args);
  void PrintCmdSetRepresentativeFragmentTestEnableNVArgs(std::ostream & os, const CmdSetRepresentativeFragmentTestEnableNVArgs &args);
  void PrintCmdSetCoverageReductionModeNVArgs(std::ostream & os, const CmdSetCoverageReductionModeNVArgs &args);
  void PrintCmdOpticalFlowExecuteNVArgs(std::ostream & os, const CmdOpticalFlowExecuteNVArgs &args);
  void PrintCmdBindShadersEXTArgs(std::ostream & os, const CmdBindShadersEXTArgs &args);
  void PrintCmdSetAttachmentFeedbackLoopEnableEXTArgs(std::ostream & os, const CmdSetAttachmentFeedbackLoopEnableEXTArgs &args);
  void PrintCmdBuildAccelerationStructuresKHRArgs(std::ostream & os, const CmdBuildAccelerationStructuresKHRArgs &args);
  void PrintCmdBuildAccelerationStructuresIndirectKHRArgs(std::ostream & os, const CmdBuildAccelerationStructuresIndirectKHRArgs &args);
  void PrintCmdCopyAccelerationStructureKHRArgs(std::ostream & os, const CmdCopyAccelerationStructureKHRArgs &args);
  void PrintCmdCopyAccelerationStructureToMemoryKHRArgs(std::ostream & os, const CmdCopyAccelerationStructureToMemoryKHRArgs &args);
  void PrintCmdCopyMemoryToAccelerationStructureKHRArgs(std::ostream & os, const CmdCopyMemoryToAccelerationStructureKHRArgs &args);
  void PrintCmdWriteAccelerationStructuresPropertiesKHRArgs(std::ostream & os, const CmdWriteAccelerationStructuresPropertiesKHRArgs &args);
  void PrintCmdTraceRaysKHRArgs(std::ostream & os, const CmdTraceRaysKHRArgs &args);
  void PrintCmdTraceRaysIndirectKHRArgs(std::ostream & os, const CmdTraceRaysIndirectKHRArgs &args);
  void PrintCmdSetRayTracingPipelineStackSizeKHRArgs(std::ostream & os, const CmdSetRayTracingPipelineStackSizeKHRArgs &args);
  void PrintCmdDrawMeshTasksEXTArgs(std::ostream & os, const CmdDrawMeshTasksEXTArgs &args);
  void PrintCmdDrawMeshTasksIndirectEXTArgs(std::ostream & os, const CmdDrawMeshTasksIndirectEXTArgs &args);
  void PrintCmdDrawMeshTasksIndirectCountEXTArgs(std::ostream & os, const CmdDrawMeshTasksIndirectCountEXTArgs &args);
};


// NOLINTEND

