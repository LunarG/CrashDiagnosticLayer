
/***************************************************************************
 *
 * Copyright (C) 2021 Google Inc.
 * Copyright (c) 2023-2024 LunarG, Inc.
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

void CommandPrinter::PrintBeginCommandBufferArgs(YAML::Emitter &os, const BeginCommandBufferArgs &args) {
    os << YAML::Key << "pBeginInfo";
    // pointer
    if (args.pBeginInfo != nullptr) {
        os << YAML::Value << *args.pBeginInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintEndCommandBufferArgs(YAML::Emitter &os, const EndCommandBufferArgs &args) {}

void CommandPrinter::PrintResetCommandBufferArgs(YAML::Emitter &os, const ResetCommandBufferArgs &args) {
    os << YAML::Key << "flags";
    // flags -> Field -> VkCommandBufferResetFlags
    os << YAML::Value << args.flags;
}

void CommandPrinter::PrintCmdBindPipelineArgs(YAML::Emitter &os, const CmdBindPipelineArgs &args) {
    os << YAML::Key << "pipelineBindPoint";
    // pipelineBindPoint -> Field -> VkPipelineBindPoint
    os << YAML::Value << args.pipelineBindPoint;
    os << YAML::Key << "pipeline";
    // pipeline -> Field -> VkPipeline
    os << YAML::Value << args.pipeline;
}

void CommandPrinter::PrintCmdSetViewportArgs(YAML::Emitter &os, const CmdSetViewportArgs &args) {
    os << YAML::Key << "firstViewport";
    // firstViewport -> Field -> uint32_t
    os << YAML::Value << args.firstViewport;
    os << YAML::Key << "viewportCount";
    // viewportCount -> Field -> uint32_t
    os << YAML::Value << args.viewportCount;
    os << YAML::Key << "pViewports";
    // pViewports -> Field -> ConstDynamicArray(VkViewport)
    if (args.viewportCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkViewport");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.viewportCount; ++i) {
                os << args.pViewports[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdSetScissorArgs(YAML::Emitter &os, const CmdSetScissorArgs &args) {
    os << YAML::Key << "firstScissor";
    // firstScissor -> Field -> uint32_t
    os << YAML::Value << args.firstScissor;
    os << YAML::Key << "scissorCount";
    // scissorCount -> Field -> uint32_t
    os << YAML::Value << args.scissorCount;
    os << YAML::Key << "pScissors";
    // pScissors -> Field -> ConstDynamicArray(VkRect2D)
    if (args.scissorCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkRect2D");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.scissorCount; ++i) {
                os << args.pScissors[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdSetLineWidthArgs(YAML::Emitter &os, const CmdSetLineWidthArgs &args) {
    os << YAML::Key << "lineWidth";
    // lineWidth -> Field -> float
    os << YAML::Value << args.lineWidth;
}

void CommandPrinter::PrintCmdSetDepthBiasArgs(YAML::Emitter &os, const CmdSetDepthBiasArgs &args) {
    os << YAML::Key << "depthBiasConstantFactor";
    // depthBiasConstantFactor -> Field -> float
    os << YAML::Value << args.depthBiasConstantFactor;
    os << YAML::Key << "depthBiasClamp";
    // depthBiasClamp -> Field -> float
    os << YAML::Value << args.depthBiasClamp;
    os << YAML::Key << "depthBiasSlopeFactor";
    // depthBiasSlopeFactor -> Field -> float
    os << YAML::Value << args.depthBiasSlopeFactor;
}

void CommandPrinter::PrintCmdSetBlendConstantsArgs(YAML::Emitter &os, const CmdSetBlendConstantsArgs &args) {
    os << YAML::Key << "blendConstants";
    // blendConstants -> Field -> ConstFixedArray(float)
    {
        os << YAML::Value;
        {
            os << YAML::Comment("float");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < 4; ++i) {
                os << args.blendConstants[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdSetDepthBoundsArgs(YAML::Emitter &os, const CmdSetDepthBoundsArgs &args) {
    os << YAML::Key << "minDepthBounds";
    // minDepthBounds -> Field -> float
    os << YAML::Value << args.minDepthBounds;
    os << YAML::Key << "maxDepthBounds";
    // maxDepthBounds -> Field -> float
    os << YAML::Value << args.maxDepthBounds;
}

void CommandPrinter::PrintCmdSetStencilCompareMaskArgs(YAML::Emitter &os, const CmdSetStencilCompareMaskArgs &args) {
    os << YAML::Key << "faceMask";
    // faceMask -> Field -> VkStencilFaceFlags
    os << YAML::Value << args.faceMask;
    os << YAML::Key << "compareMask";
    // compareMask -> Field -> uint32_t
    os << YAML::Value << args.compareMask;
}

void CommandPrinter::PrintCmdSetStencilWriteMaskArgs(YAML::Emitter &os, const CmdSetStencilWriteMaskArgs &args) {
    os << YAML::Key << "faceMask";
    // faceMask -> Field -> VkStencilFaceFlags
    os << YAML::Value << args.faceMask;
    os << YAML::Key << "writeMask";
    // writeMask -> Field -> uint32_t
    os << YAML::Value << args.writeMask;
}

void CommandPrinter::PrintCmdSetStencilReferenceArgs(YAML::Emitter &os, const CmdSetStencilReferenceArgs &args) {
    os << YAML::Key << "faceMask";
    // faceMask -> Field -> VkStencilFaceFlags
    os << YAML::Value << args.faceMask;
    os << YAML::Key << "reference";
    // reference -> Field -> uint32_t
    os << YAML::Value << args.reference;
}

void CommandPrinter::PrintCmdBindDescriptorSetsArgs(YAML::Emitter &os, const CmdBindDescriptorSetsArgs &args) {
    os << YAML::Key << "pipelineBindPoint";
    // pipelineBindPoint -> Field -> VkPipelineBindPoint
    os << YAML::Value << args.pipelineBindPoint;
    os << YAML::Key << "layout";
    // layout -> Field -> VkPipelineLayout
    os << YAML::Value << args.layout;
    os << YAML::Key << "firstSet";
    // firstSet -> Field -> uint32_t
    os << YAML::Value << args.firstSet;
    os << YAML::Key << "descriptorSetCount";
    // descriptorSetCount -> Field -> uint32_t
    os << YAML::Value << args.descriptorSetCount;
    os << YAML::Key << "pDescriptorSets";
    // pDescriptorSets -> Field -> ConstDynamicArray(VkDescriptorSet)
    if (args.descriptorSetCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkDescriptorSet");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.descriptorSetCount; ++i) {
                os << args.pDescriptorSets[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "dynamicOffsetCount";
    // dynamicOffsetCount -> Field -> uint32_t
    os << YAML::Value << args.dynamicOffsetCount;
    os << YAML::Key << "pDynamicOffsets";
    // pDynamicOffsets -> Field -> ConstDynamicArray(uint32_t)
    if (args.dynamicOffsetCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("uint32_t");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.dynamicOffsetCount; ++i) {
                os << args.pDynamicOffsets[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdBindIndexBufferArgs(YAML::Emitter &os, const CmdBindIndexBufferArgs &args) {
    os << YAML::Key << "buffer";
    // buffer -> Field -> VkBuffer
    os << YAML::Value << args.buffer;
    os << YAML::Key << "offset";
    // offset -> Field -> VkDeviceSize
    os << YAML::Value << args.offset;
    os << YAML::Key << "indexType";
    // indexType -> Field -> VkIndexType
    os << YAML::Value << args.indexType;
}

void CommandPrinter::PrintCmdBindVertexBuffersArgs(YAML::Emitter &os, const CmdBindVertexBuffersArgs &args) {
    os << YAML::Key << "firstBinding";
    // firstBinding -> Field -> uint32_t
    os << YAML::Value << args.firstBinding;
    os << YAML::Key << "bindingCount";
    // bindingCount -> Field -> uint32_t
    os << YAML::Value << args.bindingCount;
    os << YAML::Key << "pBuffers";
    // pBuffers -> Field -> ConstDynamicArray(VkBuffer)
    if (args.bindingCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkBuffer");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.bindingCount; ++i) {
                os << args.pBuffers[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "pOffsets";
    // pOffsets -> Field -> ConstDynamicArray(VkDeviceSize)
    if (args.bindingCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkDeviceSize");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.bindingCount; ++i) {
                os << args.pOffsets[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdDrawArgs(YAML::Emitter &os, const CmdDrawArgs &args) {
    os << YAML::Key << "vertexCount";
    // vertexCount -> Field -> uint32_t
    os << YAML::Value << args.vertexCount;
    os << YAML::Key << "instanceCount";
    // instanceCount -> Field -> uint32_t
    os << YAML::Value << args.instanceCount;
    os << YAML::Key << "firstVertex";
    // firstVertex -> Field -> uint32_t
    os << YAML::Value << args.firstVertex;
    os << YAML::Key << "firstInstance";
    // firstInstance -> Field -> uint32_t
    os << YAML::Value << args.firstInstance;
}

void CommandPrinter::PrintCmdDrawIndexedArgs(YAML::Emitter &os, const CmdDrawIndexedArgs &args) {
    os << YAML::Key << "indexCount";
    // indexCount -> Field -> uint32_t
    os << YAML::Value << args.indexCount;
    os << YAML::Key << "instanceCount";
    // instanceCount -> Field -> uint32_t
    os << YAML::Value << args.instanceCount;
    os << YAML::Key << "firstIndex";
    // firstIndex -> Field -> uint32_t
    os << YAML::Value << args.firstIndex;
    os << YAML::Key << "vertexOffset";
    // vertexOffset -> Field -> int32_t
    os << YAML::Value << args.vertexOffset;
    os << YAML::Key << "firstInstance";
    // firstInstance -> Field -> uint32_t
    os << YAML::Value << args.firstInstance;
}

void CommandPrinter::PrintCmdDrawIndirectArgs(YAML::Emitter &os, const CmdDrawIndirectArgs &args) {
    os << YAML::Key << "buffer";
    // buffer -> Field -> VkBuffer
    os << YAML::Value << args.buffer;
    os << YAML::Key << "offset";
    // offset -> Field -> VkDeviceSize
    os << YAML::Value << args.offset;
    os << YAML::Key << "drawCount";
    // drawCount -> Field -> uint32_t
    os << YAML::Value << args.drawCount;
    os << YAML::Key << "stride";
    // stride -> Field -> uint32_t
    os << YAML::Value << args.stride;
}

void CommandPrinter::PrintCmdDrawIndexedIndirectArgs(YAML::Emitter &os, const CmdDrawIndexedIndirectArgs &args) {
    os << YAML::Key << "buffer";
    // buffer -> Field -> VkBuffer
    os << YAML::Value << args.buffer;
    os << YAML::Key << "offset";
    // offset -> Field -> VkDeviceSize
    os << YAML::Value << args.offset;
    os << YAML::Key << "drawCount";
    // drawCount -> Field -> uint32_t
    os << YAML::Value << args.drawCount;
    os << YAML::Key << "stride";
    // stride -> Field -> uint32_t
    os << YAML::Value << args.stride;
}

void CommandPrinter::PrintCmdDispatchArgs(YAML::Emitter &os, const CmdDispatchArgs &args) {
    os << YAML::Key << "groupCountX";
    // groupCountX -> Field -> uint32_t
    os << YAML::Value << args.groupCountX;
    os << YAML::Key << "groupCountY";
    // groupCountY -> Field -> uint32_t
    os << YAML::Value << args.groupCountY;
    os << YAML::Key << "groupCountZ";
    // groupCountZ -> Field -> uint32_t
    os << YAML::Value << args.groupCountZ;
}

void CommandPrinter::PrintCmdDispatchIndirectArgs(YAML::Emitter &os, const CmdDispatchIndirectArgs &args) {
    os << YAML::Key << "buffer";
    // buffer -> Field -> VkBuffer
    os << YAML::Value << args.buffer;
    os << YAML::Key << "offset";
    // offset -> Field -> VkDeviceSize
    os << YAML::Value << args.offset;
}

void CommandPrinter::PrintCmdCopyBufferArgs(YAML::Emitter &os, const CmdCopyBufferArgs &args) {
    os << YAML::Key << "srcBuffer";
    // srcBuffer -> Field -> VkBuffer
    os << YAML::Value << args.srcBuffer;
    os << YAML::Key << "dstBuffer";
    // dstBuffer -> Field -> VkBuffer
    os << YAML::Value << args.dstBuffer;
    os << YAML::Key << "regionCount";
    // regionCount -> Field -> uint32_t
    os << YAML::Value << args.regionCount;
    os << YAML::Key << "pRegions";
    // pRegions -> Field -> ConstDynamicArray(VkBufferCopy)
    if (args.regionCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkBufferCopy");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.regionCount; ++i) {
                os << args.pRegions[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdCopyImageArgs(YAML::Emitter &os, const CmdCopyImageArgs &args) {
    os << YAML::Key << "srcImage";
    // srcImage -> Field -> VkImage
    os << YAML::Value << args.srcImage;
    os << YAML::Key << "srcImageLayout";
    // srcImageLayout -> Field -> VkImageLayout
    os << YAML::Value << args.srcImageLayout;
    os << YAML::Key << "dstImage";
    // dstImage -> Field -> VkImage
    os << YAML::Value << args.dstImage;
    os << YAML::Key << "dstImageLayout";
    // dstImageLayout -> Field -> VkImageLayout
    os << YAML::Value << args.dstImageLayout;
    os << YAML::Key << "regionCount";
    // regionCount -> Field -> uint32_t
    os << YAML::Value << args.regionCount;
    os << YAML::Key << "pRegions";
    // pRegions -> Field -> ConstDynamicArray(VkImageCopy)
    if (args.regionCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkImageCopy");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.regionCount; ++i) {
                os << args.pRegions[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdBlitImageArgs(YAML::Emitter &os, const CmdBlitImageArgs &args) {
    os << YAML::Key << "srcImage";
    // srcImage -> Field -> VkImage
    os << YAML::Value << args.srcImage;
    os << YAML::Key << "srcImageLayout";
    // srcImageLayout -> Field -> VkImageLayout
    os << YAML::Value << args.srcImageLayout;
    os << YAML::Key << "dstImage";
    // dstImage -> Field -> VkImage
    os << YAML::Value << args.dstImage;
    os << YAML::Key << "dstImageLayout";
    // dstImageLayout -> Field -> VkImageLayout
    os << YAML::Value << args.dstImageLayout;
    os << YAML::Key << "regionCount";
    // regionCount -> Field -> uint32_t
    os << YAML::Value << args.regionCount;
    os << YAML::Key << "pRegions";
    // pRegions -> Field -> ConstDynamicArray(VkImageBlit)
    if (args.regionCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkImageBlit");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.regionCount; ++i) {
                os << args.pRegions[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "filter";
    // filter -> Field -> VkFilter
    os << YAML::Value << args.filter;
}

void CommandPrinter::PrintCmdCopyBufferToImageArgs(YAML::Emitter &os, const CmdCopyBufferToImageArgs &args) {
    os << YAML::Key << "srcBuffer";
    // srcBuffer -> Field -> VkBuffer
    os << YAML::Value << args.srcBuffer;
    os << YAML::Key << "dstImage";
    // dstImage -> Field -> VkImage
    os << YAML::Value << args.dstImage;
    os << YAML::Key << "dstImageLayout";
    // dstImageLayout -> Field -> VkImageLayout
    os << YAML::Value << args.dstImageLayout;
    os << YAML::Key << "regionCount";
    // regionCount -> Field -> uint32_t
    os << YAML::Value << args.regionCount;
    os << YAML::Key << "pRegions";
    // pRegions -> Field -> ConstDynamicArray(VkBufferImageCopy)
    if (args.regionCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkBufferImageCopy");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.regionCount; ++i) {
                os << args.pRegions[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdCopyImageToBufferArgs(YAML::Emitter &os, const CmdCopyImageToBufferArgs &args) {
    os << YAML::Key << "srcImage";
    // srcImage -> Field -> VkImage
    os << YAML::Value << args.srcImage;
    os << YAML::Key << "srcImageLayout";
    // srcImageLayout -> Field -> VkImageLayout
    os << YAML::Value << args.srcImageLayout;
    os << YAML::Key << "dstBuffer";
    // dstBuffer -> Field -> VkBuffer
    os << YAML::Value << args.dstBuffer;
    os << YAML::Key << "regionCount";
    // regionCount -> Field -> uint32_t
    os << YAML::Value << args.regionCount;
    os << YAML::Key << "pRegions";
    // pRegions -> Field -> ConstDynamicArray(VkBufferImageCopy)
    if (args.regionCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkBufferImageCopy");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.regionCount; ++i) {
                os << args.pRegions[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdUpdateBufferArgs(YAML::Emitter &os, const CmdUpdateBufferArgs &args) {
    os << YAML::Key << "dstBuffer";
    // dstBuffer -> Field -> VkBuffer
    os << YAML::Value << args.dstBuffer;
    os << YAML::Key << "dstOffset";
    // dstOffset -> Field -> VkDeviceSize
    os << YAML::Value << args.dstOffset;
    os << YAML::Key << "dataSize";
    // dataSize -> Field -> VkDeviceSize
    os << YAML::Value << args.dataSize;
    os << YAML::Key << "pData";
    if (args.dataSize == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value << YAML::BeginSeq;
        {
            const uint8_t *p = (const uint8_t *)args.pData;
            for (uint64_t i = 0; i < args.dataSize; ++i) {
                os << crash_diagnostic_layer::Uint8ToStr(p[i]);
            }
        }
        os << YAML::EndSeq;
    }
}

void CommandPrinter::PrintCmdFillBufferArgs(YAML::Emitter &os, const CmdFillBufferArgs &args) {
    os << YAML::Key << "dstBuffer";
    // dstBuffer -> Field -> VkBuffer
    os << YAML::Value << args.dstBuffer;
    os << YAML::Key << "dstOffset";
    // dstOffset -> Field -> VkDeviceSize
    os << YAML::Value << args.dstOffset;
    os << YAML::Key << "size";
    // size -> Field -> VkDeviceSize
    os << YAML::Value << args.size;
    os << YAML::Key << "data";
    // data -> Field -> uint32_t
    os << YAML::Value << args.data;
}

void CommandPrinter::PrintCmdClearColorImageArgs(YAML::Emitter &os, const CmdClearColorImageArgs &args) {
    os << YAML::Key << "image";
    // image -> Field -> VkImage
    os << YAML::Value << args.image;
    os << YAML::Key << "imageLayout";
    // imageLayout -> Field -> VkImageLayout
    os << YAML::Value << args.imageLayout;
    os << YAML::Key << "pColor";
    // pointer
    if (args.pColor != nullptr) {
        os << YAML::Value << *args.pColor;
    } else {
        os << YAML::Value << "nullptr";
    }
    os << YAML::Key << "rangeCount";
    // rangeCount -> Field -> uint32_t
    os << YAML::Value << args.rangeCount;
    os << YAML::Key << "pRanges";
    // pRanges -> Field -> ConstDynamicArray(VkImageSubresourceRange)
    if (args.rangeCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkImageSubresourceRange");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.rangeCount; ++i) {
                os << args.pRanges[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdClearDepthStencilImageArgs(YAML::Emitter &os, const CmdClearDepthStencilImageArgs &args) {
    os << YAML::Key << "image";
    // image -> Field -> VkImage
    os << YAML::Value << args.image;
    os << YAML::Key << "imageLayout";
    // imageLayout -> Field -> VkImageLayout
    os << YAML::Value << args.imageLayout;
    os << YAML::Key << "pDepthStencil";
    // pointer
    if (args.pDepthStencil != nullptr) {
        os << YAML::Value << *args.pDepthStencil;
    } else {
        os << YAML::Value << "nullptr";
    }
    os << YAML::Key << "rangeCount";
    // rangeCount -> Field -> uint32_t
    os << YAML::Value << args.rangeCount;
    os << YAML::Key << "pRanges";
    // pRanges -> Field -> ConstDynamicArray(VkImageSubresourceRange)
    if (args.rangeCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkImageSubresourceRange");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.rangeCount; ++i) {
                os << args.pRanges[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdClearAttachmentsArgs(YAML::Emitter &os, const CmdClearAttachmentsArgs &args) {
    os << YAML::Key << "attachmentCount";
    // attachmentCount -> Field -> uint32_t
    os << YAML::Value << args.attachmentCount;
    os << YAML::Key << "pAttachments";
    // pAttachments -> Field -> ConstDynamicArray(VkClearAttachment)
    if (args.attachmentCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkClearAttachment");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.attachmentCount; ++i) {
                os << args.pAttachments[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "rectCount";
    // rectCount -> Field -> uint32_t
    os << YAML::Value << args.rectCount;
    os << YAML::Key << "pRects";
    // pRects -> Field -> ConstDynamicArray(VkClearRect)
    if (args.rectCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkClearRect");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.rectCount; ++i) {
                os << args.pRects[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdResolveImageArgs(YAML::Emitter &os, const CmdResolveImageArgs &args) {
    os << YAML::Key << "srcImage";
    // srcImage -> Field -> VkImage
    os << YAML::Value << args.srcImage;
    os << YAML::Key << "srcImageLayout";
    // srcImageLayout -> Field -> VkImageLayout
    os << YAML::Value << args.srcImageLayout;
    os << YAML::Key << "dstImage";
    // dstImage -> Field -> VkImage
    os << YAML::Value << args.dstImage;
    os << YAML::Key << "dstImageLayout";
    // dstImageLayout -> Field -> VkImageLayout
    os << YAML::Value << args.dstImageLayout;
    os << YAML::Key << "regionCount";
    // regionCount -> Field -> uint32_t
    os << YAML::Value << args.regionCount;
    os << YAML::Key << "pRegions";
    // pRegions -> Field -> ConstDynamicArray(VkImageResolve)
    if (args.regionCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkImageResolve");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.regionCount; ++i) {
                os << args.pRegions[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdSetEventArgs(YAML::Emitter &os, const CmdSetEventArgs &args) {
    os << YAML::Key << "event";
    // event -> Field -> VkEvent
    os << YAML::Value << args.event;
    os << YAML::Key << "stageMask";
    // stageMask -> Field -> VkPipelineStageFlags
    os << YAML::Value << args.stageMask;
}

void CommandPrinter::PrintCmdResetEventArgs(YAML::Emitter &os, const CmdResetEventArgs &args) {
    os << YAML::Key << "event";
    // event -> Field -> VkEvent
    os << YAML::Value << args.event;
    os << YAML::Key << "stageMask";
    // stageMask -> Field -> VkPipelineStageFlags
    os << YAML::Value << args.stageMask;
}

void CommandPrinter::PrintCmdWaitEventsArgs(YAML::Emitter &os, const CmdWaitEventsArgs &args) {
    os << YAML::Key << "eventCount";
    // eventCount -> Field -> uint32_t
    os << YAML::Value << args.eventCount;
    os << YAML::Key << "pEvents";
    // pEvents -> Field -> ConstDynamicArray(VkEvent)
    if (args.eventCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkEvent");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.eventCount; ++i) {
                os << args.pEvents[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "srcStageMask";
    // srcStageMask -> Field -> VkPipelineStageFlags
    os << YAML::Value << args.srcStageMask;
    os << YAML::Key << "dstStageMask";
    // dstStageMask -> Field -> VkPipelineStageFlags
    os << YAML::Value << args.dstStageMask;
    os << YAML::Key << "memoryBarrierCount";
    // memoryBarrierCount -> Field -> uint32_t
    os << YAML::Value << args.memoryBarrierCount;
    os << YAML::Key << "pMemoryBarriers";
    // pMemoryBarriers -> Field -> ConstDynamicArray(VkMemoryBarrier)
    if (args.memoryBarrierCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkMemoryBarrier");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.memoryBarrierCount; ++i) {
                os << args.pMemoryBarriers[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "bufferMemoryBarrierCount";
    // bufferMemoryBarrierCount -> Field -> uint32_t
    os << YAML::Value << args.bufferMemoryBarrierCount;
    os << YAML::Key << "pBufferMemoryBarriers";
    // pBufferMemoryBarriers -> Field -> ConstDynamicArray(VkBufferMemoryBarrier)
    if (args.bufferMemoryBarrierCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkBufferMemoryBarrier");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.bufferMemoryBarrierCount; ++i) {
                os << args.pBufferMemoryBarriers[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "imageMemoryBarrierCount";
    // imageMemoryBarrierCount -> Field -> uint32_t
    os << YAML::Value << args.imageMemoryBarrierCount;
    os << YAML::Key << "pImageMemoryBarriers";
    // pImageMemoryBarriers -> Field -> ConstDynamicArray(VkImageMemoryBarrier)
    if (args.imageMemoryBarrierCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkImageMemoryBarrier");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.imageMemoryBarrierCount; ++i) {
                os << args.pImageMemoryBarriers[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdPipelineBarrierArgs(YAML::Emitter &os, const CmdPipelineBarrierArgs &args) {
    os << YAML::Key << "srcStageMask";
    // srcStageMask -> Field -> VkPipelineStageFlags
    os << YAML::Value << args.srcStageMask;
    os << YAML::Key << "dstStageMask";
    // dstStageMask -> Field -> VkPipelineStageFlags
    os << YAML::Value << args.dstStageMask;
    os << YAML::Key << "dependencyFlags";
    // dependencyFlags -> Field -> VkDependencyFlags
    os << YAML::Value << args.dependencyFlags;
    os << YAML::Key << "memoryBarrierCount";
    // memoryBarrierCount -> Field -> uint32_t
    os << YAML::Value << args.memoryBarrierCount;
    os << YAML::Key << "pMemoryBarriers";
    // pMemoryBarriers -> Field -> ConstDynamicArray(VkMemoryBarrier)
    if (args.memoryBarrierCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkMemoryBarrier");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.memoryBarrierCount; ++i) {
                os << args.pMemoryBarriers[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "bufferMemoryBarrierCount";
    // bufferMemoryBarrierCount -> Field -> uint32_t
    os << YAML::Value << args.bufferMemoryBarrierCount;
    os << YAML::Key << "pBufferMemoryBarriers";
    // pBufferMemoryBarriers -> Field -> ConstDynamicArray(VkBufferMemoryBarrier)
    if (args.bufferMemoryBarrierCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkBufferMemoryBarrier");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.bufferMemoryBarrierCount; ++i) {
                os << args.pBufferMemoryBarriers[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "imageMemoryBarrierCount";
    // imageMemoryBarrierCount -> Field -> uint32_t
    os << YAML::Value << args.imageMemoryBarrierCount;
    os << YAML::Key << "pImageMemoryBarriers";
    // pImageMemoryBarriers -> Field -> ConstDynamicArray(VkImageMemoryBarrier)
    if (args.imageMemoryBarrierCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkImageMemoryBarrier");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.imageMemoryBarrierCount; ++i) {
                os << args.pImageMemoryBarriers[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdBeginQueryArgs(YAML::Emitter &os, const CmdBeginQueryArgs &args) {
    os << YAML::Key << "queryPool";
    // queryPool -> Field -> VkQueryPool
    os << YAML::Value << args.queryPool;
    os << YAML::Key << "query";
    // query -> Field -> uint32_t
    os << YAML::Value << args.query;
    os << YAML::Key << "flags";
    // flags -> Field -> VkQueryControlFlags
    os << YAML::Value << args.flags;
}

void CommandPrinter::PrintCmdEndQueryArgs(YAML::Emitter &os, const CmdEndQueryArgs &args) {
    os << YAML::Key << "queryPool";
    // queryPool -> Field -> VkQueryPool
    os << YAML::Value << args.queryPool;
    os << YAML::Key << "query";
    // query -> Field -> uint32_t
    os << YAML::Value << args.query;
}

void CommandPrinter::PrintCmdResetQueryPoolArgs(YAML::Emitter &os, const CmdResetQueryPoolArgs &args) {
    os << YAML::Key << "queryPool";
    // queryPool -> Field -> VkQueryPool
    os << YAML::Value << args.queryPool;
    os << YAML::Key << "firstQuery";
    // firstQuery -> Field -> uint32_t
    os << YAML::Value << args.firstQuery;
    os << YAML::Key << "queryCount";
    // queryCount -> Field -> uint32_t
    os << YAML::Value << args.queryCount;
}

void CommandPrinter::PrintCmdWriteTimestampArgs(YAML::Emitter &os, const CmdWriteTimestampArgs &args) {
    os << YAML::Key << "pipelineStage";
    // pipelineStage -> Field -> VkPipelineStageFlagBits
    os << YAML::Value << args.pipelineStage;
    os << YAML::Key << "queryPool";
    // queryPool -> Field -> VkQueryPool
    os << YAML::Value << args.queryPool;
    os << YAML::Key << "query";
    // query -> Field -> uint32_t
    os << YAML::Value << args.query;
}

void CommandPrinter::PrintCmdCopyQueryPoolResultsArgs(YAML::Emitter &os, const CmdCopyQueryPoolResultsArgs &args) {
    os << YAML::Key << "queryPool";
    // queryPool -> Field -> VkQueryPool
    os << YAML::Value << args.queryPool;
    os << YAML::Key << "firstQuery";
    // firstQuery -> Field -> uint32_t
    os << YAML::Value << args.firstQuery;
    os << YAML::Key << "queryCount";
    // queryCount -> Field -> uint32_t
    os << YAML::Value << args.queryCount;
    os << YAML::Key << "dstBuffer";
    // dstBuffer -> Field -> VkBuffer
    os << YAML::Value << args.dstBuffer;
    os << YAML::Key << "dstOffset";
    // dstOffset -> Field -> VkDeviceSize
    os << YAML::Value << args.dstOffset;
    os << YAML::Key << "stride";
    // stride -> Field -> VkDeviceSize
    os << YAML::Value << args.stride;
    os << YAML::Key << "flags";
    // flags -> Field -> VkQueryResultFlags
    os << YAML::Value << args.flags;
}

void CommandPrinter::PrintCmdPushConstantsArgs(YAML::Emitter &os, const CmdPushConstantsArgs &args) {
    os << YAML::Key << "layout";
    // layout -> Field -> VkPipelineLayout
    os << YAML::Value << args.layout;
    os << YAML::Key << "stageFlags";
    // stageFlags -> Field -> VkShaderStageFlags
    os << YAML::Value << args.stageFlags;
    os << YAML::Key << "offset";
    // offset -> Field -> uint32_t
    os << YAML::Value << args.offset;
    os << YAML::Key << "size";
    // size -> Field -> uint32_t
    os << YAML::Value << args.size;
    os << YAML::Key << "pValues";
    if (args.size == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value << YAML::BeginSeq;
        {
            const uint8_t *p = (const uint8_t *)args.pValues;
            for (uint64_t i = 0; i < args.size; ++i) {
                os << crash_diagnostic_layer::Uint8ToStr(p[i]);
            }
        }
        os << YAML::EndSeq;
    }
}

void CommandPrinter::PrintCmdBeginRenderPassArgs(YAML::Emitter &os, const CmdBeginRenderPassArgs &args) {
    os << YAML::Key << "pRenderPassBegin";
    // pointer
    if (args.pRenderPassBegin != nullptr) {
        os << YAML::Value << *args.pRenderPassBegin;
    } else {
        os << YAML::Value << "nullptr";
    }
    os << YAML::Key << "contents";
    // contents -> Field -> VkSubpassContents
    os << YAML::Value << args.contents;
}

void CommandPrinter::PrintCmdNextSubpassArgs(YAML::Emitter &os, const CmdNextSubpassArgs &args) {
    os << YAML::Key << "contents";
    // contents -> Field -> VkSubpassContents
    os << YAML::Value << args.contents;
}

void CommandPrinter::PrintCmdEndRenderPassArgs(YAML::Emitter &os, const CmdEndRenderPassArgs &args) {}

void CommandPrinter::PrintCmdExecuteCommandsArgs(YAML::Emitter &os, const CmdExecuteCommandsArgs &args) {
    os << YAML::Key << "commandBufferCount";
    // commandBufferCount -> Field -> uint32_t
    os << YAML::Value << args.commandBufferCount;
    os << YAML::Key << "pCommandBuffers";
    // pCommandBuffers -> Field -> ConstDynamicArray(VkCommandBuffer)
    if (args.commandBufferCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkCommandBuffer");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.commandBufferCount; ++i) {
                os << args.pCommandBuffers[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdSetDeviceMaskArgs(YAML::Emitter &os, const CmdSetDeviceMaskArgs &args) {
    os << YAML::Key << "deviceMask";
    // deviceMask -> Field -> uint32_t
    os << YAML::Value << args.deviceMask;
}

void CommandPrinter::PrintCmdDispatchBaseArgs(YAML::Emitter &os, const CmdDispatchBaseArgs &args) {
    os << YAML::Key << "baseGroupX";
    // baseGroupX -> Field -> uint32_t
    os << YAML::Value << args.baseGroupX;
    os << YAML::Key << "baseGroupY";
    // baseGroupY -> Field -> uint32_t
    os << YAML::Value << args.baseGroupY;
    os << YAML::Key << "baseGroupZ";
    // baseGroupZ -> Field -> uint32_t
    os << YAML::Value << args.baseGroupZ;
    os << YAML::Key << "groupCountX";
    // groupCountX -> Field -> uint32_t
    os << YAML::Value << args.groupCountX;
    os << YAML::Key << "groupCountY";
    // groupCountY -> Field -> uint32_t
    os << YAML::Value << args.groupCountY;
    os << YAML::Key << "groupCountZ";
    // groupCountZ -> Field -> uint32_t
    os << YAML::Value << args.groupCountZ;
}

void CommandPrinter::PrintCmdDrawIndirectCountArgs(YAML::Emitter &os, const CmdDrawIndirectCountArgs &args) {
    os << YAML::Key << "buffer";
    // buffer -> Field -> VkBuffer
    os << YAML::Value << args.buffer;
    os << YAML::Key << "offset";
    // offset -> Field -> VkDeviceSize
    os << YAML::Value << args.offset;
    os << YAML::Key << "countBuffer";
    // countBuffer -> Field -> VkBuffer
    os << YAML::Value << args.countBuffer;
    os << YAML::Key << "countBufferOffset";
    // countBufferOffset -> Field -> VkDeviceSize
    os << YAML::Value << args.countBufferOffset;
    os << YAML::Key << "maxDrawCount";
    // maxDrawCount -> Field -> uint32_t
    os << YAML::Value << args.maxDrawCount;
    os << YAML::Key << "stride";
    // stride -> Field -> uint32_t
    os << YAML::Value << args.stride;
}

void CommandPrinter::PrintCmdDrawIndexedIndirectCountArgs(YAML::Emitter &os,
                                                          const CmdDrawIndexedIndirectCountArgs &args) {
    os << YAML::Key << "buffer";
    // buffer -> Field -> VkBuffer
    os << YAML::Value << args.buffer;
    os << YAML::Key << "offset";
    // offset -> Field -> VkDeviceSize
    os << YAML::Value << args.offset;
    os << YAML::Key << "countBuffer";
    // countBuffer -> Field -> VkBuffer
    os << YAML::Value << args.countBuffer;
    os << YAML::Key << "countBufferOffset";
    // countBufferOffset -> Field -> VkDeviceSize
    os << YAML::Value << args.countBufferOffset;
    os << YAML::Key << "maxDrawCount";
    // maxDrawCount -> Field -> uint32_t
    os << YAML::Value << args.maxDrawCount;
    os << YAML::Key << "stride";
    // stride -> Field -> uint32_t
    os << YAML::Value << args.stride;
}

void CommandPrinter::PrintCmdBeginRenderPass2Args(YAML::Emitter &os, const CmdBeginRenderPass2Args &args) {
    os << YAML::Key << "pRenderPassBegin";
    // pointer
    if (args.pRenderPassBegin != nullptr) {
        os << YAML::Value << *args.pRenderPassBegin;
    } else {
        os << YAML::Value << "nullptr";
    }
    os << YAML::Key << "pSubpassBeginInfo";
    // pointer
    if (args.pSubpassBeginInfo != nullptr) {
        os << YAML::Value << *args.pSubpassBeginInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdNextSubpass2Args(YAML::Emitter &os, const CmdNextSubpass2Args &args) {
    os << YAML::Key << "pSubpassBeginInfo";
    // pointer
    if (args.pSubpassBeginInfo != nullptr) {
        os << YAML::Value << *args.pSubpassBeginInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
    os << YAML::Key << "pSubpassEndInfo";
    // pointer
    if (args.pSubpassEndInfo != nullptr) {
        os << YAML::Value << *args.pSubpassEndInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdEndRenderPass2Args(YAML::Emitter &os, const CmdEndRenderPass2Args &args) {
    os << YAML::Key << "pSubpassEndInfo";
    // pointer
    if (args.pSubpassEndInfo != nullptr) {
        os << YAML::Value << *args.pSubpassEndInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdSetEvent2Args(YAML::Emitter &os, const CmdSetEvent2Args &args) {
    os << YAML::Key << "event";
    // event -> Field -> VkEvent
    os << YAML::Value << args.event;
    os << YAML::Key << "pDependencyInfo";
    // pointer
    if (args.pDependencyInfo != nullptr) {
        os << YAML::Value << *args.pDependencyInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdResetEvent2Args(YAML::Emitter &os, const CmdResetEvent2Args &args) {
    os << YAML::Key << "event";
    // event -> Field -> VkEvent
    os << YAML::Value << args.event;
    os << YAML::Key << "stageMask";
    // stageMask -> Field -> VkPipelineStageFlags2
    os << YAML::Value << args.stageMask;
}

void CommandPrinter::PrintCmdWaitEvents2Args(YAML::Emitter &os, const CmdWaitEvents2Args &args) {
    os << YAML::Key << "eventCount";
    // eventCount -> Field -> uint32_t
    os << YAML::Value << args.eventCount;
    os << YAML::Key << "pEvents";
    // pEvents -> Field -> ConstDynamicArray(VkEvent)
    if (args.eventCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkEvent");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.eventCount; ++i) {
                os << args.pEvents[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "pDependencyInfos";
    // pDependencyInfos -> Field -> ConstDynamicArray(VkDependencyInfo)
    if (args.eventCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkDependencyInfo");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.eventCount; ++i) {
                os << args.pDependencyInfos[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdPipelineBarrier2Args(YAML::Emitter &os, const CmdPipelineBarrier2Args &args) {
    os << YAML::Key << "pDependencyInfo";
    // pointer
    if (args.pDependencyInfo != nullptr) {
        os << YAML::Value << *args.pDependencyInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdWriteTimestamp2Args(YAML::Emitter &os, const CmdWriteTimestamp2Args &args) {
    os << YAML::Key << "stage";
    // stage -> Field -> VkPipelineStageFlags2
    os << YAML::Value << args.stage;
    os << YAML::Key << "queryPool";
    // queryPool -> Field -> VkQueryPool
    os << YAML::Value << args.queryPool;
    os << YAML::Key << "query";
    // query -> Field -> uint32_t
    os << YAML::Value << args.query;
}

void CommandPrinter::PrintCmdCopyBuffer2Args(YAML::Emitter &os, const CmdCopyBuffer2Args &args) {
    os << YAML::Key << "pCopyBufferInfo";
    // pointer
    if (args.pCopyBufferInfo != nullptr) {
        os << YAML::Value << *args.pCopyBufferInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdCopyImage2Args(YAML::Emitter &os, const CmdCopyImage2Args &args) {
    os << YAML::Key << "pCopyImageInfo";
    // pointer
    if (args.pCopyImageInfo != nullptr) {
        os << YAML::Value << *args.pCopyImageInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdCopyBufferToImage2Args(YAML::Emitter &os, const CmdCopyBufferToImage2Args &args) {
    os << YAML::Key << "pCopyBufferToImageInfo";
    // pointer
    if (args.pCopyBufferToImageInfo != nullptr) {
        os << YAML::Value << *args.pCopyBufferToImageInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdCopyImageToBuffer2Args(YAML::Emitter &os, const CmdCopyImageToBuffer2Args &args) {
    os << YAML::Key << "pCopyImageToBufferInfo";
    // pointer
    if (args.pCopyImageToBufferInfo != nullptr) {
        os << YAML::Value << *args.pCopyImageToBufferInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdBlitImage2Args(YAML::Emitter &os, const CmdBlitImage2Args &args) {
    os << YAML::Key << "pBlitImageInfo";
    // pointer
    if (args.pBlitImageInfo != nullptr) {
        os << YAML::Value << *args.pBlitImageInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdResolveImage2Args(YAML::Emitter &os, const CmdResolveImage2Args &args) {
    os << YAML::Key << "pResolveImageInfo";
    // pointer
    if (args.pResolveImageInfo != nullptr) {
        os << YAML::Value << *args.pResolveImageInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdBeginRenderingArgs(YAML::Emitter &os, const CmdBeginRenderingArgs &args) {
    os << YAML::Key << "pRenderingInfo";
    // pointer
    if (args.pRenderingInfo != nullptr) {
        os << YAML::Value << *args.pRenderingInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdEndRenderingArgs(YAML::Emitter &os, const CmdEndRenderingArgs &args) {}

void CommandPrinter::PrintCmdSetCullModeArgs(YAML::Emitter &os, const CmdSetCullModeArgs &args) {
    os << YAML::Key << "cullMode";
    // cullMode -> Field -> VkCullModeFlags
    os << YAML::Value << args.cullMode;
}

void CommandPrinter::PrintCmdSetFrontFaceArgs(YAML::Emitter &os, const CmdSetFrontFaceArgs &args) {
    os << YAML::Key << "frontFace";
    // frontFace -> Field -> VkFrontFace
    os << YAML::Value << args.frontFace;
}

void CommandPrinter::PrintCmdSetPrimitiveTopologyArgs(YAML::Emitter &os, const CmdSetPrimitiveTopologyArgs &args) {
    os << YAML::Key << "primitiveTopology";
    // primitiveTopology -> Field -> VkPrimitiveTopology
    os << YAML::Value << args.primitiveTopology;
}

void CommandPrinter::PrintCmdSetViewportWithCountArgs(YAML::Emitter &os, const CmdSetViewportWithCountArgs &args) {
    os << YAML::Key << "viewportCount";
    // viewportCount -> Field -> uint32_t
    os << YAML::Value << args.viewportCount;
    os << YAML::Key << "pViewports";
    // pViewports -> Field -> ConstDynamicArray(VkViewport)
    if (args.viewportCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkViewport");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.viewportCount; ++i) {
                os << args.pViewports[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdSetScissorWithCountArgs(YAML::Emitter &os, const CmdSetScissorWithCountArgs &args) {
    os << YAML::Key << "scissorCount";
    // scissorCount -> Field -> uint32_t
    os << YAML::Value << args.scissorCount;
    os << YAML::Key << "pScissors";
    // pScissors -> Field -> ConstDynamicArray(VkRect2D)
    if (args.scissorCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkRect2D");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.scissorCount; ++i) {
                os << args.pScissors[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdBindVertexBuffers2Args(YAML::Emitter &os, const CmdBindVertexBuffers2Args &args) {
    os << YAML::Key << "firstBinding";
    // firstBinding -> Field -> uint32_t
    os << YAML::Value << args.firstBinding;
    os << YAML::Key << "bindingCount";
    // bindingCount -> Field -> uint32_t
    os << YAML::Value << args.bindingCount;
    os << YAML::Key << "pBuffers";
    // pBuffers -> Field -> ConstDynamicArray(VkBuffer)
    if (args.bindingCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkBuffer");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.bindingCount; ++i) {
                os << args.pBuffers[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "pOffsets";
    // pOffsets -> Field -> ConstDynamicArray(VkDeviceSize)
    if (args.bindingCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkDeviceSize");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.bindingCount; ++i) {
                os << args.pOffsets[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "pSizes";
    // pSizes -> Field -> ConstDynamicArray(VkDeviceSize)
    if (args.bindingCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkDeviceSize");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.bindingCount; ++i) {
                os << args.pSizes[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "pStrides";
    // pStrides -> Field -> ConstDynamicArray(VkDeviceSize)
    if (args.bindingCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkDeviceSize");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.bindingCount; ++i) {
                os << args.pStrides[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdSetDepthTestEnableArgs(YAML::Emitter &os, const CmdSetDepthTestEnableArgs &args) {
    os << YAML::Key << "depthTestEnable";
    // depthTestEnable -> Field -> VkBool32
    os << YAML::Value << args.depthTestEnable;
}

void CommandPrinter::PrintCmdSetDepthWriteEnableArgs(YAML::Emitter &os, const CmdSetDepthWriteEnableArgs &args) {
    os << YAML::Key << "depthWriteEnable";
    // depthWriteEnable -> Field -> VkBool32
    os << YAML::Value << args.depthWriteEnable;
}

void CommandPrinter::PrintCmdSetDepthCompareOpArgs(YAML::Emitter &os, const CmdSetDepthCompareOpArgs &args) {
    os << YAML::Key << "depthCompareOp";
    // depthCompareOp -> Field -> VkCompareOp
    os << YAML::Value << args.depthCompareOp;
}

void CommandPrinter::PrintCmdSetDepthBoundsTestEnableArgs(YAML::Emitter &os,
                                                          const CmdSetDepthBoundsTestEnableArgs &args) {
    os << YAML::Key << "depthBoundsTestEnable";
    // depthBoundsTestEnable -> Field -> VkBool32
    os << YAML::Value << args.depthBoundsTestEnable;
}

void CommandPrinter::PrintCmdSetStencilTestEnableArgs(YAML::Emitter &os, const CmdSetStencilTestEnableArgs &args) {
    os << YAML::Key << "stencilTestEnable";
    // stencilTestEnable -> Field -> VkBool32
    os << YAML::Value << args.stencilTestEnable;
}

void CommandPrinter::PrintCmdSetStencilOpArgs(YAML::Emitter &os, const CmdSetStencilOpArgs &args) {
    os << YAML::Key << "faceMask";
    // faceMask -> Field -> VkStencilFaceFlags
    os << YAML::Value << args.faceMask;
    os << YAML::Key << "failOp";
    // failOp -> Field -> VkStencilOp
    os << YAML::Value << args.failOp;
    os << YAML::Key << "passOp";
    // passOp -> Field -> VkStencilOp
    os << YAML::Value << args.passOp;
    os << YAML::Key << "depthFailOp";
    // depthFailOp -> Field -> VkStencilOp
    os << YAML::Value << args.depthFailOp;
    os << YAML::Key << "compareOp";
    // compareOp -> Field -> VkCompareOp
    os << YAML::Value << args.compareOp;
}

void CommandPrinter::PrintCmdSetRasterizerDiscardEnableArgs(YAML::Emitter &os,
                                                            const CmdSetRasterizerDiscardEnableArgs &args) {
    os << YAML::Key << "rasterizerDiscardEnable";
    // rasterizerDiscardEnable -> Field -> VkBool32
    os << YAML::Value << args.rasterizerDiscardEnable;
}

void CommandPrinter::PrintCmdSetDepthBiasEnableArgs(YAML::Emitter &os, const CmdSetDepthBiasEnableArgs &args) {
    os << YAML::Key << "depthBiasEnable";
    // depthBiasEnable -> Field -> VkBool32
    os << YAML::Value << args.depthBiasEnable;
}

void CommandPrinter::PrintCmdSetPrimitiveRestartEnableArgs(YAML::Emitter &os,
                                                           const CmdSetPrimitiveRestartEnableArgs &args) {
    os << YAML::Key << "primitiveRestartEnable";
    // primitiveRestartEnable -> Field -> VkBool32
    os << YAML::Value << args.primitiveRestartEnable;
}

void CommandPrinter::PrintCmdBeginVideoCodingKHRArgs(YAML::Emitter &os, const CmdBeginVideoCodingKHRArgs &args) {
    os << YAML::Key << "pBeginInfo";
    // pointer
    if (args.pBeginInfo != nullptr) {
        os << YAML::Value << *args.pBeginInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdEndVideoCodingKHRArgs(YAML::Emitter &os, const CmdEndVideoCodingKHRArgs &args) {
    os << YAML::Key << "pEndCodingInfo";
    // pointer
    if (args.pEndCodingInfo != nullptr) {
        os << YAML::Value << *args.pEndCodingInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdControlVideoCodingKHRArgs(YAML::Emitter &os, const CmdControlVideoCodingKHRArgs &args) {
    os << YAML::Key << "pCodingControlInfo";
    // pointer
    if (args.pCodingControlInfo != nullptr) {
        os << YAML::Value << *args.pCodingControlInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdDecodeVideoKHRArgs(YAML::Emitter &os, const CmdDecodeVideoKHRArgs &args) {
    os << YAML::Key << "pDecodeInfo";
    // pointer
    if (args.pDecodeInfo != nullptr) {
        os << YAML::Value << *args.pDecodeInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdBeginRenderingKHRArgs(YAML::Emitter &os, const CmdBeginRenderingKHRArgs &args) {
    os << YAML::Key << "pRenderingInfo";
    // pointer
    if (args.pRenderingInfo != nullptr) {
        os << YAML::Value << *args.pRenderingInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdEndRenderingKHRArgs(YAML::Emitter &os, const CmdEndRenderingKHRArgs &args) {}

void CommandPrinter::PrintCmdSetDeviceMaskKHRArgs(YAML::Emitter &os, const CmdSetDeviceMaskKHRArgs &args) {
    os << YAML::Key << "deviceMask";
    // deviceMask -> Field -> uint32_t
    os << YAML::Value << args.deviceMask;
}

void CommandPrinter::PrintCmdDispatchBaseKHRArgs(YAML::Emitter &os, const CmdDispatchBaseKHRArgs &args) {
    os << YAML::Key << "baseGroupX";
    // baseGroupX -> Field -> uint32_t
    os << YAML::Value << args.baseGroupX;
    os << YAML::Key << "baseGroupY";
    // baseGroupY -> Field -> uint32_t
    os << YAML::Value << args.baseGroupY;
    os << YAML::Key << "baseGroupZ";
    // baseGroupZ -> Field -> uint32_t
    os << YAML::Value << args.baseGroupZ;
    os << YAML::Key << "groupCountX";
    // groupCountX -> Field -> uint32_t
    os << YAML::Value << args.groupCountX;
    os << YAML::Key << "groupCountY";
    // groupCountY -> Field -> uint32_t
    os << YAML::Value << args.groupCountY;
    os << YAML::Key << "groupCountZ";
    // groupCountZ -> Field -> uint32_t
    os << YAML::Value << args.groupCountZ;
}

void CommandPrinter::PrintCmdPushDescriptorSetKHRArgs(YAML::Emitter &os, const CmdPushDescriptorSetKHRArgs &args) {
    os << YAML::Key << "pipelineBindPoint";
    // pipelineBindPoint -> Field -> VkPipelineBindPoint
    os << YAML::Value << args.pipelineBindPoint;
    os << YAML::Key << "layout";
    // layout -> Field -> VkPipelineLayout
    os << YAML::Value << args.layout;
    os << YAML::Key << "set";
    // set -> Field -> uint32_t
    os << YAML::Value << args.set;
    os << YAML::Key << "descriptorWriteCount";
    // descriptorWriteCount -> Field -> uint32_t
    os << YAML::Value << args.descriptorWriteCount;
    os << YAML::Key << "pDescriptorWrites";
    // pDescriptorWrites -> Field -> ConstDynamicArray(VkWriteDescriptorSet)
    if (args.descriptorWriteCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkWriteDescriptorSet");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.descriptorWriteCount; ++i) {
                os << args.pDescriptorWrites[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdPushDescriptorSetWithTemplateKHRArgs(YAML::Emitter &os,
                                                                  const CmdPushDescriptorSetWithTemplateKHRArgs &args) {
    os << YAML::Key << "descriptorUpdateTemplate";
    // descriptorUpdateTemplate -> Field -> VkDescriptorUpdateTemplate
    os << YAML::Value << args.descriptorUpdateTemplate;
    os << YAML::Key << "layout";
    // layout -> Field -> VkPipelineLayout
    os << YAML::Value << args.layout;
    os << YAML::Key << "set";
    // set -> Field -> uint32_t
    os << YAML::Value << args.set;
    os << YAML::Key << "pData";
    // void
    os << YAML::Value << "NOT_AVAILABLE";
}

void CommandPrinter::PrintCmdBeginRenderPass2KHRArgs(YAML::Emitter &os, const CmdBeginRenderPass2KHRArgs &args) {
    os << YAML::Key << "pRenderPassBegin";
    // pointer
    if (args.pRenderPassBegin != nullptr) {
        os << YAML::Value << *args.pRenderPassBegin;
    } else {
        os << YAML::Value << "nullptr";
    }
    os << YAML::Key << "pSubpassBeginInfo";
    // pointer
    if (args.pSubpassBeginInfo != nullptr) {
        os << YAML::Value << *args.pSubpassBeginInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdNextSubpass2KHRArgs(YAML::Emitter &os, const CmdNextSubpass2KHRArgs &args) {
    os << YAML::Key << "pSubpassBeginInfo";
    // pointer
    if (args.pSubpassBeginInfo != nullptr) {
        os << YAML::Value << *args.pSubpassBeginInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
    os << YAML::Key << "pSubpassEndInfo";
    // pointer
    if (args.pSubpassEndInfo != nullptr) {
        os << YAML::Value << *args.pSubpassEndInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdEndRenderPass2KHRArgs(YAML::Emitter &os, const CmdEndRenderPass2KHRArgs &args) {
    os << YAML::Key << "pSubpassEndInfo";
    // pointer
    if (args.pSubpassEndInfo != nullptr) {
        os << YAML::Value << *args.pSubpassEndInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdDrawIndirectCountKHRArgs(YAML::Emitter &os, const CmdDrawIndirectCountKHRArgs &args) {
    os << YAML::Key << "buffer";
    // buffer -> Field -> VkBuffer
    os << YAML::Value << args.buffer;
    os << YAML::Key << "offset";
    // offset -> Field -> VkDeviceSize
    os << YAML::Value << args.offset;
    os << YAML::Key << "countBuffer";
    // countBuffer -> Field -> VkBuffer
    os << YAML::Value << args.countBuffer;
    os << YAML::Key << "countBufferOffset";
    // countBufferOffset -> Field -> VkDeviceSize
    os << YAML::Value << args.countBufferOffset;
    os << YAML::Key << "maxDrawCount";
    // maxDrawCount -> Field -> uint32_t
    os << YAML::Value << args.maxDrawCount;
    os << YAML::Key << "stride";
    // stride -> Field -> uint32_t
    os << YAML::Value << args.stride;
}

void CommandPrinter::PrintCmdDrawIndexedIndirectCountKHRArgs(YAML::Emitter &os,
                                                             const CmdDrawIndexedIndirectCountKHRArgs &args) {
    os << YAML::Key << "buffer";
    // buffer -> Field -> VkBuffer
    os << YAML::Value << args.buffer;
    os << YAML::Key << "offset";
    // offset -> Field -> VkDeviceSize
    os << YAML::Value << args.offset;
    os << YAML::Key << "countBuffer";
    // countBuffer -> Field -> VkBuffer
    os << YAML::Value << args.countBuffer;
    os << YAML::Key << "countBufferOffset";
    // countBufferOffset -> Field -> VkDeviceSize
    os << YAML::Value << args.countBufferOffset;
    os << YAML::Key << "maxDrawCount";
    // maxDrawCount -> Field -> uint32_t
    os << YAML::Value << args.maxDrawCount;
    os << YAML::Key << "stride";
    // stride -> Field -> uint32_t
    os << YAML::Value << args.stride;
}

void CommandPrinter::PrintCmdSetFragmentShadingRateKHRArgs(YAML::Emitter &os,
                                                           const CmdSetFragmentShadingRateKHRArgs &args) {
    os << YAML::Key << "pFragmentSize";
    // pointer
    if (args.pFragmentSize != nullptr) {
        os << YAML::Value << *args.pFragmentSize;
    } else {
        os << YAML::Value << "nullptr";
    }
    os << YAML::Key << "combinerOps";
    // combinerOps -> Field -> ConstFixedArray(VkFragmentShadingRateCombinerOpKHR)
    {
        os << YAML::Value;
        {
            os << YAML::Comment("VkFragmentShadingRateCombinerOpKHR");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < 2; ++i) {
                os << args.combinerOps[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdSetRenderingAttachmentLocationsKHRArgs(
    YAML::Emitter &os, const CmdSetRenderingAttachmentLocationsKHRArgs &args) {
    os << YAML::Key << "pLocationInfo";
    // pointer
    if (args.pLocationInfo != nullptr) {
        os << YAML::Value << *args.pLocationInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdSetRenderingInputAttachmentIndicesKHRArgs(
    YAML::Emitter &os, const CmdSetRenderingInputAttachmentIndicesKHRArgs &args) {
    os << YAML::Key << "pLocationInfo";
    // pointer
    if (args.pLocationInfo != nullptr) {
        os << YAML::Value << *args.pLocationInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdEncodeVideoKHRArgs(YAML::Emitter &os, const CmdEncodeVideoKHRArgs &args) {
    os << YAML::Key << "pEncodeInfo";
    // pointer
    if (args.pEncodeInfo != nullptr) {
        os << YAML::Value << *args.pEncodeInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdSetEvent2KHRArgs(YAML::Emitter &os, const CmdSetEvent2KHRArgs &args) {
    os << YAML::Key << "event";
    // event -> Field -> VkEvent
    os << YAML::Value << args.event;
    os << YAML::Key << "pDependencyInfo";
    // pointer
    if (args.pDependencyInfo != nullptr) {
        os << YAML::Value << *args.pDependencyInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdResetEvent2KHRArgs(YAML::Emitter &os, const CmdResetEvent2KHRArgs &args) {
    os << YAML::Key << "event";
    // event -> Field -> VkEvent
    os << YAML::Value << args.event;
    os << YAML::Key << "stageMask";
    // stageMask -> Field -> VkPipelineStageFlags2
    os << YAML::Value << args.stageMask;
}

void CommandPrinter::PrintCmdWaitEvents2KHRArgs(YAML::Emitter &os, const CmdWaitEvents2KHRArgs &args) {
    os << YAML::Key << "eventCount";
    // eventCount -> Field -> uint32_t
    os << YAML::Value << args.eventCount;
    os << YAML::Key << "pEvents";
    // pEvents -> Field -> ConstDynamicArray(VkEvent)
    if (args.eventCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkEvent");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.eventCount; ++i) {
                os << args.pEvents[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "pDependencyInfos";
    // pDependencyInfos -> Field -> ConstDynamicArray(VkDependencyInfo)
    if (args.eventCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkDependencyInfo");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.eventCount; ++i) {
                os << args.pDependencyInfos[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdPipelineBarrier2KHRArgs(YAML::Emitter &os, const CmdPipelineBarrier2KHRArgs &args) {
    os << YAML::Key << "pDependencyInfo";
    // pointer
    if (args.pDependencyInfo != nullptr) {
        os << YAML::Value << *args.pDependencyInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdWriteTimestamp2KHRArgs(YAML::Emitter &os, const CmdWriteTimestamp2KHRArgs &args) {
    os << YAML::Key << "stage";
    // stage -> Field -> VkPipelineStageFlags2
    os << YAML::Value << args.stage;
    os << YAML::Key << "queryPool";
    // queryPool -> Field -> VkQueryPool
    os << YAML::Value << args.queryPool;
    os << YAML::Key << "query";
    // query -> Field -> uint32_t
    os << YAML::Value << args.query;
}

void CommandPrinter::PrintCmdWriteBufferMarker2AMDArgs(YAML::Emitter &os, const CmdWriteBufferMarker2AMDArgs &args) {
    os << YAML::Key << "stage";
    // stage -> Field -> VkPipelineStageFlags2
    os << YAML::Value << args.stage;
    os << YAML::Key << "dstBuffer";
    // dstBuffer -> Field -> VkBuffer
    os << YAML::Value << args.dstBuffer;
    os << YAML::Key << "dstOffset";
    // dstOffset -> Field -> VkDeviceSize
    os << YAML::Value << args.dstOffset;
    os << YAML::Key << "marker";
    // marker -> Field -> uint32_t
    os << YAML::Value << args.marker;
}

void CommandPrinter::PrintCmdCopyBuffer2KHRArgs(YAML::Emitter &os, const CmdCopyBuffer2KHRArgs &args) {
    os << YAML::Key << "pCopyBufferInfo";
    // pointer
    if (args.pCopyBufferInfo != nullptr) {
        os << YAML::Value << *args.pCopyBufferInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdCopyImage2KHRArgs(YAML::Emitter &os, const CmdCopyImage2KHRArgs &args) {
    os << YAML::Key << "pCopyImageInfo";
    // pointer
    if (args.pCopyImageInfo != nullptr) {
        os << YAML::Value << *args.pCopyImageInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdCopyBufferToImage2KHRArgs(YAML::Emitter &os, const CmdCopyBufferToImage2KHRArgs &args) {
    os << YAML::Key << "pCopyBufferToImageInfo";
    // pointer
    if (args.pCopyBufferToImageInfo != nullptr) {
        os << YAML::Value << *args.pCopyBufferToImageInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdCopyImageToBuffer2KHRArgs(YAML::Emitter &os, const CmdCopyImageToBuffer2KHRArgs &args) {
    os << YAML::Key << "pCopyImageToBufferInfo";
    // pointer
    if (args.pCopyImageToBufferInfo != nullptr) {
        os << YAML::Value << *args.pCopyImageToBufferInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdBlitImage2KHRArgs(YAML::Emitter &os, const CmdBlitImage2KHRArgs &args) {
    os << YAML::Key << "pBlitImageInfo";
    // pointer
    if (args.pBlitImageInfo != nullptr) {
        os << YAML::Value << *args.pBlitImageInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdResolveImage2KHRArgs(YAML::Emitter &os, const CmdResolveImage2KHRArgs &args) {
    os << YAML::Key << "pResolveImageInfo";
    // pointer
    if (args.pResolveImageInfo != nullptr) {
        os << YAML::Value << *args.pResolveImageInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdTraceRaysIndirect2KHRArgs(YAML::Emitter &os, const CmdTraceRaysIndirect2KHRArgs &args) {
    os << YAML::Key << "indirectDeviceAddress";
    // indirectDeviceAddress -> Field -> VkDeviceAddress
    os << YAML::Value << args.indirectDeviceAddress;
}

void CommandPrinter::PrintCmdBindIndexBuffer2KHRArgs(YAML::Emitter &os, const CmdBindIndexBuffer2KHRArgs &args) {
    os << YAML::Key << "buffer";
    // buffer -> Field -> VkBuffer
    os << YAML::Value << args.buffer;
    os << YAML::Key << "offset";
    // offset -> Field -> VkDeviceSize
    os << YAML::Value << args.offset;
    os << YAML::Key << "size";
    // size -> Field -> VkDeviceSize
    os << YAML::Value << args.size;
    os << YAML::Key << "indexType";
    // indexType -> Field -> VkIndexType
    os << YAML::Value << args.indexType;
}

void CommandPrinter::PrintCmdSetLineStippleKHRArgs(YAML::Emitter &os, const CmdSetLineStippleKHRArgs &args) {
    os << YAML::Key << "lineStippleFactor";
    // lineStippleFactor -> Field -> uint32_t
    os << YAML::Value << args.lineStippleFactor;
    os << YAML::Key << "lineStipplePattern";
    // lineStipplePattern -> Field -> uint16_t
    os << YAML::Value << args.lineStipplePattern;
}

void CommandPrinter::PrintCmdBindDescriptorSets2KHRArgs(YAML::Emitter &os, const CmdBindDescriptorSets2KHRArgs &args) {
    os << YAML::Key << "pBindDescriptorSetsInfo";
    // pointer
    if (args.pBindDescriptorSetsInfo != nullptr) {
        os << YAML::Value << *args.pBindDescriptorSetsInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdPushConstants2KHRArgs(YAML::Emitter &os, const CmdPushConstants2KHRArgs &args) {
    os << YAML::Key << "pPushConstantsInfo";
    // pointer
    if (args.pPushConstantsInfo != nullptr) {
        os << YAML::Value << *args.pPushConstantsInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdPushDescriptorSet2KHRArgs(YAML::Emitter &os, const CmdPushDescriptorSet2KHRArgs &args) {
    os << YAML::Key << "pPushDescriptorSetInfo";
    // pointer
    if (args.pPushDescriptorSetInfo != nullptr) {
        os << YAML::Value << *args.pPushDescriptorSetInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdPushDescriptorSetWithTemplate2KHRArgs(
    YAML::Emitter &os, const CmdPushDescriptorSetWithTemplate2KHRArgs &args) {
    os << YAML::Key << "pPushDescriptorSetWithTemplateInfo";
    // pointer
    if (args.pPushDescriptorSetWithTemplateInfo != nullptr) {
        os << YAML::Value << *args.pPushDescriptorSetWithTemplateInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdSetDescriptorBufferOffsets2EXTArgs(YAML::Emitter &os,
                                                                const CmdSetDescriptorBufferOffsets2EXTArgs &args) {
    os << YAML::Key << "pSetDescriptorBufferOffsetsInfo";
    // pointer
    if (args.pSetDescriptorBufferOffsetsInfo != nullptr) {
        os << YAML::Value << *args.pSetDescriptorBufferOffsetsInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdBindDescriptorBufferEmbeddedSamplers2EXTArgs(
    YAML::Emitter &os, const CmdBindDescriptorBufferEmbeddedSamplers2EXTArgs &args) {
    os << YAML::Key << "pBindDescriptorBufferEmbeddedSamplersInfo";
    // pointer
    if (args.pBindDescriptorBufferEmbeddedSamplersInfo != nullptr) {
        os << YAML::Value << *args.pBindDescriptorBufferEmbeddedSamplersInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdDebugMarkerBeginEXTArgs(YAML::Emitter &os, const CmdDebugMarkerBeginEXTArgs &args) {
    os << YAML::Key << "pMarkerInfo";
    // pointer
    if (args.pMarkerInfo != nullptr) {
        os << YAML::Value << *args.pMarkerInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdDebugMarkerEndEXTArgs(YAML::Emitter &os, const CmdDebugMarkerEndEXTArgs &args) {}

void CommandPrinter::PrintCmdDebugMarkerInsertEXTArgs(YAML::Emitter &os, const CmdDebugMarkerInsertEXTArgs &args) {
    os << YAML::Key << "pMarkerInfo";
    // pointer
    if (args.pMarkerInfo != nullptr) {
        os << YAML::Value << *args.pMarkerInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdBindTransformFeedbackBuffersEXTArgs(YAML::Emitter &os,
                                                                 const CmdBindTransformFeedbackBuffersEXTArgs &args) {
    os << YAML::Key << "firstBinding";
    // firstBinding -> Field -> uint32_t
    os << YAML::Value << args.firstBinding;
    os << YAML::Key << "bindingCount";
    // bindingCount -> Field -> uint32_t
    os << YAML::Value << args.bindingCount;
    os << YAML::Key << "pBuffers";
    // pBuffers -> Field -> ConstDynamicArray(VkBuffer)
    if (args.bindingCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkBuffer");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.bindingCount; ++i) {
                os << args.pBuffers[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "pOffsets";
    // pOffsets -> Field -> ConstDynamicArray(VkDeviceSize)
    if (args.bindingCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkDeviceSize");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.bindingCount; ++i) {
                os << args.pOffsets[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "pSizes";
    // pSizes -> Field -> ConstDynamicArray(VkDeviceSize)
    if (args.bindingCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkDeviceSize");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.bindingCount; ++i) {
                os << args.pSizes[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdBeginTransformFeedbackEXTArgs(YAML::Emitter &os,
                                                           const CmdBeginTransformFeedbackEXTArgs &args) {
    os << YAML::Key << "firstCounterBuffer";
    // firstCounterBuffer -> Field -> uint32_t
    os << YAML::Value << args.firstCounterBuffer;
    os << YAML::Key << "counterBufferCount";
    // counterBufferCount -> Field -> uint32_t
    os << YAML::Value << args.counterBufferCount;
    os << YAML::Key << "pCounterBuffers";
    // pCounterBuffers -> Field -> ConstDynamicArray(VkBuffer)
    if (args.counterBufferCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkBuffer");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.counterBufferCount; ++i) {
                os << args.pCounterBuffers[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "pCounterBufferOffsets";
    // pCounterBufferOffsets -> Field -> ConstDynamicArray(VkDeviceSize)
    if (args.counterBufferCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkDeviceSize");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.counterBufferCount; ++i) {
                os << args.pCounterBufferOffsets[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdEndTransformFeedbackEXTArgs(YAML::Emitter &os,
                                                         const CmdEndTransformFeedbackEXTArgs &args) {
    os << YAML::Key << "firstCounterBuffer";
    // firstCounterBuffer -> Field -> uint32_t
    os << YAML::Value << args.firstCounterBuffer;
    os << YAML::Key << "counterBufferCount";
    // counterBufferCount -> Field -> uint32_t
    os << YAML::Value << args.counterBufferCount;
    os << YAML::Key << "pCounterBuffers";
    // pCounterBuffers -> Field -> ConstDynamicArray(VkBuffer)
    if (args.counterBufferCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkBuffer");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.counterBufferCount; ++i) {
                os << args.pCounterBuffers[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "pCounterBufferOffsets";
    // pCounterBufferOffsets -> Field -> ConstDynamicArray(VkDeviceSize)
    if (args.counterBufferCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkDeviceSize");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.counterBufferCount; ++i) {
                os << args.pCounterBufferOffsets[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdBeginQueryIndexedEXTArgs(YAML::Emitter &os, const CmdBeginQueryIndexedEXTArgs &args) {
    os << YAML::Key << "queryPool";
    // queryPool -> Field -> VkQueryPool
    os << YAML::Value << args.queryPool;
    os << YAML::Key << "query";
    // query -> Field -> uint32_t
    os << YAML::Value << args.query;
    os << YAML::Key << "flags";
    // flags -> Field -> VkQueryControlFlags
    os << YAML::Value << args.flags;
    os << YAML::Key << "index";
    // index -> Field -> uint32_t
    os << YAML::Value << args.index;
}

void CommandPrinter::PrintCmdEndQueryIndexedEXTArgs(YAML::Emitter &os, const CmdEndQueryIndexedEXTArgs &args) {
    os << YAML::Key << "queryPool";
    // queryPool -> Field -> VkQueryPool
    os << YAML::Value << args.queryPool;
    os << YAML::Key << "query";
    // query -> Field -> uint32_t
    os << YAML::Value << args.query;
    os << YAML::Key << "index";
    // index -> Field -> uint32_t
    os << YAML::Value << args.index;
}

void CommandPrinter::PrintCmdDrawIndirectByteCountEXTArgs(YAML::Emitter &os,
                                                          const CmdDrawIndirectByteCountEXTArgs &args) {
    os << YAML::Key << "instanceCount";
    // instanceCount -> Field -> uint32_t
    os << YAML::Value << args.instanceCount;
    os << YAML::Key << "firstInstance";
    // firstInstance -> Field -> uint32_t
    os << YAML::Value << args.firstInstance;
    os << YAML::Key << "counterBuffer";
    // counterBuffer -> Field -> VkBuffer
    os << YAML::Value << args.counterBuffer;
    os << YAML::Key << "counterBufferOffset";
    // counterBufferOffset -> Field -> VkDeviceSize
    os << YAML::Value << args.counterBufferOffset;
    os << YAML::Key << "counterOffset";
    // counterOffset -> Field -> uint32_t
    os << YAML::Value << args.counterOffset;
    os << YAML::Key << "vertexStride";
    // vertexStride -> Field -> uint32_t
    os << YAML::Value << args.vertexStride;
}

void CommandPrinter::PrintCmdCuLaunchKernelNVXArgs(YAML::Emitter &os, const CmdCuLaunchKernelNVXArgs &args) {
    os << YAML::Key << "pLaunchInfo";
    // pointer
    if (args.pLaunchInfo != nullptr) {
        os << YAML::Value << *args.pLaunchInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdDrawIndirectCountAMDArgs(YAML::Emitter &os, const CmdDrawIndirectCountAMDArgs &args) {
    os << YAML::Key << "buffer";
    // buffer -> Field -> VkBuffer
    os << YAML::Value << args.buffer;
    os << YAML::Key << "offset";
    // offset -> Field -> VkDeviceSize
    os << YAML::Value << args.offset;
    os << YAML::Key << "countBuffer";
    // countBuffer -> Field -> VkBuffer
    os << YAML::Value << args.countBuffer;
    os << YAML::Key << "countBufferOffset";
    // countBufferOffset -> Field -> VkDeviceSize
    os << YAML::Value << args.countBufferOffset;
    os << YAML::Key << "maxDrawCount";
    // maxDrawCount -> Field -> uint32_t
    os << YAML::Value << args.maxDrawCount;
    os << YAML::Key << "stride";
    // stride -> Field -> uint32_t
    os << YAML::Value << args.stride;
}

void CommandPrinter::PrintCmdDrawIndexedIndirectCountAMDArgs(YAML::Emitter &os,
                                                             const CmdDrawIndexedIndirectCountAMDArgs &args) {
    os << YAML::Key << "buffer";
    // buffer -> Field -> VkBuffer
    os << YAML::Value << args.buffer;
    os << YAML::Key << "offset";
    // offset -> Field -> VkDeviceSize
    os << YAML::Value << args.offset;
    os << YAML::Key << "countBuffer";
    // countBuffer -> Field -> VkBuffer
    os << YAML::Value << args.countBuffer;
    os << YAML::Key << "countBufferOffset";
    // countBufferOffset -> Field -> VkDeviceSize
    os << YAML::Value << args.countBufferOffset;
    os << YAML::Key << "maxDrawCount";
    // maxDrawCount -> Field -> uint32_t
    os << YAML::Value << args.maxDrawCount;
    os << YAML::Key << "stride";
    // stride -> Field -> uint32_t
    os << YAML::Value << args.stride;
}

void CommandPrinter::PrintCmdBeginConditionalRenderingEXTArgs(YAML::Emitter &os,
                                                              const CmdBeginConditionalRenderingEXTArgs &args) {
    os << YAML::Key << "pConditionalRenderingBegin";
    // pointer
    if (args.pConditionalRenderingBegin != nullptr) {
        os << YAML::Value << *args.pConditionalRenderingBegin;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdEndConditionalRenderingEXTArgs(YAML::Emitter &os,
                                                            const CmdEndConditionalRenderingEXTArgs &args) {}

void CommandPrinter::PrintCmdSetViewportWScalingNVArgs(YAML::Emitter &os, const CmdSetViewportWScalingNVArgs &args) {
    os << YAML::Key << "firstViewport";
    // firstViewport -> Field -> uint32_t
    os << YAML::Value << args.firstViewport;
    os << YAML::Key << "viewportCount";
    // viewportCount -> Field -> uint32_t
    os << YAML::Value << args.viewportCount;
    os << YAML::Key << "pViewportWScalings";
    // pViewportWScalings -> Field -> ConstDynamicArray(VkViewportWScalingNV)
    if (args.viewportCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkViewportWScalingNV");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.viewportCount; ++i) {
                os << args.pViewportWScalings[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdSetDiscardRectangleEXTArgs(YAML::Emitter &os, const CmdSetDiscardRectangleEXTArgs &args) {
    os << YAML::Key << "firstDiscardRectangle";
    // firstDiscardRectangle -> Field -> uint32_t
    os << YAML::Value << args.firstDiscardRectangle;
    os << YAML::Key << "discardRectangleCount";
    // discardRectangleCount -> Field -> uint32_t
    os << YAML::Value << args.discardRectangleCount;
    os << YAML::Key << "pDiscardRectangles";
    // pDiscardRectangles -> Field -> ConstDynamicArray(VkRect2D)
    if (args.discardRectangleCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkRect2D");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.discardRectangleCount; ++i) {
                os << args.pDiscardRectangles[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdSetDiscardRectangleEnableEXTArgs(YAML::Emitter &os,
                                                              const CmdSetDiscardRectangleEnableEXTArgs &args) {
    os << YAML::Key << "discardRectangleEnable";
    // discardRectangleEnable -> Field -> VkBool32
    os << YAML::Value << args.discardRectangleEnable;
}

void CommandPrinter::PrintCmdSetDiscardRectangleModeEXTArgs(YAML::Emitter &os,
                                                            const CmdSetDiscardRectangleModeEXTArgs &args) {
    os << YAML::Key << "discardRectangleMode";
    // discardRectangleMode -> Field -> VkDiscardRectangleModeEXT
    os << YAML::Value << args.discardRectangleMode;
}

void CommandPrinter::PrintCmdBeginDebugUtilsLabelEXTArgs(YAML::Emitter &os,
                                                         const CmdBeginDebugUtilsLabelEXTArgs &args) {
    os << YAML::Key << "pLabelInfo";
    // pointer
    if (args.pLabelInfo != nullptr) {
        os << YAML::Value << *args.pLabelInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdEndDebugUtilsLabelEXTArgs(YAML::Emitter &os, const CmdEndDebugUtilsLabelEXTArgs &args) {}

void CommandPrinter::PrintCmdInsertDebugUtilsLabelEXTArgs(YAML::Emitter &os,
                                                          const CmdInsertDebugUtilsLabelEXTArgs &args) {
    os << YAML::Key << "pLabelInfo";
    // pointer
    if (args.pLabelInfo != nullptr) {
        os << YAML::Value << *args.pLabelInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

#ifdef VK_ENABLE_BETA_EXTENSIONS
void CommandPrinter::PrintCmdInitializeGraphScratchMemoryAMDXArgs(YAML::Emitter &os,
                                                                  const CmdInitializeGraphScratchMemoryAMDXArgs &args) {
    os << YAML::Key << "scratch";
    // scratch -> Field -> VkDeviceAddress
    os << YAML::Value << args.scratch;
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void CommandPrinter::PrintCmdDispatchGraphAMDXArgs(YAML::Emitter &os, const CmdDispatchGraphAMDXArgs &args) {
    os << YAML::Key << "scratch";
    // scratch -> Field -> VkDeviceAddress
    os << YAML::Value << args.scratch;
    os << YAML::Key << "pCountInfo";
    // pointer
    if (args.pCountInfo != nullptr) {
        os << YAML::Value << *args.pCountInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void CommandPrinter::PrintCmdDispatchGraphIndirectAMDXArgs(YAML::Emitter &os,
                                                           const CmdDispatchGraphIndirectAMDXArgs &args) {
    os << YAML::Key << "scratch";
    // scratch -> Field -> VkDeviceAddress
    os << YAML::Value << args.scratch;
    os << YAML::Key << "pCountInfo";
    // pointer
    if (args.pCountInfo != nullptr) {
        os << YAML::Value << *args.pCountInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void CommandPrinter::PrintCmdDispatchGraphIndirectCountAMDXArgs(YAML::Emitter &os,
                                                                const CmdDispatchGraphIndirectCountAMDXArgs &args) {
    os << YAML::Key << "scratch";
    // scratch -> Field -> VkDeviceAddress
    os << YAML::Value << args.scratch;
    os << YAML::Key << "countInfo";
    // countInfo -> Field -> VkDeviceAddress
    os << YAML::Value << args.countInfo;
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

void CommandPrinter::PrintCmdSetSampleLocationsEXTArgs(YAML::Emitter &os, const CmdSetSampleLocationsEXTArgs &args) {
    os << YAML::Key << "pSampleLocationsInfo";
    // pointer
    if (args.pSampleLocationsInfo != nullptr) {
        os << YAML::Value << *args.pSampleLocationsInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdBindShadingRateImageNVArgs(YAML::Emitter &os, const CmdBindShadingRateImageNVArgs &args) {
    os << YAML::Key << "imageView";
    // imageView -> Field -> VkImageView
    os << YAML::Value << args.imageView;
    os << YAML::Key << "imageLayout";
    // imageLayout -> Field -> VkImageLayout
    os << YAML::Value << args.imageLayout;
}

void CommandPrinter::PrintCmdSetViewportShadingRatePaletteNVArgs(YAML::Emitter &os,
                                                                 const CmdSetViewportShadingRatePaletteNVArgs &args) {
    os << YAML::Key << "firstViewport";
    // firstViewport -> Field -> uint32_t
    os << YAML::Value << args.firstViewport;
    os << YAML::Key << "viewportCount";
    // viewportCount -> Field -> uint32_t
    os << YAML::Value << args.viewportCount;
    os << YAML::Key << "pShadingRatePalettes";
    // pShadingRatePalettes -> Field -> ConstDynamicArray(VkShadingRatePaletteNV)
    if (args.viewportCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkShadingRatePaletteNV");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.viewportCount; ++i) {
                os << args.pShadingRatePalettes[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdSetCoarseSampleOrderNVArgs(YAML::Emitter &os, const CmdSetCoarseSampleOrderNVArgs &args) {
    os << YAML::Key << "sampleOrderType";
    // sampleOrderType -> Field -> VkCoarseSampleOrderTypeNV
    os << YAML::Value << args.sampleOrderType;
    os << YAML::Key << "customSampleOrderCount";
    // customSampleOrderCount -> Field -> uint32_t
    os << YAML::Value << args.customSampleOrderCount;
    os << YAML::Key << "pCustomSampleOrders";
    // pCustomSampleOrders -> Field -> ConstDynamicArray(VkCoarseSampleOrderCustomNV)
    if (args.customSampleOrderCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkCoarseSampleOrderCustomNV");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.customSampleOrderCount; ++i) {
                os << args.pCustomSampleOrders[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdBuildAccelerationStructureNVArgs(YAML::Emitter &os,
                                                              const CmdBuildAccelerationStructureNVArgs &args) {
    os << YAML::Key << "pInfo";
    // pointer
    if (args.pInfo != nullptr) {
        os << YAML::Value << *args.pInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
    os << YAML::Key << "instanceData";
    // instanceData -> Field -> VkBuffer
    os << YAML::Value << args.instanceData;
    os << YAML::Key << "instanceOffset";
    // instanceOffset -> Field -> VkDeviceSize
    os << YAML::Value << args.instanceOffset;
    os << YAML::Key << "update";
    // update -> Field -> VkBool32
    os << YAML::Value << args.update;
    os << YAML::Key << "dst";
    // dst -> Field -> VkAccelerationStructureNV
    os << YAML::Value << args.dst;
    os << YAML::Key << "src";
    // src -> Field -> VkAccelerationStructureNV
    os << YAML::Value << args.src;
    os << YAML::Key << "scratch";
    // scratch -> Field -> VkBuffer
    os << YAML::Value << args.scratch;
    os << YAML::Key << "scratchOffset";
    // scratchOffset -> Field -> VkDeviceSize
    os << YAML::Value << args.scratchOffset;
}

void CommandPrinter::PrintCmdCopyAccelerationStructureNVArgs(YAML::Emitter &os,
                                                             const CmdCopyAccelerationStructureNVArgs &args) {
    os << YAML::Key << "dst";
    // dst -> Field -> VkAccelerationStructureNV
    os << YAML::Value << args.dst;
    os << YAML::Key << "src";
    // src -> Field -> VkAccelerationStructureNV
    os << YAML::Value << args.src;
    os << YAML::Key << "mode";
    // mode -> Field -> VkCopyAccelerationStructureModeKHR
    os << YAML::Value << args.mode;
}

void CommandPrinter::PrintCmdTraceRaysNVArgs(YAML::Emitter &os, const CmdTraceRaysNVArgs &args) {
    os << YAML::Key << "raygenShaderBindingTableBuffer";
    // raygenShaderBindingTableBuffer -> Field -> VkBuffer
    os << YAML::Value << args.raygenShaderBindingTableBuffer;
    os << YAML::Key << "raygenShaderBindingOffset";
    // raygenShaderBindingOffset -> Field -> VkDeviceSize
    os << YAML::Value << args.raygenShaderBindingOffset;
    os << YAML::Key << "missShaderBindingTableBuffer";
    // missShaderBindingTableBuffer -> Field -> VkBuffer
    os << YAML::Value << args.missShaderBindingTableBuffer;
    os << YAML::Key << "missShaderBindingOffset";
    // missShaderBindingOffset -> Field -> VkDeviceSize
    os << YAML::Value << args.missShaderBindingOffset;
    os << YAML::Key << "missShaderBindingStride";
    // missShaderBindingStride -> Field -> VkDeviceSize
    os << YAML::Value << args.missShaderBindingStride;
    os << YAML::Key << "hitShaderBindingTableBuffer";
    // hitShaderBindingTableBuffer -> Field -> VkBuffer
    os << YAML::Value << args.hitShaderBindingTableBuffer;
    os << YAML::Key << "hitShaderBindingOffset";
    // hitShaderBindingOffset -> Field -> VkDeviceSize
    os << YAML::Value << args.hitShaderBindingOffset;
    os << YAML::Key << "hitShaderBindingStride";
    // hitShaderBindingStride -> Field -> VkDeviceSize
    os << YAML::Value << args.hitShaderBindingStride;
    os << YAML::Key << "callableShaderBindingTableBuffer";
    // callableShaderBindingTableBuffer -> Field -> VkBuffer
    os << YAML::Value << args.callableShaderBindingTableBuffer;
    os << YAML::Key << "callableShaderBindingOffset";
    // callableShaderBindingOffset -> Field -> VkDeviceSize
    os << YAML::Value << args.callableShaderBindingOffset;
    os << YAML::Key << "callableShaderBindingStride";
    // callableShaderBindingStride -> Field -> VkDeviceSize
    os << YAML::Value << args.callableShaderBindingStride;
    os << YAML::Key << "width";
    // width -> Field -> uint32_t
    os << YAML::Value << args.width;
    os << YAML::Key << "height";
    // height -> Field -> uint32_t
    os << YAML::Value << args.height;
    os << YAML::Key << "depth";
    // depth -> Field -> uint32_t
    os << YAML::Value << args.depth;
}

void CommandPrinter::PrintCmdWriteAccelerationStructuresPropertiesNVArgs(
    YAML::Emitter &os, const CmdWriteAccelerationStructuresPropertiesNVArgs &args) {
    os << YAML::Key << "accelerationStructureCount";
    // accelerationStructureCount -> Field -> uint32_t
    os << YAML::Value << args.accelerationStructureCount;
    os << YAML::Key << "pAccelerationStructures";
    // pAccelerationStructures -> Field -> ConstDynamicArray(VkAccelerationStructureNV)
    if (args.accelerationStructureCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkAccelerationStructureNV");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.accelerationStructureCount; ++i) {
                os << args.pAccelerationStructures[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "queryType";
    // queryType -> Field -> VkQueryType
    os << YAML::Value << args.queryType;
    os << YAML::Key << "queryPool";
    // queryPool -> Field -> VkQueryPool
    os << YAML::Value << args.queryPool;
    os << YAML::Key << "firstQuery";
    // firstQuery -> Field -> uint32_t
    os << YAML::Value << args.firstQuery;
}

void CommandPrinter::PrintCmdWriteBufferMarkerAMDArgs(YAML::Emitter &os, const CmdWriteBufferMarkerAMDArgs &args) {
    os << YAML::Key << "pipelineStage";
    // pipelineStage -> Field -> VkPipelineStageFlagBits
    os << YAML::Value << args.pipelineStage;
    os << YAML::Key << "dstBuffer";
    // dstBuffer -> Field -> VkBuffer
    os << YAML::Value << args.dstBuffer;
    os << YAML::Key << "dstOffset";
    // dstOffset -> Field -> VkDeviceSize
    os << YAML::Value << args.dstOffset;
    os << YAML::Key << "marker";
    // marker -> Field -> uint32_t
    os << YAML::Value << args.marker;
}

void CommandPrinter::PrintCmdDrawMeshTasksNVArgs(YAML::Emitter &os, const CmdDrawMeshTasksNVArgs &args) {
    os << YAML::Key << "taskCount";
    // taskCount -> Field -> uint32_t
    os << YAML::Value << args.taskCount;
    os << YAML::Key << "firstTask";
    // firstTask -> Field -> uint32_t
    os << YAML::Value << args.firstTask;
}

void CommandPrinter::PrintCmdDrawMeshTasksIndirectNVArgs(YAML::Emitter &os,
                                                         const CmdDrawMeshTasksIndirectNVArgs &args) {
    os << YAML::Key << "buffer";
    // buffer -> Field -> VkBuffer
    os << YAML::Value << args.buffer;
    os << YAML::Key << "offset";
    // offset -> Field -> VkDeviceSize
    os << YAML::Value << args.offset;
    os << YAML::Key << "drawCount";
    // drawCount -> Field -> uint32_t
    os << YAML::Value << args.drawCount;
    os << YAML::Key << "stride";
    // stride -> Field -> uint32_t
    os << YAML::Value << args.stride;
}

void CommandPrinter::PrintCmdDrawMeshTasksIndirectCountNVArgs(YAML::Emitter &os,
                                                              const CmdDrawMeshTasksIndirectCountNVArgs &args) {
    os << YAML::Key << "buffer";
    // buffer -> Field -> VkBuffer
    os << YAML::Value << args.buffer;
    os << YAML::Key << "offset";
    // offset -> Field -> VkDeviceSize
    os << YAML::Value << args.offset;
    os << YAML::Key << "countBuffer";
    // countBuffer -> Field -> VkBuffer
    os << YAML::Value << args.countBuffer;
    os << YAML::Key << "countBufferOffset";
    // countBufferOffset -> Field -> VkDeviceSize
    os << YAML::Value << args.countBufferOffset;
    os << YAML::Key << "maxDrawCount";
    // maxDrawCount -> Field -> uint32_t
    os << YAML::Value << args.maxDrawCount;
    os << YAML::Key << "stride";
    // stride -> Field -> uint32_t
    os << YAML::Value << args.stride;
}

void CommandPrinter::PrintCmdSetExclusiveScissorEnableNVArgs(YAML::Emitter &os,
                                                             const CmdSetExclusiveScissorEnableNVArgs &args) {
    os << YAML::Key << "firstExclusiveScissor";
    // firstExclusiveScissor -> Field -> uint32_t
    os << YAML::Value << args.firstExclusiveScissor;
    os << YAML::Key << "exclusiveScissorCount";
    // exclusiveScissorCount -> Field -> uint32_t
    os << YAML::Value << args.exclusiveScissorCount;
    os << YAML::Key << "pExclusiveScissorEnables";
    // pExclusiveScissorEnables -> Field -> ConstDynamicArray(VkBool32)
    if (args.exclusiveScissorCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkBool32");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.exclusiveScissorCount; ++i) {
                os << args.pExclusiveScissorEnables[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdSetExclusiveScissorNVArgs(YAML::Emitter &os, const CmdSetExclusiveScissorNVArgs &args) {
    os << YAML::Key << "firstExclusiveScissor";
    // firstExclusiveScissor -> Field -> uint32_t
    os << YAML::Value << args.firstExclusiveScissor;
    os << YAML::Key << "exclusiveScissorCount";
    // exclusiveScissorCount -> Field -> uint32_t
    os << YAML::Value << args.exclusiveScissorCount;
    os << YAML::Key << "pExclusiveScissors";
    // pExclusiveScissors -> Field -> ConstDynamicArray(VkRect2D)
    if (args.exclusiveScissorCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkRect2D");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.exclusiveScissorCount; ++i) {
                os << args.pExclusiveScissors[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdSetCheckpointNVArgs(YAML::Emitter &os, const CmdSetCheckpointNVArgs &args) {
    os << YAML::Key << "pCheckpointMarker";
    // void
    os << YAML::Value << "NOT_AVAILABLE";
}

void CommandPrinter::PrintCmdSetPerformanceMarkerINTELArgs(YAML::Emitter &os,
                                                           const CmdSetPerformanceMarkerINTELArgs &args) {
    os << YAML::Key << "pMarkerInfo";
    // pointer
    if (args.pMarkerInfo != nullptr) {
        os << YAML::Value << *args.pMarkerInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdSetPerformanceStreamMarkerINTELArgs(YAML::Emitter &os,
                                                                 const CmdSetPerformanceStreamMarkerINTELArgs &args) {
    os << YAML::Key << "pMarkerInfo";
    // pointer
    if (args.pMarkerInfo != nullptr) {
        os << YAML::Value << *args.pMarkerInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdSetPerformanceOverrideINTELArgs(YAML::Emitter &os,
                                                             const CmdSetPerformanceOverrideINTELArgs &args) {
    os << YAML::Key << "pOverrideInfo";
    // pointer
    if (args.pOverrideInfo != nullptr) {
        os << YAML::Value << *args.pOverrideInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdSetLineStippleEXTArgs(YAML::Emitter &os, const CmdSetLineStippleEXTArgs &args) {
    os << YAML::Key << "lineStippleFactor";
    // lineStippleFactor -> Field -> uint32_t
    os << YAML::Value << args.lineStippleFactor;
    os << YAML::Key << "lineStipplePattern";
    // lineStipplePattern -> Field -> uint16_t
    os << YAML::Value << args.lineStipplePattern;
}

void CommandPrinter::PrintCmdSetCullModeEXTArgs(YAML::Emitter &os, const CmdSetCullModeEXTArgs &args) {
    os << YAML::Key << "cullMode";
    // cullMode -> Field -> VkCullModeFlags
    os << YAML::Value << args.cullMode;
}

void CommandPrinter::PrintCmdSetFrontFaceEXTArgs(YAML::Emitter &os, const CmdSetFrontFaceEXTArgs &args) {
    os << YAML::Key << "frontFace";
    // frontFace -> Field -> VkFrontFace
    os << YAML::Value << args.frontFace;
}

void CommandPrinter::PrintCmdSetPrimitiveTopologyEXTArgs(YAML::Emitter &os,
                                                         const CmdSetPrimitiveTopologyEXTArgs &args) {
    os << YAML::Key << "primitiveTopology";
    // primitiveTopology -> Field -> VkPrimitiveTopology
    os << YAML::Value << args.primitiveTopology;
}

void CommandPrinter::PrintCmdSetViewportWithCountEXTArgs(YAML::Emitter &os,
                                                         const CmdSetViewportWithCountEXTArgs &args) {
    os << YAML::Key << "viewportCount";
    // viewportCount -> Field -> uint32_t
    os << YAML::Value << args.viewportCount;
    os << YAML::Key << "pViewports";
    // pViewports -> Field -> ConstDynamicArray(VkViewport)
    if (args.viewportCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkViewport");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.viewportCount; ++i) {
                os << args.pViewports[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdSetScissorWithCountEXTArgs(YAML::Emitter &os, const CmdSetScissorWithCountEXTArgs &args) {
    os << YAML::Key << "scissorCount";
    // scissorCount -> Field -> uint32_t
    os << YAML::Value << args.scissorCount;
    os << YAML::Key << "pScissors";
    // pScissors -> Field -> ConstDynamicArray(VkRect2D)
    if (args.scissorCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkRect2D");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.scissorCount; ++i) {
                os << args.pScissors[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdBindVertexBuffers2EXTArgs(YAML::Emitter &os, const CmdBindVertexBuffers2EXTArgs &args) {
    os << YAML::Key << "firstBinding";
    // firstBinding -> Field -> uint32_t
    os << YAML::Value << args.firstBinding;
    os << YAML::Key << "bindingCount";
    // bindingCount -> Field -> uint32_t
    os << YAML::Value << args.bindingCount;
    os << YAML::Key << "pBuffers";
    // pBuffers -> Field -> ConstDynamicArray(VkBuffer)
    if (args.bindingCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkBuffer");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.bindingCount; ++i) {
                os << args.pBuffers[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "pOffsets";
    // pOffsets -> Field -> ConstDynamicArray(VkDeviceSize)
    if (args.bindingCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkDeviceSize");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.bindingCount; ++i) {
                os << args.pOffsets[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "pSizes";
    // pSizes -> Field -> ConstDynamicArray(VkDeviceSize)
    if (args.bindingCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkDeviceSize");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.bindingCount; ++i) {
                os << args.pSizes[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "pStrides";
    // pStrides -> Field -> ConstDynamicArray(VkDeviceSize)
    if (args.bindingCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkDeviceSize");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.bindingCount; ++i) {
                os << args.pStrides[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdSetDepthTestEnableEXTArgs(YAML::Emitter &os, const CmdSetDepthTestEnableEXTArgs &args) {
    os << YAML::Key << "depthTestEnable";
    // depthTestEnable -> Field -> VkBool32
    os << YAML::Value << args.depthTestEnable;
}

void CommandPrinter::PrintCmdSetDepthWriteEnableEXTArgs(YAML::Emitter &os, const CmdSetDepthWriteEnableEXTArgs &args) {
    os << YAML::Key << "depthWriteEnable";
    // depthWriteEnable -> Field -> VkBool32
    os << YAML::Value << args.depthWriteEnable;
}

void CommandPrinter::PrintCmdSetDepthCompareOpEXTArgs(YAML::Emitter &os, const CmdSetDepthCompareOpEXTArgs &args) {
    os << YAML::Key << "depthCompareOp";
    // depthCompareOp -> Field -> VkCompareOp
    os << YAML::Value << args.depthCompareOp;
}

void CommandPrinter::PrintCmdSetDepthBoundsTestEnableEXTArgs(YAML::Emitter &os,
                                                             const CmdSetDepthBoundsTestEnableEXTArgs &args) {
    os << YAML::Key << "depthBoundsTestEnable";
    // depthBoundsTestEnable -> Field -> VkBool32
    os << YAML::Value << args.depthBoundsTestEnable;
}

void CommandPrinter::PrintCmdSetStencilTestEnableEXTArgs(YAML::Emitter &os,
                                                         const CmdSetStencilTestEnableEXTArgs &args) {
    os << YAML::Key << "stencilTestEnable";
    // stencilTestEnable -> Field -> VkBool32
    os << YAML::Value << args.stencilTestEnable;
}

void CommandPrinter::PrintCmdSetStencilOpEXTArgs(YAML::Emitter &os, const CmdSetStencilOpEXTArgs &args) {
    os << YAML::Key << "faceMask";
    // faceMask -> Field -> VkStencilFaceFlags
    os << YAML::Value << args.faceMask;
    os << YAML::Key << "failOp";
    // failOp -> Field -> VkStencilOp
    os << YAML::Value << args.failOp;
    os << YAML::Key << "passOp";
    // passOp -> Field -> VkStencilOp
    os << YAML::Value << args.passOp;
    os << YAML::Key << "depthFailOp";
    // depthFailOp -> Field -> VkStencilOp
    os << YAML::Value << args.depthFailOp;
    os << YAML::Key << "compareOp";
    // compareOp -> Field -> VkCompareOp
    os << YAML::Value << args.compareOp;
}

void CommandPrinter::PrintCmdPreprocessGeneratedCommandsNVArgs(YAML::Emitter &os,
                                                               const CmdPreprocessGeneratedCommandsNVArgs &args) {
    os << YAML::Key << "pGeneratedCommandsInfo";
    // pointer
    if (args.pGeneratedCommandsInfo != nullptr) {
        os << YAML::Value << *args.pGeneratedCommandsInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdExecuteGeneratedCommandsNVArgs(YAML::Emitter &os,
                                                            const CmdExecuteGeneratedCommandsNVArgs &args) {
    os << YAML::Key << "isPreprocessed";
    // isPreprocessed -> Field -> VkBool32
    os << YAML::Value << args.isPreprocessed;
    os << YAML::Key << "pGeneratedCommandsInfo";
    // pointer
    if (args.pGeneratedCommandsInfo != nullptr) {
        os << YAML::Value << *args.pGeneratedCommandsInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdBindPipelineShaderGroupNVArgs(YAML::Emitter &os,
                                                           const CmdBindPipelineShaderGroupNVArgs &args) {
    os << YAML::Key << "pipelineBindPoint";
    // pipelineBindPoint -> Field -> VkPipelineBindPoint
    os << YAML::Value << args.pipelineBindPoint;
    os << YAML::Key << "pipeline";
    // pipeline -> Field -> VkPipeline
    os << YAML::Value << args.pipeline;
    os << YAML::Key << "groupIndex";
    // groupIndex -> Field -> uint32_t
    os << YAML::Value << args.groupIndex;
}

void CommandPrinter::PrintCmdSetDepthBias2EXTArgs(YAML::Emitter &os, const CmdSetDepthBias2EXTArgs &args) {
    os << YAML::Key << "pDepthBiasInfo";
    // pointer
    if (args.pDepthBiasInfo != nullptr) {
        os << YAML::Value << *args.pDepthBiasInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdCudaLaunchKernelNVArgs(YAML::Emitter &os, const CmdCudaLaunchKernelNVArgs &args) {
    os << YAML::Key << "pLaunchInfo";
    // pointer
    if (args.pLaunchInfo != nullptr) {
        os << YAML::Value << *args.pLaunchInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdBindDescriptorBuffersEXTArgs(YAML::Emitter &os,
                                                          const CmdBindDescriptorBuffersEXTArgs &args) {
    os << YAML::Key << "bufferCount";
    // bufferCount -> Field -> uint32_t
    os << YAML::Value << args.bufferCount;
    os << YAML::Key << "pBindingInfos";
    // pBindingInfos -> Field -> ConstDynamicArray(VkDescriptorBufferBindingInfoEXT)
    if (args.bufferCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkDescriptorBufferBindingInfoEXT");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.bufferCount; ++i) {
                os << args.pBindingInfos[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdSetDescriptorBufferOffsetsEXTArgs(YAML::Emitter &os,
                                                               const CmdSetDescriptorBufferOffsetsEXTArgs &args) {
    os << YAML::Key << "pipelineBindPoint";
    // pipelineBindPoint -> Field -> VkPipelineBindPoint
    os << YAML::Value << args.pipelineBindPoint;
    os << YAML::Key << "layout";
    // layout -> Field -> VkPipelineLayout
    os << YAML::Value << args.layout;
    os << YAML::Key << "firstSet";
    // firstSet -> Field -> uint32_t
    os << YAML::Value << args.firstSet;
    os << YAML::Key << "setCount";
    // setCount -> Field -> uint32_t
    os << YAML::Value << args.setCount;
    os << YAML::Key << "pBufferIndices";
    // pBufferIndices -> Field -> ConstDynamicArray(uint32_t)
    if (args.setCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("uint32_t");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.setCount; ++i) {
                os << args.pBufferIndices[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "pOffsets";
    // pOffsets -> Field -> ConstDynamicArray(VkDeviceSize)
    if (args.setCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkDeviceSize");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.setCount; ++i) {
                os << args.pOffsets[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdBindDescriptorBufferEmbeddedSamplersEXTArgs(
    YAML::Emitter &os, const CmdBindDescriptorBufferEmbeddedSamplersEXTArgs &args) {
    os << YAML::Key << "pipelineBindPoint";
    // pipelineBindPoint -> Field -> VkPipelineBindPoint
    os << YAML::Value << args.pipelineBindPoint;
    os << YAML::Key << "layout";
    // layout -> Field -> VkPipelineLayout
    os << YAML::Value << args.layout;
    os << YAML::Key << "set";
    // set -> Field -> uint32_t
    os << YAML::Value << args.set;
}

void CommandPrinter::PrintCmdSetFragmentShadingRateEnumNVArgs(YAML::Emitter &os,
                                                              const CmdSetFragmentShadingRateEnumNVArgs &args) {
    os << YAML::Key << "shadingRate";
    // shadingRate -> Field -> VkFragmentShadingRateNV
    os << YAML::Value << args.shadingRate;
    os << YAML::Key << "combinerOps";
    // combinerOps -> Field -> ConstFixedArray(VkFragmentShadingRateCombinerOpKHR)
    {
        os << YAML::Value;
        {
            os << YAML::Comment("VkFragmentShadingRateCombinerOpKHR");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < 2; ++i) {
                os << args.combinerOps[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdSetVertexInputEXTArgs(YAML::Emitter &os, const CmdSetVertexInputEXTArgs &args) {
    os << YAML::Key << "vertexBindingDescriptionCount";
    // vertexBindingDescriptionCount -> Field -> uint32_t
    os << YAML::Value << args.vertexBindingDescriptionCount;
    os << YAML::Key << "pVertexBindingDescriptions";
    // pVertexBindingDescriptions -> Field -> ConstDynamicArray(VkVertexInputBindingDescription2EXT)
    if (args.vertexBindingDescriptionCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkVertexInputBindingDescription2EXT");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.vertexBindingDescriptionCount; ++i) {
                os << args.pVertexBindingDescriptions[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "vertexAttributeDescriptionCount";
    // vertexAttributeDescriptionCount -> Field -> uint32_t
    os << YAML::Value << args.vertexAttributeDescriptionCount;
    os << YAML::Key << "pVertexAttributeDescriptions";
    // pVertexAttributeDescriptions -> Field -> ConstDynamicArray(VkVertexInputAttributeDescription2EXT)
    if (args.vertexAttributeDescriptionCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkVertexInputAttributeDescription2EXT");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.vertexAttributeDescriptionCount; ++i) {
                os << args.pVertexAttributeDescriptions[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdSubpassShadingHUAWEIArgs(YAML::Emitter &os, const CmdSubpassShadingHUAWEIArgs &args) {}

void CommandPrinter::PrintCmdBindInvocationMaskHUAWEIArgs(YAML::Emitter &os,
                                                          const CmdBindInvocationMaskHUAWEIArgs &args) {
    os << YAML::Key << "imageView";
    // imageView -> Field -> VkImageView
    os << YAML::Value << args.imageView;
    os << YAML::Key << "imageLayout";
    // imageLayout -> Field -> VkImageLayout
    os << YAML::Value << args.imageLayout;
}

void CommandPrinter::PrintCmdSetPatchControlPointsEXTArgs(YAML::Emitter &os,
                                                          const CmdSetPatchControlPointsEXTArgs &args) {
    os << YAML::Key << "patchControlPoints";
    // patchControlPoints -> Field -> uint32_t
    os << YAML::Value << args.patchControlPoints;
}

void CommandPrinter::PrintCmdSetRasterizerDiscardEnableEXTArgs(YAML::Emitter &os,
                                                               const CmdSetRasterizerDiscardEnableEXTArgs &args) {
    os << YAML::Key << "rasterizerDiscardEnable";
    // rasterizerDiscardEnable -> Field -> VkBool32
    os << YAML::Value << args.rasterizerDiscardEnable;
}

void CommandPrinter::PrintCmdSetDepthBiasEnableEXTArgs(YAML::Emitter &os, const CmdSetDepthBiasEnableEXTArgs &args) {
    os << YAML::Key << "depthBiasEnable";
    // depthBiasEnable -> Field -> VkBool32
    os << YAML::Value << args.depthBiasEnable;
}

void CommandPrinter::PrintCmdSetLogicOpEXTArgs(YAML::Emitter &os, const CmdSetLogicOpEXTArgs &args) {
    os << YAML::Key << "logicOp";
    // logicOp -> Field -> VkLogicOp
    os << YAML::Value << args.logicOp;
}

void CommandPrinter::PrintCmdSetPrimitiveRestartEnableEXTArgs(YAML::Emitter &os,
                                                              const CmdSetPrimitiveRestartEnableEXTArgs &args) {
    os << YAML::Key << "primitiveRestartEnable";
    // primitiveRestartEnable -> Field -> VkBool32
    os << YAML::Value << args.primitiveRestartEnable;
}

void CommandPrinter::PrintCmdSetColorWriteEnableEXTArgs(YAML::Emitter &os, const CmdSetColorWriteEnableEXTArgs &args) {
    os << YAML::Key << "attachmentCount";
    // attachmentCount -> Field -> uint32_t
    os << YAML::Value << args.attachmentCount;
    os << YAML::Key << "pColorWriteEnables";
    // pColorWriteEnables -> Field -> ConstDynamicArray(VkBool32)
    if (args.attachmentCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkBool32");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.attachmentCount; ++i) {
                os << args.pColorWriteEnables[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdDrawMultiEXTArgs(YAML::Emitter &os, const CmdDrawMultiEXTArgs &args) {
    os << YAML::Key << "drawCount";
    // drawCount -> Field -> uint32_t
    os << YAML::Value << args.drawCount;
    os << YAML::Key << "pVertexInfo";
    // pVertexInfo -> Field -> ConstDynamicArray(VkMultiDrawInfoEXT)
    if (args.drawCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkMultiDrawInfoEXT");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.drawCount; ++i) {
                os << args.pVertexInfo[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "instanceCount";
    // instanceCount -> Field -> uint32_t
    os << YAML::Value << args.instanceCount;
    os << YAML::Key << "firstInstance";
    // firstInstance -> Field -> uint32_t
    os << YAML::Value << args.firstInstance;
    os << YAML::Key << "stride";
    // stride -> Field -> uint32_t
    os << YAML::Value << args.stride;
}

void CommandPrinter::PrintCmdDrawMultiIndexedEXTArgs(YAML::Emitter &os, const CmdDrawMultiIndexedEXTArgs &args) {
    os << YAML::Key << "drawCount";
    // drawCount -> Field -> uint32_t
    os << YAML::Value << args.drawCount;
    os << YAML::Key << "pIndexInfo";
    // pIndexInfo -> Field -> ConstDynamicArray(VkMultiDrawIndexedInfoEXT)
    if (args.drawCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkMultiDrawIndexedInfoEXT");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.drawCount; ++i) {
                os << args.pIndexInfo[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "instanceCount";
    // instanceCount -> Field -> uint32_t
    os << YAML::Value << args.instanceCount;
    os << YAML::Key << "firstInstance";
    // firstInstance -> Field -> uint32_t
    os << YAML::Value << args.firstInstance;
    os << YAML::Key << "stride";
    // stride -> Field -> uint32_t
    os << YAML::Value << args.stride;
    os << YAML::Key << "pVertexOffset";
    // pointer
    if (args.pVertexOffset != nullptr) {
        os << YAML::Value << *args.pVertexOffset;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdBuildMicromapsEXTArgs(YAML::Emitter &os, const CmdBuildMicromapsEXTArgs &args) {
    os << YAML::Key << "infoCount";
    // infoCount -> Field -> uint32_t
    os << YAML::Value << args.infoCount;
    os << YAML::Key << "pInfos";
    // pInfos -> Field -> ConstDynamicArray(VkMicromapBuildInfoEXT)
    if (args.infoCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkMicromapBuildInfoEXT");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.infoCount; ++i) {
                os << args.pInfos[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdCopyMicromapEXTArgs(YAML::Emitter &os, const CmdCopyMicromapEXTArgs &args) {
    os << YAML::Key << "pInfo";
    // pointer
    if (args.pInfo != nullptr) {
        os << YAML::Value << *args.pInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdCopyMicromapToMemoryEXTArgs(YAML::Emitter &os,
                                                         const CmdCopyMicromapToMemoryEXTArgs &args) {
    os << YAML::Key << "pInfo";
    // pointer
    if (args.pInfo != nullptr) {
        os << YAML::Value << *args.pInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdCopyMemoryToMicromapEXTArgs(YAML::Emitter &os,
                                                         const CmdCopyMemoryToMicromapEXTArgs &args) {
    os << YAML::Key << "pInfo";
    // pointer
    if (args.pInfo != nullptr) {
        os << YAML::Value << *args.pInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdWriteMicromapsPropertiesEXTArgs(YAML::Emitter &os,
                                                             const CmdWriteMicromapsPropertiesEXTArgs &args) {
    os << YAML::Key << "micromapCount";
    // micromapCount -> Field -> uint32_t
    os << YAML::Value << args.micromapCount;
    os << YAML::Key << "pMicromaps";
    // pMicromaps -> Field -> ConstDynamicArray(VkMicromapEXT)
    if (args.micromapCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkMicromapEXT");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.micromapCount; ++i) {
                os << args.pMicromaps[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "queryType";
    // queryType -> Field -> VkQueryType
    os << YAML::Value << args.queryType;
    os << YAML::Key << "queryPool";
    // queryPool -> Field -> VkQueryPool
    os << YAML::Value << args.queryPool;
    os << YAML::Key << "firstQuery";
    // firstQuery -> Field -> uint32_t
    os << YAML::Value << args.firstQuery;
}

void CommandPrinter::PrintCmdDrawClusterHUAWEIArgs(YAML::Emitter &os, const CmdDrawClusterHUAWEIArgs &args) {
    os << YAML::Key << "groupCountX";
    // groupCountX -> Field -> uint32_t
    os << YAML::Value << args.groupCountX;
    os << YAML::Key << "groupCountY";
    // groupCountY -> Field -> uint32_t
    os << YAML::Value << args.groupCountY;
    os << YAML::Key << "groupCountZ";
    // groupCountZ -> Field -> uint32_t
    os << YAML::Value << args.groupCountZ;
}

void CommandPrinter::PrintCmdDrawClusterIndirectHUAWEIArgs(YAML::Emitter &os,
                                                           const CmdDrawClusterIndirectHUAWEIArgs &args) {
    os << YAML::Key << "buffer";
    // buffer -> Field -> VkBuffer
    os << YAML::Value << args.buffer;
    os << YAML::Key << "offset";
    // offset -> Field -> VkDeviceSize
    os << YAML::Value << args.offset;
}

void CommandPrinter::PrintCmdCopyMemoryIndirectNVArgs(YAML::Emitter &os, const CmdCopyMemoryIndirectNVArgs &args) {
    os << YAML::Key << "copyBufferAddress";
    // copyBufferAddress -> Field -> VkDeviceAddress
    os << YAML::Value << args.copyBufferAddress;
    os << YAML::Key << "copyCount";
    // copyCount -> Field -> uint32_t
    os << YAML::Value << args.copyCount;
    os << YAML::Key << "stride";
    // stride -> Field -> uint32_t
    os << YAML::Value << args.stride;
}

void CommandPrinter::PrintCmdCopyMemoryToImageIndirectNVArgs(YAML::Emitter &os,
                                                             const CmdCopyMemoryToImageIndirectNVArgs &args) {
    os << YAML::Key << "copyBufferAddress";
    // copyBufferAddress -> Field -> VkDeviceAddress
    os << YAML::Value << args.copyBufferAddress;
    os << YAML::Key << "copyCount";
    // copyCount -> Field -> uint32_t
    os << YAML::Value << args.copyCount;
    os << YAML::Key << "stride";
    // stride -> Field -> uint32_t
    os << YAML::Value << args.stride;
    os << YAML::Key << "dstImage";
    // dstImage -> Field -> VkImage
    os << YAML::Value << args.dstImage;
    os << YAML::Key << "dstImageLayout";
    // dstImageLayout -> Field -> VkImageLayout
    os << YAML::Value << args.dstImageLayout;
    os << YAML::Key << "pImageSubresources";
    // pImageSubresources -> Field -> ConstDynamicArray(VkImageSubresourceLayers)
    if (args.copyCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkImageSubresourceLayers");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.copyCount; ++i) {
                os << args.pImageSubresources[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdDecompressMemoryNVArgs(YAML::Emitter &os, const CmdDecompressMemoryNVArgs &args) {
    os << YAML::Key << "decompressRegionCount";
    // decompressRegionCount -> Field -> uint32_t
    os << YAML::Value << args.decompressRegionCount;
    os << YAML::Key << "pDecompressMemoryRegions";
    // pDecompressMemoryRegions -> Field -> ConstDynamicArray(VkDecompressMemoryRegionNV)
    if (args.decompressRegionCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkDecompressMemoryRegionNV");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.decompressRegionCount; ++i) {
                os << args.pDecompressMemoryRegions[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdDecompressMemoryIndirectCountNVArgs(YAML::Emitter &os,
                                                                 const CmdDecompressMemoryIndirectCountNVArgs &args) {
    os << YAML::Key << "indirectCommandsAddress";
    // indirectCommandsAddress -> Field -> VkDeviceAddress
    os << YAML::Value << args.indirectCommandsAddress;
    os << YAML::Key << "indirectCommandsCountAddress";
    // indirectCommandsCountAddress -> Field -> VkDeviceAddress
    os << YAML::Value << args.indirectCommandsCountAddress;
    os << YAML::Key << "stride";
    // stride -> Field -> uint32_t
    os << YAML::Value << args.stride;
}

void CommandPrinter::PrintCmdUpdatePipelineIndirectBufferNVArgs(YAML::Emitter &os,
                                                                const CmdUpdatePipelineIndirectBufferNVArgs &args) {
    os << YAML::Key << "pipelineBindPoint";
    // pipelineBindPoint -> Field -> VkPipelineBindPoint
    os << YAML::Value << args.pipelineBindPoint;
    os << YAML::Key << "pipeline";
    // pipeline -> Field -> VkPipeline
    os << YAML::Value << args.pipeline;
}

void CommandPrinter::PrintCmdSetDepthClampEnableEXTArgs(YAML::Emitter &os, const CmdSetDepthClampEnableEXTArgs &args) {
    os << YAML::Key << "depthClampEnable";
    // depthClampEnable -> Field -> VkBool32
    os << YAML::Value << args.depthClampEnable;
}

void CommandPrinter::PrintCmdSetPolygonModeEXTArgs(YAML::Emitter &os, const CmdSetPolygonModeEXTArgs &args) {
    os << YAML::Key << "polygonMode";
    // polygonMode -> Field -> VkPolygonMode
    os << YAML::Value << args.polygonMode;
}

void CommandPrinter::PrintCmdSetRasterizationSamplesEXTArgs(YAML::Emitter &os,
                                                            const CmdSetRasterizationSamplesEXTArgs &args) {
    os << YAML::Key << "rasterizationSamples";
    // rasterizationSamples -> Field -> VkSampleCountFlagBits
    os << YAML::Value << args.rasterizationSamples;
}

void CommandPrinter::PrintCmdSetSampleMaskEXTArgs(YAML::Emitter &os, const CmdSetSampleMaskEXTArgs &args) {
    os << YAML::Key << "samples";
    // samples -> Field -> VkSampleCountFlagBits
    os << YAML::Value << args.samples;
    os << YAML::Key << "pSampleMask";
    // pSampleMask -> Field -> ConstDynamicArray(VkSampleMask)
    if (((args.samples + 31) / 32) == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkSampleMask");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < ((args.samples + 31) / 32); ++i) {
                os << args.pSampleMask[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdSetAlphaToCoverageEnableEXTArgs(YAML::Emitter &os,
                                                             const CmdSetAlphaToCoverageEnableEXTArgs &args) {
    os << YAML::Key << "alphaToCoverageEnable";
    // alphaToCoverageEnable -> Field -> VkBool32
    os << YAML::Value << args.alphaToCoverageEnable;
}

void CommandPrinter::PrintCmdSetAlphaToOneEnableEXTArgs(YAML::Emitter &os, const CmdSetAlphaToOneEnableEXTArgs &args) {
    os << YAML::Key << "alphaToOneEnable";
    // alphaToOneEnable -> Field -> VkBool32
    os << YAML::Value << args.alphaToOneEnable;
}

void CommandPrinter::PrintCmdSetLogicOpEnableEXTArgs(YAML::Emitter &os, const CmdSetLogicOpEnableEXTArgs &args) {
    os << YAML::Key << "logicOpEnable";
    // logicOpEnable -> Field -> VkBool32
    os << YAML::Value << args.logicOpEnable;
}

void CommandPrinter::PrintCmdSetColorBlendEnableEXTArgs(YAML::Emitter &os, const CmdSetColorBlendEnableEXTArgs &args) {
    os << YAML::Key << "firstAttachment";
    // firstAttachment -> Field -> uint32_t
    os << YAML::Value << args.firstAttachment;
    os << YAML::Key << "attachmentCount";
    // attachmentCount -> Field -> uint32_t
    os << YAML::Value << args.attachmentCount;
    os << YAML::Key << "pColorBlendEnables";
    // pColorBlendEnables -> Field -> ConstDynamicArray(VkBool32)
    if (args.attachmentCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkBool32");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.attachmentCount; ++i) {
                os << args.pColorBlendEnables[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdSetColorBlendEquationEXTArgs(YAML::Emitter &os,
                                                          const CmdSetColorBlendEquationEXTArgs &args) {
    os << YAML::Key << "firstAttachment";
    // firstAttachment -> Field -> uint32_t
    os << YAML::Value << args.firstAttachment;
    os << YAML::Key << "attachmentCount";
    // attachmentCount -> Field -> uint32_t
    os << YAML::Value << args.attachmentCount;
    os << YAML::Key << "pColorBlendEquations";
    // pColorBlendEquations -> Field -> ConstDynamicArray(VkColorBlendEquationEXT)
    if (args.attachmentCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkColorBlendEquationEXT");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.attachmentCount; ++i) {
                os << args.pColorBlendEquations[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdSetColorWriteMaskEXTArgs(YAML::Emitter &os, const CmdSetColorWriteMaskEXTArgs &args) {
    os << YAML::Key << "firstAttachment";
    // firstAttachment -> Field -> uint32_t
    os << YAML::Value << args.firstAttachment;
    os << YAML::Key << "attachmentCount";
    // attachmentCount -> Field -> uint32_t
    os << YAML::Value << args.attachmentCount;
    os << YAML::Key << "pColorWriteMasks";
    // pColorWriteMasks -> Field -> ConstDynamicArray(VkColorComponentFlags)
    if (args.attachmentCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkColorComponentFlags");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.attachmentCount; ++i) {
                os << args.pColorWriteMasks[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdSetTessellationDomainOriginEXTArgs(YAML::Emitter &os,
                                                                const CmdSetTessellationDomainOriginEXTArgs &args) {
    os << YAML::Key << "domainOrigin";
    // domainOrigin -> Field -> VkTessellationDomainOrigin
    os << YAML::Value << args.domainOrigin;
}

void CommandPrinter::PrintCmdSetRasterizationStreamEXTArgs(YAML::Emitter &os,
                                                           const CmdSetRasterizationStreamEXTArgs &args) {
    os << YAML::Key << "rasterizationStream";
    // rasterizationStream -> Field -> uint32_t
    os << YAML::Value << args.rasterizationStream;
}

void CommandPrinter::PrintCmdSetConservativeRasterizationModeEXTArgs(
    YAML::Emitter &os, const CmdSetConservativeRasterizationModeEXTArgs &args) {
    os << YAML::Key << "conservativeRasterizationMode";
    // conservativeRasterizationMode -> Field -> VkConservativeRasterizationModeEXT
    os << YAML::Value << args.conservativeRasterizationMode;
}

void CommandPrinter::PrintCmdSetExtraPrimitiveOverestimationSizeEXTArgs(
    YAML::Emitter &os, const CmdSetExtraPrimitiveOverestimationSizeEXTArgs &args) {
    os << YAML::Key << "extraPrimitiveOverestimationSize";
    // extraPrimitiveOverestimationSize -> Field -> float
    os << YAML::Value << args.extraPrimitiveOverestimationSize;
}

void CommandPrinter::PrintCmdSetDepthClipEnableEXTArgs(YAML::Emitter &os, const CmdSetDepthClipEnableEXTArgs &args) {
    os << YAML::Key << "depthClipEnable";
    // depthClipEnable -> Field -> VkBool32
    os << YAML::Value << args.depthClipEnable;
}

void CommandPrinter::PrintCmdSetSampleLocationsEnableEXTArgs(YAML::Emitter &os,
                                                             const CmdSetSampleLocationsEnableEXTArgs &args) {
    os << YAML::Key << "sampleLocationsEnable";
    // sampleLocationsEnable -> Field -> VkBool32
    os << YAML::Value << args.sampleLocationsEnable;
}

void CommandPrinter::PrintCmdSetColorBlendAdvancedEXTArgs(YAML::Emitter &os,
                                                          const CmdSetColorBlendAdvancedEXTArgs &args) {
    os << YAML::Key << "firstAttachment";
    // firstAttachment -> Field -> uint32_t
    os << YAML::Value << args.firstAttachment;
    os << YAML::Key << "attachmentCount";
    // attachmentCount -> Field -> uint32_t
    os << YAML::Value << args.attachmentCount;
    os << YAML::Key << "pColorBlendAdvanced";
    // pColorBlendAdvanced -> Field -> ConstDynamicArray(VkColorBlendAdvancedEXT)
    if (args.attachmentCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkColorBlendAdvancedEXT");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.attachmentCount; ++i) {
                os << args.pColorBlendAdvanced[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdSetProvokingVertexModeEXTArgs(YAML::Emitter &os,
                                                           const CmdSetProvokingVertexModeEXTArgs &args) {
    os << YAML::Key << "provokingVertexMode";
    // provokingVertexMode -> Field -> VkProvokingVertexModeEXT
    os << YAML::Value << args.provokingVertexMode;
}

void CommandPrinter::PrintCmdSetLineRasterizationModeEXTArgs(YAML::Emitter &os,
                                                             const CmdSetLineRasterizationModeEXTArgs &args) {
    os << YAML::Key << "lineRasterizationMode";
    // lineRasterizationMode -> Field -> VkLineRasterizationModeEXT
    os << YAML::Value << args.lineRasterizationMode;
}

void CommandPrinter::PrintCmdSetLineStippleEnableEXTArgs(YAML::Emitter &os,
                                                         const CmdSetLineStippleEnableEXTArgs &args) {
    os << YAML::Key << "stippledLineEnable";
    // stippledLineEnable -> Field -> VkBool32
    os << YAML::Value << args.stippledLineEnable;
}

void CommandPrinter::PrintCmdSetDepthClipNegativeOneToOneEXTArgs(YAML::Emitter &os,
                                                                 const CmdSetDepthClipNegativeOneToOneEXTArgs &args) {
    os << YAML::Key << "negativeOneToOne";
    // negativeOneToOne -> Field -> VkBool32
    os << YAML::Value << args.negativeOneToOne;
}

void CommandPrinter::PrintCmdSetViewportWScalingEnableNVArgs(YAML::Emitter &os,
                                                             const CmdSetViewportWScalingEnableNVArgs &args) {
    os << YAML::Key << "viewportWScalingEnable";
    // viewportWScalingEnable -> Field -> VkBool32
    os << YAML::Value << args.viewportWScalingEnable;
}

void CommandPrinter::PrintCmdSetViewportSwizzleNVArgs(YAML::Emitter &os, const CmdSetViewportSwizzleNVArgs &args) {
    os << YAML::Key << "firstViewport";
    // firstViewport -> Field -> uint32_t
    os << YAML::Value << args.firstViewport;
    os << YAML::Key << "viewportCount";
    // viewportCount -> Field -> uint32_t
    os << YAML::Value << args.viewportCount;
    os << YAML::Key << "pViewportSwizzles";
    // pViewportSwizzles -> Field -> ConstDynamicArray(VkViewportSwizzleNV)
    if (args.viewportCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkViewportSwizzleNV");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.viewportCount; ++i) {
                os << args.pViewportSwizzles[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdSetCoverageToColorEnableNVArgs(YAML::Emitter &os,
                                                            const CmdSetCoverageToColorEnableNVArgs &args) {
    os << YAML::Key << "coverageToColorEnable";
    // coverageToColorEnable -> Field -> VkBool32
    os << YAML::Value << args.coverageToColorEnable;
}

void CommandPrinter::PrintCmdSetCoverageToColorLocationNVArgs(YAML::Emitter &os,
                                                              const CmdSetCoverageToColorLocationNVArgs &args) {
    os << YAML::Key << "coverageToColorLocation";
    // coverageToColorLocation -> Field -> uint32_t
    os << YAML::Value << args.coverageToColorLocation;
}

void CommandPrinter::PrintCmdSetCoverageModulationModeNVArgs(YAML::Emitter &os,
                                                             const CmdSetCoverageModulationModeNVArgs &args) {
    os << YAML::Key << "coverageModulationMode";
    // coverageModulationMode -> Field -> VkCoverageModulationModeNV
    os << YAML::Value << args.coverageModulationMode;
}

void CommandPrinter::PrintCmdSetCoverageModulationTableEnableNVArgs(
    YAML::Emitter &os, const CmdSetCoverageModulationTableEnableNVArgs &args) {
    os << YAML::Key << "coverageModulationTableEnable";
    // coverageModulationTableEnable -> Field -> VkBool32
    os << YAML::Value << args.coverageModulationTableEnable;
}

void CommandPrinter::PrintCmdSetCoverageModulationTableNVArgs(YAML::Emitter &os,
                                                              const CmdSetCoverageModulationTableNVArgs &args) {
    os << YAML::Key << "coverageModulationTableCount";
    // coverageModulationTableCount -> Field -> uint32_t
    os << YAML::Value << args.coverageModulationTableCount;
    os << YAML::Key << "pCoverageModulationTable";
    // pCoverageModulationTable -> Field -> ConstDynamicArray(float)
    if (args.coverageModulationTableCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("float");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.coverageModulationTableCount; ++i) {
                os << args.pCoverageModulationTable[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdSetShadingRateImageEnableNVArgs(YAML::Emitter &os,
                                                             const CmdSetShadingRateImageEnableNVArgs &args) {
    os << YAML::Key << "shadingRateImageEnable";
    // shadingRateImageEnable -> Field -> VkBool32
    os << YAML::Value << args.shadingRateImageEnable;
}

void CommandPrinter::PrintCmdSetRepresentativeFragmentTestEnableNVArgs(
    YAML::Emitter &os, const CmdSetRepresentativeFragmentTestEnableNVArgs &args) {
    os << YAML::Key << "representativeFragmentTestEnable";
    // representativeFragmentTestEnable -> Field -> VkBool32
    os << YAML::Value << args.representativeFragmentTestEnable;
}

void CommandPrinter::PrintCmdSetCoverageReductionModeNVArgs(YAML::Emitter &os,
                                                            const CmdSetCoverageReductionModeNVArgs &args) {
    os << YAML::Key << "coverageReductionMode";
    // coverageReductionMode -> Field -> VkCoverageReductionModeNV
    os << YAML::Value << args.coverageReductionMode;
}

void CommandPrinter::PrintCmdOpticalFlowExecuteNVArgs(YAML::Emitter &os, const CmdOpticalFlowExecuteNVArgs &args) {
    os << YAML::Key << "session";
    // session -> Field -> VkOpticalFlowSessionNV
    os << YAML::Value << args.session;
    os << YAML::Key << "pExecuteInfo";
    // pointer
    if (args.pExecuteInfo != nullptr) {
        os << YAML::Value << *args.pExecuteInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdBindShadersEXTArgs(YAML::Emitter &os, const CmdBindShadersEXTArgs &args) {
    os << YAML::Key << "stageCount";
    // stageCount -> Field -> uint32_t
    os << YAML::Value << args.stageCount;
    os << YAML::Key << "pStages";
    // pStages -> Field -> ConstDynamicArray(VkShaderStageFlagBits)
    if (args.stageCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkShaderStageFlagBits");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.stageCount; ++i) {
                os << args.pStages[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "pShaders";
    // pShaders -> Field -> ConstDynamicArray(VkShaderEXT)
    if (args.stageCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkShaderEXT");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.stageCount; ++i) {
                os << args.pShaders[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdSetAttachmentFeedbackLoopEnableEXTArgs(
    YAML::Emitter &os, const CmdSetAttachmentFeedbackLoopEnableEXTArgs &args) {
    os << YAML::Key << "aspectMask";
    // aspectMask -> Field -> VkImageAspectFlags
    os << YAML::Value << args.aspectMask;
}

void CommandPrinter::PrintCmdBuildAccelerationStructuresKHRArgs(YAML::Emitter &os,
                                                                const CmdBuildAccelerationStructuresKHRArgs &args) {
    os << YAML::Key << "infoCount";
    // infoCount -> Field -> uint32_t
    os << YAML::Value << args.infoCount;
    os << YAML::Key << "pInfos";
    // pInfos -> Field -> ConstDynamicArray(VkAccelerationStructureBuildGeometryInfoKHR)
    if (args.infoCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkAccelerationStructureBuildGeometryInfoKHR");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.infoCount; ++i) {
                os << args.pInfos[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "ppBuildRangeInfos";
    // ppBuildRangeInfos -> Field -> ConstDynamicArray(VkAccelerationStructureBuildRangeInfoKHR)
    if (args.infoCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkAccelerationStructureBuildRangeInfoKHR");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.infoCount; ++i) {
                os << *(args.ppBuildRangeInfos)[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdBuildAccelerationStructuresIndirectKHRArgs(
    YAML::Emitter &os, const CmdBuildAccelerationStructuresIndirectKHRArgs &args) {
    os << YAML::Key << "infoCount";
    // infoCount -> Field -> uint32_t
    os << YAML::Value << args.infoCount;
    os << YAML::Key << "pInfos";
    // pInfos -> Field -> ConstDynamicArray(VkAccelerationStructureBuildGeometryInfoKHR)
    if (args.infoCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkAccelerationStructureBuildGeometryInfoKHR");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.infoCount; ++i) {
                os << args.pInfos[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "pIndirectDeviceAddresses";
    // pIndirectDeviceAddresses -> Field -> ConstDynamicArray(VkDeviceAddress)
    if (args.infoCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkDeviceAddress");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.infoCount; ++i) {
                os << args.pIndirectDeviceAddresses[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "pIndirectStrides";
    // pIndirectStrides -> Field -> ConstDynamicArray(uint32_t)
    if (args.infoCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("uint32_t");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.infoCount; ++i) {
                os << args.pIndirectStrides[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "ppMaxPrimitiveCounts";
    // ppMaxPrimitiveCounts -> Field -> ConstDynamicArray(uint32_t)
    if (args.infoCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("uint32_t");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.infoCount; ++i) {
                os << *(args.ppMaxPrimitiveCounts)[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
}

void CommandPrinter::PrintCmdCopyAccelerationStructureKHRArgs(YAML::Emitter &os,
                                                              const CmdCopyAccelerationStructureKHRArgs &args) {
    os << YAML::Key << "pInfo";
    // pointer
    if (args.pInfo != nullptr) {
        os << YAML::Value << *args.pInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdCopyAccelerationStructureToMemoryKHRArgs(
    YAML::Emitter &os, const CmdCopyAccelerationStructureToMemoryKHRArgs &args) {
    os << YAML::Key << "pInfo";
    // pointer
    if (args.pInfo != nullptr) {
        os << YAML::Value << *args.pInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdCopyMemoryToAccelerationStructureKHRArgs(
    YAML::Emitter &os, const CmdCopyMemoryToAccelerationStructureKHRArgs &args) {
    os << YAML::Key << "pInfo";
    // pointer
    if (args.pInfo != nullptr) {
        os << YAML::Value << *args.pInfo;
    } else {
        os << YAML::Value << "nullptr";
    }
}

void CommandPrinter::PrintCmdWriteAccelerationStructuresPropertiesKHRArgs(
    YAML::Emitter &os, const CmdWriteAccelerationStructuresPropertiesKHRArgs &args) {
    os << YAML::Key << "accelerationStructureCount";
    // accelerationStructureCount -> Field -> uint32_t
    os << YAML::Value << args.accelerationStructureCount;
    os << YAML::Key << "pAccelerationStructures";
    // pAccelerationStructures -> Field -> ConstDynamicArray(VkAccelerationStructureKHR)
    if (args.accelerationStructureCount == 0) {
        os << YAML::Value << "nullptr";
    } else {
        os << YAML::Value;
        {
            os << YAML::Comment("VkAccelerationStructureKHR");
            os << YAML::BeginSeq;
            for (uint64_t i = 0; i < args.accelerationStructureCount; ++i) {
                os << args.pAccelerationStructures[i];
            }  // for i
            os << YAML::EndSeq;
        }
    }
    os << YAML::Key << "queryType";
    // queryType -> Field -> VkQueryType
    os << YAML::Value << args.queryType;
    os << YAML::Key << "queryPool";
    // queryPool -> Field -> VkQueryPool
    os << YAML::Value << args.queryPool;
    os << YAML::Key << "firstQuery";
    // firstQuery -> Field -> uint32_t
    os << YAML::Value << args.firstQuery;
}

void CommandPrinter::PrintCmdTraceRaysKHRArgs(YAML::Emitter &os, const CmdTraceRaysKHRArgs &args) {
    os << YAML::Key << "pRaygenShaderBindingTable";
    // pointer
    if (args.pRaygenShaderBindingTable != nullptr) {
        os << YAML::Value << *args.pRaygenShaderBindingTable;
    } else {
        os << YAML::Value << "nullptr";
    }
    os << YAML::Key << "pMissShaderBindingTable";
    // pointer
    if (args.pMissShaderBindingTable != nullptr) {
        os << YAML::Value << *args.pMissShaderBindingTable;
    } else {
        os << YAML::Value << "nullptr";
    }
    os << YAML::Key << "pHitShaderBindingTable";
    // pointer
    if (args.pHitShaderBindingTable != nullptr) {
        os << YAML::Value << *args.pHitShaderBindingTable;
    } else {
        os << YAML::Value << "nullptr";
    }
    os << YAML::Key << "pCallableShaderBindingTable";
    // pointer
    if (args.pCallableShaderBindingTable != nullptr) {
        os << YAML::Value << *args.pCallableShaderBindingTable;
    } else {
        os << YAML::Value << "nullptr";
    }
    os << YAML::Key << "width";
    // width -> Field -> uint32_t
    os << YAML::Value << args.width;
    os << YAML::Key << "height";
    // height -> Field -> uint32_t
    os << YAML::Value << args.height;
    os << YAML::Key << "depth";
    // depth -> Field -> uint32_t
    os << YAML::Value << args.depth;
}

void CommandPrinter::PrintCmdTraceRaysIndirectKHRArgs(YAML::Emitter &os, const CmdTraceRaysIndirectKHRArgs &args) {
    os << YAML::Key << "pRaygenShaderBindingTable";
    // pointer
    if (args.pRaygenShaderBindingTable != nullptr) {
        os << YAML::Value << *args.pRaygenShaderBindingTable;
    } else {
        os << YAML::Value << "nullptr";
    }
    os << YAML::Key << "pMissShaderBindingTable";
    // pointer
    if (args.pMissShaderBindingTable != nullptr) {
        os << YAML::Value << *args.pMissShaderBindingTable;
    } else {
        os << YAML::Value << "nullptr";
    }
    os << YAML::Key << "pHitShaderBindingTable";
    // pointer
    if (args.pHitShaderBindingTable != nullptr) {
        os << YAML::Value << *args.pHitShaderBindingTable;
    } else {
        os << YAML::Value << "nullptr";
    }
    os << YAML::Key << "pCallableShaderBindingTable";
    // pointer
    if (args.pCallableShaderBindingTable != nullptr) {
        os << YAML::Value << *args.pCallableShaderBindingTable;
    } else {
        os << YAML::Value << "nullptr";
    }
    os << YAML::Key << "indirectDeviceAddress";
    // indirectDeviceAddress -> Field -> VkDeviceAddress
    os << YAML::Value << args.indirectDeviceAddress;
}

void CommandPrinter::PrintCmdSetRayTracingPipelineStackSizeKHRArgs(
    YAML::Emitter &os, const CmdSetRayTracingPipelineStackSizeKHRArgs &args) {
    os << YAML::Key << "pipelineStackSize";
    // pipelineStackSize -> Field -> uint32_t
    os << YAML::Value << args.pipelineStackSize;
}

void CommandPrinter::PrintCmdDrawMeshTasksEXTArgs(YAML::Emitter &os, const CmdDrawMeshTasksEXTArgs &args) {
    os << YAML::Key << "groupCountX";
    // groupCountX -> Field -> uint32_t
    os << YAML::Value << args.groupCountX;
    os << YAML::Key << "groupCountY";
    // groupCountY -> Field -> uint32_t
    os << YAML::Value << args.groupCountY;
    os << YAML::Key << "groupCountZ";
    // groupCountZ -> Field -> uint32_t
    os << YAML::Value << args.groupCountZ;
}

void CommandPrinter::PrintCmdDrawMeshTasksIndirectEXTArgs(YAML::Emitter &os,
                                                          const CmdDrawMeshTasksIndirectEXTArgs &args) {
    os << YAML::Key << "buffer";
    // buffer -> Field -> VkBuffer
    os << YAML::Value << args.buffer;
    os << YAML::Key << "offset";
    // offset -> Field -> VkDeviceSize
    os << YAML::Value << args.offset;
    os << YAML::Key << "drawCount";
    // drawCount -> Field -> uint32_t
    os << YAML::Value << args.drawCount;
    os << YAML::Key << "stride";
    // stride -> Field -> uint32_t
    os << YAML::Value << args.stride;
}

void CommandPrinter::PrintCmdDrawMeshTasksIndirectCountEXTArgs(YAML::Emitter &os,
                                                               const CmdDrawMeshTasksIndirectCountEXTArgs &args) {
    os << YAML::Key << "buffer";
    // buffer -> Field -> VkBuffer
    os << YAML::Value << args.buffer;
    os << YAML::Key << "offset";
    // offset -> Field -> VkDeviceSize
    os << YAML::Value << args.offset;
    os << YAML::Key << "countBuffer";
    // countBuffer -> Field -> VkBuffer
    os << YAML::Value << args.countBuffer;
    os << YAML::Key << "countBufferOffset";
    // countBufferOffset -> Field -> VkDeviceSize
    os << YAML::Value << args.countBufferOffset;
    os << YAML::Key << "maxDrawCount";
    // maxDrawCount -> Field -> uint32_t
    os << YAML::Value << args.maxDrawCount;
    os << YAML::Key << "stride";
    // stride -> Field -> uint32_t
    os << YAML::Value << args.stride;
}

// NOLINTEND