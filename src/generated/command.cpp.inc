
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

void CommandBuffer::PreCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                       VkPipeline pipeline) {
    tracker_.CmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
    WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                        VkPipeline pipeline) {
    WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                      const VkViewport* pViewports) {
    tracker_.CmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                       const VkViewport* pViewports) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount,
                                     const VkRect2D* pScissors) {
    tracker_.CmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount,
                                      const VkRect2D* pScissors) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) {
    tracker_.CmdSetLineWidth(commandBuffer, lineWidth);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor,
                                       float depthBiasClamp, float depthBiasSlopeFactor) {
    tracker_.CmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor,
                                        float depthBiasClamp, float depthBiasSlopeFactor) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]) {
    tracker_.CmdSetBlendConstants(commandBuffer, blendConstants);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) {
    tracker_.CmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                                uint32_t compareMask) {
    tracker_.CmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                                 uint32_t compareMask) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                              uint32_t writeMask) {
    tracker_.CmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                               uint32_t writeMask) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                              uint32_t reference) {
    tracker_.CmdSetStencilReference(commandBuffer, faceMask, reference);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                               uint32_t reference) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                             VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount,
                                             const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount,
                                             const uint32_t* pDynamicOffsets) {
    tracker_.CmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount,
                                   pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                              VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount,
                                              const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount,
                                              const uint32_t* pDynamicOffsets) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                          VkIndexType indexType) {
    tracker_.CmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                           VkIndexType indexType) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                            const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) {
    tracker_.CmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                             uint32_t bindingCount, const VkBuffer* pBuffers,
                                             const VkDeviceSize* pOffsets) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount,
                               uint32_t firstVertex, uint32_t firstInstance) {
    tracker_.CmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount,
                                uint32_t firstVertex, uint32_t firstInstance) {
    WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount,
                                      uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) {
    tracker_.CmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount,
                                       uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) {
    WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                       uint32_t drawCount, uint32_t stride) {
    tracker_.CmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
    WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                        uint32_t drawCount, uint32_t stride) {
    WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                              uint32_t drawCount, uint32_t stride) {
    tracker_.CmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
    WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                               uint32_t drawCount, uint32_t stride) {
    WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                   uint32_t groupCountZ) {
    tracker_.CmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
    WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                    uint32_t groupCountZ) {
    WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {
    tracker_.CmdDispatchIndirect(commandBuffer, buffer, offset);
    WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {
    WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer,
                                     uint32_t regionCount, const VkBufferCopy* pRegions) {
    tracker_.CmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
    WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer,
                                      uint32_t regionCount, const VkBufferCopy* pRegions) {
    WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                    VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                    const VkImageCopy* pRegions) {
    tracker_.CmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                     VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                     const VkImageCopy* pRegions) {
    WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                    VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                    const VkImageBlit* pRegions, VkFilter filter) {
    tracker_.CmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions,
                          filter);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                     VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                     const VkImageBlit* pRegions, VkFilter filter) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage,
                                            VkImageLayout dstImageLayout, uint32_t regionCount,
                                            const VkBufferImageCopy* pRegions) {
    tracker_.CmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
    WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage,
                                             VkImageLayout dstImageLayout, uint32_t regionCount,
                                             const VkBufferImageCopy* pRegions) {
    WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage,
                                            VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount,
                                            const VkBufferImageCopy* pRegions) {
    tracker_.CmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
    WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage,
                                             VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount,
                                             const VkBufferImageCopy* pRegions) {
    WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                       VkDeviceSize dataSize, const void* pData) {
    tracker_.CmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                        VkDeviceSize dataSize, const void* pData) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                     VkDeviceSize size, uint32_t data) {
    tracker_.CmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                      VkDeviceSize size, uint32_t data) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                          const VkClearColorValue* pColor, uint32_t rangeCount,
                                          const VkImageSubresourceRange* pRanges) {
    tracker_.CmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                           const VkClearColorValue* pColor, uint32_t rangeCount,
                                           const VkImageSubresourceRange* pRanges) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image,
                                                 VkImageLayout imageLayout,
                                                 const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount,
                                                 const VkImageSubresourceRange* pRanges) {
    tracker_.CmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image,
                                                  VkImageLayout imageLayout,
                                                  const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount,
                                                  const VkImageSubresourceRange* pRanges) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                           const VkClearAttachment* pAttachments, uint32_t rectCount,
                                           const VkClearRect* pRects) {
    tracker_.CmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                            const VkClearAttachment* pAttachments, uint32_t rectCount,
                                            const VkClearRect* pRects) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                       VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                       const VkImageResolve* pRegions) {
    tracker_.CmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                        VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                        const VkImageResolve* pRegions) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
    tracker_.CmdSetEvent(commandBuffer, event, stageMask);
    WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
    WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
    tracker_.CmdResetEvent(commandBuffer, event, stageMask);
    WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
    WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                     VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask,
                                     uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                                     uint32_t bufferMemoryBarrierCount,
                                     const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                     uint32_t imageMemoryBarrierCount,
                                     const VkImageMemoryBarrier* pImageMemoryBarriers) {
    tracker_.CmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount,
                           pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount,
                           pImageMemoryBarriers);
    WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                      VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask,
                                      uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                                      uint32_t bufferMemoryBarrierCount,
                                      const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                      uint32_t imageMemoryBarrierCount,
                                      const VkImageMemoryBarrier* pImageMemoryBarriers) {
    WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask,
                                          VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags,
                                          uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                                          uint32_t bufferMemoryBarrierCount,
                                          const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                          uint32_t imageMemoryBarrierCount,
                                          const VkImageMemoryBarrier* pImageMemoryBarriers) {
    tracker_.CmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount,
                                pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers,
                                imageMemoryBarrierCount, pImageMemoryBarriers);
    WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask,
                                           VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags,
                                           uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                                           uint32_t bufferMemoryBarrierCount,
                                           const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                           uint32_t imageMemoryBarrierCount,
                                           const VkImageMemoryBarrier* pImageMemoryBarriers) {
    WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                     VkQueryControlFlags flags) {
    tracker_.CmdBeginQuery(commandBuffer, queryPool, query, flags);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                      VkQueryControlFlags flags) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) {
    tracker_.CmdEndQuery(commandBuffer, queryPool, query);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                         uint32_t queryCount) {
    tracker_.CmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                          uint32_t queryCount) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                         VkQueryPool queryPool, uint32_t query) {
    tracker_.CmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                          VkQueryPool queryPool, uint32_t query) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool,
                                               uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer,
                                               VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags) {
    tracker_.CmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride,
                                     flags);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool,
                                                uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer,
                                                VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout,
                                        VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size,
                                        const void* pValues) {
    tracker_.CmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout,
                                         VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size,
                                         const void* pValues) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                          VkSubpassContents contents) {
    tracker_.CmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                           VkSubpassContents contents) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) {
    tracker_.CmdNextSubpass(commandBuffer, contents);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdEndRenderPass(VkCommandBuffer commandBuffer) {
    tracker_.CmdEndRenderPass(commandBuffer);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdEndRenderPass(VkCommandBuffer commandBuffer) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount,
                                          const VkCommandBuffer* pCommandBuffers) {
    tracker_.CmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
    WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount,
                                           const VkCommandBuffer* pCommandBuffers) {
    WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    tracker_.CmdSetDeviceMask(commandBuffer, deviceMask);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                       uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                       uint32_t groupCountZ) {
    tracker_.CmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                        uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                        uint32_t groupCountZ) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                            VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                            uint32_t stride) {
    tracker_.CmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                             VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                             uint32_t maxDrawCount, uint32_t stride) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                   VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                   uint32_t maxDrawCount, uint32_t stride) {
    tracker_.CmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount,
                                         stride);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                    VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                    uint32_t maxDrawCount, uint32_t stride) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                           const VkSubpassBeginInfo* pSubpassBeginInfo) {
    tracker_.CmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBeginRenderPass2(VkCommandBuffer commandBuffer,
                                            const VkRenderPassBeginInfo* pRenderPassBegin,
                                            const VkSubpassBeginInfo* pSubpassBeginInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                                       const VkSubpassEndInfo* pSubpassEndInfo) {
    tracker_.CmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                                        const VkSubpassEndInfo* pSubpassEndInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {
    tracker_.CmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event,
                                    const VkDependencyInfo* pDependencyInfo) {
    tracker_.CmdSetEvent2(commandBuffer, event, pDependencyInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event,
                                     const VkDependencyInfo* pDependencyInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) {
    tracker_.CmdResetEvent2(commandBuffer, event, stageMask);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                      const VkDependencyInfo* pDependencyInfos) {
    tracker_.CmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                       const VkDependencyInfo* pDependencyInfos) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {
    tracker_.CmdPipelineBarrier2(commandBuffer, pDependencyInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                          VkQueryPool queryPool, uint32_t query) {
    tracker_.CmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                           VkQueryPool queryPool, uint32_t query) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {
    tracker_.CmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {
    tracker_.CmdCopyImage2(commandBuffer, pCopyImageInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyBufferToImage2(VkCommandBuffer commandBuffer,
                                             const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    tracker_.CmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyBufferToImage2(VkCommandBuffer commandBuffer,
                                              const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyImageToBuffer2(VkCommandBuffer commandBuffer,
                                             const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    tracker_.CmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyImageToBuffer2(VkCommandBuffer commandBuffer,
                                              const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {
    tracker_.CmdBlitImage2(commandBuffer, pBlitImageInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {
    tracker_.CmdResolveImage2(commandBuffer, pResolveImageInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    tracker_.CmdSetCullMode(commandBuffer, cullMode);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    tracker_.CmdSetFrontFace(commandBuffer, frontFace);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {
    tracker_.CmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                               const VkViewport* pViewports) {
    tracker_.CmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                                const VkViewport* pViewports) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                              const VkRect2D* pScissors) {
    tracker_.CmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                               const VkRect2D* pScissors) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                             uint32_t bindingCount, const VkBuffer* pBuffers,
                                             const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                                             const VkDeviceSize* pStrides) {
    tracker_.CmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                              uint32_t bindingCount, const VkBuffer* pBuffers,
                                              const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                                              const VkDeviceSize* pStrides) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    tracker_.CmdSetDepthTestEnable(commandBuffer, depthTestEnable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    tracker_.CmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    tracker_.CmdSetDepthCompareOp(commandBuffer, depthCompareOp);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
    tracker_.CmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    tracker_.CmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                       VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {
    tracker_.CmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                        VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {
    tracker_.CmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
    tracker_.CmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {
    tracker_.CmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer,
                                              const VkVideoBeginCodingInfoKHR* pBeginInfo) {
    tracker_.CmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer,
                                               const VkVideoBeginCodingInfoKHR* pBeginInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdEndVideoCodingKHR(VkCommandBuffer commandBuffer,
                                            const VkVideoEndCodingInfoKHR* pEndCodingInfo) {
    tracker_.CmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdEndVideoCodingKHR(VkCommandBuffer commandBuffer,
                                             const VkVideoEndCodingInfoKHR* pEndCodingInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdControlVideoCodingKHR(VkCommandBuffer commandBuffer,
                                                const VkVideoCodingControlInfoKHR* pCodingControlInfo) {
    tracker_.CmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdControlVideoCodingKHR(VkCommandBuffer commandBuffer,
                                                 const VkVideoCodingControlInfoKHR* pCodingControlInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo) {
    tracker_.CmdDecodeVideoKHR(commandBuffer, pDecodeInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBeginRenderingKHR(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) {
    tracker_.CmdBeginRenderingKHR(commandBuffer, pRenderingInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBeginRenderingKHR(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdEndRenderingKHR(VkCommandBuffer commandBuffer) {
    tracker_.CmdEndRenderingKHR(commandBuffer);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdEndRenderingKHR(VkCommandBuffer commandBuffer) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    tracker_.CmdSetDeviceMaskKHR(commandBuffer, deviceMask);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                          uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                          uint32_t groupCountZ) {
    tracker_.CmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY,
                                groupCountZ);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                           uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                           uint32_t groupCountZ) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                               VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount,
                                               const VkWriteDescriptorSet* pDescriptorWrites) {
    tracker_.CmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount,
                                     pDescriptorWrites);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount,
                                                const VkWriteDescriptorSet* pDescriptorWrites) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer,
                                                           VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                           VkPipelineLayout layout, uint32_t set, const void* pData) {
    tracker_.CmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer,
                                                            VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                            VkPipelineLayout layout, uint32_t set, const void* pData) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer,
                                              const VkRenderPassBeginInfo* pRenderPassBegin,
                                              const VkSubpassBeginInfo* pSubpassBeginInfo) {
    tracker_.CmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer,
                                               const VkRenderPassBeginInfo* pRenderPassBegin,
                                               const VkSubpassBeginInfo* pSubpassBeginInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                                          const VkSubpassEndInfo* pSubpassEndInfo) {
    tracker_.CmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                                           const VkSubpassEndInfo* pSubpassEndInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {
    tracker_.CmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                               VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                               uint32_t maxDrawCount, uint32_t stride) {
    tracker_.CmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount,
                                     stride);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                uint32_t maxDrawCount, uint32_t stride) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                      VkDeviceSize offset, VkBuffer countBuffer,
                                                      VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                      uint32_t stride) {
    tracker_.CmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount,
                                            stride);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                       VkDeviceSize offset, VkBuffer countBuffer,
                                                       VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                       uint32_t stride) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize,
                                                    const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    tracker_.CmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize,
                                                     const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetRenderingAttachmentLocationsKHR(
    VkCommandBuffer commandBuffer, const VkRenderingAttachmentLocationInfoKHR* pLocationInfo) {
    tracker_.CmdSetRenderingAttachmentLocationsKHR(commandBuffer, pLocationInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetRenderingAttachmentLocationsKHR(
    VkCommandBuffer commandBuffer, const VkRenderingAttachmentLocationInfoKHR* pLocationInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetRenderingInputAttachmentIndicesKHR(
    VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfoKHR* pInputAttachmentIndexInfo) {
    tracker_.CmdSetRenderingInputAttachmentIndicesKHR(commandBuffer, pInputAttachmentIndexInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetRenderingInputAttachmentIndicesKHR(
    VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfoKHR* pInputAttachmentIndexInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo) {
    tracker_.CmdEncodeVideoKHR(commandBuffer, pEncodeInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event,
                                       const VkDependencyInfo* pDependencyInfo) {
    tracker_.CmdSetEvent2KHR(commandBuffer, event, pDependencyInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event,
                                        const VkDependencyInfo* pDependencyInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event,
                                         VkPipelineStageFlags2 stageMask) {
    tracker_.CmdResetEvent2KHR(commandBuffer, event, stageMask);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event,
                                          VkPipelineStageFlags2 stageMask) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                         const VkDependencyInfo* pDependencyInfos) {
    tracker_.CmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                          const VkDependencyInfo* pDependencyInfos) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {
    tracker_.CmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                             VkQueryPool queryPool, uint32_t query) {
    tracker_.CmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                              VkQueryPool queryPool, uint32_t query) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                                VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {
    tracker_.CmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                                 VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {
    tracker_.CmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {
    tracker_.CmdCopyImage2KHR(commandBuffer, pCopyImageInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer,
                                                const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    tracker_.CmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer,
                                                 const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer,
                                                const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    tracker_.CmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer,
                                                 const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {
    tracker_.CmdBlitImage2KHR(commandBuffer, pBlitImageInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdResolveImage2KHR(VkCommandBuffer commandBuffer,
                                           const VkResolveImageInfo2* pResolveImageInfo) {
    tracker_.CmdResolveImage2KHR(commandBuffer, pResolveImageInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdResolveImage2KHR(VkCommandBuffer commandBuffer,
                                            const VkResolveImageInfo2* pResolveImageInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress) {
    tracker_.CmdTraceRaysIndirect2KHR(commandBuffer, indirectDeviceAddress);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                              VkDeviceSize size, VkIndexType indexType) {
    tracker_.CmdBindIndexBuffer2KHR(commandBuffer, buffer, offset, size, indexType);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                               VkDeviceSize size, VkIndexType indexType) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                            uint16_t lineStipplePattern) {
    tracker_.CmdSetLineStippleKHR(commandBuffer, lineStippleFactor, lineStipplePattern);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                             uint16_t lineStipplePattern) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindDescriptorSets2KHR(VkCommandBuffer commandBuffer,
                                                 const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo) {
    tracker_.CmdBindDescriptorSets2KHR(commandBuffer, pBindDescriptorSetsInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindDescriptorSets2KHR(VkCommandBuffer commandBuffer,
                                                  const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdPushConstants2KHR(VkCommandBuffer commandBuffer,
                                            const VkPushConstantsInfoKHR* pPushConstantsInfo) {
    tracker_.CmdPushConstants2KHR(commandBuffer, pPushConstantsInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdPushConstants2KHR(VkCommandBuffer commandBuffer,
                                             const VkPushConstantsInfoKHR* pPushConstantsInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdPushDescriptorSet2KHR(VkCommandBuffer commandBuffer,
                                                const VkPushDescriptorSetInfoKHR* pPushDescriptorSetInfo) {
    tracker_.CmdPushDescriptorSet2KHR(commandBuffer, pPushDescriptorSetInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdPushDescriptorSet2KHR(VkCommandBuffer commandBuffer,
                                                 const VkPushDescriptorSetInfoKHR* pPushDescriptorSetInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdPushDescriptorSetWithTemplate2KHR(
    VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo) {
    tracker_.CmdPushDescriptorSetWithTemplate2KHR(commandBuffer, pPushDescriptorSetWithTemplateInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdPushDescriptorSetWithTemplate2KHR(
    VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDescriptorBufferOffsets2EXT(
    VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo) {
    tracker_.CmdSetDescriptorBufferOffsets2EXT(commandBuffer, pSetDescriptorBufferOffsetsInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDescriptorBufferOffsets2EXT(
    VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    VkCommandBuffer commandBuffer,
    const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo) {
    tracker_.CmdBindDescriptorBufferEmbeddedSamplers2EXT(commandBuffer, pBindDescriptorBufferEmbeddedSamplersInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    VkCommandBuffer commandBuffer,
    const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer,
                                              const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
    tracker_.CmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
    WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer,
                                               const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
    WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) {
    tracker_.CmdDebugMarkerEndEXT(commandBuffer);
    WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) {
    WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer,
                                               const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
    tracker_.CmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
    WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer,
                                                const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
    WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                          uint32_t bindingCount, const VkBuffer* pBuffers,
                                                          const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes) {
    tracker_.CmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                           uint32_t bindingCount, const VkBuffer* pBuffers,
                                                           const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                                    uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                                    const VkDeviceSize* pCounterBufferOffsets) {
    tracker_.CmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers,
                                          pCounterBufferOffsets);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                                     uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                                     const VkDeviceSize* pCounterBufferOffsets) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                                  uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                                  const VkDeviceSize* pCounterBufferOffsets) {
    tracker_.CmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers,
                                        pCounterBufferOffsets);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                                   uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                                   const VkDeviceSize* pCounterBufferOffsets) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                               VkQueryControlFlags flags, uint32_t index) {
    tracker_.CmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                                VkQueryControlFlags flags, uint32_t index) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                             uint32_t index) {
    tracker_.CmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                              uint32_t index) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount,
                                                   uint32_t firstInstance, VkBuffer counterBuffer,
                                                   VkDeviceSize counterBufferOffset, uint32_t counterOffset,
                                                   uint32_t vertexStride) {
    tracker_.CmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer,
                                         counterBufferOffset, counterOffset, vertexStride);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount,
                                                    uint32_t firstInstance, VkBuffer counterBuffer,
                                                    VkDeviceSize counterBufferOffset, uint32_t counterOffset,
                                                    uint32_t vertexStride) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo) {
    tracker_.CmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                               VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                               uint32_t maxDrawCount, uint32_t stride) {
    tracker_.CmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount,
                                     stride);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                uint32_t maxDrawCount, uint32_t stride) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                      VkDeviceSize offset, VkBuffer countBuffer,
                                                      VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                      uint32_t stride) {
    tracker_.CmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount,
                                            stride);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                       VkDeviceSize offset, VkBuffer countBuffer,
                                                       VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                       uint32_t stride) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBeginConditionalRenderingEXT(
    VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) {
    tracker_.CmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBeginConditionalRenderingEXT(
    VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer) {
    tracker_.CmdEndConditionalRenderingEXT(commandBuffer);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                                uint32_t viewportCount,
                                                const VkViewportWScalingNV* pViewportWScalings) {
    tracker_.CmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                                 uint32_t viewportCount,
                                                 const VkViewportWScalingNV* pViewportWScalings) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle,
                                                 uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) {
    tracker_.CmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle,
                                                  uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable) {
    tracker_.CmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer,
                                                        VkBool32 discardRectangleEnable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer,
                                                     VkDiscardRectangleModeEXT discardRectangleMode) {
    tracker_.CmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer,
                                                      VkDiscardRectangleModeEXT discardRectangleMode) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer,
                                                  const VkDebugUtilsLabelEXT* pLabelInfo) {
    tracker_.CmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer,
                                                   const VkDebugUtilsLabelEXT* pLabelInfo) {
    WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) {
    tracker_.CmdEndDebugUtilsLabelEXT(commandBuffer);
    WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) {
    WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer,
                                                   const VkDebugUtilsLabelEXT* pLabelInfo) {
    tracker_.CmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer,
                                                    const VkDebugUtilsLabelEXT* pLabelInfo) {
    WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

#ifdef VK_ENABLE_BETA_EXTENSIONS
void CommandBuffer::PreCmdInitializeGraphScratchMemoryAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch) {
    tracker_.CmdInitializeGraphScratchMemoryAMDX(commandBuffer, scratch);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdInitializeGraphScratchMemoryAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void CommandBuffer::PreCmdDispatchGraphAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                            const VkDispatchGraphCountInfoAMDX* pCountInfo) {
    tracker_.CmdDispatchGraphAMDX(commandBuffer, scratch, pCountInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDispatchGraphAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                             const VkDispatchGraphCountInfoAMDX* pCountInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void CommandBuffer::PreCmdDispatchGraphIndirectAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                                    const VkDispatchGraphCountInfoAMDX* pCountInfo) {
    tracker_.CmdDispatchGraphIndirectAMDX(commandBuffer, scratch, pCountInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDispatchGraphIndirectAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                                     const VkDispatchGraphCountInfoAMDX* pCountInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void CommandBuffer::PreCmdDispatchGraphIndirectCountAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                                         VkDeviceAddress countInfo) {
    tracker_.CmdDispatchGraphIndirectCountAMDX(commandBuffer, scratch, countInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDispatchGraphIndirectCountAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                                          VkDeviceAddress countInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

void CommandBuffer::PreCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer,
                                                const VkSampleLocationsInfoEXT* pSampleLocationsInfo) {
    tracker_.CmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer,
                                                 const VkSampleLocationsInfoEXT* pSampleLocationsInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView,
                                                 VkImageLayout imageLayout) {
    tracker_.CmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView,
                                                  VkImageLayout imageLayout) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                                          uint32_t viewportCount,
                                                          const VkShadingRatePaletteNV* pShadingRatePalettes) {
    tracker_.CmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                                           uint32_t viewportCount,
                                                           const VkShadingRatePaletteNV* pShadingRatePalettes) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer,
                                                 VkCoarseSampleOrderTypeNV sampleOrderType,
                                                 uint32_t customSampleOrderCount,
                                                 const VkCoarseSampleOrderCustomNV* pCustomSampleOrders) {
    tracker_.CmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer,
                                                  VkCoarseSampleOrderTypeNV sampleOrderType,
                                                  uint32_t customSampleOrderCount,
                                                  const VkCoarseSampleOrderCustomNV* pCustomSampleOrders) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer,
                                                       const VkAccelerationStructureInfoNV* pInfo,
                                                       VkBuffer instanceData, VkDeviceSize instanceOffset,
                                                       VkBool32 update, VkAccelerationStructureNV dst,
                                                       VkAccelerationStructureNV src, VkBuffer scratch,
                                                       VkDeviceSize scratchOffset) {
    tracker_.CmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src,
                                             scratch, scratchOffset);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer,
                                                        const VkAccelerationStructureInfoNV* pInfo,
                                                        VkBuffer instanceData, VkDeviceSize instanceOffset,
                                                        VkBool32 update, VkAccelerationStructureNV dst,
                                                        VkAccelerationStructureNV src, VkBuffer scratch,
                                                        VkDeviceSize scratchOffset) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst,
                                                      VkAccelerationStructureNV src,
                                                      VkCopyAccelerationStructureModeKHR mode) {
    tracker_.CmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst,
                                                       VkAccelerationStructureNV src,
                                                       VkCopyAccelerationStructureModeKHR mode) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer,
                                      VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer,
                                      VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride,
                                      VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset,
                                      VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer,
                                      VkDeviceSize callableShaderBindingOffset,
                                      VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height,
                                      uint32_t depth) {
    tracker_.CmdTraceRaysNV(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset,
                            missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride,
                            hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride,
                            callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride,
                            width, height, depth);
    WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer,
                                       VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer,
                                       VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride,
                                       VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset,
                                       VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer,
                                       VkDeviceSize callableShaderBindingOffset,
                                       VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height,
                                       uint32_t depth) {
    WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdWriteAccelerationStructuresPropertiesNV(
    VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
    const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool,
    uint32_t firstQuery) {
    tracker_.CmdWriteAccelerationStructuresPropertiesNV(commandBuffer, accelerationStructureCount,
                                                        pAccelerationStructures, queryType, queryPool, firstQuery);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdWriteAccelerationStructuresPropertiesNV(
    VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
    const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool,
    uint32_t firstQuery) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                               VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {
    tracker_.CmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                                VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask) {
    tracker_.CmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                  uint32_t drawCount, uint32_t stride) {
    tracker_.CmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                   uint32_t drawCount, uint32_t stride) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                       VkDeviceSize offset, VkBuffer countBuffer,
                                                       VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                       uint32_t stride) {
    tracker_.CmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                             maxDrawCount, stride);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                        VkDeviceSize offset, VkBuffer countBuffer,
                                                        VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                        uint32_t stride) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                                      uint32_t exclusiveScissorCount,
                                                      const VkBool32* pExclusiveScissorEnables) {
    tracker_.CmdSetExclusiveScissorEnableNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount,
                                            pExclusiveScissorEnables);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                                       uint32_t exclusiveScissorCount,
                                                       const VkBool32* pExclusiveScissorEnables) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                                uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors) {
    tracker_.CmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                                 uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker) {
    tracker_.CmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

VkResult CommandBuffer::PreCmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer,
                                                        const VkPerformanceMarkerInfoINTEL* pMarkerInfo) {
    tracker_.CmdSetPerformanceMarkerINTEL(commandBuffer, pMarkerInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
    return VK_SUCCESS;
}
VkResult CommandBuffer::PostCmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer,
                                                         const VkPerformanceMarkerInfoINTEL* pMarkerInfo,
                                                         VkResult result) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
    return result;
}

VkResult CommandBuffer::PreCmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer,
                                                              const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo) {
    tracker_.CmdSetPerformanceStreamMarkerINTEL(commandBuffer, pMarkerInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
    return VK_SUCCESS;
}
VkResult CommandBuffer::PostCmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer,
                                                               const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo,
                                                               VkResult result) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
    return result;
}

VkResult CommandBuffer::PreCmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer,
                                                          const VkPerformanceOverrideInfoINTEL* pOverrideInfo) {
    tracker_.CmdSetPerformanceOverrideINTEL(commandBuffer, pOverrideInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
    return VK_SUCCESS;
}
VkResult CommandBuffer::PostCmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer,
                                                           const VkPerformanceOverrideInfoINTEL* pOverrideInfo,
                                                           VkResult result) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
    return result;
}

void CommandBuffer::PreCmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                            uint16_t lineStipplePattern) {
    tracker_.CmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                             uint16_t lineStipplePattern) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    tracker_.CmdSetCullModeEXT(commandBuffer, cullMode);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    tracker_.CmdSetFrontFaceEXT(commandBuffer, frontFace);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer,
                                                  VkPrimitiveTopology primitiveTopology) {
    tracker_.CmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer,
                                                   VkPrimitiveTopology primitiveTopology) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                                  const VkViewport* pViewports) {
    tracker_.CmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                                   const VkViewport* pViewports) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                                 const VkRect2D* pScissors) {
    tracker_.CmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                                  const VkRect2D* pScissors) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                uint32_t bindingCount, const VkBuffer* pBuffers,
                                                const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                                                const VkDeviceSize* pStrides) {
    tracker_.CmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                 uint32_t bindingCount, const VkBuffer* pBuffers,
                                                 const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                                                 const VkDeviceSize* pStrides) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    tracker_.CmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    tracker_.CmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    tracker_.CmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
    tracker_.CmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    tracker_.CmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                          VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp,
                                          VkCompareOp compareOp) {
    tracker_.CmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                           VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp,
                                           VkCompareOp compareOp) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer,
                                                        const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
    tracker_.CmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer,
                                                         const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                                     const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
    tracker_.CmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                                      const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer,
                                                    VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline,
                                                    uint32_t groupIndex) {
    tracker_.CmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer,
                                                     VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline,
                                                     uint32_t groupIndex) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthBias2EXT(VkCommandBuffer commandBuffer, const VkDepthBiasInfoEXT* pDepthBiasInfo) {
    tracker_.CmdSetDepthBias2EXT(commandBuffer, pDepthBiasInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthBias2EXT(VkCommandBuffer commandBuffer, const VkDepthBiasInfoEXT* pDepthBiasInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCudaLaunchKernelNV(VkCommandBuffer commandBuffer, const VkCudaLaunchInfoNV* pLaunchInfo) {
    tracker_.CmdCudaLaunchKernelNV(commandBuffer, pLaunchInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCudaLaunchKernelNV(VkCommandBuffer commandBuffer, const VkCudaLaunchInfoNV* pLaunchInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount,
                                                   const VkDescriptorBufferBindingInfoEXT* pBindingInfos) {
    tracker_.CmdBindDescriptorBuffersEXT(commandBuffer, bufferCount, pBindingInfos);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount,
                                                    const VkDescriptorBufferBindingInfoEXT* pBindingInfos) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer commandBuffer,
                                                        VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout,
                                                        uint32_t firstSet, uint32_t setCount,
                                                        const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets) {
    tracker_.CmdSetDescriptorBufferOffsetsEXT(commandBuffer, pipelineBindPoint, layout, firstSet, setCount,
                                              pBufferIndices, pOffsets);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer commandBuffer,
                                                         VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout,
                                                         uint32_t firstSet, uint32_t setCount,
                                                         const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer commandBuffer,
                                                                  VkPipelineBindPoint pipelineBindPoint,
                                                                  VkPipelineLayout layout, uint32_t set) {
    tracker_.CmdBindDescriptorBufferEmbeddedSamplersEXT(commandBuffer, pipelineBindPoint, layout, set);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer commandBuffer,
                                                                   VkPipelineBindPoint pipelineBindPoint,
                                                                   VkPipelineLayout layout, uint32_t set) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetFragmentShadingRateEnumNV(VkCommandBuffer commandBuffer,
                                                       VkFragmentShadingRateNV shadingRate,
                                                       const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    tracker_.CmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetFragmentShadingRateEnumNV(VkCommandBuffer commandBuffer,
                                                        VkFragmentShadingRateNV shadingRate,
                                                        const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
                                            const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions,
                                            uint32_t vertexAttributeDescriptionCount,
                                            const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) {
    tracker_.CmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions,
                                  vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetVertexInputEXT(
    VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
    const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount,
    const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer) {
    tracker_.CmdSubpassShadingHUAWEI(commandBuffer);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer, VkImageView imageView,
                                                   VkImageLayout imageLayout) {
    tracker_.CmdBindInvocationMaskHUAWEI(commandBuffer, imageView, imageLayout);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer, VkImageView imageView,
                                                    VkImageLayout imageLayout) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints) {
    tracker_.CmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer,
                                                        VkBool32 rasterizerDiscardEnable) {
    tracker_.CmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer,
                                                         VkBool32 rasterizerDiscardEnable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
    tracker_.CmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp) {
    tracker_.CmdSetLogicOpEXT(commandBuffer, logicOp);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {
    tracker_.CmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer,
                                                        VkBool32 primitiveRestartEnable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                                 const VkBool32* pColorWriteEnables) {
    tracker_.CmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                                  const VkBool32* pColorWriteEnables) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                       const VkMultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount,
                                       uint32_t firstInstance, uint32_t stride) {
    tracker_.CmdDrawMultiEXT(commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                        const VkMultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount,
                                        uint32_t firstInstance, uint32_t stride) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                              const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount,
                                              uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset) {
    tracker_.CmdDrawMultiIndexedEXT(commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride,
                                    pVertexOffset);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                               const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount,
                                               uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBuildMicromapsEXT(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                            const VkMicromapBuildInfoEXT* pInfos) {
    tracker_.CmdBuildMicromapsEXT(commandBuffer, infoCount, pInfos);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBuildMicromapsEXT(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                             const VkMicromapBuildInfoEXT* pInfos) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo) {
    tracker_.CmdCopyMicromapEXT(commandBuffer, pInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer,
                                                  const VkCopyMicromapToMemoryInfoEXT* pInfo) {
    tracker_.CmdCopyMicromapToMemoryEXT(commandBuffer, pInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer,
                                                   const VkCopyMicromapToMemoryInfoEXT* pInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer,
                                                  const VkCopyMemoryToMicromapInfoEXT* pInfo) {
    tracker_.CmdCopyMemoryToMicromapEXT(commandBuffer, pInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer,
                                                   const VkCopyMemoryToMicromapInfoEXT* pInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount,
                                                      const VkMicromapEXT* pMicromaps, VkQueryType queryType,
                                                      VkQueryPool queryPool, uint32_t firstQuery) {
    tracker_.CmdWriteMicromapsPropertiesEXT(commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount,
                                                       const VkMicromapEXT* pMicromaps, VkQueryType queryType,
                                                       VkQueryPool queryPool, uint32_t firstQuery) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                            uint32_t groupCountZ) {
    tracker_.CmdDrawClusterHUAWEI(commandBuffer, groupCountX, groupCountY, groupCountZ);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                             uint32_t groupCountZ) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                    VkDeviceSize offset) {
    tracker_.CmdDrawClusterIndirectHUAWEI(commandBuffer, buffer, offset);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                     VkDeviceSize offset) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                               uint32_t copyCount, uint32_t stride) {
    tracker_.CmdCopyMemoryIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                                uint32_t copyCount, uint32_t stride) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyMemoryToImageIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                                      uint32_t copyCount, uint32_t stride, VkImage dstImage,
                                                      VkImageLayout dstImageLayout,
                                                      const VkImageSubresourceLayers* pImageSubresources) {
    tracker_.CmdCopyMemoryToImageIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride, dstImage,
                                            dstImageLayout, pImageSubresources);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyMemoryToImageIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                                       uint32_t copyCount, uint32_t stride, VkImage dstImage,
                                                       VkImageLayout dstImageLayout,
                                                       const VkImageSubresourceLayers* pImageSubresources) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount,
                                             const VkDecompressMemoryRegionNV* pDecompressMemoryRegions) {
    tracker_.CmdDecompressMemoryNV(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount,
                                              const VkDecompressMemoryRegionNV* pDecompressMemoryRegions) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer,
                                                          VkDeviceAddress indirectCommandsAddress,
                                                          VkDeviceAddress indirectCommandsCountAddress,
                                                          uint32_t stride) {
    tracker_.CmdDecompressMemoryIndirectCountNV(commandBuffer, indirectCommandsAddress, indirectCommandsCountAddress,
                                                stride);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer,
                                                           VkDeviceAddress indirectCommandsAddress,
                                                           VkDeviceAddress indirectCommandsCountAddress,
                                                           uint32_t stride) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer,
                                                         VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) {
    tracker_.CmdUpdatePipelineIndirectBufferNV(commandBuffer, pipelineBindPoint, pipeline);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer,
                                                          VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClampEnable) {
    tracker_.CmdSetDepthClampEnableEXT(commandBuffer, depthClampEnable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClampEnable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode) {
    tracker_.CmdSetPolygonModeEXT(commandBuffer, polygonMode);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer,
                                                     VkSampleCountFlagBits rasterizationSamples) {
    tracker_.CmdSetRasterizationSamplesEXT(commandBuffer, rasterizationSamples);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer,
                                                      VkSampleCountFlagBits rasterizationSamples) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples,
                                           const VkSampleMask* pSampleMask) {
    tracker_.CmdSetSampleMaskEXT(commandBuffer, samples, pSampleMask);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples,
                                            const VkSampleMask* pSampleMask) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable) {
    tracker_.CmdSetAlphaToCoverageEnableEXT(commandBuffer, alphaToCoverageEnable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable) {
    tracker_.CmdSetAlphaToOneEnableEXT(commandBuffer, alphaToOneEnable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable) {
    tracker_.CmdSetLogicOpEnableEXT(commandBuffer, logicOpEnable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                                 uint32_t attachmentCount, const VkBool32* pColorBlendEnables) {
    tracker_.CmdSetColorBlendEnableEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                                  uint32_t attachmentCount, const VkBool32* pColorBlendEnables) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                                   uint32_t attachmentCount,
                                                   const VkColorBlendEquationEXT* pColorBlendEquations) {
    tracker_.CmdSetColorBlendEquationEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                                    uint32_t attachmentCount,
                                                    const VkColorBlendEquationEXT* pColorBlendEquations) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                               uint32_t attachmentCount,
                                               const VkColorComponentFlags* pColorWriteMasks) {
    tracker_.CmdSetColorWriteMaskEXT(commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                                uint32_t attachmentCount,
                                                const VkColorComponentFlags* pColorWriteMasks) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer,
                                                         VkTessellationDomainOrigin domainOrigin) {
    tracker_.CmdSetTessellationDomainOriginEXT(commandBuffer, domainOrigin);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer,
                                                          VkTessellationDomainOrigin domainOrigin) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer, uint32_t rasterizationStream) {
    tracker_.CmdSetRasterizationStreamEXT(commandBuffer, rasterizationStream);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer, uint32_t rasterizationStream) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetConservativeRasterizationModeEXT(
    VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode) {
    tracker_.CmdSetConservativeRasterizationModeEXT(commandBuffer, conservativeRasterizationMode);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetConservativeRasterizationModeEXT(
    VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer commandBuffer,
                                                                 float extraPrimitiveOverestimationSize) {
    tracker_.CmdSetExtraPrimitiveOverestimationSizeEXT(commandBuffer, extraPrimitiveOverestimationSize);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer commandBuffer,
                                                                  float extraPrimitiveOverestimationSize) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClipEnable) {
    tracker_.CmdSetDepthClipEnableEXT(commandBuffer, depthClipEnable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClipEnable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable) {
    tracker_.CmdSetSampleLocationsEnableEXT(commandBuffer, sampleLocationsEnable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                                   uint32_t attachmentCount,
                                                   const VkColorBlendAdvancedEXT* pColorBlendAdvanced) {
    tracker_.CmdSetColorBlendAdvancedEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                                    uint32_t attachmentCount,
                                                    const VkColorBlendAdvancedEXT* pColorBlendAdvanced) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer,
                                                    VkProvokingVertexModeEXT provokingVertexMode) {
    tracker_.CmdSetProvokingVertexModeEXT(commandBuffer, provokingVertexMode);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer,
                                                     VkProvokingVertexModeEXT provokingVertexMode) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetLineRasterizationModeEXT(VkCommandBuffer commandBuffer,
                                                      VkLineRasterizationModeEXT lineRasterizationMode) {
    tracker_.CmdSetLineRasterizationModeEXT(commandBuffer, lineRasterizationMode);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetLineRasterizationModeEXT(VkCommandBuffer commandBuffer,
                                                       VkLineRasterizationModeEXT lineRasterizationMode) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable) {
    tracker_.CmdSetLineStippleEnableEXT(commandBuffer, stippledLineEnable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne) {
    tracker_.CmdSetDepthClipNegativeOneToOneEXT(commandBuffer, negativeOneToOne);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable) {
    tracker_.CmdSetViewportWScalingEnableNV(commandBuffer, viewportWScalingEnable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                               uint32_t viewportCount, const VkViewportSwizzleNV* pViewportSwizzles) {
    tracker_.CmdSetViewportSwizzleNV(commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                                uint32_t viewportCount, const VkViewportSwizzleNV* pViewportSwizzles) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable) {
    tracker_.CmdSetCoverageToColorEnableNV(commandBuffer, coverageToColorEnable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer,
                                                       uint32_t coverageToColorLocation) {
    tracker_.CmdSetCoverageToColorLocationNV(commandBuffer, coverageToColorLocation);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer,
                                                        uint32_t coverageToColorLocation) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetCoverageModulationModeNV(VkCommandBuffer commandBuffer,
                                                      VkCoverageModulationModeNV coverageModulationMode) {
    tracker_.CmdSetCoverageModulationModeNV(commandBuffer, coverageModulationMode);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetCoverageModulationModeNV(VkCommandBuffer commandBuffer,
                                                       VkCoverageModulationModeNV coverageModulationMode) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer,
                                                             VkBool32 coverageModulationTableEnable) {
    tracker_.CmdSetCoverageModulationTableEnableNV(commandBuffer, coverageModulationTableEnable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer,
                                                              VkBool32 coverageModulationTableEnable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer,
                                                       uint32_t coverageModulationTableCount,
                                                       const float* pCoverageModulationTable) {
    tracker_.CmdSetCoverageModulationTableNV(commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer,
                                                        uint32_t coverageModulationTableCount,
                                                        const float* pCoverageModulationTable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable) {
    tracker_.CmdSetShadingRateImageEnableNV(commandBuffer, shadingRateImageEnable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer commandBuffer,
                                                                VkBool32 representativeFragmentTestEnable) {
    tracker_.CmdSetRepresentativeFragmentTestEnableNV(commandBuffer, representativeFragmentTestEnable);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer commandBuffer,
                                                                 VkBool32 representativeFragmentTestEnable) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer,
                                                     VkCoverageReductionModeNV coverageReductionMode) {
    tracker_.CmdSetCoverageReductionModeNV(commandBuffer, coverageReductionMode);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer,
                                                      VkCoverageReductionModeNV coverageReductionMode) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session,
                                               const VkOpticalFlowExecuteInfoNV* pExecuteInfo) {
    tracker_.CmdOpticalFlowExecuteNV(commandBuffer, session, pExecuteInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session,
                                                const VkOpticalFlowExecuteInfoNV* pExecuteInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount,
                                         const VkShaderStageFlagBits* pStages, const VkShaderEXT* pShaders) {
    tracker_.CmdBindShadersEXT(commandBuffer, stageCount, pStages, pShaders);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount,
                                          const VkShaderStageFlagBits* pStages, const VkShaderEXT* pShaders) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetDepthClampRangeEXT(VkCommandBuffer commandBuffer, VkDepthClampModeEXT depthClampMode,
                                                const VkDepthClampRangeEXT* pDepthClampRange) {
    tracker_.CmdSetDepthClampRangeEXT(commandBuffer, depthClampMode, pDepthClampRange);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetDepthClampRangeEXT(VkCommandBuffer commandBuffer, VkDepthClampModeEXT depthClampMode,
                                                 const VkDepthClampRangeEXT* pDepthClampRange) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer,
                                                             VkImageAspectFlags aspectMask) {
    tracker_.CmdSetAttachmentFeedbackLoopEnableEXT(commandBuffer, aspectMask);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer,
                                                              VkImageAspectFlags aspectMask) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdPreprocessGeneratedCommandsEXT(VkCommandBuffer commandBuffer,
                                                         const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo,
                                                         VkCommandBuffer stateCommandBuffer) {
    tracker_.CmdPreprocessGeneratedCommandsEXT(commandBuffer, pGeneratedCommandsInfo, stateCommandBuffer);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdPreprocessGeneratedCommandsEXT(VkCommandBuffer commandBuffer,
                                                          const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo,
                                                          VkCommandBuffer stateCommandBuffer) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdExecuteGeneratedCommandsEXT(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                                      const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo) {
    tracker_.CmdExecuteGeneratedCommandsEXT(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdExecuteGeneratedCommandsEXT(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                                       const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBuildAccelerationStructuresKHR(
    VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) {
    tracker_.CmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
    WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBuildAccelerationStructuresKHR(
    VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) {
    WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdBuildAccelerationStructuresIndirectKHR(
    VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkDeviceAddress* pIndirectDeviceAddresses, const uint32_t* pIndirectStrides,
    const uint32_t* const* ppMaxPrimitiveCounts) {
    tracker_.CmdBuildAccelerationStructuresIndirectKHR(commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses,
                                                       pIndirectStrides, ppMaxPrimitiveCounts);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdBuildAccelerationStructuresIndirectKHR(
    VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkDeviceAddress* pIndirectDeviceAddresses, const uint32_t* pIndirectStrides,
    const uint32_t* const* ppMaxPrimitiveCounts) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                                       const VkCopyAccelerationStructureInfoKHR* pInfo) {
    tracker_.CmdCopyAccelerationStructureKHR(commandBuffer, pInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                                        const VkCopyAccelerationStructureInfoKHR* pInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyAccelerationStructureToMemoryKHR(
    VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) {
    tracker_.CmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyAccelerationStructureToMemoryKHR(
    VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdCopyMemoryToAccelerationStructureKHR(
    VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) {
    tracker_.CmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdCopyMemoryToAccelerationStructureKHR(
    VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdWriteAccelerationStructuresPropertiesKHR(
    VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
    const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool,
    uint32_t firstQuery) {
    tracker_.CmdWriteAccelerationStructuresPropertiesKHR(commandBuffer, accelerationStructureCount,
                                                         pAccelerationStructures, queryType, queryPool, firstQuery);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdWriteAccelerationStructuresPropertiesKHR(
    VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
    const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool,
    uint32_t firstQuery) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdTraceRaysKHR(VkCommandBuffer commandBuffer,
                                       const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                       const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                       const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                       const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                       uint32_t width, uint32_t height, uint32_t depth) {
    tracker_.CmdTraceRaysKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable,
                             pCallableShaderBindingTable, width, height, depth);
    WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdTraceRaysKHR(VkCommandBuffer commandBuffer,
                                        const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                        const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                        const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                        const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                        uint32_t width, uint32_t height, uint32_t depth) {
    WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer,
                                               const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                               const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                               const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                               const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                               VkDeviceAddress indirectDeviceAddress) {
    tracker_.CmdTraceRaysIndirectKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable,
                                     pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
    WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer,
                                                const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                                const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                                const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                                const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                                VkDeviceAddress indirectDeviceAddress) {
    WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize) {
    tracker_.CmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer,
                                                             uint32_t pipelineStackSize) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                           uint32_t groupCountZ) {
    tracker_.CmdDrawMeshTasksEXT(commandBuffer, groupCountX, groupCountY, groupCountZ);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                            uint32_t groupCountZ) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                   uint32_t drawCount, uint32_t stride) {
    tracker_.CmdDrawMeshTasksIndirectEXT(commandBuffer, buffer, offset, drawCount, stride);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                    uint32_t drawCount, uint32_t stride) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

void CommandBuffer::PreCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                        VkDeviceSize offset, VkBuffer countBuffer,
                                                        VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                        uint32_t stride) {
    tracker_.CmdDrawMeshTasksIndirectCountEXT(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                              maxDrawCount, stride);
    if (instrument_all_commands_) WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);
}
void CommandBuffer::PostCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                         VkDeviceSize offset, VkBuffer countBuffer,
                                                         VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                         uint32_t stride) {
    if (instrument_all_commands_) WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);
}

// NOLINTEND
