
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

#include <cstring>
#include <iostream>
#include <vector>
#include <vulkan/vulkan.h>

#include "linear_allocator.h"
#include "command_common.h"

class CommandRecorder {
   public:
    void Reset() { m_allocator.Reset(); }
    BeginCommandBufferArgs* RecordBeginCommandBuffer(VkCommandBuffer commandBuffer,
                                                     const VkCommandBufferBeginInfo* pBeginInfo);

    EndCommandBufferArgs* RecordEndCommandBuffer(VkCommandBuffer commandBuffer);

    ResetCommandBufferArgs* RecordResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags);

    CmdBindPipelineArgs* RecordCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                               VkPipeline pipeline);

    CmdSetViewportArgs* RecordCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                             uint32_t viewportCount, const VkViewport* pViewports);

    CmdSetScissorArgs* RecordCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount,
                                           const VkRect2D* pScissors);

    CmdSetLineWidthArgs* RecordCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth);

    CmdSetDepthBiasArgs* RecordCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor,
                                               float depthBiasClamp, float depthBiasSlopeFactor);

    CmdSetBlendConstantsArgs* RecordCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]);

    CmdSetDepthBoundsArgs* RecordCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds,
                                                   float maxDepthBounds);

    CmdSetStencilCompareMaskArgs* RecordCmdSetStencilCompareMask(VkCommandBuffer commandBuffer,
                                                                 VkStencilFaceFlags faceMask, uint32_t compareMask);

    CmdSetStencilWriteMaskArgs* RecordCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                                             uint32_t writeMask);

    CmdSetStencilReferenceArgs* RecordCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                                             uint32_t reference);

    CmdBindDescriptorSetsArgs* RecordCmdBindDescriptorSets(
        VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout,
        uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets,
        uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets);

    CmdBindIndexBufferArgs* RecordCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                     VkDeviceSize offset, VkIndexType indexType);

    CmdBindVertexBuffersArgs* RecordCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                         uint32_t bindingCount, const VkBuffer* pBuffers,
                                                         const VkDeviceSize* pOffsets);

    CmdDrawArgs* RecordCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount,
                               uint32_t firstVertex, uint32_t firstInstance);

    CmdDrawIndexedArgs* RecordCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount,
                                             uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance);

    CmdDrawIndirectArgs* RecordCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                               uint32_t drawCount, uint32_t stride);

    CmdDrawIndexedIndirectArgs* RecordCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                             VkDeviceSize offset, uint32_t drawCount, uint32_t stride);

    CmdDispatchArgs* RecordCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                       uint32_t groupCountZ);

    CmdDispatchIndirectArgs* RecordCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                       VkDeviceSize offset);

    CmdCopyBufferArgs* RecordCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer,
                                           uint32_t regionCount, const VkBufferCopy* pRegions);

    CmdCopyImageArgs* RecordCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                         VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                         const VkImageCopy* pRegions);

    CmdBlitImageArgs* RecordCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                         VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                         const VkImageBlit* pRegions, VkFilter filter);

    CmdCopyBufferToImageArgs* RecordCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer,
                                                         VkImage dstImage, VkImageLayout dstImageLayout,
                                                         uint32_t regionCount, const VkBufferImageCopy* pRegions);

    CmdCopyImageToBufferArgs* RecordCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage,
                                                         VkImageLayout srcImageLayout, VkBuffer dstBuffer,
                                                         uint32_t regionCount, const VkBufferImageCopy* pRegions);

    CmdUpdateBufferArgs* RecordCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer,
                                               VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData);

    CmdFillBufferArgs* RecordCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                           VkDeviceSize size, uint32_t data);

    CmdClearColorImageArgs* RecordCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image,
                                                     VkImageLayout imageLayout, const VkClearColorValue* pColor,
                                                     uint32_t rangeCount, const VkImageSubresourceRange* pRanges);

    CmdClearDepthStencilImageArgs* RecordCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image,
                                                                   VkImageLayout imageLayout,
                                                                   const VkClearDepthStencilValue* pDepthStencil,
                                                                   uint32_t rangeCount,
                                                                   const VkImageSubresourceRange* pRanges);

    CmdClearAttachmentsArgs* RecordCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                                       const VkClearAttachment* pAttachments, uint32_t rectCount,
                                                       const VkClearRect* pRects);

    CmdResolveImageArgs* RecordCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage,
                                               VkImageLayout srcImageLayout, VkImage dstImage,
                                               VkImageLayout dstImageLayout, uint32_t regionCount,
                                               const VkImageResolve* pRegions);

    CmdSetEventArgs* RecordCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);

    CmdResetEventArgs* RecordCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event,
                                           VkPipelineStageFlags stageMask);

    CmdWaitEventsArgs* RecordCmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                           VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask,
                                           uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                                           uint32_t bufferMemoryBarrierCount,
                                           const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                           uint32_t imageMemoryBarrierCount,
                                           const VkImageMemoryBarrier* pImageMemoryBarriers);

    CmdPipelineBarrierArgs* RecordCmdPipelineBarrier(
        VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask,
        VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
        uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers,
        uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);

    CmdBeginQueryArgs* RecordCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                           VkQueryControlFlags flags);

    CmdEndQueryArgs* RecordCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query);

    CmdResetQueryPoolArgs* RecordCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool,
                                                   uint32_t firstQuery, uint32_t queryCount);

    CmdWriteTimestampArgs* RecordCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                                   VkQueryPool queryPool, uint32_t query);

    CmdCopyQueryPoolResultsArgs* RecordCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool,
                                                               uint32_t firstQuery, uint32_t queryCount,
                                                               VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                                               VkDeviceSize stride, VkQueryResultFlags flags);

    CmdPushConstantsArgs* RecordCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout,
                                                 VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size,
                                                 const void* pValues);

    CmdBeginRenderPassArgs* RecordCmdBeginRenderPass(VkCommandBuffer commandBuffer,
                                                     const VkRenderPassBeginInfo* pRenderPassBegin,
                                                     VkSubpassContents contents);

    CmdNextSubpassArgs* RecordCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents);

    CmdEndRenderPassArgs* RecordCmdEndRenderPass(VkCommandBuffer commandBuffer);

    CmdExecuteCommandsArgs* RecordCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount,
                                                     const VkCommandBuffer* pCommandBuffers);

    CmdSetDeviceMaskArgs* RecordCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask);

    CmdDispatchBaseArgs* RecordCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                               uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                               uint32_t groupCountZ);

    CmdDrawIndirectCountArgs* RecordCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                         VkDeviceSize offset, VkBuffer countBuffer,
                                                         VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                         uint32_t stride);

    CmdDrawIndexedIndirectCountArgs* RecordCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                                       VkDeviceSize offset, VkBuffer countBuffer,
                                                                       VkDeviceSize countBufferOffset,
                                                                       uint32_t maxDrawCount, uint32_t stride);

    CmdBeginRenderPass2Args* RecordCmdBeginRenderPass2(VkCommandBuffer commandBuffer,
                                                       const VkRenderPassBeginInfo* pRenderPassBegin,
                                                       const VkSubpassBeginInfo* pSubpassBeginInfo);

    CmdNextSubpass2Args* RecordCmdNextSubpass2(VkCommandBuffer commandBuffer,
                                               const VkSubpassBeginInfo* pSubpassBeginInfo,
                                               const VkSubpassEndInfo* pSubpassEndInfo);

    CmdEndRenderPass2Args* RecordCmdEndRenderPass2(VkCommandBuffer commandBuffer,
                                                   const VkSubpassEndInfo* pSubpassEndInfo);

    CmdSetEvent2Args* RecordCmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event,
                                         const VkDependencyInfo* pDependencyInfo);

    CmdResetEvent2Args* RecordCmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event,
                                             VkPipelineStageFlags2 stageMask);

    CmdWaitEvents2Args* RecordCmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                             const VkDependencyInfo* pDependencyInfos);

    CmdPipelineBarrier2Args* RecordCmdPipelineBarrier2(VkCommandBuffer commandBuffer,
                                                       const VkDependencyInfo* pDependencyInfo);

    CmdWriteTimestamp2Args* RecordCmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                                     VkQueryPool queryPool, uint32_t query);

    CmdCopyBuffer2Args* RecordCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);

    CmdCopyImage2Args* RecordCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);

    CmdCopyBufferToImage2Args* RecordCmdCopyBufferToImage2(VkCommandBuffer commandBuffer,
                                                           const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);

    CmdCopyImageToBuffer2Args* RecordCmdCopyImageToBuffer2(VkCommandBuffer commandBuffer,
                                                           const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);

    CmdBlitImage2Args* RecordCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);

    CmdResolveImage2Args* RecordCmdResolveImage2(VkCommandBuffer commandBuffer,
                                                 const VkResolveImageInfo2* pResolveImageInfo);

    CmdBeginRenderingArgs* RecordCmdBeginRendering(VkCommandBuffer commandBuffer,
                                                   const VkRenderingInfo* pRenderingInfo);

    CmdEndRenderingArgs* RecordCmdEndRendering(VkCommandBuffer commandBuffer);

    CmdSetCullModeArgs* RecordCmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode);

    CmdSetFrontFaceArgs* RecordCmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace);

    CmdSetPrimitiveTopologyArgs* RecordCmdSetPrimitiveTopology(VkCommandBuffer commandBuffer,
                                                               VkPrimitiveTopology primitiveTopology);

    CmdSetViewportWithCountArgs* RecordCmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                                               const VkViewport* pViewports);

    CmdSetScissorWithCountArgs* RecordCmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                                             const VkRect2D* pScissors);

    CmdBindVertexBuffers2Args* RecordCmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                           uint32_t bindingCount, const VkBuffer* pBuffers,
                                                           const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                                                           const VkDeviceSize* pStrides);

    CmdSetDepthTestEnableArgs* RecordCmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable);

    CmdSetDepthWriteEnableArgs* RecordCmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable);

    CmdSetDepthCompareOpArgs* RecordCmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp);

    CmdSetDepthBoundsTestEnableArgs* RecordCmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer,
                                                                       VkBool32 depthBoundsTestEnable);

    CmdSetStencilTestEnableArgs* RecordCmdSetStencilTestEnable(VkCommandBuffer commandBuffer,
                                                               VkBool32 stencilTestEnable);

    CmdSetStencilOpArgs* RecordCmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                               VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp,
                                               VkCompareOp compareOp);

    CmdSetRasterizerDiscardEnableArgs* RecordCmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer,
                                                                           VkBool32 rasterizerDiscardEnable);

    CmdSetDepthBiasEnableArgs* RecordCmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable);

    CmdSetPrimitiveRestartEnableArgs* RecordCmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer,
                                                                         VkBool32 primitiveRestartEnable);

    CmdBeginVideoCodingKHRArgs* RecordCmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer,
                                                             const VkVideoBeginCodingInfoKHR* pBeginInfo);

    CmdEndVideoCodingKHRArgs* RecordCmdEndVideoCodingKHR(VkCommandBuffer commandBuffer,
                                                         const VkVideoEndCodingInfoKHR* pEndCodingInfo);

    CmdControlVideoCodingKHRArgs* RecordCmdControlVideoCodingKHR(VkCommandBuffer commandBuffer,
                                                                 const VkVideoCodingControlInfoKHR* pCodingControlInfo);

    CmdDecodeVideoKHRArgs* RecordCmdDecodeVideoKHR(VkCommandBuffer commandBuffer,
                                                   const VkVideoDecodeInfoKHR* pDecodeInfo);

    CmdBeginRenderingKHRArgs* RecordCmdBeginRenderingKHR(VkCommandBuffer commandBuffer,
                                                         const VkRenderingInfo* pRenderingInfo);

    CmdEndRenderingKHRArgs* RecordCmdEndRenderingKHR(VkCommandBuffer commandBuffer);

    CmdSetDeviceMaskKHRArgs* RecordCmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask);

    CmdDispatchBaseKHRArgs* RecordCmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX,
                                                     uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX,
                                                     uint32_t groupCountY, uint32_t groupCountZ);

    CmdPushDescriptorSetKHRArgs* RecordCmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer,
                                                               VkPipelineBindPoint pipelineBindPoint,
                                                               VkPipelineLayout layout, uint32_t set,
                                                               uint32_t descriptorWriteCount,
                                                               const VkWriteDescriptorSet* pDescriptorWrites);

    CmdPushDescriptorSetWithTemplateKHRArgs* RecordCmdPushDescriptorSetWithTemplateKHR(
        VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout,
        uint32_t set, const void* pData);

    CmdBeginRenderPass2KHRArgs* RecordCmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer,
                                                             const VkRenderPassBeginInfo* pRenderPassBegin,
                                                             const VkSubpassBeginInfo* pSubpassBeginInfo);

    CmdNextSubpass2KHRArgs* RecordCmdNextSubpass2KHR(VkCommandBuffer commandBuffer,
                                                     const VkSubpassBeginInfo* pSubpassBeginInfo,
                                                     const VkSubpassEndInfo* pSubpassEndInfo);

    CmdEndRenderPass2KHRArgs* RecordCmdEndRenderPass2KHR(VkCommandBuffer commandBuffer,
                                                         const VkSubpassEndInfo* pSubpassEndInfo);

    CmdDrawIndirectCountKHRArgs* RecordCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                               VkDeviceSize offset, VkBuffer countBuffer,
                                                               VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                               uint32_t stride);

    CmdDrawIndexedIndirectCountKHRArgs* RecordCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer,
                                                                             VkBuffer buffer, VkDeviceSize offset,
                                                                             VkBuffer countBuffer,
                                                                             VkDeviceSize countBufferOffset,
                                                                             uint32_t maxDrawCount, uint32_t stride);

    CmdSetFragmentShadingRateKHRArgs* RecordCmdSetFragmentShadingRateKHR(
        VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize,
        const VkFragmentShadingRateCombinerOpKHR combinerOps[2]);

    CmdSetRenderingAttachmentLocationsKHRArgs* RecordCmdSetRenderingAttachmentLocationsKHR(
        VkCommandBuffer commandBuffer, const VkRenderingAttachmentLocationInfoKHR* pLocationInfo);

    CmdSetRenderingInputAttachmentIndicesKHRArgs* RecordCmdSetRenderingInputAttachmentIndicesKHR(
        VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfoKHR* pInputAttachmentIndexInfo);

    CmdEncodeVideoKHRArgs* RecordCmdEncodeVideoKHR(VkCommandBuffer commandBuffer,
                                                   const VkVideoEncodeInfoKHR* pEncodeInfo);

    CmdSetEvent2KHRArgs* RecordCmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event,
                                               const VkDependencyInfo* pDependencyInfo);

    CmdResetEvent2KHRArgs* RecordCmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event,
                                                   VkPipelineStageFlags2 stageMask);

    CmdWaitEvents2KHRArgs* RecordCmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount,
                                                   const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos);

    CmdPipelineBarrier2KHRArgs* RecordCmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer,
                                                             const VkDependencyInfo* pDependencyInfo);

    CmdWriteTimestamp2KHRArgs* RecordCmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                                           VkQueryPool queryPool, uint32_t query);

    CmdWriteBufferMarker2AMDArgs* RecordCmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer,
                                                                 VkPipelineStageFlags2 stage, VkBuffer dstBuffer,
                                                                 VkDeviceSize dstOffset, uint32_t marker);

    CmdCopyBuffer2KHRArgs* RecordCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer,
                                                   const VkCopyBufferInfo2* pCopyBufferInfo);

    CmdCopyImage2KHRArgs* RecordCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);

    CmdCopyBufferToImage2KHRArgs* RecordCmdCopyBufferToImage2KHR(
        VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);

    CmdCopyImageToBuffer2KHRArgs* RecordCmdCopyImageToBuffer2KHR(
        VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);

    CmdBlitImage2KHRArgs* RecordCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);

    CmdResolveImage2KHRArgs* RecordCmdResolveImage2KHR(VkCommandBuffer commandBuffer,
                                                       const VkResolveImageInfo2* pResolveImageInfo);

    CmdTraceRaysIndirect2KHRArgs* RecordCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer,
                                                                 VkDeviceAddress indirectDeviceAddress);

    CmdBindIndexBuffer2KHRArgs* RecordCmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                             VkDeviceSize offset, VkDeviceSize size,
                                                             VkIndexType indexType);

    CmdSetLineStippleKHRArgs* RecordCmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                                         uint16_t lineStipplePattern);

    CmdBindDescriptorSets2KHRArgs* RecordCmdBindDescriptorSets2KHR(
        VkCommandBuffer commandBuffer, const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo);

    CmdPushConstants2KHRArgs* RecordCmdPushConstants2KHR(VkCommandBuffer commandBuffer,
                                                         const VkPushConstantsInfoKHR* pPushConstantsInfo);

    CmdPushDescriptorSet2KHRArgs* RecordCmdPushDescriptorSet2KHR(
        VkCommandBuffer commandBuffer, const VkPushDescriptorSetInfoKHR* pPushDescriptorSetInfo);

    CmdPushDescriptorSetWithTemplate2KHRArgs* RecordCmdPushDescriptorSetWithTemplate2KHR(
        VkCommandBuffer commandBuffer,
        const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo);

    CmdSetDescriptorBufferOffsets2EXTArgs* RecordCmdSetDescriptorBufferOffsets2EXT(
        VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo);

    CmdBindDescriptorBufferEmbeddedSamplers2EXTArgs* RecordCmdBindDescriptorBufferEmbeddedSamplers2EXT(
        VkCommandBuffer commandBuffer,
        const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo);

    CmdDebugMarkerBeginEXTArgs* RecordCmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer,
                                                             const VkDebugMarkerMarkerInfoEXT* pMarkerInfo);

    CmdDebugMarkerEndEXTArgs* RecordCmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer);

    CmdDebugMarkerInsertEXTArgs* RecordCmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer,
                                                               const VkDebugMarkerMarkerInfoEXT* pMarkerInfo);

    CmdBindTransformFeedbackBuffersEXTArgs* RecordCmdBindTransformFeedbackBuffersEXT(
        VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers,
        const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes);

    CmdBeginTransformFeedbackEXTArgs* RecordCmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer,
                                                                         uint32_t firstCounterBuffer,
                                                                         uint32_t counterBufferCount,
                                                                         const VkBuffer* pCounterBuffers,
                                                                         const VkDeviceSize* pCounterBufferOffsets);

    CmdEndTransformFeedbackEXTArgs* RecordCmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer,
                                                                     uint32_t firstCounterBuffer,
                                                                     uint32_t counterBufferCount,
                                                                     const VkBuffer* pCounterBuffers,
                                                                     const VkDeviceSize* pCounterBufferOffsets);

    CmdBeginQueryIndexedEXTArgs* RecordCmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool,
                                                               uint32_t query, VkQueryControlFlags flags,
                                                               uint32_t index);

    CmdEndQueryIndexedEXTArgs* RecordCmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool,
                                                           uint32_t query, uint32_t index);

    CmdDrawIndirectByteCountEXTArgs* RecordCmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer,
                                                                       uint32_t instanceCount, uint32_t firstInstance,
                                                                       VkBuffer counterBuffer,
                                                                       VkDeviceSize counterBufferOffset,
                                                                       uint32_t counterOffset, uint32_t vertexStride);

    CmdCuLaunchKernelNVXArgs* RecordCmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer,
                                                         const VkCuLaunchInfoNVX* pLaunchInfo);

    CmdDrawIndirectCountAMDArgs* RecordCmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                               VkDeviceSize offset, VkBuffer countBuffer,
                                                               VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                               uint32_t stride);

    CmdDrawIndexedIndirectCountAMDArgs* RecordCmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer,
                                                                             VkBuffer buffer, VkDeviceSize offset,
                                                                             VkBuffer countBuffer,
                                                                             VkDeviceSize countBufferOffset,
                                                                             uint32_t maxDrawCount, uint32_t stride);

    CmdBeginConditionalRenderingEXTArgs* RecordCmdBeginConditionalRenderingEXT(
        VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin);

    CmdEndConditionalRenderingEXTArgs* RecordCmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer);

    CmdSetViewportWScalingNVArgs* RecordCmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                                                 uint32_t viewportCount,
                                                                 const VkViewportWScalingNV* pViewportWScalings);

    CmdSetDiscardRectangleEXTArgs* RecordCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer,
                                                                   uint32_t firstDiscardRectangle,
                                                                   uint32_t discardRectangleCount,
                                                                   const VkRect2D* pDiscardRectangles);

    CmdSetDiscardRectangleEnableEXTArgs* RecordCmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer,
                                                                               VkBool32 discardRectangleEnable);

    CmdSetDiscardRectangleModeEXTArgs* RecordCmdSetDiscardRectangleModeEXT(
        VkCommandBuffer commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode);

    CmdBeginDebugUtilsLabelEXTArgs* RecordCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer,
                                                                     const VkDebugUtilsLabelEXT* pLabelInfo);

    CmdEndDebugUtilsLabelEXTArgs* RecordCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer);

    CmdInsertDebugUtilsLabelEXTArgs* RecordCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer,
                                                                       const VkDebugUtilsLabelEXT* pLabelInfo);

#ifdef VK_ENABLE_BETA_EXTENSIONS
    CmdInitializeGraphScratchMemoryAMDXArgs* RecordCmdInitializeGraphScratchMemoryAMDX(VkCommandBuffer commandBuffer,
                                                                                       VkDeviceAddress scratch);
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
    CmdDispatchGraphAMDXArgs* RecordCmdDispatchGraphAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                                         const VkDispatchGraphCountInfoAMDX* pCountInfo);
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
    CmdDispatchGraphIndirectAMDXArgs* RecordCmdDispatchGraphIndirectAMDX(
        VkCommandBuffer commandBuffer, VkDeviceAddress scratch, const VkDispatchGraphCountInfoAMDX* pCountInfo);
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
    CmdDispatchGraphIndirectCountAMDXArgs* RecordCmdDispatchGraphIndirectCountAMDX(VkCommandBuffer commandBuffer,
                                                                                   VkDeviceAddress scratch,
                                                                                   VkDeviceAddress countInfo);
#endif  // VK_ENABLE_BETA_EXTENSIONS

    CmdSetSampleLocationsEXTArgs* RecordCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer,
                                                                 const VkSampleLocationsInfoEXT* pSampleLocationsInfo);

    CmdBindShadingRateImageNVArgs* RecordCmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView,
                                                                   VkImageLayout imageLayout);

    CmdSetViewportShadingRatePaletteNVArgs* RecordCmdSetViewportShadingRatePaletteNV(
        VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
        const VkShadingRatePaletteNV* pShadingRatePalettes);

    CmdSetCoarseSampleOrderNVArgs* RecordCmdSetCoarseSampleOrderNV(
        VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount,
        const VkCoarseSampleOrderCustomNV* pCustomSampleOrders);

    CmdBuildAccelerationStructureNVArgs* RecordCmdBuildAccelerationStructureNV(
        VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData,
        VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src,
        VkBuffer scratch, VkDeviceSize scratchOffset);

    CmdCopyAccelerationStructureNVArgs* RecordCmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer,
                                                                             VkAccelerationStructureNV dst,
                                                                             VkAccelerationStructureNV src,
                                                                             VkCopyAccelerationStructureModeKHR mode);

    CmdTraceRaysNVArgs* RecordCmdTraceRaysNV(
        VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset,
        VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset,
        VkDeviceSize missShaderBindingStride, VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset,
        VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer,
        VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width,
        uint32_t height, uint32_t depth);

    CmdWriteAccelerationStructuresPropertiesNVArgs* RecordCmdWriteAccelerationStructuresPropertiesNV(
        VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
        const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool,
        uint32_t firstQuery);

    CmdWriteBufferMarkerAMDArgs* RecordCmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer,
                                                               VkPipelineStageFlagBits pipelineStage,
                                                               VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                                               uint32_t marker);

    CmdDrawMeshTasksNVArgs* RecordCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount,
                                                     uint32_t firstTask);

    CmdDrawMeshTasksIndirectNVArgs* RecordCmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                                     VkDeviceSize offset, uint32_t drawCount,
                                                                     uint32_t stride);

    CmdDrawMeshTasksIndirectCountNVArgs* RecordCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer,
                                                                               VkBuffer buffer, VkDeviceSize offset,
                                                                               VkBuffer countBuffer,
                                                                               VkDeviceSize countBufferOffset,
                                                                               uint32_t maxDrawCount, uint32_t stride);

    CmdSetExclusiveScissorEnableNVArgs* RecordCmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer,
                                                                             uint32_t firstExclusiveScissor,
                                                                             uint32_t exclusiveScissorCount,
                                                                             const VkBool32* pExclusiveScissorEnables);

    CmdSetExclusiveScissorNVArgs* RecordCmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer,
                                                                 uint32_t firstExclusiveScissor,
                                                                 uint32_t exclusiveScissorCount,
                                                                 const VkRect2D* pExclusiveScissors);

    CmdSetCheckpointNVArgs* RecordCmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker);

    CmdSetPerformanceMarkerINTELArgs* RecordCmdSetPerformanceMarkerINTEL(
        VkCommandBuffer commandBuffer, const VkPerformanceMarkerInfoINTEL* pMarkerInfo);

    CmdSetPerformanceStreamMarkerINTELArgs* RecordCmdSetPerformanceStreamMarkerINTEL(
        VkCommandBuffer commandBuffer, const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo);

    CmdSetPerformanceOverrideINTELArgs* RecordCmdSetPerformanceOverrideINTEL(
        VkCommandBuffer commandBuffer, const VkPerformanceOverrideInfoINTEL* pOverrideInfo);

    CmdSetLineStippleEXTArgs* RecordCmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                                         uint16_t lineStipplePattern);

    CmdSetCullModeEXTArgs* RecordCmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode);

    CmdSetFrontFaceEXTArgs* RecordCmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace);

    CmdSetPrimitiveTopologyEXTArgs* RecordCmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer,
                                                                     VkPrimitiveTopology primitiveTopology);

    CmdSetViewportWithCountEXTArgs* RecordCmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer,
                                                                     uint32_t viewportCount,
                                                                     const VkViewport* pViewports);

    CmdSetScissorWithCountEXTArgs* RecordCmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                                                   const VkRect2D* pScissors);

    CmdBindVertexBuffers2EXTArgs* RecordCmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                                 uint32_t bindingCount, const VkBuffer* pBuffers,
                                                                 const VkDeviceSize* pOffsets,
                                                                 const VkDeviceSize* pSizes,
                                                                 const VkDeviceSize* pStrides);

    CmdSetDepthTestEnableEXTArgs* RecordCmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer,
                                                                 VkBool32 depthTestEnable);

    CmdSetDepthWriteEnableEXTArgs* RecordCmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer,
                                                                   VkBool32 depthWriteEnable);

    CmdSetDepthCompareOpEXTArgs* RecordCmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer,
                                                               VkCompareOp depthCompareOp);

    CmdSetDepthBoundsTestEnableEXTArgs* RecordCmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer,
                                                                             VkBool32 depthBoundsTestEnable);

    CmdSetStencilTestEnableEXTArgs* RecordCmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer,
                                                                     VkBool32 stencilTestEnable);

    CmdSetStencilOpEXTArgs* RecordCmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                                     VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp,
                                                     VkCompareOp compareOp);

    CmdPreprocessGeneratedCommandsNVArgs* RecordCmdPreprocessGeneratedCommandsNV(
        VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);

    CmdExecuteGeneratedCommandsNVArgs* RecordCmdExecuteGeneratedCommandsNV(
        VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
        const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);

    CmdBindPipelineShaderGroupNVArgs* RecordCmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer,
                                                                         VkPipelineBindPoint pipelineBindPoint,
                                                                         VkPipeline pipeline, uint32_t groupIndex);

    CmdSetDepthBias2EXTArgs* RecordCmdSetDepthBias2EXT(VkCommandBuffer commandBuffer,
                                                       const VkDepthBiasInfoEXT* pDepthBiasInfo);

    CmdCudaLaunchKernelNVArgs* RecordCmdCudaLaunchKernelNV(VkCommandBuffer commandBuffer,
                                                           const VkCudaLaunchInfoNV* pLaunchInfo);

    CmdBindDescriptorBuffersEXTArgs* RecordCmdBindDescriptorBuffersEXT(
        VkCommandBuffer commandBuffer, uint32_t bufferCount, const VkDescriptorBufferBindingInfoEXT* pBindingInfos);

    CmdSetDescriptorBufferOffsetsEXTArgs* RecordCmdSetDescriptorBufferOffsetsEXT(
        VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout,
        uint32_t firstSet, uint32_t setCount, const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets);

    CmdBindDescriptorBufferEmbeddedSamplersEXTArgs* RecordCmdBindDescriptorBufferEmbeddedSamplersEXT(
        VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set);

    CmdSetFragmentShadingRateEnumNVArgs* RecordCmdSetFragmentShadingRateEnumNV(
        VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate,
        const VkFragmentShadingRateCombinerOpKHR combinerOps[2]);

    CmdSetVertexInputEXTArgs* RecordCmdSetVertexInputEXT(
        VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
        const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount,
        const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions);

    CmdSubpassShadingHUAWEIArgs* RecordCmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer);

    CmdBindInvocationMaskHUAWEIArgs* RecordCmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer,
                                                                       VkImageView imageView,
                                                                       VkImageLayout imageLayout);

    CmdSetPatchControlPointsEXTArgs* RecordCmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer,
                                                                       uint32_t patchControlPoints);

    CmdSetRasterizerDiscardEnableEXTArgs* RecordCmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer,
                                                                                 VkBool32 rasterizerDiscardEnable);

    CmdSetDepthBiasEnableEXTArgs* RecordCmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer,
                                                                 VkBool32 depthBiasEnable);

    CmdSetLogicOpEXTArgs* RecordCmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp);

    CmdSetPrimitiveRestartEnableEXTArgs* RecordCmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer,
                                                                               VkBool32 primitiveRestartEnable);

    CmdSetColorWriteEnableEXTArgs* RecordCmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer,
                                                                   uint32_t attachmentCount,
                                                                   const VkBool32* pColorWriteEnables);

    CmdDrawMultiEXTArgs* RecordCmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                               const VkMultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount,
                                               uint32_t firstInstance, uint32_t stride);

    CmdDrawMultiIndexedEXTArgs* RecordCmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                                             const VkMultiDrawIndexedInfoEXT* pIndexInfo,
                                                             uint32_t instanceCount, uint32_t firstInstance,
                                                             uint32_t stride, const int32_t* pVertexOffset);

    CmdBuildMicromapsEXTArgs* RecordCmdBuildMicromapsEXT(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                                         const VkMicromapBuildInfoEXT* pInfos);

    CmdCopyMicromapEXTArgs* RecordCmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo);

    CmdCopyMicromapToMemoryEXTArgs* RecordCmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer,
                                                                     const VkCopyMicromapToMemoryInfoEXT* pInfo);

    CmdCopyMemoryToMicromapEXTArgs* RecordCmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer,
                                                                     const VkCopyMemoryToMicromapInfoEXT* pInfo);

    CmdWriteMicromapsPropertiesEXTArgs* RecordCmdWriteMicromapsPropertiesEXT(
        VkCommandBuffer commandBuffer, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType,
        VkQueryPool queryPool, uint32_t firstQuery);

    CmdDrawClusterHUAWEIArgs* RecordCmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX,
                                                         uint32_t groupCountY, uint32_t groupCountZ);

    CmdDrawClusterIndirectHUAWEIArgs* RecordCmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                                         VkDeviceSize offset);

    CmdCopyMemoryIndirectNVArgs* RecordCmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer,
                                                               VkDeviceAddress copyBufferAddress, uint32_t copyCount,
                                                               uint32_t stride);

    CmdCopyMemoryToImageIndirectNVArgs* RecordCmdCopyMemoryToImageIndirectNV(
        VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride,
        VkImage dstImage, VkImageLayout dstImageLayout, const VkImageSubresourceLayers* pImageSubresources);

    CmdDecompressMemoryNVArgs* RecordCmdDecompressMemoryNV(VkCommandBuffer commandBuffer,
                                                           uint32_t decompressRegionCount,
                                                           const VkDecompressMemoryRegionNV* pDecompressMemoryRegions);

    CmdDecompressMemoryIndirectCountNVArgs* RecordCmdDecompressMemoryIndirectCountNV(
        VkCommandBuffer commandBuffer, VkDeviceAddress indirectCommandsAddress,
        VkDeviceAddress indirectCommandsCountAddress, uint32_t stride);

    CmdUpdatePipelineIndirectBufferNVArgs* RecordCmdUpdatePipelineIndirectBufferNV(
        VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline);

    CmdSetDepthClampEnableEXTArgs* RecordCmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer,
                                                                   VkBool32 depthClampEnable);

    CmdSetPolygonModeEXTArgs* RecordCmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode);

    CmdSetRasterizationSamplesEXTArgs* RecordCmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer,
                                                                           VkSampleCountFlagBits rasterizationSamples);

    CmdSetSampleMaskEXTArgs* RecordCmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples,
                                                       const VkSampleMask* pSampleMask);

    CmdSetAlphaToCoverageEnableEXTArgs* RecordCmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer,
                                                                             VkBool32 alphaToCoverageEnable);

    CmdSetAlphaToOneEnableEXTArgs* RecordCmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer,
                                                                   VkBool32 alphaToOneEnable);

    CmdSetLogicOpEnableEXTArgs* RecordCmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable);

    CmdSetColorBlendEnableEXTArgs* RecordCmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer,
                                                                   uint32_t firstAttachment, uint32_t attachmentCount,
                                                                   const VkBool32* pColorBlendEnables);

    CmdSetColorBlendEquationEXTArgs* RecordCmdSetColorBlendEquationEXT(
        VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
        const VkColorBlendEquationEXT* pColorBlendEquations);

    CmdSetColorWriteMaskEXTArgs* RecordCmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                                               uint32_t attachmentCount,
                                                               const VkColorComponentFlags* pColorWriteMasks);

    CmdSetTessellationDomainOriginEXTArgs* RecordCmdSetTessellationDomainOriginEXT(
        VkCommandBuffer commandBuffer, VkTessellationDomainOrigin domainOrigin);

    CmdSetRasterizationStreamEXTArgs* RecordCmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer,
                                                                         uint32_t rasterizationStream);

    CmdSetConservativeRasterizationModeEXTArgs* RecordCmdSetConservativeRasterizationModeEXT(
        VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode);

    CmdSetExtraPrimitiveOverestimationSizeEXTArgs* RecordCmdSetExtraPrimitiveOverestimationSizeEXT(
        VkCommandBuffer commandBuffer, float extraPrimitiveOverestimationSize);

    CmdSetDepthClipEnableEXTArgs* RecordCmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer,
                                                                 VkBool32 depthClipEnable);

    CmdSetSampleLocationsEnableEXTArgs* RecordCmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer,
                                                                             VkBool32 sampleLocationsEnable);

    CmdSetColorBlendAdvancedEXTArgs* RecordCmdSetColorBlendAdvancedEXT(
        VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
        const VkColorBlendAdvancedEXT* pColorBlendAdvanced);

    CmdSetProvokingVertexModeEXTArgs* RecordCmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer,
                                                                         VkProvokingVertexModeEXT provokingVertexMode);

    CmdSetLineRasterizationModeEXTArgs* RecordCmdSetLineRasterizationModeEXT(
        VkCommandBuffer commandBuffer, VkLineRasterizationModeEXT lineRasterizationMode);

    CmdSetLineStippleEnableEXTArgs* RecordCmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer,
                                                                     VkBool32 stippledLineEnable);

    CmdSetDepthClipNegativeOneToOneEXTArgs* RecordCmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer,
                                                                                     VkBool32 negativeOneToOne);

    CmdSetViewportWScalingEnableNVArgs* RecordCmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer,
                                                                             VkBool32 viewportWScalingEnable);

    CmdSetViewportSwizzleNVArgs* RecordCmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                                               uint32_t viewportCount,
                                                               const VkViewportSwizzleNV* pViewportSwizzles);

    CmdSetCoverageToColorEnableNVArgs* RecordCmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer,
                                                                           VkBool32 coverageToColorEnable);

    CmdSetCoverageToColorLocationNVArgs* RecordCmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer,
                                                                               uint32_t coverageToColorLocation);

    CmdSetCoverageModulationModeNVArgs* RecordCmdSetCoverageModulationModeNV(
        VkCommandBuffer commandBuffer, VkCoverageModulationModeNV coverageModulationMode);

    CmdSetCoverageModulationTableEnableNVArgs* RecordCmdSetCoverageModulationTableEnableNV(
        VkCommandBuffer commandBuffer, VkBool32 coverageModulationTableEnable);

    CmdSetCoverageModulationTableNVArgs* RecordCmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer,
                                                                               uint32_t coverageModulationTableCount,
                                                                               const float* pCoverageModulationTable);

    CmdSetShadingRateImageEnableNVArgs* RecordCmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer,
                                                                             VkBool32 shadingRateImageEnable);

    CmdSetRepresentativeFragmentTestEnableNVArgs* RecordCmdSetRepresentativeFragmentTestEnableNV(
        VkCommandBuffer commandBuffer, VkBool32 representativeFragmentTestEnable);

    CmdSetCoverageReductionModeNVArgs* RecordCmdSetCoverageReductionModeNV(
        VkCommandBuffer commandBuffer, VkCoverageReductionModeNV coverageReductionMode);

    CmdOpticalFlowExecuteNVArgs* RecordCmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer,
                                                               VkOpticalFlowSessionNV session,
                                                               const VkOpticalFlowExecuteInfoNV* pExecuteInfo);

    CmdBindShadersEXTArgs* RecordCmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount,
                                                   const VkShaderStageFlagBits* pStages, const VkShaderEXT* pShaders);

    CmdSetDepthClampRangeEXTArgs* RecordCmdSetDepthClampRangeEXT(VkCommandBuffer commandBuffer,
                                                                 VkDepthClampModeEXT depthClampMode,
                                                                 const VkDepthClampRangeEXT* pDepthClampRange);

    CmdSetAttachmentFeedbackLoopEnableEXTArgs* RecordCmdSetAttachmentFeedbackLoopEnableEXT(
        VkCommandBuffer commandBuffer, VkImageAspectFlags aspectMask);

    CmdPreprocessGeneratedCommandsEXTArgs* RecordCmdPreprocessGeneratedCommandsEXT(
        VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo,
        VkCommandBuffer stateCommandBuffer);

    CmdExecuteGeneratedCommandsEXTArgs* RecordCmdExecuteGeneratedCommandsEXT(
        VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
        const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo);

    CmdBuildAccelerationStructuresKHRArgs* RecordCmdBuildAccelerationStructuresKHR(
        VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
        const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos);

    CmdBuildAccelerationStructuresIndirectKHRArgs* RecordCmdBuildAccelerationStructuresIndirectKHR(
        VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
        const VkDeviceAddress* pIndirectDeviceAddresses, const uint32_t* pIndirectStrides,
        const uint32_t* const* ppMaxPrimitiveCounts);

    CmdCopyAccelerationStructureKHRArgs* RecordCmdCopyAccelerationStructureKHR(
        VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo);

    CmdCopyAccelerationStructureToMemoryKHRArgs* RecordCmdCopyAccelerationStructureToMemoryKHR(
        VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo);

    CmdCopyMemoryToAccelerationStructureKHRArgs* RecordCmdCopyMemoryToAccelerationStructureKHR(
        VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo);

    CmdWriteAccelerationStructuresPropertiesKHRArgs* RecordCmdWriteAccelerationStructuresPropertiesKHR(
        VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
        const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool,
        uint32_t firstQuery);

    CmdTraceRaysKHRArgs* RecordCmdTraceRaysKHR(VkCommandBuffer commandBuffer,
                                               const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                               const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                               const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                               const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                               uint32_t width, uint32_t height, uint32_t depth);

    CmdTraceRaysIndirectKHRArgs* RecordCmdTraceRaysIndirectKHR(
        VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
        const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
        const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
        const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress);

    CmdSetRayTracingPipelineStackSizeKHRArgs* RecordCmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer,
                                                                                         uint32_t pipelineStackSize);

    CmdDrawMeshTasksEXTArgs* RecordCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX,
                                                       uint32_t groupCountY, uint32_t groupCountZ);

    CmdDrawMeshTasksIndirectEXTArgs* RecordCmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                                       VkDeviceSize offset, uint32_t drawCount,
                                                                       uint32_t stride);

    CmdDrawMeshTasksIndirectCountEXTArgs* RecordCmdDrawMeshTasksIndirectCountEXT(
        VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer,
        VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);

   private:
    template <typename T>
    T* Alloc() {
        return new (m_allocator.Alloc(sizeof(T))) T;
    }
    template <typename T>
    T* CopyArray(const T* src, size_t start_index, size_t count) {
        auto ptr = reinterpret_cast<T*>(m_allocator.Alloc(sizeof(T) * count));
        std::memcpy(ptr, src, sizeof(T) * count);
        return ptr;
    }

    LinearAllocator<> m_allocator;
};

// NOLINTEND
