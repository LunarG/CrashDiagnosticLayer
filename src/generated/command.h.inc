
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
 * ***   Update source file command_prepost_generator.py for modifications
 * *** ---- WARNING! ----
 *
 ****************************************************************************/

// NOLINTBEGIN

void PreCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline);
void PostCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline);

void PreCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                       const VkViewport* pViewports);
void PostCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                        const VkViewport* pViewports);

void PreCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount,
                      const VkRect2D* pScissors);
void PostCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount,
                       const VkRect2D* pScissors);

void PreCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth);
void PostCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth);

void PreCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp,
                        float depthBiasSlopeFactor);
void PostCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp,
                         float depthBiasSlopeFactor);

void PreCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]);
void PostCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]);

void PreCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds);
void PostCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds);

void PreCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask);
void PostCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask);

void PreCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask);
void PostCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask);

void PreCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference);
void PostCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference);

void PreCmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                              VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount,
                              const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount,
                              const uint32_t* pDynamicOffsets);
void PostCmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                               VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount,
                               const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount,
                               const uint32_t* pDynamicOffsets);

void PreCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType);
void PostCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType);

void PreCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                             const VkBuffer* pBuffers, const VkDeviceSize* pOffsets);
void PostCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                              const VkBuffer* pBuffers, const VkDeviceSize* pOffsets);

void PreCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex,
                uint32_t firstInstance);
void PostCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex,
                 uint32_t firstInstance);

void PreCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex,
                       int32_t vertexOffset, uint32_t firstInstance);
void PostCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex,
                        int32_t vertexOffset, uint32_t firstInstance);

void PreCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount,
                        uint32_t stride);
void PostCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount,
                         uint32_t stride);

void PreCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount,
                               uint32_t stride);
void PostCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount,
                                uint32_t stride);

void PreCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
void PostCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);

void PreCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);
void PostCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);

void PreCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount,
                      const VkBufferCopy* pRegions);
void PostCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount,
                       const VkBufferCopy* pRegions);

void PreCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage,
                     VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions);
void PostCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage,
                      VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions);

void PreCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage,
                     VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter);
void PostCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage,
                      VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter);

void PreCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage,
                             VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions);
void PostCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage,
                              VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions);

void PreCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                             VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions);
void PostCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                              VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions);

void PreCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                        VkDeviceSize dataSize, const void* pData);
void PostCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                         VkDeviceSize dataSize, const void* pData);

void PreCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size,
                      uint32_t data);
void PostCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size,
                       uint32_t data);

void PreCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                           const VkClearColorValue* pColor, uint32_t rangeCount,
                           const VkImageSubresourceRange* pRanges);
void PostCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                            const VkClearColorValue* pColor, uint32_t rangeCount,
                            const VkImageSubresourceRange* pRanges);

void PreCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                  const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount,
                                  const VkImageSubresourceRange* pRanges);
void PostCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                   const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount,
                                   const VkImageSubresourceRange* pRanges);

void PreCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                            const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects);
void PostCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                             const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects);

void PreCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage,
                        VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions);
void PostCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                         VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                         const VkImageResolve* pRegions);

void PreCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);
void PostCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);

void PreCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);
void PostCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);

void PreCmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                      VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount,
                      const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount,
                      const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount,
                      const VkImageMemoryBarrier* pImageMemoryBarriers);
void PostCmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                       VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask,
                       uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                       uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                       uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);

void PreCmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask,
                           VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags,
                           uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                           uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                           uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);
void PostCmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask,
                            VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags,
                            uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                            uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                            uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);

void PreCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags);
void PostCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags);

void PreCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query);
void PostCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query);

void PreCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                          uint32_t queryCount);
void PostCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                           uint32_t queryCount);

void PreCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool,
                          uint32_t query);
void PostCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool,
                           uint32_t query);

void PreCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride,
                                VkQueryResultFlags flags);
void PostCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                 uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride,
                                 VkQueryResultFlags flags);

void PreCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags,
                         uint32_t offset, uint32_t size, const void* pValues);
void PostCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags,
                          uint32_t offset, uint32_t size, const void* pValues);

void PreCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                           VkSubpassContents contents);
void PostCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                            VkSubpassContents contents);

void PreCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents);
void PostCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents);

void PreCmdEndRenderPass(VkCommandBuffer commandBuffer);
void PostCmdEndRenderPass(VkCommandBuffer commandBuffer);

void PreCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount,
                           const VkCommandBuffer* pCommandBuffers);
void PostCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount,
                            const VkCommandBuffer* pCommandBuffers);

void PreCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask);
void PostCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask);

void PreCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ,
                        uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
void PostCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ,
                         uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);

void PreCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer,
                             VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);
void PostCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer,
                              VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride);

void PreCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                    VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                    uint32_t stride);
void PostCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                     VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                     uint32_t stride);

void PreCmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                            const VkSubpassBeginInfo* pSubpassBeginInfo);
void PostCmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                             const VkSubpassBeginInfo* pSubpassBeginInfo);

void PreCmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                        const VkSubpassEndInfo* pSubpassEndInfo);
void PostCmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                         const VkSubpassEndInfo* pSubpassEndInfo);

void PreCmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo);
void PostCmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo);

void PreCmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo);
void PostCmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo);

void PreCmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask);
void PostCmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask);

void PreCmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                       const VkDependencyInfo* pDependencyInfos);
void PostCmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                        const VkDependencyInfo* pDependencyInfos);

void PreCmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo);
void PostCmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo);

void PreCmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool,
                           uint32_t query);
void PostCmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool,
                            uint32_t query);

void PreCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);
void PostCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);

void PreCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);
void PostCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);

void PreCmdCopyBufferToImage2(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);
void PostCmdCopyBufferToImage2(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);

void PreCmdCopyImageToBuffer2(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);
void PostCmdCopyImageToBuffer2(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);

void PreCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);
void PostCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);

void PreCmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);
void PostCmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);

void PreCmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode);
void PostCmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode);

void PreCmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace);
void PostCmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace);

void PreCmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology);
void PostCmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology);

void PreCmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports);
void PostCmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports);

void PreCmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors);
void PostCmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors);

void PreCmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                              const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                              const VkDeviceSize* pStrides);
void PostCmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                               const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                               const VkDeviceSize* pStrides);

void PreCmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable);
void PostCmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable);

void PreCmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable);
void PostCmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable);

void PreCmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp);
void PostCmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp);

void PreCmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable);
void PostCmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable);

void PreCmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable);
void PostCmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable);

void PreCmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                        VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);
void PostCmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                         VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);

void PreCmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable);
void PostCmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable);

void PreCmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable);
void PostCmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable);

void PreCmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable);
void PostCmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable);

void PreCmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo);
void PostCmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo);

void PreCmdEndVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo);
void PostCmdEndVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo);

void PreCmdControlVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoCodingControlInfoKHR* pCodingControlInfo);
void PostCmdControlVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoCodingControlInfoKHR* pCodingControlInfo);

void PreCmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo);
void PostCmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo);

void PreCmdBeginRenderingKHR(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo);
void PostCmdBeginRenderingKHR(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo);

void PreCmdEndRenderingKHR(VkCommandBuffer commandBuffer);
void PostCmdEndRenderingKHR(VkCommandBuffer commandBuffer);

void PreCmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask);
void PostCmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask);

void PreCmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ,
                           uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
void PostCmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                            uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);

void PreCmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount,
                                const VkWriteDescriptorSet* pDescriptorWrites);
void PostCmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                 VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount,
                                 const VkWriteDescriptorSet* pDescriptorWrites);

void PreCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer,
                                            VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                            VkPipelineLayout layout, uint32_t set, const void* pData);
void PostCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer,
                                             VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                             VkPipelineLayout layout, uint32_t set, const void* pData);

void PreCmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                               const VkSubpassBeginInfo* pSubpassBeginInfo);
void PostCmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                const VkSubpassBeginInfo* pSubpassBeginInfo);

void PreCmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                           const VkSubpassEndInfo* pSubpassEndInfo);
void PostCmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                            const VkSubpassEndInfo* pSubpassEndInfo);

void PreCmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo);
void PostCmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo);

void PreCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                uint32_t stride);
void PostCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                 VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                 uint32_t stride);

void PreCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                       VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                       uint32_t stride);
void PostCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                        VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                        uint32_t stride);

void PreCmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize,
                                     const VkFragmentShadingRateCombinerOpKHR combinerOps[2]);
void PostCmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize,
                                      const VkFragmentShadingRateCombinerOpKHR combinerOps[2]);

void PreCmdSetRenderingAttachmentLocationsKHR(VkCommandBuffer commandBuffer,
                                              const VkRenderingAttachmentLocationInfoKHR* pLocationInfo);
void PostCmdSetRenderingAttachmentLocationsKHR(VkCommandBuffer commandBuffer,
                                               const VkRenderingAttachmentLocationInfoKHR* pLocationInfo);

void PreCmdSetRenderingInputAttachmentIndicesKHR(
    VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfoKHR* pInputAttachmentIndexInfo);
void PostCmdSetRenderingInputAttachmentIndicesKHR(
    VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfoKHR* pInputAttachmentIndexInfo);

void PreCmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo);
void PostCmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo);

void PreCmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo);
void PostCmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo);

void PreCmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask);
void PostCmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask);

void PreCmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                          const VkDependencyInfo* pDependencyInfos);
void PostCmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                           const VkDependencyInfo* pDependencyInfos);

void PreCmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo);
void PostCmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo);

void PreCmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool,
                              uint32_t query);
void PostCmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool,
                               uint32_t query);

void PreCmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkBuffer dstBuffer,
                                 VkDeviceSize dstOffset, uint32_t marker);
void PostCmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkBuffer dstBuffer,
                                  VkDeviceSize dstOffset, uint32_t marker);

void PreCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);
void PostCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);

void PreCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);
void PostCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);

void PreCmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);
void PostCmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer,
                                  const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);

void PreCmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);
void PostCmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer,
                                  const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);

void PreCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);
void PostCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);

void PreCmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);
void PostCmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);

void PreCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress);
void PostCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress);

void PreCmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size,
                               VkIndexType indexType);
void PostCmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size,
                                VkIndexType indexType);

void PreCmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern);
void PostCmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern);

void PreCmdBindDescriptorSets2KHR(VkCommandBuffer commandBuffer,
                                  const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo);
void PostCmdBindDescriptorSets2KHR(VkCommandBuffer commandBuffer,
                                   const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo);

void PreCmdPushConstants2KHR(VkCommandBuffer commandBuffer, const VkPushConstantsInfoKHR* pPushConstantsInfo);
void PostCmdPushConstants2KHR(VkCommandBuffer commandBuffer, const VkPushConstantsInfoKHR* pPushConstantsInfo);

void PreCmdPushDescriptorSet2KHR(VkCommandBuffer commandBuffer,
                                 const VkPushDescriptorSetInfoKHR* pPushDescriptorSetInfo);
void PostCmdPushDescriptorSet2KHR(VkCommandBuffer commandBuffer,
                                  const VkPushDescriptorSetInfoKHR* pPushDescriptorSetInfo);

void PreCmdPushDescriptorSetWithTemplate2KHR(
    VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo);
void PostCmdPushDescriptorSetWithTemplate2KHR(
    VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo);

void PreCmdSetDescriptorBufferOffsets2EXT(VkCommandBuffer commandBuffer,
                                          const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo);
void PostCmdSetDescriptorBufferOffsets2EXT(VkCommandBuffer commandBuffer,
                                           const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo);

void PreCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    VkCommandBuffer commandBuffer,
    const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo);
void PostCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    VkCommandBuffer commandBuffer,
    const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo);

void PreCmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo);
void PostCmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo);

void PreCmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer);
void PostCmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer);

void PreCmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo);
void PostCmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo);

void PreCmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                           const VkBuffer* pBuffers, const VkDeviceSize* pOffsets,
                                           const VkDeviceSize* pSizes);
void PostCmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                            const VkBuffer* pBuffers, const VkDeviceSize* pOffsets,
                                            const VkDeviceSize* pSizes);

void PreCmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                     uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                     const VkDeviceSize* pCounterBufferOffsets);
void PostCmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                      uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                      const VkDeviceSize* pCounterBufferOffsets);

void PreCmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                   uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                   const VkDeviceSize* pCounterBufferOffsets);
void PostCmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                    uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                    const VkDeviceSize* pCounterBufferOffsets);

void PreCmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                VkQueryControlFlags flags, uint32_t index);
void PostCmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                 VkQueryControlFlags flags, uint32_t index);

void PreCmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index);
void PostCmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index);

void PreCmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance,
                                    VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset,
                                    uint32_t vertexStride);
void PostCmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance,
                                     VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset,
                                     uint32_t vertexStride);

void PreCmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo);
void PostCmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo);

void PreCmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                uint32_t stride);
void PostCmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                 VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                 uint32_t stride);

void PreCmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                       VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                       uint32_t stride);
void PostCmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                        VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                        uint32_t stride);

void PreCmdBeginConditionalRenderingEXT(VkCommandBuffer commandBuffer,
                                        const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin);
void PostCmdBeginConditionalRenderingEXT(VkCommandBuffer commandBuffer,
                                         const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin);

void PreCmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer);
void PostCmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer);

void PreCmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                 const VkViewportWScalingNV* pViewportWScalings);
void PostCmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                  const VkViewportWScalingNV* pViewportWScalings);

void PreCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle,
                                  uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles);
void PostCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle,
                                   uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles);

void PreCmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable);
void PostCmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable);

void PreCmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode);
void PostCmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode);

void PreCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo);
void PostCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo);

void PreCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer);
void PostCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer);

void PreCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo);
void PostCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo);

#ifdef VK_ENABLE_BETA_EXTENSIONS
void PreCmdInitializeGraphScratchMemoryAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch);
void PostCmdInitializeGraphScratchMemoryAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch);
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void PreCmdDispatchGraphAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                             const VkDispatchGraphCountInfoAMDX* pCountInfo);
void PostCmdDispatchGraphAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                              const VkDispatchGraphCountInfoAMDX* pCountInfo);
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void PreCmdDispatchGraphIndirectAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                     const VkDispatchGraphCountInfoAMDX* pCountInfo);
void PostCmdDispatchGraphIndirectAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                      const VkDispatchGraphCountInfoAMDX* pCountInfo);
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void PreCmdDispatchGraphIndirectCountAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                          VkDeviceAddress countInfo);
void PostCmdDispatchGraphIndirectCountAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                           VkDeviceAddress countInfo);
#endif  // VK_ENABLE_BETA_EXTENSIONS

void PreCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo);
void PostCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo);

void PreCmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout);
void PostCmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout);

void PreCmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                           uint32_t viewportCount, const VkShadingRatePaletteNV* pShadingRatePalettes);
void PostCmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                            uint32_t viewportCount, const VkShadingRatePaletteNV* pShadingRatePalettes);

void PreCmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType,
                                  uint32_t customSampleOrderCount,
                                  const VkCoarseSampleOrderCustomNV* pCustomSampleOrders);
void PostCmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType,
                                   uint32_t customSampleOrderCount,
                                   const VkCoarseSampleOrderCustomNV* pCustomSampleOrders);

void PreCmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo,
                                        VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update,
                                        VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch,
                                        VkDeviceSize scratchOffset);
void PostCmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo,
                                         VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update,
                                         VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch,
                                         VkDeviceSize scratchOffset);

void PreCmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst,
                                       VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode);
void PostCmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst,
                                        VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode);

void PreCmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer,
                       VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer,
                       VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride,
                       VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset,
                       VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer,
                       VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride,
                       uint32_t width, uint32_t height, uint32_t depth);
void PostCmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer,
                        VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer,
                        VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride,
                        VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset,
                        VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer,
                        VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride,
                        uint32_t width, uint32_t height, uint32_t depth);

void PreCmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
                                                   const VkAccelerationStructureNV* pAccelerationStructures,
                                                   VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery);
void PostCmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
                                                    const VkAccelerationStructureNV* pAccelerationStructures,
                                                    VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery);

void PreCmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker);
void PostCmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                 VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker);

void PreCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask);
void PostCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask);

void PreCmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                   uint32_t drawCount, uint32_t stride);
void PostCmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                    uint32_t drawCount, uint32_t stride);

void PreCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                        VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                        uint32_t stride);
void PostCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                         VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                         uint32_t stride);

void PreCmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                       uint32_t exclusiveScissorCount, const VkBool32* pExclusiveScissorEnables);
void PostCmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                        uint32_t exclusiveScissorCount, const VkBool32* pExclusiveScissorEnables);

void PreCmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                 uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors);
void PostCmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                  uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors);

void PreCmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker);
void PostCmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker);

VkResult PreCmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer,
                                         const VkPerformanceMarkerInfoINTEL* pMarkerInfo);
VkResult PostCmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer,
                                          const VkPerformanceMarkerInfoINTEL* pMarkerInfo, VkResult result);

VkResult PreCmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer,
                                               const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo);
VkResult PostCmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer,
                                                const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo, VkResult result);

VkResult PreCmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer,
                                           const VkPerformanceOverrideInfoINTEL* pOverrideInfo);
VkResult PostCmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer,
                                            const VkPerformanceOverrideInfoINTEL* pOverrideInfo, VkResult result);

void PreCmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern);
void PostCmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern);

void PreCmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode);
void PostCmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode);

void PreCmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace);
void PostCmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace);

void PreCmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology);
void PostCmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology);

void PreCmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports);
void PostCmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                    const VkViewport* pViewports);

void PreCmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors);
void PostCmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors);

void PreCmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                 const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                                 const VkDeviceSize* pStrides);
void PostCmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                  const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                                  const VkDeviceSize* pStrides);

void PreCmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable);
void PostCmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable);

void PreCmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable);
void PostCmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable);

void PreCmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp);
void PostCmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp);

void PreCmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable);
void PostCmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable);

void PreCmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable);
void PostCmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable);

void PreCmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                           VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);
void PostCmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                            VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp);

void PreCmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer,
                                         const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);
void PostCmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer,
                                          const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);

void PreCmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                      const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);
void PostCmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                       const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);

void PreCmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                     VkPipeline pipeline, uint32_t groupIndex);
void PostCmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                      VkPipeline pipeline, uint32_t groupIndex);

void PreCmdSetDepthBias2EXT(VkCommandBuffer commandBuffer, const VkDepthBiasInfoEXT* pDepthBiasInfo);
void PostCmdSetDepthBias2EXT(VkCommandBuffer commandBuffer, const VkDepthBiasInfoEXT* pDepthBiasInfo);

void PreCmdCudaLaunchKernelNV(VkCommandBuffer commandBuffer, const VkCudaLaunchInfoNV* pLaunchInfo);
void PostCmdCudaLaunchKernelNV(VkCommandBuffer commandBuffer, const VkCudaLaunchInfoNV* pLaunchInfo);

void PreCmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount,
                                    const VkDescriptorBufferBindingInfoEXT* pBindingInfos);
void PostCmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount,
                                     const VkDescriptorBufferBindingInfoEXT* pBindingInfos);

void PreCmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                         VkPipelineLayout layout, uint32_t firstSet, uint32_t setCount,
                                         const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets);
void PostCmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                          VkPipelineLayout layout, uint32_t firstSet, uint32_t setCount,
                                          const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets);

void PreCmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                   VkPipelineLayout layout, uint32_t set);
void PostCmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer commandBuffer,
                                                    VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout,
                                                    uint32_t set);

void PreCmdSetFragmentShadingRateEnumNV(VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate,
                                        const VkFragmentShadingRateCombinerOpKHR combinerOps[2]);
void PostCmdSetFragmentShadingRateEnumNV(VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate,
                                         const VkFragmentShadingRateCombinerOpKHR combinerOps[2]);

void PreCmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
                             const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions,
                             uint32_t vertexAttributeDescriptionCount,
                             const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions);
void PostCmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
                              const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions,
                              uint32_t vertexAttributeDescriptionCount,
                              const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions);

void PreCmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer);
void PostCmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer);

void PreCmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout);
void PostCmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout);

void PreCmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints);
void PostCmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints);

void PreCmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable);
void PostCmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable);

void PreCmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable);
void PostCmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable);

void PreCmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp);
void PostCmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp);

void PreCmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable);
void PostCmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable);

void PreCmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                  const VkBool32* pColorWriteEnables);
void PostCmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                   const VkBool32* pColorWriteEnables);

void PreCmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawInfoEXT* pVertexInfo,
                        uint32_t instanceCount, uint32_t firstInstance, uint32_t stride);
void PostCmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawInfoEXT* pVertexInfo,
                         uint32_t instanceCount, uint32_t firstInstance, uint32_t stride);

void PreCmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                               const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount,
                               uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset);
void PostCmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount,
                                uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset);

void PreCmdBuildMicromapsEXT(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos);
void PostCmdBuildMicromapsEXT(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos);

void PreCmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo);
void PostCmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo);

void PreCmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo);
void PostCmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo);

void PreCmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo);
void PostCmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo);

void PreCmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount,
                                       const VkMicromapEXT* pMicromaps, VkQueryType queryType, VkQueryPool queryPool,
                                       uint32_t firstQuery);
void PostCmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount,
                                        const VkMicromapEXT* pMicromaps, VkQueryType queryType, VkQueryPool queryPool,
                                        uint32_t firstQuery);

void PreCmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                             uint32_t groupCountZ);
void PostCmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                              uint32_t groupCountZ);

void PreCmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);
void PostCmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);

void PreCmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount,
                                uint32_t stride);
void PostCmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount,
                                 uint32_t stride);

void PreCmdCopyMemoryToImageIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                       uint32_t copyCount, uint32_t stride, VkImage dstImage,
                                       VkImageLayout dstImageLayout,
                                       const VkImageSubresourceLayers* pImageSubresources);
void PostCmdCopyMemoryToImageIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                        uint32_t copyCount, uint32_t stride, VkImage dstImage,
                                        VkImageLayout dstImageLayout,
                                        const VkImageSubresourceLayers* pImageSubresources);

void PreCmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount,
                              const VkDecompressMemoryRegionNV* pDecompressMemoryRegions);
void PostCmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount,
                               const VkDecompressMemoryRegionNV* pDecompressMemoryRegions);

void PreCmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer, VkDeviceAddress indirectCommandsAddress,
                                           VkDeviceAddress indirectCommandsCountAddress, uint32_t stride);
void PostCmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer, VkDeviceAddress indirectCommandsAddress,
                                            VkDeviceAddress indirectCommandsCountAddress, uint32_t stride);

void PreCmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                          VkPipeline pipeline);
void PostCmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                           VkPipeline pipeline);

void PreCmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClampEnable);
void PostCmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClampEnable);

void PreCmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode);
void PostCmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode);

void PreCmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits rasterizationSamples);
void PostCmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits rasterizationSamples);

void PreCmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples,
                            const VkSampleMask* pSampleMask);
void PostCmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples,
                             const VkSampleMask* pSampleMask);

void PreCmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable);
void PostCmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable);

void PreCmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable);
void PostCmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable);

void PreCmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable);
void PostCmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable);

void PreCmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
                                  const VkBool32* pColorBlendEnables);
void PostCmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
                                   const VkBool32* pColorBlendEnables);

void PreCmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
                                    const VkColorBlendEquationEXT* pColorBlendEquations);
void PostCmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
                                     const VkColorBlendEquationEXT* pColorBlendEquations);

void PreCmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
                                const VkColorComponentFlags* pColorWriteMasks);
void PostCmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
                                 const VkColorComponentFlags* pColorWriteMasks);

void PreCmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer, VkTessellationDomainOrigin domainOrigin);
void PostCmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer, VkTessellationDomainOrigin domainOrigin);

void PreCmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer, uint32_t rasterizationStream);
void PostCmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer, uint32_t rasterizationStream);

void PreCmdSetConservativeRasterizationModeEXT(VkCommandBuffer commandBuffer,
                                               VkConservativeRasterizationModeEXT conservativeRasterizationMode);
void PostCmdSetConservativeRasterizationModeEXT(VkCommandBuffer commandBuffer,
                                                VkConservativeRasterizationModeEXT conservativeRasterizationMode);

void PreCmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer commandBuffer,
                                                  float extraPrimitiveOverestimationSize);
void PostCmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer commandBuffer,
                                                   float extraPrimitiveOverestimationSize);

void PreCmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClipEnable);
void PostCmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClipEnable);

void PreCmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable);
void PostCmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable);

void PreCmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
                                    const VkColorBlendAdvancedEXT* pColorBlendAdvanced);
void PostCmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
                                     const VkColorBlendAdvancedEXT* pColorBlendAdvanced);

void PreCmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer, VkProvokingVertexModeEXT provokingVertexMode);
void PostCmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer, VkProvokingVertexModeEXT provokingVertexMode);

void PreCmdSetLineRasterizationModeEXT(VkCommandBuffer commandBuffer, VkLineRasterizationModeEXT lineRasterizationMode);
void PostCmdSetLineRasterizationModeEXT(VkCommandBuffer commandBuffer,
                                        VkLineRasterizationModeEXT lineRasterizationMode);

void PreCmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable);
void PostCmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable);

void PreCmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne);
void PostCmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne);

void PreCmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable);
void PostCmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable);

void PreCmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                const VkViewportSwizzleNV* pViewportSwizzles);
void PostCmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                 const VkViewportSwizzleNV* pViewportSwizzles);

void PreCmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable);
void PostCmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable);

void PreCmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation);
void PostCmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation);

void PreCmdSetCoverageModulationModeNV(VkCommandBuffer commandBuffer,
                                       VkCoverageModulationModeNV coverageModulationMode);
void PostCmdSetCoverageModulationModeNV(VkCommandBuffer commandBuffer,
                                        VkCoverageModulationModeNV coverageModulationMode);

void PreCmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageModulationTableEnable);
void PostCmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageModulationTableEnable);

void PreCmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount,
                                        const float* pCoverageModulationTable);
void PostCmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount,
                                         const float* pCoverageModulationTable);

void PreCmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable);
void PostCmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable);

void PreCmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer commandBuffer,
                                                 VkBool32 representativeFragmentTestEnable);
void PostCmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer commandBuffer,
                                                  VkBool32 representativeFragmentTestEnable);

void PreCmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer, VkCoverageReductionModeNV coverageReductionMode);
void PostCmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer, VkCoverageReductionModeNV coverageReductionMode);

void PreCmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session,
                                const VkOpticalFlowExecuteInfoNV* pExecuteInfo);
void PostCmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session,
                                 const VkOpticalFlowExecuteInfoNV* pExecuteInfo);

void PreCmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount, const VkShaderStageFlagBits* pStages,
                          const VkShaderEXT* pShaders);
void PostCmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount, const VkShaderStageFlagBits* pStages,
                           const VkShaderEXT* pShaders);

void PreCmdSetDepthClampRangeEXT(VkCommandBuffer commandBuffer, VkDepthClampModeEXT depthClampMode,
                                 const VkDepthClampRangeEXT* pDepthClampRange);
void PostCmdSetDepthClampRangeEXT(VkCommandBuffer commandBuffer, VkDepthClampModeEXT depthClampMode,
                                  const VkDepthClampRangeEXT* pDepthClampRange);

void PreCmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer, VkImageAspectFlags aspectMask);
void PostCmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer, VkImageAspectFlags aspectMask);

void PreCmdPreprocessGeneratedCommandsEXT(VkCommandBuffer commandBuffer,
                                          const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo,
                                          VkCommandBuffer stateCommandBuffer);
void PostCmdPreprocessGeneratedCommandsEXT(VkCommandBuffer commandBuffer,
                                           const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo,
                                           VkCommandBuffer stateCommandBuffer);

void PreCmdExecuteGeneratedCommandsEXT(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                       const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo);
void PostCmdExecuteGeneratedCommandsEXT(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                        const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo);

void PreCmdBuildAccelerationStructuresKHR(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                          const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
                                          const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos);
void PostCmdBuildAccelerationStructuresKHR(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                           const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
                                           const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos);

void PreCmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                                  const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
                                                  const VkDeviceAddress* pIndirectDeviceAddresses,
                                                  const uint32_t* pIndirectStrides,
                                                  const uint32_t* const* ppMaxPrimitiveCounts);
void PostCmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                                   const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
                                                   const VkDeviceAddress* pIndirectDeviceAddresses,
                                                   const uint32_t* pIndirectStrides,
                                                   const uint32_t* const* ppMaxPrimitiveCounts);

void PreCmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo);
void PostCmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                         const VkCopyAccelerationStructureInfoKHR* pInfo);

void PreCmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer commandBuffer,
                                                const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo);
void PostCmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer commandBuffer,
                                                 const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo);

void PreCmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                                const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo);
void PostCmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                                 const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo);

void PreCmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
                                                    const VkAccelerationStructureKHR* pAccelerationStructures,
                                                    VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery);
void PostCmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
                                                     const VkAccelerationStructureKHR* pAccelerationStructures,
                                                     VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery);

void PreCmdTraceRaysKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                        const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                        const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                        const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width,
                        uint32_t height, uint32_t depth);
void PostCmdTraceRaysKHR(VkCommandBuffer commandBuffer,
                         const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                         const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                         const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                         const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width,
                         uint32_t height, uint32_t depth);

void PreCmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer,
                                const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                VkDeviceAddress indirectDeviceAddress);
void PostCmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer,
                                 const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                 const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                 const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                 const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                 VkDeviceAddress indirectDeviceAddress);

void PreCmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize);
void PostCmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize);

void PreCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                            uint32_t groupCountZ);
void PostCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                             uint32_t groupCountZ);

void PreCmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                    uint32_t drawCount, uint32_t stride);
void PostCmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                     uint32_t drawCount, uint32_t stride);

void PreCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                         VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                         uint32_t stride);
void PostCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                          VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                          uint32_t stride);

// NOLINTEND
