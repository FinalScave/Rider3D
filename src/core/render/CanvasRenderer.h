//
// Created by Scave on 2024/2/24.
//

#ifndef RIDER3D_CANVASRENDERER_H
#define RIDER3D_CANVASRENDERER_H

#include "Define.h"
#include "EntityRenderer.h"

NS_RIDER_BEGIN

    class CanvasRenderer : public EntityRenderer {
    public:
        explicit CanvasRenderer(const SMART_PTR<RenderContext>& context);

        void RenderEntity(Entity& entity) override;
    };

NS_RIDER_END

#endif //RIDER3D_CANVASRENDERER_H
