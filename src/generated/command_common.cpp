
/***************************************************************************
 *
 * Copyright (C) 2021 Google Inc.
 * Copyright (c) 2023-2025 LunarG, Inc.
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
 * ***   Update source file command_common_generator.py for modifications
 * *** ---- WARNING! ----
 *
 ****************************************************************************/

// NOLINTBEGIN

#include "command_common.h"

// Returns the name of given command. This only cares for commands that have one
// parameter of type VkCommandBuffer.
const char *Command::GetCommandName(const Command &cmd) {
    switch (cmd.type) {
        default:
        case Command::Type::kUnknown:
            return "Unknown";

        case Command::Type::kBeginCommandBuffer:
            return "vkBeginCommandBuffer";
        case Command::Type::kEndCommandBuffer:
            return "vkEndCommandBuffer";
        case Command::Type::kResetCommandBuffer:
            return "vkResetCommandBuffer";
        case Command::Type::kCmdBindPipeline:
            return "vkCmdBindPipeline";
        case Command::Type::kCmdSetViewport:
            return "vkCmdSetViewport";
        case Command::Type::kCmdSetScissor:
            return "vkCmdSetScissor";
        case Command::Type::kCmdSetLineWidth:
            return "vkCmdSetLineWidth";
        case Command::Type::kCmdSetDepthBias:
            return "vkCmdSetDepthBias";
        case Command::Type::kCmdSetBlendConstants:
            return "vkCmdSetBlendConstants";
        case Command::Type::kCmdSetDepthBounds:
            return "vkCmdSetDepthBounds";
        case Command::Type::kCmdSetStencilCompareMask:
            return "vkCmdSetStencilCompareMask";
        case Command::Type::kCmdSetStencilWriteMask:
            return "vkCmdSetStencilWriteMask";
        case Command::Type::kCmdSetStencilReference:
            return "vkCmdSetStencilReference";
        case Command::Type::kCmdBindDescriptorSets:
            return "vkCmdBindDescriptorSets";
        case Command::Type::kCmdBindIndexBuffer:
            return "vkCmdBindIndexBuffer";
        case Command::Type::kCmdBindVertexBuffers:
            return "vkCmdBindVertexBuffers";
        case Command::Type::kCmdDraw:
            return "vkCmdDraw";
        case Command::Type::kCmdDrawIndexed:
            return "vkCmdDrawIndexed";
        case Command::Type::kCmdDrawIndirect:
            return "vkCmdDrawIndirect";
        case Command::Type::kCmdDrawIndexedIndirect:
            return "vkCmdDrawIndexedIndirect";
        case Command::Type::kCmdDispatch:
            return "vkCmdDispatch";
        case Command::Type::kCmdDispatchIndirect:
            return "vkCmdDispatchIndirect";
        case Command::Type::kCmdCopyBuffer:
            return "vkCmdCopyBuffer";
        case Command::Type::kCmdCopyImage:
            return "vkCmdCopyImage";
        case Command::Type::kCmdBlitImage:
            return "vkCmdBlitImage";
        case Command::Type::kCmdCopyBufferToImage:
            return "vkCmdCopyBufferToImage";
        case Command::Type::kCmdCopyImageToBuffer:
            return "vkCmdCopyImageToBuffer";
        case Command::Type::kCmdUpdateBuffer:
            return "vkCmdUpdateBuffer";
        case Command::Type::kCmdFillBuffer:
            return "vkCmdFillBuffer";
        case Command::Type::kCmdClearColorImage:
            return "vkCmdClearColorImage";
        case Command::Type::kCmdClearDepthStencilImage:
            return "vkCmdClearDepthStencilImage";
        case Command::Type::kCmdClearAttachments:
            return "vkCmdClearAttachments";
        case Command::Type::kCmdResolveImage:
            return "vkCmdResolveImage";
        case Command::Type::kCmdSetEvent:
            return "vkCmdSetEvent";
        case Command::Type::kCmdResetEvent:
            return "vkCmdResetEvent";
        case Command::Type::kCmdWaitEvents:
            return "vkCmdWaitEvents";
        case Command::Type::kCmdPipelineBarrier:
            return "vkCmdPipelineBarrier";
        case Command::Type::kCmdBeginQuery:
            return "vkCmdBeginQuery";
        case Command::Type::kCmdEndQuery:
            return "vkCmdEndQuery";
        case Command::Type::kCmdResetQueryPool:
            return "vkCmdResetQueryPool";
        case Command::Type::kCmdWriteTimestamp:
            return "vkCmdWriteTimestamp";
        case Command::Type::kCmdCopyQueryPoolResults:
            return "vkCmdCopyQueryPoolResults";
        case Command::Type::kCmdPushConstants:
            return "vkCmdPushConstants";
        case Command::Type::kCmdBeginRenderPass:
            return "vkCmdBeginRenderPass";
        case Command::Type::kCmdNextSubpass:
            return "vkCmdNextSubpass";
        case Command::Type::kCmdEndRenderPass:
            return "vkCmdEndRenderPass";
        case Command::Type::kCmdExecuteCommands:
            return "vkCmdExecuteCommands";
        case Command::Type::kCmdSetDeviceMask:
            return "vkCmdSetDeviceMask";
        case Command::Type::kCmdDispatchBase:
            return "vkCmdDispatchBase";
        case Command::Type::kCmdDrawIndirectCount:
            return "vkCmdDrawIndirectCount";
        case Command::Type::kCmdDrawIndexedIndirectCount:
            return "vkCmdDrawIndexedIndirectCount";
        case Command::Type::kCmdBeginRenderPass2:
            return "vkCmdBeginRenderPass2";
        case Command::Type::kCmdNextSubpass2:
            return "vkCmdNextSubpass2";
        case Command::Type::kCmdEndRenderPass2:
            return "vkCmdEndRenderPass2";
        case Command::Type::kCmdSetEvent2:
            return "vkCmdSetEvent2";
        case Command::Type::kCmdResetEvent2:
            return "vkCmdResetEvent2";
        case Command::Type::kCmdWaitEvents2:
            return "vkCmdWaitEvents2";
        case Command::Type::kCmdPipelineBarrier2:
            return "vkCmdPipelineBarrier2";
        case Command::Type::kCmdWriteTimestamp2:
            return "vkCmdWriteTimestamp2";
        case Command::Type::kCmdCopyBuffer2:
            return "vkCmdCopyBuffer2";
        case Command::Type::kCmdCopyImage2:
            return "vkCmdCopyImage2";
        case Command::Type::kCmdCopyBufferToImage2:
            return "vkCmdCopyBufferToImage2";
        case Command::Type::kCmdCopyImageToBuffer2:
            return "vkCmdCopyImageToBuffer2";
        case Command::Type::kCmdBlitImage2:
            return "vkCmdBlitImage2";
        case Command::Type::kCmdResolveImage2:
            return "vkCmdResolveImage2";
        case Command::Type::kCmdBeginRendering:
            return "vkCmdBeginRendering";
        case Command::Type::kCmdEndRendering:
            return "vkCmdEndRendering";
        case Command::Type::kCmdSetCullMode:
            return "vkCmdSetCullMode";
        case Command::Type::kCmdSetFrontFace:
            return "vkCmdSetFrontFace";
        case Command::Type::kCmdSetPrimitiveTopology:
            return "vkCmdSetPrimitiveTopology";
        case Command::Type::kCmdSetViewportWithCount:
            return "vkCmdSetViewportWithCount";
        case Command::Type::kCmdSetScissorWithCount:
            return "vkCmdSetScissorWithCount";
        case Command::Type::kCmdBindVertexBuffers2:
            return "vkCmdBindVertexBuffers2";
        case Command::Type::kCmdSetDepthTestEnable:
            return "vkCmdSetDepthTestEnable";
        case Command::Type::kCmdSetDepthWriteEnable:
            return "vkCmdSetDepthWriteEnable";
        case Command::Type::kCmdSetDepthCompareOp:
            return "vkCmdSetDepthCompareOp";
        case Command::Type::kCmdSetDepthBoundsTestEnable:
            return "vkCmdSetDepthBoundsTestEnable";
        case Command::Type::kCmdSetStencilTestEnable:
            return "vkCmdSetStencilTestEnable";
        case Command::Type::kCmdSetStencilOp:
            return "vkCmdSetStencilOp";
        case Command::Type::kCmdSetRasterizerDiscardEnable:
            return "vkCmdSetRasterizerDiscardEnable";
        case Command::Type::kCmdSetDepthBiasEnable:
            return "vkCmdSetDepthBiasEnable";
        case Command::Type::kCmdSetPrimitiveRestartEnable:
            return "vkCmdSetPrimitiveRestartEnable";
        case Command::Type::kCmdSetLineStipple:
            return "vkCmdSetLineStipple";
        case Command::Type::kCmdBindIndexBuffer2:
            return "vkCmdBindIndexBuffer2";
        case Command::Type::kCmdPushDescriptorSet:
            return "vkCmdPushDescriptorSet";
        case Command::Type::kCmdPushDescriptorSetWithTemplate:
            return "vkCmdPushDescriptorSetWithTemplate";
        case Command::Type::kCmdSetRenderingAttachmentLocations:
            return "vkCmdSetRenderingAttachmentLocations";
        case Command::Type::kCmdSetRenderingInputAttachmentIndices:
            return "vkCmdSetRenderingInputAttachmentIndices";
        case Command::Type::kCmdBindDescriptorSets2:
            return "vkCmdBindDescriptorSets2";
        case Command::Type::kCmdPushConstants2:
            return "vkCmdPushConstants2";
        case Command::Type::kCmdPushDescriptorSet2:
            return "vkCmdPushDescriptorSet2";
        case Command::Type::kCmdPushDescriptorSetWithTemplate2:
            return "vkCmdPushDescriptorSetWithTemplate2";
        case Command::Type::kCmdBeginVideoCodingKHR:
            return "vkCmdBeginVideoCodingKHR";
        case Command::Type::kCmdEndVideoCodingKHR:
            return "vkCmdEndVideoCodingKHR";
        case Command::Type::kCmdControlVideoCodingKHR:
            return "vkCmdControlVideoCodingKHR";
        case Command::Type::kCmdDecodeVideoKHR:
            return "vkCmdDecodeVideoKHR";
        case Command::Type::kCmdBeginRenderingKHR:
            return "vkCmdBeginRenderingKHR";
        case Command::Type::kCmdEndRenderingKHR:
            return "vkCmdEndRenderingKHR";
        case Command::Type::kCmdSetDeviceMaskKHR:
            return "vkCmdSetDeviceMaskKHR";
        case Command::Type::kCmdDispatchBaseKHR:
            return "vkCmdDispatchBaseKHR";
        case Command::Type::kCmdPushDescriptorSetKHR:
            return "vkCmdPushDescriptorSetKHR";
        case Command::Type::kCmdPushDescriptorSetWithTemplateKHR:
            return "vkCmdPushDescriptorSetWithTemplateKHR";
        case Command::Type::kCmdBeginRenderPass2KHR:
            return "vkCmdBeginRenderPass2KHR";
        case Command::Type::kCmdNextSubpass2KHR:
            return "vkCmdNextSubpass2KHR";
        case Command::Type::kCmdEndRenderPass2KHR:
            return "vkCmdEndRenderPass2KHR";
        case Command::Type::kCmdDrawIndirectCountKHR:
            return "vkCmdDrawIndirectCountKHR";
        case Command::Type::kCmdDrawIndexedIndirectCountKHR:
            return "vkCmdDrawIndexedIndirectCountKHR";
        case Command::Type::kCmdSetFragmentShadingRateKHR:
            return "vkCmdSetFragmentShadingRateKHR";
        case Command::Type::kCmdSetRenderingAttachmentLocationsKHR:
            return "vkCmdSetRenderingAttachmentLocationsKHR";
        case Command::Type::kCmdSetRenderingInputAttachmentIndicesKHR:
            return "vkCmdSetRenderingInputAttachmentIndicesKHR";
        case Command::Type::kCmdEncodeVideoKHR:
            return "vkCmdEncodeVideoKHR";
        case Command::Type::kCmdSetEvent2KHR:
            return "vkCmdSetEvent2KHR";
        case Command::Type::kCmdResetEvent2KHR:
            return "vkCmdResetEvent2KHR";
        case Command::Type::kCmdWaitEvents2KHR:
            return "vkCmdWaitEvents2KHR";
        case Command::Type::kCmdPipelineBarrier2KHR:
            return "vkCmdPipelineBarrier2KHR";
        case Command::Type::kCmdWriteTimestamp2KHR:
            return "vkCmdWriteTimestamp2KHR";
        case Command::Type::kCmdCopyBuffer2KHR:
            return "vkCmdCopyBuffer2KHR";
        case Command::Type::kCmdCopyImage2KHR:
            return "vkCmdCopyImage2KHR";
        case Command::Type::kCmdCopyBufferToImage2KHR:
            return "vkCmdCopyBufferToImage2KHR";
        case Command::Type::kCmdCopyImageToBuffer2KHR:
            return "vkCmdCopyImageToBuffer2KHR";
        case Command::Type::kCmdBlitImage2KHR:
            return "vkCmdBlitImage2KHR";
        case Command::Type::kCmdResolveImage2KHR:
            return "vkCmdResolveImage2KHR";
        case Command::Type::kCmdTraceRaysIndirect2KHR:
            return "vkCmdTraceRaysIndirect2KHR";
        case Command::Type::kCmdBindIndexBuffer2KHR:
            return "vkCmdBindIndexBuffer2KHR";
        case Command::Type::kCmdSetLineStippleKHR:
            return "vkCmdSetLineStippleKHR";
        case Command::Type::kCmdBindDescriptorSets2KHR:
            return "vkCmdBindDescriptorSets2KHR";
        case Command::Type::kCmdPushConstants2KHR:
            return "vkCmdPushConstants2KHR";
        case Command::Type::kCmdPushDescriptorSet2KHR:
            return "vkCmdPushDescriptorSet2KHR";
        case Command::Type::kCmdPushDescriptorSetWithTemplate2KHR:
            return "vkCmdPushDescriptorSetWithTemplate2KHR";
        case Command::Type::kCmdSetDescriptorBufferOffsets2EXT:
            return "vkCmdSetDescriptorBufferOffsets2EXT";
        case Command::Type::kCmdBindDescriptorBufferEmbeddedSamplers2EXT:
            return "vkCmdBindDescriptorBufferEmbeddedSamplers2EXT";
        case Command::Type::kCmdDebugMarkerBeginEXT:
            return "vkCmdDebugMarkerBeginEXT";
        case Command::Type::kCmdDebugMarkerEndEXT:
            return "vkCmdDebugMarkerEndEXT";
        case Command::Type::kCmdDebugMarkerInsertEXT:
            return "vkCmdDebugMarkerInsertEXT";
        case Command::Type::kCmdBindTransformFeedbackBuffersEXT:
            return "vkCmdBindTransformFeedbackBuffersEXT";
        case Command::Type::kCmdBeginTransformFeedbackEXT:
            return "vkCmdBeginTransformFeedbackEXT";
        case Command::Type::kCmdEndTransformFeedbackEXT:
            return "vkCmdEndTransformFeedbackEXT";
        case Command::Type::kCmdBeginQueryIndexedEXT:
            return "vkCmdBeginQueryIndexedEXT";
        case Command::Type::kCmdEndQueryIndexedEXT:
            return "vkCmdEndQueryIndexedEXT";
        case Command::Type::kCmdDrawIndirectByteCountEXT:
            return "vkCmdDrawIndirectByteCountEXT";
        case Command::Type::kCmdCuLaunchKernelNVX:
            return "vkCmdCuLaunchKernelNVX";
        case Command::Type::kCmdDrawIndirectCountAMD:
            return "vkCmdDrawIndirectCountAMD";
        case Command::Type::kCmdDrawIndexedIndirectCountAMD:
            return "vkCmdDrawIndexedIndirectCountAMD";
        case Command::Type::kCmdBeginConditionalRenderingEXT:
            return "vkCmdBeginConditionalRenderingEXT";
        case Command::Type::kCmdEndConditionalRenderingEXT:
            return "vkCmdEndConditionalRenderingEXT";
        case Command::Type::kCmdSetViewportWScalingNV:
            return "vkCmdSetViewportWScalingNV";
        case Command::Type::kCmdSetDiscardRectangleEXT:
            return "vkCmdSetDiscardRectangleEXT";
        case Command::Type::kCmdSetDiscardRectangleEnableEXT:
            return "vkCmdSetDiscardRectangleEnableEXT";
        case Command::Type::kCmdSetDiscardRectangleModeEXT:
            return "vkCmdSetDiscardRectangleModeEXT";
        case Command::Type::kCmdBeginDebugUtilsLabelEXT:
            return "vkCmdBeginDebugUtilsLabelEXT";
        case Command::Type::kCmdEndDebugUtilsLabelEXT:
            return "vkCmdEndDebugUtilsLabelEXT";
        case Command::Type::kCmdInsertDebugUtilsLabelEXT:
            return "vkCmdInsertDebugUtilsLabelEXT";
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case Command::Type::kCmdInitializeGraphScratchMemoryAMDX:
            return "vkCmdInitializeGraphScratchMemoryAMDX";
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case Command::Type::kCmdDispatchGraphAMDX:
            return "vkCmdDispatchGraphAMDX";
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case Command::Type::kCmdDispatchGraphIndirectAMDX:
            return "vkCmdDispatchGraphIndirectAMDX";
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case Command::Type::kCmdDispatchGraphIndirectCountAMDX:
            return "vkCmdDispatchGraphIndirectCountAMDX";
#endif  // VK_ENABLE_BETA_EXTENSIONS
        case Command::Type::kCmdSetSampleLocationsEXT:
            return "vkCmdSetSampleLocationsEXT";
        case Command::Type::kCmdBindShadingRateImageNV:
            return "vkCmdBindShadingRateImageNV";
        case Command::Type::kCmdSetViewportShadingRatePaletteNV:
            return "vkCmdSetViewportShadingRatePaletteNV";
        case Command::Type::kCmdSetCoarseSampleOrderNV:
            return "vkCmdSetCoarseSampleOrderNV";
        case Command::Type::kCmdBuildAccelerationStructureNV:
            return "vkCmdBuildAccelerationStructureNV";
        case Command::Type::kCmdCopyAccelerationStructureNV:
            return "vkCmdCopyAccelerationStructureNV";
        case Command::Type::kCmdTraceRaysNV:
            return "vkCmdTraceRaysNV";
        case Command::Type::kCmdWriteAccelerationStructuresPropertiesNV:
            return "vkCmdWriteAccelerationStructuresPropertiesNV";
        case Command::Type::kCmdWriteBufferMarkerAMD:
            return "vkCmdWriteBufferMarkerAMD";
        case Command::Type::kCmdWriteBufferMarker2AMD:
            return "vkCmdWriteBufferMarker2AMD";
        case Command::Type::kCmdDrawMeshTasksNV:
            return "vkCmdDrawMeshTasksNV";
        case Command::Type::kCmdDrawMeshTasksIndirectNV:
            return "vkCmdDrawMeshTasksIndirectNV";
        case Command::Type::kCmdDrawMeshTasksIndirectCountNV:
            return "vkCmdDrawMeshTasksIndirectCountNV";
        case Command::Type::kCmdSetExclusiveScissorEnableNV:
            return "vkCmdSetExclusiveScissorEnableNV";
        case Command::Type::kCmdSetExclusiveScissorNV:
            return "vkCmdSetExclusiveScissorNV";
        case Command::Type::kCmdSetCheckpointNV:
            return "vkCmdSetCheckpointNV";
        case Command::Type::kCmdSetPerformanceMarkerINTEL:
            return "vkCmdSetPerformanceMarkerINTEL";
        case Command::Type::kCmdSetPerformanceStreamMarkerINTEL:
            return "vkCmdSetPerformanceStreamMarkerINTEL";
        case Command::Type::kCmdSetPerformanceOverrideINTEL:
            return "vkCmdSetPerformanceOverrideINTEL";
        case Command::Type::kCmdSetLineStippleEXT:
            return "vkCmdSetLineStippleEXT";
        case Command::Type::kCmdSetCullModeEXT:
            return "vkCmdSetCullModeEXT";
        case Command::Type::kCmdSetFrontFaceEXT:
            return "vkCmdSetFrontFaceEXT";
        case Command::Type::kCmdSetPrimitiveTopologyEXT:
            return "vkCmdSetPrimitiveTopologyEXT";
        case Command::Type::kCmdSetViewportWithCountEXT:
            return "vkCmdSetViewportWithCountEXT";
        case Command::Type::kCmdSetScissorWithCountEXT:
            return "vkCmdSetScissorWithCountEXT";
        case Command::Type::kCmdBindVertexBuffers2EXT:
            return "vkCmdBindVertexBuffers2EXT";
        case Command::Type::kCmdSetDepthTestEnableEXT:
            return "vkCmdSetDepthTestEnableEXT";
        case Command::Type::kCmdSetDepthWriteEnableEXT:
            return "vkCmdSetDepthWriteEnableEXT";
        case Command::Type::kCmdSetDepthCompareOpEXT:
            return "vkCmdSetDepthCompareOpEXT";
        case Command::Type::kCmdSetDepthBoundsTestEnableEXT:
            return "vkCmdSetDepthBoundsTestEnableEXT";
        case Command::Type::kCmdSetStencilTestEnableEXT:
            return "vkCmdSetStencilTestEnableEXT";
        case Command::Type::kCmdSetStencilOpEXT:
            return "vkCmdSetStencilOpEXT";
        case Command::Type::kCmdPreprocessGeneratedCommandsNV:
            return "vkCmdPreprocessGeneratedCommandsNV";
        case Command::Type::kCmdExecuteGeneratedCommandsNV:
            return "vkCmdExecuteGeneratedCommandsNV";
        case Command::Type::kCmdBindPipelineShaderGroupNV:
            return "vkCmdBindPipelineShaderGroupNV";
        case Command::Type::kCmdSetDepthBias2EXT:
            return "vkCmdSetDepthBias2EXT";
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case Command::Type::kCmdCudaLaunchKernelNV:
            return "vkCmdCudaLaunchKernelNV";
#endif  // VK_ENABLE_BETA_EXTENSIONS
        case Command::Type::kCmdDispatchTileQCOM:
            return "vkCmdDispatchTileQCOM";
        case Command::Type::kCmdBeginPerTileExecutionQCOM:
            return "vkCmdBeginPerTileExecutionQCOM";
        case Command::Type::kCmdEndPerTileExecutionQCOM:
            return "vkCmdEndPerTileExecutionQCOM";
        case Command::Type::kCmdBindDescriptorBuffersEXT:
            return "vkCmdBindDescriptorBuffersEXT";
        case Command::Type::kCmdSetDescriptorBufferOffsetsEXT:
            return "vkCmdSetDescriptorBufferOffsetsEXT";
        case Command::Type::kCmdBindDescriptorBufferEmbeddedSamplersEXT:
            return "vkCmdBindDescriptorBufferEmbeddedSamplersEXT";
        case Command::Type::kCmdSetFragmentShadingRateEnumNV:
            return "vkCmdSetFragmentShadingRateEnumNV";
        case Command::Type::kCmdSetVertexInputEXT:
            return "vkCmdSetVertexInputEXT";
        case Command::Type::kCmdSubpassShadingHUAWEI:
            return "vkCmdSubpassShadingHUAWEI";
        case Command::Type::kCmdBindInvocationMaskHUAWEI:
            return "vkCmdBindInvocationMaskHUAWEI";
        case Command::Type::kCmdSetPatchControlPointsEXT:
            return "vkCmdSetPatchControlPointsEXT";
        case Command::Type::kCmdSetRasterizerDiscardEnableEXT:
            return "vkCmdSetRasterizerDiscardEnableEXT";
        case Command::Type::kCmdSetDepthBiasEnableEXT:
            return "vkCmdSetDepthBiasEnableEXT";
        case Command::Type::kCmdSetLogicOpEXT:
            return "vkCmdSetLogicOpEXT";
        case Command::Type::kCmdSetPrimitiveRestartEnableEXT:
            return "vkCmdSetPrimitiveRestartEnableEXT";
        case Command::Type::kCmdSetColorWriteEnableEXT:
            return "vkCmdSetColorWriteEnableEXT";
        case Command::Type::kCmdDrawMultiEXT:
            return "vkCmdDrawMultiEXT";
        case Command::Type::kCmdDrawMultiIndexedEXT:
            return "vkCmdDrawMultiIndexedEXT";
        case Command::Type::kCmdBuildMicromapsEXT:
            return "vkCmdBuildMicromapsEXT";
        case Command::Type::kCmdCopyMicromapEXT:
            return "vkCmdCopyMicromapEXT";
        case Command::Type::kCmdCopyMicromapToMemoryEXT:
            return "vkCmdCopyMicromapToMemoryEXT";
        case Command::Type::kCmdCopyMemoryToMicromapEXT:
            return "vkCmdCopyMemoryToMicromapEXT";
        case Command::Type::kCmdWriteMicromapsPropertiesEXT:
            return "vkCmdWriteMicromapsPropertiesEXT";
        case Command::Type::kCmdDrawClusterHUAWEI:
            return "vkCmdDrawClusterHUAWEI";
        case Command::Type::kCmdDrawClusterIndirectHUAWEI:
            return "vkCmdDrawClusterIndirectHUAWEI";
        case Command::Type::kCmdCopyMemoryIndirectNV:
            return "vkCmdCopyMemoryIndirectNV";
        case Command::Type::kCmdCopyMemoryToImageIndirectNV:
            return "vkCmdCopyMemoryToImageIndirectNV";
        case Command::Type::kCmdDecompressMemoryNV:
            return "vkCmdDecompressMemoryNV";
        case Command::Type::kCmdDecompressMemoryIndirectCountNV:
            return "vkCmdDecompressMemoryIndirectCountNV";
        case Command::Type::kCmdUpdatePipelineIndirectBufferNV:
            return "vkCmdUpdatePipelineIndirectBufferNV";
        case Command::Type::kCmdSetDepthClampEnableEXT:
            return "vkCmdSetDepthClampEnableEXT";
        case Command::Type::kCmdSetPolygonModeEXT:
            return "vkCmdSetPolygonModeEXT";
        case Command::Type::kCmdSetRasterizationSamplesEXT:
            return "vkCmdSetRasterizationSamplesEXT";
        case Command::Type::kCmdSetSampleMaskEXT:
            return "vkCmdSetSampleMaskEXT";
        case Command::Type::kCmdSetAlphaToCoverageEnableEXT:
            return "vkCmdSetAlphaToCoverageEnableEXT";
        case Command::Type::kCmdSetAlphaToOneEnableEXT:
            return "vkCmdSetAlphaToOneEnableEXT";
        case Command::Type::kCmdSetLogicOpEnableEXT:
            return "vkCmdSetLogicOpEnableEXT";
        case Command::Type::kCmdSetColorBlendEnableEXT:
            return "vkCmdSetColorBlendEnableEXT";
        case Command::Type::kCmdSetColorBlendEquationEXT:
            return "vkCmdSetColorBlendEquationEXT";
        case Command::Type::kCmdSetColorWriteMaskEXT:
            return "vkCmdSetColorWriteMaskEXT";
        case Command::Type::kCmdSetTessellationDomainOriginEXT:
            return "vkCmdSetTessellationDomainOriginEXT";
        case Command::Type::kCmdSetRasterizationStreamEXT:
            return "vkCmdSetRasterizationStreamEXT";
        case Command::Type::kCmdSetConservativeRasterizationModeEXT:
            return "vkCmdSetConservativeRasterizationModeEXT";
        case Command::Type::kCmdSetExtraPrimitiveOverestimationSizeEXT:
            return "vkCmdSetExtraPrimitiveOverestimationSizeEXT";
        case Command::Type::kCmdSetDepthClipEnableEXT:
            return "vkCmdSetDepthClipEnableEXT";
        case Command::Type::kCmdSetSampleLocationsEnableEXT:
            return "vkCmdSetSampleLocationsEnableEXT";
        case Command::Type::kCmdSetColorBlendAdvancedEXT:
            return "vkCmdSetColorBlendAdvancedEXT";
        case Command::Type::kCmdSetProvokingVertexModeEXT:
            return "vkCmdSetProvokingVertexModeEXT";
        case Command::Type::kCmdSetLineRasterizationModeEXT:
            return "vkCmdSetLineRasterizationModeEXT";
        case Command::Type::kCmdSetLineStippleEnableEXT:
            return "vkCmdSetLineStippleEnableEXT";
        case Command::Type::kCmdSetDepthClipNegativeOneToOneEXT:
            return "vkCmdSetDepthClipNegativeOneToOneEXT";
        case Command::Type::kCmdSetViewportWScalingEnableNV:
            return "vkCmdSetViewportWScalingEnableNV";
        case Command::Type::kCmdSetViewportSwizzleNV:
            return "vkCmdSetViewportSwizzleNV";
        case Command::Type::kCmdSetCoverageToColorEnableNV:
            return "vkCmdSetCoverageToColorEnableNV";
        case Command::Type::kCmdSetCoverageToColorLocationNV:
            return "vkCmdSetCoverageToColorLocationNV";
        case Command::Type::kCmdSetCoverageModulationModeNV:
            return "vkCmdSetCoverageModulationModeNV";
        case Command::Type::kCmdSetCoverageModulationTableEnableNV:
            return "vkCmdSetCoverageModulationTableEnableNV";
        case Command::Type::kCmdSetCoverageModulationTableNV:
            return "vkCmdSetCoverageModulationTableNV";
        case Command::Type::kCmdSetShadingRateImageEnableNV:
            return "vkCmdSetShadingRateImageEnableNV";
        case Command::Type::kCmdSetRepresentativeFragmentTestEnableNV:
            return "vkCmdSetRepresentativeFragmentTestEnableNV";
        case Command::Type::kCmdSetCoverageReductionModeNV:
            return "vkCmdSetCoverageReductionModeNV";
        case Command::Type::kCmdCopyTensorARM:
            return "vkCmdCopyTensorARM";
        case Command::Type::kCmdOpticalFlowExecuteNV:
            return "vkCmdOpticalFlowExecuteNV";
        case Command::Type::kCmdBindShadersEXT:
            return "vkCmdBindShadersEXT";
        case Command::Type::kCmdSetDepthClampRangeEXT:
            return "vkCmdSetDepthClampRangeEXT";
        case Command::Type::kCmdConvertCooperativeVectorMatrixNV:
            return "vkCmdConvertCooperativeVectorMatrixNV";
        case Command::Type::kCmdDispatchDataGraphARM:
            return "vkCmdDispatchDataGraphARM";
        case Command::Type::kCmdSetAttachmentFeedbackLoopEnableEXT:
            return "vkCmdSetAttachmentFeedbackLoopEnableEXT";
        case Command::Type::kCmdBindTileMemoryQCOM:
            return "vkCmdBindTileMemoryQCOM";
        case Command::Type::kCmdBuildClusterAccelerationStructureIndirectNV:
            return "vkCmdBuildClusterAccelerationStructureIndirectNV";
        case Command::Type::kCmdBuildPartitionedAccelerationStructuresNV:
            return "vkCmdBuildPartitionedAccelerationStructuresNV";
        case Command::Type::kCmdPreprocessGeneratedCommandsEXT:
            return "vkCmdPreprocessGeneratedCommandsEXT";
        case Command::Type::kCmdExecuteGeneratedCommandsEXT:
            return "vkCmdExecuteGeneratedCommandsEXT";
        case Command::Type::kCmdEndRendering2EXT:
            return "vkCmdEndRendering2EXT";
        case Command::Type::kCmdBuildAccelerationStructuresKHR:
            return "vkCmdBuildAccelerationStructuresKHR";
        case Command::Type::kCmdBuildAccelerationStructuresIndirectKHR:
            return "vkCmdBuildAccelerationStructuresIndirectKHR";
        case Command::Type::kCmdCopyAccelerationStructureKHR:
            return "vkCmdCopyAccelerationStructureKHR";
        case Command::Type::kCmdCopyAccelerationStructureToMemoryKHR:
            return "vkCmdCopyAccelerationStructureToMemoryKHR";
        case Command::Type::kCmdCopyMemoryToAccelerationStructureKHR:
            return "vkCmdCopyMemoryToAccelerationStructureKHR";
        case Command::Type::kCmdWriteAccelerationStructuresPropertiesKHR:
            return "vkCmdWriteAccelerationStructuresPropertiesKHR";
        case Command::Type::kCmdTraceRaysKHR:
            return "vkCmdTraceRaysKHR";
        case Command::Type::kCmdTraceRaysIndirectKHR:
            return "vkCmdTraceRaysIndirectKHR";
        case Command::Type::kCmdSetRayTracingPipelineStackSizeKHR:
            return "vkCmdSetRayTracingPipelineStackSizeKHR";
        case Command::Type::kCmdDrawMeshTasksEXT:
            return "vkCmdDrawMeshTasksEXT";
        case Command::Type::kCmdDrawMeshTasksIndirectEXT:
            return "vkCmdDrawMeshTasksIndirectEXT";
        case Command::Type::kCmdDrawMeshTasksIndirectCountEXT:
            return "vkCmdDrawMeshTasksIndirectCountEXT";
    }  // switch (cmd.type)
}  // Command::GetCommandName()

// NOLINTEND
