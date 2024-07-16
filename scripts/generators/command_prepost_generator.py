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
from generators.cdl_base_generator import CdlBaseOutputGenerator

custom_functions = (
    'vkCmdBeginRendering',
    'vkCmdEndRendering',
)

default_instrumented_functions = (
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
    'vkCmdTraceRaysKHR',
    'vkCmdTraceRaysIndirectKHR',
    'vkCmdTraceRaysNV',
    'vkCmdBuildAccelerationStructuresKHR',
    'vkCmdBuildAccelerationStructuresIndirectKHR'
    'vkCmdBuildAccelerationStructuresNV',
)

#
# InterceptCommandsOutputGenerator - Generate the dispatch tables
class CommandPrePostGenerator(CdlBaseOutputGenerator):
    def __init__(self):
        CdlBaseOutputGenerator.__init__(self)

    #
    # Called at beginning of processing as file is opened
    def generate(self):
        file_start = self.GenerateFileStart(os.path.basename(__file__))
        self.write(file_start)

        if self.filename == 'command.h.inc':
            self.generateCommandsHeader()
        elif self.filename == 'command.cpp.inc':
            self.generateCommandsSource()
        else:
            self.write(f'\nFile name {self.filename} has no code to generate\n')

        self.write(self.GenerateFileEnd())

    def generateCommandsHeader(self):
        out = []
        for vkcommand in filter(lambda x: x.name.startswith('vkCmd') and x.name not in custom_functions, self.vk.commands.values()):
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
        for vkcommand in filter(lambda x: x.name.startswith('vkCmd') and x.name not in custom_functions, self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            post_func_decl = vkcommand.cPrototype.replace('VKAPI_ATTR ', '').replace('VKAPI_CALL ', '').replace(';', ' {').replace(' vk', ' CommandBuffer::Post', 1)
            pre_func_decl = post_func_decl.replace('Post', 'Pre', 1)
            func_call = f'  tracker_.{vkcommand.name[2:]}('
            count = 0
            for vkparam in vkcommand.params:
                if count != 0:
                    func_call += ', '
                func_call += vkparam.name
                count += 1
            func_call += ');'

            tracker_call = '  WriteCommandBeginCheckpoint(tracker_.GetCommands().back().id);'

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
            tracker_call = '  WriteCommandEndCheckpoint(tracker_.GetCommands().back().id);'

            out.append(f'{post_func_decl}\n')
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

