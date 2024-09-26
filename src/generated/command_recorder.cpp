
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
 * ***   Update source file command_recorder_generator.py for modifications
 * *** ---- WARNING! ----
 *
 ****************************************************************************/

// NOLINTBEGIN

#include <iomanip>
#include <sstream>

#include "command_common.h"
#include "command_recorder.h"

// Declare CopyArray template functions. We need this declaration since the
// templates call each other and we don't have control over the order of the
// definitions.

template <>
uint8_t* CommandRecorder::CopyArray<uint8_t>(const uint8_t* src, size_t start_index, size_t count);
template <>
VkExtent2D* CommandRecorder::CopyArray<VkExtent2D>(const VkExtent2D* src, size_t start_index, size_t count);
template <>
VkExtent3D* CommandRecorder::CopyArray<VkExtent3D>(const VkExtent3D* src, size_t start_index, size_t count);
template <>
VkOffset2D* CommandRecorder::CopyArray<VkOffset2D>(const VkOffset2D* src, size_t start_index, size_t count);
template <>
VkOffset3D* CommandRecorder::CopyArray<VkOffset3D>(const VkOffset3D* src, size_t start_index, size_t count);
template <>
VkRect2D* CommandRecorder::CopyArray<VkRect2D>(const VkRect2D* src, size_t start_index, size_t count);
template <>
VkBufferMemoryBarrier* CommandRecorder::CopyArray<VkBufferMemoryBarrier>(const VkBufferMemoryBarrier* src,
                                                                         size_t start_index, size_t count);
template <>
VkImageSubresourceRange* CommandRecorder::CopyArray<VkImageSubresourceRange>(const VkImageSubresourceRange* src,
                                                                             size_t start_index, size_t count);
template <>
VkImageMemoryBarrier* CommandRecorder::CopyArray<VkImageMemoryBarrier>(const VkImageMemoryBarrier* src,
                                                                       size_t start_index, size_t count);
template <>
VkMemoryBarrier* CommandRecorder::CopyArray<VkMemoryBarrier>(const VkMemoryBarrier* src, size_t start_index,
                                                             size_t count);
template <>
VkViewport* CommandRecorder::CopyArray<VkViewport>(const VkViewport* src, size_t start_index, size_t count);
template <>
VkDescriptorBufferInfo* CommandRecorder::CopyArray<VkDescriptorBufferInfo>(const VkDescriptorBufferInfo* src,
                                                                           size_t start_index, size_t count);
template <>
VkDescriptorImageInfo* CommandRecorder::CopyArray<VkDescriptorImageInfo>(const VkDescriptorImageInfo* src,
                                                                         size_t start_index, size_t count);
template <>
VkWriteDescriptorSet* CommandRecorder::CopyArray<VkWriteDescriptorSet>(const VkWriteDescriptorSet* src,
                                                                       size_t start_index, size_t count);
template <>
VkCommandBufferInheritanceInfo* CommandRecorder::CopyArray<VkCommandBufferInheritanceInfo>(
    const VkCommandBufferInheritanceInfo* src, size_t start_index, size_t count);
template <>
VkCommandBufferBeginInfo* CommandRecorder::CopyArray<VkCommandBufferBeginInfo>(const VkCommandBufferBeginInfo* src,
                                                                               size_t start_index, size_t count);
template <>
VkBufferCopy* CommandRecorder::CopyArray<VkBufferCopy>(const VkBufferCopy* src, size_t start_index, size_t count);
template <>
VkImageSubresourceLayers* CommandRecorder::CopyArray<VkImageSubresourceLayers>(const VkImageSubresourceLayers* src,
                                                                               size_t start_index, size_t count);
template <>
VkBufferImageCopy* CommandRecorder::CopyArray<VkBufferImageCopy>(const VkBufferImageCopy* src, size_t start_index,
                                                                 size_t count);
template <>
VkClearColorValue* CommandRecorder::CopyArray<VkClearColorValue>(const VkClearColorValue* src, size_t start_index,
                                                                 size_t count);
template <>
VkClearDepthStencilValue* CommandRecorder::CopyArray<VkClearDepthStencilValue>(const VkClearDepthStencilValue* src,
                                                                               size_t start_index, size_t count);
template <>
VkClearValue* CommandRecorder::CopyArray<VkClearValue>(const VkClearValue* src, size_t start_index, size_t count);
template <>
VkClearAttachment* CommandRecorder::CopyArray<VkClearAttachment>(const VkClearAttachment* src, size_t start_index,
                                                                 size_t count);
template <>
VkClearRect* CommandRecorder::CopyArray<VkClearRect>(const VkClearRect* src, size_t start_index, size_t count);
template <>
VkImageBlit* CommandRecorder::CopyArray<VkImageBlit>(const VkImageBlit* src, size_t start_index, size_t count);
template <>
VkImageCopy* CommandRecorder::CopyArray<VkImageCopy>(const VkImageCopy* src, size_t start_index, size_t count);
template <>
VkImageResolve* CommandRecorder::CopyArray<VkImageResolve>(const VkImageResolve* src, size_t start_index, size_t count);
template <>
VkRenderPassBeginInfo* CommandRecorder::CopyArray<VkRenderPassBeginInfo>(const VkRenderPassBeginInfo* src,
                                                                         size_t start_index, size_t count);
template <>
VkSubpassBeginInfo* CommandRecorder::CopyArray<VkSubpassBeginInfo>(const VkSubpassBeginInfo* src, size_t start_index,
                                                                   size_t count);
template <>
VkSubpassEndInfo* CommandRecorder::CopyArray<VkSubpassEndInfo>(const VkSubpassEndInfo* src, size_t start_index,
                                                               size_t count);
template <>
VkMemoryBarrier2* CommandRecorder::CopyArray<VkMemoryBarrier2>(const VkMemoryBarrier2* src, size_t start_index,
                                                               size_t count);
template <>
VkBufferMemoryBarrier2* CommandRecorder::CopyArray<VkBufferMemoryBarrier2>(const VkBufferMemoryBarrier2* src,
                                                                           size_t start_index, size_t count);
template <>
VkImageMemoryBarrier2* CommandRecorder::CopyArray<VkImageMemoryBarrier2>(const VkImageMemoryBarrier2* src,
                                                                         size_t start_index, size_t count);
template <>
VkDependencyInfo* CommandRecorder::CopyArray<VkDependencyInfo>(const VkDependencyInfo* src, size_t start_index,
                                                               size_t count);
template <>
VkBufferCopy2* CommandRecorder::CopyArray<VkBufferCopy2>(const VkBufferCopy2* src, size_t start_index, size_t count);
template <>
VkCopyBufferInfo2* CommandRecorder::CopyArray<VkCopyBufferInfo2>(const VkCopyBufferInfo2* src, size_t start_index,
                                                                 size_t count);
template <>
VkImageCopy2* CommandRecorder::CopyArray<VkImageCopy2>(const VkImageCopy2* src, size_t start_index, size_t count);
template <>
VkCopyImageInfo2* CommandRecorder::CopyArray<VkCopyImageInfo2>(const VkCopyImageInfo2* src, size_t start_index,
                                                               size_t count);
template <>
VkBufferImageCopy2* CommandRecorder::CopyArray<VkBufferImageCopy2>(const VkBufferImageCopy2* src, size_t start_index,
                                                                   size_t count);
template <>
VkCopyBufferToImageInfo2* CommandRecorder::CopyArray<VkCopyBufferToImageInfo2>(const VkCopyBufferToImageInfo2* src,
                                                                               size_t start_index, size_t count);
template <>
VkCopyImageToBufferInfo2* CommandRecorder::CopyArray<VkCopyImageToBufferInfo2>(const VkCopyImageToBufferInfo2* src,
                                                                               size_t start_index, size_t count);
template <>
VkImageBlit2* CommandRecorder::CopyArray<VkImageBlit2>(const VkImageBlit2* src, size_t start_index, size_t count);
template <>
VkBlitImageInfo2* CommandRecorder::CopyArray<VkBlitImageInfo2>(const VkBlitImageInfo2* src, size_t start_index,
                                                               size_t count);
template <>
VkImageResolve2* CommandRecorder::CopyArray<VkImageResolve2>(const VkImageResolve2* src, size_t start_index,
                                                             size_t count);
template <>
VkResolveImageInfo2* CommandRecorder::CopyArray<VkResolveImageInfo2>(const VkResolveImageInfo2* src, size_t start_index,
                                                                     size_t count);
template <>
VkRenderingAttachmentInfo* CommandRecorder::CopyArray<VkRenderingAttachmentInfo>(const VkRenderingAttachmentInfo* src,
                                                                                 size_t start_index, size_t count);
template <>
VkRenderingInfo* CommandRecorder::CopyArray<VkRenderingInfo>(const VkRenderingInfo* src, size_t start_index,
                                                             size_t count);
template <>
VkVideoPictureResourceInfoKHR* CommandRecorder::CopyArray<VkVideoPictureResourceInfoKHR>(
    const VkVideoPictureResourceInfoKHR* src, size_t start_index, size_t count);
template <>
VkVideoReferenceSlotInfoKHR* CommandRecorder::CopyArray<VkVideoReferenceSlotInfoKHR>(
    const VkVideoReferenceSlotInfoKHR* src, size_t start_index, size_t count);
template <>
VkVideoBeginCodingInfoKHR* CommandRecorder::CopyArray<VkVideoBeginCodingInfoKHR>(const VkVideoBeginCodingInfoKHR* src,
                                                                                 size_t start_index, size_t count);
template <>
VkVideoEndCodingInfoKHR* CommandRecorder::CopyArray<VkVideoEndCodingInfoKHR>(const VkVideoEndCodingInfoKHR* src,
                                                                             size_t start_index, size_t count);
template <>
VkVideoCodingControlInfoKHR* CommandRecorder::CopyArray<VkVideoCodingControlInfoKHR>(
    const VkVideoCodingControlInfoKHR* src, size_t start_index, size_t count);
template <>
VkVideoDecodeInfoKHR* CommandRecorder::CopyArray<VkVideoDecodeInfoKHR>(const VkVideoDecodeInfoKHR* src,
                                                                       size_t start_index, size_t count);
template <>
VkRenderingAttachmentLocationInfoKHR* CommandRecorder::CopyArray<VkRenderingAttachmentLocationInfoKHR>(
    const VkRenderingAttachmentLocationInfoKHR* src, size_t start_index, size_t count);
template <>
VkRenderingInputAttachmentIndexInfoKHR* CommandRecorder::CopyArray<VkRenderingInputAttachmentIndexInfoKHR>(
    const VkRenderingInputAttachmentIndexInfoKHR* src, size_t start_index, size_t count);
template <>
VkVideoEncodeInfoKHR* CommandRecorder::CopyArray<VkVideoEncodeInfoKHR>(const VkVideoEncodeInfoKHR* src,
                                                                       size_t start_index, size_t count);
template <>
VkBindDescriptorSetsInfoKHR* CommandRecorder::CopyArray<VkBindDescriptorSetsInfoKHR>(
    const VkBindDescriptorSetsInfoKHR* src, size_t start_index, size_t count);
template <>
VkPushConstantsInfoKHR* CommandRecorder::CopyArray<VkPushConstantsInfoKHR>(const VkPushConstantsInfoKHR* src,
                                                                           size_t start_index, size_t count);
template <>
VkPushDescriptorSetInfoKHR* CommandRecorder::CopyArray<VkPushDescriptorSetInfoKHR>(
    const VkPushDescriptorSetInfoKHR* src, size_t start_index, size_t count);
template <>
VkPushDescriptorSetWithTemplateInfoKHR* CommandRecorder::CopyArray<VkPushDescriptorSetWithTemplateInfoKHR>(
    const VkPushDescriptorSetWithTemplateInfoKHR* src, size_t start_index, size_t count);
template <>
VkSetDescriptorBufferOffsetsInfoEXT* CommandRecorder::CopyArray<VkSetDescriptorBufferOffsetsInfoEXT>(
    const VkSetDescriptorBufferOffsetsInfoEXT* src, size_t start_index, size_t count);
template <>
VkBindDescriptorBufferEmbeddedSamplersInfoEXT*
CommandRecorder::CopyArray<VkBindDescriptorBufferEmbeddedSamplersInfoEXT>(
    const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* src, size_t start_index, size_t count);
template <>
VkDebugMarkerMarkerInfoEXT* CommandRecorder::CopyArray<VkDebugMarkerMarkerInfoEXT>(
    const VkDebugMarkerMarkerInfoEXT* src, size_t start_index, size_t count);
template <>
VkCuLaunchInfoNVX* CommandRecorder::CopyArray<VkCuLaunchInfoNVX>(const VkCuLaunchInfoNVX* src, size_t start_index,
                                                                 size_t count);
template <>
VkConditionalRenderingBeginInfoEXT* CommandRecorder::CopyArray<VkConditionalRenderingBeginInfoEXT>(
    const VkConditionalRenderingBeginInfoEXT* src, size_t start_index, size_t count);
template <>
VkViewportWScalingNV* CommandRecorder::CopyArray<VkViewportWScalingNV>(const VkViewportWScalingNV* src,
                                                                       size_t start_index, size_t count);
template <>
VkViewportSwizzleNV* CommandRecorder::CopyArray<VkViewportSwizzleNV>(const VkViewportSwizzleNV* src, size_t start_index,
                                                                     size_t count);
template <>
VkDebugUtilsLabelEXT* CommandRecorder::CopyArray<VkDebugUtilsLabelEXT>(const VkDebugUtilsLabelEXT* src,
                                                                       size_t start_index, size_t count);
#ifdef VK_ENABLE_BETA_EXTENSIONS
template <>
VkDeviceOrHostAddressConstAMDX* CommandRecorder::CopyArray<VkDeviceOrHostAddressConstAMDX>(
    const VkDeviceOrHostAddressConstAMDX* src, size_t start_index, size_t count);
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
template <>
VkDispatchGraphCountInfoAMDX* CommandRecorder::CopyArray<VkDispatchGraphCountInfoAMDX>(
    const VkDispatchGraphCountInfoAMDX* src, size_t start_index, size_t count);
#endif  // VK_ENABLE_BETA_EXTENSIONS
template <>
VkSampleLocationEXT* CommandRecorder::CopyArray<VkSampleLocationEXT>(const VkSampleLocationEXT* src, size_t start_index,
                                                                     size_t count);
template <>
VkSampleLocationsInfoEXT* CommandRecorder::CopyArray<VkSampleLocationsInfoEXT>(const VkSampleLocationsInfoEXT* src,
                                                                               size_t start_index, size_t count);
template <>
VkShadingRatePaletteNV* CommandRecorder::CopyArray<VkShadingRatePaletteNV>(const VkShadingRatePaletteNV* src,
                                                                           size_t start_index, size_t count);
template <>
VkCoarseSampleLocationNV* CommandRecorder::CopyArray<VkCoarseSampleLocationNV>(const VkCoarseSampleLocationNV* src,
                                                                               size_t start_index, size_t count);
template <>
VkCoarseSampleOrderCustomNV* CommandRecorder::CopyArray<VkCoarseSampleOrderCustomNV>(
    const VkCoarseSampleOrderCustomNV* src, size_t start_index, size_t count);
template <>
VkGeometryNV* CommandRecorder::CopyArray<VkGeometryNV>(const VkGeometryNV* src, size_t start_index, size_t count);
template <>
VkAccelerationStructureInfoNV* CommandRecorder::CopyArray<VkAccelerationStructureInfoNV>(
    const VkAccelerationStructureInfoNV* src, size_t start_index, size_t count);
template <>
VkPerformanceMarkerInfoINTEL* CommandRecorder::CopyArray<VkPerformanceMarkerInfoINTEL>(
    const VkPerformanceMarkerInfoINTEL* src, size_t start_index, size_t count);
template <>
VkPerformanceStreamMarkerInfoINTEL* CommandRecorder::CopyArray<VkPerformanceStreamMarkerInfoINTEL>(
    const VkPerformanceStreamMarkerInfoINTEL* src, size_t start_index, size_t count);
template <>
VkPerformanceOverrideInfoINTEL* CommandRecorder::CopyArray<VkPerformanceOverrideInfoINTEL>(
    const VkPerformanceOverrideInfoINTEL* src, size_t start_index, size_t count);
template <>
VkIndirectCommandsStreamNV* CommandRecorder::CopyArray<VkIndirectCommandsStreamNV>(
    const VkIndirectCommandsStreamNV* src, size_t start_index, size_t count);
template <>
VkGeneratedCommandsInfoNV* CommandRecorder::CopyArray<VkGeneratedCommandsInfoNV>(const VkGeneratedCommandsInfoNV* src,
                                                                                 size_t start_index, size_t count);
template <>
VkDepthBiasInfoEXT* CommandRecorder::CopyArray<VkDepthBiasInfoEXT>(const VkDepthBiasInfoEXT* src, size_t start_index,
                                                                   size_t count);
template <>
VkCudaLaunchInfoNV* CommandRecorder::CopyArray<VkCudaLaunchInfoNV>(const VkCudaLaunchInfoNV* src, size_t start_index,
                                                                   size_t count);
template <>
VkDescriptorBufferBindingInfoEXT* CommandRecorder::CopyArray<VkDescriptorBufferBindingInfoEXT>(
    const VkDescriptorBufferBindingInfoEXT* src, size_t start_index, size_t count);
template <>
VkDeviceOrHostAddressConstKHR* CommandRecorder::CopyArray<VkDeviceOrHostAddressConstKHR>(
    const VkDeviceOrHostAddressConstKHR* src, size_t start_index, size_t count);
template <>
VkVertexInputBindingDescription2EXT* CommandRecorder::CopyArray<VkVertexInputBindingDescription2EXT>(
    const VkVertexInputBindingDescription2EXT* src, size_t start_index, size_t count);
template <>
VkVertexInputAttributeDescription2EXT* CommandRecorder::CopyArray<VkVertexInputAttributeDescription2EXT>(
    const VkVertexInputAttributeDescription2EXT* src, size_t start_index, size_t count);
template <>
VkMultiDrawInfoEXT* CommandRecorder::CopyArray<VkMultiDrawInfoEXT>(const VkMultiDrawInfoEXT* src, size_t start_index,
                                                                   size_t count);
template <>
VkMultiDrawIndexedInfoEXT* CommandRecorder::CopyArray<VkMultiDrawIndexedInfoEXT>(const VkMultiDrawIndexedInfoEXT* src,
                                                                                 size_t start_index, size_t count);
template <>
VkMicromapUsageEXT* CommandRecorder::CopyArray<VkMicromapUsageEXT>(const VkMicromapUsageEXT* src, size_t start_index,
                                                                   size_t count);
template <>
VkDeviceOrHostAddressKHR* CommandRecorder::CopyArray<VkDeviceOrHostAddressKHR>(const VkDeviceOrHostAddressKHR* src,
                                                                               size_t start_index, size_t count);
template <>
VkMicromapBuildInfoEXT* CommandRecorder::CopyArray<VkMicromapBuildInfoEXT>(const VkMicromapBuildInfoEXT* src,
                                                                           size_t start_index, size_t count);
template <>
VkCopyMicromapToMemoryInfoEXT* CommandRecorder::CopyArray<VkCopyMicromapToMemoryInfoEXT>(
    const VkCopyMicromapToMemoryInfoEXT* src, size_t start_index, size_t count);
template <>
VkCopyMemoryToMicromapInfoEXT* CommandRecorder::CopyArray<VkCopyMemoryToMicromapInfoEXT>(
    const VkCopyMemoryToMicromapInfoEXT* src, size_t start_index, size_t count);
template <>
VkCopyMicromapInfoEXT* CommandRecorder::CopyArray<VkCopyMicromapInfoEXT>(const VkCopyMicromapInfoEXT* src,
                                                                         size_t start_index, size_t count);
template <>
VkDecompressMemoryRegionNV* CommandRecorder::CopyArray<VkDecompressMemoryRegionNV>(
    const VkDecompressMemoryRegionNV* src, size_t start_index, size_t count);
template <>
VkColorBlendEquationEXT* CommandRecorder::CopyArray<VkColorBlendEquationEXT>(const VkColorBlendEquationEXT* src,
                                                                             size_t start_index, size_t count);
template <>
VkColorBlendAdvancedEXT* CommandRecorder::CopyArray<VkColorBlendAdvancedEXT>(const VkColorBlendAdvancedEXT* src,
                                                                             size_t start_index, size_t count);
template <>
VkOpticalFlowExecuteInfoNV* CommandRecorder::CopyArray<VkOpticalFlowExecuteInfoNV>(
    const VkOpticalFlowExecuteInfoNV* src, size_t start_index, size_t count);
template <>
VkDepthClampRangeEXT* CommandRecorder::CopyArray<VkDepthClampRangeEXT>(const VkDepthClampRangeEXT* src,
                                                                       size_t start_index, size_t count);
template <>
VkGeneratedCommandsInfoEXT* CommandRecorder::CopyArray<VkGeneratedCommandsInfoEXT>(
    const VkGeneratedCommandsInfoEXT* src, size_t start_index, size_t count);
template <>
VkAccelerationStructureBuildRangeInfoKHR* CommandRecorder::CopyArray<VkAccelerationStructureBuildRangeInfoKHR>(
    const VkAccelerationStructureBuildRangeInfoKHR* src, size_t start_index, size_t count);
template <>
VkAccelerationStructureGeometryKHR* CommandRecorder::CopyArray<VkAccelerationStructureGeometryKHR>(
    const VkAccelerationStructureGeometryKHR* src, size_t start_index, size_t count);
template <>
VkAccelerationStructureBuildGeometryInfoKHR* CommandRecorder::CopyArray<VkAccelerationStructureBuildGeometryInfoKHR>(
    const VkAccelerationStructureBuildGeometryInfoKHR* src, size_t start_index, size_t count);
template <>
VkCopyAccelerationStructureToMemoryInfoKHR* CommandRecorder::CopyArray<VkCopyAccelerationStructureToMemoryInfoKHR>(
    const VkCopyAccelerationStructureToMemoryInfoKHR* src, size_t start_index, size_t count);
template <>
VkCopyMemoryToAccelerationStructureInfoKHR* CommandRecorder::CopyArray<VkCopyMemoryToAccelerationStructureInfoKHR>(
    const VkCopyMemoryToAccelerationStructureInfoKHR* src, size_t start_index, size_t count);
template <>
VkCopyAccelerationStructureInfoKHR* CommandRecorder::CopyArray<VkCopyAccelerationStructureInfoKHR>(
    const VkCopyAccelerationStructureInfoKHR* src, size_t start_index, size_t count);
template <>
VkStridedDeviceAddressRegionKHR* CommandRecorder::CopyArray<VkStridedDeviceAddressRegionKHR>(
    const VkStridedDeviceAddressRegionKHR* src, size_t start_index, size_t count);

// Define CopyArray template functions.

template <>
uint8_t* CommandRecorder::CopyArray<uint8_t>(const uint8_t* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<uint8_t*>(m_allocator.Alloc(sizeof(uint8_t) * count));
    memcpy(ptr, src, sizeof(uint8_t) * count);
    return ptr;
}
template <>
VkExtent2D* CommandRecorder::CopyArray<VkExtent2D>(const VkExtent2D* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkExtent2D*>(m_allocator.Alloc(sizeof(VkExtent2D) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].width = src[start_index + i].width;
        ptr[i].height = src[start_index + i].height;
    }
    return ptr;
}

template <>
VkExtent3D* CommandRecorder::CopyArray<VkExtent3D>(const VkExtent3D* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkExtent3D*>(m_allocator.Alloc(sizeof(VkExtent3D) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].width = src[start_index + i].width;
        ptr[i].height = src[start_index + i].height;
        ptr[i].depth = src[start_index + i].depth;
    }
    return ptr;
}

template <>
VkOffset2D* CommandRecorder::CopyArray<VkOffset2D>(const VkOffset2D* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkOffset2D*>(m_allocator.Alloc(sizeof(VkOffset2D) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].x = src[start_index + i].x;
        ptr[i].y = src[start_index + i].y;
    }
    return ptr;
}

template <>
VkOffset3D* CommandRecorder::CopyArray<VkOffset3D>(const VkOffset3D* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkOffset3D*>(m_allocator.Alloc(sizeof(VkOffset3D) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].x = src[start_index + i].x;
        ptr[i].y = src[start_index + i].y;
        ptr[i].z = src[start_index + i].z;
    }
    return ptr;
}

template <>
VkRect2D* CommandRecorder::CopyArray<VkRect2D>(const VkRect2D* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkRect2D*>(m_allocator.Alloc(sizeof(VkRect2D) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].offset = src[start_index + i].offset;
        ptr[i].extent = src[start_index + i].extent;
    }
    return ptr;
}

template <>
VkBufferMemoryBarrier* CommandRecorder::CopyArray<VkBufferMemoryBarrier>(const VkBufferMemoryBarrier* src,
                                                                         size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkBufferMemoryBarrier*>(m_allocator.Alloc(sizeof(VkBufferMemoryBarrier) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].srcAccessMask = src[start_index + i].srcAccessMask;
        ptr[i].dstAccessMask = src[start_index + i].dstAccessMask;
        ptr[i].srcQueueFamilyIndex = src[start_index + i].srcQueueFamilyIndex;
        ptr[i].dstQueueFamilyIndex = src[start_index + i].dstQueueFamilyIndex;
        ptr[i].buffer = src[start_index + i].buffer;
        ptr[i].offset = src[start_index + i].offset;
        ptr[i].size = src[start_index + i].size;
    }
    return ptr;
}

template <>
VkImageSubresourceRange* CommandRecorder::CopyArray<VkImageSubresourceRange>(const VkImageSubresourceRange* src,
                                                                             size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkImageSubresourceRange*>(m_allocator.Alloc(sizeof(VkImageSubresourceRange) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].aspectMask = src[start_index + i].aspectMask;
        ptr[i].baseMipLevel = src[start_index + i].baseMipLevel;
        ptr[i].levelCount = src[start_index + i].levelCount;
        ptr[i].baseArrayLayer = src[start_index + i].baseArrayLayer;
        ptr[i].layerCount = src[start_index + i].layerCount;
    }
    return ptr;
}

template <>
VkImageMemoryBarrier* CommandRecorder::CopyArray<VkImageMemoryBarrier>(const VkImageMemoryBarrier* src,
                                                                       size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkImageMemoryBarrier*>(m_allocator.Alloc(sizeof(VkImageMemoryBarrier) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].srcAccessMask = src[start_index + i].srcAccessMask;
        ptr[i].dstAccessMask = src[start_index + i].dstAccessMask;
        ptr[i].oldLayout = src[start_index + i].oldLayout;
        ptr[i].newLayout = src[start_index + i].newLayout;
        ptr[i].srcQueueFamilyIndex = src[start_index + i].srcQueueFamilyIndex;
        ptr[i].dstQueueFamilyIndex = src[start_index + i].dstQueueFamilyIndex;
        ptr[i].image = src[start_index + i].image;
        ptr[i].subresourceRange = src[start_index + i].subresourceRange;
    }
    return ptr;
}

template <>
VkMemoryBarrier* CommandRecorder::CopyArray<VkMemoryBarrier>(const VkMemoryBarrier* src, size_t start_index,
                                                             size_t count) {
    auto ptr = reinterpret_cast<VkMemoryBarrier*>(m_allocator.Alloc(sizeof(VkMemoryBarrier) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].srcAccessMask = src[start_index + i].srcAccessMask;
        ptr[i].dstAccessMask = src[start_index + i].dstAccessMask;
    }
    return ptr;
}

template <>
VkViewport* CommandRecorder::CopyArray<VkViewport>(const VkViewport* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkViewport*>(m_allocator.Alloc(sizeof(VkViewport) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].x = src[start_index + i].x;
        ptr[i].y = src[start_index + i].y;
        ptr[i].width = src[start_index + i].width;
        ptr[i].height = src[start_index + i].height;
        ptr[i].minDepth = src[start_index + i].minDepth;
        ptr[i].maxDepth = src[start_index + i].maxDepth;
    }
    return ptr;
}

template <>
VkDescriptorBufferInfo* CommandRecorder::CopyArray<VkDescriptorBufferInfo>(const VkDescriptorBufferInfo* src,
                                                                           size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkDescriptorBufferInfo*>(m_allocator.Alloc(sizeof(VkDescriptorBufferInfo) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].buffer = src[start_index + i].buffer;
        ptr[i].offset = src[start_index + i].offset;
        ptr[i].range = src[start_index + i].range;
    }
    return ptr;
}

template <>
VkDescriptorImageInfo* CommandRecorder::CopyArray<VkDescriptorImageInfo>(const VkDescriptorImageInfo* src,
                                                                         size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkDescriptorImageInfo*>(m_allocator.Alloc(sizeof(VkDescriptorImageInfo) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sampler = src[start_index + i].sampler;
        ptr[i].imageView = src[start_index + i].imageView;
        ptr[i].imageLayout = src[start_index + i].imageLayout;
    }
    return ptr;
}

template <>
VkWriteDescriptorSet* CommandRecorder::CopyArray<VkWriteDescriptorSet>(const VkWriteDescriptorSet* src,
                                                                       size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkWriteDescriptorSet*>(m_allocator.Alloc(sizeof(VkWriteDescriptorSet) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].dstSet = src[start_index + i].dstSet;
        ptr[i].dstBinding = src[start_index + i].dstBinding;
        ptr[i].dstArrayElement = src[start_index + i].dstArrayElement;
        ptr[i].descriptorCount = src[start_index + i].descriptorCount;
        ptr[i].descriptorType = src[start_index + i].descriptorType;
        ptr[i].pImageInfo = nullptr;
        if (src[start_index + i].pImageInfo) {
            ptr[i].pImageInfo = CopyArray(src[start_index + i].pImageInfo, static_cast<uint64_t>(0U),
                                          static_cast<uint64_t>(src[start_index + i].descriptorCount));
        }
        ptr[i].pBufferInfo = nullptr;
        if (src[start_index + i].pBufferInfo) {
            ptr[i].pBufferInfo = CopyArray(src[start_index + i].pBufferInfo, static_cast<uint64_t>(0U),
                                           static_cast<uint64_t>(src[start_index + i].descriptorCount));
        }
        ptr[i].pTexelBufferView = nullptr;
        if (src[start_index + i].pTexelBufferView) {
            ptr[i].pTexelBufferView = CopyArray(src[start_index + i].pTexelBufferView, static_cast<uint64_t>(0U),
                                                static_cast<uint64_t>(src[start_index + i].descriptorCount));
        }
    }
    return ptr;
}

template <>
VkCommandBufferInheritanceInfo* CommandRecorder::CopyArray<VkCommandBufferInheritanceInfo>(
    const VkCommandBufferInheritanceInfo* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkCommandBufferInheritanceInfo*>(
        m_allocator.Alloc(sizeof(VkCommandBufferInheritanceInfo) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].renderPass = src[start_index + i].renderPass;
        ptr[i].subpass = src[start_index + i].subpass;
        ptr[i].framebuffer = src[start_index + i].framebuffer;
        ptr[i].occlusionQueryEnable = src[start_index + i].occlusionQueryEnable;
        ptr[i].queryFlags = src[start_index + i].queryFlags;
        ptr[i].pipelineStatistics = src[start_index + i].pipelineStatistics;
    }
    return ptr;
}

template <>
VkCommandBufferBeginInfo* CommandRecorder::CopyArray<VkCommandBufferBeginInfo>(const VkCommandBufferBeginInfo* src,
                                                                               size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkCommandBufferBeginInfo*>(m_allocator.Alloc(sizeof(VkCommandBufferBeginInfo) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].flags = src[start_index + i].flags;
        ptr[i].pInheritanceInfo = nullptr;
        if (src[start_index + i].pInheritanceInfo) {
            ptr[i].pInheritanceInfo =
                CopyArray(src[start_index + i].pInheritanceInfo, static_cast<uint64_t>(0U), static_cast<uint64_t>(1U));
        }
    }
    return ptr;
}

template <>
VkBufferCopy* CommandRecorder::CopyArray<VkBufferCopy>(const VkBufferCopy* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkBufferCopy*>(m_allocator.Alloc(sizeof(VkBufferCopy) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].srcOffset = src[start_index + i].srcOffset;
        ptr[i].dstOffset = src[start_index + i].dstOffset;
        ptr[i].size = src[start_index + i].size;
    }
    return ptr;
}

template <>
VkImageSubresourceLayers* CommandRecorder::CopyArray<VkImageSubresourceLayers>(const VkImageSubresourceLayers* src,
                                                                               size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkImageSubresourceLayers*>(m_allocator.Alloc(sizeof(VkImageSubresourceLayers) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].aspectMask = src[start_index + i].aspectMask;
        ptr[i].mipLevel = src[start_index + i].mipLevel;
        ptr[i].baseArrayLayer = src[start_index + i].baseArrayLayer;
        ptr[i].layerCount = src[start_index + i].layerCount;
    }
    return ptr;
}

template <>
VkBufferImageCopy* CommandRecorder::CopyArray<VkBufferImageCopy>(const VkBufferImageCopy* src, size_t start_index,
                                                                 size_t count) {
    auto ptr = reinterpret_cast<VkBufferImageCopy*>(m_allocator.Alloc(sizeof(VkBufferImageCopy) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].bufferOffset = src[start_index + i].bufferOffset;
        ptr[i].bufferRowLength = src[start_index + i].bufferRowLength;
        ptr[i].bufferImageHeight = src[start_index + i].bufferImageHeight;
        ptr[i].imageSubresource = src[start_index + i].imageSubresource;
        ptr[i].imageOffset = src[start_index + i].imageOffset;
        ptr[i].imageExtent = src[start_index + i].imageExtent;
    }
    return ptr;
}

template <>
VkClearColorValue* CommandRecorder::CopyArray<VkClearColorValue>(const VkClearColorValue* src, size_t start_index,
                                                                 size_t count) {
    auto ptr = reinterpret_cast<VkClearColorValue*>(m_allocator.Alloc(sizeof(VkClearColorValue) * count));
    for (uint64_t i = 0; i < count; ++i) {
        for (uint32_t j = 0; j < 4; ++j) {
            ptr[i].float32[j] = src[start_index + i].float32[j];
        }
        for (uint32_t j = 0; j < 4; ++j) {
            ptr[i].int32[j] = src[start_index + i].int32[j];
        }
        for (uint32_t j = 0; j < 4; ++j) {
            ptr[i].uint32[j] = src[start_index + i].uint32[j];
        }
    }
    return ptr;
}

template <>
VkClearDepthStencilValue* CommandRecorder::CopyArray<VkClearDepthStencilValue>(const VkClearDepthStencilValue* src,
                                                                               size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkClearDepthStencilValue*>(m_allocator.Alloc(sizeof(VkClearDepthStencilValue) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].depth = src[start_index + i].depth;
        ptr[i].stencil = src[start_index + i].stencil;
    }
    return ptr;
}

template <>
VkClearValue* CommandRecorder::CopyArray<VkClearValue>(const VkClearValue* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkClearValue*>(m_allocator.Alloc(sizeof(VkClearValue) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].color = src[start_index + i].color;
        ptr[i].depthStencil = src[start_index + i].depthStencil;
    }
    return ptr;
}

template <>
VkClearAttachment* CommandRecorder::CopyArray<VkClearAttachment>(const VkClearAttachment* src, size_t start_index,
                                                                 size_t count) {
    auto ptr = reinterpret_cast<VkClearAttachment*>(m_allocator.Alloc(sizeof(VkClearAttachment) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].aspectMask = src[start_index + i].aspectMask;
        ptr[i].colorAttachment = src[start_index + i].colorAttachment;
        ptr[i].clearValue = src[start_index + i].clearValue;
    }
    return ptr;
}

template <>
VkClearRect* CommandRecorder::CopyArray<VkClearRect>(const VkClearRect* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkClearRect*>(m_allocator.Alloc(sizeof(VkClearRect) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].rect = src[start_index + i].rect;
        ptr[i].baseArrayLayer = src[start_index + i].baseArrayLayer;
        ptr[i].layerCount = src[start_index + i].layerCount;
    }
    return ptr;
}

template <>
VkImageBlit* CommandRecorder::CopyArray<VkImageBlit>(const VkImageBlit* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkImageBlit*>(m_allocator.Alloc(sizeof(VkImageBlit) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].srcSubresource = src[start_index + i].srcSubresource;
        for (uint32_t j = 0; j < 2; ++j) {
            ptr[i].srcOffsets[j] = src[start_index + i].srcOffsets[j];
        }
        ptr[i].dstSubresource = src[start_index + i].dstSubresource;
        for (uint32_t j = 0; j < 2; ++j) {
            ptr[i].dstOffsets[j] = src[start_index + i].dstOffsets[j];
        }
    }
    return ptr;
}

template <>
VkImageCopy* CommandRecorder::CopyArray<VkImageCopy>(const VkImageCopy* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkImageCopy*>(m_allocator.Alloc(sizeof(VkImageCopy) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].srcSubresource = src[start_index + i].srcSubresource;
        ptr[i].srcOffset = src[start_index + i].srcOffset;
        ptr[i].dstSubresource = src[start_index + i].dstSubresource;
        ptr[i].dstOffset = src[start_index + i].dstOffset;
        ptr[i].extent = src[start_index + i].extent;
    }
    return ptr;
}

template <>
VkImageResolve* CommandRecorder::CopyArray<VkImageResolve>(const VkImageResolve* src, size_t start_index,
                                                           size_t count) {
    auto ptr = reinterpret_cast<VkImageResolve*>(m_allocator.Alloc(sizeof(VkImageResolve) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].srcSubresource = src[start_index + i].srcSubresource;
        ptr[i].srcOffset = src[start_index + i].srcOffset;
        ptr[i].dstSubresource = src[start_index + i].dstSubresource;
        ptr[i].dstOffset = src[start_index + i].dstOffset;
        ptr[i].extent = src[start_index + i].extent;
    }
    return ptr;
}

template <>
VkRenderPassBeginInfo* CommandRecorder::CopyArray<VkRenderPassBeginInfo>(const VkRenderPassBeginInfo* src,
                                                                         size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkRenderPassBeginInfo*>(m_allocator.Alloc(sizeof(VkRenderPassBeginInfo) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].renderPass = src[start_index + i].renderPass;
        ptr[i].framebuffer = src[start_index + i].framebuffer;
        ptr[i].renderArea = src[start_index + i].renderArea;
        ptr[i].clearValueCount = src[start_index + i].clearValueCount;
        ptr[i].pClearValues = nullptr;
        if (src[start_index + i].pClearValues) {
            ptr[i].pClearValues = CopyArray(src[start_index + i].pClearValues, static_cast<uint64_t>(0U),
                                            static_cast<uint64_t>(src[start_index + i].clearValueCount));
        }
    }
    return ptr;
}

template <>
VkSubpassBeginInfo* CommandRecorder::CopyArray<VkSubpassBeginInfo>(const VkSubpassBeginInfo* src, size_t start_index,
                                                                   size_t count) {
    auto ptr = reinterpret_cast<VkSubpassBeginInfo*>(m_allocator.Alloc(sizeof(VkSubpassBeginInfo) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].contents = src[start_index + i].contents;
    }
    return ptr;
}

template <>
VkSubpassEndInfo* CommandRecorder::CopyArray<VkSubpassEndInfo>(const VkSubpassEndInfo* src, size_t start_index,
                                                               size_t count) {
    auto ptr = reinterpret_cast<VkSubpassEndInfo*>(m_allocator.Alloc(sizeof(VkSubpassEndInfo) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
    }
    return ptr;
}

template <>
VkMemoryBarrier2* CommandRecorder::CopyArray<VkMemoryBarrier2>(const VkMemoryBarrier2* src, size_t start_index,
                                                               size_t count) {
    auto ptr = reinterpret_cast<VkMemoryBarrier2*>(m_allocator.Alloc(sizeof(VkMemoryBarrier2) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].srcStageMask = src[start_index + i].srcStageMask;
        ptr[i].srcAccessMask = src[start_index + i].srcAccessMask;
        ptr[i].dstStageMask = src[start_index + i].dstStageMask;
        ptr[i].dstAccessMask = src[start_index + i].dstAccessMask;
    }
    return ptr;
}

template <>
VkBufferMemoryBarrier2* CommandRecorder::CopyArray<VkBufferMemoryBarrier2>(const VkBufferMemoryBarrier2* src,
                                                                           size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkBufferMemoryBarrier2*>(m_allocator.Alloc(sizeof(VkBufferMemoryBarrier2) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].srcStageMask = src[start_index + i].srcStageMask;
        ptr[i].srcAccessMask = src[start_index + i].srcAccessMask;
        ptr[i].dstStageMask = src[start_index + i].dstStageMask;
        ptr[i].dstAccessMask = src[start_index + i].dstAccessMask;
        ptr[i].srcQueueFamilyIndex = src[start_index + i].srcQueueFamilyIndex;
        ptr[i].dstQueueFamilyIndex = src[start_index + i].dstQueueFamilyIndex;
        ptr[i].buffer = src[start_index + i].buffer;
        ptr[i].offset = src[start_index + i].offset;
        ptr[i].size = src[start_index + i].size;
    }
    return ptr;
}

template <>
VkImageMemoryBarrier2* CommandRecorder::CopyArray<VkImageMemoryBarrier2>(const VkImageMemoryBarrier2* src,
                                                                         size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkImageMemoryBarrier2*>(m_allocator.Alloc(sizeof(VkImageMemoryBarrier2) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].srcStageMask = src[start_index + i].srcStageMask;
        ptr[i].srcAccessMask = src[start_index + i].srcAccessMask;
        ptr[i].dstStageMask = src[start_index + i].dstStageMask;
        ptr[i].dstAccessMask = src[start_index + i].dstAccessMask;
        ptr[i].oldLayout = src[start_index + i].oldLayout;
        ptr[i].newLayout = src[start_index + i].newLayout;
        ptr[i].srcQueueFamilyIndex = src[start_index + i].srcQueueFamilyIndex;
        ptr[i].dstQueueFamilyIndex = src[start_index + i].dstQueueFamilyIndex;
        ptr[i].image = src[start_index + i].image;
        ptr[i].subresourceRange = src[start_index + i].subresourceRange;
    }
    return ptr;
}

template <>
VkDependencyInfo* CommandRecorder::CopyArray<VkDependencyInfo>(const VkDependencyInfo* src, size_t start_index,
                                                               size_t count) {
    auto ptr = reinterpret_cast<VkDependencyInfo*>(m_allocator.Alloc(sizeof(VkDependencyInfo) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].dependencyFlags = src[start_index + i].dependencyFlags;
        ptr[i].memoryBarrierCount = src[start_index + i].memoryBarrierCount;
        ptr[i].pMemoryBarriers = nullptr;
        if (src[start_index + i].pMemoryBarriers) {
            ptr[i].pMemoryBarriers = CopyArray(src[start_index + i].pMemoryBarriers, static_cast<uint64_t>(0U),
                                               static_cast<uint64_t>(src[start_index + i].memoryBarrierCount));
        }
        ptr[i].bufferMemoryBarrierCount = src[start_index + i].bufferMemoryBarrierCount;
        ptr[i].pBufferMemoryBarriers = nullptr;
        if (src[start_index + i].pBufferMemoryBarriers) {
            ptr[i].pBufferMemoryBarriers =
                CopyArray(src[start_index + i].pBufferMemoryBarriers, static_cast<uint64_t>(0U),
                          static_cast<uint64_t>(src[start_index + i].bufferMemoryBarrierCount));
        }
        ptr[i].imageMemoryBarrierCount = src[start_index + i].imageMemoryBarrierCount;
        ptr[i].pImageMemoryBarriers = nullptr;
        if (src[start_index + i].pImageMemoryBarriers) {
            ptr[i].pImageMemoryBarriers =
                CopyArray(src[start_index + i].pImageMemoryBarriers, static_cast<uint64_t>(0U),
                          static_cast<uint64_t>(src[start_index + i].imageMemoryBarrierCount));
        }
    }
    return ptr;
}

template <>
VkBufferCopy2* CommandRecorder::CopyArray<VkBufferCopy2>(const VkBufferCopy2* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkBufferCopy2*>(m_allocator.Alloc(sizeof(VkBufferCopy2) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].srcOffset = src[start_index + i].srcOffset;
        ptr[i].dstOffset = src[start_index + i].dstOffset;
        ptr[i].size = src[start_index + i].size;
    }
    return ptr;
}

template <>
VkCopyBufferInfo2* CommandRecorder::CopyArray<VkCopyBufferInfo2>(const VkCopyBufferInfo2* src, size_t start_index,
                                                                 size_t count) {
    auto ptr = reinterpret_cast<VkCopyBufferInfo2*>(m_allocator.Alloc(sizeof(VkCopyBufferInfo2) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].srcBuffer = src[start_index + i].srcBuffer;
        ptr[i].dstBuffer = src[start_index + i].dstBuffer;
        ptr[i].regionCount = src[start_index + i].regionCount;
        ptr[i].pRegions = nullptr;
        if (src[start_index + i].pRegions) {
            ptr[i].pRegions = CopyArray(src[start_index + i].pRegions, static_cast<uint64_t>(0U),
                                        static_cast<uint64_t>(src[start_index + i].regionCount));
        }
    }
    return ptr;
}

template <>
VkImageCopy2* CommandRecorder::CopyArray<VkImageCopy2>(const VkImageCopy2* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkImageCopy2*>(m_allocator.Alloc(sizeof(VkImageCopy2) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].srcSubresource = src[start_index + i].srcSubresource;
        ptr[i].srcOffset = src[start_index + i].srcOffset;
        ptr[i].dstSubresource = src[start_index + i].dstSubresource;
        ptr[i].dstOffset = src[start_index + i].dstOffset;
        ptr[i].extent = src[start_index + i].extent;
    }
    return ptr;
}

template <>
VkCopyImageInfo2* CommandRecorder::CopyArray<VkCopyImageInfo2>(const VkCopyImageInfo2* src, size_t start_index,
                                                               size_t count) {
    auto ptr = reinterpret_cast<VkCopyImageInfo2*>(m_allocator.Alloc(sizeof(VkCopyImageInfo2) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].srcImage = src[start_index + i].srcImage;
        ptr[i].srcImageLayout = src[start_index + i].srcImageLayout;
        ptr[i].dstImage = src[start_index + i].dstImage;
        ptr[i].dstImageLayout = src[start_index + i].dstImageLayout;
        ptr[i].regionCount = src[start_index + i].regionCount;
        ptr[i].pRegions = nullptr;
        if (src[start_index + i].pRegions) {
            ptr[i].pRegions = CopyArray(src[start_index + i].pRegions, static_cast<uint64_t>(0U),
                                        static_cast<uint64_t>(src[start_index + i].regionCount));
        }
    }
    return ptr;
}

template <>
VkBufferImageCopy2* CommandRecorder::CopyArray<VkBufferImageCopy2>(const VkBufferImageCopy2* src, size_t start_index,
                                                                   size_t count) {
    auto ptr = reinterpret_cast<VkBufferImageCopy2*>(m_allocator.Alloc(sizeof(VkBufferImageCopy2) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].bufferOffset = src[start_index + i].bufferOffset;
        ptr[i].bufferRowLength = src[start_index + i].bufferRowLength;
        ptr[i].bufferImageHeight = src[start_index + i].bufferImageHeight;
        ptr[i].imageSubresource = src[start_index + i].imageSubresource;
        ptr[i].imageOffset = src[start_index + i].imageOffset;
        ptr[i].imageExtent = src[start_index + i].imageExtent;
    }
    return ptr;
}

template <>
VkCopyBufferToImageInfo2* CommandRecorder::CopyArray<VkCopyBufferToImageInfo2>(const VkCopyBufferToImageInfo2* src,
                                                                               size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkCopyBufferToImageInfo2*>(m_allocator.Alloc(sizeof(VkCopyBufferToImageInfo2) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].srcBuffer = src[start_index + i].srcBuffer;
        ptr[i].dstImage = src[start_index + i].dstImage;
        ptr[i].dstImageLayout = src[start_index + i].dstImageLayout;
        ptr[i].regionCount = src[start_index + i].regionCount;
        ptr[i].pRegions = nullptr;
        if (src[start_index + i].pRegions) {
            ptr[i].pRegions = CopyArray(src[start_index + i].pRegions, static_cast<uint64_t>(0U),
                                        static_cast<uint64_t>(src[start_index + i].regionCount));
        }
    }
    return ptr;
}

template <>
VkCopyImageToBufferInfo2* CommandRecorder::CopyArray<VkCopyImageToBufferInfo2>(const VkCopyImageToBufferInfo2* src,
                                                                               size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkCopyImageToBufferInfo2*>(m_allocator.Alloc(sizeof(VkCopyImageToBufferInfo2) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].srcImage = src[start_index + i].srcImage;
        ptr[i].srcImageLayout = src[start_index + i].srcImageLayout;
        ptr[i].dstBuffer = src[start_index + i].dstBuffer;
        ptr[i].regionCount = src[start_index + i].regionCount;
        ptr[i].pRegions = nullptr;
        if (src[start_index + i].pRegions) {
            ptr[i].pRegions = CopyArray(src[start_index + i].pRegions, static_cast<uint64_t>(0U),
                                        static_cast<uint64_t>(src[start_index + i].regionCount));
        }
    }
    return ptr;
}

template <>
VkImageBlit2* CommandRecorder::CopyArray<VkImageBlit2>(const VkImageBlit2* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkImageBlit2*>(m_allocator.Alloc(sizeof(VkImageBlit2) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].srcSubresource = src[start_index + i].srcSubresource;
        for (uint32_t j = 0; j < 2; ++j) {
            ptr[i].srcOffsets[j] = src[start_index + i].srcOffsets[j];
        }
        ptr[i].dstSubresource = src[start_index + i].dstSubresource;
        for (uint32_t j = 0; j < 2; ++j) {
            ptr[i].dstOffsets[j] = src[start_index + i].dstOffsets[j];
        }
    }
    return ptr;
}

template <>
VkBlitImageInfo2* CommandRecorder::CopyArray<VkBlitImageInfo2>(const VkBlitImageInfo2* src, size_t start_index,
                                                               size_t count) {
    auto ptr = reinterpret_cast<VkBlitImageInfo2*>(m_allocator.Alloc(sizeof(VkBlitImageInfo2) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].srcImage = src[start_index + i].srcImage;
        ptr[i].srcImageLayout = src[start_index + i].srcImageLayout;
        ptr[i].dstImage = src[start_index + i].dstImage;
        ptr[i].dstImageLayout = src[start_index + i].dstImageLayout;
        ptr[i].regionCount = src[start_index + i].regionCount;
        ptr[i].pRegions = nullptr;
        if (src[start_index + i].pRegions) {
            ptr[i].pRegions = CopyArray(src[start_index + i].pRegions, static_cast<uint64_t>(0U),
                                        static_cast<uint64_t>(src[start_index + i].regionCount));
        }
        ptr[i].filter = src[start_index + i].filter;
    }
    return ptr;
}

template <>
VkImageResolve2* CommandRecorder::CopyArray<VkImageResolve2>(const VkImageResolve2* src, size_t start_index,
                                                             size_t count) {
    auto ptr = reinterpret_cast<VkImageResolve2*>(m_allocator.Alloc(sizeof(VkImageResolve2) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].srcSubresource = src[start_index + i].srcSubresource;
        ptr[i].srcOffset = src[start_index + i].srcOffset;
        ptr[i].dstSubresource = src[start_index + i].dstSubresource;
        ptr[i].dstOffset = src[start_index + i].dstOffset;
        ptr[i].extent = src[start_index + i].extent;
    }
    return ptr;
}

template <>
VkResolveImageInfo2* CommandRecorder::CopyArray<VkResolveImageInfo2>(const VkResolveImageInfo2* src, size_t start_index,
                                                                     size_t count) {
    auto ptr = reinterpret_cast<VkResolveImageInfo2*>(m_allocator.Alloc(sizeof(VkResolveImageInfo2) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].srcImage = src[start_index + i].srcImage;
        ptr[i].srcImageLayout = src[start_index + i].srcImageLayout;
        ptr[i].dstImage = src[start_index + i].dstImage;
        ptr[i].dstImageLayout = src[start_index + i].dstImageLayout;
        ptr[i].regionCount = src[start_index + i].regionCount;
        ptr[i].pRegions = nullptr;
        if (src[start_index + i].pRegions) {
            ptr[i].pRegions = CopyArray(src[start_index + i].pRegions, static_cast<uint64_t>(0U),
                                        static_cast<uint64_t>(src[start_index + i].regionCount));
        }
    }
    return ptr;
}

template <>
VkRenderingAttachmentInfo* CommandRecorder::CopyArray<VkRenderingAttachmentInfo>(const VkRenderingAttachmentInfo* src,
                                                                                 size_t start_index, size_t count) {
    auto ptr =
        reinterpret_cast<VkRenderingAttachmentInfo*>(m_allocator.Alloc(sizeof(VkRenderingAttachmentInfo) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].imageView = src[start_index + i].imageView;
        ptr[i].imageLayout = src[start_index + i].imageLayout;
        ptr[i].resolveMode = src[start_index + i].resolveMode;
        ptr[i].resolveImageView = src[start_index + i].resolveImageView;
        ptr[i].resolveImageLayout = src[start_index + i].resolveImageLayout;
        ptr[i].loadOp = src[start_index + i].loadOp;
        ptr[i].storeOp = src[start_index + i].storeOp;
        ptr[i].clearValue = src[start_index + i].clearValue;
    }
    return ptr;
}

template <>
VkRenderingInfo* CommandRecorder::CopyArray<VkRenderingInfo>(const VkRenderingInfo* src, size_t start_index,
                                                             size_t count) {
    auto ptr = reinterpret_cast<VkRenderingInfo*>(m_allocator.Alloc(sizeof(VkRenderingInfo) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].flags = src[start_index + i].flags;
        ptr[i].renderArea = src[start_index + i].renderArea;
        ptr[i].layerCount = src[start_index + i].layerCount;
        ptr[i].viewMask = src[start_index + i].viewMask;
        ptr[i].colorAttachmentCount = src[start_index + i].colorAttachmentCount;
        ptr[i].pColorAttachments = nullptr;
        if (src[start_index + i].pColorAttachments) {
            ptr[i].pColorAttachments = CopyArray(src[start_index + i].pColorAttachments, static_cast<uint64_t>(0U),
                                                 static_cast<uint64_t>(src[start_index + i].colorAttachmentCount));
        }
        ptr[i].pDepthAttachment = nullptr;
        if (src[start_index + i].pDepthAttachment) {
            ptr[i].pDepthAttachment =
                CopyArray(src[start_index + i].pDepthAttachment, static_cast<uint64_t>(0U), static_cast<uint64_t>(1U));
        }
        ptr[i].pStencilAttachment = nullptr;
        if (src[start_index + i].pStencilAttachment) {
            ptr[i].pStencilAttachment = CopyArray(src[start_index + i].pStencilAttachment, static_cast<uint64_t>(0U),
                                                  static_cast<uint64_t>(1U));
        }
    }
    return ptr;
}

template <>
VkVideoPictureResourceInfoKHR* CommandRecorder::CopyArray<VkVideoPictureResourceInfoKHR>(
    const VkVideoPictureResourceInfoKHR* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkVideoPictureResourceInfoKHR*>(
        m_allocator.Alloc(sizeof(VkVideoPictureResourceInfoKHR) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].codedOffset = src[start_index + i].codedOffset;
        ptr[i].codedExtent = src[start_index + i].codedExtent;
        ptr[i].baseArrayLayer = src[start_index + i].baseArrayLayer;
        ptr[i].imageViewBinding = src[start_index + i].imageViewBinding;
    }
    return ptr;
}

template <>
VkVideoReferenceSlotInfoKHR* CommandRecorder::CopyArray<VkVideoReferenceSlotInfoKHR>(
    const VkVideoReferenceSlotInfoKHR* src, size_t start_index, size_t count) {
    auto ptr =
        reinterpret_cast<VkVideoReferenceSlotInfoKHR*>(m_allocator.Alloc(sizeof(VkVideoReferenceSlotInfoKHR) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].slotIndex = src[start_index + i].slotIndex;
        ptr[i].pPictureResource = nullptr;
        if (src[start_index + i].pPictureResource) {
            ptr[i].pPictureResource =
                CopyArray(src[start_index + i].pPictureResource, static_cast<uint64_t>(0U), static_cast<uint64_t>(1U));
        }
    }
    return ptr;
}

template <>
VkVideoBeginCodingInfoKHR* CommandRecorder::CopyArray<VkVideoBeginCodingInfoKHR>(const VkVideoBeginCodingInfoKHR* src,
                                                                                 size_t start_index, size_t count) {
    auto ptr =
        reinterpret_cast<VkVideoBeginCodingInfoKHR*>(m_allocator.Alloc(sizeof(VkVideoBeginCodingInfoKHR) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].flags = src[start_index + i].flags;
        ptr[i].videoSession = src[start_index + i].videoSession;
        ptr[i].videoSessionParameters = src[start_index + i].videoSessionParameters;
        ptr[i].referenceSlotCount = src[start_index + i].referenceSlotCount;
        ptr[i].pReferenceSlots = nullptr;
        if (src[start_index + i].pReferenceSlots) {
            ptr[i].pReferenceSlots = CopyArray(src[start_index + i].pReferenceSlots, static_cast<uint64_t>(0U),
                                               static_cast<uint64_t>(src[start_index + i].referenceSlotCount));
        }
    }
    return ptr;
}

template <>
VkVideoEndCodingInfoKHR* CommandRecorder::CopyArray<VkVideoEndCodingInfoKHR>(const VkVideoEndCodingInfoKHR* src,
                                                                             size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkVideoEndCodingInfoKHR*>(m_allocator.Alloc(sizeof(VkVideoEndCodingInfoKHR) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].flags = src[start_index + i].flags;
    }
    return ptr;
}

template <>
VkVideoCodingControlInfoKHR* CommandRecorder::CopyArray<VkVideoCodingControlInfoKHR>(
    const VkVideoCodingControlInfoKHR* src, size_t start_index, size_t count) {
    auto ptr =
        reinterpret_cast<VkVideoCodingControlInfoKHR*>(m_allocator.Alloc(sizeof(VkVideoCodingControlInfoKHR) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].flags = src[start_index + i].flags;
    }
    return ptr;
}

template <>
VkVideoDecodeInfoKHR* CommandRecorder::CopyArray<VkVideoDecodeInfoKHR>(const VkVideoDecodeInfoKHR* src,
                                                                       size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkVideoDecodeInfoKHR*>(m_allocator.Alloc(sizeof(VkVideoDecodeInfoKHR) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].flags = src[start_index + i].flags;
        ptr[i].srcBuffer = src[start_index + i].srcBuffer;
        ptr[i].srcBufferOffset = src[start_index + i].srcBufferOffset;
        ptr[i].srcBufferRange = src[start_index + i].srcBufferRange;
        ptr[i].dstPictureResource = src[start_index + i].dstPictureResource;
        ptr[i].pSetupReferenceSlot = nullptr;
        if (src[start_index + i].pSetupReferenceSlot) {
            ptr[i].pSetupReferenceSlot = CopyArray(src[start_index + i].pSetupReferenceSlot, static_cast<uint64_t>(0U),
                                                   static_cast<uint64_t>(1U));
        }
        ptr[i].referenceSlotCount = src[start_index + i].referenceSlotCount;
        ptr[i].pReferenceSlots = nullptr;
        if (src[start_index + i].pReferenceSlots) {
            ptr[i].pReferenceSlots = CopyArray(src[start_index + i].pReferenceSlots, static_cast<uint64_t>(0U),
                                               static_cast<uint64_t>(src[start_index + i].referenceSlotCount));
        }
    }
    return ptr;
}

template <>
VkRenderingAttachmentLocationInfoKHR* CommandRecorder::CopyArray<VkRenderingAttachmentLocationInfoKHR>(
    const VkRenderingAttachmentLocationInfoKHR* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkRenderingAttachmentLocationInfoKHR*>(
        m_allocator.Alloc(sizeof(VkRenderingAttachmentLocationInfoKHR) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].colorAttachmentCount = src[start_index + i].colorAttachmentCount;
        ptr[i].pColorAttachmentLocations = nullptr;
        if (src[start_index + i].pColorAttachmentLocations) {
            ptr[i].pColorAttachmentLocations =
                CopyArray(src[start_index + i].pColorAttachmentLocations, static_cast<uint64_t>(0U),
                          static_cast<uint64_t>(src[start_index + i].colorAttachmentCount));
        }
    }
    return ptr;
}

template <>
VkRenderingInputAttachmentIndexInfoKHR* CommandRecorder::CopyArray<VkRenderingInputAttachmentIndexInfoKHR>(
    const VkRenderingInputAttachmentIndexInfoKHR* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkRenderingInputAttachmentIndexInfoKHR*>(
        m_allocator.Alloc(sizeof(VkRenderingInputAttachmentIndexInfoKHR) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].colorAttachmentCount = src[start_index + i].colorAttachmentCount;
        ptr[i].pColorAttachmentInputIndices = nullptr;
        if (src[start_index + i].pColorAttachmentInputIndices) {
            ptr[i].pColorAttachmentInputIndices =
                CopyArray(src[start_index + i].pColorAttachmentInputIndices, static_cast<uint64_t>(0U),
                          static_cast<uint64_t>(src[start_index + i].colorAttachmentCount));
        }
        ptr[i].pDepthInputAttachmentIndex = nullptr;
        if (src[start_index + i].pDepthInputAttachmentIndex) {
            ptr[i].pDepthInputAttachmentIndex = CopyArray(src[start_index + i].pDepthInputAttachmentIndex,
                                                          static_cast<uint64_t>(0U), static_cast<uint64_t>(1U));
        }
        ptr[i].pStencilInputAttachmentIndex = nullptr;
        if (src[start_index + i].pStencilInputAttachmentIndex) {
            ptr[i].pStencilInputAttachmentIndex = CopyArray(src[start_index + i].pStencilInputAttachmentIndex,
                                                            static_cast<uint64_t>(0U), static_cast<uint64_t>(1U));
        }
    }
    return ptr;
}

template <>
VkVideoEncodeInfoKHR* CommandRecorder::CopyArray<VkVideoEncodeInfoKHR>(const VkVideoEncodeInfoKHR* src,
                                                                       size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkVideoEncodeInfoKHR*>(m_allocator.Alloc(sizeof(VkVideoEncodeInfoKHR) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].flags = src[start_index + i].flags;
        ptr[i].dstBuffer = src[start_index + i].dstBuffer;
        ptr[i].dstBufferOffset = src[start_index + i].dstBufferOffset;
        ptr[i].dstBufferRange = src[start_index + i].dstBufferRange;
        ptr[i].srcPictureResource = src[start_index + i].srcPictureResource;
        ptr[i].pSetupReferenceSlot = nullptr;
        if (src[start_index + i].pSetupReferenceSlot) {
            ptr[i].pSetupReferenceSlot = CopyArray(src[start_index + i].pSetupReferenceSlot, static_cast<uint64_t>(0U),
                                                   static_cast<uint64_t>(1U));
        }
        ptr[i].referenceSlotCount = src[start_index + i].referenceSlotCount;
        ptr[i].pReferenceSlots = nullptr;
        if (src[start_index + i].pReferenceSlots) {
            ptr[i].pReferenceSlots = CopyArray(src[start_index + i].pReferenceSlots, static_cast<uint64_t>(0U),
                                               static_cast<uint64_t>(src[start_index + i].referenceSlotCount));
        }
        ptr[i].precedingExternallyEncodedBytes = src[start_index + i].precedingExternallyEncodedBytes;
    }
    return ptr;
}

template <>
VkBindDescriptorSetsInfoKHR* CommandRecorder::CopyArray<VkBindDescriptorSetsInfoKHR>(
    const VkBindDescriptorSetsInfoKHR* src, size_t start_index, size_t count) {
    auto ptr =
        reinterpret_cast<VkBindDescriptorSetsInfoKHR*>(m_allocator.Alloc(sizeof(VkBindDescriptorSetsInfoKHR) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].stageFlags = src[start_index + i].stageFlags;
        ptr[i].layout = src[start_index + i].layout;
        ptr[i].firstSet = src[start_index + i].firstSet;
        ptr[i].descriptorSetCount = src[start_index + i].descriptorSetCount;
        ptr[i].pDescriptorSets = nullptr;
        if (src[start_index + i].pDescriptorSets) {
            ptr[i].pDescriptorSets = CopyArray(src[start_index + i].pDescriptorSets, static_cast<uint64_t>(0U),
                                               static_cast<uint64_t>(src[start_index + i].descriptorSetCount));
        }
        ptr[i].dynamicOffsetCount = src[start_index + i].dynamicOffsetCount;
        ptr[i].pDynamicOffsets = nullptr;
        if (src[start_index + i].pDynamicOffsets) {
            ptr[i].pDynamicOffsets = CopyArray(src[start_index + i].pDynamicOffsets, static_cast<uint64_t>(0U),
                                               static_cast<uint64_t>(src[start_index + i].dynamicOffsetCount));
        }
    }
    return ptr;
}

template <>
VkPushConstantsInfoKHR* CommandRecorder::CopyArray<VkPushConstantsInfoKHR>(const VkPushConstantsInfoKHR* src,
                                                                           size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkPushConstantsInfoKHR*>(m_allocator.Alloc(sizeof(VkPushConstantsInfoKHR) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].layout = src[start_index + i].layout;
        ptr[i].stageFlags = src[start_index + i].stageFlags;
        ptr[i].offset = src[start_index + i].offset;
        ptr[i].size = src[start_index + i].size;
        ptr[i].pValues = reinterpret_cast<const void*>(
            CopyArray(reinterpret_cast<const uint8_t*>(src[start_index + i].pValues), static_cast<uint64_t>(0U),
                      static_cast<uint64_t>(src[start_index + i].size)));
    }
    return ptr;
}

template <>
VkPushDescriptorSetInfoKHR* CommandRecorder::CopyArray<VkPushDescriptorSetInfoKHR>(
    const VkPushDescriptorSetInfoKHR* src, size_t start_index, size_t count) {
    auto ptr =
        reinterpret_cast<VkPushDescriptorSetInfoKHR*>(m_allocator.Alloc(sizeof(VkPushDescriptorSetInfoKHR) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].stageFlags = src[start_index + i].stageFlags;
        ptr[i].layout = src[start_index + i].layout;
        ptr[i].set = src[start_index + i].set;
        ptr[i].descriptorWriteCount = src[start_index + i].descriptorWriteCount;
        ptr[i].pDescriptorWrites = nullptr;
        if (src[start_index + i].pDescriptorWrites) {
            ptr[i].pDescriptorWrites = CopyArray(src[start_index + i].pDescriptorWrites, static_cast<uint64_t>(0U),
                                                 static_cast<uint64_t>(src[start_index + i].descriptorWriteCount));
        }
    }
    return ptr;
}

template <>
VkPushDescriptorSetWithTemplateInfoKHR* CommandRecorder::CopyArray<VkPushDescriptorSetWithTemplateInfoKHR>(
    const VkPushDescriptorSetWithTemplateInfoKHR* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkPushDescriptorSetWithTemplateInfoKHR*>(
        m_allocator.Alloc(sizeof(VkPushDescriptorSetWithTemplateInfoKHR) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].descriptorUpdateTemplate = src[start_index + i].descriptorUpdateTemplate;
        ptr[i].layout = src[start_index + i].layout;
        ptr[i].set = src[start_index + i].set;
        ptr[i].pData = src[start_index + i].pData;
    }
    return ptr;
}

template <>
VkSetDescriptorBufferOffsetsInfoEXT* CommandRecorder::CopyArray<VkSetDescriptorBufferOffsetsInfoEXT>(
    const VkSetDescriptorBufferOffsetsInfoEXT* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkSetDescriptorBufferOffsetsInfoEXT*>(
        m_allocator.Alloc(sizeof(VkSetDescriptorBufferOffsetsInfoEXT) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].stageFlags = src[start_index + i].stageFlags;
        ptr[i].layout = src[start_index + i].layout;
        ptr[i].firstSet = src[start_index + i].firstSet;
        ptr[i].setCount = src[start_index + i].setCount;
        ptr[i].pBufferIndices = nullptr;
        if (src[start_index + i].pBufferIndices) {
            ptr[i].pBufferIndices = CopyArray(src[start_index + i].pBufferIndices, static_cast<uint64_t>(0U),
                                              static_cast<uint64_t>(src[start_index + i].setCount));
        }
        ptr[i].pOffsets = nullptr;
        if (src[start_index + i].pOffsets) {
            ptr[i].pOffsets = CopyArray(src[start_index + i].pOffsets, static_cast<uint64_t>(0U),
                                        static_cast<uint64_t>(src[start_index + i].setCount));
        }
    }
    return ptr;
}

template <>
VkBindDescriptorBufferEmbeddedSamplersInfoEXT*
CommandRecorder::CopyArray<VkBindDescriptorBufferEmbeddedSamplersInfoEXT>(
    const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkBindDescriptorBufferEmbeddedSamplersInfoEXT*>(
        m_allocator.Alloc(sizeof(VkBindDescriptorBufferEmbeddedSamplersInfoEXT) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].stageFlags = src[start_index + i].stageFlags;
        ptr[i].layout = src[start_index + i].layout;
        ptr[i].set = src[start_index + i].set;
    }
    return ptr;
}

template <>
VkDebugMarkerMarkerInfoEXT* CommandRecorder::CopyArray<VkDebugMarkerMarkerInfoEXT>(
    const VkDebugMarkerMarkerInfoEXT* src, size_t start_index, size_t count) {
    auto ptr =
        reinterpret_cast<VkDebugMarkerMarkerInfoEXT*>(m_allocator.Alloc(sizeof(VkDebugMarkerMarkerInfoEXT) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].pMarkerName = nullptr;
        if (src[start_index + i].pMarkerName) {
            ptr[i].pMarkerName =
                CopyArray<>(src[start_index + i].pMarkerName, 0, strlen(src[start_index + i].pMarkerName) + 1);
        }
        for (uint32_t j = 0; j < 4; ++j) {
            ptr[i].color[j] = src[start_index + i].color[j];
        }
    }
    return ptr;
}

template <>
VkCuLaunchInfoNVX* CommandRecorder::CopyArray<VkCuLaunchInfoNVX>(const VkCuLaunchInfoNVX* src, size_t start_index,
                                                                 size_t count) {
    auto ptr = reinterpret_cast<VkCuLaunchInfoNVX*>(m_allocator.Alloc(sizeof(VkCuLaunchInfoNVX) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].function = src[start_index + i].function;
        ptr[i].gridDimX = src[start_index + i].gridDimX;
        ptr[i].gridDimY = src[start_index + i].gridDimY;
        ptr[i].gridDimZ = src[start_index + i].gridDimZ;
        ptr[i].blockDimX = src[start_index + i].blockDimX;
        ptr[i].blockDimY = src[start_index + i].blockDimY;
        ptr[i].blockDimZ = src[start_index + i].blockDimZ;
        ptr[i].sharedMemBytes = src[start_index + i].sharedMemBytes;
        ptr[i].paramCount = src[start_index + i].paramCount;
        ptr[i].pParams = reinterpret_cast<const void* const*>(
            CopyArray(reinterpret_cast<const uint8_t*>(src[start_index + i].pParams), static_cast<uint64_t>(0U),
                      static_cast<uint64_t>(src[start_index + i].paramCount)));
        ptr[i].extraCount = src[start_index + i].extraCount;
        ptr[i].pExtras = reinterpret_cast<const void* const*>(
            CopyArray(reinterpret_cast<const uint8_t*>(src[start_index + i].pExtras), static_cast<uint64_t>(0U),
                      static_cast<uint64_t>(src[start_index + i].extraCount)));
    }
    return ptr;
}

template <>
VkConditionalRenderingBeginInfoEXT* CommandRecorder::CopyArray<VkConditionalRenderingBeginInfoEXT>(
    const VkConditionalRenderingBeginInfoEXT* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkConditionalRenderingBeginInfoEXT*>(
        m_allocator.Alloc(sizeof(VkConditionalRenderingBeginInfoEXT) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].buffer = src[start_index + i].buffer;
        ptr[i].offset = src[start_index + i].offset;
        ptr[i].flags = src[start_index + i].flags;
    }
    return ptr;
}

template <>
VkViewportWScalingNV* CommandRecorder::CopyArray<VkViewportWScalingNV>(const VkViewportWScalingNV* src,
                                                                       size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkViewportWScalingNV*>(m_allocator.Alloc(sizeof(VkViewportWScalingNV) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].xcoeff = src[start_index + i].xcoeff;
        ptr[i].ycoeff = src[start_index + i].ycoeff;
    }
    return ptr;
}

template <>
VkViewportSwizzleNV* CommandRecorder::CopyArray<VkViewportSwizzleNV>(const VkViewportSwizzleNV* src, size_t start_index,
                                                                     size_t count) {
    auto ptr = reinterpret_cast<VkViewportSwizzleNV*>(m_allocator.Alloc(sizeof(VkViewportSwizzleNV) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].x = src[start_index + i].x;
        ptr[i].y = src[start_index + i].y;
        ptr[i].z = src[start_index + i].z;
        ptr[i].w = src[start_index + i].w;
    }
    return ptr;
}

template <>
VkDebugUtilsLabelEXT* CommandRecorder::CopyArray<VkDebugUtilsLabelEXT>(const VkDebugUtilsLabelEXT* src,
                                                                       size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkDebugUtilsLabelEXT*>(m_allocator.Alloc(sizeof(VkDebugUtilsLabelEXT) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].pLabelName = nullptr;
        if (src[start_index + i].pLabelName) {
            ptr[i].pLabelName =
                CopyArray<>(src[start_index + i].pLabelName, 0, strlen(src[start_index + i].pLabelName) + 1);
        }
        for (uint32_t j = 0; j < 4; ++j) {
            ptr[i].color[j] = src[start_index + i].color[j];
        }
    }
    return ptr;
}

#ifdef VK_ENABLE_BETA_EXTENSIONS
template <>
VkDeviceOrHostAddressConstAMDX* CommandRecorder::CopyArray<VkDeviceOrHostAddressConstAMDX>(
    const VkDeviceOrHostAddressConstAMDX* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkDeviceOrHostAddressConstAMDX*>(
        m_allocator.Alloc(sizeof(VkDeviceOrHostAddressConstAMDX) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].deviceAddress = src[start_index + i].deviceAddress;
        ptr[i].hostAddress = src[start_index + i].hostAddress;
    }
    return ptr;
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
template <>
VkDispatchGraphCountInfoAMDX* CommandRecorder::CopyArray<VkDispatchGraphCountInfoAMDX>(
    const VkDispatchGraphCountInfoAMDX* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkDispatchGraphCountInfoAMDX*>(
        m_allocator.Alloc(sizeof(VkDispatchGraphCountInfoAMDX) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].count = src[start_index + i].count;
        ptr[i].infos = src[start_index + i].infos;
        ptr[i].stride = src[start_index + i].stride;
    }
    return ptr;
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

template <>
VkSampleLocationEXT* CommandRecorder::CopyArray<VkSampleLocationEXT>(const VkSampleLocationEXT* src, size_t start_index,
                                                                     size_t count) {
    auto ptr = reinterpret_cast<VkSampleLocationEXT*>(m_allocator.Alloc(sizeof(VkSampleLocationEXT) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].x = src[start_index + i].x;
        ptr[i].y = src[start_index + i].y;
    }
    return ptr;
}

template <>
VkSampleLocationsInfoEXT* CommandRecorder::CopyArray<VkSampleLocationsInfoEXT>(const VkSampleLocationsInfoEXT* src,
                                                                               size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkSampleLocationsInfoEXT*>(m_allocator.Alloc(sizeof(VkSampleLocationsInfoEXT) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].sampleLocationsPerPixel = src[start_index + i].sampleLocationsPerPixel;
        ptr[i].sampleLocationGridSize = src[start_index + i].sampleLocationGridSize;
        ptr[i].sampleLocationsCount = src[start_index + i].sampleLocationsCount;
        ptr[i].pSampleLocations = nullptr;
        if (src[start_index + i].pSampleLocations) {
            ptr[i].pSampleLocations = CopyArray(src[start_index + i].pSampleLocations, static_cast<uint64_t>(0U),
                                                static_cast<uint64_t>(src[start_index + i].sampleLocationsCount));
        }
    }
    return ptr;
}

template <>
VkShadingRatePaletteNV* CommandRecorder::CopyArray<VkShadingRatePaletteNV>(const VkShadingRatePaletteNV* src,
                                                                           size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkShadingRatePaletteNV*>(m_allocator.Alloc(sizeof(VkShadingRatePaletteNV) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].shadingRatePaletteEntryCount = src[start_index + i].shadingRatePaletteEntryCount;
        ptr[i].pShadingRatePaletteEntries = nullptr;
        if (src[start_index + i].pShadingRatePaletteEntries) {
            ptr[i].pShadingRatePaletteEntries =
                CopyArray(src[start_index + i].pShadingRatePaletteEntries, static_cast<uint64_t>(0U),
                          static_cast<uint64_t>(src[start_index + i].shadingRatePaletteEntryCount));
        }
    }
    return ptr;
}

template <>
VkCoarseSampleLocationNV* CommandRecorder::CopyArray<VkCoarseSampleLocationNV>(const VkCoarseSampleLocationNV* src,
                                                                               size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkCoarseSampleLocationNV*>(m_allocator.Alloc(sizeof(VkCoarseSampleLocationNV) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].pixelX = src[start_index + i].pixelX;
        ptr[i].pixelY = src[start_index + i].pixelY;
        ptr[i].sample = src[start_index + i].sample;
    }
    return ptr;
}

template <>
VkCoarseSampleOrderCustomNV* CommandRecorder::CopyArray<VkCoarseSampleOrderCustomNV>(
    const VkCoarseSampleOrderCustomNV* src, size_t start_index, size_t count) {
    auto ptr =
        reinterpret_cast<VkCoarseSampleOrderCustomNV*>(m_allocator.Alloc(sizeof(VkCoarseSampleOrderCustomNV) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].shadingRate = src[start_index + i].shadingRate;
        ptr[i].sampleCount = src[start_index + i].sampleCount;
        ptr[i].sampleLocationCount = src[start_index + i].sampleLocationCount;
        ptr[i].pSampleLocations = nullptr;
        if (src[start_index + i].pSampleLocations) {
            ptr[i].pSampleLocations = CopyArray(src[start_index + i].pSampleLocations, static_cast<uint64_t>(0U),
                                                static_cast<uint64_t>(src[start_index + i].sampleLocationCount));
        }
    }
    return ptr;
}

template <>
VkGeometryNV* CommandRecorder::CopyArray<VkGeometryNV>(const VkGeometryNV* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkGeometryNV*>(m_allocator.Alloc(sizeof(VkGeometryNV) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].geometryType = src[start_index + i].geometryType;
        ptr[i].geometry = src[start_index + i].geometry;
        ptr[i].flags = src[start_index + i].flags;
    }
    return ptr;
}

template <>
VkAccelerationStructureInfoNV* CommandRecorder::CopyArray<VkAccelerationStructureInfoNV>(
    const VkAccelerationStructureInfoNV* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkAccelerationStructureInfoNV*>(
        m_allocator.Alloc(sizeof(VkAccelerationStructureInfoNV) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].type = src[start_index + i].type;
        ptr[i].flags = src[start_index + i].flags;
        ptr[i].instanceCount = src[start_index + i].instanceCount;
        ptr[i].geometryCount = src[start_index + i].geometryCount;
        ptr[i].pGeometries = nullptr;
        if (src[start_index + i].pGeometries) {
            ptr[i].pGeometries = CopyArray(src[start_index + i].pGeometries, static_cast<uint64_t>(0U),
                                           static_cast<uint64_t>(src[start_index + i].geometryCount));
        }
    }
    return ptr;
}

template <>
VkPerformanceMarkerInfoINTEL* CommandRecorder::CopyArray<VkPerformanceMarkerInfoINTEL>(
    const VkPerformanceMarkerInfoINTEL* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkPerformanceMarkerInfoINTEL*>(
        m_allocator.Alloc(sizeof(VkPerformanceMarkerInfoINTEL) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].marker = src[start_index + i].marker;
    }
    return ptr;
}

template <>
VkPerformanceStreamMarkerInfoINTEL* CommandRecorder::CopyArray<VkPerformanceStreamMarkerInfoINTEL>(
    const VkPerformanceStreamMarkerInfoINTEL* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkPerformanceStreamMarkerInfoINTEL*>(
        m_allocator.Alloc(sizeof(VkPerformanceStreamMarkerInfoINTEL) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].marker = src[start_index + i].marker;
    }
    return ptr;
}

template <>
VkPerformanceOverrideInfoINTEL* CommandRecorder::CopyArray<VkPerformanceOverrideInfoINTEL>(
    const VkPerformanceOverrideInfoINTEL* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkPerformanceOverrideInfoINTEL*>(
        m_allocator.Alloc(sizeof(VkPerformanceOverrideInfoINTEL) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].type = src[start_index + i].type;
        ptr[i].enable = src[start_index + i].enable;
        ptr[i].parameter = src[start_index + i].parameter;
    }
    return ptr;
}

template <>
VkIndirectCommandsStreamNV* CommandRecorder::CopyArray<VkIndirectCommandsStreamNV>(
    const VkIndirectCommandsStreamNV* src, size_t start_index, size_t count) {
    auto ptr =
        reinterpret_cast<VkIndirectCommandsStreamNV*>(m_allocator.Alloc(sizeof(VkIndirectCommandsStreamNV) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].buffer = src[start_index + i].buffer;
        ptr[i].offset = src[start_index + i].offset;
    }
    return ptr;
}

template <>
VkGeneratedCommandsInfoNV* CommandRecorder::CopyArray<VkGeneratedCommandsInfoNV>(const VkGeneratedCommandsInfoNV* src,
                                                                                 size_t start_index, size_t count) {
    auto ptr =
        reinterpret_cast<VkGeneratedCommandsInfoNV*>(m_allocator.Alloc(sizeof(VkGeneratedCommandsInfoNV) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].pipelineBindPoint = src[start_index + i].pipelineBindPoint;
        ptr[i].pipeline = src[start_index + i].pipeline;
        ptr[i].indirectCommandsLayout = src[start_index + i].indirectCommandsLayout;
        ptr[i].streamCount = src[start_index + i].streamCount;
        ptr[i].pStreams = nullptr;
        if (src[start_index + i].pStreams) {
            ptr[i].pStreams = CopyArray(src[start_index + i].pStreams, static_cast<uint64_t>(0U),
                                        static_cast<uint64_t>(src[start_index + i].streamCount));
        }
        ptr[i].sequencesCount = src[start_index + i].sequencesCount;
        ptr[i].preprocessBuffer = src[start_index + i].preprocessBuffer;
        ptr[i].preprocessOffset = src[start_index + i].preprocessOffset;
        ptr[i].preprocessSize = src[start_index + i].preprocessSize;
        ptr[i].sequencesCountBuffer = src[start_index + i].sequencesCountBuffer;
        ptr[i].sequencesCountOffset = src[start_index + i].sequencesCountOffset;
        ptr[i].sequencesIndexBuffer = src[start_index + i].sequencesIndexBuffer;
        ptr[i].sequencesIndexOffset = src[start_index + i].sequencesIndexOffset;
    }
    return ptr;
}

template <>
VkDepthBiasInfoEXT* CommandRecorder::CopyArray<VkDepthBiasInfoEXT>(const VkDepthBiasInfoEXT* src, size_t start_index,
                                                                   size_t count) {
    auto ptr = reinterpret_cast<VkDepthBiasInfoEXT*>(m_allocator.Alloc(sizeof(VkDepthBiasInfoEXT) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].depthBiasConstantFactor = src[start_index + i].depthBiasConstantFactor;
        ptr[i].depthBiasClamp = src[start_index + i].depthBiasClamp;
        ptr[i].depthBiasSlopeFactor = src[start_index + i].depthBiasSlopeFactor;
    }
    return ptr;
}

template <>
VkCudaLaunchInfoNV* CommandRecorder::CopyArray<VkCudaLaunchInfoNV>(const VkCudaLaunchInfoNV* src, size_t start_index,
                                                                   size_t count) {
    auto ptr = reinterpret_cast<VkCudaLaunchInfoNV*>(m_allocator.Alloc(sizeof(VkCudaLaunchInfoNV) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].function = src[start_index + i].function;
        ptr[i].gridDimX = src[start_index + i].gridDimX;
        ptr[i].gridDimY = src[start_index + i].gridDimY;
        ptr[i].gridDimZ = src[start_index + i].gridDimZ;
        ptr[i].blockDimX = src[start_index + i].blockDimX;
        ptr[i].blockDimY = src[start_index + i].blockDimY;
        ptr[i].blockDimZ = src[start_index + i].blockDimZ;
        ptr[i].sharedMemBytes = src[start_index + i].sharedMemBytes;
        ptr[i].paramCount = src[start_index + i].paramCount;
        ptr[i].pParams = reinterpret_cast<const void* const*>(
            CopyArray(reinterpret_cast<const uint8_t*>(src[start_index + i].pParams), static_cast<uint64_t>(0U),
                      static_cast<uint64_t>(src[start_index + i].paramCount)));
        ptr[i].extraCount = src[start_index + i].extraCount;
        ptr[i].pExtras = reinterpret_cast<const void* const*>(
            CopyArray(reinterpret_cast<const uint8_t*>(src[start_index + i].pExtras), static_cast<uint64_t>(0U),
                      static_cast<uint64_t>(src[start_index + i].extraCount)));
    }
    return ptr;
}

template <>
VkDescriptorBufferBindingInfoEXT* CommandRecorder::CopyArray<VkDescriptorBufferBindingInfoEXT>(
    const VkDescriptorBufferBindingInfoEXT* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkDescriptorBufferBindingInfoEXT*>(
        m_allocator.Alloc(sizeof(VkDescriptorBufferBindingInfoEXT) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].address = src[start_index + i].address;
        ptr[i].usage = src[start_index + i].usage;
    }
    return ptr;
}

template <>
VkDeviceOrHostAddressConstKHR* CommandRecorder::CopyArray<VkDeviceOrHostAddressConstKHR>(
    const VkDeviceOrHostAddressConstKHR* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkDeviceOrHostAddressConstKHR*>(
        m_allocator.Alloc(sizeof(VkDeviceOrHostAddressConstKHR) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].deviceAddress = src[start_index + i].deviceAddress;
        ptr[i].hostAddress = src[start_index + i].hostAddress;
    }
    return ptr;
}

template <>
VkVertexInputBindingDescription2EXT* CommandRecorder::CopyArray<VkVertexInputBindingDescription2EXT>(
    const VkVertexInputBindingDescription2EXT* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkVertexInputBindingDescription2EXT*>(
        m_allocator.Alloc(sizeof(VkVertexInputBindingDescription2EXT) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].binding = src[start_index + i].binding;
        ptr[i].stride = src[start_index + i].stride;
        ptr[i].inputRate = src[start_index + i].inputRate;
        ptr[i].divisor = src[start_index + i].divisor;
    }
    return ptr;
}

template <>
VkVertexInputAttributeDescription2EXT* CommandRecorder::CopyArray<VkVertexInputAttributeDescription2EXT>(
    const VkVertexInputAttributeDescription2EXT* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkVertexInputAttributeDescription2EXT*>(
        m_allocator.Alloc(sizeof(VkVertexInputAttributeDescription2EXT) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].location = src[start_index + i].location;
        ptr[i].binding = src[start_index + i].binding;
        ptr[i].format = src[start_index + i].format;
        ptr[i].offset = src[start_index + i].offset;
    }
    return ptr;
}

template <>
VkMultiDrawInfoEXT* CommandRecorder::CopyArray<VkMultiDrawInfoEXT>(const VkMultiDrawInfoEXT* src, size_t start_index,
                                                                   size_t count) {
    auto ptr = reinterpret_cast<VkMultiDrawInfoEXT*>(m_allocator.Alloc(sizeof(VkMultiDrawInfoEXT) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].firstVertex = src[start_index + i].firstVertex;
        ptr[i].vertexCount = src[start_index + i].vertexCount;
    }
    return ptr;
}

template <>
VkMultiDrawIndexedInfoEXT* CommandRecorder::CopyArray<VkMultiDrawIndexedInfoEXT>(const VkMultiDrawIndexedInfoEXT* src,
                                                                                 size_t start_index, size_t count) {
    auto ptr =
        reinterpret_cast<VkMultiDrawIndexedInfoEXT*>(m_allocator.Alloc(sizeof(VkMultiDrawIndexedInfoEXT) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].firstIndex = src[start_index + i].firstIndex;
        ptr[i].indexCount = src[start_index + i].indexCount;
        ptr[i].vertexOffset = src[start_index + i].vertexOffset;
    }
    return ptr;
}

template <>
VkMicromapUsageEXT* CommandRecorder::CopyArray<VkMicromapUsageEXT>(const VkMicromapUsageEXT* src, size_t start_index,
                                                                   size_t count) {
    auto ptr = reinterpret_cast<VkMicromapUsageEXT*>(m_allocator.Alloc(sizeof(VkMicromapUsageEXT) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].count = src[start_index + i].count;
        ptr[i].subdivisionLevel = src[start_index + i].subdivisionLevel;
        ptr[i].format = src[start_index + i].format;
    }
    return ptr;
}

template <>
VkDeviceOrHostAddressKHR* CommandRecorder::CopyArray<VkDeviceOrHostAddressKHR>(const VkDeviceOrHostAddressKHR* src,
                                                                               size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkDeviceOrHostAddressKHR*>(m_allocator.Alloc(sizeof(VkDeviceOrHostAddressKHR) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].deviceAddress = src[start_index + i].deviceAddress;
        ptr[i].hostAddress = src[start_index + i].hostAddress;
    }
    return ptr;
}

template <>
VkMicromapBuildInfoEXT* CommandRecorder::CopyArray<VkMicromapBuildInfoEXT>(const VkMicromapBuildInfoEXT* src,
                                                                           size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkMicromapBuildInfoEXT*>(m_allocator.Alloc(sizeof(VkMicromapBuildInfoEXT) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].type = src[start_index + i].type;
        ptr[i].flags = src[start_index + i].flags;
        ptr[i].mode = src[start_index + i].mode;
        ptr[i].dstMicromap = src[start_index + i].dstMicromap;
        ptr[i].usageCountsCount = src[start_index + i].usageCountsCount;
        ptr[i].pUsageCounts = nullptr;
        if (src[start_index + i].pUsageCounts) {
            ptr[i].pUsageCounts = CopyArray(src[start_index + i].pUsageCounts, static_cast<uint64_t>(0U),
                                            static_cast<uint64_t>(src[start_index + i].usageCountsCount));
        }
        ptr[i].ppUsageCounts = nullptr;
        if (src[start_index + i].ppUsageCounts) {
            ptr[i].ppUsageCounts = CopyArray(src[start_index + i].ppUsageCounts, static_cast<uint64_t>(0U),
                                             static_cast<uint64_t>(src[start_index + i].usageCountsCount));
            for (uint64_t j = 0; j < uint64_t(src[start_index + i].usageCountsCount); j++) {
                const_cast<VkMicromapUsageEXT**>(ptr[i].ppUsageCounts)[j] = CopyArray(
                    src[start_index + i].ppUsageCounts[j], static_cast<uint64_t>(0U), static_cast<uint64_t>(1));
            }
        }
        ptr[i].data = src[start_index + i].data;
        ptr[i].scratchData = src[start_index + i].scratchData;
        ptr[i].triangleArray = src[start_index + i].triangleArray;
        ptr[i].triangleArrayStride = src[start_index + i].triangleArrayStride;
    }
    return ptr;
}

template <>
VkCopyMicromapToMemoryInfoEXT* CommandRecorder::CopyArray<VkCopyMicromapToMemoryInfoEXT>(
    const VkCopyMicromapToMemoryInfoEXT* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkCopyMicromapToMemoryInfoEXT*>(
        m_allocator.Alloc(sizeof(VkCopyMicromapToMemoryInfoEXT) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].src = src[start_index + i].src;
        ptr[i].dst = src[start_index + i].dst;
        ptr[i].mode = src[start_index + i].mode;
    }
    return ptr;
}

template <>
VkCopyMemoryToMicromapInfoEXT* CommandRecorder::CopyArray<VkCopyMemoryToMicromapInfoEXT>(
    const VkCopyMemoryToMicromapInfoEXT* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkCopyMemoryToMicromapInfoEXT*>(
        m_allocator.Alloc(sizeof(VkCopyMemoryToMicromapInfoEXT) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].src = src[start_index + i].src;
        ptr[i].dst = src[start_index + i].dst;
        ptr[i].mode = src[start_index + i].mode;
    }
    return ptr;
}

template <>
VkCopyMicromapInfoEXT* CommandRecorder::CopyArray<VkCopyMicromapInfoEXT>(const VkCopyMicromapInfoEXT* src,
                                                                         size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkCopyMicromapInfoEXT*>(m_allocator.Alloc(sizeof(VkCopyMicromapInfoEXT) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].src = src[start_index + i].src;
        ptr[i].dst = src[start_index + i].dst;
        ptr[i].mode = src[start_index + i].mode;
    }
    return ptr;
}

template <>
VkDecompressMemoryRegionNV* CommandRecorder::CopyArray<VkDecompressMemoryRegionNV>(
    const VkDecompressMemoryRegionNV* src, size_t start_index, size_t count) {
    auto ptr =
        reinterpret_cast<VkDecompressMemoryRegionNV*>(m_allocator.Alloc(sizeof(VkDecompressMemoryRegionNV) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].srcAddress = src[start_index + i].srcAddress;
        ptr[i].dstAddress = src[start_index + i].dstAddress;
        ptr[i].compressedSize = src[start_index + i].compressedSize;
        ptr[i].decompressedSize = src[start_index + i].decompressedSize;
        ptr[i].decompressionMethod = src[start_index + i].decompressionMethod;
    }
    return ptr;
}

template <>
VkColorBlendEquationEXT* CommandRecorder::CopyArray<VkColorBlendEquationEXT>(const VkColorBlendEquationEXT* src,
                                                                             size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkColorBlendEquationEXT*>(m_allocator.Alloc(sizeof(VkColorBlendEquationEXT) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].srcColorBlendFactor = src[start_index + i].srcColorBlendFactor;
        ptr[i].dstColorBlendFactor = src[start_index + i].dstColorBlendFactor;
        ptr[i].colorBlendOp = src[start_index + i].colorBlendOp;
        ptr[i].srcAlphaBlendFactor = src[start_index + i].srcAlphaBlendFactor;
        ptr[i].dstAlphaBlendFactor = src[start_index + i].dstAlphaBlendFactor;
        ptr[i].alphaBlendOp = src[start_index + i].alphaBlendOp;
    }
    return ptr;
}

template <>
VkColorBlendAdvancedEXT* CommandRecorder::CopyArray<VkColorBlendAdvancedEXT>(const VkColorBlendAdvancedEXT* src,
                                                                             size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkColorBlendAdvancedEXT*>(m_allocator.Alloc(sizeof(VkColorBlendAdvancedEXT) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].advancedBlendOp = src[start_index + i].advancedBlendOp;
        ptr[i].srcPremultiplied = src[start_index + i].srcPremultiplied;
        ptr[i].dstPremultiplied = src[start_index + i].dstPremultiplied;
        ptr[i].blendOverlap = src[start_index + i].blendOverlap;
        ptr[i].clampResults = src[start_index + i].clampResults;
    }
    return ptr;
}

template <>
VkOpticalFlowExecuteInfoNV* CommandRecorder::CopyArray<VkOpticalFlowExecuteInfoNV>(
    const VkOpticalFlowExecuteInfoNV* src, size_t start_index, size_t count) {
    auto ptr =
        reinterpret_cast<VkOpticalFlowExecuteInfoNV*>(m_allocator.Alloc(sizeof(VkOpticalFlowExecuteInfoNV) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].flags = src[start_index + i].flags;
        ptr[i].regionCount = src[start_index + i].regionCount;
        ptr[i].pRegions = nullptr;
        if (src[start_index + i].pRegions) {
            ptr[i].pRegions = CopyArray(src[start_index + i].pRegions, static_cast<uint64_t>(0U),
                                        static_cast<uint64_t>(src[start_index + i].regionCount));
        }
    }
    return ptr;
}

template <>
VkDepthClampRangeEXT* CommandRecorder::CopyArray<VkDepthClampRangeEXT>(const VkDepthClampRangeEXT* src,
                                                                       size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkDepthClampRangeEXT*>(m_allocator.Alloc(sizeof(VkDepthClampRangeEXT) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].minDepthClamp = src[start_index + i].minDepthClamp;
        ptr[i].maxDepthClamp = src[start_index + i].maxDepthClamp;
    }
    return ptr;
}

template <>
VkGeneratedCommandsInfoEXT* CommandRecorder::CopyArray<VkGeneratedCommandsInfoEXT>(
    const VkGeneratedCommandsInfoEXT* src, size_t start_index, size_t count) {
    auto ptr =
        reinterpret_cast<VkGeneratedCommandsInfoEXT*>(m_allocator.Alloc(sizeof(VkGeneratedCommandsInfoEXT) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].shaderStages = src[start_index + i].shaderStages;
        ptr[i].indirectExecutionSet = src[start_index + i].indirectExecutionSet;
        ptr[i].indirectCommandsLayout = src[start_index + i].indirectCommandsLayout;
        ptr[i].indirectAddress = src[start_index + i].indirectAddress;
        ptr[i].indirectAddressSize = src[start_index + i].indirectAddressSize;
        ptr[i].preprocessAddress = src[start_index + i].preprocessAddress;
        ptr[i].preprocessSize = src[start_index + i].preprocessSize;
        ptr[i].maxSequenceCount = src[start_index + i].maxSequenceCount;
        ptr[i].sequenceCountAddress = src[start_index + i].sequenceCountAddress;
        ptr[i].maxDrawCount = src[start_index + i].maxDrawCount;
    }
    return ptr;
}

template <>
VkAccelerationStructureBuildRangeInfoKHR* CommandRecorder::CopyArray<VkAccelerationStructureBuildRangeInfoKHR>(
    const VkAccelerationStructureBuildRangeInfoKHR* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkAccelerationStructureBuildRangeInfoKHR*>(
        m_allocator.Alloc(sizeof(VkAccelerationStructureBuildRangeInfoKHR) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].primitiveCount = src[start_index + i].primitiveCount;
        ptr[i].primitiveOffset = src[start_index + i].primitiveOffset;
        ptr[i].firstVertex = src[start_index + i].firstVertex;
        ptr[i].transformOffset = src[start_index + i].transformOffset;
    }
    return ptr;
}

template <>
VkAccelerationStructureGeometryKHR* CommandRecorder::CopyArray<VkAccelerationStructureGeometryKHR>(
    const VkAccelerationStructureGeometryKHR* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkAccelerationStructureGeometryKHR*>(
        m_allocator.Alloc(sizeof(VkAccelerationStructureGeometryKHR) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].geometryType = src[start_index + i].geometryType;
        ptr[i].geometry = src[start_index + i].geometry;
        ptr[i].flags = src[start_index + i].flags;
    }
    return ptr;
}

template <>
VkAccelerationStructureBuildGeometryInfoKHR* CommandRecorder::CopyArray<VkAccelerationStructureBuildGeometryInfoKHR>(
    const VkAccelerationStructureBuildGeometryInfoKHR* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkAccelerationStructureBuildGeometryInfoKHR*>(
        m_allocator.Alloc(sizeof(VkAccelerationStructureBuildGeometryInfoKHR) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].type = src[start_index + i].type;
        ptr[i].flags = src[start_index + i].flags;
        ptr[i].mode = src[start_index + i].mode;
        ptr[i].srcAccelerationStructure = src[start_index + i].srcAccelerationStructure;
        ptr[i].dstAccelerationStructure = src[start_index + i].dstAccelerationStructure;
        ptr[i].geometryCount = src[start_index + i].geometryCount;
        ptr[i].pGeometries = nullptr;
        if (src[start_index + i].pGeometries) {
            ptr[i].pGeometries = CopyArray(src[start_index + i].pGeometries, static_cast<uint64_t>(0U),
                                           static_cast<uint64_t>(src[start_index + i].geometryCount));
        }
        ptr[i].ppGeometries = nullptr;
        if (src[start_index + i].ppGeometries) {
            ptr[i].ppGeometries = CopyArray(src[start_index + i].ppGeometries, static_cast<uint64_t>(0U),
                                            static_cast<uint64_t>(src[start_index + i].geometryCount));
            for (uint64_t j = 0; j < uint64_t(src[start_index + i].geometryCount); j++) {
                const_cast<VkAccelerationStructureGeometryKHR**>(ptr[i].ppGeometries)[j] = CopyArray(
                    src[start_index + i].ppGeometries[j], static_cast<uint64_t>(0U), static_cast<uint64_t>(1));
            }
        }
        ptr[i].scratchData = src[start_index + i].scratchData;
    }
    return ptr;
}

template <>
VkCopyAccelerationStructureToMemoryInfoKHR* CommandRecorder::CopyArray<VkCopyAccelerationStructureToMemoryInfoKHR>(
    const VkCopyAccelerationStructureToMemoryInfoKHR* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkCopyAccelerationStructureToMemoryInfoKHR*>(
        m_allocator.Alloc(sizeof(VkCopyAccelerationStructureToMemoryInfoKHR) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].src = src[start_index + i].src;
        ptr[i].dst = src[start_index + i].dst;
        ptr[i].mode = src[start_index + i].mode;
    }
    return ptr;
}

template <>
VkCopyMemoryToAccelerationStructureInfoKHR* CommandRecorder::CopyArray<VkCopyMemoryToAccelerationStructureInfoKHR>(
    const VkCopyMemoryToAccelerationStructureInfoKHR* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkCopyMemoryToAccelerationStructureInfoKHR*>(
        m_allocator.Alloc(sizeof(VkCopyMemoryToAccelerationStructureInfoKHR) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].src = src[start_index + i].src;
        ptr[i].dst = src[start_index + i].dst;
        ptr[i].mode = src[start_index + i].mode;
    }
    return ptr;
}

template <>
VkCopyAccelerationStructureInfoKHR* CommandRecorder::CopyArray<VkCopyAccelerationStructureInfoKHR>(
    const VkCopyAccelerationStructureInfoKHR* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkCopyAccelerationStructureInfoKHR*>(
        m_allocator.Alloc(sizeof(VkCopyAccelerationStructureInfoKHR) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].sType = src[start_index + i].sType;
        ptr[i].pNext = nullptr;  // pNext deep copy not implemented
        ptr[i].src = src[start_index + i].src;
        ptr[i].dst = src[start_index + i].dst;
        ptr[i].mode = src[start_index + i].mode;
    }
    return ptr;
}

template <>
VkStridedDeviceAddressRegionKHR* CommandRecorder::CopyArray<VkStridedDeviceAddressRegionKHR>(
    const VkStridedDeviceAddressRegionKHR* src, size_t start_index, size_t count) {
    auto ptr = reinterpret_cast<VkStridedDeviceAddressRegionKHR*>(
        m_allocator.Alloc(sizeof(VkStridedDeviceAddressRegionKHR) * count));
    for (uint64_t i = 0; i < count; ++i) {
        ptr[i].deviceAddress = src[start_index + i].deviceAddress;
        ptr[i].stride = src[start_index + i].stride;
        ptr[i].size = src[start_index + i].size;
    }
    return ptr;
}

BeginCommandBufferArgs* CommandRecorder::RecordBeginCommandBuffer(VkCommandBuffer commandBuffer,
                                                                  const VkCommandBufferBeginInfo* pBeginInfo) {
    auto* args = Alloc<BeginCommandBufferArgs>();
    args->commandBuffer = commandBuffer;
    if (pBeginInfo) {
        args->pBeginInfo = CopyArray(pBeginInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

EndCommandBufferArgs* CommandRecorder::RecordEndCommandBuffer(VkCommandBuffer commandBuffer) {
    auto* args = Alloc<EndCommandBufferArgs>();
    args->commandBuffer = commandBuffer;
    return args;
}

ResetCommandBufferArgs* CommandRecorder::RecordResetCommandBuffer(VkCommandBuffer commandBuffer,
                                                                  VkCommandBufferResetFlags flags) {
    auto* args = Alloc<ResetCommandBufferArgs>();
    args->commandBuffer = commandBuffer;
    args->flags = flags;
    return args;
}

CmdBindPipelineArgs* CommandRecorder::RecordCmdBindPipeline(VkCommandBuffer commandBuffer,
                                                            VkPipelineBindPoint pipelineBindPoint,
                                                            VkPipeline pipeline) {
    auto* args = Alloc<CmdBindPipelineArgs>();
    args->commandBuffer = commandBuffer;
    args->pipelineBindPoint = pipelineBindPoint;
    args->pipeline = pipeline;
    return args;
}

CmdSetViewportArgs* CommandRecorder::RecordCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                                          uint32_t viewportCount, const VkViewport* pViewports) {
    auto* args = Alloc<CmdSetViewportArgs>();
    args->commandBuffer = commandBuffer;
    args->firstViewport = firstViewport;
    args->viewportCount = viewportCount;
    if (pViewports) {
        args->pViewports = CopyArray(pViewports, static_cast<size_t>(0U), static_cast<size_t>(viewportCount));
    }
    return args;
}

CmdSetScissorArgs* CommandRecorder::RecordCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor,
                                                        uint32_t scissorCount, const VkRect2D* pScissors) {
    auto* args = Alloc<CmdSetScissorArgs>();
    args->commandBuffer = commandBuffer;
    args->firstScissor = firstScissor;
    args->scissorCount = scissorCount;
    if (pScissors) {
        args->pScissors = CopyArray(pScissors, static_cast<size_t>(0U), static_cast<size_t>(scissorCount));
    }
    return args;
}

CmdSetLineWidthArgs* CommandRecorder::RecordCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) {
    auto* args = Alloc<CmdSetLineWidthArgs>();
    args->commandBuffer = commandBuffer;
    args->lineWidth = lineWidth;
    return args;
}

CmdSetDepthBiasArgs* CommandRecorder::RecordCmdSetDepthBias(VkCommandBuffer commandBuffer,
                                                            float depthBiasConstantFactor, float depthBiasClamp,
                                                            float depthBiasSlopeFactor) {
    auto* args = Alloc<CmdSetDepthBiasArgs>();
    args->commandBuffer = commandBuffer;
    args->depthBiasConstantFactor = depthBiasConstantFactor;
    args->depthBiasClamp = depthBiasClamp;
    args->depthBiasSlopeFactor = depthBiasSlopeFactor;
    return args;
}

CmdSetBlendConstantsArgs* CommandRecorder::RecordCmdSetBlendConstants(VkCommandBuffer commandBuffer,
                                                                      const float blendConstants[4]) {
    auto* args = Alloc<CmdSetBlendConstantsArgs>();
    args->commandBuffer = commandBuffer;
    for (uint32_t i = 0; i < 4; ++i) {
        args->blendConstants[i] = blendConstants[i];
    }
    return args;
}

CmdSetDepthBoundsArgs* CommandRecorder::RecordCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds,
                                                                float maxDepthBounds) {
    auto* args = Alloc<CmdSetDepthBoundsArgs>();
    args->commandBuffer = commandBuffer;
    args->minDepthBounds = minDepthBounds;
    args->maxDepthBounds = maxDepthBounds;
    return args;
}

CmdSetStencilCompareMaskArgs* CommandRecorder::RecordCmdSetStencilCompareMask(VkCommandBuffer commandBuffer,
                                                                              VkStencilFaceFlags faceMask,
                                                                              uint32_t compareMask) {
    auto* args = Alloc<CmdSetStencilCompareMaskArgs>();
    args->commandBuffer = commandBuffer;
    args->faceMask = faceMask;
    args->compareMask = compareMask;
    return args;
}

CmdSetStencilWriteMaskArgs* CommandRecorder::RecordCmdSetStencilWriteMask(VkCommandBuffer commandBuffer,
                                                                          VkStencilFaceFlags faceMask,
                                                                          uint32_t writeMask) {
    auto* args = Alloc<CmdSetStencilWriteMaskArgs>();
    args->commandBuffer = commandBuffer;
    args->faceMask = faceMask;
    args->writeMask = writeMask;
    return args;
}

CmdSetStencilReferenceArgs* CommandRecorder::RecordCmdSetStencilReference(VkCommandBuffer commandBuffer,
                                                                          VkStencilFaceFlags faceMask,
                                                                          uint32_t reference) {
    auto* args = Alloc<CmdSetStencilReferenceArgs>();
    args->commandBuffer = commandBuffer;
    args->faceMask = faceMask;
    args->reference = reference;
    return args;
}

CmdBindDescriptorSetsArgs* CommandRecorder::RecordCmdBindDescriptorSets(
    VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet,
    uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount,
    const uint32_t* pDynamicOffsets) {
    auto* args = Alloc<CmdBindDescriptorSetsArgs>();
    args->commandBuffer = commandBuffer;
    args->pipelineBindPoint = pipelineBindPoint;
    args->layout = layout;
    args->firstSet = firstSet;
    args->descriptorSetCount = descriptorSetCount;
    if (pDescriptorSets) {
        args->pDescriptorSets =
            CopyArray(pDescriptorSets, static_cast<size_t>(0U), static_cast<size_t>(descriptorSetCount));
    }
    args->dynamicOffsetCount = dynamicOffsetCount;
    if (pDynamicOffsets) {
        args->pDynamicOffsets =
            CopyArray(pDynamicOffsets, static_cast<size_t>(0U), static_cast<size_t>(dynamicOffsetCount));
    }
    return args;
}

CmdBindIndexBufferArgs* CommandRecorder::RecordCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                                  VkDeviceSize offset, VkIndexType indexType) {
    auto* args = Alloc<CmdBindIndexBufferArgs>();
    args->commandBuffer = commandBuffer;
    args->buffer = buffer;
    args->offset = offset;
    args->indexType = indexType;
    return args;
}

CmdBindVertexBuffersArgs* CommandRecorder::RecordCmdBindVertexBuffers(VkCommandBuffer commandBuffer,
                                                                      uint32_t firstBinding, uint32_t bindingCount,
                                                                      const VkBuffer* pBuffers,
                                                                      const VkDeviceSize* pOffsets) {
    auto* args = Alloc<CmdBindVertexBuffersArgs>();
    args->commandBuffer = commandBuffer;
    args->firstBinding = firstBinding;
    args->bindingCount = bindingCount;
    if (pBuffers) {
        args->pBuffers = CopyArray(pBuffers, static_cast<size_t>(0U), static_cast<size_t>(bindingCount));
    }
    if (pOffsets) {
        args->pOffsets = CopyArray(pOffsets, static_cast<size_t>(0U), static_cast<size_t>(bindingCount));
    }
    return args;
}

CmdDrawArgs* CommandRecorder::RecordCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount,
                                            uint32_t firstVertex, uint32_t firstInstance) {
    auto* args = Alloc<CmdDrawArgs>();
    args->commandBuffer = commandBuffer;
    args->vertexCount = vertexCount;
    args->instanceCount = instanceCount;
    args->firstVertex = firstVertex;
    args->firstInstance = firstInstance;
    return args;
}

CmdDrawIndexedArgs* CommandRecorder::RecordCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount,
                                                          uint32_t instanceCount, uint32_t firstIndex,
                                                          int32_t vertexOffset, uint32_t firstInstance) {
    auto* args = Alloc<CmdDrawIndexedArgs>();
    args->commandBuffer = commandBuffer;
    args->indexCount = indexCount;
    args->instanceCount = instanceCount;
    args->firstIndex = firstIndex;
    args->vertexOffset = vertexOffset;
    args->firstInstance = firstInstance;
    return args;
}

CmdDrawIndirectArgs* CommandRecorder::RecordCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                            VkDeviceSize offset, uint32_t drawCount, uint32_t stride) {
    auto* args = Alloc<CmdDrawIndirectArgs>();
    args->commandBuffer = commandBuffer;
    args->buffer = buffer;
    args->offset = offset;
    args->drawCount = drawCount;
    args->stride = stride;
    return args;
}

CmdDrawIndexedIndirectArgs* CommandRecorder::RecordCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer,
                                                                          VkBuffer buffer, VkDeviceSize offset,
                                                                          uint32_t drawCount, uint32_t stride) {
    auto* args = Alloc<CmdDrawIndexedIndirectArgs>();
    args->commandBuffer = commandBuffer;
    args->buffer = buffer;
    args->offset = offset;
    args->drawCount = drawCount;
    args->stride = stride;
    return args;
}

CmdDispatchArgs* CommandRecorder::RecordCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX,
                                                    uint32_t groupCountY, uint32_t groupCountZ) {
    auto* args = Alloc<CmdDispatchArgs>();
    args->commandBuffer = commandBuffer;
    args->groupCountX = groupCountX;
    args->groupCountY = groupCountY;
    args->groupCountZ = groupCountZ;
    return args;
}

CmdDispatchIndirectArgs* CommandRecorder::RecordCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                                    VkDeviceSize offset) {
    auto* args = Alloc<CmdDispatchIndirectArgs>();
    args->commandBuffer = commandBuffer;
    args->buffer = buffer;
    args->offset = offset;
    return args;
}

CmdCopyBufferArgs* CommandRecorder::RecordCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer,
                                                        VkBuffer dstBuffer, uint32_t regionCount,
                                                        const VkBufferCopy* pRegions) {
    auto* args = Alloc<CmdCopyBufferArgs>();
    args->commandBuffer = commandBuffer;
    args->srcBuffer = srcBuffer;
    args->dstBuffer = dstBuffer;
    args->regionCount = regionCount;
    if (pRegions) {
        args->pRegions = CopyArray(pRegions, static_cast<size_t>(0U), static_cast<size_t>(regionCount));
    }
    return args;
}

CmdCopyImageArgs* CommandRecorder::RecordCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage,
                                                      VkImageLayout srcImageLayout, VkImage dstImage,
                                                      VkImageLayout dstImageLayout, uint32_t regionCount,
                                                      const VkImageCopy* pRegions) {
    auto* args = Alloc<CmdCopyImageArgs>();
    args->commandBuffer = commandBuffer;
    args->srcImage = srcImage;
    args->srcImageLayout = srcImageLayout;
    args->dstImage = dstImage;
    args->dstImageLayout = dstImageLayout;
    args->regionCount = regionCount;
    if (pRegions) {
        args->pRegions = CopyArray(pRegions, static_cast<size_t>(0U), static_cast<size_t>(regionCount));
    }
    return args;
}

CmdBlitImageArgs* CommandRecorder::RecordCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage,
                                                      VkImageLayout srcImageLayout, VkImage dstImage,
                                                      VkImageLayout dstImageLayout, uint32_t regionCount,
                                                      const VkImageBlit* pRegions, VkFilter filter) {
    auto* args = Alloc<CmdBlitImageArgs>();
    args->commandBuffer = commandBuffer;
    args->srcImage = srcImage;
    args->srcImageLayout = srcImageLayout;
    args->dstImage = dstImage;
    args->dstImageLayout = dstImageLayout;
    args->regionCount = regionCount;
    if (pRegions) {
        args->pRegions = CopyArray(pRegions, static_cast<size_t>(0U), static_cast<size_t>(regionCount));
    }
    args->filter = filter;
    return args;
}

CmdCopyBufferToImageArgs* CommandRecorder::RecordCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer,
                                                                      VkImage dstImage, VkImageLayout dstImageLayout,
                                                                      uint32_t regionCount,
                                                                      const VkBufferImageCopy* pRegions) {
    auto* args = Alloc<CmdCopyBufferToImageArgs>();
    args->commandBuffer = commandBuffer;
    args->srcBuffer = srcBuffer;
    args->dstImage = dstImage;
    args->dstImageLayout = dstImageLayout;
    args->regionCount = regionCount;
    if (pRegions) {
        args->pRegions = CopyArray(pRegions, static_cast<size_t>(0U), static_cast<size_t>(regionCount));
    }
    return args;
}

CmdCopyImageToBufferArgs* CommandRecorder::RecordCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage,
                                                                      VkImageLayout srcImageLayout, VkBuffer dstBuffer,
                                                                      uint32_t regionCount,
                                                                      const VkBufferImageCopy* pRegions) {
    auto* args = Alloc<CmdCopyImageToBufferArgs>();
    args->commandBuffer = commandBuffer;
    args->srcImage = srcImage;
    args->srcImageLayout = srcImageLayout;
    args->dstBuffer = dstBuffer;
    args->regionCount = regionCount;
    if (pRegions) {
        args->pRegions = CopyArray(pRegions, static_cast<size_t>(0U), static_cast<size_t>(regionCount));
    }
    return args;
}

CmdUpdateBufferArgs* CommandRecorder::RecordCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer,
                                                            VkDeviceSize dstOffset, VkDeviceSize dataSize,
                                                            const void* pData) {
    auto* args = Alloc<CmdUpdateBufferArgs>();
    args->commandBuffer = commandBuffer;
    args->dstBuffer = dstBuffer;
    args->dstOffset = dstOffset;
    args->dataSize = dataSize;
    args->pData =
        CopyArray(reinterpret_cast<const uint8_t*>(pData), static_cast<size_t>(0U), static_cast<size_t>(dataSize));
    return args;
}

CmdFillBufferArgs* CommandRecorder::RecordCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer,
                                                        VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data) {
    auto* args = Alloc<CmdFillBufferArgs>();
    args->commandBuffer = commandBuffer;
    args->dstBuffer = dstBuffer;
    args->dstOffset = dstOffset;
    args->size = size;
    args->data = data;
    return args;
}

CmdClearColorImageArgs* CommandRecorder::RecordCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image,
                                                                  VkImageLayout imageLayout,
                                                                  const VkClearColorValue* pColor, uint32_t rangeCount,
                                                                  const VkImageSubresourceRange* pRanges) {
    auto* args = Alloc<CmdClearColorImageArgs>();
    args->commandBuffer = commandBuffer;
    args->image = image;
    args->imageLayout = imageLayout;
    if (pColor) {
        args->pColor = CopyArray(pColor, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    args->rangeCount = rangeCount;
    if (pRanges) {
        args->pRanges = CopyArray(pRanges, static_cast<size_t>(0U), static_cast<size_t>(rangeCount));
    }
    return args;
}

CmdClearDepthStencilImageArgs* CommandRecorder::RecordCmdClearDepthStencilImage(
    VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
    const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) {
    auto* args = Alloc<CmdClearDepthStencilImageArgs>();
    args->commandBuffer = commandBuffer;
    args->image = image;
    args->imageLayout = imageLayout;
    if (pDepthStencil) {
        args->pDepthStencil = CopyArray(pDepthStencil, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    args->rangeCount = rangeCount;
    if (pRanges) {
        args->pRanges = CopyArray(pRanges, static_cast<size_t>(0U), static_cast<size_t>(rangeCount));
    }
    return args;
}

CmdClearAttachmentsArgs* CommandRecorder::RecordCmdClearAttachments(VkCommandBuffer commandBuffer,
                                                                    uint32_t attachmentCount,
                                                                    const VkClearAttachment* pAttachments,
                                                                    uint32_t rectCount, const VkClearRect* pRects) {
    auto* args = Alloc<CmdClearAttachmentsArgs>();
    args->commandBuffer = commandBuffer;
    args->attachmentCount = attachmentCount;
    if (pAttachments) {
        args->pAttachments = CopyArray(pAttachments, static_cast<size_t>(0U), static_cast<size_t>(attachmentCount));
    }
    args->rectCount = rectCount;
    if (pRects) {
        args->pRects = CopyArray(pRects, static_cast<size_t>(0U), static_cast<size_t>(rectCount));
    }
    return args;
}

CmdResolveImageArgs* CommandRecorder::RecordCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage,
                                                            VkImageLayout srcImageLayout, VkImage dstImage,
                                                            VkImageLayout dstImageLayout, uint32_t regionCount,
                                                            const VkImageResolve* pRegions) {
    auto* args = Alloc<CmdResolveImageArgs>();
    args->commandBuffer = commandBuffer;
    args->srcImage = srcImage;
    args->srcImageLayout = srcImageLayout;
    args->dstImage = dstImage;
    args->dstImageLayout = dstImageLayout;
    args->regionCount = regionCount;
    if (pRegions) {
        args->pRegions = CopyArray(pRegions, static_cast<size_t>(0U), static_cast<size_t>(regionCount));
    }
    return args;
}

CmdSetEventArgs* CommandRecorder::RecordCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event,
                                                    VkPipelineStageFlags stageMask) {
    auto* args = Alloc<CmdSetEventArgs>();
    args->commandBuffer = commandBuffer;
    args->event = event;
    args->stageMask = stageMask;
    return args;
}

CmdResetEventArgs* CommandRecorder::RecordCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event,
                                                        VkPipelineStageFlags stageMask) {
    auto* args = Alloc<CmdResetEventArgs>();
    args->commandBuffer = commandBuffer;
    args->event = event;
    args->stageMask = stageMask;
    return args;
}

CmdWaitEventsArgs* CommandRecorder::RecordCmdWaitEvents(
    VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask,
    VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
    uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers,
    uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) {
    auto* args = Alloc<CmdWaitEventsArgs>();
    args->commandBuffer = commandBuffer;
    args->eventCount = eventCount;
    if (pEvents) {
        args->pEvents = CopyArray(pEvents, static_cast<size_t>(0U), static_cast<size_t>(eventCount));
    }
    args->srcStageMask = srcStageMask;
    args->dstStageMask = dstStageMask;
    args->memoryBarrierCount = memoryBarrierCount;
    if (pMemoryBarriers) {
        args->pMemoryBarriers =
            CopyArray(pMemoryBarriers, static_cast<size_t>(0U), static_cast<size_t>(memoryBarrierCount));
    }
    args->bufferMemoryBarrierCount = bufferMemoryBarrierCount;
    if (pBufferMemoryBarriers) {
        args->pBufferMemoryBarriers =
            CopyArray(pBufferMemoryBarriers, static_cast<size_t>(0U), static_cast<size_t>(bufferMemoryBarrierCount));
    }
    args->imageMemoryBarrierCount = imageMemoryBarrierCount;
    if (pImageMemoryBarriers) {
        args->pImageMemoryBarriers =
            CopyArray(pImageMemoryBarriers, static_cast<size_t>(0U), static_cast<size_t>(imageMemoryBarrierCount));
    }
    return args;
}

CmdPipelineBarrierArgs* CommandRecorder::RecordCmdPipelineBarrier(
    VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask,
    VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
    uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers,
    uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) {
    auto* args = Alloc<CmdPipelineBarrierArgs>();
    args->commandBuffer = commandBuffer;
    args->srcStageMask = srcStageMask;
    args->dstStageMask = dstStageMask;
    args->dependencyFlags = dependencyFlags;
    args->memoryBarrierCount = memoryBarrierCount;
    if (pMemoryBarriers) {
        args->pMemoryBarriers =
            CopyArray(pMemoryBarriers, static_cast<size_t>(0U), static_cast<size_t>(memoryBarrierCount));
    }
    args->bufferMemoryBarrierCount = bufferMemoryBarrierCount;
    if (pBufferMemoryBarriers) {
        args->pBufferMemoryBarriers =
            CopyArray(pBufferMemoryBarriers, static_cast<size_t>(0U), static_cast<size_t>(bufferMemoryBarrierCount));
    }
    args->imageMemoryBarrierCount = imageMemoryBarrierCount;
    if (pImageMemoryBarriers) {
        args->pImageMemoryBarriers =
            CopyArray(pImageMemoryBarriers, static_cast<size_t>(0U), static_cast<size_t>(imageMemoryBarrierCount));
    }
    return args;
}

CmdBeginQueryArgs* CommandRecorder::RecordCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool,
                                                        uint32_t query, VkQueryControlFlags flags) {
    auto* args = Alloc<CmdBeginQueryArgs>();
    args->commandBuffer = commandBuffer;
    args->queryPool = queryPool;
    args->query = query;
    args->flags = flags;
    return args;
}

CmdEndQueryArgs* CommandRecorder::RecordCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool,
                                                    uint32_t query) {
    auto* args = Alloc<CmdEndQueryArgs>();
    args->commandBuffer = commandBuffer;
    args->queryPool = queryPool;
    args->query = query;
    return args;
}

CmdResetQueryPoolArgs* CommandRecorder::RecordCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool,
                                                                uint32_t firstQuery, uint32_t queryCount) {
    auto* args = Alloc<CmdResetQueryPoolArgs>();
    args->commandBuffer = commandBuffer;
    args->queryPool = queryPool;
    args->firstQuery = firstQuery;
    args->queryCount = queryCount;
    return args;
}

CmdWriteTimestampArgs* CommandRecorder::RecordCmdWriteTimestamp(VkCommandBuffer commandBuffer,
                                                                VkPipelineStageFlagBits pipelineStage,
                                                                VkQueryPool queryPool, uint32_t query) {
    auto* args = Alloc<CmdWriteTimestampArgs>();
    args->commandBuffer = commandBuffer;
    args->pipelineStage = pipelineStage;
    args->queryPool = queryPool;
    args->query = query;
    return args;
}

CmdCopyQueryPoolResultsArgs* CommandRecorder::RecordCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer,
                                                                            VkQueryPool queryPool, uint32_t firstQuery,
                                                                            uint32_t queryCount, VkBuffer dstBuffer,
                                                                            VkDeviceSize dstOffset, VkDeviceSize stride,
                                                                            VkQueryResultFlags flags) {
    auto* args = Alloc<CmdCopyQueryPoolResultsArgs>();
    args->commandBuffer = commandBuffer;
    args->queryPool = queryPool;
    args->firstQuery = firstQuery;
    args->queryCount = queryCount;
    args->dstBuffer = dstBuffer;
    args->dstOffset = dstOffset;
    args->stride = stride;
    args->flags = flags;
    return args;
}

CmdPushConstantsArgs* CommandRecorder::RecordCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout,
                                                              VkShaderStageFlags stageFlags, uint32_t offset,
                                                              uint32_t size, const void* pValues) {
    auto* args = Alloc<CmdPushConstantsArgs>();
    args->commandBuffer = commandBuffer;
    args->layout = layout;
    args->stageFlags = stageFlags;
    args->offset = offset;
    args->size = size;
    args->pValues =
        CopyArray(reinterpret_cast<const uint8_t*>(pValues), static_cast<size_t>(0U), static_cast<size_t>(size));
    return args;
}

CmdBeginRenderPassArgs* CommandRecorder::RecordCmdBeginRenderPass(VkCommandBuffer commandBuffer,
                                                                  const VkRenderPassBeginInfo* pRenderPassBegin,
                                                                  VkSubpassContents contents) {
    auto* args = Alloc<CmdBeginRenderPassArgs>();
    args->commandBuffer = commandBuffer;
    if (pRenderPassBegin) {
        args->pRenderPassBegin = CopyArray(pRenderPassBegin, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    args->contents = contents;
    return args;
}

CmdNextSubpassArgs* CommandRecorder::RecordCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) {
    auto* args = Alloc<CmdNextSubpassArgs>();
    args->commandBuffer = commandBuffer;
    args->contents = contents;
    return args;
}

CmdEndRenderPassArgs* CommandRecorder::RecordCmdEndRenderPass(VkCommandBuffer commandBuffer) {
    auto* args = Alloc<CmdEndRenderPassArgs>();
    args->commandBuffer = commandBuffer;
    return args;
}

CmdExecuteCommandsArgs* CommandRecorder::RecordCmdExecuteCommands(VkCommandBuffer commandBuffer,
                                                                  uint32_t commandBufferCount,
                                                                  const VkCommandBuffer* pCommandBuffers) {
    auto* args = Alloc<CmdExecuteCommandsArgs>();
    args->commandBuffer = commandBuffer;
    args->commandBufferCount = commandBufferCount;
    if (pCommandBuffers) {
        args->pCommandBuffers =
            CopyArray(pCommandBuffers, static_cast<size_t>(0U), static_cast<size_t>(commandBufferCount));
    }
    return args;
}

CmdSetDeviceMaskArgs* CommandRecorder::RecordCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    auto* args = Alloc<CmdSetDeviceMaskArgs>();
    args->commandBuffer = commandBuffer;
    args->deviceMask = deviceMask;
    return args;
}

CmdDispatchBaseArgs* CommandRecorder::RecordCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX,
                                                            uint32_t baseGroupY, uint32_t baseGroupZ,
                                                            uint32_t groupCountX, uint32_t groupCountY,
                                                            uint32_t groupCountZ) {
    auto* args = Alloc<CmdDispatchBaseArgs>();
    args->commandBuffer = commandBuffer;
    args->baseGroupX = baseGroupX;
    args->baseGroupY = baseGroupY;
    args->baseGroupZ = baseGroupZ;
    args->groupCountX = groupCountX;
    args->groupCountY = groupCountY;
    args->groupCountZ = groupCountZ;
    return args;
}

CmdDrawIndirectCountArgs* CommandRecorder::RecordCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                                      VkDeviceSize offset, VkBuffer countBuffer,
                                                                      VkDeviceSize countBufferOffset,
                                                                      uint32_t maxDrawCount, uint32_t stride) {
    auto* args = Alloc<CmdDrawIndirectCountArgs>();
    args->commandBuffer = commandBuffer;
    args->buffer = buffer;
    args->offset = offset;
    args->countBuffer = countBuffer;
    args->countBufferOffset = countBufferOffset;
    args->maxDrawCount = maxDrawCount;
    args->stride = stride;
    return args;
}

CmdDrawIndexedIndirectCountArgs* CommandRecorder::RecordCmdDrawIndexedIndirectCount(
    VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer,
    VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
    auto* args = Alloc<CmdDrawIndexedIndirectCountArgs>();
    args->commandBuffer = commandBuffer;
    args->buffer = buffer;
    args->offset = offset;
    args->countBuffer = countBuffer;
    args->countBufferOffset = countBufferOffset;
    args->maxDrawCount = maxDrawCount;
    args->stride = stride;
    return args;
}

CmdBeginRenderPass2Args* CommandRecorder::RecordCmdBeginRenderPass2(VkCommandBuffer commandBuffer,
                                                                    const VkRenderPassBeginInfo* pRenderPassBegin,
                                                                    const VkSubpassBeginInfo* pSubpassBeginInfo) {
    auto* args = Alloc<CmdBeginRenderPass2Args>();
    args->commandBuffer = commandBuffer;
    if (pRenderPassBegin) {
        args->pRenderPassBegin = CopyArray(pRenderPassBegin, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    if (pSubpassBeginInfo) {
        args->pSubpassBeginInfo = CopyArray(pSubpassBeginInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdNextSubpass2Args* CommandRecorder::RecordCmdNextSubpass2(VkCommandBuffer commandBuffer,
                                                            const VkSubpassBeginInfo* pSubpassBeginInfo,
                                                            const VkSubpassEndInfo* pSubpassEndInfo) {
    auto* args = Alloc<CmdNextSubpass2Args>();
    args->commandBuffer = commandBuffer;
    if (pSubpassBeginInfo) {
        args->pSubpassBeginInfo = CopyArray(pSubpassBeginInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    if (pSubpassEndInfo) {
        args->pSubpassEndInfo = CopyArray(pSubpassEndInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdEndRenderPass2Args* CommandRecorder::RecordCmdEndRenderPass2(VkCommandBuffer commandBuffer,
                                                                const VkSubpassEndInfo* pSubpassEndInfo) {
    auto* args = Alloc<CmdEndRenderPass2Args>();
    args->commandBuffer = commandBuffer;
    if (pSubpassEndInfo) {
        args->pSubpassEndInfo = CopyArray(pSubpassEndInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdSetEvent2Args* CommandRecorder::RecordCmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event,
                                                      const VkDependencyInfo* pDependencyInfo) {
    auto* args = Alloc<CmdSetEvent2Args>();
    args->commandBuffer = commandBuffer;
    args->event = event;
    if (pDependencyInfo) {
        args->pDependencyInfo = CopyArray(pDependencyInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdResetEvent2Args* CommandRecorder::RecordCmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event,
                                                          VkPipelineStageFlags2 stageMask) {
    auto* args = Alloc<CmdResetEvent2Args>();
    args->commandBuffer = commandBuffer;
    args->event = event;
    args->stageMask = stageMask;
    return args;
}

CmdWaitEvents2Args* CommandRecorder::RecordCmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount,
                                                          const VkEvent* pEvents,
                                                          const VkDependencyInfo* pDependencyInfos) {
    auto* args = Alloc<CmdWaitEvents2Args>();
    args->commandBuffer = commandBuffer;
    args->eventCount = eventCount;
    if (pEvents) {
        args->pEvents = CopyArray(pEvents, static_cast<size_t>(0U), static_cast<size_t>(eventCount));
    }
    if (pDependencyInfos) {
        args->pDependencyInfos = CopyArray(pDependencyInfos, static_cast<size_t>(0U), static_cast<size_t>(eventCount));
    }
    return args;
}

CmdPipelineBarrier2Args* CommandRecorder::RecordCmdPipelineBarrier2(VkCommandBuffer commandBuffer,
                                                                    const VkDependencyInfo* pDependencyInfo) {
    auto* args = Alloc<CmdPipelineBarrier2Args>();
    args->commandBuffer = commandBuffer;
    if (pDependencyInfo) {
        args->pDependencyInfo = CopyArray(pDependencyInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdWriteTimestamp2Args* CommandRecorder::RecordCmdWriteTimestamp2(VkCommandBuffer commandBuffer,
                                                                  VkPipelineStageFlags2 stage, VkQueryPool queryPool,
                                                                  uint32_t query) {
    auto* args = Alloc<CmdWriteTimestamp2Args>();
    args->commandBuffer = commandBuffer;
    args->stage = stage;
    args->queryPool = queryPool;
    args->query = query;
    return args;
}

CmdCopyBuffer2Args* CommandRecorder::RecordCmdCopyBuffer2(VkCommandBuffer commandBuffer,
                                                          const VkCopyBufferInfo2* pCopyBufferInfo) {
    auto* args = Alloc<CmdCopyBuffer2Args>();
    args->commandBuffer = commandBuffer;
    if (pCopyBufferInfo) {
        args->pCopyBufferInfo = CopyArray(pCopyBufferInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdCopyImage2Args* CommandRecorder::RecordCmdCopyImage2(VkCommandBuffer commandBuffer,
                                                        const VkCopyImageInfo2* pCopyImageInfo) {
    auto* args = Alloc<CmdCopyImage2Args>();
    args->commandBuffer = commandBuffer;
    if (pCopyImageInfo) {
        args->pCopyImageInfo = CopyArray(pCopyImageInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdCopyBufferToImage2Args* CommandRecorder::RecordCmdCopyBufferToImage2(
    VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    auto* args = Alloc<CmdCopyBufferToImage2Args>();
    args->commandBuffer = commandBuffer;
    if (pCopyBufferToImageInfo) {
        args->pCopyBufferToImageInfo =
            CopyArray(pCopyBufferToImageInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdCopyImageToBuffer2Args* CommandRecorder::RecordCmdCopyImageToBuffer2(
    VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    auto* args = Alloc<CmdCopyImageToBuffer2Args>();
    args->commandBuffer = commandBuffer;
    if (pCopyImageToBufferInfo) {
        args->pCopyImageToBufferInfo =
            CopyArray(pCopyImageToBufferInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdBlitImage2Args* CommandRecorder::RecordCmdBlitImage2(VkCommandBuffer commandBuffer,
                                                        const VkBlitImageInfo2* pBlitImageInfo) {
    auto* args = Alloc<CmdBlitImage2Args>();
    args->commandBuffer = commandBuffer;
    if (pBlitImageInfo) {
        args->pBlitImageInfo = CopyArray(pBlitImageInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdResolveImage2Args* CommandRecorder::RecordCmdResolveImage2(VkCommandBuffer commandBuffer,
                                                              const VkResolveImageInfo2* pResolveImageInfo) {
    auto* args = Alloc<CmdResolveImage2Args>();
    args->commandBuffer = commandBuffer;
    if (pResolveImageInfo) {
        args->pResolveImageInfo = CopyArray(pResolveImageInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdBeginRenderingArgs* CommandRecorder::RecordCmdBeginRendering(VkCommandBuffer commandBuffer,
                                                                const VkRenderingInfo* pRenderingInfo) {
    auto* args = Alloc<CmdBeginRenderingArgs>();
    args->commandBuffer = commandBuffer;
    if (pRenderingInfo) {
        args->pRenderingInfo = CopyArray(pRenderingInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdEndRenderingArgs* CommandRecorder::RecordCmdEndRendering(VkCommandBuffer commandBuffer) {
    auto* args = Alloc<CmdEndRenderingArgs>();
    args->commandBuffer = commandBuffer;
    return args;
}

CmdSetCullModeArgs* CommandRecorder::RecordCmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    auto* args = Alloc<CmdSetCullModeArgs>();
    args->commandBuffer = commandBuffer;
    args->cullMode = cullMode;
    return args;
}

CmdSetFrontFaceArgs* CommandRecorder::RecordCmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    auto* args = Alloc<CmdSetFrontFaceArgs>();
    args->commandBuffer = commandBuffer;
    args->frontFace = frontFace;
    return args;
}

CmdSetPrimitiveTopologyArgs* CommandRecorder::RecordCmdSetPrimitiveTopology(VkCommandBuffer commandBuffer,
                                                                            VkPrimitiveTopology primitiveTopology) {
    auto* args = Alloc<CmdSetPrimitiveTopologyArgs>();
    args->commandBuffer = commandBuffer;
    args->primitiveTopology = primitiveTopology;
    return args;
}

CmdSetViewportWithCountArgs* CommandRecorder::RecordCmdSetViewportWithCount(VkCommandBuffer commandBuffer,
                                                                            uint32_t viewportCount,
                                                                            const VkViewport* pViewports) {
    auto* args = Alloc<CmdSetViewportWithCountArgs>();
    args->commandBuffer = commandBuffer;
    args->viewportCount = viewportCount;
    if (pViewports) {
        args->pViewports = CopyArray(pViewports, static_cast<size_t>(0U), static_cast<size_t>(viewportCount));
    }
    return args;
}

CmdSetScissorWithCountArgs* CommandRecorder::RecordCmdSetScissorWithCount(VkCommandBuffer commandBuffer,
                                                                          uint32_t scissorCount,
                                                                          const VkRect2D* pScissors) {
    auto* args = Alloc<CmdSetScissorWithCountArgs>();
    args->commandBuffer = commandBuffer;
    args->scissorCount = scissorCount;
    if (pScissors) {
        args->pScissors = CopyArray(pScissors, static_cast<size_t>(0U), static_cast<size_t>(scissorCount));
    }
    return args;
}

CmdBindVertexBuffers2Args* CommandRecorder::RecordCmdBindVertexBuffers2(
    VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers,
    const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) {
    auto* args = Alloc<CmdBindVertexBuffers2Args>();
    args->commandBuffer = commandBuffer;
    args->firstBinding = firstBinding;
    args->bindingCount = bindingCount;
    if (pBuffers) {
        args->pBuffers = CopyArray(pBuffers, static_cast<size_t>(0U), static_cast<size_t>(bindingCount));
    }
    if (pOffsets) {
        args->pOffsets = CopyArray(pOffsets, static_cast<size_t>(0U), static_cast<size_t>(bindingCount));
    }
    if (pSizes) {
        args->pSizes = CopyArray(pSizes, static_cast<size_t>(0U), static_cast<size_t>(bindingCount));
    }
    if (pStrides) {
        args->pStrides = CopyArray(pStrides, static_cast<size_t>(0U), static_cast<size_t>(bindingCount));
    }
    return args;
}

CmdSetDepthTestEnableArgs* CommandRecorder::RecordCmdSetDepthTestEnable(VkCommandBuffer commandBuffer,
                                                                        VkBool32 depthTestEnable) {
    auto* args = Alloc<CmdSetDepthTestEnableArgs>();
    args->commandBuffer = commandBuffer;
    args->depthTestEnable = depthTestEnable;
    return args;
}

CmdSetDepthWriteEnableArgs* CommandRecorder::RecordCmdSetDepthWriteEnable(VkCommandBuffer commandBuffer,
                                                                          VkBool32 depthWriteEnable) {
    auto* args = Alloc<CmdSetDepthWriteEnableArgs>();
    args->commandBuffer = commandBuffer;
    args->depthWriteEnable = depthWriteEnable;
    return args;
}

CmdSetDepthCompareOpArgs* CommandRecorder::RecordCmdSetDepthCompareOp(VkCommandBuffer commandBuffer,
                                                                      VkCompareOp depthCompareOp) {
    auto* args = Alloc<CmdSetDepthCompareOpArgs>();
    args->commandBuffer = commandBuffer;
    args->depthCompareOp = depthCompareOp;
    return args;
}

CmdSetDepthBoundsTestEnableArgs* CommandRecorder::RecordCmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer,
                                                                                    VkBool32 depthBoundsTestEnable) {
    auto* args = Alloc<CmdSetDepthBoundsTestEnableArgs>();
    args->commandBuffer = commandBuffer;
    args->depthBoundsTestEnable = depthBoundsTestEnable;
    return args;
}

CmdSetStencilTestEnableArgs* CommandRecorder::RecordCmdSetStencilTestEnable(VkCommandBuffer commandBuffer,
                                                                            VkBool32 stencilTestEnable) {
    auto* args = Alloc<CmdSetStencilTestEnableArgs>();
    args->commandBuffer = commandBuffer;
    args->stencilTestEnable = stencilTestEnable;
    return args;
}

CmdSetStencilOpArgs* CommandRecorder::RecordCmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                                            VkStencilOp failOp, VkStencilOp passOp,
                                                            VkStencilOp depthFailOp, VkCompareOp compareOp) {
    auto* args = Alloc<CmdSetStencilOpArgs>();
    args->commandBuffer = commandBuffer;
    args->faceMask = faceMask;
    args->failOp = failOp;
    args->passOp = passOp;
    args->depthFailOp = depthFailOp;
    args->compareOp = compareOp;
    return args;
}

CmdSetRasterizerDiscardEnableArgs* CommandRecorder::RecordCmdSetRasterizerDiscardEnable(
    VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {
    auto* args = Alloc<CmdSetRasterizerDiscardEnableArgs>();
    args->commandBuffer = commandBuffer;
    args->rasterizerDiscardEnable = rasterizerDiscardEnable;
    return args;
}

CmdSetDepthBiasEnableArgs* CommandRecorder::RecordCmdSetDepthBiasEnable(VkCommandBuffer commandBuffer,
                                                                        VkBool32 depthBiasEnable) {
    auto* args = Alloc<CmdSetDepthBiasEnableArgs>();
    args->commandBuffer = commandBuffer;
    args->depthBiasEnable = depthBiasEnable;
    return args;
}

CmdSetPrimitiveRestartEnableArgs* CommandRecorder::RecordCmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer,
                                                                                      VkBool32 primitiveRestartEnable) {
    auto* args = Alloc<CmdSetPrimitiveRestartEnableArgs>();
    args->commandBuffer = commandBuffer;
    args->primitiveRestartEnable = primitiveRestartEnable;
    return args;
}

CmdBeginVideoCodingKHRArgs* CommandRecorder::RecordCmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer,
                                                                          const VkVideoBeginCodingInfoKHR* pBeginInfo) {
    auto* args = Alloc<CmdBeginVideoCodingKHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pBeginInfo) {
        args->pBeginInfo = CopyArray(pBeginInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdEndVideoCodingKHRArgs* CommandRecorder::RecordCmdEndVideoCodingKHR(VkCommandBuffer commandBuffer,
                                                                      const VkVideoEndCodingInfoKHR* pEndCodingInfo) {
    auto* args = Alloc<CmdEndVideoCodingKHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pEndCodingInfo) {
        args->pEndCodingInfo = CopyArray(pEndCodingInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdControlVideoCodingKHRArgs* CommandRecorder::RecordCmdControlVideoCodingKHR(
    VkCommandBuffer commandBuffer, const VkVideoCodingControlInfoKHR* pCodingControlInfo) {
    auto* args = Alloc<CmdControlVideoCodingKHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pCodingControlInfo) {
        args->pCodingControlInfo = CopyArray(pCodingControlInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdDecodeVideoKHRArgs* CommandRecorder::RecordCmdDecodeVideoKHR(VkCommandBuffer commandBuffer,
                                                                const VkVideoDecodeInfoKHR* pDecodeInfo) {
    auto* args = Alloc<CmdDecodeVideoKHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pDecodeInfo) {
        args->pDecodeInfo = CopyArray(pDecodeInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdBeginRenderingKHRArgs* CommandRecorder::RecordCmdBeginRenderingKHR(VkCommandBuffer commandBuffer,
                                                                      const VkRenderingInfo* pRenderingInfo) {
    auto* args = Alloc<CmdBeginRenderingKHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pRenderingInfo) {
        args->pRenderingInfo = CopyArray(pRenderingInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdEndRenderingKHRArgs* CommandRecorder::RecordCmdEndRenderingKHR(VkCommandBuffer commandBuffer) {
    auto* args = Alloc<CmdEndRenderingKHRArgs>();
    args->commandBuffer = commandBuffer;
    return args;
}

CmdSetDeviceMaskKHRArgs* CommandRecorder::RecordCmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer,
                                                                    uint32_t deviceMask) {
    auto* args = Alloc<CmdSetDeviceMaskKHRArgs>();
    args->commandBuffer = commandBuffer;
    args->deviceMask = deviceMask;
    return args;
}

CmdDispatchBaseKHRArgs* CommandRecorder::RecordCmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX,
                                                                  uint32_t baseGroupY, uint32_t baseGroupZ,
                                                                  uint32_t groupCountX, uint32_t groupCountY,
                                                                  uint32_t groupCountZ) {
    auto* args = Alloc<CmdDispatchBaseKHRArgs>();
    args->commandBuffer = commandBuffer;
    args->baseGroupX = baseGroupX;
    args->baseGroupY = baseGroupY;
    args->baseGroupZ = baseGroupZ;
    args->groupCountX = groupCountX;
    args->groupCountY = groupCountY;
    args->groupCountZ = groupCountZ;
    return args;
}

CmdPushDescriptorSetKHRArgs* CommandRecorder::RecordCmdPushDescriptorSetKHR(
    VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set,
    uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites) {
    auto* args = Alloc<CmdPushDescriptorSetKHRArgs>();
    args->commandBuffer = commandBuffer;
    args->pipelineBindPoint = pipelineBindPoint;
    args->layout = layout;
    args->set = set;
    args->descriptorWriteCount = descriptorWriteCount;
    if (pDescriptorWrites) {
        args->pDescriptorWrites =
            CopyArray(pDescriptorWrites, static_cast<size_t>(0U), static_cast<size_t>(descriptorWriteCount));
    }
    return args;
}

CmdPushDescriptorSetWithTemplateKHRArgs* CommandRecorder::RecordCmdPushDescriptorSetWithTemplateKHR(
    VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout,
    uint32_t set, const void* pData) {
    auto* args = Alloc<CmdPushDescriptorSetWithTemplateKHRArgs>();
    args->commandBuffer = commandBuffer;
    args->descriptorUpdateTemplate = descriptorUpdateTemplate;
    args->layout = layout;
    args->set = set;
    args->pData = pData;
    return args;
}

CmdBeginRenderPass2KHRArgs* CommandRecorder::RecordCmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer,
                                                                          const VkRenderPassBeginInfo* pRenderPassBegin,
                                                                          const VkSubpassBeginInfo* pSubpassBeginInfo) {
    auto* args = Alloc<CmdBeginRenderPass2KHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pRenderPassBegin) {
        args->pRenderPassBegin = CopyArray(pRenderPassBegin, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    if (pSubpassBeginInfo) {
        args->pSubpassBeginInfo = CopyArray(pSubpassBeginInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdNextSubpass2KHRArgs* CommandRecorder::RecordCmdNextSubpass2KHR(VkCommandBuffer commandBuffer,
                                                                  const VkSubpassBeginInfo* pSubpassBeginInfo,
                                                                  const VkSubpassEndInfo* pSubpassEndInfo) {
    auto* args = Alloc<CmdNextSubpass2KHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pSubpassBeginInfo) {
        args->pSubpassBeginInfo = CopyArray(pSubpassBeginInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    if (pSubpassEndInfo) {
        args->pSubpassEndInfo = CopyArray(pSubpassEndInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdEndRenderPass2KHRArgs* CommandRecorder::RecordCmdEndRenderPass2KHR(VkCommandBuffer commandBuffer,
                                                                      const VkSubpassEndInfo* pSubpassEndInfo) {
    auto* args = Alloc<CmdEndRenderPass2KHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pSubpassEndInfo) {
        args->pSubpassEndInfo = CopyArray(pSubpassEndInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdDrawIndirectCountKHRArgs* CommandRecorder::RecordCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer,
                                                                            VkBuffer buffer, VkDeviceSize offset,
                                                                            VkBuffer countBuffer,
                                                                            VkDeviceSize countBufferOffset,
                                                                            uint32_t maxDrawCount, uint32_t stride) {
    auto* args = Alloc<CmdDrawIndirectCountKHRArgs>();
    args->commandBuffer = commandBuffer;
    args->buffer = buffer;
    args->offset = offset;
    args->countBuffer = countBuffer;
    args->countBufferOffset = countBufferOffset;
    args->maxDrawCount = maxDrawCount;
    args->stride = stride;
    return args;
}

CmdDrawIndexedIndirectCountKHRArgs* CommandRecorder::RecordCmdDrawIndexedIndirectCountKHR(
    VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer,
    VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
    auto* args = Alloc<CmdDrawIndexedIndirectCountKHRArgs>();
    args->commandBuffer = commandBuffer;
    args->buffer = buffer;
    args->offset = offset;
    args->countBuffer = countBuffer;
    args->countBufferOffset = countBufferOffset;
    args->maxDrawCount = maxDrawCount;
    args->stride = stride;
    return args;
}

CmdSetFragmentShadingRateKHRArgs* CommandRecorder::RecordCmdSetFragmentShadingRateKHR(
    VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize,
    const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    auto* args = Alloc<CmdSetFragmentShadingRateKHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pFragmentSize) {
        args->pFragmentSize = CopyArray(pFragmentSize, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    for (uint32_t i = 0; i < 2; ++i) {
        args->combinerOps[i] = combinerOps[i];
    }
    return args;
}

CmdSetRenderingAttachmentLocationsKHRArgs* CommandRecorder::RecordCmdSetRenderingAttachmentLocationsKHR(
    VkCommandBuffer commandBuffer, const VkRenderingAttachmentLocationInfoKHR* pLocationInfo) {
    auto* args = Alloc<CmdSetRenderingAttachmentLocationsKHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pLocationInfo) {
        args->pLocationInfo = CopyArray(pLocationInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdSetRenderingInputAttachmentIndicesKHRArgs* CommandRecorder::RecordCmdSetRenderingInputAttachmentIndicesKHR(
    VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfoKHR* pInputAttachmentIndexInfo) {
    auto* args = Alloc<CmdSetRenderingInputAttachmentIndicesKHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pInputAttachmentIndexInfo) {
        args->pInputAttachmentIndexInfo =
            CopyArray(pInputAttachmentIndexInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdEncodeVideoKHRArgs* CommandRecorder::RecordCmdEncodeVideoKHR(VkCommandBuffer commandBuffer,
                                                                const VkVideoEncodeInfoKHR* pEncodeInfo) {
    auto* args = Alloc<CmdEncodeVideoKHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pEncodeInfo) {
        args->pEncodeInfo = CopyArray(pEncodeInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdSetEvent2KHRArgs* CommandRecorder::RecordCmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event,
                                                            const VkDependencyInfo* pDependencyInfo) {
    auto* args = Alloc<CmdSetEvent2KHRArgs>();
    args->commandBuffer = commandBuffer;
    args->event = event;
    if (pDependencyInfo) {
        args->pDependencyInfo = CopyArray(pDependencyInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdResetEvent2KHRArgs* CommandRecorder::RecordCmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event,
                                                                VkPipelineStageFlags2 stageMask) {
    auto* args = Alloc<CmdResetEvent2KHRArgs>();
    args->commandBuffer = commandBuffer;
    args->event = event;
    args->stageMask = stageMask;
    return args;
}

CmdWaitEvents2KHRArgs* CommandRecorder::RecordCmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount,
                                                                const VkEvent* pEvents,
                                                                const VkDependencyInfo* pDependencyInfos) {
    auto* args = Alloc<CmdWaitEvents2KHRArgs>();
    args->commandBuffer = commandBuffer;
    args->eventCount = eventCount;
    if (pEvents) {
        args->pEvents = CopyArray(pEvents, static_cast<size_t>(0U), static_cast<size_t>(eventCount));
    }
    if (pDependencyInfos) {
        args->pDependencyInfos = CopyArray(pDependencyInfos, static_cast<size_t>(0U), static_cast<size_t>(eventCount));
    }
    return args;
}

CmdPipelineBarrier2KHRArgs* CommandRecorder::RecordCmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer,
                                                                          const VkDependencyInfo* pDependencyInfo) {
    auto* args = Alloc<CmdPipelineBarrier2KHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pDependencyInfo) {
        args->pDependencyInfo = CopyArray(pDependencyInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdWriteTimestamp2KHRArgs* CommandRecorder::RecordCmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer,
                                                                        VkPipelineStageFlags2 stage,
                                                                        VkQueryPool queryPool, uint32_t query) {
    auto* args = Alloc<CmdWriteTimestamp2KHRArgs>();
    args->commandBuffer = commandBuffer;
    args->stage = stage;
    args->queryPool = queryPool;
    args->query = query;
    return args;
}

CmdWriteBufferMarker2AMDArgs* CommandRecorder::RecordCmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer,
                                                                              VkPipelineStageFlags2 stage,
                                                                              VkBuffer dstBuffer,
                                                                              VkDeviceSize dstOffset, uint32_t marker) {
    auto* args = Alloc<CmdWriteBufferMarker2AMDArgs>();
    args->commandBuffer = commandBuffer;
    args->stage = stage;
    args->dstBuffer = dstBuffer;
    args->dstOffset = dstOffset;
    args->marker = marker;
    return args;
}

CmdCopyBuffer2KHRArgs* CommandRecorder::RecordCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer,
                                                                const VkCopyBufferInfo2* pCopyBufferInfo) {
    auto* args = Alloc<CmdCopyBuffer2KHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pCopyBufferInfo) {
        args->pCopyBufferInfo = CopyArray(pCopyBufferInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdCopyImage2KHRArgs* CommandRecorder::RecordCmdCopyImage2KHR(VkCommandBuffer commandBuffer,
                                                              const VkCopyImageInfo2* pCopyImageInfo) {
    auto* args = Alloc<CmdCopyImage2KHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pCopyImageInfo) {
        args->pCopyImageInfo = CopyArray(pCopyImageInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdCopyBufferToImage2KHRArgs* CommandRecorder::RecordCmdCopyBufferToImage2KHR(
    VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    auto* args = Alloc<CmdCopyBufferToImage2KHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pCopyBufferToImageInfo) {
        args->pCopyBufferToImageInfo =
            CopyArray(pCopyBufferToImageInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdCopyImageToBuffer2KHRArgs* CommandRecorder::RecordCmdCopyImageToBuffer2KHR(
    VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    auto* args = Alloc<CmdCopyImageToBuffer2KHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pCopyImageToBufferInfo) {
        args->pCopyImageToBufferInfo =
            CopyArray(pCopyImageToBufferInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdBlitImage2KHRArgs* CommandRecorder::RecordCmdBlitImage2KHR(VkCommandBuffer commandBuffer,
                                                              const VkBlitImageInfo2* pBlitImageInfo) {
    auto* args = Alloc<CmdBlitImage2KHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pBlitImageInfo) {
        args->pBlitImageInfo = CopyArray(pBlitImageInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdResolveImage2KHRArgs* CommandRecorder::RecordCmdResolveImage2KHR(VkCommandBuffer commandBuffer,
                                                                    const VkResolveImageInfo2* pResolveImageInfo) {
    auto* args = Alloc<CmdResolveImage2KHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pResolveImageInfo) {
        args->pResolveImageInfo = CopyArray(pResolveImageInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdTraceRaysIndirect2KHRArgs* CommandRecorder::RecordCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer,
                                                                              VkDeviceAddress indirectDeviceAddress) {
    auto* args = Alloc<CmdTraceRaysIndirect2KHRArgs>();
    args->commandBuffer = commandBuffer;
    args->indirectDeviceAddress = indirectDeviceAddress;
    return args;
}

CmdBindIndexBuffer2KHRArgs* CommandRecorder::RecordCmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer,
                                                                          VkBuffer buffer, VkDeviceSize offset,
                                                                          VkDeviceSize size, VkIndexType indexType) {
    auto* args = Alloc<CmdBindIndexBuffer2KHRArgs>();
    args->commandBuffer = commandBuffer;
    args->buffer = buffer;
    args->offset = offset;
    args->size = size;
    args->indexType = indexType;
    return args;
}

CmdSetLineStippleKHRArgs* CommandRecorder::RecordCmdSetLineStippleKHR(VkCommandBuffer commandBuffer,
                                                                      uint32_t lineStippleFactor,
                                                                      uint16_t lineStipplePattern) {
    auto* args = Alloc<CmdSetLineStippleKHRArgs>();
    args->commandBuffer = commandBuffer;
    args->lineStippleFactor = lineStippleFactor;
    args->lineStipplePattern = lineStipplePattern;
    return args;
}

CmdBindDescriptorSets2KHRArgs* CommandRecorder::RecordCmdBindDescriptorSets2KHR(
    VkCommandBuffer commandBuffer, const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo) {
    auto* args = Alloc<CmdBindDescriptorSets2KHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pBindDescriptorSetsInfo) {
        args->pBindDescriptorSetsInfo =
            CopyArray(pBindDescriptorSetsInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdPushConstants2KHRArgs* CommandRecorder::RecordCmdPushConstants2KHR(
    VkCommandBuffer commandBuffer, const VkPushConstantsInfoKHR* pPushConstantsInfo) {
    auto* args = Alloc<CmdPushConstants2KHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pPushConstantsInfo) {
        args->pPushConstantsInfo = CopyArray(pPushConstantsInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdPushDescriptorSet2KHRArgs* CommandRecorder::RecordCmdPushDescriptorSet2KHR(
    VkCommandBuffer commandBuffer, const VkPushDescriptorSetInfoKHR* pPushDescriptorSetInfo) {
    auto* args = Alloc<CmdPushDescriptorSet2KHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pPushDescriptorSetInfo) {
        args->pPushDescriptorSetInfo =
            CopyArray(pPushDescriptorSetInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdPushDescriptorSetWithTemplate2KHRArgs* CommandRecorder::RecordCmdPushDescriptorSetWithTemplate2KHR(
    VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo) {
    auto* args = Alloc<CmdPushDescriptorSetWithTemplate2KHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pPushDescriptorSetWithTemplateInfo) {
        args->pPushDescriptorSetWithTemplateInfo =
            CopyArray(pPushDescriptorSetWithTemplateInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdSetDescriptorBufferOffsets2EXTArgs* CommandRecorder::RecordCmdSetDescriptorBufferOffsets2EXT(
    VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo) {
    auto* args = Alloc<CmdSetDescriptorBufferOffsets2EXTArgs>();
    args->commandBuffer = commandBuffer;
    if (pSetDescriptorBufferOffsetsInfo) {
        args->pSetDescriptorBufferOffsetsInfo =
            CopyArray(pSetDescriptorBufferOffsetsInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdBindDescriptorBufferEmbeddedSamplers2EXTArgs* CommandRecorder::RecordCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    VkCommandBuffer commandBuffer,
    const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo) {
    auto* args = Alloc<CmdBindDescriptorBufferEmbeddedSamplers2EXTArgs>();
    args->commandBuffer = commandBuffer;
    if (pBindDescriptorBufferEmbeddedSamplersInfo) {
        args->pBindDescriptorBufferEmbeddedSamplersInfo =
            CopyArray(pBindDescriptorBufferEmbeddedSamplersInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdDebugMarkerBeginEXTArgs* CommandRecorder::RecordCmdDebugMarkerBeginEXT(
    VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
    auto* args = Alloc<CmdDebugMarkerBeginEXTArgs>();
    args->commandBuffer = commandBuffer;
    if (pMarkerInfo) {
        args->pMarkerInfo = CopyArray(pMarkerInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdDebugMarkerEndEXTArgs* CommandRecorder::RecordCmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) {
    auto* args = Alloc<CmdDebugMarkerEndEXTArgs>();
    args->commandBuffer = commandBuffer;
    return args;
}

CmdDebugMarkerInsertEXTArgs* CommandRecorder::RecordCmdDebugMarkerInsertEXT(
    VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
    auto* args = Alloc<CmdDebugMarkerInsertEXTArgs>();
    args->commandBuffer = commandBuffer;
    if (pMarkerInfo) {
        args->pMarkerInfo = CopyArray(pMarkerInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdBindTransformFeedbackBuffersEXTArgs* CommandRecorder::RecordCmdBindTransformFeedbackBuffersEXT(
    VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers,
    const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes) {
    auto* args = Alloc<CmdBindTransformFeedbackBuffersEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->firstBinding = firstBinding;
    args->bindingCount = bindingCount;
    if (pBuffers) {
        args->pBuffers = CopyArray(pBuffers, static_cast<size_t>(0U), static_cast<size_t>(bindingCount));
    }
    if (pOffsets) {
        args->pOffsets = CopyArray(pOffsets, static_cast<size_t>(0U), static_cast<size_t>(bindingCount));
    }
    if (pSizes) {
        args->pSizes = CopyArray(pSizes, static_cast<size_t>(0U), static_cast<size_t>(bindingCount));
    }
    return args;
}

CmdBeginTransformFeedbackEXTArgs* CommandRecorder::RecordCmdBeginTransformFeedbackEXT(
    VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount,
    const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) {
    auto* args = Alloc<CmdBeginTransformFeedbackEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->firstCounterBuffer = firstCounterBuffer;
    args->counterBufferCount = counterBufferCount;
    if (pCounterBuffers) {
        args->pCounterBuffers =
            CopyArray(pCounterBuffers, static_cast<size_t>(0U), static_cast<size_t>(counterBufferCount));
    }
    if (pCounterBufferOffsets) {
        args->pCounterBufferOffsets =
            CopyArray(pCounterBufferOffsets, static_cast<size_t>(0U), static_cast<size_t>(counterBufferCount));
    }
    return args;
}

CmdEndTransformFeedbackEXTArgs* CommandRecorder::RecordCmdEndTransformFeedbackEXT(
    VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount,
    const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) {
    auto* args = Alloc<CmdEndTransformFeedbackEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->firstCounterBuffer = firstCounterBuffer;
    args->counterBufferCount = counterBufferCount;
    if (pCounterBuffers) {
        args->pCounterBuffers =
            CopyArray(pCounterBuffers, static_cast<size_t>(0U), static_cast<size_t>(counterBufferCount));
    }
    if (pCounterBufferOffsets) {
        args->pCounterBufferOffsets =
            CopyArray(pCounterBufferOffsets, static_cast<size_t>(0U), static_cast<size_t>(counterBufferCount));
    }
    return args;
}

CmdBeginQueryIndexedEXTArgs* CommandRecorder::RecordCmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer,
                                                                            VkQueryPool queryPool, uint32_t query,
                                                                            VkQueryControlFlags flags, uint32_t index) {
    auto* args = Alloc<CmdBeginQueryIndexedEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->queryPool = queryPool;
    args->query = query;
    args->flags = flags;
    args->index = index;
    return args;
}

CmdEndQueryIndexedEXTArgs* CommandRecorder::RecordCmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer,
                                                                        VkQueryPool queryPool, uint32_t query,
                                                                        uint32_t index) {
    auto* args = Alloc<CmdEndQueryIndexedEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->queryPool = queryPool;
    args->query = query;
    args->index = index;
    return args;
}

CmdDrawIndirectByteCountEXTArgs* CommandRecorder::RecordCmdDrawIndirectByteCountEXT(
    VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer,
    VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride) {
    auto* args = Alloc<CmdDrawIndirectByteCountEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->instanceCount = instanceCount;
    args->firstInstance = firstInstance;
    args->counterBuffer = counterBuffer;
    args->counterBufferOffset = counterBufferOffset;
    args->counterOffset = counterOffset;
    args->vertexStride = vertexStride;
    return args;
}

CmdCuLaunchKernelNVXArgs* CommandRecorder::RecordCmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer,
                                                                      const VkCuLaunchInfoNVX* pLaunchInfo) {
    auto* args = Alloc<CmdCuLaunchKernelNVXArgs>();
    args->commandBuffer = commandBuffer;
    if (pLaunchInfo) {
        args->pLaunchInfo = CopyArray(pLaunchInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdDrawIndirectCountAMDArgs* CommandRecorder::RecordCmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer,
                                                                            VkBuffer buffer, VkDeviceSize offset,
                                                                            VkBuffer countBuffer,
                                                                            VkDeviceSize countBufferOffset,
                                                                            uint32_t maxDrawCount, uint32_t stride) {
    auto* args = Alloc<CmdDrawIndirectCountAMDArgs>();
    args->commandBuffer = commandBuffer;
    args->buffer = buffer;
    args->offset = offset;
    args->countBuffer = countBuffer;
    args->countBufferOffset = countBufferOffset;
    args->maxDrawCount = maxDrawCount;
    args->stride = stride;
    return args;
}

CmdDrawIndexedIndirectCountAMDArgs* CommandRecorder::RecordCmdDrawIndexedIndirectCountAMD(
    VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer,
    VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
    auto* args = Alloc<CmdDrawIndexedIndirectCountAMDArgs>();
    args->commandBuffer = commandBuffer;
    args->buffer = buffer;
    args->offset = offset;
    args->countBuffer = countBuffer;
    args->countBufferOffset = countBufferOffset;
    args->maxDrawCount = maxDrawCount;
    args->stride = stride;
    return args;
}

CmdBeginConditionalRenderingEXTArgs* CommandRecorder::RecordCmdBeginConditionalRenderingEXT(
    VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) {
    auto* args = Alloc<CmdBeginConditionalRenderingEXTArgs>();
    args->commandBuffer = commandBuffer;
    if (pConditionalRenderingBegin) {
        args->pConditionalRenderingBegin =
            CopyArray(pConditionalRenderingBegin, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdEndConditionalRenderingEXTArgs* CommandRecorder::RecordCmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer) {
    auto* args = Alloc<CmdEndConditionalRenderingEXTArgs>();
    args->commandBuffer = commandBuffer;
    return args;
}

CmdSetViewportWScalingNVArgs* CommandRecorder::RecordCmdSetViewportWScalingNV(
    VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
    const VkViewportWScalingNV* pViewportWScalings) {
    auto* args = Alloc<CmdSetViewportWScalingNVArgs>();
    args->commandBuffer = commandBuffer;
    args->firstViewport = firstViewport;
    args->viewportCount = viewportCount;
    if (pViewportWScalings) {
        args->pViewportWScalings =
            CopyArray(pViewportWScalings, static_cast<size_t>(0U), static_cast<size_t>(viewportCount));
    }
    return args;
}

CmdSetDiscardRectangleEXTArgs* CommandRecorder::RecordCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer,
                                                                                uint32_t firstDiscardRectangle,
                                                                                uint32_t discardRectangleCount,
                                                                                const VkRect2D* pDiscardRectangles) {
    auto* args = Alloc<CmdSetDiscardRectangleEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->firstDiscardRectangle = firstDiscardRectangle;
    args->discardRectangleCount = discardRectangleCount;
    if (pDiscardRectangles) {
        args->pDiscardRectangles =
            CopyArray(pDiscardRectangles, static_cast<size_t>(0U), static_cast<size_t>(discardRectangleCount));
    }
    return args;
}

CmdSetDiscardRectangleEnableEXTArgs* CommandRecorder::RecordCmdSetDiscardRectangleEnableEXT(
    VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable) {
    auto* args = Alloc<CmdSetDiscardRectangleEnableEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->discardRectangleEnable = discardRectangleEnable;
    return args;
}

CmdSetDiscardRectangleModeEXTArgs* CommandRecorder::RecordCmdSetDiscardRectangleModeEXT(
    VkCommandBuffer commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode) {
    auto* args = Alloc<CmdSetDiscardRectangleModeEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->discardRectangleMode = discardRectangleMode;
    return args;
}

CmdBeginDebugUtilsLabelEXTArgs* CommandRecorder::RecordCmdBeginDebugUtilsLabelEXT(
    VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {
    auto* args = Alloc<CmdBeginDebugUtilsLabelEXTArgs>();
    args->commandBuffer = commandBuffer;
    if (pLabelInfo) {
        args->pLabelInfo = CopyArray(pLabelInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdEndDebugUtilsLabelEXTArgs* CommandRecorder::RecordCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) {
    auto* args = Alloc<CmdEndDebugUtilsLabelEXTArgs>();
    args->commandBuffer = commandBuffer;
    return args;
}

CmdInsertDebugUtilsLabelEXTArgs* CommandRecorder::RecordCmdInsertDebugUtilsLabelEXT(
    VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {
    auto* args = Alloc<CmdInsertDebugUtilsLabelEXTArgs>();
    args->commandBuffer = commandBuffer;
    if (pLabelInfo) {
        args->pLabelInfo = CopyArray(pLabelInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

#ifdef VK_ENABLE_BETA_EXTENSIONS
CmdInitializeGraphScratchMemoryAMDXArgs* CommandRecorder::RecordCmdInitializeGraphScratchMemoryAMDX(
    VkCommandBuffer commandBuffer, VkDeviceAddress scratch) {
    auto* args = Alloc<CmdInitializeGraphScratchMemoryAMDXArgs>();
    args->commandBuffer = commandBuffer;
    args->scratch = scratch;
    return args;
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
CmdDispatchGraphAMDXArgs* CommandRecorder::RecordCmdDispatchGraphAMDX(VkCommandBuffer commandBuffer,
                                                                      VkDeviceAddress scratch,
                                                                      const VkDispatchGraphCountInfoAMDX* pCountInfo) {
    auto* args = Alloc<CmdDispatchGraphAMDXArgs>();
    args->commandBuffer = commandBuffer;
    args->scratch = scratch;
    if (pCountInfo) {
        args->pCountInfo = CopyArray(pCountInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
CmdDispatchGraphIndirectAMDXArgs* CommandRecorder::RecordCmdDispatchGraphIndirectAMDX(
    VkCommandBuffer commandBuffer, VkDeviceAddress scratch, const VkDispatchGraphCountInfoAMDX* pCountInfo) {
    auto* args = Alloc<CmdDispatchGraphIndirectAMDXArgs>();
    args->commandBuffer = commandBuffer;
    args->scratch = scratch;
    if (pCountInfo) {
        args->pCountInfo = CopyArray(pCountInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
CmdDispatchGraphIndirectCountAMDXArgs* CommandRecorder::RecordCmdDispatchGraphIndirectCountAMDX(
    VkCommandBuffer commandBuffer, VkDeviceAddress scratch, VkDeviceAddress countInfo) {
    auto* args = Alloc<CmdDispatchGraphIndirectCountAMDXArgs>();
    args->commandBuffer = commandBuffer;
    args->scratch = scratch;
    args->countInfo = countInfo;
    return args;
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

CmdSetSampleLocationsEXTArgs* CommandRecorder::RecordCmdSetSampleLocationsEXT(
    VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo) {
    auto* args = Alloc<CmdSetSampleLocationsEXTArgs>();
    args->commandBuffer = commandBuffer;
    if (pSampleLocationsInfo) {
        args->pSampleLocationsInfo = CopyArray(pSampleLocationsInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdBindShadingRateImageNVArgs* CommandRecorder::RecordCmdBindShadingRateImageNV(VkCommandBuffer commandBuffer,
                                                                                VkImageView imageView,
                                                                                VkImageLayout imageLayout) {
    auto* args = Alloc<CmdBindShadingRateImageNVArgs>();
    args->commandBuffer = commandBuffer;
    args->imageView = imageView;
    args->imageLayout = imageLayout;
    return args;
}

CmdSetViewportShadingRatePaletteNVArgs* CommandRecorder::RecordCmdSetViewportShadingRatePaletteNV(
    VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
    const VkShadingRatePaletteNV* pShadingRatePalettes) {
    auto* args = Alloc<CmdSetViewportShadingRatePaletteNVArgs>();
    args->commandBuffer = commandBuffer;
    args->firstViewport = firstViewport;
    args->viewportCount = viewportCount;
    if (pShadingRatePalettes) {
        args->pShadingRatePalettes =
            CopyArray(pShadingRatePalettes, static_cast<size_t>(0U), static_cast<size_t>(viewportCount));
    }
    return args;
}

CmdSetCoarseSampleOrderNVArgs* CommandRecorder::RecordCmdSetCoarseSampleOrderNV(
    VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount,
    const VkCoarseSampleOrderCustomNV* pCustomSampleOrders) {
    auto* args = Alloc<CmdSetCoarseSampleOrderNVArgs>();
    args->commandBuffer = commandBuffer;
    args->sampleOrderType = sampleOrderType;
    args->customSampleOrderCount = customSampleOrderCount;
    if (pCustomSampleOrders) {
        args->pCustomSampleOrders =
            CopyArray(pCustomSampleOrders, static_cast<size_t>(0U), static_cast<size_t>(customSampleOrderCount));
    }
    return args;
}

CmdBuildAccelerationStructureNVArgs* CommandRecorder::RecordCmdBuildAccelerationStructureNV(
    VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData,
    VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src,
    VkBuffer scratch, VkDeviceSize scratchOffset) {
    auto* args = Alloc<CmdBuildAccelerationStructureNVArgs>();
    args->commandBuffer = commandBuffer;
    if (pInfo) {
        args->pInfo = CopyArray(pInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    args->instanceData = instanceData;
    args->instanceOffset = instanceOffset;
    args->update = update;
    args->dst = dst;
    args->src = src;
    args->scratch = scratch;
    args->scratchOffset = scratchOffset;
    return args;
}

CmdCopyAccelerationStructureNVArgs* CommandRecorder::RecordCmdCopyAccelerationStructureNV(
    VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst, VkAccelerationStructureNV src,
    VkCopyAccelerationStructureModeKHR mode) {
    auto* args = Alloc<CmdCopyAccelerationStructureNVArgs>();
    args->commandBuffer = commandBuffer;
    args->dst = dst;
    args->src = src;
    args->mode = mode;
    return args;
}

CmdTraceRaysNVArgs* CommandRecorder::RecordCmdTraceRaysNV(
    VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset,
    VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride,
    VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride,
    VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset,
    VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth) {
    auto* args = Alloc<CmdTraceRaysNVArgs>();
    args->commandBuffer = commandBuffer;
    args->raygenShaderBindingTableBuffer = raygenShaderBindingTableBuffer;
    args->raygenShaderBindingOffset = raygenShaderBindingOffset;
    args->missShaderBindingTableBuffer = missShaderBindingTableBuffer;
    args->missShaderBindingOffset = missShaderBindingOffset;
    args->missShaderBindingStride = missShaderBindingStride;
    args->hitShaderBindingTableBuffer = hitShaderBindingTableBuffer;
    args->hitShaderBindingOffset = hitShaderBindingOffset;
    args->hitShaderBindingStride = hitShaderBindingStride;
    args->callableShaderBindingTableBuffer = callableShaderBindingTableBuffer;
    args->callableShaderBindingOffset = callableShaderBindingOffset;
    args->callableShaderBindingStride = callableShaderBindingStride;
    args->width = width;
    args->height = height;
    args->depth = depth;
    return args;
}

CmdWriteAccelerationStructuresPropertiesNVArgs* CommandRecorder::RecordCmdWriteAccelerationStructuresPropertiesNV(
    VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
    const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool,
    uint32_t firstQuery) {
    auto* args = Alloc<CmdWriteAccelerationStructuresPropertiesNVArgs>();
    args->commandBuffer = commandBuffer;
    args->accelerationStructureCount = accelerationStructureCount;
    if (pAccelerationStructures) {
        args->pAccelerationStructures = CopyArray(pAccelerationStructures, static_cast<size_t>(0U),
                                                  static_cast<size_t>(accelerationStructureCount));
    }
    args->queryType = queryType;
    args->queryPool = queryPool;
    args->firstQuery = firstQuery;
    return args;
}

CmdWriteBufferMarkerAMDArgs* CommandRecorder::RecordCmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer,
                                                                            VkPipelineStageFlagBits pipelineStage,
                                                                            VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                                                            uint32_t marker) {
    auto* args = Alloc<CmdWriteBufferMarkerAMDArgs>();
    args->commandBuffer = commandBuffer;
    args->pipelineStage = pipelineStage;
    args->dstBuffer = dstBuffer;
    args->dstOffset = dstOffset;
    args->marker = marker;
    return args;
}

CmdDrawMeshTasksNVArgs* CommandRecorder::RecordCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount,
                                                                  uint32_t firstTask) {
    auto* args = Alloc<CmdDrawMeshTasksNVArgs>();
    args->commandBuffer = commandBuffer;
    args->taskCount = taskCount;
    args->firstTask = firstTask;
    return args;
}

CmdDrawMeshTasksIndirectNVArgs* CommandRecorder::RecordCmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer,
                                                                                  VkBuffer buffer, VkDeviceSize offset,
                                                                                  uint32_t drawCount, uint32_t stride) {
    auto* args = Alloc<CmdDrawMeshTasksIndirectNVArgs>();
    args->commandBuffer = commandBuffer;
    args->buffer = buffer;
    args->offset = offset;
    args->drawCount = drawCount;
    args->stride = stride;
    return args;
}

CmdDrawMeshTasksIndirectCountNVArgs* CommandRecorder::RecordCmdDrawMeshTasksIndirectCountNV(
    VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer,
    VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
    auto* args = Alloc<CmdDrawMeshTasksIndirectCountNVArgs>();
    args->commandBuffer = commandBuffer;
    args->buffer = buffer;
    args->offset = offset;
    args->countBuffer = countBuffer;
    args->countBufferOffset = countBufferOffset;
    args->maxDrawCount = maxDrawCount;
    args->stride = stride;
    return args;
}

CmdSetExclusiveScissorEnableNVArgs* CommandRecorder::RecordCmdSetExclusiveScissorEnableNV(
    VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount,
    const VkBool32* pExclusiveScissorEnables) {
    auto* args = Alloc<CmdSetExclusiveScissorEnableNVArgs>();
    args->commandBuffer = commandBuffer;
    args->firstExclusiveScissor = firstExclusiveScissor;
    args->exclusiveScissorCount = exclusiveScissorCount;
    if (pExclusiveScissorEnables) {
        args->pExclusiveScissorEnables =
            CopyArray(pExclusiveScissorEnables, static_cast<size_t>(0U), static_cast<size_t>(exclusiveScissorCount));
    }
    return args;
}

CmdSetExclusiveScissorNVArgs* CommandRecorder::RecordCmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer,
                                                                              uint32_t firstExclusiveScissor,
                                                                              uint32_t exclusiveScissorCount,
                                                                              const VkRect2D* pExclusiveScissors) {
    auto* args = Alloc<CmdSetExclusiveScissorNVArgs>();
    args->commandBuffer = commandBuffer;
    args->firstExclusiveScissor = firstExclusiveScissor;
    args->exclusiveScissorCount = exclusiveScissorCount;
    if (pExclusiveScissors) {
        args->pExclusiveScissors =
            CopyArray(pExclusiveScissors, static_cast<size_t>(0U), static_cast<size_t>(exclusiveScissorCount));
    }
    return args;
}

CmdSetCheckpointNVArgs* CommandRecorder::RecordCmdSetCheckpointNV(VkCommandBuffer commandBuffer,
                                                                  const void* pCheckpointMarker) {
    auto* args = Alloc<CmdSetCheckpointNVArgs>();
    args->commandBuffer = commandBuffer;
    args->pCheckpointMarker = pCheckpointMarker;
    return args;
}

CmdSetPerformanceMarkerINTELArgs* CommandRecorder::RecordCmdSetPerformanceMarkerINTEL(
    VkCommandBuffer commandBuffer, const VkPerformanceMarkerInfoINTEL* pMarkerInfo) {
    auto* args = Alloc<CmdSetPerformanceMarkerINTELArgs>();
    args->commandBuffer = commandBuffer;
    if (pMarkerInfo) {
        args->pMarkerInfo = CopyArray(pMarkerInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdSetPerformanceStreamMarkerINTELArgs* CommandRecorder::RecordCmdSetPerformanceStreamMarkerINTEL(
    VkCommandBuffer commandBuffer, const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo) {
    auto* args = Alloc<CmdSetPerformanceStreamMarkerINTELArgs>();
    args->commandBuffer = commandBuffer;
    if (pMarkerInfo) {
        args->pMarkerInfo = CopyArray(pMarkerInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdSetPerformanceOverrideINTELArgs* CommandRecorder::RecordCmdSetPerformanceOverrideINTEL(
    VkCommandBuffer commandBuffer, const VkPerformanceOverrideInfoINTEL* pOverrideInfo) {
    auto* args = Alloc<CmdSetPerformanceOverrideINTELArgs>();
    args->commandBuffer = commandBuffer;
    if (pOverrideInfo) {
        args->pOverrideInfo = CopyArray(pOverrideInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdSetLineStippleEXTArgs* CommandRecorder::RecordCmdSetLineStippleEXT(VkCommandBuffer commandBuffer,
                                                                      uint32_t lineStippleFactor,
                                                                      uint16_t lineStipplePattern) {
    auto* args = Alloc<CmdSetLineStippleEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->lineStippleFactor = lineStippleFactor;
    args->lineStipplePattern = lineStipplePattern;
    return args;
}

CmdSetCullModeEXTArgs* CommandRecorder::RecordCmdSetCullModeEXT(VkCommandBuffer commandBuffer,
                                                                VkCullModeFlags cullMode) {
    auto* args = Alloc<CmdSetCullModeEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->cullMode = cullMode;
    return args;
}

CmdSetFrontFaceEXTArgs* CommandRecorder::RecordCmdSetFrontFaceEXT(VkCommandBuffer commandBuffer,
                                                                  VkFrontFace frontFace) {
    auto* args = Alloc<CmdSetFrontFaceEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->frontFace = frontFace;
    return args;
}

CmdSetPrimitiveTopologyEXTArgs* CommandRecorder::RecordCmdSetPrimitiveTopologyEXT(
    VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {
    auto* args = Alloc<CmdSetPrimitiveTopologyEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->primitiveTopology = primitiveTopology;
    return args;
}

CmdSetViewportWithCountEXTArgs* CommandRecorder::RecordCmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer,
                                                                                  uint32_t viewportCount,
                                                                                  const VkViewport* pViewports) {
    auto* args = Alloc<CmdSetViewportWithCountEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->viewportCount = viewportCount;
    if (pViewports) {
        args->pViewports = CopyArray(pViewports, static_cast<size_t>(0U), static_cast<size_t>(viewportCount));
    }
    return args;
}

CmdSetScissorWithCountEXTArgs* CommandRecorder::RecordCmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer,
                                                                                uint32_t scissorCount,
                                                                                const VkRect2D* pScissors) {
    auto* args = Alloc<CmdSetScissorWithCountEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->scissorCount = scissorCount;
    if (pScissors) {
        args->pScissors = CopyArray(pScissors, static_cast<size_t>(0U), static_cast<size_t>(scissorCount));
    }
    return args;
}

CmdBindVertexBuffers2EXTArgs* CommandRecorder::RecordCmdBindVertexBuffers2EXT(
    VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers,
    const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) {
    auto* args = Alloc<CmdBindVertexBuffers2EXTArgs>();
    args->commandBuffer = commandBuffer;
    args->firstBinding = firstBinding;
    args->bindingCount = bindingCount;
    if (pBuffers) {
        args->pBuffers = CopyArray(pBuffers, static_cast<size_t>(0U), static_cast<size_t>(bindingCount));
    }
    if (pOffsets) {
        args->pOffsets = CopyArray(pOffsets, static_cast<size_t>(0U), static_cast<size_t>(bindingCount));
    }
    if (pSizes) {
        args->pSizes = CopyArray(pSizes, static_cast<size_t>(0U), static_cast<size_t>(bindingCount));
    }
    if (pStrides) {
        args->pStrides = CopyArray(pStrides, static_cast<size_t>(0U), static_cast<size_t>(bindingCount));
    }
    return args;
}

CmdSetDepthTestEnableEXTArgs* CommandRecorder::RecordCmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer,
                                                                              VkBool32 depthTestEnable) {
    auto* args = Alloc<CmdSetDepthTestEnableEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->depthTestEnable = depthTestEnable;
    return args;
}

CmdSetDepthWriteEnableEXTArgs* CommandRecorder::RecordCmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer,
                                                                                VkBool32 depthWriteEnable) {
    auto* args = Alloc<CmdSetDepthWriteEnableEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->depthWriteEnable = depthWriteEnable;
    return args;
}

CmdSetDepthCompareOpEXTArgs* CommandRecorder::RecordCmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer,
                                                                            VkCompareOp depthCompareOp) {
    auto* args = Alloc<CmdSetDepthCompareOpEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->depthCompareOp = depthCompareOp;
    return args;
}

CmdSetDepthBoundsTestEnableEXTArgs* CommandRecorder::RecordCmdSetDepthBoundsTestEnableEXT(
    VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
    auto* args = Alloc<CmdSetDepthBoundsTestEnableEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->depthBoundsTestEnable = depthBoundsTestEnable;
    return args;
}

CmdSetStencilTestEnableEXTArgs* CommandRecorder::RecordCmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer,
                                                                                  VkBool32 stencilTestEnable) {
    auto* args = Alloc<CmdSetStencilTestEnableEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->stencilTestEnable = stencilTestEnable;
    return args;
}

CmdSetStencilOpEXTArgs* CommandRecorder::RecordCmdSetStencilOpEXT(VkCommandBuffer commandBuffer,
                                                                  VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                                                  VkStencilOp passOp, VkStencilOp depthFailOp,
                                                                  VkCompareOp compareOp) {
    auto* args = Alloc<CmdSetStencilOpEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->faceMask = faceMask;
    args->failOp = failOp;
    args->passOp = passOp;
    args->depthFailOp = depthFailOp;
    args->compareOp = compareOp;
    return args;
}

CmdPreprocessGeneratedCommandsNVArgs* CommandRecorder::RecordCmdPreprocessGeneratedCommandsNV(
    VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
    auto* args = Alloc<CmdPreprocessGeneratedCommandsNVArgs>();
    args->commandBuffer = commandBuffer;
    if (pGeneratedCommandsInfo) {
        args->pGeneratedCommandsInfo =
            CopyArray(pGeneratedCommandsInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdExecuteGeneratedCommandsNVArgs* CommandRecorder::RecordCmdExecuteGeneratedCommandsNV(
    VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
    auto* args = Alloc<CmdExecuteGeneratedCommandsNVArgs>();
    args->commandBuffer = commandBuffer;
    args->isPreprocessed = isPreprocessed;
    if (pGeneratedCommandsInfo) {
        args->pGeneratedCommandsInfo =
            CopyArray(pGeneratedCommandsInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdBindPipelineShaderGroupNVArgs* CommandRecorder::RecordCmdBindPipelineShaderGroupNV(
    VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, uint32_t groupIndex) {
    auto* args = Alloc<CmdBindPipelineShaderGroupNVArgs>();
    args->commandBuffer = commandBuffer;
    args->pipelineBindPoint = pipelineBindPoint;
    args->pipeline = pipeline;
    args->groupIndex = groupIndex;
    return args;
}

CmdSetDepthBias2EXTArgs* CommandRecorder::RecordCmdSetDepthBias2EXT(VkCommandBuffer commandBuffer,
                                                                    const VkDepthBiasInfoEXT* pDepthBiasInfo) {
    auto* args = Alloc<CmdSetDepthBias2EXTArgs>();
    args->commandBuffer = commandBuffer;
    if (pDepthBiasInfo) {
        args->pDepthBiasInfo = CopyArray(pDepthBiasInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdCudaLaunchKernelNVArgs* CommandRecorder::RecordCmdCudaLaunchKernelNV(VkCommandBuffer commandBuffer,
                                                                        const VkCudaLaunchInfoNV* pLaunchInfo) {
    auto* args = Alloc<CmdCudaLaunchKernelNVArgs>();
    args->commandBuffer = commandBuffer;
    if (pLaunchInfo) {
        args->pLaunchInfo = CopyArray(pLaunchInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdBindDescriptorBuffersEXTArgs* CommandRecorder::RecordCmdBindDescriptorBuffersEXT(
    VkCommandBuffer commandBuffer, uint32_t bufferCount, const VkDescriptorBufferBindingInfoEXT* pBindingInfos) {
    auto* args = Alloc<CmdBindDescriptorBuffersEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->bufferCount = bufferCount;
    if (pBindingInfos) {
        args->pBindingInfos = CopyArray(pBindingInfos, static_cast<size_t>(0U), static_cast<size_t>(bufferCount));
    }
    return args;
}

CmdSetDescriptorBufferOffsetsEXTArgs* CommandRecorder::RecordCmdSetDescriptorBufferOffsetsEXT(
    VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet,
    uint32_t setCount, const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets) {
    auto* args = Alloc<CmdSetDescriptorBufferOffsetsEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->pipelineBindPoint = pipelineBindPoint;
    args->layout = layout;
    args->firstSet = firstSet;
    args->setCount = setCount;
    if (pBufferIndices) {
        args->pBufferIndices = CopyArray(pBufferIndices, static_cast<size_t>(0U), static_cast<size_t>(setCount));
    }
    if (pOffsets) {
        args->pOffsets = CopyArray(pOffsets, static_cast<size_t>(0U), static_cast<size_t>(setCount));
    }
    return args;
}

CmdBindDescriptorBufferEmbeddedSamplersEXTArgs* CommandRecorder::RecordCmdBindDescriptorBufferEmbeddedSamplersEXT(
    VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set) {
    auto* args = Alloc<CmdBindDescriptorBufferEmbeddedSamplersEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->pipelineBindPoint = pipelineBindPoint;
    args->layout = layout;
    args->set = set;
    return args;
}

CmdSetFragmentShadingRateEnumNVArgs* CommandRecorder::RecordCmdSetFragmentShadingRateEnumNV(
    VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate,
    const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    auto* args = Alloc<CmdSetFragmentShadingRateEnumNVArgs>();
    args->commandBuffer = commandBuffer;
    args->shadingRate = shadingRate;
    for (uint32_t i = 0; i < 2; ++i) {
        args->combinerOps[i] = combinerOps[i];
    }
    return args;
}

CmdSetVertexInputEXTArgs* CommandRecorder::RecordCmdSetVertexInputEXT(
    VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
    const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount,
    const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) {
    auto* args = Alloc<CmdSetVertexInputEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->vertexBindingDescriptionCount = vertexBindingDescriptionCount;
    if (pVertexBindingDescriptions) {
        args->pVertexBindingDescriptions = CopyArray(pVertexBindingDescriptions, static_cast<size_t>(0U),
                                                     static_cast<size_t>(vertexBindingDescriptionCount));
    }
    args->vertexAttributeDescriptionCount = vertexAttributeDescriptionCount;
    if (pVertexAttributeDescriptions) {
        args->pVertexAttributeDescriptions = CopyArray(pVertexAttributeDescriptions, static_cast<size_t>(0U),
                                                       static_cast<size_t>(vertexAttributeDescriptionCount));
    }
    return args;
}

CmdSubpassShadingHUAWEIArgs* CommandRecorder::RecordCmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer) {
    auto* args = Alloc<CmdSubpassShadingHUAWEIArgs>();
    args->commandBuffer = commandBuffer;
    return args;
}

CmdBindInvocationMaskHUAWEIArgs* CommandRecorder::RecordCmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer,
                                                                                    VkImageView imageView,
                                                                                    VkImageLayout imageLayout) {
    auto* args = Alloc<CmdBindInvocationMaskHUAWEIArgs>();
    args->commandBuffer = commandBuffer;
    args->imageView = imageView;
    args->imageLayout = imageLayout;
    return args;
}

CmdSetPatchControlPointsEXTArgs* CommandRecorder::RecordCmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer,
                                                                                    uint32_t patchControlPoints) {
    auto* args = Alloc<CmdSetPatchControlPointsEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->patchControlPoints = patchControlPoints;
    return args;
}

CmdSetRasterizerDiscardEnableEXTArgs* CommandRecorder::RecordCmdSetRasterizerDiscardEnableEXT(
    VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {
    auto* args = Alloc<CmdSetRasterizerDiscardEnableEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->rasterizerDiscardEnable = rasterizerDiscardEnable;
    return args;
}

CmdSetDepthBiasEnableEXTArgs* CommandRecorder::RecordCmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer,
                                                                              VkBool32 depthBiasEnable) {
    auto* args = Alloc<CmdSetDepthBiasEnableEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->depthBiasEnable = depthBiasEnable;
    return args;
}

CmdSetLogicOpEXTArgs* CommandRecorder::RecordCmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp) {
    auto* args = Alloc<CmdSetLogicOpEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->logicOp = logicOp;
    return args;
}

CmdSetPrimitiveRestartEnableEXTArgs* CommandRecorder::RecordCmdSetPrimitiveRestartEnableEXT(
    VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {
    auto* args = Alloc<CmdSetPrimitiveRestartEnableEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->primitiveRestartEnable = primitiveRestartEnable;
    return args;
}

CmdSetColorWriteEnableEXTArgs* CommandRecorder::RecordCmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer,
                                                                                uint32_t attachmentCount,
                                                                                const VkBool32* pColorWriteEnables) {
    auto* args = Alloc<CmdSetColorWriteEnableEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->attachmentCount = attachmentCount;
    if (pColorWriteEnables) {
        args->pColorWriteEnables =
            CopyArray(pColorWriteEnables, static_cast<size_t>(0U), static_cast<size_t>(attachmentCount));
    }
    return args;
}

CmdDrawMultiEXTArgs* CommandRecorder::RecordCmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                                            const VkMultiDrawInfoEXT* pVertexInfo,
                                                            uint32_t instanceCount, uint32_t firstInstance,
                                                            uint32_t stride) {
    auto* args = Alloc<CmdDrawMultiEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->drawCount = drawCount;
    if (pVertexInfo) {
        args->pVertexInfo = CopyArray(pVertexInfo, static_cast<size_t>(0U), static_cast<size_t>(drawCount));
    }
    args->instanceCount = instanceCount;
    args->firstInstance = firstInstance;
    args->stride = stride;
    return args;
}

CmdDrawMultiIndexedEXTArgs* CommandRecorder::RecordCmdDrawMultiIndexedEXT(
    VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawIndexedInfoEXT* pIndexInfo,
    uint32_t instanceCount, uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset) {
    auto* args = Alloc<CmdDrawMultiIndexedEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->drawCount = drawCount;
    if (pIndexInfo) {
        args->pIndexInfo = CopyArray(pIndexInfo, static_cast<size_t>(0U), static_cast<size_t>(drawCount));
    }
    args->instanceCount = instanceCount;
    args->firstInstance = firstInstance;
    args->stride = stride;
    if (pVertexOffset) {
        args->pVertexOffset = CopyArray(pVertexOffset, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdBuildMicromapsEXTArgs* CommandRecorder::RecordCmdBuildMicromapsEXT(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                                                      const VkMicromapBuildInfoEXT* pInfos) {
    auto* args = Alloc<CmdBuildMicromapsEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->infoCount = infoCount;
    if (pInfos) {
        args->pInfos = CopyArray(pInfos, static_cast<size_t>(0U), static_cast<size_t>(infoCount));
    }
    return args;
}

CmdCopyMicromapEXTArgs* CommandRecorder::RecordCmdCopyMicromapEXT(VkCommandBuffer commandBuffer,
                                                                  const VkCopyMicromapInfoEXT* pInfo) {
    auto* args = Alloc<CmdCopyMicromapEXTArgs>();
    args->commandBuffer = commandBuffer;
    if (pInfo) {
        args->pInfo = CopyArray(pInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdCopyMicromapToMemoryEXTArgs* CommandRecorder::RecordCmdCopyMicromapToMemoryEXT(
    VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo) {
    auto* args = Alloc<CmdCopyMicromapToMemoryEXTArgs>();
    args->commandBuffer = commandBuffer;
    if (pInfo) {
        args->pInfo = CopyArray(pInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdCopyMemoryToMicromapEXTArgs* CommandRecorder::RecordCmdCopyMemoryToMicromapEXT(
    VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo) {
    auto* args = Alloc<CmdCopyMemoryToMicromapEXTArgs>();
    args->commandBuffer = commandBuffer;
    if (pInfo) {
        args->pInfo = CopyArray(pInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdWriteMicromapsPropertiesEXTArgs* CommandRecorder::RecordCmdWriteMicromapsPropertiesEXT(
    VkCommandBuffer commandBuffer, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType,
    VkQueryPool queryPool, uint32_t firstQuery) {
    auto* args = Alloc<CmdWriteMicromapsPropertiesEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->micromapCount = micromapCount;
    if (pMicromaps) {
        args->pMicromaps = CopyArray(pMicromaps, static_cast<size_t>(0U), static_cast<size_t>(micromapCount));
    }
    args->queryType = queryType;
    args->queryPool = queryPool;
    args->firstQuery = firstQuery;
    return args;
}

CmdDrawClusterHUAWEIArgs* CommandRecorder::RecordCmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer,
                                                                      uint32_t groupCountX, uint32_t groupCountY,
                                                                      uint32_t groupCountZ) {
    auto* args = Alloc<CmdDrawClusterHUAWEIArgs>();
    args->commandBuffer = commandBuffer;
    args->groupCountX = groupCountX;
    args->groupCountY = groupCountY;
    args->groupCountZ = groupCountZ;
    return args;
}

CmdDrawClusterIndirectHUAWEIArgs* CommandRecorder::RecordCmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer,
                                                                                      VkBuffer buffer,
                                                                                      VkDeviceSize offset) {
    auto* args = Alloc<CmdDrawClusterIndirectHUAWEIArgs>();
    args->commandBuffer = commandBuffer;
    args->buffer = buffer;
    args->offset = offset;
    return args;
}

CmdCopyMemoryIndirectNVArgs* CommandRecorder::RecordCmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer,
                                                                            VkDeviceAddress copyBufferAddress,
                                                                            uint32_t copyCount, uint32_t stride) {
    auto* args = Alloc<CmdCopyMemoryIndirectNVArgs>();
    args->commandBuffer = commandBuffer;
    args->copyBufferAddress = copyBufferAddress;
    args->copyCount = copyCount;
    args->stride = stride;
    return args;
}

CmdCopyMemoryToImageIndirectNVArgs* CommandRecorder::RecordCmdCopyMemoryToImageIndirectNV(
    VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride,
    VkImage dstImage, VkImageLayout dstImageLayout, const VkImageSubresourceLayers* pImageSubresources) {
    auto* args = Alloc<CmdCopyMemoryToImageIndirectNVArgs>();
    args->commandBuffer = commandBuffer;
    args->copyBufferAddress = copyBufferAddress;
    args->copyCount = copyCount;
    args->stride = stride;
    args->dstImage = dstImage;
    args->dstImageLayout = dstImageLayout;
    if (pImageSubresources) {
        args->pImageSubresources =
            CopyArray(pImageSubresources, static_cast<size_t>(0U), static_cast<size_t>(copyCount));
    }
    return args;
}

CmdDecompressMemoryNVArgs* CommandRecorder::RecordCmdDecompressMemoryNV(
    VkCommandBuffer commandBuffer, uint32_t decompressRegionCount,
    const VkDecompressMemoryRegionNV* pDecompressMemoryRegions) {
    auto* args = Alloc<CmdDecompressMemoryNVArgs>();
    args->commandBuffer = commandBuffer;
    args->decompressRegionCount = decompressRegionCount;
    if (pDecompressMemoryRegions) {
        args->pDecompressMemoryRegions =
            CopyArray(pDecompressMemoryRegions, static_cast<size_t>(0U), static_cast<size_t>(decompressRegionCount));
    }
    return args;
}

CmdDecompressMemoryIndirectCountNVArgs* CommandRecorder::RecordCmdDecompressMemoryIndirectCountNV(
    VkCommandBuffer commandBuffer, VkDeviceAddress indirectCommandsAddress,
    VkDeviceAddress indirectCommandsCountAddress, uint32_t stride) {
    auto* args = Alloc<CmdDecompressMemoryIndirectCountNVArgs>();
    args->commandBuffer = commandBuffer;
    args->indirectCommandsAddress = indirectCommandsAddress;
    args->indirectCommandsCountAddress = indirectCommandsCountAddress;
    args->stride = stride;
    return args;
}

CmdUpdatePipelineIndirectBufferNVArgs* CommandRecorder::RecordCmdUpdatePipelineIndirectBufferNV(
    VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) {
    auto* args = Alloc<CmdUpdatePipelineIndirectBufferNVArgs>();
    args->commandBuffer = commandBuffer;
    args->pipelineBindPoint = pipelineBindPoint;
    args->pipeline = pipeline;
    return args;
}

CmdSetDepthClampEnableEXTArgs* CommandRecorder::RecordCmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer,
                                                                                VkBool32 depthClampEnable) {
    auto* args = Alloc<CmdSetDepthClampEnableEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->depthClampEnable = depthClampEnable;
    return args;
}

CmdSetPolygonModeEXTArgs* CommandRecorder::RecordCmdSetPolygonModeEXT(VkCommandBuffer commandBuffer,
                                                                      VkPolygonMode polygonMode) {
    auto* args = Alloc<CmdSetPolygonModeEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->polygonMode = polygonMode;
    return args;
}

CmdSetRasterizationSamplesEXTArgs* CommandRecorder::RecordCmdSetRasterizationSamplesEXT(
    VkCommandBuffer commandBuffer, VkSampleCountFlagBits rasterizationSamples) {
    auto* args = Alloc<CmdSetRasterizationSamplesEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->rasterizationSamples = rasterizationSamples;
    return args;
}

CmdSetSampleMaskEXTArgs* CommandRecorder::RecordCmdSetSampleMaskEXT(VkCommandBuffer commandBuffer,
                                                                    VkSampleCountFlagBits samples,
                                                                    const VkSampleMask* pSampleMask) {
    auto* args = Alloc<CmdSetSampleMaskEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->samples = samples;
    if (pSampleMask) {
        args->pSampleMask = CopyArray(pSampleMask, static_cast<size_t>(0U), static_cast<size_t>((samples + 31) / 32));
    }
    return args;
}

CmdSetAlphaToCoverageEnableEXTArgs* CommandRecorder::RecordCmdSetAlphaToCoverageEnableEXT(
    VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable) {
    auto* args = Alloc<CmdSetAlphaToCoverageEnableEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->alphaToCoverageEnable = alphaToCoverageEnable;
    return args;
}

CmdSetAlphaToOneEnableEXTArgs* CommandRecorder::RecordCmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer,
                                                                                VkBool32 alphaToOneEnable) {
    auto* args = Alloc<CmdSetAlphaToOneEnableEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->alphaToOneEnable = alphaToOneEnable;
    return args;
}

CmdSetLogicOpEnableEXTArgs* CommandRecorder::RecordCmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer,
                                                                          VkBool32 logicOpEnable) {
    auto* args = Alloc<CmdSetLogicOpEnableEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->logicOpEnable = logicOpEnable;
    return args;
}

CmdSetColorBlendEnableEXTArgs* CommandRecorder::RecordCmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer,
                                                                                uint32_t firstAttachment,
                                                                                uint32_t attachmentCount,
                                                                                const VkBool32* pColorBlendEnables) {
    auto* args = Alloc<CmdSetColorBlendEnableEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->firstAttachment = firstAttachment;
    args->attachmentCount = attachmentCount;
    if (pColorBlendEnables) {
        args->pColorBlendEnables =
            CopyArray(pColorBlendEnables, static_cast<size_t>(0U), static_cast<size_t>(attachmentCount));
    }
    return args;
}

CmdSetColorBlendEquationEXTArgs* CommandRecorder::RecordCmdSetColorBlendEquationEXT(
    VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
    const VkColorBlendEquationEXT* pColorBlendEquations) {
    auto* args = Alloc<CmdSetColorBlendEquationEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->firstAttachment = firstAttachment;
    args->attachmentCount = attachmentCount;
    if (pColorBlendEquations) {
        args->pColorBlendEquations =
            CopyArray(pColorBlendEquations, static_cast<size_t>(0U), static_cast<size_t>(attachmentCount));
    }
    return args;
}

CmdSetColorWriteMaskEXTArgs* CommandRecorder::RecordCmdSetColorWriteMaskEXT(
    VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
    const VkColorComponentFlags* pColorWriteMasks) {
    auto* args = Alloc<CmdSetColorWriteMaskEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->firstAttachment = firstAttachment;
    args->attachmentCount = attachmentCount;
    if (pColorWriteMasks) {
        args->pColorWriteMasks =
            CopyArray(pColorWriteMasks, static_cast<size_t>(0U), static_cast<size_t>(attachmentCount));
    }
    return args;
}

CmdSetTessellationDomainOriginEXTArgs* CommandRecorder::RecordCmdSetTessellationDomainOriginEXT(
    VkCommandBuffer commandBuffer, VkTessellationDomainOrigin domainOrigin) {
    auto* args = Alloc<CmdSetTessellationDomainOriginEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->domainOrigin = domainOrigin;
    return args;
}

CmdSetRasterizationStreamEXTArgs* CommandRecorder::RecordCmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer,
                                                                                      uint32_t rasterizationStream) {
    auto* args = Alloc<CmdSetRasterizationStreamEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->rasterizationStream = rasterizationStream;
    return args;
}

CmdSetConservativeRasterizationModeEXTArgs* CommandRecorder::RecordCmdSetConservativeRasterizationModeEXT(
    VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode) {
    auto* args = Alloc<CmdSetConservativeRasterizationModeEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->conservativeRasterizationMode = conservativeRasterizationMode;
    return args;
}

CmdSetExtraPrimitiveOverestimationSizeEXTArgs* CommandRecorder::RecordCmdSetExtraPrimitiveOverestimationSizeEXT(
    VkCommandBuffer commandBuffer, float extraPrimitiveOverestimationSize) {
    auto* args = Alloc<CmdSetExtraPrimitiveOverestimationSizeEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->extraPrimitiveOverestimationSize = extraPrimitiveOverestimationSize;
    return args;
}

CmdSetDepthClipEnableEXTArgs* CommandRecorder::RecordCmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer,
                                                                              VkBool32 depthClipEnable) {
    auto* args = Alloc<CmdSetDepthClipEnableEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->depthClipEnable = depthClipEnable;
    return args;
}

CmdSetSampleLocationsEnableEXTArgs* CommandRecorder::RecordCmdSetSampleLocationsEnableEXT(
    VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable) {
    auto* args = Alloc<CmdSetSampleLocationsEnableEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->sampleLocationsEnable = sampleLocationsEnable;
    return args;
}

CmdSetColorBlendAdvancedEXTArgs* CommandRecorder::RecordCmdSetColorBlendAdvancedEXT(
    VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
    const VkColorBlendAdvancedEXT* pColorBlendAdvanced) {
    auto* args = Alloc<CmdSetColorBlendAdvancedEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->firstAttachment = firstAttachment;
    args->attachmentCount = attachmentCount;
    if (pColorBlendAdvanced) {
        args->pColorBlendAdvanced =
            CopyArray(pColorBlendAdvanced, static_cast<size_t>(0U), static_cast<size_t>(attachmentCount));
    }
    return args;
}

CmdSetProvokingVertexModeEXTArgs* CommandRecorder::RecordCmdSetProvokingVertexModeEXT(
    VkCommandBuffer commandBuffer, VkProvokingVertexModeEXT provokingVertexMode) {
    auto* args = Alloc<CmdSetProvokingVertexModeEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->provokingVertexMode = provokingVertexMode;
    return args;
}

CmdSetLineRasterizationModeEXTArgs* CommandRecorder::RecordCmdSetLineRasterizationModeEXT(
    VkCommandBuffer commandBuffer, VkLineRasterizationModeEXT lineRasterizationMode) {
    auto* args = Alloc<CmdSetLineRasterizationModeEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->lineRasterizationMode = lineRasterizationMode;
    return args;
}

CmdSetLineStippleEnableEXTArgs* CommandRecorder::RecordCmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer,
                                                                                  VkBool32 stippledLineEnable) {
    auto* args = Alloc<CmdSetLineStippleEnableEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->stippledLineEnable = stippledLineEnable;
    return args;
}

CmdSetDepthClipNegativeOneToOneEXTArgs* CommandRecorder::RecordCmdSetDepthClipNegativeOneToOneEXT(
    VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne) {
    auto* args = Alloc<CmdSetDepthClipNegativeOneToOneEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->negativeOneToOne = negativeOneToOne;
    return args;
}

CmdSetViewportWScalingEnableNVArgs* CommandRecorder::RecordCmdSetViewportWScalingEnableNV(
    VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable) {
    auto* args = Alloc<CmdSetViewportWScalingEnableNVArgs>();
    args->commandBuffer = commandBuffer;
    args->viewportWScalingEnable = viewportWScalingEnable;
    return args;
}

CmdSetViewportSwizzleNVArgs* CommandRecorder::RecordCmdSetViewportSwizzleNV(
    VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
    const VkViewportSwizzleNV* pViewportSwizzles) {
    auto* args = Alloc<CmdSetViewportSwizzleNVArgs>();
    args->commandBuffer = commandBuffer;
    args->firstViewport = firstViewport;
    args->viewportCount = viewportCount;
    if (pViewportSwizzles) {
        args->pViewportSwizzles =
            CopyArray(pViewportSwizzles, static_cast<size_t>(0U), static_cast<size_t>(viewportCount));
    }
    return args;
}

CmdSetCoverageToColorEnableNVArgs* CommandRecorder::RecordCmdSetCoverageToColorEnableNV(
    VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable) {
    auto* args = Alloc<CmdSetCoverageToColorEnableNVArgs>();
    args->commandBuffer = commandBuffer;
    args->coverageToColorEnable = coverageToColorEnable;
    return args;
}

CmdSetCoverageToColorLocationNVArgs* CommandRecorder::RecordCmdSetCoverageToColorLocationNV(
    VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation) {
    auto* args = Alloc<CmdSetCoverageToColorLocationNVArgs>();
    args->commandBuffer = commandBuffer;
    args->coverageToColorLocation = coverageToColorLocation;
    return args;
}

CmdSetCoverageModulationModeNVArgs* CommandRecorder::RecordCmdSetCoverageModulationModeNV(
    VkCommandBuffer commandBuffer, VkCoverageModulationModeNV coverageModulationMode) {
    auto* args = Alloc<CmdSetCoverageModulationModeNVArgs>();
    args->commandBuffer = commandBuffer;
    args->coverageModulationMode = coverageModulationMode;
    return args;
}

CmdSetCoverageModulationTableEnableNVArgs* CommandRecorder::RecordCmdSetCoverageModulationTableEnableNV(
    VkCommandBuffer commandBuffer, VkBool32 coverageModulationTableEnable) {
    auto* args = Alloc<CmdSetCoverageModulationTableEnableNVArgs>();
    args->commandBuffer = commandBuffer;
    args->coverageModulationTableEnable = coverageModulationTableEnable;
    return args;
}

CmdSetCoverageModulationTableNVArgs* CommandRecorder::RecordCmdSetCoverageModulationTableNV(
    VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount, const float* pCoverageModulationTable) {
    auto* args = Alloc<CmdSetCoverageModulationTableNVArgs>();
    args->commandBuffer = commandBuffer;
    args->coverageModulationTableCount = coverageModulationTableCount;
    if (pCoverageModulationTable) {
        args->pCoverageModulationTable = CopyArray(pCoverageModulationTable, static_cast<size_t>(0U),
                                                   static_cast<size_t>(coverageModulationTableCount));
    }
    return args;
}

CmdSetShadingRateImageEnableNVArgs* CommandRecorder::RecordCmdSetShadingRateImageEnableNV(
    VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable) {
    auto* args = Alloc<CmdSetShadingRateImageEnableNVArgs>();
    args->commandBuffer = commandBuffer;
    args->shadingRateImageEnable = shadingRateImageEnable;
    return args;
}

CmdSetRepresentativeFragmentTestEnableNVArgs* CommandRecorder::RecordCmdSetRepresentativeFragmentTestEnableNV(
    VkCommandBuffer commandBuffer, VkBool32 representativeFragmentTestEnable) {
    auto* args = Alloc<CmdSetRepresentativeFragmentTestEnableNVArgs>();
    args->commandBuffer = commandBuffer;
    args->representativeFragmentTestEnable = representativeFragmentTestEnable;
    return args;
}

CmdSetCoverageReductionModeNVArgs* CommandRecorder::RecordCmdSetCoverageReductionModeNV(
    VkCommandBuffer commandBuffer, VkCoverageReductionModeNV coverageReductionMode) {
    auto* args = Alloc<CmdSetCoverageReductionModeNVArgs>();
    args->commandBuffer = commandBuffer;
    args->coverageReductionMode = coverageReductionMode;
    return args;
}

CmdOpticalFlowExecuteNVArgs* CommandRecorder::RecordCmdOpticalFlowExecuteNV(
    VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session, const VkOpticalFlowExecuteInfoNV* pExecuteInfo) {
    auto* args = Alloc<CmdOpticalFlowExecuteNVArgs>();
    args->commandBuffer = commandBuffer;
    args->session = session;
    if (pExecuteInfo) {
        args->pExecuteInfo = CopyArray(pExecuteInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdBindShadersEXTArgs* CommandRecorder::RecordCmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount,
                                                                const VkShaderStageFlagBits* pStages,
                                                                const VkShaderEXT* pShaders) {
    auto* args = Alloc<CmdBindShadersEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->stageCount = stageCount;
    if (pStages) {
        args->pStages = CopyArray(pStages, static_cast<size_t>(0U), static_cast<size_t>(stageCount));
    }
    if (pShaders) {
        args->pShaders = CopyArray(pShaders, static_cast<size_t>(0U), static_cast<size_t>(stageCount));
    }
    return args;
}

CmdSetDepthClampRangeEXTArgs* CommandRecorder::RecordCmdSetDepthClampRangeEXT(
    VkCommandBuffer commandBuffer, VkDepthClampModeEXT depthClampMode, const VkDepthClampRangeEXT* pDepthClampRange) {
    auto* args = Alloc<CmdSetDepthClampRangeEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->depthClampMode = depthClampMode;
    if (pDepthClampRange) {
        args->pDepthClampRange = CopyArray(pDepthClampRange, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdSetAttachmentFeedbackLoopEnableEXTArgs* CommandRecorder::RecordCmdSetAttachmentFeedbackLoopEnableEXT(
    VkCommandBuffer commandBuffer, VkImageAspectFlags aspectMask) {
    auto* args = Alloc<CmdSetAttachmentFeedbackLoopEnableEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->aspectMask = aspectMask;
    return args;
}

CmdPreprocessGeneratedCommandsEXTArgs* CommandRecorder::RecordCmdPreprocessGeneratedCommandsEXT(
    VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo,
    VkCommandBuffer stateCommandBuffer) {
    auto* args = Alloc<CmdPreprocessGeneratedCommandsEXTArgs>();
    args->commandBuffer = commandBuffer;
    if (pGeneratedCommandsInfo) {
        args->pGeneratedCommandsInfo =
            CopyArray(pGeneratedCommandsInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    args->stateCommandBuffer = stateCommandBuffer;
    return args;
}

CmdExecuteGeneratedCommandsEXTArgs* CommandRecorder::RecordCmdExecuteGeneratedCommandsEXT(
    VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo) {
    auto* args = Alloc<CmdExecuteGeneratedCommandsEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->isPreprocessed = isPreprocessed;
    if (pGeneratedCommandsInfo) {
        args->pGeneratedCommandsInfo =
            CopyArray(pGeneratedCommandsInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdBuildAccelerationStructuresKHRArgs* CommandRecorder::RecordCmdBuildAccelerationStructuresKHR(
    VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) {
    auto* args = Alloc<CmdBuildAccelerationStructuresKHRArgs>();
    args->commandBuffer = commandBuffer;
    args->infoCount = infoCount;
    if (pInfos) {
        args->pInfos = CopyArray(pInfos, static_cast<size_t>(0U), static_cast<size_t>(infoCount));
    }
    if (ppBuildRangeInfos) {
        args->ppBuildRangeInfos = CopyArray(ppBuildRangeInfos, static_cast<size_t>(0U), static_cast<size_t>(infoCount));
    }
    return args;
}

CmdBuildAccelerationStructuresIndirectKHRArgs* CommandRecorder::RecordCmdBuildAccelerationStructuresIndirectKHR(
    VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkDeviceAddress* pIndirectDeviceAddresses, const uint32_t* pIndirectStrides,
    const uint32_t* const* ppMaxPrimitiveCounts) {
    auto* args = Alloc<CmdBuildAccelerationStructuresIndirectKHRArgs>();
    args->commandBuffer = commandBuffer;
    args->infoCount = infoCount;
    if (pInfos) {
        args->pInfos = CopyArray(pInfos, static_cast<size_t>(0U), static_cast<size_t>(infoCount));
    }
    if (pIndirectDeviceAddresses) {
        args->pIndirectDeviceAddresses =
            CopyArray(pIndirectDeviceAddresses, static_cast<size_t>(0U), static_cast<size_t>(infoCount));
    }
    if (pIndirectStrides) {
        args->pIndirectStrides = CopyArray(pIndirectStrides, static_cast<size_t>(0U), static_cast<size_t>(infoCount));
    }
    if (ppMaxPrimitiveCounts) {
        args->ppMaxPrimitiveCounts =
            CopyArray(ppMaxPrimitiveCounts, static_cast<size_t>(0U), static_cast<size_t>(infoCount));
    }
    return args;
}

CmdCopyAccelerationStructureKHRArgs* CommandRecorder::RecordCmdCopyAccelerationStructureKHR(
    VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo) {
    auto* args = Alloc<CmdCopyAccelerationStructureKHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pInfo) {
        args->pInfo = CopyArray(pInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdCopyAccelerationStructureToMemoryKHRArgs* CommandRecorder::RecordCmdCopyAccelerationStructureToMemoryKHR(
    VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) {
    auto* args = Alloc<CmdCopyAccelerationStructureToMemoryKHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pInfo) {
        args->pInfo = CopyArray(pInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdCopyMemoryToAccelerationStructureKHRArgs* CommandRecorder::RecordCmdCopyMemoryToAccelerationStructureKHR(
    VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) {
    auto* args = Alloc<CmdCopyMemoryToAccelerationStructureKHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pInfo) {
        args->pInfo = CopyArray(pInfo, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    return args;
}

CmdWriteAccelerationStructuresPropertiesKHRArgs* CommandRecorder::RecordCmdWriteAccelerationStructuresPropertiesKHR(
    VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
    const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool,
    uint32_t firstQuery) {
    auto* args = Alloc<CmdWriteAccelerationStructuresPropertiesKHRArgs>();
    args->commandBuffer = commandBuffer;
    args->accelerationStructureCount = accelerationStructureCount;
    if (pAccelerationStructures) {
        args->pAccelerationStructures = CopyArray(pAccelerationStructures, static_cast<size_t>(0U),
                                                  static_cast<size_t>(accelerationStructureCount));
    }
    args->queryType = queryType;
    args->queryPool = queryPool;
    args->firstQuery = firstQuery;
    return args;
}

CmdTraceRaysKHRArgs* CommandRecorder::RecordCmdTraceRaysKHR(
    VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width, uint32_t height,
    uint32_t depth) {
    auto* args = Alloc<CmdTraceRaysKHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pRaygenShaderBindingTable) {
        args->pRaygenShaderBindingTable =
            CopyArray(pRaygenShaderBindingTable, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    if (pMissShaderBindingTable) {
        args->pMissShaderBindingTable =
            CopyArray(pMissShaderBindingTable, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    if (pHitShaderBindingTable) {
        args->pHitShaderBindingTable =
            CopyArray(pHitShaderBindingTable, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    if (pCallableShaderBindingTable) {
        args->pCallableShaderBindingTable =
            CopyArray(pCallableShaderBindingTable, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    args->width = width;
    args->height = height;
    args->depth = depth;
    return args;
}

CmdTraceRaysIndirectKHRArgs* CommandRecorder::RecordCmdTraceRaysIndirectKHR(
    VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress) {
    auto* args = Alloc<CmdTraceRaysIndirectKHRArgs>();
    args->commandBuffer = commandBuffer;
    if (pRaygenShaderBindingTable) {
        args->pRaygenShaderBindingTable =
            CopyArray(pRaygenShaderBindingTable, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    if (pMissShaderBindingTable) {
        args->pMissShaderBindingTable =
            CopyArray(pMissShaderBindingTable, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    if (pHitShaderBindingTable) {
        args->pHitShaderBindingTable =
            CopyArray(pHitShaderBindingTable, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    if (pCallableShaderBindingTable) {
        args->pCallableShaderBindingTable =
            CopyArray(pCallableShaderBindingTable, static_cast<size_t>(0U), static_cast<size_t>(1U));
    }
    args->indirectDeviceAddress = indirectDeviceAddress;
    return args;
}

CmdSetRayTracingPipelineStackSizeKHRArgs* CommandRecorder::RecordCmdSetRayTracingPipelineStackSizeKHR(
    VkCommandBuffer commandBuffer, uint32_t pipelineStackSize) {
    auto* args = Alloc<CmdSetRayTracingPipelineStackSizeKHRArgs>();
    args->commandBuffer = commandBuffer;
    args->pipelineStackSize = pipelineStackSize;
    return args;
}

CmdDrawMeshTasksEXTArgs* CommandRecorder::RecordCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX,
                                                                    uint32_t groupCountY, uint32_t groupCountZ) {
    auto* args = Alloc<CmdDrawMeshTasksEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->groupCountX = groupCountX;
    args->groupCountY = groupCountY;
    args->groupCountZ = groupCountZ;
    return args;
}

CmdDrawMeshTasksIndirectEXTArgs* CommandRecorder::RecordCmdDrawMeshTasksIndirectEXT(
    VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) {
    auto* args = Alloc<CmdDrawMeshTasksIndirectEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->buffer = buffer;
    args->offset = offset;
    args->drawCount = drawCount;
    args->stride = stride;
    return args;
}

CmdDrawMeshTasksIndirectCountEXTArgs* CommandRecorder::RecordCmdDrawMeshTasksIndirectCountEXT(
    VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer,
    VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
    auto* args = Alloc<CmdDrawMeshTasksIndirectCountEXTArgs>();
    args->commandBuffer = commandBuffer;
    args->buffer = buffer;
    args->offset = offset;
    args->countBuffer = countBuffer;
    args->countBufferOffset = countBufferOffset;
    args->maxDrawCount = maxDrawCount;
    args->stride = stride;
    return args;
}

// NOLINTEND
