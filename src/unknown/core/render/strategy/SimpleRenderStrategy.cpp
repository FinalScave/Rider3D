//
// Created by Scave on 2023/11/13.
//

#include "SimpleRenderStrategy.h"
#include "bx/math.h"

UNKNOWN_NS_BEGIN
static Color red = {1.0, 0.0, 0.0, 1.0};
static Color green = {0.0, 1.0, 0.0, 1.0};
static Color blue = {0.0, 0.0, 1.0, 1.0};
    static Vertex s_cubeVertices[] =
            {
                    {-0.5f,  0.5f,  0.5f, {0, 0}, red},
                    { 0.5f,  0.5f,  0.5f, {0, 0}, green },
                    {-0.5f, -0.5f,  0.5f, {0, 0}, blue },
                    { 0.5f, -0.5f,  0.5f, {0, 0}, red },
                    {-0.5f,  0.5f, -0.5f, {0, 0}, green },
                    { 0.5f,  0.5f, -0.5f, {0, 0}, blue },
                    {-0.5f, -0.5f, -0.5f, {0, 0}, red },
                    { 0.5f, -0.5f, -0.5f, {0, 0}, green },
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
        //bgfx::setViewClear(view_id, BGFX_CLEAR_DEPTH | BGFX_CLEAR_COLOR, 0x666666ff);
        bgfx::touch(view_id);
        auto m_vbh = bgfx::createVertexBuffer(
                // Static data can be passed with bgfx::makeRef
                bgfx::makeRef(s_cubeVertices, sizeof(Vertex)*8 )
                , program_->vertex_layout_
        );

        // Create static index buffer for triangle list rendering.
        auto m_ibh = bgfx::createIndexBuffer(
                // Static data can be passed with bgfx::makeRef
                bgfx::makeRef(s_cubeTriList, sizeof(s_cubeTriList) )
        );
        bgfx::setVertexBuffer(0, m_vbh);
        bgfx::setIndexBuffer(m_ibh);
        bgfx::setViewFrameBuffer(view_id, BGFX_INVALID_HANDLE);
        /*bgfx::setState(BGFX_STATE_WRITE_RGB
                       | BGFX_STATE_WRITE_Z
                       | BGFX_STATE_DEPTH_TEST_LESS
                       | BGFX_STATE_MSAA);*/
        bgfx::setState(BGFX_STATE_WRITE_RGB | BGFX_STATE_BLEND_ALPHA);
        DELETE_ARRAY(model_matrix_);
        DELETE_ARRAY(view_matrix_);
        DELETE_ARRAY(proj_matrix_);
        this->model_matrix_ = new float[16];
        this->view_matrix_ = new float[16];
        this->proj_matrix_ = new float[16];
        bx::mtxIdentity(model_matrix_);
        bx::mtxIdentity(view_matrix_);
        bx::mtxIdentity(proj_matrix_);
        Camera* camera = context_->GetCamera();
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
        bx::mtxRotateXYZ(model_matrix_, object.rotation->x, object.rotation->y, object.rotation->z);
        bgfx::setTransform(model_matrix_);
        bgfx::submit(view_id, program_->program_handle_);
    }

UNKNOWN_NS_END
