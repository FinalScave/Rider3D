//
// Created by Scave on 2023/11/13.
//

#include "Graph2DRenderer.h"
#include "bx/math.h"
#include "BasicComponents.h"

NS_RIDER_BEGIN

    Graph2DRenderer::Graph2DRenderer(const SMART_PTR<RenderContext>& context) : EntityRenderer(context) {
        this->program_ = MAKE_SMART_PTR<SimpleShaderProgram>();
    }

    void Graph2DRenderer::RenderEntity(Entity& entity) {
        if (!entity.has_component<Vertices>()) {
            return;
        }
        auto vertices = entity.component<Vertices>();
        BufferHandle* handle = context_->CreateOrUpdateBuffer(
                entity,
                program_->vertex_layout_,
                vertices->vertex_data_list,
                vertices->vertex_index_list
        );
        uint8_t view_id = context_->curr_view_id_;
        uint16_t width = context_->render_config_.width;
        uint16_t height = context_->render_config_.height;
        bgfx::setViewRect(view_id, 0, 0, width, height);
        //bgfx::setViewClear(view_id, BGFX_CLEAR_DEPTH | BGFX_CLEAR_COLOR, 0x666666ff);
        bgfx::touch(view_id);
        bgfx::setVertexBuffer(0, handle->vertex_buffer);
        bgfx::setIndexBuffer(handle->index_buffer);
        bgfx::setViewFrameBuffer(view_id, BGFX_INVALID_HANDLE);
        bgfx::setState(BGFX_STATE_WRITE_RGB | BGFX_STATE_BLEND_ALPHA);
        if (context_->scene_->has_component<Camera>()) {
            bx::mtxIdentity(view_matrix_);
            bx::mtxIdentity(proj_matrix_);
            Camera* camera = context_->scene_->component<Camera>().get();
            bx::Vec3 eye = {camera->position.x, camera->position.y, camera->position.z};
            bx::Vec3 at = {camera->target.x, camera->target.y, camera->target.z};
            bx::Vec3 up_axis = {camera->up_axis.x, camera->up_axis.y, camera->up_axis.z};
            bx::mtxLookAt(view_matrix_, eye, at, up_axis);
            bx::mtxProj(proj_matrix_,
                        60.f,
                        context_->render_config_.width * 1.f / context_->render_config_.height,
                        0.1f, 100.f,
                        bgfx::getCaps()->homogeneousDepth
            );
            bgfx::setViewTransform(view_id, view_matrix_, proj_matrix_);
        }
        bx::mtxIdentity(model_matrix_);
        Transform transform;
        if (entity.has_component<Transform>()) {
            transform = *entity.component<Transform>();
        }
        // 相乘顺序为 平移 * 旋转 * 缩放，分步乘则从右往左乘
        float mtx_scale[16];
        bx::mtxIdentity(mtx_scale);
        bx::mtxScale(mtx_scale,
                     transform.scale.x, transform.scale.y, transform.scale.z);
        float mtx_rotate[16];
        bx::mtxIdentity(mtx_rotate);
        bx::mtxRotateXYZ(mtx_rotate,
                         transform.rotation.x, transform.rotation.y, transform.rotation.z);
        float mtx_scale_rotate[16];
        bx::mtxIdentity(mtx_scale_rotate);
        bx::mtxMul(mtx_scale_rotate, mtx_scale, mtx_rotate);
        float mtx_trans[16];
        bx::mtxIdentity(mtx_trans);
        bx::mtxTranslate(mtx_trans,
                         transform.translation.x, transform.translation.y, transform.translation.z);
        bx::mtxIdentity(model_matrix_);
        bx::mtxMul(model_matrix_, mtx_scale_rotate, mtx_trans);
        bgfx::setTransform(model_matrix_);

        bgfx::submit(view_id, program_->program_handle_);
    }

NS_RIDER_END
