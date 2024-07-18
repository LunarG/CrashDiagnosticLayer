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
# CommandPrinterOutputGenerator - Generate command print utilities
class CommandPrinterOutputGenerator(CdlBaseOutputGenerator):
    def __init__(self):
        CdlBaseOutputGenerator.__init__(self)

    #
    # Called at beginning of processing as file is opened
    def generate(self):
        file_start = self.GenerateFileStart(os.path.basename(__file__))
        self.write(file_start)

        if self.filename == 'command_printer.h':
            self.generateHeader()
        elif self.filename == 'command_printer_types.cpp':
            self.generateTypesSource()
        elif self.filename == 'command_printer_structs.cpp':
            self.generateStructsSource()
        elif self.filename == 'command_printer.cpp':
            self.generateSource()
        else:
            self.write(f'\nFile name {self.filename} has no code to generate\n')

        self.write(self.GenerateFileEnd())

    def generateHeader(self):
        self.write('\n#pragma once')

        out = []
        out.append('''
#include <yaml-cpp/emitter.h>
#include <vulkan/vulkan.h>

#include "command_common.h"
#include "object_name_db.h"

struct VkStruct {
    VkStructureType sType;
    void *pNext;
};

// Declare generic struct printer.
YAML::Emitter &PrintVkStruct(YAML::Emitter &os, const VkStruct *pStruct);

// Declare pNext chain printer.
YAML::Emitter &PrintNextPtr(YAML::Emitter &os, const void *pNext);
''')
        self.write("".join(out))

        self.write("// Declare Handle stream operators\n")
        out = []
        for vkhandle in self.vk.handles.values():
            out.extend([f'#ifdef {vkhandle.protect}\n'] if vkhandle.protect else [])
            if not vkhandle.dispatchable:
                out.append('#if VK_USE_64_BIT_PTR_DEFINES\n')
            out.append(f'YAML::Emitter &operator<<(YAML::Emitter& os, const {vkhandle.name} &a);')
            if not vkhandle.dispatchable:
                out.append('#endif //VK_USE_64_BIT_PTR_DEFINES\n')
            out.extend([f'#endif //{vkhandle.protect}\n'] if vkhandle.protect else [])
            out.append('\n')
        self.write("".join(out))
        self.write("\n// Declare stream operators for enums.\n")
        out = []
        for vkenum in [x for x in self.vk.enums.values() if len(x.fields) > 0]:
            out.extend([f'#ifdef {vkenum.protect}\n'] if vkenum.protect else [])
            out.append(f'YAML::Emitter &operator<<(YAML::Emitter &os, const {vkenum.name} &t);\n')
            out.extend([f'#endif //{vkenum.protect}\n'] if vkenum.protect else [])
        self.write("".join(out))

        self.write("\n// Declare all stream operators.\n")
        out = []
        for vkstruct in self.vk.structs.values():
            out.extend([f'#ifdef {vkstruct.protect}\n'] if vkstruct.protect else [])
            out.append(f'YAML::Emitter &operator<<(YAML::Emitter &os, const {vkstruct.name} &t);\n')
            out.extend([f'#endif //{vkstruct.protect}\n'] if vkstruct.protect else [])
        self.write("".join(out))

        out = []
        out.append('''
// Declare print functions.
class ObjectInfoDB;
class CommandPrinter {
 public:
  void SetNameResolver(const ObjectInfoDB *name_resolver);
  void PrintCommandParameters(YAML::Emitter &os, const Command &cmd);
''')
        for vkcommand in filter(lambda x: self.CommandBufferCall(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append(f'  void Print{vkcommand.name[2:]}Args(YAML::Emitter &os, const {vkcommand.name[2:]}Args &args);\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
        out.append('};\n');
        self.write("".join(out))

    def printArray(self, out, lengths, cur_length, prefix, member, outer = ''):
        variable = chr(ord('i') + cur_length)
        out.append('os << YAML::BeginSeq;\n')
        out.append(f'for (uint64_t {variable} = 0; {variable} < uint64_t({lengths[cur_length]}); ++{variable}) {{\n')
        if cur_length < (len(lengths) - 1):
            self.printArray(out, lengths, cur_length + 1, prefix, member, outer + '[' + variable + ']')
        else:
            pointer_prefix = prefix
            pointer_suffix = ''
            pointer_count = member.cDeclaration.count('*')
            if pointer_count > len(lengths):
                pointer_prefix = '*(' + prefix
                pointer_suffix = ')'
            out.append(f'os << {pointer_prefix}{member.name}{pointer_suffix}{outer}[{variable}];')
        out.append(f'}} // for {variable}\n')
        out.append('os << YAML::EndSeq;\n')

    def printMember(self, out, member, prefix, is_pointer):
        no_deref_structs = ('xcb_connection_t', 'Display', 'wl_display', 'wl_surface', 'ANativeWindow',
                'SECURITY_ATTRIBUTES', 'CAMetalLayer',
                'StdVideoEncodeH264SliceHeader', 'StdVideoEncodeH264PictureInfo', 'StdVideoEncodeH264ReferenceInfo',
                'StdVideoEncodeH265SliceSegmentHeader', 'StdVideoEncodeH265PictureInfo',
                'StdVideoEncodeH265ReferenceInfo', 'StdVideoDecodeH264PictureInfo', 'StdVideoDecodeH264ReferenceInfo',
                'StdVideoDecodeH265PictureInfo', 'StdVideoDecodeH265ReferenceInfo', 'StdVideoAV1SequenceHeader',
                'StdVideoDecodeAV1PictureInfo', 'StdVideoDecodeAV1ReferenceInfo',
                'StdVideoH264PictureParameterSet', 'StdVideoH264SequenceParameterSet', 'StdVideoH265PictureParameterSet',
                'StdVideoH265SequenceParameterSet', 'StdVideoH265VideoParameterSet')
        out.append(f'    os << YAML::Key <<  "{member.name}";\n')
        if is_pointer:
            prefix += '->'
        else:
            prefix += '.'
        if member.length is not None:

            lengths = []
            lengths_names = []
            if len(member.fixedSizeArray) > 1 or member.length.count(',') > 0:
                lengths = member.length.split(',')
                if len(lengths) > 1 and lengths[len(lengths) - 1] == '1':
                    lengths.pop()
            else:
                lengths.append(member.length)
            # for truly static arrays these are equal
            static_array = (lengths == member.fixedSizeArray)

            array_type = ''
            if member.const:
                array_type = 'Const'
            for i in range(len(lengths)):
                length_name = ''
                if '*' in lengths[i] or '+' in lengths[i] or '/' in lengths[i]:
                    elements = lengths[i].split(' ')
                    for j in range(len(elements)):
                        for k in range(len(elements[j])):
                            if elements[j][k] == '(':
                                continue
                            if elements[j][k].islower():
                                if k == 0:
                                    temp = prefix + elements[j]
                                else:
                                    temp = elements[j][:k] + prefix + elements[j][k:]
                                elements[j] = temp
                                break
                    lengths[i] = ''.join(elements)
                    length_name = '('
                    length_name += lengths[i] + ')'
                elif i == 0 and not static_array:
                    length_name = prefix + lengths[i]
                else:
                    length_name = lengths[i]
                if static_array:
                    array_type += 'Fixed'
                else:
                    array_type += 'Dynamic'
                array_type += 'Array('
                if i == len(lengths) - 1:
                    array_type += member.type
                lengths_names.append(length_name)
            for i in range(len(lengths)):
                array_type += ')'

            if member.type == 'char' and len(lengths) == 1:
                out.append(f'    // {member.name} -> Field -> {array_type}\n')
                out.append(f'    os << YAML::Value << {prefix}{member.name};\n')
            elif member.type == 'void':
                if static_array:
                    out.append('    {\n')
                else:
                    out.append(f'    if ({lengths_names[0]} == 0) {{\n')
                    out.append('      os << YAML::Value << "nullptr";\n')
                    out.append('    } else {\n')
                out.append('      os << YAML::Value << YAML::BeginSeq;\n')
                out.append('      {\n')
                out.append(f'        const uint8_t *p = (const uint8_t *){prefix}{member.name};\n')
                out.append(f'        for (uint64_t i = 0; i < {lengths_names[0]}; ++i) {{\n')
                out.append('          os << crash_diagnostic_layer::Uint8ToStr(p[i]);\n')
                out.append('        }\n')
                out.append('      }\n')
                out.append('      os << YAML::EndSeq;\n')
                out.append('    }\n')
            else:
                out.append(f'    // {member.name} -> Field -> {array_type}\n')
                if static_array:
                    out.append('    {\n')
                else:
                    out.append(f'    if ({lengths_names[0]} == 0) {{\n')
                    out.append('      os << YAML::Value << "nullptr";\n')
                    out.append('    } else {\n')
                out.append('      os << YAML::Value;\n')
                out.append('      {\n')
                out.append(f'       os << YAML::Comment("{member.type}");\n')
                if member.type not in no_deref_structs:
                    if member.type in self.vk.structs:
                        if member.type not in no_deref_structs:
                            self.printArray(out, lengths_names, 0, prefix, member)
                        else:
                            out.append(f'       os << YAML::BeginSeq << "{member.type} not decoded" << YAML::EndSeq;\n')
                    else:
                        self.printArray(out, lengths_names, 0, prefix, member)
                out.append('      }\n')
                out.append('    }\n')
        elif member.pointer:
            if member.name == 'pNext':
                out.append('    // pNext -> Field -> ConstNextPtr(void)\n')
                out.append('    os << YAML::Value << YAML::BeginSeq;\n')
                out.append(f'    PrintNextPtr(os, {prefix}pNext);\n')
                out.append('    os << YAML::EndSeq;\n')
            elif member.type == 'void':
                out.append('    // void\n')
                out.append('    os << YAML::Value << "NOT_AVAILABLE";\n')
            elif member.type == 'char':
                out.append(f'    // {member.name} -> Field -> string\n')
                out.append(f'    os << YAML::Value << {prefix}{member.name};\n')
            elif member.type in no_deref_structs:
                out.append('    // non-dereferenced pointer\n')
                out.append(f'   os << YAML::Value << {prefix}{member.name};\n')
            else:
                out.append('    // pointer\n')
                out.append(f'    if ({prefix}{member.name} != nullptr) {{\n')
                if member.type in self.vk.structs:
                    out.append(f'      os << YAML::Value << *{prefix}{member.name};\n')
                else:
                    out.append(f'      os << YAML::Value << *{prefix}{member.name};\n')
                out.append('    } else {\n')
                out.append('      os << YAML::Value << "nullptr";\n')
                out.append('    }\n')
        else:
            out.append(f'    // {member.name} -> Field -> {member.type}\n')
            if member.type == 'VkDeviceAddress':
                out.append(f'    os << YAML::Value << crash_diagnostic_layer::Uint64ToStr({prefix}{member.name});\n')
            else:
                out.append(f'    os << YAML::Value << {prefix}{member.name};\n')

    def generateTypesSource(self):
        out = []
        out.append('''
#include <streambuf>
#include <vulkan/vk_enum_string_helper.h>

#include "command_common.h"
#include "command_printer.h"
#include "util.h"

const ObjectInfoDB *global_name_resolver = nullptr;
void CommandPrinter::SetNameResolver(const ObjectInfoDB *name_resolver) {
  global_name_resolver = name_resolver;
}
''')
        self.write("".join(out))

        self.write("// Handle stream operators\n")
        out = []
        for vkhandle in self.vk.handles.values():
            out.extend([f'#ifdef {vkhandle.protect}\n'] if vkhandle.protect else [])
            if not vkhandle.dispatchable:
                out.append('#if VK_USE_64_BIT_PTR_DEFINES\n')
            out.append(f'''
YAML::Emitter &operator<<(YAML::Emitter& os, const {vkhandle.name} &a) {{
    os << global_name_resolver->GetObjectInfo(reinterpret_cast<uint64_t>(a));
    return os;
}}
''')
            if not vkhandle.dispatchable:
                out.append('#endif //VK_USE_64_BIT_PTR_DEFINES\n')
            out.extend([f'#endif //{vkhandle.protect}\n'] if vkhandle.protect else [])
            out.append('\n')
        self.write("".join(out))

        self.write("\n// Define stream operators for enums.\n")
        out = []
        for vkenum in [x for x in self.vk.enums.values() if len(x.fields) > 0]:
            out.extend([f'#ifdef {vkenum.protect}\n'] if vkenum.protect else [])
            out.append(f'YAML::Emitter &operator<<(YAML::Emitter & os, const {vkenum.name} &t) {{\n')
            out.append(f'  os << string_{vkenum.name}(t);\n')
            out.append('  return os;\n')
            out.append('}\n')
            out.extend([f'#endif //{vkenum.protect}\n'] if vkenum.protect else [])
            out.append('\n')
        self.write("".join(out))


    def generateStructsSource(self):
        manual_structs = ('VkWriteDescriptorSet', 'VkAccelerationStructureBuildGeometryInfoKHR')
        out = []
        out.append('''
#include <streambuf>
#include <vulkan/vk_enum_string_helper.h>

#include "command_common.h"
#include "command_printer.h"
#include "util.h"

YAML::Emitter &PrintNextPtr(YAML::Emitter &os, const void *pNext) {
  if (pNext == nullptr) {
    os << "nullptr";
    return os;
  }

  const VkStruct *pStruct = reinterpret_cast<const VkStruct *>(pNext);
  PrintVkStruct(os, pStruct);
  return PrintNextPtr(os, pStruct->pNext);
}
''')
        self.write("".join(out))
        self.write("\n// Define all stream operators.\n")
        out = []
        for vkstruct in self.vk.structs.values():
            if vkstruct.name in manual_structs:
                continue
            out.extend([f'#ifdef {vkstruct.protect}\n'] if vkstruct.protect else [])
            out.append(f'YAML::Emitter &operator<<(YAML::Emitter & os, const {vkstruct.name} &t) {{\n')
            out.append('  os << YAML::BeginMap;\n')
            for member in vkstruct.members:
                self.printMember(out, member, 't', False)
            out.append('  os << YAML::EndMap;\n')
            out.append('  return os;\n')
            out.append('}\n')
            out.extend([f'#endif //{vkstruct.protect}\n'] if vkstruct.protect else [])
            out.append('\n')
        self.write("".join(out))

        out = []
        out.append('''
YAML::Emitter &operator<<(YAML::Emitter &os, const VkWriteDescriptorSet &t) {
  os << YAML::BeginMap;
  os << YAML::Key << "sType" << YAML::Value << t.sType;

  os << YAML::Key << "pNext" << YAML::Value << t.pNext;

  os << YAML::Key << "dstSet" << YAML::Value << t.dstSet;

  os << YAML::Key << "dstBinding" << YAML::Value << t.dstBinding;

  os << YAML::Key << "dstArrayElement" << YAML::Value << t.dstArrayElement;

  os << YAML::Key << "descriptorCount" << YAML::Value << t.descriptorCount;

  os << YAML::Key << "descriptorType" << YAML::Value << t.descriptorType;

  switch (t.descriptorType){
    case VK_DESCRIPTOR_TYPE_SAMPLER:
    case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
    case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
    case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
      os << YAML::Key << "pImageInfo" << YAML::Value << YAML::BeginSeq;
      for (uint32_t i = 0; i < t.descriptorCount; ++i) {
        os << t.pImageInfo[i];
      }
      os << YAML::EndSeq;
      break;

    case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
    case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
      os << YAML::Key << "pTexelBufferView" << YAML::Value << YAML::BeginSeq;
      for (uint32_t i = 0; i < t.descriptorCount; ++i) {
        os << t.pTexelBufferView[i];
      }
      os << YAML::EndSeq;
      break;

    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
    case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
      os << YAML::Key << "pBufferInfo" << YAML::Value << YAML::BeginSeq;
      for (uint32_t i = 0; i < t.descriptorCount; ++i) {
        os << t.pBufferInfo[i];
      }
      os << YAML::EndSeq;
      break;

    default:
      os << YAML::Key << "Unknown Descriptor Type" << YAML::Value << t.descriptorType;
  }
  os << YAML::EndMap;
  return os;
}

YAML::Emitter &operator<<(YAML::Emitter &os, const VkAccelerationStructureBuildGeometryInfoKHR &t) {
    os << YAML::BeginMap;
    os << YAML::Key << "sType";
    // sType -> Field -> VkStructureType
    os << YAML::Value << t.sType;
    os << YAML::Key << "pNext";
    // pNext -> Field -> ConstNextPtr(void)
    os << YAML::Value << YAML::BeginSeq;
    PrintNextPtr(os, t.pNext);
    os << YAML::EndSeq;
    os << YAML::Key << "type";
    // type -> Field -> VkAccelerationStructureTypeKHR
    os << YAML::Value << t.type;
    os << YAML::Key << "flags";
    // flags -> Field -> VkBuildAccelerationStructureFlagsKHR
    os << YAML::Value << t.flags;
    os << YAML::Key << "mode";
    // mode -> Field -> VkBuildAccelerationStructureModeKHR
    os << YAML::Value << t.mode;
    os << YAML::Key << "srcAccelerationStructure";
    // srcAccelerationStructure -> Field -> VkAccelerationStructureKHR
    os << YAML::Value << t.srcAccelerationStructure;
    os << YAML::Key << "dstAccelerationStructure";
    // dstAccelerationStructure -> Field -> VkAccelerationStructureKHR
    os << YAML::Value << t.dstAccelerationStructure;
    os << YAML::Key << "geometryCount";
    // geometryCount -> Field -> uint32_t
    os << YAML::Value << t.geometryCount;
    // This part needs to be manual because we don't have an easy way to automatically handle
    // the "geometryCount refers to either pGeometries or ppGeometries" logic.
    if (t.pGeometries) {
        os << YAML::Key << "pGeometries";
        // pGeometries -> Field -> ConstDynamicArray(VkAccelerationStructureGeometryKHR)
        if (t.geometryCount == 0) {
            os << YAML::Value << "nullptr";
        } else {
            os << YAML::Value;
            {
                os << YAML::Comment("VkAccelerationStructureGeometryKHR");
                os << YAML::BeginSeq;
                for (uint64_t i = 0; i < uint64_t(t.geometryCount); ++i) {
                    os << t.pGeometries[i];
                }  // for i
                os << YAML::EndSeq;
            }
        }
    } else if (t.ppGeometries) {
        os << YAML::Key << "ppGeometries";
        // ppGeometries -> Field -> ConstDynamicArray(VkAccelerationStructureGeometryKHR)
        if (t.geometryCount == 0) {
            os << YAML::Value << "nullptr";
        } else {
            os << YAML::Value;
            {
                os << YAML::Comment("VkAccelerationStructureGeometryKHR");
                os << YAML::BeginSeq;
                for (uint64_t i = 0; i < uint64_t(t.geometryCount); ++i) {
                    os << *(t.ppGeometries)[i];
                }  // for i
                os << YAML::EndSeq;
            }
        }
    }
    os << YAML::Key << "scratchData";
    // scratchData -> Field -> VkDeviceOrHostAddressKHR
    os << YAML::Value << t.scratchData;
    os << YAML::EndMap;
    return os;
}
''')
        self.write("".join(out))

        out = []
        out.append('//  Print out a VkStruct\n')
        out.append('YAML::Emitter & PrintVkStruct(YAML::Emitter & os, const VkStruct *pStruct) {\n')
        out.append('  switch (pStruct->sType) {\n')
        for vkstruct in self.vk.structs.values():
            if vkstruct.sType is None:
                continue
            out.extend([f'#ifdef {vkstruct.protect}\n'] if vkstruct.protect else [])
            out.append(f'  case {vkstruct.sType}:\n')
            out.append(f'    os << *reinterpret_cast<const {vkstruct.name} *>(pStruct);\n')
            out.append('    break;\n')
            out.extend([f'#endif //{vkstruct.protect}\n'] if vkstruct.protect else [])

        out.append('  default: break;\n')
        out.append('  }\n')
        out.append('  return os;\n')
        out.append('}\n')
        self.write("".join(out))

    def generateSource(self):
        out = []
        out.append('''
#include <streambuf>
#include <vulkan/vk_enum_string_helper.h>

#include "command_common.h"
#include "command_printer.h"
#include "util.h"

''')
        self.write("".join(out))
        self.write("\n// Define print functions.\n")
        out = []
        for vkcommand in filter(lambda x: self.CommandBufferCall(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append(f'void CommandPrinter::Print{vkcommand.name[2:]}Args(\n')
            out.append(f'  YAML::Emitter & os, const {vkcommand.name[2:]}Args &args) {{\n')
            for member in vkcommand.params:
                if member.name != 'commandBuffer':
                    self.printMember(out, member, 'args', False)
            out.append('}\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append('\n')
        out.append('''
void CommandPrinter::PrintCommandParameters(YAML::Emitter &os, const Command &cmd)
{
  switch (cmd.type)
  {
    default:
    case Command::Type::kUnknown:
      // output an empty map for consistency with other command printers
      os << YAML::BeginMap << YAML::EndMap;
      break;
''')
        for vkcommand in filter(lambda x: self.CommandBufferCall(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append(f'    case Command::Type::k{vkcommand.name[2:]}:\n')
            out.append('      if (cmd.parameters) {\n')
            out.append(f'        auto args = reinterpret_cast<{vkcommand.name[2:]}Args *>(cmd.parameters);\n')
            out.append(f'        Print{vkcommand.name[2:]}Args(os, *args);\n')
            out.append('      }\n')
            out.append('      break;\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append('\n')
        out.append('    } // switch (cmd.type)\n\n')
        out.append('} // CommandPrinter::PrintCommandParameters\n\n')
        self.write("".join(out))
