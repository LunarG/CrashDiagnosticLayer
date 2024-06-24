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

class CommandTrackerGenerator(CdlBaseOutputGenerator):
    def __init__(self):
        CdlBaseOutputGenerator.__init__(self)

    #
    # Called at beginning of processing as file is opened
    def generate(self):
        file_start = self.GenerateFileStart(os.path.basename(__file__))
        self.write(file_start)

        if self.filename == 'command_tracker.h':
            self.generateCommandTrackerHeader()
        elif self.filename == 'command_tracker.cpp':
            self.generateCommandTrackerSource()
        else:
            self.write(f'\nFile name {self.filename} has no code to generate\n')

        self.write(self.GenerateFileEnd())

    def generateCommandTrackerHeader(self):
        out = []
        out.append('''

#include <string>
#include <vector>
#include <iostream>
#include <vulkan/vulkan.h>

#include "command_common.h"
#include "command_recorder.h"

class CommandTracker
{
 public:
  void Reset();

  const std::vector<Command> &GetCommands() const { return commands_; }
  std::vector<Command> &GetCommands() { return commands_; }

''')
        for vkcommand in filter(lambda x: self.CommandBufferCall(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            pre_func_decl = vkcommand.cPrototype.replace('VKAPI_ATTR ', '').replace('VKAPI_CALL ', '').replace(f'{vkcommand.returnType} ', 'void ', 1).replace('vk', '', 1)
            out.append(f'  {pre_func_decl}\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append('\n')
        out.append(''' private:
  std::vector<Command> commands_;
  CommandRecorder recorder_;
  std::vector<std::string> labels_;
};
''')
        self.write("".join(out))

    def generateCommandTrackerSource(self):
        out = []
        out.append('''
#include <vulkan/vulkan.h>
#include <cassert>

#include "command_common.h"
#include "command_tracker.h"

void CommandTracker::Reset()
{
  commands_.clear();
  recorder_.Reset();
}
''')


        for vkcommand in filter(lambda x: self.CommandBufferCall(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            func_decl = vkcommand.cPrototype.replace('VKAPI_ATTR ', '').replace('VKAPI_CALL ', '').replace(';', ' {').replace(f'{vkcommand.returnType} ', 'void ', 1).replace('vk', 'CommandTracker::', 1)
            out.append(f'{func_decl}\n')
            out.append('  Command cmd {};\n')
            out.append(f'  cmd.type = Command::Type::k{vkcommand.name[2:]};\n')
            out.append('  cmd.id = static_cast<uint32_t>(commands_.size()) + 1;\n')
            func_call = f'cmd.parameters = recorder_.Record{vkcommand.name[2:]}('

            if vkcommand.name == 'vkCmdDebugMarkerBeginEXT':
                out.append('  labels_.push_back(pMarkerInfo->pMarkerName);\n')
            elif vkcommand.name == 'vkCmdBeginDebugUtilsLabelEXT':
                out.append('  labels_.push_back(pLabelInfo->pLabelName);\n')
            out.append('  cmd.labels = labels_;\n')
            if vkcommand.name in ('vkCmdEndDebugUtilsLabelEXT', 'vkCmdDebugMarkerEndEXT'):
                out.append('  // do not crash even if the application ends without a marker present\n')
                out.append('  if (!labels_.empty()) {\n')
                out.append('      labels_.pop_back();\n')
                out.append('  }\n')

            count = 0
            for vkparam in vkcommand.params:
                if count != 0:
                    func_call += ', '
                func_call += vkparam.name
                count += 1
            out.append(f'  {func_call});\n')
            out.append('  commands_.push_back(cmd);\n')
            out.append('}\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append('\n')


        self.write("".join(out))
