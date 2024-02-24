//
// Created by Scave on 2023/11/13.
//

#ifndef UNKNOWN3D_ENTITYRENDERER_H
#define UNKNOWN3D_ENTITYRENDERER_H

#include "Define.h"
#include "shader/Shader.h"
#include "shader/ShaderProgram.h"
#include "context/RenderContext.h"

UNKNOWN_NS_BEGIN

    class EntityRenderer {
    public:
        explicit EntityRenderer(const SMART_PTR<RenderContext>& context);

        virtual void RenderEntity(Entity& entity) = 0;

    protected:
        SMART_PTR<RenderContext> context_;
        SMART_PTR<ShaderProgram> program_;
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_ENTITYRENDERER_H
