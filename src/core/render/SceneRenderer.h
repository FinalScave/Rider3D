//
// Created by Scave on 2023/11/8.
//

#ifndef RIDER3D_SCENERENDERER_H
#define RIDER3D_SCENERENDERER_H

#include "Define.h"
#include "config/RenderConfig.h"
#include "Supposition.h"
#include "context/RenderContext.h"
#include "Graph2DRenderer.h"
#include "Graph3DRenderer.h"
#include "Scene.h"

NS_RIDER_BEGIN

    class RiderEngine;

    class SceneRenderer {
        friend RiderEngine;
    public:
        explicit SceneRenderer(const RenderConfig& config);

        ~SceneRenderer();

        void SetScene(Scene* scene);

        /// OffScreen render, return the texture id after rendering
        /// \return Texture ID
        TEXTURE_ID_TYPE Render();

    private:
        /// Configuration for rendering
        RenderConfig render_config_;
        /// Context for rendering
        SMART_PTR<RenderContext> context_;
        SMART_PTR<Graph2DRenderer> renderer_2d;
        SMART_PTR<Graph3DRenderer> renderer_3d;

        void RenderScene();

        void RenderEntity(Entity& entity, ENTITY_SIZE_TYPE order);
    };

NS_RIDER_END

#endif //RIDER3D_SCENERENDERER_H
