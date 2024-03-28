
/***************************************************************************
*
* Copyright (C) 2021 Google Inc.
* Copyright (c) 2023 LunarG, Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* *** ---- WARNING! ----
* ***   THIS FILE IS GENERATED - DO NOT EDIT
* ***   Update source file command_printer_generator.py for modifications
* *** ---- WARNING! ----
*
****************************************************************************/


// NOLINTBEGIN


#include <streambuf>
#include <vulkan/vk_enum_string_helper.h>

#include "command_common.h"
#include "command_printer.h"
#include "util.h"



// Define print functions.

void CommandPrinter::PrintBeginCommandBufferArgs(
  std::ostream & os, const BeginCommandBufferArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pBeginInfo" << std::endl;
    // pointer
    if (args.pBeginInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pBeginInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintEndCommandBufferArgs(
  std::ostream & os, const EndCommandBufferArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
}

void CommandPrinter::PrintResetCommandBufferArgs(
  std::ostream & os, const ResetCommandBufferArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  flags" << std::endl;
    // flags -> Field -> VkCommandBufferResetFlags
    os << "value: " << args.flags << std::endl;
  }
}

void CommandPrinter::PrintCmdBindPipelineArgs(
  std::ostream & os, const CmdBindPipelineArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pipelineBindPoint" << std::endl;
    // pipelineBindPoint -> Field -> VkPipelineBindPoint
    os << "value: " << args.pipelineBindPoint << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pipeline" << std::endl;
    // pipeline -> Field -> VkPipeline
    os << "value: " << args.pipeline << std::endl;
  }
}

void CommandPrinter::PrintCmdSetViewportArgs(
  std::ostream & os, const CmdSetViewportArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstViewport" << std::endl;
    // firstViewport -> Field -> uint32_t
    os << "value: " << args.firstViewport << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  viewportCount" << std::endl;
    // viewportCount -> Field -> uint32_t
    os << "value: " << args.viewportCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pViewports" << std::endl;
    // pViewports -> Field -> ConstDynamicArray(VkViewport)
    if (args.viewportCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkViewport" << std::endl;
        for (uint64_t i = 0; i < args.viewportCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pViewports << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdSetScissorArgs(
  std::ostream & os, const CmdSetScissorArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstScissor" << std::endl;
    // firstScissor -> Field -> uint32_t
    os << "value: " << args.firstScissor << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  scissorCount" << std::endl;
    // scissorCount -> Field -> uint32_t
    os << "value: " << args.scissorCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pScissors" << std::endl;
    // pScissors -> Field -> ConstDynamicArray(VkRect2D)
    if (args.scissorCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkRect2D" << std::endl;
        for (uint64_t i = 0; i < args.scissorCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pScissors << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdSetLineWidthArgs(
  std::ostream & os, const CmdSetLineWidthArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  lineWidth" << std::endl;
    // lineWidth -> Field -> float
    os << "value: " << args.lineWidth << std::endl;
  }
}

void CommandPrinter::PrintCmdSetDepthBiasArgs(
  std::ostream & os, const CmdSetDepthBiasArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  depthBiasConstantFactor" << std::endl;
    // depthBiasConstantFactor -> Field -> float
    os << "value: " << args.depthBiasConstantFactor << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  depthBiasClamp" << std::endl;
    // depthBiasClamp -> Field -> float
    os << "value: " << args.depthBiasClamp << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  depthBiasSlopeFactor" << std::endl;
    // depthBiasSlopeFactor -> Field -> float
    os << "value: " << args.depthBiasSlopeFactor << std::endl;
  }
}

void CommandPrinter::PrintCmdSetBlendConstantsArgs(
  std::ostream & os, const CmdSetBlendConstantsArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  blendConstants" << std::endl;
    // blendConstants -> Field -> ConstFixedArray(float)
    {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # float" << std::endl;
        for (uint64_t i = 0; i < 4; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.blendConstants << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdSetDepthBoundsArgs(
  std::ostream & os, const CmdSetDepthBoundsArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  minDepthBounds" << std::endl;
    // minDepthBounds -> Field -> float
    os << "value: " << args.minDepthBounds << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  maxDepthBounds" << std::endl;
    // maxDepthBounds -> Field -> float
    os << "value: " << args.maxDepthBounds << std::endl;
  }
}

void CommandPrinter::PrintCmdSetStencilCompareMaskArgs(
  std::ostream & os, const CmdSetStencilCompareMaskArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  faceMask" << std::endl;
    // faceMask -> Field -> VkStencilFaceFlags
    os << "value: " << args.faceMask << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  compareMask" << std::endl;
    // compareMask -> Field -> uint32_t
    os << "value: " << args.compareMask << std::endl;
  }
}

void CommandPrinter::PrintCmdSetStencilWriteMaskArgs(
  std::ostream & os, const CmdSetStencilWriteMaskArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  faceMask" << std::endl;
    // faceMask -> Field -> VkStencilFaceFlags
    os << "value: " << args.faceMask << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  writeMask" << std::endl;
    // writeMask -> Field -> uint32_t
    os << "value: " << args.writeMask << std::endl;
  }
}

void CommandPrinter::PrintCmdSetStencilReferenceArgs(
  std::ostream & os, const CmdSetStencilReferenceArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  faceMask" << std::endl;
    // faceMask -> Field -> VkStencilFaceFlags
    os << "value: " << args.faceMask << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  reference" << std::endl;
    // reference -> Field -> uint32_t
    os << "value: " << args.reference << std::endl;
  }
}

void CommandPrinter::PrintCmdBindDescriptorSetsArgs(
  std::ostream & os, const CmdBindDescriptorSetsArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pipelineBindPoint" << std::endl;
    // pipelineBindPoint -> Field -> VkPipelineBindPoint
    os << "value: " << args.pipelineBindPoint << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  layout" << std::endl;
    // layout -> Field -> VkPipelineLayout
    os << "value: " << args.layout << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstSet" << std::endl;
    // firstSet -> Field -> uint32_t
    os << "value: " << args.firstSet << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  descriptorSetCount" << std::endl;
    // descriptorSetCount -> Field -> uint32_t
    os << "value: " << args.descriptorSetCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pDescriptorSets" << std::endl;
    // pDescriptorSets -> Field -> ConstDynamicArray(VkDescriptorSet)
    if (args.descriptorSetCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkDescriptorSet" << std::endl;
        for (uint64_t i = 0; i < args.descriptorSetCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pDescriptorSets << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dynamicOffsetCount" << std::endl;
    // dynamicOffsetCount -> Field -> uint32_t
    os << "value: " << args.dynamicOffsetCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pDynamicOffsets" << std::endl;
    // pDynamicOffsets -> Field -> ConstDynamicArray(uint32_t)
    if (args.dynamicOffsetCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # uint32_t" << std::endl;
        for (uint64_t i = 0; i < args.dynamicOffsetCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pDynamicOffsets << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdBindIndexBufferArgs(
  std::ostream & os, const CmdBindIndexBufferArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  buffer" << std::endl;
    // buffer -> Field -> VkBuffer
    os << "value: " << args.buffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  offset" << std::endl;
    // offset -> Field -> VkDeviceSize
    os << "value: " << args.offset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  indexType" << std::endl;
    // indexType -> Field -> VkIndexType
    os << "value: " << args.indexType << std::endl;
  }
}

void CommandPrinter::PrintCmdBindVertexBuffersArgs(
  std::ostream & os, const CmdBindVertexBuffersArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstBinding" << std::endl;
    // firstBinding -> Field -> uint32_t
    os << "value: " << args.firstBinding << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  bindingCount" << std::endl;
    // bindingCount -> Field -> uint32_t
    os << "value: " << args.bindingCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pBuffers" << std::endl;
    // pBuffers -> Field -> ConstDynamicArray(VkBuffer)
    if (args.bindingCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkBuffer" << std::endl;
        for (uint64_t i = 0; i < args.bindingCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pBuffers << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pOffsets" << std::endl;
    // pOffsets -> Field -> ConstDynamicArray(VkDeviceSize)
    if (args.bindingCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkDeviceSize" << std::endl;
        for (uint64_t i = 0; i < args.bindingCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pOffsets << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdDrawArgs(
  std::ostream & os, const CmdDrawArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  vertexCount" << std::endl;
    // vertexCount -> Field -> uint32_t
    os << "value: " << args.vertexCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  instanceCount" << std::endl;
    // instanceCount -> Field -> uint32_t
    os << "value: " << args.instanceCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstVertex" << std::endl;
    // firstVertex -> Field -> uint32_t
    os << "value: " << args.firstVertex << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstInstance" << std::endl;
    // firstInstance -> Field -> uint32_t
    os << "value: " << args.firstInstance << std::endl;
  }
}

void CommandPrinter::PrintCmdDrawIndexedArgs(
  std::ostream & os, const CmdDrawIndexedArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  indexCount" << std::endl;
    // indexCount -> Field -> uint32_t
    os << "value: " << args.indexCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  instanceCount" << std::endl;
    // instanceCount -> Field -> uint32_t
    os << "value: " << args.instanceCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstIndex" << std::endl;
    // firstIndex -> Field -> uint32_t
    os << "value: " << args.firstIndex << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  vertexOffset" << std::endl;
    // vertexOffset -> Field -> int32_t
    os << "value: " << args.vertexOffset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstInstance" << std::endl;
    // firstInstance -> Field -> uint32_t
    os << "value: " << args.firstInstance << std::endl;
  }
}

void CommandPrinter::PrintCmdDrawIndirectArgs(
  std::ostream & os, const CmdDrawIndirectArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  buffer" << std::endl;
    // buffer -> Field -> VkBuffer
    os << "value: " << args.buffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  offset" << std::endl;
    // offset -> Field -> VkDeviceSize
    os << "value: " << args.offset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  drawCount" << std::endl;
    // drawCount -> Field -> uint32_t
    os << "value: " << args.drawCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stride" << std::endl;
    // stride -> Field -> uint32_t
    os << "value: " << args.stride << std::endl;
  }
}

void CommandPrinter::PrintCmdDrawIndexedIndirectArgs(
  std::ostream & os, const CmdDrawIndexedIndirectArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  buffer" << std::endl;
    // buffer -> Field -> VkBuffer
    os << "value: " << args.buffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  offset" << std::endl;
    // offset -> Field -> VkDeviceSize
    os << "value: " << args.offset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  drawCount" << std::endl;
    // drawCount -> Field -> uint32_t
    os << "value: " << args.drawCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stride" << std::endl;
    // stride -> Field -> uint32_t
    os << "value: " << args.stride << std::endl;
  }
}

void CommandPrinter::PrintCmdDispatchArgs(
  std::ostream & os, const CmdDispatchArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  groupCountX" << std::endl;
    // groupCountX -> Field -> uint32_t
    os << "value: " << args.groupCountX << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  groupCountY" << std::endl;
    // groupCountY -> Field -> uint32_t
    os << "value: " << args.groupCountY << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  groupCountZ" << std::endl;
    // groupCountZ -> Field -> uint32_t
    os << "value: " << args.groupCountZ << std::endl;
  }
}

void CommandPrinter::PrintCmdDispatchIndirectArgs(
  std::ostream & os, const CmdDispatchIndirectArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  buffer" << std::endl;
    // buffer -> Field -> VkBuffer
    os << "value: " << args.buffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  offset" << std::endl;
    // offset -> Field -> VkDeviceSize
    os << "value: " << args.offset << std::endl;
  }
}

void CommandPrinter::PrintCmdCopyBufferArgs(
  std::ostream & os, const CmdCopyBufferArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  srcBuffer" << std::endl;
    // srcBuffer -> Field -> VkBuffer
    os << "value: " << args.srcBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dstBuffer" << std::endl;
    // dstBuffer -> Field -> VkBuffer
    os << "value: " << args.dstBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  regionCount" << std::endl;
    // regionCount -> Field -> uint32_t
    os << "value: " << args.regionCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pRegions" << std::endl;
    // pRegions -> Field -> ConstDynamicArray(VkBufferCopy)
    if (args.regionCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkBufferCopy" << std::endl;
        for (uint64_t i = 0; i < args.regionCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pRegions << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdCopyImageArgs(
  std::ostream & os, const CmdCopyImageArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  srcImage" << std::endl;
    // srcImage -> Field -> VkImage
    os << "value: " << args.srcImage << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  srcImageLayout" << std::endl;
    // srcImageLayout -> Field -> VkImageLayout
    os << "value: " << args.srcImageLayout << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dstImage" << std::endl;
    // dstImage -> Field -> VkImage
    os << "value: " << args.dstImage << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dstImageLayout" << std::endl;
    // dstImageLayout -> Field -> VkImageLayout
    os << "value: " << args.dstImageLayout << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  regionCount" << std::endl;
    // regionCount -> Field -> uint32_t
    os << "value: " << args.regionCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pRegions" << std::endl;
    // pRegions -> Field -> ConstDynamicArray(VkImageCopy)
    if (args.regionCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkImageCopy" << std::endl;
        for (uint64_t i = 0; i < args.regionCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pRegions << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdBlitImageArgs(
  std::ostream & os, const CmdBlitImageArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  srcImage" << std::endl;
    // srcImage -> Field -> VkImage
    os << "value: " << args.srcImage << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  srcImageLayout" << std::endl;
    // srcImageLayout -> Field -> VkImageLayout
    os << "value: " << args.srcImageLayout << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dstImage" << std::endl;
    // dstImage -> Field -> VkImage
    os << "value: " << args.dstImage << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dstImageLayout" << std::endl;
    // dstImageLayout -> Field -> VkImageLayout
    os << "value: " << args.dstImageLayout << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  regionCount" << std::endl;
    // regionCount -> Field -> uint32_t
    os << "value: " << args.regionCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pRegions" << std::endl;
    // pRegions -> Field -> ConstDynamicArray(VkImageBlit)
    if (args.regionCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkImageBlit" << std::endl;
        for (uint64_t i = 0; i < args.regionCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pRegions << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  filter" << std::endl;
    // filter -> Field -> VkFilter
    os << "value: " << args.filter << std::endl;
  }
}

void CommandPrinter::PrintCmdCopyBufferToImageArgs(
  std::ostream & os, const CmdCopyBufferToImageArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  srcBuffer" << std::endl;
    // srcBuffer -> Field -> VkBuffer
    os << "value: " << args.srcBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dstImage" << std::endl;
    // dstImage -> Field -> VkImage
    os << "value: " << args.dstImage << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dstImageLayout" << std::endl;
    // dstImageLayout -> Field -> VkImageLayout
    os << "value: " << args.dstImageLayout << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  regionCount" << std::endl;
    // regionCount -> Field -> uint32_t
    os << "value: " << args.regionCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pRegions" << std::endl;
    // pRegions -> Field -> ConstDynamicArray(VkBufferImageCopy)
    if (args.regionCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkBufferImageCopy" << std::endl;
        for (uint64_t i = 0; i < args.regionCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pRegions << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdCopyImageToBufferArgs(
  std::ostream & os, const CmdCopyImageToBufferArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  srcImage" << std::endl;
    // srcImage -> Field -> VkImage
    os << "value: " << args.srcImage << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  srcImageLayout" << std::endl;
    // srcImageLayout -> Field -> VkImageLayout
    os << "value: " << args.srcImageLayout << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dstBuffer" << std::endl;
    // dstBuffer -> Field -> VkBuffer
    os << "value: " << args.dstBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  regionCount" << std::endl;
    // regionCount -> Field -> uint32_t
    os << "value: " << args.regionCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pRegions" << std::endl;
    // pRegions -> Field -> ConstDynamicArray(VkBufferImageCopy)
    if (args.regionCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkBufferImageCopy" << std::endl;
        for (uint64_t i = 0; i < args.regionCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pRegions << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdUpdateBufferArgs(
  std::ostream & os, const CmdUpdateBufferArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dstBuffer" << std::endl;
    // dstBuffer -> Field -> VkBuffer
    os << "value: " << args.dstBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dstOffset" << std::endl;
    // dstOffset -> Field -> VkDeviceSize
    os << "value: " << args.dstOffset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dataSize" << std::endl;
    // dataSize -> Field -> VkDeviceSize
    os << "value: " << args.dataSize << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pData" << std::endl;
    if (args.dataSize == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << std::hex;
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        const uint8_t *p = (const uint8_t *)args.pData;
        for (uint64_t i = 0; i < args.dataSize; ++i) {
          os << "- 0x" << std::hex << static_cast<uint32_t>(p[i]) << std::endl;
        }
      }
      os << std::dec;
    }
  }
}

void CommandPrinter::PrintCmdFillBufferArgs(
  std::ostream & os, const CmdFillBufferArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dstBuffer" << std::endl;
    // dstBuffer -> Field -> VkBuffer
    os << "value: " << args.dstBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dstOffset" << std::endl;
    // dstOffset -> Field -> VkDeviceSize
    os << "value: " << args.dstOffset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  size" << std::endl;
    // size -> Field -> VkDeviceSize
    os << "value: " << args.size << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  data" << std::endl;
    // data -> Field -> uint32_t
    os << "value: " << args.data << std::endl;
  }
}

void CommandPrinter::PrintCmdClearColorImageArgs(
  std::ostream & os, const CmdClearColorImageArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  image" << std::endl;
    // image -> Field -> VkImage
    os << "value: " << args.image << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  imageLayout" << std::endl;
    // imageLayout -> Field -> VkImageLayout
    os << "value: " << args.imageLayout << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pColor" << std::endl;
    // pointer
    if (args.pColor != nullptr) {
      os <<  "members:" << std::endl << *args.pColor << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  rangeCount" << std::endl;
    // rangeCount -> Field -> uint32_t
    os << "value: " << args.rangeCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pRanges" << std::endl;
    // pRanges -> Field -> ConstDynamicArray(VkImageSubresourceRange)
    if (args.rangeCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkImageSubresourceRange" << std::endl;
        for (uint64_t i = 0; i < args.rangeCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pRanges << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdClearDepthStencilImageArgs(
  std::ostream & os, const CmdClearDepthStencilImageArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  image" << std::endl;
    // image -> Field -> VkImage
    os << "value: " << args.image << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  imageLayout" << std::endl;
    // imageLayout -> Field -> VkImageLayout
    os << "value: " << args.imageLayout << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pDepthStencil" << std::endl;
    // pointer
    if (args.pDepthStencil != nullptr) {
      os <<  "members:" << std::endl << *args.pDepthStencil << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  rangeCount" << std::endl;
    // rangeCount -> Field -> uint32_t
    os << "value: " << args.rangeCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pRanges" << std::endl;
    // pRanges -> Field -> ConstDynamicArray(VkImageSubresourceRange)
    if (args.rangeCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkImageSubresourceRange" << std::endl;
        for (uint64_t i = 0; i < args.rangeCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pRanges << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdClearAttachmentsArgs(
  std::ostream & os, const CmdClearAttachmentsArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  attachmentCount" << std::endl;
    // attachmentCount -> Field -> uint32_t
    os << "value: " << args.attachmentCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pAttachments" << std::endl;
    // pAttachments -> Field -> ConstDynamicArray(VkClearAttachment)
    if (args.attachmentCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkClearAttachment" << std::endl;
        for (uint64_t i = 0; i < args.attachmentCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pAttachments << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  rectCount" << std::endl;
    // rectCount -> Field -> uint32_t
    os << "value: " << args.rectCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pRects" << std::endl;
    // pRects -> Field -> ConstDynamicArray(VkClearRect)
    if (args.rectCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkClearRect" << std::endl;
        for (uint64_t i = 0; i < args.rectCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pRects << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdResolveImageArgs(
  std::ostream & os, const CmdResolveImageArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  srcImage" << std::endl;
    // srcImage -> Field -> VkImage
    os << "value: " << args.srcImage << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  srcImageLayout" << std::endl;
    // srcImageLayout -> Field -> VkImageLayout
    os << "value: " << args.srcImageLayout << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dstImage" << std::endl;
    // dstImage -> Field -> VkImage
    os << "value: " << args.dstImage << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dstImageLayout" << std::endl;
    // dstImageLayout -> Field -> VkImageLayout
    os << "value: " << args.dstImageLayout << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  regionCount" << std::endl;
    // regionCount -> Field -> uint32_t
    os << "value: " << args.regionCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pRegions" << std::endl;
    // pRegions -> Field -> ConstDynamicArray(VkImageResolve)
    if (args.regionCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkImageResolve" << std::endl;
        for (uint64_t i = 0; i < args.regionCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pRegions << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdSetEventArgs(
  std::ostream & os, const CmdSetEventArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  event" << std::endl;
    // event -> Field -> VkEvent
    os << "value: " << args.event << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stageMask" << std::endl;
    // stageMask -> Field -> VkPipelineStageFlags
    os << "value: " << args.stageMask << std::endl;
  }
}

void CommandPrinter::PrintCmdResetEventArgs(
  std::ostream & os, const CmdResetEventArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  event" << std::endl;
    // event -> Field -> VkEvent
    os << "value: " << args.event << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stageMask" << std::endl;
    // stageMask -> Field -> VkPipelineStageFlags
    os << "value: " << args.stageMask << std::endl;
  }
}

void CommandPrinter::PrintCmdWaitEventsArgs(
  std::ostream & os, const CmdWaitEventsArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  eventCount" << std::endl;
    // eventCount -> Field -> uint32_t
    os << "value: " << args.eventCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pEvents" << std::endl;
    // pEvents -> Field -> ConstDynamicArray(VkEvent)
    if (args.eventCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkEvent" << std::endl;
        for (uint64_t i = 0; i < args.eventCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pEvents << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  srcStageMask" << std::endl;
    // srcStageMask -> Field -> VkPipelineStageFlags
    os << "value: " << args.srcStageMask << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dstStageMask" << std::endl;
    // dstStageMask -> Field -> VkPipelineStageFlags
    os << "value: " << args.dstStageMask << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  memoryBarrierCount" << std::endl;
    // memoryBarrierCount -> Field -> uint32_t
    os << "value: " << args.memoryBarrierCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pMemoryBarriers" << std::endl;
    // pMemoryBarriers -> Field -> ConstDynamicArray(VkMemoryBarrier)
    if (args.memoryBarrierCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkMemoryBarrier" << std::endl;
        for (uint64_t i = 0; i < args.memoryBarrierCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pMemoryBarriers << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  bufferMemoryBarrierCount" << std::endl;
    // bufferMemoryBarrierCount -> Field -> uint32_t
    os << "value: " << args.bufferMemoryBarrierCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pBufferMemoryBarriers" << std::endl;
    // pBufferMemoryBarriers -> Field -> ConstDynamicArray(VkBufferMemoryBarrier)
    if (args.bufferMemoryBarrierCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkBufferMemoryBarrier" << std::endl;
        for (uint64_t i = 0; i < args.bufferMemoryBarrierCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pBufferMemoryBarriers << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  imageMemoryBarrierCount" << std::endl;
    // imageMemoryBarrierCount -> Field -> uint32_t
    os << "value: " << args.imageMemoryBarrierCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pImageMemoryBarriers" << std::endl;
    // pImageMemoryBarriers -> Field -> ConstDynamicArray(VkImageMemoryBarrier)
    if (args.imageMemoryBarrierCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkImageMemoryBarrier" << std::endl;
        for (uint64_t i = 0; i < args.imageMemoryBarrierCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pImageMemoryBarriers << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdPipelineBarrierArgs(
  std::ostream & os, const CmdPipelineBarrierArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  srcStageMask" << std::endl;
    // srcStageMask -> Field -> VkPipelineStageFlags
    os << "value: " << args.srcStageMask << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dstStageMask" << std::endl;
    // dstStageMask -> Field -> VkPipelineStageFlags
    os << "value: " << args.dstStageMask << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dependencyFlags" << std::endl;
    // dependencyFlags -> Field -> VkDependencyFlags
    os << "value: " << args.dependencyFlags << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  memoryBarrierCount" << std::endl;
    // memoryBarrierCount -> Field -> uint32_t
    os << "value: " << args.memoryBarrierCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pMemoryBarriers" << std::endl;
    // pMemoryBarriers -> Field -> ConstDynamicArray(VkMemoryBarrier)
    if (args.memoryBarrierCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkMemoryBarrier" << std::endl;
        for (uint64_t i = 0; i < args.memoryBarrierCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pMemoryBarriers << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  bufferMemoryBarrierCount" << std::endl;
    // bufferMemoryBarrierCount -> Field -> uint32_t
    os << "value: " << args.bufferMemoryBarrierCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pBufferMemoryBarriers" << std::endl;
    // pBufferMemoryBarriers -> Field -> ConstDynamicArray(VkBufferMemoryBarrier)
    if (args.bufferMemoryBarrierCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkBufferMemoryBarrier" << std::endl;
        for (uint64_t i = 0; i < args.bufferMemoryBarrierCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pBufferMemoryBarriers << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  imageMemoryBarrierCount" << std::endl;
    // imageMemoryBarrierCount -> Field -> uint32_t
    os << "value: " << args.imageMemoryBarrierCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pImageMemoryBarriers" << std::endl;
    // pImageMemoryBarriers -> Field -> ConstDynamicArray(VkImageMemoryBarrier)
    if (args.imageMemoryBarrierCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkImageMemoryBarrier" << std::endl;
        for (uint64_t i = 0; i < args.imageMemoryBarrierCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pImageMemoryBarriers << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdBeginQueryArgs(
  std::ostream & os, const CmdBeginQueryArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  queryPool" << std::endl;
    // queryPool -> Field -> VkQueryPool
    os << "value: " << args.queryPool << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  query" << std::endl;
    // query -> Field -> uint32_t
    os << "value: " << args.query << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  flags" << std::endl;
    // flags -> Field -> VkQueryControlFlags
    os << "value: " << args.flags << std::endl;
  }
}

void CommandPrinter::PrintCmdEndQueryArgs(
  std::ostream & os, const CmdEndQueryArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  queryPool" << std::endl;
    // queryPool -> Field -> VkQueryPool
    os << "value: " << args.queryPool << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  query" << std::endl;
    // query -> Field -> uint32_t
    os << "value: " << args.query << std::endl;
  }
}

void CommandPrinter::PrintCmdResetQueryPoolArgs(
  std::ostream & os, const CmdResetQueryPoolArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  queryPool" << std::endl;
    // queryPool -> Field -> VkQueryPool
    os << "value: " << args.queryPool << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstQuery" << std::endl;
    // firstQuery -> Field -> uint32_t
    os << "value: " << args.firstQuery << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  queryCount" << std::endl;
    // queryCount -> Field -> uint32_t
    os << "value: " << args.queryCount << std::endl;
  }
}

void CommandPrinter::PrintCmdWriteTimestampArgs(
  std::ostream & os, const CmdWriteTimestampArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pipelineStage" << std::endl;
    // pipelineStage -> Field -> VkPipelineStageFlagBits
    os << "value: " << args.pipelineStage << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  queryPool" << std::endl;
    // queryPool -> Field -> VkQueryPool
    os << "value: " << args.queryPool << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  query" << std::endl;
    // query -> Field -> uint32_t
    os << "value: " << args.query << std::endl;
  }
}

void CommandPrinter::PrintCmdCopyQueryPoolResultsArgs(
  std::ostream & os, const CmdCopyQueryPoolResultsArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  queryPool" << std::endl;
    // queryPool -> Field -> VkQueryPool
    os << "value: " << args.queryPool << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstQuery" << std::endl;
    // firstQuery -> Field -> uint32_t
    os << "value: " << args.firstQuery << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  queryCount" << std::endl;
    // queryCount -> Field -> uint32_t
    os << "value: " << args.queryCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dstBuffer" << std::endl;
    // dstBuffer -> Field -> VkBuffer
    os << "value: " << args.dstBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dstOffset" << std::endl;
    // dstOffset -> Field -> VkDeviceSize
    os << "value: " << args.dstOffset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stride" << std::endl;
    // stride -> Field -> VkDeviceSize
    os << "value: " << args.stride << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  flags" << std::endl;
    // flags -> Field -> VkQueryResultFlags
    os << "value: " << args.flags << std::endl;
  }
}

void CommandPrinter::PrintCmdPushConstantsArgs(
  std::ostream & os, const CmdPushConstantsArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  layout" << std::endl;
    // layout -> Field -> VkPipelineLayout
    os << "value: " << args.layout << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stageFlags" << std::endl;
    // stageFlags -> Field -> VkShaderStageFlags
    os << "value: " << args.stageFlags << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  offset" << std::endl;
    // offset -> Field -> uint32_t
    os << "value: " << args.offset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  size" << std::endl;
    // size -> Field -> uint32_t
    os << "value: " << args.size << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pValues" << std::endl;
    if (args.size == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << std::hex;
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        const uint8_t *p = (const uint8_t *)args.pValues;
        for (uint64_t i = 0; i < args.size; ++i) {
          os << "- 0x" << std::hex << static_cast<uint32_t>(p[i]) << std::endl;
        }
      }
      os << std::dec;
    }
  }
}

void CommandPrinter::PrintCmdBeginRenderPassArgs(
  std::ostream & os, const CmdBeginRenderPassArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pRenderPassBegin" << std::endl;
    // pointer
    if (args.pRenderPassBegin != nullptr) {
      os <<  "members:" << std::endl << *args.pRenderPassBegin << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  contents" << std::endl;
    // contents -> Field -> VkSubpassContents
    os << "value: " << args.contents << std::endl;
  }
}

void CommandPrinter::PrintCmdNextSubpassArgs(
  std::ostream & os, const CmdNextSubpassArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  contents" << std::endl;
    // contents -> Field -> VkSubpassContents
    os << "value: " << args.contents << std::endl;
  }
}

void CommandPrinter::PrintCmdEndRenderPassArgs(
  std::ostream & os, const CmdEndRenderPassArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
}

void CommandPrinter::PrintCmdExecuteCommandsArgs(
  std::ostream & os, const CmdExecuteCommandsArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBufferCount" << std::endl;
    // commandBufferCount -> Field -> uint32_t
    os << "value: " << args.commandBufferCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pCommandBuffers" << std::endl;
    // pCommandBuffers -> Field -> ConstDynamicArray(VkCommandBuffer)
    if (args.commandBufferCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkCommandBuffer" << std::endl;
        for (uint64_t i = 0; i < args.commandBufferCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pCommandBuffers << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdSetDeviceMaskArgs(
  std::ostream & os, const CmdSetDeviceMaskArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  deviceMask" << std::endl;
    // deviceMask -> Field -> uint32_t
    os << "value: " << args.deviceMask << std::endl;
  }
}

void CommandPrinter::PrintCmdDispatchBaseArgs(
  std::ostream & os, const CmdDispatchBaseArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  baseGroupX" << std::endl;
    // baseGroupX -> Field -> uint32_t
    os << "value: " << args.baseGroupX << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  baseGroupY" << std::endl;
    // baseGroupY -> Field -> uint32_t
    os << "value: " << args.baseGroupY << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  baseGroupZ" << std::endl;
    // baseGroupZ -> Field -> uint32_t
    os << "value: " << args.baseGroupZ << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  groupCountX" << std::endl;
    // groupCountX -> Field -> uint32_t
    os << "value: " << args.groupCountX << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  groupCountY" << std::endl;
    // groupCountY -> Field -> uint32_t
    os << "value: " << args.groupCountY << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  groupCountZ" << std::endl;
    // groupCountZ -> Field -> uint32_t
    os << "value: " << args.groupCountZ << std::endl;
  }
}

void CommandPrinter::PrintCmdDrawIndirectCountArgs(
  std::ostream & os, const CmdDrawIndirectCountArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  buffer" << std::endl;
    // buffer -> Field -> VkBuffer
    os << "value: " << args.buffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  offset" << std::endl;
    // offset -> Field -> VkDeviceSize
    os << "value: " << args.offset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  countBuffer" << std::endl;
    // countBuffer -> Field -> VkBuffer
    os << "value: " << args.countBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  countBufferOffset" << std::endl;
    // countBufferOffset -> Field -> VkDeviceSize
    os << "value: " << args.countBufferOffset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  maxDrawCount" << std::endl;
    // maxDrawCount -> Field -> uint32_t
    os << "value: " << args.maxDrawCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stride" << std::endl;
    // stride -> Field -> uint32_t
    os << "value: " << args.stride << std::endl;
  }
}

void CommandPrinter::PrintCmdDrawIndexedIndirectCountArgs(
  std::ostream & os, const CmdDrawIndexedIndirectCountArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  buffer" << std::endl;
    // buffer -> Field -> VkBuffer
    os << "value: " << args.buffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  offset" << std::endl;
    // offset -> Field -> VkDeviceSize
    os << "value: " << args.offset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  countBuffer" << std::endl;
    // countBuffer -> Field -> VkBuffer
    os << "value: " << args.countBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  countBufferOffset" << std::endl;
    // countBufferOffset -> Field -> VkDeviceSize
    os << "value: " << args.countBufferOffset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  maxDrawCount" << std::endl;
    // maxDrawCount -> Field -> uint32_t
    os << "value: " << args.maxDrawCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stride" << std::endl;
    // stride -> Field -> uint32_t
    os << "value: " << args.stride << std::endl;
  }
}

void CommandPrinter::PrintCmdBeginRenderPass2Args(
  std::ostream & os, const CmdBeginRenderPass2Args &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pRenderPassBegin" << std::endl;
    // pointer
    if (args.pRenderPassBegin != nullptr) {
      os <<  "members:" << std::endl << *args.pRenderPassBegin << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pSubpassBeginInfo" << std::endl;
    // pointer
    if (args.pSubpassBeginInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pSubpassBeginInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdNextSubpass2Args(
  std::ostream & os, const CmdNextSubpass2Args &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pSubpassBeginInfo" << std::endl;
    // pointer
    if (args.pSubpassBeginInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pSubpassBeginInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pSubpassEndInfo" << std::endl;
    // pointer
    if (args.pSubpassEndInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pSubpassEndInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdEndRenderPass2Args(
  std::ostream & os, const CmdEndRenderPass2Args &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pSubpassEndInfo" << std::endl;
    // pointer
    if (args.pSubpassEndInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pSubpassEndInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdSetEvent2Args(
  std::ostream & os, const CmdSetEvent2Args &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  event" << std::endl;
    // event -> Field -> VkEvent
    os << "value: " << args.event << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pDependencyInfo" << std::endl;
    // pointer
    if (args.pDependencyInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pDependencyInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdResetEvent2Args(
  std::ostream & os, const CmdResetEvent2Args &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  event" << std::endl;
    // event -> Field -> VkEvent
    os << "value: " << args.event << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stageMask" << std::endl;
    // stageMask -> Field -> VkPipelineStageFlags2
    os << "value: " << args.stageMask << std::endl;
  }
}

void CommandPrinter::PrintCmdWaitEvents2Args(
  std::ostream & os, const CmdWaitEvents2Args &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  eventCount" << std::endl;
    // eventCount -> Field -> uint32_t
    os << "value: " << args.eventCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pEvents" << std::endl;
    // pEvents -> Field -> ConstDynamicArray(VkEvent)
    if (args.eventCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkEvent" << std::endl;
        for (uint64_t i = 0; i < args.eventCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pEvents << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pDependencyInfos" << std::endl;
    // pDependencyInfos -> Field -> ConstDynamicArray(VkDependencyInfo)
    if (args.eventCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkDependencyInfo" << std::endl;
        for (uint64_t i = 0; i < args.eventCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pDependencyInfos << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdPipelineBarrier2Args(
  std::ostream & os, const CmdPipelineBarrier2Args &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pDependencyInfo" << std::endl;
    // pointer
    if (args.pDependencyInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pDependencyInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdWriteTimestamp2Args(
  std::ostream & os, const CmdWriteTimestamp2Args &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stage" << std::endl;
    // stage -> Field -> VkPipelineStageFlags2
    os << "value: " << args.stage << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  queryPool" << std::endl;
    // queryPool -> Field -> VkQueryPool
    os << "value: " << args.queryPool << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  query" << std::endl;
    // query -> Field -> uint32_t
    os << "value: " << args.query << std::endl;
  }
}

void CommandPrinter::PrintCmdCopyBuffer2Args(
  std::ostream & os, const CmdCopyBuffer2Args &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pCopyBufferInfo" << std::endl;
    // pointer
    if (args.pCopyBufferInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pCopyBufferInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdCopyImage2Args(
  std::ostream & os, const CmdCopyImage2Args &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pCopyImageInfo" << std::endl;
    // pointer
    if (args.pCopyImageInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pCopyImageInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdCopyBufferToImage2Args(
  std::ostream & os, const CmdCopyBufferToImage2Args &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pCopyBufferToImageInfo" << std::endl;
    // pointer
    if (args.pCopyBufferToImageInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pCopyBufferToImageInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdCopyImageToBuffer2Args(
  std::ostream & os, const CmdCopyImageToBuffer2Args &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pCopyImageToBufferInfo" << std::endl;
    // pointer
    if (args.pCopyImageToBufferInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pCopyImageToBufferInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdBlitImage2Args(
  std::ostream & os, const CmdBlitImage2Args &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pBlitImageInfo" << std::endl;
    // pointer
    if (args.pBlitImageInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pBlitImageInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdResolveImage2Args(
  std::ostream & os, const CmdResolveImage2Args &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pResolveImageInfo" << std::endl;
    // pointer
    if (args.pResolveImageInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pResolveImageInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdBeginRenderingArgs(
  std::ostream & os, const CmdBeginRenderingArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pRenderingInfo" << std::endl;
    // pointer
    if (args.pRenderingInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pRenderingInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdEndRenderingArgs(
  std::ostream & os, const CmdEndRenderingArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
}

void CommandPrinter::PrintCmdSetCullModeArgs(
  std::ostream & os, const CmdSetCullModeArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  cullMode" << std::endl;
    // cullMode -> Field -> VkCullModeFlags
    os << "value: " << args.cullMode << std::endl;
  }
}

void CommandPrinter::PrintCmdSetFrontFaceArgs(
  std::ostream & os, const CmdSetFrontFaceArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  frontFace" << std::endl;
    // frontFace -> Field -> VkFrontFace
    os << "value: " << args.frontFace << std::endl;
  }
}

void CommandPrinter::PrintCmdSetPrimitiveTopologyArgs(
  std::ostream & os, const CmdSetPrimitiveTopologyArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  primitiveTopology" << std::endl;
    // primitiveTopology -> Field -> VkPrimitiveTopology
    os << "value: " << args.primitiveTopology << std::endl;
  }
}

void CommandPrinter::PrintCmdSetViewportWithCountArgs(
  std::ostream & os, const CmdSetViewportWithCountArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  viewportCount" << std::endl;
    // viewportCount -> Field -> uint32_t
    os << "value: " << args.viewportCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pViewports" << std::endl;
    // pViewports -> Field -> ConstDynamicArray(VkViewport)
    if (args.viewportCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkViewport" << std::endl;
        for (uint64_t i = 0; i < args.viewportCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pViewports << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdSetScissorWithCountArgs(
  std::ostream & os, const CmdSetScissorWithCountArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  scissorCount" << std::endl;
    // scissorCount -> Field -> uint32_t
    os << "value: " << args.scissorCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pScissors" << std::endl;
    // pScissors -> Field -> ConstDynamicArray(VkRect2D)
    if (args.scissorCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkRect2D" << std::endl;
        for (uint64_t i = 0; i < args.scissorCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pScissors << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdBindVertexBuffers2Args(
  std::ostream & os, const CmdBindVertexBuffers2Args &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstBinding" << std::endl;
    // firstBinding -> Field -> uint32_t
    os << "value: " << args.firstBinding << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  bindingCount" << std::endl;
    // bindingCount -> Field -> uint32_t
    os << "value: " << args.bindingCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pBuffers" << std::endl;
    // pBuffers -> Field -> ConstDynamicArray(VkBuffer)
    if (args.bindingCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkBuffer" << std::endl;
        for (uint64_t i = 0; i < args.bindingCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pBuffers << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pOffsets" << std::endl;
    // pOffsets -> Field -> ConstDynamicArray(VkDeviceSize)
    if (args.bindingCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkDeviceSize" << std::endl;
        for (uint64_t i = 0; i < args.bindingCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pOffsets << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pSizes" << std::endl;
    // pSizes -> Field -> ConstDynamicArray(VkDeviceSize)
    if (args.bindingCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkDeviceSize" << std::endl;
        for (uint64_t i = 0; i < args.bindingCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pSizes << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pStrides" << std::endl;
    // pStrides -> Field -> ConstDynamicArray(VkDeviceSize)
    if (args.bindingCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkDeviceSize" << std::endl;
        for (uint64_t i = 0; i < args.bindingCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pStrides << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdSetDepthTestEnableArgs(
  std::ostream & os, const CmdSetDepthTestEnableArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  depthTestEnable" << std::endl;
    // depthTestEnable -> Field -> VkBool32
    os << "value: " << args.depthTestEnable << std::endl;
  }
}

void CommandPrinter::PrintCmdSetDepthWriteEnableArgs(
  std::ostream & os, const CmdSetDepthWriteEnableArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  depthWriteEnable" << std::endl;
    // depthWriteEnable -> Field -> VkBool32
    os << "value: " << args.depthWriteEnable << std::endl;
  }
}

void CommandPrinter::PrintCmdSetDepthCompareOpArgs(
  std::ostream & os, const CmdSetDepthCompareOpArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  depthCompareOp" << std::endl;
    // depthCompareOp -> Field -> VkCompareOp
    os << "value: " << args.depthCompareOp << std::endl;
  }
}

void CommandPrinter::PrintCmdSetDepthBoundsTestEnableArgs(
  std::ostream & os, const CmdSetDepthBoundsTestEnableArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  depthBoundsTestEnable" << std::endl;
    // depthBoundsTestEnable -> Field -> VkBool32
    os << "value: " << args.depthBoundsTestEnable << std::endl;
  }
}

void CommandPrinter::PrintCmdSetStencilTestEnableArgs(
  std::ostream & os, const CmdSetStencilTestEnableArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stencilTestEnable" << std::endl;
    // stencilTestEnable -> Field -> VkBool32
    os << "value: " << args.stencilTestEnable << std::endl;
  }
}

void CommandPrinter::PrintCmdSetStencilOpArgs(
  std::ostream & os, const CmdSetStencilOpArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  faceMask" << std::endl;
    // faceMask -> Field -> VkStencilFaceFlags
    os << "value: " << args.faceMask << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  failOp" << std::endl;
    // failOp -> Field -> VkStencilOp
    os << "value: " << args.failOp << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  passOp" << std::endl;
    // passOp -> Field -> VkStencilOp
    os << "value: " << args.passOp << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  depthFailOp" << std::endl;
    // depthFailOp -> Field -> VkStencilOp
    os << "value: " << args.depthFailOp << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  compareOp" << std::endl;
    // compareOp -> Field -> VkCompareOp
    os << "value: " << args.compareOp << std::endl;
  }
}

void CommandPrinter::PrintCmdSetRasterizerDiscardEnableArgs(
  std::ostream & os, const CmdSetRasterizerDiscardEnableArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  rasterizerDiscardEnable" << std::endl;
    // rasterizerDiscardEnable -> Field -> VkBool32
    os << "value: " << args.rasterizerDiscardEnable << std::endl;
  }
}

void CommandPrinter::PrintCmdSetDepthBiasEnableArgs(
  std::ostream & os, const CmdSetDepthBiasEnableArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  depthBiasEnable" << std::endl;
    // depthBiasEnable -> Field -> VkBool32
    os << "value: " << args.depthBiasEnable << std::endl;
  }
}

void CommandPrinter::PrintCmdSetPrimitiveRestartEnableArgs(
  std::ostream & os, const CmdSetPrimitiveRestartEnableArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  primitiveRestartEnable" << std::endl;
    // primitiveRestartEnable -> Field -> VkBool32
    os << "value: " << args.primitiveRestartEnable << std::endl;
  }
}

void CommandPrinter::PrintCmdBeginVideoCodingKHRArgs(
  std::ostream & os, const CmdBeginVideoCodingKHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pBeginInfo" << std::endl;
    // pointer
    if (args.pBeginInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pBeginInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdEndVideoCodingKHRArgs(
  std::ostream & os, const CmdEndVideoCodingKHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pEndCodingInfo" << std::endl;
    // pointer
    if (args.pEndCodingInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pEndCodingInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdControlVideoCodingKHRArgs(
  std::ostream & os, const CmdControlVideoCodingKHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pCodingControlInfo" << std::endl;
    // pointer
    if (args.pCodingControlInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pCodingControlInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdDecodeVideoKHRArgs(
  std::ostream & os, const CmdDecodeVideoKHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pDecodeInfo" << std::endl;
    // pointer
    if (args.pDecodeInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pDecodeInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdBeginRenderingKHRArgs(
  std::ostream & os, const CmdBeginRenderingKHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pRenderingInfo" << std::endl;
    // pointer
    if (args.pRenderingInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pRenderingInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdEndRenderingKHRArgs(
  std::ostream & os, const CmdEndRenderingKHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
}

void CommandPrinter::PrintCmdSetDeviceMaskKHRArgs(
  std::ostream & os, const CmdSetDeviceMaskKHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  deviceMask" << std::endl;
    // deviceMask -> Field -> uint32_t
    os << "value: " << args.deviceMask << std::endl;
  }
}

void CommandPrinter::PrintCmdDispatchBaseKHRArgs(
  std::ostream & os, const CmdDispatchBaseKHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  baseGroupX" << std::endl;
    // baseGroupX -> Field -> uint32_t
    os << "value: " << args.baseGroupX << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  baseGroupY" << std::endl;
    // baseGroupY -> Field -> uint32_t
    os << "value: " << args.baseGroupY << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  baseGroupZ" << std::endl;
    // baseGroupZ -> Field -> uint32_t
    os << "value: " << args.baseGroupZ << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  groupCountX" << std::endl;
    // groupCountX -> Field -> uint32_t
    os << "value: " << args.groupCountX << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  groupCountY" << std::endl;
    // groupCountY -> Field -> uint32_t
    os << "value: " << args.groupCountY << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  groupCountZ" << std::endl;
    // groupCountZ -> Field -> uint32_t
    os << "value: " << args.groupCountZ << std::endl;
  }
}

void CommandPrinter::PrintCmdPushDescriptorSetKHRArgs(
  std::ostream & os, const CmdPushDescriptorSetKHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pipelineBindPoint" << std::endl;
    // pipelineBindPoint -> Field -> VkPipelineBindPoint
    os << "value: " << args.pipelineBindPoint << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  layout" << std::endl;
    // layout -> Field -> VkPipelineLayout
    os << "value: " << args.layout << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  set" << std::endl;
    // set -> Field -> uint32_t
    os << "value: " << args.set << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  descriptorWriteCount" << std::endl;
    // descriptorWriteCount -> Field -> uint32_t
    os << "value: " << args.descriptorWriteCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pDescriptorWrites" << std::endl;
    // pDescriptorWrites -> Field -> ConstDynamicArray(VkWriteDescriptorSet)
    if (args.descriptorWriteCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkWriteDescriptorSet" << std::endl;
        for (uint64_t i = 0; i < args.descriptorWriteCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pDescriptorWrites << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdPushDescriptorSetWithTemplateKHRArgs(
  std::ostream & os, const CmdPushDescriptorSetWithTemplateKHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  descriptorUpdateTemplate" << std::endl;
    // descriptorUpdateTemplate -> Field -> VkDescriptorUpdateTemplate
    os << "value: " << args.descriptorUpdateTemplate << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  layout" << std::endl;
    // layout -> Field -> VkPipelineLayout
    os << "value: " << args.layout << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  set" << std::endl;
    // set -> Field -> uint32_t
    os << "value: " << args.set << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pData" << std::endl;
    // void
    os << "value: NOT_AVAILABLE" << std::endl;
  }
}

void CommandPrinter::PrintCmdBeginRenderPass2KHRArgs(
  std::ostream & os, const CmdBeginRenderPass2KHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pRenderPassBegin" << std::endl;
    // pointer
    if (args.pRenderPassBegin != nullptr) {
      os <<  "members:" << std::endl << *args.pRenderPassBegin << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pSubpassBeginInfo" << std::endl;
    // pointer
    if (args.pSubpassBeginInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pSubpassBeginInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdNextSubpass2KHRArgs(
  std::ostream & os, const CmdNextSubpass2KHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pSubpassBeginInfo" << std::endl;
    // pointer
    if (args.pSubpassBeginInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pSubpassBeginInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pSubpassEndInfo" << std::endl;
    // pointer
    if (args.pSubpassEndInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pSubpassEndInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdEndRenderPass2KHRArgs(
  std::ostream & os, const CmdEndRenderPass2KHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pSubpassEndInfo" << std::endl;
    // pointer
    if (args.pSubpassEndInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pSubpassEndInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdDrawIndirectCountKHRArgs(
  std::ostream & os, const CmdDrawIndirectCountKHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  buffer" << std::endl;
    // buffer -> Field -> VkBuffer
    os << "value: " << args.buffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  offset" << std::endl;
    // offset -> Field -> VkDeviceSize
    os << "value: " << args.offset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  countBuffer" << std::endl;
    // countBuffer -> Field -> VkBuffer
    os << "value: " << args.countBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  countBufferOffset" << std::endl;
    // countBufferOffset -> Field -> VkDeviceSize
    os << "value: " << args.countBufferOffset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  maxDrawCount" << std::endl;
    // maxDrawCount -> Field -> uint32_t
    os << "value: " << args.maxDrawCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stride" << std::endl;
    // stride -> Field -> uint32_t
    os << "value: " << args.stride << std::endl;
  }
}

void CommandPrinter::PrintCmdDrawIndexedIndirectCountKHRArgs(
  std::ostream & os, const CmdDrawIndexedIndirectCountKHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  buffer" << std::endl;
    // buffer -> Field -> VkBuffer
    os << "value: " << args.buffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  offset" << std::endl;
    // offset -> Field -> VkDeviceSize
    os << "value: " << args.offset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  countBuffer" << std::endl;
    // countBuffer -> Field -> VkBuffer
    os << "value: " << args.countBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  countBufferOffset" << std::endl;
    // countBufferOffset -> Field -> VkDeviceSize
    os << "value: " << args.countBufferOffset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  maxDrawCount" << std::endl;
    // maxDrawCount -> Field -> uint32_t
    os << "value: " << args.maxDrawCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stride" << std::endl;
    // stride -> Field -> uint32_t
    os << "value: " << args.stride << std::endl;
  }
}

void CommandPrinter::PrintCmdSetFragmentShadingRateKHRArgs(
  std::ostream & os, const CmdSetFragmentShadingRateKHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pFragmentSize" << std::endl;
    // pointer
    if (args.pFragmentSize != nullptr) {
      os <<  "members:" << std::endl << *args.pFragmentSize << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  combinerOps" << std::endl;
    // combinerOps -> Field -> ConstFixedArray(VkFragmentShadingRateCombinerOpKHR)
    {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkFragmentShadingRateCombinerOpKHR" << std::endl;
        for (uint64_t i = 0; i < 2; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.combinerOps << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdSetRenderingAttachmentLocationsKHRArgs(
  std::ostream & os, const CmdSetRenderingAttachmentLocationsKHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pLocationInfo" << std::endl;
    // pointer
    if (args.pLocationInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pLocationInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdSetRenderingInputAttachmentIndicesKHRArgs(
  std::ostream & os, const CmdSetRenderingInputAttachmentIndicesKHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pLocationInfo" << std::endl;
    // pointer
    if (args.pLocationInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pLocationInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdEncodeVideoKHRArgs(
  std::ostream & os, const CmdEncodeVideoKHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pEncodeInfo" << std::endl;
    // pointer
    if (args.pEncodeInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pEncodeInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdSetEvent2KHRArgs(
  std::ostream & os, const CmdSetEvent2KHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  event" << std::endl;
    // event -> Field -> VkEvent
    os << "value: " << args.event << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pDependencyInfo" << std::endl;
    // pointer
    if (args.pDependencyInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pDependencyInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdResetEvent2KHRArgs(
  std::ostream & os, const CmdResetEvent2KHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  event" << std::endl;
    // event -> Field -> VkEvent
    os << "value: " << args.event << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stageMask" << std::endl;
    // stageMask -> Field -> VkPipelineStageFlags2
    os << "value: " << args.stageMask << std::endl;
  }
}

void CommandPrinter::PrintCmdWaitEvents2KHRArgs(
  std::ostream & os, const CmdWaitEvents2KHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  eventCount" << std::endl;
    // eventCount -> Field -> uint32_t
    os << "value: " << args.eventCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pEvents" << std::endl;
    // pEvents -> Field -> ConstDynamicArray(VkEvent)
    if (args.eventCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkEvent" << std::endl;
        for (uint64_t i = 0; i < args.eventCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pEvents << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pDependencyInfos" << std::endl;
    // pDependencyInfos -> Field -> ConstDynamicArray(VkDependencyInfo)
    if (args.eventCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkDependencyInfo" << std::endl;
        for (uint64_t i = 0; i < args.eventCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pDependencyInfos << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdPipelineBarrier2KHRArgs(
  std::ostream & os, const CmdPipelineBarrier2KHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pDependencyInfo" << std::endl;
    // pointer
    if (args.pDependencyInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pDependencyInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdWriteTimestamp2KHRArgs(
  std::ostream & os, const CmdWriteTimestamp2KHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stage" << std::endl;
    // stage -> Field -> VkPipelineStageFlags2
    os << "value: " << args.stage << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  queryPool" << std::endl;
    // queryPool -> Field -> VkQueryPool
    os << "value: " << args.queryPool << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  query" << std::endl;
    // query -> Field -> uint32_t
    os << "value: " << args.query << std::endl;
  }
}

void CommandPrinter::PrintCmdWriteBufferMarker2AMDArgs(
  std::ostream & os, const CmdWriteBufferMarker2AMDArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stage" << std::endl;
    // stage -> Field -> VkPipelineStageFlags2
    os << "value: " << args.stage << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dstBuffer" << std::endl;
    // dstBuffer -> Field -> VkBuffer
    os << "value: " << args.dstBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dstOffset" << std::endl;
    // dstOffset -> Field -> VkDeviceSize
    os << "value: " << args.dstOffset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  marker" << std::endl;
    // marker -> Field -> uint32_t
    os << "value: " << args.marker << std::endl;
  }
}

void CommandPrinter::PrintCmdCopyBuffer2KHRArgs(
  std::ostream & os, const CmdCopyBuffer2KHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pCopyBufferInfo" << std::endl;
    // pointer
    if (args.pCopyBufferInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pCopyBufferInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdCopyImage2KHRArgs(
  std::ostream & os, const CmdCopyImage2KHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pCopyImageInfo" << std::endl;
    // pointer
    if (args.pCopyImageInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pCopyImageInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdCopyBufferToImage2KHRArgs(
  std::ostream & os, const CmdCopyBufferToImage2KHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pCopyBufferToImageInfo" << std::endl;
    // pointer
    if (args.pCopyBufferToImageInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pCopyBufferToImageInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdCopyImageToBuffer2KHRArgs(
  std::ostream & os, const CmdCopyImageToBuffer2KHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pCopyImageToBufferInfo" << std::endl;
    // pointer
    if (args.pCopyImageToBufferInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pCopyImageToBufferInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdBlitImage2KHRArgs(
  std::ostream & os, const CmdBlitImage2KHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pBlitImageInfo" << std::endl;
    // pointer
    if (args.pBlitImageInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pBlitImageInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdResolveImage2KHRArgs(
  std::ostream & os, const CmdResolveImage2KHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pResolveImageInfo" << std::endl;
    // pointer
    if (args.pResolveImageInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pResolveImageInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdTraceRaysIndirect2KHRArgs(
  std::ostream & os, const CmdTraceRaysIndirect2KHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  indirectDeviceAddress" << std::endl;
    // indirectDeviceAddress -> Field -> VkDeviceAddress
    os << "value: " << args.indirectDeviceAddress << std::endl;
  }
}

void CommandPrinter::PrintCmdBindIndexBuffer2KHRArgs(
  std::ostream & os, const CmdBindIndexBuffer2KHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  buffer" << std::endl;
    // buffer -> Field -> VkBuffer
    os << "value: " << args.buffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  offset" << std::endl;
    // offset -> Field -> VkDeviceSize
    os << "value: " << args.offset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  size" << std::endl;
    // size -> Field -> VkDeviceSize
    os << "value: " << args.size << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  indexType" << std::endl;
    // indexType -> Field -> VkIndexType
    os << "value: " << args.indexType << std::endl;
  }
}

void CommandPrinter::PrintCmdSetLineStippleKHRArgs(
  std::ostream & os, const CmdSetLineStippleKHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  lineStippleFactor" << std::endl;
    // lineStippleFactor -> Field -> uint32_t
    os << "value: " << args.lineStippleFactor << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  lineStipplePattern" << std::endl;
    // lineStipplePattern -> Field -> uint16_t
    os << "value: " << args.lineStipplePattern << std::endl;
  }
}

void CommandPrinter::PrintCmdBindDescriptorSets2KHRArgs(
  std::ostream & os, const CmdBindDescriptorSets2KHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pBindDescriptorSetsInfo" << std::endl;
    // pointer
    if (args.pBindDescriptorSetsInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pBindDescriptorSetsInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdPushConstants2KHRArgs(
  std::ostream & os, const CmdPushConstants2KHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pPushConstantsInfo" << std::endl;
    // pointer
    if (args.pPushConstantsInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pPushConstantsInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdPushDescriptorSet2KHRArgs(
  std::ostream & os, const CmdPushDescriptorSet2KHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pPushDescriptorSetInfo" << std::endl;
    // pointer
    if (args.pPushDescriptorSetInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pPushDescriptorSetInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdPushDescriptorSetWithTemplate2KHRArgs(
  std::ostream & os, const CmdPushDescriptorSetWithTemplate2KHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pPushDescriptorSetWithTemplateInfo" << std::endl;
    // pointer
    if (args.pPushDescriptorSetWithTemplateInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pPushDescriptorSetWithTemplateInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdSetDescriptorBufferOffsets2EXTArgs(
  std::ostream & os, const CmdSetDescriptorBufferOffsets2EXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pSetDescriptorBufferOffsetsInfo" << std::endl;
    // pointer
    if (args.pSetDescriptorBufferOffsetsInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pSetDescriptorBufferOffsetsInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdBindDescriptorBufferEmbeddedSamplers2EXTArgs(
  std::ostream & os, const CmdBindDescriptorBufferEmbeddedSamplers2EXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pBindDescriptorBufferEmbeddedSamplersInfo" << std::endl;
    // pointer
    if (args.pBindDescriptorBufferEmbeddedSamplersInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pBindDescriptorBufferEmbeddedSamplersInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdDebugMarkerBeginEXTArgs(
  std::ostream & os, const CmdDebugMarkerBeginEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pMarkerInfo" << std::endl;
    // pointer
    if (args.pMarkerInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pMarkerInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdDebugMarkerEndEXTArgs(
  std::ostream & os, const CmdDebugMarkerEndEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
}

void CommandPrinter::PrintCmdDebugMarkerInsertEXTArgs(
  std::ostream & os, const CmdDebugMarkerInsertEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pMarkerInfo" << std::endl;
    // pointer
    if (args.pMarkerInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pMarkerInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdBindTransformFeedbackBuffersEXTArgs(
  std::ostream & os, const CmdBindTransformFeedbackBuffersEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstBinding" << std::endl;
    // firstBinding -> Field -> uint32_t
    os << "value: " << args.firstBinding << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  bindingCount" << std::endl;
    // bindingCount -> Field -> uint32_t
    os << "value: " << args.bindingCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pBuffers" << std::endl;
    // pBuffers -> Field -> ConstDynamicArray(VkBuffer)
    if (args.bindingCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkBuffer" << std::endl;
        for (uint64_t i = 0; i < args.bindingCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pBuffers << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pOffsets" << std::endl;
    // pOffsets -> Field -> ConstDynamicArray(VkDeviceSize)
    if (args.bindingCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkDeviceSize" << std::endl;
        for (uint64_t i = 0; i < args.bindingCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pOffsets << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pSizes" << std::endl;
    // pSizes -> Field -> ConstDynamicArray(VkDeviceSize)
    if (args.bindingCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkDeviceSize" << std::endl;
        for (uint64_t i = 0; i < args.bindingCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pSizes << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdBeginTransformFeedbackEXTArgs(
  std::ostream & os, const CmdBeginTransformFeedbackEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstCounterBuffer" << std::endl;
    // firstCounterBuffer -> Field -> uint32_t
    os << "value: " << args.firstCounterBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  counterBufferCount" << std::endl;
    // counterBufferCount -> Field -> uint32_t
    os << "value: " << args.counterBufferCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pCounterBuffers" << std::endl;
    // pCounterBuffers -> Field -> ConstDynamicArray(VkBuffer)
    if (args.counterBufferCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkBuffer" << std::endl;
        for (uint64_t i = 0; i < args.counterBufferCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pCounterBuffers << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pCounterBufferOffsets" << std::endl;
    // pCounterBufferOffsets -> Field -> ConstDynamicArray(VkDeviceSize)
    if (args.counterBufferCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkDeviceSize" << std::endl;
        for (uint64_t i = 0; i < args.counterBufferCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pCounterBufferOffsets << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdEndTransformFeedbackEXTArgs(
  std::ostream & os, const CmdEndTransformFeedbackEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstCounterBuffer" << std::endl;
    // firstCounterBuffer -> Field -> uint32_t
    os << "value: " << args.firstCounterBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  counterBufferCount" << std::endl;
    // counterBufferCount -> Field -> uint32_t
    os << "value: " << args.counterBufferCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pCounterBuffers" << std::endl;
    // pCounterBuffers -> Field -> ConstDynamicArray(VkBuffer)
    if (args.counterBufferCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkBuffer" << std::endl;
        for (uint64_t i = 0; i < args.counterBufferCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pCounterBuffers << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pCounterBufferOffsets" << std::endl;
    // pCounterBufferOffsets -> Field -> ConstDynamicArray(VkDeviceSize)
    if (args.counterBufferCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkDeviceSize" << std::endl;
        for (uint64_t i = 0; i < args.counterBufferCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pCounterBufferOffsets << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdBeginQueryIndexedEXTArgs(
  std::ostream & os, const CmdBeginQueryIndexedEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  queryPool" << std::endl;
    // queryPool -> Field -> VkQueryPool
    os << "value: " << args.queryPool << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  query" << std::endl;
    // query -> Field -> uint32_t
    os << "value: " << args.query << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  flags" << std::endl;
    // flags -> Field -> VkQueryControlFlags
    os << "value: " << args.flags << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  index" << std::endl;
    // index -> Field -> uint32_t
    os << "value: " << args.index << std::endl;
  }
}

void CommandPrinter::PrintCmdEndQueryIndexedEXTArgs(
  std::ostream & os, const CmdEndQueryIndexedEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  queryPool" << std::endl;
    // queryPool -> Field -> VkQueryPool
    os << "value: " << args.queryPool << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  query" << std::endl;
    // query -> Field -> uint32_t
    os << "value: " << args.query << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  index" << std::endl;
    // index -> Field -> uint32_t
    os << "value: " << args.index << std::endl;
  }
}

void CommandPrinter::PrintCmdDrawIndirectByteCountEXTArgs(
  std::ostream & os, const CmdDrawIndirectByteCountEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  instanceCount" << std::endl;
    // instanceCount -> Field -> uint32_t
    os << "value: " << args.instanceCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstInstance" << std::endl;
    // firstInstance -> Field -> uint32_t
    os << "value: " << args.firstInstance << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  counterBuffer" << std::endl;
    // counterBuffer -> Field -> VkBuffer
    os << "value: " << args.counterBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  counterBufferOffset" << std::endl;
    // counterBufferOffset -> Field -> VkDeviceSize
    os << "value: " << args.counterBufferOffset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  counterOffset" << std::endl;
    // counterOffset -> Field -> uint32_t
    os << "value: " << args.counterOffset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  vertexStride" << std::endl;
    // vertexStride -> Field -> uint32_t
    os << "value: " << args.vertexStride << std::endl;
  }
}

void CommandPrinter::PrintCmdCuLaunchKernelNVXArgs(
  std::ostream & os, const CmdCuLaunchKernelNVXArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pLaunchInfo" << std::endl;
    // pointer
    if (args.pLaunchInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pLaunchInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdDrawIndirectCountAMDArgs(
  std::ostream & os, const CmdDrawIndirectCountAMDArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  buffer" << std::endl;
    // buffer -> Field -> VkBuffer
    os << "value: " << args.buffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  offset" << std::endl;
    // offset -> Field -> VkDeviceSize
    os << "value: " << args.offset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  countBuffer" << std::endl;
    // countBuffer -> Field -> VkBuffer
    os << "value: " << args.countBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  countBufferOffset" << std::endl;
    // countBufferOffset -> Field -> VkDeviceSize
    os << "value: " << args.countBufferOffset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  maxDrawCount" << std::endl;
    // maxDrawCount -> Field -> uint32_t
    os << "value: " << args.maxDrawCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stride" << std::endl;
    // stride -> Field -> uint32_t
    os << "value: " << args.stride << std::endl;
  }
}

void CommandPrinter::PrintCmdDrawIndexedIndirectCountAMDArgs(
  std::ostream & os, const CmdDrawIndexedIndirectCountAMDArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  buffer" << std::endl;
    // buffer -> Field -> VkBuffer
    os << "value: " << args.buffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  offset" << std::endl;
    // offset -> Field -> VkDeviceSize
    os << "value: " << args.offset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  countBuffer" << std::endl;
    // countBuffer -> Field -> VkBuffer
    os << "value: " << args.countBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  countBufferOffset" << std::endl;
    // countBufferOffset -> Field -> VkDeviceSize
    os << "value: " << args.countBufferOffset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  maxDrawCount" << std::endl;
    // maxDrawCount -> Field -> uint32_t
    os << "value: " << args.maxDrawCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stride" << std::endl;
    // stride -> Field -> uint32_t
    os << "value: " << args.stride << std::endl;
  }
}

void CommandPrinter::PrintCmdBeginConditionalRenderingEXTArgs(
  std::ostream & os, const CmdBeginConditionalRenderingEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pConditionalRenderingBegin" << std::endl;
    // pointer
    if (args.pConditionalRenderingBegin != nullptr) {
      os <<  "members:" << std::endl << *args.pConditionalRenderingBegin << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdEndConditionalRenderingEXTArgs(
  std::ostream & os, const CmdEndConditionalRenderingEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
}

void CommandPrinter::PrintCmdSetViewportWScalingNVArgs(
  std::ostream & os, const CmdSetViewportWScalingNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstViewport" << std::endl;
    // firstViewport -> Field -> uint32_t
    os << "value: " << args.firstViewport << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  viewportCount" << std::endl;
    // viewportCount -> Field -> uint32_t
    os << "value: " << args.viewportCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pViewportWScalings" << std::endl;
    // pViewportWScalings -> Field -> ConstDynamicArray(VkViewportWScalingNV)
    if (args.viewportCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkViewportWScalingNV" << std::endl;
        for (uint64_t i = 0; i < args.viewportCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pViewportWScalings << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdSetDiscardRectangleEXTArgs(
  std::ostream & os, const CmdSetDiscardRectangleEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstDiscardRectangle" << std::endl;
    // firstDiscardRectangle -> Field -> uint32_t
    os << "value: " << args.firstDiscardRectangle << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  discardRectangleCount" << std::endl;
    // discardRectangleCount -> Field -> uint32_t
    os << "value: " << args.discardRectangleCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pDiscardRectangles" << std::endl;
    // pDiscardRectangles -> Field -> ConstDynamicArray(VkRect2D)
    if (args.discardRectangleCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkRect2D" << std::endl;
        for (uint64_t i = 0; i < args.discardRectangleCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pDiscardRectangles << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdSetDiscardRectangleEnableEXTArgs(
  std::ostream & os, const CmdSetDiscardRectangleEnableEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  discardRectangleEnable" << std::endl;
    // discardRectangleEnable -> Field -> VkBool32
    os << "value: " << args.discardRectangleEnable << std::endl;
  }
}

void CommandPrinter::PrintCmdSetDiscardRectangleModeEXTArgs(
  std::ostream & os, const CmdSetDiscardRectangleModeEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  discardRectangleMode" << std::endl;
    // discardRectangleMode -> Field -> VkDiscardRectangleModeEXT
    os << "value: " << args.discardRectangleMode << std::endl;
  }
}

void CommandPrinter::PrintCmdBeginDebugUtilsLabelEXTArgs(
  std::ostream & os, const CmdBeginDebugUtilsLabelEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pLabelInfo" << std::endl;
    // pointer
    if (args.pLabelInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pLabelInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdEndDebugUtilsLabelEXTArgs(
  std::ostream & os, const CmdEndDebugUtilsLabelEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
}

void CommandPrinter::PrintCmdInsertDebugUtilsLabelEXTArgs(
  std::ostream & os, const CmdInsertDebugUtilsLabelEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pLabelInfo" << std::endl;
    // pointer
    if (args.pLabelInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pLabelInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

#ifdef VK_ENABLE_BETA_EXTENSIONS
void CommandPrinter::PrintCmdInitializeGraphScratchMemoryAMDXArgs(
  std::ostream & os, const CmdInitializeGraphScratchMemoryAMDXArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  scratch" << std::endl;
    // scratch -> Field -> VkDeviceAddress
    os << "value: " << args.scratch << std::endl;
  }
}
#endif //VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void CommandPrinter::PrintCmdDispatchGraphAMDXArgs(
  std::ostream & os, const CmdDispatchGraphAMDXArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  scratch" << std::endl;
    // scratch -> Field -> VkDeviceAddress
    os << "value: " << args.scratch << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pCountInfo" << std::endl;
    // pointer
    if (args.pCountInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pCountInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}
#endif //VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void CommandPrinter::PrintCmdDispatchGraphIndirectAMDXArgs(
  std::ostream & os, const CmdDispatchGraphIndirectAMDXArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  scratch" << std::endl;
    // scratch -> Field -> VkDeviceAddress
    os << "value: " << args.scratch << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pCountInfo" << std::endl;
    // pointer
    if (args.pCountInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pCountInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}
#endif //VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void CommandPrinter::PrintCmdDispatchGraphIndirectCountAMDXArgs(
  std::ostream & os, const CmdDispatchGraphIndirectCountAMDXArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  scratch" << std::endl;
    // scratch -> Field -> VkDeviceAddress
    os << "value: " << args.scratch << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  countInfo" << std::endl;
    // countInfo -> Field -> VkDeviceAddress
    os << "value: " << args.countInfo << std::endl;
  }
}
#endif //VK_ENABLE_BETA_EXTENSIONS

void CommandPrinter::PrintCmdSetSampleLocationsEXTArgs(
  std::ostream & os, const CmdSetSampleLocationsEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pSampleLocationsInfo" << std::endl;
    // pointer
    if (args.pSampleLocationsInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pSampleLocationsInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdBindShadingRateImageNVArgs(
  std::ostream & os, const CmdBindShadingRateImageNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  imageView" << std::endl;
    // imageView -> Field -> VkImageView
    os << "value: " << args.imageView << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  imageLayout" << std::endl;
    // imageLayout -> Field -> VkImageLayout
    os << "value: " << args.imageLayout << std::endl;
  }
}

void CommandPrinter::PrintCmdSetViewportShadingRatePaletteNVArgs(
  std::ostream & os, const CmdSetViewportShadingRatePaletteNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstViewport" << std::endl;
    // firstViewport -> Field -> uint32_t
    os << "value: " << args.firstViewport << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  viewportCount" << std::endl;
    // viewportCount -> Field -> uint32_t
    os << "value: " << args.viewportCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pShadingRatePalettes" << std::endl;
    // pShadingRatePalettes -> Field -> ConstDynamicArray(VkShadingRatePaletteNV)
    if (args.viewportCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkShadingRatePaletteNV" << std::endl;
        for (uint64_t i = 0; i < args.viewportCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pShadingRatePalettes << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdSetCoarseSampleOrderNVArgs(
  std::ostream & os, const CmdSetCoarseSampleOrderNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  sampleOrderType" << std::endl;
    // sampleOrderType -> Field -> VkCoarseSampleOrderTypeNV
    os << "value: " << args.sampleOrderType << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  customSampleOrderCount" << std::endl;
    // customSampleOrderCount -> Field -> uint32_t
    os << "value: " << args.customSampleOrderCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pCustomSampleOrders" << std::endl;
    // pCustomSampleOrders -> Field -> ConstDynamicArray(VkCoarseSampleOrderCustomNV)
    if (args.customSampleOrderCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkCoarseSampleOrderCustomNV" << std::endl;
        for (uint64_t i = 0; i < args.customSampleOrderCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pCustomSampleOrders << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdBuildAccelerationStructureNVArgs(
  std::ostream & os, const CmdBuildAccelerationStructureNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pInfo" << std::endl;
    // pointer
    if (args.pInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  instanceData" << std::endl;
    // instanceData -> Field -> VkBuffer
    os << "value: " << args.instanceData << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  instanceOffset" << std::endl;
    // instanceOffset -> Field -> VkDeviceSize
    os << "value: " << args.instanceOffset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  update" << std::endl;
    // update -> Field -> VkBool32
    os << "value: " << args.update << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dst" << std::endl;
    // dst -> Field -> VkAccelerationStructureNV
    os << "value: " << args.dst << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  src" << std::endl;
    // src -> Field -> VkAccelerationStructureNV
    os << "value: " << args.src << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  scratch" << std::endl;
    // scratch -> Field -> VkBuffer
    os << "value: " << args.scratch << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  scratchOffset" << std::endl;
    // scratchOffset -> Field -> VkDeviceSize
    os << "value: " << args.scratchOffset << std::endl;
  }
}

void CommandPrinter::PrintCmdCopyAccelerationStructureNVArgs(
  std::ostream & os, const CmdCopyAccelerationStructureNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dst" << std::endl;
    // dst -> Field -> VkAccelerationStructureNV
    os << "value: " << args.dst << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  src" << std::endl;
    // src -> Field -> VkAccelerationStructureNV
    os << "value: " << args.src << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  mode" << std::endl;
    // mode -> Field -> VkCopyAccelerationStructureModeKHR
    os << "value: " << args.mode << std::endl;
  }
}

void CommandPrinter::PrintCmdTraceRaysNVArgs(
  std::ostream & os, const CmdTraceRaysNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  raygenShaderBindingTableBuffer" << std::endl;
    // raygenShaderBindingTableBuffer -> Field -> VkBuffer
    os << "value: " << args.raygenShaderBindingTableBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  raygenShaderBindingOffset" << std::endl;
    // raygenShaderBindingOffset -> Field -> VkDeviceSize
    os << "value: " << args.raygenShaderBindingOffset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  missShaderBindingTableBuffer" << std::endl;
    // missShaderBindingTableBuffer -> Field -> VkBuffer
    os << "value: " << args.missShaderBindingTableBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  missShaderBindingOffset" << std::endl;
    // missShaderBindingOffset -> Field -> VkDeviceSize
    os << "value: " << args.missShaderBindingOffset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  missShaderBindingStride" << std::endl;
    // missShaderBindingStride -> Field -> VkDeviceSize
    os << "value: " << args.missShaderBindingStride << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  hitShaderBindingTableBuffer" << std::endl;
    // hitShaderBindingTableBuffer -> Field -> VkBuffer
    os << "value: " << args.hitShaderBindingTableBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  hitShaderBindingOffset" << std::endl;
    // hitShaderBindingOffset -> Field -> VkDeviceSize
    os << "value: " << args.hitShaderBindingOffset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  hitShaderBindingStride" << std::endl;
    // hitShaderBindingStride -> Field -> VkDeviceSize
    os << "value: " << args.hitShaderBindingStride << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  callableShaderBindingTableBuffer" << std::endl;
    // callableShaderBindingTableBuffer -> Field -> VkBuffer
    os << "value: " << args.callableShaderBindingTableBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  callableShaderBindingOffset" << std::endl;
    // callableShaderBindingOffset -> Field -> VkDeviceSize
    os << "value: " << args.callableShaderBindingOffset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  callableShaderBindingStride" << std::endl;
    // callableShaderBindingStride -> Field -> VkDeviceSize
    os << "value: " << args.callableShaderBindingStride << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  width" << std::endl;
    // width -> Field -> uint32_t
    os << "value: " << args.width << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  height" << std::endl;
    // height -> Field -> uint32_t
    os << "value: " << args.height << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  depth" << std::endl;
    // depth -> Field -> uint32_t
    os << "value: " << args.depth << std::endl;
  }
}

void CommandPrinter::PrintCmdWriteAccelerationStructuresPropertiesNVArgs(
  std::ostream & os, const CmdWriteAccelerationStructuresPropertiesNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  accelerationStructureCount" << std::endl;
    // accelerationStructureCount -> Field -> uint32_t
    os << "value: " << args.accelerationStructureCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pAccelerationStructures" << std::endl;
    // pAccelerationStructures -> Field -> ConstDynamicArray(VkAccelerationStructureNV)
    if (args.accelerationStructureCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkAccelerationStructureNV" << std::endl;
        for (uint64_t i = 0; i < args.accelerationStructureCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pAccelerationStructures << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  queryType" << std::endl;
    // queryType -> Field -> VkQueryType
    os << "value: " << args.queryType << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  queryPool" << std::endl;
    // queryPool -> Field -> VkQueryPool
    os << "value: " << args.queryPool << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstQuery" << std::endl;
    // firstQuery -> Field -> uint32_t
    os << "value: " << args.firstQuery << std::endl;
  }
}

void CommandPrinter::PrintCmdWriteBufferMarkerAMDArgs(
  std::ostream & os, const CmdWriteBufferMarkerAMDArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pipelineStage" << std::endl;
    // pipelineStage -> Field -> VkPipelineStageFlagBits
    os << "value: " << args.pipelineStage << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dstBuffer" << std::endl;
    // dstBuffer -> Field -> VkBuffer
    os << "value: " << args.dstBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dstOffset" << std::endl;
    // dstOffset -> Field -> VkDeviceSize
    os << "value: " << args.dstOffset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  marker" << std::endl;
    // marker -> Field -> uint32_t
    os << "value: " << args.marker << std::endl;
  }
}

void CommandPrinter::PrintCmdDrawMeshTasksNVArgs(
  std::ostream & os, const CmdDrawMeshTasksNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  taskCount" << std::endl;
    // taskCount -> Field -> uint32_t
    os << "value: " << args.taskCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstTask" << std::endl;
    // firstTask -> Field -> uint32_t
    os << "value: " << args.firstTask << std::endl;
  }
}

void CommandPrinter::PrintCmdDrawMeshTasksIndirectNVArgs(
  std::ostream & os, const CmdDrawMeshTasksIndirectNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  buffer" << std::endl;
    // buffer -> Field -> VkBuffer
    os << "value: " << args.buffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  offset" << std::endl;
    // offset -> Field -> VkDeviceSize
    os << "value: " << args.offset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  drawCount" << std::endl;
    // drawCount -> Field -> uint32_t
    os << "value: " << args.drawCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stride" << std::endl;
    // stride -> Field -> uint32_t
    os << "value: " << args.stride << std::endl;
  }
}

void CommandPrinter::PrintCmdDrawMeshTasksIndirectCountNVArgs(
  std::ostream & os, const CmdDrawMeshTasksIndirectCountNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  buffer" << std::endl;
    // buffer -> Field -> VkBuffer
    os << "value: " << args.buffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  offset" << std::endl;
    // offset -> Field -> VkDeviceSize
    os << "value: " << args.offset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  countBuffer" << std::endl;
    // countBuffer -> Field -> VkBuffer
    os << "value: " << args.countBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  countBufferOffset" << std::endl;
    // countBufferOffset -> Field -> VkDeviceSize
    os << "value: " << args.countBufferOffset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  maxDrawCount" << std::endl;
    // maxDrawCount -> Field -> uint32_t
    os << "value: " << args.maxDrawCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stride" << std::endl;
    // stride -> Field -> uint32_t
    os << "value: " << args.stride << std::endl;
  }
}

void CommandPrinter::PrintCmdSetExclusiveScissorEnableNVArgs(
  std::ostream & os, const CmdSetExclusiveScissorEnableNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstExclusiveScissor" << std::endl;
    // firstExclusiveScissor -> Field -> uint32_t
    os << "value: " << args.firstExclusiveScissor << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  exclusiveScissorCount" << std::endl;
    // exclusiveScissorCount -> Field -> uint32_t
    os << "value: " << args.exclusiveScissorCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pExclusiveScissorEnables" << std::endl;
    // pExclusiveScissorEnables -> Field -> ConstDynamicArray(VkBool32)
    if (args.exclusiveScissorCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkBool32" << std::endl;
        for (uint64_t i = 0; i < args.exclusiveScissorCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pExclusiveScissorEnables << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdSetExclusiveScissorNVArgs(
  std::ostream & os, const CmdSetExclusiveScissorNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstExclusiveScissor" << std::endl;
    // firstExclusiveScissor -> Field -> uint32_t
    os << "value: " << args.firstExclusiveScissor << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  exclusiveScissorCount" << std::endl;
    // exclusiveScissorCount -> Field -> uint32_t
    os << "value: " << args.exclusiveScissorCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pExclusiveScissors" << std::endl;
    // pExclusiveScissors -> Field -> ConstDynamicArray(VkRect2D)
    if (args.exclusiveScissorCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkRect2D" << std::endl;
        for (uint64_t i = 0; i < args.exclusiveScissorCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pExclusiveScissors << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdSetCheckpointNVArgs(
  std::ostream & os, const CmdSetCheckpointNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pCheckpointMarker" << std::endl;
    // void
    os << "value: NOT_AVAILABLE" << std::endl;
  }
}

void CommandPrinter::PrintCmdSetPerformanceMarkerINTELArgs(
  std::ostream & os, const CmdSetPerformanceMarkerINTELArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pMarkerInfo" << std::endl;
    // pointer
    if (args.pMarkerInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pMarkerInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdSetPerformanceStreamMarkerINTELArgs(
  std::ostream & os, const CmdSetPerformanceStreamMarkerINTELArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pMarkerInfo" << std::endl;
    // pointer
    if (args.pMarkerInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pMarkerInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdSetPerformanceOverrideINTELArgs(
  std::ostream & os, const CmdSetPerformanceOverrideINTELArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pOverrideInfo" << std::endl;
    // pointer
    if (args.pOverrideInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pOverrideInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdSetLineStippleEXTArgs(
  std::ostream & os, const CmdSetLineStippleEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  lineStippleFactor" << std::endl;
    // lineStippleFactor -> Field -> uint32_t
    os << "value: " << args.lineStippleFactor << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  lineStipplePattern" << std::endl;
    // lineStipplePattern -> Field -> uint16_t
    os << "value: " << args.lineStipplePattern << std::endl;
  }
}

void CommandPrinter::PrintCmdSetCullModeEXTArgs(
  std::ostream & os, const CmdSetCullModeEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  cullMode" << std::endl;
    // cullMode -> Field -> VkCullModeFlags
    os << "value: " << args.cullMode << std::endl;
  }
}

void CommandPrinter::PrintCmdSetFrontFaceEXTArgs(
  std::ostream & os, const CmdSetFrontFaceEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  frontFace" << std::endl;
    // frontFace -> Field -> VkFrontFace
    os << "value: " << args.frontFace << std::endl;
  }
}

void CommandPrinter::PrintCmdSetPrimitiveTopologyEXTArgs(
  std::ostream & os, const CmdSetPrimitiveTopologyEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  primitiveTopology" << std::endl;
    // primitiveTopology -> Field -> VkPrimitiveTopology
    os << "value: " << args.primitiveTopology << std::endl;
  }
}

void CommandPrinter::PrintCmdSetViewportWithCountEXTArgs(
  std::ostream & os, const CmdSetViewportWithCountEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  viewportCount" << std::endl;
    // viewportCount -> Field -> uint32_t
    os << "value: " << args.viewportCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pViewports" << std::endl;
    // pViewports -> Field -> ConstDynamicArray(VkViewport)
    if (args.viewportCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkViewport" << std::endl;
        for (uint64_t i = 0; i < args.viewportCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pViewports << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdSetScissorWithCountEXTArgs(
  std::ostream & os, const CmdSetScissorWithCountEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  scissorCount" << std::endl;
    // scissorCount -> Field -> uint32_t
    os << "value: " << args.scissorCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pScissors" << std::endl;
    // pScissors -> Field -> ConstDynamicArray(VkRect2D)
    if (args.scissorCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkRect2D" << std::endl;
        for (uint64_t i = 0; i < args.scissorCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pScissors << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdBindVertexBuffers2EXTArgs(
  std::ostream & os, const CmdBindVertexBuffers2EXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstBinding" << std::endl;
    // firstBinding -> Field -> uint32_t
    os << "value: " << args.firstBinding << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  bindingCount" << std::endl;
    // bindingCount -> Field -> uint32_t
    os << "value: " << args.bindingCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pBuffers" << std::endl;
    // pBuffers -> Field -> ConstDynamicArray(VkBuffer)
    if (args.bindingCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkBuffer" << std::endl;
        for (uint64_t i = 0; i < args.bindingCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pBuffers << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pOffsets" << std::endl;
    // pOffsets -> Field -> ConstDynamicArray(VkDeviceSize)
    if (args.bindingCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkDeviceSize" << std::endl;
        for (uint64_t i = 0; i < args.bindingCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pOffsets << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pSizes" << std::endl;
    // pSizes -> Field -> ConstDynamicArray(VkDeviceSize)
    if (args.bindingCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkDeviceSize" << std::endl;
        for (uint64_t i = 0; i < args.bindingCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pSizes << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pStrides" << std::endl;
    // pStrides -> Field -> ConstDynamicArray(VkDeviceSize)
    if (args.bindingCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkDeviceSize" << std::endl;
        for (uint64_t i = 0; i < args.bindingCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pStrides << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdSetDepthTestEnableEXTArgs(
  std::ostream & os, const CmdSetDepthTestEnableEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  depthTestEnable" << std::endl;
    // depthTestEnable -> Field -> VkBool32
    os << "value: " << args.depthTestEnable << std::endl;
  }
}

void CommandPrinter::PrintCmdSetDepthWriteEnableEXTArgs(
  std::ostream & os, const CmdSetDepthWriteEnableEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  depthWriteEnable" << std::endl;
    // depthWriteEnable -> Field -> VkBool32
    os << "value: " << args.depthWriteEnable << std::endl;
  }
}

void CommandPrinter::PrintCmdSetDepthCompareOpEXTArgs(
  std::ostream & os, const CmdSetDepthCompareOpEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  depthCompareOp" << std::endl;
    // depthCompareOp -> Field -> VkCompareOp
    os << "value: " << args.depthCompareOp << std::endl;
  }
}

void CommandPrinter::PrintCmdSetDepthBoundsTestEnableEXTArgs(
  std::ostream & os, const CmdSetDepthBoundsTestEnableEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  depthBoundsTestEnable" << std::endl;
    // depthBoundsTestEnable -> Field -> VkBool32
    os << "value: " << args.depthBoundsTestEnable << std::endl;
  }
}

void CommandPrinter::PrintCmdSetStencilTestEnableEXTArgs(
  std::ostream & os, const CmdSetStencilTestEnableEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stencilTestEnable" << std::endl;
    // stencilTestEnable -> Field -> VkBool32
    os << "value: " << args.stencilTestEnable << std::endl;
  }
}

void CommandPrinter::PrintCmdSetStencilOpEXTArgs(
  std::ostream & os, const CmdSetStencilOpEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  faceMask" << std::endl;
    // faceMask -> Field -> VkStencilFaceFlags
    os << "value: " << args.faceMask << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  failOp" << std::endl;
    // failOp -> Field -> VkStencilOp
    os << "value: " << args.failOp << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  passOp" << std::endl;
    // passOp -> Field -> VkStencilOp
    os << "value: " << args.passOp << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  depthFailOp" << std::endl;
    // depthFailOp -> Field -> VkStencilOp
    os << "value: " << args.depthFailOp << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  compareOp" << std::endl;
    // compareOp -> Field -> VkCompareOp
    os << "value: " << args.compareOp << std::endl;
  }
}

void CommandPrinter::PrintCmdPreprocessGeneratedCommandsNVArgs(
  std::ostream & os, const CmdPreprocessGeneratedCommandsNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pGeneratedCommandsInfo" << std::endl;
    // pointer
    if (args.pGeneratedCommandsInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pGeneratedCommandsInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdExecuteGeneratedCommandsNVArgs(
  std::ostream & os, const CmdExecuteGeneratedCommandsNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  isPreprocessed" << std::endl;
    // isPreprocessed -> Field -> VkBool32
    os << "value: " << args.isPreprocessed << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pGeneratedCommandsInfo" << std::endl;
    // pointer
    if (args.pGeneratedCommandsInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pGeneratedCommandsInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdBindPipelineShaderGroupNVArgs(
  std::ostream & os, const CmdBindPipelineShaderGroupNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pipelineBindPoint" << std::endl;
    // pipelineBindPoint -> Field -> VkPipelineBindPoint
    os << "value: " << args.pipelineBindPoint << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pipeline" << std::endl;
    // pipeline -> Field -> VkPipeline
    os << "value: " << args.pipeline << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  groupIndex" << std::endl;
    // groupIndex -> Field -> uint32_t
    os << "value: " << args.groupIndex << std::endl;
  }
}

void CommandPrinter::PrintCmdSetDepthBias2EXTArgs(
  std::ostream & os, const CmdSetDepthBias2EXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pDepthBiasInfo" << std::endl;
    // pointer
    if (args.pDepthBiasInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pDepthBiasInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdCudaLaunchKernelNVArgs(
  std::ostream & os, const CmdCudaLaunchKernelNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pLaunchInfo" << std::endl;
    // pointer
    if (args.pLaunchInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pLaunchInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdBindDescriptorBuffersEXTArgs(
  std::ostream & os, const CmdBindDescriptorBuffersEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  bufferCount" << std::endl;
    // bufferCount -> Field -> uint32_t
    os << "value: " << args.bufferCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pBindingInfos" << std::endl;
    // pBindingInfos -> Field -> ConstDynamicArray(VkDescriptorBufferBindingInfoEXT)
    if (args.bufferCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkDescriptorBufferBindingInfoEXT" << std::endl;
        for (uint64_t i = 0; i < args.bufferCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pBindingInfos << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdSetDescriptorBufferOffsetsEXTArgs(
  std::ostream & os, const CmdSetDescriptorBufferOffsetsEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pipelineBindPoint" << std::endl;
    // pipelineBindPoint -> Field -> VkPipelineBindPoint
    os << "value: " << args.pipelineBindPoint << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  layout" << std::endl;
    // layout -> Field -> VkPipelineLayout
    os << "value: " << args.layout << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstSet" << std::endl;
    // firstSet -> Field -> uint32_t
    os << "value: " << args.firstSet << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  setCount" << std::endl;
    // setCount -> Field -> uint32_t
    os << "value: " << args.setCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pBufferIndices" << std::endl;
    // pBufferIndices -> Field -> ConstDynamicArray(uint32_t)
    if (args.setCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # uint32_t" << std::endl;
        for (uint64_t i = 0; i < args.setCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pBufferIndices << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pOffsets" << std::endl;
    // pOffsets -> Field -> ConstDynamicArray(VkDeviceSize)
    if (args.setCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkDeviceSize" << std::endl;
        for (uint64_t i = 0; i < args.setCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pOffsets << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdBindDescriptorBufferEmbeddedSamplersEXTArgs(
  std::ostream & os, const CmdBindDescriptorBufferEmbeddedSamplersEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pipelineBindPoint" << std::endl;
    // pipelineBindPoint -> Field -> VkPipelineBindPoint
    os << "value: " << args.pipelineBindPoint << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  layout" << std::endl;
    // layout -> Field -> VkPipelineLayout
    os << "value: " << args.layout << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  set" << std::endl;
    // set -> Field -> uint32_t
    os << "value: " << args.set << std::endl;
  }
}

void CommandPrinter::PrintCmdSetFragmentShadingRateEnumNVArgs(
  std::ostream & os, const CmdSetFragmentShadingRateEnumNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  shadingRate" << std::endl;
    // shadingRate -> Field -> VkFragmentShadingRateNV
    os << "value: " << args.shadingRate << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  combinerOps" << std::endl;
    // combinerOps -> Field -> ConstFixedArray(VkFragmentShadingRateCombinerOpKHR)
    {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkFragmentShadingRateCombinerOpKHR" << std::endl;
        for (uint64_t i = 0; i < 2; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.combinerOps << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdSetVertexInputEXTArgs(
  std::ostream & os, const CmdSetVertexInputEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  vertexBindingDescriptionCount" << std::endl;
    // vertexBindingDescriptionCount -> Field -> uint32_t
    os << "value: " << args.vertexBindingDescriptionCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pVertexBindingDescriptions" << std::endl;
    // pVertexBindingDescriptions -> Field -> ConstDynamicArray(VkVertexInputBindingDescription2EXT)
    if (args.vertexBindingDescriptionCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkVertexInputBindingDescription2EXT" << std::endl;
        for (uint64_t i = 0; i < args.vertexBindingDescriptionCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pVertexBindingDescriptions << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  vertexAttributeDescriptionCount" << std::endl;
    // vertexAttributeDescriptionCount -> Field -> uint32_t
    os << "value: " << args.vertexAttributeDescriptionCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pVertexAttributeDescriptions" << std::endl;
    // pVertexAttributeDescriptions -> Field -> ConstDynamicArray(VkVertexInputAttributeDescription2EXT)
    if (args.vertexAttributeDescriptionCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkVertexInputAttributeDescription2EXT" << std::endl;
        for (uint64_t i = 0; i < args.vertexAttributeDescriptionCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pVertexAttributeDescriptions << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdSubpassShadingHUAWEIArgs(
  std::ostream & os, const CmdSubpassShadingHUAWEIArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
}

void CommandPrinter::PrintCmdBindInvocationMaskHUAWEIArgs(
  std::ostream & os, const CmdBindInvocationMaskHUAWEIArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  imageView" << std::endl;
    // imageView -> Field -> VkImageView
    os << "value: " << args.imageView << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  imageLayout" << std::endl;
    // imageLayout -> Field -> VkImageLayout
    os << "value: " << args.imageLayout << std::endl;
  }
}

void CommandPrinter::PrintCmdSetPatchControlPointsEXTArgs(
  std::ostream & os, const CmdSetPatchControlPointsEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  patchControlPoints" << std::endl;
    // patchControlPoints -> Field -> uint32_t
    os << "value: " << args.patchControlPoints << std::endl;
  }
}

void CommandPrinter::PrintCmdSetRasterizerDiscardEnableEXTArgs(
  std::ostream & os, const CmdSetRasterizerDiscardEnableEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  rasterizerDiscardEnable" << std::endl;
    // rasterizerDiscardEnable -> Field -> VkBool32
    os << "value: " << args.rasterizerDiscardEnable << std::endl;
  }
}

void CommandPrinter::PrintCmdSetDepthBiasEnableEXTArgs(
  std::ostream & os, const CmdSetDepthBiasEnableEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  depthBiasEnable" << std::endl;
    // depthBiasEnable -> Field -> VkBool32
    os << "value: " << args.depthBiasEnable << std::endl;
  }
}

void CommandPrinter::PrintCmdSetLogicOpEXTArgs(
  std::ostream & os, const CmdSetLogicOpEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  logicOp" << std::endl;
    // logicOp -> Field -> VkLogicOp
    os << "value: " << args.logicOp << std::endl;
  }
}

void CommandPrinter::PrintCmdSetPrimitiveRestartEnableEXTArgs(
  std::ostream & os, const CmdSetPrimitiveRestartEnableEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  primitiveRestartEnable" << std::endl;
    // primitiveRestartEnable -> Field -> VkBool32
    os << "value: " << args.primitiveRestartEnable << std::endl;
  }
}

void CommandPrinter::PrintCmdSetColorWriteEnableEXTArgs(
  std::ostream & os, const CmdSetColorWriteEnableEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  attachmentCount" << std::endl;
    // attachmentCount -> Field -> uint32_t
    os << "value: " << args.attachmentCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pColorWriteEnables" << std::endl;
    // pColorWriteEnables -> Field -> ConstDynamicArray(VkBool32)
    if (args.attachmentCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkBool32" << std::endl;
        for (uint64_t i = 0; i < args.attachmentCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pColorWriteEnables << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdDrawMultiEXTArgs(
  std::ostream & os, const CmdDrawMultiEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  drawCount" << std::endl;
    // drawCount -> Field -> uint32_t
    os << "value: " << args.drawCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pVertexInfo" << std::endl;
    // pVertexInfo -> Field -> ConstDynamicArray(VkMultiDrawInfoEXT)
    if (args.drawCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkMultiDrawInfoEXT" << std::endl;
        for (uint64_t i = 0; i < args.drawCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pVertexInfo << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  instanceCount" << std::endl;
    // instanceCount -> Field -> uint32_t
    os << "value: " << args.instanceCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstInstance" << std::endl;
    // firstInstance -> Field -> uint32_t
    os << "value: " << args.firstInstance << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stride" << std::endl;
    // stride -> Field -> uint32_t
    os << "value: " << args.stride << std::endl;
  }
}

void CommandPrinter::PrintCmdDrawMultiIndexedEXTArgs(
  std::ostream & os, const CmdDrawMultiIndexedEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  drawCount" << std::endl;
    // drawCount -> Field -> uint32_t
    os << "value: " << args.drawCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pIndexInfo" << std::endl;
    // pIndexInfo -> Field -> ConstDynamicArray(VkMultiDrawIndexedInfoEXT)
    if (args.drawCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkMultiDrawIndexedInfoEXT" << std::endl;
        for (uint64_t i = 0; i < args.drawCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pIndexInfo << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  instanceCount" << std::endl;
    // instanceCount -> Field -> uint32_t
    os << "value: " << args.instanceCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstInstance" << std::endl;
    // firstInstance -> Field -> uint32_t
    os << "value: " << args.firstInstance << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stride" << std::endl;
    // stride -> Field -> uint32_t
    os << "value: " << args.stride << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pVertexOffset" << std::endl;
    // pointer
    if (args.pVertexOffset != nullptr) {
      os << "value: *args.pVertexOffset" << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdBuildMicromapsEXTArgs(
  std::ostream & os, const CmdBuildMicromapsEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  infoCount" << std::endl;
    // infoCount -> Field -> uint32_t
    os << "value: " << args.infoCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pInfos" << std::endl;
    // pInfos -> Field -> ConstDynamicArray(VkMicromapBuildInfoEXT)
    if (args.infoCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkMicromapBuildInfoEXT" << std::endl;
        for (uint64_t i = 0; i < args.infoCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pInfos << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdCopyMicromapEXTArgs(
  std::ostream & os, const CmdCopyMicromapEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pInfo" << std::endl;
    // pointer
    if (args.pInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdCopyMicromapToMemoryEXTArgs(
  std::ostream & os, const CmdCopyMicromapToMemoryEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pInfo" << std::endl;
    // pointer
    if (args.pInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdCopyMemoryToMicromapEXTArgs(
  std::ostream & os, const CmdCopyMemoryToMicromapEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pInfo" << std::endl;
    // pointer
    if (args.pInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdWriteMicromapsPropertiesEXTArgs(
  std::ostream & os, const CmdWriteMicromapsPropertiesEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  micromapCount" << std::endl;
    // micromapCount -> Field -> uint32_t
    os << "value: " << args.micromapCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pMicromaps" << std::endl;
    // pMicromaps -> Field -> ConstDynamicArray(VkMicromapEXT)
    if (args.micromapCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkMicromapEXT" << std::endl;
        for (uint64_t i = 0; i < args.micromapCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pMicromaps << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  queryType" << std::endl;
    // queryType -> Field -> VkQueryType
    os << "value: " << args.queryType << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  queryPool" << std::endl;
    // queryPool -> Field -> VkQueryPool
    os << "value: " << args.queryPool << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstQuery" << std::endl;
    // firstQuery -> Field -> uint32_t
    os << "value: " << args.firstQuery << std::endl;
  }
}

void CommandPrinter::PrintCmdDrawClusterHUAWEIArgs(
  std::ostream & os, const CmdDrawClusterHUAWEIArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  groupCountX" << std::endl;
    // groupCountX -> Field -> uint32_t
    os << "value: " << args.groupCountX << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  groupCountY" << std::endl;
    // groupCountY -> Field -> uint32_t
    os << "value: " << args.groupCountY << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  groupCountZ" << std::endl;
    // groupCountZ -> Field -> uint32_t
    os << "value: " << args.groupCountZ << std::endl;
  }
}

void CommandPrinter::PrintCmdDrawClusterIndirectHUAWEIArgs(
  std::ostream & os, const CmdDrawClusterIndirectHUAWEIArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  buffer" << std::endl;
    // buffer -> Field -> VkBuffer
    os << "value: " << args.buffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  offset" << std::endl;
    // offset -> Field -> VkDeviceSize
    os << "value: " << args.offset << std::endl;
  }
}

void CommandPrinter::PrintCmdCopyMemoryIndirectNVArgs(
  std::ostream & os, const CmdCopyMemoryIndirectNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  copyBufferAddress" << std::endl;
    // copyBufferAddress -> Field -> VkDeviceAddress
    os << "value: " << args.copyBufferAddress << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  copyCount" << std::endl;
    // copyCount -> Field -> uint32_t
    os << "value: " << args.copyCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stride" << std::endl;
    // stride -> Field -> uint32_t
    os << "value: " << args.stride << std::endl;
  }
}

void CommandPrinter::PrintCmdCopyMemoryToImageIndirectNVArgs(
  std::ostream & os, const CmdCopyMemoryToImageIndirectNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  copyBufferAddress" << std::endl;
    // copyBufferAddress -> Field -> VkDeviceAddress
    os << "value: " << args.copyBufferAddress << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  copyCount" << std::endl;
    // copyCount -> Field -> uint32_t
    os << "value: " << args.copyCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stride" << std::endl;
    // stride -> Field -> uint32_t
    os << "value: " << args.stride << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dstImage" << std::endl;
    // dstImage -> Field -> VkImage
    os << "value: " << args.dstImage << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  dstImageLayout" << std::endl;
    // dstImageLayout -> Field -> VkImageLayout
    os << "value: " << args.dstImageLayout << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pImageSubresources" << std::endl;
    // pImageSubresources -> Field -> ConstDynamicArray(VkImageSubresourceLayers)
    if (args.copyCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkImageSubresourceLayers" << std::endl;
        for (uint64_t i = 0; i < args.copyCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pImageSubresources << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdDecompressMemoryNVArgs(
  std::ostream & os, const CmdDecompressMemoryNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  decompressRegionCount" << std::endl;
    // decompressRegionCount -> Field -> uint32_t
    os << "value: " << args.decompressRegionCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pDecompressMemoryRegions" << std::endl;
    // pDecompressMemoryRegions -> Field -> ConstDynamicArray(VkDecompressMemoryRegionNV)
    if (args.decompressRegionCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkDecompressMemoryRegionNV" << std::endl;
        for (uint64_t i = 0; i < args.decompressRegionCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pDecompressMemoryRegions << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdDecompressMemoryIndirectCountNVArgs(
  std::ostream & os, const CmdDecompressMemoryIndirectCountNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  indirectCommandsAddress" << std::endl;
    // indirectCommandsAddress -> Field -> VkDeviceAddress
    os << "value: " << args.indirectCommandsAddress << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  indirectCommandsCountAddress" << std::endl;
    // indirectCommandsCountAddress -> Field -> VkDeviceAddress
    os << "value: " << args.indirectCommandsCountAddress << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stride" << std::endl;
    // stride -> Field -> uint32_t
    os << "value: " << args.stride << std::endl;
  }
}

void CommandPrinter::PrintCmdUpdatePipelineIndirectBufferNVArgs(
  std::ostream & os, const CmdUpdatePipelineIndirectBufferNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pipelineBindPoint" << std::endl;
    // pipelineBindPoint -> Field -> VkPipelineBindPoint
    os << "value: " << args.pipelineBindPoint << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pipeline" << std::endl;
    // pipeline -> Field -> VkPipeline
    os << "value: " << args.pipeline << std::endl;
  }
}

void CommandPrinter::PrintCmdSetDepthClampEnableEXTArgs(
  std::ostream & os, const CmdSetDepthClampEnableEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  depthClampEnable" << std::endl;
    // depthClampEnable -> Field -> VkBool32
    os << "value: " << args.depthClampEnable << std::endl;
  }
}

void CommandPrinter::PrintCmdSetPolygonModeEXTArgs(
  std::ostream & os, const CmdSetPolygonModeEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  polygonMode" << std::endl;
    // polygonMode -> Field -> VkPolygonMode
    os << "value: " << args.polygonMode << std::endl;
  }
}

void CommandPrinter::PrintCmdSetRasterizationSamplesEXTArgs(
  std::ostream & os, const CmdSetRasterizationSamplesEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  rasterizationSamples" << std::endl;
    // rasterizationSamples -> Field -> VkSampleCountFlagBits
    os << "value: " << args.rasterizationSamples << std::endl;
  }
}

void CommandPrinter::PrintCmdSetSampleMaskEXTArgs(
  std::ostream & os, const CmdSetSampleMaskEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  samples" << std::endl;
    // samples -> Field -> VkSampleCountFlagBits
    os << "value: " << args.samples << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pSampleMask" << std::endl;
    // pSampleMask -> Field -> ConstDynamicArray(VkSampleMask)
    if (((args.samples+31)/32) == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkSampleMask" << std::endl;
        for (uint64_t i = 0; i < ((args.samples+31)/32); ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pSampleMask << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdSetAlphaToCoverageEnableEXTArgs(
  std::ostream & os, const CmdSetAlphaToCoverageEnableEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  alphaToCoverageEnable" << std::endl;
    // alphaToCoverageEnable -> Field -> VkBool32
    os << "value: " << args.alphaToCoverageEnable << std::endl;
  }
}

void CommandPrinter::PrintCmdSetAlphaToOneEnableEXTArgs(
  std::ostream & os, const CmdSetAlphaToOneEnableEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  alphaToOneEnable" << std::endl;
    // alphaToOneEnable -> Field -> VkBool32
    os << "value: " << args.alphaToOneEnable << std::endl;
  }
}

void CommandPrinter::PrintCmdSetLogicOpEnableEXTArgs(
  std::ostream & os, const CmdSetLogicOpEnableEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  logicOpEnable" << std::endl;
    // logicOpEnable -> Field -> VkBool32
    os << "value: " << args.logicOpEnable << std::endl;
  }
}

void CommandPrinter::PrintCmdSetColorBlendEnableEXTArgs(
  std::ostream & os, const CmdSetColorBlendEnableEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstAttachment" << std::endl;
    // firstAttachment -> Field -> uint32_t
    os << "value: " << args.firstAttachment << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  attachmentCount" << std::endl;
    // attachmentCount -> Field -> uint32_t
    os << "value: " << args.attachmentCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pColorBlendEnables" << std::endl;
    // pColorBlendEnables -> Field -> ConstDynamicArray(VkBool32)
    if (args.attachmentCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkBool32" << std::endl;
        for (uint64_t i = 0; i < args.attachmentCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pColorBlendEnables << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdSetColorBlendEquationEXTArgs(
  std::ostream & os, const CmdSetColorBlendEquationEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstAttachment" << std::endl;
    // firstAttachment -> Field -> uint32_t
    os << "value: " << args.firstAttachment << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  attachmentCount" << std::endl;
    // attachmentCount -> Field -> uint32_t
    os << "value: " << args.attachmentCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pColorBlendEquations" << std::endl;
    // pColorBlendEquations -> Field -> ConstDynamicArray(VkColorBlendEquationEXT)
    if (args.attachmentCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkColorBlendEquationEXT" << std::endl;
        for (uint64_t i = 0; i < args.attachmentCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pColorBlendEquations << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdSetColorWriteMaskEXTArgs(
  std::ostream & os, const CmdSetColorWriteMaskEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstAttachment" << std::endl;
    // firstAttachment -> Field -> uint32_t
    os << "value: " << args.firstAttachment << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  attachmentCount" << std::endl;
    // attachmentCount -> Field -> uint32_t
    os << "value: " << args.attachmentCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pColorWriteMasks" << std::endl;
    // pColorWriteMasks -> Field -> ConstDynamicArray(VkColorComponentFlags)
    if (args.attachmentCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkColorComponentFlags" << std::endl;
        for (uint64_t i = 0; i < args.attachmentCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pColorWriteMasks << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdSetTessellationDomainOriginEXTArgs(
  std::ostream & os, const CmdSetTessellationDomainOriginEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  domainOrigin" << std::endl;
    // domainOrigin -> Field -> VkTessellationDomainOrigin
    os << "value: " << args.domainOrigin << std::endl;
  }
}

void CommandPrinter::PrintCmdSetRasterizationStreamEXTArgs(
  std::ostream & os, const CmdSetRasterizationStreamEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  rasterizationStream" << std::endl;
    // rasterizationStream -> Field -> uint32_t
    os << "value: " << args.rasterizationStream << std::endl;
  }
}

void CommandPrinter::PrintCmdSetConservativeRasterizationModeEXTArgs(
  std::ostream & os, const CmdSetConservativeRasterizationModeEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  conservativeRasterizationMode" << std::endl;
    // conservativeRasterizationMode -> Field -> VkConservativeRasterizationModeEXT
    os << "value: " << args.conservativeRasterizationMode << std::endl;
  }
}

void CommandPrinter::PrintCmdSetExtraPrimitiveOverestimationSizeEXTArgs(
  std::ostream & os, const CmdSetExtraPrimitiveOverestimationSizeEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  extraPrimitiveOverestimationSize" << std::endl;
    // extraPrimitiveOverestimationSize -> Field -> float
    os << "value: " << args.extraPrimitiveOverestimationSize << std::endl;
  }
}

void CommandPrinter::PrintCmdSetDepthClipEnableEXTArgs(
  std::ostream & os, const CmdSetDepthClipEnableEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  depthClipEnable" << std::endl;
    // depthClipEnable -> Field -> VkBool32
    os << "value: " << args.depthClipEnable << std::endl;
  }
}

void CommandPrinter::PrintCmdSetSampleLocationsEnableEXTArgs(
  std::ostream & os, const CmdSetSampleLocationsEnableEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  sampleLocationsEnable" << std::endl;
    // sampleLocationsEnable -> Field -> VkBool32
    os << "value: " << args.sampleLocationsEnable << std::endl;
  }
}

void CommandPrinter::PrintCmdSetColorBlendAdvancedEXTArgs(
  std::ostream & os, const CmdSetColorBlendAdvancedEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstAttachment" << std::endl;
    // firstAttachment -> Field -> uint32_t
    os << "value: " << args.firstAttachment << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  attachmentCount" << std::endl;
    // attachmentCount -> Field -> uint32_t
    os << "value: " << args.attachmentCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pColorBlendAdvanced" << std::endl;
    // pColorBlendAdvanced -> Field -> ConstDynamicArray(VkColorBlendAdvancedEXT)
    if (args.attachmentCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkColorBlendAdvancedEXT" << std::endl;
        for (uint64_t i = 0; i < args.attachmentCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pColorBlendAdvanced << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdSetProvokingVertexModeEXTArgs(
  std::ostream & os, const CmdSetProvokingVertexModeEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  provokingVertexMode" << std::endl;
    // provokingVertexMode -> Field -> VkProvokingVertexModeEXT
    os << "value: " << args.provokingVertexMode << std::endl;
  }
}

void CommandPrinter::PrintCmdSetLineRasterizationModeEXTArgs(
  std::ostream & os, const CmdSetLineRasterizationModeEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  lineRasterizationMode" << std::endl;
    // lineRasterizationMode -> Field -> VkLineRasterizationModeEXT
    os << "value: " << args.lineRasterizationMode << std::endl;
  }
}

void CommandPrinter::PrintCmdSetLineStippleEnableEXTArgs(
  std::ostream & os, const CmdSetLineStippleEnableEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stippledLineEnable" << std::endl;
    // stippledLineEnable -> Field -> VkBool32
    os << "value: " << args.stippledLineEnable << std::endl;
  }
}

void CommandPrinter::PrintCmdSetDepthClipNegativeOneToOneEXTArgs(
  std::ostream & os, const CmdSetDepthClipNegativeOneToOneEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  negativeOneToOne" << std::endl;
    // negativeOneToOne -> Field -> VkBool32
    os << "value: " << args.negativeOneToOne << std::endl;
  }
}

void CommandPrinter::PrintCmdSetViewportWScalingEnableNVArgs(
  std::ostream & os, const CmdSetViewportWScalingEnableNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  viewportWScalingEnable" << std::endl;
    // viewportWScalingEnable -> Field -> VkBool32
    os << "value: " << args.viewportWScalingEnable << std::endl;
  }
}

void CommandPrinter::PrintCmdSetViewportSwizzleNVArgs(
  std::ostream & os, const CmdSetViewportSwizzleNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstViewport" << std::endl;
    // firstViewport -> Field -> uint32_t
    os << "value: " << args.firstViewport << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  viewportCount" << std::endl;
    // viewportCount -> Field -> uint32_t
    os << "value: " << args.viewportCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pViewportSwizzles" << std::endl;
    // pViewportSwizzles -> Field -> ConstDynamicArray(VkViewportSwizzleNV)
    if (args.viewportCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkViewportSwizzleNV" << std::endl;
        for (uint64_t i = 0; i < args.viewportCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pViewportSwizzles << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdSetCoverageToColorEnableNVArgs(
  std::ostream & os, const CmdSetCoverageToColorEnableNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  coverageToColorEnable" << std::endl;
    // coverageToColorEnable -> Field -> VkBool32
    os << "value: " << args.coverageToColorEnable << std::endl;
  }
}

void CommandPrinter::PrintCmdSetCoverageToColorLocationNVArgs(
  std::ostream & os, const CmdSetCoverageToColorLocationNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  coverageToColorLocation" << std::endl;
    // coverageToColorLocation -> Field -> uint32_t
    os << "value: " << args.coverageToColorLocation << std::endl;
  }
}

void CommandPrinter::PrintCmdSetCoverageModulationModeNVArgs(
  std::ostream & os, const CmdSetCoverageModulationModeNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  coverageModulationMode" << std::endl;
    // coverageModulationMode -> Field -> VkCoverageModulationModeNV
    os << "value: " << args.coverageModulationMode << std::endl;
  }
}

void CommandPrinter::PrintCmdSetCoverageModulationTableEnableNVArgs(
  std::ostream & os, const CmdSetCoverageModulationTableEnableNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  coverageModulationTableEnable" << std::endl;
    // coverageModulationTableEnable -> Field -> VkBool32
    os << "value: " << args.coverageModulationTableEnable << std::endl;
  }
}

void CommandPrinter::PrintCmdSetCoverageModulationTableNVArgs(
  std::ostream & os, const CmdSetCoverageModulationTableNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  coverageModulationTableCount" << std::endl;
    // coverageModulationTableCount -> Field -> uint32_t
    os << "value: " << args.coverageModulationTableCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pCoverageModulationTable" << std::endl;
    // pCoverageModulationTable -> Field -> ConstDynamicArray(float)
    if (args.coverageModulationTableCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # float" << std::endl;
        for (uint64_t i = 0; i < args.coverageModulationTableCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pCoverageModulationTable << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdSetShadingRateImageEnableNVArgs(
  std::ostream & os, const CmdSetShadingRateImageEnableNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  shadingRateImageEnable" << std::endl;
    // shadingRateImageEnable -> Field -> VkBool32
    os << "value: " << args.shadingRateImageEnable << std::endl;
  }
}

void CommandPrinter::PrintCmdSetRepresentativeFragmentTestEnableNVArgs(
  std::ostream & os, const CmdSetRepresentativeFragmentTestEnableNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  representativeFragmentTestEnable" << std::endl;
    // representativeFragmentTestEnable -> Field -> VkBool32
    os << "value: " << args.representativeFragmentTestEnable << std::endl;
  }
}

void CommandPrinter::PrintCmdSetCoverageReductionModeNVArgs(
  std::ostream & os, const CmdSetCoverageReductionModeNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  coverageReductionMode" << std::endl;
    // coverageReductionMode -> Field -> VkCoverageReductionModeNV
    os << "value: " << args.coverageReductionMode << std::endl;
  }
}

void CommandPrinter::PrintCmdOpticalFlowExecuteNVArgs(
  std::ostream & os, const CmdOpticalFlowExecuteNVArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  session" << std::endl;
    // session -> Field -> VkOpticalFlowSessionNV
    os << "value: " << args.session << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pExecuteInfo" << std::endl;
    // pointer
    if (args.pExecuteInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pExecuteInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdBindShadersEXTArgs(
  std::ostream & os, const CmdBindShadersEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stageCount" << std::endl;
    // stageCount -> Field -> uint32_t
    os << "value: " << args.stageCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pStages" << std::endl;
    // pStages -> Field -> ConstDynamicArray(VkShaderStageFlagBits)
    if (args.stageCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkShaderStageFlagBits" << std::endl;
        for (uint64_t i = 0; i < args.stageCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pStages << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pShaders" << std::endl;
    // pShaders -> Field -> ConstDynamicArray(VkShaderEXT)
    if (args.stageCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkShaderEXT" << std::endl;
        for (uint64_t i = 0; i < args.stageCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pShaders << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdSetAttachmentFeedbackLoopEnableEXTArgs(
  std::ostream & os, const CmdSetAttachmentFeedbackLoopEnableEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  aspectMask" << std::endl;
    // aspectMask -> Field -> VkImageAspectFlags
    os << "value: " << args.aspectMask << std::endl;
  }
}

void CommandPrinter::PrintCmdBuildAccelerationStructuresKHRArgs(
  std::ostream & os, const CmdBuildAccelerationStructuresKHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  infoCount" << std::endl;
    // infoCount -> Field -> uint32_t
    os << "value: " << args.infoCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pInfos" << std::endl;
    // pInfos -> Field -> ConstDynamicArray(VkAccelerationStructureBuildGeometryInfoKHR)
    if (args.infoCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkAccelerationStructureBuildGeometryInfoKHR" << std::endl;
        for (uint64_t i = 0; i < args.infoCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pInfos << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  ppBuildRangeInfos" << std::endl;
    // ppBuildRangeInfos -> Field -> ConstDynamicArray(VkAccelerationStructureBuildRangeInfoKHR)
    if (args.infoCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkAccelerationStructureBuildRangeInfoKHR" << std::endl;
        for (uint64_t i = 0; i < args.infoCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << *(args.ppBuildRangeInfos) << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdBuildAccelerationStructuresIndirectKHRArgs(
  std::ostream & os, const CmdBuildAccelerationStructuresIndirectKHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  infoCount" << std::endl;
    // infoCount -> Field -> uint32_t
    os << "value: " << args.infoCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pInfos" << std::endl;
    // pInfos -> Field -> ConstDynamicArray(VkAccelerationStructureBuildGeometryInfoKHR)
    if (args.infoCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkAccelerationStructureBuildGeometryInfoKHR" << std::endl;
        for (uint64_t i = 0; i < args.infoCount; ++i) {
          ScopedOstream somember(os);
          os << "members::" << std::endl << args.pInfos << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pIndirectDeviceAddresses" << std::endl;
    // pIndirectDeviceAddresses -> Field -> ConstDynamicArray(VkDeviceAddress)
    if (args.infoCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkDeviceAddress" << std::endl;
        for (uint64_t i = 0; i < args.infoCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pIndirectDeviceAddresses << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pIndirectStrides" << std::endl;
    // pIndirectStrides -> Field -> ConstDynamicArray(uint32_t)
    if (args.infoCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # uint32_t" << std::endl;
        for (uint64_t i = 0; i < args.infoCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pIndirectStrides << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  ppMaxPrimitiveCounts" << std::endl;
    // ppMaxPrimitiveCounts -> Field -> ConstDynamicArray(uint32_t)
    if (args.infoCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # uint32_t" << std::endl;
        for (uint64_t i = 0; i < args.infoCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << *(args.ppMaxPrimitiveCounts) << std::endl;
        } // for i
      }
    }
  }
}

void CommandPrinter::PrintCmdCopyAccelerationStructureKHRArgs(
  std::ostream & os, const CmdCopyAccelerationStructureKHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pInfo" << std::endl;
    // pointer
    if (args.pInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdCopyAccelerationStructureToMemoryKHRArgs(
  std::ostream & os, const CmdCopyAccelerationStructureToMemoryKHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pInfo" << std::endl;
    // pointer
    if (args.pInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdCopyMemoryToAccelerationStructureKHRArgs(
  std::ostream & os, const CmdCopyMemoryToAccelerationStructureKHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pInfo" << std::endl;
    // pointer
    if (args.pInfo != nullptr) {
      os <<  "members:" << std::endl << *args.pInfo << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
}

void CommandPrinter::PrintCmdWriteAccelerationStructuresPropertiesKHRArgs(
  std::ostream & os, const CmdWriteAccelerationStructuresPropertiesKHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  accelerationStructureCount" << std::endl;
    // accelerationStructureCount -> Field -> uint32_t
    os << "value: " << args.accelerationStructureCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pAccelerationStructures" << std::endl;
    // pAccelerationStructures -> Field -> ConstDynamicArray(VkAccelerationStructureKHR)
    if (args.accelerationStructureCount == 0) {
      os << "value: nullptr" << std::endl;
    } else {
      os << "members:" << std::endl;
      {
        ScopedOstream soarray(os);
        os << "- # VkAccelerationStructureKHR" << std::endl;
        for (uint64_t i = 0; i < args.accelerationStructureCount; ++i) {
          ScopedOstream somember(os);
          os << "value: :" << std::endl << args.pAccelerationStructures << std::endl;
        } // for i
      }
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  queryType" << std::endl;
    // queryType -> Field -> VkQueryType
    os << "value: " << args.queryType << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  queryPool" << std::endl;
    // queryPool -> Field -> VkQueryPool
    os << "value: " << args.queryPool << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  firstQuery" << std::endl;
    // firstQuery -> Field -> uint32_t
    os << "value: " << args.firstQuery << std::endl;
  }
}

void CommandPrinter::PrintCmdTraceRaysKHRArgs(
  std::ostream & os, const CmdTraceRaysKHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pRaygenShaderBindingTable" << std::endl;
    // pointer
    if (args.pRaygenShaderBindingTable != nullptr) {
      os <<  "members:" << std::endl << *args.pRaygenShaderBindingTable << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pMissShaderBindingTable" << std::endl;
    // pointer
    if (args.pMissShaderBindingTable != nullptr) {
      os <<  "members:" << std::endl << *args.pMissShaderBindingTable << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pHitShaderBindingTable" << std::endl;
    // pointer
    if (args.pHitShaderBindingTable != nullptr) {
      os <<  "members:" << std::endl << *args.pHitShaderBindingTable << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pCallableShaderBindingTable" << std::endl;
    // pointer
    if (args.pCallableShaderBindingTable != nullptr) {
      os <<  "members:" << std::endl << *args.pCallableShaderBindingTable << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  width" << std::endl;
    // width -> Field -> uint32_t
    os << "value: " << args.width << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  height" << std::endl;
    // height -> Field -> uint32_t
    os << "value: " << args.height << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  depth" << std::endl;
    // depth -> Field -> uint32_t
    os << "value: " << args.depth << std::endl;
  }
}

void CommandPrinter::PrintCmdTraceRaysIndirectKHRArgs(
  std::ostream & os, const CmdTraceRaysIndirectKHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pRaygenShaderBindingTable" << std::endl;
    // pointer
    if (args.pRaygenShaderBindingTable != nullptr) {
      os <<  "members:" << std::endl << *args.pRaygenShaderBindingTable << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pMissShaderBindingTable" << std::endl;
    // pointer
    if (args.pMissShaderBindingTable != nullptr) {
      os <<  "members:" << std::endl << *args.pMissShaderBindingTable << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pHitShaderBindingTable" << std::endl;
    // pointer
    if (args.pHitShaderBindingTable != nullptr) {
      os <<  "members:" << std::endl << *args.pHitShaderBindingTable << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pCallableShaderBindingTable" << std::endl;
    // pointer
    if (args.pCallableShaderBindingTable != nullptr) {
      os <<  "members:" << std::endl << *args.pCallableShaderBindingTable << std::endl;
    } else {
      os << "value: nullptr" << std::endl;
    }
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  indirectDeviceAddress" << std::endl;
    // indirectDeviceAddress -> Field -> VkDeviceAddress
    os << "value: " << args.indirectDeviceAddress << std::endl;
  }
}

void CommandPrinter::PrintCmdSetRayTracingPipelineStackSizeKHRArgs(
  std::ostream & os, const CmdSetRayTracingPipelineStackSizeKHRArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  pipelineStackSize" << std::endl;
    // pipelineStackSize -> Field -> uint32_t
    os << "value: " << args.pipelineStackSize << std::endl;
  }
}

void CommandPrinter::PrintCmdDrawMeshTasksEXTArgs(
  std::ostream & os, const CmdDrawMeshTasksEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  groupCountX" << std::endl;
    // groupCountX -> Field -> uint32_t
    os << "value: " << args.groupCountX << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  groupCountY" << std::endl;
    // groupCountY -> Field -> uint32_t
    os << "value: " << args.groupCountY << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  groupCountZ" << std::endl;
    // groupCountZ -> Field -> uint32_t
    os << "value: " << args.groupCountZ << std::endl;
  }
}

void CommandPrinter::PrintCmdDrawMeshTasksIndirectEXTArgs(
  std::ostream & os, const CmdDrawMeshTasksIndirectEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  buffer" << std::endl;
    // buffer -> Field -> VkBuffer
    os << "value: " << args.buffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  offset" << std::endl;
    // offset -> Field -> VkDeviceSize
    os << "value: " << args.offset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  drawCount" << std::endl;
    // drawCount -> Field -> uint32_t
    os << "value: " << args.drawCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stride" << std::endl;
    // stride -> Field -> uint32_t
    os << "value: " << args.stride << std::endl;
  }
}

void CommandPrinter::PrintCmdDrawMeshTasksIndirectCountEXTArgs(
  std::ostream & os, const CmdDrawMeshTasksIndirectCountEXTArgs &args) {
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  commandBuffer" << std::endl;
    // commandBuffer -> Field -> VkCommandBuffer
    os << "value: " << args.commandBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  buffer" << std::endl;
    // buffer -> Field -> VkBuffer
    os << "value: " << args.buffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  offset" << std::endl;
    // offset -> Field -> VkDeviceSize
    os << "value: " << args.offset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  countBuffer" << std::endl;
    // countBuffer -> Field -> VkBuffer
    os << "value: " << args.countBuffer << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  countBufferOffset" << std::endl;
    // countBufferOffset -> Field -> VkDeviceSize
    os << "value: " << args.countBufferOffset << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  maxDrawCount" << std::endl;
    // maxDrawCount -> Field -> uint32_t
    os << "value: " << args.maxDrawCount << std::endl;
  }
  {
    os << "- # parameter:" << std::endl;
    ScopedOstream sop(os);
    os << "name:  stride" << std::endl;
    // stride -> Field -> uint32_t
    os << "value: " << args.stride << std::endl;
  }
}



// NOLINTEND

