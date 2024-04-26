/*
 Copyright 2020 Google Inc.

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
#pragma once

// https://github.com/googlestadia/halt_and_catch_fire/blob/main/src/crash_compute.comp
static const char kCrashComputeComp[] = R"glsl(
#version 430
layout (local_size_x = 4, local_size_y = 1, local_size_z = 1) in;

layout(binding = 0) buffer Input
{
    float selector;
} inBuffer;

layout(binding = 1) buffer Output
{
    float data[];
} outBuffer;

void main()
{
    uint idx =  gl_GlobalInvocationID.x;
    outBuffer.data[idx] = 1 + 2 * idx;
}
)glsl";

// https://github.com/googlestadia/halt_and_catch_fire/blob/main/src/infinite_loop.comp
static const char kInfiniteLoopComp[] = R"glsl(
#version 430
layout (local_size_x = 4, local_size_y = 1, local_size_z = 1) in;

layout(binding = 0) buffer Input
{
    uint data[];
} inBuffer;

layout(binding = 1) buffer Output
{
    float data[];
} outBuffer;

void main()
{
  uint idx = gl_GlobalInvocationID.x;
  uint cnt = inBuffer.data[0];

  float sum = 0;
  for (uint i = 0; i < cnt; ++i)
  {
    for (uint j = 0; j < cnt; ++j)
    {
      for (uint k = 0; k < cnt; ++k)
      {
        sum += i + j + k;
      }
    }
  }

  outBuffer.data[idx] = sum;
}
)glsl";

// https://github.com/googlestadia/halt_and_catch_fire/blob/main/src/read_write.comp
static const char kReadWriteComp[] = R"glsl(
#version 430
layout (local_size_x = 4, local_size_y = 1, local_size_z = 1) in;

layout(binding = 0) buffer Input
{
    float data[];
} inBuffer;

layout(binding = 1) buffer Output
{
    float data[];
} outBuffer;

void main()
{
    uint idx =  gl_GlobalInvocationID.x;
    outBuffer.data[idx] = inBuffer.data[idx] * 4;
}
)glsl";

// VVL NegativeGpuAVBufferDeviceAddress.ReadBeforePointerPushConstant
static const char kReadBeforePointerPushConstant[] = R"glsl(
#version 450
#extension GL_EXT_buffer_reference : enable
layout(buffer_reference, buffer_reference_align = 16) buffer bufStruct;
layout(push_constant) uniform ufoo {
    bufStruct data;
    int nWrites;
} u_info;
layout(buffer_reference, std140) buffer bufStruct {
    int a[4]; // 16 byte strides
};
void main() {
    for (int i=0; i < u_info.nWrites; ++i) {
	u_info.data.a[i] = 42;
    }
}
)glsl";
