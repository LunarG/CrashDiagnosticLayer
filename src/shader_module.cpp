/*
 Copyright 2018 Google Inc.
 Copyright 2023-2024 LunarG, Inc.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#include "shader_module.h"

#include "cdl.h"
#include "util.h"

#include <fstream>
#include <iostream>

#define SPIRV_PARSE_INCLUDE_VULKAN_SPIRV_HPP
#include "spirv_parse.h"

namespace crash_diagnostic_layer {

ShaderModule::ShaderModule(Context& context, VkShaderModule vk_shader_module, int load_options, size_t code_size,
                           const char* p_spirv, const std::filesystem::path& output_path)
    : context_(context), vk_shader_module_(vk_shader_module), output_path_(output_path) {
    if (load_options & LoadOptions::kDumpOnCreate) {
        DumpShaderCode("SHADER_", code_size, p_spirv);
    }

    if (load_options & LoadOptions::kKeepInMemory) {
        shader_code.assign(p_spirv, p_spirv + code_size);
    }

    BasicSpirvParse spirv_parse;
    SpirvParse::Result result = spirv_parse.Parse(code_size, p_spirv);
    if (SpirvParse::kSuccess == result) {
        execution_model_ = spirv_parse.GetExecutionModel();
        entry_point_ = spirv_parse.GetEntryPointName();
        source_file_ = spirv_parse.GetSourceFile();
    }
}

spv::ExecutionModel ShaderModule::GetExecutionModel() const { return execution_model_; }

const std::string& ShaderModule::GetEntryPoint() const { return entry_point_; }

const std::string& ShaderModule::GetSourceFile() const { return source_file_; }

std::string ShaderModule::DumpShaderCode(const std::string& prefix) const {
    if (shader_code.size() > 0) {
        return DumpShaderCode(prefix, shader_code.size(), shader_code.data());
    }

    return "";
}

std::string ShaderModule::DumpShaderCode(const std::string& prefix, size_t code_size, const char* p_spirv) const {
    std::string shader_filename =
        prefix + PtrToStr(vk_shader_module_) + "_" + std::to_string(GetExecutionModel()) + ".spv";
    std::filesystem::create_directories(output_path_);
    std::filesystem::path shader_output_path(output_path_);
    shader_output_path /= shader_filename;

    context_.Log().Info("Writing Shader: \'%s\'", shader_filename.c_str());

    std::ofstream os(shader_output_path);
    if (os.is_open()) {
        os.write(p_spirv, static_cast<std::streamsize>(code_size));
    }
    os.flush();
    os.close();

    return shader_filename;
}

}  // namespace crash_diagnostic_layer
