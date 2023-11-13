//
// Created by Scave on 2023/11/13.
//

#include "CommonRenderStrategy.h"

UNKNOWN_NS_BEGIN

    CommonRenderStrategy::CommonRenderStrategy(const SMART_PTR<RenderContext>& context) : RenderStrategy(context) {
        this->program_ = MAKE_SMART_PTR<SimpleShaderProgram>();
        program_->Load(VS_COMMON, VS_COMMON_LEN, FS_COMMON, FS_COMMON_LEN);
        vec4_resolution_[0] = context->render_config_.width;
        vec4_resolution_[1] = context->render_config_.height;
    }

    void CommonRenderStrategy::RenderObject(Object3D& object) {
        BufferHandle& handle = context_->CreateOrUpdateBuffer(
                object.GetName(),
                object.vertices->vertex_data_list,
                object.vertices->vertex_index_list
        );
        uint8_t view_id = context_->curr_view_id_;
        uint16_t width = context_->render_config_.width;
        uint16_t height = context_->render_config_.height;
        bgfx::setViewRect(view_id, 0, 0, width, height);
        bgfx::touch(view_id);
        bgfx::setVertexBuffer(0, DefaultBgfxHandles::GetVertexBufferHandle());
        bgfx::setIndexBuffer(DefaultBgfxHandles::GetIndexBufferHandle());
        bgfx::setViewFrameBuffer(0, BGFX_INVALID_HANDLE);
        bgfx::setState(BGFX_STATE_WRITE_RGB | BGFX_STATE_BLEND_ALPHA);
        bgfx::submit(view_id, program_->program_handle_);
    }


UNKNOWN_NS_END
