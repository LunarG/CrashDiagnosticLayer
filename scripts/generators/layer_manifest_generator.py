#!/usr/bin/python3 -i
#
# Copyright (c) 2023 LunarG, Inc.
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
from generators.gfr_base_generator import GfrBaseOutputGenerator
#
# LayerManifestOutputGenerator - Generate layer manifest file
class LayerManifestOutputGenerator(GfrBaseOutputGenerator):
    def __init__(self):
        GfrBaseOutputGenerator.__init__(self)

    #
    # Called at beginning of processing as file is opened
    def generate(self):
        if self.filename == 'graphics_flight_recorder.json.in':
            self.generateJson()
        else:
            self.write(f'\nFile name {self.filename} has no code to generate\n')

    def generateJson(self):
        max_version = 1.0
        for vkversion in self.vk.versions.values():
            current_version = float(vkversion.number)
            if current_version > max_version:
                max_version = current_version

        layer_name = self.GetLayerName()
        layer_version = self.GetLayerVersion()
        layer_description = self.GetLayerDescription()

        self.write(f'''
{{
    "file_format_version": "1.1.0",
    "layer": {{
        "name": "{layer_name}",
        "type": "GLOBAL",
        "library_path": "@JSON_LIBRARY_PATH@",
        "api_version": "{max_version}.{self.vk.headerVersion}",
        "implementation_version": "{layer_version}",
        "description": "{layer_description}",
        "functions": {{
            "vkNegotiateLoaderLayerInterfaceVersion": "GFR_NegotiateLoaderLayerInterfaceVersion",
            "vkGetInstanceProcAddr": "GFR_GetInstanceProcAddr",
            "vkGetDeviceProcAddr": "GFR_GetDeviceProcAddr"
        }},
        "enable_environment": {{
            "VK_GFX_FLIGHT_RECORD_ENABLE": "1"
        }},
        "disable_environment": {{
            "VK_GFX_FLIGHT_RECORD_DISABLE": "1"
        }},
        "instance_extensions": [''')
        
        out = []
        ext_count = 0
        for vkext in self.vk.extensions.values():
            if vkext.name in self.implemented_instance_extensions:
                if ext_count > 0:
                    out.append(',\n')
                out.append('            {\n')
                out.append(f'                "name": "{vkext.name}",\n')
                out.append('                "spec_version": "1"\n')

                # NOTE: Intentionally don't return here so we can add a comma if there are more than one.
                out.append('            }')
                ext_count += 1
        out.append('\n')
        out.append('        ],\n')
        out.append('        "device_extensions": [\n')
        ext_count = 0
        for vkext in self.vk.extensions.values():
            if vkext.name in self.implemented_device_extensions:
                if ext_count > 0:
                    out.append(',\n')
                out.append('            {\n')
                out.append(f'                "name": "{vkext.name}",\n')
                out.append('                "spec_version": "1",\n')
                out.append('                "entrypoints": [\n')
                cmd_count = 0
                for vkcommand in vkext.commands:
                    if cmd_count > 0:
                        out.append(',\n')
                    out.append(f'                    "{vkcommand.name}"')
                    cmd_count += 1
                out.append('\n')
                out.append('                ]\n')

                # NOTE: Intentionally don't return here so we can add a comma if there are more than one.
                out.append('            }')
                ext_count += 1
        out.append('\n')
        out.append('        ]\n')
        out.append('    }\n')
        out.append('}\n')
        self.write("".join(out))
