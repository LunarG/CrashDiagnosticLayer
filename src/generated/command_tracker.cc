
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
 * ***   Update source file intercepts_and_prepost_generator.py for modifications
 * *** ---- WARNING! ----
 *
 ****************************************************************************/

// NOLINTBEGIN

#include <vulkan/vulkan.h>
#include <cassert>

#include "command_common.h"
#include "command_printer.h"
#include "command_tracker.h"

void CommandTracker::Reset() {
    commands_.clear();
    recorder_.Reset();
}

void CommandTracker::SetNameResolver(const ObjectInfoDB *name_resolver) { printer_.SetNameResolver(name_resolver); }

void CommandTracker::PrintCommandParameters(YAML::Emitter &os, const Command &cmd) {
    switch (cmd.type) {
        default:
        case Command::Type::kUnknown:
            // output an empty map for consistency with other command printers
            os << YAML::BeginMap << YAML::EndMap;
            break;
        case Command::Type::kBeginCommandBuffer:
            if (cmd.parameters) {
                auto args = reinterpret_cast<BeginCommandBufferArgs *>(cmd.parameters);
                printer_.PrintBeginCommandBufferArgs(os, *args);
            }
            break;

        case Command::Type::kEndCommandBuffer:
            if (cmd.parameters) {
                auto args = reinterpret_cast<EndCommandBufferArgs *>(cmd.parameters);
                printer_.PrintEndCommandBufferArgs(os, *args);
            }
            break;

        case Command::Type::kResetCommandBuffer:
            if (cmd.parameters) {
                auto args = reinterpret_cast<ResetCommandBufferArgs *>(cmd.parameters);
                printer_.PrintResetCommandBufferArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBindPipeline:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBindPipelineArgs *>(cmd.parameters);
                printer_.PrintCmdBindPipelineArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetViewport:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetViewportArgs *>(cmd.parameters);
                printer_.PrintCmdSetViewportArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetScissor:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetScissorArgs *>(cmd.parameters);
                printer_.PrintCmdSetScissorArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetLineWidth:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetLineWidthArgs *>(cmd.parameters);
                printer_.PrintCmdSetLineWidthArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetDepthBias:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetDepthBiasArgs *>(cmd.parameters);
                printer_.PrintCmdSetDepthBiasArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetBlendConstants:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetBlendConstantsArgs *>(cmd.parameters);
                printer_.PrintCmdSetBlendConstantsArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetDepthBounds:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetDepthBoundsArgs *>(cmd.parameters);
                printer_.PrintCmdSetDepthBoundsArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetStencilCompareMask:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetStencilCompareMaskArgs *>(cmd.parameters);
                printer_.PrintCmdSetStencilCompareMaskArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetStencilWriteMask:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetStencilWriteMaskArgs *>(cmd.parameters);
                printer_.PrintCmdSetStencilWriteMaskArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetStencilReference:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetStencilReferenceArgs *>(cmd.parameters);
                printer_.PrintCmdSetStencilReferenceArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBindDescriptorSets:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBindDescriptorSetsArgs *>(cmd.parameters);
                printer_.PrintCmdBindDescriptorSetsArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBindIndexBuffer:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBindIndexBufferArgs *>(cmd.parameters);
                printer_.PrintCmdBindIndexBufferArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBindVertexBuffers:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBindVertexBuffersArgs *>(cmd.parameters);
                printer_.PrintCmdBindVertexBuffersArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDraw:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDrawArgs *>(cmd.parameters);
                printer_.PrintCmdDrawArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDrawIndexed:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDrawIndexedArgs *>(cmd.parameters);
                printer_.PrintCmdDrawIndexedArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDrawIndirect:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDrawIndirectArgs *>(cmd.parameters);
                printer_.PrintCmdDrawIndirectArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDrawIndexedIndirect:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDrawIndexedIndirectArgs *>(cmd.parameters);
                printer_.PrintCmdDrawIndexedIndirectArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDispatch:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDispatchArgs *>(cmd.parameters);
                printer_.PrintCmdDispatchArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDispatchIndirect:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDispatchIndirectArgs *>(cmd.parameters);
                printer_.PrintCmdDispatchIndirectArgs(os, *args);
            }
            break;

        case Command::Type::kCmdCopyBuffer:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdCopyBufferArgs *>(cmd.parameters);
                printer_.PrintCmdCopyBufferArgs(os, *args);
            }
            break;

        case Command::Type::kCmdCopyImage:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdCopyImageArgs *>(cmd.parameters);
                printer_.PrintCmdCopyImageArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBlitImage:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBlitImageArgs *>(cmd.parameters);
                printer_.PrintCmdBlitImageArgs(os, *args);
            }
            break;

        case Command::Type::kCmdCopyBufferToImage:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdCopyBufferToImageArgs *>(cmd.parameters);
                printer_.PrintCmdCopyBufferToImageArgs(os, *args);
            }
            break;

        case Command::Type::kCmdCopyImageToBuffer:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdCopyImageToBufferArgs *>(cmd.parameters);
                printer_.PrintCmdCopyImageToBufferArgs(os, *args);
            }
            break;

        case Command::Type::kCmdUpdateBuffer:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdUpdateBufferArgs *>(cmd.parameters);
                printer_.PrintCmdUpdateBufferArgs(os, *args);
            }
            break;

        case Command::Type::kCmdFillBuffer:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdFillBufferArgs *>(cmd.parameters);
                printer_.PrintCmdFillBufferArgs(os, *args);
            }
            break;

        case Command::Type::kCmdClearColorImage:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdClearColorImageArgs *>(cmd.parameters);
                printer_.PrintCmdClearColorImageArgs(os, *args);
            }
            break;

        case Command::Type::kCmdClearDepthStencilImage:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdClearDepthStencilImageArgs *>(cmd.parameters);
                printer_.PrintCmdClearDepthStencilImageArgs(os, *args);
            }
            break;

        case Command::Type::kCmdClearAttachments:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdClearAttachmentsArgs *>(cmd.parameters);
                printer_.PrintCmdClearAttachmentsArgs(os, *args);
            }
            break;

        case Command::Type::kCmdResolveImage:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdResolveImageArgs *>(cmd.parameters);
                printer_.PrintCmdResolveImageArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetEvent:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetEventArgs *>(cmd.parameters);
                printer_.PrintCmdSetEventArgs(os, *args);
            }
            break;

        case Command::Type::kCmdResetEvent:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdResetEventArgs *>(cmd.parameters);
                printer_.PrintCmdResetEventArgs(os, *args);
            }
            break;

        case Command::Type::kCmdWaitEvents:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdWaitEventsArgs *>(cmd.parameters);
                printer_.PrintCmdWaitEventsArgs(os, *args);
            }
            break;

        case Command::Type::kCmdPipelineBarrier:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdPipelineBarrierArgs *>(cmd.parameters);
                printer_.PrintCmdPipelineBarrierArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBeginQuery:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBeginQueryArgs *>(cmd.parameters);
                printer_.PrintCmdBeginQueryArgs(os, *args);
            }
            break;

        case Command::Type::kCmdEndQuery:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdEndQueryArgs *>(cmd.parameters);
                printer_.PrintCmdEndQueryArgs(os, *args);
            }
            break;

        case Command::Type::kCmdResetQueryPool:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdResetQueryPoolArgs *>(cmd.parameters);
                printer_.PrintCmdResetQueryPoolArgs(os, *args);
            }
            break;

        case Command::Type::kCmdWriteTimestamp:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdWriteTimestampArgs *>(cmd.parameters);
                printer_.PrintCmdWriteTimestampArgs(os, *args);
            }
            break;

        case Command::Type::kCmdCopyQueryPoolResults:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdCopyQueryPoolResultsArgs *>(cmd.parameters);
                printer_.PrintCmdCopyQueryPoolResultsArgs(os, *args);
            }
            break;

        case Command::Type::kCmdPushConstants:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdPushConstantsArgs *>(cmd.parameters);
                printer_.PrintCmdPushConstantsArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBeginRenderPass:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBeginRenderPassArgs *>(cmd.parameters);
                printer_.PrintCmdBeginRenderPassArgs(os, *args);
            }
            break;

        case Command::Type::kCmdNextSubpass:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdNextSubpassArgs *>(cmd.parameters);
                printer_.PrintCmdNextSubpassArgs(os, *args);
            }
            break;

        case Command::Type::kCmdEndRenderPass:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdEndRenderPassArgs *>(cmd.parameters);
                printer_.PrintCmdEndRenderPassArgs(os, *args);
            }
            break;

        case Command::Type::kCmdExecuteCommands:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdExecuteCommandsArgs *>(cmd.parameters);
                printer_.PrintCmdExecuteCommandsArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetDeviceMask:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetDeviceMaskArgs *>(cmd.parameters);
                printer_.PrintCmdSetDeviceMaskArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDispatchBase:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDispatchBaseArgs *>(cmd.parameters);
                printer_.PrintCmdDispatchBaseArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDrawIndirectCount:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDrawIndirectCountArgs *>(cmd.parameters);
                printer_.PrintCmdDrawIndirectCountArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDrawIndexedIndirectCount:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDrawIndexedIndirectCountArgs *>(cmd.parameters);
                printer_.PrintCmdDrawIndexedIndirectCountArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBeginRenderPass2:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBeginRenderPass2Args *>(cmd.parameters);
                printer_.PrintCmdBeginRenderPass2Args(os, *args);
            }
            break;

        case Command::Type::kCmdNextSubpass2:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdNextSubpass2Args *>(cmd.parameters);
                printer_.PrintCmdNextSubpass2Args(os, *args);
            }
            break;

        case Command::Type::kCmdEndRenderPass2:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdEndRenderPass2Args *>(cmd.parameters);
                printer_.PrintCmdEndRenderPass2Args(os, *args);
            }
            break;

        case Command::Type::kCmdSetEvent2:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetEvent2Args *>(cmd.parameters);
                printer_.PrintCmdSetEvent2Args(os, *args);
            }
            break;

        case Command::Type::kCmdResetEvent2:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdResetEvent2Args *>(cmd.parameters);
                printer_.PrintCmdResetEvent2Args(os, *args);
            }
            break;

        case Command::Type::kCmdWaitEvents2:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdWaitEvents2Args *>(cmd.parameters);
                printer_.PrintCmdWaitEvents2Args(os, *args);
            }
            break;

        case Command::Type::kCmdPipelineBarrier2:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdPipelineBarrier2Args *>(cmd.parameters);
                printer_.PrintCmdPipelineBarrier2Args(os, *args);
            }
            break;

        case Command::Type::kCmdWriteTimestamp2:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdWriteTimestamp2Args *>(cmd.parameters);
                printer_.PrintCmdWriteTimestamp2Args(os, *args);
            }
            break;

        case Command::Type::kCmdCopyBuffer2:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdCopyBuffer2Args *>(cmd.parameters);
                printer_.PrintCmdCopyBuffer2Args(os, *args);
            }
            break;

        case Command::Type::kCmdCopyImage2:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdCopyImage2Args *>(cmd.parameters);
                printer_.PrintCmdCopyImage2Args(os, *args);
            }
            break;

        case Command::Type::kCmdCopyBufferToImage2:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdCopyBufferToImage2Args *>(cmd.parameters);
                printer_.PrintCmdCopyBufferToImage2Args(os, *args);
            }
            break;

        case Command::Type::kCmdCopyImageToBuffer2:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdCopyImageToBuffer2Args *>(cmd.parameters);
                printer_.PrintCmdCopyImageToBuffer2Args(os, *args);
            }
            break;

        case Command::Type::kCmdBlitImage2:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBlitImage2Args *>(cmd.parameters);
                printer_.PrintCmdBlitImage2Args(os, *args);
            }
            break;

        case Command::Type::kCmdResolveImage2:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdResolveImage2Args *>(cmd.parameters);
                printer_.PrintCmdResolveImage2Args(os, *args);
            }
            break;

        case Command::Type::kCmdBeginRendering:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBeginRenderingArgs *>(cmd.parameters);
                printer_.PrintCmdBeginRenderingArgs(os, *args);
            }
            break;

        case Command::Type::kCmdEndRendering:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdEndRenderingArgs *>(cmd.parameters);
                printer_.PrintCmdEndRenderingArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetCullMode:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetCullModeArgs *>(cmd.parameters);
                printer_.PrintCmdSetCullModeArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetFrontFace:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetFrontFaceArgs *>(cmd.parameters);
                printer_.PrintCmdSetFrontFaceArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetPrimitiveTopology:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetPrimitiveTopologyArgs *>(cmd.parameters);
                printer_.PrintCmdSetPrimitiveTopologyArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetViewportWithCount:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetViewportWithCountArgs *>(cmd.parameters);
                printer_.PrintCmdSetViewportWithCountArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetScissorWithCount:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetScissorWithCountArgs *>(cmd.parameters);
                printer_.PrintCmdSetScissorWithCountArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBindVertexBuffers2:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBindVertexBuffers2Args *>(cmd.parameters);
                printer_.PrintCmdBindVertexBuffers2Args(os, *args);
            }
            break;

        case Command::Type::kCmdSetDepthTestEnable:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetDepthTestEnableArgs *>(cmd.parameters);
                printer_.PrintCmdSetDepthTestEnableArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetDepthWriteEnable:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetDepthWriteEnableArgs *>(cmd.parameters);
                printer_.PrintCmdSetDepthWriteEnableArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetDepthCompareOp:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetDepthCompareOpArgs *>(cmd.parameters);
                printer_.PrintCmdSetDepthCompareOpArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetDepthBoundsTestEnable:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetDepthBoundsTestEnableArgs *>(cmd.parameters);
                printer_.PrintCmdSetDepthBoundsTestEnableArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetStencilTestEnable:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetStencilTestEnableArgs *>(cmd.parameters);
                printer_.PrintCmdSetStencilTestEnableArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetStencilOp:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetStencilOpArgs *>(cmd.parameters);
                printer_.PrintCmdSetStencilOpArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetRasterizerDiscardEnable:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetRasterizerDiscardEnableArgs *>(cmd.parameters);
                printer_.PrintCmdSetRasterizerDiscardEnableArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetDepthBiasEnable:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetDepthBiasEnableArgs *>(cmd.parameters);
                printer_.PrintCmdSetDepthBiasEnableArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetPrimitiveRestartEnable:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetPrimitiveRestartEnableArgs *>(cmd.parameters);
                printer_.PrintCmdSetPrimitiveRestartEnableArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBeginVideoCodingKHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBeginVideoCodingKHRArgs *>(cmd.parameters);
                printer_.PrintCmdBeginVideoCodingKHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdEndVideoCodingKHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdEndVideoCodingKHRArgs *>(cmd.parameters);
                printer_.PrintCmdEndVideoCodingKHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdControlVideoCodingKHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdControlVideoCodingKHRArgs *>(cmd.parameters);
                printer_.PrintCmdControlVideoCodingKHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDecodeVideoKHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDecodeVideoKHRArgs *>(cmd.parameters);
                printer_.PrintCmdDecodeVideoKHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBeginRenderingKHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBeginRenderingKHRArgs *>(cmd.parameters);
                printer_.PrintCmdBeginRenderingKHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdEndRenderingKHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdEndRenderingKHRArgs *>(cmd.parameters);
                printer_.PrintCmdEndRenderingKHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetDeviceMaskKHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetDeviceMaskKHRArgs *>(cmd.parameters);
                printer_.PrintCmdSetDeviceMaskKHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDispatchBaseKHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDispatchBaseKHRArgs *>(cmd.parameters);
                printer_.PrintCmdDispatchBaseKHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdPushDescriptorSetKHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdPushDescriptorSetKHRArgs *>(cmd.parameters);
                printer_.PrintCmdPushDescriptorSetKHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdPushDescriptorSetWithTemplateKHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdPushDescriptorSetWithTemplateKHRArgs *>(cmd.parameters);
                printer_.PrintCmdPushDescriptorSetWithTemplateKHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBeginRenderPass2KHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBeginRenderPass2KHRArgs *>(cmd.parameters);
                printer_.PrintCmdBeginRenderPass2KHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdNextSubpass2KHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdNextSubpass2KHRArgs *>(cmd.parameters);
                printer_.PrintCmdNextSubpass2KHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdEndRenderPass2KHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdEndRenderPass2KHRArgs *>(cmd.parameters);
                printer_.PrintCmdEndRenderPass2KHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDrawIndirectCountKHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDrawIndirectCountKHRArgs *>(cmd.parameters);
                printer_.PrintCmdDrawIndirectCountKHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDrawIndexedIndirectCountKHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDrawIndexedIndirectCountKHRArgs *>(cmd.parameters);
                printer_.PrintCmdDrawIndexedIndirectCountKHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetFragmentShadingRateKHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetFragmentShadingRateKHRArgs *>(cmd.parameters);
                printer_.PrintCmdSetFragmentShadingRateKHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetRenderingAttachmentLocationsKHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetRenderingAttachmentLocationsKHRArgs *>(cmd.parameters);
                printer_.PrintCmdSetRenderingAttachmentLocationsKHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetRenderingInputAttachmentIndicesKHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetRenderingInputAttachmentIndicesKHRArgs *>(cmd.parameters);
                printer_.PrintCmdSetRenderingInputAttachmentIndicesKHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdEncodeVideoKHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdEncodeVideoKHRArgs *>(cmd.parameters);
                printer_.PrintCmdEncodeVideoKHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetEvent2KHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetEvent2KHRArgs *>(cmd.parameters);
                printer_.PrintCmdSetEvent2KHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdResetEvent2KHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdResetEvent2KHRArgs *>(cmd.parameters);
                printer_.PrintCmdResetEvent2KHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdWaitEvents2KHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdWaitEvents2KHRArgs *>(cmd.parameters);
                printer_.PrintCmdWaitEvents2KHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdPipelineBarrier2KHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdPipelineBarrier2KHRArgs *>(cmd.parameters);
                printer_.PrintCmdPipelineBarrier2KHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdWriteTimestamp2KHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdWriteTimestamp2KHRArgs *>(cmd.parameters);
                printer_.PrintCmdWriteTimestamp2KHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdWriteBufferMarker2AMD:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdWriteBufferMarker2AMDArgs *>(cmd.parameters);
                printer_.PrintCmdWriteBufferMarker2AMDArgs(os, *args);
            }
            break;

        case Command::Type::kCmdCopyBuffer2KHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdCopyBuffer2KHRArgs *>(cmd.parameters);
                printer_.PrintCmdCopyBuffer2KHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdCopyImage2KHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdCopyImage2KHRArgs *>(cmd.parameters);
                printer_.PrintCmdCopyImage2KHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdCopyBufferToImage2KHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdCopyBufferToImage2KHRArgs *>(cmd.parameters);
                printer_.PrintCmdCopyBufferToImage2KHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdCopyImageToBuffer2KHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdCopyImageToBuffer2KHRArgs *>(cmd.parameters);
                printer_.PrintCmdCopyImageToBuffer2KHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBlitImage2KHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBlitImage2KHRArgs *>(cmd.parameters);
                printer_.PrintCmdBlitImage2KHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdResolveImage2KHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdResolveImage2KHRArgs *>(cmd.parameters);
                printer_.PrintCmdResolveImage2KHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdTraceRaysIndirect2KHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdTraceRaysIndirect2KHRArgs *>(cmd.parameters);
                printer_.PrintCmdTraceRaysIndirect2KHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBindIndexBuffer2KHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBindIndexBuffer2KHRArgs *>(cmd.parameters);
                printer_.PrintCmdBindIndexBuffer2KHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetLineStippleKHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetLineStippleKHRArgs *>(cmd.parameters);
                printer_.PrintCmdSetLineStippleKHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBindDescriptorSets2KHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBindDescriptorSets2KHRArgs *>(cmd.parameters);
                printer_.PrintCmdBindDescriptorSets2KHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdPushConstants2KHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdPushConstants2KHRArgs *>(cmd.parameters);
                printer_.PrintCmdPushConstants2KHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdPushDescriptorSet2KHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdPushDescriptorSet2KHRArgs *>(cmd.parameters);
                printer_.PrintCmdPushDescriptorSet2KHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdPushDescriptorSetWithTemplate2KHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdPushDescriptorSetWithTemplate2KHRArgs *>(cmd.parameters);
                printer_.PrintCmdPushDescriptorSetWithTemplate2KHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetDescriptorBufferOffsets2EXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetDescriptorBufferOffsets2EXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetDescriptorBufferOffsets2EXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBindDescriptorBufferEmbeddedSamplers2EXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBindDescriptorBufferEmbeddedSamplers2EXTArgs *>(cmd.parameters);
                printer_.PrintCmdBindDescriptorBufferEmbeddedSamplers2EXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDebugMarkerBeginEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDebugMarkerBeginEXTArgs *>(cmd.parameters);
                printer_.PrintCmdDebugMarkerBeginEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDebugMarkerEndEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDebugMarkerEndEXTArgs *>(cmd.parameters);
                printer_.PrintCmdDebugMarkerEndEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDebugMarkerInsertEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDebugMarkerInsertEXTArgs *>(cmd.parameters);
                printer_.PrintCmdDebugMarkerInsertEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBindTransformFeedbackBuffersEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBindTransformFeedbackBuffersEXTArgs *>(cmd.parameters);
                printer_.PrintCmdBindTransformFeedbackBuffersEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBeginTransformFeedbackEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBeginTransformFeedbackEXTArgs *>(cmd.parameters);
                printer_.PrintCmdBeginTransformFeedbackEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdEndTransformFeedbackEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdEndTransformFeedbackEXTArgs *>(cmd.parameters);
                printer_.PrintCmdEndTransformFeedbackEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBeginQueryIndexedEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBeginQueryIndexedEXTArgs *>(cmd.parameters);
                printer_.PrintCmdBeginQueryIndexedEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdEndQueryIndexedEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdEndQueryIndexedEXTArgs *>(cmd.parameters);
                printer_.PrintCmdEndQueryIndexedEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDrawIndirectByteCountEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDrawIndirectByteCountEXTArgs *>(cmd.parameters);
                printer_.PrintCmdDrawIndirectByteCountEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdCuLaunchKernelNVX:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdCuLaunchKernelNVXArgs *>(cmd.parameters);
                printer_.PrintCmdCuLaunchKernelNVXArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDrawIndirectCountAMD:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDrawIndirectCountAMDArgs *>(cmd.parameters);
                printer_.PrintCmdDrawIndirectCountAMDArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDrawIndexedIndirectCountAMD:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDrawIndexedIndirectCountAMDArgs *>(cmd.parameters);
                printer_.PrintCmdDrawIndexedIndirectCountAMDArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBeginConditionalRenderingEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBeginConditionalRenderingEXTArgs *>(cmd.parameters);
                printer_.PrintCmdBeginConditionalRenderingEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdEndConditionalRenderingEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdEndConditionalRenderingEXTArgs *>(cmd.parameters);
                printer_.PrintCmdEndConditionalRenderingEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetViewportWScalingNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetViewportWScalingNVArgs *>(cmd.parameters);
                printer_.PrintCmdSetViewportWScalingNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetDiscardRectangleEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetDiscardRectangleEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetDiscardRectangleEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetDiscardRectangleEnableEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetDiscardRectangleEnableEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetDiscardRectangleEnableEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetDiscardRectangleModeEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetDiscardRectangleModeEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetDiscardRectangleModeEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBeginDebugUtilsLabelEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBeginDebugUtilsLabelEXTArgs *>(cmd.parameters);
                printer_.PrintCmdBeginDebugUtilsLabelEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdEndDebugUtilsLabelEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdEndDebugUtilsLabelEXTArgs *>(cmd.parameters);
                printer_.PrintCmdEndDebugUtilsLabelEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdInsertDebugUtilsLabelEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdInsertDebugUtilsLabelEXTArgs *>(cmd.parameters);
                printer_.PrintCmdInsertDebugUtilsLabelEXTArgs(os, *args);
            }
            break;

#ifdef VK_ENABLE_BETA_EXTENSIONS
        case Command::Type::kCmdInitializeGraphScratchMemoryAMDX:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdInitializeGraphScratchMemoryAMDXArgs *>(cmd.parameters);
                printer_.PrintCmdInitializeGraphScratchMemoryAMDXArgs(os, *args);
            }
            break;
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
        case Command::Type::kCmdDispatchGraphAMDX:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDispatchGraphAMDXArgs *>(cmd.parameters);
                printer_.PrintCmdDispatchGraphAMDXArgs(os, *args);
            }
            break;
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
        case Command::Type::kCmdDispatchGraphIndirectAMDX:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDispatchGraphIndirectAMDXArgs *>(cmd.parameters);
                printer_.PrintCmdDispatchGraphIndirectAMDXArgs(os, *args);
            }
            break;
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
        case Command::Type::kCmdDispatchGraphIndirectCountAMDX:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDispatchGraphIndirectCountAMDXArgs *>(cmd.parameters);
                printer_.PrintCmdDispatchGraphIndirectCountAMDXArgs(os, *args);
            }
            break;
#endif  // VK_ENABLE_BETA_EXTENSIONS

        case Command::Type::kCmdSetSampleLocationsEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetSampleLocationsEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetSampleLocationsEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBindShadingRateImageNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBindShadingRateImageNVArgs *>(cmd.parameters);
                printer_.PrintCmdBindShadingRateImageNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetViewportShadingRatePaletteNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetViewportShadingRatePaletteNVArgs *>(cmd.parameters);
                printer_.PrintCmdSetViewportShadingRatePaletteNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetCoarseSampleOrderNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetCoarseSampleOrderNVArgs *>(cmd.parameters);
                printer_.PrintCmdSetCoarseSampleOrderNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBuildAccelerationStructureNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBuildAccelerationStructureNVArgs *>(cmd.parameters);
                printer_.PrintCmdBuildAccelerationStructureNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdCopyAccelerationStructureNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdCopyAccelerationStructureNVArgs *>(cmd.parameters);
                printer_.PrintCmdCopyAccelerationStructureNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdTraceRaysNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdTraceRaysNVArgs *>(cmd.parameters);
                printer_.PrintCmdTraceRaysNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdWriteAccelerationStructuresPropertiesNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdWriteAccelerationStructuresPropertiesNVArgs *>(cmd.parameters);
                printer_.PrintCmdWriteAccelerationStructuresPropertiesNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdWriteBufferMarkerAMD:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdWriteBufferMarkerAMDArgs *>(cmd.parameters);
                printer_.PrintCmdWriteBufferMarkerAMDArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDrawMeshTasksNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDrawMeshTasksNVArgs *>(cmd.parameters);
                printer_.PrintCmdDrawMeshTasksNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDrawMeshTasksIndirectNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDrawMeshTasksIndirectNVArgs *>(cmd.parameters);
                printer_.PrintCmdDrawMeshTasksIndirectNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDrawMeshTasksIndirectCountNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDrawMeshTasksIndirectCountNVArgs *>(cmd.parameters);
                printer_.PrintCmdDrawMeshTasksIndirectCountNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetExclusiveScissorEnableNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetExclusiveScissorEnableNVArgs *>(cmd.parameters);
                printer_.PrintCmdSetExclusiveScissorEnableNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetExclusiveScissorNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetExclusiveScissorNVArgs *>(cmd.parameters);
                printer_.PrintCmdSetExclusiveScissorNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetCheckpointNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetCheckpointNVArgs *>(cmd.parameters);
                printer_.PrintCmdSetCheckpointNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetPerformanceMarkerINTEL:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetPerformanceMarkerINTELArgs *>(cmd.parameters);
                printer_.PrintCmdSetPerformanceMarkerINTELArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetPerformanceStreamMarkerINTEL:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetPerformanceStreamMarkerINTELArgs *>(cmd.parameters);
                printer_.PrintCmdSetPerformanceStreamMarkerINTELArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetPerformanceOverrideINTEL:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetPerformanceOverrideINTELArgs *>(cmd.parameters);
                printer_.PrintCmdSetPerformanceOverrideINTELArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetLineStippleEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetLineStippleEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetLineStippleEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetCullModeEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetCullModeEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetCullModeEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetFrontFaceEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetFrontFaceEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetFrontFaceEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetPrimitiveTopologyEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetPrimitiveTopologyEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetPrimitiveTopologyEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetViewportWithCountEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetViewportWithCountEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetViewportWithCountEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetScissorWithCountEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetScissorWithCountEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetScissorWithCountEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBindVertexBuffers2EXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBindVertexBuffers2EXTArgs *>(cmd.parameters);
                printer_.PrintCmdBindVertexBuffers2EXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetDepthTestEnableEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetDepthTestEnableEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetDepthTestEnableEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetDepthWriteEnableEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetDepthWriteEnableEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetDepthWriteEnableEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetDepthCompareOpEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetDepthCompareOpEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetDepthCompareOpEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetDepthBoundsTestEnableEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetDepthBoundsTestEnableEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetDepthBoundsTestEnableEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetStencilTestEnableEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetStencilTestEnableEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetStencilTestEnableEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetStencilOpEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetStencilOpEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetStencilOpEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdPreprocessGeneratedCommandsNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdPreprocessGeneratedCommandsNVArgs *>(cmd.parameters);
                printer_.PrintCmdPreprocessGeneratedCommandsNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdExecuteGeneratedCommandsNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdExecuteGeneratedCommandsNVArgs *>(cmd.parameters);
                printer_.PrintCmdExecuteGeneratedCommandsNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBindPipelineShaderGroupNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBindPipelineShaderGroupNVArgs *>(cmd.parameters);
                printer_.PrintCmdBindPipelineShaderGroupNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetDepthBias2EXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetDepthBias2EXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetDepthBias2EXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdCudaLaunchKernelNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdCudaLaunchKernelNVArgs *>(cmd.parameters);
                printer_.PrintCmdCudaLaunchKernelNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBindDescriptorBuffersEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBindDescriptorBuffersEXTArgs *>(cmd.parameters);
                printer_.PrintCmdBindDescriptorBuffersEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetDescriptorBufferOffsetsEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetDescriptorBufferOffsetsEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetDescriptorBufferOffsetsEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBindDescriptorBufferEmbeddedSamplersEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBindDescriptorBufferEmbeddedSamplersEXTArgs *>(cmd.parameters);
                printer_.PrintCmdBindDescriptorBufferEmbeddedSamplersEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetFragmentShadingRateEnumNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetFragmentShadingRateEnumNVArgs *>(cmd.parameters);
                printer_.PrintCmdSetFragmentShadingRateEnumNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetVertexInputEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetVertexInputEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetVertexInputEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSubpassShadingHUAWEI:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSubpassShadingHUAWEIArgs *>(cmd.parameters);
                printer_.PrintCmdSubpassShadingHUAWEIArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBindInvocationMaskHUAWEI:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBindInvocationMaskHUAWEIArgs *>(cmd.parameters);
                printer_.PrintCmdBindInvocationMaskHUAWEIArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetPatchControlPointsEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetPatchControlPointsEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetPatchControlPointsEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetRasterizerDiscardEnableEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetRasterizerDiscardEnableEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetRasterizerDiscardEnableEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetDepthBiasEnableEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetDepthBiasEnableEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetDepthBiasEnableEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetLogicOpEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetLogicOpEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetLogicOpEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetPrimitiveRestartEnableEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetPrimitiveRestartEnableEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetPrimitiveRestartEnableEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetColorWriteEnableEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetColorWriteEnableEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetColorWriteEnableEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDrawMultiEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDrawMultiEXTArgs *>(cmd.parameters);
                printer_.PrintCmdDrawMultiEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDrawMultiIndexedEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDrawMultiIndexedEXTArgs *>(cmd.parameters);
                printer_.PrintCmdDrawMultiIndexedEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBuildMicromapsEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBuildMicromapsEXTArgs *>(cmd.parameters);
                printer_.PrintCmdBuildMicromapsEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdCopyMicromapEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdCopyMicromapEXTArgs *>(cmd.parameters);
                printer_.PrintCmdCopyMicromapEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdCopyMicromapToMemoryEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdCopyMicromapToMemoryEXTArgs *>(cmd.parameters);
                printer_.PrintCmdCopyMicromapToMemoryEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdCopyMemoryToMicromapEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdCopyMemoryToMicromapEXTArgs *>(cmd.parameters);
                printer_.PrintCmdCopyMemoryToMicromapEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdWriteMicromapsPropertiesEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdWriteMicromapsPropertiesEXTArgs *>(cmd.parameters);
                printer_.PrintCmdWriteMicromapsPropertiesEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDrawClusterHUAWEI:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDrawClusterHUAWEIArgs *>(cmd.parameters);
                printer_.PrintCmdDrawClusterHUAWEIArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDrawClusterIndirectHUAWEI:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDrawClusterIndirectHUAWEIArgs *>(cmd.parameters);
                printer_.PrintCmdDrawClusterIndirectHUAWEIArgs(os, *args);
            }
            break;

        case Command::Type::kCmdCopyMemoryIndirectNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdCopyMemoryIndirectNVArgs *>(cmd.parameters);
                printer_.PrintCmdCopyMemoryIndirectNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdCopyMemoryToImageIndirectNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdCopyMemoryToImageIndirectNVArgs *>(cmd.parameters);
                printer_.PrintCmdCopyMemoryToImageIndirectNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDecompressMemoryNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDecompressMemoryNVArgs *>(cmd.parameters);
                printer_.PrintCmdDecompressMemoryNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDecompressMemoryIndirectCountNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDecompressMemoryIndirectCountNVArgs *>(cmd.parameters);
                printer_.PrintCmdDecompressMemoryIndirectCountNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdUpdatePipelineIndirectBufferNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdUpdatePipelineIndirectBufferNVArgs *>(cmd.parameters);
                printer_.PrintCmdUpdatePipelineIndirectBufferNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetDepthClampEnableEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetDepthClampEnableEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetDepthClampEnableEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetPolygonModeEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetPolygonModeEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetPolygonModeEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetRasterizationSamplesEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetRasterizationSamplesEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetRasterizationSamplesEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetSampleMaskEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetSampleMaskEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetSampleMaskEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetAlphaToCoverageEnableEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetAlphaToCoverageEnableEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetAlphaToCoverageEnableEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetAlphaToOneEnableEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetAlphaToOneEnableEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetAlphaToOneEnableEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetLogicOpEnableEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetLogicOpEnableEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetLogicOpEnableEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetColorBlendEnableEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetColorBlendEnableEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetColorBlendEnableEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetColorBlendEquationEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetColorBlendEquationEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetColorBlendEquationEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetColorWriteMaskEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetColorWriteMaskEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetColorWriteMaskEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetTessellationDomainOriginEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetTessellationDomainOriginEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetTessellationDomainOriginEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetRasterizationStreamEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetRasterizationStreamEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetRasterizationStreamEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetConservativeRasterizationModeEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetConservativeRasterizationModeEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetConservativeRasterizationModeEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetExtraPrimitiveOverestimationSizeEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetExtraPrimitiveOverestimationSizeEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetExtraPrimitiveOverestimationSizeEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetDepthClipEnableEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetDepthClipEnableEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetDepthClipEnableEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetSampleLocationsEnableEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetSampleLocationsEnableEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetSampleLocationsEnableEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetColorBlendAdvancedEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetColorBlendAdvancedEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetColorBlendAdvancedEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetProvokingVertexModeEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetProvokingVertexModeEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetProvokingVertexModeEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetLineRasterizationModeEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetLineRasterizationModeEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetLineRasterizationModeEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetLineStippleEnableEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetLineStippleEnableEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetLineStippleEnableEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetDepthClipNegativeOneToOneEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetDepthClipNegativeOneToOneEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetDepthClipNegativeOneToOneEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetViewportWScalingEnableNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetViewportWScalingEnableNVArgs *>(cmd.parameters);
                printer_.PrintCmdSetViewportWScalingEnableNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetViewportSwizzleNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetViewportSwizzleNVArgs *>(cmd.parameters);
                printer_.PrintCmdSetViewportSwizzleNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetCoverageToColorEnableNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetCoverageToColorEnableNVArgs *>(cmd.parameters);
                printer_.PrintCmdSetCoverageToColorEnableNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetCoverageToColorLocationNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetCoverageToColorLocationNVArgs *>(cmd.parameters);
                printer_.PrintCmdSetCoverageToColorLocationNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetCoverageModulationModeNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetCoverageModulationModeNVArgs *>(cmd.parameters);
                printer_.PrintCmdSetCoverageModulationModeNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetCoverageModulationTableEnableNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetCoverageModulationTableEnableNVArgs *>(cmd.parameters);
                printer_.PrintCmdSetCoverageModulationTableEnableNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetCoverageModulationTableNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetCoverageModulationTableNVArgs *>(cmd.parameters);
                printer_.PrintCmdSetCoverageModulationTableNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetShadingRateImageEnableNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetShadingRateImageEnableNVArgs *>(cmd.parameters);
                printer_.PrintCmdSetShadingRateImageEnableNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetRepresentativeFragmentTestEnableNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetRepresentativeFragmentTestEnableNVArgs *>(cmd.parameters);
                printer_.PrintCmdSetRepresentativeFragmentTestEnableNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetCoverageReductionModeNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetCoverageReductionModeNVArgs *>(cmd.parameters);
                printer_.PrintCmdSetCoverageReductionModeNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdOpticalFlowExecuteNV:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdOpticalFlowExecuteNVArgs *>(cmd.parameters);
                printer_.PrintCmdOpticalFlowExecuteNVArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBindShadersEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBindShadersEXTArgs *>(cmd.parameters);
                printer_.PrintCmdBindShadersEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetAttachmentFeedbackLoopEnableEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetAttachmentFeedbackLoopEnableEXTArgs *>(cmd.parameters);
                printer_.PrintCmdSetAttachmentFeedbackLoopEnableEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBuildAccelerationStructuresKHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBuildAccelerationStructuresKHRArgs *>(cmd.parameters);
                printer_.PrintCmdBuildAccelerationStructuresKHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdBuildAccelerationStructuresIndirectKHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdBuildAccelerationStructuresIndirectKHRArgs *>(cmd.parameters);
                printer_.PrintCmdBuildAccelerationStructuresIndirectKHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdCopyAccelerationStructureKHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdCopyAccelerationStructureKHRArgs *>(cmd.parameters);
                printer_.PrintCmdCopyAccelerationStructureKHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdCopyAccelerationStructureToMemoryKHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdCopyAccelerationStructureToMemoryKHRArgs *>(cmd.parameters);
                printer_.PrintCmdCopyAccelerationStructureToMemoryKHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdCopyMemoryToAccelerationStructureKHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdCopyMemoryToAccelerationStructureKHRArgs *>(cmd.parameters);
                printer_.PrintCmdCopyMemoryToAccelerationStructureKHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdWriteAccelerationStructuresPropertiesKHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdWriteAccelerationStructuresPropertiesKHRArgs *>(cmd.parameters);
                printer_.PrintCmdWriteAccelerationStructuresPropertiesKHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdTraceRaysKHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdTraceRaysKHRArgs *>(cmd.parameters);
                printer_.PrintCmdTraceRaysKHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdTraceRaysIndirectKHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdTraceRaysIndirectKHRArgs *>(cmd.parameters);
                printer_.PrintCmdTraceRaysIndirectKHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdSetRayTracingPipelineStackSizeKHR:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdSetRayTracingPipelineStackSizeKHRArgs *>(cmd.parameters);
                printer_.PrintCmdSetRayTracingPipelineStackSizeKHRArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDrawMeshTasksEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDrawMeshTasksEXTArgs *>(cmd.parameters);
                printer_.PrintCmdDrawMeshTasksEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDrawMeshTasksIndirectEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDrawMeshTasksIndirectEXTArgs *>(cmd.parameters);
                printer_.PrintCmdDrawMeshTasksIndirectEXTArgs(os, *args);
            }
            break;

        case Command::Type::kCmdDrawMeshTasksIndirectCountEXT:
            if (cmd.parameters) {
                auto args = reinterpret_cast<CmdDrawMeshTasksIndirectCountEXTArgs *>(cmd.parameters);
                printer_.PrintCmdDrawMeshTasksIndirectCountEXTArgs(os, *args);
            }
            break;

    };  // switch (cmd.type)
}  // CommandTracker::PrintCommandParameters

void CommandTracker::TrackPreBeginCommandBuffer(VkCommandBuffer commandBuffer,
                                                const VkCommandBufferBeginInfo *pBeginInfo) {
    Command cmd{};
    cmd.type = Command::Type::kBeginCommandBuffer;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordBeginCommandBuffer(commandBuffer, pBeginInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreEndCommandBuffer(VkCommandBuffer commandBuffer) {
    Command cmd{};
    cmd.type = Command::Type::kEndCommandBuffer;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordEndCommandBuffer(commandBuffer);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) {
    Command cmd{};
    cmd.type = Command::Type::kResetCommandBuffer;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordResetCommandBuffer(commandBuffer, flags);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                             VkPipeline pipeline) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindPipeline;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                            uint32_t viewportCount, const VkViewport *pViewports) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetViewport;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount,
                                           const VkRect2D *pScissors) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetScissor;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetLineWidth;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetLineWidth(commandBuffer, lineWidth);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor,
                                             float depthBiasClamp, float depthBiasSlopeFactor) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthBias;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters =
        recorder_.RecordCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetBlendConstants;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetBlendConstants(commandBuffer, blendConstants);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds,
                                               float maxDepthBounds) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthBounds;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                                      uint32_t compareMask) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetStencilCompareMask;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                                    uint32_t writeMask) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetStencilWriteMask;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                                    uint32_t reference) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetStencilReference;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetStencilReference(commandBuffer, faceMask, reference);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                                   VkPipelineLayout layout, uint32_t firstSet,
                                                   uint32_t descriptorSetCount, const VkDescriptorSet *pDescriptorSets,
                                                   uint32_t dynamicOffsetCount, const uint32_t *pDynamicOffsets) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindDescriptorSets;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters =
        recorder_.RecordCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount,
                                              pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                VkIndexType indexType) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindIndexBuffer;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                  uint32_t bindingCount, const VkBuffer *pBuffers,
                                                  const VkDeviceSize *pOffsets) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindVertexBuffers;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters =
        recorder_.RecordCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount,
                                     uint32_t firstVertex, uint32_t firstInstance) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDraw;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount,
                                            uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawIndexed;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset,
                                                    firstInstance);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                             uint32_t drawCount, uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawIndirect;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                    uint32_t drawCount, uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawIndexedIndirect;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                         uint32_t groupCountZ) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDispatch;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDispatchIndirect;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDispatchIndirect(commandBuffer, buffer, offset);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer,
                                           uint32_t regionCount, const VkBufferCopy *pRegions) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyBuffer;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                          VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                          const VkImageCopy *pRegions) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyImage;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout,
                                                  regionCount, pRegions);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout,
                                          VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount,
                                          const VkImageBlit *pRegions, VkFilter filter) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBlitImage;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout,
                                                  regionCount, pRegions, filter);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage,
                                                  VkImageLayout dstImageLayout, uint32_t regionCount,
                                                  const VkBufferImageCopy *pRegions) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyBufferToImage;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters =
        recorder_.RecordCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage,
                                                  VkImageLayout srcImageLayout, VkBuffer dstBuffer,
                                                  uint32_t regionCount, const VkBufferImageCopy *pRegions) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyImageToBuffer;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters =
        recorder_.RecordCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                             VkDeviceSize dataSize, const void *pData) {
    Command cmd{};
    cmd.type = Command::Type::kCmdUpdateBuffer;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset,
                                           VkDeviceSize size, uint32_t data) {
    Command cmd{};
    cmd.type = Command::Type::kCmdFillBuffer;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout,
                                                const VkClearColorValue *pColor, uint32_t rangeCount,
                                                const VkImageSubresourceRange *pRanges) {
    Command cmd{};
    cmd.type = Command::Type::kCmdClearColorImage;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image,
                                                       VkImageLayout imageLayout,
                                                       const VkClearDepthStencilValue *pDepthStencil,
                                                       uint32_t rangeCount, const VkImageSubresourceRange *pRanges) {
    Command cmd{};
    cmd.type = Command::Type::kCmdClearDepthStencilImage;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil,
                                                               rangeCount, pRanges);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                                 const VkClearAttachment *pAttachments, uint32_t rectCount,
                                                 const VkClearRect *pRects) {
    Command cmd{};
    cmd.type = Command::Type::kCmdClearAttachments;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters =
        recorder_.RecordCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage,
                                             VkImageLayout srcImageLayout, VkImage dstImage,
                                             VkImageLayout dstImageLayout, uint32_t regionCount,
                                             const VkImageResolve *pRegions) {
    Command cmd{};
    cmd.type = Command::Type::kCmdResolveImage;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout,
                                                     regionCount, pRegions);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetEvent;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetEvent(commandBuffer, event, stageMask);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event,
                                           VkPipelineStageFlags stageMask) {
    Command cmd{};
    cmd.type = Command::Type::kCmdResetEvent;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdResetEvent(commandBuffer, event, stageMask);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent *pEvents,
                                           VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask,
                                           uint32_t memoryBarrierCount, const VkMemoryBarrier *pMemoryBarriers,
                                           uint32_t bufferMemoryBarrierCount,
                                           const VkBufferMemoryBarrier *pBufferMemoryBarriers,
                                           uint32_t imageMemoryBarrierCount,
                                           const VkImageMemoryBarrier *pImageMemoryBarriers) {
    Command cmd{};
    cmd.type = Command::Type::kCmdWaitEvents;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdWaitEvents(
        commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers,
        bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask,
                                                VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags,
                                                uint32_t memoryBarrierCount, const VkMemoryBarrier *pMemoryBarriers,
                                                uint32_t bufferMemoryBarrierCount,
                                                const VkBufferMemoryBarrier *pBufferMemoryBarriers,
                                                uint32_t imageMemoryBarrierCount,
                                                const VkImageMemoryBarrier *pImageMemoryBarriers) {
    Command cmd{};
    cmd.type = Command::Type::kCmdPipelineBarrier;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdPipelineBarrier(
        commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers,
        bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                           VkQueryControlFlags flags) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBeginQuery;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBeginQuery(commandBuffer, queryPool, query, flags);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) {
    Command cmd{};
    cmd.type = Command::Type::kCmdEndQuery;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdEndQuery(commandBuffer, queryPool, query);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool,
                                               uint32_t firstQuery, uint32_t queryCount) {
    Command cmd{};
    cmd.type = Command::Type::kCmdResetQueryPool;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                               VkQueryPool queryPool, uint32_t query) {
    Command cmd{};
    cmd.type = Command::Type::kCmdWriteTimestamp;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool,
                                                     uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer,
                                                     VkDeviceSize dstOffset, VkDeviceSize stride,
                                                     VkQueryResultFlags flags) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyQueryPoolResults;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount,
                                                             dstBuffer, dstOffset, stride, flags);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout,
                                              VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size,
                                              const void *pValues) {
    Command cmd{};
    cmd.type = Command::Type::kCmdPushConstants;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBeginRenderPass(VkCommandBuffer commandBuffer,
                                                const VkRenderPassBeginInfo *pRenderPassBegin,
                                                VkSubpassContents contents) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBeginRenderPass;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) {
    Command cmd{};
    cmd.type = Command::Type::kCmdNextSubpass;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdNextSubpass(commandBuffer, contents);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdEndRenderPass(VkCommandBuffer commandBuffer) {
    Command cmd{};
    cmd.type = Command::Type::kCmdEndRenderPass;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdEndRenderPass(commandBuffer);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount,
                                                const VkCommandBuffer *pCommandBuffers) {
    Command cmd{};
    cmd.type = Command::Type::kCmdExecuteCommands;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDeviceMask;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetDeviceMask(commandBuffer, deviceMask);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                             uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                             uint32_t groupCountZ) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDispatchBase;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX,
                                                     groupCountY, groupCountZ);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                  VkBuffer countBuffer, VkDeviceSize countBufferOffset,
                                                  uint32_t maxDrawCount, uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawIndirectCount;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                                          maxDrawCount, stride);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                         VkDeviceSize offset, VkBuffer countBuffer,
                                                         VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                         uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawIndexedIndirectCount;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer,
                                                                 countBufferOffset, maxDrawCount, stride);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBeginRenderPass2(VkCommandBuffer commandBuffer,
                                                 const VkRenderPassBeginInfo *pRenderPassBegin,
                                                 const VkSubpassBeginInfo *pSubpassBeginInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBeginRenderPass2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo *pSubpassBeginInfo,
                                             const VkSubpassEndInfo *pSubpassEndInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdNextSubpass2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo *pSubpassEndInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdEndRenderPass2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event,
                                          const VkDependencyInfo *pDependencyInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetEvent2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetEvent2(commandBuffer, event, pDependencyInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event,
                                            VkPipelineStageFlags2 stageMask) {
    Command cmd{};
    cmd.type = Command::Type::kCmdResetEvent2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdResetEvent2(commandBuffer, event, stageMask);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent *pEvents,
                                            const VkDependencyInfo *pDependencyInfos) {
    Command cmd{};
    cmd.type = Command::Type::kCmdWaitEvents2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdPipelineBarrier2(VkCommandBuffer commandBuffer,
                                                 const VkDependencyInfo *pDependencyInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdPipelineBarrier2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdPipelineBarrier2(commandBuffer, pDependencyInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                                VkQueryPool queryPool, uint32_t query) {
    Command cmd{};
    cmd.type = Command::Type::kCmdWriteTimestamp2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2 *pCopyBufferInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyBuffer2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2 *pCopyImageInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyImage2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdCopyImage2(commandBuffer, pCopyImageInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdCopyBufferToImage2(VkCommandBuffer commandBuffer,
                                                   const VkCopyBufferToImageInfo2 *pCopyBufferToImageInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyBufferToImage2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdCopyImageToBuffer2(VkCommandBuffer commandBuffer,
                                                   const VkCopyImageToBufferInfo2 *pCopyImageToBufferInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyImageToBuffer2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2 *pBlitImageInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBlitImage2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBlitImage2(commandBuffer, pBlitImageInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdResolveImage2(VkCommandBuffer commandBuffer,
                                              const VkResolveImageInfo2 *pResolveImageInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdResolveImage2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdResolveImage2(commandBuffer, pResolveImageInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo *pRenderingInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBeginRendering;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBeginRendering(commandBuffer, pRenderingInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdEndRendering(VkCommandBuffer commandBuffer) {
    Command cmd{};
    cmd.type = Command::Type::kCmdEndRendering;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdEndRendering(commandBuffer);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetCullMode;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetCullMode(commandBuffer, cullMode);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetFrontFace;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetFrontFace(commandBuffer, frontFace);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetPrimitiveTopology(VkCommandBuffer commandBuffer,
                                                     VkPrimitiveTopology primitiveTopology) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetPrimitiveTopology;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                                     const VkViewport *pViewports) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetViewportWithCount;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                                    const VkRect2D *pScissors) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetScissorWithCount;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                   uint32_t bindingCount, const VkBuffer *pBuffers,
                                                   const VkDeviceSize *pOffsets, const VkDeviceSize *pSizes,
                                                   const VkDeviceSize *pStrides) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindVertexBuffers2;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers,
                                                           pOffsets, pSizes, pStrides);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthTestEnable;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetDepthTestEnable(commandBuffer, depthTestEnable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthWriteEnable;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthCompareOp;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetDepthCompareOp(commandBuffer, depthCompareOp);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer,
                                                         VkBool32 depthBoundsTestEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthBoundsTestEnable;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetStencilTestEnable;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                             VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp,
                                             VkCompareOp compareOp) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetStencilOp;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer,
                                                           VkBool32 rasterizerDiscardEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetRasterizerDiscardEnable;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthBiasEnable;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer,
                                                          VkBool32 primitiveRestartEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetPrimitiveRestartEnable;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer,
                                                    const VkVideoBeginCodingInfoKHR *pBeginInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBeginVideoCodingKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdEndVideoCodingKHR(VkCommandBuffer commandBuffer,
                                                  const VkVideoEndCodingInfoKHR *pEndCodingInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdEndVideoCodingKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdControlVideoCodingKHR(VkCommandBuffer commandBuffer,
                                                      const VkVideoCodingControlInfoKHR *pCodingControlInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdControlVideoCodingKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR *pDecodeInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDecodeVideoKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDecodeVideoKHR(commandBuffer, pDecodeInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBeginRenderingKHR(VkCommandBuffer commandBuffer,
                                                  const VkRenderingInfo *pRenderingInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBeginRenderingKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBeginRenderingKHR(commandBuffer, pRenderingInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdEndRenderingKHR(VkCommandBuffer commandBuffer) {
    Command cmd{};
    cmd.type = Command::Type::kCmdEndRenderingKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdEndRenderingKHR(commandBuffer);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDeviceMaskKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetDeviceMaskKHR(commandBuffer, deviceMask);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                                uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                                uint32_t groupCountZ) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDispatchBaseKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX,
                                                        groupCountY, groupCountZ);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer,
                                                     VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout,
                                                     uint32_t set, uint32_t descriptorWriteCount,
                                                     const VkWriteDescriptorSet *pDescriptorWrites) {
    Command cmd{};
    cmd.type = Command::Type::kCmdPushDescriptorSetKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set,
                                                             descriptorWriteCount, pDescriptorWrites);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer,
                                                                 VkDescriptorUpdateTemplate descriptorUpdateTemplate,
                                                                 VkPipelineLayout layout, uint32_t set,
                                                                 const void *pData) {
    Command cmd{};
    cmd.type = Command::Type::kCmdPushDescriptorSetWithTemplateKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate,
                                                                         layout, set, pData);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer,
                                                    const VkRenderPassBeginInfo *pRenderPassBegin,
                                                    const VkSubpassBeginInfo *pSubpassBeginInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBeginRenderPass2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdNextSubpass2KHR(VkCommandBuffer commandBuffer,
                                                const VkSubpassBeginInfo *pSubpassBeginInfo,
                                                const VkSubpassEndInfo *pSubpassEndInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdNextSubpass2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdEndRenderPass2KHR(VkCommandBuffer commandBuffer,
                                                  const VkSubpassEndInfo *pSubpassEndInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdEndRenderPass2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                     VkDeviceSize offset, VkBuffer countBuffer,
                                                     VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                     uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawIndirectCountKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer,
                                                             countBufferOffset, maxDrawCount, stride);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                            VkDeviceSize offset, VkBuffer countBuffer,
                                                            VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                            uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawIndexedIndirectCountKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer,
                                                                    countBufferOffset, maxDrawCount, stride);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer,
                                                          const VkExtent2D *pFragmentSize,
                                                          const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetFragmentShadingRateKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetRenderingAttachmentLocationsKHR(
    VkCommandBuffer commandBuffer, const VkRenderingAttachmentLocationInfoKHR *pLocationInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetRenderingAttachmentLocationsKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetRenderingAttachmentLocationsKHR(commandBuffer, pLocationInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetRenderingInputAttachmentIndicesKHR(
    VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfoKHR *pLocationInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetRenderingInputAttachmentIndicesKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetRenderingInputAttachmentIndicesKHR(commandBuffer, pLocationInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR *pEncodeInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdEncodeVideoKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdEncodeVideoKHR(commandBuffer, pEncodeInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event,
                                             const VkDependencyInfo *pDependencyInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetEvent2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetEvent2KHR(commandBuffer, event, pDependencyInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event,
                                               VkPipelineStageFlags2 stageMask) {
    Command cmd{};
    cmd.type = Command::Type::kCmdResetEvent2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdResetEvent2KHR(commandBuffer, event, stageMask);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount,
                                               const VkEvent *pEvents, const VkDependencyInfo *pDependencyInfos) {
    Command cmd{};
    cmd.type = Command::Type::kCmdWaitEvents2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer,
                                                    const VkDependencyInfo *pDependencyInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdPipelineBarrier2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                                   VkQueryPool queryPool, uint32_t query) {
    Command cmd{};
    cmd.type = Command::Type::kCmdWriteTimestamp2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage,
                                                      VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {
    Command cmd{};
    cmd.type = Command::Type::kCmdWriteBufferMarker2AMD;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer,
                                               const VkCopyBufferInfo2 *pCopyBufferInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyBuffer2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2 *pCopyImageInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyImage2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdCopyImage2KHR(commandBuffer, pCopyImageInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer,
                                                      const VkCopyBufferToImageInfo2 *pCopyBufferToImageInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyBufferToImage2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer,
                                                      const VkCopyImageToBufferInfo2 *pCopyImageToBufferInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyImageToBuffer2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2 *pBlitImageInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBlitImage2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBlitImage2KHR(commandBuffer, pBlitImageInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdResolveImage2KHR(VkCommandBuffer commandBuffer,
                                                 const VkResolveImageInfo2 *pResolveImageInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdResolveImage2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdResolveImage2KHR(commandBuffer, pResolveImageInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer,
                                                      VkDeviceAddress indirectDeviceAddress) {
    Command cmd{};
    cmd.type = Command::Type::kCmdTraceRaysIndirect2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdTraceRaysIndirect2KHR(commandBuffer, indirectDeviceAddress);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset,
                                                    VkDeviceSize size, VkIndexType indexType) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindIndexBuffer2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBindIndexBuffer2KHR(commandBuffer, buffer, offset, size, indexType);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                                  uint16_t lineStipplePattern) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetLineStippleKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetLineStippleKHR(commandBuffer, lineStippleFactor, lineStipplePattern);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBindDescriptorSets2KHR(VkCommandBuffer commandBuffer,
                                                       const VkBindDescriptorSetsInfoKHR *pBindDescriptorSetsInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindDescriptorSets2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBindDescriptorSets2KHR(commandBuffer, pBindDescriptorSetsInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdPushConstants2KHR(VkCommandBuffer commandBuffer,
                                                  const VkPushConstantsInfoKHR *pPushConstantsInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdPushConstants2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdPushConstants2KHR(commandBuffer, pPushConstantsInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdPushDescriptorSet2KHR(VkCommandBuffer commandBuffer,
                                                      const VkPushDescriptorSetInfoKHR *pPushDescriptorSetInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdPushDescriptorSet2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdPushDescriptorSet2KHR(commandBuffer, pPushDescriptorSetInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdPushDescriptorSetWithTemplate2KHR(
    VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfoKHR *pPushDescriptorSetWithTemplateInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdPushDescriptorSetWithTemplate2KHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters =
        recorder_.RecordCmdPushDescriptorSetWithTemplate2KHR(commandBuffer, pPushDescriptorSetWithTemplateInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetDescriptorBufferOffsets2EXT(
    VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT *pSetDescriptorBufferOffsetsInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDescriptorBufferOffsets2EXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetDescriptorBufferOffsets2EXT(commandBuffer, pSetDescriptorBufferOffsetsInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    VkCommandBuffer commandBuffer,
    const VkBindDescriptorBufferEmbeddedSamplersInfoEXT *pBindDescriptorBufferEmbeddedSamplersInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindDescriptorBufferEmbeddedSamplers2EXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBindDescriptorBufferEmbeddedSamplers2EXT(
        commandBuffer, pBindDescriptorBufferEmbeddedSamplersInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer,
                                                    const VkDebugMarkerMarkerInfoEXT *pMarkerInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDebugMarkerBeginEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDebugMarkerEndEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDebugMarkerEndEXT(commandBuffer);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer,
                                                     const VkDebugMarkerMarkerInfoEXT *pMarkerInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDebugMarkerInsertEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                                uint32_t bindingCount, const VkBuffer *pBuffers,
                                                                const VkDeviceSize *pOffsets,
                                                                const VkDeviceSize *pSizes) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindTransformFeedbackBuffersEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount,
                                                                        pBuffers, pOffsets, pSizes);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                                          uint32_t counterBufferCount, const VkBuffer *pCounterBuffers,
                                                          const VkDeviceSize *pCounterBufferOffsets) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBeginTransformFeedbackEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount,
                                                                  pCounterBuffers, pCounterBufferOffsets);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                                        uint32_t counterBufferCount, const VkBuffer *pCounterBuffers,
                                                        const VkDeviceSize *pCounterBufferOffsets) {
    Command cmd{};
    cmd.type = Command::Type::kCmdEndTransformFeedbackEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount,
                                                                pCounterBuffers, pCounterBufferOffsets);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool,
                                                     uint32_t query, VkQueryControlFlags flags, uint32_t index) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBeginQueryIndexedEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query,
                                                   uint32_t index) {
    Command cmd{};
    cmd.type = Command::Type::kCmdEndQueryIndexedEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount,
                                                         uint32_t firstInstance, VkBuffer counterBuffer,
                                                         VkDeviceSize counterBufferOffset, uint32_t counterOffset,
                                                         uint32_t vertexStride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawIndirectByteCountEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDrawIndirectByteCountEXT(
        commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX *pLaunchInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCuLaunchKernelNVX;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                     VkDeviceSize offset, VkBuffer countBuffer,
                                                     VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                     uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawIndirectCountAMD;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer,
                                                             countBufferOffset, maxDrawCount, stride);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                            VkDeviceSize offset, VkBuffer countBuffer,
                                                            VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                            uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawIndexedIndirectCountAMD;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer,
                                                                    countBufferOffset, maxDrawCount, stride);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBeginConditionalRenderingEXT(
    VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT *pConditionalRenderingBegin) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBeginConditionalRenderingEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer) {
    Command cmd{};
    cmd.type = Command::Type::kCmdEndConditionalRenderingEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdEndConditionalRenderingEXT(commandBuffer);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                                      uint32_t viewportCount,
                                                      const VkViewportWScalingNV *pViewportWScalings) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetViewportWScalingNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters =
        recorder_.RecordCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle,
                                                       uint32_t discardRectangleCount,
                                                       const VkRect2D *pDiscardRectangles) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDiscardRectangleEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle,
                                                               discardRectangleCount, pDiscardRectangles);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer,
                                                             VkBool32 discardRectangleEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDiscardRectangleEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer,
                                                           VkDiscardRectangleModeEXT discardRectangleMode) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDiscardRectangleModeEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer,
                                                        const VkDebugUtilsLabelEXT *pLabelInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBeginDebugUtilsLabelEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) {
    Command cmd{};
    cmd.type = Command::Type::kCmdEndDebugUtilsLabelEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdEndDebugUtilsLabelEXT(commandBuffer);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer,
                                                         const VkDebugUtilsLabelEXT *pLabelInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdInsertDebugUtilsLabelEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    commands_.push_back(cmd);
}

#ifdef VK_ENABLE_BETA_EXTENSIONS
void CommandTracker::TrackPreCmdInitializeGraphScratchMemoryAMDX(VkCommandBuffer commandBuffer,
                                                                 VkDeviceAddress scratch) {
    Command cmd{};
    cmd.type = Command::Type::kCmdInitializeGraphScratchMemoryAMDX;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdInitializeGraphScratchMemoryAMDX(commandBuffer, scratch);
    commands_.push_back(cmd);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void CommandTracker::TrackPreCmdDispatchGraphAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                                  const VkDispatchGraphCountInfoAMDX *pCountInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDispatchGraphAMDX;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDispatchGraphAMDX(commandBuffer, scratch, pCountInfo);
    commands_.push_back(cmd);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void CommandTracker::TrackPreCmdDispatchGraphIndirectAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                                          const VkDispatchGraphCountInfoAMDX *pCountInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDispatchGraphIndirectAMDX;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDispatchGraphIndirectAMDX(commandBuffer, scratch, pCountInfo);
    commands_.push_back(cmd);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

#ifdef VK_ENABLE_BETA_EXTENSIONS
void CommandTracker::TrackPreCmdDispatchGraphIndirectCountAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch,
                                                               VkDeviceAddress countInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDispatchGraphIndirectCountAMDX;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDispatchGraphIndirectCountAMDX(commandBuffer, scratch, countInfo);
    commands_.push_back(cmd);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS

void CommandTracker::TrackPreCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer,
                                                      const VkSampleLocationsInfoEXT *pSampleLocationsInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetSampleLocationsEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView,
                                                       VkImageLayout imageLayout) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindShadingRateImageNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                                                uint32_t viewportCount,
                                                                const VkShadingRatePaletteNV *pShadingRatePalettes) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetViewportShadingRatePaletteNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount,
                                                                        pShadingRatePalettes);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer,
                                                       VkCoarseSampleOrderTypeNV sampleOrderType,
                                                       uint32_t customSampleOrderCount,
                                                       const VkCoarseSampleOrderCustomNV *pCustomSampleOrders) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetCoarseSampleOrderNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount,
                                                               pCustomSampleOrders);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer,
                                                             const VkAccelerationStructureInfoNV *pInfo,
                                                             VkBuffer instanceData, VkDeviceSize instanceOffset,
                                                             VkBool32 update, VkAccelerationStructureNV dst,
                                                             VkAccelerationStructureNV src, VkBuffer scratch,
                                                             VkDeviceSize scratchOffset) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBuildAccelerationStructureNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset,
                                                                     update, dst, src, scratch, scratchOffset);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer,
                                                            VkAccelerationStructureNV dst,
                                                            VkAccelerationStructureNV src,
                                                            VkCopyAccelerationStructureModeKHR mode) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyAccelerationStructureNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdTraceRaysNV(
    VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset,
    VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride,
    VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride,
    VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset,
    VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth) {
    Command cmd{};
    cmd.type = Command::Type::kCmdTraceRaysNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdTraceRaysNV(
        commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer,
        missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset,
        hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset,
        callableShaderBindingStride, width, height, depth);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdWriteAccelerationStructuresPropertiesNV(
    VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
    const VkAccelerationStructureNV *pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool,
    uint32_t firstQuery) {
    Command cmd{};
    cmd.type = Command::Type::kCmdWriteAccelerationStructuresPropertiesNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdWriteAccelerationStructuresPropertiesNV(
        commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer,
                                                     VkPipelineStageFlagBits pipelineStage, VkBuffer dstBuffer,
                                                     VkDeviceSize dstOffset, uint32_t marker) {
    Command cmd{};
    cmd.type = Command::Type::kCmdWriteBufferMarkerAMD;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters =
        recorder_.RecordCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawMeshTasksNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                        VkDeviceSize offset, uint32_t drawCount, uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawMeshTasksIndirectNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                             VkDeviceSize offset, VkBuffer countBuffer,
                                                             VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                             uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawMeshTasksIndirectCountNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer,
                                                                     countBufferOffset, maxDrawCount, stride);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer,
                                                            uint32_t firstExclusiveScissor,
                                                            uint32_t exclusiveScissorCount,
                                                            const VkBool32 *pExclusiveScissorEnables) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetExclusiveScissorEnableNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetExclusiveScissorEnableNV(commandBuffer, firstExclusiveScissor,
                                                                    exclusiveScissorCount, pExclusiveScissorEnables);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                                      uint32_t exclusiveScissorCount,
                                                      const VkRect2D *pExclusiveScissors) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetExclusiveScissorNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor,
                                                              exclusiveScissorCount, pExclusiveScissors);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void *pCheckpointMarker) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetCheckpointNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer,
                                                          const VkPerformanceMarkerInfoINTEL *pMarkerInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetPerformanceMarkerINTEL;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetPerformanceMarkerINTEL(commandBuffer, pMarkerInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer,
                                                                const VkPerformanceStreamMarkerInfoINTEL *pMarkerInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetPerformanceStreamMarkerINTEL;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetPerformanceStreamMarkerINTEL(commandBuffer, pMarkerInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer,
                                                            const VkPerformanceOverrideInfoINTEL *pOverrideInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetPerformanceOverrideINTEL;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetPerformanceOverrideINTEL(commandBuffer, pOverrideInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                                  uint16_t lineStipplePattern) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetLineStippleEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetCullModeEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetCullModeEXT(commandBuffer, cullMode);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetFrontFaceEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetFrontFaceEXT(commandBuffer, frontFace);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer,
                                                        VkPrimitiveTopology primitiveTopology) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetPrimitiveTopologyEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount,
                                                        const VkViewport *pViewports) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetViewportWithCountEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount,
                                                       const VkRect2D *pScissors) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetScissorWithCountEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding,
                                                      uint32_t bindingCount, const VkBuffer *pBuffers,
                                                      const VkDeviceSize *pOffsets, const VkDeviceSize *pSizes,
                                                      const VkDeviceSize *pStrides) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindVertexBuffers2EXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers,
                                                              pOffsets, pSizes, pStrides);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthTestEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthWriteEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthCompareOpEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer,
                                                            VkBool32 depthBoundsTestEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthBoundsTestEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetStencilTestEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask,
                                                VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp,
                                                VkCompareOp compareOp) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetStencilOpEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters =
        recorder_.RecordCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer,
                                                              const VkGeneratedCommandsInfoNV *pGeneratedCommandsInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdPreprocessGeneratedCommandsNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed,
                                                           const VkGeneratedCommandsInfoNV *pGeneratedCommandsInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdExecuteGeneratedCommandsNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters =
        recorder_.RecordCmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer,
                                                          VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline,
                                                          uint32_t groupIndex) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindPipelineShaderGroupNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters =
        recorder_.RecordCmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetDepthBias2EXT(VkCommandBuffer commandBuffer,
                                                 const VkDepthBiasInfoEXT *pDepthBiasInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthBias2EXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetDepthBias2EXT(commandBuffer, pDepthBiasInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdCudaLaunchKernelNV(VkCommandBuffer commandBuffer,
                                                   const VkCudaLaunchInfoNV *pLaunchInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCudaLaunchKernelNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdCudaLaunchKernelNV(commandBuffer, pLaunchInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount,
                                                         const VkDescriptorBufferBindingInfoEXT *pBindingInfos) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindDescriptorBuffersEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBindDescriptorBuffersEXT(commandBuffer, bufferCount, pBindingInfos);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer commandBuffer,
                                                              VkPipelineBindPoint pipelineBindPoint,
                                                              VkPipelineLayout layout, uint32_t firstSet,
                                                              uint32_t setCount, const uint32_t *pBufferIndices,
                                                              const VkDeviceSize *pOffsets) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDescriptorBufferOffsetsEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetDescriptorBufferOffsetsEXT(commandBuffer, pipelineBindPoint, layout,
                                                                      firstSet, setCount, pBufferIndices, pOffsets);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer commandBuffer,
                                                                        VkPipelineBindPoint pipelineBindPoint,
                                                                        VkPipelineLayout layout, uint32_t set) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindDescriptorBufferEmbeddedSamplersEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters =
        recorder_.RecordCmdBindDescriptorBufferEmbeddedSamplersEXT(commandBuffer, pipelineBindPoint, layout, set);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetFragmentShadingRateEnumNV(VkCommandBuffer commandBuffer,
                                                             VkFragmentShadingRateNV shadingRate,
                                                             const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetFragmentShadingRateEnumNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetVertexInputEXT(
    VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
    const VkVertexInputBindingDescription2EXT *pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount,
    const VkVertexInputAttributeDescription2EXT *pVertexAttributeDescriptions) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetVertexInputEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters =
        recorder_.RecordCmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions,
                                             vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSubpassShadingHUAWEI;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSubpassShadingHUAWEI(commandBuffer);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer, VkImageView imageView,
                                                         VkImageLayout imageLayout) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindInvocationMaskHUAWEI;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBindInvocationMaskHUAWEI(commandBuffer, imageView, imageLayout);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetPatchControlPointsEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer,
                                                              VkBool32 rasterizerDiscardEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetRasterizerDiscardEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthBiasEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetLogicOpEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetLogicOpEXT(commandBuffer, logicOp);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer,
                                                             VkBool32 primitiveRestartEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetPrimitiveRestartEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount,
                                                       const VkBool32 *pColorWriteEnables) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetColorWriteEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                             const VkMultiDrawInfoEXT *pVertexInfo, uint32_t instanceCount,
                                             uint32_t firstInstance, uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawMultiEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters =
        recorder_.RecordCmdDrawMultiEXT(commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount,
                                                    const VkMultiDrawIndexedInfoEXT *pIndexInfo, uint32_t instanceCount,
                                                    uint32_t firstInstance, uint32_t stride,
                                                    const int32_t *pVertexOffset) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawMultiIndexedEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDrawMultiIndexedEXT(commandBuffer, drawCount, pIndexInfo, instanceCount,
                                                            firstInstance, stride, pVertexOffset);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBuildMicromapsEXT(VkCommandBuffer commandBuffer, uint32_t infoCount,
                                                  const VkMicromapBuildInfoEXT *pInfos) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBuildMicromapsEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBuildMicromapsEXT(commandBuffer, infoCount, pInfos);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT *pInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyMicromapEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdCopyMicromapEXT(commandBuffer, pInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer,
                                                        const VkCopyMicromapToMemoryInfoEXT *pInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyMicromapToMemoryEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdCopyMicromapToMemoryEXT(commandBuffer, pInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer,
                                                        const VkCopyMemoryToMicromapInfoEXT *pInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyMemoryToMicromapEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdCopyMemoryToMicromapEXT(commandBuffer, pInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount,
                                                            const VkMicromapEXT *pMicromaps, VkQueryType queryType,
                                                            VkQueryPool queryPool, uint32_t firstQuery) {
    Command cmd{};
    cmd.type = Command::Type::kCmdWriteMicromapsPropertiesEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdWriteMicromapsPropertiesEXT(commandBuffer, micromapCount, pMicromaps, queryType,
                                                                    queryPool, firstQuery);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX,
                                                  uint32_t groupCountY, uint32_t groupCountZ) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawClusterHUAWEI;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDrawClusterHUAWEI(commandBuffer, groupCountX, groupCountY, groupCountZ);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                          VkDeviceSize offset) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawClusterIndirectHUAWEI;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDrawClusterIndirectHUAWEI(commandBuffer, buffer, offset);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress,
                                                     uint32_t copyCount, uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyMemoryIndirectNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdCopyMemoryIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdCopyMemoryToImageIndirectNV(VkCommandBuffer commandBuffer,
                                                            VkDeviceAddress copyBufferAddress, uint32_t copyCount,
                                                            uint32_t stride, VkImage dstImage,
                                                            VkImageLayout dstImageLayout,
                                                            const VkImageSubresourceLayers *pImageSubresources) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyMemoryToImageIndirectNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdCopyMemoryToImageIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride,
                                                                    dstImage, dstImageLayout, pImageSubresources);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount,
                                                   const VkDecompressMemoryRegionNV *pDecompressMemoryRegions) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDecompressMemoryNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters =
        recorder_.RecordCmdDecompressMemoryNV(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer,
                                                                VkDeviceAddress indirectCommandsAddress,
                                                                VkDeviceAddress indirectCommandsCountAddress,
                                                                uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDecompressMemoryIndirectCountNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDecompressMemoryIndirectCountNV(commandBuffer, indirectCommandsAddress,
                                                                        indirectCommandsCountAddress, stride);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer,
                                                               VkPipelineBindPoint pipelineBindPoint,
                                                               VkPipeline pipeline) {
    Command cmd{};
    cmd.type = Command::Type::kCmdUpdatePipelineIndirectBufferNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdUpdatePipelineIndirectBufferNV(commandBuffer, pipelineBindPoint, pipeline);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClampEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthClampEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetDepthClampEnableEXT(commandBuffer, depthClampEnable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetPolygonModeEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetPolygonModeEXT(commandBuffer, polygonMode);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer,
                                                           VkSampleCountFlagBits rasterizationSamples) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetRasterizationSamplesEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetRasterizationSamplesEXT(commandBuffer, rasterizationSamples);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples,
                                                 const VkSampleMask *pSampleMask) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetSampleMaskEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetSampleMaskEXT(commandBuffer, samples, pSampleMask);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer,
                                                            VkBool32 alphaToCoverageEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetAlphaToCoverageEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetAlphaToCoverageEnableEXT(commandBuffer, alphaToCoverageEnable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetAlphaToOneEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetAlphaToOneEnableEXT(commandBuffer, alphaToOneEnable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetLogicOpEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetLogicOpEnableEXT(commandBuffer, logicOpEnable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                                       uint32_t attachmentCount, const VkBool32 *pColorBlendEnables) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetColorBlendEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters =
        recorder_.RecordCmdSetColorBlendEnableEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                                         uint32_t attachmentCount,
                                                         const VkColorBlendEquationEXT *pColorBlendEquations) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetColorBlendEquationEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetColorBlendEquationEXT(commandBuffer, firstAttachment, attachmentCount,
                                                                 pColorBlendEquations);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                                     uint32_t attachmentCount,
                                                     const VkColorComponentFlags *pColorWriteMasks) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetColorWriteMaskEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters =
        recorder_.RecordCmdSetColorWriteMaskEXT(commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer,
                                                               VkTessellationDomainOrigin domainOrigin) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetTessellationDomainOriginEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetTessellationDomainOriginEXT(commandBuffer, domainOrigin);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer, uint32_t rasterizationStream) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetRasterizationStreamEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetRasterizationStreamEXT(commandBuffer, rasterizationStream);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetConservativeRasterizationModeEXT(
    VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetConservativeRasterizationModeEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters =
        recorder_.RecordCmdSetConservativeRasterizationModeEXT(commandBuffer, conservativeRasterizationMode);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer commandBuffer,
                                                                       float extraPrimitiveOverestimationSize) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetExtraPrimitiveOverestimationSizeEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters =
        recorder_.RecordCmdSetExtraPrimitiveOverestimationSizeEXT(commandBuffer, extraPrimitiveOverestimationSize);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClipEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthClipEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetDepthClipEnableEXT(commandBuffer, depthClipEnable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer,
                                                            VkBool32 sampleLocationsEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetSampleLocationsEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetSampleLocationsEnableEXT(commandBuffer, sampleLocationsEnable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment,
                                                         uint32_t attachmentCount,
                                                         const VkColorBlendAdvancedEXT *pColorBlendAdvanced) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetColorBlendAdvancedEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetColorBlendAdvancedEXT(commandBuffer, firstAttachment, attachmentCount,
                                                                 pColorBlendAdvanced);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer,
                                                          VkProvokingVertexModeEXT provokingVertexMode) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetProvokingVertexModeEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetProvokingVertexModeEXT(commandBuffer, provokingVertexMode);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetLineRasterizationModeEXT(VkCommandBuffer commandBuffer,
                                                            VkLineRasterizationModeEXT lineRasterizationMode) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetLineRasterizationModeEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetLineRasterizationModeEXT(commandBuffer, lineRasterizationMode);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetLineStippleEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetLineStippleEnableEXT(commandBuffer, stippledLineEnable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer,
                                                                VkBool32 negativeOneToOne) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetDepthClipNegativeOneToOneEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetDepthClipNegativeOneToOneEXT(commandBuffer, negativeOneToOne);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer,
                                                            VkBool32 viewportWScalingEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetViewportWScalingEnableNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetViewportWScalingEnableNV(commandBuffer, viewportWScalingEnable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport,
                                                     uint32_t viewportCount,
                                                     const VkViewportSwizzleNV *pViewportSwizzles) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetViewportSwizzleNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters =
        recorder_.RecordCmdSetViewportSwizzleNV(commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer,
                                                           VkBool32 coverageToColorEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetCoverageToColorEnableNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetCoverageToColorEnableNV(commandBuffer, coverageToColorEnable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer,
                                                             uint32_t coverageToColorLocation) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetCoverageToColorLocationNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetCoverageToColorLocationNV(commandBuffer, coverageToColorLocation);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetCoverageModulationModeNV(VkCommandBuffer commandBuffer,
                                                            VkCoverageModulationModeNV coverageModulationMode) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetCoverageModulationModeNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetCoverageModulationModeNV(commandBuffer, coverageModulationMode);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer,
                                                                   VkBool32 coverageModulationTableEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetCoverageModulationTableEnableNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters =
        recorder_.RecordCmdSetCoverageModulationTableEnableNV(commandBuffer, coverageModulationTableEnable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer,
                                                             uint32_t coverageModulationTableCount,
                                                             const float *pCoverageModulationTable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetCoverageModulationTableNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetCoverageModulationTableNV(commandBuffer, coverageModulationTableCount,
                                                                     pCoverageModulationTable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer,
                                                            VkBool32 shadingRateImageEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetShadingRateImageEnableNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetShadingRateImageEnableNV(commandBuffer, shadingRateImageEnable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer commandBuffer,
                                                                      VkBool32 representativeFragmentTestEnable) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetRepresentativeFragmentTestEnableNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters =
        recorder_.RecordCmdSetRepresentativeFragmentTestEnableNV(commandBuffer, representativeFragmentTestEnable);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer,
                                                           VkCoverageReductionModeNV coverageReductionMode) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetCoverageReductionModeNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetCoverageReductionModeNV(commandBuffer, coverageReductionMode);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session,
                                                     const VkOpticalFlowExecuteInfoNV *pExecuteInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdOpticalFlowExecuteNV;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdOpticalFlowExecuteNV(commandBuffer, session, pExecuteInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount,
                                               const VkShaderStageFlagBits *pStages, const VkShaderEXT *pShaders) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBindShadersEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBindShadersEXT(commandBuffer, stageCount, pStages, pShaders);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer,
                                                                   VkImageAspectFlags aspectMask) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetAttachmentFeedbackLoopEnableEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetAttachmentFeedbackLoopEnableEXT(commandBuffer, aspectMask);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBuildAccelerationStructuresKHR(
    VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR *pInfos,
    const VkAccelerationStructureBuildRangeInfoKHR *const *ppBuildRangeInfos) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBuildAccelerationStructuresKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters =
        recorder_.RecordCmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdBuildAccelerationStructuresIndirectKHR(
    VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR *pInfos,
    const VkDeviceAddress *pIndirectDeviceAddresses, const uint32_t *pIndirectStrides,
    const uint32_t *const *ppMaxPrimitiveCounts) {
    Command cmd{};
    cmd.type = Command::Type::kCmdBuildAccelerationStructuresIndirectKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdBuildAccelerationStructuresIndirectKHR(
        commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer,
                                                             const VkCopyAccelerationStructureInfoKHR *pInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyAccelerationStructureKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdCopyAccelerationStructureKHR(commandBuffer, pInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdCopyAccelerationStructureToMemoryKHR(
    VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR *pInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyAccelerationStructureToMemoryKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdCopyMemoryToAccelerationStructureKHR(
    VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR *pInfo) {
    Command cmd{};
    cmd.type = Command::Type::kCmdCopyMemoryToAccelerationStructureKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdWriteAccelerationStructuresPropertiesKHR(
    VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount,
    const VkAccelerationStructureKHR *pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool,
    uint32_t firstQuery) {
    Command cmd{};
    cmd.type = Command::Type::kCmdWriteAccelerationStructuresPropertiesKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdWriteAccelerationStructuresPropertiesKHR(
        commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdTraceRaysKHR(VkCommandBuffer commandBuffer,
                                             const VkStridedDeviceAddressRegionKHR *pRaygenShaderBindingTable,
                                             const VkStridedDeviceAddressRegionKHR *pMissShaderBindingTable,
                                             const VkStridedDeviceAddressRegionKHR *pHitShaderBindingTable,
                                             const VkStridedDeviceAddressRegionKHR *pCallableShaderBindingTable,
                                             uint32_t width, uint32_t height, uint32_t depth) {
    Command cmd{};
    cmd.type = Command::Type::kCmdTraceRaysKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters =
        recorder_.RecordCmdTraceRaysKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable,
                                        pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer,
                                                     const VkStridedDeviceAddressRegionKHR *pRaygenShaderBindingTable,
                                                     const VkStridedDeviceAddressRegionKHR *pMissShaderBindingTable,
                                                     const VkStridedDeviceAddressRegionKHR *pHitShaderBindingTable,
                                                     const VkStridedDeviceAddressRegionKHR *pCallableShaderBindingTable,
                                                     VkDeviceAddress indirectDeviceAddress) {
    Command cmd{};
    cmd.type = Command::Type::kCmdTraceRaysIndirectKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdTraceRaysIndirectKHR(commandBuffer, pRaygenShaderBindingTable,
                                                             pMissShaderBindingTable, pHitShaderBindingTable,
                                                             pCallableShaderBindingTable, indirectDeviceAddress);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer,
                                                                  uint32_t pipelineStackSize) {
    Command cmd{};
    cmd.type = Command::Type::kCmdSetRayTracingPipelineStackSizeKHR;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX,
                                                 uint32_t groupCountY, uint32_t groupCountZ) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawMeshTasksEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDrawMeshTasksEXT(commandBuffer, groupCountX, groupCountY, groupCountZ);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                         VkDeviceSize offset, uint32_t drawCount, uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawMeshTasksIndirectEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDrawMeshTasksIndirectEXT(commandBuffer, buffer, offset, drawCount, stride);
    commands_.push_back(cmd);
}

void CommandTracker::TrackPreCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer, VkBuffer buffer,
                                                              VkDeviceSize offset, VkBuffer countBuffer,
                                                              VkDeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                              uint32_t stride) {
    Command cmd{};
    cmd.type = Command::Type::kCmdDrawMeshTasksIndirectCountEXT;
    cmd.id = static_cast<uint32_t>(commands_.size()) + 1;
    cmd.parameters = recorder_.RecordCmdDrawMeshTasksIndirectCountEXT(commandBuffer, buffer, offset, countBuffer,
                                                                      countBufferOffset, maxDrawCount, stride);
    commands_.push_back(cmd);
}

// NOLINTEND
