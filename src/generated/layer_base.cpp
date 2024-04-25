
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

#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>
#include <vulkan/vk_layer.h>
#include <vulkan/vulkan.h>

#include "layer_base.h"

namespace crash_diagnostic_layer {

constexpr VkLayerProperties kLayerProperties{"VK_LAYER_LUNARG_crash_diagnostic", VK_HEADER_VERSION, 1,
                                             "Crash Diagnostic Layer is a crash/hang debugging tool that helps "
                                             "determines GPU progress in a Vulkan application."};

constexpr VkPhysicalDeviceToolPropertiesEXT kToolProperties{
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES_EXT,
    nullptr,
    "VK_LAYER_LUNARG_crash_diagnostic",
    "1",
    VK_TOOL_PURPOSE_TRACING_BIT_EXT | VK_TOOL_PURPOSE_DEBUG_REPORTING_BIT_EXT | VK_TOOL_PURPOSE_DEBUG_MARKERS_BIT_EXT,
    "Crash Diagnostic Layer is a crash/hang debugging tool that helps determines GPU progress in a Vulkan application.",
    "VK_LAYER_LUNARG_crash_diagnostic",
};

namespace {

// Generally we expect to get the same device and instance, so we keep them handy
static thread_local InstanceData* last_used_instance_data = nullptr;
static thread_local DeviceData* last_used_device_data = nullptr;

std::mutex g_instance_mutex;
std::unordered_map<uintptr_t, std::unique_ptr<InstanceData>> g_instance_data;

std::mutex g_device_mutex;
std::unordered_map<uintptr_t, std::unique_ptr<DeviceData>> g_device_data;

}  // namespace

uintptr_t DataKey(const void* object) { return (uintptr_t)(*(void**)object); }

InstanceData* GetInstanceLayerData(uintptr_t key) {
    if (last_used_instance_data && DataKey(last_used_instance_data->instance) == key) {
        return last_used_instance_data;
    }

    std::lock_guard<std::mutex> lock(g_instance_mutex);
    last_used_instance_data = g_instance_data[key].get();
    return last_used_instance_data;
}

void FreeInstanceLayerData(uintptr_t key) {
    std::lock_guard<std::mutex> lock(g_instance_mutex);
    g_instance_data.erase(key);
    last_used_instance_data = nullptr;
}

DeviceData* GetDeviceLayerData(uintptr_t key) {
    if (last_used_device_data && DataKey(last_used_device_data->device) == key) {
        return last_used_device_data;
    }

    std::lock_guard<std::mutex> lock(g_device_mutex);
    last_used_device_data = g_device_data[key].get();
    return last_used_device_data;
}

void FreeDeviceLayerData(uintptr_t key) {
    std::lock_guard<std::mutex> lock(g_device_mutex);
    g_device_data.erase(key);
    last_used_device_data = nullptr;
}

static VkStruct* FindOnChain(VkStruct* s, VkStructureType type) {
    VkStruct* n = (VkStruct*)s->pNext;
    while (n && n->sType != type) {
        n = (VkStruct*)n->pNext;
    }
    return n;
}

VkLayerInstanceCreateInfo* GetLoaderInstanceInfo(const VkInstanceCreateInfo* create_info, VkLayerFunction func_type) {
    VkStruct* n = (VkStruct*)create_info;
    while ((n = FindOnChain(n, VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO))) {
        VkLayerInstanceCreateInfo* vci = (VkLayerInstanceCreateInfo*)n;
        if (vci->function == func_type) {
            return vci;
        }
    }
    return nullptr;
}

VkLayerDeviceCreateInfo* GetLoaderDeviceInfo(const VkDeviceCreateInfo* create_info, VkLayerFunction func_type) {
    VkStruct* n = (VkStruct*)create_info;
    while ((n = FindOnChain(n, VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO))) {
        VkLayerDeviceCreateInfo* vdi = (VkLayerDeviceCreateInfo*)n;
        if (vdi->function == func_type) {
            return vdi;
        }
    }
    return nullptr;
}

VkResult SetInstanceLoaderData(VkInstance instance, void* obj) {
    InstanceData* instance_data = GetInstanceLayerData(DataKey(instance));
    return instance_data->pfn_set_instance_loader_data(instance, obj);
}

VkResult SetDeviceLoaderData(VkDevice device, void* obj) {
    DeviceData* device_data = GetDeviceLayerData(DataKey(device));
    return device_data->pfn_set_device_loader_data(device, obj);
}

// Declare the list of implemented instance and device extensions.

static constexpr std::array<VkExtensionProperties, 3> instance_extensions{{
    {VK_EXT_DEBUG_REPORT_EXTENSION_NAME, VK_EXT_DEBUG_REPORT_SPEC_VERSION},
    {VK_EXT_DEBUG_UTILS_EXTENSION_NAME, VK_EXT_DEBUG_UTILS_SPEC_VERSION},
    {VK_EXT_LAYER_SETTINGS_EXTENSION_NAME, VK_EXT_LAYER_SETTINGS_SPEC_VERSION},
}};
static constexpr std::array<VkExtensionProperties, 2> device_extensions{{
    {VK_EXT_DEBUG_MARKER_EXTENSION_NAME, VK_EXT_DEBUG_MARKER_SPEC_VERSION},
    {VK_EXT_TOOLING_INFO_EXTENSION_NAME, VK_EXT_TOOLING_INFO_SPEC_VERSION},
}};

// Implement layer version of Vulkan API functions.

void InterceptGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue) {
    auto layer_data = GetDeviceLayerData(DataKey(device));
    PFN_vkGetDeviceQueue pfn = layer_data->dispatch_table.GetDeviceQueue;
    if (pfn != nullptr) {
        pfn(device, queueFamilyIndex, queueIndex, pQueue);
    }

    layer_data->interceptor->PostGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
}

VkResult InterceptQueueWaitIdle(VkQueue queue) {
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

VkResult InterceptDeviceWaitIdle(VkDevice device) {
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

VkResult InterceptGetFenceStatus(VkDevice device, VkFence fence) {
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

VkResult InterceptWaitForFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll,
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

VkResult InterceptCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo,
                                  const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore) {
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

void InterceptDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetDeviceLayerData(DataKey(device));
    layer_data->interceptor->PreDestroySemaphore(device, semaphore, pAllocator);

    PFN_vkDestroySemaphore pfn = layer_data->dispatch_table.DestroySemaphore;
    if (pfn != nullptr) {
        pfn(device, semaphore, pAllocator);
    }

    layer_data->interceptor->PostDestroySemaphore(device, semaphore, pAllocator);
}

VkResult InterceptGetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount,
                                      size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags) {
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

VkResult InterceptCreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo,
                                     const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(device));
    PFN_vkCreateShaderModule pfn = layer_data->dispatch_table.CreateShaderModule;
    if (pfn != nullptr) {
        result = pfn(device, pCreateInfo, pAllocator, pShaderModule);
    }

    result = layer_data->interceptor->PostCreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule, result);
    return result;
}

void InterceptDestroyShaderModule(VkDevice device, VkShaderModule shaderModule,
                                  const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetDeviceLayerData(DataKey(device));
    PFN_vkDestroyShaderModule pfn = layer_data->dispatch_table.DestroyShaderModule;
    if (pfn != nullptr) {
        pfn(device, shaderModule, pAllocator);
    }

    layer_data->interceptor->PostDestroyShaderModule(device, shaderModule, pAllocator);
}

VkResult InterceptCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount,
                                          const VkGraphicsPipelineCreateInfo* pCreateInfos,
                                          const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
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

VkResult InterceptCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount,
                                         const VkComputePipelineCreateInfo* pCreateInfos,
                                         const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
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

void InterceptDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetDeviceLayerData(DataKey(device));
    layer_data->interceptor->PreDestroyPipeline(device, pipeline, pAllocator);

    PFN_vkDestroyPipeline pfn = layer_data->dispatch_table.DestroyPipeline;
    if (pfn != nullptr) {
        pfn(device, pipeline, pAllocator);
    }

    layer_data->interceptor->PostDestroyPipeline(device, pipeline, pAllocator);
}

VkResult InterceptCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo,
                                    const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool) {
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

void InterceptDestroyCommandPool(VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetDeviceLayerData(DataKey(device));
    layer_data->interceptor->PreDestroyCommandPool(device, commandPool, pAllocator);

    PFN_vkDestroyCommandPool pfn = layer_data->dispatch_table.DestroyCommandPool;
    if (pfn != nullptr) {
        pfn(device, commandPool, pAllocator);
    }

    layer_data->interceptor->PostDestroyCommandPool(device, commandPool, pAllocator);
}

VkResult InterceptResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags) {
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

VkResult InterceptAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo,
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

void InterceptFreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount,
                                 const VkCommandBuffer* pCommandBuffers) {
    auto layer_data = GetDeviceLayerData(DataKey(device));
    layer_data->interceptor->PreFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);

    PFN_vkFreeCommandBuffers pfn = layer_data->dispatch_table.FreeCommandBuffers;
    if (pfn != nullptr) {
        pfn(device, commandPool, commandBufferCount, pCommandBuffers);
    }

    layer_data->interceptor->PostFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
}

VkResult InterceptBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo) {
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

VkResult InterceptEndCommandBuffer(VkCommandBuffer commandBuffer) {
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

VkResult InterceptResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) {
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

void InterceptCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                              VkPipeline pipeline) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);

    PFN_vkCmdBindPipeline pfn = layer_data->dispatch_table.CmdBindPipeline;
    if (pfn != nullptr) {
        pfn(commandBuffer, pipelineBindPoint, pipeline);
    }

    layer_data->interceptor->PostCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
}

void InterceptCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                             const VkViewport* pViewports) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);

    PFN_vkCmdSetViewport pfn = layer_data->dispatch_table.CmdSetViewport;
    if (pfn != nullptr) {
        pfn(commandBuffer, firstViewport, viewportCount, pViewports);
    }

    layer_data->interceptor->PostCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
}

void InterceptCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount,
                            const VkRect2D* pScissors) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);

    PFN_vkCmdSetScissor pfn = layer_data->dispatch_table.CmdSetScissor;
    if (pfn != nullptr) {
        pfn(commandBuffer, firstScissor, scissorCount, pScissors);
    }

    layer_data->interceptor->PostCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
}

void InterceptCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetLineWidth(commandBuffer, lineWidth);

    PFN_vkCmdSetLineWidth pfn = layer_data->dispatch_table.CmdSetLineWidth;
    if (pfn != nullptr) {
        pfn(commandBuffer, lineWidth);
    }

    layer_data->interceptor->PostCmdSetLineWidth(commandBuffer, lineWidth);
}

void InterceptCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp,
                              float depthBiasSlopeFactor) {
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

void InterceptCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetBlendConstants(commandBuffer, blendConstants);

    PFN_vkCmdSetBlendConstants pfn = layer_data->dispatch_table.CmdSetBlendConstants;
    if (pfn != nullptr) {
        pfn(commandBuffer, blendConstants);
    }

    layer_data->interceptor->PostCmdSetBlendConstants(commandBuffer, blendConstants);
}

void InterceptCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);

    PFN_vkCmdSetDepthBounds pfn = layer_data->dispatch_table.CmdSetDepthBounds;
    if (pfn != nullptr) {
        pfn(commandBuffer, minDepthBounds, maxDepthBounds);
    }

    layer_data->interceptor->PostCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
}

void InterceptCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                       uint32_t compareMask) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);

    PFN_vkCmdSetStencilCompareMask pfn = layer_data->dispatch_table.CmdSetStencilCompareMask;
    if (pfn != nullptr) {
        pfn(commandBuffer, faceMask, compareMask);
    }

    layer_data->interceptor->PostCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
}

void InterceptCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);

    PFN_vkCmdSetStencilWriteMask pfn = layer_data->dispatch_table.CmdSetStencilWriteMask;
    if (pfn != nullptr) {
        pfn(commandBuffer, faceMask, writeMask);
    }

    layer_data->interceptor->PostCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
}

void InterceptCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetStencilReference(commandBuffer, faceMask, reference);

    PFN_vkCmdSetStencilReference pfn = layer_data->dispatch_table.CmdSetStencilReference;
    if (pfn != nullptr) {
        pfn(commandBuffer, faceMask, reference);
    }

    layer_data->interceptor->PostCmdSetStencilReference(commandBuffer, faceMask, reference);
}

void InterceptCmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                    VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount,
                                    const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount,
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

void InterceptCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                 VkIndexType indexType) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);

    PFN_vkCmdBindIndexBuffer pfn = layer_data->dispatch_table.CmdBindIndexBuffer;
    if (pfn != nullptr) {
        pfn(commandBuffer, buffer, offset, indexType);
    }

    layer_data->interceptor->PostCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
}

void InterceptCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                   const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);

    PFN_vkCmdBindVertexBuffers pfn = layer_data->dispatch_table.CmdBindVertexBuffers;
    if (pfn != nullptr) {
        pfn(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
    }

    layer_data->interceptor->PostCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
}

void InterceptCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex,
                      uint32_t firstInstance) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);

    PFN_vkCmdDraw pfn = layer_data->dispatch_table.CmdDraw;
    if (pfn != nullptr) {
        pfn(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    }

    layer_data->interceptor->PostCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}

void InterceptCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount,
                             uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) {
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

void InterceptCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount,
                              uint32_t stride) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);

    PFN_vkCmdDrawIndirect pfn = layer_data->dispatch_table.CmdDrawIndirect;
    if (pfn != nullptr) {
        pfn(commandBuffer, buffer, offset, drawCount, stride);
    }

    layer_data->interceptor->PostCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
}

void InterceptCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                     uint32_t drawCount, uint32_t stride) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);

    PFN_vkCmdDrawIndexedIndirect pfn = layer_data->dispatch_table.CmdDrawIndexedIndirect;
    if (pfn != nullptr) {
        pfn(commandBuffer, buffer, offset, drawCount, stride);
    }

    layer_data->interceptor->PostCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
}

void InterceptCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                          uint32_t groupCountZ) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);

    PFN_vkCmdDispatch pfn = layer_data->dispatch_table.CmdDispatch;
    if (pfn != nullptr) {
        pfn(commandBuffer, groupCountX, groupCountY, groupCountZ);
    }

    layer_data->interceptor->PostCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
}

void InterceptCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDispatchIndirect(commandBuffer, buffer, offset);

    PFN_vkCmdDispatchIndirect pfn = layer_data->dispatch_table.CmdDispatchIndirect;
    if (pfn != nullptr) {
        pfn(commandBuffer, buffer, offset);
    }

    layer_data->interceptor->PostCmdDispatchIndirect(commandBuffer, buffer, offset);
}

void InterceptCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount,
                            const VkBufferCopy* pRegions) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);

    PFN_vkCmdCopyBuffer pfn = layer_data->dispatch_table.CmdCopyBuffer;
    if (pfn != nullptr) {
        pfn(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
    }

    layer_data->interceptor->PostCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
}

void InterceptCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                           VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
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

void InterceptCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                           VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
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

void InterceptCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage,
                                   VkImageLayout dstImageLayout, uint32_t regionCount,
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

void InterceptCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                   VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions) {
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

void InterceptCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                              VkDeviceSize dataSize, const void* pData) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);

    PFN_vkCmdUpdateBuffer pfn = layer_data->dispatch_table.CmdUpdateBuffer;
    if (pfn != nullptr) {
        pfn(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
    }

    layer_data->interceptor->PostCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
}

void InterceptCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                            VkDeviceSize size, uint32_t data) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);

    PFN_vkCmdFillBuffer pfn = layer_data->dispatch_table.CmdFillBuffer;
    if (pfn != nullptr) {
        pfn(commandBuffer, dstBuffer, dstOffset, size, data);
    }

    layer_data->interceptor->PostCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
}

void InterceptCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
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

void InterceptCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                        const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount,
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

void InterceptCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                  const VkClearAttachment* pAttachments, uint32_t rectCount,
                                  const VkClearRect* pRects) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);

    PFN_vkCmdClearAttachments pfn = layer_data->dispatch_table.CmdClearAttachments;
    if (pfn != nullptr) {
        pfn(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
    }

    layer_data->interceptor->PostCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
}

void InterceptCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                              VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
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

void InterceptCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetEvent(commandBuffer, event, stageMask);

    PFN_vkCmdSetEvent pfn = layer_data->dispatch_table.CmdSetEvent;
    if (pfn != nullptr) {
        pfn(commandBuffer, event, stageMask);
    }

    layer_data->interceptor->PostCmdSetEvent(commandBuffer, event, stageMask);
}

void InterceptCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdResetEvent(commandBuffer, event, stageMask);

    PFN_vkCmdResetEvent pfn = layer_data->dispatch_table.CmdResetEvent;
    if (pfn != nullptr) {
        pfn(commandBuffer, event, stageMask);
    }

    layer_data->interceptor->PostCmdResetEvent(commandBuffer, event, stageMask);
}

void InterceptCmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                            VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask,
                            uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
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

void InterceptCmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask,
                                 VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags,
                                 uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers,
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

void InterceptCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                            VkQueryControlFlags flags) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBeginQuery(commandBuffer, queryPool, query, flags);

    PFN_vkCmdBeginQuery pfn = layer_data->dispatch_table.CmdBeginQuery;
    if (pfn != nullptr) {
        pfn(commandBuffer, queryPool, query, flags);
    }

    layer_data->interceptor->PostCmdBeginQuery(commandBuffer, queryPool, query, flags);
}

void InterceptCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdEndQuery(commandBuffer, queryPool, query);

    PFN_vkCmdEndQuery pfn = layer_data->dispatch_table.CmdEndQuery;
    if (pfn != nullptr) {
        pfn(commandBuffer, queryPool, query);
    }

    layer_data->interceptor->PostCmdEndQuery(commandBuffer, queryPool, query);
}

void InterceptCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                uint32_t queryCount) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);

    PFN_vkCmdResetQueryPool pfn = layer_data->dispatch_table.CmdResetQueryPool;
    if (pfn != nullptr) {
        pfn(commandBuffer, queryPool, firstQuery, queryCount);
    }

    layer_data->interceptor->PostCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
}

void InterceptCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                VkQueryPool queryPool, uint32_t query) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);

    PFN_vkCmdWriteTimestamp pfn = layer_data->dispatch_table.CmdWriteTimestamp;
    if (pfn != nullptr) {
        pfn(commandBuffer, pipelineStage, queryPool, query);
    }

    layer_data->interceptor->PostCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
}

void InterceptCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery,
                                      uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset,
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

void InterceptCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags,
                               uint32_t offset, uint32_t size, const void* pValues) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);

    PFN_vkCmdPushConstants pfn = layer_data->dispatch_table.CmdPushConstants;
    if (pfn != nullptr) {
        pfn(commandBuffer, layout, stageFlags, offset, size, pValues);
    }

    layer_data->interceptor->PostCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
}

void InterceptCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                 VkSubpassContents contents) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);

    PFN_vkCmdBeginRenderPass pfn = layer_data->dispatch_table.CmdBeginRenderPass;
    if (pfn != nullptr) {
        pfn(commandBuffer, pRenderPassBegin, contents);
    }

    layer_data->interceptor->PostCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
}

void InterceptCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdNextSubpass(commandBuffer, contents);

    PFN_vkCmdNextSubpass pfn = layer_data->dispatch_table.CmdNextSubpass;
    if (pfn != nullptr) {
        pfn(commandBuffer, contents);
    }

    layer_data->interceptor->PostCmdNextSubpass(commandBuffer, contents);
}

void InterceptCmdEndRenderPass(VkCommandBuffer commandBuffer) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdEndRenderPass(commandBuffer);

    PFN_vkCmdEndRenderPass pfn = layer_data->dispatch_table.CmdEndRenderPass;
    if (pfn != nullptr) {
        pfn(commandBuffer);
    }

    layer_data->interceptor->PostCmdEndRenderPass(commandBuffer);
}

void InterceptCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount,
                                 const VkCommandBuffer* pCommandBuffers) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);

    PFN_vkCmdExecuteCommands pfn = layer_data->dispatch_table.CmdExecuteCommands;
    if (pfn != nullptr) {
        pfn(commandBuffer, commandBufferCount, pCommandBuffers);
    }

    layer_data->interceptor->PostCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
}

void InterceptCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDeviceMask(commandBuffer, deviceMask);

    PFN_vkCmdSetDeviceMask pfn = layer_data->dispatch_table.CmdSetDeviceMask;
    if (pfn != nullptr) {
        pfn(commandBuffer, deviceMask);
    }

    layer_data->interceptor->PostCmdSetDeviceMask(commandBuffer, deviceMask);
}

void InterceptCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                              uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
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

void InterceptGetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue) {
    auto layer_data = GetDeviceLayerData(DataKey(device));
    layer_data->interceptor->PreGetDeviceQueue2(device, pQueueInfo, pQueue);

    PFN_vkGetDeviceQueue2 pfn = layer_data->dispatch_table.GetDeviceQueue2;
    if (pfn != nullptr) {
        pfn(device, pQueueInfo, pQueue);
    }

    layer_data->interceptor->PostGetDeviceQueue2(device, pQueueInfo, pQueue);
}

void InterceptCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                   VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
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

void InterceptCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                          VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                          uint32_t stride) {
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

void InterceptCmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                  const VkSubpassBeginInfo* pSubpassBeginInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);

    PFN_vkCmdBeginRenderPass2 pfn = layer_data->dispatch_table.CmdBeginRenderPass2;
    if (pfn != nullptr) {
        pfn(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    }

    layer_data->interceptor->PostCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

void InterceptCmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                              const VkSubpassEndInfo* pSubpassEndInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);

    PFN_vkCmdNextSubpass2 pfn = layer_data->dispatch_table.CmdNextSubpass2;
    if (pfn != nullptr) {
        pfn(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    }

    layer_data->interceptor->PostCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}

void InterceptCmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdEndRenderPass2(commandBuffer, pSubpassEndInfo);

    PFN_vkCmdEndRenderPass2 pfn = layer_data->dispatch_table.CmdEndRenderPass2;
    if (pfn != nullptr) {
        pfn(commandBuffer, pSubpassEndInfo);
    }

    layer_data->interceptor->PostCmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
}

void InterceptCmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetEvent2(commandBuffer, event, pDependencyInfo);

    PFN_vkCmdSetEvent2 pfn = layer_data->dispatch_table.CmdSetEvent2;
    if (pfn != nullptr) {
        pfn(commandBuffer, event, pDependencyInfo);
    }

    layer_data->interceptor->PostCmdSetEvent2(commandBuffer, event, pDependencyInfo);
}

void InterceptCmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdResetEvent2(commandBuffer, event, stageMask);

    PFN_vkCmdResetEvent2 pfn = layer_data->dispatch_table.CmdResetEvent2;
    if (pfn != nullptr) {
        pfn(commandBuffer, event, stageMask);
    }

    layer_data->interceptor->PostCmdResetEvent2(commandBuffer, event, stageMask);
}

void InterceptCmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                             const VkDependencyInfo* pDependencyInfos) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);

    PFN_vkCmdWaitEvents2 pfn = layer_data->dispatch_table.CmdWaitEvents2;
    if (pfn != nullptr) {
        pfn(commandBuffer, eventCount, pEvents, pDependencyInfos);
    }

    layer_data->interceptor->PostCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
}

void InterceptCmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdPipelineBarrier2(commandBuffer, pDependencyInfo);

    PFN_vkCmdPipelineBarrier2 pfn = layer_data->dispatch_table.CmdPipelineBarrier2;
    if (pfn != nullptr) {
        pfn(commandBuffer, pDependencyInfo);
    }

    layer_data->interceptor->PostCmdPipelineBarrier2(commandBuffer, pDependencyInfo);
}

void InterceptCmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool,
                                 uint32_t query) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdWriteTimestamp2(commandBuffer, stage, queryPool, query);

    PFN_vkCmdWriteTimestamp2 pfn = layer_data->dispatch_table.CmdWriteTimestamp2;
    if (pfn != nullptr) {
        pfn(commandBuffer, stage, queryPool, query);
    }

    layer_data->interceptor->PostCmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
}

void InterceptCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyBuffer2(commandBuffer, pCopyBufferInfo);

    PFN_vkCmdCopyBuffer2 pfn = layer_data->dispatch_table.CmdCopyBuffer2;
    if (pfn != nullptr) {
        pfn(commandBuffer, pCopyBufferInfo);
    }

    layer_data->interceptor->PostCmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
}

void InterceptCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyImage2(commandBuffer, pCopyImageInfo);

    PFN_vkCmdCopyImage2 pfn = layer_data->dispatch_table.CmdCopyImage2;
    if (pfn != nullptr) {
        pfn(commandBuffer, pCopyImageInfo);
    }

    layer_data->interceptor->PostCmdCopyImage2(commandBuffer, pCopyImageInfo);
}

void InterceptCmdCopyBufferToImage2(VkCommandBuffer commandBuffer,
                                    const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);

    PFN_vkCmdCopyBufferToImage2 pfn = layer_data->dispatch_table.CmdCopyBufferToImage2;
    if (pfn != nullptr) {
        pfn(commandBuffer, pCopyBufferToImageInfo);
    }

    layer_data->interceptor->PostCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
}

void InterceptCmdCopyImageToBuffer2(VkCommandBuffer commandBuffer,
                                    const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);

    PFN_vkCmdCopyImageToBuffer2 pfn = layer_data->dispatch_table.CmdCopyImageToBuffer2;
    if (pfn != nullptr) {
        pfn(commandBuffer, pCopyImageToBufferInfo);
    }

    layer_data->interceptor->PostCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
}

void InterceptCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBlitImage2(commandBuffer, pBlitImageInfo);

    PFN_vkCmdBlitImage2 pfn = layer_data->dispatch_table.CmdBlitImage2;
    if (pfn != nullptr) {
        pfn(commandBuffer, pBlitImageInfo);
    }

    layer_data->interceptor->PostCmdBlitImage2(commandBuffer, pBlitImageInfo);
}

void InterceptCmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdResolveImage2(commandBuffer, pResolveImageInfo);

    PFN_vkCmdResolveImage2 pfn = layer_data->dispatch_table.CmdResolveImage2;
    if (pfn != nullptr) {
        pfn(commandBuffer, pResolveImageInfo);
    }

    layer_data->interceptor->PostCmdResolveImage2(commandBuffer, pResolveImageInfo);
}

void InterceptCmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBeginRendering(commandBuffer, pRenderingInfo);

    PFN_vkCmdBeginRendering pfn = layer_data->dispatch_table.CmdBeginRendering;
    if (pfn != nullptr) {
        pfn(commandBuffer, pRenderingInfo);
    }

    layer_data->interceptor->PostCmdBeginRendering(commandBuffer, pRenderingInfo);
}

void InterceptCmdEndRendering(VkCommandBuffer commandBuffer) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdEndRendering(commandBuffer);

    PFN_vkCmdEndRendering pfn = layer_data->dispatch_table.CmdEndRendering;
    if (pfn != nullptr) {
        pfn(commandBuffer);
    }

    layer_data->interceptor->PostCmdEndRendering(commandBuffer);
}

void InterceptCmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetCullMode(commandBuffer, cullMode);

    PFN_vkCmdSetCullMode pfn = layer_data->dispatch_table.CmdSetCullMode;
    if (pfn != nullptr) {
        pfn(commandBuffer, cullMode);
    }

    layer_data->interceptor->PostCmdSetCullMode(commandBuffer, cullMode);
}

void InterceptCmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetFrontFace(commandBuffer, frontFace);

    PFN_vkCmdSetFrontFace pfn = layer_data->dispatch_table.CmdSetFrontFace;
    if (pfn != nullptr) {
        pfn(commandBuffer, frontFace);
    }

    layer_data->interceptor->PostCmdSetFrontFace(commandBuffer, frontFace);
}

void InterceptCmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetPrimitiveTopology(commandBuffer, primitiveTopology);

    PFN_vkCmdSetPrimitiveTopology pfn = layer_data->dispatch_table.CmdSetPrimitiveTopology;
    if (pfn != nullptr) {
        pfn(commandBuffer, primitiveTopology);
    }

    layer_data->interceptor->PostCmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
}

void InterceptCmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                      const VkViewport* pViewports) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);

    PFN_vkCmdSetViewportWithCount pfn = layer_data->dispatch_table.CmdSetViewportWithCount;
    if (pfn != nullptr) {
        pfn(commandBuffer, viewportCount, pViewports);
    }

    layer_data->interceptor->PostCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
}

void InterceptCmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);

    PFN_vkCmdSetScissorWithCount pfn = layer_data->dispatch_table.CmdSetScissorWithCount;
    if (pfn != nullptr) {
        pfn(commandBuffer, scissorCount, pScissors);
    }

    layer_data->interceptor->PostCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
}

void InterceptCmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                    const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes,
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

void InterceptCmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthTestEnable(commandBuffer, depthTestEnable);

    PFN_vkCmdSetDepthTestEnable pfn = layer_data->dispatch_table.CmdSetDepthTestEnable;
    if (pfn != nullptr) {
        pfn(commandBuffer, depthTestEnable);
    }

    layer_data->interceptor->PostCmdSetDepthTestEnable(commandBuffer, depthTestEnable);
}

void InterceptCmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);

    PFN_vkCmdSetDepthWriteEnable pfn = layer_data->dispatch_table.CmdSetDepthWriteEnable;
    if (pfn != nullptr) {
        pfn(commandBuffer, depthWriteEnable);
    }

    layer_data->interceptor->PostCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
}

void InterceptCmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthCompareOp(commandBuffer, depthCompareOp);

    PFN_vkCmdSetDepthCompareOp pfn = layer_data->dispatch_table.CmdSetDepthCompareOp;
    if (pfn != nullptr) {
        pfn(commandBuffer, depthCompareOp);
    }

    layer_data->interceptor->PostCmdSetDepthCompareOp(commandBuffer, depthCompareOp);
}

void InterceptCmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);

    PFN_vkCmdSetDepthBoundsTestEnable pfn = layer_data->dispatch_table.CmdSetDepthBoundsTestEnable;
    if (pfn != nullptr) {
        pfn(commandBuffer, depthBoundsTestEnable);
    }

    layer_data->interceptor->PostCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
}

void InterceptCmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetStencilTestEnable(commandBuffer, stencilTestEnable);

    PFN_vkCmdSetStencilTestEnable pfn = layer_data->dispatch_table.CmdSetStencilTestEnable;
    if (pfn != nullptr) {
        pfn(commandBuffer, stencilTestEnable);
    }

    layer_data->interceptor->PostCmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
}

void InterceptCmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                              VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);

    PFN_vkCmdSetStencilOp pfn = layer_data->dispatch_table.CmdSetStencilOp;
    if (pfn != nullptr) {
        pfn(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    }

    layer_data->interceptor->PostCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}

void InterceptCmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);

    PFN_vkCmdSetRasterizerDiscardEnable pfn = layer_data->dispatch_table.CmdSetRasterizerDiscardEnable;
    if (pfn != nullptr) {
        pfn(commandBuffer, rasterizerDiscardEnable);
    }

    layer_data->interceptor->PostCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
}

void InterceptCmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);

    PFN_vkCmdSetDepthBiasEnable pfn = layer_data->dispatch_table.CmdSetDepthBiasEnable;
    if (pfn != nullptr) {
        pfn(commandBuffer, depthBiasEnable);
    }

    layer_data->interceptor->PostCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
}

void InterceptCmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);

    PFN_vkCmdSetPrimitiveRestartEnable pfn = layer_data->dispatch_table.CmdSetPrimitiveRestartEnable;
    if (pfn != nullptr) {
        pfn(commandBuffer, primitiveRestartEnable);
    }

    layer_data->interceptor->PostCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
}

VkResult InterceptAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout,
                                      VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex) {
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

VkResult InterceptQueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo) {
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

void InterceptCmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);

    PFN_vkCmdBeginVideoCodingKHR pfn = layer_data->dispatch_table.CmdBeginVideoCodingKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pBeginInfo);
    }

    layer_data->interceptor->PostCmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);
}

void InterceptCmdEndVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);

    PFN_vkCmdEndVideoCodingKHR pfn = layer_data->dispatch_table.CmdEndVideoCodingKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pEndCodingInfo);
    }

    layer_data->interceptor->PostCmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);
}

void InterceptCmdControlVideoCodingKHR(VkCommandBuffer commandBuffer,
                                       const VkVideoCodingControlInfoKHR* pCodingControlInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);

    PFN_vkCmdControlVideoCodingKHR pfn = layer_data->dispatch_table.CmdControlVideoCodingKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pCodingControlInfo);
    }

    layer_data->interceptor->PostCmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);
}

void InterceptCmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDecodeVideoKHR(commandBuffer, pDecodeInfo);

    PFN_vkCmdDecodeVideoKHR pfn = layer_data->dispatch_table.CmdDecodeVideoKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pDecodeInfo);
    }

    layer_data->interceptor->PostCmdDecodeVideoKHR(commandBuffer, pDecodeInfo);
}

void InterceptCmdBeginRenderingKHR(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBeginRenderingKHR(commandBuffer, pRenderingInfo);

    PFN_vkCmdBeginRenderingKHR pfn = layer_data->dispatch_table.CmdBeginRenderingKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pRenderingInfo);
    }

    layer_data->interceptor->PostCmdBeginRenderingKHR(commandBuffer, pRenderingInfo);
}

void InterceptCmdEndRenderingKHR(VkCommandBuffer commandBuffer) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdEndRenderingKHR(commandBuffer);

    PFN_vkCmdEndRenderingKHR pfn = layer_data->dispatch_table.CmdEndRenderingKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer);
    }

    layer_data->interceptor->PostCmdEndRenderingKHR(commandBuffer);
}

void InterceptCmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDeviceMaskKHR(commandBuffer, deviceMask);

    PFN_vkCmdSetDeviceMaskKHR pfn = layer_data->dispatch_table.CmdSetDeviceMaskKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, deviceMask);
    }

    layer_data->interceptor->PostCmdSetDeviceMaskKHR(commandBuffer, deviceMask);
}

void InterceptCmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                 uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
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

void InterceptCmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                      VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount,
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

void InterceptCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer,
                                                  VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                  VkPipelineLayout layout, uint32_t set, const void* pData) {
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

void InterceptCmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin,
                                     const VkSubpassBeginInfo* pSubpassBeginInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);

    PFN_vkCmdBeginRenderPass2KHR pfn = layer_data->dispatch_table.CmdBeginRenderPass2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    }

    layer_data->interceptor->PostCmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

void InterceptCmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo,
                                 const VkSubpassEndInfo* pSubpassEndInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);

    PFN_vkCmdNextSubpass2KHR pfn = layer_data->dispatch_table.CmdNextSubpass2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    }

    layer_data->interceptor->PostCmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}

void InterceptCmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);

    PFN_vkCmdEndRenderPass2KHR pfn = layer_data->dispatch_table.CmdEndRenderPass2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pSubpassEndInfo);
    }

    layer_data->interceptor->PostCmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);
}

void InterceptCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                      VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                      uint32_t stride) {
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

void InterceptCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                             VkBuffer countBuffer, VkDeviceSize countBufferOffset,
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

VkResult InterceptGetSemaphoreCounterValueKHR(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) {
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

VkResult InterceptWaitSemaphoresKHR(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) {
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

VkResult InterceptSignalSemaphoreKHR(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) {
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

void InterceptCmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize,
                                           const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);

    PFN_vkCmdSetFragmentShadingRateKHR pfn = layer_data->dispatch_table.CmdSetFragmentShadingRateKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pFragmentSize, combinerOps);
    }

    layer_data->interceptor->PostCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
}

void InterceptCmdSetRenderingAttachmentLocationsKHR(VkCommandBuffer commandBuffer,
                                                    const VkRenderingAttachmentLocationInfoKHR* pLocationInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetRenderingAttachmentLocationsKHR(commandBuffer, pLocationInfo);

    PFN_vkCmdSetRenderingAttachmentLocationsKHR pfn = layer_data->dispatch_table.CmdSetRenderingAttachmentLocationsKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pLocationInfo);
    }

    layer_data->interceptor->PostCmdSetRenderingAttachmentLocationsKHR(commandBuffer, pLocationInfo);
}

void InterceptCmdSetRenderingInputAttachmentIndicesKHR(VkCommandBuffer commandBuffer,
                                                       const VkRenderingInputAttachmentIndexInfoKHR* pLocationInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetRenderingInputAttachmentIndicesKHR(commandBuffer, pLocationInfo);

    PFN_vkCmdSetRenderingInputAttachmentIndicesKHR pfn =
        layer_data->dispatch_table.CmdSetRenderingInputAttachmentIndicesKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pLocationInfo);
    }

    layer_data->interceptor->PostCmdSetRenderingInputAttachmentIndicesKHR(commandBuffer, pLocationInfo);
}

void InterceptCmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdEncodeVideoKHR(commandBuffer, pEncodeInfo);

    PFN_vkCmdEncodeVideoKHR pfn = layer_data->dispatch_table.CmdEncodeVideoKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pEncodeInfo);
    }

    layer_data->interceptor->PostCmdEncodeVideoKHR(commandBuffer, pEncodeInfo);
}

void InterceptCmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetEvent2KHR(commandBuffer, event, pDependencyInfo);

    PFN_vkCmdSetEvent2KHR pfn = layer_data->dispatch_table.CmdSetEvent2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, event, pDependencyInfo);
    }

    layer_data->interceptor->PostCmdSetEvent2KHR(commandBuffer, event, pDependencyInfo);
}

void InterceptCmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdResetEvent2KHR(commandBuffer, event, stageMask);

    PFN_vkCmdResetEvent2KHR pfn = layer_data->dispatch_table.CmdResetEvent2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, event, stageMask);
    }

    layer_data->interceptor->PostCmdResetEvent2KHR(commandBuffer, event, stageMask);
}

void InterceptCmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents,
                                const VkDependencyInfo* pDependencyInfos) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos);

    PFN_vkCmdWaitEvents2KHR pfn = layer_data->dispatch_table.CmdWaitEvents2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, eventCount, pEvents, pDependencyInfos);
    }

    layer_data->interceptor->PostCmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos);
}

void InterceptCmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo);

    PFN_vkCmdPipelineBarrier2KHR pfn = layer_data->dispatch_table.CmdPipelineBarrier2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pDependencyInfo);
    }

    layer_data->interceptor->PostCmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo);
}

void InterceptCmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool,
                                    uint32_t query) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query);

    PFN_vkCmdWriteTimestamp2KHR pfn = layer_data->dispatch_table.CmdWriteTimestamp2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, stage, queryPool, query);
    }

    layer_data->interceptor->PostCmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query);
}

void InterceptCmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkBuffer dstBuffer,
                                       VkDeviceSize dstOffset, uint32_t marker) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);

    PFN_vkCmdWriteBufferMarker2AMD pfn = layer_data->dispatch_table.CmdWriteBufferMarker2AMD;
    if (pfn != nullptr) {
        pfn(commandBuffer, stage, dstBuffer, dstOffset, marker);
    }

    layer_data->interceptor->PostCmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
}

void InterceptCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);

    PFN_vkCmdCopyBuffer2KHR pfn = layer_data->dispatch_table.CmdCopyBuffer2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pCopyBufferInfo);
    }

    layer_data->interceptor->PostCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);
}

void InterceptCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyImage2KHR(commandBuffer, pCopyImageInfo);

    PFN_vkCmdCopyImage2KHR pfn = layer_data->dispatch_table.CmdCopyImage2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pCopyImageInfo);
    }

    layer_data->interceptor->PostCmdCopyImage2KHR(commandBuffer, pCopyImageInfo);
}

void InterceptCmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer,
                                       const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);

    PFN_vkCmdCopyBufferToImage2KHR pfn = layer_data->dispatch_table.CmdCopyBufferToImage2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pCopyBufferToImageInfo);
    }

    layer_data->interceptor->PostCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);
}

void InterceptCmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer,
                                       const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);

    PFN_vkCmdCopyImageToBuffer2KHR pfn = layer_data->dispatch_table.CmdCopyImageToBuffer2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pCopyImageToBufferInfo);
    }

    layer_data->interceptor->PostCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);
}

void InterceptCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBlitImage2KHR(commandBuffer, pBlitImageInfo);

    PFN_vkCmdBlitImage2KHR pfn = layer_data->dispatch_table.CmdBlitImage2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pBlitImageInfo);
    }

    layer_data->interceptor->PostCmdBlitImage2KHR(commandBuffer, pBlitImageInfo);
}

void InterceptCmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdResolveImage2KHR(commandBuffer, pResolveImageInfo);

    PFN_vkCmdResolveImage2KHR pfn = layer_data->dispatch_table.CmdResolveImage2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pResolveImageInfo);
    }

    layer_data->interceptor->PostCmdResolveImage2KHR(commandBuffer, pResolveImageInfo);
}

void InterceptCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdTraceRaysIndirect2KHR(commandBuffer, indirectDeviceAddress);

    PFN_vkCmdTraceRaysIndirect2KHR pfn = layer_data->dispatch_table.CmdTraceRaysIndirect2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, indirectDeviceAddress);
    }

    layer_data->interceptor->PostCmdTraceRaysIndirect2KHR(commandBuffer, indirectDeviceAddress);
}

void InterceptCmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                     VkDeviceSize size, VkIndexType indexType) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBindIndexBuffer2KHR(commandBuffer, buffer, offset, size, indexType);

    PFN_vkCmdBindIndexBuffer2KHR pfn = layer_data->dispatch_table.CmdBindIndexBuffer2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, buffer, offset, size, indexType);
    }

    layer_data->interceptor->PostCmdBindIndexBuffer2KHR(commandBuffer, buffer, offset, size, indexType);
}

void InterceptCmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                   uint16_t lineStipplePattern) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetLineStippleKHR(commandBuffer, lineStippleFactor, lineStipplePattern);

    PFN_vkCmdSetLineStippleKHR pfn = layer_data->dispatch_table.CmdSetLineStippleKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, lineStippleFactor, lineStipplePattern);
    }

    layer_data->interceptor->PostCmdSetLineStippleKHR(commandBuffer, lineStippleFactor, lineStipplePattern);
}

void InterceptCmdBindDescriptorSets2KHR(VkCommandBuffer commandBuffer,
                                        const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBindDescriptorSets2KHR(commandBuffer, pBindDescriptorSetsInfo);

    PFN_vkCmdBindDescriptorSets2KHR pfn = layer_data->dispatch_table.CmdBindDescriptorSets2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pBindDescriptorSetsInfo);
    }

    layer_data->interceptor->PostCmdBindDescriptorSets2KHR(commandBuffer, pBindDescriptorSetsInfo);
}

void InterceptCmdPushConstants2KHR(VkCommandBuffer commandBuffer, const VkPushConstantsInfoKHR* pPushConstantsInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdPushConstants2KHR(commandBuffer, pPushConstantsInfo);

    PFN_vkCmdPushConstants2KHR pfn = layer_data->dispatch_table.CmdPushConstants2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pPushConstantsInfo);
    }

    layer_data->interceptor->PostCmdPushConstants2KHR(commandBuffer, pPushConstantsInfo);
}

void InterceptCmdPushDescriptorSet2KHR(VkCommandBuffer commandBuffer,
                                       const VkPushDescriptorSetInfoKHR* pPushDescriptorSetInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdPushDescriptorSet2KHR(commandBuffer, pPushDescriptorSetInfo);

    PFN_vkCmdPushDescriptorSet2KHR pfn = layer_data->dispatch_table.CmdPushDescriptorSet2KHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pPushDescriptorSetInfo);
    }

    layer_data->interceptor->PostCmdPushDescriptorSet2KHR(commandBuffer, pPushDescriptorSetInfo);
}

void InterceptCmdPushDescriptorSetWithTemplate2KHR(
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

void InterceptCmdSetDescriptorBufferOffsets2EXT(
    VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDescriptorBufferOffsets2EXT(commandBuffer, pSetDescriptorBufferOffsetsInfo);

    PFN_vkCmdSetDescriptorBufferOffsets2EXT pfn = layer_data->dispatch_table.CmdSetDescriptorBufferOffsets2EXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, pSetDescriptorBufferOffsetsInfo);
    }

    layer_data->interceptor->PostCmdSetDescriptorBufferOffsets2EXT(commandBuffer, pSetDescriptorBufferOffsetsInfo);
}

void InterceptCmdBindDescriptorBufferEmbeddedSamplers2EXT(
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

VkResult InterceptCreateDebugReportCallbackEXT(VkInstance instance,
                                               const VkDebugReportCallbackCreateInfoEXT* pCreateInfo,
                                               const VkAllocationCallbacks* pAllocator,
                                               VkDebugReportCallbackEXT* pCallback) {
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

void InterceptDestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback,
                                            const VkAllocationCallbacks* pAllocator) {
    auto layer_data = GetInstanceLayerData(DataKey(instance));
    layer_data->interceptor->PreDestroyDebugReportCallbackEXT(instance, callback, pAllocator);

    PFN_vkDestroyDebugReportCallbackEXT pfn = layer_data->dispatch_table.DestroyDebugReportCallbackEXT;
    if (pfn != nullptr) {
        pfn(instance, callback, pAllocator);
    }

    layer_data->interceptor->PostDestroyDebugReportCallbackEXT(instance, callback, pAllocator);
}

VkResult InterceptDebugMarkerSetObjectNameEXT(VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo) {
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

void InterceptCmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);

    PFN_vkCmdDebugMarkerBeginEXT pfn = layer_data->dispatch_table.CmdDebugMarkerBeginEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, pMarkerInfo);
    }

    layer_data->interceptor->PostCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
}

void InterceptCmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDebugMarkerEndEXT(commandBuffer);

    PFN_vkCmdDebugMarkerEndEXT pfn = layer_data->dispatch_table.CmdDebugMarkerEndEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer);
    }

    layer_data->interceptor->PostCmdDebugMarkerEndEXT(commandBuffer);
}

void InterceptCmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);

    PFN_vkCmdDebugMarkerInsertEXT pfn = layer_data->dispatch_table.CmdDebugMarkerInsertEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, pMarkerInfo);
    }

    layer_data->interceptor->PostCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
}

void InterceptCmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                 uint32_t bindingCount, const VkBuffer* pBuffers,
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

void InterceptCmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                           uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
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

void InterceptCmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                         uint32_t counterBufferCount, const VkBuffer* pCounterBuffers,
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

void InterceptCmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                      VkQueryControlFlags flags, uint32_t index) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);

    PFN_vkCmdBeginQueryIndexedEXT pfn = layer_data->dispatch_table.CmdBeginQueryIndexedEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, queryPool, query, flags, index);
    }

    layer_data->interceptor->PostCmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
}

void InterceptCmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                    uint32_t index) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);

    PFN_vkCmdEndQueryIndexedEXT pfn = layer_data->dispatch_table.CmdEndQueryIndexedEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, queryPool, query, index);
    }

    layer_data->interceptor->PostCmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
}

void InterceptCmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance,
                                          VkBuffer counterBuffer, VkDeviceSize counterBufferOffset,
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

void InterceptCmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);

    PFN_vkCmdCuLaunchKernelNVX pfn = layer_data->dispatch_table.CmdCuLaunchKernelNVX;
    if (pfn != nullptr) {
        pfn(commandBuffer, pLaunchInfo);
    }

    layer_data->interceptor->PostCmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);
}

void InterceptCmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                      VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                      uint32_t stride) {
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

void InterceptCmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                             VkBuffer countBuffer, VkDeviceSize countBufferOffset,
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

void InterceptCmdBeginConditionalRenderingEXT(VkCommandBuffer commandBuffer,
                                              const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);

    PFN_vkCmdBeginConditionalRenderingEXT pfn = layer_data->dispatch_table.CmdBeginConditionalRenderingEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, pConditionalRenderingBegin);
    }

    layer_data->interceptor->PostCmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
}

void InterceptCmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdEndConditionalRenderingEXT(commandBuffer);

    PFN_vkCmdEndConditionalRenderingEXT pfn = layer_data->dispatch_table.CmdEndConditionalRenderingEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer);
    }

    layer_data->interceptor->PostCmdEndConditionalRenderingEXT(commandBuffer);
}

void InterceptCmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
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

void InterceptCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle,
                                        uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) {
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

void InterceptCmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable);

    PFN_vkCmdSetDiscardRectangleEnableEXT pfn = layer_data->dispatch_table.CmdSetDiscardRectangleEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, discardRectangleEnable);
    }

    layer_data->interceptor->PostCmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable);
}

void InterceptCmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer,
                                            VkDiscardRectangleModeEXT discardRectangleMode) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode);

    PFN_vkCmdSetDiscardRectangleModeEXT pfn = layer_data->dispatch_table.CmdSetDiscardRectangleModeEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, discardRectangleMode);
    }

    layer_data->interceptor->PostCmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode);
}

VkResult InterceptSetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo) {
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

void InterceptCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);

    PFN_vkCmdBeginDebugUtilsLabelEXT pfn = layer_data->dispatch_table.CmdBeginDebugUtilsLabelEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, pLabelInfo);
    }

    layer_data->interceptor->PostCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}

void InterceptCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdEndDebugUtilsLabelEXT(commandBuffer);

    PFN_vkCmdEndDebugUtilsLabelEXT pfn = layer_data->dispatch_table.CmdEndDebugUtilsLabelEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer);
    }

    layer_data->interceptor->PostCmdEndDebugUtilsLabelEXT(commandBuffer);
}

void InterceptCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);

    PFN_vkCmdInsertDebugUtilsLabelEXT pfn = layer_data->dispatch_table.CmdInsertDebugUtilsLabelEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, pLabelInfo);
    }

    layer_data->interceptor->PostCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}

VkResult InterceptCreateDebugUtilsMessengerEXT(VkInstance instance,
                                               const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
                                               const VkAllocationCallbacks* pAllocator,
                                               VkDebugUtilsMessengerEXT* pMessenger) {
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

void InterceptDestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT messenger,
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
void InterceptCmdInitializeGraphScratchMemoryAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch) {
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
void InterceptCmdDispatchGraphAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
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
void InterceptCmdDispatchGraphIndirectAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                           const VkDispatchGraphCountInfoAMDX* pCountInfo) {
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
void InterceptCmdDispatchGraphIndirectCountAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
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

void InterceptCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer,
                                       const VkSampleLocationsInfoEXT* pSampleLocationsInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);

    PFN_vkCmdSetSampleLocationsEXT pfn = layer_data->dispatch_table.CmdSetSampleLocationsEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, pSampleLocationsInfo);
    }

    layer_data->interceptor->PostCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
}

void InterceptCmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView,
                                        VkImageLayout imageLayout) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);

    PFN_vkCmdBindShadingRateImageNV pfn = layer_data->dispatch_table.CmdBindShadingRateImageNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, imageView, imageLayout);
    }

    layer_data->interceptor->PostCmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
}

void InterceptCmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                                 uint32_t viewportCount,
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

void InterceptCmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType,
                                        uint32_t customSampleOrderCount,
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

void InterceptCmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo,
                                              VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update,
                                              VkAccelerationStructureNV dst, VkAccelerationStructureNV src,
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

void InterceptCmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst,
                                             VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);

    PFN_vkCmdCopyAccelerationStructureNV pfn = layer_data->dispatch_table.CmdCopyAccelerationStructureNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, dst, src, mode);
    }

    layer_data->interceptor->PostCmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
}

void InterceptCmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer,
                             VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer,
                             VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride,
                             VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset,
                             VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer,
                             VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride,
                             uint32_t width, uint32_t height, uint32_t depth) {
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

void InterceptCmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer,
                                                         uint32_t accelerationStructureCount,
                                                         const VkAccelerationStructureNV* pAccelerationStructures,
                                                         VkQueryType queryType, VkQueryPool queryPool,
                                                         uint32_t firstQuery) {
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

void InterceptCmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                      VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);

    PFN_vkCmdWriteBufferMarkerAMD pfn = layer_data->dispatch_table.CmdWriteBufferMarkerAMD;
    if (pfn != nullptr) {
        pfn(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
    }

    layer_data->interceptor->PostCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
}

void InterceptCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);

    PFN_vkCmdDrawMeshTasksNV pfn = layer_data->dispatch_table.CmdDrawMeshTasksNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, taskCount, firstTask);
    }

    layer_data->interceptor->PostCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
}

void InterceptCmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                         uint32_t drawCount, uint32_t stride) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);

    PFN_vkCmdDrawMeshTasksIndirectNV pfn = layer_data->dispatch_table.CmdDrawMeshTasksIndirectNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, buffer, offset, drawCount, stride);
    }

    layer_data->interceptor->PostCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
}

void InterceptCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                              VkBuffer countBuffer, VkDeviceSize countBufferOffset,
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

void InterceptCmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                             uint32_t exclusiveScissorCount, const VkBool32* pExclusiveScissorEnables) {
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

void InterceptCmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                       uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors) {
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

void InterceptCmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetCheckpointNV(commandBuffer, pCheckpointMarker);

    PFN_vkCmdSetCheckpointNV pfn = layer_data->dispatch_table.CmdSetCheckpointNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, pCheckpointMarker);
    }

    layer_data->interceptor->PostCmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
}

VkResult InterceptCmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer,
                                               const VkPerformanceMarkerInfoINTEL* pMarkerInfo) {
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

VkResult InterceptCmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer,
                                                     const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo) {
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

VkResult InterceptCmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer,
                                                 const VkPerformanceOverrideInfoINTEL* pOverrideInfo) {
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

void InterceptCmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                   uint16_t lineStipplePattern) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);

    PFN_vkCmdSetLineStippleEXT pfn = layer_data->dispatch_table.CmdSetLineStippleEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, lineStippleFactor, lineStipplePattern);
    }

    layer_data->interceptor->PostCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
}

void InterceptCmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetCullModeEXT(commandBuffer, cullMode);

    PFN_vkCmdSetCullModeEXT pfn = layer_data->dispatch_table.CmdSetCullModeEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, cullMode);
    }

    layer_data->interceptor->PostCmdSetCullModeEXT(commandBuffer, cullMode);
}

void InterceptCmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetFrontFaceEXT(commandBuffer, frontFace);

    PFN_vkCmdSetFrontFaceEXT pfn = layer_data->dispatch_table.CmdSetFrontFaceEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, frontFace);
    }

    layer_data->interceptor->PostCmdSetFrontFaceEXT(commandBuffer, frontFace);
}

void InterceptCmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);

    PFN_vkCmdSetPrimitiveTopologyEXT pfn = layer_data->dispatch_table.CmdSetPrimitiveTopologyEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, primitiveTopology);
    }

    layer_data->interceptor->PostCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);
}

void InterceptCmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                         const VkViewport* pViewports) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);

    PFN_vkCmdSetViewportWithCountEXT pfn = layer_data->dispatch_table.CmdSetViewportWithCountEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, viewportCount, pViewports);
    }

    layer_data->interceptor->PostCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);
}

void InterceptCmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                        const VkRect2D* pScissors) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);

    PFN_vkCmdSetScissorWithCountEXT pfn = layer_data->dispatch_table.CmdSetScissorWithCountEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, scissorCount, pScissors);
    }

    layer_data->interceptor->PostCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);
}

void InterceptCmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                       const VkBuffer* pBuffers, const VkDeviceSize* pOffsets,
                                       const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) {
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

void InterceptCmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);

    PFN_vkCmdSetDepthTestEnableEXT pfn = layer_data->dispatch_table.CmdSetDepthTestEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, depthTestEnable);
    }

    layer_data->interceptor->PostCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);
}

void InterceptCmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);

    PFN_vkCmdSetDepthWriteEnableEXT pfn = layer_data->dispatch_table.CmdSetDepthWriteEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, depthWriteEnable);
    }

    layer_data->interceptor->PostCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);
}

void InterceptCmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);

    PFN_vkCmdSetDepthCompareOpEXT pfn = layer_data->dispatch_table.CmdSetDepthCompareOpEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, depthCompareOp);
    }

    layer_data->interceptor->PostCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);
}

void InterceptCmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);

    PFN_vkCmdSetDepthBoundsTestEnableEXT pfn = layer_data->dispatch_table.CmdSetDepthBoundsTestEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, depthBoundsTestEnable);
    }

    layer_data->interceptor->PostCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);
}

void InterceptCmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);

    PFN_vkCmdSetStencilTestEnableEXT pfn = layer_data->dispatch_table.CmdSetStencilTestEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, stencilTestEnable);
    }

    layer_data->interceptor->PostCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);
}

void InterceptCmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp,
                                 VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);

    PFN_vkCmdSetStencilOpEXT pfn = layer_data->dispatch_table.CmdSetStencilOpEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    }

    layer_data->interceptor->PostCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}

void InterceptCmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer,
                                               const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);

    PFN_vkCmdPreprocessGeneratedCommandsNV pfn = layer_data->dispatch_table.CmdPreprocessGeneratedCommandsNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, pGeneratedCommandsInfo);
    }

    layer_data->interceptor->PostCmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);
}

void InterceptCmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                            const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);

    PFN_vkCmdExecuteGeneratedCommandsNV pfn = layer_data->dispatch_table.CmdExecuteGeneratedCommandsNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
    }

    layer_data->interceptor->PostCmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
}

void InterceptCmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                           VkPipeline pipeline, uint32_t groupIndex) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);

    PFN_vkCmdBindPipelineShaderGroupNV pfn = layer_data->dispatch_table.CmdBindPipelineShaderGroupNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
    }

    layer_data->interceptor->PostCmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
}

void InterceptCmdSetDepthBias2EXT(VkCommandBuffer commandBuffer, const VkDepthBiasInfoEXT* pDepthBiasInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthBias2EXT(commandBuffer, pDepthBiasInfo);

    PFN_vkCmdSetDepthBias2EXT pfn = layer_data->dispatch_table.CmdSetDepthBias2EXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, pDepthBiasInfo);
    }

    layer_data->interceptor->PostCmdSetDepthBias2EXT(commandBuffer, pDepthBiasInfo);
}

void InterceptCmdCudaLaunchKernelNV(VkCommandBuffer commandBuffer, const VkCudaLaunchInfoNV* pLaunchInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCudaLaunchKernelNV(commandBuffer, pLaunchInfo);

    PFN_vkCmdCudaLaunchKernelNV pfn = layer_data->dispatch_table.CmdCudaLaunchKernelNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, pLaunchInfo);
    }

    layer_data->interceptor->PostCmdCudaLaunchKernelNV(commandBuffer, pLaunchInfo);
}

void InterceptCmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount,
                                          const VkDescriptorBufferBindingInfoEXT* pBindingInfos) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBindDescriptorBuffersEXT(commandBuffer, bufferCount, pBindingInfos);

    PFN_vkCmdBindDescriptorBuffersEXT pfn = layer_data->dispatch_table.CmdBindDescriptorBuffersEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, bufferCount, pBindingInfos);
    }

    layer_data->interceptor->PostCmdBindDescriptorBuffersEXT(commandBuffer, bufferCount, pBindingInfos);
}

void InterceptCmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                               VkPipelineLayout layout, uint32_t firstSet, uint32_t setCount,
                                               const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets) {
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

void InterceptCmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer commandBuffer,
                                                         VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout,
                                                         uint32_t set) {
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

void InterceptCmdSetFragmentShadingRateEnumNV(VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate,
                                              const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);

    PFN_vkCmdSetFragmentShadingRateEnumNV pfn = layer_data->dispatch_table.CmdSetFragmentShadingRateEnumNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, shadingRate, combinerOps);
    }

    layer_data->interceptor->PostCmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);
}

void InterceptCmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
                                   const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions,
                                   uint32_t vertexAttributeDescriptionCount,
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

void InterceptCmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSubpassShadingHUAWEI(commandBuffer);

    PFN_vkCmdSubpassShadingHUAWEI pfn = layer_data->dispatch_table.CmdSubpassShadingHUAWEI;
    if (pfn != nullptr) {
        pfn(commandBuffer);
    }

    layer_data->interceptor->PostCmdSubpassShadingHUAWEI(commandBuffer);
}

void InterceptCmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer, VkImageView imageView,
                                          VkImageLayout imageLayout) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBindInvocationMaskHUAWEI(commandBuffer, imageView, imageLayout);

    PFN_vkCmdBindInvocationMaskHUAWEI pfn = layer_data->dispatch_table.CmdBindInvocationMaskHUAWEI;
    if (pfn != nullptr) {
        pfn(commandBuffer, imageView, imageLayout);
    }

    layer_data->interceptor->PostCmdBindInvocationMaskHUAWEI(commandBuffer, imageView, imageLayout);
}

void InterceptCmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);

    PFN_vkCmdSetPatchControlPointsEXT pfn = layer_data->dispatch_table.CmdSetPatchControlPointsEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, patchControlPoints);
    }

    layer_data->interceptor->PostCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
}

void InterceptCmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable);

    PFN_vkCmdSetRasterizerDiscardEnableEXT pfn = layer_data->dispatch_table.CmdSetRasterizerDiscardEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, rasterizerDiscardEnable);
    }

    layer_data->interceptor->PostCmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable);
}

void InterceptCmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable);

    PFN_vkCmdSetDepthBiasEnableEXT pfn = layer_data->dispatch_table.CmdSetDepthBiasEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, depthBiasEnable);
    }

    layer_data->interceptor->PostCmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable);
}

void InterceptCmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetLogicOpEXT(commandBuffer, logicOp);

    PFN_vkCmdSetLogicOpEXT pfn = layer_data->dispatch_table.CmdSetLogicOpEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, logicOp);
    }

    layer_data->interceptor->PostCmdSetLogicOpEXT(commandBuffer, logicOp);
}

void InterceptCmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable);

    PFN_vkCmdSetPrimitiveRestartEnableEXT pfn = layer_data->dispatch_table.CmdSetPrimitiveRestartEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, primitiveRestartEnable);
    }

    layer_data->interceptor->PostCmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable);
}

void InterceptCmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                        const VkBool32* pColorWriteEnables) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);

    PFN_vkCmdSetColorWriteEnableEXT pfn = layer_data->dispatch_table.CmdSetColorWriteEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, attachmentCount, pColorWriteEnables);
    }

    layer_data->interceptor->PostCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
}

void InterceptCmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawInfoEXT* pVertexInfo,
                              uint32_t instanceCount, uint32_t firstInstance, uint32_t stride) {
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

void InterceptCmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                     const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount,
                                     uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset) {
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

void InterceptCmdBuildMicromapsEXT(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                   const VkMicromapBuildInfoEXT* pInfos) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBuildMicromapsEXT(commandBuffer, infoCount, pInfos);

    PFN_vkCmdBuildMicromapsEXT pfn = layer_data->dispatch_table.CmdBuildMicromapsEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, infoCount, pInfos);
    }

    layer_data->interceptor->PostCmdBuildMicromapsEXT(commandBuffer, infoCount, pInfos);
}

void InterceptCmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyMicromapEXT(commandBuffer, pInfo);

    PFN_vkCmdCopyMicromapEXT pfn = layer_data->dispatch_table.CmdCopyMicromapEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, pInfo);
    }

    layer_data->interceptor->PostCmdCopyMicromapEXT(commandBuffer, pInfo);
}

void InterceptCmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyMicromapToMemoryEXT(commandBuffer, pInfo);

    PFN_vkCmdCopyMicromapToMemoryEXT pfn = layer_data->dispatch_table.CmdCopyMicromapToMemoryEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, pInfo);
    }

    layer_data->interceptor->PostCmdCopyMicromapToMemoryEXT(commandBuffer, pInfo);
}

void InterceptCmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyMemoryToMicromapEXT(commandBuffer, pInfo);

    PFN_vkCmdCopyMemoryToMicromapEXT pfn = layer_data->dispatch_table.CmdCopyMemoryToMicromapEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, pInfo);
    }

    layer_data->interceptor->PostCmdCopyMemoryToMicromapEXT(commandBuffer, pInfo);
}

void InterceptCmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount,
                                             const VkMicromapEXT* pMicromaps, VkQueryType queryType,
                                             VkQueryPool queryPool, uint32_t firstQuery) {
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

void InterceptCmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                   uint32_t groupCountZ) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawClusterHUAWEI(commandBuffer, groupCountX, groupCountY, groupCountZ);

    PFN_vkCmdDrawClusterHUAWEI pfn = layer_data->dispatch_table.CmdDrawClusterHUAWEI;
    if (pfn != nullptr) {
        pfn(commandBuffer, groupCountX, groupCountY, groupCountZ);
    }

    layer_data->interceptor->PostCmdDrawClusterHUAWEI(commandBuffer, groupCountX, groupCountY, groupCountZ);
}

void InterceptCmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawClusterIndirectHUAWEI(commandBuffer, buffer, offset);

    PFN_vkCmdDrawClusterIndirectHUAWEI pfn = layer_data->dispatch_table.CmdDrawClusterIndirectHUAWEI;
    if (pfn != nullptr) {
        pfn(commandBuffer, buffer, offset);
    }

    layer_data->interceptor->PostCmdDrawClusterIndirectHUAWEI(commandBuffer, buffer, offset);
}

void InterceptCmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                      uint32_t copyCount, uint32_t stride) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyMemoryIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride);

    PFN_vkCmdCopyMemoryIndirectNV pfn = layer_data->dispatch_table.CmdCopyMemoryIndirectNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, copyBufferAddress, copyCount, stride);
    }

    layer_data->interceptor->PostCmdCopyMemoryIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride);
}

void InterceptCmdCopyMemoryToImageIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                             uint32_t copyCount, uint32_t stride, VkImage dstImage,
                                             VkImageLayout dstImageLayout,
                                             const VkImageSubresourceLayers* pImageSubresources) {
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

void InterceptCmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount,
                                    const VkDecompressMemoryRegionNV* pDecompressMemoryRegions) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDecompressMemoryNV(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);

    PFN_vkCmdDecompressMemoryNV pfn = layer_data->dispatch_table.CmdDecompressMemoryNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
    }

    layer_data->interceptor->PostCmdDecompressMemoryNV(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
}

void InterceptCmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer, VkDeviceAddress indirectCommandsAddress,
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

void InterceptCmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                VkPipeline pipeline) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdUpdatePipelineIndirectBufferNV(commandBuffer, pipelineBindPoint, pipeline);

    PFN_vkCmdUpdatePipelineIndirectBufferNV pfn = layer_data->dispatch_table.CmdUpdatePipelineIndirectBufferNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, pipelineBindPoint, pipeline);
    }

    layer_data->interceptor->PostCmdUpdatePipelineIndirectBufferNV(commandBuffer, pipelineBindPoint, pipeline);
}

void InterceptCmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClampEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthClampEnableEXT(commandBuffer, depthClampEnable);

    PFN_vkCmdSetDepthClampEnableEXT pfn = layer_data->dispatch_table.CmdSetDepthClampEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, depthClampEnable);
    }

    layer_data->interceptor->PostCmdSetDepthClampEnableEXT(commandBuffer, depthClampEnable);
}

void InterceptCmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetPolygonModeEXT(commandBuffer, polygonMode);

    PFN_vkCmdSetPolygonModeEXT pfn = layer_data->dispatch_table.CmdSetPolygonModeEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, polygonMode);
    }

    layer_data->interceptor->PostCmdSetPolygonModeEXT(commandBuffer, polygonMode);
}

void InterceptCmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits rasterizationSamples) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetRasterizationSamplesEXT(commandBuffer, rasterizationSamples);

    PFN_vkCmdSetRasterizationSamplesEXT pfn = layer_data->dispatch_table.CmdSetRasterizationSamplesEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, rasterizationSamples);
    }

    layer_data->interceptor->PostCmdSetRasterizationSamplesEXT(commandBuffer, rasterizationSamples);
}

void InterceptCmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples,
                                  const VkSampleMask* pSampleMask) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetSampleMaskEXT(commandBuffer, samples, pSampleMask);

    PFN_vkCmdSetSampleMaskEXT pfn = layer_data->dispatch_table.CmdSetSampleMaskEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, samples, pSampleMask);
    }

    layer_data->interceptor->PostCmdSetSampleMaskEXT(commandBuffer, samples, pSampleMask);
}

void InterceptCmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetAlphaToCoverageEnableEXT(commandBuffer, alphaToCoverageEnable);

    PFN_vkCmdSetAlphaToCoverageEnableEXT pfn = layer_data->dispatch_table.CmdSetAlphaToCoverageEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, alphaToCoverageEnable);
    }

    layer_data->interceptor->PostCmdSetAlphaToCoverageEnableEXT(commandBuffer, alphaToCoverageEnable);
}

void InterceptCmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetAlphaToOneEnableEXT(commandBuffer, alphaToOneEnable);

    PFN_vkCmdSetAlphaToOneEnableEXT pfn = layer_data->dispatch_table.CmdSetAlphaToOneEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, alphaToOneEnable);
    }

    layer_data->interceptor->PostCmdSetAlphaToOneEnableEXT(commandBuffer, alphaToOneEnable);
}

void InterceptCmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetLogicOpEnableEXT(commandBuffer, logicOpEnable);

    PFN_vkCmdSetLogicOpEnableEXT pfn = layer_data->dispatch_table.CmdSetLogicOpEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, logicOpEnable);
    }

    layer_data->interceptor->PostCmdSetLogicOpEnableEXT(commandBuffer, logicOpEnable);
}

void InterceptCmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                        uint32_t attachmentCount, const VkBool32* pColorBlendEnables) {
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

void InterceptCmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                          uint32_t attachmentCount,
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

void InterceptCmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
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

void InterceptCmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer,
                                                VkTessellationDomainOrigin domainOrigin) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetTessellationDomainOriginEXT(commandBuffer, domainOrigin);

    PFN_vkCmdSetTessellationDomainOriginEXT pfn = layer_data->dispatch_table.CmdSetTessellationDomainOriginEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, domainOrigin);
    }

    layer_data->interceptor->PostCmdSetTessellationDomainOriginEXT(commandBuffer, domainOrigin);
}

void InterceptCmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer, uint32_t rasterizationStream) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetRasterizationStreamEXT(commandBuffer, rasterizationStream);

    PFN_vkCmdSetRasterizationStreamEXT pfn = layer_data->dispatch_table.CmdSetRasterizationStreamEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, rasterizationStream);
    }

    layer_data->interceptor->PostCmdSetRasterizationStreamEXT(commandBuffer, rasterizationStream);
}

void InterceptCmdSetConservativeRasterizationModeEXT(VkCommandBuffer commandBuffer,
                                                     VkConservativeRasterizationModeEXT conservativeRasterizationMode) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetConservativeRasterizationModeEXT(commandBuffer, conservativeRasterizationMode);

    PFN_vkCmdSetConservativeRasterizationModeEXT pfn =
        layer_data->dispatch_table.CmdSetConservativeRasterizationModeEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, conservativeRasterizationMode);
    }

    layer_data->interceptor->PostCmdSetConservativeRasterizationModeEXT(commandBuffer, conservativeRasterizationMode);
}

void InterceptCmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer commandBuffer,
                                                        float extraPrimitiveOverestimationSize) {
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

void InterceptCmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClipEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthClipEnableEXT(commandBuffer, depthClipEnable);

    PFN_vkCmdSetDepthClipEnableEXT pfn = layer_data->dispatch_table.CmdSetDepthClipEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, depthClipEnable);
    }

    layer_data->interceptor->PostCmdSetDepthClipEnableEXT(commandBuffer, depthClipEnable);
}

void InterceptCmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetSampleLocationsEnableEXT(commandBuffer, sampleLocationsEnable);

    PFN_vkCmdSetSampleLocationsEnableEXT pfn = layer_data->dispatch_table.CmdSetSampleLocationsEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, sampleLocationsEnable);
    }

    layer_data->interceptor->PostCmdSetSampleLocationsEnableEXT(commandBuffer, sampleLocationsEnable);
}

void InterceptCmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                          uint32_t attachmentCount,
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

void InterceptCmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer,
                                           VkProvokingVertexModeEXT provokingVertexMode) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetProvokingVertexModeEXT(commandBuffer, provokingVertexMode);

    PFN_vkCmdSetProvokingVertexModeEXT pfn = layer_data->dispatch_table.CmdSetProvokingVertexModeEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, provokingVertexMode);
    }

    layer_data->interceptor->PostCmdSetProvokingVertexModeEXT(commandBuffer, provokingVertexMode);
}

void InterceptCmdSetLineRasterizationModeEXT(VkCommandBuffer commandBuffer,
                                             VkLineRasterizationModeEXT lineRasterizationMode) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetLineRasterizationModeEXT(commandBuffer, lineRasterizationMode);

    PFN_vkCmdSetLineRasterizationModeEXT pfn = layer_data->dispatch_table.CmdSetLineRasterizationModeEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, lineRasterizationMode);
    }

    layer_data->interceptor->PostCmdSetLineRasterizationModeEXT(commandBuffer, lineRasterizationMode);
}

void InterceptCmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetLineStippleEnableEXT(commandBuffer, stippledLineEnable);

    PFN_vkCmdSetLineStippleEnableEXT pfn = layer_data->dispatch_table.CmdSetLineStippleEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, stippledLineEnable);
    }

    layer_data->interceptor->PostCmdSetLineStippleEnableEXT(commandBuffer, stippledLineEnable);
}

void InterceptCmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetDepthClipNegativeOneToOneEXT(commandBuffer, negativeOneToOne);

    PFN_vkCmdSetDepthClipNegativeOneToOneEXT pfn = layer_data->dispatch_table.CmdSetDepthClipNegativeOneToOneEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, negativeOneToOne);
    }

    layer_data->interceptor->PostCmdSetDepthClipNegativeOneToOneEXT(commandBuffer, negativeOneToOne);
}

void InterceptCmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetViewportWScalingEnableNV(commandBuffer, viewportWScalingEnable);

    PFN_vkCmdSetViewportWScalingEnableNV pfn = layer_data->dispatch_table.CmdSetViewportWScalingEnableNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, viewportWScalingEnable);
    }

    layer_data->interceptor->PostCmdSetViewportWScalingEnableNV(commandBuffer, viewportWScalingEnable);
}

void InterceptCmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
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

void InterceptCmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetCoverageToColorEnableNV(commandBuffer, coverageToColorEnable);

    PFN_vkCmdSetCoverageToColorEnableNV pfn = layer_data->dispatch_table.CmdSetCoverageToColorEnableNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, coverageToColorEnable);
    }

    layer_data->interceptor->PostCmdSetCoverageToColorEnableNV(commandBuffer, coverageToColorEnable);
}

void InterceptCmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetCoverageToColorLocationNV(commandBuffer, coverageToColorLocation);

    PFN_vkCmdSetCoverageToColorLocationNV pfn = layer_data->dispatch_table.CmdSetCoverageToColorLocationNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, coverageToColorLocation);
    }

    layer_data->interceptor->PostCmdSetCoverageToColorLocationNV(commandBuffer, coverageToColorLocation);
}

void InterceptCmdSetCoverageModulationModeNV(VkCommandBuffer commandBuffer,
                                             VkCoverageModulationModeNV coverageModulationMode) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetCoverageModulationModeNV(commandBuffer, coverageModulationMode);

    PFN_vkCmdSetCoverageModulationModeNV pfn = layer_data->dispatch_table.CmdSetCoverageModulationModeNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, coverageModulationMode);
    }

    layer_data->interceptor->PostCmdSetCoverageModulationModeNV(commandBuffer, coverageModulationMode);
}

void InterceptCmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer,
                                                    VkBool32 coverageModulationTableEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetCoverageModulationTableEnableNV(commandBuffer, coverageModulationTableEnable);

    PFN_vkCmdSetCoverageModulationTableEnableNV pfn = layer_data->dispatch_table.CmdSetCoverageModulationTableEnableNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, coverageModulationTableEnable);
    }

    layer_data->interceptor->PostCmdSetCoverageModulationTableEnableNV(commandBuffer, coverageModulationTableEnable);
}

void InterceptCmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount,
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

void InterceptCmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetShadingRateImageEnableNV(commandBuffer, shadingRateImageEnable);

    PFN_vkCmdSetShadingRateImageEnableNV pfn = layer_data->dispatch_table.CmdSetShadingRateImageEnableNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, shadingRateImageEnable);
    }

    layer_data->interceptor->PostCmdSetShadingRateImageEnableNV(commandBuffer, shadingRateImageEnable);
}

void InterceptCmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer commandBuffer,
                                                       VkBool32 representativeFragmentTestEnable) {
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

void InterceptCmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer,
                                            VkCoverageReductionModeNV coverageReductionMode) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetCoverageReductionModeNV(commandBuffer, coverageReductionMode);

    PFN_vkCmdSetCoverageReductionModeNV pfn = layer_data->dispatch_table.CmdSetCoverageReductionModeNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, coverageReductionMode);
    }

    layer_data->interceptor->PostCmdSetCoverageReductionModeNV(commandBuffer, coverageReductionMode);
}

void InterceptCmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session,
                                      const VkOpticalFlowExecuteInfoNV* pExecuteInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdOpticalFlowExecuteNV(commandBuffer, session, pExecuteInfo);

    PFN_vkCmdOpticalFlowExecuteNV pfn = layer_data->dispatch_table.CmdOpticalFlowExecuteNV;
    if (pfn != nullptr) {
        pfn(commandBuffer, session, pExecuteInfo);
    }

    layer_data->interceptor->PostCmdOpticalFlowExecuteNV(commandBuffer, session, pExecuteInfo);
}

void InterceptCmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount,
                                const VkShaderStageFlagBits* pStages, const VkShaderEXT* pShaders) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdBindShadersEXT(commandBuffer, stageCount, pStages, pShaders);

    PFN_vkCmdBindShadersEXT pfn = layer_data->dispatch_table.CmdBindShadersEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, stageCount, pStages, pShaders);
    }

    layer_data->interceptor->PostCmdBindShadersEXT(commandBuffer, stageCount, pStages, pShaders);
}

void InterceptCmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer, VkImageAspectFlags aspectMask) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetAttachmentFeedbackLoopEnableEXT(commandBuffer, aspectMask);

    PFN_vkCmdSetAttachmentFeedbackLoopEnableEXT pfn = layer_data->dispatch_table.CmdSetAttachmentFeedbackLoopEnableEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, aspectMask);
    }

    layer_data->interceptor->PostCmdSetAttachmentFeedbackLoopEnableEXT(commandBuffer, aspectMask);
}

void InterceptCmdBuildAccelerationStructuresKHR(
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

void InterceptCmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                                        const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
                                                        const VkDeviceAddress* pIndirectDeviceAddresses,
                                                        const uint32_t* pIndirectStrides,
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

void InterceptCmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                              const VkCopyAccelerationStructureInfoKHR* pInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyAccelerationStructureKHR(commandBuffer, pInfo);

    PFN_vkCmdCopyAccelerationStructureKHR pfn = layer_data->dispatch_table.CmdCopyAccelerationStructureKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pInfo);
    }

    layer_data->interceptor->PostCmdCopyAccelerationStructureKHR(commandBuffer, pInfo);
}

void InterceptCmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer commandBuffer,
                                                      const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);

    PFN_vkCmdCopyAccelerationStructureToMemoryKHR pfn =
        layer_data->dispatch_table.CmdCopyAccelerationStructureToMemoryKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pInfo);
    }

    layer_data->interceptor->PostCmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);
}

void InterceptCmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                                      const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);

    PFN_vkCmdCopyMemoryToAccelerationStructureKHR pfn =
        layer_data->dispatch_table.CmdCopyMemoryToAccelerationStructureKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pInfo);
    }

    layer_data->interceptor->PostCmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);
}

void InterceptCmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer commandBuffer,
                                                          uint32_t accelerationStructureCount,
                                                          const VkAccelerationStructureKHR* pAccelerationStructures,
                                                          VkQueryType queryType, VkQueryPool queryPool,
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

void InterceptCmdTraceRaysKHR(VkCommandBuffer commandBuffer,
                              const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                              const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                              const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                              const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width,
                              uint32_t height, uint32_t depth) {
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

void InterceptCmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer,
                                      const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                      const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                      const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                      const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                      VkDeviceAddress indirectDeviceAddress) {
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

void InterceptCmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);

    PFN_vkCmdSetRayTracingPipelineStackSizeKHR pfn = layer_data->dispatch_table.CmdSetRayTracingPipelineStackSizeKHR;
    if (pfn != nullptr) {
        pfn(commandBuffer, pipelineStackSize);
    }

    layer_data->interceptor->PostCmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);
}

void InterceptCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                  uint32_t groupCountZ) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawMeshTasksEXT(commandBuffer, groupCountX, groupCountY, groupCountZ);

    PFN_vkCmdDrawMeshTasksEXT pfn = layer_data->dispatch_table.CmdDrawMeshTasksEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, groupCountX, groupCountY, groupCountZ);
    }

    layer_data->interceptor->PostCmdDrawMeshTasksEXT(commandBuffer, groupCountX, groupCountY, groupCountZ);
}

void InterceptCmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                          uint32_t drawCount, uint32_t stride) {
    auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
    layer_data->interceptor->PreCmdDrawMeshTasksIndirectEXT(commandBuffer, buffer, offset, drawCount, stride);

    PFN_vkCmdDrawMeshTasksIndirectEXT pfn = layer_data->dispatch_table.CmdDrawMeshTasksIndirectEXT;
    if (pfn != nullptr) {
        pfn(commandBuffer, buffer, offset, drawCount, stride);
    }

    layer_data->interceptor->PostCmdDrawMeshTasksIndirectEXT(commandBuffer, buffer, offset, drawCount, stride);
}

void InterceptCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                               VkBuffer countBuffer, VkDeviceSize countBufferOffset,
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

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL PassInstanceProcDownTheChain(VkInstance inst, const char* func) {
    // Get the instance data.
    auto id = GetInstanceLayerData(DataKey(inst));
    // Pass down the instance proc address call through the chain.
    return (PFN_vkVoidFunction)id->pfn_next_instance_proc_addr(inst, func);
}

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL PassDeviceProcDownTheChain(VkDevice dev, const char* func) {
    // Get the device data.
    auto dd = GetDeviceLayerData(DataKey(dev));
    // Pass down the device proc address call through the chain.
    return (PFN_vkVoidFunction)dd->pfn_next_device_proc_addr(dev, func);
}

/*****************************************************************************/
/*                         Custom Intercept Functions                        */
/*****************************************************************************/

VkResult InterceptCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                                 VkInstance* pInstance) {
    // Find the create info
    VkLayerInstanceCreateInfo* layer_create_info = GetLoaderInstanceInfo(pCreateInfo, VK_LAYER_LINK_INFO);
    if (layer_create_info == NULL) {
        // No loader instance create info
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    PFN_vkGetInstanceProcAddr pfn_get_instance_proc_addr = layer_create_info->u.pLayerInfo->pfnNextGetInstanceProcAddr;
    PFN_vkCreateInstance pfn_create_instance =
        (PFN_vkCreateInstance)pfn_get_instance_proc_addr(NULL, "vkCreateInstance");
    if (pfn_create_instance == NULL) return VK_ERROR_INITIALIZATION_FAILED;

    // Move chain on for the next layer.
    layer_create_info->u.pLayerInfo = layer_create_info->u.pLayerInfo->pNext;

    Interceptor* interceptor = nullptr;
    auto result = CreateInstance(pCreateInfo, pAllocator, pInstance, &interceptor);
    if (result != VK_SUCCESS) {
        return result;
    }

    const VkInstanceCreateInfo* pFinalCreateInfo = interceptor->GetModifiedInstanceCreateInfo(pCreateInfo);

    result = pfn_create_instance(pFinalCreateInfo, pAllocator, pInstance);
    if (VK_SUCCESS != result) {
        return result;
    }

    auto id = std::make_unique<InstanceData>();
    id->instance = *pInstance;
    id->interceptor = interceptor;
    auto chain_info = GetLoaderInstanceInfo(pFinalCreateInfo, VK_LOADER_DATA_CALLBACK);
    id->pfn_set_instance_loader_data = chain_info->u.pfnSetInstanceLoaderData;
    id->pfn_next_instance_proc_addr = pfn_get_instance_proc_addr;
    InitInstanceDispatchTable(*pInstance, pfn_get_instance_proc_addr, &id->dispatch_table);

    {
        std::lock_guard<std::mutex> lock(g_instance_mutex);
        g_instance_data[DataKey(*pInstance)] = std::move(id);
    }

    result = interceptor->PostCreateInstance(pFinalCreateInfo, pAllocator, pInstance, result);

    return result;
}

void InterceptDestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator) {
    auto instance_key = DataKey(instance);
    InstanceData* instance_data = GetInstanceLayerData(instance_key);

    instance_data->interceptor->PreDestroyInstance(instance, pAllocator);

    auto pfn_destroy_instance = instance_data->dispatch_table.DestroyInstance;
    pfn_destroy_instance(instance, pAllocator);
    delete instance_data->interceptor;
    FreeInstanceLayerData(instance_key);
}

VkResult InterceptCreateDevice(VkPhysicalDevice gpu, const VkDeviceCreateInfo* pCreateInfo,
                               const VkAllocationCallbacks* pAllocator, VkDevice* pDevice) {
    VkLayerDeviceCreateInfo* layer_create_info = GetLoaderDeviceInfo(pCreateInfo, VK_LAYER_LINK_INFO);

    // Get the instance data.
    auto instance_data = GetInstanceLayerData(DataKey(gpu));

    // Get the proc addr pointers for this layer and update the chain for the next
    // layer.
    PFN_vkGetInstanceProcAddr pfn_next_instance_proc_addr = layer_create_info->u.pLayerInfo->pfnNextGetInstanceProcAddr;
    PFN_vkGetDeviceProcAddr pfn_next_device_proc_addr = layer_create_info->u.pLayerInfo->pfnNextGetDeviceProcAddr;
    PFN_vkCreateDevice pfn_create_device =
        (PFN_vkCreateDevice)pfn_next_instance_proc_addr(instance_data->instance, "vkCreateDevice");
    layer_create_info->u.pLayerInfo = layer_create_info->u.pLayerInfo->pNext;

    const VkDeviceCreateInfo* pFinalCreateInfo =
        instance_data->interceptor->GetModifiedDeviceCreateInfo(gpu, pCreateInfo);

    auto result = pfn_create_device(gpu, pFinalCreateInfo, pAllocator, pDevice);
    if (VK_SUCCESS != result) {
        return result;
    }

    auto dd = std::make_unique<DeviceData>();
    dd->device = *pDevice;
    dd->interceptor = instance_data->interceptor;
    auto chain_info = GetLoaderDeviceInfo(pFinalCreateInfo, VK_LOADER_DATA_CALLBACK);
    dd->pfn_set_device_loader_data = chain_info->u.pfnSetDeviceLoaderData;
    dd->pfn_next_device_proc_addr = pfn_next_device_proc_addr;
    InitDeviceDispatchTable(*pDevice, pfn_next_device_proc_addr, &dd->dispatch_table);
    {
        std::lock_guard<std::mutex> lock(g_device_mutex);
        g_device_data[DataKey(*pDevice)] = std::move(dd);
    }

    result = instance_data->interceptor->PostCreateDevice(gpu, pFinalCreateInfo, pAllocator, pDevice, result);

    return result;
}

void InterceptDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator) {
    auto device_key = DataKey(device);
    DeviceData* device_data = GetDeviceLayerData(device_key);
    device_data->interceptor->PreDestroyDevice(device, pAllocator);
    auto pfn_destroy_device = device_data->dispatch_table.DestroyDevice;
    pfn_destroy_device(device, pAllocator);
    device_data->interceptor->PostDestroyDevice(device, pAllocator);

    FreeDeviceLayerData(device_key);
}

VkResult InterceptQueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(queue));
    return layer_data->interceptor->QueueSubmit(queue, submitCount, pSubmits, fence);
}

VkResult InterceptQueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo,
                                  VkFence fence) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(queue));
    return layer_data->interceptor->QueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
}

VkResult InterceptQueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(queue));
    return layer_data->interceptor->QueueSubmit2(queue, submitCount, pSubmits, fence);
}

VkResult InterceptQueueSubmit2KHR(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) {
    VkResult result = VK_SUCCESS;

    auto layer_data = GetDeviceLayerData(DataKey(queue));
    return layer_data->interceptor->QueueSubmit2(queue, submitCount, pSubmits, fence);
}

VkResult InterceptEnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties) {
    VkResult result = VK_SUCCESS;
    uint32_t copy_count = *pPropertyCount;
    if (pProperties != nullptr && *pPropertyCount > 0) {
        *pProperties = kLayerProperties;
    }
    *pPropertyCount = 1;
    return result;
}

VkResult InterceptEnumerateDeviceLayerProperties(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount,
                                                 VkLayerProperties* pProperties) {
    (void)physicalDevice;
    VkResult result = VK_SUCCESS;
    uint32_t copy_count = *pPropertyCount;
    if (pProperties != nullptr && *pPropertyCount > 0) {
        *pProperties = kLayerProperties;
    }
    *pPropertyCount = 1;
    return result;
}

VkResult InterceptEnumerateInstanceExtensionProperties(const char* pLayerName, uint32_t* pPropertyCount,
                                                       VkExtensionProperties* pProperties) {
    bool layer_requested = (nullptr == pLayerName || !strcmp(pLayerName, kLayerProperties.layerName));
    if (!layer_requested) {
        return VK_ERROR_LAYER_NOT_PRESENT;
    }
    if (nullptr == pProperties) {
        *pPropertyCount += static_cast<uint32_t>(instance_extensions.size());
        return VK_SUCCESS;
    } else if (*pPropertyCount > 0) {
        *pPropertyCount = static_cast<uint32_t>(instance_extensions.size());
        memcpy(pProperties, instance_extensions.data(), instance_extensions.size() * sizeof(VkExtensionProperties));
    }
    VkResult result = VK_SUCCESS;

    return result;
}

VkResult InterceptEnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, const char* pLayerName,
                                                     uint32_t* pPropertyCount, VkExtensionProperties* pProperties) {
    // we want to append our extensions, removing duplicates.
    InstanceData* instance_data = GetInstanceLayerData(DataKey(physicalDevice));

    uint32_t num_other_extensions = 0;
    VkResult result = instance_data->dispatch_table.EnumerateDeviceExtensionProperties(physicalDevice, nullptr,
                                                                                       &num_other_extensions, nullptr);
    if (result != VK_SUCCESS) {
        return result;
    }

    // call down to get other device properties
    std::vector<VkExtensionProperties> extensions(num_other_extensions);
    result = instance_data->dispatch_table.EnumerateDeviceExtensionProperties(physicalDevice, pLayerName,
                                                                              &num_other_extensions, &extensions[0]);

    // add our extensions if we have any and requested
    bool layer_requested = (nullptr == pLayerName || !strcmp(pLayerName, kLayerProperties.layerName));

    if (result == VK_SUCCESS && layer_requested) {
        // not just our layer, we expose all our extensions
        uint32_t max_extensions = *pPropertyCount;

        // set and copy base extensions
        *pPropertyCount = num_other_extensions;

        // find our unique extensions that need to be added
        uint32_t num_additional_extensions = 0;
        auto num_device_extensions = device_extensions.size();
        std::vector<const VkExtensionProperties*> additional_extensions(num_device_extensions);

        for (size_t i = 0; i < num_device_extensions; ++i) {
            bool is_unique_extension = true;

            for (size_t j = 0; j < num_other_extensions; ++j) {
                if (0 == strcmp(extensions[j].extensionName, device_extensions[i].extensionName)) {
                    is_unique_extension = false;
                    break;
                }
            }

            if (is_unique_extension) {
                additional_extensions[num_additional_extensions++] = &device_extensions[i];
            }
        }

        // null properties, just count total extensions
        if (nullptr == pProperties) {
            *pPropertyCount += num_additional_extensions;
        } else {
            uint32_t numExtensions = std::min(num_other_extensions, max_extensions);

            memcpy(pProperties, &extensions[0], numExtensions * sizeof(VkExtensionProperties));

            for (size_t i = 0; i < num_additional_extensions && numExtensions < max_extensions; ++i) {
                pProperties[numExtensions++] = *additional_extensions[i];
            }

            *pPropertyCount = numExtensions;

            // not enough space for all extensions
            if (num_other_extensions + num_additional_extensions > max_extensions) {
                result = VK_INCOMPLETE;
            }
        }
    }

    result = instance_data->interceptor->PostEnumerateDeviceExtensionProperties(physicalDevice, pLayerName,
                                                                                pPropertyCount, pProperties, result);

    return result;
}

VkResult InterceptGetPhysicalDeviceToolProperties(VkPhysicalDevice physicalDevice, uint32_t* pToolCount,
                                                  VkPhysicalDeviceToolProperties* pToolProperties) {
    InstanceData* instance_data = GetInstanceLayerData(DataKey(physicalDevice));
    VkResult result = VK_SUCCESS;
    if (pToolProperties != nullptr && *pToolCount > 0) {
        *pToolProperties = kToolProperties;
        pToolProperties = ((*pToolCount > 1) ? &pToolProperties[1] : nullptr);
        (*pToolCount)--;
    }
    if (instance_data->dispatch_table.GetPhysicalDeviceToolProperties == nullptr) {
        // This layer is the terminator.
        *pToolCount = 0;
    } else {
        result =
            instance_data->dispatch_table.GetPhysicalDeviceToolProperties(physicalDevice, pToolCount, pToolProperties);
    }
    return result;
}

VkResult InterceptGetPhysicalDeviceToolPropertiesEXT(VkPhysicalDevice physicalDevice, uint32_t* pToolCount,
                                                     VkPhysicalDeviceToolProperties* pToolProperties) {
    InstanceData* instance_data = GetInstanceLayerData(DataKey(physicalDevice));
    VkResult result = VK_SUCCESS;
    if (pToolProperties != nullptr && *pToolCount > 0) {
        *pToolProperties = kToolProperties;
        pToolProperties = ((*pToolCount > 1) ? &pToolProperties[1] : nullptr);
        (*pToolCount)--;
    }
    if (instance_data->dispatch_table.GetPhysicalDeviceToolPropertiesEXT == nullptr) {
        // This layer is the terminator.
        *pToolCount = 0;
    } else {
        result = instance_data->dispatch_table.GetPhysicalDeviceToolPropertiesEXT(physicalDevice, pToolCount,
                                                                                  pToolProperties);
    }
    return result;
}

PFN_vkVoidFunction GetInstanceFuncs(const char* func) {
    if (0 == strcmp(func, "vkCreateInstance")) return (PFN_vkVoidFunction)InterceptCreateInstance;
    if (0 == strcmp(func, "vkDestroyInstance")) return (PFN_vkVoidFunction)InterceptDestroyInstance;
    if (0 == strcmp(func, "vkCreateDevice")) return (PFN_vkVoidFunction)InterceptCreateDevice;
    if (0 == strcmp(func, "vkEnumerateInstanceExtensionProperties"))
        return (PFN_vkVoidFunction)InterceptEnumerateInstanceExtensionProperties;
    if (0 == strcmp(func, "vkEnumerateDeviceExtensionProperties"))
        return (PFN_vkVoidFunction)InterceptEnumerateDeviceExtensionProperties;
    if (0 == strcmp(func, "vkEnumerateInstanceLayerProperties"))
        return (PFN_vkVoidFunction)InterceptEnumerateInstanceLayerProperties;
    if (0 == strcmp(func, "vkEnumerateDeviceLayerProperties"))
        return (PFN_vkVoidFunction)InterceptEnumerateDeviceLayerProperties;
    if (0 == strcmp(func, "vkGetPhysicalDeviceToolProperties"))
        return (PFN_vkVoidFunction)InterceptGetPhysicalDeviceToolProperties;
    if (0 == strcmp(func, "vkGetPhysicalDeviceToolPropertiesEXT"))
        return (PFN_vkVoidFunction)InterceptGetPhysicalDeviceToolPropertiesEXT;

    return nullptr;
}

PFN_vkVoidFunction GetDeviceFuncs(const char* func) {
    if (0 == strcmp(func, "vkDestroyDevice")) return (PFN_vkVoidFunction)InterceptDestroyDevice;
    if (0 == strcmp(func, "vkGetDeviceQueue")) return (PFN_vkVoidFunction)InterceptGetDeviceQueue;
    if (0 == strcmp(func, "vkQueueSubmit")) return (PFN_vkVoidFunction)InterceptQueueSubmit;
    if (0 == strcmp(func, "vkQueueWaitIdle")) return (PFN_vkVoidFunction)InterceptQueueWaitIdle;
    if (0 == strcmp(func, "vkDeviceWaitIdle")) return (PFN_vkVoidFunction)InterceptDeviceWaitIdle;
    if (0 == strcmp(func, "vkQueueBindSparse")) return (PFN_vkVoidFunction)InterceptQueueBindSparse;
    if (0 == strcmp(func, "vkGetFenceStatus")) return (PFN_vkVoidFunction)InterceptGetFenceStatus;
    if (0 == strcmp(func, "vkWaitForFences")) return (PFN_vkVoidFunction)InterceptWaitForFences;
    if (0 == strcmp(func, "vkCreateSemaphore")) return (PFN_vkVoidFunction)InterceptCreateSemaphore;
    if (0 == strcmp(func, "vkDestroySemaphore")) return (PFN_vkVoidFunction)InterceptDestroySemaphore;
    if (0 == strcmp(func, "vkGetQueryPoolResults")) return (PFN_vkVoidFunction)InterceptGetQueryPoolResults;
    if (0 == strcmp(func, "vkCreateShaderModule")) return (PFN_vkVoidFunction)InterceptCreateShaderModule;
    if (0 == strcmp(func, "vkDestroyShaderModule")) return (PFN_vkVoidFunction)InterceptDestroyShaderModule;
    if (0 == strcmp(func, "vkCreateGraphicsPipelines")) return (PFN_vkVoidFunction)InterceptCreateGraphicsPipelines;
    if (0 == strcmp(func, "vkCreateComputePipelines")) return (PFN_vkVoidFunction)InterceptCreateComputePipelines;
    if (0 == strcmp(func, "vkDestroyPipeline")) return (PFN_vkVoidFunction)InterceptDestroyPipeline;
    if (0 == strcmp(func, "vkCreateCommandPool")) return (PFN_vkVoidFunction)InterceptCreateCommandPool;
    if (0 == strcmp(func, "vkDestroyCommandPool")) return (PFN_vkVoidFunction)InterceptDestroyCommandPool;
    if (0 == strcmp(func, "vkResetCommandPool")) return (PFN_vkVoidFunction)InterceptResetCommandPool;
    if (0 == strcmp(func, "vkAllocateCommandBuffers")) return (PFN_vkVoidFunction)InterceptAllocateCommandBuffers;
    if (0 == strcmp(func, "vkFreeCommandBuffers")) return (PFN_vkVoidFunction)InterceptFreeCommandBuffers;
    if (0 == strcmp(func, "vkBeginCommandBuffer")) return (PFN_vkVoidFunction)InterceptBeginCommandBuffer;
    if (0 == strcmp(func, "vkEndCommandBuffer")) return (PFN_vkVoidFunction)InterceptEndCommandBuffer;
    if (0 == strcmp(func, "vkResetCommandBuffer")) return (PFN_vkVoidFunction)InterceptResetCommandBuffer;
    if (0 == strcmp(func, "vkCmdBindPipeline")) return (PFN_vkVoidFunction)InterceptCmdBindPipeline;
    if (0 == strcmp(func, "vkCmdSetViewport")) return (PFN_vkVoidFunction)InterceptCmdSetViewport;
    if (0 == strcmp(func, "vkCmdSetScissor")) return (PFN_vkVoidFunction)InterceptCmdSetScissor;
    if (0 == strcmp(func, "vkCmdSetLineWidth")) return (PFN_vkVoidFunction)InterceptCmdSetLineWidth;
    if (0 == strcmp(func, "vkCmdSetDepthBias")) return (PFN_vkVoidFunction)InterceptCmdSetDepthBias;
    if (0 == strcmp(func, "vkCmdSetBlendConstants")) return (PFN_vkVoidFunction)InterceptCmdSetBlendConstants;
    if (0 == strcmp(func, "vkCmdSetDepthBounds")) return (PFN_vkVoidFunction)InterceptCmdSetDepthBounds;
    if (0 == strcmp(func, "vkCmdSetStencilCompareMask")) return (PFN_vkVoidFunction)InterceptCmdSetStencilCompareMask;
    if (0 == strcmp(func, "vkCmdSetStencilWriteMask")) return (PFN_vkVoidFunction)InterceptCmdSetStencilWriteMask;
    if (0 == strcmp(func, "vkCmdSetStencilReference")) return (PFN_vkVoidFunction)InterceptCmdSetStencilReference;
    if (0 == strcmp(func, "vkCmdBindDescriptorSets")) return (PFN_vkVoidFunction)InterceptCmdBindDescriptorSets;
    if (0 == strcmp(func, "vkCmdBindIndexBuffer")) return (PFN_vkVoidFunction)InterceptCmdBindIndexBuffer;
    if (0 == strcmp(func, "vkCmdBindVertexBuffers")) return (PFN_vkVoidFunction)InterceptCmdBindVertexBuffers;
    if (0 == strcmp(func, "vkCmdDraw")) return (PFN_vkVoidFunction)InterceptCmdDraw;
    if (0 == strcmp(func, "vkCmdDrawIndexed")) return (PFN_vkVoidFunction)InterceptCmdDrawIndexed;
    if (0 == strcmp(func, "vkCmdDrawIndirect")) return (PFN_vkVoidFunction)InterceptCmdDrawIndirect;
    if (0 == strcmp(func, "vkCmdDrawIndexedIndirect")) return (PFN_vkVoidFunction)InterceptCmdDrawIndexedIndirect;
    if (0 == strcmp(func, "vkCmdDispatch")) return (PFN_vkVoidFunction)InterceptCmdDispatch;
    if (0 == strcmp(func, "vkCmdDispatchIndirect")) return (PFN_vkVoidFunction)InterceptCmdDispatchIndirect;
    if (0 == strcmp(func, "vkCmdCopyBuffer")) return (PFN_vkVoidFunction)InterceptCmdCopyBuffer;
    if (0 == strcmp(func, "vkCmdCopyImage")) return (PFN_vkVoidFunction)InterceptCmdCopyImage;
    if (0 == strcmp(func, "vkCmdBlitImage")) return (PFN_vkVoidFunction)InterceptCmdBlitImage;
    if (0 == strcmp(func, "vkCmdCopyBufferToImage")) return (PFN_vkVoidFunction)InterceptCmdCopyBufferToImage;
    if (0 == strcmp(func, "vkCmdCopyImageToBuffer")) return (PFN_vkVoidFunction)InterceptCmdCopyImageToBuffer;
    if (0 == strcmp(func, "vkCmdUpdateBuffer")) return (PFN_vkVoidFunction)InterceptCmdUpdateBuffer;
    if (0 == strcmp(func, "vkCmdFillBuffer")) return (PFN_vkVoidFunction)InterceptCmdFillBuffer;
    if (0 == strcmp(func, "vkCmdClearColorImage")) return (PFN_vkVoidFunction)InterceptCmdClearColorImage;
    if (0 == strcmp(func, "vkCmdClearDepthStencilImage")) return (PFN_vkVoidFunction)InterceptCmdClearDepthStencilImage;
    if (0 == strcmp(func, "vkCmdClearAttachments")) return (PFN_vkVoidFunction)InterceptCmdClearAttachments;
    if (0 == strcmp(func, "vkCmdResolveImage")) return (PFN_vkVoidFunction)InterceptCmdResolveImage;
    if (0 == strcmp(func, "vkCmdSetEvent")) return (PFN_vkVoidFunction)InterceptCmdSetEvent;
    if (0 == strcmp(func, "vkCmdResetEvent")) return (PFN_vkVoidFunction)InterceptCmdResetEvent;
    if (0 == strcmp(func, "vkCmdWaitEvents")) return (PFN_vkVoidFunction)InterceptCmdWaitEvents;
    if (0 == strcmp(func, "vkCmdPipelineBarrier")) return (PFN_vkVoidFunction)InterceptCmdPipelineBarrier;
    if (0 == strcmp(func, "vkCmdBeginQuery")) return (PFN_vkVoidFunction)InterceptCmdBeginQuery;
    if (0 == strcmp(func, "vkCmdEndQuery")) return (PFN_vkVoidFunction)InterceptCmdEndQuery;
    if (0 == strcmp(func, "vkCmdResetQueryPool")) return (PFN_vkVoidFunction)InterceptCmdResetQueryPool;
    if (0 == strcmp(func, "vkCmdWriteTimestamp")) return (PFN_vkVoidFunction)InterceptCmdWriteTimestamp;
    if (0 == strcmp(func, "vkCmdCopyQueryPoolResults")) return (PFN_vkVoidFunction)InterceptCmdCopyQueryPoolResults;
    if (0 == strcmp(func, "vkCmdPushConstants")) return (PFN_vkVoidFunction)InterceptCmdPushConstants;
    if (0 == strcmp(func, "vkCmdBeginRenderPass")) return (PFN_vkVoidFunction)InterceptCmdBeginRenderPass;
    if (0 == strcmp(func, "vkCmdNextSubpass")) return (PFN_vkVoidFunction)InterceptCmdNextSubpass;
    if (0 == strcmp(func, "vkCmdEndRenderPass")) return (PFN_vkVoidFunction)InterceptCmdEndRenderPass;
    if (0 == strcmp(func, "vkCmdExecuteCommands")) return (PFN_vkVoidFunction)InterceptCmdExecuteCommands;
    if (0 == strcmp(func, "vkCmdSetDeviceMask")) return (PFN_vkVoidFunction)InterceptCmdSetDeviceMask;
    if (0 == strcmp(func, "vkCmdDispatchBase")) return (PFN_vkVoidFunction)InterceptCmdDispatchBase;
    if (0 == strcmp(func, "vkGetDeviceQueue2")) return (PFN_vkVoidFunction)InterceptGetDeviceQueue2;
    if (0 == strcmp(func, "vkCmdDrawIndirectCount")) return (PFN_vkVoidFunction)InterceptCmdDrawIndirectCount;
    if (0 == strcmp(func, "vkCmdDrawIndexedIndirectCount"))
        return (PFN_vkVoidFunction)InterceptCmdDrawIndexedIndirectCount;
    if (0 == strcmp(func, "vkCmdBeginRenderPass2")) return (PFN_vkVoidFunction)InterceptCmdBeginRenderPass2;
    if (0 == strcmp(func, "vkCmdNextSubpass2")) return (PFN_vkVoidFunction)InterceptCmdNextSubpass2;
    if (0 == strcmp(func, "vkCmdEndRenderPass2")) return (PFN_vkVoidFunction)InterceptCmdEndRenderPass2;
    if (0 == strcmp(func, "vkCmdSetEvent2")) return (PFN_vkVoidFunction)InterceptCmdSetEvent2;
    if (0 == strcmp(func, "vkCmdResetEvent2")) return (PFN_vkVoidFunction)InterceptCmdResetEvent2;
    if (0 == strcmp(func, "vkCmdWaitEvents2")) return (PFN_vkVoidFunction)InterceptCmdWaitEvents2;
    if (0 == strcmp(func, "vkCmdPipelineBarrier2")) return (PFN_vkVoidFunction)InterceptCmdPipelineBarrier2;
    if (0 == strcmp(func, "vkCmdWriteTimestamp2")) return (PFN_vkVoidFunction)InterceptCmdWriteTimestamp2;
    if (0 == strcmp(func, "vkQueueSubmit2")) return (PFN_vkVoidFunction)InterceptQueueSubmit2;
    if (0 == strcmp(func, "vkCmdCopyBuffer2")) return (PFN_vkVoidFunction)InterceptCmdCopyBuffer2;
    if (0 == strcmp(func, "vkCmdCopyImage2")) return (PFN_vkVoidFunction)InterceptCmdCopyImage2;
    if (0 == strcmp(func, "vkCmdCopyBufferToImage2")) return (PFN_vkVoidFunction)InterceptCmdCopyBufferToImage2;
    if (0 == strcmp(func, "vkCmdCopyImageToBuffer2")) return (PFN_vkVoidFunction)InterceptCmdCopyImageToBuffer2;
    if (0 == strcmp(func, "vkCmdBlitImage2")) return (PFN_vkVoidFunction)InterceptCmdBlitImage2;
    if (0 == strcmp(func, "vkCmdResolveImage2")) return (PFN_vkVoidFunction)InterceptCmdResolveImage2;
    if (0 == strcmp(func, "vkCmdBeginRendering")) return (PFN_vkVoidFunction)InterceptCmdBeginRendering;
    if (0 == strcmp(func, "vkCmdEndRendering")) return (PFN_vkVoidFunction)InterceptCmdEndRendering;
    if (0 == strcmp(func, "vkCmdSetCullMode")) return (PFN_vkVoidFunction)InterceptCmdSetCullMode;
    if (0 == strcmp(func, "vkCmdSetFrontFace")) return (PFN_vkVoidFunction)InterceptCmdSetFrontFace;
    if (0 == strcmp(func, "vkCmdSetPrimitiveTopology")) return (PFN_vkVoidFunction)InterceptCmdSetPrimitiveTopology;
    if (0 == strcmp(func, "vkCmdSetViewportWithCount")) return (PFN_vkVoidFunction)InterceptCmdSetViewportWithCount;
    if (0 == strcmp(func, "vkCmdSetScissorWithCount")) return (PFN_vkVoidFunction)InterceptCmdSetScissorWithCount;
    if (0 == strcmp(func, "vkCmdBindVertexBuffers2")) return (PFN_vkVoidFunction)InterceptCmdBindVertexBuffers2;
    if (0 == strcmp(func, "vkCmdSetDepthTestEnable")) return (PFN_vkVoidFunction)InterceptCmdSetDepthTestEnable;
    if (0 == strcmp(func, "vkCmdSetDepthWriteEnable")) return (PFN_vkVoidFunction)InterceptCmdSetDepthWriteEnable;
    if (0 == strcmp(func, "vkCmdSetDepthCompareOp")) return (PFN_vkVoidFunction)InterceptCmdSetDepthCompareOp;
    if (0 == strcmp(func, "vkCmdSetDepthBoundsTestEnable"))
        return (PFN_vkVoidFunction)InterceptCmdSetDepthBoundsTestEnable;
    if (0 == strcmp(func, "vkCmdSetStencilTestEnable")) return (PFN_vkVoidFunction)InterceptCmdSetStencilTestEnable;
    if (0 == strcmp(func, "vkCmdSetStencilOp")) return (PFN_vkVoidFunction)InterceptCmdSetStencilOp;
    if (0 == strcmp(func, "vkCmdSetRasterizerDiscardEnable"))
        return (PFN_vkVoidFunction)InterceptCmdSetRasterizerDiscardEnable;
    if (0 == strcmp(func, "vkCmdSetDepthBiasEnable")) return (PFN_vkVoidFunction)InterceptCmdSetDepthBiasEnable;
    if (0 == strcmp(func, "vkCmdSetPrimitiveRestartEnable"))
        return (PFN_vkVoidFunction)InterceptCmdSetPrimitiveRestartEnable;
    if (0 == strcmp(func, "vkAcquireNextImageKHR")) return (PFN_vkVoidFunction)InterceptAcquireNextImageKHR;
    if (0 == strcmp(func, "vkQueuePresentKHR")) return (PFN_vkVoidFunction)InterceptQueuePresentKHR;
    if (0 == strcmp(func, "vkCmdBeginVideoCodingKHR")) return (PFN_vkVoidFunction)InterceptCmdBeginVideoCodingKHR;
    if (0 == strcmp(func, "vkCmdEndVideoCodingKHR")) return (PFN_vkVoidFunction)InterceptCmdEndVideoCodingKHR;
    if (0 == strcmp(func, "vkCmdControlVideoCodingKHR")) return (PFN_vkVoidFunction)InterceptCmdControlVideoCodingKHR;
    if (0 == strcmp(func, "vkCmdDecodeVideoKHR")) return (PFN_vkVoidFunction)InterceptCmdDecodeVideoKHR;
    if (0 == strcmp(func, "vkCmdBeginRenderingKHR")) return (PFN_vkVoidFunction)InterceptCmdBeginRenderingKHR;
    if (0 == strcmp(func, "vkCmdEndRenderingKHR")) return (PFN_vkVoidFunction)InterceptCmdEndRenderingKHR;
    if (0 == strcmp(func, "vkCmdSetDeviceMaskKHR")) return (PFN_vkVoidFunction)InterceptCmdSetDeviceMaskKHR;
    if (0 == strcmp(func, "vkCmdDispatchBaseKHR")) return (PFN_vkVoidFunction)InterceptCmdDispatchBaseKHR;
    if (0 == strcmp(func, "vkCmdPushDescriptorSetKHR")) return (PFN_vkVoidFunction)InterceptCmdPushDescriptorSetKHR;
    if (0 == strcmp(func, "vkCmdPushDescriptorSetWithTemplateKHR"))
        return (PFN_vkVoidFunction)InterceptCmdPushDescriptorSetWithTemplateKHR;
    if (0 == strcmp(func, "vkCmdBeginRenderPass2KHR")) return (PFN_vkVoidFunction)InterceptCmdBeginRenderPass2KHR;
    if (0 == strcmp(func, "vkCmdNextSubpass2KHR")) return (PFN_vkVoidFunction)InterceptCmdNextSubpass2KHR;
    if (0 == strcmp(func, "vkCmdEndRenderPass2KHR")) return (PFN_vkVoidFunction)InterceptCmdEndRenderPass2KHR;
    if (0 == strcmp(func, "vkCmdDrawIndirectCountKHR")) return (PFN_vkVoidFunction)InterceptCmdDrawIndirectCountKHR;
    if (0 == strcmp(func, "vkCmdDrawIndexedIndirectCountKHR"))
        return (PFN_vkVoidFunction)InterceptCmdDrawIndexedIndirectCountKHR;
    if (0 == strcmp(func, "vkGetSemaphoreCounterValueKHR"))
        return (PFN_vkVoidFunction)InterceptGetSemaphoreCounterValueKHR;
    if (0 == strcmp(func, "vkWaitSemaphoresKHR")) return (PFN_vkVoidFunction)InterceptWaitSemaphoresKHR;
    if (0 == strcmp(func, "vkSignalSemaphoreKHR")) return (PFN_vkVoidFunction)InterceptSignalSemaphoreKHR;
    if (0 == strcmp(func, "vkCmdSetFragmentShadingRateKHR"))
        return (PFN_vkVoidFunction)InterceptCmdSetFragmentShadingRateKHR;
    if (0 == strcmp(func, "vkCmdSetRenderingAttachmentLocationsKHR"))
        return (PFN_vkVoidFunction)InterceptCmdSetRenderingAttachmentLocationsKHR;
    if (0 == strcmp(func, "vkCmdSetRenderingInputAttachmentIndicesKHR"))
        return (PFN_vkVoidFunction)InterceptCmdSetRenderingInputAttachmentIndicesKHR;
    if (0 == strcmp(func, "vkCmdEncodeVideoKHR")) return (PFN_vkVoidFunction)InterceptCmdEncodeVideoKHR;
    if (0 == strcmp(func, "vkCmdSetEvent2KHR")) return (PFN_vkVoidFunction)InterceptCmdSetEvent2KHR;
    if (0 == strcmp(func, "vkCmdResetEvent2KHR")) return (PFN_vkVoidFunction)InterceptCmdResetEvent2KHR;
    if (0 == strcmp(func, "vkCmdWaitEvents2KHR")) return (PFN_vkVoidFunction)InterceptCmdWaitEvents2KHR;
    if (0 == strcmp(func, "vkCmdPipelineBarrier2KHR")) return (PFN_vkVoidFunction)InterceptCmdPipelineBarrier2KHR;
    if (0 == strcmp(func, "vkCmdWriteTimestamp2KHR")) return (PFN_vkVoidFunction)InterceptCmdWriteTimestamp2KHR;
    if (0 == strcmp(func, "vkQueueSubmit2KHR")) return (PFN_vkVoidFunction)InterceptQueueSubmit2KHR;
    if (0 == strcmp(func, "vkCmdWriteBufferMarker2AMD")) return (PFN_vkVoidFunction)InterceptCmdWriteBufferMarker2AMD;
    if (0 == strcmp(func, "vkCmdCopyBuffer2KHR")) return (PFN_vkVoidFunction)InterceptCmdCopyBuffer2KHR;
    if (0 == strcmp(func, "vkCmdCopyImage2KHR")) return (PFN_vkVoidFunction)InterceptCmdCopyImage2KHR;
    if (0 == strcmp(func, "vkCmdCopyBufferToImage2KHR")) return (PFN_vkVoidFunction)InterceptCmdCopyBufferToImage2KHR;
    if (0 == strcmp(func, "vkCmdCopyImageToBuffer2KHR")) return (PFN_vkVoidFunction)InterceptCmdCopyImageToBuffer2KHR;
    if (0 == strcmp(func, "vkCmdBlitImage2KHR")) return (PFN_vkVoidFunction)InterceptCmdBlitImage2KHR;
    if (0 == strcmp(func, "vkCmdResolveImage2KHR")) return (PFN_vkVoidFunction)InterceptCmdResolveImage2KHR;
    if (0 == strcmp(func, "vkCmdTraceRaysIndirect2KHR")) return (PFN_vkVoidFunction)InterceptCmdTraceRaysIndirect2KHR;
    if (0 == strcmp(func, "vkCmdBindIndexBuffer2KHR")) return (PFN_vkVoidFunction)InterceptCmdBindIndexBuffer2KHR;
    if (0 == strcmp(func, "vkCmdSetLineStippleKHR")) return (PFN_vkVoidFunction)InterceptCmdSetLineStippleKHR;
    if (0 == strcmp(func, "vkCmdBindDescriptorSets2KHR")) return (PFN_vkVoidFunction)InterceptCmdBindDescriptorSets2KHR;
    if (0 == strcmp(func, "vkCmdPushConstants2KHR")) return (PFN_vkVoidFunction)InterceptCmdPushConstants2KHR;
    if (0 == strcmp(func, "vkCmdPushDescriptorSet2KHR")) return (PFN_vkVoidFunction)InterceptCmdPushDescriptorSet2KHR;
    if (0 == strcmp(func, "vkCmdPushDescriptorSetWithTemplate2KHR"))
        return (PFN_vkVoidFunction)InterceptCmdPushDescriptorSetWithTemplate2KHR;
    if (0 == strcmp(func, "vkCmdSetDescriptorBufferOffsets2EXT"))
        return (PFN_vkVoidFunction)InterceptCmdSetDescriptorBufferOffsets2EXT;
    if (0 == strcmp(func, "vkCmdBindDescriptorBufferEmbeddedSamplers2EXT"))
        return (PFN_vkVoidFunction)InterceptCmdBindDescriptorBufferEmbeddedSamplers2EXT;
    if (0 == strcmp(func, "vkDebugMarkerSetObjectNameEXT"))
        return (PFN_vkVoidFunction)InterceptDebugMarkerSetObjectNameEXT;
    if (0 == strcmp(func, "vkCmdDebugMarkerBeginEXT")) return (PFN_vkVoidFunction)InterceptCmdDebugMarkerBeginEXT;
    if (0 == strcmp(func, "vkCmdDebugMarkerEndEXT")) return (PFN_vkVoidFunction)InterceptCmdDebugMarkerEndEXT;
    if (0 == strcmp(func, "vkCmdDebugMarkerInsertEXT")) return (PFN_vkVoidFunction)InterceptCmdDebugMarkerInsertEXT;
    if (0 == strcmp(func, "vkCmdBindTransformFeedbackBuffersEXT"))
        return (PFN_vkVoidFunction)InterceptCmdBindTransformFeedbackBuffersEXT;
    if (0 == strcmp(func, "vkCmdBeginTransformFeedbackEXT"))
        return (PFN_vkVoidFunction)InterceptCmdBeginTransformFeedbackEXT;
    if (0 == strcmp(func, "vkCmdEndTransformFeedbackEXT"))
        return (PFN_vkVoidFunction)InterceptCmdEndTransformFeedbackEXT;
    if (0 == strcmp(func, "vkCmdBeginQueryIndexedEXT")) return (PFN_vkVoidFunction)InterceptCmdBeginQueryIndexedEXT;
    if (0 == strcmp(func, "vkCmdEndQueryIndexedEXT")) return (PFN_vkVoidFunction)InterceptCmdEndQueryIndexedEXT;
    if (0 == strcmp(func, "vkCmdDrawIndirectByteCountEXT"))
        return (PFN_vkVoidFunction)InterceptCmdDrawIndirectByteCountEXT;
    if (0 == strcmp(func, "vkCmdCuLaunchKernelNVX")) return (PFN_vkVoidFunction)InterceptCmdCuLaunchKernelNVX;
    if (0 == strcmp(func, "vkCmdDrawIndirectCountAMD")) return (PFN_vkVoidFunction)InterceptCmdDrawIndirectCountAMD;
    if (0 == strcmp(func, "vkCmdDrawIndexedIndirectCountAMD"))
        return (PFN_vkVoidFunction)InterceptCmdDrawIndexedIndirectCountAMD;
    if (0 == strcmp(func, "vkCmdBeginConditionalRenderingEXT"))
        return (PFN_vkVoidFunction)InterceptCmdBeginConditionalRenderingEXT;
    if (0 == strcmp(func, "vkCmdEndConditionalRenderingEXT"))
        return (PFN_vkVoidFunction)InterceptCmdEndConditionalRenderingEXT;
    if (0 == strcmp(func, "vkCmdSetViewportWScalingNV")) return (PFN_vkVoidFunction)InterceptCmdSetViewportWScalingNV;
    if (0 == strcmp(func, "vkCmdSetDiscardRectangleEXT")) return (PFN_vkVoidFunction)InterceptCmdSetDiscardRectangleEXT;
    if (0 == strcmp(func, "vkCmdSetDiscardRectangleEnableEXT"))
        return (PFN_vkVoidFunction)InterceptCmdSetDiscardRectangleEnableEXT;
    if (0 == strcmp(func, "vkCmdSetDiscardRectangleModeEXT"))
        return (PFN_vkVoidFunction)InterceptCmdSetDiscardRectangleModeEXT;
    if (0 == strcmp(func, "vkSetDebugUtilsObjectNameEXT"))
        return (PFN_vkVoidFunction)InterceptSetDebugUtilsObjectNameEXT;
    if (0 == strcmp(func, "vkCmdBeginDebugUtilsLabelEXT"))
        return (PFN_vkVoidFunction)InterceptCmdBeginDebugUtilsLabelEXT;
    if (0 == strcmp(func, "vkCmdEndDebugUtilsLabelEXT")) return (PFN_vkVoidFunction)InterceptCmdEndDebugUtilsLabelEXT;
    if (0 == strcmp(func, "vkCmdInsertDebugUtilsLabelEXT"))
        return (PFN_vkVoidFunction)InterceptCmdInsertDebugUtilsLabelEXT;
#ifdef VK_ENABLE_BETA_EXTENSIONS
    if (0 == strcmp(func, "vkCmdInitializeGraphScratchMemoryAMDX"))
        return (PFN_vkVoidFunction)InterceptCmdInitializeGraphScratchMemoryAMDX;
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
    if (0 == strcmp(func, "vkCmdDispatchGraphAMDX")) return (PFN_vkVoidFunction)InterceptCmdDispatchGraphAMDX;
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
    if (0 == strcmp(func, "vkCmdDispatchGraphIndirectAMDX"))
        return (PFN_vkVoidFunction)InterceptCmdDispatchGraphIndirectAMDX;
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
    if (0 == strcmp(func, "vkCmdDispatchGraphIndirectCountAMDX"))
        return (PFN_vkVoidFunction)InterceptCmdDispatchGraphIndirectCountAMDX;
#endif  // VK_ENABLE_BETA_EXTENSIONS
    if (0 == strcmp(func, "vkCmdSetSampleLocationsEXT")) return (PFN_vkVoidFunction)InterceptCmdSetSampleLocationsEXT;
    if (0 == strcmp(func, "vkCmdBindShadingRateImageNV")) return (PFN_vkVoidFunction)InterceptCmdBindShadingRateImageNV;
    if (0 == strcmp(func, "vkCmdSetViewportShadingRatePaletteNV"))
        return (PFN_vkVoidFunction)InterceptCmdSetViewportShadingRatePaletteNV;
    if (0 == strcmp(func, "vkCmdSetCoarseSampleOrderNV")) return (PFN_vkVoidFunction)InterceptCmdSetCoarseSampleOrderNV;
    if (0 == strcmp(func, "vkCmdBuildAccelerationStructureNV"))
        return (PFN_vkVoidFunction)InterceptCmdBuildAccelerationStructureNV;
    if (0 == strcmp(func, "vkCmdCopyAccelerationStructureNV"))
        return (PFN_vkVoidFunction)InterceptCmdCopyAccelerationStructureNV;
    if (0 == strcmp(func, "vkCmdTraceRaysNV")) return (PFN_vkVoidFunction)InterceptCmdTraceRaysNV;
    if (0 == strcmp(func, "vkCmdWriteAccelerationStructuresPropertiesNV"))
        return (PFN_vkVoidFunction)InterceptCmdWriteAccelerationStructuresPropertiesNV;
    if (0 == strcmp(func, "vkCmdWriteBufferMarkerAMD")) return (PFN_vkVoidFunction)InterceptCmdWriteBufferMarkerAMD;
    if (0 == strcmp(func, "vkCmdDrawMeshTasksNV")) return (PFN_vkVoidFunction)InterceptCmdDrawMeshTasksNV;
    if (0 == strcmp(func, "vkCmdDrawMeshTasksIndirectNV"))
        return (PFN_vkVoidFunction)InterceptCmdDrawMeshTasksIndirectNV;
    if (0 == strcmp(func, "vkCmdDrawMeshTasksIndirectCountNV"))
        return (PFN_vkVoidFunction)InterceptCmdDrawMeshTasksIndirectCountNV;
    if (0 == strcmp(func, "vkCmdSetExclusiveScissorEnableNV"))
        return (PFN_vkVoidFunction)InterceptCmdSetExclusiveScissorEnableNV;
    if (0 == strcmp(func, "vkCmdSetExclusiveScissorNV")) return (PFN_vkVoidFunction)InterceptCmdSetExclusiveScissorNV;
    if (0 == strcmp(func, "vkCmdSetCheckpointNV")) return (PFN_vkVoidFunction)InterceptCmdSetCheckpointNV;
    if (0 == strcmp(func, "vkCmdSetPerformanceMarkerINTEL"))
        return (PFN_vkVoidFunction)InterceptCmdSetPerformanceMarkerINTEL;
    if (0 == strcmp(func, "vkCmdSetPerformanceStreamMarkerINTEL"))
        return (PFN_vkVoidFunction)InterceptCmdSetPerformanceStreamMarkerINTEL;
    if (0 == strcmp(func, "vkCmdSetPerformanceOverrideINTEL"))
        return (PFN_vkVoidFunction)InterceptCmdSetPerformanceOverrideINTEL;
    if (0 == strcmp(func, "vkCmdSetLineStippleEXT")) return (PFN_vkVoidFunction)InterceptCmdSetLineStippleEXT;
    if (0 == strcmp(func, "vkCmdSetCullModeEXT")) return (PFN_vkVoidFunction)InterceptCmdSetCullModeEXT;
    if (0 == strcmp(func, "vkCmdSetFrontFaceEXT")) return (PFN_vkVoidFunction)InterceptCmdSetFrontFaceEXT;
    if (0 == strcmp(func, "vkCmdSetPrimitiveTopologyEXT"))
        return (PFN_vkVoidFunction)InterceptCmdSetPrimitiveTopologyEXT;
    if (0 == strcmp(func, "vkCmdSetViewportWithCountEXT"))
        return (PFN_vkVoidFunction)InterceptCmdSetViewportWithCountEXT;
    if (0 == strcmp(func, "vkCmdSetScissorWithCountEXT")) return (PFN_vkVoidFunction)InterceptCmdSetScissorWithCountEXT;
    if (0 == strcmp(func, "vkCmdBindVertexBuffers2EXT")) return (PFN_vkVoidFunction)InterceptCmdBindVertexBuffers2EXT;
    if (0 == strcmp(func, "vkCmdSetDepthTestEnableEXT")) return (PFN_vkVoidFunction)InterceptCmdSetDepthTestEnableEXT;
    if (0 == strcmp(func, "vkCmdSetDepthWriteEnableEXT")) return (PFN_vkVoidFunction)InterceptCmdSetDepthWriteEnableEXT;
    if (0 == strcmp(func, "vkCmdSetDepthCompareOpEXT")) return (PFN_vkVoidFunction)InterceptCmdSetDepthCompareOpEXT;
    if (0 == strcmp(func, "vkCmdSetDepthBoundsTestEnableEXT"))
        return (PFN_vkVoidFunction)InterceptCmdSetDepthBoundsTestEnableEXT;
    if (0 == strcmp(func, "vkCmdSetStencilTestEnableEXT"))
        return (PFN_vkVoidFunction)InterceptCmdSetStencilTestEnableEXT;
    if (0 == strcmp(func, "vkCmdSetStencilOpEXT")) return (PFN_vkVoidFunction)InterceptCmdSetStencilOpEXT;
    if (0 == strcmp(func, "vkCmdPreprocessGeneratedCommandsNV"))
        return (PFN_vkVoidFunction)InterceptCmdPreprocessGeneratedCommandsNV;
    if (0 == strcmp(func, "vkCmdExecuteGeneratedCommandsNV"))
        return (PFN_vkVoidFunction)InterceptCmdExecuteGeneratedCommandsNV;
    if (0 == strcmp(func, "vkCmdBindPipelineShaderGroupNV"))
        return (PFN_vkVoidFunction)InterceptCmdBindPipelineShaderGroupNV;
    if (0 == strcmp(func, "vkCmdSetDepthBias2EXT")) return (PFN_vkVoidFunction)InterceptCmdSetDepthBias2EXT;
    if (0 == strcmp(func, "vkCmdCudaLaunchKernelNV")) return (PFN_vkVoidFunction)InterceptCmdCudaLaunchKernelNV;
    if (0 == strcmp(func, "vkCmdBindDescriptorBuffersEXT"))
        return (PFN_vkVoidFunction)InterceptCmdBindDescriptorBuffersEXT;
    if (0 == strcmp(func, "vkCmdSetDescriptorBufferOffsetsEXT"))
        return (PFN_vkVoidFunction)InterceptCmdSetDescriptorBufferOffsetsEXT;
    if (0 == strcmp(func, "vkCmdBindDescriptorBufferEmbeddedSamplersEXT"))
        return (PFN_vkVoidFunction)InterceptCmdBindDescriptorBufferEmbeddedSamplersEXT;
    if (0 == strcmp(func, "vkCmdSetFragmentShadingRateEnumNV"))
        return (PFN_vkVoidFunction)InterceptCmdSetFragmentShadingRateEnumNV;
    if (0 == strcmp(func, "vkCmdSetVertexInputEXT")) return (PFN_vkVoidFunction)InterceptCmdSetVertexInputEXT;
    if (0 == strcmp(func, "vkCmdSubpassShadingHUAWEI")) return (PFN_vkVoidFunction)InterceptCmdSubpassShadingHUAWEI;
    if (0 == strcmp(func, "vkCmdBindInvocationMaskHUAWEI"))
        return (PFN_vkVoidFunction)InterceptCmdBindInvocationMaskHUAWEI;
    if (0 == strcmp(func, "vkCmdSetPatchControlPointsEXT"))
        return (PFN_vkVoidFunction)InterceptCmdSetPatchControlPointsEXT;
    if (0 == strcmp(func, "vkCmdSetRasterizerDiscardEnableEXT"))
        return (PFN_vkVoidFunction)InterceptCmdSetRasterizerDiscardEnableEXT;
    if (0 == strcmp(func, "vkCmdSetDepthBiasEnableEXT")) return (PFN_vkVoidFunction)InterceptCmdSetDepthBiasEnableEXT;
    if (0 == strcmp(func, "vkCmdSetLogicOpEXT")) return (PFN_vkVoidFunction)InterceptCmdSetLogicOpEXT;
    if (0 == strcmp(func, "vkCmdSetPrimitiveRestartEnableEXT"))
        return (PFN_vkVoidFunction)InterceptCmdSetPrimitiveRestartEnableEXT;
    if (0 == strcmp(func, "vkCmdSetColorWriteEnableEXT")) return (PFN_vkVoidFunction)InterceptCmdSetColorWriteEnableEXT;
    if (0 == strcmp(func, "vkCmdDrawMultiEXT")) return (PFN_vkVoidFunction)InterceptCmdDrawMultiEXT;
    if (0 == strcmp(func, "vkCmdDrawMultiIndexedEXT")) return (PFN_vkVoidFunction)InterceptCmdDrawMultiIndexedEXT;
    if (0 == strcmp(func, "vkCmdBuildMicromapsEXT")) return (PFN_vkVoidFunction)InterceptCmdBuildMicromapsEXT;
    if (0 == strcmp(func, "vkCmdCopyMicromapEXT")) return (PFN_vkVoidFunction)InterceptCmdCopyMicromapEXT;
    if (0 == strcmp(func, "vkCmdCopyMicromapToMemoryEXT"))
        return (PFN_vkVoidFunction)InterceptCmdCopyMicromapToMemoryEXT;
    if (0 == strcmp(func, "vkCmdCopyMemoryToMicromapEXT"))
        return (PFN_vkVoidFunction)InterceptCmdCopyMemoryToMicromapEXT;
    if (0 == strcmp(func, "vkCmdWriteMicromapsPropertiesEXT"))
        return (PFN_vkVoidFunction)InterceptCmdWriteMicromapsPropertiesEXT;
    if (0 == strcmp(func, "vkCmdDrawClusterHUAWEI")) return (PFN_vkVoidFunction)InterceptCmdDrawClusterHUAWEI;
    if (0 == strcmp(func, "vkCmdDrawClusterIndirectHUAWEI"))
        return (PFN_vkVoidFunction)InterceptCmdDrawClusterIndirectHUAWEI;
    if (0 == strcmp(func, "vkCmdCopyMemoryIndirectNV")) return (PFN_vkVoidFunction)InterceptCmdCopyMemoryIndirectNV;
    if (0 == strcmp(func, "vkCmdCopyMemoryToImageIndirectNV"))
        return (PFN_vkVoidFunction)InterceptCmdCopyMemoryToImageIndirectNV;
    if (0 == strcmp(func, "vkCmdDecompressMemoryNV")) return (PFN_vkVoidFunction)InterceptCmdDecompressMemoryNV;
    if (0 == strcmp(func, "vkCmdDecompressMemoryIndirectCountNV"))
        return (PFN_vkVoidFunction)InterceptCmdDecompressMemoryIndirectCountNV;
    if (0 == strcmp(func, "vkCmdUpdatePipelineIndirectBufferNV"))
        return (PFN_vkVoidFunction)InterceptCmdUpdatePipelineIndirectBufferNV;
    if (0 == strcmp(func, "vkCmdSetDepthClampEnableEXT")) return (PFN_vkVoidFunction)InterceptCmdSetDepthClampEnableEXT;
    if (0 == strcmp(func, "vkCmdSetPolygonModeEXT")) return (PFN_vkVoidFunction)InterceptCmdSetPolygonModeEXT;
    if (0 == strcmp(func, "vkCmdSetRasterizationSamplesEXT"))
        return (PFN_vkVoidFunction)InterceptCmdSetRasterizationSamplesEXT;
    if (0 == strcmp(func, "vkCmdSetSampleMaskEXT")) return (PFN_vkVoidFunction)InterceptCmdSetSampleMaskEXT;
    if (0 == strcmp(func, "vkCmdSetAlphaToCoverageEnableEXT"))
        return (PFN_vkVoidFunction)InterceptCmdSetAlphaToCoverageEnableEXT;
    if (0 == strcmp(func, "vkCmdSetAlphaToOneEnableEXT")) return (PFN_vkVoidFunction)InterceptCmdSetAlphaToOneEnableEXT;
    if (0 == strcmp(func, "vkCmdSetLogicOpEnableEXT")) return (PFN_vkVoidFunction)InterceptCmdSetLogicOpEnableEXT;
    if (0 == strcmp(func, "vkCmdSetColorBlendEnableEXT")) return (PFN_vkVoidFunction)InterceptCmdSetColorBlendEnableEXT;
    if (0 == strcmp(func, "vkCmdSetColorBlendEquationEXT"))
        return (PFN_vkVoidFunction)InterceptCmdSetColorBlendEquationEXT;
    if (0 == strcmp(func, "vkCmdSetColorWriteMaskEXT")) return (PFN_vkVoidFunction)InterceptCmdSetColorWriteMaskEXT;
    if (0 == strcmp(func, "vkCmdSetTessellationDomainOriginEXT"))
        return (PFN_vkVoidFunction)InterceptCmdSetTessellationDomainOriginEXT;
    if (0 == strcmp(func, "vkCmdSetRasterizationStreamEXT"))
        return (PFN_vkVoidFunction)InterceptCmdSetRasterizationStreamEXT;
    if (0 == strcmp(func, "vkCmdSetConservativeRasterizationModeEXT"))
        return (PFN_vkVoidFunction)InterceptCmdSetConservativeRasterizationModeEXT;
    if (0 == strcmp(func, "vkCmdSetExtraPrimitiveOverestimationSizeEXT"))
        return (PFN_vkVoidFunction)InterceptCmdSetExtraPrimitiveOverestimationSizeEXT;
    if (0 == strcmp(func, "vkCmdSetDepthClipEnableEXT")) return (PFN_vkVoidFunction)InterceptCmdSetDepthClipEnableEXT;
    if (0 == strcmp(func, "vkCmdSetSampleLocationsEnableEXT"))
        return (PFN_vkVoidFunction)InterceptCmdSetSampleLocationsEnableEXT;
    if (0 == strcmp(func, "vkCmdSetColorBlendAdvancedEXT"))
        return (PFN_vkVoidFunction)InterceptCmdSetColorBlendAdvancedEXT;
    if (0 == strcmp(func, "vkCmdSetProvokingVertexModeEXT"))
        return (PFN_vkVoidFunction)InterceptCmdSetProvokingVertexModeEXT;
    if (0 == strcmp(func, "vkCmdSetLineRasterizationModeEXT"))
        return (PFN_vkVoidFunction)InterceptCmdSetLineRasterizationModeEXT;
    if (0 == strcmp(func, "vkCmdSetLineStippleEnableEXT"))
        return (PFN_vkVoidFunction)InterceptCmdSetLineStippleEnableEXT;
    if (0 == strcmp(func, "vkCmdSetDepthClipNegativeOneToOneEXT"))
        return (PFN_vkVoidFunction)InterceptCmdSetDepthClipNegativeOneToOneEXT;
    if (0 == strcmp(func, "vkCmdSetViewportWScalingEnableNV"))
        return (PFN_vkVoidFunction)InterceptCmdSetViewportWScalingEnableNV;
    if (0 == strcmp(func, "vkCmdSetViewportSwizzleNV")) return (PFN_vkVoidFunction)InterceptCmdSetViewportSwizzleNV;
    if (0 == strcmp(func, "vkCmdSetCoverageToColorEnableNV"))
        return (PFN_vkVoidFunction)InterceptCmdSetCoverageToColorEnableNV;
    if (0 == strcmp(func, "vkCmdSetCoverageToColorLocationNV"))
        return (PFN_vkVoidFunction)InterceptCmdSetCoverageToColorLocationNV;
    if (0 == strcmp(func, "vkCmdSetCoverageModulationModeNV"))
        return (PFN_vkVoidFunction)InterceptCmdSetCoverageModulationModeNV;
    if (0 == strcmp(func, "vkCmdSetCoverageModulationTableEnableNV"))
        return (PFN_vkVoidFunction)InterceptCmdSetCoverageModulationTableEnableNV;
    if (0 == strcmp(func, "vkCmdSetCoverageModulationTableNV"))
        return (PFN_vkVoidFunction)InterceptCmdSetCoverageModulationTableNV;
    if (0 == strcmp(func, "vkCmdSetShadingRateImageEnableNV"))
        return (PFN_vkVoidFunction)InterceptCmdSetShadingRateImageEnableNV;
    if (0 == strcmp(func, "vkCmdSetRepresentativeFragmentTestEnableNV"))
        return (PFN_vkVoidFunction)InterceptCmdSetRepresentativeFragmentTestEnableNV;
    if (0 == strcmp(func, "vkCmdSetCoverageReductionModeNV"))
        return (PFN_vkVoidFunction)InterceptCmdSetCoverageReductionModeNV;
    if (0 == strcmp(func, "vkCmdOpticalFlowExecuteNV")) return (PFN_vkVoidFunction)InterceptCmdOpticalFlowExecuteNV;
    if (0 == strcmp(func, "vkCmdBindShadersEXT")) return (PFN_vkVoidFunction)InterceptCmdBindShadersEXT;
    if (0 == strcmp(func, "vkCmdSetAttachmentFeedbackLoopEnableEXT"))
        return (PFN_vkVoidFunction)InterceptCmdSetAttachmentFeedbackLoopEnableEXT;
    if (0 == strcmp(func, "vkCmdBuildAccelerationStructuresKHR"))
        return (PFN_vkVoidFunction)InterceptCmdBuildAccelerationStructuresKHR;
    if (0 == strcmp(func, "vkCmdBuildAccelerationStructuresIndirectKHR"))
        return (PFN_vkVoidFunction)InterceptCmdBuildAccelerationStructuresIndirectKHR;
    if (0 == strcmp(func, "vkCmdCopyAccelerationStructureKHR"))
        return (PFN_vkVoidFunction)InterceptCmdCopyAccelerationStructureKHR;
    if (0 == strcmp(func, "vkCmdCopyAccelerationStructureToMemoryKHR"))
        return (PFN_vkVoidFunction)InterceptCmdCopyAccelerationStructureToMemoryKHR;
    if (0 == strcmp(func, "vkCmdCopyMemoryToAccelerationStructureKHR"))
        return (PFN_vkVoidFunction)InterceptCmdCopyMemoryToAccelerationStructureKHR;
    if (0 == strcmp(func, "vkCmdWriteAccelerationStructuresPropertiesKHR"))
        return (PFN_vkVoidFunction)InterceptCmdWriteAccelerationStructuresPropertiesKHR;
    if (0 == strcmp(func, "vkCmdTraceRaysKHR")) return (PFN_vkVoidFunction)InterceptCmdTraceRaysKHR;
    if (0 == strcmp(func, "vkCmdTraceRaysIndirectKHR")) return (PFN_vkVoidFunction)InterceptCmdTraceRaysIndirectKHR;
    if (0 == strcmp(func, "vkCmdSetRayTracingPipelineStackSizeKHR"))
        return (PFN_vkVoidFunction)InterceptCmdSetRayTracingPipelineStackSizeKHR;
    if (0 == strcmp(func, "vkCmdDrawMeshTasksEXT")) return (PFN_vkVoidFunction)InterceptCmdDrawMeshTasksEXT;
    if (0 == strcmp(func, "vkCmdDrawMeshTasksIndirectEXT"))
        return (PFN_vkVoidFunction)InterceptCmdDrawMeshTasksIndirectEXT;
    if (0 == strcmp(func, "vkCmdDrawMeshTasksIndirectCountEXT"))
        return (PFN_vkVoidFunction)InterceptCmdDrawMeshTasksIndirectCountEXT;

    return nullptr;
}

}  // namespace crash_diagnostic_layer

extern "C" {

CDL_EXPORT VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL CDL_GetInstanceProcAddr(VkInstance inst, const char* func) {
    PFN_vkVoidFunction return_func = crash_diagnostic_layer::GetInstanceFuncs(func);
    if (return_func != nullptr) {
        return return_func;
    }
    return_func = crash_diagnostic_layer::GetDeviceFuncs(func);
    if (return_func != nullptr) {
        return return_func;
    }

    // If the function was not found, just pass it down the chain to support
    // unregistered extensions, such as vkSwapchainCallbackEXT.
    return (PFN_vkVoidFunction)crash_diagnostic_layer::PassInstanceProcDownTheChain(inst, func);
}

CDL_EXPORT VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL CDL_GetDeviceProcAddr(VkDevice dev, const char* func) {
    PFN_vkVoidFunction return_func = crash_diagnostic_layer::GetDeviceFuncs(func);
    if (return_func != nullptr) {
        return return_func;
    }

    // If the function was not found, just pass it down the chain to support
    // unregistered extensions, such as vkSwapchainCallbackEXT.
    return (PFN_vkVoidFunction)crash_diagnostic_layer::PassDeviceProcDownTheChain(dev, func);
}  // NOLINT(readability/fn_size)

CDL_EXPORT VKAPI_ATTR VkResult VKAPI_CALL
CDL_NegotiateLoaderLayerInterfaceVersion(VkNegotiateLayerInterface* pVersionStruct) {
    assert(pVersionStruct != NULL);
    assert(pVersionStruct->sType == LAYER_NEGOTIATE_INTERFACE_STRUCT);
    // Fill in the function pointers if our version is at least capable of having
    // the structure contain them.
    if (pVersionStruct->loaderLayerInterfaceVersion >= 2) {
        pVersionStruct->pfnGetInstanceProcAddr = &CDL_GetInstanceProcAddr;
        pVersionStruct->pfnGetDeviceProcAddr = &CDL_GetDeviceProcAddr;
        pVersionStruct->pfnGetPhysicalDeviceProcAddr = nullptr;
    }
    if (pVersionStruct->loaderLayerInterfaceVersion > CURRENT_LOADER_LAYER_INTERFACE_VERSION) {
        pVersionStruct->loaderLayerInterfaceVersion = CURRENT_LOADER_LAYER_INTERFACE_VERSION;
    }
    return VK_SUCCESS;
}

}  // extern "C"

// NOLINTEND
