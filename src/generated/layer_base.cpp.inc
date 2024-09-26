
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

static VKAPI_ATTR void VKAPI_CALL InterceptGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex,
                                                          uint32_t queueIndex, VkQueue* pQueue) {
    auto layer_data = GetDeviceLayerData(DataKey(device));
    PFN_vkGetDeviceQueue pfn = layer_data->dispatch_table.GetDeviceQueue;
    if (pfn != nullptr) {
        pfn(device, queueFamilyIndex, queueIndex, pQueue);
    }

    layer_data->interceptor->PostGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
}

static VKAPI_ATTR VkResult VKAPI_CALL InterceptQueueWaitIdle(VkQueue queue) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(queue));
    layer_data->interceptor->PreQueueWaitIdle(queue);

    PFN_vkQueueWaitIdle pfn = layer_data->dispatch_table.QueueWaitIdle;
    if (pfn != nullptr) {
        result = pfn(queue);
    }

    result = layer_data->interceptor->PostQueueWaitIdle(queue, result);
    return result;
}

static VKAPI_ATTR VkResult VKAPI_CALL InterceptDeviceWaitIdle(VkDevice device) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(device));
    layer_data->interceptor->PreDeviceWaitIdle(device);

    PFN_vkDeviceWaitIdle pfn = layer_data->dispatch_table.DeviceWaitIdle;
    if (pfn != nullptr) {
        result = pfn(device);
    }

    result = layer_data->interceptor->PostDeviceWaitIdle(device, result);
    return result;
}

static VKAPI_ATTR VkResult VKAPI_CALL InterceptGetFenceStatus(VkDevice device, VkFence fence) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(device));
    layer_data->interceptor->PreGetFenceStatus(device, fence);

    PFN_vkGetFenceStatus pfn = layer_data->dispatch_table.GetFenceStatus;
    if (pfn != nullptr) {
        result = pfn(device, fence);
    }

    result = layer_data->interceptor->PostGetFenceStatus(device, fence, result);
    return result;
}

static VKAPI_ATTR VkResult VKAPI_CALL InterceptWaitForFences(VkDevice device, uint32_t fenceCount,
                                                             const VkFence* pFences, VkBool32 waitAll,
                                                             uint64_t timeout) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(device));
    layer_data->interceptor->PreWaitForFences(device, fenceCount, pFences, waitAll, timeout);

    PFN_vkWaitForFences pfn = layer_data->dispatch_table.WaitForFences;
    if (pfn != nullptr) {
        result = pfn(device, fenceCount, pFences, waitAll, timeout);
    }

    result = layer_data->interceptor->PostWaitForFences(device, fenceCount, pFences, waitAll, timeout, result);
    return result;
}

static VKAPI_ATTR VkResult VKAPI_CALL InterceptCreateSemaphore(VkDevice device,
                                                               const VkSemaphoreCreateInfo* pCreateInfo,
                                                               const VkAllocationCallbacks* pAllocator,
                                                               VkSemaphore* pSemaphore) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(device));
    layer_data->interceptor->PreCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);

    PFN_vkCreateSemaphore pfn = layer_data->dispatch_table.CreateSemaphore;
    if (pfn != nullptr) {
        result = pfn(device, pCreateInfo, pAllocator, pSemaphore);
    }

    result = layer_data->interceptor->PostCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore, result);
    return result;
}

static VKAPI_ATTR void VKAPI_CALL InterceptDestroySemaphore(VkDevice device, VkSemaphore semaphore,
                                                            const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetDeviceLayerData(DataKey(device));
    layer_data->interceptor->PreDestroySemaphore(device, semaphore, pAllocator);

    PFN_vkDestroySemaphore pfn = layer_data->dispatch_table.DestroySemaphore;
    if (pfn != nullptr) {
        pfn(device, semaphore, pAllocator);
    }

    layer_data->interceptor->PostDestroySemaphore(device, semaphore, pAllocator);
}

static VKAPI_ATTR VkResult VKAPI_CALL InterceptGetQueryPoolResults(VkDevice device, VkQueryPool queryPool,
                                                                   uint32_t firstQuery, uint32_t queryCount,
                                                                   size_t dataSize, void* pData, VkDeviceSize stride,
                                                                   VkQueryResultFlags flags) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(device));
    layer_data->interceptor->PreGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride,
                                                    flags);

    PFN_vkGetQueryPoolResults pfn = layer_data->dispatch_table.GetQueryPoolResults;
    if (pfn != nullptr) {
        result = pfn(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
    }

    result = layer_data->interceptor->PostGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize,
                                                              pData, stride, flags, result);
    return result;
}

static VKAPI_ATTR VkResult VKAPI_CALL InterceptCreateShaderModule(VkDevice device,
                                                                  const VkShaderModuleCreateInfo* pCreateInfo,
                                                                  const VkAllocationCallbacks* pAllocator,
                                                                  VkShaderModule* pShaderModule) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(device));
    PFN_vkCreateShaderModule pfn = layer_data->dispatch_table.CreateShaderModule;
    if (pfn != nullptr) {
        result = pfn(device, pCreateInfo, pAllocator, pShaderModule);
    }

    result = layer_data->interceptor->PostCreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule, result);
    return result;
}

static VKAPI_ATTR void VKAPI_CALL InterceptDestroyShaderModule(VkDevice device, VkShaderModule shaderModule,
                                                               const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetDeviceLayerData(DataKey(device));
    layer_data->interceptor->PreDestroyShaderModule(device, shaderModule, pAllocator);

    PFN_vkDestroyShaderModule pfn = layer_data->dispatch_table.DestroyShaderModule;
    if (pfn != nullptr) {
        pfn(device, shaderModule, pAllocator);
    }
}

static VKAPI_ATTR VkResult VKAPI_CALL InterceptCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache,
                                                                       uint32_t createInfoCount,
                                                                       const VkGraphicsPipelineCreateInfo* pCreateInfos,
                                                                       const VkAllocationCallbacks* pAllocator,
                                                                       VkPipeline* pPipelines) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(device));
    PFN_vkCreateGraphicsPipelines pfn = layer_data->dispatch_table.CreateGraphicsPipelines;
    if (pfn != nullptr) {
        result = pfn(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    }

    result = layer_data->interceptor->PostCreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos,
                                                                  pAllocator, pPipelines, result);
    return result;
}

static VKAPI_ATTR VkResult VKAPI_CALL InterceptCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache,
                                                                      uint32_t createInfoCount,
                                                                      const VkComputePipelineCreateInfo* pCreateInfos,
                                                                      const VkAllocationCallbacks* pAllocator,
                                                                      VkPipeline* pPipelines) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(device));
    PFN_vkCreateComputePipelines pfn = layer_data->dispatch_table.CreateComputePipelines;
    if (pfn != nullptr) {
        result = pfn(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    }

    result = layer_data->interceptor->PostCreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos,
                                                                 pAllocator, pPipelines, result);
    return result;
}

static VKAPI_ATTR void VKAPI_CALL InterceptDestroyPipeline(VkDevice device, VkPipeline pipeline,
                                                           const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetDeviceLayerData(DataKey(device));
    layer_data->interceptor->PreDestroyPipeline(device, pipeline, pAllocator);

    PFN_vkDestroyPipeline pfn = layer_data->dispatch_table.DestroyPipeline;
    if (pfn != nullptr) {
        pfn(device, pipeline, pAllocator);
    }

    layer_data->interceptor->PostDestroyPipeline(device, pipeline, pAllocator);
}

static VKAPI_ATTR VkResult VKAPI_CALL InterceptCreateCommandPool(VkDevice device,
                                                                 const VkCommandPoolCreateInfo* pCreateInfo,
                                                                 const VkAllocationCallbacks* pAllocator,
                                                                 VkCommandPool* pCommandPool) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(device));
    layer_data->interceptor->PreCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);

    PFN_vkCreateCommandPool pfn = layer_data->dispatch_table.CreateCommandPool;
    if (pfn != nullptr) {
        result = pfn(device, pCreateInfo, pAllocator, pCommandPool);
    }

    result = layer_data->interceptor->PostCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool, result);
    return result;
}

static VKAPI_ATTR void VKAPI_CALL InterceptDestroyCommandPool(VkDevice device, VkCommandPool commandPool,
                                                              const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetDeviceLayerData(DataKey(device));
    layer_data->interceptor->PreDestroyCommandPool(device, commandPool, pAllocator);

    PFN_vkDestroyCommandPool pfn = layer_data->dispatch_table.DestroyCommandPool;
    if (pfn != nullptr) {
        pfn(device, commandPool, pAllocator);
    }

    layer_data->interceptor->PostDestroyCommandPool(device, commandPool, pAllocator);
}

static VKAPI_ATTR VkResult VKAPI_CALL InterceptResetCommandPool(VkDevice device, VkCommandPool commandPool,
                                                                VkCommandPoolResetFlags flags) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(device));
    layer_data->interceptor->PreResetCommandPool(device, commandPool, flags);

    PFN_vkResetCommandPool pfn = layer_data->dispatch_table.ResetCommandPool;
    if (pfn != nullptr) {
        result = pfn(device, commandPool, flags);
    }

    result = layer_data->interceptor->PostResetCommandPool(device, commandPool, flags, result);
    return result;
}

static VKAPI_ATTR VkResult VKAPI_CALL InterceptAllocateCommandBuffers(VkDevice device,
                                                                      const VkCommandBufferAllocateInfo* pAllocateInfo,
                                                                      VkCommandBuffer* pCommandBuffers) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(device));
    layer_data->interceptor->PreAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);

    PFN_vkAllocateCommandBuffers pfn = layer_data->dispatch_table.AllocateCommandBuffers;
    if (pfn != nullptr) {
        result = pfn(device, pAllocateInfo, pCommandBuffers);
    }

    result = layer_data->interceptor->PostAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers, result);
    return result;
}

static VKAPI_ATTR void VKAPI_CALL InterceptFreeCommandBuffers(VkDevice device, VkCommandPool commandPool,
                                                              uint32_t commandBufferCount,
                                                              const VkCommandBuffer* pCommandBuffers) {
    auto layer_data = GetDeviceLayerData(DataKey(device));
    layer_data->interceptor->PreFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);

    PFN_vkFreeCommandBuffers pfn = layer_data->dispatch_table.FreeCommandBuffers;
    if (pfn != nullptr) {
        pfn(device, commandPool, commandBufferCount, pCommandBuffers);
    }

    layer_data->interceptor->PostFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
}

static VKAPI_ATTR VkResult VKAPI_CALL InterceptBeginCommandBuffer(VkCommandBuffer commandBuffer,
                                                                  const VkCommandBufferBeginInfo* pBeginInfo) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreBeginCommandBuffer(commandBuffer, pBeginInfo);

    PFN_vkBeginCommandBuffer pfn = layer_data->dispatch_table.BeginCommandBuffer;
    if (pfn != nullptr) {
        result = pfn(commandBuffer, pBeginInfo);
    }

    result = layer_data->interceptor->PostBeginCommandBuffer(commandBuffer, pBeginInfo, result);
    return result;
}

static VKAPI_ATTR VkResult VKAPI_CALL InterceptEndCommandBuffer(VkCommandBuffer commandBuffer) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreEndCommandBuffer(commandBuffer);

    PFN_vkEndCommandBuffer pfn = layer_data->dispatch_table.EndCommandBuffer;
    if (pfn != nullptr) {
        result = pfn(commandBuffer);
    }

    result = layer_data->interceptor->PostEndCommandBuffer(commandBuffer, result);
    return result;
}

static VKAPI_ATTR VkResult VKAPI_CALL InterceptResetCommandBuffer(VkCommandBuffer commandBuffer,
                                                                  VkCommandBufferResetFlags flags) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreResetCommandBuffer(commandBuffer, flags);

    PFN_vkResetCommandBuffer pfn = layer_data->dispatch_table.ResetCommandBuffer;
    if (pfn != nullptr) {
        result = pfn(commandBuffer, flags);
    }

    result = layer_data->interceptor->PostResetCommandBuffer(commandBuffer, flags, result);
    return result;
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBindPipeline(VkCommandBuffer commandBuffer,
                                                           VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);

    PFN_vkCmdBindPipeline pfn = layer_data->dispatch_table.CmdBindPipeline;
    if (pfn != nullptr) {
        pfn(commandBuffer, pipelineBindPoint, pipeline);
    }

    layer_data->interceptor->PostCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                                          uint32_t viewportCount, const VkViewport* pViewports) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);

    PFN_vkCmdSetViewport pfn = layer_data->dispatch_table.CmdSetViewport;
    if (pfn != nullptr) {
        pfn(commandBuffer, firstViewport, viewportCount, pViewports);
    }

    layer_data->interceptor->PostCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor,
                                                         uint32_t scissorCount, const VkRect2D* pScissors) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);

    PFN_vkCmdSetScissor pfn = layer_data->dispatch_table.CmdSetScissor;
    if (pfn != nullptr) {
        pfn(commandBuffer, firstScissor, scissorCount, pScissors);
    }

    layer_data->interceptor->PostCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetLineWidth(commandBuffer, lineWidth);

    PFN_vkCmdSetLineWidth pfn = layer_data->dispatch_table.CmdSetLineWidth;
    if (pfn != nullptr) {
        pfn(commandBuffer, lineWidth);
    }

    layer_data->interceptor->PostCmdSetLineWidth(commandBuffer, lineWidth);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor,
                                                           float depthBiasClamp, float depthBiasSlopeFactor) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp,
                                                depthBiasSlopeFactor);

    PFN_vkCmdSetDepthBias pfn = layer_data->dispatch_table.CmdSetDepthBias;
    if (pfn != nullptr) {
        pfn(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
    }

    layer_data->interceptor->PostCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp,
                                                 depthBiasSlopeFactor);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetBlendConstants(VkCommandBuffer commandBuffer,
                                                                const float blendConstants[4]) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetBlendConstants(commandBuffer, blendConstants);

    PFN_vkCmdSetBlendConstants pfn = layer_data->dispatch_table.CmdSetBlendConstants;
    if (pfn != nullptr) {
        pfn(commandBuffer, blendConstants);
    }

    layer_data->interceptor->PostCmdSetBlendConstants(commandBuffer, blendConstants);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds,
                                                             float maxDepthBounds) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);

    PFN_vkCmdSetDepthBounds pfn = layer_data->dispatch_table.CmdSetDepthBounds;
    if (pfn != nullptr) {
        pfn(commandBuffer, minDepthBounds, maxDepthBounds);
    }

    layer_data->interceptor->PostCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetStencilCompareMask(VkCommandBuffer commandBuffer,
                                                                    VkStencilFaceFlags faceMask, uint32_t compareMask) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);

    PFN_vkCmdSetStencilCompareMask pfn = layer_data->dispatch_table.CmdSetStencilCompareMask;
    if (pfn != nullptr) {
        pfn(commandBuffer, faceMask, compareMask);
    }

    layer_data->interceptor->PostCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetStencilWriteMask(VkCommandBuffer commandBuffer,
                                                                  VkStencilFaceFlags faceMask, uint32_t writeMask) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);

    PFN_vkCmdSetStencilWriteMask pfn = layer_data->dispatch_table.CmdSetStencilWriteMask;
    if (pfn != nullptr) {
        pfn(commandBuffer, faceMask, writeMask);
    }

    layer_data->interceptor->PostCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetStencilReference(VkCommandBuffer commandBuffer,
                                                                  VkStencilFaceFlags faceMask, uint32_t reference) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetStencilReference(commandBuffer, faceMask, reference);

    PFN_vkCmdSetStencilReference pfn = layer_data->dispatch_table.CmdSetStencilReference;
    if (pfn != nullptr) {
        pfn(commandBuffer, faceMask, reference);
    }

    layer_data->interceptor->PostCmdSetStencilReference(commandBuffer, faceMask, reference);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBindDescriptorSets(
    VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet,
    uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount,
    const uint32_t* pDynamicOffsets) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet,
                                                      descriptorSetCount, pDescriptorSets, dynamicOffsetCount,
                                                      pDynamicOffsets);

    PFN_vkCmdBindDescriptorSets pfn = layer_data->dispatch_table.CmdBindDescriptorSets;
    if (pfn != nullptr) {
        pfn(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount,
            pDynamicOffsets);
    }

    layer_data->interceptor->PostCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet,
                                                       descriptorSetCount, pDescriptorSets, dynamicOffsetCount,
                                                       pDynamicOffsets);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                              VkDeviceSize offset, VkIndexType indexType) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);

    PFN_vkCmdBindIndexBuffer pfn = layer_data->dispatch_table.CmdBindIndexBuffer;
    if (pfn != nullptr) {
        pfn(commandBuffer, buffer, offset, indexType);
    }

    layer_data->interceptor->PostCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                                uint32_t bindingCount, const VkBuffer* pBuffers,
                                                                const VkDeviceSize* pOffsets) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);

    PFN_vkCmdBindVertexBuffers pfn = layer_data->dispatch_table.CmdBindVertexBuffers;
    if (pfn != nullptr) {
        pfn(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
    }

    layer_data->interceptor->PostCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount,
                                                   uint32_t instanceCount, uint32_t firstVertex,
                                                   uint32_t firstInstance) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);

    PFN_vkCmdDraw pfn = layer_data->dispatch_table.CmdDraw;
    if (pfn != nullptr) {
        pfn(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    }

    layer_data->interceptor->PostCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount,
                                                          uint32_t instanceCount, uint32_t firstIndex,
                                                          int32_t vertexOffset, uint32_t firstInstance) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset,
                                               firstInstance);

    PFN_vkCmdDrawIndexed pfn = layer_data->dispatch_table.CmdDrawIndexed;
    if (pfn != nullptr) {
        pfn(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    }

    layer_data->interceptor->PostCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset,
                                                firstInstance);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                           VkDeviceSize offset, uint32_t drawCount, uint32_t stride) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);

    PFN_vkCmdDrawIndirect pfn = layer_data->dispatch_table.CmdDrawIndirect;
    if (pfn != nullptr) {
        pfn(commandBuffer, buffer, offset, drawCount, stride);
    }

    layer_data->interceptor->PostCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                                  VkDeviceSize offset, uint32_t drawCount,
                                                                  uint32_t stride) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);

    PFN_vkCmdDrawIndexedIndirect pfn = layer_data->dispatch_table.CmdDrawIndexedIndirect;
    if (pfn != nullptr) {
        pfn(commandBuffer, buffer, offset, drawCount, stride);
    }

    layer_data->interceptor->PostCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX,
                                                       uint32_t groupCountY, uint32_t groupCountZ) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);

    PFN_vkCmdDispatch pfn = layer_data->dispatch_table.CmdDispatch;
    if (pfn != nullptr) {
        pfn(commandBuffer, groupCountX, groupCountY, groupCountZ);
    }

    layer_data->interceptor->PostCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                               VkDeviceSize offset) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDispatchIndirect(commandBuffer, buffer, offset);

    PFN_vkCmdDispatchIndirect pfn = layer_data->dispatch_table.CmdDispatchIndirect;
    if (pfn != nullptr) {
        pfn(commandBuffer, buffer, offset);
    }

    layer_data->interceptor->PostCmdDispatchIndirect(commandBuffer, buffer, offset);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer,
                                                         VkBuffer dstBuffer, uint32_t regionCount,
                                                         const VkBufferCopy* pRegions) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);

    PFN_vkCmdCopyBuffer pfn = layer_data->dispatch_table.CmdCopyBuffer;
    if (pfn != nullptr) {
        pfn(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
    }

    layer_data->interceptor->PostCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage,
                                                        VkImageLayout srcImageLayout, VkImage dstImage,
                                                        VkImageLayout dstImageLayout, uint32_t regionCount,
                                                        const VkImageCopy* pRegions) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout,
                                             regionCount, pRegions);

    PFN_vkCmdCopyImage pfn = layer_data->dispatch_table.CmdCopyImage;
    if (pfn != nullptr) {
        pfn(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    }

    layer_data->interceptor->PostCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout,
                                              regionCount, pRegions);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage,
                                                        VkImageLayout srcImageLayout, VkImage dstImage,
                                                        VkImageLayout dstImageLayout, uint32_t regionCount,
                                                        const VkImageBlit* pRegions, VkFilter filter) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout,
                                             regionCount, pRegions, filter);

    PFN_vkCmdBlitImage pfn = layer_data->dispatch_table.CmdBlitImage;
    if (pfn != nullptr) {
        pfn(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
    }

    layer_data->interceptor->PostCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout,
                                              regionCount, pRegions, filter);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer,
                                                                VkImage dstImage, VkImageLayout dstImageLayout,
                                                                uint32_t regionCount,
                                                                const VkBufferImageCopy* pRegions) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount,
                                                     pRegions);

    PFN_vkCmdCopyBufferToImage pfn = layer_data->dispatch_table.CmdCopyBufferToImage;
    if (pfn != nullptr) {
        pfn(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
    }

    layer_data->interceptor->PostCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount,
                                                      pRegions);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage,
                                                                VkImageLayout srcImageLayout, VkBuffer dstBuffer,
                                                                uint32_t regionCount,
                                                                const VkBufferImageCopy* pRegions) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount,
                                                     pRegions);

    PFN_vkCmdCopyImageToBuffer pfn = layer_data->dispatch_table.CmdCopyImageToBuffer;
    if (pfn != nullptr) {
        pfn(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
    }

    layer_data->interceptor->PostCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount,
                                                      pRegions);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer,
                                                           VkDeviceSize dstOffset, VkDeviceSize dataSize,
                                                           const void* pData) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);

    PFN_vkCmdUpdateBuffer pfn = layer_data->dispatch_table.CmdUpdateBuffer;
    if (pfn != nullptr) {
        pfn(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
    }

    layer_data->interceptor->PostCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer,
                                                         VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);

    PFN_vkCmdFillBuffer pfn = layer_data->dispatch_table.CmdFillBuffer;
    if (pfn != nullptr) {
        pfn(commandBuffer, dstBuffer, dstOffset, size, data);
    }

    layer_data->interceptor->PostCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image,
                                                              VkImageLayout imageLayout,
                                                              const VkClearColorValue* pColor, uint32_t rangeCount,
                                                              const VkImageSubresourceRange* pRanges) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);

    PFN_vkCmdClearColorImage pfn = layer_data->dispatch_table.CmdClearColorImage;
    if (pfn != nullptr) {
        pfn(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
    }

    layer_data->interceptor->PostCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image,
                                                                     VkImageLayout imageLayout,
                                                                     const VkClearDepthStencilValue* pDepthStencil,
                                                                     uint32_t rangeCount,
                                                                     const VkImageSubresourceRange* pRanges) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount,
                                                          pRanges);

    PFN_vkCmdClearDepthStencilImage pfn = layer_data->dispatch_table.CmdClearDepthStencilImage;
    if (pfn != nullptr) {
        pfn(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
    }

    layer_data->interceptor->PostCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount,
                                                           pRanges);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                                               const VkClearAttachment* pAttachments,
                                                               uint32_t rectCount, const VkClearRect* pRects) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);

    PFN_vkCmdClearAttachments pfn = layer_data->dispatch_table.CmdClearAttachments;
    if (pfn != nullptr) {
        pfn(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
    }

    layer_data->interceptor->PostCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage,
                                                           VkImageLayout srcImageLayout, VkImage dstImage,
                                                           VkImageLayout dstImageLayout, uint32_t regionCount,
                                                           const VkImageResolve* pRegions) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout,
                                                regionCount, pRegions);

    PFN_vkCmdResolveImage pfn = layer_data->dispatch_table.CmdResolveImage;
    if (pfn != nullptr) {
        pfn(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    }

    layer_data->interceptor->PostCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout,
                                                 regionCount, pRegions);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event,
                                                       VkPipelineStageFlags stageMask) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetEvent(commandBuffer, event, stageMask);

    PFN_vkCmdSetEvent pfn = layer_data->dispatch_table.CmdSetEvent;
    if (pfn != nullptr) {
        pfn(commandBuffer, event, stageMask);
    }

    layer_data->interceptor->PostCmdSetEvent(commandBuffer, event, stageMask);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event,
                                                         VkPipelineStageFlags stageMask) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdResetEvent(commandBuffer, event, stageMask);

    PFN_vkCmdResetEvent pfn = layer_data->dispatch_table.CmdResetEvent;
    if (pfn != nullptr) {
        pfn(commandBuffer, event, stageMask);
    }

    layer_data->interceptor->PostCmdResetEvent(commandBuffer, event, stageMask);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdWaitEvents(
    VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask,
    VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
    uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers,
    uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask,
                                              memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount,
                                              pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

    PFN_vkCmdWaitEvents pfn = layer_data->dispatch_table.CmdWaitEvents;
    if (pfn != nullptr) {
        pfn(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers,
            bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    }

    layer_data->interceptor->PostCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask,
                                               memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount,
                                               pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdPipelineBarrier(
    VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask,
    VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
    uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers,
    uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdPipelineBarrier(
        commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers,
        bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

    PFN_vkCmdPipelineBarrier pfn = layer_data->dispatch_table.CmdPipelineBarrier;
    if (pfn != nullptr) {
        pfn(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers,
            bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    }

    layer_data->interceptor->PostCmdPipelineBarrier(
        commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers,
        bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool,
                                                         uint32_t query, VkQueryControlFlags flags) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBeginQuery(commandBuffer, queryPool, query, flags);

    PFN_vkCmdBeginQuery pfn = layer_data->dispatch_table.CmdBeginQuery;
    if (pfn != nullptr) {
        pfn(commandBuffer, queryPool, query, flags);
    }

    layer_data->interceptor->PostCmdBeginQuery(commandBuffer, queryPool, query, flags);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool,
                                                       uint32_t query) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdEndQuery(commandBuffer, queryPool, query);

    PFN_vkCmdEndQuery pfn = layer_data->dispatch_table.CmdEndQuery;
    if (pfn != nullptr) {
        pfn(commandBuffer, queryPool, query);
    }

    layer_data->interceptor->PostCmdEndQuery(commandBuffer, queryPool, query);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool,
                                                             uint32_t firstQuery, uint32_t queryCount) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);

    PFN_vkCmdResetQueryPool pfn = layer_data->dispatch_table.CmdResetQueryPool;
    if (pfn != nullptr) {
        pfn(commandBuffer, queryPool, firstQuery, queryCount);
    }

    layer_data->interceptor->PostCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdWriteTimestamp(VkCommandBuffer commandBuffer,
                                                             VkPipelineStageFlagBits pipelineStage,
                                                             VkQueryPool queryPool, uint32_t query) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);

    PFN_vkCmdWriteTimestamp pfn = layer_data->dispatch_table.CmdWriteTimestamp;
    if (pfn != nullptr) {
        pfn(commandBuffer, pipelineStage, queryPool, query);
    }

    layer_data->interceptor->PostCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool,
                                                                   uint32_t firstQuery, uint32_t queryCount,
                                                                   VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                                                   VkDeviceSize stride, VkQueryResultFlags flags) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer,
                                                        dstOffset, stride, flags);

    PFN_vkCmdCopyQueryPoolResults pfn = layer_data->dispatch_table.CmdCopyQueryPoolResults;
    if (pfn != nullptr) {
        pfn(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
    }

    layer_data->interceptor->PostCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer,
                                                         dstOffset, stride, flags);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout,
                                                            VkShaderStageFlags stageFlags, uint32_t offset,
                                                            uint32_t size, const void* pValues) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);

    PFN_vkCmdPushConstants pfn = layer_data->dispatch_table.CmdPushConstants;
    if (pfn != nullptr) {
        pfn(commandBuffer, layout, stageFlags, offset, size, pValues);
    }

    layer_data->interceptor->PostCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBeginRenderPass(VkCommandBuffer commandBuffer,
                                                              const VkRenderPassBeginInfo* pRenderPassBegin,
                                                              VkSubpassContents contents) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);

    PFN_vkCmdBeginRenderPass pfn = layer_data->dispatch_table.CmdBeginRenderPass;
    if (pfn != nullptr) {
        pfn(commandBuffer, pRenderPassBegin, contents);
    }

    layer_data->interceptor->PostCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdNextSubpass(commandBuffer, contents);

    PFN_vkCmdNextSubpass pfn = layer_data->dispatch_table.CmdNextSubpass;
    if (pfn != nullptr) {
        pfn(commandBuffer, contents);
    }

    layer_data->interceptor->PostCmdNextSubpass(commandBuffer, contents);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdEndRenderPass(VkCommandBuffer commandBuffer) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdEndRenderPass(commandBuffer);

    PFN_vkCmdEndRenderPass pfn = layer_data->dispatch_table.CmdEndRenderPass;
    if (pfn != nullptr) {
        pfn(commandBuffer);
    }

    layer_data->interceptor->PostCmdEndRenderPass(commandBuffer);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdExecuteCommands(VkCommandBuffer commandBuffer,
                                                              uint32_t commandBufferCount,
                                                              const VkCommandBuffer* pCommandBuffers) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);

    PFN_vkCmdExecuteCommands pfn = layer_data->dispatch_table.CmdExecuteCommands;
    if (pfn != nullptr) {
        pfn(commandBuffer, commandBufferCount, pCommandBuffers);
    }

    layer_data->interceptor->PostCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDeviceMask(commandBuffer, deviceMask);

    PFN_vkCmdSetDeviceMask pfn = layer_data->dispatch_table.CmdSetDeviceMask;
    if (pfn != nullptr) {
        pfn(commandBuffer, deviceMask);
    }

    layer_data->interceptor->PostCmdSetDeviceMask(commandBuffer, deviceMask);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX,
                                                           uint32_t baseGroupY, uint32_t baseGroupZ,
                                                           uint32_t groupCountX, uint32_t groupCountY,
                                                           uint32_t groupCountZ) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX,
                                                groupCountY, groupCountZ);

    PFN_vkCmdDispatchBase pfn = layer_data->dispatch_table.CmdDispatchBase;
    if (pfn != nullptr) {
        pfn(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    }

    layer_data->interceptor->PostCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX,
                                                 groupCountY, groupCountZ);
}

static VKAPI_ATTR void VKAPI_CALL InterceptGetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo,
                                                           VkQueue* pQueue) {
    auto layer_data = GetDeviceLayerData(DataKey(device));
    PFN_vkGetDeviceQueue2 pfn = layer_data->dispatch_table.GetDeviceQueue2;
    if (pfn != nullptr) {
        pfn(device, pQueueInfo, pQueue);
    }

    layer_data->interceptor->PostGetDeviceQueue2(device, pQueueInfo, pQueue);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                                VkDeviceSize offset, VkBuffer countBuffer,
                                                                VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                                uint32_t stride) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                                     maxDrawCount, stride);

    PFN_vkCmdDrawIndirectCount pfn = layer_data->dispatch_table.CmdDrawIndirectCount;
    if (pfn != nullptr) {
        pfn(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    layer_data->interceptor->PostCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                                      maxDrawCount, stride);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                                       VkDeviceSize offset, VkBuffer countBuffer,
                                                                       VkDeviceSize countBufferOffset,
                                                                       uint32_t maxDrawCount, uint32_t stride) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer,
                                                            countBufferOffset, maxDrawCount, stride);

    PFN_vkCmdDrawIndexedIndirectCount pfn = layer_data->dispatch_table.CmdDrawIndexedIndirectCount;
    if (pfn != nullptr) {
        pfn(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    layer_data->interceptor->PostCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer,
                                                             countBufferOffset, maxDrawCount, stride);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBeginRenderPass2(VkCommandBuffer commandBuffer,
                                                               const VkRenderPassBeginInfo* pRenderPassBegin,
                                                               const VkSubpassBeginInfo* pSubpassBeginInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);

    PFN_vkCmdBeginRenderPass2 pfn = layer_data->dispatch_table.CmdBeginRenderPass2;
    if (pfn != nullptr) {
        pfn(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    }

    layer_data->interceptor->PostCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdNextSubpass2(VkCommandBuffer commandBuffer,
                                                           const VkSubpassBeginInfo* pSubpassBeginInfo,
                                                           const VkSubpassEndInfo* pSubpassEndInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);

    PFN_vkCmdNextSubpass2 pfn = layer_data->dispatch_table.CmdNextSubpass2;
    if (pfn != nullptr) {
        pfn(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    }

    layer_data->interceptor->PostCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdEndRenderPass2(VkCommandBuffer commandBuffer,
                                                             const VkSubpassEndInfo* pSubpassEndInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdEndRenderPass2(commandBuffer, pSubpassEndInfo);

    PFN_vkCmdEndRenderPass2 pfn = layer_data->dispatch_table.CmdEndRenderPass2;
    if (pfn != nullptr) {
        pfn(commandBuffer, pSubpassEndInfo);
    }

    layer_data->interceptor->PostCmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
}

static VKAPI_ATTR VkResult VKAPI_CALL InterceptGetSemaphoreCounterValue(VkDevice device, VkSemaphore semaphore,
                                                                        uint64_t* pValue) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(device));
    layer_data->interceptor->PreGetSemaphoreCounterValue(device, semaphore, pValue);

    PFN_vkGetSemaphoreCounterValue pfn = layer_data->dispatch_table.GetSemaphoreCounterValue;
    if (pfn != nullptr) {
        result = pfn(device, semaphore, pValue);
    }

    result = layer_data->interceptor->PostGetSemaphoreCounterValue(device, semaphore, pValue, result);
    return result;
}

static VKAPI_ATTR VkResult VKAPI_CALL InterceptWaitSemaphores(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo,
                                                              uint64_t timeout) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(device));
    layer_data->interceptor->PreWaitSemaphores(device, pWaitInfo, timeout);

    PFN_vkWaitSemaphores pfn = layer_data->dispatch_table.WaitSemaphores;
    if (pfn != nullptr) {
        result = pfn(device, pWaitInfo, timeout);
    }

    result = layer_data->interceptor->PostWaitSemaphores(device, pWaitInfo, timeout, result);
    return result;
}

static VKAPI_ATTR VkResult VKAPI_CALL InterceptSignalSemaphore(VkDevice device,
                                                               const VkSemaphoreSignalInfo* pSignalInfo) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(device));
    layer_data->interceptor->PreSignalSemaphore(device, pSignalInfo);

    PFN_vkSignalSemaphore pfn = layer_data->dispatch_table.SignalSemaphore;
    if (pfn != nullptr) {
        result = pfn(device, pSignalInfo);
    }

    result = layer_data->interceptor->PostSignalSemaphore(device, pSignalInfo, result);
    return result;
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event,
                                                        const VkDependencyInfo* pDependencyInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetEvent2(commandBuffer, event, pDependencyInfo);

    PFN_vkCmdSetEvent2 pfn = layer_data->dispatch_table.CmdSetEvent2;
    if (pfn != nullptr) {
        pfn(commandBuffer, event, pDependencyInfo);
    }

    layer_data->interceptor->PostCmdSetEvent2(commandBuffer, event, pDependencyInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event,
                                                          VkPipelineStageFlags2 stageMask) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdResetEvent2(commandBuffer, event, stageMask);

    PFN_vkCmdResetEvent2 pfn = layer_data->dispatch_table.CmdResetEvent2;
    if (pfn != nullptr) {
        pfn(commandBuffer, event, stageMask);
    }

    layer_data->interceptor->PostCmdResetEvent2(commandBuffer, event, stageMask);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount,
                                                          const VkEvent* pEvents,
                                                          const VkDependencyInfo* pDependencyInfos) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);

    PFN_vkCmdWaitEvents2 pfn = layer_data->dispatch_table.CmdWaitEvents2;
    if (pfn != nullptr) {
        pfn(commandBuffer, eventCount, pEvents, pDependencyInfos);
    }

    layer_data->interceptor->PostCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdPipelineBarrier2(VkCommandBuffer commandBuffer,
                                                               const VkDependencyInfo* pDependencyInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdPipelineBarrier2(commandBuffer, pDependencyInfo);

    PFN_vkCmdPipelineBarrier2 pfn = layer_data->dispatch_table.CmdPipelineBarrier2;
    if (pfn != nullptr) {
        pfn(commandBuffer, pDependencyInfo);
    }

    layer_data->interceptor->PostCmdPipelineBarrier2(commandBuffer, pDependencyInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdWriteTimestamp2(VkCommandBuffer commandBuffer,
                                                              VkPipelineStageFlags2 stage, VkQueryPool queryPool,
                                                              uint32_t query) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdWriteTimestamp2(commandBuffer, stage, queryPool, query);

    PFN_vkCmdWriteTimestamp2 pfn = layer_data->dispatch_table.CmdWriteTimestamp2;
    if (pfn != nullptr) {
        pfn(commandBuffer, stage, queryPool, query);
    }

    layer_data->interceptor->PostCmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdCopyBuffer2(VkCommandBuffer commandBuffer,
                                                          const VkCopyBufferInfo2* pCopyBufferInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyBuffer2(commandBuffer, pCopyBufferInfo);

    PFN_vkCmdCopyBuffer2 pfn = layer_data->dispatch_table.CmdCopyBuffer2;
    if (pfn != nullptr) {
        pfn(commandBuffer, pCopyBufferInfo);
    }

    layer_data->interceptor->PostCmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdCopyImage2(VkCommandBuffer commandBuffer,
                                                         const VkCopyImageInfo2* pCopyImageInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyImage2(commandBuffer, pCopyImageInfo);

    PFN_vkCmdCopyImage2 pfn = layer_data->dispatch_table.CmdCopyImage2;
    if (pfn != nullptr) {
        pfn(commandBuffer, pCopyImageInfo);
    }

    layer_data->interceptor->PostCmdCopyImage2(commandBuffer, pCopyImageInfo);
}

static VKAPI_ATTR void VKAPI_CALL
InterceptCmdCopyBufferToImage2(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);

    PFN_vkCmdCopyBufferToImage2 pfn = layer_data->dispatch_table.CmdCopyBufferToImage2;
    if (pfn != nullptr) {
        pfn(commandBuffer, pCopyBufferToImageInfo);
    }

    layer_data->interceptor->PostCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
}

static VKAPI_ATTR void VKAPI_CALL
InterceptCmdCopyImageToBuffer2(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);

    PFN_vkCmdCopyImageToBuffer2 pfn = layer_data->dispatch_table.CmdCopyImageToBuffer2;
    if (pfn != nullptr) {
        pfn(commandBuffer, pCopyImageToBufferInfo);
    }

    layer_data->interceptor->PostCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBlitImage2(VkCommandBuffer commandBuffer,
                                                         const VkBlitImageInfo2* pBlitImageInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBlitImage2(commandBuffer, pBlitImageInfo);

    PFN_vkCmdBlitImage2 pfn = layer_data->dispatch_table.CmdBlitImage2;
    if (pfn != nullptr) {
        pfn(commandBuffer, pBlitImageInfo);
    }

    layer_data->interceptor->PostCmdBlitImage2(commandBuffer, pBlitImageInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdResolveImage2(VkCommandBuffer commandBuffer,
                                                            const VkResolveImageInfo2* pResolveImageInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdResolveImage2(commandBuffer, pResolveImageInfo);

    PFN_vkCmdResolveImage2 pfn = layer_data->dispatch_table.CmdResolveImage2;
    if (pfn != nullptr) {
        pfn(commandBuffer, pResolveImageInfo);
    }

    layer_data->interceptor->PostCmdResolveImage2(commandBuffer, pResolveImageInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBeginRendering(VkCommandBuffer commandBuffer,
                                                             const VkRenderingInfo* pRenderingInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBeginRendering(commandBuffer, pRenderingInfo);

    PFN_vkCmdBeginRendering pfn = layer_data->dispatch_table.CmdBeginRendering;
    if (pfn != nullptr) {
        pfn(commandBuffer, pRenderingInfo);
    }

    layer_data->interceptor->PostCmdBeginRendering(commandBuffer, pRenderingInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdEndRendering(VkCommandBuffer commandBuffer) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdEndRendering(commandBuffer);

    PFN_vkCmdEndRendering pfn = layer_data->dispatch_table.CmdEndRendering;
    if (pfn != nullptr) {
        pfn(commandBuffer);
    }

    layer_data->interceptor->PostCmdEndRendering(commandBuffer);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetCullMode(commandBuffer, cullMode);

    PFN_vkCmdSetCullMode pfn = layer_data->dispatch_table.CmdSetCullMode;
    if (pfn != nullptr) {
        pfn(commandBuffer, cullMode);
    }

    layer_data->interceptor->PostCmdSetCullMode(commandBuffer, cullMode);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetFrontFace(commandBuffer, frontFace);

    PFN_vkCmdSetFrontFace pfn = layer_data->dispatch_table.CmdSetFrontFace;
    if (pfn != nullptr) {
        pfn(commandBuffer, frontFace);
    }

    layer_data->interceptor->PostCmdSetFrontFace(commandBuffer, frontFace);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetPrimitiveTopology(VkCommandBuffer commandBuffer,
                                                                   VkPrimitiveTopology primitiveTopology) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetPrimitiveTopology(commandBuffer, primitiveTopology);

    PFN_vkCmdSetPrimitiveTopology pfn = layer_data->dispatch_table.CmdSetPrimitiveTopology;
    if (pfn != nullptr) {
        pfn(commandBuffer, primitiveTopology);
    }

    layer_data->interceptor->PostCmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetViewportWithCount(VkCommandBuffer commandBuffer,
                                                                   uint32_t viewportCount,
                                                                   const VkViewport* pViewports) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);

    PFN_vkCmdSetViewportWithCount pfn = layer_data->dispatch_table.CmdSetViewportWithCount;
    if (pfn != nullptr) {
        pfn(commandBuffer, viewportCount, pViewports);
    }

    layer_data->interceptor->PostCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                                                  const VkRect2D* pScissors) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);

    PFN_vkCmdSetScissorWithCount pfn = layer_data->dispatch_table.CmdSetScissorWithCount;
    if (pfn != nullptr) {
        pfn(commandBuffer, scissorCount, pScissors);
    }

    layer_data->interceptor->PostCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                                 uint32_t bindingCount, const VkBuffer* pBuffers,
                                                                 const VkDeviceSize* pOffsets,
                                                                 const VkDeviceSize* pSizes,
                                                                 const VkDeviceSize* pStrides) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets,
                                                      pSizes, pStrides);

    PFN_vkCmdBindVertexBuffers2 pfn = layer_data->dispatch_table.CmdBindVertexBuffers2;
    if (pfn != nullptr) {
        pfn(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
    }

    layer_data->interceptor->PostCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets,
                                                       pSizes, pStrides);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetDepthTestEnable(VkCommandBuffer commandBuffer,
                                                                 VkBool32 depthTestEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthTestEnable(commandBuffer, depthTestEnable);

    PFN_vkCmdSetDepthTestEnable pfn = layer_data->dispatch_table.CmdSetDepthTestEnable;
    if (pfn != nullptr) {
        pfn(commandBuffer, depthTestEnable);
    }

    layer_data->interceptor->PostCmdSetDepthTestEnable(commandBuffer, depthTestEnable);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetDepthWriteEnable(VkCommandBuffer commandBuffer,
                                                                  VkBool32 depthWriteEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);

    PFN_vkCmdSetDepthWriteEnable pfn = layer_data->dispatch_table.CmdSetDepthWriteEnable;
    if (pfn != nullptr) {
        pfn(commandBuffer, depthWriteEnable);
    }

    layer_data->interceptor->PostCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetDepthCompareOp(VkCommandBuffer commandBuffer,
                                                                VkCompareOp depthCompareOp) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthCompareOp(commandBuffer, depthCompareOp);

    PFN_vkCmdSetDepthCompareOp pfn = layer_data->dispatch_table.CmdSetDepthCompareOp;
    if (pfn != nullptr) {
        pfn(commandBuffer, depthCompareOp);
    }

    layer_data->interceptor->PostCmdSetDepthCompareOp(commandBuffer, depthCompareOp);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer,
                                                                       VkBool32 depthBoundsTestEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);

    PFN_vkCmdSetDepthBoundsTestEnable pfn = layer_data->dispatch_table.CmdSetDepthBoundsTestEnable;
    if (pfn != nullptr) {
        pfn(commandBuffer, depthBoundsTestEnable);
    }

    layer_data->interceptor->PostCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetStencilTestEnable(VkCommandBuffer commandBuffer,
                                                                   VkBool32 stencilTestEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetStencilTestEnable(commandBuffer, stencilTestEnable);

    PFN_vkCmdSetStencilTestEnable pfn = layer_data->dispatch_table.CmdSetStencilTestEnable;
    if (pfn != nullptr) {
        pfn(commandBuffer, stencilTestEnable);
    }

    layer_data->interceptor->PostCmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                                           VkStencilOp failOp, VkStencilOp passOp,
                                                           VkStencilOp depthFailOp, VkCompareOp compareOp) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);

    PFN_vkCmdSetStencilOp pfn = layer_data->dispatch_table.CmdSetStencilOp;
    if (pfn != nullptr) {
        pfn(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    }

    layer_data->interceptor->PostCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer,
                                                                         VkBool32 rasterizerDiscardEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);

    PFN_vkCmdSetRasterizerDiscardEnable pfn = layer_data->dispatch_table.CmdSetRasterizerDiscardEnable;
    if (pfn != nullptr) {
        pfn(commandBuffer, rasterizerDiscardEnable);
    }

    layer_data->interceptor->PostCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetDepthBiasEnable(VkCommandBuffer commandBuffer,
                                                                 VkBool32 depthBiasEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);

    PFN_vkCmdSetDepthBiasEnable pfn = layer_data->dispatch_table.CmdSetDepthBiasEnable;
    if (pfn != nullptr) {
        pfn(commandBuffer, depthBiasEnable);
    }

    layer_data->interceptor->PostCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer,
                                                                        VkBool32 primitiveRestartEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);

    PFN_vkCmdSetPrimitiveRestartEnable pfn = layer_data->dispatch_table.CmdSetPrimitiveRestartEnable;
    if (pfn != nullptr) {
        pfn(commandBuffer, primitiveRestartEnable);
    }

    layer_data->interceptor->PostCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
}

static VKAPI_ATTR VkResult VKAPI_CALL InterceptAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain,
                                                                   uint64_t timeout, VkSemaphore semaphore,
                                                                   VkFence fence, uint32_t* pImageIndex) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(device));
    layer_data->interceptor->PreAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);

    PFN_vkAcquireNextImageKHR pfn = layer_data->dispatch_table.AcquireNextImageKHR;
    if (pfn != nullptr) {
        result = pfn(device, swapchain, timeout, semaphore, fence, pImageIndex);
    }

    result = layer_data->interceptor->PostAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex,
                                                              result);
    return result;
}

static VKAPI_ATTR VkResult VKAPI_CALL InterceptQueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(queue));
    layer_data->interceptor->PreQueuePresentKHR(queue, pPresentInfo);

    PFN_vkQueuePresentKHR pfn = layer_data->dispatch_table.QueuePresentKHR;
    if (pfn != nullptr) {
        result = pfn(queue, pPresentInfo);
    }

    result = layer_data->interceptor->PostQueuePresentKHR(queue, pPresentInfo, result);
    return result;
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer,
                                                                  const VkVideoBeginCodingInfoKHR* pBeginInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);

    PFN_vkCmdBeginVideoCodingKHR pfn = layer_data->dispatch_table.CmdBeginVideoCodingKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pBeginInfo);
    }

    layer_data->interceptor->PostCmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdEndVideoCodingKHR(VkCommandBuffer commandBuffer,
                                                                const VkVideoEndCodingInfoKHR* pEndCodingInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);

    PFN_vkCmdEndVideoCodingKHR pfn = layer_data->dispatch_table.CmdEndVideoCodingKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pEndCodingInfo);
    }

    layer_data->interceptor->PostCmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdControlVideoCodingKHR(
    VkCommandBuffer commandBuffer, const VkVideoCodingControlInfoKHR* pCodingControlInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);

    PFN_vkCmdControlVideoCodingKHR pfn = layer_data->dispatch_table.CmdControlVideoCodingKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pCodingControlInfo);
    }

    layer_data->interceptor->PostCmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDecodeVideoKHR(VkCommandBuffer commandBuffer,
                                                             const VkVideoDecodeInfoKHR* pDecodeInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDecodeVideoKHR(commandBuffer, pDecodeInfo);

    PFN_vkCmdDecodeVideoKHR pfn = layer_data->dispatch_table.CmdDecodeVideoKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pDecodeInfo);
    }

    layer_data->interceptor->PostCmdDecodeVideoKHR(commandBuffer, pDecodeInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBeginRenderingKHR(VkCommandBuffer commandBuffer,
                                                                const VkRenderingInfo* pRenderingInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBeginRenderingKHR(commandBuffer, pRenderingInfo);

    PFN_vkCmdBeginRenderingKHR pfn = layer_data->dispatch_table.CmdBeginRenderingKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pRenderingInfo);
    }

    layer_data->interceptor->PostCmdBeginRenderingKHR(commandBuffer, pRenderingInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdEndRenderingKHR(VkCommandBuffer commandBuffer) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdEndRenderingKHR(commandBuffer);

    PFN_vkCmdEndRenderingKHR pfn = layer_data->dispatch_table.CmdEndRenderingKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer);
    }

    layer_data->interceptor->PostCmdEndRenderingKHR(commandBuffer);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDeviceMaskKHR(commandBuffer, deviceMask);

    PFN_vkCmdSetDeviceMaskKHR pfn = layer_data->dispatch_table.CmdSetDeviceMaskKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, deviceMask);
    }

    layer_data->interceptor->PostCmdSetDeviceMaskKHR(commandBuffer, deviceMask);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX,
                                                              uint32_t baseGroupY, uint32_t baseGroupZ,
                                                              uint32_t groupCountX, uint32_t groupCountY,
                                                              uint32_t groupCountZ) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX,
                                                   groupCountY, groupCountZ);

    PFN_vkCmdDispatchBaseKHR pfn = layer_data->dispatch_table.CmdDispatchBaseKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    }

    layer_data->interceptor->PostCmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX,
                                                    groupCountY, groupCountZ);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer,
                                                                   VkPipelineBindPoint pipelineBindPoint,
                                                                   VkPipelineLayout layout, uint32_t set,
                                                                   uint32_t descriptorWriteCount,
                                                                   const VkWriteDescriptorSet* pDescriptorWrites) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set,
                                                        descriptorWriteCount, pDescriptorWrites);

    PFN_vkCmdPushDescriptorSetKHR pfn = layer_data->dispatch_table.CmdPushDescriptorSetKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
    }

    layer_data->interceptor->PostCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set,
                                                         descriptorWriteCount, pDescriptorWrites);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdPushDescriptorSetWithTemplateKHR(
    VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout,
    uint32_t set, const void* pData) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout,
                                                                    set, pData);

    PFN_vkCmdPushDescriptorSetWithTemplateKHR pfn = layer_data->dispatch_table.CmdPushDescriptorSetWithTemplateKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
    }

    layer_data->interceptor->PostCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout,
                                                                     set, pData);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer,
                                                                  const VkRenderPassBeginInfo* pRenderPassBegin,
                                                                  const VkSubpassBeginInfo* pSubpassBeginInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);

    PFN_vkCmdBeginRenderPass2KHR pfn = layer_data->dispatch_table.CmdBeginRenderPass2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    }

    layer_data->interceptor->PostCmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdNextSubpass2KHR(VkCommandBuffer commandBuffer,
                                                              const VkSubpassBeginInfo* pSubpassBeginInfo,
                                                              const VkSubpassEndInfo* pSubpassEndInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);

    PFN_vkCmdNextSubpass2KHR pfn = layer_data->dispatch_table.CmdNextSubpass2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    }

    layer_data->interceptor->PostCmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdEndRenderPass2KHR(VkCommandBuffer commandBuffer,
                                                                const VkSubpassEndInfo* pSubpassEndInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);

    PFN_vkCmdEndRenderPass2KHR pfn = layer_data->dispatch_table.CmdEndRenderPass2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pSubpassEndInfo);
    }

    layer_data->interceptor->PostCmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                                   VkDeviceSize offset, VkBuffer countBuffer,
                                                                   VkDeviceSize countBufferOffset,
                                                                   uint32_t maxDrawCount, uint32_t stride) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                                        maxDrawCount, stride);

    PFN_vkCmdDrawIndirectCountKHR pfn = layer_data->dispatch_table.CmdDrawIndirectCountKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    layer_data->interceptor->PostCmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                                         maxDrawCount, stride);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer,
                                                                          VkBuffer buffer, VkDeviceSize offset,
                                                                          VkBuffer countBuffer,
                                                                          VkDeviceSize countBufferOffset,
                                                                          uint32_t maxDrawCount, uint32_t stride) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer,
                                                               countBufferOffset, maxDrawCount, stride);

    PFN_vkCmdDrawIndexedIndirectCountKHR pfn = layer_data->dispatch_table.CmdDrawIndexedIndirectCountKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    layer_data->interceptor->PostCmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer,
                                                                countBufferOffset, maxDrawCount, stride);
}

static VKAPI_ATTR VkResult VKAPI_CALL InterceptGetSemaphoreCounterValueKHR(VkDevice device, VkSemaphore semaphore,
                                                                           uint64_t* pValue) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(device));
    layer_data->interceptor->PreGetSemaphoreCounterValueKHR(device, semaphore, pValue);

    PFN_vkGetSemaphoreCounterValueKHR pfn = layer_data->dispatch_table.GetSemaphoreCounterValueKHR;
    if (pfn != nullptr) {
        result = pfn(device, semaphore, pValue);
    }

    result = layer_data->interceptor->PostGetSemaphoreCounterValueKHR(device, semaphore, pValue, result);
    return result;
}

static VKAPI_ATTR VkResult VKAPI_CALL InterceptWaitSemaphoresKHR(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo,
                                                                 uint64_t timeout) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(device));
    layer_data->interceptor->PreWaitSemaphoresKHR(device, pWaitInfo, timeout);

    PFN_vkWaitSemaphoresKHR pfn = layer_data->dispatch_table.WaitSemaphoresKHR;
    if (pfn != nullptr) {
        result = pfn(device, pWaitInfo, timeout);
    }

    result = layer_data->interceptor->PostWaitSemaphoresKHR(device, pWaitInfo, timeout, result);
    return result;
}

static VKAPI_ATTR VkResult VKAPI_CALL InterceptSignalSemaphoreKHR(VkDevice device,
                                                                  const VkSemaphoreSignalInfo* pSignalInfo) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(device));
    layer_data->interceptor->PreSignalSemaphoreKHR(device, pSignalInfo);

    PFN_vkSignalSemaphoreKHR pfn = layer_data->dispatch_table.SignalSemaphoreKHR;
    if (pfn != nullptr) {
        result = pfn(device, pSignalInfo);
    }

    result = layer_data->interceptor->PostSignalSemaphoreKHR(device, pSignalInfo, result);
    return result;
}

static VKAPI_ATTR void VKAPI_CALL
InterceptCmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize,
                                      const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);

    PFN_vkCmdSetFragmentShadingRateKHR pfn = layer_data->dispatch_table.CmdSetFragmentShadingRateKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pFragmentSize, combinerOps);
    }

    layer_data->interceptor->PostCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetRenderingAttachmentLocationsKHR(
    VkCommandBuffer commandBuffer, const VkRenderingAttachmentLocationInfoKHR* pLocationInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetRenderingAttachmentLocationsKHR(commandBuffer, pLocationInfo);

    PFN_vkCmdSetRenderingAttachmentLocationsKHR pfn = layer_data->dispatch_table.CmdSetRenderingAttachmentLocationsKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pLocationInfo);
    }

    layer_data->interceptor->PostCmdSetRenderingAttachmentLocationsKHR(commandBuffer, pLocationInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetRenderingInputAttachmentIndicesKHR(
    VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfoKHR* pInputAttachmentIndexInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetRenderingInputAttachmentIndicesKHR(commandBuffer, pInputAttachmentIndexInfo);

    PFN_vkCmdSetRenderingInputAttachmentIndicesKHR pfn =
        layer_data->dispatch_table.CmdSetRenderingInputAttachmentIndicesKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pInputAttachmentIndexInfo);
    }

    layer_data->interceptor->PostCmdSetRenderingInputAttachmentIndicesKHR(commandBuffer, pInputAttachmentIndexInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdEncodeVideoKHR(VkCommandBuffer commandBuffer,
                                                             const VkVideoEncodeInfoKHR* pEncodeInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdEncodeVideoKHR(commandBuffer, pEncodeInfo);

    PFN_vkCmdEncodeVideoKHR pfn = layer_data->dispatch_table.CmdEncodeVideoKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pEncodeInfo);
    }

    layer_data->interceptor->PostCmdEncodeVideoKHR(commandBuffer, pEncodeInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event,
                                                           const VkDependencyInfo* pDependencyInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetEvent2KHR(commandBuffer, event, pDependencyInfo);

    PFN_vkCmdSetEvent2KHR pfn = layer_data->dispatch_table.CmdSetEvent2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, event, pDependencyInfo);
    }

    layer_data->interceptor->PostCmdSetEvent2KHR(commandBuffer, event, pDependencyInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event,
                                                             VkPipelineStageFlags2 stageMask) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdResetEvent2KHR(commandBuffer, event, stageMask);

    PFN_vkCmdResetEvent2KHR pfn = layer_data->dispatch_table.CmdResetEvent2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, event, stageMask);
    }

    layer_data->interceptor->PostCmdResetEvent2KHR(commandBuffer, event, stageMask);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount,
                                                             const VkEvent* pEvents,
                                                             const VkDependencyInfo* pDependencyInfos) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos);

    PFN_vkCmdWaitEvents2KHR pfn = layer_data->dispatch_table.CmdWaitEvents2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, eventCount, pEvents, pDependencyInfos);
    }

    layer_data->interceptor->PostCmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer,
                                                                  const VkDependencyInfo* pDependencyInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo);

    PFN_vkCmdPipelineBarrier2KHR pfn = layer_data->dispatch_table.CmdPipelineBarrier2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pDependencyInfo);
    }

    layer_data->interceptor->PostCmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer,
                                                                 VkPipelineStageFlags2 stage, VkQueryPool queryPool,
                                                                 uint32_t query) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query);

    PFN_vkCmdWriteTimestamp2KHR pfn = layer_data->dispatch_table.CmdWriteTimestamp2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, stage, queryPool, query);
    }

    layer_data->interceptor->PostCmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer,
                                                                    VkPipelineStageFlags2 stage, VkBuffer dstBuffer,
                                                                    VkDeviceSize dstOffset, uint32_t marker) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);

    PFN_vkCmdWriteBufferMarker2AMD pfn = layer_data->dispatch_table.CmdWriteBufferMarker2AMD;
    if (pfn != nullptr) {
        pfn(commandBuffer, stage, dstBuffer, dstOffset, marker);
    }

    layer_data->interceptor->PostCmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer,
                                                             const VkCopyBufferInfo2* pCopyBufferInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);

    PFN_vkCmdCopyBuffer2KHR pfn = layer_data->dispatch_table.CmdCopyBuffer2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pCopyBufferInfo);
    }

    layer_data->interceptor->PostCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdCopyImage2KHR(VkCommandBuffer commandBuffer,
                                                            const VkCopyImageInfo2* pCopyImageInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyImage2KHR(commandBuffer, pCopyImageInfo);

    PFN_vkCmdCopyImage2KHR pfn = layer_data->dispatch_table.CmdCopyImage2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pCopyImageInfo);
    }

    layer_data->interceptor->PostCmdCopyImage2KHR(commandBuffer, pCopyImageInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdCopyBufferToImage2KHR(
    VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);

    PFN_vkCmdCopyBufferToImage2KHR pfn = layer_data->dispatch_table.CmdCopyBufferToImage2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pCopyBufferToImageInfo);
    }

    layer_data->interceptor->PostCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdCopyImageToBuffer2KHR(
    VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);

    PFN_vkCmdCopyImageToBuffer2KHR pfn = layer_data->dispatch_table.CmdCopyImageToBuffer2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pCopyImageToBufferInfo);
    }

    layer_data->interceptor->PostCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBlitImage2KHR(VkCommandBuffer commandBuffer,
                                                            const VkBlitImageInfo2* pBlitImageInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBlitImage2KHR(commandBuffer, pBlitImageInfo);

    PFN_vkCmdBlitImage2KHR pfn = layer_data->dispatch_table.CmdBlitImage2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pBlitImageInfo);
    }

    layer_data->interceptor->PostCmdBlitImage2KHR(commandBuffer, pBlitImageInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdResolveImage2KHR(VkCommandBuffer commandBuffer,
                                                               const VkResolveImageInfo2* pResolveImageInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdResolveImage2KHR(commandBuffer, pResolveImageInfo);

    PFN_vkCmdResolveImage2KHR pfn = layer_data->dispatch_table.CmdResolveImage2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pResolveImageInfo);
    }

    layer_data->interceptor->PostCmdResolveImage2KHR(commandBuffer, pResolveImageInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer,
                                                                    VkDeviceAddress indirectDeviceAddress) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdTraceRaysIndirect2KHR(commandBuffer, indirectDeviceAddress);

    PFN_vkCmdTraceRaysIndirect2KHR pfn = layer_data->dispatch_table.CmdTraceRaysIndirect2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, indirectDeviceAddress);
    }

    layer_data->interceptor->PostCmdTraceRaysIndirect2KHR(commandBuffer, indirectDeviceAddress);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                                  VkDeviceSize offset, VkDeviceSize size,
                                                                  VkIndexType indexType) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBindIndexBuffer2KHR(commandBuffer, buffer, offset, size, indexType);

    PFN_vkCmdBindIndexBuffer2KHR pfn = layer_data->dispatch_table.CmdBindIndexBuffer2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, buffer, offset, size, indexType);
    }

    layer_data->interceptor->PostCmdBindIndexBuffer2KHR(commandBuffer, buffer, offset, size, indexType);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetLineStippleKHR(VkCommandBuffer commandBuffer,
                                                                uint32_t lineStippleFactor,
                                                                uint16_t lineStipplePattern) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetLineStippleKHR(commandBuffer, lineStippleFactor, lineStipplePattern);

    PFN_vkCmdSetLineStippleKHR pfn = layer_data->dispatch_table.CmdSetLineStippleKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, lineStippleFactor, lineStipplePattern);
    }

    layer_data->interceptor->PostCmdSetLineStippleKHR(commandBuffer, lineStippleFactor, lineStipplePattern);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBindDescriptorSets2KHR(
    VkCommandBuffer commandBuffer, const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBindDescriptorSets2KHR(commandBuffer, pBindDescriptorSetsInfo);

    PFN_vkCmdBindDescriptorSets2KHR pfn = layer_data->dispatch_table.CmdBindDescriptorSets2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pBindDescriptorSetsInfo);
    }

    layer_data->interceptor->PostCmdBindDescriptorSets2KHR(commandBuffer, pBindDescriptorSetsInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdPushConstants2KHR(VkCommandBuffer commandBuffer,
                                                                const VkPushConstantsInfoKHR* pPushConstantsInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdPushConstants2KHR(commandBuffer, pPushConstantsInfo);

    PFN_vkCmdPushConstants2KHR pfn = layer_data->dispatch_table.CmdPushConstants2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pPushConstantsInfo);
    }

    layer_data->interceptor->PostCmdPushConstants2KHR(commandBuffer, pPushConstantsInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdPushDescriptorSet2KHR(
    VkCommandBuffer commandBuffer, const VkPushDescriptorSetInfoKHR* pPushDescriptorSetInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdPushDescriptorSet2KHR(commandBuffer, pPushDescriptorSetInfo);

    PFN_vkCmdPushDescriptorSet2KHR pfn = layer_data->dispatch_table.CmdPushDescriptorSet2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pPushDescriptorSetInfo);
    }

    layer_data->interceptor->PostCmdPushDescriptorSet2KHR(commandBuffer, pPushDescriptorSetInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdPushDescriptorSetWithTemplate2KHR(
    VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdPushDescriptorSetWithTemplate2KHR(commandBuffer, pPushDescriptorSetWithTemplateInfo);

    PFN_vkCmdPushDescriptorSetWithTemplate2KHR pfn = layer_data->dispatch_table.CmdPushDescriptorSetWithTemplate2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pPushDescriptorSetWithTemplateInfo);
    }

    layer_data->interceptor->PostCmdPushDescriptorSetWithTemplate2KHR(commandBuffer,
                                                                      pPushDescriptorSetWithTemplateInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetDescriptorBufferOffsets2EXT(
    VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDescriptorBufferOffsets2EXT(commandBuffer, pSetDescriptorBufferOffsetsInfo);

    PFN_vkCmdSetDescriptorBufferOffsets2EXT pfn = layer_data->dispatch_table.CmdSetDescriptorBufferOffsets2EXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, pSetDescriptorBufferOffsetsInfo);
    }

    layer_data->interceptor->PostCmdSetDescriptorBufferOffsets2EXT(commandBuffer, pSetDescriptorBufferOffsetsInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    VkCommandBuffer commandBuffer,
    const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBindDescriptorBufferEmbeddedSamplers2EXT(commandBuffer,
                                                                            pBindDescriptorBufferEmbeddedSamplersInfo);

    PFN_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT pfn =
        layer_data->dispatch_table.CmdBindDescriptorBufferEmbeddedSamplers2EXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, pBindDescriptorBufferEmbeddedSamplersInfo);
    }

    layer_data->interceptor->PostCmdBindDescriptorBufferEmbeddedSamplers2EXT(commandBuffer,
                                                                             pBindDescriptorBufferEmbeddedSamplersInfo);
}

static VKAPI_ATTR VkResult VKAPI_CALL
InterceptCreateDebugReportCallbackEXT(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo,
                                      const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetInstanceLayerData(DataKey(instance));
    layer_data->interceptor->PreCreateDebugReportCallbackEXT(instance, pCreateInfo, pAllocator, pCallback);

    PFN_vkCreateDebugReportCallbackEXT pfn = layer_data->dispatch_table.CreateDebugReportCallbackEXT;
    if (pfn != nullptr) {
        result = pfn(instance, pCreateInfo, pAllocator, pCallback);
    }

    result =
        layer_data->interceptor->PostCreateDebugReportCallbackEXT(instance, pCreateInfo, pAllocator, pCallback, result);
    return result;
}

static VKAPI_ATTR void VKAPI_CALL InterceptDestroyDebugReportCallbackEXT(VkInstance instance,
                                                                         VkDebugReportCallbackEXT callback,
                                                                         const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetInstanceLayerData(DataKey(instance));
    layer_data->interceptor->PreDestroyDebugReportCallbackEXT(instance, callback, pAllocator);

    PFN_vkDestroyDebugReportCallbackEXT pfn = layer_data->dispatch_table.DestroyDebugReportCallbackEXT;
    if (pfn != nullptr) {
        pfn(instance, callback, pAllocator);
    }

    layer_data->interceptor->PostDestroyDebugReportCallbackEXT(instance, callback, pAllocator);
}

static VKAPI_ATTR VkResult VKAPI_CALL
InterceptDebugMarkerSetObjectNameEXT(VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(device));
    layer_data->interceptor->PreDebugMarkerSetObjectNameEXT(device, pNameInfo);

    PFN_vkDebugMarkerSetObjectNameEXT pfn = layer_data->dispatch_table.DebugMarkerSetObjectNameEXT;
    if (pfn != nullptr) {
        result = pfn(device, pNameInfo);
    }

    result = layer_data->interceptor->PostDebugMarkerSetObjectNameEXT(device, pNameInfo, result);
    return result;
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer,
                                                                  const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);

    PFN_vkCmdDebugMarkerBeginEXT pfn = layer_data->dispatch_table.CmdDebugMarkerBeginEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, pMarkerInfo);
    }

    layer_data->interceptor->PostCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDebugMarkerEndEXT(commandBuffer);

    PFN_vkCmdDebugMarkerEndEXT pfn = layer_data->dispatch_table.CmdDebugMarkerEndEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer);
    }

    layer_data->interceptor->PostCmdDebugMarkerEndEXT(commandBuffer);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer,
                                                                   const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);

    PFN_vkCmdDebugMarkerInsertEXT pfn = layer_data->dispatch_table.CmdDebugMarkerInsertEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, pMarkerInfo);
    }

    layer_data->interceptor->PostCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBindTransformFeedbackBuffersEXT(
    VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers,
    const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers,
                                                                   pOffsets, pSizes);

    PFN_vkCmdBindTransformFeedbackBuffersEXT pfn = layer_data->dispatch_table.CmdBindTransformFeedbackBuffersEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
    }

    layer_data->interceptor->PostCmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers,
                                                                    pOffsets, pSizes);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer,
                                                                        uint32_t firstCounterBuffer,
                                                                        uint32_t counterBufferCount,
                                                                        const VkBuffer* pCounterBuffers,
                                                                        const VkDeviceSize* pCounterBufferOffsets) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount,
                                                             pCounterBuffers, pCounterBufferOffsets);

    PFN_vkCmdBeginTransformFeedbackEXT pfn = layer_data->dispatch_table.CmdBeginTransformFeedbackEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
    }

    layer_data->interceptor->PostCmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount,
                                                              pCounterBuffers, pCounterBufferOffsets);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer,
                                                                      uint32_t firstCounterBuffer,
                                                                      uint32_t counterBufferCount,
                                                                      const VkBuffer* pCounterBuffers,
                                                                      const VkDeviceSize* pCounterBufferOffsets) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount,
                                                           pCounterBuffers, pCounterBufferOffsets);

    PFN_vkCmdEndTransformFeedbackEXT pfn = layer_data->dispatch_table.CmdEndTransformFeedbackEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
    }

    layer_data->interceptor->PostCmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount,
                                                            pCounterBuffers, pCounterBufferOffsets);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool,
                                                                   uint32_t query, VkQueryControlFlags flags,
                                                                   uint32_t index) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);

    PFN_vkCmdBeginQueryIndexedEXT pfn = layer_data->dispatch_table.CmdBeginQueryIndexedEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, queryPool, query, flags, index);
    }

    layer_data->interceptor->PostCmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool,
                                                                 uint32_t query, uint32_t index) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);

    PFN_vkCmdEndQueryIndexedEXT pfn = layer_data->dispatch_table.CmdEndQueryIndexedEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, queryPool, query, index);
    }

    layer_data->interceptor->PostCmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer,
                                                                       uint32_t instanceCount, uint32_t firstInstance,
                                                                       VkBuffer counterBuffer,
                                                                       VkDeviceSize counterBufferOffset,
                                                                       uint32_t counterOffset, uint32_t vertexStride) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer,
                                                            counterBufferOffset, counterOffset, vertexStride);

    PFN_vkCmdDrawIndirectByteCountEXT pfn = layer_data->dispatch_table.CmdDrawIndirectByteCountEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset,
            vertexStride);
    }

    layer_data->interceptor->PostCmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer,
                                                             counterBufferOffset, counterOffset, vertexStride);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer,
                                                                const VkCuLaunchInfoNVX* pLaunchInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);

    PFN_vkCmdCuLaunchKernelNVX pfn = layer_data->dispatch_table.CmdCuLaunchKernelNVX;
    if (pfn != nullptr) {
        pfn(commandBuffer, pLaunchInfo);
    }

    layer_data->interceptor->PostCmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                                   VkDeviceSize offset, VkBuffer countBuffer,
                                                                   VkDeviceSize countBufferOffset,
                                                                   uint32_t maxDrawCount, uint32_t stride) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                                        maxDrawCount, stride);

    PFN_vkCmdDrawIndirectCountAMD pfn = layer_data->dispatch_table.CmdDrawIndirectCountAMD;
    if (pfn != nullptr) {
        pfn(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    layer_data->interceptor->PostCmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                                         maxDrawCount, stride);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer,
                                                                          VkBuffer buffer, VkDeviceSize offset,
                                                                          VkBuffer countBuffer,
                                                                          VkDeviceSize countBufferOffset,
                                                                          uint32_t maxDrawCount, uint32_t stride) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer,
                                                               countBufferOffset, maxDrawCount, stride);

    PFN_vkCmdDrawIndexedIndirectCountAMD pfn = layer_data->dispatch_table.CmdDrawIndexedIndirectCountAMD;
    if (pfn != nullptr) {
        pfn(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    layer_data->interceptor->PostCmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer,
                                                                countBufferOffset, maxDrawCount, stride);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBeginConditionalRenderingEXT(
    VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);

    PFN_vkCmdBeginConditionalRenderingEXT pfn = layer_data->dispatch_table.CmdBeginConditionalRenderingEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, pConditionalRenderingBegin);
    }

    layer_data->interceptor->PostCmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdEndConditionalRenderingEXT(commandBuffer);

    PFN_vkCmdEndConditionalRenderingEXT pfn = layer_data->dispatch_table.CmdEndConditionalRenderingEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer);
    }

    layer_data->interceptor->PostCmdEndConditionalRenderingEXT(commandBuffer);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetViewportWScalingNV(VkCommandBuffer commandBuffer,
                                                                    uint32_t firstViewport, uint32_t viewportCount,
                                                                    const VkViewportWScalingNV* pViewportWScalings) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount,
                                                         pViewportWScalings);

    PFN_vkCmdSetViewportWScalingNV pfn = layer_data->dispatch_table.CmdSetViewportWScalingNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
    }

    layer_data->interceptor->PostCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount,
                                                          pViewportWScalings);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer,
                                                                     uint32_t firstDiscardRectangle,
                                                                     uint32_t discardRectangleCount,
                                                                     const VkRect2D* pDiscardRectangles) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount,
                                                          pDiscardRectangles);

    PFN_vkCmdSetDiscardRectangleEXT pfn = layer_data->dispatch_table.CmdSetDiscardRectangleEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
    }

    layer_data->interceptor->PostCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount,
                                                           pDiscardRectangles);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer,
                                                                           VkBool32 discardRectangleEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable);

    PFN_vkCmdSetDiscardRectangleEnableEXT pfn = layer_data->dispatch_table.CmdSetDiscardRectangleEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, discardRectangleEnable);
    }

    layer_data->interceptor->PostCmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable);
}

static VKAPI_ATTR void VKAPI_CALL
InterceptCmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode);

    PFN_vkCmdSetDiscardRectangleModeEXT pfn = layer_data->dispatch_table.CmdSetDiscardRectangleModeEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, discardRectangleMode);
    }

    layer_data->interceptor->PostCmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode);
}

static VKAPI_ATTR VkResult VKAPI_CALL
InterceptSetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(device));
    layer_data->interceptor->PreSetDebugUtilsObjectNameEXT(device, pNameInfo);

    PFN_vkSetDebugUtilsObjectNameEXT pfn = layer_data->dispatch_table.SetDebugUtilsObjectNameEXT;
    if (pfn != nullptr) {
        result = pfn(device, pNameInfo);
    }

    result = layer_data->interceptor->PostSetDebugUtilsObjectNameEXT(device, pNameInfo, result);
    return result;
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer,
                                                                      const VkDebugUtilsLabelEXT* pLabelInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);

    PFN_vkCmdBeginDebugUtilsLabelEXT pfn = layer_data->dispatch_table.CmdBeginDebugUtilsLabelEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, pLabelInfo);
    }

    layer_data->interceptor->PostCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdEndDebugUtilsLabelEXT(commandBuffer);

    PFN_vkCmdEndDebugUtilsLabelEXT pfn = layer_data->dispatch_table.CmdEndDebugUtilsLabelEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer);
    }

    layer_data->interceptor->PostCmdEndDebugUtilsLabelEXT(commandBuffer);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer,
                                                                       const VkDebugUtilsLabelEXT* pLabelInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);

    PFN_vkCmdInsertDebugUtilsLabelEXT pfn = layer_data->dispatch_table.CmdInsertDebugUtilsLabelEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, pLabelInfo);
    }

    layer_data->interceptor->PostCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}

static VKAPI_ATTR VkResult VKAPI_CALL
InterceptCreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
                                      const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetInstanceLayerData(DataKey(instance));
    layer_data->interceptor->PreCreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pMessenger);

    PFN_vkCreateDebugUtilsMessengerEXT pfn = layer_data->dispatch_table.CreateDebugUtilsMessengerEXT;
    if (pfn != nullptr) {
        result = pfn(instance, pCreateInfo, pAllocator, pMessenger);
    }

    result = layer_data->interceptor->PostCreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pMessenger,
                                                                       result);
    return result;
}

static VKAPI_ATTR void VKAPI_CALL InterceptDestroyDebugUtilsMessengerEXT(VkInstance instance,
                                                                         VkDebugUtilsMessengerEXT messenger,
                                                                         const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetInstanceLayerData(DataKey(instance));
    layer_data->interceptor->PreDestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator);

    PFN_vkDestroyDebugUtilsMessengerEXT pfn = layer_data->dispatch_table.DestroyDebugUtilsMessengerEXT;
    if (pfn != nullptr) {
        pfn(instance, messenger, pAllocator);
    }

    layer_data->interceptor->PostDestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator);
}

#ifdef VK_ENABLE_BETA_EXTENSIONS
static VKAPI_ATTR void VKAPI_CALL InterceptCmdInitializeGraphScratchMemoryAMDX(VkCommandBuffer commandBuffer,
                                                                               VkDeviceAddress scratch) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdInitializeGraphScratchMemoryAMDX(commandBuffer, scratch);

    PFN_vkCmdInitializeGraphScratchMemoryAMDX pfn = layer_data->dispatch_table.CmdInitializeGraphScratchMemoryAMDX;
    if (pfn != nullptr) {
        pfn(commandBuffer, scratch);
    }

    layer_data->interceptor->PostCmdInitializeGraphScratchMemoryAMDX(commandBuffer, scratch);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
static VKAPI_ATTR void VKAPI_CALL InterceptCmdDispatchGraphAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                                                const VkDispatchGraphCountInfoAMDX* pCountInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDispatchGraphAMDX(commandBuffer, scratch, pCountInfo);

    PFN_vkCmdDispatchGraphAMDX pfn = layer_data->dispatch_table.CmdDispatchGraphAMDX;
    if (pfn != nullptr) {
        pfn(commandBuffer, scratch, pCountInfo);
    }

    layer_data->interceptor->PostCmdDispatchGraphAMDX(commandBuffer, scratch, pCountInfo);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
static VKAPI_ATTR void VKAPI_CALL InterceptCmdDispatchGraphIndirectAMDX(
    VkCommandBuffer commandBuffer, VkDeviceAddress scratch, const VkDispatchGraphCountInfoAMDX* pCountInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDispatchGraphIndirectAMDX(commandBuffer, scratch, pCountInfo);

    PFN_vkCmdDispatchGraphIndirectAMDX pfn = layer_data->dispatch_table.CmdDispatchGraphIndirectAMDX;
    if (pfn != nullptr) {
        pfn(commandBuffer, scratch, pCountInfo);
    }

    layer_data->interceptor->PostCmdDispatchGraphIndirectAMDX(commandBuffer, scratch, pCountInfo);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
static VKAPI_ATTR void VKAPI_CALL InterceptCmdDispatchGraphIndirectCountAMDX(VkCommandBuffer commandBuffer,
                                                                             VkDeviceAddress scratch,
                                                                             VkDeviceAddress countInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDispatchGraphIndirectCountAMDX(commandBuffer, scratch, countInfo);

    PFN_vkCmdDispatchGraphIndirectCountAMDX pfn = layer_data->dispatch_table.CmdDispatchGraphIndirectCountAMDX;
    if (pfn != nullptr) {
        pfn(commandBuffer, scratch, countInfo);
    }

    layer_data->interceptor->PostCmdDispatchGraphIndirectCountAMDX(commandBuffer, scratch, countInfo);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

static VKAPI_ATTR void VKAPI_CALL
InterceptCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);

    PFN_vkCmdSetSampleLocationsEXT pfn = layer_data->dispatch_table.CmdSetSampleLocationsEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, pSampleLocationsInfo);
    }

    layer_data->interceptor->PostCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBindShadingRateImageNV(VkCommandBuffer commandBuffer,
                                                                     VkImageView imageView, VkImageLayout imageLayout) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);

    PFN_vkCmdBindShadingRateImageNV pfn = layer_data->dispatch_table.CmdBindShadingRateImageNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, imageView, imageLayout);
    }

    layer_data->interceptor->PostCmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetViewportShadingRatePaletteNV(
    VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
    const VkShadingRatePaletteNV* pShadingRatePalettes) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount,
                                                                   pShadingRatePalettes);

    PFN_vkCmdSetViewportShadingRatePaletteNV pfn = layer_data->dispatch_table.CmdSetViewportShadingRatePaletteNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
    }

    layer_data->interceptor->PostCmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount,
                                                                    pShadingRatePalettes);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetCoarseSampleOrderNV(
    VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount,
    const VkCoarseSampleOrderCustomNV* pCustomSampleOrders) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount,
                                                          pCustomSampleOrders);

    PFN_vkCmdSetCoarseSampleOrderNV pfn = layer_data->dispatch_table.CmdSetCoarseSampleOrderNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
    }

    layer_data->interceptor->PostCmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount,
                                                           pCustomSampleOrders);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBuildAccelerationStructureNV(
    VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData,
    VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src,
    VkBuffer scratch, VkDeviceSize scratchOffset) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset,
                                                                update, dst, src, scratch, scratchOffset);

    PFN_vkCmdBuildAccelerationStructureNV pfn = layer_data->dispatch_table.CmdBuildAccelerationStructureNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
    }

    layer_data->interceptor->PostCmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset,
                                                                 update, dst, src, scratch, scratchOffset);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer,
                                                                          VkAccelerationStructureNV dst,
                                                                          VkAccelerationStructureNV src,
                                                                          VkCopyAccelerationStructureModeKHR mode) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);

    PFN_vkCmdCopyAccelerationStructureNV pfn = layer_data->dispatch_table.CmdCopyAccelerationStructureNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, dst, src, mode);
    }

    layer_data->interceptor->PostCmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdTraceRaysNV(
    VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset,
    VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride,
    VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride,
    VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset,
    VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdTraceRaysNV(
        commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer,
        missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset,
        hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset,
        callableShaderBindingStride, width, height, depth);

    PFN_vkCmdTraceRaysNV pfn = layer_data->dispatch_table.CmdTraceRaysNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer,
            missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset,
            hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset,
            callableShaderBindingStride, width, height, depth);
    }

    layer_data->interceptor->PostCmdTraceRaysNV(
        commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer,
        missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset,
        hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset,
        callableShaderBindingStride, width, height, depth);
}

static VKAPI_ATTR void VKAPI_CALL
InterceptCmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
                                                    const VkAccelerationStructureNV* pAccelerationStructures,
                                                    VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdWriteAccelerationStructuresPropertiesNV(
        commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);

    PFN_vkCmdWriteAccelerationStructuresPropertiesNV pfn =
        layer_data->dispatch_table.CmdWriteAccelerationStructuresPropertiesNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
    }

    layer_data->interceptor->PostCmdWriteAccelerationStructuresPropertiesNV(
        commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer,
                                                                   VkPipelineStageFlagBits pipelineStage,
                                                                   VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                                                   uint32_t marker) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);

    PFN_vkCmdWriteBufferMarkerAMD pfn = layer_data->dispatch_table.CmdWriteBufferMarkerAMD;
    if (pfn != nullptr) {
        pfn(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
    }

    layer_data->interceptor->PostCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount,
                                                              uint32_t firstTask) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);

    PFN_vkCmdDrawMeshTasksNV pfn = layer_data->dispatch_table.CmdDrawMeshTasksNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, taskCount, firstTask);
    }

    layer_data->interceptor->PostCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                                      VkDeviceSize offset, uint32_t drawCount,
                                                                      uint32_t stride) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);

    PFN_vkCmdDrawMeshTasksIndirectNV pfn = layer_data->dispatch_table.CmdDrawMeshTasksIndirectNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, buffer, offset, drawCount, stride);
    }

    layer_data->interceptor->PostCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer,
                                                                           VkBuffer buffer, VkDeviceSize offset,
                                                                           VkBuffer countBuffer,
                                                                           VkDeviceSize countBufferOffset,
                                                                           uint32_t maxDrawCount, uint32_t stride) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer,
                                                                countBufferOffset, maxDrawCount, stride);

    PFN_vkCmdDrawMeshTasksIndirectCountNV pfn = layer_data->dispatch_table.CmdDrawMeshTasksIndirectCountNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    layer_data->interceptor->PostCmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer,
                                                                 countBufferOffset, maxDrawCount, stride);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer,
                                                                          uint32_t firstExclusiveScissor,
                                                                          uint32_t exclusiveScissorCount,
                                                                          const VkBool32* pExclusiveScissorEnables) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetExclusiveScissorEnableNV(commandBuffer, firstExclusiveScissor,
                                                               exclusiveScissorCount, pExclusiveScissorEnables);

    PFN_vkCmdSetExclusiveScissorEnableNV pfn = layer_data->dispatch_table.CmdSetExclusiveScissorEnableNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);
    }

    layer_data->interceptor->PostCmdSetExclusiveScissorEnableNV(commandBuffer, firstExclusiveScissor,
                                                                exclusiveScissorCount, pExclusiveScissorEnables);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer,
                                                                    uint32_t firstExclusiveScissor,
                                                                    uint32_t exclusiveScissorCount,
                                                                    const VkRect2D* pExclusiveScissors) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount,
                                                         pExclusiveScissors);

    PFN_vkCmdSetExclusiveScissorNV pfn = layer_data->dispatch_table.CmdSetExclusiveScissorNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
    }

    layer_data->interceptor->PostCmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount,
                                                          pExclusiveScissors);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetCheckpointNV(VkCommandBuffer commandBuffer,
                                                              const void* pCheckpointMarker) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetCheckpointNV(commandBuffer, pCheckpointMarker);

    PFN_vkCmdSetCheckpointNV pfn = layer_data->dispatch_table.CmdSetCheckpointNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, pCheckpointMarker);
    }

    layer_data->interceptor->PostCmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
}

static VKAPI_ATTR VkResult VKAPI_CALL
InterceptCmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceMarkerInfoINTEL* pMarkerInfo) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetPerformanceMarkerINTEL(commandBuffer, pMarkerInfo);

    PFN_vkCmdSetPerformanceMarkerINTEL pfn = layer_data->dispatch_table.CmdSetPerformanceMarkerINTEL;
    if (pfn != nullptr) {
        result = pfn(commandBuffer, pMarkerInfo);
    }

    result = layer_data->interceptor->PostCmdSetPerformanceMarkerINTEL(commandBuffer, pMarkerInfo, result);
    return result;
}

static VKAPI_ATTR VkResult VKAPI_CALL InterceptCmdSetPerformanceStreamMarkerINTEL(
    VkCommandBuffer commandBuffer, const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetPerformanceStreamMarkerINTEL(commandBuffer, pMarkerInfo);

    PFN_vkCmdSetPerformanceStreamMarkerINTEL pfn = layer_data->dispatch_table.CmdSetPerformanceStreamMarkerINTEL;
    if (pfn != nullptr) {
        result = pfn(commandBuffer, pMarkerInfo);
    }

    result = layer_data->interceptor->PostCmdSetPerformanceStreamMarkerINTEL(commandBuffer, pMarkerInfo, result);
    return result;
}

static VKAPI_ATTR VkResult VKAPI_CALL InterceptCmdSetPerformanceOverrideINTEL(
    VkCommandBuffer commandBuffer, const VkPerformanceOverrideInfoINTEL* pOverrideInfo) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetPerformanceOverrideINTEL(commandBuffer, pOverrideInfo);

    PFN_vkCmdSetPerformanceOverrideINTEL pfn = layer_data->dispatch_table.CmdSetPerformanceOverrideINTEL;
    if (pfn != nullptr) {
        result = pfn(commandBuffer, pOverrideInfo);
    }

    result = layer_data->interceptor->PostCmdSetPerformanceOverrideINTEL(commandBuffer, pOverrideInfo, result);
    return result;
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetLineStippleEXT(VkCommandBuffer commandBuffer,
                                                                uint32_t lineStippleFactor,
                                                                uint16_t lineStipplePattern) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);

    PFN_vkCmdSetLineStippleEXT pfn = layer_data->dispatch_table.CmdSetLineStippleEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, lineStippleFactor, lineStipplePattern);
    }

    layer_data->interceptor->PostCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetCullModeEXT(commandBuffer, cullMode);

    PFN_vkCmdSetCullModeEXT pfn = layer_data->dispatch_table.CmdSetCullModeEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, cullMode);
    }

    layer_data->interceptor->PostCmdSetCullModeEXT(commandBuffer, cullMode);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetFrontFaceEXT(commandBuffer, frontFace);

    PFN_vkCmdSetFrontFaceEXT pfn = layer_data->dispatch_table.CmdSetFrontFaceEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, frontFace);
    }

    layer_data->interceptor->PostCmdSetFrontFaceEXT(commandBuffer, frontFace);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer,
                                                                      VkPrimitiveTopology primitiveTopology) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);

    PFN_vkCmdSetPrimitiveTopologyEXT pfn = layer_data->dispatch_table.CmdSetPrimitiveTopologyEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, primitiveTopology);
    }

    layer_data->interceptor->PostCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer,
                                                                      uint32_t viewportCount,
                                                                      const VkViewport* pViewports) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);

    PFN_vkCmdSetViewportWithCountEXT pfn = layer_data->dispatch_table.CmdSetViewportWithCountEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, viewportCount, pViewports);
    }

    layer_data->interceptor->PostCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer,
                                                                     uint32_t scissorCount, const VkRect2D* pScissors) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);

    PFN_vkCmdSetScissorWithCountEXT pfn = layer_data->dispatch_table.CmdSetScissorWithCountEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, scissorCount, pScissors);
    }

    layer_data->interceptor->PostCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBindVertexBuffers2EXT(
    VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers,
    const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets,
                                                         pSizes, pStrides);

    PFN_vkCmdBindVertexBuffers2EXT pfn = layer_data->dispatch_table.CmdBindVertexBuffers2EXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
    }

    layer_data->interceptor->PostCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets,
                                                          pSizes, pStrides);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer,
                                                                    VkBool32 depthTestEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);

    PFN_vkCmdSetDepthTestEnableEXT pfn = layer_data->dispatch_table.CmdSetDepthTestEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, depthTestEnable);
    }

    layer_data->interceptor->PostCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer,
                                                                     VkBool32 depthWriteEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);

    PFN_vkCmdSetDepthWriteEnableEXT pfn = layer_data->dispatch_table.CmdSetDepthWriteEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, depthWriteEnable);
    }

    layer_data->interceptor->PostCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer,
                                                                   VkCompareOp depthCompareOp) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);

    PFN_vkCmdSetDepthCompareOpEXT pfn = layer_data->dispatch_table.CmdSetDepthCompareOpEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, depthCompareOp);
    }

    layer_data->interceptor->PostCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer,
                                                                          VkBool32 depthBoundsTestEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);

    PFN_vkCmdSetDepthBoundsTestEnableEXT pfn = layer_data->dispatch_table.CmdSetDepthBoundsTestEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, depthBoundsTestEnable);
    }

    layer_data->interceptor->PostCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer,
                                                                      VkBool32 stencilTestEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);

    PFN_vkCmdSetStencilTestEnableEXT pfn = layer_data->dispatch_table.CmdSetStencilTestEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, stencilTestEnable);
    }

    layer_data->interceptor->PostCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetStencilOpEXT(VkCommandBuffer commandBuffer,
                                                              VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                                              VkStencilOp passOp, VkStencilOp depthFailOp,
                                                              VkCompareOp compareOp) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);

    PFN_vkCmdSetStencilOpEXT pfn = layer_data->dispatch_table.CmdSetStencilOpEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    }

    layer_data->interceptor->PostCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdPreprocessGeneratedCommandsNV(
    VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);

    PFN_vkCmdPreprocessGeneratedCommandsNV pfn = layer_data->dispatch_table.CmdPreprocessGeneratedCommandsNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, pGeneratedCommandsInfo);
    }

    layer_data->interceptor->PostCmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdExecuteGeneratedCommandsNV(
    VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);

    PFN_vkCmdExecuteGeneratedCommandsNV pfn = layer_data->dispatch_table.CmdExecuteGeneratedCommandsNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
    }

    layer_data->interceptor->PostCmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer,
                                                                        VkPipelineBindPoint pipelineBindPoint,
                                                                        VkPipeline pipeline, uint32_t groupIndex) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);

    PFN_vkCmdBindPipelineShaderGroupNV pfn = layer_data->dispatch_table.CmdBindPipelineShaderGroupNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
    }

    layer_data->interceptor->PostCmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetDepthBias2EXT(VkCommandBuffer commandBuffer,
                                                               const VkDepthBiasInfoEXT* pDepthBiasInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthBias2EXT(commandBuffer, pDepthBiasInfo);

    PFN_vkCmdSetDepthBias2EXT pfn = layer_data->dispatch_table.CmdSetDepthBias2EXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, pDepthBiasInfo);
    }

    layer_data->interceptor->PostCmdSetDepthBias2EXT(commandBuffer, pDepthBiasInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdCudaLaunchKernelNV(VkCommandBuffer commandBuffer,
                                                                 const VkCudaLaunchInfoNV* pLaunchInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCudaLaunchKernelNV(commandBuffer, pLaunchInfo);

    PFN_vkCmdCudaLaunchKernelNV pfn = layer_data->dispatch_table.CmdCudaLaunchKernelNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, pLaunchInfo);
    }

    layer_data->interceptor->PostCmdCudaLaunchKernelNV(commandBuffer, pLaunchInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBindDescriptorBuffersEXT(
    VkCommandBuffer commandBuffer, uint32_t bufferCount, const VkDescriptorBufferBindingInfoEXT* pBindingInfos) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBindDescriptorBuffersEXT(commandBuffer, bufferCount, pBindingInfos);

    PFN_vkCmdBindDescriptorBuffersEXT pfn = layer_data->dispatch_table.CmdBindDescriptorBuffersEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, bufferCount, pBindingInfos);
    }

    layer_data->interceptor->PostCmdBindDescriptorBuffersEXT(commandBuffer, bufferCount, pBindingInfos);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetDescriptorBufferOffsetsEXT(
    VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet,
    uint32_t setCount, const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDescriptorBufferOffsetsEXT(commandBuffer, pipelineBindPoint, layout, firstSet,
                                                                 setCount, pBufferIndices, pOffsets);

    PFN_vkCmdSetDescriptorBufferOffsetsEXT pfn = layer_data->dispatch_table.CmdSetDescriptorBufferOffsetsEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, pipelineBindPoint, layout, firstSet, setCount, pBufferIndices, pOffsets);
    }

    layer_data->interceptor->PostCmdSetDescriptorBufferOffsetsEXT(commandBuffer, pipelineBindPoint, layout, firstSet,
                                                                  setCount, pBufferIndices, pOffsets);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBindDescriptorBufferEmbeddedSamplersEXT(
    VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBindDescriptorBufferEmbeddedSamplersEXT(commandBuffer, pipelineBindPoint, layout,
                                                                           set);

    PFN_vkCmdBindDescriptorBufferEmbeddedSamplersEXT pfn =
        layer_data->dispatch_table.CmdBindDescriptorBufferEmbeddedSamplersEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, pipelineBindPoint, layout, set);
    }

    layer_data->interceptor->PostCmdBindDescriptorBufferEmbeddedSamplersEXT(commandBuffer, pipelineBindPoint, layout,
                                                                            set);
}

static VKAPI_ATTR void VKAPI_CALL
InterceptCmdSetFragmentShadingRateEnumNV(VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate,
                                         const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);

    PFN_vkCmdSetFragmentShadingRateEnumNV pfn = layer_data->dispatch_table.CmdSetFragmentShadingRateEnumNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, shadingRate, combinerOps);
    }

    layer_data->interceptor->PostCmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetVertexInputEXT(
    VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
    const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount,
    const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount,
                                                     pVertexBindingDescriptions, vertexAttributeDescriptionCount,
                                                     pVertexAttributeDescriptions);

    PFN_vkCmdSetVertexInputEXT pfn = layer_data->dispatch_table.CmdSetVertexInputEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount,
            pVertexAttributeDescriptions);
    }

    layer_data->interceptor->PostCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount,
                                                      pVertexBindingDescriptions, vertexAttributeDescriptionCount,
                                                      pVertexAttributeDescriptions);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSubpassShadingHUAWEI(commandBuffer);

    PFN_vkCmdSubpassShadingHUAWEI pfn = layer_data->dispatch_table.CmdSubpassShadingHUAWEI;
    if (pfn != nullptr) {
        pfn(commandBuffer);
    }

    layer_data->interceptor->PostCmdSubpassShadingHUAWEI(commandBuffer);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer,
                                                                       VkImageView imageView,
                                                                       VkImageLayout imageLayout) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBindInvocationMaskHUAWEI(commandBuffer, imageView, imageLayout);

    PFN_vkCmdBindInvocationMaskHUAWEI pfn = layer_data->dispatch_table.CmdBindInvocationMaskHUAWEI;
    if (pfn != nullptr) {
        pfn(commandBuffer, imageView, imageLayout);
    }

    layer_data->interceptor->PostCmdBindInvocationMaskHUAWEI(commandBuffer, imageView, imageLayout);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer,
                                                                       uint32_t patchControlPoints) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);

    PFN_vkCmdSetPatchControlPointsEXT pfn = layer_data->dispatch_table.CmdSetPatchControlPointsEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, patchControlPoints);
    }

    layer_data->interceptor->PostCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer,
                                                                            VkBool32 rasterizerDiscardEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable);

    PFN_vkCmdSetRasterizerDiscardEnableEXT pfn = layer_data->dispatch_table.CmdSetRasterizerDiscardEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, rasterizerDiscardEnable);
    }

    layer_data->interceptor->PostCmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer,
                                                                    VkBool32 depthBiasEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable);

    PFN_vkCmdSetDepthBiasEnableEXT pfn = layer_data->dispatch_table.CmdSetDepthBiasEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, depthBiasEnable);
    }

    layer_data->interceptor->PostCmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetLogicOpEXT(commandBuffer, logicOp);

    PFN_vkCmdSetLogicOpEXT pfn = layer_data->dispatch_table.CmdSetLogicOpEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, logicOp);
    }

    layer_data->interceptor->PostCmdSetLogicOpEXT(commandBuffer, logicOp);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer,
                                                                           VkBool32 primitiveRestartEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable);

    PFN_vkCmdSetPrimitiveRestartEnableEXT pfn = layer_data->dispatch_table.CmdSetPrimitiveRestartEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, primitiveRestartEnable);
    }

    layer_data->interceptor->PostCmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer,
                                                                     uint32_t attachmentCount,
                                                                     const VkBool32* pColorWriteEnables) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);

    PFN_vkCmdSetColorWriteEnableEXT pfn = layer_data->dispatch_table.CmdSetColorWriteEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, attachmentCount, pColorWriteEnables);
    }

    layer_data->interceptor->PostCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                                           const VkMultiDrawInfoEXT* pVertexInfo,
                                                           uint32_t instanceCount, uint32_t firstInstance,
                                                           uint32_t stride) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawMultiEXT(commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance,
                                                stride);

    PFN_vkCmdDrawMultiEXT pfn = layer_data->dispatch_table.CmdDrawMultiEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
    }

    layer_data->interceptor->PostCmdDrawMultiEXT(commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance,
                                                 stride);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                                                  const VkMultiDrawIndexedInfoEXT* pIndexInfo,
                                                                  uint32_t instanceCount, uint32_t firstInstance,
                                                                  uint32_t stride, const int32_t* pVertexOffset) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawMultiIndexedEXT(commandBuffer, drawCount, pIndexInfo, instanceCount,
                                                       firstInstance, stride, pVertexOffset);

    PFN_vkCmdDrawMultiIndexedEXT pfn = layer_data->dispatch_table.CmdDrawMultiIndexedEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
    }

    layer_data->interceptor->PostCmdDrawMultiIndexedEXT(commandBuffer, drawCount, pIndexInfo, instanceCount,
                                                        firstInstance, stride, pVertexOffset);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBuildMicromapsEXT(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                                                const VkMicromapBuildInfoEXT* pInfos) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBuildMicromapsEXT(commandBuffer, infoCount, pInfos);

    PFN_vkCmdBuildMicromapsEXT pfn = layer_data->dispatch_table.CmdBuildMicromapsEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, infoCount, pInfos);
    }

    layer_data->interceptor->PostCmdBuildMicromapsEXT(commandBuffer, infoCount, pInfos);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdCopyMicromapEXT(VkCommandBuffer commandBuffer,
                                                              const VkCopyMicromapInfoEXT* pInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyMicromapEXT(commandBuffer, pInfo);

    PFN_vkCmdCopyMicromapEXT pfn = layer_data->dispatch_table.CmdCopyMicromapEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, pInfo);
    }

    layer_data->interceptor->PostCmdCopyMicromapEXT(commandBuffer, pInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer,
                                                                      const VkCopyMicromapToMemoryInfoEXT* pInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyMicromapToMemoryEXT(commandBuffer, pInfo);

    PFN_vkCmdCopyMicromapToMemoryEXT pfn = layer_data->dispatch_table.CmdCopyMicromapToMemoryEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, pInfo);
    }

    layer_data->interceptor->PostCmdCopyMicromapToMemoryEXT(commandBuffer, pInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer,
                                                                      const VkCopyMemoryToMicromapInfoEXT* pInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyMemoryToMicromapEXT(commandBuffer, pInfo);

    PFN_vkCmdCopyMemoryToMicromapEXT pfn = layer_data->dispatch_table.CmdCopyMemoryToMicromapEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, pInfo);
    }

    layer_data->interceptor->PostCmdCopyMemoryToMicromapEXT(commandBuffer, pInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer,
                                                                          uint32_t micromapCount,
                                                                          const VkMicromapEXT* pMicromaps,
                                                                          VkQueryType queryType, VkQueryPool queryPool,
                                                                          uint32_t firstQuery) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdWriteMicromapsPropertiesEXT(commandBuffer, micromapCount, pMicromaps, queryType,
                                                               queryPool, firstQuery);

    PFN_vkCmdWriteMicromapsPropertiesEXT pfn = layer_data->dispatch_table.CmdWriteMicromapsPropertiesEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);
    }

    layer_data->interceptor->PostCmdWriteMicromapsPropertiesEXT(commandBuffer, micromapCount, pMicromaps, queryType,
                                                                queryPool, firstQuery);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX,
                                                                uint32_t groupCountY, uint32_t groupCountZ) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawClusterHUAWEI(commandBuffer, groupCountX, groupCountY, groupCountZ);

    PFN_vkCmdDrawClusterHUAWEI pfn = layer_data->dispatch_table.CmdDrawClusterHUAWEI;
    if (pfn != nullptr) {
        pfn(commandBuffer, groupCountX, groupCountY, groupCountZ);
    }

    layer_data->interceptor->PostCmdDrawClusterHUAWEI(commandBuffer, groupCountX, groupCountY, groupCountZ);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                                        VkDeviceSize offset) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawClusterIndirectHUAWEI(commandBuffer, buffer, offset);

    PFN_vkCmdDrawClusterIndirectHUAWEI pfn = layer_data->dispatch_table.CmdDrawClusterIndirectHUAWEI;
    if (pfn != nullptr) {
        pfn(commandBuffer, buffer, offset);
    }

    layer_data->interceptor->PostCmdDrawClusterIndirectHUAWEI(commandBuffer, buffer, offset);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer,
                                                                   VkDeviceAddress copyBufferAddress,
                                                                   uint32_t copyCount, uint32_t stride) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyMemoryIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride);

    PFN_vkCmdCopyMemoryIndirectNV pfn = layer_data->dispatch_table.CmdCopyMemoryIndirectNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, copyBufferAddress, copyCount, stride);
    }

    layer_data->interceptor->PostCmdCopyMemoryIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdCopyMemoryToImageIndirectNV(
    VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride,
    VkImage dstImage, VkImageLayout dstImageLayout, const VkImageSubresourceLayers* pImageSubresources) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyMemoryToImageIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride,
                                                               dstImage, dstImageLayout, pImageSubresources);

    PFN_vkCmdCopyMemoryToImageIndirectNV pfn = layer_data->dispatch_table.CmdCopyMemoryToImageIndirectNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, copyBufferAddress, copyCount, stride, dstImage, dstImageLayout, pImageSubresources);
    }

    layer_data->interceptor->PostCmdCopyMemoryToImageIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride,
                                                                dstImage, dstImageLayout, pImageSubresources);
}

static VKAPI_ATTR void VKAPI_CALL
InterceptCmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount,
                               const VkDecompressMemoryRegionNV* pDecompressMemoryRegions) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDecompressMemoryNV(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);

    PFN_vkCmdDecompressMemoryNV pfn = layer_data->dispatch_table.CmdDecompressMemoryNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
    }

    layer_data->interceptor->PostCmdDecompressMemoryNV(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
}

static VKAPI_ATTR void VKAPI_CALL
InterceptCmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer, VkDeviceAddress indirectCommandsAddress,
                                            VkDeviceAddress indirectCommandsCountAddress, uint32_t stride) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDecompressMemoryIndirectCountNV(commandBuffer, indirectCommandsAddress,
                                                                   indirectCommandsCountAddress, stride);

    PFN_vkCmdDecompressMemoryIndirectCountNV pfn = layer_data->dispatch_table.CmdDecompressMemoryIndirectCountNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, indirectCommandsAddress, indirectCommandsCountAddress, stride);
    }

    layer_data->interceptor->PostCmdDecompressMemoryIndirectCountNV(commandBuffer, indirectCommandsAddress,
                                                                    indirectCommandsCountAddress, stride);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer,
                                                                             VkPipelineBindPoint pipelineBindPoint,
                                                                             VkPipeline pipeline) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdUpdatePipelineIndirectBufferNV(commandBuffer, pipelineBindPoint, pipeline);

    PFN_vkCmdUpdatePipelineIndirectBufferNV pfn = layer_data->dispatch_table.CmdUpdatePipelineIndirectBufferNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, pipelineBindPoint, pipeline);
    }

    layer_data->interceptor->PostCmdUpdatePipelineIndirectBufferNV(commandBuffer, pipelineBindPoint, pipeline);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer,
                                                                     VkBool32 depthClampEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthClampEnableEXT(commandBuffer, depthClampEnable);

    PFN_vkCmdSetDepthClampEnableEXT pfn = layer_data->dispatch_table.CmdSetDepthClampEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, depthClampEnable);
    }

    layer_data->interceptor->PostCmdSetDepthClampEnableEXT(commandBuffer, depthClampEnable);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetPolygonModeEXT(VkCommandBuffer commandBuffer,
                                                                VkPolygonMode polygonMode) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetPolygonModeEXT(commandBuffer, polygonMode);

    PFN_vkCmdSetPolygonModeEXT pfn = layer_data->dispatch_table.CmdSetPolygonModeEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, polygonMode);
    }

    layer_data->interceptor->PostCmdSetPolygonModeEXT(commandBuffer, polygonMode);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer,
                                                                         VkSampleCountFlagBits rasterizationSamples) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetRasterizationSamplesEXT(commandBuffer, rasterizationSamples);

    PFN_vkCmdSetRasterizationSamplesEXT pfn = layer_data->dispatch_table.CmdSetRasterizationSamplesEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, rasterizationSamples);
    }

    layer_data->interceptor->PostCmdSetRasterizationSamplesEXT(commandBuffer, rasterizationSamples);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetSampleMaskEXT(VkCommandBuffer commandBuffer,
                                                               VkSampleCountFlagBits samples,
                                                               const VkSampleMask* pSampleMask) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetSampleMaskEXT(commandBuffer, samples, pSampleMask);

    PFN_vkCmdSetSampleMaskEXT pfn = layer_data->dispatch_table.CmdSetSampleMaskEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, samples, pSampleMask);
    }

    layer_data->interceptor->PostCmdSetSampleMaskEXT(commandBuffer, samples, pSampleMask);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer,
                                                                          VkBool32 alphaToCoverageEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetAlphaToCoverageEnableEXT(commandBuffer, alphaToCoverageEnable);

    PFN_vkCmdSetAlphaToCoverageEnableEXT pfn = layer_data->dispatch_table.CmdSetAlphaToCoverageEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, alphaToCoverageEnable);
    }

    layer_data->interceptor->PostCmdSetAlphaToCoverageEnableEXT(commandBuffer, alphaToCoverageEnable);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer,
                                                                     VkBool32 alphaToOneEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetAlphaToOneEnableEXT(commandBuffer, alphaToOneEnable);

    PFN_vkCmdSetAlphaToOneEnableEXT pfn = layer_data->dispatch_table.CmdSetAlphaToOneEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, alphaToOneEnable);
    }

    layer_data->interceptor->PostCmdSetAlphaToOneEnableEXT(commandBuffer, alphaToOneEnable);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer,
                                                                  VkBool32 logicOpEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetLogicOpEnableEXT(commandBuffer, logicOpEnable);

    PFN_vkCmdSetLogicOpEnableEXT pfn = layer_data->dispatch_table.CmdSetLogicOpEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, logicOpEnable);
    }

    layer_data->interceptor->PostCmdSetLogicOpEnableEXT(commandBuffer, logicOpEnable);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer,
                                                                     uint32_t firstAttachment, uint32_t attachmentCount,
                                                                     const VkBool32* pColorBlendEnables) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetColorBlendEnableEXT(commandBuffer, firstAttachment, attachmentCount,
                                                          pColorBlendEnables);

    PFN_vkCmdSetColorBlendEnableEXT pfn = layer_data->dispatch_table.CmdSetColorBlendEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
    }

    layer_data->interceptor->PostCmdSetColorBlendEnableEXT(commandBuffer, firstAttachment, attachmentCount,
                                                           pColorBlendEnables);
}

static VKAPI_ATTR void VKAPI_CALL
InterceptCmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
                                     const VkColorBlendEquationEXT* pColorBlendEquations) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetColorBlendEquationEXT(commandBuffer, firstAttachment, attachmentCount,
                                                            pColorBlendEquations);

    PFN_vkCmdSetColorBlendEquationEXT pfn = layer_data->dispatch_table.CmdSetColorBlendEquationEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
    }

    layer_data->interceptor->PostCmdSetColorBlendEquationEXT(commandBuffer, firstAttachment, attachmentCount,
                                                             pColorBlendEquations);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer,
                                                                   uint32_t firstAttachment, uint32_t attachmentCount,
                                                                   const VkColorComponentFlags* pColorWriteMasks) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetColorWriteMaskEXT(commandBuffer, firstAttachment, attachmentCount,
                                                        pColorWriteMasks);

    PFN_vkCmdSetColorWriteMaskEXT pfn = layer_data->dispatch_table.CmdSetColorWriteMaskEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
    }

    layer_data->interceptor->PostCmdSetColorWriteMaskEXT(commandBuffer, firstAttachment, attachmentCount,
                                                         pColorWriteMasks);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer,
                                                                             VkTessellationDomainOrigin domainOrigin) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetTessellationDomainOriginEXT(commandBuffer, domainOrigin);

    PFN_vkCmdSetTessellationDomainOriginEXT pfn = layer_data->dispatch_table.CmdSetTessellationDomainOriginEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, domainOrigin);
    }

    layer_data->interceptor->PostCmdSetTessellationDomainOriginEXT(commandBuffer, domainOrigin);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer,
                                                                        uint32_t rasterizationStream) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetRasterizationStreamEXT(commandBuffer, rasterizationStream);

    PFN_vkCmdSetRasterizationStreamEXT pfn = layer_data->dispatch_table.CmdSetRasterizationStreamEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, rasterizationStream);
    }

    layer_data->interceptor->PostCmdSetRasterizationStreamEXT(commandBuffer, rasterizationStream);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetConservativeRasterizationModeEXT(
    VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetConservativeRasterizationModeEXT(commandBuffer, conservativeRasterizationMode);

    PFN_vkCmdSetConservativeRasterizationModeEXT pfn =
        layer_data->dispatch_table.CmdSetConservativeRasterizationModeEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, conservativeRasterizationMode);
    }

    layer_data->interceptor->PostCmdSetConservativeRasterizationModeEXT(commandBuffer, conservativeRasterizationMode);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetExtraPrimitiveOverestimationSizeEXT(
    VkCommandBuffer commandBuffer, float extraPrimitiveOverestimationSize) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetExtraPrimitiveOverestimationSizeEXT(commandBuffer,
                                                                          extraPrimitiveOverestimationSize);

    PFN_vkCmdSetExtraPrimitiveOverestimationSizeEXT pfn =
        layer_data->dispatch_table.CmdSetExtraPrimitiveOverestimationSizeEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, extraPrimitiveOverestimationSize);
    }

    layer_data->interceptor->PostCmdSetExtraPrimitiveOverestimationSizeEXT(commandBuffer,
                                                                           extraPrimitiveOverestimationSize);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer,
                                                                    VkBool32 depthClipEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthClipEnableEXT(commandBuffer, depthClipEnable);

    PFN_vkCmdSetDepthClipEnableEXT pfn = layer_data->dispatch_table.CmdSetDepthClipEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, depthClipEnable);
    }

    layer_data->interceptor->PostCmdSetDepthClipEnableEXT(commandBuffer, depthClipEnable);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer,
                                                                          VkBool32 sampleLocationsEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetSampleLocationsEnableEXT(commandBuffer, sampleLocationsEnable);

    PFN_vkCmdSetSampleLocationsEnableEXT pfn = layer_data->dispatch_table.CmdSetSampleLocationsEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, sampleLocationsEnable);
    }

    layer_data->interceptor->PostCmdSetSampleLocationsEnableEXT(commandBuffer, sampleLocationsEnable);
}

static VKAPI_ATTR void VKAPI_CALL
InterceptCmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
                                     const VkColorBlendAdvancedEXT* pColorBlendAdvanced) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetColorBlendAdvancedEXT(commandBuffer, firstAttachment, attachmentCount,
                                                            pColorBlendAdvanced);

    PFN_vkCmdSetColorBlendAdvancedEXT pfn = layer_data->dispatch_table.CmdSetColorBlendAdvancedEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
    }

    layer_data->interceptor->PostCmdSetColorBlendAdvancedEXT(commandBuffer, firstAttachment, attachmentCount,
                                                             pColorBlendAdvanced);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer,
                                                                        VkProvokingVertexModeEXT provokingVertexMode) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetProvokingVertexModeEXT(commandBuffer, provokingVertexMode);

    PFN_vkCmdSetProvokingVertexModeEXT pfn = layer_data->dispatch_table.CmdSetProvokingVertexModeEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, provokingVertexMode);
    }

    layer_data->interceptor->PostCmdSetProvokingVertexModeEXT(commandBuffer, provokingVertexMode);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetLineRasterizationModeEXT(
    VkCommandBuffer commandBuffer, VkLineRasterizationModeEXT lineRasterizationMode) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetLineRasterizationModeEXT(commandBuffer, lineRasterizationMode);

    PFN_vkCmdSetLineRasterizationModeEXT pfn = layer_data->dispatch_table.CmdSetLineRasterizationModeEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, lineRasterizationMode);
    }

    layer_data->interceptor->PostCmdSetLineRasterizationModeEXT(commandBuffer, lineRasterizationMode);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer,
                                                                      VkBool32 stippledLineEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetLineStippleEnableEXT(commandBuffer, stippledLineEnable);

    PFN_vkCmdSetLineStippleEnableEXT pfn = layer_data->dispatch_table.CmdSetLineStippleEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, stippledLineEnable);
    }

    layer_data->interceptor->PostCmdSetLineStippleEnableEXT(commandBuffer, stippledLineEnable);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer,
                                                                              VkBool32 negativeOneToOne) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthClipNegativeOneToOneEXT(commandBuffer, negativeOneToOne);

    PFN_vkCmdSetDepthClipNegativeOneToOneEXT pfn = layer_data->dispatch_table.CmdSetDepthClipNegativeOneToOneEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, negativeOneToOne);
    }

    layer_data->interceptor->PostCmdSetDepthClipNegativeOneToOneEXT(commandBuffer, negativeOneToOne);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer,
                                                                          VkBool32 viewportWScalingEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetViewportWScalingEnableNV(commandBuffer, viewportWScalingEnable);

    PFN_vkCmdSetViewportWScalingEnableNV pfn = layer_data->dispatch_table.CmdSetViewportWScalingEnableNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, viewportWScalingEnable);
    }

    layer_data->interceptor->PostCmdSetViewportWScalingEnableNV(commandBuffer, viewportWScalingEnable);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer,
                                                                   uint32_t firstViewport, uint32_t viewportCount,
                                                                   const VkViewportSwizzleNV* pViewportSwizzles) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetViewportSwizzleNV(commandBuffer, firstViewport, viewportCount, pViewportSwizzles);

    PFN_vkCmdSetViewportSwizzleNV pfn = layer_data->dispatch_table.CmdSetViewportSwizzleNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
    }

    layer_data->interceptor->PostCmdSetViewportSwizzleNV(commandBuffer, firstViewport, viewportCount,
                                                         pViewportSwizzles);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer,
                                                                         VkBool32 coverageToColorEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetCoverageToColorEnableNV(commandBuffer, coverageToColorEnable);

    PFN_vkCmdSetCoverageToColorEnableNV pfn = layer_data->dispatch_table.CmdSetCoverageToColorEnableNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, coverageToColorEnable);
    }

    layer_data->interceptor->PostCmdSetCoverageToColorEnableNV(commandBuffer, coverageToColorEnable);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer,
                                                                           uint32_t coverageToColorLocation) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetCoverageToColorLocationNV(commandBuffer, coverageToColorLocation);

    PFN_vkCmdSetCoverageToColorLocationNV pfn = layer_data->dispatch_table.CmdSetCoverageToColorLocationNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, coverageToColorLocation);
    }

    layer_data->interceptor->PostCmdSetCoverageToColorLocationNV(commandBuffer, coverageToColorLocation);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetCoverageModulationModeNV(
    VkCommandBuffer commandBuffer, VkCoverageModulationModeNV coverageModulationMode) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetCoverageModulationModeNV(commandBuffer, coverageModulationMode);

    PFN_vkCmdSetCoverageModulationModeNV pfn = layer_data->dispatch_table.CmdSetCoverageModulationModeNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, coverageModulationMode);
    }

    layer_data->interceptor->PostCmdSetCoverageModulationModeNV(commandBuffer, coverageModulationMode);
}

static VKAPI_ATTR void VKAPI_CALL
InterceptCmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageModulationTableEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetCoverageModulationTableEnableNV(commandBuffer, coverageModulationTableEnable);

    PFN_vkCmdSetCoverageModulationTableEnableNV pfn = layer_data->dispatch_table.CmdSetCoverageModulationTableEnableNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, coverageModulationTableEnable);
    }

    layer_data->interceptor->PostCmdSetCoverageModulationTableEnableNV(commandBuffer, coverageModulationTableEnable);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer,
                                                                           uint32_t coverageModulationTableCount,
                                                                           const float* pCoverageModulationTable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetCoverageModulationTableNV(commandBuffer, coverageModulationTableCount,
                                                                pCoverageModulationTable);

    PFN_vkCmdSetCoverageModulationTableNV pfn = layer_data->dispatch_table.CmdSetCoverageModulationTableNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
    }

    layer_data->interceptor->PostCmdSetCoverageModulationTableNV(commandBuffer, coverageModulationTableCount,
                                                                 pCoverageModulationTable);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer,
                                                                          VkBool32 shadingRateImageEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetShadingRateImageEnableNV(commandBuffer, shadingRateImageEnable);

    PFN_vkCmdSetShadingRateImageEnableNV pfn = layer_data->dispatch_table.CmdSetShadingRateImageEnableNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, shadingRateImageEnable);
    }

    layer_data->interceptor->PostCmdSetShadingRateImageEnableNV(commandBuffer, shadingRateImageEnable);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetRepresentativeFragmentTestEnableNV(
    VkCommandBuffer commandBuffer, VkBool32 representativeFragmentTestEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetRepresentativeFragmentTestEnableNV(commandBuffer,
                                                                         representativeFragmentTestEnable);

    PFN_vkCmdSetRepresentativeFragmentTestEnableNV pfn =
        layer_data->dispatch_table.CmdSetRepresentativeFragmentTestEnableNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, representativeFragmentTestEnable);
    }

    layer_data->interceptor->PostCmdSetRepresentativeFragmentTestEnableNV(commandBuffer,
                                                                          representativeFragmentTestEnable);
}

static VKAPI_ATTR void VKAPI_CALL
InterceptCmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer, VkCoverageReductionModeNV coverageReductionMode) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetCoverageReductionModeNV(commandBuffer, coverageReductionMode);

    PFN_vkCmdSetCoverageReductionModeNV pfn = layer_data->dispatch_table.CmdSetCoverageReductionModeNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, coverageReductionMode);
    }

    layer_data->interceptor->PostCmdSetCoverageReductionModeNV(commandBuffer, coverageReductionMode);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer,
                                                                   VkOpticalFlowSessionNV session,
                                                                   const VkOpticalFlowExecuteInfoNV* pExecuteInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdOpticalFlowExecuteNV(commandBuffer, session, pExecuteInfo);

    PFN_vkCmdOpticalFlowExecuteNV pfn = layer_data->dispatch_table.CmdOpticalFlowExecuteNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, session, pExecuteInfo);
    }

    layer_data->interceptor->PostCmdOpticalFlowExecuteNV(commandBuffer, session, pExecuteInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount,
                                                             const VkShaderStageFlagBits* pStages,
                                                             const VkShaderEXT* pShaders) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBindShadersEXT(commandBuffer, stageCount, pStages, pShaders);

    PFN_vkCmdBindShadersEXT pfn = layer_data->dispatch_table.CmdBindShadersEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, stageCount, pStages, pShaders);
    }

    layer_data->interceptor->PostCmdBindShadersEXT(commandBuffer, stageCount, pStages, pShaders);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetDepthClampRangeEXT(VkCommandBuffer commandBuffer,
                                                                    VkDepthClampModeEXT depthClampMode,
                                                                    const VkDepthClampRangeEXT* pDepthClampRange) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthClampRangeEXT(commandBuffer, depthClampMode, pDepthClampRange);

    PFN_vkCmdSetDepthClampRangeEXT pfn = layer_data->dispatch_table.CmdSetDepthClampRangeEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, depthClampMode, pDepthClampRange);
    }

    layer_data->interceptor->PostCmdSetDepthClampRangeEXT(commandBuffer, depthClampMode, pDepthClampRange);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer,
                                                                                 VkImageAspectFlags aspectMask) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetAttachmentFeedbackLoopEnableEXT(commandBuffer, aspectMask);

    PFN_vkCmdSetAttachmentFeedbackLoopEnableEXT pfn = layer_data->dispatch_table.CmdSetAttachmentFeedbackLoopEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, aspectMask);
    }

    layer_data->interceptor->PostCmdSetAttachmentFeedbackLoopEnableEXT(commandBuffer, aspectMask);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdPreprocessGeneratedCommandsEXT(
    VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo,
    VkCommandBuffer stateCommandBuffer) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdPreprocessGeneratedCommandsEXT(commandBuffer, pGeneratedCommandsInfo,
                                                                  stateCommandBuffer);

    PFN_vkCmdPreprocessGeneratedCommandsEXT pfn = layer_data->dispatch_table.CmdPreprocessGeneratedCommandsEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, pGeneratedCommandsInfo, stateCommandBuffer);
    }

    layer_data->interceptor->PostCmdPreprocessGeneratedCommandsEXT(commandBuffer, pGeneratedCommandsInfo,
                                                                   stateCommandBuffer);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdExecuteGeneratedCommandsEXT(
    VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdExecuteGeneratedCommandsEXT(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);

    PFN_vkCmdExecuteGeneratedCommandsEXT pfn = layer_data->dispatch_table.CmdExecuteGeneratedCommandsEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
    }

    layer_data->interceptor->PostCmdExecuteGeneratedCommandsEXT(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBuildAccelerationStructuresKHR(
    VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);

    PFN_vkCmdBuildAccelerationStructuresKHR pfn = layer_data->dispatch_table.CmdBuildAccelerationStructuresKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
    }

    layer_data->interceptor->PostCmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdBuildAccelerationStructuresIndirectKHR(
    VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkDeviceAddress* pIndirectDeviceAddresses, const uint32_t* pIndirectStrides,
    const uint32_t* const* ppMaxPrimitiveCounts) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBuildAccelerationStructuresIndirectKHR(
        commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);

    PFN_vkCmdBuildAccelerationStructuresIndirectKHR pfn =
        layer_data->dispatch_table.CmdBuildAccelerationStructuresIndirectKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
    }

    layer_data->interceptor->PostCmdBuildAccelerationStructuresIndirectKHR(
        commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdCopyAccelerationStructureKHR(
    VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyAccelerationStructureKHR(commandBuffer, pInfo);

    PFN_vkCmdCopyAccelerationStructureKHR pfn = layer_data->dispatch_table.CmdCopyAccelerationStructureKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pInfo);
    }

    layer_data->interceptor->PostCmdCopyAccelerationStructureKHR(commandBuffer, pInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdCopyAccelerationStructureToMemoryKHR(
    VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);

    PFN_vkCmdCopyAccelerationStructureToMemoryKHR pfn =
        layer_data->dispatch_table.CmdCopyAccelerationStructureToMemoryKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pInfo);
    }

    layer_data->interceptor->PostCmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdCopyMemoryToAccelerationStructureKHR(
    VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);

    PFN_vkCmdCopyMemoryToAccelerationStructureKHR pfn =
        layer_data->dispatch_table.CmdCopyMemoryToAccelerationStructureKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pInfo);
    }

    layer_data->interceptor->PostCmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdWriteAccelerationStructuresPropertiesKHR(
    VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
    const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool,
    uint32_t firstQuery) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdWriteAccelerationStructuresPropertiesKHR(
        commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);

    PFN_vkCmdWriteAccelerationStructuresPropertiesKHR pfn =
        layer_data->dispatch_table.CmdWriteAccelerationStructuresPropertiesKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
    }

    layer_data->interceptor->PostCmdWriteAccelerationStructuresPropertiesKHR(
        commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdTraceRaysKHR(
    VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width, uint32_t height,
    uint32_t depth) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdTraceRaysKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable,
                                                pHitShaderBindingTable, pCallableShaderBindingTable, width, height,
                                                depth);

    PFN_vkCmdTraceRaysKHR pfn = layer_data->dispatch_table.CmdTraceRaysKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable,
            pCallableShaderBindingTable, width, height, depth);
    }

    layer_data->interceptor->PostCmdTraceRaysKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable,
                                                 pHitShaderBindingTable, pCallableShaderBindingTable, width, height,
                                                 depth);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdTraceRaysIndirectKHR(
    VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdTraceRaysIndirectKHR(commandBuffer, pRaygenShaderBindingTable,
                                                        pMissShaderBindingTable, pHitShaderBindingTable,
                                                        pCallableShaderBindingTable, indirectDeviceAddress);

    PFN_vkCmdTraceRaysIndirectKHR pfn = layer_data->dispatch_table.CmdTraceRaysIndirectKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable,
            pCallableShaderBindingTable, indirectDeviceAddress);
    }

    layer_data->interceptor->PostCmdTraceRaysIndirectKHR(commandBuffer, pRaygenShaderBindingTable,
                                                         pMissShaderBindingTable, pHitShaderBindingTable,
                                                         pCallableShaderBindingTable, indirectDeviceAddress);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer,
                                                                                uint32_t pipelineStackSize) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);

    PFN_vkCmdSetRayTracingPipelineStackSizeKHR pfn = layer_data->dispatch_table.CmdSetRayTracingPipelineStackSizeKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pipelineStackSize);
    }

    layer_data->interceptor->PostCmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX,
                                                               uint32_t groupCountY, uint32_t groupCountZ) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawMeshTasksEXT(commandBuffer, groupCountX, groupCountY, groupCountZ);

    PFN_vkCmdDrawMeshTasksEXT pfn = layer_data->dispatch_table.CmdDrawMeshTasksEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, groupCountX, groupCountY, groupCountZ);
    }

    layer_data->interceptor->PostCmdDrawMeshTasksEXT(commandBuffer, groupCountX, groupCountY, groupCountZ);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                                       VkDeviceSize offset, uint32_t drawCount,
                                                                       uint32_t stride) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawMeshTasksIndirectEXT(commandBuffer, buffer, offset, drawCount, stride);

    PFN_vkCmdDrawMeshTasksIndirectEXT pfn = layer_data->dispatch_table.CmdDrawMeshTasksIndirectEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, buffer, offset, drawCount, stride);
    }

    layer_data->interceptor->PostCmdDrawMeshTasksIndirectEXT(commandBuffer, buffer, offset, drawCount, stride);
}

static VKAPI_ATTR void VKAPI_CALL InterceptCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer,
                                                                            VkBuffer buffer, VkDeviceSize offset,
                                                                            VkBuffer countBuffer,
                                                                            VkDeviceSize countBufferOffset,
                                                                            uint32_t maxDrawCount, uint32_t stride) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawMeshTasksIndirectCountEXT(commandBuffer, buffer, offset, countBuffer,
                                                                 countBufferOffset, maxDrawCount, stride);

    PFN_vkCmdDrawMeshTasksIndirectCountEXT pfn = layer_data->dispatch_table.CmdDrawMeshTasksIndirectCountEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    layer_data->interceptor->PostCmdDrawMeshTasksIndirectCountEXT(commandBuffer, buffer, offset, countBuffer,
                                                                  countBufferOffset, maxDrawCount, stride);
}

typedef enum ApiFunctionType { kFuncTypeInst = 0, kFuncTypePdev = 1, kFuncTypeDev = 2 } ApiFunctionType;

typedef struct {
    ApiFunctionType function_type;
    void* funcptr;
} function_data;

const std::unordered_map<std::string, function_data>& GetNameToFuncPtrMap() {
    static const std::unordered_map<std::string, function_data> name_to_func_ptr_map = {
        {"vkCreateInstance", {kFuncTypeInst, (void*)InterceptCreateInstance}},
        {"vkDestroyInstance", {kFuncTypeInst, (void*)InterceptDestroyInstance}},
        {"vkCreateDevice", {kFuncTypePdev, (void*)InterceptCreateDevice}},
        {"vkDestroyDevice", {kFuncTypeDev, (void*)InterceptDestroyDevice}},
        {"vkEnumerateInstanceExtensionProperties",
         {kFuncTypeInst, (void*)InterceptEnumerateInstanceExtensionProperties}},
        {"vkEnumerateDeviceExtensionProperties", {kFuncTypePdev, (void*)InterceptEnumerateDeviceExtensionProperties}},
        {"vkEnumerateInstanceLayerProperties", {kFuncTypeInst, (void*)InterceptEnumerateInstanceLayerProperties}},
        {"vkEnumerateDeviceLayerProperties", {kFuncTypePdev, (void*)InterceptEnumerateDeviceLayerProperties}},
        {"vkGetDeviceQueue", {kFuncTypeDev, (void*)InterceptGetDeviceQueue}},
        {"vkQueueSubmit", {kFuncTypeDev, (void*)InterceptQueueSubmit}},
        {"vkQueueWaitIdle", {kFuncTypeDev, (void*)InterceptQueueWaitIdle}},
        {"vkDeviceWaitIdle", {kFuncTypeDev, (void*)InterceptDeviceWaitIdle}},
        {"vkQueueBindSparse", {kFuncTypeDev, (void*)InterceptQueueBindSparse}},
        {"vkGetFenceStatus", {kFuncTypeDev, (void*)InterceptGetFenceStatus}},
        {"vkWaitForFences", {kFuncTypeDev, (void*)InterceptWaitForFences}},
        {"vkCreateSemaphore", {kFuncTypeDev, (void*)InterceptCreateSemaphore}},
        {"vkDestroySemaphore", {kFuncTypeDev, (void*)InterceptDestroySemaphore}},
        {"vkGetQueryPoolResults", {kFuncTypeDev, (void*)InterceptGetQueryPoolResults}},
        {"vkCreateShaderModule", {kFuncTypeDev, (void*)InterceptCreateShaderModule}},
        {"vkDestroyShaderModule", {kFuncTypeDev, (void*)InterceptDestroyShaderModule}},
        {"vkCreateGraphicsPipelines", {kFuncTypeDev, (void*)InterceptCreateGraphicsPipelines}},
        {"vkCreateComputePipelines", {kFuncTypeDev, (void*)InterceptCreateComputePipelines}},
        {"vkDestroyPipeline", {kFuncTypeDev, (void*)InterceptDestroyPipeline}},
        {"vkCreateCommandPool", {kFuncTypeDev, (void*)InterceptCreateCommandPool}},
        {"vkDestroyCommandPool", {kFuncTypeDev, (void*)InterceptDestroyCommandPool}},
        {"vkResetCommandPool", {kFuncTypeDev, (void*)InterceptResetCommandPool}},
        {"vkAllocateCommandBuffers", {kFuncTypeDev, (void*)InterceptAllocateCommandBuffers}},
        {"vkFreeCommandBuffers", {kFuncTypeDev, (void*)InterceptFreeCommandBuffers}},
        {"vkBeginCommandBuffer", {kFuncTypeDev, (void*)InterceptBeginCommandBuffer}},
        {"vkEndCommandBuffer", {kFuncTypeDev, (void*)InterceptEndCommandBuffer}},
        {"vkResetCommandBuffer", {kFuncTypeDev, (void*)InterceptResetCommandBuffer}},
        {"vkCmdBindPipeline", {kFuncTypeDev, (void*)InterceptCmdBindPipeline}},
        {"vkCmdSetViewport", {kFuncTypeDev, (void*)InterceptCmdSetViewport}},
        {"vkCmdSetScissor", {kFuncTypeDev, (void*)InterceptCmdSetScissor}},
        {"vkCmdSetLineWidth", {kFuncTypeDev, (void*)InterceptCmdSetLineWidth}},
        {"vkCmdSetDepthBias", {kFuncTypeDev, (void*)InterceptCmdSetDepthBias}},
        {"vkCmdSetBlendConstants", {kFuncTypeDev, (void*)InterceptCmdSetBlendConstants}},
        {"vkCmdSetDepthBounds", {kFuncTypeDev, (void*)InterceptCmdSetDepthBounds}},
        {"vkCmdSetStencilCompareMask", {kFuncTypeDev, (void*)InterceptCmdSetStencilCompareMask}},
        {"vkCmdSetStencilWriteMask", {kFuncTypeDev, (void*)InterceptCmdSetStencilWriteMask}},
        {"vkCmdSetStencilReference", {kFuncTypeDev, (void*)InterceptCmdSetStencilReference}},
        {"vkCmdBindDescriptorSets", {kFuncTypeDev, (void*)InterceptCmdBindDescriptorSets}},
        {"vkCmdBindIndexBuffer", {kFuncTypeDev, (void*)InterceptCmdBindIndexBuffer}},
        {"vkCmdBindVertexBuffers", {kFuncTypeDev, (void*)InterceptCmdBindVertexBuffers}},
        {"vkCmdDraw", {kFuncTypeDev, (void*)InterceptCmdDraw}},
        {"vkCmdDrawIndexed", {kFuncTypeDev, (void*)InterceptCmdDrawIndexed}},
        {"vkCmdDrawIndirect", {kFuncTypeDev, (void*)InterceptCmdDrawIndirect}},
        {"vkCmdDrawIndexedIndirect", {kFuncTypeDev, (void*)InterceptCmdDrawIndexedIndirect}},
        {"vkCmdDispatch", {kFuncTypeDev, (void*)InterceptCmdDispatch}},
        {"vkCmdDispatchIndirect", {kFuncTypeDev, (void*)InterceptCmdDispatchIndirect}},
        {"vkCmdCopyBuffer", {kFuncTypeDev, (void*)InterceptCmdCopyBuffer}},
        {"vkCmdCopyImage", {kFuncTypeDev, (void*)InterceptCmdCopyImage}},
        {"vkCmdBlitImage", {kFuncTypeDev, (void*)InterceptCmdBlitImage}},
        {"vkCmdCopyBufferToImage", {kFuncTypeDev, (void*)InterceptCmdCopyBufferToImage}},
        {"vkCmdCopyImageToBuffer", {kFuncTypeDev, (void*)InterceptCmdCopyImageToBuffer}},
        {"vkCmdUpdateBuffer", {kFuncTypeDev, (void*)InterceptCmdUpdateBuffer}},
        {"vkCmdFillBuffer", {kFuncTypeDev, (void*)InterceptCmdFillBuffer}},
        {"vkCmdClearColorImage", {kFuncTypeDev, (void*)InterceptCmdClearColorImage}},
        {"vkCmdClearDepthStencilImage", {kFuncTypeDev, (void*)InterceptCmdClearDepthStencilImage}},
        {"vkCmdClearAttachments", {kFuncTypeDev, (void*)InterceptCmdClearAttachments}},
        {"vkCmdResolveImage", {kFuncTypeDev, (void*)InterceptCmdResolveImage}},
        {"vkCmdSetEvent", {kFuncTypeDev, (void*)InterceptCmdSetEvent}},
        {"vkCmdResetEvent", {kFuncTypeDev, (void*)InterceptCmdResetEvent}},
        {"vkCmdWaitEvents", {kFuncTypeDev, (void*)InterceptCmdWaitEvents}},
        {"vkCmdPipelineBarrier", {kFuncTypeDev, (void*)InterceptCmdPipelineBarrier}},
        {"vkCmdBeginQuery", {kFuncTypeDev, (void*)InterceptCmdBeginQuery}},
        {"vkCmdEndQuery", {kFuncTypeDev, (void*)InterceptCmdEndQuery}},
        {"vkCmdResetQueryPool", {kFuncTypeDev, (void*)InterceptCmdResetQueryPool}},
        {"vkCmdWriteTimestamp", {kFuncTypeDev, (void*)InterceptCmdWriteTimestamp}},
        {"vkCmdCopyQueryPoolResults", {kFuncTypeDev, (void*)InterceptCmdCopyQueryPoolResults}},
        {"vkCmdPushConstants", {kFuncTypeDev, (void*)InterceptCmdPushConstants}},
        {"vkCmdBeginRenderPass", {kFuncTypeDev, (void*)InterceptCmdBeginRenderPass}},
        {"vkCmdNextSubpass", {kFuncTypeDev, (void*)InterceptCmdNextSubpass}},
        {"vkCmdEndRenderPass", {kFuncTypeDev, (void*)InterceptCmdEndRenderPass}},
        {"vkCmdExecuteCommands", {kFuncTypeDev, (void*)InterceptCmdExecuteCommands}},
        {"vkCmdSetDeviceMask", {kFuncTypeDev, (void*)InterceptCmdSetDeviceMask}},
        {"vkCmdDispatchBase", {kFuncTypeDev, (void*)InterceptCmdDispatchBase}},
        {"vkGetDeviceQueue2", {kFuncTypeDev, (void*)InterceptGetDeviceQueue2}},
        {"vkCmdDrawIndirectCount", {kFuncTypeDev, (void*)InterceptCmdDrawIndirectCount}},
        {"vkCmdDrawIndexedIndirectCount", {kFuncTypeDev, (void*)InterceptCmdDrawIndexedIndirectCount}},
        {"vkCmdBeginRenderPass2", {kFuncTypeDev, (void*)InterceptCmdBeginRenderPass2}},
        {"vkCmdNextSubpass2", {kFuncTypeDev, (void*)InterceptCmdNextSubpass2}},
        {"vkCmdEndRenderPass2", {kFuncTypeDev, (void*)InterceptCmdEndRenderPass2}},
        {"vkGetSemaphoreCounterValue", {kFuncTypeDev, (void*)InterceptGetSemaphoreCounterValue}},
        {"vkWaitSemaphores", {kFuncTypeDev, (void*)InterceptWaitSemaphores}},
        {"vkSignalSemaphore", {kFuncTypeDev, (void*)InterceptSignalSemaphore}},
        {"vkGetPhysicalDeviceToolProperties", {kFuncTypePdev, (void*)InterceptGetPhysicalDeviceToolProperties}},
        {"vkCmdSetEvent2", {kFuncTypeDev, (void*)InterceptCmdSetEvent2}},
        {"vkCmdResetEvent2", {kFuncTypeDev, (void*)InterceptCmdResetEvent2}},
        {"vkCmdWaitEvents2", {kFuncTypeDev, (void*)InterceptCmdWaitEvents2}},
        {"vkCmdPipelineBarrier2", {kFuncTypeDev, (void*)InterceptCmdPipelineBarrier2}},
        {"vkCmdWriteTimestamp2", {kFuncTypeDev, (void*)InterceptCmdWriteTimestamp2}},
        {"vkQueueSubmit2", {kFuncTypeDev, (void*)InterceptQueueSubmit2}},
        {"vkCmdCopyBuffer2", {kFuncTypeDev, (void*)InterceptCmdCopyBuffer2}},
        {"vkCmdCopyImage2", {kFuncTypeDev, (void*)InterceptCmdCopyImage2}},
        {"vkCmdCopyBufferToImage2", {kFuncTypeDev, (void*)InterceptCmdCopyBufferToImage2}},
        {"vkCmdCopyImageToBuffer2", {kFuncTypeDev, (void*)InterceptCmdCopyImageToBuffer2}},
        {"vkCmdBlitImage2", {kFuncTypeDev, (void*)InterceptCmdBlitImage2}},
        {"vkCmdResolveImage2", {kFuncTypeDev, (void*)InterceptCmdResolveImage2}},
        {"vkCmdBeginRendering", {kFuncTypeDev, (void*)InterceptCmdBeginRendering}},
        {"vkCmdEndRendering", {kFuncTypeDev, (void*)InterceptCmdEndRendering}},
        {"vkCmdSetCullMode", {kFuncTypeDev, (void*)InterceptCmdSetCullMode}},
        {"vkCmdSetFrontFace", {kFuncTypeDev, (void*)InterceptCmdSetFrontFace}},
        {"vkCmdSetPrimitiveTopology", {kFuncTypeDev, (void*)InterceptCmdSetPrimitiveTopology}},
        {"vkCmdSetViewportWithCount", {kFuncTypeDev, (void*)InterceptCmdSetViewportWithCount}},
        {"vkCmdSetScissorWithCount", {kFuncTypeDev, (void*)InterceptCmdSetScissorWithCount}},
        {"vkCmdBindVertexBuffers2", {kFuncTypeDev, (void*)InterceptCmdBindVertexBuffers2}},
        {"vkCmdSetDepthTestEnable", {kFuncTypeDev, (void*)InterceptCmdSetDepthTestEnable}},
        {"vkCmdSetDepthWriteEnable", {kFuncTypeDev, (void*)InterceptCmdSetDepthWriteEnable}},
        {"vkCmdSetDepthCompareOp", {kFuncTypeDev, (void*)InterceptCmdSetDepthCompareOp}},
        {"vkCmdSetDepthBoundsTestEnable", {kFuncTypeDev, (void*)InterceptCmdSetDepthBoundsTestEnable}},
        {"vkCmdSetStencilTestEnable", {kFuncTypeDev, (void*)InterceptCmdSetStencilTestEnable}},
        {"vkCmdSetStencilOp", {kFuncTypeDev, (void*)InterceptCmdSetStencilOp}},
        {"vkCmdSetRasterizerDiscardEnable", {kFuncTypeDev, (void*)InterceptCmdSetRasterizerDiscardEnable}},
        {"vkCmdSetDepthBiasEnable", {kFuncTypeDev, (void*)InterceptCmdSetDepthBiasEnable}},
        {"vkCmdSetPrimitiveRestartEnable", {kFuncTypeDev, (void*)InterceptCmdSetPrimitiveRestartEnable}},
        {"vkAcquireNextImageKHR", {kFuncTypeDev, (void*)InterceptAcquireNextImageKHR}},
        {"vkQueuePresentKHR", {kFuncTypeDev, (void*)InterceptQueuePresentKHR}},
        {"vkCmdBeginVideoCodingKHR", {kFuncTypeDev, (void*)InterceptCmdBeginVideoCodingKHR}},
        {"vkCmdEndVideoCodingKHR", {kFuncTypeDev, (void*)InterceptCmdEndVideoCodingKHR}},
        {"vkCmdControlVideoCodingKHR", {kFuncTypeDev, (void*)InterceptCmdControlVideoCodingKHR}},
        {"vkCmdDecodeVideoKHR", {kFuncTypeDev, (void*)InterceptCmdDecodeVideoKHR}},
        {"vkCmdBeginRenderingKHR", {kFuncTypeDev, (void*)InterceptCmdBeginRenderingKHR}},
        {"vkCmdEndRenderingKHR", {kFuncTypeDev, (void*)InterceptCmdEndRenderingKHR}},
        {"vkCmdSetDeviceMaskKHR", {kFuncTypeDev, (void*)InterceptCmdSetDeviceMaskKHR}},
        {"vkCmdDispatchBaseKHR", {kFuncTypeDev, (void*)InterceptCmdDispatchBaseKHR}},
        {"vkCmdPushDescriptorSetKHR", {kFuncTypeDev, (void*)InterceptCmdPushDescriptorSetKHR}},
        {"vkCmdPushDescriptorSetWithTemplateKHR", {kFuncTypeDev, (void*)InterceptCmdPushDescriptorSetWithTemplateKHR}},
        {"vkCmdBeginRenderPass2KHR", {kFuncTypeDev, (void*)InterceptCmdBeginRenderPass2KHR}},
        {"vkCmdNextSubpass2KHR", {kFuncTypeDev, (void*)InterceptCmdNextSubpass2KHR}},
        {"vkCmdEndRenderPass2KHR", {kFuncTypeDev, (void*)InterceptCmdEndRenderPass2KHR}},
        {"vkCmdDrawIndirectCountKHR", {kFuncTypeDev, (void*)InterceptCmdDrawIndirectCountKHR}},
        {"vkCmdDrawIndexedIndirectCountKHR", {kFuncTypeDev, (void*)InterceptCmdDrawIndexedIndirectCountKHR}},
        {"vkGetSemaphoreCounterValueKHR", {kFuncTypeDev, (void*)InterceptGetSemaphoreCounterValueKHR}},
        {"vkWaitSemaphoresKHR", {kFuncTypeDev, (void*)InterceptWaitSemaphoresKHR}},
        {"vkSignalSemaphoreKHR", {kFuncTypeDev, (void*)InterceptSignalSemaphoreKHR}},
        {"vkCmdSetFragmentShadingRateKHR", {kFuncTypeDev, (void*)InterceptCmdSetFragmentShadingRateKHR}},
        {"vkCmdSetRenderingAttachmentLocationsKHR",
         {kFuncTypeDev, (void*)InterceptCmdSetRenderingAttachmentLocationsKHR}},
        {"vkCmdSetRenderingInputAttachmentIndicesKHR",
         {kFuncTypeDev, (void*)InterceptCmdSetRenderingInputAttachmentIndicesKHR}},
        {"vkCmdEncodeVideoKHR", {kFuncTypeDev, (void*)InterceptCmdEncodeVideoKHR}},
        {"vkCmdSetEvent2KHR", {kFuncTypeDev, (void*)InterceptCmdSetEvent2KHR}},
        {"vkCmdResetEvent2KHR", {kFuncTypeDev, (void*)InterceptCmdResetEvent2KHR}},
        {"vkCmdWaitEvents2KHR", {kFuncTypeDev, (void*)InterceptCmdWaitEvents2KHR}},
        {"vkCmdPipelineBarrier2KHR", {kFuncTypeDev, (void*)InterceptCmdPipelineBarrier2KHR}},
        {"vkCmdWriteTimestamp2KHR", {kFuncTypeDev, (void*)InterceptCmdWriteTimestamp2KHR}},
        {"vkQueueSubmit2KHR", {kFuncTypeDev, (void*)InterceptQueueSubmit2KHR}},
        {"vkCmdWriteBufferMarker2AMD", {kFuncTypeDev, (void*)InterceptCmdWriteBufferMarker2AMD}},
        {"vkCmdCopyBuffer2KHR", {kFuncTypeDev, (void*)InterceptCmdCopyBuffer2KHR}},
        {"vkCmdCopyImage2KHR", {kFuncTypeDev, (void*)InterceptCmdCopyImage2KHR}},
        {"vkCmdCopyBufferToImage2KHR", {kFuncTypeDev, (void*)InterceptCmdCopyBufferToImage2KHR}},
        {"vkCmdCopyImageToBuffer2KHR", {kFuncTypeDev, (void*)InterceptCmdCopyImageToBuffer2KHR}},
        {"vkCmdBlitImage2KHR", {kFuncTypeDev, (void*)InterceptCmdBlitImage2KHR}},
        {"vkCmdResolveImage2KHR", {kFuncTypeDev, (void*)InterceptCmdResolveImage2KHR}},
        {"vkCmdTraceRaysIndirect2KHR", {kFuncTypeDev, (void*)InterceptCmdTraceRaysIndirect2KHR}},
        {"vkCmdBindIndexBuffer2KHR", {kFuncTypeDev, (void*)InterceptCmdBindIndexBuffer2KHR}},
        {"vkCmdSetLineStippleKHR", {kFuncTypeDev, (void*)InterceptCmdSetLineStippleKHR}},
        {"vkCmdBindDescriptorSets2KHR", {kFuncTypeDev, (void*)InterceptCmdBindDescriptorSets2KHR}},
        {"vkCmdPushConstants2KHR", {kFuncTypeDev, (void*)InterceptCmdPushConstants2KHR}},
        {"vkCmdPushDescriptorSet2KHR", {kFuncTypeDev, (void*)InterceptCmdPushDescriptorSet2KHR}},
        {"vkCmdPushDescriptorSetWithTemplate2KHR",
         {kFuncTypeDev, (void*)InterceptCmdPushDescriptorSetWithTemplate2KHR}},
        {"vkCmdSetDescriptorBufferOffsets2EXT", {kFuncTypeDev, (void*)InterceptCmdSetDescriptorBufferOffsets2EXT}},
        {"vkCmdBindDescriptorBufferEmbeddedSamplers2EXT",
         {kFuncTypeDev, (void*)InterceptCmdBindDescriptorBufferEmbeddedSamplers2EXT}},
        {"vkCreateDebugReportCallbackEXT", {kFuncTypeInst, (void*)InterceptCreateDebugReportCallbackEXT}},
        {"vkDestroyDebugReportCallbackEXT", {kFuncTypeInst, (void*)InterceptDestroyDebugReportCallbackEXT}},
        {"vkDebugMarkerSetObjectNameEXT", {kFuncTypeDev, (void*)InterceptDebugMarkerSetObjectNameEXT}},
        {"vkCmdDebugMarkerBeginEXT", {kFuncTypeDev, (void*)InterceptCmdDebugMarkerBeginEXT}},
        {"vkCmdDebugMarkerEndEXT", {kFuncTypeDev, (void*)InterceptCmdDebugMarkerEndEXT}},
        {"vkCmdDebugMarkerInsertEXT", {kFuncTypeDev, (void*)InterceptCmdDebugMarkerInsertEXT}},
        {"vkCmdBindTransformFeedbackBuffersEXT", {kFuncTypeDev, (void*)InterceptCmdBindTransformFeedbackBuffersEXT}},
        {"vkCmdBeginTransformFeedbackEXT", {kFuncTypeDev, (void*)InterceptCmdBeginTransformFeedbackEXT}},
        {"vkCmdEndTransformFeedbackEXT", {kFuncTypeDev, (void*)InterceptCmdEndTransformFeedbackEXT}},
        {"vkCmdBeginQueryIndexedEXT", {kFuncTypeDev, (void*)InterceptCmdBeginQueryIndexedEXT}},
        {"vkCmdEndQueryIndexedEXT", {kFuncTypeDev, (void*)InterceptCmdEndQueryIndexedEXT}},
        {"vkCmdDrawIndirectByteCountEXT", {kFuncTypeDev, (void*)InterceptCmdDrawIndirectByteCountEXT}},
        {"vkCmdCuLaunchKernelNVX", {kFuncTypeDev, (void*)InterceptCmdCuLaunchKernelNVX}},
        {"vkCmdDrawIndirectCountAMD", {kFuncTypeDev, (void*)InterceptCmdDrawIndirectCountAMD}},
        {"vkCmdDrawIndexedIndirectCountAMD", {kFuncTypeDev, (void*)InterceptCmdDrawIndexedIndirectCountAMD}},
        {"vkCmdBeginConditionalRenderingEXT", {kFuncTypeDev, (void*)InterceptCmdBeginConditionalRenderingEXT}},
        {"vkCmdEndConditionalRenderingEXT", {kFuncTypeDev, (void*)InterceptCmdEndConditionalRenderingEXT}},
        {"vkCmdSetViewportWScalingNV", {kFuncTypeDev, (void*)InterceptCmdSetViewportWScalingNV}},
        {"vkCmdSetDiscardRectangleEXT", {kFuncTypeDev, (void*)InterceptCmdSetDiscardRectangleEXT}},
        {"vkCmdSetDiscardRectangleEnableEXT", {kFuncTypeDev, (void*)InterceptCmdSetDiscardRectangleEnableEXT}},
        {"vkCmdSetDiscardRectangleModeEXT", {kFuncTypeDev, (void*)InterceptCmdSetDiscardRectangleModeEXT}},
        {"vkSetDebugUtilsObjectNameEXT", {kFuncTypeDev, (void*)InterceptSetDebugUtilsObjectNameEXT}},
        {"vkCmdBeginDebugUtilsLabelEXT", {kFuncTypeDev, (void*)InterceptCmdBeginDebugUtilsLabelEXT}},
        {"vkCmdEndDebugUtilsLabelEXT", {kFuncTypeDev, (void*)InterceptCmdEndDebugUtilsLabelEXT}},
        {"vkCmdInsertDebugUtilsLabelEXT", {kFuncTypeDev, (void*)InterceptCmdInsertDebugUtilsLabelEXT}},
        {"vkCreateDebugUtilsMessengerEXT", {kFuncTypeInst, (void*)InterceptCreateDebugUtilsMessengerEXT}},
        {"vkDestroyDebugUtilsMessengerEXT", {kFuncTypeInst, (void*)InterceptDestroyDebugUtilsMessengerEXT}},
#ifdef VK_ENABLE_BETA_EXTENSIONS
        {"vkCmdInitializeGraphScratchMemoryAMDX", {kFuncTypeDev, (void*)InterceptCmdInitializeGraphScratchMemoryAMDX}},
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
        {"vkCmdDispatchGraphAMDX", {kFuncTypeDev, (void*)InterceptCmdDispatchGraphAMDX}},
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
        {"vkCmdDispatchGraphIndirectAMDX", {kFuncTypeDev, (void*)InterceptCmdDispatchGraphIndirectAMDX}},
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
        {"vkCmdDispatchGraphIndirectCountAMDX", {kFuncTypeDev, (void*)InterceptCmdDispatchGraphIndirectCountAMDX}},
#endif  // VK_ENABLE_BETA_EXTENSIONS
        {"vkCmdSetSampleLocationsEXT", {kFuncTypeDev, (void*)InterceptCmdSetSampleLocationsEXT}},
        {"vkCmdBindShadingRateImageNV", {kFuncTypeDev, (void*)InterceptCmdBindShadingRateImageNV}},
        {"vkCmdSetViewportShadingRatePaletteNV", {kFuncTypeDev, (void*)InterceptCmdSetViewportShadingRatePaletteNV}},
        {"vkCmdSetCoarseSampleOrderNV", {kFuncTypeDev, (void*)InterceptCmdSetCoarseSampleOrderNV}},
        {"vkCmdBuildAccelerationStructureNV", {kFuncTypeDev, (void*)InterceptCmdBuildAccelerationStructureNV}},
        {"vkCmdCopyAccelerationStructureNV", {kFuncTypeDev, (void*)InterceptCmdCopyAccelerationStructureNV}},
        {"vkCmdTraceRaysNV", {kFuncTypeDev, (void*)InterceptCmdTraceRaysNV}},
        {"vkCmdWriteAccelerationStructuresPropertiesNV",
         {kFuncTypeDev, (void*)InterceptCmdWriteAccelerationStructuresPropertiesNV}},
        {"vkCmdWriteBufferMarkerAMD", {kFuncTypeDev, (void*)InterceptCmdWriteBufferMarkerAMD}},
        {"vkCmdDrawMeshTasksNV", {kFuncTypeDev, (void*)InterceptCmdDrawMeshTasksNV}},
        {"vkCmdDrawMeshTasksIndirectNV", {kFuncTypeDev, (void*)InterceptCmdDrawMeshTasksIndirectNV}},
        {"vkCmdDrawMeshTasksIndirectCountNV", {kFuncTypeDev, (void*)InterceptCmdDrawMeshTasksIndirectCountNV}},
        {"vkCmdSetExclusiveScissorEnableNV", {kFuncTypeDev, (void*)InterceptCmdSetExclusiveScissorEnableNV}},
        {"vkCmdSetExclusiveScissorNV", {kFuncTypeDev, (void*)InterceptCmdSetExclusiveScissorNV}},
        {"vkCmdSetCheckpointNV", {kFuncTypeDev, (void*)InterceptCmdSetCheckpointNV}},
        {"vkCmdSetPerformanceMarkerINTEL", {kFuncTypeDev, (void*)InterceptCmdSetPerformanceMarkerINTEL}},
        {"vkCmdSetPerformanceStreamMarkerINTEL", {kFuncTypeDev, (void*)InterceptCmdSetPerformanceStreamMarkerINTEL}},
        {"vkCmdSetPerformanceOverrideINTEL", {kFuncTypeDev, (void*)InterceptCmdSetPerformanceOverrideINTEL}},
        {"vkGetPhysicalDeviceToolPropertiesEXT", {kFuncTypePdev, (void*)InterceptGetPhysicalDeviceToolPropertiesEXT}},
        {"vkCmdSetLineStippleEXT", {kFuncTypeDev, (void*)InterceptCmdSetLineStippleEXT}},
        {"vkCmdSetCullModeEXT", {kFuncTypeDev, (void*)InterceptCmdSetCullModeEXT}},
        {"vkCmdSetFrontFaceEXT", {kFuncTypeDev, (void*)InterceptCmdSetFrontFaceEXT}},
        {"vkCmdSetPrimitiveTopologyEXT", {kFuncTypeDev, (void*)InterceptCmdSetPrimitiveTopologyEXT}},
        {"vkCmdSetViewportWithCountEXT", {kFuncTypeDev, (void*)InterceptCmdSetViewportWithCountEXT}},
        {"vkCmdSetScissorWithCountEXT", {kFuncTypeDev, (void*)InterceptCmdSetScissorWithCountEXT}},
        {"vkCmdBindVertexBuffers2EXT", {kFuncTypeDev, (void*)InterceptCmdBindVertexBuffers2EXT}},
        {"vkCmdSetDepthTestEnableEXT", {kFuncTypeDev, (void*)InterceptCmdSetDepthTestEnableEXT}},
        {"vkCmdSetDepthWriteEnableEXT", {kFuncTypeDev, (void*)InterceptCmdSetDepthWriteEnableEXT}},
        {"vkCmdSetDepthCompareOpEXT", {kFuncTypeDev, (void*)InterceptCmdSetDepthCompareOpEXT}},
        {"vkCmdSetDepthBoundsTestEnableEXT", {kFuncTypeDev, (void*)InterceptCmdSetDepthBoundsTestEnableEXT}},
        {"vkCmdSetStencilTestEnableEXT", {kFuncTypeDev, (void*)InterceptCmdSetStencilTestEnableEXT}},
        {"vkCmdSetStencilOpEXT", {kFuncTypeDev, (void*)InterceptCmdSetStencilOpEXT}},
        {"vkCmdPreprocessGeneratedCommandsNV", {kFuncTypeDev, (void*)InterceptCmdPreprocessGeneratedCommandsNV}},
        {"vkCmdExecuteGeneratedCommandsNV", {kFuncTypeDev, (void*)InterceptCmdExecuteGeneratedCommandsNV}},
        {"vkCmdBindPipelineShaderGroupNV", {kFuncTypeDev, (void*)InterceptCmdBindPipelineShaderGroupNV}},
        {"vkCmdSetDepthBias2EXT", {kFuncTypeDev, (void*)InterceptCmdSetDepthBias2EXT}},
        {"vkCmdCudaLaunchKernelNV", {kFuncTypeDev, (void*)InterceptCmdCudaLaunchKernelNV}},
        {"vkCmdBindDescriptorBuffersEXT", {kFuncTypeDev, (void*)InterceptCmdBindDescriptorBuffersEXT}},
        {"vkCmdSetDescriptorBufferOffsetsEXT", {kFuncTypeDev, (void*)InterceptCmdSetDescriptorBufferOffsetsEXT}},
        {"vkCmdBindDescriptorBufferEmbeddedSamplersEXT",
         {kFuncTypeDev, (void*)InterceptCmdBindDescriptorBufferEmbeddedSamplersEXT}},
        {"vkCmdSetFragmentShadingRateEnumNV", {kFuncTypeDev, (void*)InterceptCmdSetFragmentShadingRateEnumNV}},
        {"vkCmdSetVertexInputEXT", {kFuncTypeDev, (void*)InterceptCmdSetVertexInputEXT}},
        {"vkCmdSubpassShadingHUAWEI", {kFuncTypeDev, (void*)InterceptCmdSubpassShadingHUAWEI}},
        {"vkCmdBindInvocationMaskHUAWEI", {kFuncTypeDev, (void*)InterceptCmdBindInvocationMaskHUAWEI}},
        {"vkCmdSetPatchControlPointsEXT", {kFuncTypeDev, (void*)InterceptCmdSetPatchControlPointsEXT}},
        {"vkCmdSetRasterizerDiscardEnableEXT", {kFuncTypeDev, (void*)InterceptCmdSetRasterizerDiscardEnableEXT}},
        {"vkCmdSetDepthBiasEnableEXT", {kFuncTypeDev, (void*)InterceptCmdSetDepthBiasEnableEXT}},
        {"vkCmdSetLogicOpEXT", {kFuncTypeDev, (void*)InterceptCmdSetLogicOpEXT}},
        {"vkCmdSetPrimitiveRestartEnableEXT", {kFuncTypeDev, (void*)InterceptCmdSetPrimitiveRestartEnableEXT}},
        {"vkCmdSetColorWriteEnableEXT", {kFuncTypeDev, (void*)InterceptCmdSetColorWriteEnableEXT}},
        {"vkCmdDrawMultiEXT", {kFuncTypeDev, (void*)InterceptCmdDrawMultiEXT}},
        {"vkCmdDrawMultiIndexedEXT", {kFuncTypeDev, (void*)InterceptCmdDrawMultiIndexedEXT}},
        {"vkCmdBuildMicromapsEXT", {kFuncTypeDev, (void*)InterceptCmdBuildMicromapsEXT}},
        {"vkCmdCopyMicromapEXT", {kFuncTypeDev, (void*)InterceptCmdCopyMicromapEXT}},
        {"vkCmdCopyMicromapToMemoryEXT", {kFuncTypeDev, (void*)InterceptCmdCopyMicromapToMemoryEXT}},
        {"vkCmdCopyMemoryToMicromapEXT", {kFuncTypeDev, (void*)InterceptCmdCopyMemoryToMicromapEXT}},
        {"vkCmdWriteMicromapsPropertiesEXT", {kFuncTypeDev, (void*)InterceptCmdWriteMicromapsPropertiesEXT}},
        {"vkCmdDrawClusterHUAWEI", {kFuncTypeDev, (void*)InterceptCmdDrawClusterHUAWEI}},
        {"vkCmdDrawClusterIndirectHUAWEI", {kFuncTypeDev, (void*)InterceptCmdDrawClusterIndirectHUAWEI}},
        {"vkCmdCopyMemoryIndirectNV", {kFuncTypeDev, (void*)InterceptCmdCopyMemoryIndirectNV}},
        {"vkCmdCopyMemoryToImageIndirectNV", {kFuncTypeDev, (void*)InterceptCmdCopyMemoryToImageIndirectNV}},
        {"vkCmdDecompressMemoryNV", {kFuncTypeDev, (void*)InterceptCmdDecompressMemoryNV}},
        {"vkCmdDecompressMemoryIndirectCountNV", {kFuncTypeDev, (void*)InterceptCmdDecompressMemoryIndirectCountNV}},
        {"vkCmdUpdatePipelineIndirectBufferNV", {kFuncTypeDev, (void*)InterceptCmdUpdatePipelineIndirectBufferNV}},
        {"vkCmdSetDepthClampEnableEXT", {kFuncTypeDev, (void*)InterceptCmdSetDepthClampEnableEXT}},
        {"vkCmdSetPolygonModeEXT", {kFuncTypeDev, (void*)InterceptCmdSetPolygonModeEXT}},
        {"vkCmdSetRasterizationSamplesEXT", {kFuncTypeDev, (void*)InterceptCmdSetRasterizationSamplesEXT}},
        {"vkCmdSetSampleMaskEXT", {kFuncTypeDev, (void*)InterceptCmdSetSampleMaskEXT}},
        {"vkCmdSetAlphaToCoverageEnableEXT", {kFuncTypeDev, (void*)InterceptCmdSetAlphaToCoverageEnableEXT}},
        {"vkCmdSetAlphaToOneEnableEXT", {kFuncTypeDev, (void*)InterceptCmdSetAlphaToOneEnableEXT}},
        {"vkCmdSetLogicOpEnableEXT", {kFuncTypeDev, (void*)InterceptCmdSetLogicOpEnableEXT}},
        {"vkCmdSetColorBlendEnableEXT", {kFuncTypeDev, (void*)InterceptCmdSetColorBlendEnableEXT}},
        {"vkCmdSetColorBlendEquationEXT", {kFuncTypeDev, (void*)InterceptCmdSetColorBlendEquationEXT}},
        {"vkCmdSetColorWriteMaskEXT", {kFuncTypeDev, (void*)InterceptCmdSetColorWriteMaskEXT}},
        {"vkCmdSetTessellationDomainOriginEXT", {kFuncTypeDev, (void*)InterceptCmdSetTessellationDomainOriginEXT}},
        {"vkCmdSetRasterizationStreamEXT", {kFuncTypeDev, (void*)InterceptCmdSetRasterizationStreamEXT}},
        {"vkCmdSetConservativeRasterizationModeEXT",
         {kFuncTypeDev, (void*)InterceptCmdSetConservativeRasterizationModeEXT}},
        {"vkCmdSetExtraPrimitiveOverestimationSizeEXT",
         {kFuncTypeDev, (void*)InterceptCmdSetExtraPrimitiveOverestimationSizeEXT}},
        {"vkCmdSetDepthClipEnableEXT", {kFuncTypeDev, (void*)InterceptCmdSetDepthClipEnableEXT}},
        {"vkCmdSetSampleLocationsEnableEXT", {kFuncTypeDev, (void*)InterceptCmdSetSampleLocationsEnableEXT}},
        {"vkCmdSetColorBlendAdvancedEXT", {kFuncTypeDev, (void*)InterceptCmdSetColorBlendAdvancedEXT}},
        {"vkCmdSetProvokingVertexModeEXT", {kFuncTypeDev, (void*)InterceptCmdSetProvokingVertexModeEXT}},
        {"vkCmdSetLineRasterizationModeEXT", {kFuncTypeDev, (void*)InterceptCmdSetLineRasterizationModeEXT}},
        {"vkCmdSetLineStippleEnableEXT", {kFuncTypeDev, (void*)InterceptCmdSetLineStippleEnableEXT}},
        {"vkCmdSetDepthClipNegativeOneToOneEXT", {kFuncTypeDev, (void*)InterceptCmdSetDepthClipNegativeOneToOneEXT}},
        {"vkCmdSetViewportWScalingEnableNV", {kFuncTypeDev, (void*)InterceptCmdSetViewportWScalingEnableNV}},
        {"vkCmdSetViewportSwizzleNV", {kFuncTypeDev, (void*)InterceptCmdSetViewportSwizzleNV}},
        {"vkCmdSetCoverageToColorEnableNV", {kFuncTypeDev, (void*)InterceptCmdSetCoverageToColorEnableNV}},
        {"vkCmdSetCoverageToColorLocationNV", {kFuncTypeDev, (void*)InterceptCmdSetCoverageToColorLocationNV}},
        {"vkCmdSetCoverageModulationModeNV", {kFuncTypeDev, (void*)InterceptCmdSetCoverageModulationModeNV}},
        {"vkCmdSetCoverageModulationTableEnableNV",
         {kFuncTypeDev, (void*)InterceptCmdSetCoverageModulationTableEnableNV}},
        {"vkCmdSetCoverageModulationTableNV", {kFuncTypeDev, (void*)InterceptCmdSetCoverageModulationTableNV}},
        {"vkCmdSetShadingRateImageEnableNV", {kFuncTypeDev, (void*)InterceptCmdSetShadingRateImageEnableNV}},
        {"vkCmdSetRepresentativeFragmentTestEnableNV",
         {kFuncTypeDev, (void*)InterceptCmdSetRepresentativeFragmentTestEnableNV}},
        {"vkCmdSetCoverageReductionModeNV", {kFuncTypeDev, (void*)InterceptCmdSetCoverageReductionModeNV}},
        {"vkCmdOpticalFlowExecuteNV", {kFuncTypeDev, (void*)InterceptCmdOpticalFlowExecuteNV}},
        {"vkCmdBindShadersEXT", {kFuncTypeDev, (void*)InterceptCmdBindShadersEXT}},
        {"vkCmdSetDepthClampRangeEXT", {kFuncTypeDev, (void*)InterceptCmdSetDepthClampRangeEXT}},
        {"vkCmdSetAttachmentFeedbackLoopEnableEXT",
         {kFuncTypeDev, (void*)InterceptCmdSetAttachmentFeedbackLoopEnableEXT}},
        {"vkCmdPreprocessGeneratedCommandsEXT", {kFuncTypeDev, (void*)InterceptCmdPreprocessGeneratedCommandsEXT}},
        {"vkCmdExecuteGeneratedCommandsEXT", {kFuncTypeDev, (void*)InterceptCmdExecuteGeneratedCommandsEXT}},
        {"vkCmdBuildAccelerationStructuresKHR", {kFuncTypeDev, (void*)InterceptCmdBuildAccelerationStructuresKHR}},
        {"vkCmdBuildAccelerationStructuresIndirectKHR",
         {kFuncTypeDev, (void*)InterceptCmdBuildAccelerationStructuresIndirectKHR}},
        {"vkCmdCopyAccelerationStructureKHR", {kFuncTypeDev, (void*)InterceptCmdCopyAccelerationStructureKHR}},
        {"vkCmdCopyAccelerationStructureToMemoryKHR",
         {kFuncTypeDev, (void*)InterceptCmdCopyAccelerationStructureToMemoryKHR}},
        {"vkCmdCopyMemoryToAccelerationStructureKHR",
         {kFuncTypeDev, (void*)InterceptCmdCopyMemoryToAccelerationStructureKHR}},
        {"vkCmdWriteAccelerationStructuresPropertiesKHR",
         {kFuncTypeDev, (void*)InterceptCmdWriteAccelerationStructuresPropertiesKHR}},
        {"vkCmdTraceRaysKHR", {kFuncTypeDev, (void*)InterceptCmdTraceRaysKHR}},
        {"vkCmdTraceRaysIndirectKHR", {kFuncTypeDev, (void*)InterceptCmdTraceRaysIndirectKHR}},
        {"vkCmdSetRayTracingPipelineStackSizeKHR",
         {kFuncTypeDev, (void*)InterceptCmdSetRayTracingPipelineStackSizeKHR}},
        {"vkCmdDrawMeshTasksEXT", {kFuncTypeDev, (void*)InterceptCmdDrawMeshTasksEXT}},
        {"vkCmdDrawMeshTasksIndirectEXT", {kFuncTypeDev, (void*)InterceptCmdDrawMeshTasksIndirectEXT}},
        {"vkCmdDrawMeshTasksIndirectCountEXT", {kFuncTypeDev, (void*)InterceptCmdDrawMeshTasksIndirectCountEXT}},
    };
    return name_to_func_ptr_map;
};

// NOLINTEND
