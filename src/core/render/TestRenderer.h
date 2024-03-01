//
// Created by Scave on 2023/11/13.
//

#ifndef RIDER3D_TESTRENDERER_H
#define RIDER3D_TESTRENDERER_H

#include "Define.h"
#include "EntityRenderer.h"

NS_RIDER_BEGIN

    class TestRenderer : public EntityRenderer {
    public:
        explicit TestRenderer(const SMART_PTR<RenderContext>& context);

        void RenderEntity(Entity& entity) override;

    private:
        bgfx::VertexBufferHandle vertex_buffer_ = BGFX_INVALID_HANDLE;
        bgfx::IndexBufferHandle index_buffer_ = BGFX_INVALID_HANDLE;
        float model_matrix_[16] = {0};
        float view_matrix_[16] = {0};
        float proj_matrix_[16] = {0};
    };

NS_RIDER_END

#endif //RIDER3D_TESTRENDERER_H
