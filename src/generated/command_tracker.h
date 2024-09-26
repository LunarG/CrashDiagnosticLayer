
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
 * ***   Update source file command_tracker_generator.py for modifications
 * *** ---- WARNING! ----
 *
 ****************************************************************************/

// NOLINTBEGIN

#include <string>
#include <vector>
#include <iostream>
#include <vulkan/vulkan.h>

#include "command_common.h"
#include "command_recorder.h"

class CommandTracker {
   public:
    void Reset();

    const std::vector<Command>& GetCommands() const { return commands_; }
    std::vector<Command>& GetCommands() { return commands_; }

    void BeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo);

    void EndCommandBuffer(VkCommandBuffer commandBuffer);

    void ResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags);

    void CmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline);

    void CmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                        const VkViewport* pViewports);

    void CmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount,
                       const VkRect2D* pScissors);

    void CmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth);

    void CmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp,
                         float depthBiasSlopeFactor);

    void CmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]);

    void CmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds);

    void CmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask);

    void CmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask);

    void CmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference);

    void CmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                               VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount,
                               const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount,
                               const uint32_t* pDynamicOffsets);

    void CmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType);

    void CmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                              const VkBuffer* pBuffers, const VkDeviceSize* pOffsets);

    void CmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex,
                 uint32_t firstInstance);

    void CmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex,
                        int32_t vertexOffset, uint32_t firstInstance);

    void CmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount,
                         uint32_t stride);

    void CmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount,
                                uint32_t stride);

    void CmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);

    void CmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);

    void CmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount,
                       const VkBufferCopy* pRegions);

    void CmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage,
                      VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions);

    void CmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage,
                      VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter);

    void CmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage,
                              VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions);

    void CmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                              VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions);

    void CmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                         VkDeviceSize dataSize, const void* pData);

    void CmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size,
                       uint32_t data);

    void CmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                            const VkClearColorValue* pColor, uint32_t rangeCount,
                            const VkImageSubresourceRange* pRanges);

    void CmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                   const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount,
                                   const VkImageSubresourceRange* pRanges);

    void CmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                             const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects);

    void CmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                         VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                         const VkImageResolve* pRegions);

    void CmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);

    void CmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);

    void CmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                       VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask,
                       uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                       uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                       uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);

    void CmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask,
                            VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags,
                            uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                            uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                            uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);

    void CmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags);

    void CmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query);

    void CmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                           uint32_t queryCount);

    void CmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool,
                           uint32_t query);

    void CmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                 uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride,
                                 VkQueryResultFlags flags);

    void CmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags,
                          uint32_t offset, uint32_t size, const void* pValues);

    void CmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                            VkSubpassContents contents);

    void CmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents);

    void CmdEndRenderPass(VkCommandBuffer commandBuffer);

    void CmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount,
                            const VkCommandBuffer* pCommandBuffers);

    void CmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask);

    void CmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ,
                         uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);

    void CmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer,
                              VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);

    void CmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                     VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                     uint32_t stride);

    void CmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                             const VkSubpassBeginInfo* pSubpassBeginInfo);

    void CmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                         const VkSubpassEndInfo* pSubpassEndInfo);

    void CmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo);

    void CmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo);

    void CmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask);

    void CmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                        const VkDependencyInfo* pDependencyInfos);

    void CmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo);

    void CmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool,
                            uint32_t query);

    void CmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);

    void CmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);

    void CmdCopyBufferToImage2(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);

    void CmdCopyImageToBuffer2(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);

    void CmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);

    void CmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);

    void CmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo);

    void CmdEndRendering(VkCommandBuffer commandBuffer);

    void CmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode);

    void CmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace);

    void CmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology);

    void CmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports);

    void CmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors);

    void CmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                               const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                               const VkDeviceSize* pStrides);

    void CmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable);

    void CmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable);

    void CmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp);

    void CmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable);

    void CmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable);

    void CmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                         VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);

    void CmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable);

    void CmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable);

    void CmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable);

    void CmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo);

    void CmdEndVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo);

    void CmdControlVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoCodingControlInfoKHR* pCodingControlInfo);

    void CmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo);

    void CmdBeginRenderingKHR(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo);

    void CmdEndRenderingKHR(VkCommandBuffer commandBuffer);

    void CmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask);

    void CmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                            uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);

    void CmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                 VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount,
                                 const VkWriteDescriptorSet* pDescriptorWrites);

    void CmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer,
                                             VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                             VkPipelineLayout layout, uint32_t set, const void* pData);

    void CmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                const VkSubpassBeginInfo* pSubpassBeginInfo);

    void CmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                            const VkSubpassEndInfo* pSubpassEndInfo);

    void CmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo);

    void CmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                 VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                 uint32_t stride);

    void CmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                        VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                        uint32_t stride);

    void CmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize,
                                      const VkFragmentShadingRateCombinerOpKHR combinerOps[2]);

    void CmdSetRenderingAttachmentLocationsKHR(VkCommandBuffer commandBuffer,
                                               const VkRenderingAttachmentLocationInfoKHR* pLocationInfo);

    void CmdSetRenderingInputAttachmentIndicesKHR(
        VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfoKHR* pInputAttachmentIndexInfo);

    void CmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo);

    void CmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo);

    void CmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask);

    void CmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                           const VkDependencyInfo* pDependencyInfos);

    void CmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo);

    void CmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool,
                               uint32_t query);

    void CmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkBuffer dstBuffer,
                                  VkDeviceSize dstOffset, uint32_t marker);

    void CmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);

    void CmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);

    void CmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer,
                                  const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);

    void CmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer,
                                  const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);

    void CmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);

    void CmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);

    void CmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress);

    void CmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size,
                                VkIndexType indexType);

    void CmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern);

    void CmdBindDescriptorSets2KHR(VkCommandBuffer commandBuffer,
                                   const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo);

    void CmdPushConstants2KHR(VkCommandBuffer commandBuffer, const VkPushConstantsInfoKHR* pPushConstantsInfo);

    void CmdPushDescriptorSet2KHR(VkCommandBuffer commandBuffer,
                                  const VkPushDescriptorSetInfoKHR* pPushDescriptorSetInfo);

    void CmdPushDescriptorSetWithTemplate2KHR(
        VkCommandBuffer commandBuffer,
        const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo);

    void CmdSetDescriptorBufferOffsets2EXT(VkCommandBuffer commandBuffer,
                                           const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo);

    void CmdBindDescriptorBufferEmbeddedSamplers2EXT(
        VkCommandBuffer commandBuffer,
        const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo);

    void CmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo);

    void CmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer);

    void CmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo);

    void CmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                            const VkBuffer* pBuffers, const VkDeviceSize* pOffsets,
                                            const VkDeviceSize* pSizes);

    void CmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                      uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                      const VkDeviceSize* pCounterBufferOffsets);

    void CmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                    uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                    const VkDeviceSize* pCounterBufferOffsets);

    void CmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                 VkQueryControlFlags flags, uint32_t index);

    void CmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index);

    void CmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance,
                                     VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset,
                                     uint32_t vertexStride);

    void CmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo);

    void CmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                 VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                 uint32_t stride);

    void CmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                        VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                        uint32_t stride);

    void CmdBeginConditionalRenderingEXT(VkCommandBuffer commandBuffer,
                                         const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin);

    void CmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer);

    void CmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                  const VkViewportWScalingNV* pViewportWScalings);

    void CmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle,
                                   uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles);

    void CmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable);

    void CmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode);

    void CmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo);

    void CmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer);

    void CmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo);

#ifdef VK_ENABLE_BETA_EXTENSIONS
    void CmdInitializeGraphScratchMemoryAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch);
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
    void CmdDispatchGraphAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                              const VkDispatchGraphCountInfoAMDX* pCountInfo);
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
    void CmdDispatchGraphIndirectAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                      const VkDispatchGraphCountInfoAMDX* pCountInfo);
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
    void CmdDispatchGraphIndirectCountAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                           VkDeviceAddress countInfo);
#endif  // VK_ENABLE_BETA_EXTENSIONS

    void CmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo);

    void CmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout);

    void CmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                            uint32_t viewportCount, const VkShadingRatePaletteNV* pShadingRatePalettes);

    void CmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType,
                                   uint32_t customSampleOrderCount,
                                   const VkCoarseSampleOrderCustomNV* pCustomSampleOrders);

    void CmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo,
                                         VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update,
                                         VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch,
                                         VkDeviceSize scratchOffset);

    void CmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst,
                                        VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode);

    void CmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer,
                        VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer,
                        VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride,
                        VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset,
                        VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer,
                        VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride,
                        uint32_t width, uint32_t height, uint32_t depth);

    void CmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
                                                    const VkAccelerationStructureNV* pAccelerationStructures,
                                                    VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery);

    void CmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                 VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker);

    void CmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask);

    void CmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                    uint32_t drawCount, uint32_t stride);

    void CmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                         VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                         uint32_t stride);

    void CmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                        uint32_t exclusiveScissorCount, const VkBool32* pExclusiveScissorEnables);

    void CmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                  uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors);

    void CmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker);

    void CmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceMarkerInfoINTEL* pMarkerInfo);

    void CmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer,
                                            const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo);

    void CmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer,
                                        const VkPerformanceOverrideInfoINTEL* pOverrideInfo);

    void CmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern);

    void CmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode);

    void CmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace);

    void CmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology);

    void CmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                    const VkViewport* pViewports);

    void CmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors);

    void CmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                  const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                                  const VkDeviceSize* pStrides);

    void CmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable);

    void CmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable);

    void CmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp);

    void CmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable);

    void CmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable);

    void CmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                            VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);

    void CmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer,
                                          const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);

    void CmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                       const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);

    void CmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                      VkPipeline pipeline, uint32_t groupIndex);

    void CmdSetDepthBias2EXT(VkCommandBuffer commandBuffer, const VkDepthBiasInfoEXT* pDepthBiasInfo);

    void CmdCudaLaunchKernelNV(VkCommandBuffer commandBuffer, const VkCudaLaunchInfoNV* pLaunchInfo);

    void CmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount,
                                     const VkDescriptorBufferBindingInfoEXT* pBindingInfos);

    void CmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                          VkPipelineLayout layout, uint32_t firstSet, uint32_t setCount,
                                          const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets);

    void CmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer commandBuffer,
                                                    VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout,
                                                    uint32_t set);

    void CmdSetFragmentShadingRateEnumNV(VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate,
                                         const VkFragmentShadingRateCombinerOpKHR combinerOps[2]);

    void CmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
                              const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions,
                              uint32_t vertexAttributeDescriptionCount,
                              const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions);

    void CmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer);

    void CmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout);

    void CmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints);

    void CmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable);

    void CmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable);

    void CmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp);

    void CmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable);

    void CmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                   const VkBool32* pColorWriteEnables);

    void CmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawInfoEXT* pVertexInfo,
                         uint32_t instanceCount, uint32_t firstInstance, uint32_t stride);

    void CmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount,
                                uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset);

    void CmdBuildMicromapsEXT(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos);

    void CmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo);

    void CmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo);

    void CmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo);

    void CmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount,
                                        const VkMicromapEXT* pMicromaps, VkQueryType queryType, VkQueryPool queryPool,
                                        uint32_t firstQuery);

    void CmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                              uint32_t groupCountZ);

    void CmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);

    void CmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount,
                                 uint32_t stride);

    void CmdCopyMemoryToImageIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                        uint32_t copyCount, uint32_t stride, VkImage dstImage,
                                        VkImageLayout dstImageLayout,
                                        const VkImageSubresourceLayers* pImageSubresources);

    void CmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount,
                               const VkDecompressMemoryRegionNV* pDecompressMemoryRegions);

    void CmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer, VkDeviceAddress indirectCommandsAddress,
                                            VkDeviceAddress indirectCommandsCountAddress, uint32_t stride);

    void CmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                           VkPipeline pipeline);

    void CmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClampEnable);

    void CmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode);

    void CmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits rasterizationSamples);

    void CmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples,
                             const VkSampleMask* pSampleMask);

    void CmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable);

    void CmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable);

    void CmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable);

    void CmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
                                   const VkBool32* pColorBlendEnables);

    void CmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
                                     const VkColorBlendEquationEXT* pColorBlendEquations);

    void CmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
                                 const VkColorComponentFlags* pColorWriteMasks);

    void CmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer, VkTessellationDomainOrigin domainOrigin);

    void CmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer, uint32_t rasterizationStream);

    void CmdSetConservativeRasterizationModeEXT(VkCommandBuffer commandBuffer,
                                                VkConservativeRasterizationModeEXT conservativeRasterizationMode);

    void CmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer commandBuffer,
                                                   float extraPrimitiveOverestimationSize);

    void CmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClipEnable);

    void CmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable);

    void CmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
                                     const VkColorBlendAdvancedEXT* pColorBlendAdvanced);

    void CmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer, VkProvokingVertexModeEXT provokingVertexMode);

    void CmdSetLineRasterizationModeEXT(VkCommandBuffer commandBuffer,
                                        VkLineRasterizationModeEXT lineRasterizationMode);

    void CmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable);

    void CmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne);

    void CmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable);

    void CmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                 const VkViewportSwizzleNV* pViewportSwizzles);

    void CmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable);

    void CmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation);

    void CmdSetCoverageModulationModeNV(VkCommandBuffer commandBuffer,
                                        VkCoverageModulationModeNV coverageModulationMode);

    void CmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageModulationTableEnable);

    void CmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount,
                                         const float* pCoverageModulationTable);

    void CmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable);

    void CmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer commandBuffer,
                                                  VkBool32 representativeFragmentTestEnable);

    void CmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer, VkCoverageReductionModeNV coverageReductionMode);

    void CmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session,
                                 const VkOpticalFlowExecuteInfoNV* pExecuteInfo);

    void CmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount, const VkShaderStageFlagBits* pStages,
                           const VkShaderEXT* pShaders);

    void CmdSetDepthClampRangeEXT(VkCommandBuffer commandBuffer, VkDepthClampModeEXT depthClampMode,
                                  const VkDepthClampRangeEXT* pDepthClampRange);

    void CmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer, VkImageAspectFlags aspectMask);

    void CmdPreprocessGeneratedCommandsEXT(VkCommandBuffer commandBuffer,
                                           const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo,
                                           VkCommandBuffer stateCommandBuffer);

    void CmdExecuteGeneratedCommandsEXT(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                        const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo);

    void CmdBuildAccelerationStructuresKHR(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                           const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
                                           const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos);

    void CmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                                   const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
                                                   const VkDeviceAddress* pIndirectDeviceAddresses,
                                                   const uint32_t* pIndirectStrides,
                                                   const uint32_t* const* ppMaxPrimitiveCounts);

    void CmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                         const VkCopyAccelerationStructureInfoKHR* pInfo);

    void CmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer commandBuffer,
                                                 const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo);

    void CmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                                 const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo);

    void CmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
                                                     const VkAccelerationStructureKHR* pAccelerationStructures,
                                                     VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery);

    void CmdTraceRaysKHR(VkCommandBuffer commandBuffer,
                         const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                         const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                         const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                         const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width,
                         uint32_t height, uint32_t depth);

    void CmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer,
                                 const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                 const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                 const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                 const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                 VkDeviceAddress indirectDeviceAddress);

    void CmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize);

    void CmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                             uint32_t groupCountZ);

    void CmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                     uint32_t drawCount, uint32_t stride);

    void CmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                          VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                          uint32_t stride);

   private:
    std::vector<Command> commands_;
    CommandRecorder recorder_;
    std::vector<std::string> labels_;
};

// NOLINTEND
