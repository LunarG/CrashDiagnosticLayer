
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
 * ***   Update source file intercepts_and_prepost_generator.py for modifications
 * *** ---- WARNING! ----
 *
 ****************************************************************************/

// NOLINTBEGIN

#include <vector>
#include <iostream>
#include <vulkan/vulkan.h>

#include "command_common.h"
#include "command_printer.h"
#include "command_recorder.h"

class CommandTracker {
   public:
    void Reset();
    void SetNameResolver(const ObjectInfoDB* name_resolver);
    void PrintCommandParameters(YAML::Emitter& os, const Command& cmd);

    const std::vector<Command>& GetCommands() const { return commands_; }
    std::vector<Command>& GetCommands() { return commands_; }

    void TrackPreBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo);

    void TrackPreEndCommandBuffer(VkCommandBuffer commandBuffer);

    void TrackPreResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags);

    void TrackPreCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                 VkPipeline pipeline);

    void TrackPreCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                const VkViewport* pViewports);

    void TrackPreCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount,
                               const VkRect2D* pScissors);

    void TrackPreCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth);

    void TrackPreCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp,
                                 float depthBiasSlopeFactor);

    void TrackPreCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]);

    void TrackPreCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds);

    void TrackPreCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                          uint32_t compareMask);

    void TrackPreCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask);

    void TrackPreCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference);

    void TrackPreCmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                       VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount,
                                       const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount,
                                       const uint32_t* pDynamicOffsets);

    void TrackPreCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                    VkIndexType indexType);

    void TrackPreCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                      const VkBuffer* pBuffers, const VkDeviceSize* pOffsets);

    void TrackPreCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount,
                         uint32_t firstVertex, uint32_t firstInstance);

    void TrackPreCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount,
                                uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance);

    void TrackPreCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                 uint32_t drawCount, uint32_t stride);

    void TrackPreCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                        uint32_t drawCount, uint32_t stride);

    void TrackPreCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                             uint32_t groupCountZ);

    void TrackPreCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);

    void TrackPreCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer,
                               uint32_t regionCount, const VkBufferCopy* pRegions);

    void TrackPreCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                              VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                              const VkImageCopy* pRegions);

    void TrackPreCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                              VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                              const VkImageBlit* pRegions, VkFilter filter);

    void TrackPreCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage,
                                      VkImageLayout dstImageLayout, uint32_t regionCount,
                                      const VkBufferImageCopy* pRegions);

    void TrackPreCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                      VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions);

    void TrackPreCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                 VkDeviceSize dataSize, const void* pData);

    void TrackPreCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                               VkDeviceSize size, uint32_t data);

    void TrackPreCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                    const VkClearColorValue* pColor, uint32_t rangeCount,
                                    const VkImageSubresourceRange* pRanges);

    void TrackPreCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                           const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount,
                                           const VkImageSubresourceRange* pRanges);

    void TrackPreCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                     const VkClearAttachment* pAttachments, uint32_t rectCount,
                                     const VkClearRect* pRects);

    void TrackPreCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                 VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                 const VkImageResolve* pRegions);

    void TrackPreCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);

    void TrackPreCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);

    void TrackPreCmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                               VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask,
                               uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                               uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                               uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);

    void TrackPreCmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask,
                                    VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags,
                                    uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                                    uint32_t bufferMemoryBarrierCount,
                                    const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                    uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);

    void TrackPreCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                               VkQueryControlFlags flags);

    void TrackPreCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query);

    void TrackPreCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                   uint32_t queryCount);

    void TrackPreCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                   VkQueryPool queryPool, uint32_t query);

    void TrackPreCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                         uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                         VkDeviceSize stride, VkQueryResultFlags flags);

    void TrackPreCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags,
                                  uint32_t offset, uint32_t size, const void* pValues);

    void TrackPreCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                    VkSubpassContents contents);

    void TrackPreCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents);

    void TrackPreCmdEndRenderPass(VkCommandBuffer commandBuffer);

    void TrackPreCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount,
                                    const VkCommandBuffer* pCommandBuffers);

    void TrackPreCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask);

    void TrackPreCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                 uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);

    void TrackPreCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                      VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                      uint32_t stride);

    void TrackPreCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                             VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                             uint32_t maxDrawCount, uint32_t stride);

    void TrackPreCmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                     const VkSubpassBeginInfo* pSubpassBeginInfo);

    void TrackPreCmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                                 const VkSubpassEndInfo* pSubpassEndInfo);

    void TrackPreCmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo);

    void TrackPreCmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo);

    void TrackPreCmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask);

    void TrackPreCmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                const VkDependencyInfo* pDependencyInfos);

    void TrackPreCmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo);

    void TrackPreCmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool,
                                    uint32_t query);

    void TrackPreCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);

    void TrackPreCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);

    void TrackPreCmdCopyBufferToImage2(VkCommandBuffer commandBuffer,
                                       const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);

    void TrackPreCmdCopyImageToBuffer2(VkCommandBuffer commandBuffer,
                                       const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);

    void TrackPreCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);

    void TrackPreCmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);

    void TrackPreCmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo);

    void TrackPreCmdEndRendering(VkCommandBuffer commandBuffer);

    void TrackPreCmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode);

    void TrackPreCmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace);

    void TrackPreCmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology);

    void TrackPreCmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                         const VkViewport* pViewports);

    void TrackPreCmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                        const VkRect2D* pScissors);

    void TrackPreCmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                       const VkBuffer* pBuffers, const VkDeviceSize* pOffsets,
                                       const VkDeviceSize* pSizes, const VkDeviceSize* pStrides);

    void TrackPreCmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable);

    void TrackPreCmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable);

    void TrackPreCmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp);

    void TrackPreCmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable);

    void TrackPreCmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable);

    void TrackPreCmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                 VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);

    void TrackPreCmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable);

    void TrackPreCmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable);

    void TrackPreCmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable);

    void TrackPreCmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo);

    void TrackPreCmdEndVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo);

    void TrackPreCmdControlVideoCodingKHR(VkCommandBuffer commandBuffer,
                                          const VkVideoCodingControlInfoKHR* pCodingControlInfo);

    void TrackPreCmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo);

    void TrackPreCmdBeginRenderingKHR(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo);

    void TrackPreCmdEndRenderingKHR(VkCommandBuffer commandBuffer);

    void TrackPreCmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask);

    void TrackPreCmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                    uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                    uint32_t groupCountZ);

    void TrackPreCmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                         VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount,
                                         const VkWriteDescriptorSet* pDescriptorWrites);

    void TrackPreCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer,
                                                     VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                     VkPipelineLayout layout, uint32_t set, const void* pData);

    void TrackPreCmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                        const VkSubpassBeginInfo* pSubpassBeginInfo);

    void TrackPreCmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                                    const VkSubpassEndInfo* pSubpassEndInfo);

    void TrackPreCmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo);

    void TrackPreCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                         VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                         uint32_t stride);

    void TrackPreCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                uint32_t maxDrawCount, uint32_t stride);

    void TrackPreCmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize,
                                              const VkFragmentShadingRateCombinerOpKHR combinerOps[2]);

    void TrackPreCmdSetRenderingAttachmentLocationsKHR(VkCommandBuffer commandBuffer,
                                                       const VkRenderingAttachmentLocationInfoKHR* pLocationInfo);

    void TrackPreCmdSetRenderingInputAttachmentIndicesKHR(VkCommandBuffer commandBuffer,
                                                          const VkRenderingInputAttachmentIndexInfoKHR* pLocationInfo);

    void TrackPreCmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo);

    void TrackPreCmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo);

    void TrackPreCmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask);

    void TrackPreCmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                   const VkDependencyInfo* pDependencyInfos);

    void TrackPreCmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo);

    void TrackPreCmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                       VkQueryPool queryPool, uint32_t query);

    void TrackPreCmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                          VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker);

    void TrackPreCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);

    void TrackPreCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);

    void TrackPreCmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer,
                                          const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);

    void TrackPreCmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer,
                                          const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);

    void TrackPreCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);

    void TrackPreCmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);

    void TrackPreCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress);

    void TrackPreCmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                        VkDeviceSize size, VkIndexType indexType);

    void TrackPreCmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                      uint16_t lineStipplePattern);

    void TrackPreCmdBindDescriptorSets2KHR(VkCommandBuffer commandBuffer,
                                           const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo);

    void TrackPreCmdPushConstants2KHR(VkCommandBuffer commandBuffer, const VkPushConstantsInfoKHR* pPushConstantsInfo);

    void TrackPreCmdPushDescriptorSet2KHR(VkCommandBuffer commandBuffer,
                                          const VkPushDescriptorSetInfoKHR* pPushDescriptorSetInfo);

    void TrackPreCmdPushDescriptorSetWithTemplate2KHR(
        VkCommandBuffer commandBuffer,
        const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo);

    void TrackPreCmdSetDescriptorBufferOffsets2EXT(
        VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo);

    void TrackPreCmdBindDescriptorBufferEmbeddedSamplers2EXT(
        VkCommandBuffer commandBuffer,
        const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo);

    void TrackPreCmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo);

    void TrackPreCmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer);

    void TrackPreCmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo);

    void TrackPreCmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                    uint32_t bindingCount, const VkBuffer* pBuffers,
                                                    const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes);

    void TrackPreCmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                              uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                              const VkDeviceSize* pCounterBufferOffsets);

    void TrackPreCmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                            uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                            const VkDeviceSize* pCounterBufferOffsets);

    void TrackPreCmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                         VkQueryControlFlags flags, uint32_t index);

    void TrackPreCmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                       uint32_t index);

    void TrackPreCmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount,
                                             uint32_t firstInstance, VkBuffer counterBuffer,
                                             VkDeviceSize counterBufferOffset, uint32_t counterOffset,
                                             uint32_t vertexStride);

    void TrackPreCmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo);

    void TrackPreCmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                         VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                         uint32_t stride);

    void TrackPreCmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                uint32_t maxDrawCount, uint32_t stride);

    void TrackPreCmdBeginConditionalRenderingEXT(VkCommandBuffer commandBuffer,
                                                 const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin);

    void TrackPreCmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer);

    void TrackPreCmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                          const VkViewportWScalingNV* pViewportWScalings);

    void TrackPreCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle,
                                           uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles);

    void TrackPreCmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable);

    void TrackPreCmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer,
                                               VkDiscardRectangleModeEXT discardRectangleMode);

    void TrackPreCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo);

    void TrackPreCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer);

    void TrackPreCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo);

#ifdef VK_ENABLE_BETA_EXTENSIONS
    void TrackPreCmdInitializeGraphScratchMemoryAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch);
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
    void TrackPreCmdDispatchGraphAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                      const VkDispatchGraphCountInfoAMDX* pCountInfo);
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
    void TrackPreCmdDispatchGraphIndirectAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                              const VkDispatchGraphCountInfoAMDX* pCountInfo);
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
    void TrackPreCmdDispatchGraphIndirectCountAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                                   VkDeviceAddress countInfo);
#endif  // VK_ENABLE_BETA_EXTENSIONS

    void TrackPreCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer,
                                          const VkSampleLocationsInfoEXT* pSampleLocationsInfo);

    void TrackPreCmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView,
                                           VkImageLayout imageLayout);

    void TrackPreCmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                                    uint32_t viewportCount,
                                                    const VkShadingRatePaletteNV* pShadingRatePalettes);

    void TrackPreCmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType,
                                           uint32_t customSampleOrderCount,
                                           const VkCoarseSampleOrderCustomNV* pCustomSampleOrders);

    void TrackPreCmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer,
                                                 const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData,
                                                 VkDeviceSize instanceOffset, VkBool32 update,
                                                 VkAccelerationStructureNV dst, VkAccelerationStructureNV src,
                                                 VkBuffer scratch, VkDeviceSize scratchOffset);

    void TrackPreCmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst,
                                                VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode);

    void TrackPreCmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer,
                                VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer,
                                VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride,
                                VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset,
                                VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer,
                                VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride,
                                uint32_t width, uint32_t height, uint32_t depth);

    void TrackPreCmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer,
                                                            uint32_t accelerationStructureCount,
                                                            const VkAccelerationStructureNV* pAccelerationStructures,
                                                            VkQueryType queryType, VkQueryPool queryPool,
                                                            uint32_t firstQuery);

    void TrackPreCmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                         VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker);

    void TrackPreCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask);

    void TrackPreCmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                            uint32_t drawCount, uint32_t stride);

    void TrackPreCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                 VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                 uint32_t maxDrawCount, uint32_t stride);

    void TrackPreCmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                                uint32_t exclusiveScissorCount,
                                                const VkBool32* pExclusiveScissorEnables);

    void TrackPreCmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                          uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors);

    void TrackPreCmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker);

    void TrackPreCmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer,
                                              const VkPerformanceMarkerInfoINTEL* pMarkerInfo);

    void TrackPreCmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer,
                                                    const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo);

    void TrackPreCmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer,
                                                const VkPerformanceOverrideInfoINTEL* pOverrideInfo);

    void TrackPreCmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                      uint16_t lineStipplePattern);

    void TrackPreCmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode);

    void TrackPreCmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace);

    void TrackPreCmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology);

    void TrackPreCmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                            const VkViewport* pViewports);

    void TrackPreCmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                           const VkRect2D* pScissors);

    void TrackPreCmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                          const VkBuffer* pBuffers, const VkDeviceSize* pOffsets,
                                          const VkDeviceSize* pSizes, const VkDeviceSize* pStrides);

    void TrackPreCmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable);

    void TrackPreCmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable);

    void TrackPreCmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp);

    void TrackPreCmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable);

    void TrackPreCmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable);

    void TrackPreCmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                    VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);

    void TrackPreCmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer,
                                                  const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);

    void TrackPreCmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                               const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);

    void TrackPreCmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                              VkPipeline pipeline, uint32_t groupIndex);

    void TrackPreCmdSetDepthBias2EXT(VkCommandBuffer commandBuffer, const VkDepthBiasInfoEXT* pDepthBiasInfo);

    void TrackPreCmdCudaLaunchKernelNV(VkCommandBuffer commandBuffer, const VkCudaLaunchInfoNV* pLaunchInfo);

    void TrackPreCmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount,
                                             const VkDescriptorBufferBindingInfoEXT* pBindingInfos);

    void TrackPreCmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                  VkPipelineLayout layout, uint32_t firstSet, uint32_t setCount,
                                                  const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets);

    void TrackPreCmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer commandBuffer,
                                                            VkPipelineBindPoint pipelineBindPoint,
                                                            VkPipelineLayout layout, uint32_t set);

    void TrackPreCmdSetFragmentShadingRateEnumNV(VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate,
                                                 const VkFragmentShadingRateCombinerOpKHR combinerOps[2]);

    void TrackPreCmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
                                      const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions,
                                      uint32_t vertexAttributeDescriptionCount,
                                      const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions);

    void TrackPreCmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer);

    void TrackPreCmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer, VkImageView imageView,
                                             VkImageLayout imageLayout);

    void TrackPreCmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints);

    void TrackPreCmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable);

    void TrackPreCmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable);

    void TrackPreCmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp);

    void TrackPreCmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable);

    void TrackPreCmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                           const VkBool32* pColorWriteEnables);

    void TrackPreCmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                 const VkMultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount, uint32_t firstInstance,
                                 uint32_t stride);

    void TrackPreCmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                        const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount,
                                        uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset);

    void TrackPreCmdBuildMicromapsEXT(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                      const VkMicromapBuildInfoEXT* pInfos);

    void TrackPreCmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo);

    void TrackPreCmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo);

    void TrackPreCmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo);

    void TrackPreCmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount,
                                                const VkMicromapEXT* pMicromaps, VkQueryType queryType,
                                                VkQueryPool queryPool, uint32_t firstQuery);

    void TrackPreCmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                      uint32_t groupCountZ);

    void TrackPreCmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);

    void TrackPreCmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                         uint32_t copyCount, uint32_t stride);

    void TrackPreCmdCopyMemoryToImageIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                                uint32_t copyCount, uint32_t stride, VkImage dstImage,
                                                VkImageLayout dstImageLayout,
                                                const VkImageSubresourceLayers* pImageSubresources);

    void TrackPreCmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount,
                                       const VkDecompressMemoryRegionNV* pDecompressMemoryRegions);

    void TrackPreCmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer,
                                                    VkDeviceAddress indirectCommandsAddress,
                                                    VkDeviceAddress indirectCommandsCountAddress, uint32_t stride);

    void TrackPreCmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                   VkPipeline pipeline);

    void TrackPreCmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClampEnable);

    void TrackPreCmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode);

    void TrackPreCmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer,
                                               VkSampleCountFlagBits rasterizationSamples);

    void TrackPreCmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples,
                                     const VkSampleMask* pSampleMask);

    void TrackPreCmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable);

    void TrackPreCmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable);

    void TrackPreCmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable);

    void TrackPreCmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                           uint32_t attachmentCount, const VkBool32* pColorBlendEnables);

    void TrackPreCmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                             uint32_t attachmentCount,
                                             const VkColorBlendEquationEXT* pColorBlendEquations);

    void TrackPreCmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                         uint32_t attachmentCount, const VkColorComponentFlags* pColorWriteMasks);

    void TrackPreCmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer,
                                                   VkTessellationDomainOrigin domainOrigin);

    void TrackPreCmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer, uint32_t rasterizationStream);

    void TrackPreCmdSetConservativeRasterizationModeEXT(
        VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode);

    void TrackPreCmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer commandBuffer,
                                                           float extraPrimitiveOverestimationSize);

    void TrackPreCmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClipEnable);

    void TrackPreCmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable);

    void TrackPreCmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                             uint32_t attachmentCount,
                                             const VkColorBlendAdvancedEXT* pColorBlendAdvanced);

    void TrackPreCmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer,
                                              VkProvokingVertexModeEXT provokingVertexMode);

    void TrackPreCmdSetLineRasterizationModeEXT(VkCommandBuffer commandBuffer,
                                                VkLineRasterizationModeEXT lineRasterizationMode);

    void TrackPreCmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable);

    void TrackPreCmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne);

    void TrackPreCmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable);

    void TrackPreCmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                         const VkViewportSwizzleNV* pViewportSwizzles);

    void TrackPreCmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable);

    void TrackPreCmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation);

    void TrackPreCmdSetCoverageModulationModeNV(VkCommandBuffer commandBuffer,
                                                VkCoverageModulationModeNV coverageModulationMode);

    void TrackPreCmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer,
                                                       VkBool32 coverageModulationTableEnable);

    void TrackPreCmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount,
                                                 const float* pCoverageModulationTable);

    void TrackPreCmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable);

    void TrackPreCmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer commandBuffer,
                                                          VkBool32 representativeFragmentTestEnable);

    void TrackPreCmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer,
                                               VkCoverageReductionModeNV coverageReductionMode);

    void TrackPreCmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session,
                                         const VkOpticalFlowExecuteInfoNV* pExecuteInfo);

    void TrackPreCmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount,
                                   const VkShaderStageFlagBits* pStages, const VkShaderEXT* pShaders);

    void TrackPreCmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer, VkImageAspectFlags aspectMask);

    void TrackPreCmdBuildAccelerationStructuresKHR(
        VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
        const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos);

    void TrackPreCmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                                           const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
                                                           const VkDeviceAddress* pIndirectDeviceAddresses,
                                                           const uint32_t* pIndirectStrides,
                                                           const uint32_t* const* ppMaxPrimitiveCounts);

    void TrackPreCmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                                 const VkCopyAccelerationStructureInfoKHR* pInfo);

    void TrackPreCmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer commandBuffer,
                                                         const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo);

    void TrackPreCmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                                         const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo);

    void TrackPreCmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer commandBuffer,
                                                             uint32_t accelerationStructureCount,
                                                             const VkAccelerationStructureKHR* pAccelerationStructures,
                                                             VkQueryType queryType, VkQueryPool queryPool,
                                                             uint32_t firstQuery);

    void TrackPreCmdTraceRaysKHR(VkCommandBuffer commandBuffer,
                                 const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                 const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                 const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                 const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width,
                                 uint32_t height, uint32_t depth);

    void TrackPreCmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer,
                                         const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                         const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                         const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                         const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                         VkDeviceAddress indirectDeviceAddress);

    void TrackPreCmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize);

    void TrackPreCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                     uint32_t groupCountZ);

    void TrackPreCmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                             uint32_t drawCount, uint32_t stride);

    void TrackPreCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                  VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                  uint32_t maxDrawCount, uint32_t stride);

   private:
    std::vector<Command> commands_;
    CommandPrinter printer_;
    CommandRecorder recorder_;
};

// NOLINTEND
