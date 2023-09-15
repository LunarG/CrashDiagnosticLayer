#!/usr/bin/python3
#
# Copyright (c) 2013-2023 The Khronos Group Inc.
# Copyright (c) 2023-2023 RasterGrid Kft.
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

import argparse
import sys
import time
import os
from xml.etree import ElementTree

# Simple timer functions
startTime = None

def startTimer(timeit):
    global startTime
    if timeit:
        startTime = time.process_time()

def endTimer(timeit, msg):
    global startTime
    if timeit:
        endTime = time.process_time()
        print(msg, endTime - startTime, file=sys.stderr)
        startTime = None

def RunGenerator(api: str, registry: str, grammar: str, scripts: str, directory: str, target: str, time: bool = False):

    # These live in the Vulkan-Docs repo, but are pulled in via the
    # Vulkan-Headers/registry folder
    # At runtime we inject python path to find these helper scripts
    scripts_directory_path = os.path.dirname(os.path.abspath(__file__))
    registry_headers_path = os.path.join(scripts_directory_path, scripts)
    sys.path.insert(0, registry_headers_path)
    from reg import Registry

    from generators.base_generator import BaseGeneratorOptions
    from generators.command_common_generator import CommandCommonOutputGenerator
    from generators.command_printer_generator import CommandPrinterOutputGenerator
    from generators.command_recorder_generator import CommandRecorderOutputGenerator
    from generators.dispatch_generator import DispatchOutputGenerator
    from generators.intercepts_and_prepost_generator import InterceptCommandsOutputGenerator
    from generators.layer_base_generator import LayerBaseOutputGenerator
    from generators.layer_manifest_generator import LayerManifestOutputGenerator

    # Allow downstream users to merge other (e.g. the main "vulkan") API into
    # the API for which code is generated
    mergeApiNames = None

    # Output target directory
    from generators.base_generator import SetOutputDirectory
    from generators.base_generator import SetTargetApiName
    SetOutputDirectory(directory)
    SetTargetApiName(api)

    genOpts = {}

    # GFR Generators

    genOpts['command.h.inc'] = [
          InterceptCommandsOutputGenerator,
          BaseGeneratorOptions(
            filename          = 'command.h.inc',
            mergeApiNames     = mergeApiNames,
            valid_usage_path  = scripts)
        ]
    genOpts['command.cc.inc'] = [
          InterceptCommandsOutputGenerator,
          BaseGeneratorOptions(
            filename          = 'command.cc.inc',
            mergeApiNames     = mergeApiNames,
            valid_usage_path  = scripts)
        ]

    genOpts['command_common.h'] = [
          CommandCommonOutputGenerator,
          BaseGeneratorOptions(
            filename          = 'command_common.h',
            mergeApiNames     = mergeApiNames,
            valid_usage_path  = scripts)
        ]
    genOpts['command_common.cc'] = [
          CommandCommonOutputGenerator,
          BaseGeneratorOptions(
            filename          = 'command_common.cc',
            mergeApiNames     = mergeApiNames,
            valid_usage_path  = scripts)
        ]

    genOpts['command_printer.h'] = [
          CommandPrinterOutputGenerator,
          BaseGeneratorOptions(
            filename          = 'command_printer.h',
            mergeApiNames     = mergeApiNames,
            valid_usage_path  = scripts)
        ]
    genOpts['command_printer.cc'] = [
          CommandPrinterOutputGenerator,
          BaseGeneratorOptions(
            filename          = 'command_printer.cc',
            mergeApiNames     = mergeApiNames,
            valid_usage_path  = scripts)
        ]

    genOpts['command_recorder.h'] = [
          CommandRecorderOutputGenerator,
          BaseGeneratorOptions(
            filename          = 'command_recorder.h',
            mergeApiNames     = mergeApiNames,
            valid_usage_path  = scripts)
        ]
    genOpts['command_recorder.cc'] = [
          CommandRecorderOutputGenerator,
          BaseGeneratorOptions(
            filename          = 'command_recorder.cc',
            mergeApiNames     = mergeApiNames,
            valid_usage_path  = scripts)
        ]

    genOpts['command_tracker.h'] = [
          InterceptCommandsOutputGenerator,
          BaseGeneratorOptions(
            filename          = 'command_tracker.h',
            mergeApiNames     = mergeApiNames,
            valid_usage_path  = scripts)
        ]
    genOpts['command_tracker.cc'] = [
          InterceptCommandsOutputGenerator,
          BaseGeneratorOptions(
            filename          = 'command_tracker.cc',
            mergeApiNames     = mergeApiNames,
            valid_usage_path  = scripts)
        ]

    genOpts['dispatch.h'] = [
          DispatchOutputGenerator,
          BaseGeneratorOptions(
            filename          = 'dispatch.h',
            mergeApiNames     = mergeApiNames,
            valid_usage_path  = scripts)
        ]
    genOpts['dispatch.cc'] = [
          DispatchOutputGenerator,
          BaseGeneratorOptions(
            filename          = 'dispatch.cc',
            mergeApiNames     = mergeApiNames,
            valid_usage_path  = scripts)
        ]

    genOpts['gfr_commands.h.inc'] = [
          InterceptCommandsOutputGenerator,
          BaseGeneratorOptions(
            filename          = 'gfr_commands.h.inc',
            mergeApiNames     = mergeApiNames,
            valid_usage_path  = scripts)
        ]
    genOpts['gfr_commands.cc.inc'] = [
          InterceptCommandsOutputGenerator,
          BaseGeneratorOptions(
            filename          = 'gfr_commands.cc.inc',
            mergeApiNames     = mergeApiNames,
            valid_usage_path  = scripts)
        ]
    genOpts['gfr_intercepts.cc.inc'] = [
          InterceptCommandsOutputGenerator,
          BaseGeneratorOptions(
            filename          = 'gfr_intercepts.cc.inc',
            mergeApiNames     = mergeApiNames,
            valid_usage_path  = scripts)
        ]

    genOpts['layer_base.h'] = [
          LayerBaseOutputGenerator,
          BaseGeneratorOptions(
            filename          = 'layer_base.h',
            mergeApiNames     = mergeApiNames,
            valid_usage_path  = scripts)
        ]
    genOpts['layer_base.cc'] = [
          LayerBaseOutputGenerator,
          BaseGeneratorOptions(
            filename          = 'layer_base.cc',
            mergeApiNames     = mergeApiNames,
            valid_usage_path  = scripts)
        ]

    genOpts['graphics_flight_recorder.json.in'] = [
          LayerManifestOutputGenerator,
          BaseGeneratorOptions(
            filename          = 'graphics_flight_recorder.json.in',
            mergeApiNames     = mergeApiNames,
            valid_usage_path  = scripts)
        ]

    if (target not in genOpts.keys()):
        print(f'ERROR: No generator options for unknown target: {target}', file=sys.stderr)
        return

    createGenerator = genOpts[target][0]
    gen = createGenerator()

    options = genOpts[target][1]

    # Create the registry object with the specified generator and generator
    # options. The options are set before XML loading as they may affect it.
    reg = Registry(gen, options)

    # Parse the specified registry XML into an ElementTree object
    startTimer(time)
    tree = ElementTree.parse(registry)
    endTimer(time, '* Time to make ElementTree =')

    # Filter out non-Vulkan extensions
    if api == 'vulkan':
        [exts.remove(e) for exts in tree.findall('extensions') for e in exts.findall('extension') if (sup := e.get('supported')) is not None and options.apiname not in sup.split(',')]

    # Load the XML tree into the registry object
    startTimer(time)
    reg.loadElementTree(tree)
    endTimer(time, '* Time to parse ElementTree =')

    # Finally, use the output generator to create the requested target
    startTimer(time)
    reg.apiGen()
    endTimer(time, '* Time to generate ' + options.filename + ' =')

# -extension name
# For both, "name" may be a single name, or a space-separated list
# of names, or a regular expression.
if __name__ == '__main__':
    parser = argparse.ArgumentParser()

    parser.add_argument('-api', action='store',
                        default='vulkan',
                        choices=['vulkan'],
                        help='Specify API name to generate')
    parser.add_argument('-registry', action='store',
                        default='vk.xml',
                        help='Use specified registry file instead of vk.xml')
    parser.add_argument('-grammar', action='store',
                        default='spirv.core.grammar.json',
                        help='Use specified grammar file instead of spirv.core.grammar.json')
    parser.add_argument('-time', action='store_true',
                        help='Enable timing')
    parser.add_argument('-o', action='store', dest='directory',
                        default='.',
                        help='Create target and related files in specified directory')
    parser.add_argument('target', metavar='target', nargs='?',
                        help='Specify target')

    # This argument tells us where to load the script from the Vulkan-Headers registry
    parser.add_argument('-scripts', action='store',
                        help='Find additional scripts in this directory')

    args = parser.parse_args()

    # default scripts path to be same as registry
    if not args.scripts:
        args.scripts = os.path.dirname(args.registry)

    RunGenerator(args.api, args.registry, args.grammar, args.scripts, args.directory, args.target, args.time)
