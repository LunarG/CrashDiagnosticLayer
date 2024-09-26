
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

VkResult Context::PostBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo,
                                         VkResult result) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    return p_cmd->PostBeginCommandBuffer(commandBuffer, pBeginInfo, result);
}

VkResult Context::PreEndCommandBuffer(VkCommandBuffer commandBuffer) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    return p_cmd->PreEndCommandBuffer(commandBuffer);
}
VkResult Context::PostEndCommandBuffer(VkCommandBuffer commandBuffer, VkResult result) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    return p_cmd->PostEndCommandBuffer(commandBuffer, result);
}

VkResult Context::PostResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags,
                                         VkResult result) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    return p_cmd->PostResetCommandBuffer(commandBuffer, flags, result);
}

void Context::PostCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                  VkPipeline pipeline) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
}

void Context::PreCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                const VkViewport* pViewports) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
}
void Context::PostCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                 const VkViewport* pViewports) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
}

void Context::PreCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount,
                               const VkRect2D* pScissors) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
}
void Context::PostCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount,
                                const VkRect2D* pScissors) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
}

void Context::PreCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetLineWidth(commandBuffer, lineWidth);
}
void Context::PostCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetLineWidth(commandBuffer, lineWidth);
}

void Context::PreCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp,
                                 float depthBiasSlopeFactor) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
}
void Context::PostCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp,
                                  float depthBiasSlopeFactor) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
}

void Context::PreCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetBlendConstants(commandBuffer, blendConstants);
}
void Context::PostCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetBlendConstants(commandBuffer, blendConstants);
}

void Context::PreCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
}
void Context::PostCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
}

void Context::PreCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                          uint32_t compareMask) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
}
void Context::PostCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                           uint32_t compareMask) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
}

void Context::PreCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                        uint32_t writeMask) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
}
void Context::PostCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                         uint32_t writeMask) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
}

void Context::PreCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                        uint32_t reference) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetStencilReference(commandBuffer, faceMask, reference);
}
void Context::PostCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                         uint32_t reference) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetStencilReference(commandBuffer, faceMask, reference);
}

void Context::PreCmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                       VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount,
                                       const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount,
                                       const uint32_t* pDynamicOffsets) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount,
                                    pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
}
void Context::PostCmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                        VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount,
                                        const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount,
                                        const uint32_t* pDynamicOffsets) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount,
                                     pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
}

void Context::PreCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                    VkIndexType indexType) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
}
void Context::PostCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                     VkIndexType indexType) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
}

void Context::PreCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                      const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
}
void Context::PostCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                       const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
}

void Context::PreCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount,
                         uint32_t firstVertex, uint32_t firstInstance) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}
void Context::PostCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount,
                          uint32_t firstVertex, uint32_t firstInstance) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}

void Context::PreCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount,
                                uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}
void Context::PostCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount,
                                 uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}

void Context::PreCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                 uint32_t drawCount, uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
}
void Context::PostCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                  uint32_t drawCount, uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
}

void Context::PreCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                        uint32_t drawCount, uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
}
void Context::PostCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                         uint32_t drawCount, uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
}

void Context::PreCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                             uint32_t groupCountZ) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
}
void Context::PostCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                              uint32_t groupCountZ) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
}

void Context::PreCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDispatchIndirect(commandBuffer, buffer, offset);
}
void Context::PostCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDispatchIndirect(commandBuffer, buffer, offset);
}

void Context::PreCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer,
                               uint32_t regionCount, const VkBufferCopy* pRegions) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
}
void Context::PostCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer,
                                uint32_t regionCount, const VkBufferCopy* pRegions) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
}

void Context::PreCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                              VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                              const VkImageCopy* pRegions) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}
void Context::PostCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                               VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                               const VkImageCopy* pRegions) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}

void Context::PreCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                              VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                              const VkImageBlit* pRegions, VkFilter filter) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions,
                           filter);
}
void Context::PostCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                               VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                               const VkImageBlit* pRegions, VkFilter filter) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions,
                            filter);
}

void Context::PreCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage,
                                      VkImageLayout dstImageLayout, uint32_t regionCount,
                                      const VkBufferImageCopy* pRegions) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
}
void Context::PostCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage,
                                       VkImageLayout dstImageLayout, uint32_t regionCount,
                                       const VkBufferImageCopy* pRegions) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
}

void Context::PreCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                      VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
}
void Context::PostCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                       VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
}

void Context::PreCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                 VkDeviceSize dataSize, const void* pData) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
}
void Context::PostCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                  VkDeviceSize dataSize, const void* pData) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
}

void Context::PreCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                               VkDeviceSize size, uint32_t data) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
}
void Context::PostCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                VkDeviceSize size, uint32_t data) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
}

void Context::PreCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                    const VkClearColorValue* pColor, uint32_t rangeCount,
                                    const VkImageSubresourceRange* pRanges) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
}
void Context::PostCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                     const VkClearColorValue* pColor, uint32_t rangeCount,
                                     const VkImageSubresourceRange* pRanges) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
}

void Context::PreCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                           const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount,
                                           const VkImageSubresourceRange* pRanges) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
}
void Context::PostCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                            const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount,
                                            const VkImageSubresourceRange* pRanges) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
}

void Context::PreCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                     const VkClearAttachment* pAttachments, uint32_t rectCount,
                                     const VkClearRect* pRects) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
}
void Context::PostCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                      const VkClearAttachment* pAttachments, uint32_t rectCount,
                                      const VkClearRect* pRects) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
}

void Context::PreCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                 VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                 const VkImageResolve* pRegions) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}
void Context::PostCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                  VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                  const VkImageResolve* pRegions) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount,
                               pRegions);
}

void Context::PreCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetEvent(commandBuffer, event, stageMask);
}
void Context::PostCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetEvent(commandBuffer, event, stageMask);
}

void Context::PreCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdResetEvent(commandBuffer, event, stageMask);
}
void Context::PostCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdResetEvent(commandBuffer, event, stageMask);
}

void Context::PreCmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                               VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask,
                               uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                               uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                               uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount,
                            pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount,
                            pImageMemoryBarriers);
}
void Context::PostCmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask,
                                uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                                uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount,
                             pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount,
                             pImageMemoryBarriers);
}

void Context::PreCmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask,
                                    VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags,
                                    uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                                    uint32_t bufferMemoryBarrierCount,
                                    const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                    uint32_t imageMemoryBarrierCount,
                                    const VkImageMemoryBarrier* pImageMemoryBarriers) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount,
                                 pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers,
                                 imageMemoryBarrierCount, pImageMemoryBarriers);
}
void Context::PostCmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask,
                                     VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags,
                                     uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                                     uint32_t bufferMemoryBarrierCount,
                                     const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                     uint32_t imageMemoryBarrierCount,
                                     const VkImageMemoryBarrier* pImageMemoryBarriers) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount,
                                  pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers,
                                  imageMemoryBarrierCount, pImageMemoryBarriers);
}

void Context::PreCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                               VkQueryControlFlags flags) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBeginQuery(commandBuffer, queryPool, query, flags);
}
void Context::PostCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                VkQueryControlFlags flags) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBeginQuery(commandBuffer, queryPool, query, flags);
}

void Context::PreCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdEndQuery(commandBuffer, queryPool, query);
}
void Context::PostCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdEndQuery(commandBuffer, queryPool, query);
}

void Context::PreCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                   uint32_t queryCount) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
}
void Context::PostCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                    uint32_t queryCount) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
}

void Context::PreCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                   VkQueryPool queryPool, uint32_t query) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
}
void Context::PostCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                    VkQueryPool queryPool, uint32_t query) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
}

void Context::PreCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                         uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                         VkDeviceSize stride, VkQueryResultFlags flags) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride,
                                      flags);
}
void Context::PostCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                          uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                          VkDeviceSize stride, VkQueryResultFlags flags) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride,
                                       flags);
}

void Context::PreCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags,
                                  uint32_t offset, uint32_t size, const void* pValues) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
}
void Context::PostCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout,
                                   VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
}

void Context::PreCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                    VkSubpassContents contents) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
}
void Context::PostCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                     VkSubpassContents contents) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
}

void Context::PreCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdNextSubpass(commandBuffer, contents);
}
void Context::PostCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdNextSubpass(commandBuffer, contents);
}

void Context::PreCmdEndRenderPass(VkCommandBuffer commandBuffer) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdEndRenderPass(commandBuffer);
}
void Context::PostCmdEndRenderPass(VkCommandBuffer commandBuffer) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdEndRenderPass(commandBuffer);
}

void Context::PreCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount,
                                    const VkCommandBuffer* pCommandBuffers) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
}
void Context::PostCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount,
                                     const VkCommandBuffer* pCommandBuffers) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
}

void Context::PreCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetDeviceMask(commandBuffer, deviceMask);
}
void Context::PostCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetDeviceMask(commandBuffer, deviceMask);
}

void Context::PreCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                 uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                 uint32_t groupCountZ) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}
void Context::PostCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                  uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                  uint32_t groupCountZ) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY,
                               groupCountZ);
}

void Context::PreCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                      VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                      uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
void Context::PostCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                       VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                       uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount,
                                    stride);
}

void Context::PreCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                             VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                             uint32_t maxDrawCount, uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount,
                                          stride);
}
void Context::PostCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                              VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                              uint32_t maxDrawCount, uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount,
                                           stride);
}

void Context::PreCmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                     const VkSubpassBeginInfo* pSubpassBeginInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}
void Context::PostCmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                      const VkSubpassBeginInfo* pSubpassBeginInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

void Context::PreCmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                                 const VkSubpassEndInfo* pSubpassEndInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}
void Context::PostCmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                                  const VkSubpassEndInfo* pSubpassEndInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}

void Context::PreCmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
}
void Context::PostCmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
}

void Context::PreCmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetEvent2(commandBuffer, event, pDependencyInfo);
}
void Context::PostCmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetEvent2(commandBuffer, event, pDependencyInfo);
}

void Context::PreCmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdResetEvent2(commandBuffer, event, stageMask);
}
void Context::PostCmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdResetEvent2(commandBuffer, event, stageMask);
}

void Context::PreCmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                const VkDependencyInfo* pDependencyInfos) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
}
void Context::PostCmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                 const VkDependencyInfo* pDependencyInfos) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
}

void Context::PreCmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdPipelineBarrier2(commandBuffer, pDependencyInfo);
}
void Context::PostCmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdPipelineBarrier2(commandBuffer, pDependencyInfo);
}

void Context::PreCmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool,
                                    uint32_t query) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
}
void Context::PostCmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool,
                                     uint32_t query) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
}

void Context::PreCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
}
void Context::PostCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
}

void Context::PreCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdCopyImage2(commandBuffer, pCopyImageInfo);
}
void Context::PostCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdCopyImage2(commandBuffer, pCopyImageInfo);
}

void Context::PreCmdCopyBufferToImage2(VkCommandBuffer commandBuffer,
                                       const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
}
void Context::PostCmdCopyBufferToImage2(VkCommandBuffer commandBuffer,
                                        const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
}

void Context::PreCmdCopyImageToBuffer2(VkCommandBuffer commandBuffer,
                                       const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
}
void Context::PostCmdCopyImageToBuffer2(VkCommandBuffer commandBuffer,
                                        const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
}

void Context::PreCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBlitImage2(commandBuffer, pBlitImageInfo);
}
void Context::PostCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBlitImage2(commandBuffer, pBlitImageInfo);
}

void Context::PreCmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdResolveImage2(commandBuffer, pResolveImageInfo);
}
void Context::PostCmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdResolveImage2(commandBuffer, pResolveImageInfo);
}

void Context::PreCmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBeginRendering(commandBuffer, pRenderingInfo);
}
void Context::PostCmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBeginRendering(commandBuffer, pRenderingInfo);
}

void Context::PreCmdEndRendering(VkCommandBuffer commandBuffer) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdEndRendering(commandBuffer);
}
void Context::PostCmdEndRendering(VkCommandBuffer commandBuffer) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdEndRendering(commandBuffer);
}

void Context::PreCmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetCullMode(commandBuffer, cullMode);
}
void Context::PostCmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetCullMode(commandBuffer, cullMode);
}

void Context::PreCmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetFrontFace(commandBuffer, frontFace);
}
void Context::PostCmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetFrontFace(commandBuffer, frontFace);
}

void Context::PreCmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
}
void Context::PostCmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
}

void Context::PreCmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                         const VkViewport* pViewports) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
}
void Context::PostCmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                          const VkViewport* pViewports) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
}

void Context::PreCmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                        const VkRect2D* pScissors) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
}
void Context::PostCmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                         const VkRect2D* pScissors) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
}

void Context::PreCmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                       const VkBuffer* pBuffers, const VkDeviceSize* pOffsets,
                                       const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}
void Context::PostCmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                        const VkBuffer* pBuffers, const VkDeviceSize* pOffsets,
                                        const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}

void Context::PreCmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetDepthTestEnable(commandBuffer, depthTestEnable);
}
void Context::PostCmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetDepthTestEnable(commandBuffer, depthTestEnable);
}

void Context::PreCmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
}
void Context::PostCmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
}

void Context::PreCmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetDepthCompareOp(commandBuffer, depthCompareOp);
}
void Context::PostCmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetDepthCompareOp(commandBuffer, depthCompareOp);
}

void Context::PreCmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
}
void Context::PostCmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
}

void Context::PreCmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
}
void Context::PostCmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
}

void Context::PreCmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                 VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}
void Context::PostCmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                  VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}

void Context::PreCmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
}
void Context::PostCmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
}

void Context::PreCmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
}
void Context::PostCmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
}

void Context::PreCmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
}
void Context::PostCmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
}

void Context::PreCmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);
}
void Context::PostCmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);
}

void Context::PreCmdEndVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);
}
void Context::PostCmdEndVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);
}

void Context::PreCmdControlVideoCodingKHR(VkCommandBuffer commandBuffer,
                                          const VkVideoCodingControlInfoKHR* pCodingControlInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);
}
void Context::PostCmdControlVideoCodingKHR(VkCommandBuffer commandBuffer,
                                           const VkVideoCodingControlInfoKHR* pCodingControlInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);
}

void Context::PreCmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDecodeVideoKHR(commandBuffer, pDecodeInfo);
}
void Context::PostCmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDecodeVideoKHR(commandBuffer, pDecodeInfo);
}

void Context::PreCmdBeginRenderingKHR(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBeginRenderingKHR(commandBuffer, pRenderingInfo);
}
void Context::PostCmdBeginRenderingKHR(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBeginRenderingKHR(commandBuffer, pRenderingInfo);
}

void Context::PreCmdEndRenderingKHR(VkCommandBuffer commandBuffer) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdEndRenderingKHR(commandBuffer);
}
void Context::PostCmdEndRenderingKHR(VkCommandBuffer commandBuffer) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdEndRenderingKHR(commandBuffer);
}

void Context::PreCmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetDeviceMaskKHR(commandBuffer, deviceMask);
}
void Context::PostCmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetDeviceMaskKHR(commandBuffer, deviceMask);
}

void Context::PreCmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                    uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                    uint32_t groupCountZ) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY,
                                 groupCountZ);
}
void Context::PostCmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                     uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                     uint32_t groupCountZ) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY,
                                  groupCountZ);
}

void Context::PreCmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                         VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount,
                                         const VkWriteDescriptorSet* pDescriptorWrites) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount,
                                      pDescriptorWrites);
}
void Context::PostCmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                          VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount,
                                          const VkWriteDescriptorSet* pDescriptorWrites) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount,
                                       pDescriptorWrites);
}

void Context::PreCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer,
                                                     VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                     VkPipelineLayout layout, uint32_t set, const void* pData) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
}
void Context::PostCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer,
                                                      VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                      VkPipelineLayout layout, uint32_t set, const void* pData) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
}

void Context::PreCmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                        const VkSubpassBeginInfo* pSubpassBeginInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}
void Context::PostCmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                         const VkSubpassBeginInfo* pSubpassBeginInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

void Context::PreCmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                                    const VkSubpassEndInfo* pSubpassEndInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}
void Context::PostCmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                                     const VkSubpassEndInfo* pSubpassEndInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}

void Context::PreCmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);
}
void Context::PostCmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);
}

void Context::PreCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                         VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                         uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount,
                                      stride);
}
void Context::PostCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                          VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                          uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount,
                                       stride);
}

void Context::PreCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                uint32_t maxDrawCount, uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                             maxDrawCount, stride);
}
void Context::PostCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                 VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                 uint32_t maxDrawCount, uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                              maxDrawCount, stride);
}

void Context::PreCmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize,
                                              const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
}
void Context::PostCmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize,
                                               const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
}

void Context::PreCmdSetRenderingAttachmentLocationsKHR(VkCommandBuffer commandBuffer,
                                                       const VkRenderingAttachmentLocationInfoKHR* pLocationInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetRenderingAttachmentLocationsKHR(commandBuffer, pLocationInfo);
}
void Context::PostCmdSetRenderingAttachmentLocationsKHR(VkCommandBuffer commandBuffer,
                                                        const VkRenderingAttachmentLocationInfoKHR* pLocationInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetRenderingAttachmentLocationsKHR(commandBuffer, pLocationInfo);
}

void Context::PreCmdSetRenderingInputAttachmentIndicesKHR(
    VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfoKHR* pInputAttachmentIndexInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetRenderingInputAttachmentIndicesKHR(commandBuffer, pInputAttachmentIndexInfo);
}
void Context::PostCmdSetRenderingInputAttachmentIndicesKHR(
    VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfoKHR* pInputAttachmentIndexInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetRenderingInputAttachmentIndicesKHR(commandBuffer, pInputAttachmentIndexInfo);
}

void Context::PreCmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdEncodeVideoKHR(commandBuffer, pEncodeInfo);
}
void Context::PostCmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdEncodeVideoKHR(commandBuffer, pEncodeInfo);
}

void Context::PreCmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event,
                                 const VkDependencyInfo* pDependencyInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetEvent2KHR(commandBuffer, event, pDependencyInfo);
}
void Context::PostCmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event,
                                  const VkDependencyInfo* pDependencyInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetEvent2KHR(commandBuffer, event, pDependencyInfo);
}

void Context::PreCmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdResetEvent2KHR(commandBuffer, event, stageMask);
}
void Context::PostCmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdResetEvent2KHR(commandBuffer, event, stageMask);
}

void Context::PreCmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                   const VkDependencyInfo* pDependencyInfos) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos);
}
void Context::PostCmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                    const VkDependencyInfo* pDependencyInfos) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos);
}

void Context::PreCmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo);
}
void Context::PostCmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo);
}

void Context::PreCmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                       VkQueryPool queryPool, uint32_t query) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query);
}
void Context::PostCmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                        VkQueryPool queryPool, uint32_t query) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query);
}

void Context::PreCmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                          VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
}
void Context::PostCmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                           VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
}

void Context::PreCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);
}
void Context::PostCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);
}

void Context::PreCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdCopyImage2KHR(commandBuffer, pCopyImageInfo);
}
void Context::PostCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdCopyImage2KHR(commandBuffer, pCopyImageInfo);
}

void Context::PreCmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer,
                                          const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);
}
void Context::PostCmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer,
                                           const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);
}

void Context::PreCmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer,
                                          const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);
}
void Context::PostCmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer,
                                           const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);
}

void Context::PreCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBlitImage2KHR(commandBuffer, pBlitImageInfo);
}
void Context::PostCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBlitImage2KHR(commandBuffer, pBlitImageInfo);
}

void Context::PreCmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdResolveImage2KHR(commandBuffer, pResolveImageInfo);
}
void Context::PostCmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdResolveImage2KHR(commandBuffer, pResolveImageInfo);
}

void Context::PreCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdTraceRaysIndirect2KHR(commandBuffer, indirectDeviceAddress);
}
void Context::PostCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdTraceRaysIndirect2KHR(commandBuffer, indirectDeviceAddress);
}

void Context::PreCmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                        VkDeviceSize size, VkIndexType indexType) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBindIndexBuffer2KHR(commandBuffer, buffer, offset, size, indexType);
}
void Context::PostCmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                         VkDeviceSize size, VkIndexType indexType) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBindIndexBuffer2KHR(commandBuffer, buffer, offset, size, indexType);
}

void Context::PreCmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                      uint16_t lineStipplePattern) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetLineStippleKHR(commandBuffer, lineStippleFactor, lineStipplePattern);
}
void Context::PostCmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                       uint16_t lineStipplePattern) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetLineStippleKHR(commandBuffer, lineStippleFactor, lineStipplePattern);
}

void Context::PreCmdBindDescriptorSets2KHR(VkCommandBuffer commandBuffer,
                                           const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBindDescriptorSets2KHR(commandBuffer, pBindDescriptorSetsInfo);
}
void Context::PostCmdBindDescriptorSets2KHR(VkCommandBuffer commandBuffer,
                                            const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBindDescriptorSets2KHR(commandBuffer, pBindDescriptorSetsInfo);
}

void Context::PreCmdPushConstants2KHR(VkCommandBuffer commandBuffer, const VkPushConstantsInfoKHR* pPushConstantsInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdPushConstants2KHR(commandBuffer, pPushConstantsInfo);
}
void Context::PostCmdPushConstants2KHR(VkCommandBuffer commandBuffer,
                                       const VkPushConstantsInfoKHR* pPushConstantsInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdPushConstants2KHR(commandBuffer, pPushConstantsInfo);
}

void Context::PreCmdPushDescriptorSet2KHR(VkCommandBuffer commandBuffer,
                                          const VkPushDescriptorSetInfoKHR* pPushDescriptorSetInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdPushDescriptorSet2KHR(commandBuffer, pPushDescriptorSetInfo);
}
void Context::PostCmdPushDescriptorSet2KHR(VkCommandBuffer commandBuffer,
                                           const VkPushDescriptorSetInfoKHR* pPushDescriptorSetInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdPushDescriptorSet2KHR(commandBuffer, pPushDescriptorSetInfo);
}

void Context::PreCmdPushDescriptorSetWithTemplate2KHR(
    VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdPushDescriptorSetWithTemplate2KHR(commandBuffer, pPushDescriptorSetWithTemplateInfo);
}
void Context::PostCmdPushDescriptorSetWithTemplate2KHR(
    VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdPushDescriptorSetWithTemplate2KHR(commandBuffer, pPushDescriptorSetWithTemplateInfo);
}

void Context::PreCmdSetDescriptorBufferOffsets2EXT(
    VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetDescriptorBufferOffsets2EXT(commandBuffer, pSetDescriptorBufferOffsetsInfo);
}
void Context::PostCmdSetDescriptorBufferOffsets2EXT(
    VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetDescriptorBufferOffsets2EXT(commandBuffer, pSetDescriptorBufferOffsetsInfo);
}

void Context::PreCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    VkCommandBuffer commandBuffer,
    const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBindDescriptorBufferEmbeddedSamplers2EXT(commandBuffer, pBindDescriptorBufferEmbeddedSamplersInfo);
}
void Context::PostCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    VkCommandBuffer commandBuffer,
    const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBindDescriptorBufferEmbeddedSamplers2EXT(commandBuffer, pBindDescriptorBufferEmbeddedSamplersInfo);
}

void Context::PreCmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
}
void Context::PostCmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
}

void Context::PreCmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDebugMarkerEndEXT(commandBuffer);
}
void Context::PostCmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDebugMarkerEndEXT(commandBuffer);
}

void Context::PreCmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
}
void Context::PostCmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer,
                                          const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
}

void Context::PreCmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                    uint32_t bindingCount, const VkBuffer* pBuffers,
                                                    const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
}
void Context::PostCmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                     uint32_t bindingCount, const VkBuffer* pBuffers,
                                                     const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets,
                                                  pSizes);
}

void Context::PreCmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                              uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                              const VkDeviceSize* pCounterBufferOffsets) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers,
                                           pCounterBufferOffsets);
}
void Context::PostCmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                               uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                               const VkDeviceSize* pCounterBufferOffsets) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers,
                                            pCounterBufferOffsets);
}

void Context::PreCmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                            uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                            const VkDeviceSize* pCounterBufferOffsets) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers,
                                         pCounterBufferOffsets);
}
void Context::PostCmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                             uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                             const VkDeviceSize* pCounterBufferOffsets) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers,
                                          pCounterBufferOffsets);
}

void Context::PreCmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                         VkQueryControlFlags flags, uint32_t index) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
}
void Context::PostCmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                          VkQueryControlFlags flags, uint32_t index) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
}

void Context::PreCmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                       uint32_t index) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
}
void Context::PostCmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                        uint32_t index) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
}

void Context::PreCmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount,
                                             uint32_t firstInstance, VkBuffer counterBuffer,
                                             VkDeviceSize counterBufferOffset, uint32_t counterOffset,
                                             uint32_t vertexStride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer,
                                          counterBufferOffset, counterOffset, vertexStride);
}
void Context::PostCmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount,
                                              uint32_t firstInstance, VkBuffer counterBuffer,
                                              VkDeviceSize counterBufferOffset, uint32_t counterOffset,
                                              uint32_t vertexStride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer,
                                           counterBufferOffset, counterOffset, vertexStride);
}

void Context::PreCmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);
}
void Context::PostCmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);
}

void Context::PreCmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                         VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                         uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount,
                                      stride);
}
void Context::PostCmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                          VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                          uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount,
                                       stride);
}

void Context::PreCmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                uint32_t maxDrawCount, uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                             maxDrawCount, stride);
}
void Context::PostCmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                 VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                 uint32_t maxDrawCount, uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                              maxDrawCount, stride);
}

void Context::PreCmdBeginConditionalRenderingEXT(VkCommandBuffer commandBuffer,
                                                 const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
}
void Context::PostCmdBeginConditionalRenderingEXT(
    VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
}

void Context::PreCmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdEndConditionalRenderingEXT(commandBuffer);
}
void Context::PostCmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdEndConditionalRenderingEXT(commandBuffer);
}

void Context::PreCmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                          const VkViewportWScalingNV* pViewportWScalings) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
}
void Context::PostCmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                           uint32_t viewportCount, const VkViewportWScalingNV* pViewportWScalings) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
}

void Context::PreCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle,
                                           uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount,
                                        pDiscardRectangles);
}
void Context::PostCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle,
                                            uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount,
                                         pDiscardRectangles);
}

void Context::PreCmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable);
}
void Context::PostCmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable);
}

void Context::PreCmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer,
                                               VkDiscardRectangleModeEXT discardRectangleMode) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode);
}
void Context::PostCmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer,
                                                VkDiscardRectangleModeEXT discardRectangleMode) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode);
}

void Context::PreCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}
void Context::PostCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}

void Context::PreCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdEndDebugUtilsLabelEXT(commandBuffer);
}
void Context::PostCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdEndDebugUtilsLabelEXT(commandBuffer);
}

void Context::PreCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}
void Context::PostCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}

#ifdef VK_ENABLE_BETA_EXTENSIONS
void Context::PreCmdInitializeGraphScratchMemoryAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdInitializeGraphScratchMemoryAMDX(commandBuffer, scratch);
}
void Context::PostCmdInitializeGraphScratchMemoryAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdInitializeGraphScratchMemoryAMDX(commandBuffer, scratch);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void Context::PreCmdDispatchGraphAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                      const VkDispatchGraphCountInfoAMDX* pCountInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDispatchGraphAMDX(commandBuffer, scratch, pCountInfo);
}
void Context::PostCmdDispatchGraphAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                       const VkDispatchGraphCountInfoAMDX* pCountInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDispatchGraphAMDX(commandBuffer, scratch, pCountInfo);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void Context::PreCmdDispatchGraphIndirectAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                              const VkDispatchGraphCountInfoAMDX* pCountInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDispatchGraphIndirectAMDX(commandBuffer, scratch, pCountInfo);
}
void Context::PostCmdDispatchGraphIndirectAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                               const VkDispatchGraphCountInfoAMDX* pCountInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDispatchGraphIndirectAMDX(commandBuffer, scratch, pCountInfo);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void Context::PreCmdDispatchGraphIndirectCountAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                                   VkDeviceAddress countInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDispatchGraphIndirectCountAMDX(commandBuffer, scratch, countInfo);
}
void Context::PostCmdDispatchGraphIndirectCountAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                                    VkDeviceAddress countInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDispatchGraphIndirectCountAMDX(commandBuffer, scratch, countInfo);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

void Context::PreCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer,
                                          const VkSampleLocationsInfoEXT* pSampleLocationsInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
}
void Context::PostCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer,
                                           const VkSampleLocationsInfoEXT* pSampleLocationsInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
}

void Context::PreCmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView,
                                           VkImageLayout imageLayout) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
}
void Context::PostCmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView,
                                            VkImageLayout imageLayout) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
}

void Context::PreCmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                                    uint32_t viewportCount,
                                                    const VkShadingRatePaletteNV* pShadingRatePalettes) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
}
void Context::PostCmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                                     uint32_t viewportCount,
                                                     const VkShadingRatePaletteNV* pShadingRatePalettes) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
}

void Context::PreCmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType,
                                           uint32_t customSampleOrderCount,
                                           const VkCoarseSampleOrderCustomNV* pCustomSampleOrders) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
}
void Context::PostCmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType,
                                            uint32_t customSampleOrderCount,
                                            const VkCoarseSampleOrderCustomNV* pCustomSampleOrders) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
}

void Context::PreCmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer,
                                                 const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData,
                                                 VkDeviceSize instanceOffset, VkBool32 update,
                                                 VkAccelerationStructureNV dst, VkAccelerationStructureNV src,
                                                 VkBuffer scratch, VkDeviceSize scratchOffset) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src,
                                              scratch, scratchOffset);
}
void Context::PostCmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer,
                                                  const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData,
                                                  VkDeviceSize instanceOffset, VkBool32 update,
                                                  VkAccelerationStructureNV dst, VkAccelerationStructureNV src,
                                                  VkBuffer scratch, VkDeviceSize scratchOffset) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src,
                                               scratch, scratchOffset);
}

void Context::PreCmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst,
                                                VkAccelerationStructureNV src,
                                                VkCopyAccelerationStructureModeKHR mode) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
}
void Context::PostCmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst,
                                                 VkAccelerationStructureNV src,
                                                 VkCopyAccelerationStructureModeKHR mode) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
}

void Context::PreCmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer,
                                VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer,
                                VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride,
                                VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset,
                                VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer,
                                VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride,
                                uint32_t width, uint32_t height, uint32_t depth) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdTraceRaysNV(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset,
                             missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride,
                             hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride,
                             callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride,
                             width, height, depth);
}
void Context::PostCmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer,
                                 VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer,
                                 VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride,
                                 VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset,
                                 VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer,
                                 VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride,
                                 uint32_t width, uint32_t height, uint32_t depth) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdTraceRaysNV(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset,
                              missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride,
                              hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride,
                              callableShaderBindingTableBuffer, callableShaderBindingOffset,
                              callableShaderBindingStride, width, height, depth);
}

void Context::PreCmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer,
                                                            uint32_t accelerationStructureCount,
                                                            const VkAccelerationStructureNV* pAccelerationStructures,
                                                            VkQueryType queryType, VkQueryPool queryPool,
                                                            uint32_t firstQuery) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdWriteAccelerationStructuresPropertiesNV(commandBuffer, accelerationStructureCount,
                                                         pAccelerationStructures, queryType, queryPool, firstQuery);
}
void Context::PostCmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer,
                                                             uint32_t accelerationStructureCount,
                                                             const VkAccelerationStructureNV* pAccelerationStructures,
                                                             VkQueryType queryType, VkQueryPool queryPool,
                                                             uint32_t firstQuery) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdWriteAccelerationStructuresPropertiesNV(commandBuffer, accelerationStructureCount,
                                                          pAccelerationStructures, queryType, queryPool, firstQuery);
}

void Context::PreCmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                         VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
}
void Context::PostCmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                          VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
}

void Context::PreCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
}
void Context::PostCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
}

void Context::PreCmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                            uint32_t drawCount, uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
}
void Context::PostCmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                             uint32_t drawCount, uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
}

void Context::PreCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                 VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                 uint32_t maxDrawCount, uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                              maxDrawCount, stride);
}
void Context::PostCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                  VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                  uint32_t maxDrawCount, uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                               maxDrawCount, stride);
}

void Context::PreCmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                                uint32_t exclusiveScissorCount,
                                                const VkBool32* pExclusiveScissorEnables) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetExclusiveScissorEnableNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount,
                                             pExclusiveScissorEnables);
}
void Context::PostCmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                                 uint32_t exclusiveScissorCount,
                                                 const VkBool32* pExclusiveScissorEnables) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetExclusiveScissorEnableNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount,
                                              pExclusiveScissorEnables);
}

void Context::PreCmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                          uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
}
void Context::PostCmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                           uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount,
                                        pExclusiveScissors);
}

void Context::PreCmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
}
void Context::PostCmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
}

VkResult Context::PreCmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer,
                                                  const VkPerformanceMarkerInfoINTEL* pMarkerInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    return p_cmd->PreCmdSetPerformanceMarkerINTEL(commandBuffer, pMarkerInfo);
}
VkResult Context::PostCmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer,
                                                   const VkPerformanceMarkerInfoINTEL* pMarkerInfo, VkResult result) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    return p_cmd->PostCmdSetPerformanceMarkerINTEL(commandBuffer, pMarkerInfo, result);
}

VkResult Context::PreCmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer,
                                                        const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    return p_cmd->PreCmdSetPerformanceStreamMarkerINTEL(commandBuffer, pMarkerInfo);
}
VkResult Context::PostCmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer,
                                                         const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo,
                                                         VkResult result) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    return p_cmd->PostCmdSetPerformanceStreamMarkerINTEL(commandBuffer, pMarkerInfo, result);
}

VkResult Context::PreCmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer,
                                                    const VkPerformanceOverrideInfoINTEL* pOverrideInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    return p_cmd->PreCmdSetPerformanceOverrideINTEL(commandBuffer, pOverrideInfo);
}
VkResult Context::PostCmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer,
                                                     const VkPerformanceOverrideInfoINTEL* pOverrideInfo,
                                                     VkResult result) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    return p_cmd->PostCmdSetPerformanceOverrideINTEL(commandBuffer, pOverrideInfo, result);
}

void Context::PreCmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                      uint16_t lineStipplePattern) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
}
void Context::PostCmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                       uint16_t lineStipplePattern) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
}

void Context::PreCmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetCullModeEXT(commandBuffer, cullMode);
}
void Context::PostCmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetCullModeEXT(commandBuffer, cullMode);
}

void Context::PreCmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetFrontFaceEXT(commandBuffer, frontFace);
}
void Context::PostCmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetFrontFaceEXT(commandBuffer, frontFace);
}

void Context::PreCmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);
}
void Context::PostCmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);
}

void Context::PreCmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                            const VkViewport* pViewports) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);
}
void Context::PostCmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                             const VkViewport* pViewports) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);
}

void Context::PreCmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                           const VkRect2D* pScissors) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);
}
void Context::PostCmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                            const VkRect2D* pScissors) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);
}

void Context::PreCmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                          const VkBuffer* pBuffers, const VkDeviceSize* pOffsets,
                                          const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}
void Context::PostCmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                           const VkBuffer* pBuffers, const VkDeviceSize* pOffsets,
                                           const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes,
                                        pStrides);
}

void Context::PreCmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);
}
void Context::PostCmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);
}

void Context::PreCmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);
}
void Context::PostCmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);
}

void Context::PreCmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);
}
void Context::PostCmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);
}

void Context::PreCmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);
}
void Context::PostCmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);
}

void Context::PreCmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);
}
void Context::PostCmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);
}

void Context::PreCmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                    VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}
void Context::PostCmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                     VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}

void Context::PreCmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer,
                                                  const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);
}
void Context::PostCmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer,
                                                   const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);
}

void Context::PreCmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                               const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
}
void Context::PostCmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                                const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
}

void Context::PreCmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                              VkPipeline pipeline, uint32_t groupIndex) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
}
void Context::PostCmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                               VkPipeline pipeline, uint32_t groupIndex) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
}

void Context::PreCmdSetDepthBias2EXT(VkCommandBuffer commandBuffer, const VkDepthBiasInfoEXT* pDepthBiasInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetDepthBias2EXT(commandBuffer, pDepthBiasInfo);
}
void Context::PostCmdSetDepthBias2EXT(VkCommandBuffer commandBuffer, const VkDepthBiasInfoEXT* pDepthBiasInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetDepthBias2EXT(commandBuffer, pDepthBiasInfo);
}

void Context::PreCmdCudaLaunchKernelNV(VkCommandBuffer commandBuffer, const VkCudaLaunchInfoNV* pLaunchInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdCudaLaunchKernelNV(commandBuffer, pLaunchInfo);
}
void Context::PostCmdCudaLaunchKernelNV(VkCommandBuffer commandBuffer, const VkCudaLaunchInfoNV* pLaunchInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdCudaLaunchKernelNV(commandBuffer, pLaunchInfo);
}

void Context::PreCmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount,
                                             const VkDescriptorBufferBindingInfoEXT* pBindingInfos) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBindDescriptorBuffersEXT(commandBuffer, bufferCount, pBindingInfos);
}
void Context::PostCmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount,
                                              const VkDescriptorBufferBindingInfoEXT* pBindingInfos) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBindDescriptorBuffersEXT(commandBuffer, bufferCount, pBindingInfos);
}

void Context::PreCmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                  VkPipelineLayout layout, uint32_t firstSet, uint32_t setCount,
                                                  const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetDescriptorBufferOffsetsEXT(commandBuffer, pipelineBindPoint, layout, firstSet, setCount,
                                               pBufferIndices, pOffsets);
}
void Context::PostCmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                   VkPipelineLayout layout, uint32_t firstSet, uint32_t setCount,
                                                   const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetDescriptorBufferOffsetsEXT(commandBuffer, pipelineBindPoint, layout, firstSet, setCount,
                                                pBufferIndices, pOffsets);
}

void Context::PreCmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer commandBuffer,
                                                            VkPipelineBindPoint pipelineBindPoint,
                                                            VkPipelineLayout layout, uint32_t set) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBindDescriptorBufferEmbeddedSamplersEXT(commandBuffer, pipelineBindPoint, layout, set);
}
void Context::PostCmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer commandBuffer,
                                                             VkPipelineBindPoint pipelineBindPoint,
                                                             VkPipelineLayout layout, uint32_t set) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBindDescriptorBufferEmbeddedSamplersEXT(commandBuffer, pipelineBindPoint, layout, set);
}

void Context::PreCmdSetFragmentShadingRateEnumNV(VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate,
                                                 const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);
}
void Context::PostCmdSetFragmentShadingRateEnumNV(VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate,
                                                  const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);
}

void Context::PreCmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
                                      const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions,
                                      uint32_t vertexAttributeDescriptionCount,
                                      const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions,
                                   vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
}
void Context::PostCmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
                                       const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions,
                                       uint32_t vertexAttributeDescriptionCount,
                                       const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions,
                                    vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
}

void Context::PreCmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSubpassShadingHUAWEI(commandBuffer);
}
void Context::PostCmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSubpassShadingHUAWEI(commandBuffer);
}

void Context::PreCmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer, VkImageView imageView,
                                             VkImageLayout imageLayout) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBindInvocationMaskHUAWEI(commandBuffer, imageView, imageLayout);
}
void Context::PostCmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer, VkImageView imageView,
                                              VkImageLayout imageLayout) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBindInvocationMaskHUAWEI(commandBuffer, imageView, imageLayout);
}

void Context::PreCmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
}
void Context::PostCmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
}

void Context::PreCmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable);
}
void Context::PostCmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable);
}

void Context::PreCmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable);
}
void Context::PostCmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable);
}

void Context::PreCmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetLogicOpEXT(commandBuffer, logicOp);
}
void Context::PostCmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetLogicOpEXT(commandBuffer, logicOp);
}

void Context::PreCmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable);
}
void Context::PostCmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable);
}

void Context::PreCmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                           const VkBool32* pColorWriteEnables) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
}
void Context::PostCmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                            const VkBool32* pColorWriteEnables) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
}

void Context::PreCmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                 const VkMultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount, uint32_t firstInstance,
                                 uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDrawMultiEXT(commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
}
void Context::PostCmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                  const VkMultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount, uint32_t firstInstance,
                                  uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDrawMultiEXT(commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
}

void Context::PreCmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                        const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount,
                                        uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDrawMultiIndexedEXT(commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride,
                                     pVertexOffset);
}
void Context::PostCmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                         const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount,
                                         uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDrawMultiIndexedEXT(commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride,
                                      pVertexOffset);
}

void Context::PreCmdBuildMicromapsEXT(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                      const VkMicromapBuildInfoEXT* pInfos) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBuildMicromapsEXT(commandBuffer, infoCount, pInfos);
}
void Context::PostCmdBuildMicromapsEXT(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                       const VkMicromapBuildInfoEXT* pInfos) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBuildMicromapsEXT(commandBuffer, infoCount, pInfos);
}

void Context::PreCmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdCopyMicromapEXT(commandBuffer, pInfo);
}
void Context::PostCmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdCopyMicromapEXT(commandBuffer, pInfo);
}

void Context::PreCmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdCopyMicromapToMemoryEXT(commandBuffer, pInfo);
}
void Context::PostCmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer,
                                             const VkCopyMicromapToMemoryInfoEXT* pInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdCopyMicromapToMemoryEXT(commandBuffer, pInfo);
}

void Context::PreCmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdCopyMemoryToMicromapEXT(commandBuffer, pInfo);
}
void Context::PostCmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer,
                                             const VkCopyMemoryToMicromapInfoEXT* pInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdCopyMemoryToMicromapEXT(commandBuffer, pInfo);
}

void Context::PreCmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount,
                                                const VkMicromapEXT* pMicromaps, VkQueryType queryType,
                                                VkQueryPool queryPool, uint32_t firstQuery) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdWriteMicromapsPropertiesEXT(commandBuffer, micromapCount, pMicromaps, queryType, queryPool,
                                             firstQuery);
}
void Context::PostCmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount,
                                                 const VkMicromapEXT* pMicromaps, VkQueryType queryType,
                                                 VkQueryPool queryPool, uint32_t firstQuery) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdWriteMicromapsPropertiesEXT(commandBuffer, micromapCount, pMicromaps, queryType, queryPool,
                                              firstQuery);
}

void Context::PreCmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                      uint32_t groupCountZ) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDrawClusterHUAWEI(commandBuffer, groupCountX, groupCountY, groupCountZ);
}
void Context::PostCmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                       uint32_t groupCountZ) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDrawClusterHUAWEI(commandBuffer, groupCountX, groupCountY, groupCountZ);
}

void Context::PreCmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDrawClusterIndirectHUAWEI(commandBuffer, buffer, offset);
}
void Context::PostCmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDrawClusterIndirectHUAWEI(commandBuffer, buffer, offset);
}

void Context::PreCmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                         uint32_t copyCount, uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdCopyMemoryIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride);
}
void Context::PostCmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                          uint32_t copyCount, uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdCopyMemoryIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride);
}

void Context::PreCmdCopyMemoryToImageIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                                uint32_t copyCount, uint32_t stride, VkImage dstImage,
                                                VkImageLayout dstImageLayout,
                                                const VkImageSubresourceLayers* pImageSubresources) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdCopyMemoryToImageIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride, dstImage,
                                             dstImageLayout, pImageSubresources);
}
void Context::PostCmdCopyMemoryToImageIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                                 uint32_t copyCount, uint32_t stride, VkImage dstImage,
                                                 VkImageLayout dstImageLayout,
                                                 const VkImageSubresourceLayers* pImageSubresources) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdCopyMemoryToImageIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride, dstImage,
                                              dstImageLayout, pImageSubresources);
}

void Context::PreCmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount,
                                       const VkDecompressMemoryRegionNV* pDecompressMemoryRegions) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDecompressMemoryNV(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
}
void Context::PostCmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount,
                                        const VkDecompressMemoryRegionNV* pDecompressMemoryRegions) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDecompressMemoryNV(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
}

void Context::PreCmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer,
                                                    VkDeviceAddress indirectCommandsAddress,
                                                    VkDeviceAddress indirectCommandsCountAddress, uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDecompressMemoryIndirectCountNV(commandBuffer, indirectCommandsAddress, indirectCommandsCountAddress,
                                                 stride);
}
void Context::PostCmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer,
                                                     VkDeviceAddress indirectCommandsAddress,
                                                     VkDeviceAddress indirectCommandsCountAddress, uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDecompressMemoryIndirectCountNV(commandBuffer, indirectCommandsAddress, indirectCommandsCountAddress,
                                                  stride);
}

void Context::PreCmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                   VkPipeline pipeline) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdUpdatePipelineIndirectBufferNV(commandBuffer, pipelineBindPoint, pipeline);
}
void Context::PostCmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer,
                                                    VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdUpdatePipelineIndirectBufferNV(commandBuffer, pipelineBindPoint, pipeline);
}

void Context::PreCmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClampEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetDepthClampEnableEXT(commandBuffer, depthClampEnable);
}
void Context::PostCmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClampEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetDepthClampEnableEXT(commandBuffer, depthClampEnable);
}

void Context::PreCmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetPolygonModeEXT(commandBuffer, polygonMode);
}
void Context::PostCmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetPolygonModeEXT(commandBuffer, polygonMode);
}

void Context::PreCmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer,
                                               VkSampleCountFlagBits rasterizationSamples) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetRasterizationSamplesEXT(commandBuffer, rasterizationSamples);
}
void Context::PostCmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer,
                                                VkSampleCountFlagBits rasterizationSamples) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetRasterizationSamplesEXT(commandBuffer, rasterizationSamples);
}

void Context::PreCmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples,
                                     const VkSampleMask* pSampleMask) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetSampleMaskEXT(commandBuffer, samples, pSampleMask);
}
void Context::PostCmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples,
                                      const VkSampleMask* pSampleMask) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetSampleMaskEXT(commandBuffer, samples, pSampleMask);
}

void Context::PreCmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetAlphaToCoverageEnableEXT(commandBuffer, alphaToCoverageEnable);
}
void Context::PostCmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetAlphaToCoverageEnableEXT(commandBuffer, alphaToCoverageEnable);
}

void Context::PreCmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetAlphaToOneEnableEXT(commandBuffer, alphaToOneEnable);
}
void Context::PostCmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetAlphaToOneEnableEXT(commandBuffer, alphaToOneEnable);
}

void Context::PreCmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetLogicOpEnableEXT(commandBuffer, logicOpEnable);
}
void Context::PostCmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetLogicOpEnableEXT(commandBuffer, logicOpEnable);
}

void Context::PreCmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                           uint32_t attachmentCount, const VkBool32* pColorBlendEnables) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetColorBlendEnableEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
}
void Context::PostCmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                            uint32_t attachmentCount, const VkBool32* pColorBlendEnables) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetColorBlendEnableEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
}

void Context::PreCmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                             uint32_t attachmentCount,
                                             const VkColorBlendEquationEXT* pColorBlendEquations) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetColorBlendEquationEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
}
void Context::PostCmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                              uint32_t attachmentCount,
                                              const VkColorBlendEquationEXT* pColorBlendEquations) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetColorBlendEquationEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
}

void Context::PreCmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                         uint32_t attachmentCount, const VkColorComponentFlags* pColorWriteMasks) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetColorWriteMaskEXT(commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
}
void Context::PostCmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                          uint32_t attachmentCount, const VkColorComponentFlags* pColorWriteMasks) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetColorWriteMaskEXT(commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
}

void Context::PreCmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer,
                                                   VkTessellationDomainOrigin domainOrigin) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetTessellationDomainOriginEXT(commandBuffer, domainOrigin);
}
void Context::PostCmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer,
                                                    VkTessellationDomainOrigin domainOrigin) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetTessellationDomainOriginEXT(commandBuffer, domainOrigin);
}

void Context::PreCmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer, uint32_t rasterizationStream) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetRasterizationStreamEXT(commandBuffer, rasterizationStream);
}
void Context::PostCmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer, uint32_t rasterizationStream) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetRasterizationStreamEXT(commandBuffer, rasterizationStream);
}

void Context::PreCmdSetConservativeRasterizationModeEXT(
    VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetConservativeRasterizationModeEXT(commandBuffer, conservativeRasterizationMode);
}
void Context::PostCmdSetConservativeRasterizationModeEXT(
    VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetConservativeRasterizationModeEXT(commandBuffer, conservativeRasterizationMode);
}

void Context::PreCmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer commandBuffer,
                                                           float extraPrimitiveOverestimationSize) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetExtraPrimitiveOverestimationSizeEXT(commandBuffer, extraPrimitiveOverestimationSize);
}
void Context::PostCmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer commandBuffer,
                                                            float extraPrimitiveOverestimationSize) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetExtraPrimitiveOverestimationSizeEXT(commandBuffer, extraPrimitiveOverestimationSize);
}

void Context::PreCmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClipEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetDepthClipEnableEXT(commandBuffer, depthClipEnable);
}
void Context::PostCmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClipEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetDepthClipEnableEXT(commandBuffer, depthClipEnable);
}

void Context::PreCmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetSampleLocationsEnableEXT(commandBuffer, sampleLocationsEnable);
}
void Context::PostCmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetSampleLocationsEnableEXT(commandBuffer, sampleLocationsEnable);
}

void Context::PreCmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                             uint32_t attachmentCount,
                                             const VkColorBlendAdvancedEXT* pColorBlendAdvanced) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetColorBlendAdvancedEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
}
void Context::PostCmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                              uint32_t attachmentCount,
                                              const VkColorBlendAdvancedEXT* pColorBlendAdvanced) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetColorBlendAdvancedEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
}

void Context::PreCmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer,
                                              VkProvokingVertexModeEXT provokingVertexMode) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetProvokingVertexModeEXT(commandBuffer, provokingVertexMode);
}
void Context::PostCmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer,
                                               VkProvokingVertexModeEXT provokingVertexMode) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetProvokingVertexModeEXT(commandBuffer, provokingVertexMode);
}

void Context::PreCmdSetLineRasterizationModeEXT(VkCommandBuffer commandBuffer,
                                                VkLineRasterizationModeEXT lineRasterizationMode) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetLineRasterizationModeEXT(commandBuffer, lineRasterizationMode);
}
void Context::PostCmdSetLineRasterizationModeEXT(VkCommandBuffer commandBuffer,
                                                 VkLineRasterizationModeEXT lineRasterizationMode) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetLineRasterizationModeEXT(commandBuffer, lineRasterizationMode);
}

void Context::PreCmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetLineStippleEnableEXT(commandBuffer, stippledLineEnable);
}
void Context::PostCmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetLineStippleEnableEXT(commandBuffer, stippledLineEnable);
}

void Context::PreCmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetDepthClipNegativeOneToOneEXT(commandBuffer, negativeOneToOne);
}
void Context::PostCmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetDepthClipNegativeOneToOneEXT(commandBuffer, negativeOneToOne);
}

void Context::PreCmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetViewportWScalingEnableNV(commandBuffer, viewportWScalingEnable);
}
void Context::PostCmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetViewportWScalingEnableNV(commandBuffer, viewportWScalingEnable);
}

void Context::PreCmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                         const VkViewportSwizzleNV* pViewportSwizzles) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetViewportSwizzleNV(commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
}
void Context::PostCmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                          const VkViewportSwizzleNV* pViewportSwizzles) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetViewportSwizzleNV(commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
}

void Context::PreCmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetCoverageToColorEnableNV(commandBuffer, coverageToColorEnable);
}
void Context::PostCmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetCoverageToColorEnableNV(commandBuffer, coverageToColorEnable);
}

void Context::PreCmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetCoverageToColorLocationNV(commandBuffer, coverageToColorLocation);
}
void Context::PostCmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetCoverageToColorLocationNV(commandBuffer, coverageToColorLocation);
}

void Context::PreCmdSetCoverageModulationModeNV(VkCommandBuffer commandBuffer,
                                                VkCoverageModulationModeNV coverageModulationMode) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetCoverageModulationModeNV(commandBuffer, coverageModulationMode);
}
void Context::PostCmdSetCoverageModulationModeNV(VkCommandBuffer commandBuffer,
                                                 VkCoverageModulationModeNV coverageModulationMode) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetCoverageModulationModeNV(commandBuffer, coverageModulationMode);
}

void Context::PreCmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer,
                                                       VkBool32 coverageModulationTableEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetCoverageModulationTableEnableNV(commandBuffer, coverageModulationTableEnable);
}
void Context::PostCmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer,
                                                        VkBool32 coverageModulationTableEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetCoverageModulationTableEnableNV(commandBuffer, coverageModulationTableEnable);
}

void Context::PreCmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount,
                                                 const float* pCoverageModulationTable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetCoverageModulationTableNV(commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
}
void Context::PostCmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount,
                                                  const float* pCoverageModulationTable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetCoverageModulationTableNV(commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
}

void Context::PreCmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetShadingRateImageEnableNV(commandBuffer, shadingRateImageEnable);
}
void Context::PostCmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetShadingRateImageEnableNV(commandBuffer, shadingRateImageEnable);
}

void Context::PreCmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer commandBuffer,
                                                          VkBool32 representativeFragmentTestEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetRepresentativeFragmentTestEnableNV(commandBuffer, representativeFragmentTestEnable);
}
void Context::PostCmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer commandBuffer,
                                                           VkBool32 representativeFragmentTestEnable) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetRepresentativeFragmentTestEnableNV(commandBuffer, representativeFragmentTestEnable);
}

void Context::PreCmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer,
                                               VkCoverageReductionModeNV coverageReductionMode) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetCoverageReductionModeNV(commandBuffer, coverageReductionMode);
}
void Context::PostCmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer,
                                                VkCoverageReductionModeNV coverageReductionMode) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetCoverageReductionModeNV(commandBuffer, coverageReductionMode);
}

void Context::PreCmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session,
                                         const VkOpticalFlowExecuteInfoNV* pExecuteInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdOpticalFlowExecuteNV(commandBuffer, session, pExecuteInfo);
}
void Context::PostCmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session,
                                          const VkOpticalFlowExecuteInfoNV* pExecuteInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdOpticalFlowExecuteNV(commandBuffer, session, pExecuteInfo);
}

void Context::PreCmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount,
                                   const VkShaderStageFlagBits* pStages, const VkShaderEXT* pShaders) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBindShadersEXT(commandBuffer, stageCount, pStages, pShaders);
}
void Context::PostCmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount,
                                    const VkShaderStageFlagBits* pStages, const VkShaderEXT* pShaders) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBindShadersEXT(commandBuffer, stageCount, pStages, pShaders);
}

void Context::PreCmdSetDepthClampRangeEXT(VkCommandBuffer commandBuffer, VkDepthClampModeEXT depthClampMode,
                                          const VkDepthClampRangeEXT* pDepthClampRange) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetDepthClampRangeEXT(commandBuffer, depthClampMode, pDepthClampRange);
}
void Context::PostCmdSetDepthClampRangeEXT(VkCommandBuffer commandBuffer, VkDepthClampModeEXT depthClampMode,
                                           const VkDepthClampRangeEXT* pDepthClampRange) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetDepthClampRangeEXT(commandBuffer, depthClampMode, pDepthClampRange);
}

void Context::PreCmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer, VkImageAspectFlags aspectMask) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetAttachmentFeedbackLoopEnableEXT(commandBuffer, aspectMask);
}
void Context::PostCmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer, VkImageAspectFlags aspectMask) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetAttachmentFeedbackLoopEnableEXT(commandBuffer, aspectMask);
}

void Context::PreCmdPreprocessGeneratedCommandsEXT(VkCommandBuffer commandBuffer,
                                                   const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo,
                                                   VkCommandBuffer stateCommandBuffer) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdPreprocessGeneratedCommandsEXT(commandBuffer, pGeneratedCommandsInfo, stateCommandBuffer);
}
void Context::PostCmdPreprocessGeneratedCommandsEXT(VkCommandBuffer commandBuffer,
                                                    const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo,
                                                    VkCommandBuffer stateCommandBuffer) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdPreprocessGeneratedCommandsEXT(commandBuffer, pGeneratedCommandsInfo, stateCommandBuffer);
}

void Context::PreCmdExecuteGeneratedCommandsEXT(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                                const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdExecuteGeneratedCommandsEXT(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
}
void Context::PostCmdExecuteGeneratedCommandsEXT(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                                 const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdExecuteGeneratedCommandsEXT(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
}

void Context::PreCmdBuildAccelerationStructuresKHR(
    VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
}
void Context::PostCmdBuildAccelerationStructuresKHR(
    VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
}

void Context::PreCmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                                           const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
                                                           const VkDeviceAddress* pIndirectDeviceAddresses,
                                                           const uint32_t* pIndirectStrides,
                                                           const uint32_t* const* ppMaxPrimitiveCounts) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdBuildAccelerationStructuresIndirectKHR(commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses,
                                                        pIndirectStrides, ppMaxPrimitiveCounts);
}
void Context::PostCmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                                            const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
                                                            const VkDeviceAddress* pIndirectDeviceAddresses,
                                                            const uint32_t* pIndirectStrides,
                                                            const uint32_t* const* ppMaxPrimitiveCounts) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdBuildAccelerationStructuresIndirectKHR(commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses,
                                                         pIndirectStrides, ppMaxPrimitiveCounts);
}

void Context::PreCmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                                 const VkCopyAccelerationStructureInfoKHR* pInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdCopyAccelerationStructureKHR(commandBuffer, pInfo);
}
void Context::PostCmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                                  const VkCopyAccelerationStructureInfoKHR* pInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdCopyAccelerationStructureKHR(commandBuffer, pInfo);
}

void Context::PreCmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer commandBuffer,
                                                         const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);
}
void Context::PostCmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer commandBuffer,
                                                          const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);
}

void Context::PreCmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                                         const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);
}
void Context::PostCmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                                          const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);
}

void Context::PreCmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer commandBuffer,
                                                             uint32_t accelerationStructureCount,
                                                             const VkAccelerationStructureKHR* pAccelerationStructures,
                                                             VkQueryType queryType, VkQueryPool queryPool,
                                                             uint32_t firstQuery) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdWriteAccelerationStructuresPropertiesKHR(commandBuffer, accelerationStructureCount,
                                                          pAccelerationStructures, queryType, queryPool, firstQuery);
}
void Context::PostCmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer commandBuffer,
                                                              uint32_t accelerationStructureCount,
                                                              const VkAccelerationStructureKHR* pAccelerationStructures,
                                                              VkQueryType queryType, VkQueryPool queryPool,
                                                              uint32_t firstQuery) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdWriteAccelerationStructuresPropertiesKHR(commandBuffer, accelerationStructureCount,
                                                           pAccelerationStructures, queryType, queryPool, firstQuery);
}

void Context::PreCmdTraceRaysKHR(VkCommandBuffer commandBuffer,
                                 const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                 const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                 const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                 const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width,
                                 uint32_t height, uint32_t depth) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdTraceRaysKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable,
                              pCallableShaderBindingTable, width, height, depth);
}
void Context::PostCmdTraceRaysKHR(VkCommandBuffer commandBuffer,
                                  const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                  const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                  const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                  const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width,
                                  uint32_t height, uint32_t depth) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdTraceRaysKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable,
                               pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
}

void Context::PreCmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer,
                                         const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                         const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                         const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                         const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                         VkDeviceAddress indirectDeviceAddress) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdTraceRaysIndirectKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable,
                                      pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
}
void Context::PostCmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer,
                                          const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                          const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                          const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                          const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                          VkDeviceAddress indirectDeviceAddress) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdTraceRaysIndirectKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable,
                                       pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
}

void Context::PreCmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);
}
void Context::PostCmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);
}

void Context::PreCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                     uint32_t groupCountZ) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDrawMeshTasksEXT(commandBuffer, groupCountX, groupCountY, groupCountZ);
}
void Context::PostCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                      uint32_t groupCountZ) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDrawMeshTasksEXT(commandBuffer, groupCountX, groupCountY, groupCountZ);
}

void Context::PreCmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                             uint32_t drawCount, uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDrawMeshTasksIndirectEXT(commandBuffer, buffer, offset, drawCount, stride);
}
void Context::PostCmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                              uint32_t drawCount, uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDrawMeshTasksIndirectEXT(commandBuffer, buffer, offset, drawCount, stride);
}

void Context::PreCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                  VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                  uint32_t maxDrawCount, uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PreCmdDrawMeshTasksIndirectCountEXT(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                               maxDrawCount, stride);
}
void Context::PostCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                   VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                   uint32_t maxDrawCount, uint32_t stride) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    p_cmd->PostCmdDrawMeshTasksIndirectCountEXT(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                                maxDrawCount, stride);
}

// NOLINTEND
