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

#
# CommandRecorderOutputGenerator - Generate the dispatch tables
class CommandRecorderOutputGenerator(CdlBaseOutputGenerator):
    def __init__(self):
        CdlBaseOutputGenerator.__init__(self)

    #
    # Called at beginning of processing as file is opened
    def generate(self):
        file_start = self.GenerateFileStart(os.path.basename(__file__))
        self.write(file_start)

        if self.filename == 'command_recorder.h':
            self.generateHeader()
        elif self.filename == 'command_recorder.cpp':
            self.generateSource()
        else:
            self.write(f'\nFile name {self.filename} has no code to generate\n')

        self.write(self.GenerateFileEnd())

    def generateHeader(self):
        out = []
        out.append('''
#include <cstring>
#include <iostream>
#include <vector>
#include <vulkan/vulkan.h>

#include "linear_allocator.h"
#include "command_common.h"

class CommandRecorder
{
  public:
  void Reset() { m_allocator.Reset(); }
''')
        for vkcommand in filter(lambda x: self.CommandBufferCall(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            func_decl = vkcommand.cPrototype.replace('VKAPI_ATTR ', '').replace('VKAPI_CALL ', '').replace('vk', 'Record', 1).replace(f'{vkcommand.returnType} ', f'{vkcommand.name[2:]}Args*', 1)
            out.append(f'  {func_decl}\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append('\n')
        out.append('''

  private:

    template <typename T> T *Alloc() { return new(m_allocator.Alloc(sizeof(T))) T; }
    template <typename T> T *CopyArray(const T *src, uint64_t start_index, uint64_t count) {
      auto ptr = reinterpret_cast<T *>(m_allocator.Alloc(sizeof(T) * count));
      std::memcpy(ptr, src, sizeof(T) * count);
      return ptr;
    }

    LinearAllocator<> m_allocator;
};
''')
        self.write("".join(out))

    def generateSource(self):
        out = []
        out.append('''
#include <iomanip>
#include <sstream>

#include "command_common.h"
#include "command_recorder.h"

// Declare CopyArray template functions. We need this declaration since the
// templates call each other and we don't have control over the order of the
// definitions.

''')
        out.append('template<>\n')
        out.append('uint8_t* CommandRecorder::CopyArray<uint8_t>(const uint8_t* src, uint64_t start_index, uint64_t count);\n')
        for vkstruct in self.vk.structs.values():
            out.extend([f'#ifdef {vkstruct.protect}\n'] if vkstruct.protect else [])
            out.append('template<>\n')
            out.append(f'{vkstruct.name}* CommandRecorder::CopyArray<{vkstruct.name}>(const {vkstruct.name}* src, uint64_t start_index, uint64_t count);\n')
            out.extend([f'#endif //{vkstruct.protect}\n'] if vkstruct.protect else [])

        out.append('\n\n// Define CopyArray template functions.\n\n')

        out.append('template<>\n')
        out.append('uint8_t* CommandRecorder::CopyArray<uint8_t>(const uint8_t* src, uint64_t start_index, uint64_t count) {\n')
        out.append('    auto ptr = reinterpret_cast<uint8_t*>(m_allocator.Alloc(sizeof(uint8_t) * count));\n')
        out.append('    memcpy(ptr, src, sizeof(uint8_t) * count);\n')
        out.append('    return ptr;\n')
        out.append('}\n')
        for vkstruct in self.vk.structs.values():
            out.extend([f'#ifdef {vkstruct.protect}\n'] if vkstruct.protect else [])
            out.append('template<>\n')
            out.append(f'{vkstruct.name}* CommandRecorder::CopyArray<{vkstruct.name}>(const {vkstruct.name}* src, uint64_t start_index, uint64_t count) {{\n')
            out.append(f'  auto ptr = reinterpret_cast<{vkstruct.name}*>(m_allocator.Alloc(sizeof({vkstruct.name}) * count));\n')
            out.append('  for (uint64_t i = 0; i < count; ++i) {\n')
            for vkmember in vkstruct.members:
                pointer_count = vkmember.cDeclaration.count('*')
                is_array = (vkmember.length is not None and len(vkmember.length) > 0) or (vkmember.fixedSizeArray is not None and len(vkmember.fixedSizeArray) > 0)
                if 'char' in vkmember.type and pointer_count == 1:
                    out.append(f'      ptr[i].{vkmember.name} = nullptr;\n')
                    out.append(f'      if (src[start_index + i].{vkmember.name}) {{\n')
                    out.append(f'        ptr[i].{vkmember.name} = CopyArray<>(src[start_index + i].{vkmember.name}, 0, strlen(src[start_index + i].{vkmember.name}) + 1);\n')
                    out.append('      }\n')
                elif is_array and not (vkmember.type == 'void' or 'PFN_' in vkmember.type):
                    if (vkmember.fixedSizeArray is not None and len(vkmember.fixedSizeArray) > 0):
                        out.append(f'      std::memcpy(ptr[i].{vkmember.name}, src[start_index + i].{vkmember.name}, sizeof(src[start_index + i].{vkmember.name}));\n')
                    else:
                        out.append(f'      ptr[i].{vkmember.name} = nullptr;\n')
                        out.append(f'      if (src[start_index + i].{vkmember.name}) {{\n')
                        out.append(f'        ptr[i].{vkmember.name} = CopyArray<>(src[start_index + i].{vkmember.name}, 0, 1);\n')
                        out.append('      }\n')
                else:
                    out.append(f'      ptr[i].{vkmember.name} = src[start_index + i].{vkmember.name};\n')
            out.append('  }\n')
            out.append('  return ptr;\n')
            out.append('}\n')
            out.extend([f'#endif //{vkstruct.protect}\n'] if vkstruct.protect else [])
            out.append('\n')

        for vkcommand in filter(lambda x: self.CommandBufferCall(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            func_decl = vkcommand.cPrototype.replace('VKAPI_ATTR ', '').replace('VKAPI_CALL ', '').replace('vk', 'CommandRecorder::Record').replace(f'{vkcommand.returnType} ', f'{vkcommand.name[2:]}Args*', 1).replace(';', ' {', 1)
            out.append(f'{func_decl}\n')
            out.append(f'  auto *args = Alloc<{vkcommand.name[2:]}Args>();\n')
            for vkparam in vkcommand.params:
                if vkparam.fixedSizeArray is not None and len(vkparam.fixedSizeArray) > 0:
                    out.append(f'  for (uint32_t i = 0; i < {vkparam.length}; ++i) {{\n')
                    out.append(f'    args->{vkparam.name}[i] = {vkparam.name}[i];\n')
                    out.append('  }\n')
                elif vkparam.pointer and 'void' != vkparam.type:
                    out.append(f'  if ({vkparam.name}) {{\n')
                    if vkparam.length is not None and len(vkparam.length) > 0:
                        out.append(f'    args->{vkparam.name} = CopyArray({vkparam.name}, static_cast<uint64_t>(0U), static_cast<uint64_t>({vkparam.length}));\n')
                    else:
                        out.append(f'    args->{vkparam.name} = CopyArray({vkparam.name}, static_cast<uint64_t>(0U), static_cast<uint64_t>(1U));\n')
                    out.append('  }\n')
                elif vkparam.length is not None and len(vkparam.length) > 0:
                    out.append(f'    args->{vkparam.name} = CopyArray(reinterpret_cast<const uint8_t*>({vkparam.name}), static_cast<uint64_t>(0U), static_cast<uint64_t>({vkparam.length}));\n')
                else:
                    out.append(f'  args->{vkparam.name} = {vkparam.name};\n')
            out.append('  return args;\n')
            out.append('}\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append('\n')
        self.write("".join(out))
