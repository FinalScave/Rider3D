//
// Created by Scave on 2023/11/13.
//

#include "CommonRenderStrategy.h"
#include "bx/math.h"

UNKNOWN_NS_BEGIN

    CommonRenderStrategy::CommonRenderStrategy(const SMART_PTR<RenderContext>& context) : RenderStrategy(context) {
        this->program_ = MAKE_SMART_PTR<CommonShaderProgram>();
        vec4_resolution_[0] = context->render_config_.width;
        vec4_resolution_[1] = context->render_config_.height;
        bx::mtxIdentity(model_matrix_);
        bx::mtxIdentity(view_matrix_);
        bx::mtxIdentity(proj_matrix_);
    }

    void CommonRenderStrategy::RenderObject(Object3D& object) {
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
        bgfx::touch(view_id);
        bgfx::setVertexBuffer(0, handle.vertex_buffer);
        bgfx::setIndexBuffer(handle.index_buffer);
        bgfx::setViewFrameBuffer(0, BGFX_INVALID_HANDLE);
        bgfx::setState(BGFX_STATE_WRITE_RGB | BGFX_STATE_BLEND_ALPHA);
        bx::mtxLookAt(view_matrix_, {1, 0, 0}, {0, 0, 0});
        bx::mtxProj(proj_matrix_, 0.2f, 0.5f, 0.1f, 100.f, true);
        bgfx::setViewTransform(view_id, view_matrix_, proj_matrix_);
        bx::mtxRotateX(model_matrix_, object.rotation->x);
        bgfx::setTransform(model_matrix_);
        bgfx::setUniform(program_->uniform_handles_[0], vec4_resolution_);
        bgfx::submit(view_id, program_->program_handle_);
    }


UNKNOWN_NS_END
