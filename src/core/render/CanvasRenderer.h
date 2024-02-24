//
// Created by Scave on 2024/2/24.
//

#ifndef UNKNOWN3D_CANVASRENDERER_H
#define UNKNOWN3D_CANVASRENDERER_H

#include "Define.h"
#include "EntityRenderer.h"

UNKNOWN_NS_BEGIN

    class CanvasRenderer : public EntityRenderer {
    public:
        explicit CanvasRenderer(const SMART_PTR<RenderContext>& context);

        void RenderEntity(Entity& entity) override;
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_CANVASRENDERER_H
