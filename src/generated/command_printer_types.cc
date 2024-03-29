
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

// Handle ostream operators

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkBuffer &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkImage &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

std::ostream &operator<<(std::ostream &os, const VkInstance &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkPhysicalDevice &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkDevice &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkQueue &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkSemaphore &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

std::ostream &operator<<(std::ostream &os, const VkCommandBuffer &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkFence &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkDeviceMemory &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkEvent &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkQueryPool &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkBufferView &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkImageView &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkShaderModule &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkPipelineCache &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkPipelineLayout &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkPipeline &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkRenderPass &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkDescriptorSetLayout &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkSampler &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkDescriptorSet &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkDescriptorPool &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkFramebuffer &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkCommandPool &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkSamplerYcbcrConversion &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkDescriptorUpdateTemplate &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkPrivateDataSlot &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkSurfaceKHR &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkSwapchainKHR &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkDisplayKHR &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkDisplayModeKHR &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkVideoSessionKHR &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkVideoSessionParametersKHR &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkDeferredOperationKHR &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkDebugReportCallbackEXT &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkCuModuleNVX &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkCuFunctionNVX &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkDebugUtilsMessengerEXT &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkValidationCacheEXT &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkAccelerationStructureNV &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkPerformanceConfigurationINTEL &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkIndirectCommandsLayoutNV &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkCudaModuleNV &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkCudaFunctionNV &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkAccelerationStructureKHR &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#ifdef VK_USE_PLATFORM_FUCHSIA
#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkBufferCollectionFUCHSIA &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES
#endif  // VK_USE_PLATFORM_FUCHSIA

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkMicromapEXT &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkOpticalFlowSessionNV &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

#if VK_USE_64_BIT_PTR_DEFINES
std::ostream &operator<<(std::ostream &os, const VkShaderEXT &a) {
    auto handle = (uint64_t)(a);
    os << crash_diagnostic_layer::Uint64ToStr(handle) << std::endl;

    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
        os << "debugName: \"" << debug_name << "\"";
    }
    return os;
}
#endif  // VK_USE_64_BIT_PTR_DEFINES

// Define ostream operators for enums.

std::ostream &operator<<(std::ostream &os, const VkResult &t) {
    os << string_VkResult(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkStructureType &t) {
    os << string_VkStructureType(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkPipelineCacheHeaderVersion &t) {
    os << string_VkPipelineCacheHeaderVersion(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkImageLayout &t) {
    os << string_VkImageLayout(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkObjectType &t) {
    os << string_VkObjectType(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkVendorId &t) {
    os << string_VkVendorId(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkSystemAllocationScope &t) {
    os << string_VkSystemAllocationScope(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkInternalAllocationType &t) {
    os << string_VkInternalAllocationType(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkFormat &t) {
    os << string_VkFormat(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkImageTiling &t) {
    os << string_VkImageTiling(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkImageType &t) {
    os << string_VkImageType(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkPhysicalDeviceType &t) {
    os << string_VkPhysicalDeviceType(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkQueryType &t) {
    os << string_VkQueryType(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkSharingMode &t) {
    os << string_VkSharingMode(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkComponentSwizzle &t) {
    os << string_VkComponentSwizzle(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkImageViewType &t) {
    os << string_VkImageViewType(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkBlendFactor &t) {
    os << string_VkBlendFactor(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkBlendOp &t) {
    os << string_VkBlendOp(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkCompareOp &t) {
    os << string_VkCompareOp(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkDynamicState &t) {
    os << string_VkDynamicState(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkFrontFace &t) {
    os << string_VkFrontFace(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkVertexInputRate &t) {
    os << string_VkVertexInputRate(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkPrimitiveTopology &t) {
    os << string_VkPrimitiveTopology(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkPolygonMode &t) {
    os << string_VkPolygonMode(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkStencilOp &t) {
    os << string_VkStencilOp(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkLogicOp &t) {
    os << string_VkLogicOp(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkBorderColor &t) {
    os << string_VkBorderColor(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkFilter &t) {
    os << string_VkFilter(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkSamplerAddressMode &t) {
    os << string_VkSamplerAddressMode(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkSamplerMipmapMode &t) {
    os << string_VkSamplerMipmapMode(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkDescriptorType &t) {
    os << string_VkDescriptorType(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkAttachmentLoadOp &t) {
    os << string_VkAttachmentLoadOp(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkAttachmentStoreOp &t) {
    os << string_VkAttachmentStoreOp(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkPipelineBindPoint &t) {
    os << string_VkPipelineBindPoint(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkCommandBufferLevel &t) {
    os << string_VkCommandBufferLevel(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkIndexType &t) {
    os << string_VkIndexType(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkSubpassContents &t) {
    os << string_VkSubpassContents(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkPointClippingBehavior &t) {
    os << string_VkPointClippingBehavior(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkTessellationDomainOrigin &t) {
    os << string_VkTessellationDomainOrigin(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkSamplerYcbcrModelConversion &t) {
    os << string_VkSamplerYcbcrModelConversion(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkSamplerYcbcrRange &t) {
    os << string_VkSamplerYcbcrRange(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkChromaLocation &t) {
    os << string_VkChromaLocation(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkDescriptorUpdateTemplateType &t) {
    os << string_VkDescriptorUpdateTemplateType(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkDriverId &t) {
    os << string_VkDriverId(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkShaderFloatControlsIndependence &t) {
    os << string_VkShaderFloatControlsIndependence(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkSamplerReductionMode &t) {
    os << string_VkSamplerReductionMode(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkSemaphoreType &t) {
    os << string_VkSemaphoreType(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkPresentModeKHR &t) {
    os << string_VkPresentModeKHR(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkColorSpaceKHR &t) {
    os << string_VkColorSpaceKHR(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkQueryResultStatusKHR &t) {
    os << string_VkQueryResultStatusKHR(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkPerformanceCounterUnitKHR &t) {
    os << string_VkPerformanceCounterUnitKHR(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkPerformanceCounterScopeKHR &t) {
    os << string_VkPerformanceCounterScopeKHR(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkPerformanceCounterStorageKHR &t) {
    os << string_VkPerformanceCounterStorageKHR(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkQueueGlobalPriorityKHR &t) {
    os << string_VkQueueGlobalPriorityKHR(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkFragmentShadingRateCombinerOpKHR &t) {
    os << string_VkFragmentShadingRateCombinerOpKHR(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkPipelineExecutableStatisticFormatKHR &t) {
    os << string_VkPipelineExecutableStatisticFormatKHR(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkVideoEncodeTuningModeKHR &t) {
    os << string_VkVideoEncodeTuningModeKHR(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkComponentTypeKHR &t) {
    os << string_VkComponentTypeKHR(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkScopeKHR &t) {
    os << string_VkScopeKHR(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkLineRasterizationModeKHR &t) {
    os << string_VkLineRasterizationModeKHR(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkTimeDomainKHR &t) {
    os << string_VkTimeDomainKHR(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkDebugReportObjectTypeEXT &t) {
    os << string_VkDebugReportObjectTypeEXT(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkRasterizationOrderAMD &t) {
    os << string_VkRasterizationOrderAMD(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkShaderInfoTypeAMD &t) {
    os << string_VkShaderInfoTypeAMD(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkValidationCheckEXT &t) {
    os << string_VkValidationCheckEXT(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkPipelineRobustnessBufferBehaviorEXT &t) {
    os << string_VkPipelineRobustnessBufferBehaviorEXT(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkPipelineRobustnessImageBehaviorEXT &t) {
    os << string_VkPipelineRobustnessImageBehaviorEXT(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkDisplayPowerStateEXT &t) {
    os << string_VkDisplayPowerStateEXT(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkDeviceEventTypeEXT &t) {
    os << string_VkDeviceEventTypeEXT(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkDisplayEventTypeEXT &t) {
    os << string_VkDisplayEventTypeEXT(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkViewportCoordinateSwizzleNV &t) {
    os << string_VkViewportCoordinateSwizzleNV(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkDiscardRectangleModeEXT &t) {
    os << string_VkDiscardRectangleModeEXT(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkConservativeRasterizationModeEXT &t) {
    os << string_VkConservativeRasterizationModeEXT(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkBlendOverlapEXT &t) {
    os << string_VkBlendOverlapEXT(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkCoverageModulationModeNV &t) {
    os << string_VkCoverageModulationModeNV(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkValidationCacheHeaderVersionEXT &t) {
    os << string_VkValidationCacheHeaderVersionEXT(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkShadingRatePaletteEntryNV &t) {
    os << string_VkShadingRatePaletteEntryNV(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkCoarseSampleOrderTypeNV &t) {
    os << string_VkCoarseSampleOrderTypeNV(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkRayTracingShaderGroupTypeKHR &t) {
    os << string_VkRayTracingShaderGroupTypeKHR(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkGeometryTypeKHR &t) {
    os << string_VkGeometryTypeKHR(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkAccelerationStructureTypeKHR &t) {
    os << string_VkAccelerationStructureTypeKHR(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkCopyAccelerationStructureModeKHR &t) {
    os << string_VkCopyAccelerationStructureModeKHR(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkAccelerationStructureMemoryRequirementsTypeNV &t) {
    os << string_VkAccelerationStructureMemoryRequirementsTypeNV(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkMemoryOverallocationBehaviorAMD &t) {
    os << string_VkMemoryOverallocationBehaviorAMD(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkPerformanceConfigurationTypeINTEL &t) {
    os << string_VkPerformanceConfigurationTypeINTEL(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkQueryPoolSamplingModeINTEL &t) {
    os << string_VkQueryPoolSamplingModeINTEL(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkPerformanceOverrideTypeINTEL &t) {
    os << string_VkPerformanceOverrideTypeINTEL(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkPerformanceParameterTypeINTEL &t) {
    os << string_VkPerformanceParameterTypeINTEL(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkPerformanceValueTypeINTEL &t) {
    os << string_VkPerformanceValueTypeINTEL(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkValidationFeatureEnableEXT &t) {
    os << string_VkValidationFeatureEnableEXT(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkValidationFeatureDisableEXT &t) {
    os << string_VkValidationFeatureDisableEXT(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkCoverageReductionModeNV &t) {
    os << string_VkCoverageReductionModeNV(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkProvokingVertexModeEXT &t) {
    os << string_VkProvokingVertexModeEXT(t);
    return os;
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
std::ostream &operator<<(std::ostream &os, const VkFullScreenExclusiveEXT &t) {
    os << string_VkFullScreenExclusiveEXT(t);
    return os;
}
#endif  // VK_USE_PLATFORM_WIN32_KHR

std::ostream &operator<<(std::ostream &os, const VkIndirectCommandsTokenTypeNV &t) {
    os << string_VkIndirectCommandsTokenTypeNV(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkDepthBiasRepresentationEXT &t) {
    os << string_VkDepthBiasRepresentationEXT(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkDeviceMemoryReportEventTypeEXT &t) {
    os << string_VkDeviceMemoryReportEventTypeEXT(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkFragmentShadingRateTypeNV &t) {
    os << string_VkFragmentShadingRateTypeNV(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkFragmentShadingRateNV &t) {
    os << string_VkFragmentShadingRateNV(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkAccelerationStructureMotionInstanceTypeNV &t) {
    os << string_VkAccelerationStructureMotionInstanceTypeNV(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkDeviceFaultAddressTypeEXT &t) {
    os << string_VkDeviceFaultAddressTypeEXT(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkDeviceFaultVendorBinaryHeaderVersionEXT &t) {
    os << string_VkDeviceFaultVendorBinaryHeaderVersionEXT(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkDeviceAddressBindingTypeEXT &t) {
    os << string_VkDeviceAddressBindingTypeEXT(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkMicromapTypeEXT &t) {
    os << string_VkMicromapTypeEXT(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkBuildMicromapModeEXT &t) {
    os << string_VkBuildMicromapModeEXT(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkCopyMicromapModeEXT &t) {
    os << string_VkCopyMicromapModeEXT(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkOpacityMicromapFormatEXT &t) {
    os << string_VkOpacityMicromapFormatEXT(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkOpacityMicromapSpecialIndexEXT &t) {
    os << string_VkOpacityMicromapSpecialIndexEXT(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkAccelerationStructureCompatibilityKHR &t) {
    os << string_VkAccelerationStructureCompatibilityKHR(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkAccelerationStructureBuildTypeKHR &t) {
    os << string_VkAccelerationStructureBuildTypeKHR(t);
    return os;
}

#ifdef VK_ENABLE_BETA_EXTENSIONS
std::ostream &operator<<(std::ostream &os, const VkDisplacementMicromapFormatNV &t) {
    os << string_VkDisplacementMicromapFormatNV(t);
    return os;
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

std::ostream &operator<<(std::ostream &os, const VkSubpassMergeStatusEXT &t) {
    os << string_VkSubpassMergeStatusEXT(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkDirectDriverLoadingModeLUNARG &t) {
    os << string_VkDirectDriverLoadingModeLUNARG(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkOpticalFlowPerformanceLevelNV &t) {
    os << string_VkOpticalFlowPerformanceLevelNV(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkOpticalFlowSessionBindingPointNV &t) {
    os << string_VkOpticalFlowSessionBindingPointNV(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkShaderCodeTypeEXT &t) {
    os << string_VkShaderCodeTypeEXT(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkRayTracingInvocationReorderModeNV &t) {
    os << string_VkRayTracingInvocationReorderModeNV(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkLayerSettingTypeEXT &t) {
    os << string_VkLayerSettingTypeEXT(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkLatencyMarkerNV &t) {
    os << string_VkLatencyMarkerNV(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkOutOfBandQueueTypeNV &t) {
    os << string_VkOutOfBandQueueTypeNV(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkBlockMatchWindowCompareModeQCOM &t) {
    os << string_VkBlockMatchWindowCompareModeQCOM(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkCubicFilterWeightsQCOM &t) {
    os << string_VkCubicFilterWeightsQCOM(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkLayeredDriverUnderlyingApiMSFT &t) {
    os << string_VkLayeredDriverUnderlyingApiMSFT(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkBuildAccelerationStructureModeKHR &t) {
    os << string_VkBuildAccelerationStructureModeKHR(t);
    return os;
}

std::ostream &operator<<(std::ostream &os, const VkShaderGroupShaderKHR &t) {
    os << string_VkShaderGroupShaderKHR(t);
    return os;
}

// NOLINTEND
