//
// Created by Scave on 2023/11/13.
//

#include "SimpleRenderStrategy.h"

UNKNOWN_NS_BEGIN

    const static float vertices[] = {
        0, 0.5, 0, 0, 0, 1, 1, 1, 1,
        0.5, 0.5, 0, 0, 0, 1, 1, 1, 1,
        0.5, 0, 0, 0, 0, 1, 1, 1, 1,
        0, 0, 0, 0, 0, 1, 1, 1, 1,
    };
    const static uint16_t indices[] = {
            0, 1, 2,
            0, 3, 2
    };

    SimpleRenderStrategy::SimpleRenderStrategy(const SMART_PTR<RenderContext>& context) : RenderStrategy(context) {
        this->program_ = MAKE_SMART_PTR<SimpleShaderProgram>();
    }

    void SimpleRenderStrategy::RenderObject(Object3D& object) {
        BufferHandle& handle = context_->CreateOrUpdateBuffer(
                object.GetName(),
                program_->vertex_layout_,
                object.vertices->vertex_data_list,
                object.vertices->vertex_index_list
        );
        uint8_t view_id = context_->curr_view_id_;
        uint16_t width = context_->render_config_.width;
        uint16_t height = context_->render_config_.height;
        bgfx::setViewRect(view_id, 0, 0, width, height);
        bgfx::setViewClear(view_id, BGFX_CLEAR_DEPTH | BGFX_CLEAR_COLOR, 0x666666ff);
        bgfx::touch(view_id);
        auto vertex_ref = bgfx::makeRef(vertices, sizeof(float) * 9 * 4);
        auto vertex_buffer = bgfx::createVertexBuffer(vertex_ref, program_->vertex_layout_);
        auto index_ref = bgfx::makeRef(indices, sizeof(uint16_t) * 6);
        auto index_buffer = bgfx::createIndexBuffer(index_ref);
        bgfx::setVertexBuffer(0, vertex_buffer);
        bgfx::setIndexBuffer(index_buffer);
        bgfx::setViewFrameBuffer(view_id, BGFX_INVALID_HANDLE);
        bgfx::setState(BGFX_STATE_WRITE_RGB | BGFX_STATE_BLEND_ALPHA);
        bgfx::submit(view_id, program_->program_handle_);
    }

UNKNOWN_NS_END
