//
// Created by Scave on 2023/11/8.
//

#ifndef UNKNOWN3D_UNKNOWNRENDERER_H
#define UNKNOWN3D_UNKNOWNRENDERER_H

#include <stdint.h>
#include "Define.h"
#include "config/RenderConfig.h"
#include "object/Supposition.h"
#include "object/Vertex.h"
#include "context/RenderContext.h"

UNKNOWN_NS_BEGIN

    class Unknown3DEngine;

    class UnknownRenderer {
        friend Unknown3DEngine;
    public:
        explicit UnknownRenderer(const RenderConfig &config);

        ~UnknownRenderer();

        /// OffScreen render, return the texture id after rendering
        /// \return Texture ID
        uint16_t Render();

    private:
        /// Configuration for rendering
        RenderConfig render_config_;
        /// Context for rendering
        SMART_PTR<RenderContext> render_context_;
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_UNKNOWNRENDERER_H
