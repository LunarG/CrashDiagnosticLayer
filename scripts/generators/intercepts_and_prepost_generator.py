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
from generators.vulkan_object import (Queues, CommandScope)
from generators.cdl_base_generator import CdlBaseOutputGenerator

#  CDL has custom implementation for pre intercept #
custom_functions = [
    'vkCreateInstance',
    'vkEnumerateDeviceExtensionProperties',
    'vkDestroyDevice',
    'vkResetCommandPool',
    'vkDestroyCommandPool'
    'vkQueueSubmit',
    'vkQueueSubmit2',
    'vkWaitSemaphoresKHR',
    'vkQueueSubmit2KHR',
    'vkDebugMarkerSetObjectNameEXT',
    'vkSetDebugUtilsObjectNameEXT'
]

custom_pre_intercept_functions = [
    'vkCreateInstance',
    'vkBeginCommandBuffer',
    'vkResetCommandBuffer',
    'vkCmdBindPipeline'
]

custom_post_intercept_functions = [
    'vkDestroyInstance',
    'vkEnumerateDeviceExtensionProperties',
    'vkCreateDevice',
    'vkGetDeviceQueue',
    'vkGetDeviceQueue2',
    'vkDeviceWaitIdle',
    'vkQueueWaitIdle',
    'vkQueuePresentKHR',
    'vkQueueBindSparse',
    'vkWaitForFences',
    'vkGetFenceStatus',
    'vkGetQueryPoolResults',
    'vkAcquireNextImageKHR',
    'vkCreateShaderModule',
    'vkDestroyShaderModule',
    'vkCreateGraphicsPipelines',
    'vkCreateComputePipelines',
    'vkDestroyPipeline',
    'vkCreateCommandPool',
    'vkAllocateCommandBuffers',
    'vkFreeCommandBuffers',
    'vkCreateSemaphore',
    'vkDestroySemaphore',
    'vkSignalSemaphoreKHR',
    'vkGetSemaphoreCounterValueKHR'
]

default_instrumented_functions = [
    'vkCmdDispatch',
    'vkCmdDispatchIndirect',
    'vkCmdDraw',
    'vkCmdDrawIndexed',
    'vkCmdDrawIndirect',
    'vkCmdDrawIndexedIndirect',
    'vkCmdCopyBuffer',
    'vkCmdCopyBufferToImage',
    'vkCmdCopyImage',
    'vkCmdCopyImageToBuffer',
    'vkCmdBindPipeline',
    'vkCmdExecuteCommands',
    'vkCmdPipelineBarrier',
    'vkCmdSetEvent',
    'vkCmdResetEvent',
    'vkCmdWaitEvents',
    'vkCmdDebugMarkerBeginEXT',
    'vkCmdDebugMarkerEndEXT',
    'vkCmdDebugMarkerInsertEXT',
    'vkCmdBeginDebugUtilsLabelEXT',
    'vkCmdEndDebugUtilsLabelEXT',
    'vkCmdInsertDebugUtilsLabelEXT',
]

#
# InterceptCommandsOutputGenerator - Generate the dispatch tables
class InterceptCommandsOutputGenerator(CdlBaseOutputGenerator):
    def __init__(self):
        CdlBaseOutputGenerator.__init__(self)

    #
    # Called at beginning of processing as file is opened
    def generate(self):
        file_start = self.GenerateFileStart(os.path.basename(__file__))
        self.write(file_start)

        if self.filename == 'cdl_commands.h.inc':
            self.generateContextCommandsHeader()
        elif self.filename == 'cdl_commands.cc.inc':
            self.generateContextCommandsSource()
        elif self.filename == 'command.h.inc':
            self.generateCommandsHeader()
        elif self.filename == 'command.cc.inc':
            self.generateCommandsSource()
        elif self.filename == 'command_tracker.h':
            self.generateCommandTrackerHeader()
        elif self.filename == 'command_tracker.cc':
            self.generateCommandTrackerSource()
        else:
            self.write(f'\nFile name {self.filename} has no code to generate\n')

        self.write(self.GenerateFileEnd())

    def generateContextCommandsHeader(self):
        out = []
        for vkcommand in filter(lambda x: self.InterceptCommand(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            post_func_decl = vkcommand.cPrototype.replace('VKAPI_ATTR ', '').replace('VKAPI_CALL ', '').replace(' vk', ' Post', 1).replace(';', ' override;')
            pre_func_decl = post_func_decl.replace('Post', 'Pre', 1)
            if self.CommandHasReturn(vkcommand):
                post_func_decl = post_func_decl.replace(')', f',\n    {vkcommand.returnType}                                    result)')
            if self.InterceptPreCommand(vkcommand):
                out.append(f'{pre_func_decl}\n')
            if self.InterceptPostCommand(vkcommand):
                out.append(f'{post_func_decl}\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append('\n')
        self.write("".join(out))

    def generateContextCommandsSource(self):
        out = []

        for vkcommand in filter(lambda x: self.CommandBufferCall(x) and x.name not in custom_functions, self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            post_func_decl = vkcommand.cPrototype.replace('VKAPI_ATTR ', '').replace('VKAPI_CALL ', '').replace(';', ' {').replace(' vk', ' Context::Post', 1)
            pre_func_decl = post_func_decl.replace('Context::Post', 'Context::Pre', 1)
            pre_func_call = '  '
            post_func_call = '  '
            if self.CommandHasReturn(vkcommand):
                post_func_decl = post_func_decl.replace(')', f',\n    {vkcommand.returnType}                                    result)')
                pre_func_call += 'return '
                post_func_call += 'return '
            pre_func_call += f'p_cmd->Pre{vkcommand.name[2:]}('
            post_func_call += f'p_cmd->Post{vkcommand.name[2:]}('
            count = 0
            for vkparam in vkcommand.params:
                if count != 0:
                    pre_func_call += ', '
                    post_func_call += ', '
                pre_func_call += vkparam.name
                post_func_call += vkparam.name
                count += 1
            if self.CommandHasReturn(vkcommand):
                post_func_call += ', result'
            pre_func_call += ');'
            post_func_call += ');'

            # Skip vkCmdBindPipeline pre call since it's implemented by hand
            if not (vkcommand.name in custom_functions or vkcommand.name in custom_pre_intercept_functions):
                out.append(f'{pre_func_decl}\n')
                out.append('  auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);\n')
                out.append(f'{pre_func_call}\n')
                out.append('}\n')

            if not (vkcommand.name in custom_functions or vkcommand.name in custom_post_intercept_functions):
                out.append(f'{post_func_decl}\n')
                out.append('  auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);\n')
                out.append(f'{post_func_call}\n')
                out.append('}\n')

            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append('\n')
        self.write("".join(out))

    def generateCommandsHeader(self):
        out = []
        for vkcommand in filter(lambda x: x.name.startswith('vkCmd'), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            post_func_decl = vkcommand.cPrototype.replace('VKAPI_ATTR ', '').replace('VKAPI_CALL ', '').replace(' vk', ' Post', 1)
            pre_func_decl = post_func_decl.replace('Post', 'Pre', 1)
            if self.CommandHasReturn(vkcommand):
                post_func_decl = post_func_decl.replace(')', f', {vkcommand.returnType} result)', 1)
            out.append(f'{pre_func_decl}\n')
            out.append(f'{post_func_decl}\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append('\n')
        self.write("".join(out))

    def generateCommandsSource(self):
        out = []
        for vkcommand in filter(lambda x: x.name.startswith('vkCmd'), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            post_func_decl = vkcommand.cPrototype.replace('VKAPI_ATTR ', '').replace('VKAPI_CALL ', '').replace(';', ' {').replace(' vk', ' CommandBuffer::Post', 1)
            pre_func_decl = post_func_decl.replace('Post', 'Pre', 1)
            func_call = f'  tracker_.TrackPre{vkcommand.name[2:]}('
            count = 0
            for vkparam in vkcommand.params:
                if count != 0:
                    func_call += ', '
                func_call += vkparam.name
                count += 1
            func_call += ');'

            tracker_call = '  WriteBeginCommandExecutionMarker(tracker_.GetCommands().back().id);'

            out.append(f'{pre_func_decl}\n')
            out.append(f'{func_call}\n')
            if vkcommand.name not in default_instrumented_functions:
                out.append('  if (instrument_all_commands_)\n')
                out.append('  ')
            out.append(f'{tracker_call}\n')

            if self.CommandHasReturn(vkcommand):
                default_value = self.GetDefaultReturnValue(vkcommand.returnType)
                out.append(f'  return {default_value};\n')

            out.append('}\n')

            if self.CommandHasReturn(vkcommand):
                post_func_decl = post_func_decl.replace(')', f',\n    {vkcommand.returnType}                                    result)')
            func_call = func_call.replace('TrackPre', 'TrackPost', 1)
            tracker_call = tracker_call.replace('Begin', 'End', 1)

            out.append(f'{post_func_decl}\n')
            out.append(f'{func_call}\n')
            if vkcommand.name not in default_instrumented_functions:
                out.append('  if (instrument_all_commands_)\n')
                out.append('  ')
            out.append(f'{tracker_call}\n')
            if self.CommandHasReturn(vkcommand):
                out.append('  return result;\n')
            out.append('}\n')

            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append('\n')
        self.write("".join(out))

    def generateCommandTrackerHeader(self):
        out = []
        out.append('''

#include <vector>
#include <iostream>
#include <vulkan/vulkan.h>

#include "command_common.h"
#include "command_printer.h"
#include "command_recorder.h"

class CommandTracker
{
 public:
  void Reset();
  void SetNameResolver(const ObjectInfoDB *name_resolver);
  void PrintCommandParameters(YAML::Emitter &os, const Command &cmd);

  const std::vector<Command> &GetCommands() const { return commands_; }
  std::vector<Command> &GetCommands() { return commands_; }

''')
        for vkcommand in filter(lambda x: self.CommandBufferCall(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            pre_func_decl = vkcommand.cPrototype.replace('VKAPI_ATTR ', '').replace('VKAPI_CALL ', '').replace(f'{vkcommand.returnType} ', 'void ', 1).replace('vk', 'TrackPre', 1)
            post_func_decl = pre_func_decl.replace('Pre', 'Post', 1)
            out.append(f'  {pre_func_decl}\n')
            out.append(f'  {post_func_decl}\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append('\n')
        out.append(''' private:
  std::vector<Command> commands_;
  CommandPrinter printer_;
  CommandRecorder recorder_;
};
''')
        self.write("".join(out))

    def generateCommandTrackerSource(self):
        out = []
        out.append('''
#include <vulkan/vulkan.h>
#include <cassert>

#include "command_common.h"
#include "command_printer.h"
#include "command_tracker.h"

void CommandTracker::Reset()
{
  commands_.clear();
  recorder_.Reset();
}

void CommandTracker::SetNameResolver(const ObjectInfoDB *name_resolver)
{
  printer_.SetNameResolver(name_resolver);
}

void CommandTracker::PrintCommandParameters(YAML::Emitter &os, const Command &cmd)
{
  switch (cmd.type)
  {
    default:
    case Command::Type::kUnknown:
      os << "";
      break;
''')
        for vkcommand in filter(lambda x: x.name.startswith('vkCmd'), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append(f'    case Command::Type::k{vkcommand.name[2:]}:\n')
            out.append('      if (cmd.parameters) {\n')
            out.append(f'        auto args = reinterpret_cast<{vkcommand.name[2:]}Args *>(cmd.parameters);\n')
            out.append(f'        printer_.Print{vkcommand.name[2:]}Args(os, *args);\n')
            out.append('      }\n')
            out.append('      break;\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append('\n')

        out.append('  }; // switch (cmd.type)\n')
        out.append('} // CommandTracker::PrintCommandParameters\n\n')

        for vkcommand in filter(lambda x: self.CommandBufferCall(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            func_decl = vkcommand.cPrototype.replace('VKAPI_ATTR ', '').replace('VKAPI_CALL ', '').replace(';', ' {').replace(f'{vkcommand.returnType} ', 'void ', 1).replace('vk', 'CommandTracker::TrackPre', 1)
            out.append(f'{func_decl}\n')
            out.append('  Command cmd {};\n')
            out.append(f'  cmd.type = Command::Type::k{vkcommand.name[2:]};\n')
            out.append('  cmd.id = static_cast<uint32_t>(commands_.size()) + 1;\n')
            func_call = f'cmd.parameters = recorder_.Record{vkcommand.name[2:]}('
            count = 0
            for vkparam in vkcommand.params:
                if count != 0:
                    func_call += ', '
                func_call += vkparam.name
                count += 1
            out.append(f'  {func_call});\n')
            out.append('  commands_.push_back(cmd);\n')
            out.append('}\n')


            func_decl = func_decl.replace('TrackPre', 'TrackPost', 1)
            out.append(f'{func_decl}\n')
            out.append(f'  assert(commands_.back().type == Command::Type::k{vkcommand.name[2:]});\n')
            out.append('}\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append('\n')
        self.write("".join(out))
