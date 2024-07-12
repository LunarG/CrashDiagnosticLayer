#!/usr/bin/python3 -i
#
# Copyright (c) 2023-2024 LunarG, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from generators.base_generator import BaseGenerator

custom_intercept_commands = [
    'vkCreateInstance',
    'vkDestroyInstance',
    'vkCreateDevice',
    'vkDestroyDevice',
    'vkEnumerateInstanceLayerProperties',
    'vkEnumerateDeviceLayerProperties',
    'vkEnumerateInstanceExtensionProperties',
    'vkEnumerateDeviceExtensionProperties',
    'vkQueueSubmit',
    'vkQueueSubmit2',
    'vkQueueSubmit2KHR',
    'vkQueueBindSparse',
    'vkGetPhysicalDeviceToolPropertiesEXT',
    'vkGetPhysicalDeviceToolProperties',
]

intercept_pre_functions = [
    'vkDestroyInstance',
]

no_intercept_pre_functions = [
    'vkCreateInstance',
    'vkCreateDevice',
    'vkEnumerateInstanceLayerProperties',
    'vkEnumerateDeviceLayerProperties',
    'vkEnumerateInstanceExtensionProperties',
    'vkEnumerateDeviceExtensionProperties',
    'vkQueueSubmit',
    'vkQueueSubmit2',
    'vkQueueSubmit2KHR',
    'vkQueueBindSparse',
    'vkGetPhysicalDeviceToolPropertiesEXT',
    'vkGetPhysicalDeviceToolProperties',
]

intercept_post_functions = [
    'vkGetDeviceQueue',
    'vkCreateShaderModule',
    'vkDestroyShaderModule',
    'vkCreateGraphicsPipelines',
    'vkCreateComputePipelines',
]

no_intercept_post_functions = [
    'vkDestroyInstance',
    'vkEnumerateInstanceLayerProperties',
    'vkEnumerateDeviceLayerProperties',
    'vkEnumerateInstanceExtensionProperties',
    'vkQueueSubmit',
    'vkQueueSubmit2',
    'vkQueueSubmit2KHR',
    'vkQueueBindSparse',
    'vkGetPhysicalDeviceToolPropertiesEXT',
    'vkGetPhysicalDeviceToolProperties',
]

intercept_override_functions = [
    'vkQueueSubmit',
    'vkQueueSubmit2',
    'vkQueueSubmit2KHR',
    'vkQueueBindSparse',
]

intercept_functions = [
    'vkDestroyCommandPool',
    'vkResetCommandPool',
    'vkAllocateCommandBuffers',
    'vkFreeCommandBuffers',
    'vkDeviceWaitIdle',
    'vkQueueWaitIdle',
    'vkGetFenceStatus',
    'vkWaitForFences',
    'vkCreateSemaphore',
    'vkDestroySemaphore',
    'vkGetQueryPoolResults',
    'vkDestroyPipeline',
    'vkGetDeviceQueue2',
    'vkCreateCommandPool',
    'vkAcquireNextImageKHR',
    'vkQueuePresentKHR',
    'vkGetSemaphoreCounterValue',
    'vkGetSemaphoreCounterValueKHR',
    'vkSignalSemaphore',
    'vkSignalSemaphoreKHR',
    'vkWaitSemaphores',
    'vkWaitSemaphoresKHR',
    'vkDebugMarkerSetObjectNameEXT',
    'vkSetDebugUtilsObjectNameEXT',
    'vkQueueSubmit',
    'vkQueueSubmit2',
    'vkQueueSubmit2KHR',
    'vkQueueBindSparse',
    'vkGetPhysicalDeviceToolPropertiesEXT',
    'vkGetPhysicalDeviceToolProperties',
    'vkCreateDebugUtilsMessengerEXT',
    'vkDestroyDebugUtilsMessengerEXT',
    'vkCreateDebugReportCallbackEXT',
    'vkDestroyDebugReportCallbackEXT',
]

namespace = 'crash_diagnostic_layer'

#
# CdlBaseOutputGenerator - Base Generator for the whole Crash Diagnostic Layer
class CdlBaseOutputGenerator(BaseGenerator):
    def __init__(self):
        BaseGenerator.__init__(self)
        self.custom_intercept_commands = custom_intercept_commands

    def GenerateFileStart(self, filename):
        file_start = f'''
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
* ***   Update source file {filename} for modifications
* *** ---- WARNING! ----
*
****************************************************************************/\n

// NOLINTBEGIN
'''
        return file_start

    def GenerateFileEnd(self):
        file_end = '\n// NOLINTEND\n'
        return file_end

    def GenerateNamespaceBegin(self):
        namespace_text = f'\nnamespace {namespace} {{\n'
        return namespace_text

    def GenerateNamespaceEnd(self):
        namespace_text = f'\n}} // namespace {namespace}\n'
        return namespace_text

    def CreateNamespaceReference(self, item):
        namespace_text = f'{namespace}::{item}'
        return namespace_text

    def CommandBufferCall(self, command):
        intercept = (command.name.startswith('vkCmd') or
                     command.params[0].type == 'VkCommandBuffer')
        return intercept

    def NeedsIntercept(self, command):
        intercept = (self.CommandBufferCall(command) or
                        command.name in custom_intercept_commands)
        return intercept

    def InterceptPreCommand(self, command):
        intercept = False
        if ((self.NeedsIntercept(command) or command.name in intercept_functions or command.name in intercept_pre_functions)
            and command.name not in no_intercept_pre_functions):
            intercept = True
        return intercept

    def InterceptPostCommand(self, command):
        intercept = False
        if ((self.NeedsIntercept(command) or command.name in intercept_functions or command.name in intercept_post_functions)
            and command.name not in no_intercept_post_functions):
            intercept = True
        return intercept

    def InterceptOverrideCommand(self, command):
        intercept = False
        if (command.name in intercept_override_functions):
            intercept = True
        return intercept

    def InterceptCommand(self, command):
        return self.InterceptPreCommand(command) or self.InterceptPostCommand(command) or self.InterceptOverrideCommand(command)

    def InstanceCommand(self, command):
        return command.instance or command.params[0].type == 'VkPhysicalDevice'

    def CommandHasReturn(self, command):
        return command.returnType is not None and command.returnType != 'void'

    def GetDefaultReturnValue(self, return_type):
        return_string = ''
        if return_type == 'VkResult':
            return_string = 'VK_SUCCESS'
        elif return_type in self.vk.structs.values():
            return_string = 'nullptr'
        elif 'int' in return_type and '64' not in return_type:
            return_string = '0'
        elif 'int64' in return_type or 'Address' in return_type or 'Size' in return_type:
            return_string = '0ULL'
        elif return_type == 'VkBool32':
            return_string = 'VK_FALSE'
        elif 'PFN_' in return_type:
            return_string = 'nullptr'
        elif 'PFN_' in return_type:
            return_string = 'UNKNOWN_VALUE'
        return return_string
