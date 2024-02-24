//
// Created by Scave on 2023/11/13.
//

#ifndef UNKNOWN3D_GRAPH2DRENDERER_H
#define UNKNOWN3D_GRAPH2DRENDERER_H

#include "Define.h"
#include "EntityRenderer.h"

UNKNOWN_NS_BEGIN

    class Graph2DRenderer : public EntityRenderer {
    public:
        explicit Graph2DRenderer(const SMART_PTR<RenderContext>& context);

        void RenderEntity(Entity &entity) override;
    private:
        float* model_matrix_ = nullptr;
        float* view_matrix_ = nullptr;
        float* proj_matrix_ = nullptr;
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_GRAPH2DRENDERER_H
