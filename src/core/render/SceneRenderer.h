//
// Created by Scave on 2023/11/8.
//

#ifndef UNKNOWN3D_SCENERENDERER_H
#define UNKNOWN3D_SCENERENDERER_H

#include "Define.h"
#include "config/RenderConfig.h"
#include "Supposition.h"
#include "Vertex.h"
#include "context/RenderContext.h"
#include "strategy/SimpleRenderStrategy.h"
#include "strategy/CommonRenderStrategy.h"
#include "Scene.h"
#include "Object3D.h"

UNKNOWN_NS_BEGIN

    class UnknownEngine;

    class SceneRenderer {
        friend UnknownEngine;
    public:
        explicit SceneRenderer(const RenderConfig &config);

        ~SceneRenderer();

        void SetScene(const SMART_PTR<Scene> &scene);

        /// OffScreen render, return the texture id after rendering
        /// \return Texture ID
        uint16_t Render();
    private:
        /// Configuration for rendering
        RenderConfig render_config_;
        /// Context for rendering
        SMART_PTR<RenderContext> render_context_;
        SMART_PTR<SimpleRenderStrategy> simple_renderer_;
        SMART_PTR<CommonRenderStrategy> common_renderer_;

        void RenderScene();

        void RenderObject(Object3D &object, uint8_t id);
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_SCENERENDERER_H
