
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
 * ***   Update source file intercepts_and_prepost_generator.py for modifications
 * *** ---- WARNING! ----
 *
 ****************************************************************************/

// NOLINTBEGIN

void CommandBuffer::PreCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                       VkPipeline pipeline) {
    tracker_.TrackPreCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
    WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                        VkPipeline pipeline) {
    tracker_.TrackPostCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
    WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                      const VkViewport* pViewports) {
    tracker_.TrackPreCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                       const VkViewport* pViewports) {
    tracker_.TrackPostCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount,
                                     const VkRect2D* pScissors) {
    tracker_.TrackPreCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount,
                                      const VkRect2D* pScissors) {
    tracker_.TrackPostCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) {
    tracker_.TrackPreCmdSetLineWidth(commandBuffer, lineWidth);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) {
    tracker_.TrackPostCmdSetLineWidth(commandBuffer, lineWidth);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor,
                                       float depthBiasClamp, float depthBiasSlopeFactor) {
    tracker_.TrackPreCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor,
                                        float depthBiasClamp, float depthBiasSlopeFactor) {
    tracker_.TrackPostCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]) {
    tracker_.TrackPreCmdSetBlendConstants(commandBuffer, blendConstants);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]) {
    tracker_.TrackPostCmdSetBlendConstants(commandBuffer, blendConstants);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) {
    tracker_.TrackPreCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) {
    tracker_.TrackPostCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                                uint32_t compareMask) {
    tracker_.TrackPreCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                                 uint32_t compareMask) {
    tracker_.TrackPostCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                              uint32_t writeMask) {
    tracker_.TrackPreCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                               uint32_t writeMask) {
    tracker_.TrackPostCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                              uint32_t reference) {
    tracker_.TrackPreCmdSetStencilReference(commandBuffer, faceMask, reference);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                               uint32_t reference) {
    tracker_.TrackPostCmdSetStencilReference(commandBuffer, faceMask, reference);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                             VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount,
                                             const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount,
                                             const uint32_t* pDynamicOffsets) {
    tracker_.TrackPreCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount,
                                           pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                              VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount,
                                              const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount,
                                              const uint32_t* pDynamicOffsets) {
    tracker_.TrackPostCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount,
                                            pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                          VkIndexType indexType) {
    tracker_.TrackPreCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                           VkIndexType indexType) {
    tracker_.TrackPostCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                            const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) {
    tracker_.TrackPreCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                             uint32_t bindingCount, const VkBuffer* pBuffers,
                                             const VkDeviceSize* pOffsets) {
    tracker_.TrackPostCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount,
                               uint32_t firstVertex, uint32_t firstInstance) {
    tracker_.TrackPreCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount,
                                uint32_t firstVertex, uint32_t firstInstance) {
    tracker_.TrackPostCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount,
                                      uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) {
    tracker_.TrackPreCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount,
                                       uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) {
    tracker_.TrackPostCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                       uint32_t drawCount, uint32_t stride) {
    tracker_.TrackPreCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
    WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                        uint32_t drawCount, uint32_t stride) {
    tracker_.TrackPostCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
    WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                              uint32_t drawCount, uint32_t stride) {
    tracker_.TrackPreCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
    WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                               uint32_t drawCount, uint32_t stride) {
    tracker_.TrackPostCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
    WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                   uint32_t groupCountZ) {
    tracker_.TrackPreCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
    WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                    uint32_t groupCountZ) {
    tracker_.TrackPostCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
    WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {
    tracker_.TrackPreCmdDispatchIndirect(commandBuffer, buffer, offset);
    WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {
    tracker_.TrackPostCmdDispatchIndirect(commandBuffer, buffer, offset);
    WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer,
                                     uint32_t regionCount, const VkBufferCopy* pRegions) {
    tracker_.TrackPreCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
    WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer,
                                      uint32_t regionCount, const VkBufferCopy* pRegions) {
    tracker_.TrackPostCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
    WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                    VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                    const VkImageCopy* pRegions) {
    tracker_.TrackPreCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount,
                                  pRegions);
    WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                     VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                     const VkImageCopy* pRegions) {
    tracker_.TrackPostCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount,
                                   pRegions);
    WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                    VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                    const VkImageBlit* pRegions, VkFilter filter) {
    tracker_.TrackPreCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount,
                                  pRegions, filter);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                     VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                     const VkImageBlit* pRegions, VkFilter filter) {
    tracker_.TrackPostCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount,
                                   pRegions, filter);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage,
                                            VkImageLayout dstImageLayout, uint32_t regionCount,
                                            const VkBufferImageCopy* pRegions) {
    tracker_.TrackPreCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
    WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage,
                                             VkImageLayout dstImageLayout, uint32_t regionCount,
                                             const VkBufferImageCopy* pRegions) {
    tracker_.TrackPostCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
    WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage,
                                            VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount,
                                            const VkBufferImageCopy* pRegions) {
    tracker_.TrackPreCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
    WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage,
                                             VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount,
                                             const VkBufferImageCopy* pRegions) {
    tracker_.TrackPostCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
    WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                       VkDeviceSize dataSize, const void* pData) {
    tracker_.TrackPreCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                        VkDeviceSize dataSize, const void* pData) {
    tracker_.TrackPostCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                     VkDeviceSize size, uint32_t data) {
    tracker_.TrackPreCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                      VkDeviceSize size, uint32_t data) {
    tracker_.TrackPostCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                          const VkClearColorValue* pColor, uint32_t rangeCount,
                                          const VkImageSubresourceRange* pRanges) {
    tracker_.TrackPreCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                           const VkClearColorValue* pColor, uint32_t rangeCount,
                                           const VkImageSubresourceRange* pRanges) {
    tracker_.TrackPostCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image,
                                                 VkImageLayout imageLayout,
                                                 const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount,
                                                 const VkImageSubresourceRange* pRanges) {
    tracker_.TrackPreCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image,
                                                  VkImageLayout imageLayout,
                                                  const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount,
                                                  const VkImageSubresourceRange* pRanges) {
    tracker_.TrackPostCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                           const VkClearAttachment* pAttachments, uint32_t rectCount,
                                           const VkClearRect* pRects) {
    tracker_.TrackPreCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                            const VkClearAttachment* pAttachments, uint32_t rectCount,
                                            const VkClearRect* pRects) {
    tracker_.TrackPostCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                       VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                       const VkImageResolve* pRegions) {
    tracker_.TrackPreCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount,
                                     pRegions);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                        VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                        const VkImageResolve* pRegions) {
    tracker_.TrackPostCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount,
                                      pRegions);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
    tracker_.TrackPreCmdSetEvent(commandBuffer, event, stageMask);
    WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
    tracker_.TrackPostCmdSetEvent(commandBuffer, event, stageMask);
    WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
    tracker_.TrackPreCmdResetEvent(commandBuffer, event, stageMask);
    WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
    tracker_.TrackPostCmdResetEvent(commandBuffer, event, stageMask);
    WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                     VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask,
                                     uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                                     uint32_t bufferMemoryBarrierCount,
                                     const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                     uint32_t imageMemoryBarrierCount,
                                     const VkImageMemoryBarrier* pImageMemoryBarriers) {
    tracker_.TrackPreCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount,
                                   pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers,
                                   imageMemoryBarrierCount, pImageMemoryBarriers);
    WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                      VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask,
                                      uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                                      uint32_t bufferMemoryBarrierCount,
                                      const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                      uint32_t imageMemoryBarrierCount,
                                      const VkImageMemoryBarrier* pImageMemoryBarriers) {
    tracker_.TrackPostCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount,
                                    pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers,
                                    imageMemoryBarrierCount, pImageMemoryBarriers);
    WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask,
                                          VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags,
                                          uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                                          uint32_t bufferMemoryBarrierCount,
                                          const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                          uint32_t imageMemoryBarrierCount,
                                          const VkImageMemoryBarrier* pImageMemoryBarriers) {
    tracker_.TrackPreCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount,
                                        pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers,
                                        imageMemoryBarrierCount, pImageMemoryBarriers);
    WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask,
                                           VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags,
                                           uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                                           uint32_t bufferMemoryBarrierCount,
                                           const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                           uint32_t imageMemoryBarrierCount,
                                           const VkImageMemoryBarrier* pImageMemoryBarriers) {
    tracker_.TrackPostCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount,
                                         pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers,
                                         imageMemoryBarrierCount, pImageMemoryBarriers);
    WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                     VkQueryControlFlags flags) {
    tracker_.TrackPreCmdBeginQuery(commandBuffer, queryPool, query, flags);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                      VkQueryControlFlags flags) {
    tracker_.TrackPostCmdBeginQuery(commandBuffer, queryPool, query, flags);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) {
    tracker_.TrackPreCmdEndQuery(commandBuffer, queryPool, query);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) {
    tracker_.TrackPostCmdEndQuery(commandBuffer, queryPool, query);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                         uint32_t queryCount) {
    tracker_.TrackPreCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                          uint32_t queryCount) {
    tracker_.TrackPostCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                         VkQueryPool queryPool, uint32_t query) {
    tracker_.TrackPreCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                          VkQueryPool queryPool, uint32_t query) {
    tracker_.TrackPostCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool,
                                               uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer,
                                               VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags) {
    tracker_.TrackPreCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset,
                                             stride, flags);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool,
                                                uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer,
                                                VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags) {
    tracker_.TrackPostCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset,
                                              stride, flags);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout,
                                        VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size,
                                        const void* pValues) {
    tracker_.TrackPreCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout,
                                         VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size,
                                         const void* pValues) {
    tracker_.TrackPostCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                          VkSubpassContents contents) {
    tracker_.TrackPreCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                           VkSubpassContents contents) {
    tracker_.TrackPostCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) {
    tracker_.TrackPreCmdNextSubpass(commandBuffer, contents);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) {
    tracker_.TrackPostCmdNextSubpass(commandBuffer, contents);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdEndRenderPass(VkCommandBuffer commandBuffer) {
    tracker_.TrackPreCmdEndRenderPass(commandBuffer);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdEndRenderPass(VkCommandBuffer commandBuffer) {
    tracker_.TrackPostCmdEndRenderPass(commandBuffer);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount,
                                          const VkCommandBuffer* pCommandBuffers) {
    tracker_.TrackPreCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
    WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount,
                                           const VkCommandBuffer* pCommandBuffers) {
    tracker_.TrackPostCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
    WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    tracker_.TrackPreCmdSetDeviceMask(commandBuffer, deviceMask);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    tracker_.TrackPostCmdSetDeviceMask(commandBuffer, deviceMask);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                       uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                       uint32_t groupCountZ) {
    tracker_.TrackPreCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY,
                                     groupCountZ);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                        uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                        uint32_t groupCountZ) {
    tracker_.TrackPostCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY,
                                      groupCountZ);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                            VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                            uint32_t stride) {
    tracker_.TrackPreCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount,
                                          stride);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                             VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                             uint32_t maxDrawCount, uint32_t stride) {
    tracker_.TrackPostCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount,
                                           stride);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                   VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                   uint32_t maxDrawCount, uint32_t stride) {
    tracker_.TrackPreCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                                 maxDrawCount, stride);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                    VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                    uint32_t maxDrawCount, uint32_t stride) {
    tracker_.TrackPostCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                                  maxDrawCount, stride);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                           const VkSubpassBeginInfo* pSubpassBeginInfo) {
    tracker_.TrackPreCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBeginRenderPass2(VkCommandBuffer commandBuffer,
                                            const VkRenderPassBeginInfo* pRenderPassBegin,
                                            const VkSubpassBeginInfo* pSubpassBeginInfo) {
    tracker_.TrackPostCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                                       const VkSubpassEndInfo* pSubpassEndInfo) {
    tracker_.TrackPreCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                                        const VkSubpassEndInfo* pSubpassEndInfo) {
    tracker_.TrackPostCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {
    tracker_.TrackPreCmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {
    tracker_.TrackPostCmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event,
                                    const VkDependencyInfo* pDependencyInfo) {
    tracker_.TrackPreCmdSetEvent2(commandBuffer, event, pDependencyInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event,
                                     const VkDependencyInfo* pDependencyInfo) {
    tracker_.TrackPostCmdSetEvent2(commandBuffer, event, pDependencyInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) {
    tracker_.TrackPreCmdResetEvent2(commandBuffer, event, stageMask);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) {
    tracker_.TrackPostCmdResetEvent2(commandBuffer, event, stageMask);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                      const VkDependencyInfo* pDependencyInfos) {
    tracker_.TrackPreCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                       const VkDependencyInfo* pDependencyInfos) {
    tracker_.TrackPostCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {
    tracker_.TrackPreCmdPipelineBarrier2(commandBuffer, pDependencyInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {
    tracker_.TrackPostCmdPipelineBarrier2(commandBuffer, pDependencyInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                          VkQueryPool queryPool, uint32_t query) {
    tracker_.TrackPreCmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                           VkQueryPool queryPool, uint32_t query) {
    tracker_.TrackPostCmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {
    tracker_.TrackPreCmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {
    tracker_.TrackPostCmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {
    tracker_.TrackPreCmdCopyImage2(commandBuffer, pCopyImageInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {
    tracker_.TrackPostCmdCopyImage2(commandBuffer, pCopyImageInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyBufferToImage2(VkCommandBuffer commandBuffer,
                                             const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    tracker_.TrackPreCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyBufferToImage2(VkCommandBuffer commandBuffer,
                                              const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    tracker_.TrackPostCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyImageToBuffer2(VkCommandBuffer commandBuffer,
                                             const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    tracker_.TrackPreCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyImageToBuffer2(VkCommandBuffer commandBuffer,
                                              const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    tracker_.TrackPostCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {
    tracker_.TrackPreCmdBlitImage2(commandBuffer, pBlitImageInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {
    tracker_.TrackPostCmdBlitImage2(commandBuffer, pBlitImageInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {
    tracker_.TrackPreCmdResolveImage2(commandBuffer, pResolveImageInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {
    tracker_.TrackPostCmdResolveImage2(commandBuffer, pResolveImageInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) {
    tracker_.TrackPreCmdBeginRendering(commandBuffer, pRenderingInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) {
    tracker_.TrackPostCmdBeginRendering(commandBuffer, pRenderingInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdEndRendering(VkCommandBuffer commandBuffer) {
    tracker_.TrackPreCmdEndRendering(commandBuffer);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdEndRendering(VkCommandBuffer commandBuffer) {
    tracker_.TrackPostCmdEndRendering(commandBuffer);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    tracker_.TrackPreCmdSetCullMode(commandBuffer, cullMode);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    tracker_.TrackPostCmdSetCullMode(commandBuffer, cullMode);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    tracker_.TrackPreCmdSetFrontFace(commandBuffer, frontFace);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    tracker_.TrackPostCmdSetFrontFace(commandBuffer, frontFace);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {
    tracker_.TrackPreCmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {
    tracker_.TrackPostCmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                               const VkViewport* pViewports) {
    tracker_.TrackPreCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                                const VkViewport* pViewports) {
    tracker_.TrackPostCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                              const VkRect2D* pScissors) {
    tracker_.TrackPreCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                               const VkRect2D* pScissors) {
    tracker_.TrackPostCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                             uint32_t bindingCount, const VkBuffer* pBuffers,
                                             const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                                             const VkDeviceSize* pStrides) {
    tracker_.TrackPreCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes,
                                           pStrides);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                              uint32_t bindingCount, const VkBuffer* pBuffers,
                                              const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                                              const VkDeviceSize* pStrides) {
    tracker_.TrackPostCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes,
                                            pStrides);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    tracker_.TrackPreCmdSetDepthTestEnable(commandBuffer, depthTestEnable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    tracker_.TrackPostCmdSetDepthTestEnable(commandBuffer, depthTestEnable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    tracker_.TrackPreCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    tracker_.TrackPostCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    tracker_.TrackPreCmdSetDepthCompareOp(commandBuffer, depthCompareOp);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    tracker_.TrackPostCmdSetDepthCompareOp(commandBuffer, depthCompareOp);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
    tracker_.TrackPreCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
    tracker_.TrackPostCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    tracker_.TrackPreCmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    tracker_.TrackPostCmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                       VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {
    tracker_.TrackPreCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                        VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {
    tracker_.TrackPostCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {
    tracker_.TrackPreCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {
    tracker_.TrackPostCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
    tracker_.TrackPreCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
    tracker_.TrackPostCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {
    tracker_.TrackPreCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {
    tracker_.TrackPostCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer,
                                              const VkVideoBeginCodingInfoKHR* pBeginInfo) {
    tracker_.TrackPreCmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer,
                                               const VkVideoBeginCodingInfoKHR* pBeginInfo) {
    tracker_.TrackPostCmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdEndVideoCodingKHR(VkCommandBuffer commandBuffer,
                                            const VkVideoEndCodingInfoKHR* pEndCodingInfo) {
    tracker_.TrackPreCmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdEndVideoCodingKHR(VkCommandBuffer commandBuffer,
                                             const VkVideoEndCodingInfoKHR* pEndCodingInfo) {
    tracker_.TrackPostCmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdControlVideoCodingKHR(VkCommandBuffer commandBuffer,
                                                const VkVideoCodingControlInfoKHR* pCodingControlInfo) {
    tracker_.TrackPreCmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdControlVideoCodingKHR(VkCommandBuffer commandBuffer,
                                                 const VkVideoCodingControlInfoKHR* pCodingControlInfo) {
    tracker_.TrackPostCmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo) {
    tracker_.TrackPreCmdDecodeVideoKHR(commandBuffer, pDecodeInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo) {
    tracker_.TrackPostCmdDecodeVideoKHR(commandBuffer, pDecodeInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBeginRenderingKHR(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) {
    tracker_.TrackPreCmdBeginRenderingKHR(commandBuffer, pRenderingInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBeginRenderingKHR(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) {
    tracker_.TrackPostCmdBeginRenderingKHR(commandBuffer, pRenderingInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdEndRenderingKHR(VkCommandBuffer commandBuffer) {
    tracker_.TrackPreCmdEndRenderingKHR(commandBuffer);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdEndRenderingKHR(VkCommandBuffer commandBuffer) {
    tracker_.TrackPostCmdEndRenderingKHR(commandBuffer);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    tracker_.TrackPreCmdSetDeviceMaskKHR(commandBuffer, deviceMask);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    tracker_.TrackPostCmdSetDeviceMaskKHR(commandBuffer, deviceMask);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                          uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                          uint32_t groupCountZ) {
    tracker_.TrackPreCmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY,
                                        groupCountZ);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                           uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                           uint32_t groupCountZ) {
    tracker_.TrackPostCmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY,
                                         groupCountZ);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                               VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount,
                                               const VkWriteDescriptorSet* pDescriptorWrites) {
    tracker_.TrackPreCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount,
                                             pDescriptorWrites);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount,
                                                const VkWriteDescriptorSet* pDescriptorWrites) {
    tracker_.TrackPostCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount,
                                              pDescriptorWrites);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer,
                                                           VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                           VkPipelineLayout layout, uint32_t set, const void* pData) {
    tracker_.TrackPreCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer,
                                                            VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                            VkPipelineLayout layout, uint32_t set, const void* pData) {
    tracker_.TrackPostCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer,
                                              const VkRenderPassBeginInfo* pRenderPassBegin,
                                              const VkSubpassBeginInfo* pSubpassBeginInfo) {
    tracker_.TrackPreCmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer,
                                               const VkRenderPassBeginInfo* pRenderPassBegin,
                                               const VkSubpassBeginInfo* pSubpassBeginInfo) {
    tracker_.TrackPostCmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                                          const VkSubpassEndInfo* pSubpassEndInfo) {
    tracker_.TrackPreCmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                                           const VkSubpassEndInfo* pSubpassEndInfo) {
    tracker_.TrackPostCmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {
    tracker_.TrackPreCmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {
    tracker_.TrackPostCmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                               VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                               uint32_t maxDrawCount, uint32_t stride) {
    tracker_.TrackPreCmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                             maxDrawCount, stride);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                uint32_t maxDrawCount, uint32_t stride) {
    tracker_.TrackPostCmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                              maxDrawCount, stride);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                      VkDeviceSize offset, VkBuffer countBuffer,
                                                      VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                      uint32_t stride) {
    tracker_.TrackPreCmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                                    maxDrawCount, stride);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                       VkDeviceSize offset, VkBuffer countBuffer,
                                                       VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                       uint32_t stride) {
    tracker_.TrackPostCmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                                     maxDrawCount, stride);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize,
                                                    const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    tracker_.TrackPreCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize,
                                                     const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    tracker_.TrackPostCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetRenderingAttachmentLocationsKHR(
    VkCommandBuffer commandBuffer, const VkRenderingAttachmentLocationInfoKHR* pLocationInfo) {
    tracker_.TrackPreCmdSetRenderingAttachmentLocationsKHR(commandBuffer, pLocationInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetRenderingAttachmentLocationsKHR(
    VkCommandBuffer commandBuffer, const VkRenderingAttachmentLocationInfoKHR* pLocationInfo) {
    tracker_.TrackPostCmdSetRenderingAttachmentLocationsKHR(commandBuffer, pLocationInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetRenderingInputAttachmentIndicesKHR(
    VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfoKHR* pLocationInfo) {
    tracker_.TrackPreCmdSetRenderingInputAttachmentIndicesKHR(commandBuffer, pLocationInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetRenderingInputAttachmentIndicesKHR(
    VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfoKHR* pLocationInfo) {
    tracker_.TrackPostCmdSetRenderingInputAttachmentIndicesKHR(commandBuffer, pLocationInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo) {
    tracker_.TrackPreCmdEncodeVideoKHR(commandBuffer, pEncodeInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo) {
    tracker_.TrackPostCmdEncodeVideoKHR(commandBuffer, pEncodeInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event,
                                       const VkDependencyInfo* pDependencyInfo) {
    tracker_.TrackPreCmdSetEvent2KHR(commandBuffer, event, pDependencyInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event,
                                        const VkDependencyInfo* pDependencyInfo) {
    tracker_.TrackPostCmdSetEvent2KHR(commandBuffer, event, pDependencyInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event,
                                         VkPipelineStageFlags2 stageMask) {
    tracker_.TrackPreCmdResetEvent2KHR(commandBuffer, event, stageMask);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event,
                                          VkPipelineStageFlags2 stageMask) {
    tracker_.TrackPostCmdResetEvent2KHR(commandBuffer, event, stageMask);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                         const VkDependencyInfo* pDependencyInfos) {
    tracker_.TrackPreCmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                          const VkDependencyInfo* pDependencyInfos) {
    tracker_.TrackPostCmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {
    tracker_.TrackPreCmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {
    tracker_.TrackPostCmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                             VkQueryPool queryPool, uint32_t query) {
    tracker_.TrackPreCmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                              VkQueryPool queryPool, uint32_t query) {
    tracker_.TrackPostCmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                                VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {
    tracker_.TrackPreCmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                                 VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {
    tracker_.TrackPostCmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {
    tracker_.TrackPreCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {
    tracker_.TrackPostCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {
    tracker_.TrackPreCmdCopyImage2KHR(commandBuffer, pCopyImageInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {
    tracker_.TrackPostCmdCopyImage2KHR(commandBuffer, pCopyImageInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer,
                                                const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    tracker_.TrackPreCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer,
                                                 const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    tracker_.TrackPostCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer,
                                                const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    tracker_.TrackPreCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer,
                                                 const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    tracker_.TrackPostCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {
    tracker_.TrackPreCmdBlitImage2KHR(commandBuffer, pBlitImageInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {
    tracker_.TrackPostCmdBlitImage2KHR(commandBuffer, pBlitImageInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdResolveImage2KHR(VkCommandBuffer commandBuffer,
                                           const VkResolveImageInfo2* pResolveImageInfo) {
    tracker_.TrackPreCmdResolveImage2KHR(commandBuffer, pResolveImageInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdResolveImage2KHR(VkCommandBuffer commandBuffer,
                                            const VkResolveImageInfo2* pResolveImageInfo) {
    tracker_.TrackPostCmdResolveImage2KHR(commandBuffer, pResolveImageInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress) {
    tracker_.TrackPreCmdTraceRaysIndirect2KHR(commandBuffer, indirectDeviceAddress);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress) {
    tracker_.TrackPostCmdTraceRaysIndirect2KHR(commandBuffer, indirectDeviceAddress);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                              VkDeviceSize size, VkIndexType indexType) {
    tracker_.TrackPreCmdBindIndexBuffer2KHR(commandBuffer, buffer, offset, size, indexType);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                               VkDeviceSize size, VkIndexType indexType) {
    tracker_.TrackPostCmdBindIndexBuffer2KHR(commandBuffer, buffer, offset, size, indexType);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                            uint16_t lineStipplePattern) {
    tracker_.TrackPreCmdSetLineStippleKHR(commandBuffer, lineStippleFactor, lineStipplePattern);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                             uint16_t lineStipplePattern) {
    tracker_.TrackPostCmdSetLineStippleKHR(commandBuffer, lineStippleFactor, lineStipplePattern);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindDescriptorSets2KHR(VkCommandBuffer commandBuffer,
                                                 const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo) {
    tracker_.TrackPreCmdBindDescriptorSets2KHR(commandBuffer, pBindDescriptorSetsInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindDescriptorSets2KHR(VkCommandBuffer commandBuffer,
                                                  const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo) {
    tracker_.TrackPostCmdBindDescriptorSets2KHR(commandBuffer, pBindDescriptorSetsInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdPushConstants2KHR(VkCommandBuffer commandBuffer,
                                            const VkPushConstantsInfoKHR* pPushConstantsInfo) {
    tracker_.TrackPreCmdPushConstants2KHR(commandBuffer, pPushConstantsInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdPushConstants2KHR(VkCommandBuffer commandBuffer,
                                             const VkPushConstantsInfoKHR* pPushConstantsInfo) {
    tracker_.TrackPostCmdPushConstants2KHR(commandBuffer, pPushConstantsInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdPushDescriptorSet2KHR(VkCommandBuffer commandBuffer,
                                                const VkPushDescriptorSetInfoKHR* pPushDescriptorSetInfo) {
    tracker_.TrackPreCmdPushDescriptorSet2KHR(commandBuffer, pPushDescriptorSetInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdPushDescriptorSet2KHR(VkCommandBuffer commandBuffer,
                                                 const VkPushDescriptorSetInfoKHR* pPushDescriptorSetInfo) {
    tracker_.TrackPostCmdPushDescriptorSet2KHR(commandBuffer, pPushDescriptorSetInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdPushDescriptorSetWithTemplate2KHR(
    VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo) {
    tracker_.TrackPreCmdPushDescriptorSetWithTemplate2KHR(commandBuffer, pPushDescriptorSetWithTemplateInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdPushDescriptorSetWithTemplate2KHR(
    VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo) {
    tracker_.TrackPostCmdPushDescriptorSetWithTemplate2KHR(commandBuffer, pPushDescriptorSetWithTemplateInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDescriptorBufferOffsets2EXT(
    VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo) {
    tracker_.TrackPreCmdSetDescriptorBufferOffsets2EXT(commandBuffer, pSetDescriptorBufferOffsetsInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDescriptorBufferOffsets2EXT(
    VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo) {
    tracker_.TrackPostCmdSetDescriptorBufferOffsets2EXT(commandBuffer, pSetDescriptorBufferOffsetsInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    VkCommandBuffer commandBuffer,
    const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo) {
    tracker_.TrackPreCmdBindDescriptorBufferEmbeddedSamplers2EXT(commandBuffer,
                                                                 pBindDescriptorBufferEmbeddedSamplersInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    VkCommandBuffer commandBuffer,
    const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo) {
    tracker_.TrackPostCmdBindDescriptorBufferEmbeddedSamplers2EXT(commandBuffer,
                                                                  pBindDescriptorBufferEmbeddedSamplersInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer,
                                              const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
    tracker_.TrackPreCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
    WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer,
                                               const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
    tracker_.TrackPostCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
    WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) {
    tracker_.TrackPreCmdDebugMarkerEndEXT(commandBuffer);
    WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) {
    tracker_.TrackPostCmdDebugMarkerEndEXT(commandBuffer);
    WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer,
                                               const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
    tracker_.TrackPreCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
    WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer,
                                                const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
    tracker_.TrackPostCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
    WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                          uint32_t bindingCount, const VkBuffer* pBuffers,
                                                          const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes) {
    tracker_.TrackPreCmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets,
                                                        pSizes);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                           uint32_t bindingCount, const VkBuffer* pBuffers,
                                                           const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes) {
    tracker_.TrackPostCmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets,
                                                         pSizes);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                                    uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                                    const VkDeviceSize* pCounterBufferOffsets) {
    tracker_.TrackPreCmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount,
                                                  pCounterBuffers, pCounterBufferOffsets);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                                     uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                                     const VkDeviceSize* pCounterBufferOffsets) {
    tracker_.TrackPostCmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount,
                                                   pCounterBuffers, pCounterBufferOffsets);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                                  uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                                  const VkDeviceSize* pCounterBufferOffsets) {
    tracker_.TrackPreCmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers,
                                                pCounterBufferOffsets);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                                   uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                                   const VkDeviceSize* pCounterBufferOffsets) {
    tracker_.TrackPostCmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers,
                                                 pCounterBufferOffsets);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                               VkQueryControlFlags flags, uint32_t index) {
    tracker_.TrackPreCmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                                VkQueryControlFlags flags, uint32_t index) {
    tracker_.TrackPostCmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                             uint32_t index) {
    tracker_.TrackPreCmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                              uint32_t index) {
    tracker_.TrackPostCmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount,
                                                   uint32_t firstInstance, VkBuffer counterBuffer,
                                                   VkDeviceSize counterBufferOffset, uint32_t counterOffset,
                                                   uint32_t vertexStride) {
    tracker_.TrackPreCmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer,
                                                 counterBufferOffset, counterOffset, vertexStride);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount,
                                                    uint32_t firstInstance, VkBuffer counterBuffer,
                                                    VkDeviceSize counterBufferOffset, uint32_t counterOffset,
                                                    uint32_t vertexStride) {
    tracker_.TrackPostCmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer,
                                                  counterBufferOffset, counterOffset, vertexStride);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo) {
    tracker_.TrackPreCmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo) {
    tracker_.TrackPostCmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                               VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                               uint32_t maxDrawCount, uint32_t stride) {
    tracker_.TrackPreCmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                             maxDrawCount, stride);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                uint32_t maxDrawCount, uint32_t stride) {
    tracker_.TrackPostCmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                              maxDrawCount, stride);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                      VkDeviceSize offset, VkBuffer countBuffer,
                                                      VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                      uint32_t stride) {
    tracker_.TrackPreCmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                                    maxDrawCount, stride);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                       VkDeviceSize offset, VkBuffer countBuffer,
                                                       VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                       uint32_t stride) {
    tracker_.TrackPostCmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                                     maxDrawCount, stride);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBeginConditionalRenderingEXT(
    VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) {
    tracker_.TrackPreCmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBeginConditionalRenderingEXT(
    VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) {
    tracker_.TrackPostCmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer) {
    tracker_.TrackPreCmdEndConditionalRenderingEXT(commandBuffer);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer) {
    tracker_.TrackPostCmdEndConditionalRenderingEXT(commandBuffer);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                                uint32_t viewportCount,
                                                const VkViewportWScalingNV* pViewportWScalings) {
    tracker_.TrackPreCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                                 uint32_t viewportCount,
                                                 const VkViewportWScalingNV* pViewportWScalings) {
    tracker_.TrackPostCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle,
                                                 uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) {
    tracker_.TrackPreCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount,
                                               pDiscardRectangles);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle,
                                                  uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) {
    tracker_.TrackPostCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount,
                                                pDiscardRectangles);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable) {
    tracker_.TrackPreCmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer,
                                                        VkBool32 discardRectangleEnable) {
    tracker_.TrackPostCmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer,
                                                     VkDiscardRectangleModeEXT discardRectangleMode) {
    tracker_.TrackPreCmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer,
                                                      VkDiscardRectangleModeEXT discardRectangleMode) {
    tracker_.TrackPostCmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer,
                                                  const VkDebugUtilsLabelEXT* pLabelInfo) {
    tracker_.TrackPreCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer,
                                                   const VkDebugUtilsLabelEXT* pLabelInfo) {
    tracker_.TrackPostCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) {
    tracker_.TrackPreCmdEndDebugUtilsLabelEXT(commandBuffer);
    WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) {
    tracker_.TrackPostCmdEndDebugUtilsLabelEXT(commandBuffer);
    WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer,
                                                   const VkDebugUtilsLabelEXT* pLabelInfo) {
    tracker_.TrackPreCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer,
                                                    const VkDebugUtilsLabelEXT* pLabelInfo) {
    tracker_.TrackPostCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

#ifdef VK_ENABLE_BETA_EXTENSIONS
void CommandBuffer::PreCmdInitializeGraphScratchMemoryAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch) {
    tracker_.TrackPreCmdInitializeGraphScratchMemoryAMDX(commandBuffer, scratch);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdInitializeGraphScratchMemoryAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch) {
    tracker_.TrackPostCmdInitializeGraphScratchMemoryAMDX(commandBuffer, scratch);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void CommandBuffer::PreCmdDispatchGraphAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                            const VkDispatchGraphCountInfoAMDX* pCountInfo) {
    tracker_.TrackPreCmdDispatchGraphAMDX(commandBuffer, scratch, pCountInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDispatchGraphAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                             const VkDispatchGraphCountInfoAMDX* pCountInfo) {
    tracker_.TrackPostCmdDispatchGraphAMDX(commandBuffer, scratch, pCountInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void CommandBuffer::PreCmdDispatchGraphIndirectAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                                    const VkDispatchGraphCountInfoAMDX* pCountInfo) {
    tracker_.TrackPreCmdDispatchGraphIndirectAMDX(commandBuffer, scratch, pCountInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDispatchGraphIndirectAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                                     const VkDispatchGraphCountInfoAMDX* pCountInfo) {
    tracker_.TrackPostCmdDispatchGraphIndirectAMDX(commandBuffer, scratch, pCountInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void CommandBuffer::PreCmdDispatchGraphIndirectCountAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                                         VkDeviceAddress countInfo) {
    tracker_.TrackPreCmdDispatchGraphIndirectCountAMDX(commandBuffer, scratch, countInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDispatchGraphIndirectCountAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                                          VkDeviceAddress countInfo) {
    tracker_.TrackPostCmdDispatchGraphIndirectCountAMDX(commandBuffer, scratch, countInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

void CommandBuffer::PreCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer,
                                                const VkSampleLocationsInfoEXT* pSampleLocationsInfo) {
    tracker_.TrackPreCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer,
                                                 const VkSampleLocationsInfoEXT* pSampleLocationsInfo) {
    tracker_.TrackPostCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView,
                                                 VkImageLayout imageLayout) {
    tracker_.TrackPreCmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView,
                                                  VkImageLayout imageLayout) {
    tracker_.TrackPostCmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                                          uint32_t viewportCount,
                                                          const VkShadingRatePaletteNV* pShadingRatePalettes) {
    tracker_.TrackPreCmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount,
                                                        pShadingRatePalettes);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                                           uint32_t viewportCount,
                                                           const VkShadingRatePaletteNV* pShadingRatePalettes) {
    tracker_.TrackPostCmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount,
                                                         pShadingRatePalettes);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer,
                                                 VkCoarseSampleOrderTypeNV sampleOrderType,
                                                 uint32_t customSampleOrderCount,
                                                 const VkCoarseSampleOrderCustomNV* pCustomSampleOrders) {
    tracker_.TrackPreCmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount,
                                               pCustomSampleOrders);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer,
                                                  VkCoarseSampleOrderTypeNV sampleOrderType,
                                                  uint32_t customSampleOrderCount,
                                                  const VkCoarseSampleOrderCustomNV* pCustomSampleOrders) {
    tracker_.TrackPostCmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount,
                                                pCustomSampleOrders);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer,
                                                       const VkAccelerationStructureInfoNV* pInfo,
                                                       VkBuffer instanceData, VkDeviceSize instanceOffset,
                                                       VkBool32 update, VkAccelerationStructureNV dst,
                                                       VkAccelerationStructureNV src, VkBuffer scratch,
                                                       VkDeviceSize scratchOffset) {
    tracker_.TrackPreCmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset, update, dst,
                                                     src, scratch, scratchOffset);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer,
                                                        const VkAccelerationStructureInfoNV* pInfo,
                                                        VkBuffer instanceData, VkDeviceSize instanceOffset,
                                                        VkBool32 update, VkAccelerationStructureNV dst,
                                                        VkAccelerationStructureNV src, VkBuffer scratch,
                                                        VkDeviceSize scratchOffset) {
    tracker_.TrackPostCmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset, update, dst,
                                                      src, scratch, scratchOffset);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst,
                                                      VkAccelerationStructureNV src,
                                                      VkCopyAccelerationStructureModeKHR mode) {
    tracker_.TrackPreCmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst,
                                                       VkAccelerationStructureNV src,
                                                       VkCopyAccelerationStructureModeKHR mode) {
    tracker_.TrackPostCmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer,
                                      VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer,
                                      VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride,
                                      VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset,
                                      VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer,
                                      VkDeviceSize callableShaderBindingOffset,
                                      VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height,
                                      uint32_t depth) {
    tracker_.TrackPreCmdTraceRaysNV(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset,
                                    missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride,
                                    hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride,
                                    callableShaderBindingTableBuffer, callableShaderBindingOffset,
                                    callableShaderBindingStride, width, height, depth);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer,
                                       VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer,
                                       VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride,
                                       VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset,
                                       VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer,
                                       VkDeviceSize callableShaderBindingOffset,
                                       VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height,
                                       uint32_t depth) {
    tracker_.TrackPostCmdTraceRaysNV(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset,
                                     missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride,
                                     hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride,
                                     callableShaderBindingTableBuffer, callableShaderBindingOffset,
                                     callableShaderBindingStride, width, height, depth);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdWriteAccelerationStructuresPropertiesNV(
    VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
    const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool,
    uint32_t firstQuery) {
    tracker_.TrackPreCmdWriteAccelerationStructuresPropertiesNV(
        commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdWriteAccelerationStructuresPropertiesNV(
    VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
    const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool,
    uint32_t firstQuery) {
    tracker_.TrackPostCmdWriteAccelerationStructuresPropertiesNV(
        commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                               VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {
    tracker_.TrackPreCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                                VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {
    tracker_.TrackPostCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask) {
    tracker_.TrackPreCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask) {
    tracker_.TrackPostCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                  uint32_t drawCount, uint32_t stride) {
    tracker_.TrackPreCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                   uint32_t drawCount, uint32_t stride) {
    tracker_.TrackPostCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                       VkDeviceSize offset, VkBuffer countBuffer,
                                                       VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                       uint32_t stride) {
    tracker_.TrackPreCmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                                     maxDrawCount, stride);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                        VkDeviceSize offset, VkBuffer countBuffer,
                                                        VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                        uint32_t stride) {
    tracker_.TrackPostCmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                                      maxDrawCount, stride);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                                      uint32_t exclusiveScissorCount,
                                                      const VkBool32* pExclusiveScissorEnables) {
    tracker_.TrackPreCmdSetExclusiveScissorEnableNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount,
                                                    pExclusiveScissorEnables);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                                       uint32_t exclusiveScissorCount,
                                                       const VkBool32* pExclusiveScissorEnables) {
    tracker_.TrackPostCmdSetExclusiveScissorEnableNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount,
                                                     pExclusiveScissorEnables);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                                uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors) {
    tracker_.TrackPreCmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount,
                                              pExclusiveScissors);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                                 uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors) {
    tracker_.TrackPostCmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount,
                                               pExclusiveScissors);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker) {
    tracker_.TrackPreCmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker) {
    tracker_.TrackPostCmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

VkResult CommandBuffer::PreCmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer,
                                                        const VkPerformanceMarkerInfoINTEL* pMarkerInfo) {
    tracker_.TrackPreCmdSetPerformanceMarkerINTEL(commandBuffer, pMarkerInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
    return VK_SUCCESS;
}
VkResult CommandBuffer::PostCmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer,
                                                         const VkPerformanceMarkerInfoINTEL* pMarkerInfo,
                                                         VkResult result) {
    tracker_.TrackPostCmdSetPerformanceMarkerINTEL(commandBuffer, pMarkerInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
    return result;
}

VkResult CommandBuffer::PreCmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer,
                                                              const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo) {
    tracker_.TrackPreCmdSetPerformanceStreamMarkerINTEL(commandBuffer, pMarkerInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
    return VK_SUCCESS;
}
VkResult CommandBuffer::PostCmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer,
                                                               const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo,
                                                               VkResult result) {
    tracker_.TrackPostCmdSetPerformanceStreamMarkerINTEL(commandBuffer, pMarkerInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
    return result;
}

VkResult CommandBuffer::PreCmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer,
                                                          const VkPerformanceOverrideInfoINTEL* pOverrideInfo) {
    tracker_.TrackPreCmdSetPerformanceOverrideINTEL(commandBuffer, pOverrideInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
    return VK_SUCCESS;
}
VkResult CommandBuffer::PostCmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer,
                                                           const VkPerformanceOverrideInfoINTEL* pOverrideInfo,
                                                           VkResult result) {
    tracker_.TrackPostCmdSetPerformanceOverrideINTEL(commandBuffer, pOverrideInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
    return result;
}

void CommandBuffer::PreCmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                            uint16_t lineStipplePattern) {
    tracker_.TrackPreCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                             uint16_t lineStipplePattern) {
    tracker_.TrackPostCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    tracker_.TrackPreCmdSetCullModeEXT(commandBuffer, cullMode);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    tracker_.TrackPostCmdSetCullModeEXT(commandBuffer, cullMode);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    tracker_.TrackPreCmdSetFrontFaceEXT(commandBuffer, frontFace);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    tracker_.TrackPostCmdSetFrontFaceEXT(commandBuffer, frontFace);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer,
                                                  VkPrimitiveTopology primitiveTopology) {
    tracker_.TrackPreCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer,
                                                   VkPrimitiveTopology primitiveTopology) {
    tracker_.TrackPostCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                                  const VkViewport* pViewports) {
    tracker_.TrackPreCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                                   const VkViewport* pViewports) {
    tracker_.TrackPostCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                                 const VkRect2D* pScissors) {
    tracker_.TrackPreCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                                  const VkRect2D* pScissors) {
    tracker_.TrackPostCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                uint32_t bindingCount, const VkBuffer* pBuffers,
                                                const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                                                const VkDeviceSize* pStrides) {
    tracker_.TrackPreCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes,
                                              pStrides);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                 uint32_t bindingCount, const VkBuffer* pBuffers,
                                                 const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                                                 const VkDeviceSize* pStrides) {
    tracker_.TrackPostCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes,
                                               pStrides);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    tracker_.TrackPreCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    tracker_.TrackPostCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    tracker_.TrackPreCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    tracker_.TrackPostCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    tracker_.TrackPreCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    tracker_.TrackPostCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
    tracker_.TrackPreCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
    tracker_.TrackPostCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    tracker_.TrackPreCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    tracker_.TrackPostCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                          VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp,
                                          VkCompareOp compareOp) {
    tracker_.TrackPreCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                           VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp,
                                           VkCompareOp compareOp) {
    tracker_.TrackPostCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer,
                                                        const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
    tracker_.TrackPreCmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer,
                                                         const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
    tracker_.TrackPostCmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                                     const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
    tracker_.TrackPreCmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                                      const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
    tracker_.TrackPostCmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer,
                                                    VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline,
                                                    uint32_t groupIndex) {
    tracker_.TrackPreCmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer,
                                                     VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline,
                                                     uint32_t groupIndex) {
    tracker_.TrackPostCmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthBias2EXT(VkCommandBuffer commandBuffer, const VkDepthBiasInfoEXT* pDepthBiasInfo) {
    tracker_.TrackPreCmdSetDepthBias2EXT(commandBuffer, pDepthBiasInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthBias2EXT(VkCommandBuffer commandBuffer, const VkDepthBiasInfoEXT* pDepthBiasInfo) {
    tracker_.TrackPostCmdSetDepthBias2EXT(commandBuffer, pDepthBiasInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCudaLaunchKernelNV(VkCommandBuffer commandBuffer, const VkCudaLaunchInfoNV* pLaunchInfo) {
    tracker_.TrackPreCmdCudaLaunchKernelNV(commandBuffer, pLaunchInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCudaLaunchKernelNV(VkCommandBuffer commandBuffer, const VkCudaLaunchInfoNV* pLaunchInfo) {
    tracker_.TrackPostCmdCudaLaunchKernelNV(commandBuffer, pLaunchInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount,
                                                   const VkDescriptorBufferBindingInfoEXT* pBindingInfos) {
    tracker_.TrackPreCmdBindDescriptorBuffersEXT(commandBuffer, bufferCount, pBindingInfos);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount,
                                                    const VkDescriptorBufferBindingInfoEXT* pBindingInfos) {
    tracker_.TrackPostCmdBindDescriptorBuffersEXT(commandBuffer, bufferCount, pBindingInfos);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer commandBuffer,
                                                        VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout,
                                                        uint32_t firstSet, uint32_t setCount,
                                                        const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets) {
    tracker_.TrackPreCmdSetDescriptorBufferOffsetsEXT(commandBuffer, pipelineBindPoint, layout, firstSet, setCount,
                                                      pBufferIndices, pOffsets);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer commandBuffer,
                                                         VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout,
                                                         uint32_t firstSet, uint32_t setCount,
                                                         const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets) {
    tracker_.TrackPostCmdSetDescriptorBufferOffsetsEXT(commandBuffer, pipelineBindPoint, layout, firstSet, setCount,
                                                       pBufferIndices, pOffsets);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer commandBuffer,
                                                                  VkPipelineBindPoint pipelineBindPoint,
                                                                  VkPipelineLayout layout, uint32_t set) {
    tracker_.TrackPreCmdBindDescriptorBufferEmbeddedSamplersEXT(commandBuffer, pipelineBindPoint, layout, set);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer commandBuffer,
                                                                   VkPipelineBindPoint pipelineBindPoint,
                                                                   VkPipelineLayout layout, uint32_t set) {
    tracker_.TrackPostCmdBindDescriptorBufferEmbeddedSamplersEXT(commandBuffer, pipelineBindPoint, layout, set);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetFragmentShadingRateEnumNV(VkCommandBuffer commandBuffer,
                                                       VkFragmentShadingRateNV shadingRate,
                                                       const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    tracker_.TrackPreCmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetFragmentShadingRateEnumNV(VkCommandBuffer commandBuffer,
                                                        VkFragmentShadingRateNV shadingRate,
                                                        const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    tracker_.TrackPostCmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
                                            const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions,
                                            uint32_t vertexAttributeDescriptionCount,
                                            const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) {
    tracker_.TrackPreCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions,
                                          vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetVertexInputEXT(
    VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
    const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount,
    const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) {
    tracker_.TrackPostCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions,
                                           vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer) {
    tracker_.TrackPreCmdSubpassShadingHUAWEI(commandBuffer);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer) {
    tracker_.TrackPostCmdSubpassShadingHUAWEI(commandBuffer);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer, VkImageView imageView,
                                                   VkImageLayout imageLayout) {
    tracker_.TrackPreCmdBindInvocationMaskHUAWEI(commandBuffer, imageView, imageLayout);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer, VkImageView imageView,
                                                    VkImageLayout imageLayout) {
    tracker_.TrackPostCmdBindInvocationMaskHUAWEI(commandBuffer, imageView, imageLayout);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints) {
    tracker_.TrackPreCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints) {
    tracker_.TrackPostCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer,
                                                        VkBool32 rasterizerDiscardEnable) {
    tracker_.TrackPreCmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer,
                                                         VkBool32 rasterizerDiscardEnable) {
    tracker_.TrackPostCmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
    tracker_.TrackPreCmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
    tracker_.TrackPostCmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp) {
    tracker_.TrackPreCmdSetLogicOpEXT(commandBuffer, logicOp);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp) {
    tracker_.TrackPostCmdSetLogicOpEXT(commandBuffer, logicOp);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {
    tracker_.TrackPreCmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer,
                                                        VkBool32 primitiveRestartEnable) {
    tracker_.TrackPostCmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                                 const VkBool32* pColorWriteEnables) {
    tracker_.TrackPreCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                                  const VkBool32* pColorWriteEnables) {
    tracker_.TrackPostCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                       const VkMultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount,
                                       uint32_t firstInstance, uint32_t stride) {
    tracker_.TrackPreCmdDrawMultiEXT(commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                        const VkMultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount,
                                        uint32_t firstInstance, uint32_t stride) {
    tracker_.TrackPostCmdDrawMultiEXT(commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                              const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount,
                                              uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset) {
    tracker_.TrackPreCmdDrawMultiIndexedEXT(commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride,
                                            pVertexOffset);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                               const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount,
                                               uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset) {
    tracker_.TrackPostCmdDrawMultiIndexedEXT(commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride,
                                             pVertexOffset);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBuildMicromapsEXT(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                            const VkMicromapBuildInfoEXT* pInfos) {
    tracker_.TrackPreCmdBuildMicromapsEXT(commandBuffer, infoCount, pInfos);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBuildMicromapsEXT(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                             const VkMicromapBuildInfoEXT* pInfos) {
    tracker_.TrackPostCmdBuildMicromapsEXT(commandBuffer, infoCount, pInfos);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo) {
    tracker_.TrackPreCmdCopyMicromapEXT(commandBuffer, pInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo) {
    tracker_.TrackPostCmdCopyMicromapEXT(commandBuffer, pInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer,
                                                  const VkCopyMicromapToMemoryInfoEXT* pInfo) {
    tracker_.TrackPreCmdCopyMicromapToMemoryEXT(commandBuffer, pInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer,
                                                   const VkCopyMicromapToMemoryInfoEXT* pInfo) {
    tracker_.TrackPostCmdCopyMicromapToMemoryEXT(commandBuffer, pInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer,
                                                  const VkCopyMemoryToMicromapInfoEXT* pInfo) {
    tracker_.TrackPreCmdCopyMemoryToMicromapEXT(commandBuffer, pInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer,
                                                   const VkCopyMemoryToMicromapInfoEXT* pInfo) {
    tracker_.TrackPostCmdCopyMemoryToMicromapEXT(commandBuffer, pInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount,
                                                      const VkMicromapEXT* pMicromaps, VkQueryType queryType,
                                                      VkQueryPool queryPool, uint32_t firstQuery) {
    tracker_.TrackPreCmdWriteMicromapsPropertiesEXT(commandBuffer, micromapCount, pMicromaps, queryType, queryPool,
                                                    firstQuery);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount,
                                                       const VkMicromapEXT* pMicromaps, VkQueryType queryType,
                                                       VkQueryPool queryPool, uint32_t firstQuery) {
    tracker_.TrackPostCmdWriteMicromapsPropertiesEXT(commandBuffer, micromapCount, pMicromaps, queryType, queryPool,
                                                     firstQuery);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                            uint32_t groupCountZ) {
    tracker_.TrackPreCmdDrawClusterHUAWEI(commandBuffer, groupCountX, groupCountY, groupCountZ);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                             uint32_t groupCountZ) {
    tracker_.TrackPostCmdDrawClusterHUAWEI(commandBuffer, groupCountX, groupCountY, groupCountZ);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                    VkDeviceSize offset) {
    tracker_.TrackPreCmdDrawClusterIndirectHUAWEI(commandBuffer, buffer, offset);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                     VkDeviceSize offset) {
    tracker_.TrackPostCmdDrawClusterIndirectHUAWEI(commandBuffer, buffer, offset);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                               uint32_t copyCount, uint32_t stride) {
    tracker_.TrackPreCmdCopyMemoryIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                                uint32_t copyCount, uint32_t stride) {
    tracker_.TrackPostCmdCopyMemoryIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyMemoryToImageIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                                      uint32_t copyCount, uint32_t stride, VkImage dstImage,
                                                      VkImageLayout dstImageLayout,
                                                      const VkImageSubresourceLayers* pImageSubresources) {
    tracker_.TrackPreCmdCopyMemoryToImageIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride, dstImage,
                                                    dstImageLayout, pImageSubresources);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyMemoryToImageIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                                       uint32_t copyCount, uint32_t stride, VkImage dstImage,
                                                       VkImageLayout dstImageLayout,
                                                       const VkImageSubresourceLayers* pImageSubresources) {
    tracker_.TrackPostCmdCopyMemoryToImageIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride, dstImage,
                                                     dstImageLayout, pImageSubresources);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount,
                                             const VkDecompressMemoryRegionNV* pDecompressMemoryRegions) {
    tracker_.TrackPreCmdDecompressMemoryNV(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount,
                                              const VkDecompressMemoryRegionNV* pDecompressMemoryRegions) {
    tracker_.TrackPostCmdDecompressMemoryNV(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer,
                                                          VkDeviceAddress indirectCommandsAddress,
                                                          VkDeviceAddress indirectCommandsCountAddress,
                                                          uint32_t stride) {
    tracker_.TrackPreCmdDecompressMemoryIndirectCountNV(commandBuffer, indirectCommandsAddress,
                                                        indirectCommandsCountAddress, stride);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer,
                                                           VkDeviceAddress indirectCommandsAddress,
                                                           VkDeviceAddress indirectCommandsCountAddress,
                                                           uint32_t stride) {
    tracker_.TrackPostCmdDecompressMemoryIndirectCountNV(commandBuffer, indirectCommandsAddress,
                                                         indirectCommandsCountAddress, stride);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer,
                                                         VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) {
    tracker_.TrackPreCmdUpdatePipelineIndirectBufferNV(commandBuffer, pipelineBindPoint, pipeline);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer,
                                                          VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) {
    tracker_.TrackPostCmdUpdatePipelineIndirectBufferNV(commandBuffer, pipelineBindPoint, pipeline);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClampEnable) {
    tracker_.TrackPreCmdSetDepthClampEnableEXT(commandBuffer, depthClampEnable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClampEnable) {
    tracker_.TrackPostCmdSetDepthClampEnableEXT(commandBuffer, depthClampEnable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode) {
    tracker_.TrackPreCmdSetPolygonModeEXT(commandBuffer, polygonMode);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode) {
    tracker_.TrackPostCmdSetPolygonModeEXT(commandBuffer, polygonMode);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer,
                                                     VkSampleCountFlagBits rasterizationSamples) {
    tracker_.TrackPreCmdSetRasterizationSamplesEXT(commandBuffer, rasterizationSamples);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer,
                                                      VkSampleCountFlagBits rasterizationSamples) {
    tracker_.TrackPostCmdSetRasterizationSamplesEXT(commandBuffer, rasterizationSamples);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples,
                                           const VkSampleMask* pSampleMask) {
    tracker_.TrackPreCmdSetSampleMaskEXT(commandBuffer, samples, pSampleMask);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples,
                                            const VkSampleMask* pSampleMask) {
    tracker_.TrackPostCmdSetSampleMaskEXT(commandBuffer, samples, pSampleMask);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable) {
    tracker_.TrackPreCmdSetAlphaToCoverageEnableEXT(commandBuffer, alphaToCoverageEnable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable) {
    tracker_.TrackPostCmdSetAlphaToCoverageEnableEXT(commandBuffer, alphaToCoverageEnable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable) {
    tracker_.TrackPreCmdSetAlphaToOneEnableEXT(commandBuffer, alphaToOneEnable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable) {
    tracker_.TrackPostCmdSetAlphaToOneEnableEXT(commandBuffer, alphaToOneEnable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable) {
    tracker_.TrackPreCmdSetLogicOpEnableEXT(commandBuffer, logicOpEnable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable) {
    tracker_.TrackPostCmdSetLogicOpEnableEXT(commandBuffer, logicOpEnable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                                 uint32_t attachmentCount, const VkBool32* pColorBlendEnables) {
    tracker_.TrackPreCmdSetColorBlendEnableEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                                  uint32_t attachmentCount, const VkBool32* pColorBlendEnables) {
    tracker_.TrackPostCmdSetColorBlendEnableEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                                   uint32_t attachmentCount,
                                                   const VkColorBlendEquationEXT* pColorBlendEquations) {
    tracker_.TrackPreCmdSetColorBlendEquationEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                                    uint32_t attachmentCount,
                                                    const VkColorBlendEquationEXT* pColorBlendEquations) {
    tracker_.TrackPostCmdSetColorBlendEquationEXT(commandBuffer, firstAttachment, attachmentCount,
                                                  pColorBlendEquations);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                               uint32_t attachmentCount,
                                               const VkColorComponentFlags* pColorWriteMasks) {
    tracker_.TrackPreCmdSetColorWriteMaskEXT(commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                                uint32_t attachmentCount,
                                                const VkColorComponentFlags* pColorWriteMasks) {
    tracker_.TrackPostCmdSetColorWriteMaskEXT(commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer,
                                                         VkTessellationDomainOrigin domainOrigin) {
    tracker_.TrackPreCmdSetTessellationDomainOriginEXT(commandBuffer, domainOrigin);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer,
                                                          VkTessellationDomainOrigin domainOrigin) {
    tracker_.TrackPostCmdSetTessellationDomainOriginEXT(commandBuffer, domainOrigin);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer, uint32_t rasterizationStream) {
    tracker_.TrackPreCmdSetRasterizationStreamEXT(commandBuffer, rasterizationStream);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer, uint32_t rasterizationStream) {
    tracker_.TrackPostCmdSetRasterizationStreamEXT(commandBuffer, rasterizationStream);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetConservativeRasterizationModeEXT(
    VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode) {
    tracker_.TrackPreCmdSetConservativeRasterizationModeEXT(commandBuffer, conservativeRasterizationMode);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetConservativeRasterizationModeEXT(
    VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode) {
    tracker_.TrackPostCmdSetConservativeRasterizationModeEXT(commandBuffer, conservativeRasterizationMode);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer commandBuffer,
                                                                 float extraPrimitiveOverestimationSize) {
    tracker_.TrackPreCmdSetExtraPrimitiveOverestimationSizeEXT(commandBuffer, extraPrimitiveOverestimationSize);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer commandBuffer,
                                                                  float extraPrimitiveOverestimationSize) {
    tracker_.TrackPostCmdSetExtraPrimitiveOverestimationSizeEXT(commandBuffer, extraPrimitiveOverestimationSize);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClipEnable) {
    tracker_.TrackPreCmdSetDepthClipEnableEXT(commandBuffer, depthClipEnable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClipEnable) {
    tracker_.TrackPostCmdSetDepthClipEnableEXT(commandBuffer, depthClipEnable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable) {
    tracker_.TrackPreCmdSetSampleLocationsEnableEXT(commandBuffer, sampleLocationsEnable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable) {
    tracker_.TrackPostCmdSetSampleLocationsEnableEXT(commandBuffer, sampleLocationsEnable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                                   uint32_t attachmentCount,
                                                   const VkColorBlendAdvancedEXT* pColorBlendAdvanced) {
    tracker_.TrackPreCmdSetColorBlendAdvancedEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                                    uint32_t attachmentCount,
                                                    const VkColorBlendAdvancedEXT* pColorBlendAdvanced) {
    tracker_.TrackPostCmdSetColorBlendAdvancedEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer,
                                                    VkProvokingVertexModeEXT provokingVertexMode) {
    tracker_.TrackPreCmdSetProvokingVertexModeEXT(commandBuffer, provokingVertexMode);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer,
                                                     VkProvokingVertexModeEXT provokingVertexMode) {
    tracker_.TrackPostCmdSetProvokingVertexModeEXT(commandBuffer, provokingVertexMode);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetLineRasterizationModeEXT(VkCommandBuffer commandBuffer,
                                                      VkLineRasterizationModeEXT lineRasterizationMode) {
    tracker_.TrackPreCmdSetLineRasterizationModeEXT(commandBuffer, lineRasterizationMode);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetLineRasterizationModeEXT(VkCommandBuffer commandBuffer,
                                                       VkLineRasterizationModeEXT lineRasterizationMode) {
    tracker_.TrackPostCmdSetLineRasterizationModeEXT(commandBuffer, lineRasterizationMode);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable) {
    tracker_.TrackPreCmdSetLineStippleEnableEXT(commandBuffer, stippledLineEnable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable) {
    tracker_.TrackPostCmdSetLineStippleEnableEXT(commandBuffer, stippledLineEnable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne) {
    tracker_.TrackPreCmdSetDepthClipNegativeOneToOneEXT(commandBuffer, negativeOneToOne);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne) {
    tracker_.TrackPostCmdSetDepthClipNegativeOneToOneEXT(commandBuffer, negativeOneToOne);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable) {
    tracker_.TrackPreCmdSetViewportWScalingEnableNV(commandBuffer, viewportWScalingEnable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable) {
    tracker_.TrackPostCmdSetViewportWScalingEnableNV(commandBuffer, viewportWScalingEnable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                               uint32_t viewportCount, const VkViewportSwizzleNV* pViewportSwizzles) {
    tracker_.TrackPreCmdSetViewportSwizzleNV(commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                                uint32_t viewportCount, const VkViewportSwizzleNV* pViewportSwizzles) {
    tracker_.TrackPostCmdSetViewportSwizzleNV(commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable) {
    tracker_.TrackPreCmdSetCoverageToColorEnableNV(commandBuffer, coverageToColorEnable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable) {
    tracker_.TrackPostCmdSetCoverageToColorEnableNV(commandBuffer, coverageToColorEnable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer,
                                                       uint32_t coverageToColorLocation) {
    tracker_.TrackPreCmdSetCoverageToColorLocationNV(commandBuffer, coverageToColorLocation);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer,
                                                        uint32_t coverageToColorLocation) {
    tracker_.TrackPostCmdSetCoverageToColorLocationNV(commandBuffer, coverageToColorLocation);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetCoverageModulationModeNV(VkCommandBuffer commandBuffer,
                                                      VkCoverageModulationModeNV coverageModulationMode) {
    tracker_.TrackPreCmdSetCoverageModulationModeNV(commandBuffer, coverageModulationMode);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetCoverageModulationModeNV(VkCommandBuffer commandBuffer,
                                                       VkCoverageModulationModeNV coverageModulationMode) {
    tracker_.TrackPostCmdSetCoverageModulationModeNV(commandBuffer, coverageModulationMode);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer,
                                                             VkBool32 coverageModulationTableEnable) {
    tracker_.TrackPreCmdSetCoverageModulationTableEnableNV(commandBuffer, coverageModulationTableEnable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer,
                                                              VkBool32 coverageModulationTableEnable) {
    tracker_.TrackPostCmdSetCoverageModulationTableEnableNV(commandBuffer, coverageModulationTableEnable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer,
                                                       uint32_t coverageModulationTableCount,
                                                       const float* pCoverageModulationTable) {
    tracker_.TrackPreCmdSetCoverageModulationTableNV(commandBuffer, coverageModulationTableCount,
                                                     pCoverageModulationTable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer,
                                                        uint32_t coverageModulationTableCount,
                                                        const float* pCoverageModulationTable) {
    tracker_.TrackPostCmdSetCoverageModulationTableNV(commandBuffer, coverageModulationTableCount,
                                                      pCoverageModulationTable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable) {
    tracker_.TrackPreCmdSetShadingRateImageEnableNV(commandBuffer, shadingRateImageEnable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable) {
    tracker_.TrackPostCmdSetShadingRateImageEnableNV(commandBuffer, shadingRateImageEnable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer commandBuffer,
                                                                VkBool32 representativeFragmentTestEnable) {
    tracker_.TrackPreCmdSetRepresentativeFragmentTestEnableNV(commandBuffer, representativeFragmentTestEnable);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer commandBuffer,
                                                                 VkBool32 representativeFragmentTestEnable) {
    tracker_.TrackPostCmdSetRepresentativeFragmentTestEnableNV(commandBuffer, representativeFragmentTestEnable);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer,
                                                     VkCoverageReductionModeNV coverageReductionMode) {
    tracker_.TrackPreCmdSetCoverageReductionModeNV(commandBuffer, coverageReductionMode);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer,
                                                      VkCoverageReductionModeNV coverageReductionMode) {
    tracker_.TrackPostCmdSetCoverageReductionModeNV(commandBuffer, coverageReductionMode);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session,
                                               const VkOpticalFlowExecuteInfoNV* pExecuteInfo) {
    tracker_.TrackPreCmdOpticalFlowExecuteNV(commandBuffer, session, pExecuteInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session,
                                                const VkOpticalFlowExecuteInfoNV* pExecuteInfo) {
    tracker_.TrackPostCmdOpticalFlowExecuteNV(commandBuffer, session, pExecuteInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount,
                                         const VkShaderStageFlagBits* pStages, const VkShaderEXT* pShaders) {
    tracker_.TrackPreCmdBindShadersEXT(commandBuffer, stageCount, pStages, pShaders);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount,
                                          const VkShaderStageFlagBits* pStages, const VkShaderEXT* pShaders) {
    tracker_.TrackPostCmdBindShadersEXT(commandBuffer, stageCount, pStages, pShaders);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer,
                                                             VkImageAspectFlags aspectMask) {
    tracker_.TrackPreCmdSetAttachmentFeedbackLoopEnableEXT(commandBuffer, aspectMask);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer,
                                                              VkImageAspectFlags aspectMask) {
    tracker_.TrackPostCmdSetAttachmentFeedbackLoopEnableEXT(commandBuffer, aspectMask);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBuildAccelerationStructuresKHR(
    VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) {
    tracker_.TrackPreCmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBuildAccelerationStructuresKHR(
    VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) {
    tracker_.TrackPostCmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBuildAccelerationStructuresIndirectKHR(
    VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkDeviceAddress* pIndirectDeviceAddresses, const uint32_t* pIndirectStrides,
    const uint32_t* const* ppMaxPrimitiveCounts) {
    tracker_.TrackPreCmdBuildAccelerationStructuresIndirectKHR(
        commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBuildAccelerationStructuresIndirectKHR(
    VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkDeviceAddress* pIndirectDeviceAddresses, const uint32_t* pIndirectStrides,
    const uint32_t* const* ppMaxPrimitiveCounts) {
    tracker_.TrackPostCmdBuildAccelerationStructuresIndirectKHR(
        commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                                       const VkCopyAccelerationStructureInfoKHR* pInfo) {
    tracker_.TrackPreCmdCopyAccelerationStructureKHR(commandBuffer, pInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                                        const VkCopyAccelerationStructureInfoKHR* pInfo) {
    tracker_.TrackPostCmdCopyAccelerationStructureKHR(commandBuffer, pInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyAccelerationStructureToMemoryKHR(
    VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) {
    tracker_.TrackPreCmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyAccelerationStructureToMemoryKHR(
    VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) {
    tracker_.TrackPostCmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyMemoryToAccelerationStructureKHR(
    VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) {
    tracker_.TrackPreCmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyMemoryToAccelerationStructureKHR(
    VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) {
    tracker_.TrackPostCmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdWriteAccelerationStructuresPropertiesKHR(
    VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
    const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool,
    uint32_t firstQuery) {
    tracker_.TrackPreCmdWriteAccelerationStructuresPropertiesKHR(
        commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdWriteAccelerationStructuresPropertiesKHR(
    VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
    const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool,
    uint32_t firstQuery) {
    tracker_.TrackPostCmdWriteAccelerationStructuresPropertiesKHR(
        commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdTraceRaysKHR(VkCommandBuffer commandBuffer,
                                       const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                       const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                       const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                       const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                       uint32_t width, uint32_t height, uint32_t depth) {
    tracker_.TrackPreCmdTraceRaysKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable,
                                     pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdTraceRaysKHR(VkCommandBuffer commandBuffer,
                                        const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                        const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                        const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                        const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                        uint32_t width, uint32_t height, uint32_t depth) {
    tracker_.TrackPostCmdTraceRaysKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable,
                                      pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer,
                                               const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                               const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                               const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                               const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                               VkDeviceAddress indirectDeviceAddress) {
    tracker_.TrackPreCmdTraceRaysIndirectKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable,
                                             pHitShaderBindingTable, pCallableShaderBindingTable,
                                             indirectDeviceAddress);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer,
                                                const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                                const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                                const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                                const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                                VkDeviceAddress indirectDeviceAddress) {
    tracker_.TrackPostCmdTraceRaysIndirectKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable,
                                              pHitShaderBindingTable, pCallableShaderBindingTable,
                                              indirectDeviceAddress);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize) {
    tracker_.TrackPreCmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer,
                                                             uint32_t pipelineStackSize) {
    tracker_.TrackPostCmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                           uint32_t groupCountZ) {
    tracker_.TrackPreCmdDrawMeshTasksEXT(commandBuffer, groupCountX, groupCountY, groupCountZ);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                            uint32_t groupCountZ) {
    tracker_.TrackPostCmdDrawMeshTasksEXT(commandBuffer, groupCountX, groupCountY, groupCountZ);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                   uint32_t drawCount, uint32_t stride) {
    tracker_.TrackPreCmdDrawMeshTasksIndirectEXT(commandBuffer, buffer, offset, drawCount, stride);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                    uint32_t drawCount, uint32_t stride) {
    tracker_.TrackPostCmdDrawMeshTasksIndirectEXT(commandBuffer, buffer, offset, drawCount, stride);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                        VkDeviceSize offset, VkBuffer countBuffer,
                                                        VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                        uint32_t stride) {
    tracker_.TrackPreCmdDrawMeshTasksIndirectCountEXT(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                                      maxDrawCount, stride);
    if (instrument_all_commands_) WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                         VkDeviceSize offset, VkBuffer countBuffer,
                                                         VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                         uint32_t stride) {
    tracker_.TrackPostCmdDrawMeshTasksIndirectCountEXT(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                                       maxDrawCount, stride);
    if (instrument_all_commands_) WriteEndCommandExecutionMarker(tracker_.GetCommands().back().id);
}

// NOLINTEND
