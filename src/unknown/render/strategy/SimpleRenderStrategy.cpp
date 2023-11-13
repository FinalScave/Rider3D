//
// Created by Scave on 2023/11/13.
//

#include "SimpleRenderStrategy.h"

UNKNOWN_NS_BEGIN

    SimpleRenderStrategy::SimpleRenderStrategy(const SMART_PTR<RenderContext>& context) : RenderStrategy(context) {
        this->program_ = MAKE_SMART_PTR<SimpleShaderProgram>();
        program_->Load(VS_SIMPLE, VS_SIMPLE_LEN, FS_SIMPLE, FS_SIMPLE_LEN);
    }

    void SimpleRenderStrategy::RenderObject(Object3D& object) {
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
        bgfx::setViewFrameBuffer(view_id, BGFX_INVALID_HANDLE);
        bgfx::setState(BGFX_STATE_WRITE_RGB | BGFX_STATE_BLEND_ALPHA);
        bgfx::submit(view_id, program_->program_handle_);
    }

UNKNOWN_NS_END
