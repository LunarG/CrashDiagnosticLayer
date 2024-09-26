
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
 * ***   Update source file layer_base_generator.py for modifications
 * *** ---- WARNING! ----
 *
 ****************************************************************************/

// NOLINTBEGIN

#pragma once
virtual VkResult PostCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                                    VkInstance* pInstance, VkResult result) {
    return result;
}

virtual void PreDestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator) {}

virtual VkResult PostCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo,
                                  const VkAllocationCallbacks* pAllocator, VkDevice* pDevice, VkResult result) {
    return result;
}

virtual void PreDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator) {}

virtual VkResult PostEnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, const char* pLayerName,
                                                        uint32_t* pPropertyCount, VkExtensionProperties* pProperties,
                                                        VkResult result) {
    return result;
}

virtual void PostGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue) {}

virtual VkResult QueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) = 0;

virtual VkResult PreQueueWaitIdle(VkQueue queue) { return VK_SUCCESS; }

virtual VkResult PostQueueWaitIdle(VkQueue queue, VkResult result) { return result; }

virtual VkResult PreDeviceWaitIdle(VkDevice device) { return VK_SUCCESS; }

virtual VkResult PostDeviceWaitIdle(VkDevice device, VkResult result) { return result; }

virtual VkResult QueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo,
                                 VkFence fence) = 0;

virtual VkResult PreGetFenceStatus(VkDevice device, VkFence fence) { return VK_SUCCESS; }

virtual VkResult PostGetFenceStatus(VkDevice device, VkFence fence, VkResult result) { return result; }

virtual VkResult PreWaitForFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll,
                                  uint64_t timeout) {
    return VK_SUCCESS;
}

virtual VkResult PostWaitForFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll,
                                   uint64_t timeout, VkResult result) {
    return result;
}

virtual VkResult PreCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo,
                                    const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore) {
    return VK_SUCCESS;
}

virtual VkResult PostCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo,
                                     const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore,
                                     VkResult result) {
    return result;
}

virtual void PreDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) {}

virtual void PostDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) {}

virtual VkResult PreGetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery,
                                        uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride,
                                        VkQueryResultFlags flags) {
    return VK_SUCCESS;
}

virtual VkResult PostGetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery,
                                         uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride,
                                         VkQueryResultFlags flags, VkResult result) {
    return result;
}

virtual VkResult PostCreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo,
                                        const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule,
                                        VkResult result) {
    return result;
}

virtual void PreDestroyShaderModule(VkDevice device, VkShaderModule shaderModule,
                                    const VkAllocationCallbacks* pAllocator) {}

virtual VkResult PostCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount,
                                             const VkGraphicsPipelineCreateInfo* pCreateInfos,
                                             const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                             VkResult result) {
    return result;
}

virtual VkResult PostCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount,
                                            const VkComputePipelineCreateInfo* pCreateInfos,
                                            const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                            VkResult result) {
    return result;
}

virtual void PreDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator) {}

virtual void PostDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator) {}

virtual VkResult PreCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo,
                                      const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool) {
    return VK_SUCCESS;
}

virtual VkResult PostCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo,
                                       const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool,
                                       VkResult result) {
    return result;
}

virtual void PreDestroyCommandPool(VkDevice device, VkCommandPool commandPool,
                                   const VkAllocationCallbacks* pAllocator) {}

virtual void PostDestroyCommandPool(VkDevice device, VkCommandPool commandPool,
                                    const VkAllocationCallbacks* pAllocator) {}

virtual VkResult PreResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags) {
    return VK_SUCCESS;
}

virtual VkResult PostResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags,
                                      VkResult result) {
    return result;
}

virtual VkResult PreAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo,
                                           VkCommandBuffer* pCommandBuffers) {
    return VK_SUCCESS;
}

virtual VkResult PostAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo,
                                            VkCommandBuffer* pCommandBuffers, VkResult result) {
    return result;
}

virtual void PreFreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount,
                                   const VkCommandBuffer* pCommandBuffers) {}

virtual void PostFreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount,
                                    const VkCommandBuffer* pCommandBuffers) {}

virtual VkResult PreBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo) {
    return VK_SUCCESS;
}

virtual VkResult PostBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo,
                                        VkResult result) {
    return result;
}

virtual VkResult PreEndCommandBuffer(VkCommandBuffer commandBuffer) { return VK_SUCCESS; }

virtual VkResult PostEndCommandBuffer(VkCommandBuffer commandBuffer, VkResult result) { return result; }

virtual VkResult PreResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) {
    return VK_SUCCESS;
}

virtual VkResult PostResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags,
                                        VkResult result) {
    return result;
}

virtual void PreCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                VkPipeline pipeline) {}

virtual void PostCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                 VkPipeline pipeline) {}

virtual void PreCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                               const VkViewport* pViewports) {}

virtual void PostCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                const VkViewport* pViewports) {}

virtual void PreCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount,
                              const VkRect2D* pScissors) {}

virtual void PostCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount,
                               const VkRect2D* pScissors) {}

virtual void PreCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) {}

virtual void PostCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) {}

virtual void PreCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp,
                                float depthBiasSlopeFactor) {}

virtual void PostCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp,
                                 float depthBiasSlopeFactor) {}

virtual void PreCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]) {}

virtual void PostCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]) {}

virtual void PreCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) {}

virtual void PostCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) {}

virtual void PreCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                         uint32_t compareMask) {}

virtual void PostCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                          uint32_t compareMask) {}

virtual void PreCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask) {
}

virtual void PostCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                        uint32_t writeMask) {}

virtual void PreCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference) {
}

virtual void PostCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                        uint32_t reference) {}

virtual void PreCmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                      VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount,
                                      const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount,
                                      const uint32_t* pDynamicOffsets) {}

virtual void PostCmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                       VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount,
                                       const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount,
                                       const uint32_t* pDynamicOffsets) {}

virtual void PreCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                   VkIndexType indexType) {}

virtual void PostCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                    VkIndexType indexType) {}

virtual void PreCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                     const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) {}

virtual void PostCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                      const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) {}

virtual void PreCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount,
                        uint32_t firstVertex, uint32_t firstInstance) {}

virtual void PostCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount,
                         uint32_t firstVertex, uint32_t firstInstance) {}

virtual void PreCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount,
                               uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) {}

virtual void PostCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount,
                                uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) {}

virtual void PreCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount,
                                uint32_t stride) {}

virtual void PostCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                 uint32_t drawCount, uint32_t stride) {}

virtual void PreCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                       uint32_t drawCount, uint32_t stride) {}

virtual void PostCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                        uint32_t drawCount, uint32_t stride) {}

virtual void PreCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                            uint32_t groupCountZ) {}

virtual void PostCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                             uint32_t groupCountZ) {}

virtual void PreCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {}

virtual void PostCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {}

virtual void PreCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer,
                              uint32_t regionCount, const VkBufferCopy* pRegions) {}

virtual void PostCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer,
                               uint32_t regionCount, const VkBufferCopy* pRegions) {}

virtual void PreCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                             VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                             const VkImageCopy* pRegions) {}

virtual void PostCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                              VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                              const VkImageCopy* pRegions) {}

virtual void PreCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                             VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                             const VkImageBlit* pRegions, VkFilter filter) {}

virtual void PostCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                              VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                              const VkImageBlit* pRegions, VkFilter filter) {}

virtual void PreCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage,
                                     VkImageLayout dstImageLayout, uint32_t regionCount,
                                     const VkBufferImageCopy* pRegions) {}

virtual void PostCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage,
                                      VkImageLayout dstImageLayout, uint32_t regionCount,
                                      const VkBufferImageCopy* pRegions) {}

virtual void PreCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                     VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions) {}

virtual void PostCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                      VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions) {}

virtual void PreCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                VkDeviceSize dataSize, const void* pData) {}

virtual void PostCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                 VkDeviceSize dataSize, const void* pData) {}

virtual void PreCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                              VkDeviceSize size, uint32_t data) {}

virtual void PostCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                               VkDeviceSize size, uint32_t data) {}

virtual void PreCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                   const VkClearColorValue* pColor, uint32_t rangeCount,
                                   const VkImageSubresourceRange* pRanges) {}

virtual void PostCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                    const VkClearColorValue* pColor, uint32_t rangeCount,
                                    const VkImageSubresourceRange* pRanges) {}

virtual void PreCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                          const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount,
                                          const VkImageSubresourceRange* pRanges) {}

virtual void PostCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                           const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount,
                                           const VkImageSubresourceRange* pRanges) {}

virtual void PreCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                    const VkClearAttachment* pAttachments, uint32_t rectCount,
                                    const VkClearRect* pRects) {}

virtual void PostCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                     const VkClearAttachment* pAttachments, uint32_t rectCount,
                                     const VkClearRect* pRects) {}

virtual void PreCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                const VkImageResolve* pRegions) {}

virtual void PostCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                 VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                 const VkImageResolve* pRegions) {}

virtual void PreCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {}

virtual void PostCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {}

virtual void PreCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {}

virtual void PostCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {}

virtual void PreCmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                              VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask,
                              uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                              uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                              uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) {}

virtual void PostCmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                               VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask,
                               uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                               uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                               uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) {}

virtual void PreCmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask,
                                   VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags,
                                   uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                                   uint32_t bufferMemoryBarrierCount,
                                   const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount,
                                   const VkImageMemoryBarrier* pImageMemoryBarriers) {}

virtual void PostCmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask,
                                    VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags,
                                    uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
                                    uint32_t bufferMemoryBarrierCount,
                                    const VkBufferMemoryBarrier* pBufferMemoryBarriers,
                                    uint32_t imageMemoryBarrierCount,
                                    const VkImageMemoryBarrier* pImageMemoryBarriers) {}

virtual void PreCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                              VkQueryControlFlags flags) {}

virtual void PostCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                               VkQueryControlFlags flags) {}

virtual void PreCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) {}

virtual void PostCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) {}

virtual void PreCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                  uint32_t queryCount) {}

virtual void PostCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                   uint32_t queryCount) {}

virtual void PreCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                  VkQueryPool queryPool, uint32_t query) {}

virtual void PostCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                   VkQueryPool queryPool, uint32_t query) {}

virtual void PreCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                        uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                        VkDeviceSize stride, VkQueryResultFlags flags) {}

virtual void PostCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                         uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                         VkDeviceSize stride, VkQueryResultFlags flags) {}

virtual void PreCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags,
                                 uint32_t offset, uint32_t size, const void* pValues) {}

virtual void PostCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags,
                                  uint32_t offset, uint32_t size, const void* pValues) {}

virtual void PreCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                   VkSubpassContents contents) {}

virtual void PostCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                    VkSubpassContents contents) {}

virtual void PreCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) {}

virtual void PostCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) {}

virtual void PreCmdEndRenderPass(VkCommandBuffer commandBuffer) {}

virtual void PostCmdEndRenderPass(VkCommandBuffer commandBuffer) {}

virtual void PreCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount,
                                   const VkCommandBuffer* pCommandBuffers) {}

virtual void PostCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount,
                                    const VkCommandBuffer* pCommandBuffers) {}

virtual void PreCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) {}

virtual void PostCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) {}

virtual void PreCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
}

virtual void PostCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                 uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                 uint32_t groupCountZ) {}

virtual void PostGetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue) {}

virtual void PreCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                     VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                     uint32_t stride) {}

virtual void PostCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                      VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                      uint32_t stride) {}

virtual void PreCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                            VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                            uint32_t stride) {}

virtual void PostCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                             VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                             uint32_t maxDrawCount, uint32_t stride) {}

virtual void PreCmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                    const VkSubpassBeginInfo* pSubpassBeginInfo) {}

virtual void PostCmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                     const VkSubpassBeginInfo* pSubpassBeginInfo) {}

virtual void PreCmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                                const VkSubpassEndInfo* pSubpassEndInfo) {}

virtual void PostCmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                                 const VkSubpassEndInfo* pSubpassEndInfo) {}

virtual void PreCmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {}

virtual void PostCmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {}

virtual VkResult PreGetSemaphoreCounterValue(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) {
    return VK_SUCCESS;
}

virtual VkResult PostGetSemaphoreCounterValue(VkDevice device, VkSemaphore semaphore, uint64_t* pValue,
                                              VkResult result) {
    return result;
}

virtual VkResult PreWaitSemaphores(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) {
    return VK_SUCCESS;
}

virtual VkResult PostWaitSemaphores(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout,
                                    VkResult result) {
    return result;
}

virtual VkResult PreSignalSemaphore(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) { return VK_SUCCESS; }

virtual VkResult PostSignalSemaphore(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo, VkResult result) {
    return result;
}

virtual void PreCmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) {}

virtual void PostCmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) {}

virtual void PreCmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) {}

virtual void PostCmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) {}

virtual void PreCmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                               const VkDependencyInfo* pDependencyInfos) {}

virtual void PostCmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                const VkDependencyInfo* pDependencyInfos) {}

virtual void PreCmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {}

virtual void PostCmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {}

virtual void PreCmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool,
                                   uint32_t query) {}

virtual void PostCmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool,
                                    uint32_t query) {}

virtual VkResult QueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) = 0;

virtual void PreCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {}

virtual void PostCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {}

virtual void PreCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {}

virtual void PostCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {}

virtual void PreCmdCopyBufferToImage2(VkCommandBuffer commandBuffer,
                                      const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {}

virtual void PostCmdCopyBufferToImage2(VkCommandBuffer commandBuffer,
                                       const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {}

virtual void PreCmdCopyImageToBuffer2(VkCommandBuffer commandBuffer,
                                      const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {}

virtual void PostCmdCopyImageToBuffer2(VkCommandBuffer commandBuffer,
                                       const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {}

virtual void PreCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {}

virtual void PostCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {}

virtual void PreCmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {}

virtual void PostCmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {}

virtual void PreCmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) {}

virtual void PostCmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) {}

virtual void PreCmdEndRendering(VkCommandBuffer commandBuffer) {}

virtual void PostCmdEndRendering(VkCommandBuffer commandBuffer) {}

virtual void PreCmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {}

virtual void PostCmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {}

virtual void PreCmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {}

virtual void PostCmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {}

virtual void PreCmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {}

virtual void PostCmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {}

virtual void PreCmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                        const VkViewport* pViewports) {}

virtual void PostCmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                         const VkViewport* pViewports) {}

virtual void PreCmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                       const VkRect2D* pScissors) {}

virtual void PostCmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                        const VkRect2D* pScissors) {}

virtual void PreCmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                      const VkBuffer* pBuffers, const VkDeviceSize* pOffsets,
                                      const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) {}

virtual void PostCmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                       const VkBuffer* pBuffers, const VkDeviceSize* pOffsets,
                                       const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) {}

virtual void PreCmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {}

virtual void PostCmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {}

virtual void PreCmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {}

virtual void PostCmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {}

virtual void PreCmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {}

virtual void PostCmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {}

virtual void PreCmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {}

virtual void PostCmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {}

virtual void PreCmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {}

virtual void PostCmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {}

virtual void PreCmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {}

virtual void PostCmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                 VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {}

virtual void PreCmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {}

virtual void PostCmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {}

virtual void PreCmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {}

virtual void PostCmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {}

virtual void PreCmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {}

virtual void PostCmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {}

virtual VkResult PreAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout,
                                        VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex) {
    return VK_SUCCESS;
}

virtual VkResult PostAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout,
                                         VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex, VkResult result) {
    return result;
}

virtual VkResult PreQueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo) { return VK_SUCCESS; }

virtual VkResult PostQueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo, VkResult result) {
    return result;
}

virtual void PreCmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo) {}

virtual void PostCmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo) {}

virtual void PreCmdEndVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo) {}

virtual void PostCmdEndVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo) {}

virtual void PreCmdControlVideoCodingKHR(VkCommandBuffer commandBuffer,
                                         const VkVideoCodingControlInfoKHR* pCodingControlInfo) {}

virtual void PostCmdControlVideoCodingKHR(VkCommandBuffer commandBuffer,
                                          const VkVideoCodingControlInfoKHR* pCodingControlInfo) {}

virtual void PreCmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo) {}

virtual void PostCmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo) {}

virtual void PreCmdBeginRenderingKHR(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) {}

virtual void PostCmdBeginRenderingKHR(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) {}

virtual void PreCmdEndRenderingKHR(VkCommandBuffer commandBuffer) {}

virtual void PostCmdEndRenderingKHR(VkCommandBuffer commandBuffer) {}

virtual void PreCmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask) {}

virtual void PostCmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask) {}

virtual void PreCmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                   uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                   uint32_t groupCountZ) {}

virtual void PostCmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                    uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                    uint32_t groupCountZ) {}

virtual void PreCmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                        VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount,
                                        const VkWriteDescriptorSet* pDescriptorWrites) {}

virtual void PostCmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                         VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount,
                                         const VkWriteDescriptorSet* pDescriptorWrites) {}

virtual void PreCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer,
                                                    VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                    VkPipelineLayout layout, uint32_t set, const void* pData) {}

virtual void PostCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer,
                                                     VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                     VkPipelineLayout layout, uint32_t set, const void* pData) {}

virtual void PreCmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                       const VkSubpassBeginInfo* pSubpassBeginInfo) {}

virtual void PostCmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                        const VkSubpassBeginInfo* pSubpassBeginInfo) {}

virtual void PreCmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                                   const VkSubpassEndInfo* pSubpassEndInfo) {}

virtual void PostCmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                                    const VkSubpassEndInfo* pSubpassEndInfo) {}

virtual void PreCmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {}

virtual void PostCmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {}

virtual void PreCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                        VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                        uint32_t stride) {}

virtual void PostCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                         VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                         uint32_t stride) {}

virtual void PreCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                               VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                               uint32_t maxDrawCount, uint32_t stride) {}

virtual void PostCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                uint32_t maxDrawCount, uint32_t stride) {}

virtual VkResult PreGetSemaphoreCounterValueKHR(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) {
    return VK_SUCCESS;
}

virtual VkResult PostGetSemaphoreCounterValueKHR(VkDevice device, VkSemaphore semaphore, uint64_t* pValue,
                                                 VkResult result) {
    return result;
}

virtual VkResult PreWaitSemaphoresKHR(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) {
    return VK_SUCCESS;
}

virtual VkResult PostWaitSemaphoresKHR(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout,
                                       VkResult result) {
    return result;
}

virtual VkResult PreSignalSemaphoreKHR(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) { return VK_SUCCESS; }

virtual VkResult PostSignalSemaphoreKHR(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo, VkResult result) {
    return result;
}

virtual void PreCmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize,
                                             const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {}

virtual void PostCmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize,
                                              const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {}

virtual void PreCmdSetRenderingAttachmentLocationsKHR(VkCommandBuffer commandBuffer,
                                                      const VkRenderingAttachmentLocationInfoKHR* pLocationInfo) {}

virtual void PostCmdSetRenderingAttachmentLocationsKHR(VkCommandBuffer commandBuffer,
                                                       const VkRenderingAttachmentLocationInfoKHR* pLocationInfo) {}

virtual void PreCmdSetRenderingInputAttachmentIndicesKHR(
    VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfoKHR* pInputAttachmentIndexInfo) {}

virtual void PostCmdSetRenderingInputAttachmentIndicesKHR(
    VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfoKHR* pInputAttachmentIndexInfo) {}

virtual void PreCmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo) {}

virtual void PostCmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo) {}

virtual void PreCmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) {
}

virtual void PostCmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event,
                                 const VkDependencyInfo* pDependencyInfo) {}

virtual void PreCmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) {}

virtual void PostCmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) {}

virtual void PreCmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                  const VkDependencyInfo* pDependencyInfos) {}

virtual void PostCmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                   const VkDependencyInfo* pDependencyInfos) {}

virtual void PreCmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {}

virtual void PostCmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {}

virtual void PreCmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool,
                                      uint32_t query) {}

virtual void PostCmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                       VkQueryPool queryPool, uint32_t query) {}

virtual VkResult QueueSubmit2KHR(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) = 0;

virtual void PreCmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkBuffer dstBuffer,
                                         VkDeviceSize dstOffset, uint32_t marker) {}

virtual void PostCmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                          VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {}

virtual void PreCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {}

virtual void PostCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {}

virtual void PreCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {}

virtual void PostCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {}

virtual void PreCmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer,
                                         const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {}

virtual void PostCmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer,
                                          const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {}

virtual void PreCmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer,
                                         const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {}

virtual void PostCmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer,
                                          const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {}

virtual void PreCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {}

virtual void PostCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {}

virtual void PreCmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {}

virtual void PostCmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {}

virtual void PreCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress) {}

virtual void PostCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress) {}

virtual void PreCmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                       VkDeviceSize size, VkIndexType indexType) {}

virtual void PostCmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                        VkDeviceSize size, VkIndexType indexType) {}

virtual void PreCmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                     uint16_t lineStipplePattern) {}

virtual void PostCmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                      uint16_t lineStipplePattern) {}

virtual void PreCmdBindDescriptorSets2KHR(VkCommandBuffer commandBuffer,
                                          const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo) {}

virtual void PostCmdBindDescriptorSets2KHR(VkCommandBuffer commandBuffer,
                                           const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo) {}

virtual void PreCmdPushConstants2KHR(VkCommandBuffer commandBuffer, const VkPushConstantsInfoKHR* pPushConstantsInfo) {}

virtual void PostCmdPushConstants2KHR(VkCommandBuffer commandBuffer, const VkPushConstantsInfoKHR* pPushConstantsInfo) {
}

virtual void PreCmdPushDescriptorSet2KHR(VkCommandBuffer commandBuffer,
                                         const VkPushDescriptorSetInfoKHR* pPushDescriptorSetInfo) {}

virtual void PostCmdPushDescriptorSet2KHR(VkCommandBuffer commandBuffer,
                                          const VkPushDescriptorSetInfoKHR* pPushDescriptorSetInfo) {}

virtual void PreCmdPushDescriptorSetWithTemplate2KHR(
    VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo) {}

virtual void PostCmdPushDescriptorSetWithTemplate2KHR(
    VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo) {}

virtual void PreCmdSetDescriptorBufferOffsets2EXT(
    VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo) {}

virtual void PostCmdSetDescriptorBufferOffsets2EXT(
    VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo) {}

virtual void PreCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    VkCommandBuffer commandBuffer,
    const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo) {}

virtual void PostCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    VkCommandBuffer commandBuffer,
    const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo) {}

virtual VkResult PreCreateDebugReportCallbackEXT(VkInstance instance,
                                                 const VkDebugReportCallbackCreateInfoEXT* pCreateInfo,
                                                 const VkAllocationCallbacks* pAllocator,
                                                 VkDebugReportCallbackEXT* pCallback) {
    return VK_SUCCESS;
}

virtual VkResult PostCreateDebugReportCallbackEXT(VkInstance instance,
                                                  const VkDebugReportCallbackCreateInfoEXT* pCreateInfo,
                                                  const VkAllocationCallbacks* pAllocator,
                                                  VkDebugReportCallbackEXT* pCallback, VkResult result) {
    return result;
}

virtual void PreDestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback,
                                              const VkAllocationCallbacks* pAllocator) {}

virtual void PostDestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback,
                                               const VkAllocationCallbacks* pAllocator) {}

virtual VkResult PreDebugMarkerSetObjectNameEXT(VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo) {
    return VK_SUCCESS;
}

virtual VkResult PostDebugMarkerSetObjectNameEXT(VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo,
                                                 VkResult result) {
    return result;
}

virtual void PreCmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {}

virtual void PostCmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {}

virtual void PreCmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) {}

virtual void PostCmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) {}

virtual void PreCmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {}

virtual void PostCmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
}

virtual void PreCmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                   uint32_t bindingCount, const VkBuffer* pBuffers,
                                                   const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes) {}

virtual void PostCmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                    uint32_t bindingCount, const VkBuffer* pBuffers,
                                                    const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes) {}

virtual void PreCmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                             uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                             const VkDeviceSize* pCounterBufferOffsets) {}

virtual void PostCmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                              uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                              const VkDeviceSize* pCounterBufferOffsets) {}

virtual void PreCmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                           uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                           const VkDeviceSize* pCounterBufferOffsets) {}

virtual void PostCmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                            uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
                                            const VkDeviceSize* pCounterBufferOffsets) {}

virtual void PreCmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                        VkQueryControlFlags flags, uint32_t index) {}

virtual void PostCmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                         VkQueryControlFlags flags, uint32_t index) {}

virtual void PreCmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                      uint32_t index) {}

virtual void PostCmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                       uint32_t index) {}

virtual void PreCmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount,
                                            uint32_t firstInstance, VkBuffer counterBuffer,
                                            VkDeviceSize counterBufferOffset, uint32_t counterOffset,
                                            uint32_t vertexStride) {}

virtual void PostCmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount,
                                             uint32_t firstInstance, VkBuffer counterBuffer,
                                             VkDeviceSize counterBufferOffset, uint32_t counterOffset,
                                             uint32_t vertexStride) {}

virtual void PreCmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo) {}

virtual void PostCmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo) {}

virtual void PreCmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                        VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                        uint32_t stride) {}

virtual void PostCmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                         VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                         uint32_t stride) {}

virtual void PreCmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                               VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                               uint32_t maxDrawCount, uint32_t stride) {}

virtual void PostCmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                uint32_t maxDrawCount, uint32_t stride) {}

virtual void PreCmdBeginConditionalRenderingEXT(VkCommandBuffer commandBuffer,
                                                const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) {}

virtual void PostCmdBeginConditionalRenderingEXT(VkCommandBuffer commandBuffer,
                                                 const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) {
}

virtual void PreCmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer) {}

virtual void PostCmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer) {}

virtual void PreCmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                         const VkViewportWScalingNV* pViewportWScalings) {}

virtual void PostCmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                          const VkViewportWScalingNV* pViewportWScalings) {}

virtual void PreCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle,
                                          uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) {}

virtual void PostCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle,
                                           uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) {}

virtual void PreCmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable) {}

virtual void PostCmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable) {}

virtual void PreCmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer,
                                              VkDiscardRectangleModeEXT discardRectangleMode) {}

virtual void PostCmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer,
                                               VkDiscardRectangleModeEXT discardRectangleMode) {}

virtual VkResult PreSetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo) {
    return VK_SUCCESS;
}

virtual VkResult PostSetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo,
                                                VkResult result) {
    return result;
}

virtual void PreCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {}

virtual void PostCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {}

virtual void PreCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) {}

virtual void PostCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) {}

virtual void PreCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {}

virtual void PostCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {}

virtual VkResult PreCreateDebugUtilsMessengerEXT(VkInstance instance,
                                                 const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
                                                 const VkAllocationCallbacks* pAllocator,
                                                 VkDebugUtilsMessengerEXT* pMessenger) {
    return VK_SUCCESS;
}

virtual VkResult PostCreateDebugUtilsMessengerEXT(VkInstance instance,
                                                  const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
                                                  const VkAllocationCallbacks* pAllocator,
                                                  VkDebugUtilsMessengerEXT* pMessenger, VkResult result) {
    return result;
}

virtual void PreDestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT messenger,
                                              const VkAllocationCallbacks* pAllocator) {}

virtual void PostDestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT messenger,
                                               const VkAllocationCallbacks* pAllocator) {}

#ifdef VK_ENABLE_BETA_EXTENSIONS
virtual void PreCmdInitializeGraphScratchMemoryAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch) {}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
virtual void PostCmdInitializeGraphScratchMemoryAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch) {}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
virtual void PreCmdDispatchGraphAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                     const VkDispatchGraphCountInfoAMDX* pCountInfo) {}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
virtual void PostCmdDispatchGraphAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                      const VkDispatchGraphCountInfoAMDX* pCountInfo) {}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
virtual void PreCmdDispatchGraphIndirectAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                             const VkDispatchGraphCountInfoAMDX* pCountInfo) {}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
virtual void PostCmdDispatchGraphIndirectAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                              const VkDispatchGraphCountInfoAMDX* pCountInfo) {}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
virtual void PreCmdDispatchGraphIndirectCountAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                                  VkDeviceAddress countInfo) {}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
virtual void PostCmdDispatchGraphIndirectCountAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                                   VkDeviceAddress countInfo) {}
#endif  // VK_ENABLE_BETA_EXTENSIONS

virtual void PreCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer,
                                         const VkSampleLocationsInfoEXT* pSampleLocationsInfo) {}

virtual void PostCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer,
                                          const VkSampleLocationsInfoEXT* pSampleLocationsInfo) {}

virtual void PreCmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView,
                                          VkImageLayout imageLayout) {}

virtual void PostCmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView,
                                           VkImageLayout imageLayout) {}

virtual void PreCmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                                   uint32_t viewportCount,
                                                   const VkShadingRatePaletteNV* pShadingRatePalettes) {}

virtual void PostCmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                                    uint32_t viewportCount,
                                                    const VkShadingRatePaletteNV* pShadingRatePalettes) {}

virtual void PreCmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType,
                                          uint32_t customSampleOrderCount,
                                          const VkCoarseSampleOrderCustomNV* pCustomSampleOrders) {}

virtual void PostCmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType,
                                           uint32_t customSampleOrderCount,
                                           const VkCoarseSampleOrderCustomNV* pCustomSampleOrders) {}

virtual void PreCmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer,
                                                const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData,
                                                VkDeviceSize instanceOffset, VkBool32 update,
                                                VkAccelerationStructureNV dst, VkAccelerationStructureNV src,
                                                VkBuffer scratch, VkDeviceSize scratchOffset) {}

virtual void PostCmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer,
                                                 const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData,
                                                 VkDeviceSize instanceOffset, VkBool32 update,
                                                 VkAccelerationStructureNV dst, VkAccelerationStructureNV src,
                                                 VkBuffer scratch, VkDeviceSize scratchOffset) {}

virtual void PreCmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst,
                                               VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode) {
}

virtual void PostCmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst,
                                                VkAccelerationStructureNV src,
                                                VkCopyAccelerationStructureModeKHR mode) {}

virtual void PreCmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer,
                               VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer,
                               VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride,
                               VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset,
                               VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer,
                               VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride,
                               uint32_t width, uint32_t height, uint32_t depth) {}

virtual void PostCmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer,
                                VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer,
                                VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride,
                                VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset,
                                VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer,
                                VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride,
                                uint32_t width, uint32_t height, uint32_t depth) {}

virtual void PreCmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer,
                                                           uint32_t accelerationStructureCount,
                                                           const VkAccelerationStructureNV* pAccelerationStructures,
                                                           VkQueryType queryType, VkQueryPool queryPool,
                                                           uint32_t firstQuery) {}

virtual void PostCmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer,
                                                            uint32_t accelerationStructureCount,
                                                            const VkAccelerationStructureNV* pAccelerationStructures,
                                                            VkQueryType queryType, VkQueryPool queryPool,
                                                            uint32_t firstQuery) {}

virtual void PreCmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                        VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {}

virtual void PostCmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                         VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {}

virtual void PreCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask) {}

virtual void PostCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask) {}

virtual void PreCmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                           uint32_t drawCount, uint32_t stride) {}

virtual void PostCmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                            uint32_t drawCount, uint32_t stride) {}

virtual void PreCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                uint32_t maxDrawCount, uint32_t stride) {}

virtual void PostCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                 VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                 uint32_t maxDrawCount, uint32_t stride) {}

virtual void PreCmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                               uint32_t exclusiveScissorCount,
                                               const VkBool32* pExclusiveScissorEnables) {}

virtual void PostCmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                                uint32_t exclusiveScissorCount,
                                                const VkBool32* pExclusiveScissorEnables) {}

virtual void PreCmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                         uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors) {}

virtual void PostCmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                          uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors) {}

virtual void PreCmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker) {}

virtual void PostCmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker) {}

virtual VkResult PreCmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer,
                                                 const VkPerformanceMarkerInfoINTEL* pMarkerInfo) {
    return VK_SUCCESS;
}

virtual VkResult PostCmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer,
                                                  const VkPerformanceMarkerInfoINTEL* pMarkerInfo, VkResult result) {
    return result;
}

virtual VkResult PreCmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer,
                                                       const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo) {
    return VK_SUCCESS;
}

virtual VkResult PostCmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer,
                                                        const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo,
                                                        VkResult result) {
    return result;
}

virtual VkResult PreCmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer,
                                                   const VkPerformanceOverrideInfoINTEL* pOverrideInfo) {
    return VK_SUCCESS;
}

virtual VkResult PostCmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer,
                                                    const VkPerformanceOverrideInfoINTEL* pOverrideInfo,
                                                    VkResult result) {
    return result;
}

virtual void PreCmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                     uint16_t lineStipplePattern) {}

virtual void PostCmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                      uint16_t lineStipplePattern) {}

virtual void PreCmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {}

virtual void PostCmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {}

virtual void PreCmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {}

virtual void PostCmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {}

virtual void PreCmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {}

virtual void PostCmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {}

virtual void PreCmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                           const VkViewport* pViewports) {}

virtual void PostCmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                            const VkViewport* pViewports) {}

virtual void PreCmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                          const VkRect2D* pScissors) {}

virtual void PostCmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                           const VkRect2D* pScissors) {}

virtual void PreCmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                         const VkBuffer* pBuffers, const VkDeviceSize* pOffsets,
                                         const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) {}

virtual void PostCmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                          const VkBuffer* pBuffers, const VkDeviceSize* pOffsets,
                                          const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) {}

virtual void PreCmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {}

virtual void PostCmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {}

virtual void PreCmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {}

virtual void PostCmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {}

virtual void PreCmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {}

virtual void PostCmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {}

virtual void PreCmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {}

virtual void PostCmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {}

virtual void PreCmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {}

virtual void PostCmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {}

virtual void PreCmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                   VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {}

virtual void PostCmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                    VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {}

virtual void PreCmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer,
                                                 const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {}

virtual void PostCmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer,
                                                  const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {}

virtual void PreCmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                              const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {}

virtual void PostCmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                               const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {}

virtual void PreCmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                             VkPipeline pipeline, uint32_t groupIndex) {}

virtual void PostCmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                              VkPipeline pipeline, uint32_t groupIndex) {}

virtual void PreCmdSetDepthBias2EXT(VkCommandBuffer commandBuffer, const VkDepthBiasInfoEXT* pDepthBiasInfo) {}

virtual void PostCmdSetDepthBias2EXT(VkCommandBuffer commandBuffer, const VkDepthBiasInfoEXT* pDepthBiasInfo) {}

virtual void PreCmdCudaLaunchKernelNV(VkCommandBuffer commandBuffer, const VkCudaLaunchInfoNV* pLaunchInfo) {}

virtual void PostCmdCudaLaunchKernelNV(VkCommandBuffer commandBuffer, const VkCudaLaunchInfoNV* pLaunchInfo) {}

virtual void PreCmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount,
                                            const VkDescriptorBufferBindingInfoEXT* pBindingInfos) {}

virtual void PostCmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount,
                                             const VkDescriptorBufferBindingInfoEXT* pBindingInfos) {}

virtual void PreCmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                 VkPipelineLayout layout, uint32_t firstSet, uint32_t setCount,
                                                 const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets) {}

virtual void PostCmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                  VkPipelineLayout layout, uint32_t firstSet, uint32_t setCount,
                                                  const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets) {}

virtual void PreCmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer commandBuffer,
                                                           VkPipelineBindPoint pipelineBindPoint,
                                                           VkPipelineLayout layout, uint32_t set) {}

virtual void PostCmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer commandBuffer,
                                                            VkPipelineBindPoint pipelineBindPoint,
                                                            VkPipelineLayout layout, uint32_t set) {}

virtual void PreCmdSetFragmentShadingRateEnumNV(VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate,
                                                const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {}

virtual void PostCmdSetFragmentShadingRateEnumNV(VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate,
                                                 const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {}

virtual void PreCmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
                                     const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions,
                                     uint32_t vertexAttributeDescriptionCount,
                                     const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) {}

virtual void PostCmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
                                      const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions,
                                      uint32_t vertexAttributeDescriptionCount,
                                      const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) {}

virtual void PreCmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer) {}

virtual void PostCmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer) {}

virtual void PreCmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer, VkImageView imageView,
                                            VkImageLayout imageLayout) {}

virtual void PostCmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer, VkImageView imageView,
                                             VkImageLayout imageLayout) {}

virtual void PreCmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints) {}

virtual void PostCmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints) {}

virtual void PreCmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {}

virtual void PostCmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {}

virtual void PreCmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {}

virtual void PostCmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {}

virtual void PreCmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp) {}

virtual void PostCmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp) {}

virtual void PreCmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {}

virtual void PostCmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {}

virtual void PreCmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                          const VkBool32* pColorWriteEnables) {}

virtual void PostCmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                           const VkBool32* pColorWriteEnables) {}

virtual void PreCmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                const VkMultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount, uint32_t firstInstance,
                                uint32_t stride) {}

virtual void PostCmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                 const VkMultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount, uint32_t firstInstance,
                                 uint32_t stride) {}

virtual void PreCmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                       const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount,
                                       uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset) {}

virtual void PostCmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                        const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount,
                                        uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset) {}

virtual void PreCmdBuildMicromapsEXT(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                     const VkMicromapBuildInfoEXT* pInfos) {}

virtual void PostCmdBuildMicromapsEXT(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                      const VkMicromapBuildInfoEXT* pInfos) {}

virtual void PreCmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo) {}

virtual void PostCmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo) {}

virtual void PreCmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo) {}

virtual void PostCmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo) {
}

virtual void PreCmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo) {}

virtual void PostCmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo) {
}

virtual void PreCmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount,
                                               const VkMicromapEXT* pMicromaps, VkQueryType queryType,
                                               VkQueryPool queryPool, uint32_t firstQuery) {}

virtual void PostCmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount,
                                                const VkMicromapEXT* pMicromaps, VkQueryType queryType,
                                                VkQueryPool queryPool, uint32_t firstQuery) {}

virtual void PreCmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                     uint32_t groupCountZ) {}

virtual void PostCmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                      uint32_t groupCountZ) {}

virtual void PreCmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {}

virtual void PostCmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {}

virtual void PreCmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                        uint32_t copyCount, uint32_t stride) {}

virtual void PostCmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                         uint32_t copyCount, uint32_t stride) {}

virtual void PreCmdCopyMemoryToImageIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                               uint32_t copyCount, uint32_t stride, VkImage dstImage,
                                               VkImageLayout dstImageLayout,
                                               const VkImageSubresourceLayers* pImageSubresources) {}

virtual void PostCmdCopyMemoryToImageIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                                uint32_t copyCount, uint32_t stride, VkImage dstImage,
                                                VkImageLayout dstImageLayout,
                                                const VkImageSubresourceLayers* pImageSubresources) {}

virtual void PreCmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount,
                                      const VkDecompressMemoryRegionNV* pDecompressMemoryRegions) {}

virtual void PostCmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount,
                                       const VkDecompressMemoryRegionNV* pDecompressMemoryRegions) {}

virtual void PreCmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer,
                                                   VkDeviceAddress indirectCommandsAddress,
                                                   VkDeviceAddress indirectCommandsCountAddress, uint32_t stride) {}

virtual void PostCmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer,
                                                    VkDeviceAddress indirectCommandsAddress,
                                                    VkDeviceAddress indirectCommandsCountAddress, uint32_t stride) {}

virtual void PreCmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                  VkPipeline pipeline) {}

virtual void PostCmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                   VkPipeline pipeline) {}

virtual void PreCmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClampEnable) {}

virtual void PostCmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClampEnable) {}

virtual void PreCmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode) {}

virtual void PostCmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode) {}

virtual void PreCmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer,
                                              VkSampleCountFlagBits rasterizationSamples) {}

virtual void PostCmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer,
                                               VkSampleCountFlagBits rasterizationSamples) {}

virtual void PreCmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples,
                                    const VkSampleMask* pSampleMask) {}

virtual void PostCmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples,
                                     const VkSampleMask* pSampleMask) {}

virtual void PreCmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable) {}

virtual void PostCmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable) {}

virtual void PreCmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable) {}

virtual void PostCmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable) {}

virtual void PreCmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable) {}

virtual void PostCmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable) {}

virtual void PreCmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                          uint32_t attachmentCount, const VkBool32* pColorBlendEnables) {}

virtual void PostCmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                           uint32_t attachmentCount, const VkBool32* pColorBlendEnables) {}

virtual void PreCmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                            uint32_t attachmentCount,
                                            const VkColorBlendEquationEXT* pColorBlendEquations) {}

virtual void PostCmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                             uint32_t attachmentCount,
                                             const VkColorBlendEquationEXT* pColorBlendEquations) {}

virtual void PreCmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                        uint32_t attachmentCount, const VkColorComponentFlags* pColorWriteMasks) {}

virtual void PostCmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                         uint32_t attachmentCount, const VkColorComponentFlags* pColorWriteMasks) {}

virtual void PreCmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer,
                                                  VkTessellationDomainOrigin domainOrigin) {}

virtual void PostCmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer,
                                                   VkTessellationDomainOrigin domainOrigin) {}

virtual void PreCmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer, uint32_t rasterizationStream) {}

virtual void PostCmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer, uint32_t rasterizationStream) {}

virtual void PreCmdSetConservativeRasterizationModeEXT(
    VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode) {}

virtual void PostCmdSetConservativeRasterizationModeEXT(
    VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode) {}

virtual void PreCmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer commandBuffer,
                                                          float extraPrimitiveOverestimationSize) {}

virtual void PostCmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer commandBuffer,
                                                           float extraPrimitiveOverestimationSize) {}

virtual void PreCmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClipEnable) {}

virtual void PostCmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClipEnable) {}

virtual void PreCmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable) {}

virtual void PostCmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable) {}

virtual void PreCmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                            uint32_t attachmentCount,
                                            const VkColorBlendAdvancedEXT* pColorBlendAdvanced) {}

virtual void PostCmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                             uint32_t attachmentCount,
                                             const VkColorBlendAdvancedEXT* pColorBlendAdvanced) {}

virtual void PreCmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer,
                                             VkProvokingVertexModeEXT provokingVertexMode) {}

virtual void PostCmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer,
                                              VkProvokingVertexModeEXT provokingVertexMode) {}

virtual void PreCmdSetLineRasterizationModeEXT(VkCommandBuffer commandBuffer,
                                               VkLineRasterizationModeEXT lineRasterizationMode) {}

virtual void PostCmdSetLineRasterizationModeEXT(VkCommandBuffer commandBuffer,
                                                VkLineRasterizationModeEXT lineRasterizationMode) {}

virtual void PreCmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable) {}

virtual void PostCmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable) {}

virtual void PreCmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne) {}

virtual void PostCmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne) {}

virtual void PreCmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable) {}

virtual void PostCmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable) {}

virtual void PreCmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                        const VkViewportSwizzleNV* pViewportSwizzles) {}

virtual void PostCmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                         const VkViewportSwizzleNV* pViewportSwizzles) {}

virtual void PreCmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable) {}

virtual void PostCmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable) {}

virtual void PreCmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation) {}

virtual void PostCmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation) {}

virtual void PreCmdSetCoverageModulationModeNV(VkCommandBuffer commandBuffer,
                                               VkCoverageModulationModeNV coverageModulationMode) {}

virtual void PostCmdSetCoverageModulationModeNV(VkCommandBuffer commandBuffer,
                                                VkCoverageModulationModeNV coverageModulationMode) {}

virtual void PreCmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer,
                                                      VkBool32 coverageModulationTableEnable) {}

virtual void PostCmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer,
                                                       VkBool32 coverageModulationTableEnable) {}

virtual void PreCmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount,
                                                const float* pCoverageModulationTable) {}

virtual void PostCmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount,
                                                 const float* pCoverageModulationTable) {}

virtual void PreCmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable) {}

virtual void PostCmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable) {}

virtual void PreCmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer commandBuffer,
                                                         VkBool32 representativeFragmentTestEnable) {}

virtual void PostCmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer commandBuffer,
                                                          VkBool32 representativeFragmentTestEnable) {}

virtual void PreCmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer,
                                              VkCoverageReductionModeNV coverageReductionMode) {}

virtual void PostCmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer,
                                               VkCoverageReductionModeNV coverageReductionMode) {}

virtual void PreCmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session,
                                        const VkOpticalFlowExecuteInfoNV* pExecuteInfo) {}

virtual void PostCmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session,
                                         const VkOpticalFlowExecuteInfoNV* pExecuteInfo) {}

virtual void PreCmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount,
                                  const VkShaderStageFlagBits* pStages, const VkShaderEXT* pShaders) {}

virtual void PostCmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount,
                                   const VkShaderStageFlagBits* pStages, const VkShaderEXT* pShaders) {}

virtual void PreCmdSetDepthClampRangeEXT(VkCommandBuffer commandBuffer, VkDepthClampModeEXT depthClampMode,
                                         const VkDepthClampRangeEXT* pDepthClampRange) {}

virtual void PostCmdSetDepthClampRangeEXT(VkCommandBuffer commandBuffer, VkDepthClampModeEXT depthClampMode,
                                          const VkDepthClampRangeEXT* pDepthClampRange) {}

virtual void PreCmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer, VkImageAspectFlags aspectMask) {}

virtual void PostCmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer, VkImageAspectFlags aspectMask) {}

virtual void PreCmdPreprocessGeneratedCommandsEXT(VkCommandBuffer commandBuffer,
                                                  const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo,
                                                  VkCommandBuffer stateCommandBuffer) {}

virtual void PostCmdPreprocessGeneratedCommandsEXT(VkCommandBuffer commandBuffer,
                                                   const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo,
                                                   VkCommandBuffer stateCommandBuffer) {}

virtual void PreCmdExecuteGeneratedCommandsEXT(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                               const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo) {}

virtual void PostCmdExecuteGeneratedCommandsEXT(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                                const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo) {}

virtual void PreCmdBuildAccelerationStructuresKHR(
    VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) {}

virtual void PostCmdBuildAccelerationStructuresKHR(
    VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) {}

virtual void PreCmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                                          const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
                                                          const VkDeviceAddress* pIndirectDeviceAddresses,
                                                          const uint32_t* pIndirectStrides,
                                                          const uint32_t* const* ppMaxPrimitiveCounts) {}

virtual void PostCmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                                           const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
                                                           const VkDeviceAddress* pIndirectDeviceAddresses,
                                                           const uint32_t* pIndirectStrides,
                                                           const uint32_t* const* ppMaxPrimitiveCounts) {}

virtual void PreCmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                                const VkCopyAccelerationStructureInfoKHR* pInfo) {}

virtual void PostCmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                                 const VkCopyAccelerationStructureInfoKHR* pInfo) {}

virtual void PreCmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer commandBuffer,
                                                        const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) {}

virtual void PostCmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer commandBuffer,
                                                         const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) {}

virtual void PreCmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                                        const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) {}

virtual void PostCmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                                         const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) {}

virtual void PreCmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer commandBuffer,
                                                            uint32_t accelerationStructureCount,
                                                            const VkAccelerationStructureKHR* pAccelerationStructures,
                                                            VkQueryType queryType, VkQueryPool queryPool,
                                                            uint32_t firstQuery) {}

virtual void PostCmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer commandBuffer,
                                                             uint32_t accelerationStructureCount,
                                                             const VkAccelerationStructureKHR* pAccelerationStructures,
                                                             VkQueryType queryType, VkQueryPool queryPool,
                                                             uint32_t firstQuery) {}

virtual void PreCmdTraceRaysKHR(VkCommandBuffer commandBuffer,
                                const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width,
                                uint32_t height, uint32_t depth) {}

virtual void PostCmdTraceRaysKHR(VkCommandBuffer commandBuffer,
                                 const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                 const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                 const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                 const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width,
                                 uint32_t height, uint32_t depth) {}

virtual void PreCmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer,
                                        const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                        const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                        const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                        const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                        VkDeviceAddress indirectDeviceAddress) {}

virtual void PostCmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer,
                                         const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                         const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                         const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                         const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                         VkDeviceAddress indirectDeviceAddress) {}

virtual void PreCmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize) {}

virtual void PostCmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize) {}

virtual void PreCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                    uint32_t groupCountZ) {}

virtual void PostCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                     uint32_t groupCountZ) {}

virtual void PreCmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                            uint32_t drawCount, uint32_t stride) {}

virtual void PostCmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                             uint32_t drawCount, uint32_t stride) {}

virtual void PreCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                 VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                 uint32_t maxDrawCount, uint32_t stride) {}

virtual void PostCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                  VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                  uint32_t maxDrawCount, uint32_t stride) {}

// NOLINTEND
