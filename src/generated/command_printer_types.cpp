
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
 * ***   Update source file command_printer_generator.py for modifications
 * *** ---- WARNING! ----
 *
 ****************************************************************************/

// NOLINTBEGIN

#include <streambuf>
#include <vulkan/vk_enum_string_helper.h>

#include "command_common.h"
#include "command_printer.h"
#include "util.h"

const ObjectInfoDB *global_name_resolver = nullptr;
void CommandPrinter::SetNameResolver(const ObjectInfoDB *name_resolver) { global_name_resolver = name_resolver; }

// Handle stream operators

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkBuffer &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkImage &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkInstance &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDevice &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkDevice &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkQueue &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkSemaphore &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkCommandBuffer &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkFence &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceMemory &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkEvent &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkQueryPool &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkBufferView &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageView &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkShaderModule &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineCache &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineLayout &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipeline &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkRenderPass &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorSetLayout &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkSampler &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorSet &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorPool &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkFramebuffer &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkCommandPool &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkSamplerYcbcrConversion &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorUpdateTemplate &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkPrivateDataSlot &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkSurfaceKHR &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkSwapchainKHR &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkDisplayKHR &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkDisplayModeKHR &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoSessionKHR &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoSessionParametersKHR &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeferredOperationKHR &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineBinaryKHR &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkDebugReportCallbackEXT &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkCuModuleNVX &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkCuFunctionNVX &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkDebugUtilsMessengerEXT &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkValidationCacheEXT &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureNV &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkPerformanceConfigurationINTEL &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkIndirectCommandsLayoutNV &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkCudaModuleNV &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkCudaFunctionNV &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureKHR &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#ifdef VK_USE_PLATFORM_FUCHSIA
#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkBufferCollectionFUCHSIA &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES
#endif  // VK_USE_PLATFORM_FUCHSIA

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkMicromapEXT &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkOpticalFlowSessionNV &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkShaderEXT &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkIndirectExecutionSetEXT &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES

YAML::Emitter &operator<<(YAML::Emitter &os, const VkIndirectCommandsLayoutEXT &a) {
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

// Define stream operators for enums.

YAML::Emitter &operator<<(YAML::Emitter &os, const VkResult &t) {
    os << string_VkResult(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkStructureType &t) {
    os << string_VkStructureType(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineCacheHeaderVersion &t) {
    os << string_VkPipelineCacheHeaderVersion(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageLayout &t) {
    os << string_VkImageLayout(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkObjectType &t) {
    os << string_VkObjectType(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkVendorId &t) {
    os << string_VkVendorId(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkSystemAllocationScope &t) {
    os << string_VkSystemAllocationScope(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkInternalAllocationType &t) {
    os << string_VkInternalAllocationType(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkFormat &t) {
    os << string_VkFormat(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageTiling &t) {
    os << string_VkImageTiling(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageType &t) {
    os << string_VkImageType(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceType &t) {
    os << string_VkPhysicalDeviceType(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkQueryType &t) {
    os << string_VkQueryType(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkSharingMode &t) {
    os << string_VkSharingMode(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkComponentSwizzle &t) {
    os << string_VkComponentSwizzle(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkImageViewType &t) {
    os << string_VkImageViewType(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkBlendFactor &t) {
    os << string_VkBlendFactor(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkBlendOp &t) {
    os << string_VkBlendOp(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkCompareOp &t) {
    os << string_VkCompareOp(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkDynamicState &t) {
    os << string_VkDynamicState(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkFrontFace &t) {
    os << string_VkFrontFace(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkVertexInputRate &t) {
    os << string_VkVertexInputRate(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkPrimitiveTopology &t) {
    os << string_VkPrimitiveTopology(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkPolygonMode &t) {
    os << string_VkPolygonMode(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkStencilOp &t) {
    os << string_VkStencilOp(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkLogicOp &t) {
    os << string_VkLogicOp(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkBorderColor &t) {
    os << string_VkBorderColor(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkFilter &t) {
    os << string_VkFilter(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkSamplerAddressMode &t) {
    os << string_VkSamplerAddressMode(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkSamplerMipmapMode &t) {
    os << string_VkSamplerMipmapMode(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorType &t) {
    os << string_VkDescriptorType(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkAttachmentLoadOp &t) {
    os << string_VkAttachmentLoadOp(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkAttachmentStoreOp &t) {
    os << string_VkAttachmentStoreOp(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineBindPoint &t) {
    os << string_VkPipelineBindPoint(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkCommandBufferLevel &t) {
    os << string_VkCommandBufferLevel(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkIndexType &t) {
    os << string_VkIndexType(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkSubpassContents &t) {
    os << string_VkSubpassContents(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkPointClippingBehavior &t) {
    os << string_VkPointClippingBehavior(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkTessellationDomainOrigin &t) {
    os << string_VkTessellationDomainOrigin(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkSamplerYcbcrModelConversion &t) {
    os << string_VkSamplerYcbcrModelConversion(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkSamplerYcbcrRange &t) {
    os << string_VkSamplerYcbcrRange(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkChromaLocation &t) {
    os << string_VkChromaLocation(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkDescriptorUpdateTemplateType &t) {
    os << string_VkDescriptorUpdateTemplateType(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkDriverId &t) {
    os << string_VkDriverId(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkShaderFloatControlsIndependence &t) {
    os << string_VkShaderFloatControlsIndependence(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkSamplerReductionMode &t) {
    os << string_VkSamplerReductionMode(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkSemaphoreType &t) {
    os << string_VkSemaphoreType(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkPresentModeKHR &t) {
    os << string_VkPresentModeKHR(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkColorSpaceKHR &t) {
    os << string_VkColorSpaceKHR(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkQueryResultStatusKHR &t) {
    os << string_VkQueryResultStatusKHR(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkPerformanceCounterUnitKHR &t) {
    os << string_VkPerformanceCounterUnitKHR(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkPerformanceCounterScopeKHR &t) {
    os << string_VkPerformanceCounterScopeKHR(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkPerformanceCounterStorageKHR &t) {
    os << string_VkPerformanceCounterStorageKHR(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkQueueGlobalPriorityKHR &t) {
    os << string_VkQueueGlobalPriorityKHR(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkFragmentShadingRateCombinerOpKHR &t) {
    os << string_VkFragmentShadingRateCombinerOpKHR(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineExecutableStatisticFormatKHR &t) {
    os << string_VkPipelineExecutableStatisticFormatKHR(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkVideoEncodeTuningModeKHR &t) {
    os << string_VkVideoEncodeTuningModeKHR(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkComponentTypeKHR &t) {
    os << string_VkComponentTypeKHR(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkScopeKHR &t) {
    os << string_VkScopeKHR(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkLineRasterizationModeKHR &t) {
    os << string_VkLineRasterizationModeKHR(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkTimeDomainKHR &t) {
    os << string_VkTimeDomainKHR(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkPhysicalDeviceLayeredApiKHR &t) {
    os << string_VkPhysicalDeviceLayeredApiKHR(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkDebugReportObjectTypeEXT &t) {
    os << string_VkDebugReportObjectTypeEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkRasterizationOrderAMD &t) {
    os << string_VkRasterizationOrderAMD(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkShaderInfoTypeAMD &t) {
    os << string_VkShaderInfoTypeAMD(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkValidationCheckEXT &t) {
    os << string_VkValidationCheckEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineRobustnessBufferBehaviorEXT &t) {
    os << string_VkPipelineRobustnessBufferBehaviorEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkPipelineRobustnessImageBehaviorEXT &t) {
    os << string_VkPipelineRobustnessImageBehaviorEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkDisplayPowerStateEXT &t) {
    os << string_VkDisplayPowerStateEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceEventTypeEXT &t) {
    os << string_VkDeviceEventTypeEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkDisplayEventTypeEXT &t) {
    os << string_VkDisplayEventTypeEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkViewportCoordinateSwizzleNV &t) {
    os << string_VkViewportCoordinateSwizzleNV(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkDiscardRectangleModeEXT &t) {
    os << string_VkDiscardRectangleModeEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkConservativeRasterizationModeEXT &t) {
    os << string_VkConservativeRasterizationModeEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkBlendOverlapEXT &t) {
    os << string_VkBlendOverlapEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkCoverageModulationModeNV &t) {
    os << string_VkCoverageModulationModeNV(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkValidationCacheHeaderVersionEXT &t) {
    os << string_VkValidationCacheHeaderVersionEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkShadingRatePaletteEntryNV &t) {
    os << string_VkShadingRatePaletteEntryNV(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkCoarseSampleOrderTypeNV &t) {
    os << string_VkCoarseSampleOrderTypeNV(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkRayTracingShaderGroupTypeKHR &t) {
    os << string_VkRayTracingShaderGroupTypeKHR(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkGeometryTypeKHR &t) {
    os << string_VkGeometryTypeKHR(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureTypeKHR &t) {
    os << string_VkAccelerationStructureTypeKHR(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkCopyAccelerationStructureModeKHR &t) {
    os << string_VkCopyAccelerationStructureModeKHR(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureMemoryRequirementsTypeNV &t) {
    os << string_VkAccelerationStructureMemoryRequirementsTypeNV(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkMemoryOverallocationBehaviorAMD &t) {
    os << string_VkMemoryOverallocationBehaviorAMD(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkPerformanceConfigurationTypeINTEL &t) {
    os << string_VkPerformanceConfigurationTypeINTEL(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkQueryPoolSamplingModeINTEL &t) {
    os << string_VkQueryPoolSamplingModeINTEL(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkPerformanceOverrideTypeINTEL &t) {
    os << string_VkPerformanceOverrideTypeINTEL(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkPerformanceParameterTypeINTEL &t) {
    os << string_VkPerformanceParameterTypeINTEL(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkPerformanceValueTypeINTEL &t) {
    os << string_VkPerformanceValueTypeINTEL(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkValidationFeatureEnableEXT &t) {
    os << string_VkValidationFeatureEnableEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkValidationFeatureDisableEXT &t) {
    os << string_VkValidationFeatureDisableEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkCoverageReductionModeNV &t) {
    os << string_VkCoverageReductionModeNV(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkProvokingVertexModeEXT &t) {
    os << string_VkProvokingVertexModeEXT(t);
    return os;
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
YAML::Emitter &operator<<(YAML::Emitter &os, const VkFullScreenExclusiveEXT &t) {
    os << string_VkFullScreenExclusiveEXT(t);
    return os;
}
#endif  // VK_USE_PLATFORM_WIN32_KHR

YAML::Emitter &operator<<(YAML::Emitter &os, const VkIndirectCommandsTokenTypeNV &t) {
    os << string_VkIndirectCommandsTokenTypeNV(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkDepthBiasRepresentationEXT &t) {
    os << string_VkDepthBiasRepresentationEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceMemoryReportEventTypeEXT &t) {
    os << string_VkDeviceMemoryReportEventTypeEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkFragmentShadingRateTypeNV &t) {
    os << string_VkFragmentShadingRateTypeNV(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkFragmentShadingRateNV &t) {
    os << string_VkFragmentShadingRateNV(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureMotionInstanceTypeNV &t) {
    os << string_VkAccelerationStructureMotionInstanceTypeNV(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceFaultAddressTypeEXT &t) {
    os << string_VkDeviceFaultAddressTypeEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceFaultVendorBinaryHeaderVersionEXT &t) {
    os << string_VkDeviceFaultVendorBinaryHeaderVersionEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkDeviceAddressBindingTypeEXT &t) {
    os << string_VkDeviceAddressBindingTypeEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkMicromapTypeEXT &t) {
    os << string_VkMicromapTypeEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkBuildMicromapModeEXT &t) {
    os << string_VkBuildMicromapModeEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkCopyMicromapModeEXT &t) {
    os << string_VkCopyMicromapModeEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkOpacityMicromapFormatEXT &t) {
    os << string_VkOpacityMicromapFormatEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkOpacityMicromapSpecialIndexEXT &t) {
    os << string_VkOpacityMicromapSpecialIndexEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureCompatibilityKHR &t) {
    os << string_VkAccelerationStructureCompatibilityKHR(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureBuildTypeKHR &t) {
    os << string_VkAccelerationStructureBuildTypeKHR(t);
    return os;
}

#ifdef VK_ENABLE_BETA_EXTENSIONS
YAML::Emitter &operator<<(YAML::Emitter &os, const VkDisplacementMicromapFormatNV &t) {
    os << string_VkDisplacementMicromapFormatNV(t);
    return os;
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

YAML::Emitter &operator<<(YAML::Emitter &os, const VkSubpassMergeStatusEXT &t) {
    os << string_VkSubpassMergeStatusEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkDirectDriverLoadingModeLUNARG &t) {
    os << string_VkDirectDriverLoadingModeLUNARG(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkOpticalFlowPerformanceLevelNV &t) {
    os << string_VkOpticalFlowPerformanceLevelNV(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkOpticalFlowSessionBindingPointNV &t) {
    os << string_VkOpticalFlowSessionBindingPointNV(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkAntiLagModeAMD &t) {
    os << string_VkAntiLagModeAMD(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkAntiLagStageAMD &t) {
    os << string_VkAntiLagStageAMD(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkShaderCodeTypeEXT &t) {
    os << string_VkShaderCodeTypeEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkDepthClampModeEXT &t) {
    os << string_VkDepthClampModeEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkRayTracingInvocationReorderModeNV &t) {
    os << string_VkRayTracingInvocationReorderModeNV(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkLayerSettingTypeEXT &t) {
    os << string_VkLayerSettingTypeEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkLatencyMarkerNV &t) {
    os << string_VkLatencyMarkerNV(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkOutOfBandQueueTypeNV &t) {
    os << string_VkOutOfBandQueueTypeNV(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkBlockMatchWindowCompareModeQCOM &t) {
    os << string_VkBlockMatchWindowCompareModeQCOM(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkCubicFilterWeightsQCOM &t) {
    os << string_VkCubicFilterWeightsQCOM(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkLayeredDriverUnderlyingApiMSFT &t) {
    os << string_VkLayeredDriverUnderlyingApiMSFT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkIndirectExecutionSetInfoTypeEXT &t) {
    os << string_VkIndirectExecutionSetInfoTypeEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkIndirectCommandsTokenTypeEXT &t) {
    os << string_VkIndirectCommandsTokenTypeEXT(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkBuildAccelerationStructureModeKHR &t) {
    os << string_VkBuildAccelerationStructureModeKHR(t);
    return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkShaderGroupShaderKHR &t) {
    os << string_VkShaderGroupShaderKHR(t);
    return os;
}

// NOLINTEND
