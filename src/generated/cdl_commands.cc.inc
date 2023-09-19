
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

VkResult CdlContext::PostBeginCommandBuffer(
    VkCommandBuffer                             commandBuffer,
    const VkCommandBufferBeginInfo*             pBeginInfo,
    VkResult                                    result) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  return p_cmd->PostBeginCommandBuffer(commandBuffer, pBeginInfo, result);
}

VkResult CdlContext::PreEndCommandBuffer(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  return p_cmd->PreEndCommandBuffer(commandBuffer);
}
VkResult CdlContext::PostEndCommandBuffer(
    VkCommandBuffer                             commandBuffer,
    VkResult                                    result) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  return p_cmd->PostEndCommandBuffer(commandBuffer, result);
}

VkResult CdlContext::PostResetCommandBuffer(
    VkCommandBuffer                             commandBuffer,
    VkCommandBufferResetFlags                   flags,
    VkResult                                    result) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  return p_cmd->PostResetCommandBuffer(commandBuffer, flags, result);
}

void CdlContext::PostCmdBindPipeline(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
}

void CdlContext::PreCmdSetViewport(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
}
void CdlContext::PostCmdSetViewport(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
}

void CdlContext::PreCmdSetScissor(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
}
void CdlContext::PostCmdSetScissor(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
}

void CdlContext::PreCmdSetLineWidth(
    VkCommandBuffer                             commandBuffer,
    float                                       lineWidth) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetLineWidth(commandBuffer, lineWidth);
}
void CdlContext::PostCmdSetLineWidth(
    VkCommandBuffer                             commandBuffer,
    float                                       lineWidth) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetLineWidth(commandBuffer, lineWidth);
}

void CdlContext::PreCmdSetDepthBias(
    VkCommandBuffer                             commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
}
void CdlContext::PostCmdSetDepthBias(
    VkCommandBuffer                             commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
}

void CdlContext::PreCmdSetBlendConstants(
    VkCommandBuffer                             commandBuffer,
    const float                                 blendConstants[4]) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetBlendConstants(commandBuffer, blendConstants);
}
void CdlContext::PostCmdSetBlendConstants(
    VkCommandBuffer                             commandBuffer,
    const float                                 blendConstants[4]) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetBlendConstants(commandBuffer, blendConstants);
}

void CdlContext::PreCmdSetDepthBounds(
    VkCommandBuffer                             commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
}
void CdlContext::PostCmdSetDepthBounds(
    VkCommandBuffer                             commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
}

void CdlContext::PreCmdSetStencilCompareMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
}
void CdlContext::PostCmdSetStencilCompareMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
}

void CdlContext::PreCmdSetStencilWriteMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
}
void CdlContext::PostCmdSetStencilWriteMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
}

void CdlContext::PreCmdSetStencilReference(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetStencilReference(commandBuffer, faceMask, reference);
}
void CdlContext::PostCmdSetStencilReference(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetStencilReference(commandBuffer, faceMask, reference);
}

void CdlContext::PreCmdBindDescriptorSets(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    descriptorSetCount,
    const VkDescriptorSet*                      pDescriptorSets,
    uint32_t                                    dynamicOffsetCount,
    const uint32_t*                             pDynamicOffsets) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
}
void CdlContext::PostCmdBindDescriptorSets(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    descriptorSetCount,
    const VkDescriptorSet*                      pDescriptorSets,
    uint32_t                                    dynamicOffsetCount,
    const uint32_t*                             pDynamicOffsets) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
}

void CdlContext::PreCmdBindIndexBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
}
void CdlContext::PostCmdBindIndexBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
}

void CdlContext::PreCmdBindVertexBuffers(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
}
void CdlContext::PostCmdBindVertexBuffers(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
}

void CdlContext::PreCmdDraw(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}
void CdlContext::PostCmdDraw(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}

void CdlContext::PreCmdDrawIndexed(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}
void CdlContext::PostCmdDrawIndexed(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}

void CdlContext::PreCmdDrawIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
}
void CdlContext::PostCmdDrawIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
}

void CdlContext::PreCmdDrawIndexedIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
}
void CdlContext::PostCmdDrawIndexedIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
}

void CdlContext::PreCmdDispatch(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
}
void CdlContext::PostCmdDispatch(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
}

void CdlContext::PreCmdDispatchIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDispatchIndirect(commandBuffer, buffer, offset);
}
void CdlContext::PostCmdDispatchIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDispatchIndirect(commandBuffer, buffer, offset);
}

void CdlContext::PreCmdCopyBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferCopy*                         pRegions) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
}
void CdlContext::PostCmdCopyBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferCopy*                         pRegions) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
}

void CdlContext::PreCmdCopyImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageCopy*                          pRegions) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}
void CdlContext::PostCmdCopyImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageCopy*                          pRegions) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}

void CdlContext::PreCmdBlitImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageBlit*                          pRegions,
    VkFilter                                    filter) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
}
void CdlContext::PostCmdBlitImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageBlit*                          pRegions,
    VkFilter                                    filter) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
}

void CdlContext::PreCmdCopyBufferToImage(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
}
void CdlContext::PostCmdCopyBufferToImage(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
}

void CdlContext::PreCmdCopyImageToBuffer(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
}
void CdlContext::PostCmdCopyImageToBuffer(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
}

void CdlContext::PreCmdUpdateBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    const void*                                 pData) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
}
void CdlContext::PostCmdUpdateBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    const void*                                 pData) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
}

void CdlContext::PreCmdFillBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
}
void CdlContext::PostCmdFillBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
}

void CdlContext::PreCmdClearColorImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearColorValue*                    pColor,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
}
void CdlContext::PostCmdClearColorImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearColorValue*                    pColor,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
}

void CdlContext::PreCmdClearDepthStencilImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearDepthStencilValue*             pDepthStencil,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
}
void CdlContext::PostCmdClearDepthStencilImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearDepthStencilValue*             pDepthStencil,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
}

void CdlContext::PreCmdClearAttachments(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkClearAttachment*                    pAttachments,
    uint32_t                                    rectCount,
    const VkClearRect*                          pRects) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
}
void CdlContext::PostCmdClearAttachments(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkClearAttachment*                    pAttachments,
    uint32_t                                    rectCount,
    const VkClearRect*                          pRects) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
}

void CdlContext::PreCmdResolveImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageResolve*                       pRegions) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}
void CdlContext::PostCmdResolveImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageResolve*                       pRegions) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}

void CdlContext::PreCmdSetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetEvent(commandBuffer, event, stageMask);
}
void CdlContext::PostCmdSetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetEvent(commandBuffer, event, stageMask);
}

void CdlContext::PreCmdResetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdResetEvent(commandBuffer, event, stageMask);
}
void CdlContext::PostCmdResetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdResetEvent(commandBuffer, event, stageMask);
}

void CdlContext::PreCmdWaitEvents(
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
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}
void CdlContext::PostCmdWaitEvents(
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
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}

void CdlContext::PreCmdPipelineBarrier(
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
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}
void CdlContext::PostCmdPipelineBarrier(
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
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}

void CdlContext::PreCmdBeginQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBeginQuery(commandBuffer, queryPool, query, flags);
}
void CdlContext::PostCmdBeginQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBeginQuery(commandBuffer, queryPool, query, flags);
}

void CdlContext::PreCmdEndQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdEndQuery(commandBuffer, queryPool, query);
}
void CdlContext::PostCmdEndQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdEndQuery(commandBuffer, queryPool, query);
}

void CdlContext::PreCmdResetQueryPool(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
}
void CdlContext::PostCmdResetQueryPool(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
}

void CdlContext::PreCmdWriteTimestamp(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
}
void CdlContext::PostCmdWriteTimestamp(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
}

void CdlContext::PreCmdCopyQueryPoolResults(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
}
void CdlContext::PostCmdCopyQueryPoolResults(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
}

void CdlContext::PreCmdPushConstants(
    VkCommandBuffer                             commandBuffer,
    VkPipelineLayout                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    const void*                                 pValues) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
}
void CdlContext::PostCmdPushConstants(
    VkCommandBuffer                             commandBuffer,
    VkPipelineLayout                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    const void*                                 pValues) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
}

void CdlContext::PreCmdBeginRenderPass(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    VkSubpassContents                           contents) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
}
void CdlContext::PostCmdBeginRenderPass(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    VkSubpassContents                           contents) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
}

void CdlContext::PreCmdNextSubpass(
    VkCommandBuffer                             commandBuffer,
    VkSubpassContents                           contents) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdNextSubpass(commandBuffer, contents);
}
void CdlContext::PostCmdNextSubpass(
    VkCommandBuffer                             commandBuffer,
    VkSubpassContents                           contents) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdNextSubpass(commandBuffer, contents);
}

void CdlContext::PreCmdEndRenderPass(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdEndRenderPass(commandBuffer);
}
void CdlContext::PostCmdEndRenderPass(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdEndRenderPass(commandBuffer);
}

void CdlContext::PreCmdExecuteCommands(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
}
void CdlContext::PostCmdExecuteCommands(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
}

void CdlContext::PreCmdSetDeviceMask(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDeviceMask(commandBuffer, deviceMask);
}
void CdlContext::PostCmdSetDeviceMask(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDeviceMask(commandBuffer, deviceMask);
}

void CdlContext::PreCmdDispatchBase(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}
void CdlContext::PostCmdDispatchBase(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

void CdlContext::PreCmdDrawIndirectCount(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
void CdlContext::PostCmdDrawIndirectCount(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void CdlContext::PreCmdDrawIndexedIndirectCount(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
void CdlContext::PostCmdDrawIndexedIndirectCount(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void CdlContext::PreCmdBeginRenderPass2(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}
void CdlContext::PostCmdBeginRenderPass2(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

void CdlContext::PreCmdNextSubpass2(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo,
    const VkSubpassEndInfo*                     pSubpassEndInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}
void CdlContext::PostCmdNextSubpass2(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo,
    const VkSubpassEndInfo*                     pSubpassEndInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}

void CdlContext::PreCmdEndRenderPass2(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassEndInfo*                     pSubpassEndInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
}
void CdlContext::PostCmdEndRenderPass2(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassEndInfo*                     pSubpassEndInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
}

void CdlContext::PreCmdSetEvent2(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    const VkDependencyInfo*                     pDependencyInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetEvent2(commandBuffer, event, pDependencyInfo);
}
void CdlContext::PostCmdSetEvent2(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    const VkDependencyInfo*                     pDependencyInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetEvent2(commandBuffer, event, pDependencyInfo);
}

void CdlContext::PreCmdResetEvent2(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags2                       stageMask) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdResetEvent2(commandBuffer, event, stageMask);
}
void CdlContext::PostCmdResetEvent2(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags2                       stageMask) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdResetEvent2(commandBuffer, event, stageMask);
}

void CdlContext::PreCmdWaitEvents2(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    const VkDependencyInfo*                     pDependencyInfos) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
}
void CdlContext::PostCmdWaitEvents2(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    const VkDependencyInfo*                     pDependencyInfos) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
}

void CdlContext::PreCmdPipelineBarrier2(
    VkCommandBuffer                             commandBuffer,
    const VkDependencyInfo*                     pDependencyInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdPipelineBarrier2(commandBuffer, pDependencyInfo);
}
void CdlContext::PostCmdPipelineBarrier2(
    VkCommandBuffer                             commandBuffer,
    const VkDependencyInfo*                     pDependencyInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdPipelineBarrier2(commandBuffer, pDependencyInfo);
}

void CdlContext::PreCmdWriteTimestamp2(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
}
void CdlContext::PostCmdWriteTimestamp2(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
}

void CdlContext::PreCmdCopyBuffer2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferInfo2*                    pCopyBufferInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
}
void CdlContext::PostCmdCopyBuffer2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferInfo2*                    pCopyBufferInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
}

void CdlContext::PreCmdCopyImage2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageInfo2*                     pCopyImageInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyImage2(commandBuffer, pCopyImageInfo);
}
void CdlContext::PostCmdCopyImage2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageInfo2*                     pCopyImageInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyImage2(commandBuffer, pCopyImageInfo);
}

void CdlContext::PreCmdCopyBufferToImage2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferToImageInfo2*             pCopyBufferToImageInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
}
void CdlContext::PostCmdCopyBufferToImage2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferToImageInfo2*             pCopyBufferToImageInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
}

void CdlContext::PreCmdCopyImageToBuffer2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageToBufferInfo2*             pCopyImageToBufferInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
}
void CdlContext::PostCmdCopyImageToBuffer2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageToBufferInfo2*             pCopyImageToBufferInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
}

void CdlContext::PreCmdBlitImage2(
    VkCommandBuffer                             commandBuffer,
    const VkBlitImageInfo2*                     pBlitImageInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBlitImage2(commandBuffer, pBlitImageInfo);
}
void CdlContext::PostCmdBlitImage2(
    VkCommandBuffer                             commandBuffer,
    const VkBlitImageInfo2*                     pBlitImageInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBlitImage2(commandBuffer, pBlitImageInfo);
}

void CdlContext::PreCmdResolveImage2(
    VkCommandBuffer                             commandBuffer,
    const VkResolveImageInfo2*                  pResolveImageInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdResolveImage2(commandBuffer, pResolveImageInfo);
}
void CdlContext::PostCmdResolveImage2(
    VkCommandBuffer                             commandBuffer,
    const VkResolveImageInfo2*                  pResolveImageInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdResolveImage2(commandBuffer, pResolveImageInfo);
}

void CdlContext::PreCmdBeginRendering(
    VkCommandBuffer                             commandBuffer,
    const VkRenderingInfo*                      pRenderingInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBeginRendering(commandBuffer, pRenderingInfo);
}
void CdlContext::PostCmdBeginRendering(
    VkCommandBuffer                             commandBuffer,
    const VkRenderingInfo*                      pRenderingInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBeginRendering(commandBuffer, pRenderingInfo);
}

void CdlContext::PreCmdEndRendering(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdEndRendering(commandBuffer);
}
void CdlContext::PostCmdEndRendering(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdEndRendering(commandBuffer);
}

void CdlContext::PreCmdSetCullMode(
    VkCommandBuffer                             commandBuffer,
    VkCullModeFlags                             cullMode) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetCullMode(commandBuffer, cullMode);
}
void CdlContext::PostCmdSetCullMode(
    VkCommandBuffer                             commandBuffer,
    VkCullModeFlags                             cullMode) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetCullMode(commandBuffer, cullMode);
}

void CdlContext::PreCmdSetFrontFace(
    VkCommandBuffer                             commandBuffer,
    VkFrontFace                                 frontFace) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetFrontFace(commandBuffer, frontFace);
}
void CdlContext::PostCmdSetFrontFace(
    VkCommandBuffer                             commandBuffer,
    VkFrontFace                                 frontFace) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetFrontFace(commandBuffer, frontFace);
}

void CdlContext::PreCmdSetPrimitiveTopology(
    VkCommandBuffer                             commandBuffer,
    VkPrimitiveTopology                         primitiveTopology) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
}
void CdlContext::PostCmdSetPrimitiveTopology(
    VkCommandBuffer                             commandBuffer,
    VkPrimitiveTopology                         primitiveTopology) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
}

void CdlContext::PreCmdSetViewportWithCount(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
}
void CdlContext::PostCmdSetViewportWithCount(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
}

void CdlContext::PreCmdSetScissorWithCount(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
}
void CdlContext::PostCmdSetScissorWithCount(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
}

void CdlContext::PreCmdBindVertexBuffers2(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes,
    const VkDeviceSize*                         pStrides) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}
void CdlContext::PostCmdBindVertexBuffers2(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes,
    const VkDeviceSize*                         pStrides) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}

void CdlContext::PreCmdSetDepthTestEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthTestEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthTestEnable(commandBuffer, depthTestEnable);
}
void CdlContext::PostCmdSetDepthTestEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthTestEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthTestEnable(commandBuffer, depthTestEnable);
}

void CdlContext::PreCmdSetDepthWriteEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthWriteEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
}
void CdlContext::PostCmdSetDepthWriteEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthWriteEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
}

void CdlContext::PreCmdSetDepthCompareOp(
    VkCommandBuffer                             commandBuffer,
    VkCompareOp                                 depthCompareOp) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthCompareOp(commandBuffer, depthCompareOp);
}
void CdlContext::PostCmdSetDepthCompareOp(
    VkCommandBuffer                             commandBuffer,
    VkCompareOp                                 depthCompareOp) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthCompareOp(commandBuffer, depthCompareOp);
}

void CdlContext::PreCmdSetDepthBoundsTestEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBoundsTestEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
}
void CdlContext::PostCmdSetDepthBoundsTestEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBoundsTestEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
}

void CdlContext::PreCmdSetStencilTestEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stencilTestEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
}
void CdlContext::PostCmdSetStencilTestEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stencilTestEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
}

void CdlContext::PreCmdSetStencilOp(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}
void CdlContext::PostCmdSetStencilOp(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}

void CdlContext::PreCmdSetRasterizerDiscardEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    rasterizerDiscardEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
}
void CdlContext::PostCmdSetRasterizerDiscardEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    rasterizerDiscardEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
}

void CdlContext::PreCmdSetDepthBiasEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBiasEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
}
void CdlContext::PostCmdSetDepthBiasEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBiasEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
}

void CdlContext::PreCmdSetPrimitiveRestartEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    primitiveRestartEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
}
void CdlContext::PostCmdSetPrimitiveRestartEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    primitiveRestartEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
}

void CdlContext::PreCmdBeginVideoCodingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoBeginCodingInfoKHR*            pBeginInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);
}
void CdlContext::PostCmdBeginVideoCodingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoBeginCodingInfoKHR*            pBeginInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);
}

void CdlContext::PreCmdEndVideoCodingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoEndCodingInfoKHR*              pEndCodingInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);
}
void CdlContext::PostCmdEndVideoCodingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoEndCodingInfoKHR*              pEndCodingInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);
}

void CdlContext::PreCmdControlVideoCodingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoCodingControlInfoKHR*          pCodingControlInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);
}
void CdlContext::PostCmdControlVideoCodingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoCodingControlInfoKHR*          pCodingControlInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);
}

void CdlContext::PreCmdDecodeVideoKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoDecodeInfoKHR*                 pDecodeInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDecodeVideoKHR(commandBuffer, pDecodeInfo);
}
void CdlContext::PostCmdDecodeVideoKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoDecodeInfoKHR*                 pDecodeInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDecodeVideoKHR(commandBuffer, pDecodeInfo);
}

void CdlContext::PreCmdBeginRenderingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkRenderingInfo*                      pRenderingInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBeginRenderingKHR(commandBuffer, pRenderingInfo);
}
void CdlContext::PostCmdBeginRenderingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkRenderingInfo*                      pRenderingInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBeginRenderingKHR(commandBuffer, pRenderingInfo);
}

void CdlContext::PreCmdEndRenderingKHR(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdEndRenderingKHR(commandBuffer);
}
void CdlContext::PostCmdEndRenderingKHR(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdEndRenderingKHR(commandBuffer);
}

void CdlContext::PreCmdSetDeviceMaskKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDeviceMaskKHR(commandBuffer, deviceMask);
}
void CdlContext::PostCmdSetDeviceMaskKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDeviceMaskKHR(commandBuffer, deviceMask);
}

void CdlContext::PreCmdDispatchBaseKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}
void CdlContext::PostCmdDispatchBaseKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

void CdlContext::PreCmdPushDescriptorSetKHR(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    const VkWriteDescriptorSet*                 pDescriptorWrites) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
}
void CdlContext::PostCmdPushDescriptorSetKHR(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    const VkWriteDescriptorSet*                 pDescriptorWrites) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
}

void CdlContext::PreCmdPushDescriptorSetWithTemplateKHR(
    VkCommandBuffer                             commandBuffer,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    VkPipelineLayout                            layout,
    uint32_t                                    set,
    const void*                                 pData) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
}
void CdlContext::PostCmdPushDescriptorSetWithTemplateKHR(
    VkCommandBuffer                             commandBuffer,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    VkPipelineLayout                            layout,
    uint32_t                                    set,
    const void*                                 pData) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
}

void CdlContext::PreCmdBeginRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}
void CdlContext::PostCmdBeginRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

void CdlContext::PreCmdNextSubpass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo,
    const VkSubpassEndInfo*                     pSubpassEndInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}
void CdlContext::PostCmdNextSubpass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo,
    const VkSubpassEndInfo*                     pSubpassEndInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}

void CdlContext::PreCmdEndRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassEndInfo*                     pSubpassEndInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);
}
void CdlContext::PostCmdEndRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassEndInfo*                     pSubpassEndInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);
}

void CdlContext::PreCmdDrawIndirectCountKHR(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
void CdlContext::PostCmdDrawIndirectCountKHR(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void CdlContext::PreCmdDrawIndexedIndirectCountKHR(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
void CdlContext::PostCmdDrawIndexedIndirectCountKHR(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void CdlContext::PreCmdSetFragmentShadingRateKHR(
    VkCommandBuffer                             commandBuffer,
    const VkExtent2D*                           pFragmentSize,
    const VkFragmentShadingRateCombinerOpKHR    combinerOps[2]) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
}
void CdlContext::PostCmdSetFragmentShadingRateKHR(
    VkCommandBuffer                             commandBuffer,
    const VkExtent2D*                           pFragmentSize,
    const VkFragmentShadingRateCombinerOpKHR    combinerOps[2]) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
}

#ifdef VK_ENABLE_BETA_EXTENSIONS
void CdlContext::PreCmdEncodeVideoKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoEncodeInfoKHR*                 pEncodeInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdEncodeVideoKHR(commandBuffer, pEncodeInfo);
}
void CdlContext::PostCmdEncodeVideoKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoEncodeInfoKHR*                 pEncodeInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdEncodeVideoKHR(commandBuffer, pEncodeInfo);
}
#endif //VK_ENABLE_BETA_EXTENSIONS

void CdlContext::PreCmdSetEvent2KHR(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    const VkDependencyInfo*                     pDependencyInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetEvent2KHR(commandBuffer, event, pDependencyInfo);
}
void CdlContext::PostCmdSetEvent2KHR(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    const VkDependencyInfo*                     pDependencyInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetEvent2KHR(commandBuffer, event, pDependencyInfo);
}

void CdlContext::PreCmdResetEvent2KHR(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags2                       stageMask) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdResetEvent2KHR(commandBuffer, event, stageMask);
}
void CdlContext::PostCmdResetEvent2KHR(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags2                       stageMask) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdResetEvent2KHR(commandBuffer, event, stageMask);
}

void CdlContext::PreCmdWaitEvents2KHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    const VkDependencyInfo*                     pDependencyInfos) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos);
}
void CdlContext::PostCmdWaitEvents2KHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    const VkDependencyInfo*                     pDependencyInfos) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos);
}

void CdlContext::PreCmdPipelineBarrier2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkDependencyInfo*                     pDependencyInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo);
}
void CdlContext::PostCmdPipelineBarrier2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkDependencyInfo*                     pDependencyInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo);
}

void CdlContext::PreCmdWriteTimestamp2KHR(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query);
}
void CdlContext::PostCmdWriteTimestamp2KHR(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query);
}

void CdlContext::PreCmdWriteBufferMarker2AMD(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
}
void CdlContext::PostCmdWriteBufferMarker2AMD(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
}

void CdlContext::PreCmdCopyBuffer2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferInfo2*                    pCopyBufferInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);
}
void CdlContext::PostCmdCopyBuffer2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferInfo2*                    pCopyBufferInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);
}

void CdlContext::PreCmdCopyImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageInfo2*                     pCopyImageInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyImage2KHR(commandBuffer, pCopyImageInfo);
}
void CdlContext::PostCmdCopyImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageInfo2*                     pCopyImageInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyImage2KHR(commandBuffer, pCopyImageInfo);
}

void CdlContext::PreCmdCopyBufferToImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferToImageInfo2*             pCopyBufferToImageInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);
}
void CdlContext::PostCmdCopyBufferToImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferToImageInfo2*             pCopyBufferToImageInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);
}

void CdlContext::PreCmdCopyImageToBuffer2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageToBufferInfo2*             pCopyImageToBufferInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);
}
void CdlContext::PostCmdCopyImageToBuffer2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageToBufferInfo2*             pCopyImageToBufferInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);
}

void CdlContext::PreCmdBlitImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkBlitImageInfo2*                     pBlitImageInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBlitImage2KHR(commandBuffer, pBlitImageInfo);
}
void CdlContext::PostCmdBlitImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkBlitImageInfo2*                     pBlitImageInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBlitImage2KHR(commandBuffer, pBlitImageInfo);
}

void CdlContext::PreCmdResolveImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkResolveImageInfo2*                  pResolveImageInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdResolveImage2KHR(commandBuffer, pResolveImageInfo);
}
void CdlContext::PostCmdResolveImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkResolveImageInfo2*                  pResolveImageInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdResolveImage2KHR(commandBuffer, pResolveImageInfo);
}

void CdlContext::PreCmdTraceRaysIndirect2KHR(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             indirectDeviceAddress) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdTraceRaysIndirect2KHR(commandBuffer, indirectDeviceAddress);
}
void CdlContext::PostCmdTraceRaysIndirect2KHR(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             indirectDeviceAddress) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdTraceRaysIndirect2KHR(commandBuffer, indirectDeviceAddress);
}

void CdlContext::PreCmdDebugMarkerBeginEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
}
void CdlContext::PostCmdDebugMarkerBeginEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
}

void CdlContext::PreCmdDebugMarkerEndEXT(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDebugMarkerEndEXT(commandBuffer);
}
void CdlContext::PostCmdDebugMarkerEndEXT(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDebugMarkerEndEXT(commandBuffer);
}

void CdlContext::PreCmdDebugMarkerInsertEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
}
void CdlContext::PostCmdDebugMarkerInsertEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
}

void CdlContext::PreCmdBindTransformFeedbackBuffersEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
}
void CdlContext::PostCmdBindTransformFeedbackBuffersEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
}

void CdlContext::PreCmdBeginTransformFeedbackEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const VkBuffer*                             pCounterBuffers,
    const VkDeviceSize*                         pCounterBufferOffsets) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}
void CdlContext::PostCmdBeginTransformFeedbackEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const VkBuffer*                             pCounterBuffers,
    const VkDeviceSize*                         pCounterBufferOffsets) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}

void CdlContext::PreCmdEndTransformFeedbackEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const VkBuffer*                             pCounterBuffers,
    const VkDeviceSize*                         pCounterBufferOffsets) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}
void CdlContext::PostCmdEndTransformFeedbackEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const VkBuffer*                             pCounterBuffers,
    const VkDeviceSize*                         pCounterBufferOffsets) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}

void CdlContext::PreCmdBeginQueryIndexedEXT(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags,
    uint32_t                                    index) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
}
void CdlContext::PostCmdBeginQueryIndexedEXT(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags,
    uint32_t                                    index) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
}

void CdlContext::PreCmdEndQueryIndexedEXT(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    uint32_t                                    index) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
}
void CdlContext::PostCmdEndQueryIndexedEXT(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    uint32_t                                    index) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
}

void CdlContext::PreCmdDrawIndirectByteCountEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    VkBuffer                                    counterBuffer,
    VkDeviceSize                                counterBufferOffset,
    uint32_t                                    counterOffset,
    uint32_t                                    vertexStride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
}
void CdlContext::PostCmdDrawIndirectByteCountEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    VkBuffer                                    counterBuffer,
    VkDeviceSize                                counterBufferOffset,
    uint32_t                                    counterOffset,
    uint32_t                                    vertexStride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
}

void CdlContext::PreCmdCuLaunchKernelNVX(
    VkCommandBuffer                             commandBuffer,
    const VkCuLaunchInfoNVX*                    pLaunchInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);
}
void CdlContext::PostCmdCuLaunchKernelNVX(
    VkCommandBuffer                             commandBuffer,
    const VkCuLaunchInfoNVX*                    pLaunchInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);
}

void CdlContext::PreCmdDrawIndirectCountAMD(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
void CdlContext::PostCmdDrawIndirectCountAMD(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void CdlContext::PreCmdDrawIndexedIndirectCountAMD(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
void CdlContext::PostCmdDrawIndexedIndirectCountAMD(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void CdlContext::PreCmdBeginConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer,
    const VkConditionalRenderingBeginInfoEXT*   pConditionalRenderingBegin) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
}
void CdlContext::PostCmdBeginConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer,
    const VkConditionalRenderingBeginInfoEXT*   pConditionalRenderingBegin) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
}

void CdlContext::PreCmdEndConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdEndConditionalRenderingEXT(commandBuffer);
}
void CdlContext::PostCmdEndConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdEndConditionalRenderingEXT(commandBuffer);
}

void CdlContext::PreCmdSetViewportWScalingNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewportWScalingNV*                 pViewportWScalings) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
}
void CdlContext::PostCmdSetViewportWScalingNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewportWScalingNV*                 pViewportWScalings) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
}

void CdlContext::PreCmdSetDiscardRectangleEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    const VkRect2D*                             pDiscardRectangles) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
}
void CdlContext::PostCmdSetDiscardRectangleEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    const VkRect2D*                             pDiscardRectangles) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
}

void CdlContext::PreCmdSetDiscardRectangleEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    discardRectangleEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable);
}
void CdlContext::PostCmdSetDiscardRectangleEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    discardRectangleEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable);
}

void CdlContext::PreCmdSetDiscardRectangleModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkDiscardRectangleModeEXT                   discardRectangleMode) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode);
}
void CdlContext::PostCmdSetDiscardRectangleModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkDiscardRectangleModeEXT                   discardRectangleMode) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode);
}

void CdlContext::PreCmdBeginDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}
void CdlContext::PostCmdBeginDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}

void CdlContext::PreCmdEndDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdEndDebugUtilsLabelEXT(commandBuffer);
}
void CdlContext::PostCmdEndDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdEndDebugUtilsLabelEXT(commandBuffer);
}

void CdlContext::PreCmdInsertDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}
void CdlContext::PostCmdInsertDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}

void CdlContext::PreCmdSetSampleLocationsEXT(
    VkCommandBuffer                             commandBuffer,
    const VkSampleLocationsInfoEXT*             pSampleLocationsInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
}
void CdlContext::PostCmdSetSampleLocationsEXT(
    VkCommandBuffer                             commandBuffer,
    const VkSampleLocationsInfoEXT*             pSampleLocationsInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
}

void CdlContext::PreCmdBindShadingRateImageNV(
    VkCommandBuffer                             commandBuffer,
    VkImageView                                 imageView,
    VkImageLayout                               imageLayout) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
}
void CdlContext::PostCmdBindShadingRateImageNV(
    VkCommandBuffer                             commandBuffer,
    VkImageView                                 imageView,
    VkImageLayout                               imageLayout) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
}

void CdlContext::PreCmdSetViewportShadingRatePaletteNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkShadingRatePaletteNV*               pShadingRatePalettes) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
}
void CdlContext::PostCmdSetViewportShadingRatePaletteNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkShadingRatePaletteNV*               pShadingRatePalettes) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
}

void CdlContext::PreCmdSetCoarseSampleOrderNV(
    VkCommandBuffer                             commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    const VkCoarseSampleOrderCustomNV*          pCustomSampleOrders) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
}
void CdlContext::PostCmdSetCoarseSampleOrderNV(
    VkCommandBuffer                             commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    const VkCoarseSampleOrderCustomNV*          pCustomSampleOrders) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
}

void CdlContext::PreCmdBuildAccelerationStructureNV(
    VkCommandBuffer                             commandBuffer,
    const VkAccelerationStructureInfoNV*        pInfo,
    VkBuffer                                    instanceData,
    VkDeviceSize                                instanceOffset,
    VkBool32                                    update,
    VkAccelerationStructureNV                   dst,
    VkAccelerationStructureNV                   src,
    VkBuffer                                    scratch,
    VkDeviceSize                                scratchOffset) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
}
void CdlContext::PostCmdBuildAccelerationStructureNV(
    VkCommandBuffer                             commandBuffer,
    const VkAccelerationStructureInfoNV*        pInfo,
    VkBuffer                                    instanceData,
    VkDeviceSize                                instanceOffset,
    VkBool32                                    update,
    VkAccelerationStructureNV                   dst,
    VkAccelerationStructureNV                   src,
    VkBuffer                                    scratch,
    VkDeviceSize                                scratchOffset) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
}

void CdlContext::PreCmdCopyAccelerationStructureNV(
    VkCommandBuffer                             commandBuffer,
    VkAccelerationStructureNV                   dst,
    VkAccelerationStructureNV                   src,
    VkCopyAccelerationStructureModeKHR          mode) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
}
void CdlContext::PostCmdCopyAccelerationStructureNV(
    VkCommandBuffer                             commandBuffer,
    VkAccelerationStructureNV                   dst,
    VkAccelerationStructureNV                   src,
    VkCopyAccelerationStructureModeKHR          mode) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
}

void CdlContext::PreCmdTraceRaysNV(
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
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdTraceRaysNV(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
}
void CdlContext::PostCmdTraceRaysNV(
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
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdTraceRaysNV(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
}

void CdlContext::PreCmdWriteAccelerationStructuresPropertiesNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    accelerationStructureCount,
    const VkAccelerationStructureNV*            pAccelerationStructures,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdWriteAccelerationStructuresPropertiesNV(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}
void CdlContext::PostCmdWriteAccelerationStructuresPropertiesNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    accelerationStructureCount,
    const VkAccelerationStructureNV*            pAccelerationStructures,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdWriteAccelerationStructuresPropertiesNV(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}

void CdlContext::PreCmdWriteBufferMarkerAMD(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
}
void CdlContext::PostCmdWriteBufferMarkerAMD(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
}

void CdlContext::PreCmdDrawMeshTasksNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
}
void CdlContext::PostCmdDrawMeshTasksNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
}

void CdlContext::PreCmdDrawMeshTasksIndirectNV(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
}
void CdlContext::PostCmdDrawMeshTasksIndirectNV(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
}

void CdlContext::PreCmdDrawMeshTasksIndirectCountNV(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
void CdlContext::PostCmdDrawMeshTasksIndirectCountNV(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void CdlContext::PreCmdSetExclusiveScissorEnableNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    const VkBool32*                             pExclusiveScissorEnables) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetExclusiveScissorEnableNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);
}
void CdlContext::PostCmdSetExclusiveScissorEnableNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    const VkBool32*                             pExclusiveScissorEnables) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetExclusiveScissorEnableNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);
}

void CdlContext::PreCmdSetExclusiveScissorNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    const VkRect2D*                             pExclusiveScissors) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
}
void CdlContext::PostCmdSetExclusiveScissorNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    const VkRect2D*                             pExclusiveScissors) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
}

void CdlContext::PreCmdSetCheckpointNV(
    VkCommandBuffer                             commandBuffer,
    const void*                                 pCheckpointMarker) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
}
void CdlContext::PostCmdSetCheckpointNV(
    VkCommandBuffer                             commandBuffer,
    const void*                                 pCheckpointMarker) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
}

VkResult CdlContext::PreCmdSetPerformanceMarkerINTEL(
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceMarkerInfoINTEL*         pMarkerInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  return p_cmd->PreCmdSetPerformanceMarkerINTEL(commandBuffer, pMarkerInfo);
}
VkResult CdlContext::PostCmdSetPerformanceMarkerINTEL(
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceMarkerInfoINTEL*         pMarkerInfo,
    VkResult                                    result) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  return p_cmd->PostCmdSetPerformanceMarkerINTEL(commandBuffer, pMarkerInfo, result);
}

VkResult CdlContext::PreCmdSetPerformanceStreamMarkerINTEL(
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceStreamMarkerInfoINTEL*   pMarkerInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  return p_cmd->PreCmdSetPerformanceStreamMarkerINTEL(commandBuffer, pMarkerInfo);
}
VkResult CdlContext::PostCmdSetPerformanceStreamMarkerINTEL(
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceStreamMarkerInfoINTEL*   pMarkerInfo,
    VkResult                                    result) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  return p_cmd->PostCmdSetPerformanceStreamMarkerINTEL(commandBuffer, pMarkerInfo, result);
}

VkResult CdlContext::PreCmdSetPerformanceOverrideINTEL(
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceOverrideInfoINTEL*       pOverrideInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  return p_cmd->PreCmdSetPerformanceOverrideINTEL(commandBuffer, pOverrideInfo);
}
VkResult CdlContext::PostCmdSetPerformanceOverrideINTEL(
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceOverrideInfoINTEL*       pOverrideInfo,
    VkResult                                    result) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  return p_cmd->PostCmdSetPerformanceOverrideINTEL(commandBuffer, pOverrideInfo, result);
}

void CdlContext::PreCmdSetLineStippleEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
}
void CdlContext::PostCmdSetLineStippleEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
}

void CdlContext::PreCmdSetCullModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkCullModeFlags                             cullMode) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetCullModeEXT(commandBuffer, cullMode);
}
void CdlContext::PostCmdSetCullModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkCullModeFlags                             cullMode) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetCullModeEXT(commandBuffer, cullMode);
}

void CdlContext::PreCmdSetFrontFaceEXT(
    VkCommandBuffer                             commandBuffer,
    VkFrontFace                                 frontFace) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetFrontFaceEXT(commandBuffer, frontFace);
}
void CdlContext::PostCmdSetFrontFaceEXT(
    VkCommandBuffer                             commandBuffer,
    VkFrontFace                                 frontFace) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetFrontFaceEXT(commandBuffer, frontFace);
}

void CdlContext::PreCmdSetPrimitiveTopologyEXT(
    VkCommandBuffer                             commandBuffer,
    VkPrimitiveTopology                         primitiveTopology) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);
}
void CdlContext::PostCmdSetPrimitiveTopologyEXT(
    VkCommandBuffer                             commandBuffer,
    VkPrimitiveTopology                         primitiveTopology) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);
}

void CdlContext::PreCmdSetViewportWithCountEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);
}
void CdlContext::PostCmdSetViewportWithCountEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);
}

void CdlContext::PreCmdSetScissorWithCountEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);
}
void CdlContext::PostCmdSetScissorWithCountEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);
}

void CdlContext::PreCmdBindVertexBuffers2EXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes,
    const VkDeviceSize*                         pStrides) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}
void CdlContext::PostCmdBindVertexBuffers2EXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes,
    const VkDeviceSize*                         pStrides) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}

void CdlContext::PreCmdSetDepthTestEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthTestEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);
}
void CdlContext::PostCmdSetDepthTestEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthTestEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);
}

void CdlContext::PreCmdSetDepthWriteEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthWriteEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);
}
void CdlContext::PostCmdSetDepthWriteEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthWriteEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);
}

void CdlContext::PreCmdSetDepthCompareOpEXT(
    VkCommandBuffer                             commandBuffer,
    VkCompareOp                                 depthCompareOp) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);
}
void CdlContext::PostCmdSetDepthCompareOpEXT(
    VkCommandBuffer                             commandBuffer,
    VkCompareOp                                 depthCompareOp) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);
}

void CdlContext::PreCmdSetDepthBoundsTestEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBoundsTestEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);
}
void CdlContext::PostCmdSetDepthBoundsTestEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBoundsTestEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);
}

void CdlContext::PreCmdSetStencilTestEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stencilTestEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);
}
void CdlContext::PostCmdSetStencilTestEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stencilTestEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);
}

void CdlContext::PreCmdSetStencilOpEXT(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}
void CdlContext::PostCmdSetStencilOpEXT(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}

void CdlContext::PreCmdPreprocessGeneratedCommandsNV(
    VkCommandBuffer                             commandBuffer,
    const VkGeneratedCommandsInfoNV*            pGeneratedCommandsInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);
}
void CdlContext::PostCmdPreprocessGeneratedCommandsNV(
    VkCommandBuffer                             commandBuffer,
    const VkGeneratedCommandsInfoNV*            pGeneratedCommandsInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);
}

void CdlContext::PreCmdExecuteGeneratedCommandsNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    isPreprocessed,
    const VkGeneratedCommandsInfoNV*            pGeneratedCommandsInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
}
void CdlContext::PostCmdExecuteGeneratedCommandsNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    isPreprocessed,
    const VkGeneratedCommandsInfoNV*            pGeneratedCommandsInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
}

void CdlContext::PreCmdBindPipelineShaderGroupNV(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline,
    uint32_t                                    groupIndex) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
}
void CdlContext::PostCmdBindPipelineShaderGroupNV(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline,
    uint32_t                                    groupIndex) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
}

void CdlContext::PreCmdSetDepthBias2EXT(
    VkCommandBuffer                             commandBuffer,
    const VkDepthBiasInfoEXT*                   pDepthBiasInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthBias2EXT(commandBuffer, pDepthBiasInfo);
}
void CdlContext::PostCmdSetDepthBias2EXT(
    VkCommandBuffer                             commandBuffer,
    const VkDepthBiasInfoEXT*                   pDepthBiasInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthBias2EXT(commandBuffer, pDepthBiasInfo);
}

void CdlContext::PreCmdBindDescriptorBuffersEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    bufferCount,
    const VkDescriptorBufferBindingInfoEXT*     pBindingInfos) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBindDescriptorBuffersEXT(commandBuffer, bufferCount, pBindingInfos);
}
void CdlContext::PostCmdBindDescriptorBuffersEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    bufferCount,
    const VkDescriptorBufferBindingInfoEXT*     pBindingInfos) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBindDescriptorBuffersEXT(commandBuffer, bufferCount, pBindingInfos);
}

void CdlContext::PreCmdSetDescriptorBufferOffsetsEXT(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    setCount,
    const uint32_t*                             pBufferIndices,
    const VkDeviceSize*                         pOffsets) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDescriptorBufferOffsetsEXT(commandBuffer, pipelineBindPoint, layout, firstSet, setCount, pBufferIndices, pOffsets);
}
void CdlContext::PostCmdSetDescriptorBufferOffsetsEXT(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    setCount,
    const uint32_t*                             pBufferIndices,
    const VkDeviceSize*                         pOffsets) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDescriptorBufferOffsetsEXT(commandBuffer, pipelineBindPoint, layout, firstSet, setCount, pBufferIndices, pOffsets);
}

void CdlContext::PreCmdBindDescriptorBufferEmbeddedSamplersEXT(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    set) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBindDescriptorBufferEmbeddedSamplersEXT(commandBuffer, pipelineBindPoint, layout, set);
}
void CdlContext::PostCmdBindDescriptorBufferEmbeddedSamplersEXT(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    set) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBindDescriptorBufferEmbeddedSamplersEXT(commandBuffer, pipelineBindPoint, layout, set);
}

void CdlContext::PreCmdSetFragmentShadingRateEnumNV(
    VkCommandBuffer                             commandBuffer,
    VkFragmentShadingRateNV                     shadingRate,
    const VkFragmentShadingRateCombinerOpKHR    combinerOps[2]) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);
}
void CdlContext::PostCmdSetFragmentShadingRateEnumNV(
    VkCommandBuffer                             commandBuffer,
    VkFragmentShadingRateNV                     shadingRate,
    const VkFragmentShadingRateCombinerOpKHR    combinerOps[2]) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);
}

void CdlContext::PreCmdSetVertexInputEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexBindingDescriptionCount,
    const VkVertexInputBindingDescription2EXT*  pVertexBindingDescriptions,
    uint32_t                                    vertexAttributeDescriptionCount,
    const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
}
void CdlContext::PostCmdSetVertexInputEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexBindingDescriptionCount,
    const VkVertexInputBindingDescription2EXT*  pVertexBindingDescriptions,
    uint32_t                                    vertexAttributeDescriptionCount,
    const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
}

void CdlContext::PreCmdSubpassShadingHUAWEI(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSubpassShadingHUAWEI(commandBuffer);
}
void CdlContext::PostCmdSubpassShadingHUAWEI(
    VkCommandBuffer                             commandBuffer) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSubpassShadingHUAWEI(commandBuffer);
}

void CdlContext::PreCmdBindInvocationMaskHUAWEI(
    VkCommandBuffer                             commandBuffer,
    VkImageView                                 imageView,
    VkImageLayout                               imageLayout) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBindInvocationMaskHUAWEI(commandBuffer, imageView, imageLayout);
}
void CdlContext::PostCmdBindInvocationMaskHUAWEI(
    VkCommandBuffer                             commandBuffer,
    VkImageView                                 imageView,
    VkImageLayout                               imageLayout) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBindInvocationMaskHUAWEI(commandBuffer, imageView, imageLayout);
}

void CdlContext::PreCmdSetPatchControlPointsEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    patchControlPoints) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
}
void CdlContext::PostCmdSetPatchControlPointsEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    patchControlPoints) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
}

void CdlContext::PreCmdSetRasterizerDiscardEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    rasterizerDiscardEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable);
}
void CdlContext::PostCmdSetRasterizerDiscardEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    rasterizerDiscardEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable);
}

void CdlContext::PreCmdSetDepthBiasEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBiasEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable);
}
void CdlContext::PostCmdSetDepthBiasEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBiasEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable);
}

void CdlContext::PreCmdSetLogicOpEXT(
    VkCommandBuffer                             commandBuffer,
    VkLogicOp                                   logicOp) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetLogicOpEXT(commandBuffer, logicOp);
}
void CdlContext::PostCmdSetLogicOpEXT(
    VkCommandBuffer                             commandBuffer,
    VkLogicOp                                   logicOp) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetLogicOpEXT(commandBuffer, logicOp);
}

void CdlContext::PreCmdSetPrimitiveRestartEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    primitiveRestartEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable);
}
void CdlContext::PostCmdSetPrimitiveRestartEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    primitiveRestartEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable);
}

void                                    CdlContext::PreCmdSetColorWriteEnableEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkBool32*                             pColorWriteEnables) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
}
void                                    CdlContext::PostCmdSetColorWriteEnableEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkBool32*                             pColorWriteEnables) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
}

void CdlContext::PreCmdDrawMultiEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    drawCount,
    const VkMultiDrawInfoEXT*                   pVertexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawMultiEXT(commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
}
void CdlContext::PostCmdDrawMultiEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    drawCount,
    const VkMultiDrawInfoEXT*                   pVertexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawMultiEXT(commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
}

void CdlContext::PreCmdDrawMultiIndexedEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    drawCount,
    const VkMultiDrawIndexedInfoEXT*            pIndexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride,
    const int32_t*                              pVertexOffset) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawMultiIndexedEXT(commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
}
void CdlContext::PostCmdDrawMultiIndexedEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    drawCount,
    const VkMultiDrawIndexedInfoEXT*            pIndexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride,
    const int32_t*                              pVertexOffset) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawMultiIndexedEXT(commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
}

void CdlContext::PreCmdBuildMicromapsEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkMicromapBuildInfoEXT*               pInfos) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBuildMicromapsEXT(commandBuffer, infoCount, pInfos);
}
void CdlContext::PostCmdBuildMicromapsEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkMicromapBuildInfoEXT*               pInfos) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBuildMicromapsEXT(commandBuffer, infoCount, pInfos);
}

void CdlContext::PreCmdCopyMicromapEXT(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMicromapInfoEXT*                pInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyMicromapEXT(commandBuffer, pInfo);
}
void CdlContext::PostCmdCopyMicromapEXT(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMicromapInfoEXT*                pInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyMicromapEXT(commandBuffer, pInfo);
}

void CdlContext::PreCmdCopyMicromapToMemoryEXT(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMicromapToMemoryInfoEXT*        pInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyMicromapToMemoryEXT(commandBuffer, pInfo);
}
void CdlContext::PostCmdCopyMicromapToMemoryEXT(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMicromapToMemoryInfoEXT*        pInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyMicromapToMemoryEXT(commandBuffer, pInfo);
}

void CdlContext::PreCmdCopyMemoryToMicromapEXT(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMemoryToMicromapInfoEXT*        pInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyMemoryToMicromapEXT(commandBuffer, pInfo);
}
void CdlContext::PostCmdCopyMemoryToMicromapEXT(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMemoryToMicromapInfoEXT*        pInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyMemoryToMicromapEXT(commandBuffer, pInfo);
}

void CdlContext::PreCmdWriteMicromapsPropertiesEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    micromapCount,
    const VkMicromapEXT*                        pMicromaps,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdWriteMicromapsPropertiesEXT(commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);
}
void CdlContext::PostCmdWriteMicromapsPropertiesEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    micromapCount,
    const VkMicromapEXT*                        pMicromaps,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdWriteMicromapsPropertiesEXT(commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);
}

void CdlContext::PreCmdDrawClusterHUAWEI(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawClusterHUAWEI(commandBuffer, groupCountX, groupCountY, groupCountZ);
}
void CdlContext::PostCmdDrawClusterHUAWEI(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawClusterHUAWEI(commandBuffer, groupCountX, groupCountY, groupCountZ);
}

void CdlContext::PreCmdDrawClusterIndirectHUAWEI(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawClusterIndirectHUAWEI(commandBuffer, buffer, offset);
}
void CdlContext::PostCmdDrawClusterIndirectHUAWEI(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawClusterIndirectHUAWEI(commandBuffer, buffer, offset);
}

void CdlContext::PreCmdCopyMemoryIndirectNV(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             copyBufferAddress,
    uint32_t                                    copyCount,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyMemoryIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride);
}
void CdlContext::PostCmdCopyMemoryIndirectNV(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             copyBufferAddress,
    uint32_t                                    copyCount,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyMemoryIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride);
}

void CdlContext::PreCmdCopyMemoryToImageIndirectNV(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             copyBufferAddress,
    uint32_t                                    copyCount,
    uint32_t                                    stride,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    const VkImageSubresourceLayers*             pImageSubresources) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyMemoryToImageIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride, dstImage, dstImageLayout, pImageSubresources);
}
void CdlContext::PostCmdCopyMemoryToImageIndirectNV(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             copyBufferAddress,
    uint32_t                                    copyCount,
    uint32_t                                    stride,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    const VkImageSubresourceLayers*             pImageSubresources) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyMemoryToImageIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride, dstImage, dstImageLayout, pImageSubresources);
}

void CdlContext::PreCmdDecompressMemoryNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    decompressRegionCount,
    const VkDecompressMemoryRegionNV*           pDecompressMemoryRegions) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDecompressMemoryNV(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
}
void CdlContext::PostCmdDecompressMemoryNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    decompressRegionCount,
    const VkDecompressMemoryRegionNV*           pDecompressMemoryRegions) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDecompressMemoryNV(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
}

void CdlContext::PreCmdDecompressMemoryIndirectCountNV(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             indirectCommandsAddress,
    VkDeviceAddress                             indirectCommandsCountAddress,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDecompressMemoryIndirectCountNV(commandBuffer, indirectCommandsAddress, indirectCommandsCountAddress, stride);
}
void CdlContext::PostCmdDecompressMemoryIndirectCountNV(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             indirectCommandsAddress,
    VkDeviceAddress                             indirectCommandsCountAddress,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDecompressMemoryIndirectCountNV(commandBuffer, indirectCommandsAddress, indirectCommandsCountAddress, stride);
}

void CdlContext::PreCmdUpdatePipelineIndirectBufferNV(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdUpdatePipelineIndirectBufferNV(commandBuffer, pipelineBindPoint, pipeline);
}
void CdlContext::PostCmdUpdatePipelineIndirectBufferNV(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdUpdatePipelineIndirectBufferNV(commandBuffer, pipelineBindPoint, pipeline);
}

void CdlContext::PreCmdSetTessellationDomainOriginEXT(
    VkCommandBuffer                             commandBuffer,
    VkTessellationDomainOrigin                  domainOrigin) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetTessellationDomainOriginEXT(commandBuffer, domainOrigin);
}
void CdlContext::PostCmdSetTessellationDomainOriginEXT(
    VkCommandBuffer                             commandBuffer,
    VkTessellationDomainOrigin                  domainOrigin) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetTessellationDomainOriginEXT(commandBuffer, domainOrigin);
}

void CdlContext::PreCmdSetDepthClampEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthClampEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthClampEnableEXT(commandBuffer, depthClampEnable);
}
void CdlContext::PostCmdSetDepthClampEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthClampEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthClampEnableEXT(commandBuffer, depthClampEnable);
}

void CdlContext::PreCmdSetPolygonModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkPolygonMode                               polygonMode) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetPolygonModeEXT(commandBuffer, polygonMode);
}
void CdlContext::PostCmdSetPolygonModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkPolygonMode                               polygonMode) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetPolygonModeEXT(commandBuffer, polygonMode);
}

void CdlContext::PreCmdSetRasterizationSamplesEXT(
    VkCommandBuffer                             commandBuffer,
    VkSampleCountFlagBits                       rasterizationSamples) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetRasterizationSamplesEXT(commandBuffer, rasterizationSamples);
}
void CdlContext::PostCmdSetRasterizationSamplesEXT(
    VkCommandBuffer                             commandBuffer,
    VkSampleCountFlagBits                       rasterizationSamples) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetRasterizationSamplesEXT(commandBuffer, rasterizationSamples);
}

void CdlContext::PreCmdSetSampleMaskEXT(
    VkCommandBuffer                             commandBuffer,
    VkSampleCountFlagBits                       samples,
    const VkSampleMask*                         pSampleMask) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetSampleMaskEXT(commandBuffer, samples, pSampleMask);
}
void CdlContext::PostCmdSetSampleMaskEXT(
    VkCommandBuffer                             commandBuffer,
    VkSampleCountFlagBits                       samples,
    const VkSampleMask*                         pSampleMask) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetSampleMaskEXT(commandBuffer, samples, pSampleMask);
}

void CdlContext::PreCmdSetAlphaToCoverageEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    alphaToCoverageEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetAlphaToCoverageEnableEXT(commandBuffer, alphaToCoverageEnable);
}
void CdlContext::PostCmdSetAlphaToCoverageEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    alphaToCoverageEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetAlphaToCoverageEnableEXT(commandBuffer, alphaToCoverageEnable);
}

void CdlContext::PreCmdSetAlphaToOneEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    alphaToOneEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetAlphaToOneEnableEXT(commandBuffer, alphaToOneEnable);
}
void CdlContext::PostCmdSetAlphaToOneEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    alphaToOneEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetAlphaToOneEnableEXT(commandBuffer, alphaToOneEnable);
}

void CdlContext::PreCmdSetLogicOpEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    logicOpEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetLogicOpEnableEXT(commandBuffer, logicOpEnable);
}
void CdlContext::PostCmdSetLogicOpEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    logicOpEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetLogicOpEnableEXT(commandBuffer, logicOpEnable);
}

void CdlContext::PreCmdSetColorBlendEnableEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkBool32*                             pColorBlendEnables) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetColorBlendEnableEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
}
void CdlContext::PostCmdSetColorBlendEnableEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkBool32*                             pColorBlendEnables) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetColorBlendEnableEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
}

void CdlContext::PreCmdSetColorBlendEquationEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorBlendEquationEXT*              pColorBlendEquations) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetColorBlendEquationEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
}
void CdlContext::PostCmdSetColorBlendEquationEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorBlendEquationEXT*              pColorBlendEquations) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetColorBlendEquationEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
}

void CdlContext::PreCmdSetColorWriteMaskEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorComponentFlags*                pColorWriteMasks) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetColorWriteMaskEXT(commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
}
void CdlContext::PostCmdSetColorWriteMaskEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorComponentFlags*                pColorWriteMasks) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetColorWriteMaskEXT(commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
}

void CdlContext::PreCmdSetRasterizationStreamEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    rasterizationStream) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetRasterizationStreamEXT(commandBuffer, rasterizationStream);
}
void CdlContext::PostCmdSetRasterizationStreamEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    rasterizationStream) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetRasterizationStreamEXT(commandBuffer, rasterizationStream);
}

void CdlContext::PreCmdSetConservativeRasterizationModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkConservativeRasterizationModeEXT          conservativeRasterizationMode) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetConservativeRasterizationModeEXT(commandBuffer, conservativeRasterizationMode);
}
void CdlContext::PostCmdSetConservativeRasterizationModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkConservativeRasterizationModeEXT          conservativeRasterizationMode) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetConservativeRasterizationModeEXT(commandBuffer, conservativeRasterizationMode);
}

void CdlContext::PreCmdSetExtraPrimitiveOverestimationSizeEXT(
    VkCommandBuffer                             commandBuffer,
    float                                       extraPrimitiveOverestimationSize) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetExtraPrimitiveOverestimationSizeEXT(commandBuffer, extraPrimitiveOverestimationSize);
}
void CdlContext::PostCmdSetExtraPrimitiveOverestimationSizeEXT(
    VkCommandBuffer                             commandBuffer,
    float                                       extraPrimitiveOverestimationSize) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetExtraPrimitiveOverestimationSizeEXT(commandBuffer, extraPrimitiveOverestimationSize);
}

void CdlContext::PreCmdSetDepthClipEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthClipEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthClipEnableEXT(commandBuffer, depthClipEnable);
}
void CdlContext::PostCmdSetDepthClipEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthClipEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthClipEnableEXT(commandBuffer, depthClipEnable);
}

void CdlContext::PreCmdSetSampleLocationsEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    sampleLocationsEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetSampleLocationsEnableEXT(commandBuffer, sampleLocationsEnable);
}
void CdlContext::PostCmdSetSampleLocationsEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    sampleLocationsEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetSampleLocationsEnableEXT(commandBuffer, sampleLocationsEnable);
}

void CdlContext::PreCmdSetColorBlendAdvancedEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorBlendAdvancedEXT*              pColorBlendAdvanced) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetColorBlendAdvancedEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
}
void CdlContext::PostCmdSetColorBlendAdvancedEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorBlendAdvancedEXT*              pColorBlendAdvanced) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetColorBlendAdvancedEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
}

void CdlContext::PreCmdSetProvokingVertexModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkProvokingVertexModeEXT                    provokingVertexMode) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetProvokingVertexModeEXT(commandBuffer, provokingVertexMode);
}
void CdlContext::PostCmdSetProvokingVertexModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkProvokingVertexModeEXT                    provokingVertexMode) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetProvokingVertexModeEXT(commandBuffer, provokingVertexMode);
}

void CdlContext::PreCmdSetLineRasterizationModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkLineRasterizationModeEXT                  lineRasterizationMode) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetLineRasterizationModeEXT(commandBuffer, lineRasterizationMode);
}
void CdlContext::PostCmdSetLineRasterizationModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkLineRasterizationModeEXT                  lineRasterizationMode) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetLineRasterizationModeEXT(commandBuffer, lineRasterizationMode);
}

void CdlContext::PreCmdSetLineStippleEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stippledLineEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetLineStippleEnableEXT(commandBuffer, stippledLineEnable);
}
void CdlContext::PostCmdSetLineStippleEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stippledLineEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetLineStippleEnableEXT(commandBuffer, stippledLineEnable);
}

void CdlContext::PreCmdSetDepthClipNegativeOneToOneEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    negativeOneToOne) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetDepthClipNegativeOneToOneEXT(commandBuffer, negativeOneToOne);
}
void CdlContext::PostCmdSetDepthClipNegativeOneToOneEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    negativeOneToOne) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetDepthClipNegativeOneToOneEXT(commandBuffer, negativeOneToOne);
}

void CdlContext::PreCmdSetViewportWScalingEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    viewportWScalingEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetViewportWScalingEnableNV(commandBuffer, viewportWScalingEnable);
}
void CdlContext::PostCmdSetViewportWScalingEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    viewportWScalingEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetViewportWScalingEnableNV(commandBuffer, viewportWScalingEnable);
}

void CdlContext::PreCmdSetViewportSwizzleNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewportSwizzleNV*                  pViewportSwizzles) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetViewportSwizzleNV(commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
}
void CdlContext::PostCmdSetViewportSwizzleNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewportSwizzleNV*                  pViewportSwizzles) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetViewportSwizzleNV(commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
}

void CdlContext::PreCmdSetCoverageToColorEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    coverageToColorEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetCoverageToColorEnableNV(commandBuffer, coverageToColorEnable);
}
void CdlContext::PostCmdSetCoverageToColorEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    coverageToColorEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetCoverageToColorEnableNV(commandBuffer, coverageToColorEnable);
}

void CdlContext::PreCmdSetCoverageToColorLocationNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    coverageToColorLocation) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetCoverageToColorLocationNV(commandBuffer, coverageToColorLocation);
}
void CdlContext::PostCmdSetCoverageToColorLocationNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    coverageToColorLocation) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetCoverageToColorLocationNV(commandBuffer, coverageToColorLocation);
}

void CdlContext::PreCmdSetCoverageModulationModeNV(
    VkCommandBuffer                             commandBuffer,
    VkCoverageModulationModeNV                  coverageModulationMode) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetCoverageModulationModeNV(commandBuffer, coverageModulationMode);
}
void CdlContext::PostCmdSetCoverageModulationModeNV(
    VkCommandBuffer                             commandBuffer,
    VkCoverageModulationModeNV                  coverageModulationMode) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetCoverageModulationModeNV(commandBuffer, coverageModulationMode);
}

void CdlContext::PreCmdSetCoverageModulationTableEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    coverageModulationTableEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetCoverageModulationTableEnableNV(commandBuffer, coverageModulationTableEnable);
}
void CdlContext::PostCmdSetCoverageModulationTableEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    coverageModulationTableEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetCoverageModulationTableEnableNV(commandBuffer, coverageModulationTableEnable);
}

void CdlContext::PreCmdSetCoverageModulationTableNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    coverageModulationTableCount,
    const float*                                pCoverageModulationTable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetCoverageModulationTableNV(commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
}
void CdlContext::PostCmdSetCoverageModulationTableNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    coverageModulationTableCount,
    const float*                                pCoverageModulationTable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetCoverageModulationTableNV(commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
}

void CdlContext::PreCmdSetShadingRateImageEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    shadingRateImageEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetShadingRateImageEnableNV(commandBuffer, shadingRateImageEnable);
}
void CdlContext::PostCmdSetShadingRateImageEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    shadingRateImageEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetShadingRateImageEnableNV(commandBuffer, shadingRateImageEnable);
}

void CdlContext::PreCmdSetRepresentativeFragmentTestEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    representativeFragmentTestEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetRepresentativeFragmentTestEnableNV(commandBuffer, representativeFragmentTestEnable);
}
void CdlContext::PostCmdSetRepresentativeFragmentTestEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    representativeFragmentTestEnable) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetRepresentativeFragmentTestEnableNV(commandBuffer, representativeFragmentTestEnable);
}

void CdlContext::PreCmdSetCoverageReductionModeNV(
    VkCommandBuffer                             commandBuffer,
    VkCoverageReductionModeNV                   coverageReductionMode) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetCoverageReductionModeNV(commandBuffer, coverageReductionMode);
}
void CdlContext::PostCmdSetCoverageReductionModeNV(
    VkCommandBuffer                             commandBuffer,
    VkCoverageReductionModeNV                   coverageReductionMode) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetCoverageReductionModeNV(commandBuffer, coverageReductionMode);
}

void CdlContext::PreCmdOpticalFlowExecuteNV(
    VkCommandBuffer                             commandBuffer,
    VkOpticalFlowSessionNV                      session,
    const VkOpticalFlowExecuteInfoNV*           pExecuteInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdOpticalFlowExecuteNV(commandBuffer, session, pExecuteInfo);
}
void CdlContext::PostCmdOpticalFlowExecuteNV(
    VkCommandBuffer                             commandBuffer,
    VkOpticalFlowSessionNV                      session,
    const VkOpticalFlowExecuteInfoNV*           pExecuteInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdOpticalFlowExecuteNV(commandBuffer, session, pExecuteInfo);
}

void CdlContext::PreCmdBindShadersEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    stageCount,
    const VkShaderStageFlagBits*                pStages,
    const VkShaderEXT*                          pShaders) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBindShadersEXT(commandBuffer, stageCount, pStages, pShaders);
}
void CdlContext::PostCmdBindShadersEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    stageCount,
    const VkShaderStageFlagBits*                pStages,
    const VkShaderEXT*                          pShaders) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBindShadersEXT(commandBuffer, stageCount, pStages, pShaders);
}

void CdlContext::PreCmdSetAttachmentFeedbackLoopEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkImageAspectFlags                          aspectMask) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetAttachmentFeedbackLoopEnableEXT(commandBuffer, aspectMask);
}
void CdlContext::PostCmdSetAttachmentFeedbackLoopEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkImageAspectFlags                          aspectMask) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetAttachmentFeedbackLoopEnableEXT(commandBuffer, aspectMask);
}

void CdlContext::PreCmdBuildAccelerationStructuresKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
}
void CdlContext::PostCmdBuildAccelerationStructuresKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
}

void CdlContext::PreCmdBuildAccelerationStructuresIndirectKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkDeviceAddress*                      pIndirectDeviceAddresses,
    const uint32_t*                             pIndirectStrides,
    const uint32_t* const*                      ppMaxPrimitiveCounts) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdBuildAccelerationStructuresIndirectKHR(commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
}
void CdlContext::PostCmdBuildAccelerationStructuresIndirectKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkDeviceAddress*                      pIndirectDeviceAddresses,
    const uint32_t*                             pIndirectStrides,
    const uint32_t* const*                      ppMaxPrimitiveCounts) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdBuildAccelerationStructuresIndirectKHR(commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
}

void CdlContext::PreCmdCopyAccelerationStructureKHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyAccelerationStructureInfoKHR*   pInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyAccelerationStructureKHR(commandBuffer, pInfo);
}
void CdlContext::PostCmdCopyAccelerationStructureKHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyAccelerationStructureInfoKHR*   pInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyAccelerationStructureKHR(commandBuffer, pInfo);
}

void CdlContext::PreCmdCopyAccelerationStructureToMemoryKHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);
}
void CdlContext::PostCmdCopyAccelerationStructureToMemoryKHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);
}

void CdlContext::PreCmdCopyMemoryToAccelerationStructureKHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);
}
void CdlContext::PostCmdCopyMemoryToAccelerationStructureKHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);
}

void CdlContext::PreCmdWriteAccelerationStructuresPropertiesKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    accelerationStructureCount,
    const VkAccelerationStructureKHR*           pAccelerationStructures,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdWriteAccelerationStructuresPropertiesKHR(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}
void CdlContext::PostCmdWriteAccelerationStructuresPropertiesKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    accelerationStructureCount,
    const VkAccelerationStructureKHR*           pAccelerationStructures,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdWriteAccelerationStructuresPropertiesKHR(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}

void CdlContext::PreCmdTraceRaysKHR(
    VkCommandBuffer                             commandBuffer,
    const VkStridedDeviceAddressRegionKHR*      pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pCallableShaderBindingTable,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdTraceRaysKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
}
void CdlContext::PostCmdTraceRaysKHR(
    VkCommandBuffer                             commandBuffer,
    const VkStridedDeviceAddressRegionKHR*      pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pCallableShaderBindingTable,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdTraceRaysKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
}

void CdlContext::PreCmdTraceRaysIndirectKHR(
    VkCommandBuffer                             commandBuffer,
    const VkStridedDeviceAddressRegionKHR*      pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pCallableShaderBindingTable,
    VkDeviceAddress                             indirectDeviceAddress) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdTraceRaysIndirectKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
}
void CdlContext::PostCmdTraceRaysIndirectKHR(
    VkCommandBuffer                             commandBuffer,
    const VkStridedDeviceAddressRegionKHR*      pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pCallableShaderBindingTable,
    VkDeviceAddress                             indirectDeviceAddress) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdTraceRaysIndirectKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
}

void CdlContext::PreCmdSetRayTracingPipelineStackSizeKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    pipelineStackSize) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);
}
void CdlContext::PostCmdSetRayTracingPipelineStackSizeKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    pipelineStackSize) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);
}

void CdlContext::PreCmdDrawMeshTasksEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawMeshTasksEXT(commandBuffer, groupCountX, groupCountY, groupCountZ);
}
void CdlContext::PostCmdDrawMeshTasksEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawMeshTasksEXT(commandBuffer, groupCountX, groupCountY, groupCountZ);
}

void CdlContext::PreCmdDrawMeshTasksIndirectEXT(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawMeshTasksIndirectEXT(commandBuffer, buffer, offset, drawCount, stride);
}
void CdlContext::PostCmdDrawMeshTasksIndirectEXT(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawMeshTasksIndirectEXT(commandBuffer, buffer, offset, drawCount, stride);
}

void CdlContext::PreCmdDrawMeshTasksIndirectCountEXT(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PreCmdDrawMeshTasksIndirectCountEXT(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
void CdlContext::PostCmdDrawMeshTasksIndirectCountEXT(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  auto p_cmd = crash_diagnostic_layer::GetCdlCommandBuffer(commandBuffer);
  p_cmd->PostCmdDrawMeshTasksIndirectCountEXT(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}



// NOLINTEND

