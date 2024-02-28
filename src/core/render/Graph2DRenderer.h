//
// Created by Scave on 2023/11/13.
//

#ifndef RIDER3D_GRAPH2DRENDERER_H
#define RIDER3D_GRAPH2DRENDERER_H

#include "Define.h"
#include "EntityRenderer.h"

NS_RIDER_BEGIN

    class Graph2DRenderer : public EntityRenderer {
    public:
        explicit Graph2DRenderer(const SMART_PTR<RenderContext>& context);

        void RenderEntity(Entity& entity) override;

    private:
        float model_matrix_[16] = {0};
        float view_matrix_[16] = {0};
        float proj_matrix_[16] = {0};
    };

NS_RIDER_END

#endif //RIDER3D_GRAPH2DRENDERER_H
