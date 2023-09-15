
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

VkResult GfrContext::PostBeginCommandBuffer(
    VkCommandBuffer                             commandBuffer,
    const VkCommandBufferBeginInfo*             pBeginInfo,
    VkResult                                    result) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  return p_cmd->PostBeginCommandBuffer(commandBuffer, pBeginInfo, result);
}

VkResult GfrContext::PreEndCommandBuffer(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  return p_cmd->PreEndCommandBuffer(commandBuffer);
}
VkResult GfrContext::PostEndCommandBuffer(
    VkCommandBuffer                             commandBuffer,
    VkResult                                    result) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  return p_cmd->PostEndCommandBuffer(commandBuffer, result);
}

VkResult GfrContext::PostResetCommandBuffer(
    VkCommandBuffer                             commandBuffer,
    VkCommandBufferResetFlags                   flags,
    VkResult                                    result) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  return p_cmd->PostResetCommandBuffer(commandBuffer, flags, result);
}

void GfrContext::PostCmdBindPipeline(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
}

void GfrContext::PreCmdSetViewport(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
}
void GfrContext::PostCmdSetViewport(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
}

void GfrContext::PreCmdSetScissor(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
}
void GfrContext::PostCmdSetScissor(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
}

void GfrContext::PreCmdSetLineWidth(
    VkCommandBuffer                             commandBuffer,
    float                                       lineWidth) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetLineWidth(commandBuffer, lineWidth);
}
void GfrContext::PostCmdSetLineWidth(
    VkCommandBuffer                             commandBuffer,
    float                                       lineWidth) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetLineWidth(commandBuffer, lineWidth);
}

void GfrContext::PreCmdSetDepthBias(
    VkCommandBuffer                             commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
}
void GfrContext::PostCmdSetDepthBias(
    VkCommandBuffer                             commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
}

void GfrContext::PreCmdSetBlendConstants(
    VkCommandBuffer                             commandBuffer,
    const float                                 blendConstants[4]) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetBlendConstants(commandBuffer, blendConstants);
}
void GfrContext::PostCmdSetBlendConstants(
    VkCommandBuffer                             commandBuffer,
    const float                                 blendConstants[4]) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetBlendConstants(commandBuffer, blendConstants);
}

void GfrContext::PreCmdSetDepthBounds(
    VkCommandBuffer                             commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
}
void GfrContext::PostCmdSetDepthBounds(
    VkCommandBuffer                             commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
}

void GfrContext::PreCmdSetStencilCompareMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
}
void GfrContext::PostCmdSetStencilCompareMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
}

void GfrContext::PreCmdSetStencilWriteMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
}
void GfrContext::PostCmdSetStencilWriteMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
}

void GfrContext::PreCmdSetStencilReference(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetStencilReference(commandBuffer, faceMask, reference);
}
void GfrContext::PostCmdSetStencilReference(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetStencilReference(commandBuffer, faceMask, reference);
}

void GfrContext::PreCmdBindDescriptorSets(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    descriptorSetCount,
    const VkDescriptorSet*                      pDescriptorSets,
    uint32_t                                    dynamicOffsetCount,
    const uint32_t*                             pDynamicOffsets) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
}
void GfrContext::PostCmdBindDescriptorSets(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    descriptorSetCount,
    const VkDescriptorSet*                      pDescriptorSets,
    uint32_t                                    dynamicOffsetCount,
    const uint32_t*                             pDynamicOffsets) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
}

void GfrContext::PreCmdBindIndexBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
}
void GfrContext::PostCmdBindIndexBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
}

void GfrContext::PreCmdBindVertexBuffers(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
}
void GfrContext::PostCmdBindVertexBuffers(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
}

void GfrContext::PreCmdDraw(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}
void GfrContext::PostCmdDraw(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}

void GfrContext::PreCmdDrawIndexed(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}
void GfrContext::PostCmdDrawIndexed(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}

void GfrContext::PreCmdDrawIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
}
void GfrContext::PostCmdDrawIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
}

void GfrContext::PreCmdDrawIndexedIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
}
void GfrContext::PostCmdDrawIndexedIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
}

void GfrContext::PreCmdDispatch(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
}
void GfrContext::PostCmdDispatch(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
}

void GfrContext::PreCmdDispatchIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDispatchIndirect(commandBuffer, buffer, offset);
}
void GfrContext::PostCmdDispatchIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDispatchIndirect(commandBuffer, buffer, offset);
}

void GfrContext::PreCmdCopyBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferCopy*                         pRegions) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
}
void GfrContext::PostCmdCopyBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferCopy*                         pRegions) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
}

void GfrContext::PreCmdCopyImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageCopy*                          pRegions) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}
void GfrContext::PostCmdCopyImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageCopy*                          pRegions) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}

void GfrContext::PreCmdBlitImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageBlit*                          pRegions,
    VkFilter                                    filter) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
}
void GfrContext::PostCmdBlitImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageBlit*                          pRegions,
    VkFilter                                    filter) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
}

void GfrContext::PreCmdCopyBufferToImage(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
}
void GfrContext::PostCmdCopyBufferToImage(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
}

void GfrContext::PreCmdCopyImageToBuffer(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
}
void GfrContext::PostCmdCopyImageToBuffer(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
}

void GfrContext::PreCmdUpdateBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    const void*                                 pData) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
}
void GfrContext::PostCmdUpdateBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    const void*                                 pData) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
}

void GfrContext::PreCmdFillBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
}
void GfrContext::PostCmdFillBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
}

void GfrContext::PreCmdClearColorImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearColorValue*                    pColor,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
}
void GfrContext::PostCmdClearColorImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearColorValue*                    pColor,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
}

void GfrContext::PreCmdClearDepthStencilImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearDepthStencilValue*             pDepthStencil,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
}
void GfrContext::PostCmdClearDepthStencilImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearDepthStencilValue*             pDepthStencil,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
}

void GfrContext::PreCmdClearAttachments(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkClearAttachment*                    pAttachments,
    uint32_t                                    rectCount,
    const VkClearRect*                          pRects) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
}
void GfrContext::PostCmdClearAttachments(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkClearAttachment*                    pAttachments,
    uint32_t                                    rectCount,
    const VkClearRect*                          pRects) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
}

void GfrContext::PreCmdResolveImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageResolve*                       pRegions) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}
void GfrContext::PostCmdResolveImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageResolve*                       pRegions) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}

void GfrContext::PreCmdSetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetEvent(commandBuffer, event, stageMask);
}
void GfrContext::PostCmdSetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetEvent(commandBuffer, event, stageMask);
}

void GfrContext::PreCmdResetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdResetEvent(commandBuffer, event, stageMask);
}
void GfrContext::PostCmdResetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdResetEvent(commandBuffer, event, stageMask);
}

void GfrContext::PreCmdWaitEvents(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    uint32_t                                    memoryBarrierCount,
    const VkMemoryBarrier*                      pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const VkImageMemoryBarrier*                 pImageMemoryBarriers) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}
void GfrContext::PostCmdWaitEvents(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    uint32_t                                    memoryBarrierCount,
    const VkMemoryBarrier*                      pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const VkImageMemoryBarrier*                 pImageMemoryBarriers) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}

void GfrContext::PreCmdPipelineBarrier(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    VkDependencyFlags                           dependencyFlags,
    uint32_t                                    memoryBarrierCount,
    const VkMemoryBarrier*                      pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const VkImageMemoryBarrier*                 pImageMemoryBarriers) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}
void GfrContext::PostCmdPipelineBarrier(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    VkDependencyFlags                           dependencyFlags,
    uint32_t                                    memoryBarrierCount,
    const VkMemoryBarrier*                      pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const VkImageMemoryBarrier*                 pImageMemoryBarriers) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}

void GfrContext::PreCmdBeginQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBeginQuery(commandBuffer, queryPool, query, flags);
}
void GfrContext::PostCmdBeginQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBeginQuery(commandBuffer, queryPool, query, flags);
}

void GfrContext::PreCmdEndQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdEndQuery(commandBuffer, queryPool, query);
}
void GfrContext::PostCmdEndQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdEndQuery(commandBuffer, queryPool, query);
}

void GfrContext::PreCmdResetQueryPool(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
}
void GfrContext::PostCmdResetQueryPool(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
}

void GfrContext::PreCmdWriteTimestamp(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
}
void GfrContext::PostCmdWriteTimestamp(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
}

void GfrContext::PreCmdCopyQueryPoolResults(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
}
void GfrContext::PostCmdCopyQueryPoolResults(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
}

void GfrContext::PreCmdPushConstants(
    VkCommandBuffer                             commandBuffer,
    VkPipelineLayout                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    const void*                                 pValues) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
}
void GfrContext::PostCmdPushConstants(
    VkCommandBuffer                             commandBuffer,
    VkPipelineLayout                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    const void*                                 pValues) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
}

void GfrContext::PreCmdBeginRenderPass(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    VkSubpassContents                           contents) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
}
void GfrContext::PostCmdBeginRenderPass(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    VkSubpassContents                           contents) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
}

void GfrContext::PreCmdNextSubpass(
    VkCommandBuffer                             commandBuffer,
    VkSubpassContents                           contents) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdNextSubpass(commandBuffer, contents);
}
void GfrContext::PostCmdNextSubpass(
    VkCommandBuffer                             commandBuffer,
    VkSubpassContents                           contents) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdNextSubpass(commandBuffer, contents);
}

void GfrContext::PreCmdEndRenderPass(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdEndRenderPass(commandBuffer);
}
void GfrContext::PostCmdEndRenderPass(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdEndRenderPass(commandBuffer);
}

void GfrContext::PreCmdExecuteCommands(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
}
void GfrContext::PostCmdExecuteCommands(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
}

void GfrContext::PreCmdSetDeviceMask(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDeviceMask(commandBuffer, deviceMask);
}
void GfrContext::PostCmdSetDeviceMask(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDeviceMask(commandBuffer, deviceMask);
}

void GfrContext::PreCmdDispatchBase(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}
void GfrContext::PostCmdDispatchBase(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

void GfrContext::PreCmdDrawIndirectCount(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
void GfrContext::PostCmdDrawIndirectCount(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void GfrContext::PreCmdDrawIndexedIndirectCount(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
void GfrContext::PostCmdDrawIndexedIndirectCount(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void GfrContext::PreCmdBeginRenderPass2(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}
void GfrContext::PostCmdBeginRenderPass2(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

void GfrContext::PreCmdNextSubpass2(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo,
    const VkSubpassEndInfo*                     pSubpassEndInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}
void GfrContext::PostCmdNextSubpass2(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo,
    const VkSubpassEndInfo*                     pSubpassEndInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}

void GfrContext::PreCmdEndRenderPass2(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassEndInfo*                     pSubpassEndInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
}
void GfrContext::PostCmdEndRenderPass2(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassEndInfo*                     pSubpassEndInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
}

void GfrContext::PreCmdSetEvent2(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    const VkDependencyInfo*                     pDependencyInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetEvent2(commandBuffer, event, pDependencyInfo);
}
void GfrContext::PostCmdSetEvent2(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    const VkDependencyInfo*                     pDependencyInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetEvent2(commandBuffer, event, pDependencyInfo);
}

void GfrContext::PreCmdResetEvent2(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags2                       stageMask) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdResetEvent2(commandBuffer, event, stageMask);
}
void GfrContext::PostCmdResetEvent2(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags2                       stageMask) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdResetEvent2(commandBuffer, event, stageMask);
}

void GfrContext::PreCmdWaitEvents2(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    const VkDependencyInfo*                     pDependencyInfos) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
}
void GfrContext::PostCmdWaitEvents2(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    const VkDependencyInfo*                     pDependencyInfos) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
}

void GfrContext::PreCmdPipelineBarrier2(
    VkCommandBuffer                             commandBuffer,
    const VkDependencyInfo*                     pDependencyInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdPipelineBarrier2(commandBuffer, pDependencyInfo);
}
void GfrContext::PostCmdPipelineBarrier2(
    VkCommandBuffer                             commandBuffer,
    const VkDependencyInfo*                     pDependencyInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdPipelineBarrier2(commandBuffer, pDependencyInfo);
}

void GfrContext::PreCmdWriteTimestamp2(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
}
void GfrContext::PostCmdWriteTimestamp2(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
}

void GfrContext::PreCmdCopyBuffer2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferInfo2*                    pCopyBufferInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
}
void GfrContext::PostCmdCopyBuffer2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferInfo2*                    pCopyBufferInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
}

void GfrContext::PreCmdCopyImage2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageInfo2*                     pCopyImageInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyImage2(commandBuffer, pCopyImageInfo);
}
void GfrContext::PostCmdCopyImage2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageInfo2*                     pCopyImageInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyImage2(commandBuffer, pCopyImageInfo);
}

void GfrContext::PreCmdCopyBufferToImage2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferToImageInfo2*             pCopyBufferToImageInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
}
void GfrContext::PostCmdCopyBufferToImage2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferToImageInfo2*             pCopyBufferToImageInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
}

void GfrContext::PreCmdCopyImageToBuffer2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageToBufferInfo2*             pCopyImageToBufferInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
}
void GfrContext::PostCmdCopyImageToBuffer2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageToBufferInfo2*             pCopyImageToBufferInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
}

void GfrContext::PreCmdBlitImage2(
    VkCommandBuffer                             commandBuffer,
    const VkBlitImageInfo2*                     pBlitImageInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBlitImage2(commandBuffer, pBlitImageInfo);
}
void GfrContext::PostCmdBlitImage2(
    VkCommandBuffer                             commandBuffer,
    const VkBlitImageInfo2*                     pBlitImageInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBlitImage2(commandBuffer, pBlitImageInfo);
}

void GfrContext::PreCmdResolveImage2(
    VkCommandBuffer                             commandBuffer,
    const VkResolveImageInfo2*                  pResolveImageInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdResolveImage2(commandBuffer, pResolveImageInfo);
}
void GfrContext::PostCmdResolveImage2(
    VkCommandBuffer                             commandBuffer,
    const VkResolveImageInfo2*                  pResolveImageInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdResolveImage2(commandBuffer, pResolveImageInfo);
}

void GfrContext::PreCmdBeginRendering(
    VkCommandBuffer                             commandBuffer,
    const VkRenderingInfo*                      pRenderingInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBeginRendering(commandBuffer, pRenderingInfo);
}
void GfrContext::PostCmdBeginRendering(
    VkCommandBuffer                             commandBuffer,
    const VkRenderingInfo*                      pRenderingInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBeginRendering(commandBuffer, pRenderingInfo);
}

void GfrContext::PreCmdEndRendering(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdEndRendering(commandBuffer);
}
void GfrContext::PostCmdEndRendering(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdEndRendering(commandBuffer);
}

void GfrContext::PreCmdSetCullMode(
    VkCommandBuffer                             commandBuffer,
    VkCullModeFlags                             cullMode) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetCullMode(commandBuffer, cullMode);
}
void GfrContext::PostCmdSetCullMode(
    VkCommandBuffer                             commandBuffer,
    VkCullModeFlags                             cullMode) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetCullMode(commandBuffer, cullMode);
}

void GfrContext::PreCmdSetFrontFace(
    VkCommandBuffer                             commandBuffer,
    VkFrontFace                                 frontFace) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetFrontFace(commandBuffer, frontFace);
}
void GfrContext::PostCmdSetFrontFace(
    VkCommandBuffer                             commandBuffer,
    VkFrontFace                                 frontFace) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetFrontFace(commandBuffer, frontFace);
}

void GfrContext::PreCmdSetPrimitiveTopology(
    VkCommandBuffer                             commandBuffer,
    VkPrimitiveTopology                         primitiveTopology) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
}
void GfrContext::PostCmdSetPrimitiveTopology(
    VkCommandBuffer                             commandBuffer,
    VkPrimitiveTopology                         primitiveTopology) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
}

void GfrContext::PreCmdSetViewportWithCount(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
}
void GfrContext::PostCmdSetViewportWithCount(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
}

void GfrContext::PreCmdSetScissorWithCount(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
}
void GfrContext::PostCmdSetScissorWithCount(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
}

void GfrContext::PreCmdBindVertexBuffers2(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes,
    const VkDeviceSize*                         pStrides) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}
void GfrContext::PostCmdBindVertexBuffers2(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes,
    const VkDeviceSize*                         pStrides) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}

void GfrContext::PreCmdSetDepthTestEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthTestEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthTestEnable(commandBuffer, depthTestEnable);
}
void GfrContext::PostCmdSetDepthTestEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthTestEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthTestEnable(commandBuffer, depthTestEnable);
}

void GfrContext::PreCmdSetDepthWriteEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthWriteEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
}
void GfrContext::PostCmdSetDepthWriteEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthWriteEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
}

void GfrContext::PreCmdSetDepthCompareOp(
    VkCommandBuffer                             commandBuffer,
    VkCompareOp                                 depthCompareOp) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthCompareOp(commandBuffer, depthCompareOp);
}
void GfrContext::PostCmdSetDepthCompareOp(
    VkCommandBuffer                             commandBuffer,
    VkCompareOp                                 depthCompareOp) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthCompareOp(commandBuffer, depthCompareOp);
}

void GfrContext::PreCmdSetDepthBoundsTestEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBoundsTestEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
}
void GfrContext::PostCmdSetDepthBoundsTestEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBoundsTestEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
}

void GfrContext::PreCmdSetStencilTestEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stencilTestEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
}
void GfrContext::PostCmdSetStencilTestEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stencilTestEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
}

void GfrContext::PreCmdSetStencilOp(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}
void GfrContext::PostCmdSetStencilOp(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}

void GfrContext::PreCmdSetRasterizerDiscardEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    rasterizerDiscardEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
}
void GfrContext::PostCmdSetRasterizerDiscardEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    rasterizerDiscardEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
}

void GfrContext::PreCmdSetDepthBiasEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBiasEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
}
void GfrContext::PostCmdSetDepthBiasEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBiasEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
}

void GfrContext::PreCmdSetPrimitiveRestartEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    primitiveRestartEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
}
void GfrContext::PostCmdSetPrimitiveRestartEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    primitiveRestartEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
}

void GfrContext::PreCmdBeginVideoCodingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoBeginCodingInfoKHR*            pBeginInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);
}
void GfrContext::PostCmdBeginVideoCodingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoBeginCodingInfoKHR*            pBeginInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);
}

void GfrContext::PreCmdEndVideoCodingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoEndCodingInfoKHR*              pEndCodingInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);
}
void GfrContext::PostCmdEndVideoCodingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoEndCodingInfoKHR*              pEndCodingInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);
}

void GfrContext::PreCmdControlVideoCodingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoCodingControlInfoKHR*          pCodingControlInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);
}
void GfrContext::PostCmdControlVideoCodingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoCodingControlInfoKHR*          pCodingControlInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);
}

void GfrContext::PreCmdDecodeVideoKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoDecodeInfoKHR*                 pDecodeInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDecodeVideoKHR(commandBuffer, pDecodeInfo);
}
void GfrContext::PostCmdDecodeVideoKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoDecodeInfoKHR*                 pDecodeInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDecodeVideoKHR(commandBuffer, pDecodeInfo);
}

void GfrContext::PreCmdBeginRenderingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkRenderingInfo*                      pRenderingInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBeginRenderingKHR(commandBuffer, pRenderingInfo);
}
void GfrContext::PostCmdBeginRenderingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkRenderingInfo*                      pRenderingInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBeginRenderingKHR(commandBuffer, pRenderingInfo);
}

void GfrContext::PreCmdEndRenderingKHR(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdEndRenderingKHR(commandBuffer);
}
void GfrContext::PostCmdEndRenderingKHR(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdEndRenderingKHR(commandBuffer);
}

void GfrContext::PreCmdSetDeviceMaskKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDeviceMaskKHR(commandBuffer, deviceMask);
}
void GfrContext::PostCmdSetDeviceMaskKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDeviceMaskKHR(commandBuffer, deviceMask);
}

void GfrContext::PreCmdDispatchBaseKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}
void GfrContext::PostCmdDispatchBaseKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

void GfrContext::PreCmdPushDescriptorSetKHR(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    const VkWriteDescriptorSet*                 pDescriptorWrites) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
}
void GfrContext::PostCmdPushDescriptorSetKHR(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    const VkWriteDescriptorSet*                 pDescriptorWrites) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
}

void GfrContext::PreCmdPushDescriptorSetWithTemplateKHR(
    VkCommandBuffer                             commandBuffer,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    VkPipelineLayout                            layout,
    uint32_t                                    set,
    const void*                                 pData) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
}
void GfrContext::PostCmdPushDescriptorSetWithTemplateKHR(
    VkCommandBuffer                             commandBuffer,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    VkPipelineLayout                            layout,
    uint32_t                                    set,
    const void*                                 pData) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
}

void GfrContext::PreCmdBeginRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}
void GfrContext::PostCmdBeginRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

void GfrContext::PreCmdNextSubpass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo,
    const VkSubpassEndInfo*                     pSubpassEndInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}
void GfrContext::PostCmdNextSubpass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo,
    const VkSubpassEndInfo*                     pSubpassEndInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}

void GfrContext::PreCmdEndRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassEndInfo*                     pSubpassEndInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);
}
void GfrContext::PostCmdEndRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassEndInfo*                     pSubpassEndInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);
}

void GfrContext::PreCmdDrawIndirectCountKHR(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
void GfrContext::PostCmdDrawIndirectCountKHR(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void GfrContext::PreCmdDrawIndexedIndirectCountKHR(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
void GfrContext::PostCmdDrawIndexedIndirectCountKHR(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void GfrContext::PreCmdSetFragmentShadingRateKHR(
    VkCommandBuffer                             commandBuffer,
    const VkExtent2D*                           pFragmentSize,
    const VkFragmentShadingRateCombinerOpKHR    combinerOps[2]) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
}
void GfrContext::PostCmdSetFragmentShadingRateKHR(
    VkCommandBuffer                             commandBuffer,
    const VkExtent2D*                           pFragmentSize,
    const VkFragmentShadingRateCombinerOpKHR    combinerOps[2]) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
}

#ifdef VK_ENABLE_BETA_EXTENSIONS
void GfrContext::PreCmdEncodeVideoKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoEncodeInfoKHR*                 pEncodeInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdEncodeVideoKHR(commandBuffer, pEncodeInfo);
}
void GfrContext::PostCmdEncodeVideoKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoEncodeInfoKHR*                 pEncodeInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdEncodeVideoKHR(commandBuffer, pEncodeInfo);
}
#endif //VK_ENABLE_BETA_EXTENSIONS

void GfrContext::PreCmdSetEvent2KHR(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    const VkDependencyInfo*                     pDependencyInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetEvent2KHR(commandBuffer, event, pDependencyInfo);
}
void GfrContext::PostCmdSetEvent2KHR(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    const VkDependencyInfo*                     pDependencyInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetEvent2KHR(commandBuffer, event, pDependencyInfo);
}

void GfrContext::PreCmdResetEvent2KHR(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags2                       stageMask) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdResetEvent2KHR(commandBuffer, event, stageMask);
}
void GfrContext::PostCmdResetEvent2KHR(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags2                       stageMask) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdResetEvent2KHR(commandBuffer, event, stageMask);
}

void GfrContext::PreCmdWaitEvents2KHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    const VkDependencyInfo*                     pDependencyInfos) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos);
}
void GfrContext::PostCmdWaitEvents2KHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    const VkDependencyInfo*                     pDependencyInfos) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos);
}

void GfrContext::PreCmdPipelineBarrier2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkDependencyInfo*                     pDependencyInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo);
}
void GfrContext::PostCmdPipelineBarrier2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkDependencyInfo*                     pDependencyInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo);
}

void GfrContext::PreCmdWriteTimestamp2KHR(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query);
}
void GfrContext::PostCmdWriteTimestamp2KHR(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query);
}

void GfrContext::PreCmdWriteBufferMarker2AMD(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
}
void GfrContext::PostCmdWriteBufferMarker2AMD(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
}

void GfrContext::PreCmdCopyBuffer2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferInfo2*                    pCopyBufferInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);
}
void GfrContext::PostCmdCopyBuffer2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferInfo2*                    pCopyBufferInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);
}

void GfrContext::PreCmdCopyImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageInfo2*                     pCopyImageInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyImage2KHR(commandBuffer, pCopyImageInfo);
}
void GfrContext::PostCmdCopyImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageInfo2*                     pCopyImageInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyImage2KHR(commandBuffer, pCopyImageInfo);
}

void GfrContext::PreCmdCopyBufferToImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferToImageInfo2*             pCopyBufferToImageInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);
}
void GfrContext::PostCmdCopyBufferToImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferToImageInfo2*             pCopyBufferToImageInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);
}

void GfrContext::PreCmdCopyImageToBuffer2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageToBufferInfo2*             pCopyImageToBufferInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);
}
void GfrContext::PostCmdCopyImageToBuffer2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageToBufferInfo2*             pCopyImageToBufferInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);
}

void GfrContext::PreCmdBlitImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkBlitImageInfo2*                     pBlitImageInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBlitImage2KHR(commandBuffer, pBlitImageInfo);
}
void GfrContext::PostCmdBlitImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkBlitImageInfo2*                     pBlitImageInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBlitImage2KHR(commandBuffer, pBlitImageInfo);
}

void GfrContext::PreCmdResolveImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkResolveImageInfo2*                  pResolveImageInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdResolveImage2KHR(commandBuffer, pResolveImageInfo);
}
void GfrContext::PostCmdResolveImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkResolveImageInfo2*                  pResolveImageInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdResolveImage2KHR(commandBuffer, pResolveImageInfo);
}

void GfrContext::PreCmdTraceRaysIndirect2KHR(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             indirectDeviceAddress) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdTraceRaysIndirect2KHR(commandBuffer, indirectDeviceAddress);
}
void GfrContext::PostCmdTraceRaysIndirect2KHR(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             indirectDeviceAddress) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdTraceRaysIndirect2KHR(commandBuffer, indirectDeviceAddress);
}

void GfrContext::PreCmdDebugMarkerBeginEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
}
void GfrContext::PostCmdDebugMarkerBeginEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
}

void GfrContext::PreCmdDebugMarkerEndEXT(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDebugMarkerEndEXT(commandBuffer);
}
void GfrContext::PostCmdDebugMarkerEndEXT(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDebugMarkerEndEXT(commandBuffer);
}

void GfrContext::PreCmdDebugMarkerInsertEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
}
void GfrContext::PostCmdDebugMarkerInsertEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
}

void GfrContext::PreCmdBindTransformFeedbackBuffersEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
}
void GfrContext::PostCmdBindTransformFeedbackBuffersEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
}

void GfrContext::PreCmdBeginTransformFeedbackEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const VkBuffer*                             pCounterBuffers,
    const VkDeviceSize*                         pCounterBufferOffsets) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}
void GfrContext::PostCmdBeginTransformFeedbackEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const VkBuffer*                             pCounterBuffers,
    const VkDeviceSize*                         pCounterBufferOffsets) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}

void GfrContext::PreCmdEndTransformFeedbackEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const VkBuffer*                             pCounterBuffers,
    const VkDeviceSize*                         pCounterBufferOffsets) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}
void GfrContext::PostCmdEndTransformFeedbackEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const VkBuffer*                             pCounterBuffers,
    const VkDeviceSize*                         pCounterBufferOffsets) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}

void GfrContext::PreCmdBeginQueryIndexedEXT(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags,
    uint32_t                                    index) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
}
void GfrContext::PostCmdBeginQueryIndexedEXT(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags,
    uint32_t                                    index) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
}

void GfrContext::PreCmdEndQueryIndexedEXT(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    uint32_t                                    index) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
}
void GfrContext::PostCmdEndQueryIndexedEXT(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    uint32_t                                    index) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
}

void GfrContext::PreCmdDrawIndirectByteCountEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    VkBuffer                                    counterBuffer,
    VkDeviceSize                                counterBufferOffset,
    uint32_t                                    counterOffset,
    uint32_t                                    vertexStride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
}
void GfrContext::PostCmdDrawIndirectByteCountEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    VkBuffer                                    counterBuffer,
    VkDeviceSize                                counterBufferOffset,
    uint32_t                                    counterOffset,
    uint32_t                                    vertexStride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
}

void GfrContext::PreCmdCuLaunchKernelNVX(
    VkCommandBuffer                             commandBuffer,
    const VkCuLaunchInfoNVX*                    pLaunchInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);
}
void GfrContext::PostCmdCuLaunchKernelNVX(
    VkCommandBuffer                             commandBuffer,
    const VkCuLaunchInfoNVX*                    pLaunchInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);
}

void GfrContext::PreCmdDrawIndirectCountAMD(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
void GfrContext::PostCmdDrawIndirectCountAMD(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void GfrContext::PreCmdDrawIndexedIndirectCountAMD(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
void GfrContext::PostCmdDrawIndexedIndirectCountAMD(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void GfrContext::PreCmdBeginConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer,
    const VkConditionalRenderingBeginInfoEXT*   pConditionalRenderingBegin) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
}
void GfrContext::PostCmdBeginConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer,
    const VkConditionalRenderingBeginInfoEXT*   pConditionalRenderingBegin) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
}

void GfrContext::PreCmdEndConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdEndConditionalRenderingEXT(commandBuffer);
}
void GfrContext::PostCmdEndConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdEndConditionalRenderingEXT(commandBuffer);
}

void GfrContext::PreCmdSetViewportWScalingNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewportWScalingNV*                 pViewportWScalings) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
}
void GfrContext::PostCmdSetViewportWScalingNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewportWScalingNV*                 pViewportWScalings) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
}

void GfrContext::PreCmdSetDiscardRectangleEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    const VkRect2D*                             pDiscardRectangles) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
}
void GfrContext::PostCmdSetDiscardRectangleEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    const VkRect2D*                             pDiscardRectangles) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
}

void GfrContext::PreCmdSetDiscardRectangleEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    discardRectangleEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable);
}
void GfrContext::PostCmdSetDiscardRectangleEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    discardRectangleEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable);
}

void GfrContext::PreCmdSetDiscardRectangleModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkDiscardRectangleModeEXT                   discardRectangleMode) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode);
}
void GfrContext::PostCmdSetDiscardRectangleModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkDiscardRectangleModeEXT                   discardRectangleMode) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode);
}

void GfrContext::PreCmdBeginDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}
void GfrContext::PostCmdBeginDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}

void GfrContext::PreCmdEndDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdEndDebugUtilsLabelEXT(commandBuffer);
}
void GfrContext::PostCmdEndDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdEndDebugUtilsLabelEXT(commandBuffer);
}

void GfrContext::PreCmdInsertDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}
void GfrContext::PostCmdInsertDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}

void GfrContext::PreCmdSetSampleLocationsEXT(
    VkCommandBuffer                             commandBuffer,
    const VkSampleLocationsInfoEXT*             pSampleLocationsInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
}
void GfrContext::PostCmdSetSampleLocationsEXT(
    VkCommandBuffer                             commandBuffer,
    const VkSampleLocationsInfoEXT*             pSampleLocationsInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
}

void GfrContext::PreCmdBindShadingRateImageNV(
    VkCommandBuffer                             commandBuffer,
    VkImageView                                 imageView,
    VkImageLayout                               imageLayout) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
}
void GfrContext::PostCmdBindShadingRateImageNV(
    VkCommandBuffer                             commandBuffer,
    VkImageView                                 imageView,
    VkImageLayout                               imageLayout) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
}

void GfrContext::PreCmdSetViewportShadingRatePaletteNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkShadingRatePaletteNV*               pShadingRatePalettes) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
}
void GfrContext::PostCmdSetViewportShadingRatePaletteNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkShadingRatePaletteNV*               pShadingRatePalettes) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
}

void GfrContext::PreCmdSetCoarseSampleOrderNV(
    VkCommandBuffer                             commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    const VkCoarseSampleOrderCustomNV*          pCustomSampleOrders) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
}
void GfrContext::PostCmdSetCoarseSampleOrderNV(
    VkCommandBuffer                             commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    const VkCoarseSampleOrderCustomNV*          pCustomSampleOrders) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
}

void GfrContext::PreCmdBuildAccelerationStructureNV(
    VkCommandBuffer                             commandBuffer,
    const VkAccelerationStructureInfoNV*        pInfo,
    VkBuffer                                    instanceData,
    VkDeviceSize                                instanceOffset,
    VkBool32                                    update,
    VkAccelerationStructureNV                   dst,
    VkAccelerationStructureNV                   src,
    VkBuffer                                    scratch,
    VkDeviceSize                                scratchOffset) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
}
void GfrContext::PostCmdBuildAccelerationStructureNV(
    VkCommandBuffer                             commandBuffer,
    const VkAccelerationStructureInfoNV*        pInfo,
    VkBuffer                                    instanceData,
    VkDeviceSize                                instanceOffset,
    VkBool32                                    update,
    VkAccelerationStructureNV                   dst,
    VkAccelerationStructureNV                   src,
    VkBuffer                                    scratch,
    VkDeviceSize                                scratchOffset) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
}

void GfrContext::PreCmdCopyAccelerationStructureNV(
    VkCommandBuffer                             commandBuffer,
    VkAccelerationStructureNV                   dst,
    VkAccelerationStructureNV                   src,
    VkCopyAccelerationStructureModeKHR          mode) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
}
void GfrContext::PostCmdCopyAccelerationStructureNV(
    VkCommandBuffer                             commandBuffer,
    VkAccelerationStructureNV                   dst,
    VkAccelerationStructureNV                   src,
    VkCopyAccelerationStructureModeKHR          mode) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
}

void GfrContext::PreCmdTraceRaysNV(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    raygenShaderBindingTableBuffer,
    VkDeviceSize                                raygenShaderBindingOffset,
    VkBuffer                                    missShaderBindingTableBuffer,
    VkDeviceSize                                missShaderBindingOffset,
    VkDeviceSize                                missShaderBindingStride,
    VkBuffer                                    hitShaderBindingTableBuffer,
    VkDeviceSize                                hitShaderBindingOffset,
    VkDeviceSize                                hitShaderBindingStride,
    VkBuffer                                    callableShaderBindingTableBuffer,
    VkDeviceSize                                callableShaderBindingOffset,
    VkDeviceSize                                callableShaderBindingStride,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdTraceRaysNV(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
}
void GfrContext::PostCmdTraceRaysNV(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    raygenShaderBindingTableBuffer,
    VkDeviceSize                                raygenShaderBindingOffset,
    VkBuffer                                    missShaderBindingTableBuffer,
    VkDeviceSize                                missShaderBindingOffset,
    VkDeviceSize                                missShaderBindingStride,
    VkBuffer                                    hitShaderBindingTableBuffer,
    VkDeviceSize                                hitShaderBindingOffset,
    VkDeviceSize                                hitShaderBindingStride,
    VkBuffer                                    callableShaderBindingTableBuffer,
    VkDeviceSize                                callableShaderBindingOffset,
    VkDeviceSize                                callableShaderBindingStride,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdTraceRaysNV(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
}

void GfrContext::PreCmdWriteAccelerationStructuresPropertiesNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    accelerationStructureCount,
    const VkAccelerationStructureNV*            pAccelerationStructures,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdWriteAccelerationStructuresPropertiesNV(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}
void GfrContext::PostCmdWriteAccelerationStructuresPropertiesNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    accelerationStructureCount,
    const VkAccelerationStructureNV*            pAccelerationStructures,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdWriteAccelerationStructuresPropertiesNV(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}

void GfrContext::PreCmdWriteBufferMarkerAMD(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
}
void GfrContext::PostCmdWriteBufferMarkerAMD(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
}

void GfrContext::PreCmdDrawMeshTasksNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
}
void GfrContext::PostCmdDrawMeshTasksNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
}

void GfrContext::PreCmdDrawMeshTasksIndirectNV(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
}
void GfrContext::PostCmdDrawMeshTasksIndirectNV(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
}

void GfrContext::PreCmdDrawMeshTasksIndirectCountNV(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
void GfrContext::PostCmdDrawMeshTasksIndirectCountNV(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void GfrContext::PreCmdSetExclusiveScissorEnableNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    const VkBool32*                             pExclusiveScissorEnables) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetExclusiveScissorEnableNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);
}
void GfrContext::PostCmdSetExclusiveScissorEnableNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    const VkBool32*                             pExclusiveScissorEnables) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetExclusiveScissorEnableNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);
}

void GfrContext::PreCmdSetExclusiveScissorNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    const VkRect2D*                             pExclusiveScissors) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
}
void GfrContext::PostCmdSetExclusiveScissorNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    const VkRect2D*                             pExclusiveScissors) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
}

void GfrContext::PreCmdSetCheckpointNV(
    VkCommandBuffer                             commandBuffer,
    const void*                                 pCheckpointMarker) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
}
void GfrContext::PostCmdSetCheckpointNV(
    VkCommandBuffer                             commandBuffer,
    const void*                                 pCheckpointMarker) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
}

VkResult GfrContext::PreCmdSetPerformanceMarkerINTEL(
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceMarkerInfoINTEL*         pMarkerInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  return p_cmd->PreCmdSetPerformanceMarkerINTEL(commandBuffer, pMarkerInfo);
}
VkResult GfrContext::PostCmdSetPerformanceMarkerINTEL(
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceMarkerInfoINTEL*         pMarkerInfo,
    VkResult                                    result) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  return p_cmd->PostCmdSetPerformanceMarkerINTEL(commandBuffer, pMarkerInfo, result);
}

VkResult GfrContext::PreCmdSetPerformanceStreamMarkerINTEL(
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceStreamMarkerInfoINTEL*   pMarkerInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  return p_cmd->PreCmdSetPerformanceStreamMarkerINTEL(commandBuffer, pMarkerInfo);
}
VkResult GfrContext::PostCmdSetPerformanceStreamMarkerINTEL(
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceStreamMarkerInfoINTEL*   pMarkerInfo,
    VkResult                                    result) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  return p_cmd->PostCmdSetPerformanceStreamMarkerINTEL(commandBuffer, pMarkerInfo, result);
}

VkResult GfrContext::PreCmdSetPerformanceOverrideINTEL(
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceOverrideInfoINTEL*       pOverrideInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  return p_cmd->PreCmdSetPerformanceOverrideINTEL(commandBuffer, pOverrideInfo);
}
VkResult GfrContext::PostCmdSetPerformanceOverrideINTEL(
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceOverrideInfoINTEL*       pOverrideInfo,
    VkResult                                    result) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  return p_cmd->PostCmdSetPerformanceOverrideINTEL(commandBuffer, pOverrideInfo, result);
}

void GfrContext::PreCmdSetLineStippleEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
}
void GfrContext::PostCmdSetLineStippleEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
}

void GfrContext::PreCmdSetCullModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkCullModeFlags                             cullMode) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetCullModeEXT(commandBuffer, cullMode);
}
void GfrContext::PostCmdSetCullModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkCullModeFlags                             cullMode) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetCullModeEXT(commandBuffer, cullMode);
}

void GfrContext::PreCmdSetFrontFaceEXT(
    VkCommandBuffer                             commandBuffer,
    VkFrontFace                                 frontFace) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetFrontFaceEXT(commandBuffer, frontFace);
}
void GfrContext::PostCmdSetFrontFaceEXT(
    VkCommandBuffer                             commandBuffer,
    VkFrontFace                                 frontFace) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetFrontFaceEXT(commandBuffer, frontFace);
}

void GfrContext::PreCmdSetPrimitiveTopologyEXT(
    VkCommandBuffer                             commandBuffer,
    VkPrimitiveTopology                         primitiveTopology) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);
}
void GfrContext::PostCmdSetPrimitiveTopologyEXT(
    VkCommandBuffer                             commandBuffer,
    VkPrimitiveTopology                         primitiveTopology) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);
}

void GfrContext::PreCmdSetViewportWithCountEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);
}
void GfrContext::PostCmdSetViewportWithCountEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);
}

void GfrContext::PreCmdSetScissorWithCountEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);
}
void GfrContext::PostCmdSetScissorWithCountEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);
}

void GfrContext::PreCmdBindVertexBuffers2EXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes,
    const VkDeviceSize*                         pStrides) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}
void GfrContext::PostCmdBindVertexBuffers2EXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes,
    const VkDeviceSize*                         pStrides) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}

void GfrContext::PreCmdSetDepthTestEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthTestEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);
}
void GfrContext::PostCmdSetDepthTestEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthTestEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);
}

void GfrContext::PreCmdSetDepthWriteEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthWriteEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);
}
void GfrContext::PostCmdSetDepthWriteEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthWriteEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);
}

void GfrContext::PreCmdSetDepthCompareOpEXT(
    VkCommandBuffer                             commandBuffer,
    VkCompareOp                                 depthCompareOp) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);
}
void GfrContext::PostCmdSetDepthCompareOpEXT(
    VkCommandBuffer                             commandBuffer,
    VkCompareOp                                 depthCompareOp) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);
}

void GfrContext::PreCmdSetDepthBoundsTestEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBoundsTestEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);
}
void GfrContext::PostCmdSetDepthBoundsTestEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBoundsTestEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);
}

void GfrContext::PreCmdSetStencilTestEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stencilTestEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);
}
void GfrContext::PostCmdSetStencilTestEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stencilTestEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);
}

void GfrContext::PreCmdSetStencilOpEXT(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}
void GfrContext::PostCmdSetStencilOpEXT(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}

void GfrContext::PreCmdPreprocessGeneratedCommandsNV(
    VkCommandBuffer                             commandBuffer,
    const VkGeneratedCommandsInfoNV*            pGeneratedCommandsInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);
}
void GfrContext::PostCmdPreprocessGeneratedCommandsNV(
    VkCommandBuffer                             commandBuffer,
    const VkGeneratedCommandsInfoNV*            pGeneratedCommandsInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);
}

void GfrContext::PreCmdExecuteGeneratedCommandsNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    isPreprocessed,
    const VkGeneratedCommandsInfoNV*            pGeneratedCommandsInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
}
void GfrContext::PostCmdExecuteGeneratedCommandsNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    isPreprocessed,
    const VkGeneratedCommandsInfoNV*            pGeneratedCommandsInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
}

void GfrContext::PreCmdBindPipelineShaderGroupNV(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline,
    uint32_t                                    groupIndex) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
}
void GfrContext::PostCmdBindPipelineShaderGroupNV(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline,
    uint32_t                                    groupIndex) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
}

void GfrContext::PreCmdSetDepthBias2EXT(
    VkCommandBuffer                             commandBuffer,
    const VkDepthBiasInfoEXT*                   pDepthBiasInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthBias2EXT(commandBuffer, pDepthBiasInfo);
}
void GfrContext::PostCmdSetDepthBias2EXT(
    VkCommandBuffer                             commandBuffer,
    const VkDepthBiasInfoEXT*                   pDepthBiasInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthBias2EXT(commandBuffer, pDepthBiasInfo);
}

void GfrContext::PreCmdBindDescriptorBuffersEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    bufferCount,
    const VkDescriptorBufferBindingInfoEXT*     pBindingInfos) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBindDescriptorBuffersEXT(commandBuffer, bufferCount, pBindingInfos);
}
void GfrContext::PostCmdBindDescriptorBuffersEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    bufferCount,
    const VkDescriptorBufferBindingInfoEXT*     pBindingInfos) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBindDescriptorBuffersEXT(commandBuffer, bufferCount, pBindingInfos);
}

void GfrContext::PreCmdSetDescriptorBufferOffsetsEXT(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    setCount,
    const uint32_t*                             pBufferIndices,
    const VkDeviceSize*                         pOffsets) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDescriptorBufferOffsetsEXT(commandBuffer, pipelineBindPoint, layout, firstSet, setCount, pBufferIndices, pOffsets);
}
void GfrContext::PostCmdSetDescriptorBufferOffsetsEXT(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    setCount,
    const uint32_t*                             pBufferIndices,
    const VkDeviceSize*                         pOffsets) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDescriptorBufferOffsetsEXT(commandBuffer, pipelineBindPoint, layout, firstSet, setCount, pBufferIndices, pOffsets);
}

void GfrContext::PreCmdBindDescriptorBufferEmbeddedSamplersEXT(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    set) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBindDescriptorBufferEmbeddedSamplersEXT(commandBuffer, pipelineBindPoint, layout, set);
}
void GfrContext::PostCmdBindDescriptorBufferEmbeddedSamplersEXT(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    set) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBindDescriptorBufferEmbeddedSamplersEXT(commandBuffer, pipelineBindPoint, layout, set);
}

void GfrContext::PreCmdSetFragmentShadingRateEnumNV(
    VkCommandBuffer                             commandBuffer,
    VkFragmentShadingRateNV                     shadingRate,
    const VkFragmentShadingRateCombinerOpKHR    combinerOps[2]) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);
}
void GfrContext::PostCmdSetFragmentShadingRateEnumNV(
    VkCommandBuffer                             commandBuffer,
    VkFragmentShadingRateNV                     shadingRate,
    const VkFragmentShadingRateCombinerOpKHR    combinerOps[2]) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);
}

void GfrContext::PreCmdSetVertexInputEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexBindingDescriptionCount,
    const VkVertexInputBindingDescription2EXT*  pVertexBindingDescriptions,
    uint32_t                                    vertexAttributeDescriptionCount,
    const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
}
void GfrContext::PostCmdSetVertexInputEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexBindingDescriptionCount,
    const VkVertexInputBindingDescription2EXT*  pVertexBindingDescriptions,
    uint32_t                                    vertexAttributeDescriptionCount,
    const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
}

void GfrContext::PreCmdSubpassShadingHUAWEI(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSubpassShadingHUAWEI(commandBuffer);
}
void GfrContext::PostCmdSubpassShadingHUAWEI(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSubpassShadingHUAWEI(commandBuffer);
}

void GfrContext::PreCmdBindInvocationMaskHUAWEI(
    VkCommandBuffer                             commandBuffer,
    VkImageView                                 imageView,
    VkImageLayout                               imageLayout) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBindInvocationMaskHUAWEI(commandBuffer, imageView, imageLayout);
}
void GfrContext::PostCmdBindInvocationMaskHUAWEI(
    VkCommandBuffer                             commandBuffer,
    VkImageView                                 imageView,
    VkImageLayout                               imageLayout) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBindInvocationMaskHUAWEI(commandBuffer, imageView, imageLayout);
}

void GfrContext::PreCmdSetPatchControlPointsEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    patchControlPoints) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
}
void GfrContext::PostCmdSetPatchControlPointsEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    patchControlPoints) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
}

void GfrContext::PreCmdSetRasterizerDiscardEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    rasterizerDiscardEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable);
}
void GfrContext::PostCmdSetRasterizerDiscardEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    rasterizerDiscardEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable);
}

void GfrContext::PreCmdSetDepthBiasEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBiasEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable);
}
void GfrContext::PostCmdSetDepthBiasEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBiasEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable);
}

void GfrContext::PreCmdSetLogicOpEXT(
    VkCommandBuffer                             commandBuffer,
    VkLogicOp                                   logicOp) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetLogicOpEXT(commandBuffer, logicOp);
}
void GfrContext::PostCmdSetLogicOpEXT(
    VkCommandBuffer                             commandBuffer,
    VkLogicOp                                   logicOp) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetLogicOpEXT(commandBuffer, logicOp);
}

void GfrContext::PreCmdSetPrimitiveRestartEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    primitiveRestartEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable);
}
void GfrContext::PostCmdSetPrimitiveRestartEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    primitiveRestartEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable);
}

void                                    GfrContext::PreCmdSetColorWriteEnableEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkBool32*                             pColorWriteEnables) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
}
void                                    GfrContext::PostCmdSetColorWriteEnableEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkBool32*                             pColorWriteEnables) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
}

void GfrContext::PreCmdDrawMultiEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    drawCount,
    const VkMultiDrawInfoEXT*                   pVertexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawMultiEXT(commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
}
void GfrContext::PostCmdDrawMultiEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    drawCount,
    const VkMultiDrawInfoEXT*                   pVertexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawMultiEXT(commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
}

void GfrContext::PreCmdDrawMultiIndexedEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    drawCount,
    const VkMultiDrawIndexedInfoEXT*            pIndexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride,
    const int32_t*                              pVertexOffset) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawMultiIndexedEXT(commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
}
void GfrContext::PostCmdDrawMultiIndexedEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    drawCount,
    const VkMultiDrawIndexedInfoEXT*            pIndexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride,
    const int32_t*                              pVertexOffset) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawMultiIndexedEXT(commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
}

void GfrContext::PreCmdBuildMicromapsEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkMicromapBuildInfoEXT*               pInfos) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBuildMicromapsEXT(commandBuffer, infoCount, pInfos);
}
void GfrContext::PostCmdBuildMicromapsEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkMicromapBuildInfoEXT*               pInfos) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBuildMicromapsEXT(commandBuffer, infoCount, pInfos);
}

void GfrContext::PreCmdCopyMicromapEXT(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMicromapInfoEXT*                pInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyMicromapEXT(commandBuffer, pInfo);
}
void GfrContext::PostCmdCopyMicromapEXT(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMicromapInfoEXT*                pInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyMicromapEXT(commandBuffer, pInfo);
}

void GfrContext::PreCmdCopyMicromapToMemoryEXT(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMicromapToMemoryInfoEXT*        pInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyMicromapToMemoryEXT(commandBuffer, pInfo);
}
void GfrContext::PostCmdCopyMicromapToMemoryEXT(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMicromapToMemoryInfoEXT*        pInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyMicromapToMemoryEXT(commandBuffer, pInfo);
}

void GfrContext::PreCmdCopyMemoryToMicromapEXT(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMemoryToMicromapInfoEXT*        pInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyMemoryToMicromapEXT(commandBuffer, pInfo);
}
void GfrContext::PostCmdCopyMemoryToMicromapEXT(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMemoryToMicromapInfoEXT*        pInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyMemoryToMicromapEXT(commandBuffer, pInfo);
}

void GfrContext::PreCmdWriteMicromapsPropertiesEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    micromapCount,
    const VkMicromapEXT*                        pMicromaps,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdWriteMicromapsPropertiesEXT(commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);
}
void GfrContext::PostCmdWriteMicromapsPropertiesEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    micromapCount,
    const VkMicromapEXT*                        pMicromaps,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdWriteMicromapsPropertiesEXT(commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);
}

void GfrContext::PreCmdDrawClusterHUAWEI(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawClusterHUAWEI(commandBuffer, groupCountX, groupCountY, groupCountZ);
}
void GfrContext::PostCmdDrawClusterHUAWEI(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawClusterHUAWEI(commandBuffer, groupCountX, groupCountY, groupCountZ);
}

void GfrContext::PreCmdDrawClusterIndirectHUAWEI(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawClusterIndirectHUAWEI(commandBuffer, buffer, offset);
}
void GfrContext::PostCmdDrawClusterIndirectHUAWEI(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawClusterIndirectHUAWEI(commandBuffer, buffer, offset);
}

void GfrContext::PreCmdCopyMemoryIndirectNV(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             copyBufferAddress,
    uint32_t                                    copyCount,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyMemoryIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride);
}
void GfrContext::PostCmdCopyMemoryIndirectNV(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             copyBufferAddress,
    uint32_t                                    copyCount,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyMemoryIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride);
}

void GfrContext::PreCmdCopyMemoryToImageIndirectNV(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             copyBufferAddress,
    uint32_t                                    copyCount,
    uint32_t                                    stride,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    const VkImageSubresourceLayers*             pImageSubresources) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyMemoryToImageIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride, dstImage, dstImageLayout, pImageSubresources);
}
void GfrContext::PostCmdCopyMemoryToImageIndirectNV(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             copyBufferAddress,
    uint32_t                                    copyCount,
    uint32_t                                    stride,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    const VkImageSubresourceLayers*             pImageSubresources) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyMemoryToImageIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride, dstImage, dstImageLayout, pImageSubresources);
}

void GfrContext::PreCmdDecompressMemoryNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    decompressRegionCount,
    const VkDecompressMemoryRegionNV*           pDecompressMemoryRegions) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDecompressMemoryNV(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
}
void GfrContext::PostCmdDecompressMemoryNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    decompressRegionCount,
    const VkDecompressMemoryRegionNV*           pDecompressMemoryRegions) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDecompressMemoryNV(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
}

void GfrContext::PreCmdDecompressMemoryIndirectCountNV(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             indirectCommandsAddress,
    VkDeviceAddress                             indirectCommandsCountAddress,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDecompressMemoryIndirectCountNV(commandBuffer, indirectCommandsAddress, indirectCommandsCountAddress, stride);
}
void GfrContext::PostCmdDecompressMemoryIndirectCountNV(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             indirectCommandsAddress,
    VkDeviceAddress                             indirectCommandsCountAddress,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDecompressMemoryIndirectCountNV(commandBuffer, indirectCommandsAddress, indirectCommandsCountAddress, stride);
}

void GfrContext::PreCmdUpdatePipelineIndirectBufferNV(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdUpdatePipelineIndirectBufferNV(commandBuffer, pipelineBindPoint, pipeline);
}
void GfrContext::PostCmdUpdatePipelineIndirectBufferNV(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdUpdatePipelineIndirectBufferNV(commandBuffer, pipelineBindPoint, pipeline);
}

void GfrContext::PreCmdSetTessellationDomainOriginEXT(
    VkCommandBuffer                             commandBuffer,
    VkTessellationDomainOrigin                  domainOrigin) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetTessellationDomainOriginEXT(commandBuffer, domainOrigin);
}
void GfrContext::PostCmdSetTessellationDomainOriginEXT(
    VkCommandBuffer                             commandBuffer,
    VkTessellationDomainOrigin                  domainOrigin) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetTessellationDomainOriginEXT(commandBuffer, domainOrigin);
}

void GfrContext::PreCmdSetDepthClampEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthClampEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthClampEnableEXT(commandBuffer, depthClampEnable);
}
void GfrContext::PostCmdSetDepthClampEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthClampEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthClampEnableEXT(commandBuffer, depthClampEnable);
}

void GfrContext::PreCmdSetPolygonModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkPolygonMode                               polygonMode) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetPolygonModeEXT(commandBuffer, polygonMode);
}
void GfrContext::PostCmdSetPolygonModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkPolygonMode                               polygonMode) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetPolygonModeEXT(commandBuffer, polygonMode);
}

void GfrContext::PreCmdSetRasterizationSamplesEXT(
    VkCommandBuffer                             commandBuffer,
    VkSampleCountFlagBits                       rasterizationSamples) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetRasterizationSamplesEXT(commandBuffer, rasterizationSamples);
}
void GfrContext::PostCmdSetRasterizationSamplesEXT(
    VkCommandBuffer                             commandBuffer,
    VkSampleCountFlagBits                       rasterizationSamples) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetRasterizationSamplesEXT(commandBuffer, rasterizationSamples);
}

void GfrContext::PreCmdSetSampleMaskEXT(
    VkCommandBuffer                             commandBuffer,
    VkSampleCountFlagBits                       samples,
    const VkSampleMask*                         pSampleMask) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetSampleMaskEXT(commandBuffer, samples, pSampleMask);
}
void GfrContext::PostCmdSetSampleMaskEXT(
    VkCommandBuffer                             commandBuffer,
    VkSampleCountFlagBits                       samples,
    const VkSampleMask*                         pSampleMask) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetSampleMaskEXT(commandBuffer, samples, pSampleMask);
}

void GfrContext::PreCmdSetAlphaToCoverageEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    alphaToCoverageEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetAlphaToCoverageEnableEXT(commandBuffer, alphaToCoverageEnable);
}
void GfrContext::PostCmdSetAlphaToCoverageEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    alphaToCoverageEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetAlphaToCoverageEnableEXT(commandBuffer, alphaToCoverageEnable);
}

void GfrContext::PreCmdSetAlphaToOneEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    alphaToOneEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetAlphaToOneEnableEXT(commandBuffer, alphaToOneEnable);
}
void GfrContext::PostCmdSetAlphaToOneEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    alphaToOneEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetAlphaToOneEnableEXT(commandBuffer, alphaToOneEnable);
}

void GfrContext::PreCmdSetLogicOpEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    logicOpEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetLogicOpEnableEXT(commandBuffer, logicOpEnable);
}
void GfrContext::PostCmdSetLogicOpEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    logicOpEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetLogicOpEnableEXT(commandBuffer, logicOpEnable);
}

void GfrContext::PreCmdSetColorBlendEnableEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkBool32*                             pColorBlendEnables) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetColorBlendEnableEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
}
void GfrContext::PostCmdSetColorBlendEnableEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkBool32*                             pColorBlendEnables) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetColorBlendEnableEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
}

void GfrContext::PreCmdSetColorBlendEquationEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorBlendEquationEXT*              pColorBlendEquations) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetColorBlendEquationEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
}
void GfrContext::PostCmdSetColorBlendEquationEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorBlendEquationEXT*              pColorBlendEquations) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetColorBlendEquationEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
}

void GfrContext::PreCmdSetColorWriteMaskEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorComponentFlags*                pColorWriteMasks) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetColorWriteMaskEXT(commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
}
void GfrContext::PostCmdSetColorWriteMaskEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorComponentFlags*                pColorWriteMasks) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetColorWriteMaskEXT(commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
}

void GfrContext::PreCmdSetRasterizationStreamEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    rasterizationStream) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetRasterizationStreamEXT(commandBuffer, rasterizationStream);
}
void GfrContext::PostCmdSetRasterizationStreamEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    rasterizationStream) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetRasterizationStreamEXT(commandBuffer, rasterizationStream);
}

void GfrContext::PreCmdSetConservativeRasterizationModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkConservativeRasterizationModeEXT          conservativeRasterizationMode) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetConservativeRasterizationModeEXT(commandBuffer, conservativeRasterizationMode);
}
void GfrContext::PostCmdSetConservativeRasterizationModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkConservativeRasterizationModeEXT          conservativeRasterizationMode) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetConservativeRasterizationModeEXT(commandBuffer, conservativeRasterizationMode);
}

void GfrContext::PreCmdSetExtraPrimitiveOverestimationSizeEXT(
    VkCommandBuffer                             commandBuffer,
    float                                       extraPrimitiveOverestimationSize) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetExtraPrimitiveOverestimationSizeEXT(commandBuffer, extraPrimitiveOverestimationSize);
}
void GfrContext::PostCmdSetExtraPrimitiveOverestimationSizeEXT(
    VkCommandBuffer                             commandBuffer,
    float                                       extraPrimitiveOverestimationSize) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetExtraPrimitiveOverestimationSizeEXT(commandBuffer, extraPrimitiveOverestimationSize);
}

void GfrContext::PreCmdSetDepthClipEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthClipEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthClipEnableEXT(commandBuffer, depthClipEnable);
}
void GfrContext::PostCmdSetDepthClipEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthClipEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthClipEnableEXT(commandBuffer, depthClipEnable);
}

void GfrContext::PreCmdSetSampleLocationsEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    sampleLocationsEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetSampleLocationsEnableEXT(commandBuffer, sampleLocationsEnable);
}
void GfrContext::PostCmdSetSampleLocationsEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    sampleLocationsEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetSampleLocationsEnableEXT(commandBuffer, sampleLocationsEnable);
}

void GfrContext::PreCmdSetColorBlendAdvancedEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorBlendAdvancedEXT*              pColorBlendAdvanced) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetColorBlendAdvancedEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
}
void GfrContext::PostCmdSetColorBlendAdvancedEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorBlendAdvancedEXT*              pColorBlendAdvanced) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetColorBlendAdvancedEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
}

void GfrContext::PreCmdSetProvokingVertexModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkProvokingVertexModeEXT                    provokingVertexMode) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetProvokingVertexModeEXT(commandBuffer, provokingVertexMode);
}
void GfrContext::PostCmdSetProvokingVertexModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkProvokingVertexModeEXT                    provokingVertexMode) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetProvokingVertexModeEXT(commandBuffer, provokingVertexMode);
}

void GfrContext::PreCmdSetLineRasterizationModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkLineRasterizationModeEXT                  lineRasterizationMode) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetLineRasterizationModeEXT(commandBuffer, lineRasterizationMode);
}
void GfrContext::PostCmdSetLineRasterizationModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkLineRasterizationModeEXT                  lineRasterizationMode) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetLineRasterizationModeEXT(commandBuffer, lineRasterizationMode);
}

void GfrContext::PreCmdSetLineStippleEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stippledLineEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetLineStippleEnableEXT(commandBuffer, stippledLineEnable);
}
void GfrContext::PostCmdSetLineStippleEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stippledLineEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetLineStippleEnableEXT(commandBuffer, stippledLineEnable);
}

void GfrContext::PreCmdSetDepthClipNegativeOneToOneEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    negativeOneToOne) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthClipNegativeOneToOneEXT(commandBuffer, negativeOneToOne);
}
void GfrContext::PostCmdSetDepthClipNegativeOneToOneEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    negativeOneToOne) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthClipNegativeOneToOneEXT(commandBuffer, negativeOneToOne);
}

void GfrContext::PreCmdSetViewportWScalingEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    viewportWScalingEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetViewportWScalingEnableNV(commandBuffer, viewportWScalingEnable);
}
void GfrContext::PostCmdSetViewportWScalingEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    viewportWScalingEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetViewportWScalingEnableNV(commandBuffer, viewportWScalingEnable);
}

void GfrContext::PreCmdSetViewportSwizzleNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewportSwizzleNV*                  pViewportSwizzles) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetViewportSwizzleNV(commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
}
void GfrContext::PostCmdSetViewportSwizzleNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewportSwizzleNV*                  pViewportSwizzles) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetViewportSwizzleNV(commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
}

void GfrContext::PreCmdSetCoverageToColorEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    coverageToColorEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetCoverageToColorEnableNV(commandBuffer, coverageToColorEnable);
}
void GfrContext::PostCmdSetCoverageToColorEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    coverageToColorEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetCoverageToColorEnableNV(commandBuffer, coverageToColorEnable);
}

void GfrContext::PreCmdSetCoverageToColorLocationNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    coverageToColorLocation) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetCoverageToColorLocationNV(commandBuffer, coverageToColorLocation);
}
void GfrContext::PostCmdSetCoverageToColorLocationNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    coverageToColorLocation) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetCoverageToColorLocationNV(commandBuffer, coverageToColorLocation);
}

void GfrContext::PreCmdSetCoverageModulationModeNV(
    VkCommandBuffer                             commandBuffer,
    VkCoverageModulationModeNV                  coverageModulationMode) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetCoverageModulationModeNV(commandBuffer, coverageModulationMode);
}
void GfrContext::PostCmdSetCoverageModulationModeNV(
    VkCommandBuffer                             commandBuffer,
    VkCoverageModulationModeNV                  coverageModulationMode) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetCoverageModulationModeNV(commandBuffer, coverageModulationMode);
}

void GfrContext::PreCmdSetCoverageModulationTableEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    coverageModulationTableEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetCoverageModulationTableEnableNV(commandBuffer, coverageModulationTableEnable);
}
void GfrContext::PostCmdSetCoverageModulationTableEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    coverageModulationTableEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetCoverageModulationTableEnableNV(commandBuffer, coverageModulationTableEnable);
}

void GfrContext::PreCmdSetCoverageModulationTableNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    coverageModulationTableCount,
    const float*                                pCoverageModulationTable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetCoverageModulationTableNV(commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
}
void GfrContext::PostCmdSetCoverageModulationTableNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    coverageModulationTableCount,
    const float*                                pCoverageModulationTable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetCoverageModulationTableNV(commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
}

void GfrContext::PreCmdSetShadingRateImageEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    shadingRateImageEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetShadingRateImageEnableNV(commandBuffer, shadingRateImageEnable);
}
void GfrContext::PostCmdSetShadingRateImageEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    shadingRateImageEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetShadingRateImageEnableNV(commandBuffer, shadingRateImageEnable);
}

void GfrContext::PreCmdSetRepresentativeFragmentTestEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    representativeFragmentTestEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetRepresentativeFragmentTestEnableNV(commandBuffer, representativeFragmentTestEnable);
}
void GfrContext::PostCmdSetRepresentativeFragmentTestEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    representativeFragmentTestEnable) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetRepresentativeFragmentTestEnableNV(commandBuffer, representativeFragmentTestEnable);
}

void GfrContext::PreCmdSetCoverageReductionModeNV(
    VkCommandBuffer                             commandBuffer,
    VkCoverageReductionModeNV                   coverageReductionMode) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetCoverageReductionModeNV(commandBuffer, coverageReductionMode);
}
void GfrContext::PostCmdSetCoverageReductionModeNV(
    VkCommandBuffer                             commandBuffer,
    VkCoverageReductionModeNV                   coverageReductionMode) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetCoverageReductionModeNV(commandBuffer, coverageReductionMode);
}

void GfrContext::PreCmdOpticalFlowExecuteNV(
    VkCommandBuffer                             commandBuffer,
    VkOpticalFlowSessionNV                      session,
    const VkOpticalFlowExecuteInfoNV*           pExecuteInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdOpticalFlowExecuteNV(commandBuffer, session, pExecuteInfo);
}
void GfrContext::PostCmdOpticalFlowExecuteNV(
    VkCommandBuffer                             commandBuffer,
    VkOpticalFlowSessionNV                      session,
    const VkOpticalFlowExecuteInfoNV*           pExecuteInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdOpticalFlowExecuteNV(commandBuffer, session, pExecuteInfo);
}

void GfrContext::PreCmdBindShadersEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    stageCount,
    const VkShaderStageFlagBits*                pStages,
    const VkShaderEXT*                          pShaders) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBindShadersEXT(commandBuffer, stageCount, pStages, pShaders);
}
void GfrContext::PostCmdBindShadersEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    stageCount,
    const VkShaderStageFlagBits*                pStages,
    const VkShaderEXT*                          pShaders) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBindShadersEXT(commandBuffer, stageCount, pStages, pShaders);
}

void GfrContext::PreCmdSetAttachmentFeedbackLoopEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkImageAspectFlags                          aspectMask) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetAttachmentFeedbackLoopEnableEXT(commandBuffer, aspectMask);
}
void GfrContext::PostCmdSetAttachmentFeedbackLoopEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkImageAspectFlags                          aspectMask) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetAttachmentFeedbackLoopEnableEXT(commandBuffer, aspectMask);
}

void GfrContext::PreCmdBuildAccelerationStructuresKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
}
void GfrContext::PostCmdBuildAccelerationStructuresKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
}

void GfrContext::PreCmdBuildAccelerationStructuresIndirectKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkDeviceAddress*                      pIndirectDeviceAddresses,
    const uint32_t*                             pIndirectStrides,
    const uint32_t* const*                      ppMaxPrimitiveCounts) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdBuildAccelerationStructuresIndirectKHR(commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
}
void GfrContext::PostCmdBuildAccelerationStructuresIndirectKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkDeviceAddress*                      pIndirectDeviceAddresses,
    const uint32_t*                             pIndirectStrides,
    const uint32_t* const*                      ppMaxPrimitiveCounts) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdBuildAccelerationStructuresIndirectKHR(commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
}

void GfrContext::PreCmdCopyAccelerationStructureKHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyAccelerationStructureInfoKHR*   pInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyAccelerationStructureKHR(commandBuffer, pInfo);
}
void GfrContext::PostCmdCopyAccelerationStructureKHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyAccelerationStructureInfoKHR*   pInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyAccelerationStructureKHR(commandBuffer, pInfo);
}

void GfrContext::PreCmdCopyAccelerationStructureToMemoryKHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);
}
void GfrContext::PostCmdCopyAccelerationStructureToMemoryKHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);
}

void GfrContext::PreCmdCopyMemoryToAccelerationStructureKHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);
}
void GfrContext::PostCmdCopyMemoryToAccelerationStructureKHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);
}

void GfrContext::PreCmdWriteAccelerationStructuresPropertiesKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    accelerationStructureCount,
    const VkAccelerationStructureKHR*           pAccelerationStructures,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdWriteAccelerationStructuresPropertiesKHR(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}
void GfrContext::PostCmdWriteAccelerationStructuresPropertiesKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    accelerationStructureCount,
    const VkAccelerationStructureKHR*           pAccelerationStructures,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdWriteAccelerationStructuresPropertiesKHR(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}

void GfrContext::PreCmdTraceRaysKHR(
    VkCommandBuffer                             commandBuffer,
    const VkStridedDeviceAddressRegionKHR*      pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pCallableShaderBindingTable,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdTraceRaysKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
}
void GfrContext::PostCmdTraceRaysKHR(
    VkCommandBuffer                             commandBuffer,
    const VkStridedDeviceAddressRegionKHR*      pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pCallableShaderBindingTable,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdTraceRaysKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
}

void GfrContext::PreCmdTraceRaysIndirectKHR(
    VkCommandBuffer                             commandBuffer,
    const VkStridedDeviceAddressRegionKHR*      pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pCallableShaderBindingTable,
    VkDeviceAddress                             indirectDeviceAddress) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdTraceRaysIndirectKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
}
void GfrContext::PostCmdTraceRaysIndirectKHR(
    VkCommandBuffer                             commandBuffer,
    const VkStridedDeviceAddressRegionKHR*      pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pCallableShaderBindingTable,
    VkDeviceAddress                             indirectDeviceAddress) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdTraceRaysIndirectKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
}

void GfrContext::PreCmdSetRayTracingPipelineStackSizeKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    pipelineStackSize) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);
}
void GfrContext::PostCmdSetRayTracingPipelineStackSizeKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    pipelineStackSize) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);
}

void GfrContext::PreCmdDrawMeshTasksEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawMeshTasksEXT(commandBuffer, groupCountX, groupCountY, groupCountZ);
}
void GfrContext::PostCmdDrawMeshTasksEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawMeshTasksEXT(commandBuffer, groupCountX, groupCountY, groupCountZ);
}

void GfrContext::PreCmdDrawMeshTasksIndirectEXT(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawMeshTasksIndirectEXT(commandBuffer, buffer, offset, drawCount, stride);
}
void GfrContext::PostCmdDrawMeshTasksIndirectEXT(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawMeshTasksIndirectEXT(commandBuffer, buffer, offset, drawCount, stride);
}

void GfrContext::PreCmdDrawMeshTasksIndirectCountEXT(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawMeshTasksIndirectCountEXT(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
void GfrContext::PostCmdDrawMeshTasksIndirectCountEXT(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = graphics_flight_recorder::GetGfrCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawMeshTasksIndirectCountEXT(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}



// NOLINTEND

