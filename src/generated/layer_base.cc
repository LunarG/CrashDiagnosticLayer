
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

constexpr VkLayerProperties layer_properties = {
    "VK_LAYER_LUNARG_crash_diagnostic", VK_HEADER_VERSION,
    1,
    "Crash Diagnostic Layer is a crash/hang debugging tool that helps determines GPU progress in a Vulkan application."
};

namespace {

// Generally we expect to get the same device and instance, so we keep them handy
static thread_local InstanceData* last_used_instance_data = nullptr;
static thread_local DeviceData* last_used_device_data = nullptr;

std::mutex g_instance_mutex;
std::unordered_map<uintptr_t, std::unique_ptr<InstanceData>> g_instance_data;

std::mutex g_device_mutex;
std::unordered_map<uintptr_t, std::unique_ptr<DeviceData>> g_device_data;

} // namespace

uintptr_t DataKey(const void *object) {
   return (uintptr_t)(*(void **)object);
}

InstanceData* GetInstanceLayerData(uintptr_t key) {
  if (last_used_instance_data &&
      DataKey(last_used_instance_data->instance) == key) {
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
  if (last_used_device_data &&
      DataKey(last_used_device_data->device) == key) {
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

VkStruct *FindOnChain(VkStruct *s, VkStructureType type) {
  VkStruct *n = (VkStruct *)s->pNext;
  while (n && n->sType != type) {
    n = (VkStruct *)n->pNext;
  }
  return n;
}

VkLayerInstanceCreateInfo *GetLoaderInstanceInfo(
    const VkInstanceCreateInfo *create_info, VkLayerFunction func_type) {
  VkStruct *n = (VkStruct *)create_info;
  while ((n = FindOnChain(n, VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO))) {
    VkLayerInstanceCreateInfo *vci = (VkLayerInstanceCreateInfo *)n;
    if (vci->function == func_type) {
      return vci;
    }
  }
  return nullptr;
}

VkLayerDeviceCreateInfo *GetLoaderDeviceInfo(
    const VkDeviceCreateInfo *create_info, VkLayerFunction func_type) {
  VkStruct *n = (VkStruct *)create_info;
  while ((n = FindOnChain(n, VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO))) {
    VkLayerDeviceCreateInfo *vdi = (VkLayerDeviceCreateInfo *)n;
    if (vdi->function == func_type) {
      return vdi;
    }
  }
  return nullptr;
}

VkResult SetInstanceLoaderData(VkInstance instance, void *obj)
{
  InstanceData *instance_data = GetInstanceLayerData(DataKey(instance));
  return instance_data->pfn_set_instance_loader_data(instance, obj);
}

VkResult SetDeviceLoaderData(VkDevice device, void *obj)
{
  DeviceData *device_data = GetDeviceLayerData(DataKey(device));
  return device_data->pfn_set_device_loader_data(device, obj);
}



// Declare the list of implemented instance and device extensions.

static constexpr std::array<VkExtensionProperties, 2> instance_extensions{{
    {VK_EXT_DEBUG_REPORT_EXTENSION_NAME, VK_EXT_DEBUG_REPORT_SPEC_VERSION},
    {VK_EXT_DEBUG_UTILS_EXTENSION_NAME, VK_EXT_DEBUG_UTILS_SPEC_VERSION},
}};
static constexpr std::array<VkExtensionProperties, 1> device_extensions{{
    {VK_EXT_DEBUG_MARKER_EXTENSION_NAME, VK_EXT_DEBUG_MARKER_SPEC_VERSION},
}};


// Implement layer version of Vulkan API functions.

void InterceptGetDeviceQueue(
    VkDevice                                    device,
    uint32_t                                    queueFamilyIndex,
    uint32_t                                    queueIndex,
    VkQueue*                                    pQueue) {
  auto layer_data = GetDeviceLayerData(DataKey(device));
  PFN_vkGetDeviceQueue pfn = layer_data->dispatch_table.GetDeviceQueue;
  if (pfn != nullptr) {
    pfn(device, queueFamilyIndex, queueIndex, pQueue);
  }

  InterceptPostGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
}

VkResult InterceptQueueSubmit(
    VkQueue                                     queue,
    uint32_t                                    submitCount,
    const VkSubmitInfo*                         pSubmits,
    VkFence                                     fence) {
  VkResult result = VK_SUCCESS;

  InterceptPreQueueSubmit(queue, submitCount, pSubmits, fence);

  auto layer_data = GetDeviceLayerData(DataKey(queue));
  PFN_vkQueueSubmit pfn = layer_data->dispatch_table.QueueSubmit;
  if (pfn != nullptr) {
    result = pfn(queue, submitCount, pSubmits, fence);
  }

  result = InterceptPostQueueSubmit(queue, submitCount, pSubmits, fence, result);
  return result;
}

VkResult InterceptQueueWaitIdle(
    VkQueue                                     queue) {
  VkResult result = VK_SUCCESS;

  InterceptPreQueueWaitIdle(queue);

  auto layer_data = GetDeviceLayerData(DataKey(queue));
  PFN_vkQueueWaitIdle pfn = layer_data->dispatch_table.QueueWaitIdle;
  if (pfn != nullptr) {
    result = pfn(queue);
  }

  result = InterceptPostQueueWaitIdle(queue, result);
  return result;
}

VkResult InterceptDeviceWaitIdle(
    VkDevice                                    device) {
  VkResult result = VK_SUCCESS;

  InterceptPreDeviceWaitIdle(device);

  auto layer_data = GetDeviceLayerData(DataKey(device));
  PFN_vkDeviceWaitIdle pfn = layer_data->dispatch_table.DeviceWaitIdle;
  if (pfn != nullptr) {
    result = pfn(device);
  }

  result = InterceptPostDeviceWaitIdle(device, result);
  return result;
}

VkResult InterceptQueueBindSparse(
    VkQueue                                     queue,
    uint32_t                                    bindInfoCount,
    const VkBindSparseInfo*                     pBindInfo,
    VkFence                                     fence) {
  VkResult result = VK_SUCCESS;

  InterceptPreQueueBindSparse(queue, bindInfoCount, pBindInfo, fence);

  auto layer_data = GetDeviceLayerData(DataKey(queue));
  PFN_vkQueueBindSparse pfn = layer_data->dispatch_table.QueueBindSparse;
  if (pfn != nullptr) {
    result = pfn(queue, bindInfoCount, pBindInfo, fence);
  }

  result = InterceptPostQueueBindSparse(queue, bindInfoCount, pBindInfo, fence, result);
  return result;
}

VkResult InterceptGetFenceStatus(
    VkDevice                                    device,
    VkFence                                     fence) {
  VkResult result = VK_SUCCESS;

  InterceptPreGetFenceStatus(device, fence);

  auto layer_data = GetDeviceLayerData(DataKey(device));
  PFN_vkGetFenceStatus pfn = layer_data->dispatch_table.GetFenceStatus;
  if (pfn != nullptr) {
    result = pfn(device, fence);
  }

  result = InterceptPostGetFenceStatus(device, fence, result);
  return result;
}

VkResult InterceptWaitForFences(
    VkDevice                                    device,
    uint32_t                                    fenceCount,
    const VkFence*                              pFences,
    VkBool32                                    waitAll,
    uint64_t                                    timeout) {
  VkResult result = VK_SUCCESS;

  InterceptPreWaitForFences(device, fenceCount, pFences, waitAll, timeout);

  auto layer_data = GetDeviceLayerData(DataKey(device));
  PFN_vkWaitForFences pfn = layer_data->dispatch_table.WaitForFences;
  if (pfn != nullptr) {
    result = pfn(device, fenceCount, pFences, waitAll, timeout);
  }

  result = InterceptPostWaitForFences(device, fenceCount, pFences, waitAll, timeout, result);
  return result;
}

VkResult InterceptCreateSemaphore(
    VkDevice                                    device,
    const VkSemaphoreCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSemaphore*                                pSemaphore) {
  VkResult result = VK_SUCCESS;

  InterceptPreCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);

  auto layer_data = GetDeviceLayerData(DataKey(device));
  PFN_vkCreateSemaphore pfn = layer_data->dispatch_table.CreateSemaphore;
  if (pfn != nullptr) {
    result = pfn(device, pCreateInfo, pAllocator, pSemaphore);
  }

  result = InterceptPostCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore, result);
  return result;
}

void InterceptDestroySemaphore(
    VkDevice                                    device,
    VkSemaphore                                 semaphore,
    const VkAllocationCallbacks*                pAllocator) {
  InterceptPreDestroySemaphore(device, semaphore, pAllocator);

  auto layer_data = GetDeviceLayerData(DataKey(device));
  PFN_vkDestroySemaphore pfn = layer_data->dispatch_table.DestroySemaphore;
  if (pfn != nullptr) {
    pfn(device, semaphore, pAllocator);
  }

  InterceptPostDestroySemaphore(device, semaphore, pAllocator);
}

VkResult InterceptGetQueryPoolResults(
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    size_t                                      dataSize,
    void*                                       pData,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags) {
  VkResult result = VK_SUCCESS;

  InterceptPreGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);

  auto layer_data = GetDeviceLayerData(DataKey(device));
  PFN_vkGetQueryPoolResults pfn = layer_data->dispatch_table.GetQueryPoolResults;
  if (pfn != nullptr) {
    result = pfn(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
  }

  result = InterceptPostGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags, result);
  return result;
}

VkResult InterceptCreateShaderModule(
    VkDevice                                    device,
    const VkShaderModuleCreateInfo*             pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkShaderModule*                             pShaderModule) {
  VkResult result = VK_SUCCESS;

  auto layer_data = GetDeviceLayerData(DataKey(device));
  PFN_vkCreateShaderModule pfn = layer_data->dispatch_table.CreateShaderModule;
  if (pfn != nullptr) {
    result = pfn(device, pCreateInfo, pAllocator, pShaderModule);
  }

  result = InterceptPostCreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule, result);
  return result;
}

void InterceptDestroyShaderModule(
    VkDevice                                    device,
    VkShaderModule                              shaderModule,
    const VkAllocationCallbacks*                pAllocator) {
  auto layer_data = GetDeviceLayerData(DataKey(device));
  PFN_vkDestroyShaderModule pfn = layer_data->dispatch_table.DestroyShaderModule;
  if (pfn != nullptr) {
    pfn(device, shaderModule, pAllocator);
  }

  InterceptPostDestroyShaderModule(device, shaderModule, pAllocator);
}

VkResult InterceptCreateGraphicsPipelines(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkGraphicsPipelineCreateInfo*         pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines) {
  VkResult result = VK_SUCCESS;

  auto layer_data = GetDeviceLayerData(DataKey(device));
  PFN_vkCreateGraphicsPipelines pfn = layer_data->dispatch_table.CreateGraphicsPipelines;
  if (pfn != nullptr) {
    result = pfn(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
  }

  result = InterceptPostCreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines, result);
  return result;
}

VkResult InterceptCreateComputePipelines(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkComputePipelineCreateInfo*          pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines) {
  VkResult result = VK_SUCCESS;

  auto layer_data = GetDeviceLayerData(DataKey(device));
  PFN_vkCreateComputePipelines pfn = layer_data->dispatch_table.CreateComputePipelines;
  if (pfn != nullptr) {
    result = pfn(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
  }

  result = InterceptPostCreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines, result);
  return result;
}

void InterceptDestroyPipeline(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    const VkAllocationCallbacks*                pAllocator) {
  InterceptPreDestroyPipeline(device, pipeline, pAllocator);

  auto layer_data = GetDeviceLayerData(DataKey(device));
  PFN_vkDestroyPipeline pfn = layer_data->dispatch_table.DestroyPipeline;
  if (pfn != nullptr) {
    pfn(device, pipeline, pAllocator);
  }

  InterceptPostDestroyPipeline(device, pipeline, pAllocator);
}

VkResult InterceptCreateCommandPool(
    VkDevice                                    device,
    const VkCommandPoolCreateInfo*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkCommandPool*                              pCommandPool) {
  VkResult result = VK_SUCCESS;

  InterceptPreCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);

  auto layer_data = GetDeviceLayerData(DataKey(device));
  PFN_vkCreateCommandPool pfn = layer_data->dispatch_table.CreateCommandPool;
  if (pfn != nullptr) {
    result = pfn(device, pCreateInfo, pAllocator, pCommandPool);
  }

  result = InterceptPostCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool, result);
  return result;
}

void InterceptDestroyCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    const VkAllocationCallbacks*                pAllocator) {
  InterceptPreDestroyCommandPool(device, commandPool, pAllocator);

  auto layer_data = GetDeviceLayerData(DataKey(device));
  PFN_vkDestroyCommandPool pfn = layer_data->dispatch_table.DestroyCommandPool;
  if (pfn != nullptr) {
    pfn(device, commandPool, pAllocator);
  }

  InterceptPostDestroyCommandPool(device, commandPool, pAllocator);
}

VkResult InterceptResetCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolResetFlags                     flags) {
  VkResult result = VK_SUCCESS;

  InterceptPreResetCommandPool(device, commandPool, flags);

  auto layer_data = GetDeviceLayerData(DataKey(device));
  PFN_vkResetCommandPool pfn = layer_data->dispatch_table.ResetCommandPool;
  if (pfn != nullptr) {
    result = pfn(device, commandPool, flags);
  }

  result = InterceptPostResetCommandPool(device, commandPool, flags, result);
  return result;
}

VkResult InterceptAllocateCommandBuffers(
    VkDevice                                    device,
    const VkCommandBufferAllocateInfo*          pAllocateInfo,
    VkCommandBuffer*                            pCommandBuffers) {
  VkResult result = VK_SUCCESS;

  InterceptPreAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);

  auto layer_data = GetDeviceLayerData(DataKey(device));
  PFN_vkAllocateCommandBuffers pfn = layer_data->dispatch_table.AllocateCommandBuffers;
  if (pfn != nullptr) {
    result = pfn(device, pAllocateInfo, pCommandBuffers);
  }

  result = InterceptPostAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers, result);
  return result;
}

void InterceptFreeCommandBuffers(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers) {
  InterceptPreFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);

  auto layer_data = GetDeviceLayerData(DataKey(device));
  PFN_vkFreeCommandBuffers pfn = layer_data->dispatch_table.FreeCommandBuffers;
  if (pfn != nullptr) {
    pfn(device, commandPool, commandBufferCount, pCommandBuffers);
  }

  InterceptPostFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
}

VkResult InterceptBeginCommandBuffer(
    VkCommandBuffer                             commandBuffer,
    const VkCommandBufferBeginInfo*             pBeginInfo) {
  VkResult result = VK_SUCCESS;

  InterceptPreBeginCommandBuffer(commandBuffer, pBeginInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkBeginCommandBuffer pfn = layer_data->dispatch_table.BeginCommandBuffer;
  if (pfn != nullptr) {
    result = pfn(commandBuffer, pBeginInfo);
  }

  result = InterceptPostBeginCommandBuffer(commandBuffer, pBeginInfo, result);
  return result;
}

VkResult InterceptEndCommandBuffer(
    VkCommandBuffer                             commandBuffer) {
  VkResult result = VK_SUCCESS;

  InterceptPreEndCommandBuffer(commandBuffer);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkEndCommandBuffer pfn = layer_data->dispatch_table.EndCommandBuffer;
  if (pfn != nullptr) {
    result = pfn(commandBuffer);
  }

  result = InterceptPostEndCommandBuffer(commandBuffer, result);
  return result;
}

VkResult InterceptResetCommandBuffer(
    VkCommandBuffer                             commandBuffer,
    VkCommandBufferResetFlags                   flags) {
  VkResult result = VK_SUCCESS;

  InterceptPreResetCommandBuffer(commandBuffer, flags);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkResetCommandBuffer pfn = layer_data->dispatch_table.ResetCommandBuffer;
  if (pfn != nullptr) {
    result = pfn(commandBuffer, flags);
  }

  result = InterceptPostResetCommandBuffer(commandBuffer, flags, result);
  return result;
}

void InterceptCmdBindPipeline(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline) {
  InterceptPreCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBindPipeline pfn = layer_data->dispatch_table.CmdBindPipeline;
  if (pfn != nullptr) {
    pfn(commandBuffer, pipelineBindPoint, pipeline);
  }

  InterceptPostCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
}

void InterceptCmdSetViewport(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports) {
  InterceptPreCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetViewport pfn = layer_data->dispatch_table.CmdSetViewport;
  if (pfn != nullptr) {
    pfn(commandBuffer, firstViewport, viewportCount, pViewports);
  }

  InterceptPostCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
}

void InterceptCmdSetScissor(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors) {
  InterceptPreCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetScissor pfn = layer_data->dispatch_table.CmdSetScissor;
  if (pfn != nullptr) {
    pfn(commandBuffer, firstScissor, scissorCount, pScissors);
  }

  InterceptPostCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
}

void InterceptCmdSetLineWidth(
    VkCommandBuffer                             commandBuffer,
    float                                       lineWidth) {
  InterceptPreCmdSetLineWidth(commandBuffer, lineWidth);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetLineWidth pfn = layer_data->dispatch_table.CmdSetLineWidth;
  if (pfn != nullptr) {
    pfn(commandBuffer, lineWidth);
  }

  InterceptPostCmdSetLineWidth(commandBuffer, lineWidth);
}

void InterceptCmdSetDepthBias(
    VkCommandBuffer                             commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor) {
  InterceptPreCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetDepthBias pfn = layer_data->dispatch_table.CmdSetDepthBias;
  if (pfn != nullptr) {
    pfn(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
  }

  InterceptPostCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
}

void InterceptCmdSetBlendConstants(
    VkCommandBuffer                             commandBuffer,
    const float                                 blendConstants[4]) {
  InterceptPreCmdSetBlendConstants(commandBuffer, blendConstants);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetBlendConstants pfn = layer_data->dispatch_table.CmdSetBlendConstants;
  if (pfn != nullptr) {
    pfn(commandBuffer, blendConstants);
  }

  InterceptPostCmdSetBlendConstants(commandBuffer, blendConstants);
}

void InterceptCmdSetDepthBounds(
    VkCommandBuffer                             commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds) {
  InterceptPreCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetDepthBounds pfn = layer_data->dispatch_table.CmdSetDepthBounds;
  if (pfn != nullptr) {
    pfn(commandBuffer, minDepthBounds, maxDepthBounds);
  }

  InterceptPostCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
}

void InterceptCmdSetStencilCompareMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask) {
  InterceptPreCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetStencilCompareMask pfn = layer_data->dispatch_table.CmdSetStencilCompareMask;
  if (pfn != nullptr) {
    pfn(commandBuffer, faceMask, compareMask);
  }

  InterceptPostCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
}

void InterceptCmdSetStencilWriteMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask) {
  InterceptPreCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetStencilWriteMask pfn = layer_data->dispatch_table.CmdSetStencilWriteMask;
  if (pfn != nullptr) {
    pfn(commandBuffer, faceMask, writeMask);
  }

  InterceptPostCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
}

void InterceptCmdSetStencilReference(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference) {
  InterceptPreCmdSetStencilReference(commandBuffer, faceMask, reference);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetStencilReference pfn = layer_data->dispatch_table.CmdSetStencilReference;
  if (pfn != nullptr) {
    pfn(commandBuffer, faceMask, reference);
  }

  InterceptPostCmdSetStencilReference(commandBuffer, faceMask, reference);
}

void InterceptCmdBindDescriptorSets(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    descriptorSetCount,
    const VkDescriptorSet*                      pDescriptorSets,
    uint32_t                                    dynamicOffsetCount,
    const uint32_t*                             pDynamicOffsets) {
  InterceptPreCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBindDescriptorSets pfn = layer_data->dispatch_table.CmdBindDescriptorSets;
  if (pfn != nullptr) {
    pfn(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
  }

  InterceptPostCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
}

void InterceptCmdBindIndexBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType) {
  InterceptPreCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBindIndexBuffer pfn = layer_data->dispatch_table.CmdBindIndexBuffer;
  if (pfn != nullptr) {
    pfn(commandBuffer, buffer, offset, indexType);
  }

  InterceptPostCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
}

void InterceptCmdBindVertexBuffers(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets) {
  InterceptPreCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBindVertexBuffers pfn = layer_data->dispatch_table.CmdBindVertexBuffers;
  if (pfn != nullptr) {
    pfn(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
  }

  InterceptPostCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
}

void InterceptCmdDraw(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance) {
  InterceptPreCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDraw pfn = layer_data->dispatch_table.CmdDraw;
  if (pfn != nullptr) {
    pfn(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
  }

  InterceptPostCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}

void InterceptCmdDrawIndexed(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance) {
  InterceptPreCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDrawIndexed pfn = layer_data->dispatch_table.CmdDrawIndexed;
  if (pfn != nullptr) {
    pfn(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
  }

  InterceptPostCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}

void InterceptCmdDrawIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) {
  InterceptPreCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDrawIndirect pfn = layer_data->dispatch_table.CmdDrawIndirect;
  if (pfn != nullptr) {
    pfn(commandBuffer, buffer, offset, drawCount, stride);
  }

  InterceptPostCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
}

void InterceptCmdDrawIndexedIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) {
  InterceptPreCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDrawIndexedIndirect pfn = layer_data->dispatch_table.CmdDrawIndexedIndirect;
  if (pfn != nullptr) {
    pfn(commandBuffer, buffer, offset, drawCount, stride);
  }

  InterceptPostCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
}

void InterceptCmdDispatch(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) {
  InterceptPreCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDispatch pfn = layer_data->dispatch_table.CmdDispatch;
  if (pfn != nullptr) {
    pfn(commandBuffer, groupCountX, groupCountY, groupCountZ);
  }

  InterceptPostCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
}

void InterceptCmdDispatchIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset) {
  InterceptPreCmdDispatchIndirect(commandBuffer, buffer, offset);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDispatchIndirect pfn = layer_data->dispatch_table.CmdDispatchIndirect;
  if (pfn != nullptr) {
    pfn(commandBuffer, buffer, offset);
  }

  InterceptPostCmdDispatchIndirect(commandBuffer, buffer, offset);
}

void InterceptCmdCopyBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferCopy*                         pRegions) {
  InterceptPreCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdCopyBuffer pfn = layer_data->dispatch_table.CmdCopyBuffer;
  if (pfn != nullptr) {
    pfn(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
  }

  InterceptPostCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
}

void InterceptCmdCopyImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageCopy*                          pRegions) {
  InterceptPreCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdCopyImage pfn = layer_data->dispatch_table.CmdCopyImage;
  if (pfn != nullptr) {
    pfn(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
  }

  InterceptPostCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}

void InterceptCmdBlitImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageBlit*                          pRegions,
    VkFilter                                    filter) {
  InterceptPreCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBlitImage pfn = layer_data->dispatch_table.CmdBlitImage;
  if (pfn != nullptr) {
    pfn(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
  }

  InterceptPostCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
}

void InterceptCmdCopyBufferToImage(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions) {
  InterceptPreCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdCopyBufferToImage pfn = layer_data->dispatch_table.CmdCopyBufferToImage;
  if (pfn != nullptr) {
    pfn(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
  }

  InterceptPostCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
}

void InterceptCmdCopyImageToBuffer(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions) {
  InterceptPreCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdCopyImageToBuffer pfn = layer_data->dispatch_table.CmdCopyImageToBuffer;
  if (pfn != nullptr) {
    pfn(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
  }

  InterceptPostCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
}

void InterceptCmdUpdateBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    const void*                                 pData) {
  InterceptPreCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdUpdateBuffer pfn = layer_data->dispatch_table.CmdUpdateBuffer;
  if (pfn != nullptr) {
    pfn(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
  }

  InterceptPostCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
}

void InterceptCmdFillBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data) {
  InterceptPreCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdFillBuffer pfn = layer_data->dispatch_table.CmdFillBuffer;
  if (pfn != nullptr) {
    pfn(commandBuffer, dstBuffer, dstOffset, size, data);
  }

  InterceptPostCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
}

void InterceptCmdClearColorImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearColorValue*                    pColor,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges) {
  InterceptPreCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdClearColorImage pfn = layer_data->dispatch_table.CmdClearColorImage;
  if (pfn != nullptr) {
    pfn(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
  }

  InterceptPostCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
}

void InterceptCmdClearDepthStencilImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearDepthStencilValue*             pDepthStencil,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges) {
  InterceptPreCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdClearDepthStencilImage pfn = layer_data->dispatch_table.CmdClearDepthStencilImage;
  if (pfn != nullptr) {
    pfn(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
  }

  InterceptPostCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
}

void InterceptCmdClearAttachments(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkClearAttachment*                    pAttachments,
    uint32_t                                    rectCount,
    const VkClearRect*                          pRects) {
  InterceptPreCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdClearAttachments pfn = layer_data->dispatch_table.CmdClearAttachments;
  if (pfn != nullptr) {
    pfn(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
  }

  InterceptPostCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
}

void InterceptCmdResolveImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageResolve*                       pRegions) {
  InterceptPreCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdResolveImage pfn = layer_data->dispatch_table.CmdResolveImage;
  if (pfn != nullptr) {
    pfn(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
  }

  InterceptPostCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}

void InterceptCmdSetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask) {
  InterceptPreCmdSetEvent(commandBuffer, event, stageMask);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetEvent pfn = layer_data->dispatch_table.CmdSetEvent;
  if (pfn != nullptr) {
    pfn(commandBuffer, event, stageMask);
  }

  InterceptPostCmdSetEvent(commandBuffer, event, stageMask);
}

void InterceptCmdResetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask) {
  InterceptPreCmdResetEvent(commandBuffer, event, stageMask);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdResetEvent pfn = layer_data->dispatch_table.CmdResetEvent;
  if (pfn != nullptr) {
    pfn(commandBuffer, event, stageMask);
  }

  InterceptPostCmdResetEvent(commandBuffer, event, stageMask);
}

void InterceptCmdWaitEvents(
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
  InterceptPreCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdWaitEvents pfn = layer_data->dispatch_table.CmdWaitEvents;
  if (pfn != nullptr) {
    pfn(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
  }

  InterceptPostCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}

void InterceptCmdPipelineBarrier(
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
  InterceptPreCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdPipelineBarrier pfn = layer_data->dispatch_table.CmdPipelineBarrier;
  if (pfn != nullptr) {
    pfn(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
  }

  InterceptPostCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}

void InterceptCmdBeginQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags) {
  InterceptPreCmdBeginQuery(commandBuffer, queryPool, query, flags);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBeginQuery pfn = layer_data->dispatch_table.CmdBeginQuery;
  if (pfn != nullptr) {
    pfn(commandBuffer, queryPool, query, flags);
  }

  InterceptPostCmdBeginQuery(commandBuffer, queryPool, query, flags);
}

void InterceptCmdEndQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) {
  InterceptPreCmdEndQuery(commandBuffer, queryPool, query);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdEndQuery pfn = layer_data->dispatch_table.CmdEndQuery;
  if (pfn != nullptr) {
    pfn(commandBuffer, queryPool, query);
  }

  InterceptPostCmdEndQuery(commandBuffer, queryPool, query);
}

void InterceptCmdResetQueryPool(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount) {
  InterceptPreCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdResetQueryPool pfn = layer_data->dispatch_table.CmdResetQueryPool;
  if (pfn != nullptr) {
    pfn(commandBuffer, queryPool, firstQuery, queryCount);
  }

  InterceptPostCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
}

void InterceptCmdWriteTimestamp(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) {
  InterceptPreCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdWriteTimestamp pfn = layer_data->dispatch_table.CmdWriteTimestamp;
  if (pfn != nullptr) {
    pfn(commandBuffer, pipelineStage, queryPool, query);
  }

  InterceptPostCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
}

void InterceptCmdCopyQueryPoolResults(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags) {
  InterceptPreCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdCopyQueryPoolResults pfn = layer_data->dispatch_table.CmdCopyQueryPoolResults;
  if (pfn != nullptr) {
    pfn(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
  }

  InterceptPostCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
}

void InterceptCmdPushConstants(
    VkCommandBuffer                             commandBuffer,
    VkPipelineLayout                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    const void*                                 pValues) {
  InterceptPreCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdPushConstants pfn = layer_data->dispatch_table.CmdPushConstants;
  if (pfn != nullptr) {
    pfn(commandBuffer, layout, stageFlags, offset, size, pValues);
  }

  InterceptPostCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
}

void InterceptCmdBeginRenderPass(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    VkSubpassContents                           contents) {
  InterceptPreCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBeginRenderPass pfn = layer_data->dispatch_table.CmdBeginRenderPass;
  if (pfn != nullptr) {
    pfn(commandBuffer, pRenderPassBegin, contents);
  }

  InterceptPostCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
}

void InterceptCmdNextSubpass(
    VkCommandBuffer                             commandBuffer,
    VkSubpassContents                           contents) {
  InterceptPreCmdNextSubpass(commandBuffer, contents);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdNextSubpass pfn = layer_data->dispatch_table.CmdNextSubpass;
  if (pfn != nullptr) {
    pfn(commandBuffer, contents);
  }

  InterceptPostCmdNextSubpass(commandBuffer, contents);
}

void InterceptCmdEndRenderPass(
    VkCommandBuffer                             commandBuffer) {
  InterceptPreCmdEndRenderPass(commandBuffer);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdEndRenderPass pfn = layer_data->dispatch_table.CmdEndRenderPass;
  if (pfn != nullptr) {
    pfn(commandBuffer);
  }

  InterceptPostCmdEndRenderPass(commandBuffer);
}

void InterceptCmdExecuteCommands(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers) {
  InterceptPreCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdExecuteCommands pfn = layer_data->dispatch_table.CmdExecuteCommands;
  if (pfn != nullptr) {
    pfn(commandBuffer, commandBufferCount, pCommandBuffers);
  }

  InterceptPostCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
}

void InterceptCmdSetDeviceMask(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask) {
  InterceptPreCmdSetDeviceMask(commandBuffer, deviceMask);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetDeviceMask pfn = layer_data->dispatch_table.CmdSetDeviceMask;
  if (pfn != nullptr) {
    pfn(commandBuffer, deviceMask);
  }

  InterceptPostCmdSetDeviceMask(commandBuffer, deviceMask);
}

void InterceptCmdDispatchBase(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) {
  InterceptPreCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDispatchBase pfn = layer_data->dispatch_table.CmdDispatchBase;
  if (pfn != nullptr) {
    pfn(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
  }

  InterceptPostCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

void InterceptGetDeviceQueue2(
    VkDevice                                    device,
    const VkDeviceQueueInfo2*                   pQueueInfo,
    VkQueue*                                    pQueue) {
  InterceptPreGetDeviceQueue2(device, pQueueInfo, pQueue);

  auto layer_data = GetDeviceLayerData(DataKey(device));
  PFN_vkGetDeviceQueue2 pfn = layer_data->dispatch_table.GetDeviceQueue2;
  if (pfn != nullptr) {
    pfn(device, pQueueInfo, pQueue);
  }

  InterceptPostGetDeviceQueue2(device, pQueueInfo, pQueue);
}

void InterceptCmdDrawIndirectCount(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  InterceptPreCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDrawIndirectCount pfn = layer_data->dispatch_table.CmdDrawIndirectCount;
  if (pfn != nullptr) {
    pfn(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
  }

  InterceptPostCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void InterceptCmdDrawIndexedIndirectCount(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  InterceptPreCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDrawIndexedIndirectCount pfn = layer_data->dispatch_table.CmdDrawIndexedIndirectCount;
  if (pfn != nullptr) {
    pfn(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
  }

  InterceptPostCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void InterceptCmdBeginRenderPass2(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo) {
  InterceptPreCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBeginRenderPass2 pfn = layer_data->dispatch_table.CmdBeginRenderPass2;
  if (pfn != nullptr) {
    pfn(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
  }

  InterceptPostCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

void InterceptCmdNextSubpass2(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo,
    const VkSubpassEndInfo*                     pSubpassEndInfo) {
  InterceptPreCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdNextSubpass2 pfn = layer_data->dispatch_table.CmdNextSubpass2;
  if (pfn != nullptr) {
    pfn(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
  }

  InterceptPostCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}

void InterceptCmdEndRenderPass2(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassEndInfo*                     pSubpassEndInfo) {
  InterceptPreCmdEndRenderPass2(commandBuffer, pSubpassEndInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdEndRenderPass2 pfn = layer_data->dispatch_table.CmdEndRenderPass2;
  if (pfn != nullptr) {
    pfn(commandBuffer, pSubpassEndInfo);
  }

  InterceptPostCmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
}

void InterceptCmdSetEvent2(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    const VkDependencyInfo*                     pDependencyInfo) {
  InterceptPreCmdSetEvent2(commandBuffer, event, pDependencyInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetEvent2 pfn = layer_data->dispatch_table.CmdSetEvent2;
  if (pfn != nullptr) {
    pfn(commandBuffer, event, pDependencyInfo);
  }

  InterceptPostCmdSetEvent2(commandBuffer, event, pDependencyInfo);
}

void InterceptCmdResetEvent2(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags2                       stageMask) {
  InterceptPreCmdResetEvent2(commandBuffer, event, stageMask);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdResetEvent2 pfn = layer_data->dispatch_table.CmdResetEvent2;
  if (pfn != nullptr) {
    pfn(commandBuffer, event, stageMask);
  }

  InterceptPostCmdResetEvent2(commandBuffer, event, stageMask);
}

void InterceptCmdWaitEvents2(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    const VkDependencyInfo*                     pDependencyInfos) {
  InterceptPreCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdWaitEvents2 pfn = layer_data->dispatch_table.CmdWaitEvents2;
  if (pfn != nullptr) {
    pfn(commandBuffer, eventCount, pEvents, pDependencyInfos);
  }

  InterceptPostCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
}

void InterceptCmdPipelineBarrier2(
    VkCommandBuffer                             commandBuffer,
    const VkDependencyInfo*                     pDependencyInfo) {
  InterceptPreCmdPipelineBarrier2(commandBuffer, pDependencyInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdPipelineBarrier2 pfn = layer_data->dispatch_table.CmdPipelineBarrier2;
  if (pfn != nullptr) {
    pfn(commandBuffer, pDependencyInfo);
  }

  InterceptPostCmdPipelineBarrier2(commandBuffer, pDependencyInfo);
}

void InterceptCmdWriteTimestamp2(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) {
  InterceptPreCmdWriteTimestamp2(commandBuffer, stage, queryPool, query);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdWriteTimestamp2 pfn = layer_data->dispatch_table.CmdWriteTimestamp2;
  if (pfn != nullptr) {
    pfn(commandBuffer, stage, queryPool, query);
  }

  InterceptPostCmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
}

VkResult InterceptQueueSubmit2(
    VkQueue                                     queue,
    uint32_t                                    submitCount,
    const VkSubmitInfo2*                        pSubmits,
    VkFence                                     fence) {
  VkResult result = VK_SUCCESS;

  InterceptPreQueueSubmit2(queue, submitCount, pSubmits, fence);

  auto layer_data = GetDeviceLayerData(DataKey(queue));
  PFN_vkQueueSubmit2 pfn = layer_data->dispatch_table.QueueSubmit2;
  if (pfn != nullptr) {
    result = pfn(queue, submitCount, pSubmits, fence);
  }

  result = InterceptPostQueueSubmit2(queue, submitCount, pSubmits, fence, result);
  return result;
}

void InterceptCmdCopyBuffer2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferInfo2*                    pCopyBufferInfo) {
  InterceptPreCmdCopyBuffer2(commandBuffer, pCopyBufferInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdCopyBuffer2 pfn = layer_data->dispatch_table.CmdCopyBuffer2;
  if (pfn != nullptr) {
    pfn(commandBuffer, pCopyBufferInfo);
  }

  InterceptPostCmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
}

void InterceptCmdCopyImage2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageInfo2*                     pCopyImageInfo) {
  InterceptPreCmdCopyImage2(commandBuffer, pCopyImageInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdCopyImage2 pfn = layer_data->dispatch_table.CmdCopyImage2;
  if (pfn != nullptr) {
    pfn(commandBuffer, pCopyImageInfo);
  }

  InterceptPostCmdCopyImage2(commandBuffer, pCopyImageInfo);
}

void InterceptCmdCopyBufferToImage2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferToImageInfo2*             pCopyBufferToImageInfo) {
  InterceptPreCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdCopyBufferToImage2 pfn = layer_data->dispatch_table.CmdCopyBufferToImage2;
  if (pfn != nullptr) {
    pfn(commandBuffer, pCopyBufferToImageInfo);
  }

  InterceptPostCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
}

void InterceptCmdCopyImageToBuffer2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageToBufferInfo2*             pCopyImageToBufferInfo) {
  InterceptPreCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdCopyImageToBuffer2 pfn = layer_data->dispatch_table.CmdCopyImageToBuffer2;
  if (pfn != nullptr) {
    pfn(commandBuffer, pCopyImageToBufferInfo);
  }

  InterceptPostCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
}

void InterceptCmdBlitImage2(
    VkCommandBuffer                             commandBuffer,
    const VkBlitImageInfo2*                     pBlitImageInfo) {
  InterceptPreCmdBlitImage2(commandBuffer, pBlitImageInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBlitImage2 pfn = layer_data->dispatch_table.CmdBlitImage2;
  if (pfn != nullptr) {
    pfn(commandBuffer, pBlitImageInfo);
  }

  InterceptPostCmdBlitImage2(commandBuffer, pBlitImageInfo);
}

void InterceptCmdResolveImage2(
    VkCommandBuffer                             commandBuffer,
    const VkResolveImageInfo2*                  pResolveImageInfo) {
  InterceptPreCmdResolveImage2(commandBuffer, pResolveImageInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdResolveImage2 pfn = layer_data->dispatch_table.CmdResolveImage2;
  if (pfn != nullptr) {
    pfn(commandBuffer, pResolveImageInfo);
  }

  InterceptPostCmdResolveImage2(commandBuffer, pResolveImageInfo);
}

void InterceptCmdBeginRendering(
    VkCommandBuffer                             commandBuffer,
    const VkRenderingInfo*                      pRenderingInfo) {
  InterceptPreCmdBeginRendering(commandBuffer, pRenderingInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBeginRendering pfn = layer_data->dispatch_table.CmdBeginRendering;
  if (pfn != nullptr) {
    pfn(commandBuffer, pRenderingInfo);
  }

  InterceptPostCmdBeginRendering(commandBuffer, pRenderingInfo);
}

void InterceptCmdEndRendering(
    VkCommandBuffer                             commandBuffer) {
  InterceptPreCmdEndRendering(commandBuffer);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdEndRendering pfn = layer_data->dispatch_table.CmdEndRendering;
  if (pfn != nullptr) {
    pfn(commandBuffer);
  }

  InterceptPostCmdEndRendering(commandBuffer);
}

void InterceptCmdSetCullMode(
    VkCommandBuffer                             commandBuffer,
    VkCullModeFlags                             cullMode) {
  InterceptPreCmdSetCullMode(commandBuffer, cullMode);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetCullMode pfn = layer_data->dispatch_table.CmdSetCullMode;
  if (pfn != nullptr) {
    pfn(commandBuffer, cullMode);
  }

  InterceptPostCmdSetCullMode(commandBuffer, cullMode);
}

void InterceptCmdSetFrontFace(
    VkCommandBuffer                             commandBuffer,
    VkFrontFace                                 frontFace) {
  InterceptPreCmdSetFrontFace(commandBuffer, frontFace);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetFrontFace pfn = layer_data->dispatch_table.CmdSetFrontFace;
  if (pfn != nullptr) {
    pfn(commandBuffer, frontFace);
  }

  InterceptPostCmdSetFrontFace(commandBuffer, frontFace);
}

void InterceptCmdSetPrimitiveTopology(
    VkCommandBuffer                             commandBuffer,
    VkPrimitiveTopology                         primitiveTopology) {
  InterceptPreCmdSetPrimitiveTopology(commandBuffer, primitiveTopology);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetPrimitiveTopology pfn = layer_data->dispatch_table.CmdSetPrimitiveTopology;
  if (pfn != nullptr) {
    pfn(commandBuffer, primitiveTopology);
  }

  InterceptPostCmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
}

void InterceptCmdSetViewportWithCount(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports) {
  InterceptPreCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetViewportWithCount pfn = layer_data->dispatch_table.CmdSetViewportWithCount;
  if (pfn != nullptr) {
    pfn(commandBuffer, viewportCount, pViewports);
  }

  InterceptPostCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
}

void InterceptCmdSetScissorWithCount(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors) {
  InterceptPreCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetScissorWithCount pfn = layer_data->dispatch_table.CmdSetScissorWithCount;
  if (pfn != nullptr) {
    pfn(commandBuffer, scissorCount, pScissors);
  }

  InterceptPostCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
}

void InterceptCmdBindVertexBuffers2(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes,
    const VkDeviceSize*                         pStrides) {
  InterceptPreCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBindVertexBuffers2 pfn = layer_data->dispatch_table.CmdBindVertexBuffers2;
  if (pfn != nullptr) {
    pfn(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
  }

  InterceptPostCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}

void InterceptCmdSetDepthTestEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthTestEnable) {
  InterceptPreCmdSetDepthTestEnable(commandBuffer, depthTestEnable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetDepthTestEnable pfn = layer_data->dispatch_table.CmdSetDepthTestEnable;
  if (pfn != nullptr) {
    pfn(commandBuffer, depthTestEnable);
  }

  InterceptPostCmdSetDepthTestEnable(commandBuffer, depthTestEnable);
}

void InterceptCmdSetDepthWriteEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthWriteEnable) {
  InterceptPreCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetDepthWriteEnable pfn = layer_data->dispatch_table.CmdSetDepthWriteEnable;
  if (pfn != nullptr) {
    pfn(commandBuffer, depthWriteEnable);
  }

  InterceptPostCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
}

void InterceptCmdSetDepthCompareOp(
    VkCommandBuffer                             commandBuffer,
    VkCompareOp                                 depthCompareOp) {
  InterceptPreCmdSetDepthCompareOp(commandBuffer, depthCompareOp);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetDepthCompareOp pfn = layer_data->dispatch_table.CmdSetDepthCompareOp;
  if (pfn != nullptr) {
    pfn(commandBuffer, depthCompareOp);
  }

  InterceptPostCmdSetDepthCompareOp(commandBuffer, depthCompareOp);
}

void InterceptCmdSetDepthBoundsTestEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBoundsTestEnable) {
  InterceptPreCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetDepthBoundsTestEnable pfn = layer_data->dispatch_table.CmdSetDepthBoundsTestEnable;
  if (pfn != nullptr) {
    pfn(commandBuffer, depthBoundsTestEnable);
  }

  InterceptPostCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
}

void InterceptCmdSetStencilTestEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stencilTestEnable) {
  InterceptPreCmdSetStencilTestEnable(commandBuffer, stencilTestEnable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetStencilTestEnable pfn = layer_data->dispatch_table.CmdSetStencilTestEnable;
  if (pfn != nullptr) {
    pfn(commandBuffer, stencilTestEnable);
  }

  InterceptPostCmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
}

void InterceptCmdSetStencilOp(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp) {
  InterceptPreCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetStencilOp pfn = layer_data->dispatch_table.CmdSetStencilOp;
  if (pfn != nullptr) {
    pfn(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
  }

  InterceptPostCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}

void InterceptCmdSetRasterizerDiscardEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    rasterizerDiscardEnable) {
  InterceptPreCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetRasterizerDiscardEnable pfn = layer_data->dispatch_table.CmdSetRasterizerDiscardEnable;
  if (pfn != nullptr) {
    pfn(commandBuffer, rasterizerDiscardEnable);
  }

  InterceptPostCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
}

void InterceptCmdSetDepthBiasEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBiasEnable) {
  InterceptPreCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetDepthBiasEnable pfn = layer_data->dispatch_table.CmdSetDepthBiasEnable;
  if (pfn != nullptr) {
    pfn(commandBuffer, depthBiasEnable);
  }

  InterceptPostCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
}

void InterceptCmdSetPrimitiveRestartEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    primitiveRestartEnable) {
  InterceptPreCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetPrimitiveRestartEnable pfn = layer_data->dispatch_table.CmdSetPrimitiveRestartEnable;
  if (pfn != nullptr) {
    pfn(commandBuffer, primitiveRestartEnable);
  }

  InterceptPostCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
}

VkResult InterceptAcquireNextImageKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint64_t                                    timeout,
    VkSemaphore                                 semaphore,
    VkFence                                     fence,
    uint32_t*                                   pImageIndex) {
  VkResult result = VK_SUCCESS;

  InterceptPreAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);

  auto layer_data = GetDeviceLayerData(DataKey(device));
  PFN_vkAcquireNextImageKHR pfn = layer_data->dispatch_table.AcquireNextImageKHR;
  if (pfn != nullptr) {
    result = pfn(device, swapchain, timeout, semaphore, fence, pImageIndex);
  }

  result = InterceptPostAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex, result);
  return result;
}

VkResult InterceptQueuePresentKHR(
    VkQueue                                     queue,
    const VkPresentInfoKHR*                     pPresentInfo) {
  VkResult result = VK_SUCCESS;

  InterceptPreQueuePresentKHR(queue, pPresentInfo);

  auto layer_data = GetDeviceLayerData(DataKey(queue));
  PFN_vkQueuePresentKHR pfn = layer_data->dispatch_table.QueuePresentKHR;
  if (pfn != nullptr) {
    result = pfn(queue, pPresentInfo);
  }

  result = InterceptPostQueuePresentKHR(queue, pPresentInfo, result);
  return result;
}

void InterceptCmdBeginVideoCodingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoBeginCodingInfoKHR*            pBeginInfo) {
  InterceptPreCmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBeginVideoCodingKHR pfn = layer_data->dispatch_table.CmdBeginVideoCodingKHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pBeginInfo);
  }

  InterceptPostCmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);
}

void InterceptCmdEndVideoCodingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoEndCodingInfoKHR*              pEndCodingInfo) {
  InterceptPreCmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdEndVideoCodingKHR pfn = layer_data->dispatch_table.CmdEndVideoCodingKHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pEndCodingInfo);
  }

  InterceptPostCmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);
}

void InterceptCmdControlVideoCodingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoCodingControlInfoKHR*          pCodingControlInfo) {
  InterceptPreCmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdControlVideoCodingKHR pfn = layer_data->dispatch_table.CmdControlVideoCodingKHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pCodingControlInfo);
  }

  InterceptPostCmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);
}

void InterceptCmdDecodeVideoKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoDecodeInfoKHR*                 pDecodeInfo) {
  InterceptPreCmdDecodeVideoKHR(commandBuffer, pDecodeInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDecodeVideoKHR pfn = layer_data->dispatch_table.CmdDecodeVideoKHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pDecodeInfo);
  }

  InterceptPostCmdDecodeVideoKHR(commandBuffer, pDecodeInfo);
}

void InterceptCmdBeginRenderingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkRenderingInfo*                      pRenderingInfo) {
  InterceptPreCmdBeginRenderingKHR(commandBuffer, pRenderingInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBeginRenderingKHR pfn = layer_data->dispatch_table.CmdBeginRenderingKHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pRenderingInfo);
  }

  InterceptPostCmdBeginRenderingKHR(commandBuffer, pRenderingInfo);
}

void InterceptCmdEndRenderingKHR(
    VkCommandBuffer                             commandBuffer) {
  InterceptPreCmdEndRenderingKHR(commandBuffer);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdEndRenderingKHR pfn = layer_data->dispatch_table.CmdEndRenderingKHR;
  if (pfn != nullptr) {
    pfn(commandBuffer);
  }

  InterceptPostCmdEndRenderingKHR(commandBuffer);
}

void InterceptCmdSetDeviceMaskKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask) {
  InterceptPreCmdSetDeviceMaskKHR(commandBuffer, deviceMask);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetDeviceMaskKHR pfn = layer_data->dispatch_table.CmdSetDeviceMaskKHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, deviceMask);
  }

  InterceptPostCmdSetDeviceMaskKHR(commandBuffer, deviceMask);
}

void InterceptCmdDispatchBaseKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) {
  InterceptPreCmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDispatchBaseKHR pfn = layer_data->dispatch_table.CmdDispatchBaseKHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
  }

  InterceptPostCmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

void InterceptCmdPushDescriptorSetKHR(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    const VkWriteDescriptorSet*                 pDescriptorWrites) {
  InterceptPreCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdPushDescriptorSetKHR pfn = layer_data->dispatch_table.CmdPushDescriptorSetKHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
  }

  InterceptPostCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
}

void InterceptCmdPushDescriptorSetWithTemplateKHR(
    VkCommandBuffer                             commandBuffer,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    VkPipelineLayout                            layout,
    uint32_t                                    set,
    const void*                                 pData) {
  InterceptPreCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdPushDescriptorSetWithTemplateKHR pfn = layer_data->dispatch_table.CmdPushDescriptorSetWithTemplateKHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
  }

  InterceptPostCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
}

void InterceptCmdBeginRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo) {
  InterceptPreCmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBeginRenderPass2KHR pfn = layer_data->dispatch_table.CmdBeginRenderPass2KHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
  }

  InterceptPostCmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

void InterceptCmdNextSubpass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo,
    const VkSubpassEndInfo*                     pSubpassEndInfo) {
  InterceptPreCmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdNextSubpass2KHR pfn = layer_data->dispatch_table.CmdNextSubpass2KHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
  }

  InterceptPostCmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}

void InterceptCmdEndRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassEndInfo*                     pSubpassEndInfo) {
  InterceptPreCmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdEndRenderPass2KHR pfn = layer_data->dispatch_table.CmdEndRenderPass2KHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pSubpassEndInfo);
  }

  InterceptPostCmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);
}

void InterceptCmdDrawIndirectCountKHR(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  InterceptPreCmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDrawIndirectCountKHR pfn = layer_data->dispatch_table.CmdDrawIndirectCountKHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
  }

  InterceptPostCmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void InterceptCmdDrawIndexedIndirectCountKHR(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  InterceptPreCmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDrawIndexedIndirectCountKHR pfn = layer_data->dispatch_table.CmdDrawIndexedIndirectCountKHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
  }

  InterceptPostCmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VkResult InterceptGetSemaphoreCounterValueKHR(
    VkDevice                                    device,
    VkSemaphore                                 semaphore,
    uint64_t*                                   pValue) {
  VkResult result = VK_SUCCESS;

  InterceptPreGetSemaphoreCounterValueKHR(device, semaphore, pValue);

  auto layer_data = GetDeviceLayerData(DataKey(device));
  PFN_vkGetSemaphoreCounterValueKHR pfn = layer_data->dispatch_table.GetSemaphoreCounterValueKHR;
  if (pfn != nullptr) {
    result = pfn(device, semaphore, pValue);
  }

  result = InterceptPostGetSemaphoreCounterValueKHR(device, semaphore, pValue, result);
  return result;
}

VkResult InterceptWaitSemaphoresKHR(
    VkDevice                                    device,
    const VkSemaphoreWaitInfo*                  pWaitInfo,
    uint64_t                                    timeout) {
  VkResult result = VK_SUCCESS;

  InterceptPreWaitSemaphoresKHR(device, pWaitInfo, timeout);

  auto layer_data = GetDeviceLayerData(DataKey(device));
  PFN_vkWaitSemaphoresKHR pfn = layer_data->dispatch_table.WaitSemaphoresKHR;
  if (pfn != nullptr) {
    result = pfn(device, pWaitInfo, timeout);
  }

  result = InterceptPostWaitSemaphoresKHR(device, pWaitInfo, timeout, result);
  return result;
}

VkResult InterceptSignalSemaphoreKHR(
    VkDevice                                    device,
    const VkSemaphoreSignalInfo*                pSignalInfo) {
  VkResult result = VK_SUCCESS;

  InterceptPreSignalSemaphoreKHR(device, pSignalInfo);

  auto layer_data = GetDeviceLayerData(DataKey(device));
  PFN_vkSignalSemaphoreKHR pfn = layer_data->dispatch_table.SignalSemaphoreKHR;
  if (pfn != nullptr) {
    result = pfn(device, pSignalInfo);
  }

  result = InterceptPostSignalSemaphoreKHR(device, pSignalInfo, result);
  return result;
}

void InterceptCmdSetFragmentShadingRateKHR(
    VkCommandBuffer                             commandBuffer,
    const VkExtent2D*                           pFragmentSize,
    const VkFragmentShadingRateCombinerOpKHR    combinerOps[2]) {
  InterceptPreCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetFragmentShadingRateKHR pfn = layer_data->dispatch_table.CmdSetFragmentShadingRateKHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pFragmentSize, combinerOps);
  }

  InterceptPostCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
}

void InterceptCmdEncodeVideoKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoEncodeInfoKHR*                 pEncodeInfo) {
  InterceptPreCmdEncodeVideoKHR(commandBuffer, pEncodeInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdEncodeVideoKHR pfn = layer_data->dispatch_table.CmdEncodeVideoKHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pEncodeInfo);
  }

  InterceptPostCmdEncodeVideoKHR(commandBuffer, pEncodeInfo);
}

void InterceptCmdSetEvent2KHR(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    const VkDependencyInfo*                     pDependencyInfo) {
  InterceptPreCmdSetEvent2KHR(commandBuffer, event, pDependencyInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetEvent2KHR pfn = layer_data->dispatch_table.CmdSetEvent2KHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, event, pDependencyInfo);
  }

  InterceptPostCmdSetEvent2KHR(commandBuffer, event, pDependencyInfo);
}

void InterceptCmdResetEvent2KHR(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags2                       stageMask) {
  InterceptPreCmdResetEvent2KHR(commandBuffer, event, stageMask);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdResetEvent2KHR pfn = layer_data->dispatch_table.CmdResetEvent2KHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, event, stageMask);
  }

  InterceptPostCmdResetEvent2KHR(commandBuffer, event, stageMask);
}

void InterceptCmdWaitEvents2KHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    const VkDependencyInfo*                     pDependencyInfos) {
  InterceptPreCmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdWaitEvents2KHR pfn = layer_data->dispatch_table.CmdWaitEvents2KHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, eventCount, pEvents, pDependencyInfos);
  }

  InterceptPostCmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos);
}

void InterceptCmdPipelineBarrier2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkDependencyInfo*                     pDependencyInfo) {
  InterceptPreCmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdPipelineBarrier2KHR pfn = layer_data->dispatch_table.CmdPipelineBarrier2KHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pDependencyInfo);
  }

  InterceptPostCmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo);
}

void InterceptCmdWriteTimestamp2KHR(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query) {
  InterceptPreCmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdWriteTimestamp2KHR pfn = layer_data->dispatch_table.CmdWriteTimestamp2KHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, stage, queryPool, query);
  }

  InterceptPostCmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query);
}

VkResult InterceptQueueSubmit2KHR(
    VkQueue                                     queue,
    uint32_t                                    submitCount,
    const VkSubmitInfo2*                        pSubmits,
    VkFence                                     fence) {
  VkResult result = VK_SUCCESS;

  InterceptPreQueueSubmit2KHR(queue, submitCount, pSubmits, fence);

  auto layer_data = GetDeviceLayerData(DataKey(queue));
  PFN_vkQueueSubmit2KHR pfn = layer_data->dispatch_table.QueueSubmit2KHR;
  if (pfn != nullptr) {
    result = pfn(queue, submitCount, pSubmits, fence);
  }

  result = InterceptPostQueueSubmit2KHR(queue, submitCount, pSubmits, fence, result);
  return result;
}

void InterceptCmdWriteBufferMarker2AMD(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker) {
  InterceptPreCmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdWriteBufferMarker2AMD pfn = layer_data->dispatch_table.CmdWriteBufferMarker2AMD;
  if (pfn != nullptr) {
    pfn(commandBuffer, stage, dstBuffer, dstOffset, marker);
  }

  InterceptPostCmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
}

void InterceptCmdCopyBuffer2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferInfo2*                    pCopyBufferInfo) {
  InterceptPreCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdCopyBuffer2KHR pfn = layer_data->dispatch_table.CmdCopyBuffer2KHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pCopyBufferInfo);
  }

  InterceptPostCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);
}

void InterceptCmdCopyImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageInfo2*                     pCopyImageInfo) {
  InterceptPreCmdCopyImage2KHR(commandBuffer, pCopyImageInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdCopyImage2KHR pfn = layer_data->dispatch_table.CmdCopyImage2KHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pCopyImageInfo);
  }

  InterceptPostCmdCopyImage2KHR(commandBuffer, pCopyImageInfo);
}

void InterceptCmdCopyBufferToImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferToImageInfo2*             pCopyBufferToImageInfo) {
  InterceptPreCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdCopyBufferToImage2KHR pfn = layer_data->dispatch_table.CmdCopyBufferToImage2KHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pCopyBufferToImageInfo);
  }

  InterceptPostCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);
}

void InterceptCmdCopyImageToBuffer2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageToBufferInfo2*             pCopyImageToBufferInfo) {
  InterceptPreCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdCopyImageToBuffer2KHR pfn = layer_data->dispatch_table.CmdCopyImageToBuffer2KHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pCopyImageToBufferInfo);
  }

  InterceptPostCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);
}

void InterceptCmdBlitImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkBlitImageInfo2*                     pBlitImageInfo) {
  InterceptPreCmdBlitImage2KHR(commandBuffer, pBlitImageInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBlitImage2KHR pfn = layer_data->dispatch_table.CmdBlitImage2KHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pBlitImageInfo);
  }

  InterceptPostCmdBlitImage2KHR(commandBuffer, pBlitImageInfo);
}

void InterceptCmdResolveImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkResolveImageInfo2*                  pResolveImageInfo) {
  InterceptPreCmdResolveImage2KHR(commandBuffer, pResolveImageInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdResolveImage2KHR pfn = layer_data->dispatch_table.CmdResolveImage2KHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pResolveImageInfo);
  }

  InterceptPostCmdResolveImage2KHR(commandBuffer, pResolveImageInfo);
}

void InterceptCmdTraceRaysIndirect2KHR(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             indirectDeviceAddress) {
  InterceptPreCmdTraceRaysIndirect2KHR(commandBuffer, indirectDeviceAddress);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdTraceRaysIndirect2KHR pfn = layer_data->dispatch_table.CmdTraceRaysIndirect2KHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, indirectDeviceAddress);
  }

  InterceptPostCmdTraceRaysIndirect2KHR(commandBuffer, indirectDeviceAddress);
}

void InterceptCmdBindIndexBuffer2KHR(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkIndexType                                 indexType) {
  InterceptPreCmdBindIndexBuffer2KHR(commandBuffer, buffer, offset, size, indexType);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBindIndexBuffer2KHR pfn = layer_data->dispatch_table.CmdBindIndexBuffer2KHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, buffer, offset, size, indexType);
  }

  InterceptPostCmdBindIndexBuffer2KHR(commandBuffer, buffer, offset, size, indexType);
}

void InterceptCmdBindDescriptorSets2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkBindDescriptorSetsInfoKHR*          pBindDescriptorSetsInfo) {
  InterceptPreCmdBindDescriptorSets2KHR(commandBuffer, pBindDescriptorSetsInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBindDescriptorSets2KHR pfn = layer_data->dispatch_table.CmdBindDescriptorSets2KHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pBindDescriptorSetsInfo);
  }

  InterceptPostCmdBindDescriptorSets2KHR(commandBuffer, pBindDescriptorSetsInfo);
}

void InterceptCmdPushConstants2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkPushConstantsInfoKHR*               pPushConstantsInfo) {
  InterceptPreCmdPushConstants2KHR(commandBuffer, pPushConstantsInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdPushConstants2KHR pfn = layer_data->dispatch_table.CmdPushConstants2KHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pPushConstantsInfo);
  }

  InterceptPostCmdPushConstants2KHR(commandBuffer, pPushConstantsInfo);
}

void InterceptCmdPushDescriptorSet2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkPushDescriptorSetInfoKHR*           pPushDescriptorSetInfo) {
  InterceptPreCmdPushDescriptorSet2KHR(commandBuffer, pPushDescriptorSetInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdPushDescriptorSet2KHR pfn = layer_data->dispatch_table.CmdPushDescriptorSet2KHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pPushDescriptorSetInfo);
  }

  InterceptPostCmdPushDescriptorSet2KHR(commandBuffer, pPushDescriptorSetInfo);
}

void InterceptCmdPushDescriptorSetWithTemplate2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo) {
  InterceptPreCmdPushDescriptorSetWithTemplate2KHR(commandBuffer, pPushDescriptorSetWithTemplateInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdPushDescriptorSetWithTemplate2KHR pfn = layer_data->dispatch_table.CmdPushDescriptorSetWithTemplate2KHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pPushDescriptorSetWithTemplateInfo);
  }

  InterceptPostCmdPushDescriptorSetWithTemplate2KHR(commandBuffer, pPushDescriptorSetWithTemplateInfo);
}

void InterceptCmdSetDescriptorBufferOffsets2EXT(
    VkCommandBuffer                             commandBuffer,
    const VkSetDescriptorBufferOffsetsInfoEXT*  pSetDescriptorBufferOffsetsInfo) {
  InterceptPreCmdSetDescriptorBufferOffsets2EXT(commandBuffer, pSetDescriptorBufferOffsetsInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetDescriptorBufferOffsets2EXT pfn = layer_data->dispatch_table.CmdSetDescriptorBufferOffsets2EXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, pSetDescriptorBufferOffsetsInfo);
  }

  InterceptPostCmdSetDescriptorBufferOffsets2EXT(commandBuffer, pSetDescriptorBufferOffsetsInfo);
}

void InterceptCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    VkCommandBuffer                             commandBuffer,
    const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo) {
  InterceptPreCmdBindDescriptorBufferEmbeddedSamplers2EXT(commandBuffer, pBindDescriptorBufferEmbeddedSamplersInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT pfn = layer_data->dispatch_table.CmdBindDescriptorBufferEmbeddedSamplers2EXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, pBindDescriptorBufferEmbeddedSamplersInfo);
  }

  InterceptPostCmdBindDescriptorBufferEmbeddedSamplers2EXT(commandBuffer, pBindDescriptorBufferEmbeddedSamplersInfo);
}

VkResult InterceptDebugMarkerSetObjectNameEXT(
    VkDevice                                    device,
    const VkDebugMarkerObjectNameInfoEXT*       pNameInfo) {
  VkResult result = VK_SUCCESS;

  InterceptPreDebugMarkerSetObjectNameEXT(device, pNameInfo);

  auto layer_data = GetDeviceLayerData(DataKey(device));
  PFN_vkDebugMarkerSetObjectNameEXT pfn = layer_data->dispatch_table.DebugMarkerSetObjectNameEXT;
  if (pfn != nullptr) {
    result = pfn(device, pNameInfo);
  }

  result = InterceptPostDebugMarkerSetObjectNameEXT(device, pNameInfo, result);
  return result;
}

void InterceptCmdDebugMarkerBeginEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo) {
  InterceptPreCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDebugMarkerBeginEXT pfn = layer_data->dispatch_table.CmdDebugMarkerBeginEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, pMarkerInfo);
  }

  InterceptPostCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
}

void InterceptCmdDebugMarkerEndEXT(
    VkCommandBuffer                             commandBuffer) {
  InterceptPreCmdDebugMarkerEndEXT(commandBuffer);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDebugMarkerEndEXT pfn = layer_data->dispatch_table.CmdDebugMarkerEndEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer);
  }

  InterceptPostCmdDebugMarkerEndEXT(commandBuffer);
}

void InterceptCmdDebugMarkerInsertEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo) {
  InterceptPreCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDebugMarkerInsertEXT pfn = layer_data->dispatch_table.CmdDebugMarkerInsertEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, pMarkerInfo);
  }

  InterceptPostCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
}

void InterceptCmdBindTransformFeedbackBuffersEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes) {
  InterceptPreCmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBindTransformFeedbackBuffersEXT pfn = layer_data->dispatch_table.CmdBindTransformFeedbackBuffersEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
  }

  InterceptPostCmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
}

void InterceptCmdBeginTransformFeedbackEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const VkBuffer*                             pCounterBuffers,
    const VkDeviceSize*                         pCounterBufferOffsets) {
  InterceptPreCmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBeginTransformFeedbackEXT pfn = layer_data->dispatch_table.CmdBeginTransformFeedbackEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
  }

  InterceptPostCmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}

void InterceptCmdEndTransformFeedbackEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const VkBuffer*                             pCounterBuffers,
    const VkDeviceSize*                         pCounterBufferOffsets) {
  InterceptPreCmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdEndTransformFeedbackEXT pfn = layer_data->dispatch_table.CmdEndTransformFeedbackEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
  }

  InterceptPostCmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}

void InterceptCmdBeginQueryIndexedEXT(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags,
    uint32_t                                    index) {
  InterceptPreCmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBeginQueryIndexedEXT pfn = layer_data->dispatch_table.CmdBeginQueryIndexedEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, queryPool, query, flags, index);
  }

  InterceptPostCmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
}

void InterceptCmdEndQueryIndexedEXT(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    uint32_t                                    index) {
  InterceptPreCmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdEndQueryIndexedEXT pfn = layer_data->dispatch_table.CmdEndQueryIndexedEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, queryPool, query, index);
  }

  InterceptPostCmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
}

void InterceptCmdDrawIndirectByteCountEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    VkBuffer                                    counterBuffer,
    VkDeviceSize                                counterBufferOffset,
    uint32_t                                    counterOffset,
    uint32_t                                    vertexStride) {
  InterceptPreCmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDrawIndirectByteCountEXT pfn = layer_data->dispatch_table.CmdDrawIndirectByteCountEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
  }

  InterceptPostCmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
}

void InterceptCmdCuLaunchKernelNVX(
    VkCommandBuffer                             commandBuffer,
    const VkCuLaunchInfoNVX*                    pLaunchInfo) {
  InterceptPreCmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdCuLaunchKernelNVX pfn = layer_data->dispatch_table.CmdCuLaunchKernelNVX;
  if (pfn != nullptr) {
    pfn(commandBuffer, pLaunchInfo);
  }

  InterceptPostCmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);
}

void InterceptCmdDrawIndirectCountAMD(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  InterceptPreCmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDrawIndirectCountAMD pfn = layer_data->dispatch_table.CmdDrawIndirectCountAMD;
  if (pfn != nullptr) {
    pfn(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
  }

  InterceptPostCmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void InterceptCmdDrawIndexedIndirectCountAMD(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  InterceptPreCmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDrawIndexedIndirectCountAMD pfn = layer_data->dispatch_table.CmdDrawIndexedIndirectCountAMD;
  if (pfn != nullptr) {
    pfn(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
  }

  InterceptPostCmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void InterceptCmdBeginConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer,
    const VkConditionalRenderingBeginInfoEXT*   pConditionalRenderingBegin) {
  InterceptPreCmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBeginConditionalRenderingEXT pfn = layer_data->dispatch_table.CmdBeginConditionalRenderingEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, pConditionalRenderingBegin);
  }

  InterceptPostCmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
}

void InterceptCmdEndConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer) {
  InterceptPreCmdEndConditionalRenderingEXT(commandBuffer);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdEndConditionalRenderingEXT pfn = layer_data->dispatch_table.CmdEndConditionalRenderingEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer);
  }

  InterceptPostCmdEndConditionalRenderingEXT(commandBuffer);
}

void InterceptCmdSetViewportWScalingNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewportWScalingNV*                 pViewportWScalings) {
  InterceptPreCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetViewportWScalingNV pfn = layer_data->dispatch_table.CmdSetViewportWScalingNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
  }

  InterceptPostCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
}

void InterceptCmdSetDiscardRectangleEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    const VkRect2D*                             pDiscardRectangles) {
  InterceptPreCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetDiscardRectangleEXT pfn = layer_data->dispatch_table.CmdSetDiscardRectangleEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
  }

  InterceptPostCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
}

void InterceptCmdSetDiscardRectangleEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    discardRectangleEnable) {
  InterceptPreCmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetDiscardRectangleEnableEXT pfn = layer_data->dispatch_table.CmdSetDiscardRectangleEnableEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, discardRectangleEnable);
  }

  InterceptPostCmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable);
}

void InterceptCmdSetDiscardRectangleModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkDiscardRectangleModeEXT                   discardRectangleMode) {
  InterceptPreCmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetDiscardRectangleModeEXT pfn = layer_data->dispatch_table.CmdSetDiscardRectangleModeEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, discardRectangleMode);
  }

  InterceptPostCmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode);
}

VkResult InterceptSetDebugUtilsObjectNameEXT(
    VkDevice                                    device,
    const VkDebugUtilsObjectNameInfoEXT*        pNameInfo) {
  VkResult result = VK_SUCCESS;

  InterceptPreSetDebugUtilsObjectNameEXT(device, pNameInfo);

  auto layer_data = GetDeviceLayerData(DataKey(device));
  PFN_vkSetDebugUtilsObjectNameEXT pfn = layer_data->dispatch_table.SetDebugUtilsObjectNameEXT;
  if (pfn != nullptr) {
    result = pfn(device, pNameInfo);
  }

  result = InterceptPostSetDebugUtilsObjectNameEXT(device, pNameInfo, result);
  return result;
}

void InterceptCmdBeginDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo) {
  InterceptPreCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBeginDebugUtilsLabelEXT pfn = layer_data->dispatch_table.CmdBeginDebugUtilsLabelEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, pLabelInfo);
  }

  InterceptPostCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}

void InterceptCmdEndDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer) {
  InterceptPreCmdEndDebugUtilsLabelEXT(commandBuffer);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdEndDebugUtilsLabelEXT pfn = layer_data->dispatch_table.CmdEndDebugUtilsLabelEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer);
  }

  InterceptPostCmdEndDebugUtilsLabelEXT(commandBuffer);
}

void InterceptCmdInsertDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo) {
  InterceptPreCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdInsertDebugUtilsLabelEXT pfn = layer_data->dispatch_table.CmdInsertDebugUtilsLabelEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, pLabelInfo);
  }

  InterceptPostCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}

#ifdef VK_ENABLE_BETA_EXTENSIONS
void InterceptCmdInitializeGraphScratchMemoryAMDX(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             scratch) {
  InterceptPreCmdInitializeGraphScratchMemoryAMDX(commandBuffer, scratch);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdInitializeGraphScratchMemoryAMDX pfn = layer_data->dispatch_table.CmdInitializeGraphScratchMemoryAMDX;
  if (pfn != nullptr) {
    pfn(commandBuffer, scratch);
  }

  InterceptPostCmdInitializeGraphScratchMemoryAMDX(commandBuffer, scratch);
}
#endif //VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void InterceptCmdDispatchGraphAMDX(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             scratch,
    const VkDispatchGraphCountInfoAMDX*         pCountInfo) {
  InterceptPreCmdDispatchGraphAMDX(commandBuffer, scratch, pCountInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDispatchGraphAMDX pfn = layer_data->dispatch_table.CmdDispatchGraphAMDX;
  if (pfn != nullptr) {
    pfn(commandBuffer, scratch, pCountInfo);
  }

  InterceptPostCmdDispatchGraphAMDX(commandBuffer, scratch, pCountInfo);
}
#endif //VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void InterceptCmdDispatchGraphIndirectAMDX(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             scratch,
    const VkDispatchGraphCountInfoAMDX*         pCountInfo) {
  InterceptPreCmdDispatchGraphIndirectAMDX(commandBuffer, scratch, pCountInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDispatchGraphIndirectAMDX pfn = layer_data->dispatch_table.CmdDispatchGraphIndirectAMDX;
  if (pfn != nullptr) {
    pfn(commandBuffer, scratch, pCountInfo);
  }

  InterceptPostCmdDispatchGraphIndirectAMDX(commandBuffer, scratch, pCountInfo);
}
#endif //VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void InterceptCmdDispatchGraphIndirectCountAMDX(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             scratch,
    VkDeviceAddress                             countInfo) {
  InterceptPreCmdDispatchGraphIndirectCountAMDX(commandBuffer, scratch, countInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDispatchGraphIndirectCountAMDX pfn = layer_data->dispatch_table.CmdDispatchGraphIndirectCountAMDX;
  if (pfn != nullptr) {
    pfn(commandBuffer, scratch, countInfo);
  }

  InterceptPostCmdDispatchGraphIndirectCountAMDX(commandBuffer, scratch, countInfo);
}
#endif //VK_ENABLE_BETA_EXTENSIONS

void InterceptCmdSetSampleLocationsEXT(
    VkCommandBuffer                             commandBuffer,
    const VkSampleLocationsInfoEXT*             pSampleLocationsInfo) {
  InterceptPreCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetSampleLocationsEXT pfn = layer_data->dispatch_table.CmdSetSampleLocationsEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, pSampleLocationsInfo);
  }

  InterceptPostCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
}

void InterceptCmdBindShadingRateImageNV(
    VkCommandBuffer                             commandBuffer,
    VkImageView                                 imageView,
    VkImageLayout                               imageLayout) {
  InterceptPreCmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBindShadingRateImageNV pfn = layer_data->dispatch_table.CmdBindShadingRateImageNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, imageView, imageLayout);
  }

  InterceptPostCmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
}

void InterceptCmdSetViewportShadingRatePaletteNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkShadingRatePaletteNV*               pShadingRatePalettes) {
  InterceptPreCmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetViewportShadingRatePaletteNV pfn = layer_data->dispatch_table.CmdSetViewportShadingRatePaletteNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
  }

  InterceptPostCmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
}

void InterceptCmdSetCoarseSampleOrderNV(
    VkCommandBuffer                             commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    const VkCoarseSampleOrderCustomNV*          pCustomSampleOrders) {
  InterceptPreCmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetCoarseSampleOrderNV pfn = layer_data->dispatch_table.CmdSetCoarseSampleOrderNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
  }

  InterceptPostCmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
}

void InterceptCmdBuildAccelerationStructureNV(
    VkCommandBuffer                             commandBuffer,
    const VkAccelerationStructureInfoNV*        pInfo,
    VkBuffer                                    instanceData,
    VkDeviceSize                                instanceOffset,
    VkBool32                                    update,
    VkAccelerationStructureNV                   dst,
    VkAccelerationStructureNV                   src,
    VkBuffer                                    scratch,
    VkDeviceSize                                scratchOffset) {
  InterceptPreCmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBuildAccelerationStructureNV pfn = layer_data->dispatch_table.CmdBuildAccelerationStructureNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
  }

  InterceptPostCmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
}

void InterceptCmdCopyAccelerationStructureNV(
    VkCommandBuffer                             commandBuffer,
    VkAccelerationStructureNV                   dst,
    VkAccelerationStructureNV                   src,
    VkCopyAccelerationStructureModeKHR          mode) {
  InterceptPreCmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdCopyAccelerationStructureNV pfn = layer_data->dispatch_table.CmdCopyAccelerationStructureNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, dst, src, mode);
  }

  InterceptPostCmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
}

void InterceptCmdTraceRaysNV(
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
  InterceptPreCmdTraceRaysNV(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdTraceRaysNV pfn = layer_data->dispatch_table.CmdTraceRaysNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
  }

  InterceptPostCmdTraceRaysNV(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
}

void InterceptCmdWriteAccelerationStructuresPropertiesNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    accelerationStructureCount,
    const VkAccelerationStructureNV*            pAccelerationStructures,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery) {
  InterceptPreCmdWriteAccelerationStructuresPropertiesNV(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdWriteAccelerationStructuresPropertiesNV pfn = layer_data->dispatch_table.CmdWriteAccelerationStructuresPropertiesNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
  }

  InterceptPostCmdWriteAccelerationStructuresPropertiesNV(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}

void InterceptCmdWriteBufferMarkerAMD(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker) {
  InterceptPreCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdWriteBufferMarkerAMD pfn = layer_data->dispatch_table.CmdWriteBufferMarkerAMD;
  if (pfn != nullptr) {
    pfn(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
  }

  InterceptPostCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
}

void InterceptCmdDrawMeshTasksNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask) {
  InterceptPreCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDrawMeshTasksNV pfn = layer_data->dispatch_table.CmdDrawMeshTasksNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, taskCount, firstTask);
  }

  InterceptPostCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
}

void InterceptCmdDrawMeshTasksIndirectNV(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) {
  InterceptPreCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDrawMeshTasksIndirectNV pfn = layer_data->dispatch_table.CmdDrawMeshTasksIndirectNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, buffer, offset, drawCount, stride);
  }

  InterceptPostCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
}

void InterceptCmdDrawMeshTasksIndirectCountNV(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  InterceptPreCmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDrawMeshTasksIndirectCountNV pfn = layer_data->dispatch_table.CmdDrawMeshTasksIndirectCountNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
  }

  InterceptPostCmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void InterceptCmdSetExclusiveScissorEnableNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    const VkBool32*                             pExclusiveScissorEnables) {
  InterceptPreCmdSetExclusiveScissorEnableNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetExclusiveScissorEnableNV pfn = layer_data->dispatch_table.CmdSetExclusiveScissorEnableNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);
  }

  InterceptPostCmdSetExclusiveScissorEnableNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);
}

void InterceptCmdSetExclusiveScissorNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    const VkRect2D*                             pExclusiveScissors) {
  InterceptPreCmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetExclusiveScissorNV pfn = layer_data->dispatch_table.CmdSetExclusiveScissorNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
  }

  InterceptPostCmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
}

void InterceptCmdSetCheckpointNV(
    VkCommandBuffer                             commandBuffer,
    const void*                                 pCheckpointMarker) {
  InterceptPreCmdSetCheckpointNV(commandBuffer, pCheckpointMarker);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetCheckpointNV pfn = layer_data->dispatch_table.CmdSetCheckpointNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, pCheckpointMarker);
  }

  InterceptPostCmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
}

VkResult InterceptCmdSetPerformanceMarkerINTEL(
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceMarkerInfoINTEL*         pMarkerInfo) {
  VkResult result = VK_SUCCESS;

  InterceptPreCmdSetPerformanceMarkerINTEL(commandBuffer, pMarkerInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetPerformanceMarkerINTEL pfn = layer_data->dispatch_table.CmdSetPerformanceMarkerINTEL;
  if (pfn != nullptr) {
    result = pfn(commandBuffer, pMarkerInfo);
  }

  result = InterceptPostCmdSetPerformanceMarkerINTEL(commandBuffer, pMarkerInfo, result);
  return result;
}

VkResult InterceptCmdSetPerformanceStreamMarkerINTEL(
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceStreamMarkerInfoINTEL*   pMarkerInfo) {
  VkResult result = VK_SUCCESS;

  InterceptPreCmdSetPerformanceStreamMarkerINTEL(commandBuffer, pMarkerInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetPerformanceStreamMarkerINTEL pfn = layer_data->dispatch_table.CmdSetPerformanceStreamMarkerINTEL;
  if (pfn != nullptr) {
    result = pfn(commandBuffer, pMarkerInfo);
  }

  result = InterceptPostCmdSetPerformanceStreamMarkerINTEL(commandBuffer, pMarkerInfo, result);
  return result;
}

VkResult InterceptCmdSetPerformanceOverrideINTEL(
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceOverrideInfoINTEL*       pOverrideInfo) {
  VkResult result = VK_SUCCESS;

  InterceptPreCmdSetPerformanceOverrideINTEL(commandBuffer, pOverrideInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetPerformanceOverrideINTEL pfn = layer_data->dispatch_table.CmdSetPerformanceOverrideINTEL;
  if (pfn != nullptr) {
    result = pfn(commandBuffer, pOverrideInfo);
  }

  result = InterceptPostCmdSetPerformanceOverrideINTEL(commandBuffer, pOverrideInfo, result);
  return result;
}

void InterceptCmdSetLineStippleEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern) {
  InterceptPreCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetLineStippleEXT pfn = layer_data->dispatch_table.CmdSetLineStippleEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, lineStippleFactor, lineStipplePattern);
  }

  InterceptPostCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
}

void InterceptCmdSetCullModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkCullModeFlags                             cullMode) {
  InterceptPreCmdSetCullModeEXT(commandBuffer, cullMode);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetCullModeEXT pfn = layer_data->dispatch_table.CmdSetCullModeEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, cullMode);
  }

  InterceptPostCmdSetCullModeEXT(commandBuffer, cullMode);
}

void InterceptCmdSetFrontFaceEXT(
    VkCommandBuffer                             commandBuffer,
    VkFrontFace                                 frontFace) {
  InterceptPreCmdSetFrontFaceEXT(commandBuffer, frontFace);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetFrontFaceEXT pfn = layer_data->dispatch_table.CmdSetFrontFaceEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, frontFace);
  }

  InterceptPostCmdSetFrontFaceEXT(commandBuffer, frontFace);
}

void InterceptCmdSetPrimitiveTopologyEXT(
    VkCommandBuffer                             commandBuffer,
    VkPrimitiveTopology                         primitiveTopology) {
  InterceptPreCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetPrimitiveTopologyEXT pfn = layer_data->dispatch_table.CmdSetPrimitiveTopologyEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, primitiveTopology);
  }

  InterceptPostCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);
}

void InterceptCmdSetViewportWithCountEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports) {
  InterceptPreCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetViewportWithCountEXT pfn = layer_data->dispatch_table.CmdSetViewportWithCountEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, viewportCount, pViewports);
  }

  InterceptPostCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);
}

void InterceptCmdSetScissorWithCountEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors) {
  InterceptPreCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetScissorWithCountEXT pfn = layer_data->dispatch_table.CmdSetScissorWithCountEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, scissorCount, pScissors);
  }

  InterceptPostCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);
}

void InterceptCmdBindVertexBuffers2EXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes,
    const VkDeviceSize*                         pStrides) {
  InterceptPreCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBindVertexBuffers2EXT pfn = layer_data->dispatch_table.CmdBindVertexBuffers2EXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
  }

  InterceptPostCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}

void InterceptCmdSetDepthTestEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthTestEnable) {
  InterceptPreCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetDepthTestEnableEXT pfn = layer_data->dispatch_table.CmdSetDepthTestEnableEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, depthTestEnable);
  }

  InterceptPostCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);
}

void InterceptCmdSetDepthWriteEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthWriteEnable) {
  InterceptPreCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetDepthWriteEnableEXT pfn = layer_data->dispatch_table.CmdSetDepthWriteEnableEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, depthWriteEnable);
  }

  InterceptPostCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);
}

void InterceptCmdSetDepthCompareOpEXT(
    VkCommandBuffer                             commandBuffer,
    VkCompareOp                                 depthCompareOp) {
  InterceptPreCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetDepthCompareOpEXT pfn = layer_data->dispatch_table.CmdSetDepthCompareOpEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, depthCompareOp);
  }

  InterceptPostCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);
}

void InterceptCmdSetDepthBoundsTestEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBoundsTestEnable) {
  InterceptPreCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetDepthBoundsTestEnableEXT pfn = layer_data->dispatch_table.CmdSetDepthBoundsTestEnableEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, depthBoundsTestEnable);
  }

  InterceptPostCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);
}

void InterceptCmdSetStencilTestEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stencilTestEnable) {
  InterceptPreCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetStencilTestEnableEXT pfn = layer_data->dispatch_table.CmdSetStencilTestEnableEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, stencilTestEnable);
  }

  InterceptPostCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);
}

void InterceptCmdSetStencilOpEXT(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp) {
  InterceptPreCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetStencilOpEXT pfn = layer_data->dispatch_table.CmdSetStencilOpEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
  }

  InterceptPostCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}

void InterceptCmdPreprocessGeneratedCommandsNV(
    VkCommandBuffer                             commandBuffer,
    const VkGeneratedCommandsInfoNV*            pGeneratedCommandsInfo) {
  InterceptPreCmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdPreprocessGeneratedCommandsNV pfn = layer_data->dispatch_table.CmdPreprocessGeneratedCommandsNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, pGeneratedCommandsInfo);
  }

  InterceptPostCmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);
}

void InterceptCmdExecuteGeneratedCommandsNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    isPreprocessed,
    const VkGeneratedCommandsInfoNV*            pGeneratedCommandsInfo) {
  InterceptPreCmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdExecuteGeneratedCommandsNV pfn = layer_data->dispatch_table.CmdExecuteGeneratedCommandsNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
  }

  InterceptPostCmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
}

void InterceptCmdBindPipelineShaderGroupNV(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline,
    uint32_t                                    groupIndex) {
  InterceptPreCmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBindPipelineShaderGroupNV pfn = layer_data->dispatch_table.CmdBindPipelineShaderGroupNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
  }

  InterceptPostCmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
}

void InterceptCmdSetDepthBias2EXT(
    VkCommandBuffer                             commandBuffer,
    const VkDepthBiasInfoEXT*                   pDepthBiasInfo) {
  InterceptPreCmdSetDepthBias2EXT(commandBuffer, pDepthBiasInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetDepthBias2EXT pfn = layer_data->dispatch_table.CmdSetDepthBias2EXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, pDepthBiasInfo);
  }

  InterceptPostCmdSetDepthBias2EXT(commandBuffer, pDepthBiasInfo);
}

void InterceptCmdCudaLaunchKernelNV(
    VkCommandBuffer                             commandBuffer,
    const VkCudaLaunchInfoNV*                   pLaunchInfo) {
  InterceptPreCmdCudaLaunchKernelNV(commandBuffer, pLaunchInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdCudaLaunchKernelNV pfn = layer_data->dispatch_table.CmdCudaLaunchKernelNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, pLaunchInfo);
  }

  InterceptPostCmdCudaLaunchKernelNV(commandBuffer, pLaunchInfo);
}

void InterceptCmdBindDescriptorBuffersEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    bufferCount,
    const VkDescriptorBufferBindingInfoEXT*     pBindingInfos) {
  InterceptPreCmdBindDescriptorBuffersEXT(commandBuffer, bufferCount, pBindingInfos);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBindDescriptorBuffersEXT pfn = layer_data->dispatch_table.CmdBindDescriptorBuffersEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, bufferCount, pBindingInfos);
  }

  InterceptPostCmdBindDescriptorBuffersEXT(commandBuffer, bufferCount, pBindingInfos);
}

void InterceptCmdSetDescriptorBufferOffsetsEXT(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    setCount,
    const uint32_t*                             pBufferIndices,
    const VkDeviceSize*                         pOffsets) {
  InterceptPreCmdSetDescriptorBufferOffsetsEXT(commandBuffer, pipelineBindPoint, layout, firstSet, setCount, pBufferIndices, pOffsets);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetDescriptorBufferOffsetsEXT pfn = layer_data->dispatch_table.CmdSetDescriptorBufferOffsetsEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, pipelineBindPoint, layout, firstSet, setCount, pBufferIndices, pOffsets);
  }

  InterceptPostCmdSetDescriptorBufferOffsetsEXT(commandBuffer, pipelineBindPoint, layout, firstSet, setCount, pBufferIndices, pOffsets);
}

void InterceptCmdBindDescriptorBufferEmbeddedSamplersEXT(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    set) {
  InterceptPreCmdBindDescriptorBufferEmbeddedSamplersEXT(commandBuffer, pipelineBindPoint, layout, set);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBindDescriptorBufferEmbeddedSamplersEXT pfn = layer_data->dispatch_table.CmdBindDescriptorBufferEmbeddedSamplersEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, pipelineBindPoint, layout, set);
  }

  InterceptPostCmdBindDescriptorBufferEmbeddedSamplersEXT(commandBuffer, pipelineBindPoint, layout, set);
}

void InterceptCmdSetFragmentShadingRateEnumNV(
    VkCommandBuffer                             commandBuffer,
    VkFragmentShadingRateNV                     shadingRate,
    const VkFragmentShadingRateCombinerOpKHR    combinerOps[2]) {
  InterceptPreCmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetFragmentShadingRateEnumNV pfn = layer_data->dispatch_table.CmdSetFragmentShadingRateEnumNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, shadingRate, combinerOps);
  }

  InterceptPostCmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);
}

void InterceptCmdSetVertexInputEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexBindingDescriptionCount,
    const VkVertexInputBindingDescription2EXT*  pVertexBindingDescriptions,
    uint32_t                                    vertexAttributeDescriptionCount,
    const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) {
  InterceptPreCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetVertexInputEXT pfn = layer_data->dispatch_table.CmdSetVertexInputEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
  }

  InterceptPostCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
}

void InterceptCmdSubpassShadingHUAWEI(
    VkCommandBuffer                             commandBuffer) {
  InterceptPreCmdSubpassShadingHUAWEI(commandBuffer);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSubpassShadingHUAWEI pfn = layer_data->dispatch_table.CmdSubpassShadingHUAWEI;
  if (pfn != nullptr) {
    pfn(commandBuffer);
  }

  InterceptPostCmdSubpassShadingHUAWEI(commandBuffer);
}

void InterceptCmdBindInvocationMaskHUAWEI(
    VkCommandBuffer                             commandBuffer,
    VkImageView                                 imageView,
    VkImageLayout                               imageLayout) {
  InterceptPreCmdBindInvocationMaskHUAWEI(commandBuffer, imageView, imageLayout);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBindInvocationMaskHUAWEI pfn = layer_data->dispatch_table.CmdBindInvocationMaskHUAWEI;
  if (pfn != nullptr) {
    pfn(commandBuffer, imageView, imageLayout);
  }

  InterceptPostCmdBindInvocationMaskHUAWEI(commandBuffer, imageView, imageLayout);
}

void InterceptCmdSetPatchControlPointsEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    patchControlPoints) {
  InterceptPreCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetPatchControlPointsEXT pfn = layer_data->dispatch_table.CmdSetPatchControlPointsEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, patchControlPoints);
  }

  InterceptPostCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
}

void InterceptCmdSetRasterizerDiscardEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    rasterizerDiscardEnable) {
  InterceptPreCmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetRasterizerDiscardEnableEXT pfn = layer_data->dispatch_table.CmdSetRasterizerDiscardEnableEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, rasterizerDiscardEnable);
  }

  InterceptPostCmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable);
}

void InterceptCmdSetDepthBiasEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBiasEnable) {
  InterceptPreCmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetDepthBiasEnableEXT pfn = layer_data->dispatch_table.CmdSetDepthBiasEnableEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, depthBiasEnable);
  }

  InterceptPostCmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable);
}

void InterceptCmdSetLogicOpEXT(
    VkCommandBuffer                             commandBuffer,
    VkLogicOp                                   logicOp) {
  InterceptPreCmdSetLogicOpEXT(commandBuffer, logicOp);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetLogicOpEXT pfn = layer_data->dispatch_table.CmdSetLogicOpEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, logicOp);
  }

  InterceptPostCmdSetLogicOpEXT(commandBuffer, logicOp);
}

void InterceptCmdSetPrimitiveRestartEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    primitiveRestartEnable) {
  InterceptPreCmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetPrimitiveRestartEnableEXT pfn = layer_data->dispatch_table.CmdSetPrimitiveRestartEnableEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, primitiveRestartEnable);
  }

  InterceptPostCmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable);
}

void                                    InterceptCmdSetColorWriteEnableEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkBool32*                             pColorWriteEnables) {
  InterceptPreCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetColorWriteEnableEXT pfn = layer_data->dispatch_table.CmdSetColorWriteEnableEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, attachmentCount, pColorWriteEnables);
  }

  InterceptPostCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
}

void InterceptCmdDrawMultiEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    drawCount,
    const VkMultiDrawInfoEXT*                   pVertexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride) {
  InterceptPreCmdDrawMultiEXT(commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDrawMultiEXT pfn = layer_data->dispatch_table.CmdDrawMultiEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
  }

  InterceptPostCmdDrawMultiEXT(commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
}

void InterceptCmdDrawMultiIndexedEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    drawCount,
    const VkMultiDrawIndexedInfoEXT*            pIndexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride,
    const int32_t*                              pVertexOffset) {
  InterceptPreCmdDrawMultiIndexedEXT(commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDrawMultiIndexedEXT pfn = layer_data->dispatch_table.CmdDrawMultiIndexedEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
  }

  InterceptPostCmdDrawMultiIndexedEXT(commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
}

void InterceptCmdBuildMicromapsEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkMicromapBuildInfoEXT*               pInfos) {
  InterceptPreCmdBuildMicromapsEXT(commandBuffer, infoCount, pInfos);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBuildMicromapsEXT pfn = layer_data->dispatch_table.CmdBuildMicromapsEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, infoCount, pInfos);
  }

  InterceptPostCmdBuildMicromapsEXT(commandBuffer, infoCount, pInfos);
}

void InterceptCmdCopyMicromapEXT(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMicromapInfoEXT*                pInfo) {
  InterceptPreCmdCopyMicromapEXT(commandBuffer, pInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdCopyMicromapEXT pfn = layer_data->dispatch_table.CmdCopyMicromapEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, pInfo);
  }

  InterceptPostCmdCopyMicromapEXT(commandBuffer, pInfo);
}

void InterceptCmdCopyMicromapToMemoryEXT(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMicromapToMemoryInfoEXT*        pInfo) {
  InterceptPreCmdCopyMicromapToMemoryEXT(commandBuffer, pInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdCopyMicromapToMemoryEXT pfn = layer_data->dispatch_table.CmdCopyMicromapToMemoryEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, pInfo);
  }

  InterceptPostCmdCopyMicromapToMemoryEXT(commandBuffer, pInfo);
}

void InterceptCmdCopyMemoryToMicromapEXT(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMemoryToMicromapInfoEXT*        pInfo) {
  InterceptPreCmdCopyMemoryToMicromapEXT(commandBuffer, pInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdCopyMemoryToMicromapEXT pfn = layer_data->dispatch_table.CmdCopyMemoryToMicromapEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, pInfo);
  }

  InterceptPostCmdCopyMemoryToMicromapEXT(commandBuffer, pInfo);
}

void InterceptCmdWriteMicromapsPropertiesEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    micromapCount,
    const VkMicromapEXT*                        pMicromaps,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery) {
  InterceptPreCmdWriteMicromapsPropertiesEXT(commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdWriteMicromapsPropertiesEXT pfn = layer_data->dispatch_table.CmdWriteMicromapsPropertiesEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);
  }

  InterceptPostCmdWriteMicromapsPropertiesEXT(commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);
}

void InterceptCmdDrawClusterHUAWEI(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) {
  InterceptPreCmdDrawClusterHUAWEI(commandBuffer, groupCountX, groupCountY, groupCountZ);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDrawClusterHUAWEI pfn = layer_data->dispatch_table.CmdDrawClusterHUAWEI;
  if (pfn != nullptr) {
    pfn(commandBuffer, groupCountX, groupCountY, groupCountZ);
  }

  InterceptPostCmdDrawClusterHUAWEI(commandBuffer, groupCountX, groupCountY, groupCountZ);
}

void InterceptCmdDrawClusterIndirectHUAWEI(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset) {
  InterceptPreCmdDrawClusterIndirectHUAWEI(commandBuffer, buffer, offset);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDrawClusterIndirectHUAWEI pfn = layer_data->dispatch_table.CmdDrawClusterIndirectHUAWEI;
  if (pfn != nullptr) {
    pfn(commandBuffer, buffer, offset);
  }

  InterceptPostCmdDrawClusterIndirectHUAWEI(commandBuffer, buffer, offset);
}

void InterceptCmdCopyMemoryIndirectNV(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             copyBufferAddress,
    uint32_t                                    copyCount,
    uint32_t                                    stride) {
  InterceptPreCmdCopyMemoryIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdCopyMemoryIndirectNV pfn = layer_data->dispatch_table.CmdCopyMemoryIndirectNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, copyBufferAddress, copyCount, stride);
  }

  InterceptPostCmdCopyMemoryIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride);
}

void InterceptCmdCopyMemoryToImageIndirectNV(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             copyBufferAddress,
    uint32_t                                    copyCount,
    uint32_t                                    stride,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    const VkImageSubresourceLayers*             pImageSubresources) {
  InterceptPreCmdCopyMemoryToImageIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride, dstImage, dstImageLayout, pImageSubresources);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdCopyMemoryToImageIndirectNV pfn = layer_data->dispatch_table.CmdCopyMemoryToImageIndirectNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, copyBufferAddress, copyCount, stride, dstImage, dstImageLayout, pImageSubresources);
  }

  InterceptPostCmdCopyMemoryToImageIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride, dstImage, dstImageLayout, pImageSubresources);
}

void InterceptCmdDecompressMemoryNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    decompressRegionCount,
    const VkDecompressMemoryRegionNV*           pDecompressMemoryRegions) {
  InterceptPreCmdDecompressMemoryNV(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDecompressMemoryNV pfn = layer_data->dispatch_table.CmdDecompressMemoryNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
  }

  InterceptPostCmdDecompressMemoryNV(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
}

void InterceptCmdDecompressMemoryIndirectCountNV(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             indirectCommandsAddress,
    VkDeviceAddress                             indirectCommandsCountAddress,
    uint32_t                                    stride) {
  InterceptPreCmdDecompressMemoryIndirectCountNV(commandBuffer, indirectCommandsAddress, indirectCommandsCountAddress, stride);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDecompressMemoryIndirectCountNV pfn = layer_data->dispatch_table.CmdDecompressMemoryIndirectCountNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, indirectCommandsAddress, indirectCommandsCountAddress, stride);
  }

  InterceptPostCmdDecompressMemoryIndirectCountNV(commandBuffer, indirectCommandsAddress, indirectCommandsCountAddress, stride);
}

void InterceptCmdUpdatePipelineIndirectBufferNV(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline) {
  InterceptPreCmdUpdatePipelineIndirectBufferNV(commandBuffer, pipelineBindPoint, pipeline);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdUpdatePipelineIndirectBufferNV pfn = layer_data->dispatch_table.CmdUpdatePipelineIndirectBufferNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, pipelineBindPoint, pipeline);
  }

  InterceptPostCmdUpdatePipelineIndirectBufferNV(commandBuffer, pipelineBindPoint, pipeline);
}

void InterceptCmdSetTessellationDomainOriginEXT(
    VkCommandBuffer                             commandBuffer,
    VkTessellationDomainOrigin                  domainOrigin) {
  InterceptPreCmdSetTessellationDomainOriginEXT(commandBuffer, domainOrigin);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetTessellationDomainOriginEXT pfn = layer_data->dispatch_table.CmdSetTessellationDomainOriginEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, domainOrigin);
  }

  InterceptPostCmdSetTessellationDomainOriginEXT(commandBuffer, domainOrigin);
}

void InterceptCmdSetDepthClampEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthClampEnable) {
  InterceptPreCmdSetDepthClampEnableEXT(commandBuffer, depthClampEnable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetDepthClampEnableEXT pfn = layer_data->dispatch_table.CmdSetDepthClampEnableEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, depthClampEnable);
  }

  InterceptPostCmdSetDepthClampEnableEXT(commandBuffer, depthClampEnable);
}

void InterceptCmdSetPolygonModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkPolygonMode                               polygonMode) {
  InterceptPreCmdSetPolygonModeEXT(commandBuffer, polygonMode);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetPolygonModeEXT pfn = layer_data->dispatch_table.CmdSetPolygonModeEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, polygonMode);
  }

  InterceptPostCmdSetPolygonModeEXT(commandBuffer, polygonMode);
}

void InterceptCmdSetRasterizationSamplesEXT(
    VkCommandBuffer                             commandBuffer,
    VkSampleCountFlagBits                       rasterizationSamples) {
  InterceptPreCmdSetRasterizationSamplesEXT(commandBuffer, rasterizationSamples);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetRasterizationSamplesEXT pfn = layer_data->dispatch_table.CmdSetRasterizationSamplesEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, rasterizationSamples);
  }

  InterceptPostCmdSetRasterizationSamplesEXT(commandBuffer, rasterizationSamples);
}

void InterceptCmdSetSampleMaskEXT(
    VkCommandBuffer                             commandBuffer,
    VkSampleCountFlagBits                       samples,
    const VkSampleMask*                         pSampleMask) {
  InterceptPreCmdSetSampleMaskEXT(commandBuffer, samples, pSampleMask);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetSampleMaskEXT pfn = layer_data->dispatch_table.CmdSetSampleMaskEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, samples, pSampleMask);
  }

  InterceptPostCmdSetSampleMaskEXT(commandBuffer, samples, pSampleMask);
}

void InterceptCmdSetAlphaToCoverageEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    alphaToCoverageEnable) {
  InterceptPreCmdSetAlphaToCoverageEnableEXT(commandBuffer, alphaToCoverageEnable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetAlphaToCoverageEnableEXT pfn = layer_data->dispatch_table.CmdSetAlphaToCoverageEnableEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, alphaToCoverageEnable);
  }

  InterceptPostCmdSetAlphaToCoverageEnableEXT(commandBuffer, alphaToCoverageEnable);
}

void InterceptCmdSetAlphaToOneEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    alphaToOneEnable) {
  InterceptPreCmdSetAlphaToOneEnableEXT(commandBuffer, alphaToOneEnable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetAlphaToOneEnableEXT pfn = layer_data->dispatch_table.CmdSetAlphaToOneEnableEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, alphaToOneEnable);
  }

  InterceptPostCmdSetAlphaToOneEnableEXT(commandBuffer, alphaToOneEnable);
}

void InterceptCmdSetLogicOpEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    logicOpEnable) {
  InterceptPreCmdSetLogicOpEnableEXT(commandBuffer, logicOpEnable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetLogicOpEnableEXT pfn = layer_data->dispatch_table.CmdSetLogicOpEnableEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, logicOpEnable);
  }

  InterceptPostCmdSetLogicOpEnableEXT(commandBuffer, logicOpEnable);
}

void InterceptCmdSetColorBlendEnableEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkBool32*                             pColorBlendEnables) {
  InterceptPreCmdSetColorBlendEnableEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetColorBlendEnableEXT pfn = layer_data->dispatch_table.CmdSetColorBlendEnableEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
  }

  InterceptPostCmdSetColorBlendEnableEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
}

void InterceptCmdSetColorBlendEquationEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorBlendEquationEXT*              pColorBlendEquations) {
  InterceptPreCmdSetColorBlendEquationEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetColorBlendEquationEXT pfn = layer_data->dispatch_table.CmdSetColorBlendEquationEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
  }

  InterceptPostCmdSetColorBlendEquationEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
}

void InterceptCmdSetColorWriteMaskEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorComponentFlags*                pColorWriteMasks) {
  InterceptPreCmdSetColorWriteMaskEXT(commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetColorWriteMaskEXT pfn = layer_data->dispatch_table.CmdSetColorWriteMaskEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
  }

  InterceptPostCmdSetColorWriteMaskEXT(commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
}

void InterceptCmdSetRasterizationStreamEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    rasterizationStream) {
  InterceptPreCmdSetRasterizationStreamEXT(commandBuffer, rasterizationStream);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetRasterizationStreamEXT pfn = layer_data->dispatch_table.CmdSetRasterizationStreamEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, rasterizationStream);
  }

  InterceptPostCmdSetRasterizationStreamEXT(commandBuffer, rasterizationStream);
}

void InterceptCmdSetConservativeRasterizationModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkConservativeRasterizationModeEXT          conservativeRasterizationMode) {
  InterceptPreCmdSetConservativeRasterizationModeEXT(commandBuffer, conservativeRasterizationMode);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetConservativeRasterizationModeEXT pfn = layer_data->dispatch_table.CmdSetConservativeRasterizationModeEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, conservativeRasterizationMode);
  }

  InterceptPostCmdSetConservativeRasterizationModeEXT(commandBuffer, conservativeRasterizationMode);
}

void InterceptCmdSetExtraPrimitiveOverestimationSizeEXT(
    VkCommandBuffer                             commandBuffer,
    float                                       extraPrimitiveOverestimationSize) {
  InterceptPreCmdSetExtraPrimitiveOverestimationSizeEXT(commandBuffer, extraPrimitiveOverestimationSize);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetExtraPrimitiveOverestimationSizeEXT pfn = layer_data->dispatch_table.CmdSetExtraPrimitiveOverestimationSizeEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, extraPrimitiveOverestimationSize);
  }

  InterceptPostCmdSetExtraPrimitiveOverestimationSizeEXT(commandBuffer, extraPrimitiveOverestimationSize);
}

void InterceptCmdSetDepthClipEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthClipEnable) {
  InterceptPreCmdSetDepthClipEnableEXT(commandBuffer, depthClipEnable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetDepthClipEnableEXT pfn = layer_data->dispatch_table.CmdSetDepthClipEnableEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, depthClipEnable);
  }

  InterceptPostCmdSetDepthClipEnableEXT(commandBuffer, depthClipEnable);
}

void InterceptCmdSetSampleLocationsEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    sampleLocationsEnable) {
  InterceptPreCmdSetSampleLocationsEnableEXT(commandBuffer, sampleLocationsEnable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetSampleLocationsEnableEXT pfn = layer_data->dispatch_table.CmdSetSampleLocationsEnableEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, sampleLocationsEnable);
  }

  InterceptPostCmdSetSampleLocationsEnableEXT(commandBuffer, sampleLocationsEnable);
}

void InterceptCmdSetColorBlendAdvancedEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorBlendAdvancedEXT*              pColorBlendAdvanced) {
  InterceptPreCmdSetColorBlendAdvancedEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetColorBlendAdvancedEXT pfn = layer_data->dispatch_table.CmdSetColorBlendAdvancedEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
  }

  InterceptPostCmdSetColorBlendAdvancedEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
}

void InterceptCmdSetProvokingVertexModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkProvokingVertexModeEXT                    provokingVertexMode) {
  InterceptPreCmdSetProvokingVertexModeEXT(commandBuffer, provokingVertexMode);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetProvokingVertexModeEXT pfn = layer_data->dispatch_table.CmdSetProvokingVertexModeEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, provokingVertexMode);
  }

  InterceptPostCmdSetProvokingVertexModeEXT(commandBuffer, provokingVertexMode);
}

void InterceptCmdSetLineRasterizationModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkLineRasterizationModeEXT                  lineRasterizationMode) {
  InterceptPreCmdSetLineRasterizationModeEXT(commandBuffer, lineRasterizationMode);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetLineRasterizationModeEXT pfn = layer_data->dispatch_table.CmdSetLineRasterizationModeEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, lineRasterizationMode);
  }

  InterceptPostCmdSetLineRasterizationModeEXT(commandBuffer, lineRasterizationMode);
}

void InterceptCmdSetLineStippleEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stippledLineEnable) {
  InterceptPreCmdSetLineStippleEnableEXT(commandBuffer, stippledLineEnable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetLineStippleEnableEXT pfn = layer_data->dispatch_table.CmdSetLineStippleEnableEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, stippledLineEnable);
  }

  InterceptPostCmdSetLineStippleEnableEXT(commandBuffer, stippledLineEnable);
}

void InterceptCmdSetDepthClipNegativeOneToOneEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    negativeOneToOne) {
  InterceptPreCmdSetDepthClipNegativeOneToOneEXT(commandBuffer, negativeOneToOne);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetDepthClipNegativeOneToOneEXT pfn = layer_data->dispatch_table.CmdSetDepthClipNegativeOneToOneEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, negativeOneToOne);
  }

  InterceptPostCmdSetDepthClipNegativeOneToOneEXT(commandBuffer, negativeOneToOne);
}

void InterceptCmdSetViewportWScalingEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    viewportWScalingEnable) {
  InterceptPreCmdSetViewportWScalingEnableNV(commandBuffer, viewportWScalingEnable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetViewportWScalingEnableNV pfn = layer_data->dispatch_table.CmdSetViewportWScalingEnableNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, viewportWScalingEnable);
  }

  InterceptPostCmdSetViewportWScalingEnableNV(commandBuffer, viewportWScalingEnable);
}

void InterceptCmdSetViewportSwizzleNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewportSwizzleNV*                  pViewportSwizzles) {
  InterceptPreCmdSetViewportSwizzleNV(commandBuffer, firstViewport, viewportCount, pViewportSwizzles);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetViewportSwizzleNV pfn = layer_data->dispatch_table.CmdSetViewportSwizzleNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
  }

  InterceptPostCmdSetViewportSwizzleNV(commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
}

void InterceptCmdSetCoverageToColorEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    coverageToColorEnable) {
  InterceptPreCmdSetCoverageToColorEnableNV(commandBuffer, coverageToColorEnable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetCoverageToColorEnableNV pfn = layer_data->dispatch_table.CmdSetCoverageToColorEnableNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, coverageToColorEnable);
  }

  InterceptPostCmdSetCoverageToColorEnableNV(commandBuffer, coverageToColorEnable);
}

void InterceptCmdSetCoverageToColorLocationNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    coverageToColorLocation) {
  InterceptPreCmdSetCoverageToColorLocationNV(commandBuffer, coverageToColorLocation);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetCoverageToColorLocationNV pfn = layer_data->dispatch_table.CmdSetCoverageToColorLocationNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, coverageToColorLocation);
  }

  InterceptPostCmdSetCoverageToColorLocationNV(commandBuffer, coverageToColorLocation);
}

void InterceptCmdSetCoverageModulationModeNV(
    VkCommandBuffer                             commandBuffer,
    VkCoverageModulationModeNV                  coverageModulationMode) {
  InterceptPreCmdSetCoverageModulationModeNV(commandBuffer, coverageModulationMode);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetCoverageModulationModeNV pfn = layer_data->dispatch_table.CmdSetCoverageModulationModeNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, coverageModulationMode);
  }

  InterceptPostCmdSetCoverageModulationModeNV(commandBuffer, coverageModulationMode);
}

void InterceptCmdSetCoverageModulationTableEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    coverageModulationTableEnable) {
  InterceptPreCmdSetCoverageModulationTableEnableNV(commandBuffer, coverageModulationTableEnable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetCoverageModulationTableEnableNV pfn = layer_data->dispatch_table.CmdSetCoverageModulationTableEnableNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, coverageModulationTableEnable);
  }

  InterceptPostCmdSetCoverageModulationTableEnableNV(commandBuffer, coverageModulationTableEnable);
}

void InterceptCmdSetCoverageModulationTableNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    coverageModulationTableCount,
    const float*                                pCoverageModulationTable) {
  InterceptPreCmdSetCoverageModulationTableNV(commandBuffer, coverageModulationTableCount, pCoverageModulationTable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetCoverageModulationTableNV pfn = layer_data->dispatch_table.CmdSetCoverageModulationTableNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
  }

  InterceptPostCmdSetCoverageModulationTableNV(commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
}

void InterceptCmdSetShadingRateImageEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    shadingRateImageEnable) {
  InterceptPreCmdSetShadingRateImageEnableNV(commandBuffer, shadingRateImageEnable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetShadingRateImageEnableNV pfn = layer_data->dispatch_table.CmdSetShadingRateImageEnableNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, shadingRateImageEnable);
  }

  InterceptPostCmdSetShadingRateImageEnableNV(commandBuffer, shadingRateImageEnable);
}

void InterceptCmdSetRepresentativeFragmentTestEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    representativeFragmentTestEnable) {
  InterceptPreCmdSetRepresentativeFragmentTestEnableNV(commandBuffer, representativeFragmentTestEnable);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetRepresentativeFragmentTestEnableNV pfn = layer_data->dispatch_table.CmdSetRepresentativeFragmentTestEnableNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, representativeFragmentTestEnable);
  }

  InterceptPostCmdSetRepresentativeFragmentTestEnableNV(commandBuffer, representativeFragmentTestEnable);
}

void InterceptCmdSetCoverageReductionModeNV(
    VkCommandBuffer                             commandBuffer,
    VkCoverageReductionModeNV                   coverageReductionMode) {
  InterceptPreCmdSetCoverageReductionModeNV(commandBuffer, coverageReductionMode);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetCoverageReductionModeNV pfn = layer_data->dispatch_table.CmdSetCoverageReductionModeNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, coverageReductionMode);
  }

  InterceptPostCmdSetCoverageReductionModeNV(commandBuffer, coverageReductionMode);
}

void InterceptCmdOpticalFlowExecuteNV(
    VkCommandBuffer                             commandBuffer,
    VkOpticalFlowSessionNV                      session,
    const VkOpticalFlowExecuteInfoNV*           pExecuteInfo) {
  InterceptPreCmdOpticalFlowExecuteNV(commandBuffer, session, pExecuteInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdOpticalFlowExecuteNV pfn = layer_data->dispatch_table.CmdOpticalFlowExecuteNV;
  if (pfn != nullptr) {
    pfn(commandBuffer, session, pExecuteInfo);
  }

  InterceptPostCmdOpticalFlowExecuteNV(commandBuffer, session, pExecuteInfo);
}

void InterceptCmdBindShadersEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    stageCount,
    const VkShaderStageFlagBits*                pStages,
    const VkShaderEXT*                          pShaders) {
  InterceptPreCmdBindShadersEXT(commandBuffer, stageCount, pStages, pShaders);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBindShadersEXT pfn = layer_data->dispatch_table.CmdBindShadersEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, stageCount, pStages, pShaders);
  }

  InterceptPostCmdBindShadersEXT(commandBuffer, stageCount, pStages, pShaders);
}

void InterceptCmdSetAttachmentFeedbackLoopEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkImageAspectFlags                          aspectMask) {
  InterceptPreCmdSetAttachmentFeedbackLoopEnableEXT(commandBuffer, aspectMask);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetAttachmentFeedbackLoopEnableEXT pfn = layer_data->dispatch_table.CmdSetAttachmentFeedbackLoopEnableEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, aspectMask);
  }

  InterceptPostCmdSetAttachmentFeedbackLoopEnableEXT(commandBuffer, aspectMask);
}

void InterceptCmdBuildAccelerationStructuresKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) {
  InterceptPreCmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBuildAccelerationStructuresKHR pfn = layer_data->dispatch_table.CmdBuildAccelerationStructuresKHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
  }

  InterceptPostCmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
}

void InterceptCmdBuildAccelerationStructuresIndirectKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkDeviceAddress*                      pIndirectDeviceAddresses,
    const uint32_t*                             pIndirectStrides,
    const uint32_t* const*                      ppMaxPrimitiveCounts) {
  InterceptPreCmdBuildAccelerationStructuresIndirectKHR(commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdBuildAccelerationStructuresIndirectKHR pfn = layer_data->dispatch_table.CmdBuildAccelerationStructuresIndirectKHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
  }

  InterceptPostCmdBuildAccelerationStructuresIndirectKHR(commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
}

void InterceptCmdCopyAccelerationStructureKHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyAccelerationStructureInfoKHR*   pInfo) {
  InterceptPreCmdCopyAccelerationStructureKHR(commandBuffer, pInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdCopyAccelerationStructureKHR pfn = layer_data->dispatch_table.CmdCopyAccelerationStructureKHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pInfo);
  }

  InterceptPostCmdCopyAccelerationStructureKHR(commandBuffer, pInfo);
}

void InterceptCmdCopyAccelerationStructureToMemoryKHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) {
  InterceptPreCmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdCopyAccelerationStructureToMemoryKHR pfn = layer_data->dispatch_table.CmdCopyAccelerationStructureToMemoryKHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pInfo);
  }

  InterceptPostCmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);
}

void InterceptCmdCopyMemoryToAccelerationStructureKHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) {
  InterceptPreCmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdCopyMemoryToAccelerationStructureKHR pfn = layer_data->dispatch_table.CmdCopyMemoryToAccelerationStructureKHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pInfo);
  }

  InterceptPostCmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);
}

void InterceptCmdWriteAccelerationStructuresPropertiesKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    accelerationStructureCount,
    const VkAccelerationStructureKHR*           pAccelerationStructures,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery) {
  InterceptPreCmdWriteAccelerationStructuresPropertiesKHR(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdWriteAccelerationStructuresPropertiesKHR pfn = layer_data->dispatch_table.CmdWriteAccelerationStructuresPropertiesKHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
  }

  InterceptPostCmdWriteAccelerationStructuresPropertiesKHR(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}

void InterceptCmdTraceRaysKHR(
    VkCommandBuffer                             commandBuffer,
    const VkStridedDeviceAddressRegionKHR*      pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pCallableShaderBindingTable,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth) {
  InterceptPreCmdTraceRaysKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdTraceRaysKHR pfn = layer_data->dispatch_table.CmdTraceRaysKHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
  }

  InterceptPostCmdTraceRaysKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
}

void InterceptCmdTraceRaysIndirectKHR(
    VkCommandBuffer                             commandBuffer,
    const VkStridedDeviceAddressRegionKHR*      pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pCallableShaderBindingTable,
    VkDeviceAddress                             indirectDeviceAddress) {
  InterceptPreCmdTraceRaysIndirectKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdTraceRaysIndirectKHR pfn = layer_data->dispatch_table.CmdTraceRaysIndirectKHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
  }

  InterceptPostCmdTraceRaysIndirectKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
}

void InterceptCmdSetRayTracingPipelineStackSizeKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    pipelineStackSize) {
  InterceptPreCmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdSetRayTracingPipelineStackSizeKHR pfn = layer_data->dispatch_table.CmdSetRayTracingPipelineStackSizeKHR;
  if (pfn != nullptr) {
    pfn(commandBuffer, pipelineStackSize);
  }

  InterceptPostCmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);
}

void InterceptCmdDrawMeshTasksEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ) {
  InterceptPreCmdDrawMeshTasksEXT(commandBuffer, groupCountX, groupCountY, groupCountZ);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDrawMeshTasksEXT pfn = layer_data->dispatch_table.CmdDrawMeshTasksEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, groupCountX, groupCountY, groupCountZ);
  }

  InterceptPostCmdDrawMeshTasksEXT(commandBuffer, groupCountX, groupCountY, groupCountZ);
}

void InterceptCmdDrawMeshTasksIndirectEXT(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride) {
  InterceptPreCmdDrawMeshTasksIndirectEXT(commandBuffer, buffer, offset, drawCount, stride);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDrawMeshTasksIndirectEXT pfn = layer_data->dispatch_table.CmdDrawMeshTasksIndirectEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, buffer, offset, drawCount, stride);
  }

  InterceptPostCmdDrawMeshTasksIndirectEXT(commandBuffer, buffer, offset, drawCount, stride);
}

void InterceptCmdDrawMeshTasksIndirectCountEXT(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride) {
  InterceptPreCmdDrawMeshTasksIndirectCountEXT(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

  auto layer_data = GetDeviceLayerData(DataKey(commandBuffer));
  PFN_vkCmdDrawMeshTasksIndirectCountEXT pfn = layer_data->dispatch_table.CmdDrawMeshTasksIndirectCountEXT;
  if (pfn != nullptr) {
    pfn(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
  }

  InterceptPostCmdDrawMeshTasksIndirectCountEXT(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}



VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL PassInstanceProcDownTheChain(
  VkInstance inst, const char* func) {
  // Get the instance data.
  auto id = GetInstanceLayerData(DataKey(inst));
  // Pass down the instance proc address call through the chain.
  return (PFN_vkVoidFunction)id->pfn_next_instance_proc_addr(inst, func);
}

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL PassDeviceProcDownTheChain(
  VkDevice dev, const char* func) {
  // Get the device data.
  auto dd = GetDeviceLayerData(DataKey(dev));
  // Pass down the device proc address call through the chain.
  return (PFN_vkVoidFunction)dd->pfn_next_device_proc_addr(dev, func);
}

/*****************************************************************************/
/*                         Custom Intercept Functions                        */
/*****************************************************************************/

VKAPI_ATTR VkResult VKAPI_CALL InterceptCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance) {
  // Find the create info
  VkLayerInstanceCreateInfo *layer_create_info = GetLoaderInstanceInfo(pCreateInfo, VK_LAYER_LINK_INFO);
  if (layer_create_info == NULL)
  {
    // No loader instance create info
    return VK_ERROR_INITIALIZATION_FAILED;
  }

  PFN_vkGetInstanceProcAddr pfn_get_instance_proc_addr = layer_create_info->u.pLayerInfo->pfnNextGetInstanceProcAddr;
  PFN_vkCreateInstance pfn_create_instance = (PFN_vkCreateInstance)pfn_get_instance_proc_addr(NULL, "vkCreateInstance");
  if (pfn_create_instance == NULL) return VK_ERROR_INITIALIZATION_FAILED;

  // Move chain on for the next layer.
  layer_create_info->u.pLayerInfo = layer_create_info->u.pLayerInfo->pNext;

  InterceptPreCreateInstance(pCreateInfo, pAllocator, pInstance);

  const VkInstanceCreateInfo *pFinalCreateInfo = GetModifiedInstanceCreateInfo(pCreateInfo);

  auto result = pfn_create_instance(pFinalCreateInfo, pAllocator, pInstance);
  if (VK_SUCCESS != result)
  {
    return result;
  }

  auto id = std::make_unique<InstanceData>();
  id->instance = *pInstance;
  auto chain_info = GetLoaderInstanceInfo(pFinalCreateInfo, VK_LOADER_DATA_CALLBACK);
  id->pfn_set_instance_loader_data = chain_info->u.pfnSetInstanceLoaderData;
  id->pfn_next_instance_proc_addr = pfn_get_instance_proc_addr;
  InitInstanceDispatchTable(*pInstance, pfn_get_instance_proc_addr, &id->dispatch_table);

  {
    std::lock_guard<std::mutex> lock(g_instance_mutex);
    g_instance_data[DataKey(*pInstance)] = std::move(id);
  }

  result = InterceptPostCreateInstance(pFinalCreateInfo, pAllocator, pInstance, result);

  return result;
}

VKAPI_ATTR void VKAPI_CALL InterceptDestroyInstance(
    VkInstance instance, const VkAllocationCallbacks *pAllocator) {

  auto instance_key = DataKey(instance);
  InstanceData *instance_data = GetInstanceLayerData(instance_key);

  InterceptPreDestroyInstance(instance, pAllocator);

  auto pfn_destroy_instance = instance_data->dispatch_table.DestroyInstance;
  pfn_destroy_instance(instance, pAllocator);

  FreeInstanceLayerData(instance_key);
}

VkResult InterceptCreateDevice(VkPhysicalDevice gpu,
                               const VkDeviceCreateInfo *pCreateInfo,
                               const VkAllocationCallbacks *pAllocator,
                               VkDevice *pDevice) {

  VkLayerDeviceCreateInfo *layer_create_info =
      GetLoaderDeviceInfo(pCreateInfo, VK_LAYER_LINK_INFO);

  // Get the instance data.
  auto instance_data = GetInstanceLayerData(DataKey(gpu));

  // Get the proc addr pointers for this layer and update the chain for the next
  // layer.
  PFN_vkGetInstanceProcAddr pfn_next_instance_proc_addr =
      layer_create_info->u.pLayerInfo->pfnNextGetInstanceProcAddr;
  PFN_vkGetDeviceProcAddr pfn_next_device_proc_addr =
      layer_create_info->u.pLayerInfo->pfnNextGetDeviceProcAddr;
  PFN_vkCreateDevice pfn_create_device =
      (PFN_vkCreateDevice)pfn_next_instance_proc_addr(instance_data->instance,
                                                      "vkCreateDevice");
  layer_create_info->u.pLayerInfo = layer_create_info->u.pLayerInfo->pNext;

  const VkDeviceCreateInfo *pFinalCreateInfo =
      GetModifiedDeviceCreateInfo(gpu, pCreateInfo);

  VkResult result = CreateDevice(pfn_create_device, gpu, pFinalCreateInfo,
                                 pAllocator, pDevice);
  if (VK_SUCCESS != result) {
    return result;
  }

  auto dd = std::make_unique<DeviceData>();
  dd->device = *pDevice;
  auto chain_info =
      GetLoaderDeviceInfo(pFinalCreateInfo, VK_LOADER_DATA_CALLBACK);
  dd->pfn_set_device_loader_data = chain_info->u.pfnSetDeviceLoaderData;
  dd->pfn_next_device_proc_addr = pfn_next_device_proc_addr;
  InitDeviceDispatchTable(*pDevice, pfn_next_device_proc_addr,
                          &dd->dispatch_table);
  {
    std::lock_guard<std::mutex> lock(g_device_mutex);
    g_device_data[DataKey(*pDevice)] = std::move(dd);
  }

  result = InterceptPostCreateDevice(gpu, pFinalCreateInfo, pAllocator, pDevice,
                                     result);

  return result;
}

VKAPI_ATTR void VKAPI_CALL InterceptDestroyDevice(
    VkDevice device, const VkAllocationCallbacks *pAllocator) {

  auto device_key = DataKey(device);
  DeviceData *device_data = GetDeviceLayerData(device_key);
  auto pfn_destroy_device = device_data->dispatch_table.DestroyDevice;
  pfn_destroy_device(device, pAllocator);

  FreeDeviceLayerData(device_key);
}

VkResult
InterceptEnumerateInstanceLayerProperties(uint32_t *pPropertyCount,
                                          VkLayerProperties *pProperties) {

  VkResult result = VK_SUCCESS;
  uint32_t copy_count = *pPropertyCount;
  if (pProperties != nullptr && *pPropertyCount > 0) {
    *pProperties = layer_properties;
  }
  *pPropertyCount = 1;
  return result;
}

VkResult
InterceptEnumerateDeviceLayerProperties(VkPhysicalDevice physicalDevice,
                                        uint32_t *pPropertyCount,
                                        VkLayerProperties *pProperties) {
  (void)physicalDevice;
  VkResult result = VK_SUCCESS;
  uint32_t copy_count = *pPropertyCount;
  if (pProperties != nullptr && *pPropertyCount > 0) {
    *pProperties = layer_properties;
  }
  *pPropertyCount = 1;
  return result;
}

VkResult InterceptEnumerateInstanceExtensionProperties(const char *pLayerName,
                                                       uint32_t *pPropertyCount,
                                                       VkExtensionProperties *pProperties) {
  bool layer_requested = (nullptr == pLayerName ||        strcmp(pLayerName, "VK_LAYER_LUNARG_crash_diagnostic"));
  if (!layer_requested) {
    return VK_ERROR_LAYER_NOT_PRESENT;
  }
  if (nullptr == pProperties) {
    *pPropertyCount += static_cast<uint32_t>(instance_extensions.size());
    return VK_SUCCESS;
  } else if (*pPropertyCount > 0) {
    *pPropertyCount = static_cast<uint32_t>(instance_extensions.size());
    memcpy(pProperties, instance_extensions.data(),
           instance_extensions.size() * sizeof(VkExtensionProperties));
  }
  VkResult result = VK_SUCCESS;

  return result;
}

VkResult InterceptEnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice,
                                                     const char *pLayerName,
                                                     uint32_t *pPropertyCount,
                                                     VkExtensionProperties *pProperties) {

  // we want to append our extensions, removing duplicates.
  InstanceData *instance_data = GetInstanceLayerData(DataKey(physicalDevice));

  uint32_t num_other_extensions = 0;
  VkResult result =
      instance_data->dispatch_table.EnumerateDeviceExtensionProperties(
          physicalDevice, nullptr, &num_other_extensions, nullptr);
  if (result != VK_SUCCESS) {
    return result;
  }

  // call down to get other device properties
  std::vector<VkExtensionProperties> extensions(num_other_extensions);
  result = instance_data->dispatch_table.EnumerateDeviceExtensionProperties(
      physicalDevice, pLayerName, &num_other_extensions, &extensions[0]);

  // add our extensions if we have any and requested
  bool layer_requested =      (nullptr == pLayerName || strcmp(pLayerName, "VK_LAYER_LUNARG_crash_diagnostic"));

  if (result == VK_SUCCESS && layer_requested) {
    // not just our layer, we expose all our extensions
    uint32_t max_extensions = *pPropertyCount;

    // set and copy base extensions
    *pPropertyCount = num_other_extensions;

    // find our unique extensions that need to be added
    uint32_t num_additional_extensions = 0;
    auto num_device_extensions = device_extensions.size();
    std::vector<const VkExtensionProperties *> additional_extensions(
        num_device_extensions);

    for (size_t i = 0; i < num_device_extensions; ++i) {
      bool is_unique_extension = true;

      for (size_t j = 0; j < num_other_extensions; ++j) {
        if (0 == strcmp(extensions[j].extensionName,
                        device_extensions[i].extensionName)) {
          is_unique_extension = false;
          break;
        }
      }

      if (is_unique_extension) {
        additional_extensions[num_additional_extensions++] =
            &device_extensions[i];
      }
    }

    // null properties, just count total extensions
    if (nullptr == pProperties) {
      *pPropertyCount += num_additional_extensions;
    } else {
      uint32_t numExtensions = std::min(num_other_extensions, max_extensions);

      memcpy(pProperties, &extensions[0],
             numExtensions * sizeof(VkExtensionProperties));

      for (size_t i = 0;
           i < num_additional_extensions && numExtensions < max_extensions;
           ++i) {
        pProperties[numExtensions++] = *additional_extensions[i];
      }

      *pPropertyCount = numExtensions;

      // not enough space for all extensions
      if (num_other_extensions + num_additional_extensions > max_extensions) {
        result = VK_INCOMPLETE;
      }
    }
  }

  result = InterceptPostEnumerateDeviceExtensionProperties(
                   physicalDevice, pLayerName, pPropertyCount, pProperties,
                   result);

  return result;
}

PFN_vkVoidFunction GetInstanceFuncs(const char* func)
{
  if (0 == strcmp(func, "vkCreateInstance"))
    return (PFN_vkVoidFunction)InterceptCreateInstance;
  if (0 == strcmp(func, "vkDestroyInstance"))
    return (PFN_vkVoidFunction)InterceptDestroyInstance;
  if (0 == strcmp(func, "vkCreateDevice"))
    return (PFN_vkVoidFunction)InterceptCreateDevice;
  if (0 == strcmp(func, "vkEnumerateInstanceExtensionProperties"))
    return (PFN_vkVoidFunction)InterceptEnumerateInstanceExtensionProperties;
  if (0 == strcmp(func, "vkEnumerateDeviceExtensionProperties"))
    return (PFN_vkVoidFunction)InterceptEnumerateDeviceExtensionProperties;
  if (0 == strcmp(func, "vkEnumerateInstanceLayerProperties"))
    return (PFN_vkVoidFunction)InterceptEnumerateInstanceLayerProperties;
  if (0 == strcmp(func, "vkEnumerateDeviceLayerProperties"))
    return (PFN_vkVoidFunction)InterceptEnumerateDeviceLayerProperties;

  return nullptr;
}

PFN_vkVoidFunction GetDeviceFuncs(const char* func)
{
  if (0 == strcmp(func, "vkDestroyDevice"))
    return (PFN_vkVoidFunction)InterceptDestroyDevice;
  if (0 == strcmp(func, "vkGetDeviceQueue"))
    return (PFN_vkVoidFunction)InterceptGetDeviceQueue;
  if (0 == strcmp(func, "vkQueueSubmit"))
    return (PFN_vkVoidFunction)InterceptQueueSubmit;
  if (0 == strcmp(func, "vkQueueWaitIdle"))
    return (PFN_vkVoidFunction)InterceptQueueWaitIdle;
  if (0 == strcmp(func, "vkDeviceWaitIdle"))
    return (PFN_vkVoidFunction)InterceptDeviceWaitIdle;
  if (0 == strcmp(func, "vkQueueBindSparse"))
    return (PFN_vkVoidFunction)InterceptQueueBindSparse;
  if (0 == strcmp(func, "vkGetFenceStatus"))
    return (PFN_vkVoidFunction)InterceptGetFenceStatus;
  if (0 == strcmp(func, "vkWaitForFences"))
    return (PFN_vkVoidFunction)InterceptWaitForFences;
  if (0 == strcmp(func, "vkCreateSemaphore"))
    return (PFN_vkVoidFunction)InterceptCreateSemaphore;
  if (0 == strcmp(func, "vkDestroySemaphore"))
    return (PFN_vkVoidFunction)InterceptDestroySemaphore;
  if (0 == strcmp(func, "vkGetQueryPoolResults"))
    return (PFN_vkVoidFunction)InterceptGetQueryPoolResults;
  if (0 == strcmp(func, "vkCreateShaderModule"))
    return (PFN_vkVoidFunction)InterceptCreateShaderModule;
  if (0 == strcmp(func, "vkDestroyShaderModule"))
    return (PFN_vkVoidFunction)InterceptDestroyShaderModule;
  if (0 == strcmp(func, "vkCreateGraphicsPipelines"))
    return (PFN_vkVoidFunction)InterceptCreateGraphicsPipelines;
  if (0 == strcmp(func, "vkCreateComputePipelines"))
    return (PFN_vkVoidFunction)InterceptCreateComputePipelines;
  if (0 == strcmp(func, "vkDestroyPipeline"))
    return (PFN_vkVoidFunction)InterceptDestroyPipeline;
  if (0 == strcmp(func, "vkCreateCommandPool"))
    return (PFN_vkVoidFunction)InterceptCreateCommandPool;
  if (0 == strcmp(func, "vkDestroyCommandPool"))
    return (PFN_vkVoidFunction)InterceptDestroyCommandPool;
  if (0 == strcmp(func, "vkResetCommandPool"))
    return (PFN_vkVoidFunction)InterceptResetCommandPool;
  if (0 == strcmp(func, "vkAllocateCommandBuffers"))
    return (PFN_vkVoidFunction)InterceptAllocateCommandBuffers;
  if (0 == strcmp(func, "vkFreeCommandBuffers"))
    return (PFN_vkVoidFunction)InterceptFreeCommandBuffers;
  if (0 == strcmp(func, "vkBeginCommandBuffer"))
    return (PFN_vkVoidFunction)InterceptBeginCommandBuffer;
  if (0 == strcmp(func, "vkEndCommandBuffer"))
    return (PFN_vkVoidFunction)InterceptEndCommandBuffer;
  if (0 == strcmp(func, "vkResetCommandBuffer"))
    return (PFN_vkVoidFunction)InterceptResetCommandBuffer;
  if (0 == strcmp(func, "vkCmdBindPipeline"))
    return (PFN_vkVoidFunction)InterceptCmdBindPipeline;
  if (0 == strcmp(func, "vkCmdSetViewport"))
    return (PFN_vkVoidFunction)InterceptCmdSetViewport;
  if (0 == strcmp(func, "vkCmdSetScissor"))
    return (PFN_vkVoidFunction)InterceptCmdSetScissor;
  if (0 == strcmp(func, "vkCmdSetLineWidth"))
    return (PFN_vkVoidFunction)InterceptCmdSetLineWidth;
  if (0 == strcmp(func, "vkCmdSetDepthBias"))
    return (PFN_vkVoidFunction)InterceptCmdSetDepthBias;
  if (0 == strcmp(func, "vkCmdSetBlendConstants"))
    return (PFN_vkVoidFunction)InterceptCmdSetBlendConstants;
  if (0 == strcmp(func, "vkCmdSetDepthBounds"))
    return (PFN_vkVoidFunction)InterceptCmdSetDepthBounds;
  if (0 == strcmp(func, "vkCmdSetStencilCompareMask"))
    return (PFN_vkVoidFunction)InterceptCmdSetStencilCompareMask;
  if (0 == strcmp(func, "vkCmdSetStencilWriteMask"))
    return (PFN_vkVoidFunction)InterceptCmdSetStencilWriteMask;
  if (0 == strcmp(func, "vkCmdSetStencilReference"))
    return (PFN_vkVoidFunction)InterceptCmdSetStencilReference;
  if (0 == strcmp(func, "vkCmdBindDescriptorSets"))
    return (PFN_vkVoidFunction)InterceptCmdBindDescriptorSets;
  if (0 == strcmp(func, "vkCmdBindIndexBuffer"))
    return (PFN_vkVoidFunction)InterceptCmdBindIndexBuffer;
  if (0 == strcmp(func, "vkCmdBindVertexBuffers"))
    return (PFN_vkVoidFunction)InterceptCmdBindVertexBuffers;
  if (0 == strcmp(func, "vkCmdDraw"))
    return (PFN_vkVoidFunction)InterceptCmdDraw;
  if (0 == strcmp(func, "vkCmdDrawIndexed"))
    return (PFN_vkVoidFunction)InterceptCmdDrawIndexed;
  if (0 == strcmp(func, "vkCmdDrawIndirect"))
    return (PFN_vkVoidFunction)InterceptCmdDrawIndirect;
  if (0 == strcmp(func, "vkCmdDrawIndexedIndirect"))
    return (PFN_vkVoidFunction)InterceptCmdDrawIndexedIndirect;
  if (0 == strcmp(func, "vkCmdDispatch"))
    return (PFN_vkVoidFunction)InterceptCmdDispatch;
  if (0 == strcmp(func, "vkCmdDispatchIndirect"))
    return (PFN_vkVoidFunction)InterceptCmdDispatchIndirect;
  if (0 == strcmp(func, "vkCmdCopyBuffer"))
    return (PFN_vkVoidFunction)InterceptCmdCopyBuffer;
  if (0 == strcmp(func, "vkCmdCopyImage"))
    return (PFN_vkVoidFunction)InterceptCmdCopyImage;
  if (0 == strcmp(func, "vkCmdBlitImage"))
    return (PFN_vkVoidFunction)InterceptCmdBlitImage;
  if (0 == strcmp(func, "vkCmdCopyBufferToImage"))
    return (PFN_vkVoidFunction)InterceptCmdCopyBufferToImage;
  if (0 == strcmp(func, "vkCmdCopyImageToBuffer"))
    return (PFN_vkVoidFunction)InterceptCmdCopyImageToBuffer;
  if (0 == strcmp(func, "vkCmdUpdateBuffer"))
    return (PFN_vkVoidFunction)InterceptCmdUpdateBuffer;
  if (0 == strcmp(func, "vkCmdFillBuffer"))
    return (PFN_vkVoidFunction)InterceptCmdFillBuffer;
  if (0 == strcmp(func, "vkCmdClearColorImage"))
    return (PFN_vkVoidFunction)InterceptCmdClearColorImage;
  if (0 == strcmp(func, "vkCmdClearDepthStencilImage"))
    return (PFN_vkVoidFunction)InterceptCmdClearDepthStencilImage;
  if (0 == strcmp(func, "vkCmdClearAttachments"))
    return (PFN_vkVoidFunction)InterceptCmdClearAttachments;
  if (0 == strcmp(func, "vkCmdResolveImage"))
    return (PFN_vkVoidFunction)InterceptCmdResolveImage;
  if (0 == strcmp(func, "vkCmdSetEvent"))
    return (PFN_vkVoidFunction)InterceptCmdSetEvent;
  if (0 == strcmp(func, "vkCmdResetEvent"))
    return (PFN_vkVoidFunction)InterceptCmdResetEvent;
  if (0 == strcmp(func, "vkCmdWaitEvents"))
    return (PFN_vkVoidFunction)InterceptCmdWaitEvents;
  if (0 == strcmp(func, "vkCmdPipelineBarrier"))
    return (PFN_vkVoidFunction)InterceptCmdPipelineBarrier;
  if (0 == strcmp(func, "vkCmdBeginQuery"))
    return (PFN_vkVoidFunction)InterceptCmdBeginQuery;
  if (0 == strcmp(func, "vkCmdEndQuery"))
    return (PFN_vkVoidFunction)InterceptCmdEndQuery;
  if (0 == strcmp(func, "vkCmdResetQueryPool"))
    return (PFN_vkVoidFunction)InterceptCmdResetQueryPool;
  if (0 == strcmp(func, "vkCmdWriteTimestamp"))
    return (PFN_vkVoidFunction)InterceptCmdWriteTimestamp;
  if (0 == strcmp(func, "vkCmdCopyQueryPoolResults"))
    return (PFN_vkVoidFunction)InterceptCmdCopyQueryPoolResults;
  if (0 == strcmp(func, "vkCmdPushConstants"))
    return (PFN_vkVoidFunction)InterceptCmdPushConstants;
  if (0 == strcmp(func, "vkCmdBeginRenderPass"))
    return (PFN_vkVoidFunction)InterceptCmdBeginRenderPass;
  if (0 == strcmp(func, "vkCmdNextSubpass"))
    return (PFN_vkVoidFunction)InterceptCmdNextSubpass;
  if (0 == strcmp(func, "vkCmdEndRenderPass"))
    return (PFN_vkVoidFunction)InterceptCmdEndRenderPass;
  if (0 == strcmp(func, "vkCmdExecuteCommands"))
    return (PFN_vkVoidFunction)InterceptCmdExecuteCommands;
  if (0 == strcmp(func, "vkCmdSetDeviceMask"))
    return (PFN_vkVoidFunction)InterceptCmdSetDeviceMask;
  if (0 == strcmp(func, "vkCmdDispatchBase"))
    return (PFN_vkVoidFunction)InterceptCmdDispatchBase;
  if (0 == strcmp(func, "vkGetDeviceQueue2"))
    return (PFN_vkVoidFunction)InterceptGetDeviceQueue2;
  if (0 == strcmp(func, "vkCmdDrawIndirectCount"))
    return (PFN_vkVoidFunction)InterceptCmdDrawIndirectCount;
  if (0 == strcmp(func, "vkCmdDrawIndexedIndirectCount"))
    return (PFN_vkVoidFunction)InterceptCmdDrawIndexedIndirectCount;
  if (0 == strcmp(func, "vkCmdBeginRenderPass2"))
    return (PFN_vkVoidFunction)InterceptCmdBeginRenderPass2;
  if (0 == strcmp(func, "vkCmdNextSubpass2"))
    return (PFN_vkVoidFunction)InterceptCmdNextSubpass2;
  if (0 == strcmp(func, "vkCmdEndRenderPass2"))
    return (PFN_vkVoidFunction)InterceptCmdEndRenderPass2;
  if (0 == strcmp(func, "vkCmdSetEvent2"))
    return (PFN_vkVoidFunction)InterceptCmdSetEvent2;
  if (0 == strcmp(func, "vkCmdResetEvent2"))
    return (PFN_vkVoidFunction)InterceptCmdResetEvent2;
  if (0 == strcmp(func, "vkCmdWaitEvents2"))
    return (PFN_vkVoidFunction)InterceptCmdWaitEvents2;
  if (0 == strcmp(func, "vkCmdPipelineBarrier2"))
    return (PFN_vkVoidFunction)InterceptCmdPipelineBarrier2;
  if (0 == strcmp(func, "vkCmdWriteTimestamp2"))
    return (PFN_vkVoidFunction)InterceptCmdWriteTimestamp2;
  if (0 == strcmp(func, "vkQueueSubmit2"))
    return (PFN_vkVoidFunction)InterceptQueueSubmit2;
  if (0 == strcmp(func, "vkCmdCopyBuffer2"))
    return (PFN_vkVoidFunction)InterceptCmdCopyBuffer2;
  if (0 == strcmp(func, "vkCmdCopyImage2"))
    return (PFN_vkVoidFunction)InterceptCmdCopyImage2;
  if (0 == strcmp(func, "vkCmdCopyBufferToImage2"))
    return (PFN_vkVoidFunction)InterceptCmdCopyBufferToImage2;
  if (0 == strcmp(func, "vkCmdCopyImageToBuffer2"))
    return (PFN_vkVoidFunction)InterceptCmdCopyImageToBuffer2;
  if (0 == strcmp(func, "vkCmdBlitImage2"))
    return (PFN_vkVoidFunction)InterceptCmdBlitImage2;
  if (0 == strcmp(func, "vkCmdResolveImage2"))
    return (PFN_vkVoidFunction)InterceptCmdResolveImage2;
  if (0 == strcmp(func, "vkCmdBeginRendering"))
    return (PFN_vkVoidFunction)InterceptCmdBeginRendering;
  if (0 == strcmp(func, "vkCmdEndRendering"))
    return (PFN_vkVoidFunction)InterceptCmdEndRendering;
  if (0 == strcmp(func, "vkCmdSetCullMode"))
    return (PFN_vkVoidFunction)InterceptCmdSetCullMode;
  if (0 == strcmp(func, "vkCmdSetFrontFace"))
    return (PFN_vkVoidFunction)InterceptCmdSetFrontFace;
  if (0 == strcmp(func, "vkCmdSetPrimitiveTopology"))
    return (PFN_vkVoidFunction)InterceptCmdSetPrimitiveTopology;
  if (0 == strcmp(func, "vkCmdSetViewportWithCount"))
    return (PFN_vkVoidFunction)InterceptCmdSetViewportWithCount;
  if (0 == strcmp(func, "vkCmdSetScissorWithCount"))
    return (PFN_vkVoidFunction)InterceptCmdSetScissorWithCount;
  if (0 == strcmp(func, "vkCmdBindVertexBuffers2"))
    return (PFN_vkVoidFunction)InterceptCmdBindVertexBuffers2;
  if (0 == strcmp(func, "vkCmdSetDepthTestEnable"))
    return (PFN_vkVoidFunction)InterceptCmdSetDepthTestEnable;
  if (0 == strcmp(func, "vkCmdSetDepthWriteEnable"))
    return (PFN_vkVoidFunction)InterceptCmdSetDepthWriteEnable;
  if (0 == strcmp(func, "vkCmdSetDepthCompareOp"))
    return (PFN_vkVoidFunction)InterceptCmdSetDepthCompareOp;
  if (0 == strcmp(func, "vkCmdSetDepthBoundsTestEnable"))
    return (PFN_vkVoidFunction)InterceptCmdSetDepthBoundsTestEnable;
  if (0 == strcmp(func, "vkCmdSetStencilTestEnable"))
    return (PFN_vkVoidFunction)InterceptCmdSetStencilTestEnable;
  if (0 == strcmp(func, "vkCmdSetStencilOp"))
    return (PFN_vkVoidFunction)InterceptCmdSetStencilOp;
  if (0 == strcmp(func, "vkCmdSetRasterizerDiscardEnable"))
    return (PFN_vkVoidFunction)InterceptCmdSetRasterizerDiscardEnable;
  if (0 == strcmp(func, "vkCmdSetDepthBiasEnable"))
    return (PFN_vkVoidFunction)InterceptCmdSetDepthBiasEnable;
  if (0 == strcmp(func, "vkCmdSetPrimitiveRestartEnable"))
    return (PFN_vkVoidFunction)InterceptCmdSetPrimitiveRestartEnable;
  if (0 == strcmp(func, "vkAcquireNextImageKHR"))
    return (PFN_vkVoidFunction)InterceptAcquireNextImageKHR;
  if (0 == strcmp(func, "vkQueuePresentKHR"))
    return (PFN_vkVoidFunction)InterceptQueuePresentKHR;
  if (0 == strcmp(func, "vkCmdBeginVideoCodingKHR"))
    return (PFN_vkVoidFunction)InterceptCmdBeginVideoCodingKHR;
  if (0 == strcmp(func, "vkCmdEndVideoCodingKHR"))
    return (PFN_vkVoidFunction)InterceptCmdEndVideoCodingKHR;
  if (0 == strcmp(func, "vkCmdControlVideoCodingKHR"))
    return (PFN_vkVoidFunction)InterceptCmdControlVideoCodingKHR;
  if (0 == strcmp(func, "vkCmdDecodeVideoKHR"))
    return (PFN_vkVoidFunction)InterceptCmdDecodeVideoKHR;
  if (0 == strcmp(func, "vkCmdBeginRenderingKHR"))
    return (PFN_vkVoidFunction)InterceptCmdBeginRenderingKHR;
  if (0 == strcmp(func, "vkCmdEndRenderingKHR"))
    return (PFN_vkVoidFunction)InterceptCmdEndRenderingKHR;
  if (0 == strcmp(func, "vkCmdSetDeviceMaskKHR"))
    return (PFN_vkVoidFunction)InterceptCmdSetDeviceMaskKHR;
  if (0 == strcmp(func, "vkCmdDispatchBaseKHR"))
    return (PFN_vkVoidFunction)InterceptCmdDispatchBaseKHR;
  if (0 == strcmp(func, "vkCmdPushDescriptorSetKHR"))
    return (PFN_vkVoidFunction)InterceptCmdPushDescriptorSetKHR;
  if (0 == strcmp(func, "vkCmdPushDescriptorSetWithTemplateKHR"))
    return (PFN_vkVoidFunction)InterceptCmdPushDescriptorSetWithTemplateKHR;
  if (0 == strcmp(func, "vkCmdBeginRenderPass2KHR"))
    return (PFN_vkVoidFunction)InterceptCmdBeginRenderPass2KHR;
  if (0 == strcmp(func, "vkCmdNextSubpass2KHR"))
    return (PFN_vkVoidFunction)InterceptCmdNextSubpass2KHR;
  if (0 == strcmp(func, "vkCmdEndRenderPass2KHR"))
    return (PFN_vkVoidFunction)InterceptCmdEndRenderPass2KHR;
  if (0 == strcmp(func, "vkCmdDrawIndirectCountKHR"))
    return (PFN_vkVoidFunction)InterceptCmdDrawIndirectCountKHR;
  if (0 == strcmp(func, "vkCmdDrawIndexedIndirectCountKHR"))
    return (PFN_vkVoidFunction)InterceptCmdDrawIndexedIndirectCountKHR;
  if (0 == strcmp(func, "vkGetSemaphoreCounterValueKHR"))
    return (PFN_vkVoidFunction)InterceptGetSemaphoreCounterValueKHR;
  if (0 == strcmp(func, "vkWaitSemaphoresKHR"))
    return (PFN_vkVoidFunction)InterceptWaitSemaphoresKHR;
  if (0 == strcmp(func, "vkSignalSemaphoreKHR"))
    return (PFN_vkVoidFunction)InterceptSignalSemaphoreKHR;
  if (0 == strcmp(func, "vkCmdSetFragmentShadingRateKHR"))
    return (PFN_vkVoidFunction)InterceptCmdSetFragmentShadingRateKHR;
  if (0 == strcmp(func, "vkCmdEncodeVideoKHR"))
    return (PFN_vkVoidFunction)InterceptCmdEncodeVideoKHR;
  if (0 == strcmp(func, "vkCmdSetEvent2KHR"))
    return (PFN_vkVoidFunction)InterceptCmdSetEvent2KHR;
  if (0 == strcmp(func, "vkCmdResetEvent2KHR"))
    return (PFN_vkVoidFunction)InterceptCmdResetEvent2KHR;
  if (0 == strcmp(func, "vkCmdWaitEvents2KHR"))
    return (PFN_vkVoidFunction)InterceptCmdWaitEvents2KHR;
  if (0 == strcmp(func, "vkCmdPipelineBarrier2KHR"))
    return (PFN_vkVoidFunction)InterceptCmdPipelineBarrier2KHR;
  if (0 == strcmp(func, "vkCmdWriteTimestamp2KHR"))
    return (PFN_vkVoidFunction)InterceptCmdWriteTimestamp2KHR;
  if (0 == strcmp(func, "vkQueueSubmit2KHR"))
    return (PFN_vkVoidFunction)InterceptQueueSubmit2KHR;
  if (0 == strcmp(func, "vkCmdWriteBufferMarker2AMD"))
    return (PFN_vkVoidFunction)InterceptCmdWriteBufferMarker2AMD;
  if (0 == strcmp(func, "vkCmdCopyBuffer2KHR"))
    return (PFN_vkVoidFunction)InterceptCmdCopyBuffer2KHR;
  if (0 == strcmp(func, "vkCmdCopyImage2KHR"))
    return (PFN_vkVoidFunction)InterceptCmdCopyImage2KHR;
  if (0 == strcmp(func, "vkCmdCopyBufferToImage2KHR"))
    return (PFN_vkVoidFunction)InterceptCmdCopyBufferToImage2KHR;
  if (0 == strcmp(func, "vkCmdCopyImageToBuffer2KHR"))
    return (PFN_vkVoidFunction)InterceptCmdCopyImageToBuffer2KHR;
  if (0 == strcmp(func, "vkCmdBlitImage2KHR"))
    return (PFN_vkVoidFunction)InterceptCmdBlitImage2KHR;
  if (0 == strcmp(func, "vkCmdResolveImage2KHR"))
    return (PFN_vkVoidFunction)InterceptCmdResolveImage2KHR;
  if (0 == strcmp(func, "vkCmdTraceRaysIndirect2KHR"))
    return (PFN_vkVoidFunction)InterceptCmdTraceRaysIndirect2KHR;
  if (0 == strcmp(func, "vkCmdBindIndexBuffer2KHR"))
    return (PFN_vkVoidFunction)InterceptCmdBindIndexBuffer2KHR;
  if (0 == strcmp(func, "vkCmdBindDescriptorSets2KHR"))
    return (PFN_vkVoidFunction)InterceptCmdBindDescriptorSets2KHR;
  if (0 == strcmp(func, "vkCmdPushConstants2KHR"))
    return (PFN_vkVoidFunction)InterceptCmdPushConstants2KHR;
  if (0 == strcmp(func, "vkCmdPushDescriptorSet2KHR"))
    return (PFN_vkVoidFunction)InterceptCmdPushDescriptorSet2KHR;
  if (0 == strcmp(func, "vkCmdPushDescriptorSetWithTemplate2KHR"))
    return (PFN_vkVoidFunction)InterceptCmdPushDescriptorSetWithTemplate2KHR;
  if (0 == strcmp(func, "vkCmdSetDescriptorBufferOffsets2EXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetDescriptorBufferOffsets2EXT;
  if (0 == strcmp(func, "vkCmdBindDescriptorBufferEmbeddedSamplers2EXT"))
    return (PFN_vkVoidFunction)InterceptCmdBindDescriptorBufferEmbeddedSamplers2EXT;
  if (0 == strcmp(func, "vkDebugMarkerSetObjectNameEXT"))
    return (PFN_vkVoidFunction)InterceptDebugMarkerSetObjectNameEXT;
  if (0 == strcmp(func, "vkCmdDebugMarkerBeginEXT"))
    return (PFN_vkVoidFunction)InterceptCmdDebugMarkerBeginEXT;
  if (0 == strcmp(func, "vkCmdDebugMarkerEndEXT"))
    return (PFN_vkVoidFunction)InterceptCmdDebugMarkerEndEXT;
  if (0 == strcmp(func, "vkCmdDebugMarkerInsertEXT"))
    return (PFN_vkVoidFunction)InterceptCmdDebugMarkerInsertEXT;
  if (0 == strcmp(func, "vkCmdBindTransformFeedbackBuffersEXT"))
    return (PFN_vkVoidFunction)InterceptCmdBindTransformFeedbackBuffersEXT;
  if (0 == strcmp(func, "vkCmdBeginTransformFeedbackEXT"))
    return (PFN_vkVoidFunction)InterceptCmdBeginTransformFeedbackEXT;
  if (0 == strcmp(func, "vkCmdEndTransformFeedbackEXT"))
    return (PFN_vkVoidFunction)InterceptCmdEndTransformFeedbackEXT;
  if (0 == strcmp(func, "vkCmdBeginQueryIndexedEXT"))
    return (PFN_vkVoidFunction)InterceptCmdBeginQueryIndexedEXT;
  if (0 == strcmp(func, "vkCmdEndQueryIndexedEXT"))
    return (PFN_vkVoidFunction)InterceptCmdEndQueryIndexedEXT;
  if (0 == strcmp(func, "vkCmdDrawIndirectByteCountEXT"))
    return (PFN_vkVoidFunction)InterceptCmdDrawIndirectByteCountEXT;
  if (0 == strcmp(func, "vkCmdCuLaunchKernelNVX"))
    return (PFN_vkVoidFunction)InterceptCmdCuLaunchKernelNVX;
  if (0 == strcmp(func, "vkCmdDrawIndirectCountAMD"))
    return (PFN_vkVoidFunction)InterceptCmdDrawIndirectCountAMD;
  if (0 == strcmp(func, "vkCmdDrawIndexedIndirectCountAMD"))
    return (PFN_vkVoidFunction)InterceptCmdDrawIndexedIndirectCountAMD;
  if (0 == strcmp(func, "vkCmdBeginConditionalRenderingEXT"))
    return (PFN_vkVoidFunction)InterceptCmdBeginConditionalRenderingEXT;
  if (0 == strcmp(func, "vkCmdEndConditionalRenderingEXT"))
    return (PFN_vkVoidFunction)InterceptCmdEndConditionalRenderingEXT;
  if (0 == strcmp(func, "vkCmdSetViewportWScalingNV"))
    return (PFN_vkVoidFunction)InterceptCmdSetViewportWScalingNV;
  if (0 == strcmp(func, "vkCmdSetDiscardRectangleEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetDiscardRectangleEXT;
  if (0 == strcmp(func, "vkCmdSetDiscardRectangleEnableEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetDiscardRectangleEnableEXT;
  if (0 == strcmp(func, "vkCmdSetDiscardRectangleModeEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetDiscardRectangleModeEXT;
  if (0 == strcmp(func, "vkSetDebugUtilsObjectNameEXT"))
    return (PFN_vkVoidFunction)InterceptSetDebugUtilsObjectNameEXT;
  if (0 == strcmp(func, "vkCmdBeginDebugUtilsLabelEXT"))
    return (PFN_vkVoidFunction)InterceptCmdBeginDebugUtilsLabelEXT;
  if (0 == strcmp(func, "vkCmdEndDebugUtilsLabelEXT"))
    return (PFN_vkVoidFunction)InterceptCmdEndDebugUtilsLabelEXT;
  if (0 == strcmp(func, "vkCmdInsertDebugUtilsLabelEXT"))
    return (PFN_vkVoidFunction)InterceptCmdInsertDebugUtilsLabelEXT;
#ifdef VK_ENABLE_BETA_EXTENSIONS
  if (0 == strcmp(func, "vkCmdInitializeGraphScratchMemoryAMDX"))
    return (PFN_vkVoidFunction)InterceptCmdInitializeGraphScratchMemoryAMDX;
#endif //VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
  if (0 == strcmp(func, "vkCmdDispatchGraphAMDX"))
    return (PFN_vkVoidFunction)InterceptCmdDispatchGraphAMDX;
#endif //VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
  if (0 == strcmp(func, "vkCmdDispatchGraphIndirectAMDX"))
    return (PFN_vkVoidFunction)InterceptCmdDispatchGraphIndirectAMDX;
#endif //VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
  if (0 == strcmp(func, "vkCmdDispatchGraphIndirectCountAMDX"))
    return (PFN_vkVoidFunction)InterceptCmdDispatchGraphIndirectCountAMDX;
#endif //VK_ENABLE_BETA_EXTENSIONS
  if (0 == strcmp(func, "vkCmdSetSampleLocationsEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetSampleLocationsEXT;
  if (0 == strcmp(func, "vkCmdBindShadingRateImageNV"))
    return (PFN_vkVoidFunction)InterceptCmdBindShadingRateImageNV;
  if (0 == strcmp(func, "vkCmdSetViewportShadingRatePaletteNV"))
    return (PFN_vkVoidFunction)InterceptCmdSetViewportShadingRatePaletteNV;
  if (0 == strcmp(func, "vkCmdSetCoarseSampleOrderNV"))
    return (PFN_vkVoidFunction)InterceptCmdSetCoarseSampleOrderNV;
  if (0 == strcmp(func, "vkCmdBuildAccelerationStructureNV"))
    return (PFN_vkVoidFunction)InterceptCmdBuildAccelerationStructureNV;
  if (0 == strcmp(func, "vkCmdCopyAccelerationStructureNV"))
    return (PFN_vkVoidFunction)InterceptCmdCopyAccelerationStructureNV;
  if (0 == strcmp(func, "vkCmdTraceRaysNV"))
    return (PFN_vkVoidFunction)InterceptCmdTraceRaysNV;
  if (0 == strcmp(func, "vkCmdWriteAccelerationStructuresPropertiesNV"))
    return (PFN_vkVoidFunction)InterceptCmdWriteAccelerationStructuresPropertiesNV;
  if (0 == strcmp(func, "vkCmdWriteBufferMarkerAMD"))
    return (PFN_vkVoidFunction)InterceptCmdWriteBufferMarkerAMD;
  if (0 == strcmp(func, "vkCmdDrawMeshTasksNV"))
    return (PFN_vkVoidFunction)InterceptCmdDrawMeshTasksNV;
  if (0 == strcmp(func, "vkCmdDrawMeshTasksIndirectNV"))
    return (PFN_vkVoidFunction)InterceptCmdDrawMeshTasksIndirectNV;
  if (0 == strcmp(func, "vkCmdDrawMeshTasksIndirectCountNV"))
    return (PFN_vkVoidFunction)InterceptCmdDrawMeshTasksIndirectCountNV;
  if (0 == strcmp(func, "vkCmdSetExclusiveScissorEnableNV"))
    return (PFN_vkVoidFunction)InterceptCmdSetExclusiveScissorEnableNV;
  if (0 == strcmp(func, "vkCmdSetExclusiveScissorNV"))
    return (PFN_vkVoidFunction)InterceptCmdSetExclusiveScissorNV;
  if (0 == strcmp(func, "vkCmdSetCheckpointNV"))
    return (PFN_vkVoidFunction)InterceptCmdSetCheckpointNV;
  if (0 == strcmp(func, "vkCmdSetPerformanceMarkerINTEL"))
    return (PFN_vkVoidFunction)InterceptCmdSetPerformanceMarkerINTEL;
  if (0 == strcmp(func, "vkCmdSetPerformanceStreamMarkerINTEL"))
    return (PFN_vkVoidFunction)InterceptCmdSetPerformanceStreamMarkerINTEL;
  if (0 == strcmp(func, "vkCmdSetPerformanceOverrideINTEL"))
    return (PFN_vkVoidFunction)InterceptCmdSetPerformanceOverrideINTEL;
  if (0 == strcmp(func, "vkCmdSetLineStippleEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetLineStippleEXT;
  if (0 == strcmp(func, "vkCmdSetCullModeEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetCullModeEXT;
  if (0 == strcmp(func, "vkCmdSetFrontFaceEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetFrontFaceEXT;
  if (0 == strcmp(func, "vkCmdSetPrimitiveTopologyEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetPrimitiveTopologyEXT;
  if (0 == strcmp(func, "vkCmdSetViewportWithCountEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetViewportWithCountEXT;
  if (0 == strcmp(func, "vkCmdSetScissorWithCountEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetScissorWithCountEXT;
  if (0 == strcmp(func, "vkCmdBindVertexBuffers2EXT"))
    return (PFN_vkVoidFunction)InterceptCmdBindVertexBuffers2EXT;
  if (0 == strcmp(func, "vkCmdSetDepthTestEnableEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetDepthTestEnableEXT;
  if (0 == strcmp(func, "vkCmdSetDepthWriteEnableEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetDepthWriteEnableEXT;
  if (0 == strcmp(func, "vkCmdSetDepthCompareOpEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetDepthCompareOpEXT;
  if (0 == strcmp(func, "vkCmdSetDepthBoundsTestEnableEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetDepthBoundsTestEnableEXT;
  if (0 == strcmp(func, "vkCmdSetStencilTestEnableEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetStencilTestEnableEXT;
  if (0 == strcmp(func, "vkCmdSetStencilOpEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetStencilOpEXT;
  if (0 == strcmp(func, "vkCmdPreprocessGeneratedCommandsNV"))
    return (PFN_vkVoidFunction)InterceptCmdPreprocessGeneratedCommandsNV;
  if (0 == strcmp(func, "vkCmdExecuteGeneratedCommandsNV"))
    return (PFN_vkVoidFunction)InterceptCmdExecuteGeneratedCommandsNV;
  if (0 == strcmp(func, "vkCmdBindPipelineShaderGroupNV"))
    return (PFN_vkVoidFunction)InterceptCmdBindPipelineShaderGroupNV;
  if (0 == strcmp(func, "vkCmdSetDepthBias2EXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetDepthBias2EXT;
  if (0 == strcmp(func, "vkCmdCudaLaunchKernelNV"))
    return (PFN_vkVoidFunction)InterceptCmdCudaLaunchKernelNV;
  if (0 == strcmp(func, "vkCmdBindDescriptorBuffersEXT"))
    return (PFN_vkVoidFunction)InterceptCmdBindDescriptorBuffersEXT;
  if (0 == strcmp(func, "vkCmdSetDescriptorBufferOffsetsEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetDescriptorBufferOffsetsEXT;
  if (0 == strcmp(func, "vkCmdBindDescriptorBufferEmbeddedSamplersEXT"))
    return (PFN_vkVoidFunction)InterceptCmdBindDescriptorBufferEmbeddedSamplersEXT;
  if (0 == strcmp(func, "vkCmdSetFragmentShadingRateEnumNV"))
    return (PFN_vkVoidFunction)InterceptCmdSetFragmentShadingRateEnumNV;
  if (0 == strcmp(func, "vkCmdSetVertexInputEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetVertexInputEXT;
  if (0 == strcmp(func, "vkCmdSubpassShadingHUAWEI"))
    return (PFN_vkVoidFunction)InterceptCmdSubpassShadingHUAWEI;
  if (0 == strcmp(func, "vkCmdBindInvocationMaskHUAWEI"))
    return (PFN_vkVoidFunction)InterceptCmdBindInvocationMaskHUAWEI;
  if (0 == strcmp(func, "vkCmdSetPatchControlPointsEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetPatchControlPointsEXT;
  if (0 == strcmp(func, "vkCmdSetRasterizerDiscardEnableEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetRasterizerDiscardEnableEXT;
  if (0 == strcmp(func, "vkCmdSetDepthBiasEnableEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetDepthBiasEnableEXT;
  if (0 == strcmp(func, "vkCmdSetLogicOpEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetLogicOpEXT;
  if (0 == strcmp(func, "vkCmdSetPrimitiveRestartEnableEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetPrimitiveRestartEnableEXT;
  if (0 == strcmp(func, "vkCmdSetColorWriteEnableEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetColorWriteEnableEXT;
  if (0 == strcmp(func, "vkCmdDrawMultiEXT"))
    return (PFN_vkVoidFunction)InterceptCmdDrawMultiEXT;
  if (0 == strcmp(func, "vkCmdDrawMultiIndexedEXT"))
    return (PFN_vkVoidFunction)InterceptCmdDrawMultiIndexedEXT;
  if (0 == strcmp(func, "vkCmdBuildMicromapsEXT"))
    return (PFN_vkVoidFunction)InterceptCmdBuildMicromapsEXT;
  if (0 == strcmp(func, "vkCmdCopyMicromapEXT"))
    return (PFN_vkVoidFunction)InterceptCmdCopyMicromapEXT;
  if (0 == strcmp(func, "vkCmdCopyMicromapToMemoryEXT"))
    return (PFN_vkVoidFunction)InterceptCmdCopyMicromapToMemoryEXT;
  if (0 == strcmp(func, "vkCmdCopyMemoryToMicromapEXT"))
    return (PFN_vkVoidFunction)InterceptCmdCopyMemoryToMicromapEXT;
  if (0 == strcmp(func, "vkCmdWriteMicromapsPropertiesEXT"))
    return (PFN_vkVoidFunction)InterceptCmdWriteMicromapsPropertiesEXT;
  if (0 == strcmp(func, "vkCmdDrawClusterHUAWEI"))
    return (PFN_vkVoidFunction)InterceptCmdDrawClusterHUAWEI;
  if (0 == strcmp(func, "vkCmdDrawClusterIndirectHUAWEI"))
    return (PFN_vkVoidFunction)InterceptCmdDrawClusterIndirectHUAWEI;
  if (0 == strcmp(func, "vkCmdCopyMemoryIndirectNV"))
    return (PFN_vkVoidFunction)InterceptCmdCopyMemoryIndirectNV;
  if (0 == strcmp(func, "vkCmdCopyMemoryToImageIndirectNV"))
    return (PFN_vkVoidFunction)InterceptCmdCopyMemoryToImageIndirectNV;
  if (0 == strcmp(func, "vkCmdDecompressMemoryNV"))
    return (PFN_vkVoidFunction)InterceptCmdDecompressMemoryNV;
  if (0 == strcmp(func, "vkCmdDecompressMemoryIndirectCountNV"))
    return (PFN_vkVoidFunction)InterceptCmdDecompressMemoryIndirectCountNV;
  if (0 == strcmp(func, "vkCmdUpdatePipelineIndirectBufferNV"))
    return (PFN_vkVoidFunction)InterceptCmdUpdatePipelineIndirectBufferNV;
  if (0 == strcmp(func, "vkCmdSetTessellationDomainOriginEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetTessellationDomainOriginEXT;
  if (0 == strcmp(func, "vkCmdSetDepthClampEnableEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetDepthClampEnableEXT;
  if (0 == strcmp(func, "vkCmdSetPolygonModeEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetPolygonModeEXT;
  if (0 == strcmp(func, "vkCmdSetRasterizationSamplesEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetRasterizationSamplesEXT;
  if (0 == strcmp(func, "vkCmdSetSampleMaskEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetSampleMaskEXT;
  if (0 == strcmp(func, "vkCmdSetAlphaToCoverageEnableEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetAlphaToCoverageEnableEXT;
  if (0 == strcmp(func, "vkCmdSetAlphaToOneEnableEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetAlphaToOneEnableEXT;
  if (0 == strcmp(func, "vkCmdSetLogicOpEnableEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetLogicOpEnableEXT;
  if (0 == strcmp(func, "vkCmdSetColorBlendEnableEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetColorBlendEnableEXT;
  if (0 == strcmp(func, "vkCmdSetColorBlendEquationEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetColorBlendEquationEXT;
  if (0 == strcmp(func, "vkCmdSetColorWriteMaskEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetColorWriteMaskEXT;
  if (0 == strcmp(func, "vkCmdSetRasterizationStreamEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetRasterizationStreamEXT;
  if (0 == strcmp(func, "vkCmdSetConservativeRasterizationModeEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetConservativeRasterizationModeEXT;
  if (0 == strcmp(func, "vkCmdSetExtraPrimitiveOverestimationSizeEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetExtraPrimitiveOverestimationSizeEXT;
  if (0 == strcmp(func, "vkCmdSetDepthClipEnableEXT"))
    return (PFN_vkVoidFunction)InterceptCmdSetDepthClipEnableEXT;
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
  if (0 == strcmp(func, "vkCmdSetViewportSwizzleNV"))
    return (PFN_vkVoidFunction)InterceptCmdSetViewportSwizzleNV;
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
  if (0 == strcmp(func, "vkCmdOpticalFlowExecuteNV"))
    return (PFN_vkVoidFunction)InterceptCmdOpticalFlowExecuteNV;
  if (0 == strcmp(func, "vkCmdBindShadersEXT"))
    return (PFN_vkVoidFunction)InterceptCmdBindShadersEXT;
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
  if (0 == strcmp(func, "vkCmdTraceRaysKHR"))
    return (PFN_vkVoidFunction)InterceptCmdTraceRaysKHR;
  if (0 == strcmp(func, "vkCmdTraceRaysIndirectKHR"))
    return (PFN_vkVoidFunction)InterceptCmdTraceRaysIndirectKHR;
  if (0 == strcmp(func, "vkCmdSetRayTracingPipelineStackSizeKHR"))
    return (PFN_vkVoidFunction)InterceptCmdSetRayTracingPipelineStackSizeKHR;
  if (0 == strcmp(func, "vkCmdDrawMeshTasksEXT"))
    return (PFN_vkVoidFunction)InterceptCmdDrawMeshTasksEXT;
  if (0 == strcmp(func, "vkCmdDrawMeshTasksIndirectEXT"))
    return (PFN_vkVoidFunction)InterceptCmdDrawMeshTasksIndirectEXT;
  if (0 == strcmp(func, "vkCmdDrawMeshTasksIndirectCountEXT"))
    return (PFN_vkVoidFunction)InterceptCmdDrawMeshTasksIndirectCountEXT;

  return nullptr;
}

} // namespace crash_diagnostic_layer

extern "C" {

CDL_EXPORT VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL CDL_GetInstanceProcAddr(
    VkInstance inst, const char *func) {
  PFN_vkVoidFunction return_func = crash_diagnostic_layer::GetInstanceFuncs(func);
  if(return_func != nullptr) {
    return return_func;
  }
  return_func = crash_diagnostic_layer::GetDeviceFuncs(func);
  if(return_func != nullptr) {
    return return_func;
  }

  // If the function was not found, just pass it down the chain to support
  // unregistered extensions, such as vkSwapchainCallbackEXT.
  return (PFN_vkVoidFunction)crash_diagnostic_layer::PassInstanceProcDownTheChain(inst, func);
}

CDL_EXPORT VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL CDL_GetDeviceProcAddr(
    VkDevice dev, const char *func) {
  PFN_vkVoidFunction return_func = crash_diagnostic_layer::GetDeviceFuncs(func);
  if(return_func != nullptr) {
    return return_func;
  }

  // If the function was not found, just pass it down the chain to support
  // unregistered extensions, such as vkSwapchainCallbackEXT.
  return (PFN_vkVoidFunction)crash_diagnostic_layer::PassDeviceProcDownTheChain(dev, func);
} // NOLINT(readability/fn_size)

CDL_EXPORT VKAPI_ATTR VkResult VKAPI_CALL CDL_NegotiateLoaderLayerInterfaceVersion(
    VkNegotiateLayerInterface *pVersionStruct) {
  assert(pVersionStruct != NULL);
  assert(pVersionStruct->sType == LAYER_NEGOTIATE_INTERFACE_STRUCT);
  // Fill in the function pointers if our version is at least capable of having
  // the structure contain them.
  if (pVersionStruct->loaderLayerInterfaceVersion >= 2) {
    pVersionStruct->pfnGetInstanceProcAddr = &CDL_GetInstanceProcAddr;
    pVersionStruct->pfnGetDeviceProcAddr = &CDL_GetDeviceProcAddr;
    pVersionStruct->pfnGetPhysicalDeviceProcAddr = nullptr;
  }
  if (pVersionStruct->loaderLayerInterfaceVersion >
      CURRENT_LOADER_LAYER_INTERFACE_VERSION) {
    pVersionStruct->loaderLayerInterfaceVersion =
        CURRENT_LOADER_LAYER_INTERFACE_VERSION;
  }
  return VK_SUCCESS;
}

} // extern "C"



// NOLINTEND

