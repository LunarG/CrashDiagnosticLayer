#!/usr/bin/env python3
# Copyright (c) 2021-2025 The Khronos Group Inc.
# Copyright (c) 2021-2025 Valve Corporation
# Copyright (c) 2021-2025 LunarG, Inc.
# Copyright (c) 2021-2024 Google Inc.
# Copyright (c) 2023-2024 RasterGrid Kft.
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
import filecmp
import os
import shutil
import subprocess
import sys
import tempfile
import difflib
import json
import common_ci
import pickle
from xml.etree import ElementTree

def RunGenerators(api: str, registry: str, grammar: str, directory: str, styleFile: str, targetFilter: str, caching: bool):

    has_clang_format = shutil.which('clang-format') is not None
    if not has_clang_format:
        print("WARNING: Unable to find clang-format!")

    # These live in the Vulkan-Docs repo, but are pulled in via the
    # Vulkan-Headers/registry folder
    # At runtime we inject python path to find these helper scripts
    scripts = os.path.dirname(registry)
    scripts_directory_path = os.path.dirname(os.path.abspath(__file__))
    registry_headers_path = os.path.join(scripts_directory_path, scripts)
    sys.path.insert(0, registry_headers_path)
    try:
        from reg import Registry
    except:
        print("ModuleNotFoundError: No module named 'reg'") # normal python error message
        print(f'{registry_headers_path} is not pointing to the Vulkan-Headers registry directory.')
        print("Inside Vulkan-Headers there is a registry/reg.py file that is used.")
        sys.exit(1) # Return without call stack so easy to spot error

    from base_generator import BaseGeneratorOptions
    from generators.command_common_generator import CommandCommonOutputGenerator
    from generators.command_printer_generator import CommandPrinterOutputGenerator
    from generators.command_recorder_generator import CommandRecorderOutputGenerator
    from generators.dispatch_generator import DispatchOutputGenerator
    from generators.command_prepost_generator import CommandPrePostGenerator
    from generators.command_tracker_generator import CommandTrackerGenerator
    from generators.context_generator import InterceptContextGenerator
    from generators.layer_base_generator import LayerBaseOutputGenerator
    from generators.test_icd_generator import TestIcdGenerator
    from generators.object_name_generator import ObjectNameGenerator

    # These set fields that are needed by both OutputGenerator and BaseGenerator,
    # but are uniform and don't need to be set at a per-generated file level
    from base_generator import SetOutputDirectory, SetTargetApiName, SetMergedApiNames, EnableCaching
    SetOutputDirectory(directory)
    SetTargetApiName(api)

    # Build up a list of all generators
    # Note: Options variable names MUST match order of constructor variable in generator
    generators = {
        'command_common.h' : {
            'generator': CommandCommonOutputGenerator,
            'genCombined': True,
        },
        'command_common.cpp' : {
            'generator': CommandCommonOutputGenerator,
            'genCombined': True,
        },
        'command_printer.h' : {
            'generator': CommandPrinterOutputGenerator,
            'genCombined': True,
        },
        'command_printer.cpp' : {
            'generator': CommandPrinterOutputGenerator,
            'genCombined': True,
        },
        'command_printer_structs.cpp' : {
            'generator': CommandPrinterOutputGenerator,
            'genCombined': True,
        },
        'command_printer_types.cpp' : {
            'generator': CommandPrinterOutputGenerator,
            'genCombined': True,
        },
        'command_recorder.h' : {
            'generator': CommandRecorderOutputGenerator,
            'genCombined': True,
        },
        'command_recorder.cpp' : {
            'generator': CommandRecorderOutputGenerator,
            'genCombined': True,
        },
        'command.h.inc' : {
            'generator': CommandPrePostGenerator,
            'genCombined': True,
        },
        'command.cpp.inc' : {
            'generator': CommandPrePostGenerator,
            'genCombined': True,
        },
        'command_tracker.h' : {
            'generator': CommandTrackerGenerator,
            'genCombined': True,
        },
        'command_tracker.cpp' : {
            'generator': CommandTrackerGenerator,
            'genCombined': True,
        },
        'dispatch.h' : {
            'generator': DispatchOutputGenerator,
            'genCombined': True,
        },
        'dispatch.cpp' : {
            'generator': DispatchOutputGenerator,
            'genCombined': True,
        },
        'cdl_commands.h.inc' : {
            'generator': InterceptContextGenerator,
            'genCombined': True,
        },
        'cdl_commands.cpp.inc' : {
            'generator': InterceptContextGenerator,
            'genCombined': True,
        },
        'layer_base.h.inc' : {
            'generator': LayerBaseOutputGenerator,
            'genCombined': True,
        },
        'layer_base.cpp.inc' : {
            'generator': LayerBaseOutputGenerator,
            'genCombined': True,
        },
        'test_icd_helper.h' : {
            'generator': TestIcdGenerator,
            'genCombined': True,
        },
        'object_name.h' : {
            'generator': ObjectNameGenerator,
            'genCombined': True,
        },
    }

    unknownTargets = [x for x in (targetFilter if targetFilter else []) if x not in generators.keys()]
    if unknownTargets:
        print(f'ERROR: No generator options for unknown target(s): {", ".join(unknownTargets)}', file=sys.stderr)
        return 1

    # Filter if --target is passed in
    targets = [x for x in generators.keys() if not targetFilter or x in targetFilter]

    cacheVkObjectData = None
    cachePath = os.path.join(tempfile.gettempdir(), f'vkobject_{os.getpid()}')
    if caching:
        EnableCaching()

    for index, target in enumerate(targets, start=1):
        print(f'[{index}|{len(targets)}] Generating {target}')

        # First grab a class contructor object and create an instance
        targetGenerator = generators[target]['generator']
        generatorOptions = generators[target]['options'] if 'options' in generators[target] else []
        generator = targetGenerator(*generatorOptions)

        # This code and the 'genCombined' generator metadata is used by downstream
        # users to generate code with all Vulkan APIs merged into the target API variant
        # (e.g. Vulkan SC) when needed. The constructed apiList is also used to filter
        # out non-applicable extensions later below.
        apiList = [api]
        if api != 'vulkan' and generators[target]['genCombined']:
            SetMergedApiNames('vulkan')
            apiList.append('vulkan')
        else:
            SetMergedApiNames(None)

        baseOptions = BaseGeneratorOptions(customFileName = target)

        # Create the registry object with the specified generator and generator
        # options. The options are set before XML loading as they may affect it.
        reg = Registry(generator, baseOptions)

        # Parse the specified registry XML into an ElementTree object
        tree = ElementTree.parse(registry)

        # Filter out extensions that are not on the API list
        [exts.remove(e) for exts in tree.findall('extensions') for e in exts.findall('extension') if (sup := e.get('supported')) is not None and all(api not in sup.split(',') for api in apiList)]

        # Load the XML tree into the registry object
        reg.loadElementTree(tree)

        # The cached data is saved inside the BaseGenerator, so search for it and try
        # to reuse the parsing for each generator file.
        if caching and not cacheVkObjectData:
            if os.path.isfile(cachePath):
                file = open(cachePath, 'rb')
                cacheVkObjectData = pickle.load(file)
                file.close()

        if caching and cacheVkObjectData and 'regenerate' not in generators[target]:
            # TODO - We shouldn't have to regenerate any files, need to investigate why we some scripts need it
            reg.gen.generateFromCache(cacheVkObjectData, reg.genOpts)
        else:
            # Finally, use the output generator to create the requested target
            reg.apiGen()

        # Run clang-format on the file
        if has_clang_format:
            common_ci.RunShellCmd(f'clang-format -i --style=file:{styleFile} {os.path.join(directory, target)}')

    if os.path.isfile(cachePath):
        os.remove(cachePath)

# helper to define paths relative to the repo root
def repo_relative(path):
    return os.path.abspath(os.path.join(os.path.dirname(__file__), '..', path))

def main(argv):
    # files to exclude from --verify check
    verify_exclude = [
        '.clang-format',
    ]

    parser = argparse.ArgumentParser(description='Generate source code for this repository')
    parser.add_argument('--api',
                        default='vulkan',
                        choices=['vulkan'],
                        help='Specify API name to generate')
    parser.add_argument('paths', nargs='+',
                        help='Either: Paths to the Vulkan-Headers registry directory and the SPIRV-Headers grammar directory'
                        + ' OR path to the base directory containing the Vulkan-Headers and SPIRV-Headers repositories')
    parser.add_argument('--generated-version', help='sets the header version used to generate the repo')
    parser.add_argument('-o', help='Create target and related files in specified directory.', dest='output_directory')
    group = parser.add_mutually_exclusive_group()
    group.add_argument('--target', nargs='+', help='only generate file names passed in')
    group.add_argument('-i', '--incremental', action='store_true', help='only update repo files that change')
    group.add_argument('-v', '--verify', action='store_true', help='verify repo files match generator output')
    group.add_argument('--no-caching', action='store_true', help='Do not try to cache generator objects')
    args = parser.parse_args(argv)

    repo_dir = repo_relative(f'src/generated')

    # Need pass style file incase running with --verify and it can't find the file automatically in the temp directory
    styleFile = repo_relative('.clang-format')
    if common_ci.IsGHA() and args.verify:
        # Have found that sometimes (~5%) the 20.04 Ubuntu machines have clang-format v11 but we need v14 to
        # use a dedicated styleFile location. For these case there we can survive just skipping the verify check
        stdout = subprocess.check_output(['clang-format', '--version']).decode("utf-8")
        version = stdout[stdout.index('version') + 8:][:2]
        if int(version) < 14:
            return 0 # Success

    # Update the api_version in the respective json files
    if args.generated_version:
        json_files = []
        json_files.append(repo_relative('src/crash_diagnostic_layer.json.in'))
        for json_file in json_files:
            with open(json_file) as f:
                data = json.load(f)

            data["layer"]["api_version"] = args.generated_version

            with open(json_file, mode='w', encoding='utf-8', newline='\n') as f:
                f.write(json.dumps(data, indent=4))

    # get directory where generators will run
    if args.verify or args.incremental:
        # generate in temp directory so we can compare or copy later
        temp_obj = tempfile.TemporaryDirectory(prefix='cdl_codegen_')
        temp_dir = temp_obj.name
        gen_dir = temp_dir
    else:
        # generate directly in the repo
        gen_dir = repo_dir

    if args.output_directory is not None:
      gen_dir = args.output_directory

    if len(args.paths) == 1:
        base = args.paths[0]
        registry = os.path.join(base, 'Vulkan-Headers/registry')
        grammar = os.path.join(base, 'SPIRV-Headers/include/spirv/unified1')
    elif len(args.paths) == 2:
        registry = args.paths[0]
        grammar = args.paths[1]
    else:
        args.print_help()
        return -1

    registry = os.path.abspath(os.path.join(registry,  'vk.xml'))
    if not os.path.isfile(registry):
        print(f'{registry} does not exist')
        return -1
    grammar = os.path.abspath(os.path.join(grammar, 'spirv.core.grammar.json'))
    if not os.path.isfile(grammar):
        print(f'{grammar} does not exist')
        return -1

    caching = not args.no_caching
    RunGenerators(args.api, registry, grammar, gen_dir, styleFile, args.target, caching)

    # optional post-generation steps
    if args.verify:
        # compare contents of temp dir and repo
        temp_files = set(os.listdir(temp_dir))
        repo_files = set(os.listdir(repo_dir))
        for filename in sorted((temp_files | repo_files) - set(verify_exclude)):
            temp_filename = os.path.join(temp_dir, filename)
            repo_filename = os.path.join(repo_dir, filename)
            if filename not in repo_files:
                print('ERROR: Missing repo file', filename)
                return 2
            elif filename not in temp_files:
                print('ERROR: Missing generator for', filename)
                return 3
            elif not filecmp.cmp(temp_filename, repo_filename, shallow=False):
                print('ERROR: Repo files do not match generator output for', filename)
                # print line diff on file mismatch
                with open(temp_filename) as temp_file, open(repo_filename) as repo_file:
                    print(''.join(difflib.unified_diff(temp_file.readlines(),
                                                       repo_file.readlines(),
                                                       fromfile='temp/' + filename,
                                                       tofile=  'repo/' + filename)))
                return 4

        # return code for test scripts
        print('SUCCESS: Repo files match generator output')

    elif args.incremental:
        # copy missing or differing files from temp directory to repo
        for filename in os.listdir(temp_dir):
            temp_filename = os.path.join(temp_dir, filename)
            repo_filename = os.path.join(repo_dir, filename)
            if not os.path.exists(repo_filename) or \
               not filecmp.cmp(temp_filename, repo_filename, shallow=False):
                print('update', repo_filename)
                shutil.copyfile(temp_filename, repo_filename)

    return 0

if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))

