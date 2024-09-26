
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
 * ***   Update source file context_generator.py for modifications
 * *** ---- WARNING! ----
 *
 ****************************************************************************/

// NOLINTBEGIN

VkResult PreBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo) override;
VkResult PostBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo,
                                VkResult result) override;

VkResult PreEndCommandBuffer(VkCommandBuffer commandBuffer) override;
VkResult PostEndCommandBuffer(VkCommandBuffer commandBuffer, VkResult result) override;

VkResult PreResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) override;
VkResult PostResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags,
                                VkResult result) override;

void PreCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                        VkPipeline pipeline) override;
void PostCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                         VkPipeline pipeline) override;

void PreCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                       const VkViewport* pViewports) override;
void PostCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                        const VkViewport* pViewports) override;

void PreCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount,
                      const VkRect2D* pScissors) override;
void PostCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount,
                       const VkRect2D* pScissors) override;

void PreCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) override;
void PostCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) override;

void PreCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp,
                        float depthBiasSlopeFactor) override;
void PostCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp,
                         float depthBiasSlopeFactor) override;

void PreCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]) override;
void PostCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]) override;

void PreCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) override;
void PostCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) override;

void PreCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                 uint32_t compareMask) override;
void PostCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                  uint32_t compareMask) override;

void PreCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask) override;
void PostCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                uint32_t writeMask) override;

void PreCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference) override;
void PostCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                uint32_t reference) override;

void PreCmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                              VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount,
                              const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount,
                              const uint32_t* pDynamicOffsets) override;
void PostCmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                               VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount,
                               const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount,
                               const uint32_t* pDynamicOffsets) override;

void PreCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                           VkIndexType indexType) override;
void PostCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                            VkIndexType indexType) override;

void PreCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                             const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) override;
void PostCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                              const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) override;

void PreCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex,
                uint32_t firstInstance) override;
void PostCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex,
                 uint32_t firstInstance) override;

void PreCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex,
                       int32_t vertexOffset, uint32_t firstInstance) override;
void PostCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex,
                        int32_t vertexOffset, uint32_t firstInstance) override;

void PreCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount,
                        uint32_t stride) override;
void PostCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount,
                         uint32_t stride) override;

void PreCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount,
                               uint32_t stride) override;
void PostCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount,
                                uint32_t stride) override;

void PreCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                    uint32_t groupCountZ) override;
void PostCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                     uint32_t groupCountZ) override;

void PreCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) override;
void PostCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) override;

void PreCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount,
                      const VkBufferCopy* pRegions) override;
void PostCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount,
                       const VkBufferCopy* pRegions) override;

void PreCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage,
                     VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions) override;
void PostCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage,
                      VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions) override;

void PreCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage,
                     VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions,
                     VkFilter filter) override;
void PostCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage,
                      VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions,
                      VkFilter filter) override;

void PreCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage,
                             VkImageLayout dstImageLayout, uint32_t regionCount,
                             const VkBufferImageCopy* pRegions) override;
void PostCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage,
                              VkImageLayout dstImageLayout, uint32_t regionCount,
                              const VkBufferImageCopy* pRegions) override;

void PreCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                             VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions) override;
void PostCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                              VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions) override;

void PreCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                        VkDeviceSize dataSize, const void* pData) override;
void PostCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                         VkDeviceSize dataSize, const void* pData) override;

void PreCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size,
                      uint32_t data) override;
void PostCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size,
                       uint32_t data) override;

void PreCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                           const VkClearColorValue* pColor, uint32_t rangeCount,
                           const VkImageSubresourceRange* pRanges) override;
void PostCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                            const VkClearColorValue* pColor, uint32_t rangeCount,
                            const VkImageSubresourceRange* pRanges) override;

void PreCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                  const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount,
                                  const VkImageSubresourceRange* pRanges) override;
void PostCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                   const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount,
                                   const VkImageSubresourceRange* pRanges) override;

void PreCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                            const VkClearAttachment* pAttachments, uint32_t rectCount,
                            const VkClearRect* pRects) override;
void PostCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                             const VkClearAttachment* pAttachments, uint32_t rectCount,
                             const VkClearRect* pRects) override;

void PreCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage,
                        VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions) override;
void PostCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                         VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                         const VkImageResolve* pRegions) override;

void PreCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) override;
void PostCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) override;

void PreCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) override;
void PostCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) override;

void PreCmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                      VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount,
                      const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount,
                      const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount,
                      const VkImageMemoryBarrier* pImageMemoryBarriers) override;
void PostCmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                       VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask,
                       uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                       uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                       uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) override;

void PreCmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask,
                           VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags,
                           uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                           uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                           uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) override;
void PostCmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask,
                            VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags,
                            uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                            uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                            uint32_t imageMemoryBarrierCount,
                            const VkImageMemoryBarrier* pImageMemoryBarriers) override;

void PreCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                      VkQueryControlFlags flags) override;
void PostCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                       VkQueryControlFlags flags) override;

void PreCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) override;
void PostCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) override;

void PreCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                          uint32_t queryCount) override;
void PostCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                           uint32_t queryCount) override;

void PreCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool,
                          uint32_t query) override;
void PostCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool,
                           uint32_t query) override;

void PreCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride,
                                VkQueryResultFlags flags) override;
void PostCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                 uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride,
                                 VkQueryResultFlags flags) override;

void PreCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags,
                         uint32_t offset, uint32_t size, const void* pValues) override;
void PostCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags,
                          uint32_t offset, uint32_t size, const void* pValues) override;

void PreCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                           VkSubpassContents contents) override;
void PostCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                            VkSubpassContents contents) override;

void PreCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) override;
void PostCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) override;

void PreCmdEndRenderPass(VkCommandBuffer commandBuffer) override;
void PostCmdEndRenderPass(VkCommandBuffer commandBuffer) override;

void PreCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount,
                           const VkCommandBuffer* pCommandBuffers) override;
void PostCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount,
                            const VkCommandBuffer* pCommandBuffers) override;

void PreCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) override;
void PostCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) override;

void PreCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ,
                        uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) override;
void PostCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ,
                         uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) override;

void PreCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer,
                             VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) override;
void PostCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer,
                              VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) override;

void PreCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                    VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                    uint32_t stride) override;
void PostCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                     VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                     uint32_t stride) override;

void PreCmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                            const VkSubpassBeginInfo* pSubpassBeginInfo) override;
void PostCmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                             const VkSubpassBeginInfo* pSubpassBeginInfo) override;

void PreCmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                        const VkSubpassEndInfo* pSubpassEndInfo) override;
void PostCmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                         const VkSubpassEndInfo* pSubpassEndInfo) override;

void PreCmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) override;
void PostCmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) override;

void PreCmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) override;
void PostCmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) override;

void PreCmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) override;
void PostCmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) override;

void PreCmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                       const VkDependencyInfo* pDependencyInfos) override;
void PostCmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                        const VkDependencyInfo* pDependencyInfos) override;

void PreCmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) override;
void PostCmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) override;

void PreCmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool,
                           uint32_t query) override;
void PostCmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool,
                            uint32_t query) override;

void PreCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) override;
void PostCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) override;

void PreCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) override;
void PostCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) override;

void PreCmdCopyBufferToImage2(VkCommandBuffer commandBuffer,
                              const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) override;
void PostCmdCopyBufferToImage2(VkCommandBuffer commandBuffer,
                               const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) override;

void PreCmdCopyImageToBuffer2(VkCommandBuffer commandBuffer,
                              const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) override;
void PostCmdCopyImageToBuffer2(VkCommandBuffer commandBuffer,
                               const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) override;

void PreCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) override;
void PostCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) override;

void PreCmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) override;
void PostCmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) override;

void PreCmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) override;
void PostCmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) override;

void PreCmdEndRendering(VkCommandBuffer commandBuffer) override;
void PostCmdEndRendering(VkCommandBuffer commandBuffer) override;

void PreCmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) override;
void PostCmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) override;

void PreCmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace) override;
void PostCmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace) override;

void PreCmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) override;
void PostCmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) override;

void PreCmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                const VkViewport* pViewports) override;
void PostCmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                 const VkViewport* pViewports) override;

void PreCmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                               const VkRect2D* pScissors) override;
void PostCmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                const VkRect2D* pScissors) override;

void PreCmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                              const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                              const VkDeviceSize* pStrides) override;
void PostCmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                               const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                               const VkDeviceSize* pStrides) override;

void PreCmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) override;
void PostCmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) override;

void PreCmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) override;
void PostCmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) override;

void PreCmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) override;
void PostCmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) override;

void PreCmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) override;
void PostCmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) override;

void PreCmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) override;
void PostCmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) override;

void PreCmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                        VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) override;
void PostCmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                         VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) override;

void PreCmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) override;
void PostCmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) override;

void PreCmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) override;
void PostCmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) override;

void PreCmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) override;
void PostCmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) override;

void PreCmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo) override;
void PostCmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo) override;

void PreCmdEndVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo) override;
void PostCmdEndVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo) override;

void PreCmdControlVideoCodingKHR(VkCommandBuffer commandBuffer,
                                 const VkVideoCodingControlInfoKHR* pCodingControlInfo) override;
void PostCmdControlVideoCodingKHR(VkCommandBuffer commandBuffer,
                                  const VkVideoCodingControlInfoKHR* pCodingControlInfo) override;

void PreCmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo) override;
void PostCmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo) override;

void PreCmdBeginRenderingKHR(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) override;
void PostCmdBeginRenderingKHR(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) override;

void PreCmdEndRenderingKHR(VkCommandBuffer commandBuffer) override;
void PostCmdEndRenderingKHR(VkCommandBuffer commandBuffer) override;

void PreCmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask) override;
void PostCmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask) override;

void PreCmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ,
                           uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) override;
void PostCmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                            uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                            uint32_t groupCountZ) override;

void PreCmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount,
                                const VkWriteDescriptorSet* pDescriptorWrites) override;
void PostCmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                 VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount,
                                 const VkWriteDescriptorSet* pDescriptorWrites) override;

void PreCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer,
                                            VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                            VkPipelineLayout layout, uint32_t set, const void* pData) override;
void PostCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer,
                                             VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                             VkPipelineLayout layout, uint32_t set, const void* pData) override;

void PreCmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                               const VkSubpassBeginInfo* pSubpassBeginInfo) override;
void PostCmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                const VkSubpassBeginInfo* pSubpassBeginInfo) override;

void PreCmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                           const VkSubpassEndInfo* pSubpassEndInfo) override;
void PostCmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                            const VkSubpassEndInfo* pSubpassEndInfo) override;

void PreCmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) override;
void PostCmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) override;

void PreCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                uint32_t stride) override;
void PostCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                 VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                 uint32_t stride) override;

void PreCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                       VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                       uint32_t stride) override;
void PostCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                        VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                        uint32_t stride) override;

void PreCmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize,
                                     const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) override;
void PostCmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize,
                                      const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) override;

void PreCmdSetRenderingAttachmentLocationsKHR(VkCommandBuffer commandBuffer,
                                              const VkRenderingAttachmentLocationInfoKHR* pLocationInfo) override;
void PostCmdSetRenderingAttachmentLocationsKHR(VkCommandBuffer commandBuffer,
                                               const VkRenderingAttachmentLocationInfoKHR* pLocationInfo) override;

void PreCmdSetRenderingInputAttachmentIndicesKHR(
    VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfoKHR* pInputAttachmentIndexInfo) override;
void PostCmdSetRenderingInputAttachmentIndicesKHR(
    VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfoKHR* pInputAttachmentIndexInfo) override;

void PreCmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo) override;
void PostCmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo) override;

void PreCmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) override;
void PostCmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event,
                         const VkDependencyInfo* pDependencyInfo) override;

void PreCmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) override;
void PostCmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) override;

void PreCmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                          const VkDependencyInfo* pDependencyInfos) override;
void PostCmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                           const VkDependencyInfo* pDependencyInfos) override;

void PreCmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) override;
void PostCmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) override;

void PreCmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool,
                              uint32_t query) override;
void PostCmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool,
                               uint32_t query) override;

void PreCmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkBuffer dstBuffer,
                                 VkDeviceSize dstOffset, uint32_t marker) override;
void PostCmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkBuffer dstBuffer,
                                  VkDeviceSize dstOffset, uint32_t marker) override;

void PreCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) override;
void PostCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) override;

void PreCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) override;
void PostCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) override;

void PreCmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer,
                                 const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) override;
void PostCmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer,
                                  const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) override;

void PreCmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer,
                                 const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) override;
void PostCmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer,
                                  const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) override;

void PreCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) override;
void PostCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) override;

void PreCmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) override;
void PostCmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) override;

void PreCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress) override;
void PostCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress) override;

void PreCmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size,
                               VkIndexType indexType) override;
void PostCmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size,
                                VkIndexType indexType) override;

void PreCmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                             uint16_t lineStipplePattern) override;
void PostCmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                              uint16_t lineStipplePattern) override;

void PreCmdBindDescriptorSets2KHR(VkCommandBuffer commandBuffer,
                                  const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo) override;
void PostCmdBindDescriptorSets2KHR(VkCommandBuffer commandBuffer,
                                   const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo) override;

void PreCmdPushConstants2KHR(VkCommandBuffer commandBuffer, const VkPushConstantsInfoKHR* pPushConstantsInfo) override;
void PostCmdPushConstants2KHR(VkCommandBuffer commandBuffer, const VkPushConstantsInfoKHR* pPushConstantsInfo) override;

void PreCmdPushDescriptorSet2KHR(VkCommandBuffer commandBuffer,
                                 const VkPushDescriptorSetInfoKHR* pPushDescriptorSetInfo) override;
void PostCmdPushDescriptorSet2KHR(VkCommandBuffer commandBuffer,
                                  const VkPushDescriptorSetInfoKHR* pPushDescriptorSetInfo) override;

void PreCmdPushDescriptorSetWithTemplate2KHR(
    VkCommandBuffer commandBuffer,
    const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo) override;
void PostCmdPushDescriptorSetWithTemplate2KHR(
    VkCommandBuffer commandBuffer,
    const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo) override;

void PreCmdSetDescriptorBufferOffsets2EXT(
    VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo) override;
void PostCmdSetDescriptorBufferOffsets2EXT(
    VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo) override;

void PreCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    VkCommandBuffer commandBuffer,
    const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo) override;
void PostCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    VkCommandBuffer commandBuffer,
    const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo) override;

void PreCmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) override;
void PostCmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) override;

void PreCmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) override;
void PostCmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) override;

void PreCmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) override;
void PostCmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) override;

void PreCmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                           const VkBuffer* pBuffers, const VkDeviceSize* pOffsets,
                                           const VkDeviceSize* pSizes) override;
void PostCmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                            const VkBuffer* pBuffers, const VkDeviceSize* pOffsets,
                                            const VkDeviceSize* pSizes) override;

void PreCmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                     uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                     const VkDeviceSize* pCounterBufferOffsets) override;
void PostCmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                      uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                      const VkDeviceSize* pCounterBufferOffsets) override;

void PreCmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                   uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                   const VkDeviceSize* pCounterBufferOffsets) override;
void PostCmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                    uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                    const VkDeviceSize* pCounterBufferOffsets) override;

void PreCmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                VkQueryControlFlags flags, uint32_t index) override;
void PostCmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                 VkQueryControlFlags flags, uint32_t index) override;

void PreCmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                              uint32_t index) override;
void PostCmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                               uint32_t index) override;

void PreCmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance,
                                    VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset,
                                    uint32_t vertexStride) override;
void PostCmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance,
                                     VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset,
                                     uint32_t vertexStride) override;

void PreCmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo) override;
void PostCmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo) override;

void PreCmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                uint32_t stride) override;
void PostCmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                 VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                 uint32_t stride) override;

void PreCmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                       VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                       uint32_t stride) override;
void PostCmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                        VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                        uint32_t stride) override;

void PreCmdBeginConditionalRenderingEXT(VkCommandBuffer commandBuffer,
                                        const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) override;
void PostCmdBeginConditionalRenderingEXT(VkCommandBuffer commandBuffer,
                                         const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) override;

void PreCmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer) override;
void PostCmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer) override;

void PreCmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                 const VkViewportWScalingNV* pViewportWScalings) override;
void PostCmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                  const VkViewportWScalingNV* pViewportWScalings) override;

void PreCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle,
                                  uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) override;
void PostCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle,
                                   uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) override;

void PreCmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable) override;
void PostCmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable) override;

void PreCmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer,
                                      VkDiscardRectangleModeEXT discardRectangleMode) override;
void PostCmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer,
                                       VkDiscardRectangleModeEXT discardRectangleMode) override;

void PreCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) override;
void PostCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) override;

void PreCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) override;
void PostCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) override;

void PreCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) override;
void PostCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) override;

#ifdef VK_ENABLE_BETA_EXTENSIONS
void PreCmdInitializeGraphScratchMemoryAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch) override;
void PostCmdInitializeGraphScratchMemoryAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch) override;
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void PreCmdDispatchGraphAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                             const VkDispatchGraphCountInfoAMDX* pCountInfo) override;
void PostCmdDispatchGraphAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                              const VkDispatchGraphCountInfoAMDX* pCountInfo) override;
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void PreCmdDispatchGraphIndirectAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                     const VkDispatchGraphCountInfoAMDX* pCountInfo) override;
void PostCmdDispatchGraphIndirectAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                      const VkDispatchGraphCountInfoAMDX* pCountInfo) override;
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void PreCmdDispatchGraphIndirectCountAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                          VkDeviceAddress countInfo) override;
void PostCmdDispatchGraphIndirectCountAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                           VkDeviceAddress countInfo) override;
#endif  // VK_ENABLE_BETA_EXTENSIONS

void PreCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer,
                                 const VkSampleLocationsInfoEXT* pSampleLocationsInfo) override;
void PostCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer,
                                  const VkSampleLocationsInfoEXT* pSampleLocationsInfo) override;

void PreCmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView,
                                  VkImageLayout imageLayout) override;
void PostCmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView,
                                   VkImageLayout imageLayout) override;

void PreCmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                           uint32_t viewportCount,
                                           const VkShadingRatePaletteNV* pShadingRatePalettes) override;
void PostCmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                            uint32_t viewportCount,
                                            const VkShadingRatePaletteNV* pShadingRatePalettes) override;

void PreCmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType,
                                  uint32_t customSampleOrderCount,
                                  const VkCoarseSampleOrderCustomNV* pCustomSampleOrders) override;
void PostCmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType,
                                   uint32_t customSampleOrderCount,
                                   const VkCoarseSampleOrderCustomNV* pCustomSampleOrders) override;

void PreCmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo,
                                        VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update,
                                        VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch,
                                        VkDeviceSize scratchOffset) override;
void PostCmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo,
                                         VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update,
                                         VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch,
                                         VkDeviceSize scratchOffset) override;

void PreCmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst,
                                       VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode) override;
void PostCmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst,
                                        VkAccelerationStructureNV src,
                                        VkCopyAccelerationStructureModeKHR mode) override;

void PreCmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer,
                       VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer,
                       VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride,
                       VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset,
                       VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer,
                       VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride,
                       uint32_t width, uint32_t height, uint32_t depth) override;
void PostCmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer,
                        VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer,
                        VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride,
                        VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset,
                        VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer,
                        VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride,
                        uint32_t width, uint32_t height, uint32_t depth) override;

void PreCmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
                                                   const VkAccelerationStructureNV* pAccelerationStructures,
                                                   VkQueryType queryType, VkQueryPool queryPool,
                                                   uint32_t firstQuery) override;
void PostCmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
                                                    const VkAccelerationStructureNV* pAccelerationStructures,
                                                    VkQueryType queryType, VkQueryPool queryPool,
                                                    uint32_t firstQuery) override;

void PreCmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) override;
void PostCmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                 VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) override;

void PreCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask) override;
void PostCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask) override;

void PreCmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                   uint32_t drawCount, uint32_t stride) override;
void PostCmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                    uint32_t drawCount, uint32_t stride) override;

void PreCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                        VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                        uint32_t stride) override;
void PostCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                         VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                         uint32_t stride) override;

void PreCmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                       uint32_t exclusiveScissorCount,
                                       const VkBool32* pExclusiveScissorEnables) override;
void PostCmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                        uint32_t exclusiveScissorCount,
                                        const VkBool32* pExclusiveScissorEnables) override;

void PreCmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                 uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors) override;
void PostCmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                  uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors) override;

void PreCmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker) override;
void PostCmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker) override;

VkResult PreCmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer,
                                         const VkPerformanceMarkerInfoINTEL* pMarkerInfo) override;
VkResult PostCmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer,
                                          const VkPerformanceMarkerInfoINTEL* pMarkerInfo, VkResult result) override;

VkResult PreCmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer,
                                               const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo) override;
VkResult PostCmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer,
                                                const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo,
                                                VkResult result) override;

VkResult PreCmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer,
                                           const VkPerformanceOverrideInfoINTEL* pOverrideInfo) override;
VkResult PostCmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer,
                                            const VkPerformanceOverrideInfoINTEL* pOverrideInfo,
                                            VkResult result) override;

void PreCmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                             uint16_t lineStipplePattern) override;
void PostCmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                              uint16_t lineStipplePattern) override;

void PreCmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) override;
void PostCmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) override;

void PreCmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) override;
void PostCmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) override;

void PreCmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) override;
void PostCmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) override;

void PreCmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                   const VkViewport* pViewports) override;
void PostCmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                    const VkViewport* pViewports) override;

void PreCmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                  const VkRect2D* pScissors) override;
void PostCmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                   const VkRect2D* pScissors) override;

void PreCmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                 const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                                 const VkDeviceSize* pStrides) override;
void PostCmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                  const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                                  const VkDeviceSize* pStrides) override;

void PreCmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) override;
void PostCmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) override;

void PreCmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) override;
void PostCmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) override;

void PreCmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) override;
void PostCmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) override;

void PreCmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) override;
void PostCmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) override;

void PreCmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) override;
void PostCmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) override;

void PreCmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                           VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) override;
void PostCmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                            VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) override;

void PreCmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer,
                                         const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) override;
void PostCmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer,
                                          const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) override;

void PreCmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                      const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) override;
void PostCmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                       const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) override;

void PreCmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                     VkPipeline pipeline, uint32_t groupIndex) override;
void PostCmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                      VkPipeline pipeline, uint32_t groupIndex) override;

void PreCmdSetDepthBias2EXT(VkCommandBuffer commandBuffer, const VkDepthBiasInfoEXT* pDepthBiasInfo) override;
void PostCmdSetDepthBias2EXT(VkCommandBuffer commandBuffer, const VkDepthBiasInfoEXT* pDepthBiasInfo) override;

void PreCmdCudaLaunchKernelNV(VkCommandBuffer commandBuffer, const VkCudaLaunchInfoNV* pLaunchInfo) override;
void PostCmdCudaLaunchKernelNV(VkCommandBuffer commandBuffer, const VkCudaLaunchInfoNV* pLaunchInfo) override;

void PreCmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount,
                                    const VkDescriptorBufferBindingInfoEXT* pBindingInfos) override;
void PostCmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount,
                                     const VkDescriptorBufferBindingInfoEXT* pBindingInfos) override;

void PreCmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                         VkPipelineLayout layout, uint32_t firstSet, uint32_t setCount,
                                         const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets) override;
void PostCmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                          VkPipelineLayout layout, uint32_t firstSet, uint32_t setCount,
                                          const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets) override;

void PreCmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                   VkPipelineLayout layout, uint32_t set) override;
void PostCmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer commandBuffer,
                                                    VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout,
                                                    uint32_t set) override;

void PreCmdSetFragmentShadingRateEnumNV(VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate,
                                        const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) override;
void PostCmdSetFragmentShadingRateEnumNV(VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate,
                                         const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) override;

void PreCmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
                             const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions,
                             uint32_t vertexAttributeDescriptionCount,
                             const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) override;
void PostCmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
                              const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions,
                              uint32_t vertexAttributeDescriptionCount,
                              const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) override;

void PreCmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer) override;
void PostCmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer) override;

void PreCmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer, VkImageView imageView,
                                    VkImageLayout imageLayout) override;
void PostCmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer, VkImageView imageView,
                                     VkImageLayout imageLayout) override;

void PreCmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints) override;
void PostCmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints) override;

void PreCmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) override;
void PostCmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) override;

void PreCmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) override;
void PostCmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) override;

void PreCmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp) override;
void PostCmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp) override;

void PreCmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) override;
void PostCmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) override;

void PreCmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                  const VkBool32* pColorWriteEnables) override;
void PostCmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                   const VkBool32* pColorWriteEnables) override;

void PreCmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawInfoEXT* pVertexInfo,
                        uint32_t instanceCount, uint32_t firstInstance, uint32_t stride) override;
void PostCmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawInfoEXT* pVertexInfo,
                         uint32_t instanceCount, uint32_t firstInstance, uint32_t stride) override;

void PreCmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                               const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount,
                               uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset) override;
void PostCmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount,
                                uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset) override;

void PreCmdBuildMicromapsEXT(VkCommandBuffer commandBuffer, uint32_t infoCount,
                             const VkMicromapBuildInfoEXT* pInfos) override;
void PostCmdBuildMicromapsEXT(VkCommandBuffer commandBuffer, uint32_t infoCount,
                              const VkMicromapBuildInfoEXT* pInfos) override;

void PreCmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo) override;
void PostCmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo) override;

void PreCmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo) override;
void PostCmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo) override;

void PreCmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo) override;
void PostCmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo) override;

void PreCmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount,
                                       const VkMicromapEXT* pMicromaps, VkQueryType queryType, VkQueryPool queryPool,
                                       uint32_t firstQuery) override;
void PostCmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount,
                                        const VkMicromapEXT* pMicromaps, VkQueryType queryType, VkQueryPool queryPool,
                                        uint32_t firstQuery) override;

void PreCmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                             uint32_t groupCountZ) override;
void PostCmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                              uint32_t groupCountZ) override;

void PreCmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) override;
void PostCmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) override;

void PreCmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount,
                                uint32_t stride) override;
void PostCmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount,
                                 uint32_t stride) override;

void PreCmdCopyMemoryToImageIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                       uint32_t copyCount, uint32_t stride, VkImage dstImage,
                                       VkImageLayout dstImageLayout,
                                       const VkImageSubresourceLayers* pImageSubresources) override;
void PostCmdCopyMemoryToImageIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                        uint32_t copyCount, uint32_t stride, VkImage dstImage,
                                        VkImageLayout dstImageLayout,
                                        const VkImageSubresourceLayers* pImageSubresources) override;

void PreCmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount,
                              const VkDecompressMemoryRegionNV* pDecompressMemoryRegions) override;
void PostCmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount,
                               const VkDecompressMemoryRegionNV* pDecompressMemoryRegions) override;

void PreCmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer, VkDeviceAddress indirectCommandsAddress,
                                           VkDeviceAddress indirectCommandsCountAddress, uint32_t stride) override;
void PostCmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer, VkDeviceAddress indirectCommandsAddress,
                                            VkDeviceAddress indirectCommandsCountAddress, uint32_t stride) override;

void PreCmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                          VkPipeline pipeline) override;
void PostCmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                           VkPipeline pipeline) override;

void PreCmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClampEnable) override;
void PostCmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClampEnable) override;

void PreCmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode) override;
void PostCmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode) override;

void PreCmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer,
                                      VkSampleCountFlagBits rasterizationSamples) override;
void PostCmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer,
                                       VkSampleCountFlagBits rasterizationSamples) override;

void PreCmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples,
                            const VkSampleMask* pSampleMask) override;
void PostCmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples,
                             const VkSampleMask* pSampleMask) override;

void PreCmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable) override;
void PostCmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable) override;

void PreCmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable) override;
void PostCmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable) override;

void PreCmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable) override;
void PostCmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable) override;

void PreCmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
                                  const VkBool32* pColorBlendEnables) override;
void PostCmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
                                   const VkBool32* pColorBlendEnables) override;

void PreCmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
                                    const VkColorBlendEquationEXT* pColorBlendEquations) override;
void PostCmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
                                     const VkColorBlendEquationEXT* pColorBlendEquations) override;

void PreCmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
                                const VkColorComponentFlags* pColorWriteMasks) override;
void PostCmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
                                 const VkColorComponentFlags* pColorWriteMasks) override;

void PreCmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer,
                                          VkTessellationDomainOrigin domainOrigin) override;
void PostCmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer,
                                           VkTessellationDomainOrigin domainOrigin) override;

void PreCmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer, uint32_t rasterizationStream) override;
void PostCmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer, uint32_t rasterizationStream) override;

void PreCmdSetConservativeRasterizationModeEXT(
    VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode) override;
void PostCmdSetConservativeRasterizationModeEXT(
    VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode) override;

void PreCmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer commandBuffer,
                                                  float extraPrimitiveOverestimationSize) override;
void PostCmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer commandBuffer,
                                                   float extraPrimitiveOverestimationSize) override;

void PreCmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClipEnable) override;
void PostCmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClipEnable) override;

void PreCmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable) override;
void PostCmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable) override;

void PreCmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
                                    const VkColorBlendAdvancedEXT* pColorBlendAdvanced) override;
void PostCmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
                                     const VkColorBlendAdvancedEXT* pColorBlendAdvanced) override;

void PreCmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer,
                                     VkProvokingVertexModeEXT provokingVertexMode) override;
void PostCmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer,
                                      VkProvokingVertexModeEXT provokingVertexMode) override;

void PreCmdSetLineRasterizationModeEXT(VkCommandBuffer commandBuffer,
                                       VkLineRasterizationModeEXT lineRasterizationMode) override;
void PostCmdSetLineRasterizationModeEXT(VkCommandBuffer commandBuffer,
                                        VkLineRasterizationModeEXT lineRasterizationMode) override;

void PreCmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable) override;
void PostCmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable) override;

void PreCmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne) override;
void PostCmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne) override;

void PreCmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable) override;
void PostCmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable) override;

void PreCmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                const VkViewportSwizzleNV* pViewportSwizzles) override;
void PostCmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                 const VkViewportSwizzleNV* pViewportSwizzles) override;

void PreCmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable) override;
void PostCmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable) override;

void PreCmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation) override;
void PostCmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation) override;

void PreCmdSetCoverageModulationModeNV(VkCommandBuffer commandBuffer,
                                       VkCoverageModulationModeNV coverageModulationMode) override;
void PostCmdSetCoverageModulationModeNV(VkCommandBuffer commandBuffer,
                                        VkCoverageModulationModeNV coverageModulationMode) override;

void PreCmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer,
                                              VkBool32 coverageModulationTableEnable) override;
void PostCmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer,
                                               VkBool32 coverageModulationTableEnable) override;

void PreCmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount,
                                        const float* pCoverageModulationTable) override;
void PostCmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount,
                                         const float* pCoverageModulationTable) override;

void PreCmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable) override;
void PostCmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable) override;

void PreCmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer commandBuffer,
                                                 VkBool32 representativeFragmentTestEnable) override;
void PostCmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer commandBuffer,
                                                  VkBool32 representativeFragmentTestEnable) override;

void PreCmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer,
                                      VkCoverageReductionModeNV coverageReductionMode) override;
void PostCmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer,
                                       VkCoverageReductionModeNV coverageReductionMode) override;

void PreCmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session,
                                const VkOpticalFlowExecuteInfoNV* pExecuteInfo) override;
void PostCmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session,
                                 const VkOpticalFlowExecuteInfoNV* pExecuteInfo) override;

void PreCmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount, const VkShaderStageFlagBits* pStages,
                          const VkShaderEXT* pShaders) override;
void PostCmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount, const VkShaderStageFlagBits* pStages,
                           const VkShaderEXT* pShaders) override;

void PreCmdSetDepthClampRangeEXT(VkCommandBuffer commandBuffer, VkDepthClampModeEXT depthClampMode,
                                 const VkDepthClampRangeEXT* pDepthClampRange) override;
void PostCmdSetDepthClampRangeEXT(VkCommandBuffer commandBuffer, VkDepthClampModeEXT depthClampMode,
                                  const VkDepthClampRangeEXT* pDepthClampRange) override;

void PreCmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer, VkImageAspectFlags aspectMask) override;
void PostCmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer, VkImageAspectFlags aspectMask) override;

void PreCmdPreprocessGeneratedCommandsEXT(VkCommandBuffer commandBuffer,
                                          const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo,
                                          VkCommandBuffer stateCommandBuffer) override;
void PostCmdPreprocessGeneratedCommandsEXT(VkCommandBuffer commandBuffer,
                                           const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo,
                                           VkCommandBuffer stateCommandBuffer) override;

void PreCmdExecuteGeneratedCommandsEXT(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                       const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo) override;
void PostCmdExecuteGeneratedCommandsEXT(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                        const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo) override;

void PreCmdBuildAccelerationStructuresKHR(
    VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) override;
void PostCmdBuildAccelerationStructuresKHR(
    VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) override;

void PreCmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                                  const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
                                                  const VkDeviceAddress* pIndirectDeviceAddresses,
                                                  const uint32_t* pIndirectStrides,
                                                  const uint32_t* const* ppMaxPrimitiveCounts) override;
void PostCmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                                   const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
                                                   const VkDeviceAddress* pIndirectDeviceAddresses,
                                                   const uint32_t* pIndirectStrides,
                                                   const uint32_t* const* ppMaxPrimitiveCounts) override;

void PreCmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                        const VkCopyAccelerationStructureInfoKHR* pInfo) override;
void PostCmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                         const VkCopyAccelerationStructureInfoKHR* pInfo) override;

void PreCmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer commandBuffer,
                                                const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) override;
void PostCmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer commandBuffer,
                                                 const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) override;

void PreCmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                                const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) override;
void PostCmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                                 const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) override;

void PreCmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
                                                    const VkAccelerationStructureKHR* pAccelerationStructures,
                                                    VkQueryType queryType, VkQueryPool queryPool,
                                                    uint32_t firstQuery) override;
void PostCmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
                                                     const VkAccelerationStructureKHR* pAccelerationStructures,
                                                     VkQueryType queryType, VkQueryPool queryPool,
                                                     uint32_t firstQuery) override;

void PreCmdTraceRaysKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                        const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                        const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                        const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width,
                        uint32_t height, uint32_t depth) override;
void PostCmdTraceRaysKHR(VkCommandBuffer commandBuffer,
                         const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                         const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                         const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                         const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width,
                         uint32_t height, uint32_t depth) override;

void PreCmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer,
                                const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                VkDeviceAddress indirectDeviceAddress) override;
void PostCmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer,
                                 const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                 const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                 const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                 const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                 VkDeviceAddress indirectDeviceAddress) override;

void PreCmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize) override;
void PostCmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize) override;

void PreCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                            uint32_t groupCountZ) override;
void PostCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                             uint32_t groupCountZ) override;

void PreCmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                    uint32_t drawCount, uint32_t stride) override;
void PostCmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                     uint32_t drawCount, uint32_t stride) override;

void PreCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                         VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                         uint32_t stride) override;
void PostCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                          VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                          uint32_t stride) override;

// NOLINTEND
