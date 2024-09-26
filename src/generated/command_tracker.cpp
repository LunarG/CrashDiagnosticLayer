
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

#include <vulkan/vulkan.h>
#include <cassert>

#include "command_common.h"
#include "command_tracker.h"

void CommandTracker::Reset() {
    commands_.clear();
    recorder_.Reset();
}
void CommandTracker::BeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo) {
    Command cmd{};
    cmd.type = Command::Type::kBeginCommandBuffer;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordBeginCommandBuffer(commandBuffer, pBeginInfo);
    commands_.push_back(cmd);
}

void CommandTracker::EndCommandBuffer(VkCommandBuffer commandBuffer) {
    Command cmd{};
    cmd.type = Command::Type::kEndCommandBuffer;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordEndCommandBuffer(commandBuffer);
    commands_.push_back(cmd);
}

void CommandTracker::ResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) {
    Command cmd{};
    cmd.type = Command::Type::kResetCommandBuffer;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordResetCommandBuffer(commandBuffer, flags);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                     VkPipeline pipeline) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindPipeline;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                    const VkViewport* pViewports) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetViewport;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount,
                                   const VkRect2D* pScissors) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetScissor;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetLineWidth;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetLineWidth(commandBuffer, lineWidth);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp,
                                     float depthBiasSlopeFactor) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthBias;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters =
        recorder_.RecordCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetBlendConstants;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetBlendConstants(commandBuffer, blendConstants);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthBounds;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                              uint32_t compareMask) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetStencilCompareMask;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                            uint32_t writeMask) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetStencilWriteMask;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                            uint32_t reference) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetStencilReference;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetStencilReference(commandBuffer, faceMask, reference);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                           VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount,
                                           const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount,
                                           const uint32_t* pDynamicOffsets) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindDescriptorSets;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters =
        recorder_.RecordCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount,
                                              pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                        VkIndexType indexType) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindIndexBuffer;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                          const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindVertexBuffers;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters =
        recorder_.RecordCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount,
                             uint32_t firstVertex, uint32_t firstInstance) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDraw;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount,
                                    uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawIndexed;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset,
                                                    firstInstance);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                     uint32_t drawCount, uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawIndirect;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                            uint32_t drawCount, uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawIndexedIndirect;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                 uint32_t groupCountZ) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDispatch;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDispatchIndirect;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDispatchIndirect(commandBuffer, buffer, offset);
    commands_.push_back(cmd);
}

void CommandTracker::CmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer,
                                   uint32_t regionCount, const VkBufferCopy* pRegions) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyBuffer;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
    commands_.push_back(cmd);
}

void CommandTracker::CmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                  VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                  const VkImageCopy* pRegions) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyImage;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout,
                                                  regionCount, pRegions);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                  VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                  const VkImageBlit* pRegions, VkFilter filter) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBlitImage;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout,
                                                  regionCount, pRegions, filter);
    commands_.push_back(cmd);
}

void CommandTracker::CmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage,
                                          VkImageLayout dstImageLayout, uint32_t regionCount,
                                          const VkBufferImageCopy* pRegions) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyBufferToImage;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters =
        recorder_.RecordCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
    commands_.push_back(cmd);
}

void CommandTracker::CmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                          VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyImageToBuffer;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters =
        recorder_.RecordCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
    commands_.push_back(cmd);
}

void CommandTracker::CmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                     VkDeviceSize dataSize, const void* pData) {
    Command cmd{};
    cmd.type = Command::Type::kCmdUpdateBuffer;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
    commands_.push_back(cmd);
}

void CommandTracker::CmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                   VkDeviceSize size, uint32_t data) {
    Command cmd{};
    cmd.type = Command::Type::kCmdFillBuffer;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
    commands_.push_back(cmd);
}

void CommandTracker::CmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                        const VkClearColorValue* pColor, uint32_t rangeCount,
                                        const VkImageSubresourceRange* pRanges) {
    Command cmd{};
    cmd.type = Command::Type::kCmdClearColorImage;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
    commands_.push_back(cmd);
}

void CommandTracker::CmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                               const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount,
                                               const VkImageSubresourceRange* pRanges) {
    Command cmd{};
    cmd.type = Command::Type::kCmdClearDepthStencilImage;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil,
                                                               rangeCount, pRanges);
    commands_.push_back(cmd);
}

void CommandTracker::CmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                         const VkClearAttachment* pAttachments, uint32_t rectCount,
                                         const VkClearRect* pRects) {
    Command cmd{};
    cmd.type = Command::Type::kCmdClearAttachments;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters =
        recorder_.RecordCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
    commands_.push_back(cmd);
}

void CommandTracker::CmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                     VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                     const VkImageResolve* pRegions) {
    Command cmd{};
    cmd.type = Command::Type::kCmdResolveImage;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout,
                                                     regionCount, pRegions);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetEvent;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetEvent(commandBuffer, event, stageMask);
    commands_.push_back(cmd);
}

void CommandTracker::CmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
    Command cmd{};
    cmd.type = Command::Type::kCmdResetEvent;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdResetEvent(commandBuffer, event, stageMask);
    commands_.push_back(cmd);
}

void CommandTracker::CmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                   VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask,
                                   uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                                   uint32_t bufferMemoryBarrierCount,
                                   const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount,
                                   const VkImageMemoryBarrier* pImageMemoryBarriers) {
    Command cmd{};
    cmd.type = Command::Type::kCmdWaitEvents;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdWaitEvents(
        commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers,
        bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    commands_.push_back(cmd);
}

void CommandTracker::CmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask,
                                        VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags,
                                        uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                                        uint32_t bufferMemoryBarrierCount,
                                        const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                        uint32_t imageMemoryBarrierCount,
                                        const VkImageMemoryBarrier* pImageMemoryBarriers) {
    Command cmd{};
    cmd.type = Command::Type::kCmdPipelineBarrier;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdPipelineBarrier(
        commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers,
        bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                   VkQueryControlFlags flags) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBeginQuery;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBeginQuery(commandBuffer, queryPool, query, flags);
    commands_.push_back(cmd);
}

void CommandTracker::CmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) {
    Command cmd{};
    cmd.type = Command::Type::kCmdEndQuery;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdEndQuery(commandBuffer, queryPool, query);
    commands_.push_back(cmd);
}

void CommandTracker::CmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                       uint32_t queryCount) {
    Command cmd{};
    cmd.type = Command::Type::kCmdResetQueryPool;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
    commands_.push_back(cmd);
}

void CommandTracker::CmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                       VkQueryPool queryPool, uint32_t query) {
    Command cmd{};
    cmd.type = Command::Type::kCmdWriteTimestamp;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
    commands_.push_back(cmd);
}

void CommandTracker::CmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                             uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                             VkDeviceSize stride, VkQueryResultFlags flags) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyQueryPoolResults;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount,
                                                             dstBuffer, dstOffset, stride, flags);
    commands_.push_back(cmd);
}

void CommandTracker::CmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout,
                                      VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size,
                                      const void* pValues) {
    Command cmd{};
    cmd.type = Command::Type::kCmdPushConstants;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                        VkSubpassContents contents) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBeginRenderPass;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
    commands_.push_back(cmd);
}

void CommandTracker::CmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) {
    Command cmd{};
    cmd.type = Command::Type::kCmdNextSubpass;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdNextSubpass(commandBuffer, contents);
    commands_.push_back(cmd);
}

void CommandTracker::CmdEndRenderPass(VkCommandBuffer commandBuffer) {
    Command cmd{};
    cmd.type = Command::Type::kCmdEndRenderPass;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdEndRenderPass(commandBuffer);
    commands_.push_back(cmd);
}

void CommandTracker::CmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount,
                                        const VkCommandBuffer* pCommandBuffers) {
    Command cmd{};
    cmd.type = Command::Type::kCmdExecuteCommands;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDeviceMask;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetDeviceMask(commandBuffer, deviceMask);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                     uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                     uint32_t groupCountZ) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDispatchBase;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX,
                                                     groupCountY, groupCountZ);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                          VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                          uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawIndirectCount;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                                          maxDrawCount, stride);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                 VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                 uint32_t maxDrawCount, uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawIndexedIndirectCount;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer,
                                                                 countBufferOffset, maxDrawCount, stride);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                         const VkSubpassBeginInfo* pSubpassBeginInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBeginRenderPass2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                                     const VkSubpassEndInfo* pSubpassEndInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdNextSubpass2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdEndRenderPass2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event,
                                  const VkDependencyInfo* pDependencyInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetEvent2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetEvent2(commandBuffer, event, pDependencyInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) {
    Command cmd{};
    cmd.type = Command::Type::kCmdResetEvent2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdResetEvent2(commandBuffer, event, stageMask);
    commands_.push_back(cmd);
}

void CommandTracker::CmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                    const VkDependencyInfo* pDependencyInfos) {
    Command cmd{};
    cmd.type = Command::Type::kCmdWaitEvents2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
    commands_.push_back(cmd);
}

void CommandTracker::CmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdPipelineBarrier2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdPipelineBarrier2(commandBuffer, pDependencyInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                        VkQueryPool queryPool, uint32_t query) {
    Command cmd{};
    cmd.type = Command::Type::kCmdWriteTimestamp2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
    commands_.push_back(cmd);
}

void CommandTracker::CmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyBuffer2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyImage2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdCopyImage2(commandBuffer, pCopyImageInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdCopyBufferToImage2(VkCommandBuffer commandBuffer,
                                           const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyBufferToImage2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdCopyImageToBuffer2(VkCommandBuffer commandBuffer,
                                           const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyImageToBuffer2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBlitImage2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBlitImage2(commandBuffer, pBlitImageInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdResolveImage2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdResolveImage2(commandBuffer, pResolveImageInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBeginRendering;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBeginRendering(commandBuffer, pRenderingInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdEndRendering(VkCommandBuffer commandBuffer) {
    Command cmd{};
    cmd.type = Command::Type::kCmdEndRendering;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdEndRendering(commandBuffer);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetCullMode;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetCullMode(commandBuffer, cullMode);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetFrontFace;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetFrontFace(commandBuffer, frontFace);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetPrimitiveTopology;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                             const VkViewport* pViewports) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetViewportWithCount;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                            const VkRect2D* pScissors) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetScissorWithCount;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                           const VkBuffer* pBuffers, const VkDeviceSize* pOffsets,
                                           const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindVertexBuffers2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers,
                                                           pOffsets, pSizes, pStrides);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthTestEnable;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetDepthTestEnable(commandBuffer, depthTestEnable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthWriteEnable;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthCompareOp;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetDepthCompareOp(commandBuffer, depthCompareOp);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthBoundsTestEnable;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetStencilTestEnable;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                     VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetStencilOp;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetRasterizerDiscardEnable;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthBiasEnable;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetPrimitiveRestartEnable;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer,
                                            const VkVideoBeginCodingInfoKHR* pBeginInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBeginVideoCodingKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdEndVideoCodingKHR(VkCommandBuffer commandBuffer,
                                          const VkVideoEndCodingInfoKHR* pEndCodingInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdEndVideoCodingKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdControlVideoCodingKHR(VkCommandBuffer commandBuffer,
                                              const VkVideoCodingControlInfoKHR* pCodingControlInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdControlVideoCodingKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDecodeVideoKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDecodeVideoKHR(commandBuffer, pDecodeInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBeginRenderingKHR(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBeginRenderingKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBeginRenderingKHR(commandBuffer, pRenderingInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdEndRenderingKHR(VkCommandBuffer commandBuffer) {
    Command cmd{};
    cmd.type = Command::Type::kCmdEndRenderingKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdEndRenderingKHR(commandBuffer);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDeviceMaskKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetDeviceMaskKHR(commandBuffer, deviceMask);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                        uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                        uint32_t groupCountZ) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDispatchBaseKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX,
                                                        groupCountY, groupCountZ);
    commands_.push_back(cmd);
}

void CommandTracker::CmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                             VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount,
                                             const VkWriteDescriptorSet* pDescriptorWrites) {
    Command cmd{};
    cmd.type = Command::Type::kCmdPushDescriptorSetKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set,
                                                             descriptorWriteCount, pDescriptorWrites);
    commands_.push_back(cmd);
}

void CommandTracker::CmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer,
                                                         VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                         VkPipelineLayout layout, uint32_t set, const void* pData) {
    Command cmd{};
    cmd.type = Command::Type::kCmdPushDescriptorSetWithTemplateKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate,
                                                                         layout, set, pData);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer,
                                            const VkRenderPassBeginInfo* pRenderPassBegin,
                                            const VkSubpassBeginInfo* pSubpassBeginInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBeginRenderPass2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                                        const VkSubpassEndInfo* pSubpassEndInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdNextSubpass2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdEndRenderPass2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                             VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                             uint32_t maxDrawCount, uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawIndirectCountKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer,
                                                             countBufferOffset, maxDrawCount, stride);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                    VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                    uint32_t maxDrawCount, uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawIndexedIndirectCountKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer,
                                                                    countBufferOffset, maxDrawCount, stride);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize,
                                                  const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetFragmentShadingRateKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetRenderingAttachmentLocationsKHR(VkCommandBuffer commandBuffer,
                                                           const VkRenderingAttachmentLocationInfoKHR* pLocationInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetRenderingAttachmentLocationsKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetRenderingAttachmentLocationsKHR(commandBuffer, pLocationInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetRenderingInputAttachmentIndicesKHR(
    VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfoKHR* pInputAttachmentIndexInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetRenderingInputAttachmentIndicesKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetRenderingInputAttachmentIndicesKHR(commandBuffer, pInputAttachmentIndexInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdEncodeVideoKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdEncodeVideoKHR(commandBuffer, pEncodeInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event,
                                     const VkDependencyInfo* pDependencyInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetEvent2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetEvent2KHR(commandBuffer, event, pDependencyInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) {
    Command cmd{};
    cmd.type = Command::Type::kCmdResetEvent2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdResetEvent2KHR(commandBuffer, event, stageMask);
    commands_.push_back(cmd);
}

void CommandTracker::CmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                       const VkDependencyInfo* pDependencyInfos) {
    Command cmd{};
    cmd.type = Command::Type::kCmdWaitEvents2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos);
    commands_.push_back(cmd);
}

void CommandTracker::CmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdPipelineBarrier2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                           VkQueryPool queryPool, uint32_t query) {
    Command cmd{};
    cmd.type = Command::Type::kCmdWriteTimestamp2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query);
    commands_.push_back(cmd);
}

void CommandTracker::CmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                              VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {
    Command cmd{};
    cmd.type = Command::Type::kCmdWriteBufferMarker2AMD;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
    commands_.push_back(cmd);
}

void CommandTracker::CmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyBuffer2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyImage2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdCopyImage2KHR(commandBuffer, pCopyImageInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer,
                                              const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyBufferToImage2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer,
                                              const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyImageToBuffer2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBlitImage2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBlitImage2KHR(commandBuffer, pBlitImageInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdResolveImage2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdResolveImage2KHR(commandBuffer, pResolveImageInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress) {
    Command cmd{};
    cmd.type = Command::Type::kCmdTraceRaysIndirect2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdTraceRaysIndirect2KHR(commandBuffer, indirectDeviceAddress);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                            VkDeviceSize size, VkIndexType indexType) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindIndexBuffer2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBindIndexBuffer2KHR(commandBuffer, buffer, offset, size, indexType);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                          uint16_t lineStipplePattern) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetLineStippleKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetLineStippleKHR(commandBuffer, lineStippleFactor, lineStipplePattern);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBindDescriptorSets2KHR(VkCommandBuffer commandBuffer,
                                               const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindDescriptorSets2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBindDescriptorSets2KHR(commandBuffer, pBindDescriptorSetsInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdPushConstants2KHR(VkCommandBuffer commandBuffer,
                                          const VkPushConstantsInfoKHR* pPushConstantsInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdPushConstants2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdPushConstants2KHR(commandBuffer, pPushConstantsInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdPushDescriptorSet2KHR(VkCommandBuffer commandBuffer,
                                              const VkPushDescriptorSetInfoKHR* pPushDescriptorSetInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdPushDescriptorSet2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdPushDescriptorSet2KHR(commandBuffer, pPushDescriptorSetInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdPushDescriptorSetWithTemplate2KHR(
    VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdPushDescriptorSetWithTemplate2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters =
        recorder_.RecordCmdPushDescriptorSetWithTemplate2KHR(commandBuffer, pPushDescriptorSetWithTemplateInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetDescriptorBufferOffsets2EXT(
    VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDescriptorBufferOffsets2EXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetDescriptorBufferOffsets2EXT(commandBuffer, pSetDescriptorBufferOffsetsInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBindDescriptorBufferEmbeddedSamplers2EXT(
    VkCommandBuffer commandBuffer,
    const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindDescriptorBufferEmbeddedSamplers2EXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBindDescriptorBufferEmbeddedSamplers2EXT(
        commandBuffer, pBindDescriptorBufferEmbeddedSamplersInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer,
                                            const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDebugMarkerBeginEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    labels_.push_back(pMarkerInfo->pMarkerName);
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDebugMarkerEndEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    // do not crash even if the application ends without a marker present
    if (!labels_.empty()) {
        labels_.pop_back();
    }
    cmd.parameters = recorder_.RecordCmdDebugMarkerEndEXT(commandBuffer);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer,
                                             const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDebugMarkerInsertEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                        uint32_t bindingCount, const VkBuffer* pBuffers,
                                                        const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindTransformFeedbackBuffersEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount,
                                                                        pBuffers, pOffsets, pSizes);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                                  uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                                  const VkDeviceSize* pCounterBufferOffsets) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBeginTransformFeedbackEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount,
                                                                  pCounterBuffers, pCounterBufferOffsets);
    commands_.push_back(cmd);
}

void CommandTracker::CmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                                uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                                const VkDeviceSize* pCounterBufferOffsets) {
    Command cmd{};
    cmd.type = Command::Type::kCmdEndTransformFeedbackEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount,
                                                                pCounterBuffers, pCounterBufferOffsets);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                             VkQueryControlFlags flags, uint32_t index) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBeginQueryIndexedEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
    commands_.push_back(cmd);
}

void CommandTracker::CmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                           uint32_t index) {
    Command cmd{};
    cmd.type = Command::Type::kCmdEndQueryIndexedEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount,
                                                 uint32_t firstInstance, VkBuffer counterBuffer,
                                                 VkDeviceSize counterBufferOffset, uint32_t counterOffset,
                                                 uint32_t vertexStride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawIndirectByteCountEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDrawIndirectByteCountEXT(
        commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
    commands_.push_back(cmd);
}

void CommandTracker::CmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCuLaunchKernelNVX;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                             VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                             uint32_t maxDrawCount, uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawIndirectCountAMD;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer,
                                                             countBufferOffset, maxDrawCount, stride);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                    VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                    uint32_t maxDrawCount, uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawIndexedIndirectCountAMD;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer,
                                                                    countBufferOffset, maxDrawCount, stride);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBeginConditionalRenderingEXT(
    VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBeginConditionalRenderingEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
    commands_.push_back(cmd);
}

void CommandTracker::CmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer) {
    Command cmd{};
    cmd.type = Command::Type::kCmdEndConditionalRenderingEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdEndConditionalRenderingEXT(commandBuffer);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                              uint32_t viewportCount, const VkViewportWScalingNV* pViewportWScalings) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetViewportWScalingNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters =
        recorder_.RecordCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle,
                                               uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDiscardRectangleEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle,
                                                               discardRectangleCount, pDiscardRectangles);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDiscardRectangleEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer,
                                                   VkDiscardRectangleModeEXT discardRectangleMode) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDiscardRectangleModeEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBeginDebugUtilsLabelEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    labels_.push_back(pLabelInfo->pLabelName);
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) {
    Command cmd{};
    cmd.type = Command::Type::kCmdEndDebugUtilsLabelEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    // do not crash even if the application ends without a marker present
    if (!labels_.empty()) {
        labels_.pop_back();
    }
    cmd.parameters = recorder_.RecordCmdEndDebugUtilsLabelEXT(commandBuffer);
    commands_.push_back(cmd);
}

void CommandTracker::CmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer,
                                                 const VkDebugUtilsLabelEXT* pLabelInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdInsertDebugUtilsLabelEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    commands_.push_back(cmd);
}

#ifdef VK_ENABLE_BETA_EXTENSIONS
void CommandTracker::CmdInitializeGraphScratchMemoryAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch) {
    Command cmd{};
    cmd.type = Command::Type::kCmdInitializeGraphScratchMemoryAMDX;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdInitializeGraphScratchMemoryAMDX(commandBuffer, scratch);
    commands_.push_back(cmd);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void CommandTracker::CmdDispatchGraphAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                          const VkDispatchGraphCountInfoAMDX* pCountInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDispatchGraphAMDX;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDispatchGraphAMDX(commandBuffer, scratch, pCountInfo);
    commands_.push_back(cmd);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void CommandTracker::CmdDispatchGraphIndirectAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                                  const VkDispatchGraphCountInfoAMDX* pCountInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDispatchGraphIndirectAMDX;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDispatchGraphIndirectAMDX(commandBuffer, scratch, pCountInfo);
    commands_.push_back(cmd);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void CommandTracker::CmdDispatchGraphIndirectCountAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                                       VkDeviceAddress countInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDispatchGraphIndirectCountAMDX;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDispatchGraphIndirectCountAMDX(commandBuffer, scratch, countInfo);
    commands_.push_back(cmd);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

void CommandTracker::CmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer,
                                              const VkSampleLocationsInfoEXT* pSampleLocationsInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetSampleLocationsEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView,
                                               VkImageLayout imageLayout) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindShadingRateImageNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                                        uint32_t viewportCount,
                                                        const VkShadingRatePaletteNV* pShadingRatePalettes) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetViewportShadingRatePaletteNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount,
                                                                        pShadingRatePalettes);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType,
                                               uint32_t customSampleOrderCount,
                                               const VkCoarseSampleOrderCustomNV* pCustomSampleOrders) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetCoarseSampleOrderNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount,
                                                               pCustomSampleOrders);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer,
                                                     const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData,
                                                     VkDeviceSize instanceOffset, VkBool32 update,
                                                     VkAccelerationStructureNV dst, VkAccelerationStructureNV src,
                                                     VkBuffer scratch, VkDeviceSize scratchOffset) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBuildAccelerationStructureNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset,
                                                                     update, dst, src, scratch, scratchOffset);
    commands_.push_back(cmd);
}

void CommandTracker::CmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst,
                                                    VkAccelerationStructureNV src,
                                                    VkCopyAccelerationStructureModeKHR mode) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyAccelerationStructureNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
    commands_.push_back(cmd);
}

void CommandTracker::CmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer,
                                    VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer,
                                    VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride,
                                    VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset,
                                    VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer,
                                    VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride,
                                    uint32_t width, uint32_t height, uint32_t depth) {
    Command cmd{};
    cmd.type = Command::Type::kCmdTraceRaysNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdTraceRaysNV(
        commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer,
        missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset,
        hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset,
        callableShaderBindingStride, width, height, depth);
    commands_.push_back(cmd);
}

void CommandTracker::CmdWriteAccelerationStructuresPropertiesNV(
    VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
    const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool,
    uint32_t firstQuery) {
    Command cmd{};
    cmd.type = Command::Type::kCmdWriteAccelerationStructuresPropertiesNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdWriteAccelerationStructuresPropertiesNV(
        commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
    commands_.push_back(cmd);
}

void CommandTracker::CmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                             VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {
    Command cmd{};
    cmd.type = Command::Type::kCmdWriteBufferMarkerAMD;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters =
        recorder_.RecordCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawMeshTasksNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                uint32_t drawCount, uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawMeshTasksIndirectNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                     VkDeviceSize offset, VkBuffer countBuffer,
                                                     VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                     uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawMeshTasksIndirectCountNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer,
                                                                     countBufferOffset, maxDrawCount, stride);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                                    uint32_t exclusiveScissorCount,
                                                    const VkBool32* pExclusiveScissorEnables) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetExclusiveScissorEnableNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetExclusiveScissorEnableNV(commandBuffer, firstExclusiveScissor,
                                                                    exclusiveScissorCount, pExclusiveScissorEnables);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                              uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetExclusiveScissorNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor,
                                                              exclusiveScissorCount, pExclusiveScissors);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetCheckpointNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer,
                                                  const VkPerformanceMarkerInfoINTEL* pMarkerInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetPerformanceMarkerINTEL;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetPerformanceMarkerINTEL(commandBuffer, pMarkerInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer,
                                                        const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetPerformanceStreamMarkerINTEL;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetPerformanceStreamMarkerINTEL(commandBuffer, pMarkerInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer,
                                                    const VkPerformanceOverrideInfoINTEL* pOverrideInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetPerformanceOverrideINTEL;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetPerformanceOverrideINTEL(commandBuffer, pOverrideInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                          uint16_t lineStipplePattern) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetLineStippleEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetCullModeEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetCullModeEXT(commandBuffer, cullMode);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetFrontFaceEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetFrontFaceEXT(commandBuffer, frontFace);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetPrimitiveTopologyEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                                const VkViewport* pViewports) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetViewportWithCountEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                               const VkRect2D* pScissors) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetScissorWithCountEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                              uint32_t bindingCount, const VkBuffer* pBuffers,
                                              const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
                                              const VkDeviceSize* pStrides) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindVertexBuffers2EXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers,
                                                              pOffsets, pSizes, pStrides);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthTestEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthWriteEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthCompareOpEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthBoundsTestEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetStencilTestEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                        VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetStencilOpEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters =
        recorder_.RecordCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    commands_.push_back(cmd);
}

void CommandTracker::CmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer,
                                                      const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdPreprocessGeneratedCommandsNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                                   const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdExecuteGeneratedCommandsNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters =
        recorder_.RecordCmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                  VkPipeline pipeline, uint32_t groupIndex) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindPipelineShaderGroupNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters =
        recorder_.RecordCmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetDepthBias2EXT(VkCommandBuffer commandBuffer, const VkDepthBiasInfoEXT* pDepthBiasInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthBias2EXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetDepthBias2EXT(commandBuffer, pDepthBiasInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdCudaLaunchKernelNV(VkCommandBuffer commandBuffer, const VkCudaLaunchInfoNV* pLaunchInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCudaLaunchKernelNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdCudaLaunchKernelNV(commandBuffer, pLaunchInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount,
                                                 const VkDescriptorBufferBindingInfoEXT* pBindingInfos) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindDescriptorBuffersEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBindDescriptorBuffersEXT(commandBuffer, bufferCount, pBindingInfos);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer commandBuffer,
                                                      VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout,
                                                      uint32_t firstSet, uint32_t setCount,
                                                      const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDescriptorBufferOffsetsEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetDescriptorBufferOffsetsEXT(commandBuffer, pipelineBindPoint, layout,
                                                                      firstSet, setCount, pBufferIndices, pOffsets);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer commandBuffer,
                                                                VkPipelineBindPoint pipelineBindPoint,
                                                                VkPipelineLayout layout, uint32_t set) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindDescriptorBufferEmbeddedSamplersEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters =
        recorder_.RecordCmdBindDescriptorBufferEmbeddedSamplersEXT(commandBuffer, pipelineBindPoint, layout, set);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetFragmentShadingRateEnumNV(VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate,
                                                     const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetFragmentShadingRateEnumNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
                                          const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions,
                                          uint32_t vertexAttributeDescriptionCount,
                                          const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetVertexInputEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters =
        recorder_.RecordCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions,
                                             vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSubpassShadingHUAWEI;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSubpassShadingHUAWEI(commandBuffer);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer, VkImageView imageView,
                                                 VkImageLayout imageLayout) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindInvocationMaskHUAWEI;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBindInvocationMaskHUAWEI(commandBuffer, imageView, imageLayout);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetPatchControlPointsEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetRasterizerDiscardEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthBiasEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetLogicOpEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetLogicOpEXT(commandBuffer, logicOp);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetPrimitiveRestartEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                               const VkBool32* pColorWriteEnables) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetColorWriteEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                     const VkMultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount,
                                     uint32_t firstInstance, uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawMultiEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters =
        recorder_.RecordCmdDrawMultiEXT(commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                            const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount,
                                            uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawMultiIndexedEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDrawMultiIndexedEXT(commandBuffer, drawCount, pIndexInfo, instanceCount,
                                                            firstInstance, stride, pVertexOffset);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBuildMicromapsEXT(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                          const VkMicromapBuildInfoEXT* pInfos) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBuildMicromapsEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBuildMicromapsEXT(commandBuffer, infoCount, pInfos);
    commands_.push_back(cmd);
}

void CommandTracker::CmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyMicromapEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdCopyMicromapEXT(commandBuffer, pInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer,
                                                const VkCopyMicromapToMemoryInfoEXT* pInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyMicromapToMemoryEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdCopyMicromapToMemoryEXT(commandBuffer, pInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer,
                                                const VkCopyMemoryToMicromapInfoEXT* pInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyMemoryToMicromapEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdCopyMemoryToMicromapEXT(commandBuffer, pInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount,
                                                    const VkMicromapEXT* pMicromaps, VkQueryType queryType,
                                                    VkQueryPool queryPool, uint32_t firstQuery) {
    Command cmd{};
    cmd.type = Command::Type::kCmdWriteMicromapsPropertiesEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdWriteMicromapsPropertiesEXT(commandBuffer, micromapCount, pMicromaps, queryType,
                                                                    queryPool, firstQuery);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                          uint32_t groupCountZ) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawClusterHUAWEI;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDrawClusterHUAWEI(commandBuffer, groupCountX, groupCountY, groupCountZ);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawClusterIndirectHUAWEI;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDrawClusterIndirectHUAWEI(commandBuffer, buffer, offset);
    commands_.push_back(cmd);
}

void CommandTracker::CmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                             uint32_t copyCount, uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyMemoryIndirectNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdCopyMemoryIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride);
    commands_.push_back(cmd);
}

void CommandTracker::CmdCopyMemoryToImageIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                                    uint32_t copyCount, uint32_t stride, VkImage dstImage,
                                                    VkImageLayout dstImageLayout,
                                                    const VkImageSubresourceLayers* pImageSubresources) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyMemoryToImageIndirectNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdCopyMemoryToImageIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride,
                                                                    dstImage, dstImageLayout, pImageSubresources);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount,
                                           const VkDecompressMemoryRegionNV* pDecompressMemoryRegions) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDecompressMemoryNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters =
        recorder_.RecordCmdDecompressMemoryNV(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer,
                                                        VkDeviceAddress indirectCommandsAddress,
                                                        VkDeviceAddress indirectCommandsCountAddress, uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDecompressMemoryIndirectCountNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDecompressMemoryIndirectCountNV(commandBuffer, indirectCommandsAddress,
                                                                        indirectCommandsCountAddress, stride);
    commands_.push_back(cmd);
}

void CommandTracker::CmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer,
                                                       VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) {
    Command cmd{};
    cmd.type = Command::Type::kCmdUpdatePipelineIndirectBufferNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdUpdatePipelineIndirectBufferNV(commandBuffer, pipelineBindPoint, pipeline);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClampEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthClampEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetDepthClampEnableEXT(commandBuffer, depthClampEnable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetPolygonModeEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetPolygonModeEXT(commandBuffer, polygonMode);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer,
                                                   VkSampleCountFlagBits rasterizationSamples) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetRasterizationSamplesEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetRasterizationSamplesEXT(commandBuffer, rasterizationSamples);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples,
                                         const VkSampleMask* pSampleMask) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetSampleMaskEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetSampleMaskEXT(commandBuffer, samples, pSampleMask);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetAlphaToCoverageEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetAlphaToCoverageEnableEXT(commandBuffer, alphaToCoverageEnable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetAlphaToOneEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetAlphaToOneEnableEXT(commandBuffer, alphaToOneEnable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetLogicOpEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetLogicOpEnableEXT(commandBuffer, logicOpEnable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                               uint32_t attachmentCount, const VkBool32* pColorBlendEnables) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetColorBlendEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters =
        recorder_.RecordCmdSetColorBlendEnableEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                                 uint32_t attachmentCount,
                                                 const VkColorBlendEquationEXT* pColorBlendEquations) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetColorBlendEquationEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetColorBlendEquationEXT(commandBuffer, firstAttachment, attachmentCount,
                                                                 pColorBlendEquations);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                             uint32_t attachmentCount, const VkColorComponentFlags* pColorWriteMasks) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetColorWriteMaskEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters =
        recorder_.RecordCmdSetColorWriteMaskEXT(commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer,
                                                       VkTessellationDomainOrigin domainOrigin) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetTessellationDomainOriginEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetTessellationDomainOriginEXT(commandBuffer, domainOrigin);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer, uint32_t rasterizationStream) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetRasterizationStreamEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetRasterizationStreamEXT(commandBuffer, rasterizationStream);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetConservativeRasterizationModeEXT(
    VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetConservativeRasterizationModeEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters =
        recorder_.RecordCmdSetConservativeRasterizationModeEXT(commandBuffer, conservativeRasterizationMode);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer commandBuffer,
                                                               float extraPrimitiveOverestimationSize) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetExtraPrimitiveOverestimationSizeEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters =
        recorder_.RecordCmdSetExtraPrimitiveOverestimationSizeEXT(commandBuffer, extraPrimitiveOverestimationSize);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClipEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthClipEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetDepthClipEnableEXT(commandBuffer, depthClipEnable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetSampleLocationsEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetSampleLocationsEnableEXT(commandBuffer, sampleLocationsEnable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                                 uint32_t attachmentCount,
                                                 const VkColorBlendAdvancedEXT* pColorBlendAdvanced) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetColorBlendAdvancedEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetColorBlendAdvancedEXT(commandBuffer, firstAttachment, attachmentCount,
                                                                 pColorBlendAdvanced);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer,
                                                  VkProvokingVertexModeEXT provokingVertexMode) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetProvokingVertexModeEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetProvokingVertexModeEXT(commandBuffer, provokingVertexMode);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetLineRasterizationModeEXT(VkCommandBuffer commandBuffer,
                                                    VkLineRasterizationModeEXT lineRasterizationMode) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetLineRasterizationModeEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetLineRasterizationModeEXT(commandBuffer, lineRasterizationMode);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetLineStippleEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetLineStippleEnableEXT(commandBuffer, stippledLineEnable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthClipNegativeOneToOneEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetDepthClipNegativeOneToOneEXT(commandBuffer, negativeOneToOne);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetViewportWScalingEnableNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetViewportWScalingEnableNV(commandBuffer, viewportWScalingEnable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                             uint32_t viewportCount, const VkViewportSwizzleNV* pViewportSwizzles) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetViewportSwizzleNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters =
        recorder_.RecordCmdSetViewportSwizzleNV(commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetCoverageToColorEnableNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetCoverageToColorEnableNV(commandBuffer, coverageToColorEnable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetCoverageToColorLocationNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetCoverageToColorLocationNV(commandBuffer, coverageToColorLocation);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetCoverageModulationModeNV(VkCommandBuffer commandBuffer,
                                                    VkCoverageModulationModeNV coverageModulationMode) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetCoverageModulationModeNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetCoverageModulationModeNV(commandBuffer, coverageModulationMode);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer,
                                                           VkBool32 coverageModulationTableEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetCoverageModulationTableEnableNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters =
        recorder_.RecordCmdSetCoverageModulationTableEnableNV(commandBuffer, coverageModulationTableEnable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer,
                                                     uint32_t coverageModulationTableCount,
                                                     const float* pCoverageModulationTable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetCoverageModulationTableNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetCoverageModulationTableNV(commandBuffer, coverageModulationTableCount,
                                                                     pCoverageModulationTable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetShadingRateImageEnableNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetShadingRateImageEnableNV(commandBuffer, shadingRateImageEnable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer commandBuffer,
                                                              VkBool32 representativeFragmentTestEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetRepresentativeFragmentTestEnableNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters =
        recorder_.RecordCmdSetRepresentativeFragmentTestEnableNV(commandBuffer, representativeFragmentTestEnable);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer,
                                                   VkCoverageReductionModeNV coverageReductionMode) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetCoverageReductionModeNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetCoverageReductionModeNV(commandBuffer, coverageReductionMode);
    commands_.push_back(cmd);
}

void CommandTracker::CmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session,
                                             const VkOpticalFlowExecuteInfoNV* pExecuteInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdOpticalFlowExecuteNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdOpticalFlowExecuteNV(commandBuffer, session, pExecuteInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount,
                                       const VkShaderStageFlagBits* pStages, const VkShaderEXT* pShaders) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindShadersEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBindShadersEXT(commandBuffer, stageCount, pStages, pShaders);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetDepthClampRangeEXT(VkCommandBuffer commandBuffer, VkDepthClampModeEXT depthClampMode,
                                              const VkDepthClampRangeEXT* pDepthClampRange) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthClampRangeEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetDepthClampRangeEXT(commandBuffer, depthClampMode, pDepthClampRange);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer,
                                                           VkImageAspectFlags aspectMask) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetAttachmentFeedbackLoopEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetAttachmentFeedbackLoopEnableEXT(commandBuffer, aspectMask);
    commands_.push_back(cmd);
}

void CommandTracker::CmdPreprocessGeneratedCommandsEXT(VkCommandBuffer commandBuffer,
                                                       const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo,
                                                       VkCommandBuffer stateCommandBuffer) {
    Command cmd{};
    cmd.type = Command::Type::kCmdPreprocessGeneratedCommandsEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters =
        recorder_.RecordCmdPreprocessGeneratedCommandsEXT(commandBuffer, pGeneratedCommandsInfo, stateCommandBuffer);
    commands_.push_back(cmd);
}

void CommandTracker::CmdExecuteGeneratedCommandsEXT(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                                    const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdExecuteGeneratedCommandsEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters =
        recorder_.RecordCmdExecuteGeneratedCommandsEXT(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBuildAccelerationStructuresKHR(
    VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBuildAccelerationStructuresKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters =
        recorder_.RecordCmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
    commands_.push_back(cmd);
}

void CommandTracker::CmdBuildAccelerationStructuresIndirectKHR(
    VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkDeviceAddress* pIndirectDeviceAddresses, const uint32_t* pIndirectStrides,
    const uint32_t* const* ppMaxPrimitiveCounts) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBuildAccelerationStructuresIndirectKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdBuildAccelerationStructuresIndirectKHR(
        commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
    commands_.push_back(cmd);
}

void CommandTracker::CmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                                     const VkCopyAccelerationStructureInfoKHR* pInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyAccelerationStructureKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdCopyAccelerationStructureKHR(commandBuffer, pInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer commandBuffer,
                                                             const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyAccelerationStructureToMemoryKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                                             const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyMemoryToAccelerationStructureKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);
    commands_.push_back(cmd);
}

void CommandTracker::CmdWriteAccelerationStructuresPropertiesKHR(
    VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
    const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool,
    uint32_t firstQuery) {
    Command cmd{};
    cmd.type = Command::Type::kCmdWriteAccelerationStructuresPropertiesKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdWriteAccelerationStructuresPropertiesKHR(
        commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
    commands_.push_back(cmd);
}

void CommandTracker::CmdTraceRaysKHR(VkCommandBuffer commandBuffer,
                                     const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                     const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                     const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                     const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width,
                                     uint32_t height, uint32_t depth) {
    Command cmd{};
    cmd.type = Command::Type::kCmdTraceRaysKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters =
        recorder_.RecordCmdTraceRaysKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable,
                                        pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
    commands_.push_back(cmd);
}

void CommandTracker::CmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer,
                                             const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                             const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                             const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                             const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                             VkDeviceAddress indirectDeviceAddress) {
    Command cmd{};
    cmd.type = Command::Type::kCmdTraceRaysIndirectKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdTraceRaysIndirectKHR(commandBuffer, pRaygenShaderBindingTable,
                                                             pMissShaderBindingTable, pHitShaderBindingTable,
                                                             pCallableShaderBindingTable, indirectDeviceAddress);
    commands_.push_back(cmd);
}

void CommandTracker::CmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetRayTracingPipelineStackSizeKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                         uint32_t groupCountZ) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawMeshTasksEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDrawMeshTasksEXT(commandBuffer, groupCountX, groupCountY, groupCountZ);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                 uint32_t drawCount, uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawMeshTasksIndirectEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDrawMeshTasksIndirectEXT(commandBuffer, buffer, offset, drawCount, stride);
    commands_.push_back(cmd);
}

void CommandTracker::CmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                      VkDeviceSize offset, VkBuffer countBuffer,
                                                      VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                      uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawMeshTasksIndirectCountEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.labels = labels_;
    cmd.parameters = recorder_.RecordCmdDrawMeshTasksIndirectCountEXT(commandBuffer, buffer, offset, countBuffer,
                                                                      countBufferOffset, maxDrawCount, stride);
    commands_.push_back(cmd);
}

// NOLINTEND
