//
// Created by Scave on 2023/11/13.
//

#include "bx/math.h"
#include "BasicComponents.h"
#include "TestRenderer.h"

NS_RIDER_BEGIN

    static Color red = {1.0, 0.0, 0.0, 1.0};
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
            };

    TestRenderer::TestRenderer(const SMART_PTR<RenderContext>& context) : EntityRenderer(context) {
        this->program_ = MAKE_SMART_PTR<SimpleShaderProgram>();
    }

    void TestRenderer::RenderEntity(Entity& entity) {
        if (!entity.has_component<Vertices>()) {
            return;
        }
        uint8_t view_id = context_->curr_view_id_;
        uint16_t width = context_->render_config_.width;
        uint16_t height = context_->render_config_.height;
        bgfx::setViewRect(view_id, 0, 0, width, height);
        //bgfx::setViewClear(view_id, BGFX_CLEAR_DEPTH | BGFX_CLEAR_COLOR, 0x666666ff);
        bgfx::touch(view_id);
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

        auto m_vbh = bgfx::createVertexBuffer(
                bgfx::makeRef(s_cubeVertices, sizeof(Vertex) * 8), program_->vertex_layout_
        );
        auto m_ibh = bgfx::createIndexBuffer(
                bgfx::makeRef(s_cubeTriList, sizeof(s_cubeTriList))
        );
        bgfx::setVertexBuffer(0, m_vbh);
        bgfx::setIndexBuffer(m_ibh);
        bgfx::setViewFrameBuffer(view_id, BGFX_INVALID_HANDLE);
        bgfx::setState(BGFX_STATE_WRITE_RGB | BGFX_STATE_BLEND_ALPHA);
        bgfx::submit(view_id, program_->program_handle_);
    }

NS_RIDER_END
