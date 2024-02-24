//
// Created by Scave on 2023/11/13.
//

#include "Graph3DRenderer.h"
#include "bx/math.h"
#include "BasicComponents.h"

UNKNOWN_NS_BEGIN
    /*static Color red = {1.0, 0.0, 0.0, 1.0};
    static Color green = {0.0, 1.0, 0.0, 1.0};
    static Color blue = {0.0, 0.0, 1.0, 1.0};
    static Vertex s_cubeVertices[] =
            {
                    {-0.5f, 0.5f,  0.5f,  {0, 0}, red},
                    {0.5f,  0.5f,  0.5f,  {0, 0}, green},
                    {-0.5f, -0.5f, 0.5f,  {0, 0}, blue},
                    {0.5f,  -0.5f, 0.5f,  {0, 0}, red},
                    {-0.5f, 0.5f,  -0.5f, {0, 0}, green},
                    {0.5f,  0.5f,  -0.5f, {0, 0}, blue},
                    {-0.5f, -0.5f, -0.5f, {0, 0}, red},
                    {0.5f,  -0.5f, -0.5f, {0, 0}, green},
            };
    static const uint16_t s_cubeTriList[] =
            {
                    0, 1, 2, // 0
                    1, 3, 2,
                    4, 6, 5, // 2
                    5, 6, 7,
                    0, 2, 4, // 4
                    4, 2, 6,
                    1, 5, 3, // 6
                    5, 7, 3,
                    0, 4, 1, // 8
                    4, 5, 1,
                    2, 3, 6, // 10
                    6, 3, 7,
            };*/

    Graph3DRenderer::Graph3DRenderer(const SMART_PTR<RenderContext>& context) : EntityRenderer(context) {
        this->program_ = MAKE_SMART_PTR<CommonShaderProgram>();
        vec4_resolution_[0] = context->render_config_.width;
        vec4_resolution_[1] = context->render_config_.height;
    }

    void Graph3DRenderer::RenderEntity(Entity& entity) {
        if (!entity.has_component<Vertices>()) {
            return;
        }
        Vertices* vertices = entity.component<Vertices>().get();
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
        bgfx::touch(view_id);
        /*auto m_vbh = bgfx::createVertexBuffer(
                bgfx::makeRef(s_cubeVertices, sizeof(Vertex) * 8), program_->vertex_layout_
        );
        auto m_ibh = bgfx::createIndexBuffer(
                bgfx::makeRef(s_cubeTriList, sizeof(s_cubeTriList))
        );*/
        bgfx::setVertexBuffer(0, handle->vertex_buffer);
        bgfx::setIndexBuffer(handle->index_buffer);
        bgfx::setViewFrameBuffer(0, BGFX_INVALID_HANDLE);
        bgfx::setState(BGFX_STATE_WRITE_RGB | BGFX_STATE_BLEND_ALPHA);

        if (context_->scene_->has_component<Camera>()) {
            bx::mtxIdentity(view_matrix_);
            bx::mtxIdentity(proj_matrix_);
            auto camera = context_->scene_->component<Camera>();
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
        bx::mtxScale(model_matrix_,
                     transform.scale.x, transform.scale.y, transform.scale.z);
        bx::mtxRotateXYZ(model_matrix_,
                         transform.rotation.x, transform.rotation.y, transform.rotation.z);
        bx::mtxTranslate(model_matrix_,
                         transform.translation.x, transform.translation.y, transform.translation.z);
        bgfx::setTransform(model_matrix_);

        bgfx::setUniform(program_->uniform_handles_[0], vec4_resolution_);
        bgfx::submit(view_id, program_->program_handle_);
    }


UNKNOWN_NS_END
