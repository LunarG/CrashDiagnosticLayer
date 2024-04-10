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

import os
import sys
from generators.base_generator import BaseGenerator

implemented_instance_extensions = [
    'VK_EXT_debug_report',
    'VK_EXT_debug_utils'
]

implemented_device_extensions = [
    'VK_EXT_debug_marker'
]

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
    'vkGetSemaphoreCounterValueKHR',
    'vkSignalSemaphoreKHR',
    'vkWaitSemaphoresKHR',
    'vkDebugMarkerSetObjectNameEXT',
    'vkSetDebugUtilsObjectNameEXT',
    'vkQueueSubmit',
    'vkQueueSubmit2',
    'vkQueueSubmit2KHR',
    'vkQueueBindSparse',
]

namespace = 'crash_diagnostic_layer'
layer_name = 'VK_LAYER_LUNARG_crash_diagnostic'
layer_version = '1'
layer_description = 'Crash Diagnostic Layer is a crash/hang debugging tool ' \
                    'that helps determines GPU progress in a Vulkan application.'

#
# CdlBaseOutputGenerator - Base Generator for the whole Graphics Flight Recorder
class CdlBaseOutputGenerator(BaseGenerator):
    def __init__(self):
        BaseGenerator.__init__(self)

        self.implemented_instance_extensions = implemented_instance_extensions
        self.implemented_device_extensions = implemented_device_extensions
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

    def CommandBufferCall(self, vkcommand):
        intercept = (vkcommand.name.startswith('vkCmd') or
                     vkcommand.params[0].type == 'VkCommandBuffer')
        return intercept

    def NeedsIntercept(self, vkcommand):
        intercept = (self.CommandBufferCall(vkcommand) or
                        vkcommand.name in custom_intercept_commands)
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

    def InstanceCommand(self, vkcommand):
        return vkcommand.instance or vkcommand.params[0].type == 'VkPhysicalDevice'

    def CommandHasReturn(self, vkcommand):
        return vkcommand.returnType is not None and vkcommand.returnType != 'void'

    def GetLayerName(self):
        return layer_name

    def GetLayerVersion(self):
        return layer_version

    def GetLayerDescription(self):
        return layer_description

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
