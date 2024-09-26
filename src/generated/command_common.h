
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
 * ***   Update source file command_common_generator.py for modifications
 * *** ---- WARNING! ----
 *
 ****************************************************************************/

// NOLINTBEGIN

#pragma once

#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <vulkan/vulkan.h>

// Enumerate commands that have one parameter of type VkCommandBuffer.
struct Command {
    enum Type {
        kUnknown,

        kBeginCommandBuffer,
        kEndCommandBuffer,
        kResetCommandBuffer,
        kCmdBindPipeline,
        kCmdSetViewport,
        kCmdSetScissor,
        kCmdSetLineWidth,
        kCmdSetDepthBias,
        kCmdSetBlendConstants,
        kCmdSetDepthBounds,
        kCmdSetStencilCompareMask,
        kCmdSetStencilWriteMask,
        kCmdSetStencilReference,
        kCmdBindDescriptorSets,
        kCmdBindIndexBuffer,
        kCmdBindVertexBuffers,
        kCmdDraw,
        kCmdDrawIndexed,
        kCmdDrawIndirect,
        kCmdDrawIndexedIndirect,
        kCmdDispatch,
        kCmdDispatchIndirect,
        kCmdCopyBuffer,
        kCmdCopyImage,
        kCmdBlitImage,
        kCmdCopyBufferToImage,
        kCmdCopyImageToBuffer,
        kCmdUpdateBuffer,
        kCmdFillBuffer,
        kCmdClearColorImage,
        kCmdClearDepthStencilImage,
        kCmdClearAttachments,
        kCmdResolveImage,
        kCmdSetEvent,
        kCmdResetEvent,
        kCmdWaitEvents,
        kCmdPipelineBarrier,
        kCmdBeginQuery,
        kCmdEndQuery,
        kCmdResetQueryPool,
        kCmdWriteTimestamp,
        kCmdCopyQueryPoolResults,
        kCmdPushConstants,
        kCmdBeginRenderPass,
        kCmdNextSubpass,
        kCmdEndRenderPass,
        kCmdExecuteCommands,
        kCmdSetDeviceMask,
        kCmdDispatchBase,
        kCmdDrawIndirectCount,
        kCmdDrawIndexedIndirectCount,
        kCmdBeginRenderPass2,
        kCmdNextSubpass2,
        kCmdEndRenderPass2,
        kCmdSetEvent2,
        kCmdResetEvent2,
        kCmdWaitEvents2,
        kCmdPipelineBarrier2,
        kCmdWriteTimestamp2,
        kCmdCopyBuffer2,
        kCmdCopyImage2,
        kCmdCopyBufferToImage2,
        kCmdCopyImageToBuffer2,
        kCmdBlitImage2,
        kCmdResolveImage2,
        kCmdBeginRendering,
        kCmdEndRendering,
        kCmdSetCullMode,
        kCmdSetFrontFace,
        kCmdSetPrimitiveTopology,
        kCmdSetViewportWithCount,
        kCmdSetScissorWithCount,
        kCmdBindVertexBuffers2,
        kCmdSetDepthTestEnable,
        kCmdSetDepthWriteEnable,
        kCmdSetDepthCompareOp,
        kCmdSetDepthBoundsTestEnable,
        kCmdSetStencilTestEnable,
        kCmdSetStencilOp,
        kCmdSetRasterizerDiscardEnable,
        kCmdSetDepthBiasEnable,
        kCmdSetPrimitiveRestartEnable,
        kCmdBeginVideoCodingKHR,
        kCmdEndVideoCodingKHR,
        kCmdControlVideoCodingKHR,
        kCmdDecodeVideoKHR,
        kCmdBeginRenderingKHR,
        kCmdEndRenderingKHR,
        kCmdSetDeviceMaskKHR,
        kCmdDispatchBaseKHR,
        kCmdPushDescriptorSetKHR,
        kCmdPushDescriptorSetWithTemplateKHR,
        kCmdBeginRenderPass2KHR,
        kCmdNextSubpass2KHR,
        kCmdEndRenderPass2KHR,
        kCmdDrawIndirectCountKHR,
        kCmdDrawIndexedIndirectCountKHR,
        kCmdSetFragmentShadingRateKHR,
        kCmdSetRenderingAttachmentLocationsKHR,
        kCmdSetRenderingInputAttachmentIndicesKHR,
        kCmdEncodeVideoKHR,
        kCmdSetEvent2KHR,
        kCmdResetEvent2KHR,
        kCmdWaitEvents2KHR,
        kCmdPipelineBarrier2KHR,
        kCmdWriteTimestamp2KHR,
        kCmdWriteBufferMarker2AMD,
        kCmdCopyBuffer2KHR,
        kCmdCopyImage2KHR,
        kCmdCopyBufferToImage2KHR,
        kCmdCopyImageToBuffer2KHR,
        kCmdBlitImage2KHR,
        kCmdResolveImage2KHR,
        kCmdTraceRaysIndirect2KHR,
        kCmdBindIndexBuffer2KHR,
        kCmdSetLineStippleKHR,
        kCmdBindDescriptorSets2KHR,
        kCmdPushConstants2KHR,
        kCmdPushDescriptorSet2KHR,
        kCmdPushDescriptorSetWithTemplate2KHR,
        kCmdSetDescriptorBufferOffsets2EXT,
        kCmdBindDescriptorBufferEmbeddedSamplers2EXT,
        kCmdDebugMarkerBeginEXT,
        kCmdDebugMarkerEndEXT,
        kCmdDebugMarkerInsertEXT,
        kCmdBindTransformFeedbackBuffersEXT,
        kCmdBeginTransformFeedbackEXT,
        kCmdEndTransformFeedbackEXT,
        kCmdBeginQueryIndexedEXT,
        kCmdEndQueryIndexedEXT,
        kCmdDrawIndirectByteCountEXT,
        kCmdCuLaunchKernelNVX,
        kCmdDrawIndirectCountAMD,
        kCmdDrawIndexedIndirectCountAMD,
        kCmdBeginConditionalRenderingEXT,
        kCmdEndConditionalRenderingEXT,
        kCmdSetViewportWScalingNV,
        kCmdSetDiscardRectangleEXT,
        kCmdSetDiscardRectangleEnableEXT,
        kCmdSetDiscardRectangleModeEXT,
        kCmdBeginDebugUtilsLabelEXT,
        kCmdEndDebugUtilsLabelEXT,
        kCmdInsertDebugUtilsLabelEXT,
#ifdef VK_ENABLE_BETA_EXTENSIONS
        kCmdInitializeGraphScratchMemoryAMDX,
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
        kCmdDispatchGraphAMDX,
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
        kCmdDispatchGraphIndirectAMDX,
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
        kCmdDispatchGraphIndirectCountAMDX,
#endif  // VK_ENABLE_BETA_EXTENSIONS
        kCmdSetSampleLocationsEXT,
        kCmdBindShadingRateImageNV,
        kCmdSetViewportShadingRatePaletteNV,
        kCmdSetCoarseSampleOrderNV,
        kCmdBuildAccelerationStructureNV,
        kCmdCopyAccelerationStructureNV,
        kCmdTraceRaysNV,
        kCmdWriteAccelerationStructuresPropertiesNV,
        kCmdWriteBufferMarkerAMD,
        kCmdDrawMeshTasksNV,
        kCmdDrawMeshTasksIndirectNV,
        kCmdDrawMeshTasksIndirectCountNV,
        kCmdSetExclusiveScissorEnableNV,
        kCmdSetExclusiveScissorNV,
        kCmdSetCheckpointNV,
        kCmdSetPerformanceMarkerINTEL,
        kCmdSetPerformanceStreamMarkerINTEL,
        kCmdSetPerformanceOverrideINTEL,
        kCmdSetLineStippleEXT,
        kCmdSetCullModeEXT,
        kCmdSetFrontFaceEXT,
        kCmdSetPrimitiveTopologyEXT,
        kCmdSetViewportWithCountEXT,
        kCmdSetScissorWithCountEXT,
        kCmdBindVertexBuffers2EXT,
        kCmdSetDepthTestEnableEXT,
        kCmdSetDepthWriteEnableEXT,
        kCmdSetDepthCompareOpEXT,
        kCmdSetDepthBoundsTestEnableEXT,
        kCmdSetStencilTestEnableEXT,
        kCmdSetStencilOpEXT,
        kCmdPreprocessGeneratedCommandsNV,
        kCmdExecuteGeneratedCommandsNV,
        kCmdBindPipelineShaderGroupNV,
        kCmdSetDepthBias2EXT,
        kCmdCudaLaunchKernelNV,
        kCmdBindDescriptorBuffersEXT,
        kCmdSetDescriptorBufferOffsetsEXT,
        kCmdBindDescriptorBufferEmbeddedSamplersEXT,
        kCmdSetFragmentShadingRateEnumNV,
        kCmdSetVertexInputEXT,
        kCmdSubpassShadingHUAWEI,
        kCmdBindInvocationMaskHUAWEI,
        kCmdSetPatchControlPointsEXT,
        kCmdSetRasterizerDiscardEnableEXT,
        kCmdSetDepthBiasEnableEXT,
        kCmdSetLogicOpEXT,
        kCmdSetPrimitiveRestartEnableEXT,
        kCmdSetColorWriteEnableEXT,
        kCmdDrawMultiEXT,
        kCmdDrawMultiIndexedEXT,
        kCmdBuildMicromapsEXT,
        kCmdCopyMicromapEXT,
        kCmdCopyMicromapToMemoryEXT,
        kCmdCopyMemoryToMicromapEXT,
        kCmdWriteMicromapsPropertiesEXT,
        kCmdDrawClusterHUAWEI,
        kCmdDrawClusterIndirectHUAWEI,
        kCmdCopyMemoryIndirectNV,
        kCmdCopyMemoryToImageIndirectNV,
        kCmdDecompressMemoryNV,
        kCmdDecompressMemoryIndirectCountNV,
        kCmdUpdatePipelineIndirectBufferNV,
        kCmdSetDepthClampEnableEXT,
        kCmdSetPolygonModeEXT,
        kCmdSetRasterizationSamplesEXT,
        kCmdSetSampleMaskEXT,
        kCmdSetAlphaToCoverageEnableEXT,
        kCmdSetAlphaToOneEnableEXT,
        kCmdSetLogicOpEnableEXT,
        kCmdSetColorBlendEnableEXT,
        kCmdSetColorBlendEquationEXT,
        kCmdSetColorWriteMaskEXT,
        kCmdSetTessellationDomainOriginEXT,
        kCmdSetRasterizationStreamEXT,
        kCmdSetConservativeRasterizationModeEXT,
        kCmdSetExtraPrimitiveOverestimationSizeEXT,
        kCmdSetDepthClipEnableEXT,
        kCmdSetSampleLocationsEnableEXT,
        kCmdSetColorBlendAdvancedEXT,
        kCmdSetProvokingVertexModeEXT,
        kCmdSetLineRasterizationModeEXT,
        kCmdSetLineStippleEnableEXT,
        kCmdSetDepthClipNegativeOneToOneEXT,
        kCmdSetViewportWScalingEnableNV,
        kCmdSetViewportSwizzleNV,
        kCmdSetCoverageToColorEnableNV,
        kCmdSetCoverageToColorLocationNV,
        kCmdSetCoverageModulationModeNV,
        kCmdSetCoverageModulationTableEnableNV,
        kCmdSetCoverageModulationTableNV,
        kCmdSetShadingRateImageEnableNV,
        kCmdSetRepresentativeFragmentTestEnableNV,
        kCmdSetCoverageReductionModeNV,
        kCmdOpticalFlowExecuteNV,
        kCmdBindShadersEXT,
        kCmdSetDepthClampRangeEXT,
        kCmdSetAttachmentFeedbackLoopEnableEXT,
        kCmdPreprocessGeneratedCommandsEXT,
        kCmdExecuteGeneratedCommandsEXT,
        kCmdBuildAccelerationStructuresKHR,
        kCmdBuildAccelerationStructuresIndirectKHR,
        kCmdCopyAccelerationStructureKHR,
        kCmdCopyAccelerationStructureToMemoryKHR,
        kCmdCopyMemoryToAccelerationStructureKHR,
        kCmdWriteAccelerationStructuresPropertiesKHR,
        kCmdTraceRaysKHR,
        kCmdTraceRaysIndirectKHR,
        kCmdSetRayTracingPipelineStackSizeKHR,
        kCmdDrawMeshTasksEXT,
        kCmdDrawMeshTasksIndirectEXT,
        kCmdDrawMeshTasksIndirectCountEXT,
    };  // enum Type

   public:
    static const char* GetCommandName(const Command& cmd);

    Type type;
    uint32_t id;
    void* parameters;
    std::vector<std::string> labels;
};  // struct Command

// Define structs for command parameters

struct BeginCommandBufferArgs {
    VkCommandBuffer commandBuffer;
    const VkCommandBufferBeginInfo* pBeginInfo;
};

struct EndCommandBufferArgs {
    VkCommandBuffer commandBuffer;
};

struct ResetCommandBufferArgs {
    VkCommandBuffer commandBuffer;
    VkCommandBufferResetFlags flags;
};

struct CmdBindPipelineArgs {
    VkCommandBuffer commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    VkPipeline pipeline;
};

struct CmdSetViewportArgs {
    VkCommandBuffer commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    const VkViewport* pViewports;
};

struct CmdSetScissorArgs {
    VkCommandBuffer commandBuffer;
    uint32_t firstScissor;
    uint32_t scissorCount;
    const VkRect2D* pScissors;
};

struct CmdSetLineWidthArgs {
    VkCommandBuffer commandBuffer;
    float lineWidth;
};

struct CmdSetDepthBiasArgs {
    VkCommandBuffer commandBuffer;
    float depthBiasConstantFactor;
    float depthBiasClamp;
    float depthBiasSlopeFactor;
};

struct CmdSetBlendConstantsArgs {
    VkCommandBuffer commandBuffer;
    float blendConstants[4];
};

struct CmdSetDepthBoundsArgs {
    VkCommandBuffer commandBuffer;
    float minDepthBounds;
    float maxDepthBounds;
};

struct CmdSetStencilCompareMaskArgs {
    VkCommandBuffer commandBuffer;
    VkStencilFaceFlags faceMask;
    uint32_t compareMask;
};

struct CmdSetStencilWriteMaskArgs {
    VkCommandBuffer commandBuffer;
    VkStencilFaceFlags faceMask;
    uint32_t writeMask;
};

struct CmdSetStencilReferenceArgs {
    VkCommandBuffer commandBuffer;
    VkStencilFaceFlags faceMask;
    uint32_t reference;
};

struct CmdBindDescriptorSetsArgs {
    VkCommandBuffer commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    VkPipelineLayout layout;
    uint32_t firstSet;
    uint32_t descriptorSetCount;
    const VkDescriptorSet* pDescriptorSets;
    uint32_t dynamicOffsetCount;
    const uint32_t* pDynamicOffsets;
};

struct CmdBindIndexBufferArgs {
    VkCommandBuffer commandBuffer;
    VkBuffer buffer;
    VkDeviceSize offset;
    VkIndexType indexType;
};

struct CmdBindVertexBuffersArgs {
    VkCommandBuffer commandBuffer;
    uint32_t firstBinding;
    uint32_t bindingCount;
    const VkBuffer* pBuffers;
    const VkDeviceSize* pOffsets;
};

struct CmdDrawArgs {
    VkCommandBuffer commandBuffer;
    uint32_t vertexCount;
    uint32_t instanceCount;
    uint32_t firstVertex;
    uint32_t firstInstance;
};

struct CmdDrawIndexedArgs {
    VkCommandBuffer commandBuffer;
    uint32_t indexCount;
    uint32_t instanceCount;
    uint32_t firstIndex;
    int32_t vertexOffset;
    uint32_t firstInstance;
};

struct CmdDrawIndirectArgs {
    VkCommandBuffer commandBuffer;
    VkBuffer buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;
};

struct CmdDrawIndexedIndirectArgs {
    VkCommandBuffer commandBuffer;
    VkBuffer buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;
};

struct CmdDispatchArgs {
    VkCommandBuffer commandBuffer;
    uint32_t groupCountX;
    uint32_t groupCountY;
    uint32_t groupCountZ;
};

struct CmdDispatchIndirectArgs {
    VkCommandBuffer commandBuffer;
    VkBuffer buffer;
    VkDeviceSize offset;
};

struct CmdCopyBufferArgs {
    VkCommandBuffer commandBuffer;
    VkBuffer srcBuffer;
    VkBuffer dstBuffer;
    uint32_t regionCount;
    const VkBufferCopy* pRegions;
};

struct CmdCopyImageArgs {
    VkCommandBuffer commandBuffer;
    VkImage srcImage;
    VkImageLayout srcImageLayout;
    VkImage dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    const VkImageCopy* pRegions;
};

struct CmdBlitImageArgs {
    VkCommandBuffer commandBuffer;
    VkImage srcImage;
    VkImageLayout srcImageLayout;
    VkImage dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    const VkImageBlit* pRegions;
    VkFilter filter;
};

struct CmdCopyBufferToImageArgs {
    VkCommandBuffer commandBuffer;
    VkBuffer srcBuffer;
    VkImage dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    const VkBufferImageCopy* pRegions;
};

struct CmdCopyImageToBufferArgs {
    VkCommandBuffer commandBuffer;
    VkImage srcImage;
    VkImageLayout srcImageLayout;
    VkBuffer dstBuffer;
    uint32_t regionCount;
    const VkBufferImageCopy* pRegions;
};

struct CmdUpdateBufferArgs {
    VkCommandBuffer commandBuffer;
    VkBuffer dstBuffer;
    VkDeviceSize dstOffset;
    VkDeviceSize dataSize;
    const void* pData;
};

struct CmdFillBufferArgs {
    VkCommandBuffer commandBuffer;
    VkBuffer dstBuffer;
    VkDeviceSize dstOffset;
    VkDeviceSize size;
    uint32_t data;
};

struct CmdClearColorImageArgs {
    VkCommandBuffer commandBuffer;
    VkImage image;
    VkImageLayout imageLayout;
    const VkClearColorValue* pColor;
    uint32_t rangeCount;
    const VkImageSubresourceRange* pRanges;
};

struct CmdClearDepthStencilImageArgs {
    VkCommandBuffer commandBuffer;
    VkImage image;
    VkImageLayout imageLayout;
    const VkClearDepthStencilValue* pDepthStencil;
    uint32_t rangeCount;
    const VkImageSubresourceRange* pRanges;
};

struct CmdClearAttachmentsArgs {
    VkCommandBuffer commandBuffer;
    uint32_t attachmentCount;
    const VkClearAttachment* pAttachments;
    uint32_t rectCount;
    const VkClearRect* pRects;
};

struct CmdResolveImageArgs {
    VkCommandBuffer commandBuffer;
    VkImage srcImage;
    VkImageLayout srcImageLayout;
    VkImage dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    const VkImageResolve* pRegions;
};

struct CmdSetEventArgs {
    VkCommandBuffer commandBuffer;
    VkEvent event;
    VkPipelineStageFlags stageMask;
};

struct CmdResetEventArgs {
    VkCommandBuffer commandBuffer;
    VkEvent event;
    VkPipelineStageFlags stageMask;
};

struct CmdWaitEventsArgs {
    VkCommandBuffer commandBuffer;
    uint32_t eventCount;
    const VkEvent* pEvents;
    VkPipelineStageFlags srcStageMask;
    VkPipelineStageFlags dstStageMask;
    uint32_t memoryBarrierCount;
    const VkMemoryBarrier* pMemoryBarriers;
    uint32_t bufferMemoryBarrierCount;
    const VkBufferMemoryBarrier* pBufferMemoryBarriers;
    uint32_t imageMemoryBarrierCount;
    const VkImageMemoryBarrier* pImageMemoryBarriers;
};

struct CmdPipelineBarrierArgs {
    VkCommandBuffer commandBuffer;
    VkPipelineStageFlags srcStageMask;
    VkPipelineStageFlags dstStageMask;
    VkDependencyFlags dependencyFlags;
    uint32_t memoryBarrierCount;
    const VkMemoryBarrier* pMemoryBarriers;
    uint32_t bufferMemoryBarrierCount;
    const VkBufferMemoryBarrier* pBufferMemoryBarriers;
    uint32_t imageMemoryBarrierCount;
    const VkImageMemoryBarrier* pImageMemoryBarriers;
};

struct CmdBeginQueryArgs {
    VkCommandBuffer commandBuffer;
    VkQueryPool queryPool;
    uint32_t query;
    VkQueryControlFlags flags;
};

struct CmdEndQueryArgs {
    VkCommandBuffer commandBuffer;
    VkQueryPool queryPool;
    uint32_t query;
};

struct CmdResetQueryPoolArgs {
    VkCommandBuffer commandBuffer;
    VkQueryPool queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;
};

struct CmdWriteTimestampArgs {
    VkCommandBuffer commandBuffer;
    VkPipelineStageFlagBits pipelineStage;
    VkQueryPool queryPool;
    uint32_t query;
};

struct CmdCopyQueryPoolResultsArgs {
    VkCommandBuffer commandBuffer;
    VkQueryPool queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;
    VkBuffer dstBuffer;
    VkDeviceSize dstOffset;
    VkDeviceSize stride;
    VkQueryResultFlags flags;
};

struct CmdPushConstantsArgs {
    VkCommandBuffer commandBuffer;
    VkPipelineLayout layout;
    VkShaderStageFlags stageFlags;
    uint32_t offset;
    uint32_t size;
    const void* pValues;
};

struct CmdBeginRenderPassArgs {
    VkCommandBuffer commandBuffer;
    const VkRenderPassBeginInfo* pRenderPassBegin;
    VkSubpassContents contents;
};

struct CmdNextSubpassArgs {
    VkCommandBuffer commandBuffer;
    VkSubpassContents contents;
};

struct CmdEndRenderPassArgs {
    VkCommandBuffer commandBuffer;
};

struct CmdExecuteCommandsArgs {
    VkCommandBuffer commandBuffer;
    uint32_t commandBufferCount;
    const VkCommandBuffer* pCommandBuffers;
};

struct CmdSetDeviceMaskArgs {
    VkCommandBuffer commandBuffer;
    uint32_t deviceMask;
};

struct CmdDispatchBaseArgs {
    VkCommandBuffer commandBuffer;
    uint32_t baseGroupX;
    uint32_t baseGroupY;
    uint32_t baseGroupZ;
    uint32_t groupCountX;
    uint32_t groupCountY;
    uint32_t groupCountZ;
};

struct CmdDrawIndirectCountArgs {
    VkCommandBuffer commandBuffer;
    VkBuffer buffer;
    VkDeviceSize offset;
    VkBuffer countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;
};

struct CmdDrawIndexedIndirectCountArgs {
    VkCommandBuffer commandBuffer;
    VkBuffer buffer;
    VkDeviceSize offset;
    VkBuffer countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;
};

struct CmdBeginRenderPass2Args {
    VkCommandBuffer commandBuffer;
    const VkRenderPassBeginInfo* pRenderPassBegin;
    const VkSubpassBeginInfo* pSubpassBeginInfo;
};

struct CmdNextSubpass2Args {
    VkCommandBuffer commandBuffer;
    const VkSubpassBeginInfo* pSubpassBeginInfo;
    const VkSubpassEndInfo* pSubpassEndInfo;
};

struct CmdEndRenderPass2Args {
    VkCommandBuffer commandBuffer;
    const VkSubpassEndInfo* pSubpassEndInfo;
};

struct CmdSetEvent2Args {
    VkCommandBuffer commandBuffer;
    VkEvent event;
    const VkDependencyInfo* pDependencyInfo;
};

struct CmdResetEvent2Args {
    VkCommandBuffer commandBuffer;
    VkEvent event;
    VkPipelineStageFlags2 stageMask;
};

struct CmdWaitEvents2Args {
    VkCommandBuffer commandBuffer;
    uint32_t eventCount;
    const VkEvent* pEvents;
    const VkDependencyInfo* pDependencyInfos;
};

struct CmdPipelineBarrier2Args {
    VkCommandBuffer commandBuffer;
    const VkDependencyInfo* pDependencyInfo;
};

struct CmdWriteTimestamp2Args {
    VkCommandBuffer commandBuffer;
    VkPipelineStageFlags2 stage;
    VkQueryPool queryPool;
    uint32_t query;
};

struct CmdCopyBuffer2Args {
    VkCommandBuffer commandBuffer;
    const VkCopyBufferInfo2* pCopyBufferInfo;
};

struct CmdCopyImage2Args {
    VkCommandBuffer commandBuffer;
    const VkCopyImageInfo2* pCopyImageInfo;
};

struct CmdCopyBufferToImage2Args {
    VkCommandBuffer commandBuffer;
    const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo;
};

struct CmdCopyImageToBuffer2Args {
    VkCommandBuffer commandBuffer;
    const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo;
};

struct CmdBlitImage2Args {
    VkCommandBuffer commandBuffer;
    const VkBlitImageInfo2* pBlitImageInfo;
};

struct CmdResolveImage2Args {
    VkCommandBuffer commandBuffer;
    const VkResolveImageInfo2* pResolveImageInfo;
};

struct CmdBeginRenderingArgs {
    VkCommandBuffer commandBuffer;
    const VkRenderingInfo* pRenderingInfo;
};

struct CmdEndRenderingArgs {
    VkCommandBuffer commandBuffer;
};

struct CmdSetCullModeArgs {
    VkCommandBuffer commandBuffer;
    VkCullModeFlags cullMode;
};

struct CmdSetFrontFaceArgs {
    VkCommandBuffer commandBuffer;
    VkFrontFace frontFace;
};

struct CmdSetPrimitiveTopologyArgs {
    VkCommandBuffer commandBuffer;
    VkPrimitiveTopology primitiveTopology;
};

struct CmdSetViewportWithCountArgs {
    VkCommandBuffer commandBuffer;
    uint32_t viewportCount;
    const VkViewport* pViewports;
};

struct CmdSetScissorWithCountArgs {
    VkCommandBuffer commandBuffer;
    uint32_t scissorCount;
    const VkRect2D* pScissors;
};

struct CmdBindVertexBuffers2Args {
    VkCommandBuffer commandBuffer;
    uint32_t firstBinding;
    uint32_t bindingCount;
    const VkBuffer* pBuffers;
    const VkDeviceSize* pOffsets;
    const VkDeviceSize* pSizes;
    const VkDeviceSize* pStrides;
};

struct CmdSetDepthTestEnableArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 depthTestEnable;
};

struct CmdSetDepthWriteEnableArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 depthWriteEnable;
};

struct CmdSetDepthCompareOpArgs {
    VkCommandBuffer commandBuffer;
    VkCompareOp depthCompareOp;
};

struct CmdSetDepthBoundsTestEnableArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 depthBoundsTestEnable;
};

struct CmdSetStencilTestEnableArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 stencilTestEnable;
};

struct CmdSetStencilOpArgs {
    VkCommandBuffer commandBuffer;
    VkStencilFaceFlags faceMask;
    VkStencilOp failOp;
    VkStencilOp passOp;
    VkStencilOp depthFailOp;
    VkCompareOp compareOp;
};

struct CmdSetRasterizerDiscardEnableArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 rasterizerDiscardEnable;
};

struct CmdSetDepthBiasEnableArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 depthBiasEnable;
};

struct CmdSetPrimitiveRestartEnableArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 primitiveRestartEnable;
};

struct CmdBeginVideoCodingKHRArgs {
    VkCommandBuffer commandBuffer;
    const VkVideoBeginCodingInfoKHR* pBeginInfo;
};

struct CmdEndVideoCodingKHRArgs {
    VkCommandBuffer commandBuffer;
    const VkVideoEndCodingInfoKHR* pEndCodingInfo;
};

struct CmdControlVideoCodingKHRArgs {
    VkCommandBuffer commandBuffer;
    const VkVideoCodingControlInfoKHR* pCodingControlInfo;
};

struct CmdDecodeVideoKHRArgs {
    VkCommandBuffer commandBuffer;
    const VkVideoDecodeInfoKHR* pDecodeInfo;
};

struct CmdBeginRenderingKHRArgs {
    VkCommandBuffer commandBuffer;
    const VkRenderingInfo* pRenderingInfo;
};

struct CmdEndRenderingKHRArgs {
    VkCommandBuffer commandBuffer;
};

struct CmdSetDeviceMaskKHRArgs {
    VkCommandBuffer commandBuffer;
    uint32_t deviceMask;
};

struct CmdDispatchBaseKHRArgs {
    VkCommandBuffer commandBuffer;
    uint32_t baseGroupX;
    uint32_t baseGroupY;
    uint32_t baseGroupZ;
    uint32_t groupCountX;
    uint32_t groupCountY;
    uint32_t groupCountZ;
};

struct CmdPushDescriptorSetKHRArgs {
    VkCommandBuffer commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    VkPipelineLayout layout;
    uint32_t set;
    uint32_t descriptorWriteCount;
    const VkWriteDescriptorSet* pDescriptorWrites;
};

struct CmdPushDescriptorSetWithTemplateKHRArgs {
    VkCommandBuffer commandBuffer;
    VkDescriptorUpdateTemplate descriptorUpdateTemplate;
    VkPipelineLayout layout;
    uint32_t set;
    const void* pData;
};

struct CmdBeginRenderPass2KHRArgs {
    VkCommandBuffer commandBuffer;
    const VkRenderPassBeginInfo* pRenderPassBegin;
    const VkSubpassBeginInfo* pSubpassBeginInfo;
};

struct CmdNextSubpass2KHRArgs {
    VkCommandBuffer commandBuffer;
    const VkSubpassBeginInfo* pSubpassBeginInfo;
    const VkSubpassEndInfo* pSubpassEndInfo;
};

struct CmdEndRenderPass2KHRArgs {
    VkCommandBuffer commandBuffer;
    const VkSubpassEndInfo* pSubpassEndInfo;
};

struct CmdDrawIndirectCountKHRArgs {
    VkCommandBuffer commandBuffer;
    VkBuffer buffer;
    VkDeviceSize offset;
    VkBuffer countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;
};

struct CmdDrawIndexedIndirectCountKHRArgs {
    VkCommandBuffer commandBuffer;
    VkBuffer buffer;
    VkDeviceSize offset;
    VkBuffer countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;
};

struct CmdSetFragmentShadingRateKHRArgs {
    VkCommandBuffer commandBuffer;
    const VkExtent2D* pFragmentSize;
    VkFragmentShadingRateCombinerOpKHR combinerOps[2];
};

struct CmdSetRenderingAttachmentLocationsKHRArgs {
    VkCommandBuffer commandBuffer;
    const VkRenderingAttachmentLocationInfoKHR* pLocationInfo;
};

struct CmdSetRenderingInputAttachmentIndicesKHRArgs {
    VkCommandBuffer commandBuffer;
    const VkRenderingInputAttachmentIndexInfoKHR* pInputAttachmentIndexInfo;
};

struct CmdEncodeVideoKHRArgs {
    VkCommandBuffer commandBuffer;
    const VkVideoEncodeInfoKHR* pEncodeInfo;
};

struct CmdSetEvent2KHRArgs {
    VkCommandBuffer commandBuffer;
    VkEvent event;
    const VkDependencyInfo* pDependencyInfo;
};

struct CmdResetEvent2KHRArgs {
    VkCommandBuffer commandBuffer;
    VkEvent event;
    VkPipelineStageFlags2 stageMask;
};

struct CmdWaitEvents2KHRArgs {
    VkCommandBuffer commandBuffer;
    uint32_t eventCount;
    const VkEvent* pEvents;
    const VkDependencyInfo* pDependencyInfos;
};

struct CmdPipelineBarrier2KHRArgs {
    VkCommandBuffer commandBuffer;
    const VkDependencyInfo* pDependencyInfo;
};

struct CmdWriteTimestamp2KHRArgs {
    VkCommandBuffer commandBuffer;
    VkPipelineStageFlags2 stage;
    VkQueryPool queryPool;
    uint32_t query;
};

struct CmdWriteBufferMarker2AMDArgs {
    VkCommandBuffer commandBuffer;
    VkPipelineStageFlags2 stage;
    VkBuffer dstBuffer;
    VkDeviceSize dstOffset;
    uint32_t marker;
};

struct CmdCopyBuffer2KHRArgs {
    VkCommandBuffer commandBuffer;
    const VkCopyBufferInfo2* pCopyBufferInfo;
};

struct CmdCopyImage2KHRArgs {
    VkCommandBuffer commandBuffer;
    const VkCopyImageInfo2* pCopyImageInfo;
};

struct CmdCopyBufferToImage2KHRArgs {
    VkCommandBuffer commandBuffer;
    const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo;
};

struct CmdCopyImageToBuffer2KHRArgs {
    VkCommandBuffer commandBuffer;
    const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo;
};

struct CmdBlitImage2KHRArgs {
    VkCommandBuffer commandBuffer;
    const VkBlitImageInfo2* pBlitImageInfo;
};

struct CmdResolveImage2KHRArgs {
    VkCommandBuffer commandBuffer;
    const VkResolveImageInfo2* pResolveImageInfo;
};

struct CmdTraceRaysIndirect2KHRArgs {
    VkCommandBuffer commandBuffer;
    VkDeviceAddress indirectDeviceAddress;
};

struct CmdBindIndexBuffer2KHRArgs {
    VkCommandBuffer commandBuffer;
    VkBuffer buffer;
    VkDeviceSize offset;
    VkDeviceSize size;
    VkIndexType indexType;
};

struct CmdSetLineStippleKHRArgs {
    VkCommandBuffer commandBuffer;
    uint32_t lineStippleFactor;
    uint16_t lineStipplePattern;
};

struct CmdBindDescriptorSets2KHRArgs {
    VkCommandBuffer commandBuffer;
    const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo;
};

struct CmdPushConstants2KHRArgs {
    VkCommandBuffer commandBuffer;
    const VkPushConstantsInfoKHR* pPushConstantsInfo;
};

struct CmdPushDescriptorSet2KHRArgs {
    VkCommandBuffer commandBuffer;
    const VkPushDescriptorSetInfoKHR* pPushDescriptorSetInfo;
};

struct CmdPushDescriptorSetWithTemplate2KHRArgs {
    VkCommandBuffer commandBuffer;
    const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo;
};

struct CmdSetDescriptorBufferOffsets2EXTArgs {
    VkCommandBuffer commandBuffer;
    const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo;
};

struct CmdBindDescriptorBufferEmbeddedSamplers2EXTArgs {
    VkCommandBuffer commandBuffer;
    const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo;
};

struct CmdDebugMarkerBeginEXTArgs {
    VkCommandBuffer commandBuffer;
    const VkDebugMarkerMarkerInfoEXT* pMarkerInfo;
};

struct CmdDebugMarkerEndEXTArgs {
    VkCommandBuffer commandBuffer;
};

struct CmdDebugMarkerInsertEXTArgs {
    VkCommandBuffer commandBuffer;
    const VkDebugMarkerMarkerInfoEXT* pMarkerInfo;
};

struct CmdBindTransformFeedbackBuffersEXTArgs {
    VkCommandBuffer commandBuffer;
    uint32_t firstBinding;
    uint32_t bindingCount;
    const VkBuffer* pBuffers;
    const VkDeviceSize* pOffsets;
    const VkDeviceSize* pSizes;
};

struct CmdBeginTransformFeedbackEXTArgs {
    VkCommandBuffer commandBuffer;
    uint32_t firstCounterBuffer;
    uint32_t counterBufferCount;
    const VkBuffer* pCounterBuffers;
    const VkDeviceSize* pCounterBufferOffsets;
};

struct CmdEndTransformFeedbackEXTArgs {
    VkCommandBuffer commandBuffer;
    uint32_t firstCounterBuffer;
    uint32_t counterBufferCount;
    const VkBuffer* pCounterBuffers;
    const VkDeviceSize* pCounterBufferOffsets;
};

struct CmdBeginQueryIndexedEXTArgs {
    VkCommandBuffer commandBuffer;
    VkQueryPool queryPool;
    uint32_t query;
    VkQueryControlFlags flags;
    uint32_t index;
};

struct CmdEndQueryIndexedEXTArgs {
    VkCommandBuffer commandBuffer;
    VkQueryPool queryPool;
    uint32_t query;
    uint32_t index;
};

struct CmdDrawIndirectByteCountEXTArgs {
    VkCommandBuffer commandBuffer;
    uint32_t instanceCount;
    uint32_t firstInstance;
    VkBuffer counterBuffer;
    VkDeviceSize counterBufferOffset;
    uint32_t counterOffset;
    uint32_t vertexStride;
};

struct CmdCuLaunchKernelNVXArgs {
    VkCommandBuffer commandBuffer;
    const VkCuLaunchInfoNVX* pLaunchInfo;
};

struct CmdDrawIndirectCountAMDArgs {
    VkCommandBuffer commandBuffer;
    VkBuffer buffer;
    VkDeviceSize offset;
    VkBuffer countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;
};

struct CmdDrawIndexedIndirectCountAMDArgs {
    VkCommandBuffer commandBuffer;
    VkBuffer buffer;
    VkDeviceSize offset;
    VkBuffer countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;
};

struct CmdBeginConditionalRenderingEXTArgs {
    VkCommandBuffer commandBuffer;
    const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin;
};

struct CmdEndConditionalRenderingEXTArgs {
    VkCommandBuffer commandBuffer;
};

struct CmdSetViewportWScalingNVArgs {
    VkCommandBuffer commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    const VkViewportWScalingNV* pViewportWScalings;
};

struct CmdSetDiscardRectangleEXTArgs {
    VkCommandBuffer commandBuffer;
    uint32_t firstDiscardRectangle;
    uint32_t discardRectangleCount;
    const VkRect2D* pDiscardRectangles;
};

struct CmdSetDiscardRectangleEnableEXTArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 discardRectangleEnable;
};

struct CmdSetDiscardRectangleModeEXTArgs {
    VkCommandBuffer commandBuffer;
    VkDiscardRectangleModeEXT discardRectangleMode;
};

struct CmdBeginDebugUtilsLabelEXTArgs {
    VkCommandBuffer commandBuffer;
    const VkDebugUtilsLabelEXT* pLabelInfo;
};

struct CmdEndDebugUtilsLabelEXTArgs {
    VkCommandBuffer commandBuffer;
};

struct CmdInsertDebugUtilsLabelEXTArgs {
    VkCommandBuffer commandBuffer;
    const VkDebugUtilsLabelEXT* pLabelInfo;
};

#ifdef VK_ENABLE_BETA_EXTENSIONS
struct CmdInitializeGraphScratchMemoryAMDXArgs {
    VkCommandBuffer commandBuffer;
    VkDeviceAddress scratch;
};
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
struct CmdDispatchGraphAMDXArgs {
    VkCommandBuffer commandBuffer;
    VkDeviceAddress scratch;
    const VkDispatchGraphCountInfoAMDX* pCountInfo;
};
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
struct CmdDispatchGraphIndirectAMDXArgs {
    VkCommandBuffer commandBuffer;
    VkDeviceAddress scratch;
    const VkDispatchGraphCountInfoAMDX* pCountInfo;
};
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
struct CmdDispatchGraphIndirectCountAMDXArgs {
    VkCommandBuffer commandBuffer;
    VkDeviceAddress scratch;
    VkDeviceAddress countInfo;
};
#endif  // VK_ENABLE_BETA_EXTENSIONS

struct CmdSetSampleLocationsEXTArgs {
    VkCommandBuffer commandBuffer;
    const VkSampleLocationsInfoEXT* pSampleLocationsInfo;
};

struct CmdBindShadingRateImageNVArgs {
    VkCommandBuffer commandBuffer;
    VkImageView imageView;
    VkImageLayout imageLayout;
};

struct CmdSetViewportShadingRatePaletteNVArgs {
    VkCommandBuffer commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    const VkShadingRatePaletteNV* pShadingRatePalettes;
};

struct CmdSetCoarseSampleOrderNVArgs {
    VkCommandBuffer commandBuffer;
    VkCoarseSampleOrderTypeNV sampleOrderType;
    uint32_t customSampleOrderCount;
    const VkCoarseSampleOrderCustomNV* pCustomSampleOrders;
};

struct CmdBuildAccelerationStructureNVArgs {
    VkCommandBuffer commandBuffer;
    const VkAccelerationStructureInfoNV* pInfo;
    VkBuffer instanceData;
    VkDeviceSize instanceOffset;
    VkBool32 update;
    VkAccelerationStructureNV dst;
    VkAccelerationStructureNV src;
    VkBuffer scratch;
    VkDeviceSize scratchOffset;
};

struct CmdCopyAccelerationStructureNVArgs {
    VkCommandBuffer commandBuffer;
    VkAccelerationStructureNV dst;
    VkAccelerationStructureNV src;
    VkCopyAccelerationStructureModeKHR mode;
};

struct CmdTraceRaysNVArgs {
    VkCommandBuffer commandBuffer;
    VkBuffer raygenShaderBindingTableBuffer;
    VkDeviceSize raygenShaderBindingOffset;
    VkBuffer missShaderBindingTableBuffer;
    VkDeviceSize missShaderBindingOffset;
    VkDeviceSize missShaderBindingStride;
    VkBuffer hitShaderBindingTableBuffer;
    VkDeviceSize hitShaderBindingOffset;
    VkDeviceSize hitShaderBindingStride;
    VkBuffer callableShaderBindingTableBuffer;
    VkDeviceSize callableShaderBindingOffset;
    VkDeviceSize callableShaderBindingStride;
    uint32_t width;
    uint32_t height;
    uint32_t depth;
};

struct CmdWriteAccelerationStructuresPropertiesNVArgs {
    VkCommandBuffer commandBuffer;
    uint32_t accelerationStructureCount;
    const VkAccelerationStructureNV* pAccelerationStructures;
    VkQueryType queryType;
    VkQueryPool queryPool;
    uint32_t firstQuery;
};

struct CmdWriteBufferMarkerAMDArgs {
    VkCommandBuffer commandBuffer;
    VkPipelineStageFlagBits pipelineStage;
    VkBuffer dstBuffer;
    VkDeviceSize dstOffset;
    uint32_t marker;
};

struct CmdDrawMeshTasksNVArgs {
    VkCommandBuffer commandBuffer;
    uint32_t taskCount;
    uint32_t firstTask;
};

struct CmdDrawMeshTasksIndirectNVArgs {
    VkCommandBuffer commandBuffer;
    VkBuffer buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;
};

struct CmdDrawMeshTasksIndirectCountNVArgs {
    VkCommandBuffer commandBuffer;
    VkBuffer buffer;
    VkDeviceSize offset;
    VkBuffer countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;
};

struct CmdSetExclusiveScissorEnableNVArgs {
    VkCommandBuffer commandBuffer;
    uint32_t firstExclusiveScissor;
    uint32_t exclusiveScissorCount;
    const VkBool32* pExclusiveScissorEnables;
};

struct CmdSetExclusiveScissorNVArgs {
    VkCommandBuffer commandBuffer;
    uint32_t firstExclusiveScissor;
    uint32_t exclusiveScissorCount;
    const VkRect2D* pExclusiveScissors;
};

struct CmdSetCheckpointNVArgs {
    VkCommandBuffer commandBuffer;
    const void* pCheckpointMarker;
};

struct CmdSetPerformanceMarkerINTELArgs {
    VkCommandBuffer commandBuffer;
    const VkPerformanceMarkerInfoINTEL* pMarkerInfo;
};

struct CmdSetPerformanceStreamMarkerINTELArgs {
    VkCommandBuffer commandBuffer;
    const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo;
};

struct CmdSetPerformanceOverrideINTELArgs {
    VkCommandBuffer commandBuffer;
    const VkPerformanceOverrideInfoINTEL* pOverrideInfo;
};

struct CmdSetLineStippleEXTArgs {
    VkCommandBuffer commandBuffer;
    uint32_t lineStippleFactor;
    uint16_t lineStipplePattern;
};

struct CmdSetCullModeEXTArgs {
    VkCommandBuffer commandBuffer;
    VkCullModeFlags cullMode;
};

struct CmdSetFrontFaceEXTArgs {
    VkCommandBuffer commandBuffer;
    VkFrontFace frontFace;
};

struct CmdSetPrimitiveTopologyEXTArgs {
    VkCommandBuffer commandBuffer;
    VkPrimitiveTopology primitiveTopology;
};

struct CmdSetViewportWithCountEXTArgs {
    VkCommandBuffer commandBuffer;
    uint32_t viewportCount;
    const VkViewport* pViewports;
};

struct CmdSetScissorWithCountEXTArgs {
    VkCommandBuffer commandBuffer;
    uint32_t scissorCount;
    const VkRect2D* pScissors;
};

struct CmdBindVertexBuffers2EXTArgs {
    VkCommandBuffer commandBuffer;
    uint32_t firstBinding;
    uint32_t bindingCount;
    const VkBuffer* pBuffers;
    const VkDeviceSize* pOffsets;
    const VkDeviceSize* pSizes;
    const VkDeviceSize* pStrides;
};

struct CmdSetDepthTestEnableEXTArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 depthTestEnable;
};

struct CmdSetDepthWriteEnableEXTArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 depthWriteEnable;
};

struct CmdSetDepthCompareOpEXTArgs {
    VkCommandBuffer commandBuffer;
    VkCompareOp depthCompareOp;
};

struct CmdSetDepthBoundsTestEnableEXTArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 depthBoundsTestEnable;
};

struct CmdSetStencilTestEnableEXTArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 stencilTestEnable;
};

struct CmdSetStencilOpEXTArgs {
    VkCommandBuffer commandBuffer;
    VkStencilFaceFlags faceMask;
    VkStencilOp failOp;
    VkStencilOp passOp;
    VkStencilOp depthFailOp;
    VkCompareOp compareOp;
};

struct CmdPreprocessGeneratedCommandsNVArgs {
    VkCommandBuffer commandBuffer;
    const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo;
};

struct CmdExecuteGeneratedCommandsNVArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 isPreprocessed;
    const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo;
};

struct CmdBindPipelineShaderGroupNVArgs {
    VkCommandBuffer commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    VkPipeline pipeline;
    uint32_t groupIndex;
};

struct CmdSetDepthBias2EXTArgs {
    VkCommandBuffer commandBuffer;
    const VkDepthBiasInfoEXT* pDepthBiasInfo;
};

struct CmdCudaLaunchKernelNVArgs {
    VkCommandBuffer commandBuffer;
    const VkCudaLaunchInfoNV* pLaunchInfo;
};

struct CmdBindDescriptorBuffersEXTArgs {
    VkCommandBuffer commandBuffer;
    uint32_t bufferCount;
    const VkDescriptorBufferBindingInfoEXT* pBindingInfos;
};

struct CmdSetDescriptorBufferOffsetsEXTArgs {
    VkCommandBuffer commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    VkPipelineLayout layout;
    uint32_t firstSet;
    uint32_t setCount;
    const uint32_t* pBufferIndices;
    const VkDeviceSize* pOffsets;
};

struct CmdBindDescriptorBufferEmbeddedSamplersEXTArgs {
    VkCommandBuffer commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    VkPipelineLayout layout;
    uint32_t set;
};

struct CmdSetFragmentShadingRateEnumNVArgs {
    VkCommandBuffer commandBuffer;
    VkFragmentShadingRateNV shadingRate;
    VkFragmentShadingRateCombinerOpKHR combinerOps[2];
};

struct CmdSetVertexInputEXTArgs {
    VkCommandBuffer commandBuffer;
    uint32_t vertexBindingDescriptionCount;
    const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions;
    uint32_t vertexAttributeDescriptionCount;
    const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions;
};

struct CmdSubpassShadingHUAWEIArgs {
    VkCommandBuffer commandBuffer;
};

struct CmdBindInvocationMaskHUAWEIArgs {
    VkCommandBuffer commandBuffer;
    VkImageView imageView;
    VkImageLayout imageLayout;
};

struct CmdSetPatchControlPointsEXTArgs {
    VkCommandBuffer commandBuffer;
    uint32_t patchControlPoints;
};

struct CmdSetRasterizerDiscardEnableEXTArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 rasterizerDiscardEnable;
};

struct CmdSetDepthBiasEnableEXTArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 depthBiasEnable;
};

struct CmdSetLogicOpEXTArgs {
    VkCommandBuffer commandBuffer;
    VkLogicOp logicOp;
};

struct CmdSetPrimitiveRestartEnableEXTArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 primitiveRestartEnable;
};

struct CmdSetColorWriteEnableEXTArgs {
    VkCommandBuffer commandBuffer;
    uint32_t attachmentCount;
    const VkBool32* pColorWriteEnables;
};

struct CmdDrawMultiEXTArgs {
    VkCommandBuffer commandBuffer;
    uint32_t drawCount;
    const VkMultiDrawInfoEXT* pVertexInfo;
    uint32_t instanceCount;
    uint32_t firstInstance;
    uint32_t stride;
};

struct CmdDrawMultiIndexedEXTArgs {
    VkCommandBuffer commandBuffer;
    uint32_t drawCount;
    const VkMultiDrawIndexedInfoEXT* pIndexInfo;
    uint32_t instanceCount;
    uint32_t firstInstance;
    uint32_t stride;
    const int32_t* pVertexOffset;
};

struct CmdBuildMicromapsEXTArgs {
    VkCommandBuffer commandBuffer;
    uint32_t infoCount;
    const VkMicromapBuildInfoEXT* pInfos;
};

struct CmdCopyMicromapEXTArgs {
    VkCommandBuffer commandBuffer;
    const VkCopyMicromapInfoEXT* pInfo;
};

struct CmdCopyMicromapToMemoryEXTArgs {
    VkCommandBuffer commandBuffer;
    const VkCopyMicromapToMemoryInfoEXT* pInfo;
};

struct CmdCopyMemoryToMicromapEXTArgs {
    VkCommandBuffer commandBuffer;
    const VkCopyMemoryToMicromapInfoEXT* pInfo;
};

struct CmdWriteMicromapsPropertiesEXTArgs {
    VkCommandBuffer commandBuffer;
    uint32_t micromapCount;
    const VkMicromapEXT* pMicromaps;
    VkQueryType queryType;
    VkQueryPool queryPool;
    uint32_t firstQuery;
};

struct CmdDrawClusterHUAWEIArgs {
    VkCommandBuffer commandBuffer;
    uint32_t groupCountX;
    uint32_t groupCountY;
    uint32_t groupCountZ;
};

struct CmdDrawClusterIndirectHUAWEIArgs {
    VkCommandBuffer commandBuffer;
    VkBuffer buffer;
    VkDeviceSize offset;
};

struct CmdCopyMemoryIndirectNVArgs {
    VkCommandBuffer commandBuffer;
    VkDeviceAddress copyBufferAddress;
    uint32_t copyCount;
    uint32_t stride;
};

struct CmdCopyMemoryToImageIndirectNVArgs {
    VkCommandBuffer commandBuffer;
    VkDeviceAddress copyBufferAddress;
    uint32_t copyCount;
    uint32_t stride;
    VkImage dstImage;
    VkImageLayout dstImageLayout;
    const VkImageSubresourceLayers* pImageSubresources;
};

struct CmdDecompressMemoryNVArgs {
    VkCommandBuffer commandBuffer;
    uint32_t decompressRegionCount;
    const VkDecompressMemoryRegionNV* pDecompressMemoryRegions;
};

struct CmdDecompressMemoryIndirectCountNVArgs {
    VkCommandBuffer commandBuffer;
    VkDeviceAddress indirectCommandsAddress;
    VkDeviceAddress indirectCommandsCountAddress;
    uint32_t stride;
};

struct CmdUpdatePipelineIndirectBufferNVArgs {
    VkCommandBuffer commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    VkPipeline pipeline;
};

struct CmdSetDepthClampEnableEXTArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 depthClampEnable;
};

struct CmdSetPolygonModeEXTArgs {
    VkCommandBuffer commandBuffer;
    VkPolygonMode polygonMode;
};

struct CmdSetRasterizationSamplesEXTArgs {
    VkCommandBuffer commandBuffer;
    VkSampleCountFlagBits rasterizationSamples;
};

struct CmdSetSampleMaskEXTArgs {
    VkCommandBuffer commandBuffer;
    VkSampleCountFlagBits samples;
    const VkSampleMask* pSampleMask;
};

struct CmdSetAlphaToCoverageEnableEXTArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 alphaToCoverageEnable;
};

struct CmdSetAlphaToOneEnableEXTArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 alphaToOneEnable;
};

struct CmdSetLogicOpEnableEXTArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 logicOpEnable;
};

struct CmdSetColorBlendEnableEXTArgs {
    VkCommandBuffer commandBuffer;
    uint32_t firstAttachment;
    uint32_t attachmentCount;
    const VkBool32* pColorBlendEnables;
};

struct CmdSetColorBlendEquationEXTArgs {
    VkCommandBuffer commandBuffer;
    uint32_t firstAttachment;
    uint32_t attachmentCount;
    const VkColorBlendEquationEXT* pColorBlendEquations;
};

struct CmdSetColorWriteMaskEXTArgs {
    VkCommandBuffer commandBuffer;
    uint32_t firstAttachment;
    uint32_t attachmentCount;
    const VkColorComponentFlags* pColorWriteMasks;
};

struct CmdSetTessellationDomainOriginEXTArgs {
    VkCommandBuffer commandBuffer;
    VkTessellationDomainOrigin domainOrigin;
};

struct CmdSetRasterizationStreamEXTArgs {
    VkCommandBuffer commandBuffer;
    uint32_t rasterizationStream;
};

struct CmdSetConservativeRasterizationModeEXTArgs {
    VkCommandBuffer commandBuffer;
    VkConservativeRasterizationModeEXT conservativeRasterizationMode;
};

struct CmdSetExtraPrimitiveOverestimationSizeEXTArgs {
    VkCommandBuffer commandBuffer;
    float extraPrimitiveOverestimationSize;
};

struct CmdSetDepthClipEnableEXTArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 depthClipEnable;
};

struct CmdSetSampleLocationsEnableEXTArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 sampleLocationsEnable;
};

struct CmdSetColorBlendAdvancedEXTArgs {
    VkCommandBuffer commandBuffer;
    uint32_t firstAttachment;
    uint32_t attachmentCount;
    const VkColorBlendAdvancedEXT* pColorBlendAdvanced;
};

struct CmdSetProvokingVertexModeEXTArgs {
    VkCommandBuffer commandBuffer;
    VkProvokingVertexModeEXT provokingVertexMode;
};

struct CmdSetLineRasterizationModeEXTArgs {
    VkCommandBuffer commandBuffer;
    VkLineRasterizationModeEXT lineRasterizationMode;
};

struct CmdSetLineStippleEnableEXTArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 stippledLineEnable;
};

struct CmdSetDepthClipNegativeOneToOneEXTArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 negativeOneToOne;
};

struct CmdSetViewportWScalingEnableNVArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 viewportWScalingEnable;
};

struct CmdSetViewportSwizzleNVArgs {
    VkCommandBuffer commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    const VkViewportSwizzleNV* pViewportSwizzles;
};

struct CmdSetCoverageToColorEnableNVArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 coverageToColorEnable;
};

struct CmdSetCoverageToColorLocationNVArgs {
    VkCommandBuffer commandBuffer;
    uint32_t coverageToColorLocation;
};

struct CmdSetCoverageModulationModeNVArgs {
    VkCommandBuffer commandBuffer;
    VkCoverageModulationModeNV coverageModulationMode;
};

struct CmdSetCoverageModulationTableEnableNVArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 coverageModulationTableEnable;
};

struct CmdSetCoverageModulationTableNVArgs {
    VkCommandBuffer commandBuffer;
    uint32_t coverageModulationTableCount;
    const float* pCoverageModulationTable;
};

struct CmdSetShadingRateImageEnableNVArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 shadingRateImageEnable;
};

struct CmdSetRepresentativeFragmentTestEnableNVArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 representativeFragmentTestEnable;
};

struct CmdSetCoverageReductionModeNVArgs {
    VkCommandBuffer commandBuffer;
    VkCoverageReductionModeNV coverageReductionMode;
};

struct CmdOpticalFlowExecuteNVArgs {
    VkCommandBuffer commandBuffer;
    VkOpticalFlowSessionNV session;
    const VkOpticalFlowExecuteInfoNV* pExecuteInfo;
};

struct CmdBindShadersEXTArgs {
    VkCommandBuffer commandBuffer;
    uint32_t stageCount;
    const VkShaderStageFlagBits* pStages;
    const VkShaderEXT* pShaders;
};

struct CmdSetDepthClampRangeEXTArgs {
    VkCommandBuffer commandBuffer;
    VkDepthClampModeEXT depthClampMode;
    const VkDepthClampRangeEXT* pDepthClampRange;
};

struct CmdSetAttachmentFeedbackLoopEnableEXTArgs {
    VkCommandBuffer commandBuffer;
    VkImageAspectFlags aspectMask;
};

struct CmdPreprocessGeneratedCommandsEXTArgs {
    VkCommandBuffer commandBuffer;
    const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo;
    VkCommandBuffer stateCommandBuffer;
};

struct CmdExecuteGeneratedCommandsEXTArgs {
    VkCommandBuffer commandBuffer;
    VkBool32 isPreprocessed;
    const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo;
};

struct CmdBuildAccelerationStructuresKHRArgs {
    VkCommandBuffer commandBuffer;
    uint32_t infoCount;
    const VkAccelerationStructureBuildGeometryInfoKHR* pInfos;
    const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos;
};

struct CmdBuildAccelerationStructuresIndirectKHRArgs {
    VkCommandBuffer commandBuffer;
    uint32_t infoCount;
    const VkAccelerationStructureBuildGeometryInfoKHR* pInfos;
    const VkDeviceAddress* pIndirectDeviceAddresses;
    const uint32_t* pIndirectStrides;
    const uint32_t* const* ppMaxPrimitiveCounts;
};

struct CmdCopyAccelerationStructureKHRArgs {
    VkCommandBuffer commandBuffer;
    const VkCopyAccelerationStructureInfoKHR* pInfo;
};

struct CmdCopyAccelerationStructureToMemoryKHRArgs {
    VkCommandBuffer commandBuffer;
    const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo;
};

struct CmdCopyMemoryToAccelerationStructureKHRArgs {
    VkCommandBuffer commandBuffer;
    const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo;
};

struct CmdWriteAccelerationStructuresPropertiesKHRArgs {
    VkCommandBuffer commandBuffer;
    uint32_t accelerationStructureCount;
    const VkAccelerationStructureKHR* pAccelerationStructures;
    VkQueryType queryType;
    VkQueryPool queryPool;
    uint32_t firstQuery;
};

struct CmdTraceRaysKHRArgs {
    VkCommandBuffer commandBuffer;
    const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable;
    const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable;
    const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable;
    const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable;
    uint32_t width;
    uint32_t height;
    uint32_t depth;
};

struct CmdTraceRaysIndirectKHRArgs {
    VkCommandBuffer commandBuffer;
    const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable;
    const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable;
    const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable;
    const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable;
    VkDeviceAddress indirectDeviceAddress;
};

struct CmdSetRayTracingPipelineStackSizeKHRArgs {
    VkCommandBuffer commandBuffer;
    uint32_t pipelineStackSize;
};

struct CmdDrawMeshTasksEXTArgs {
    VkCommandBuffer commandBuffer;
    uint32_t groupCountX;
    uint32_t groupCountY;
    uint32_t groupCountZ;
};

struct CmdDrawMeshTasksIndirectEXTArgs {
    VkCommandBuffer commandBuffer;
    VkBuffer buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;
};

struct CmdDrawMeshTasksIndirectCountEXTArgs {
    VkCommandBuffer commandBuffer;
    VkBuffer buffer;
    VkDeviceSize offset;
    VkBuffer countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;
};

// NOLINTEND
