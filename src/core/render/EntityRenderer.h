//
// Created by Scave on 2023/11/13.
//

#ifndef RIDER3D_ENTITYRENDERER_H
#define RIDER3D_ENTITYRENDERER_H

#include "Define.h"
#include "shader/Shader.h"
#include "shader/ShaderProgram.h"
#include "context/RenderContext.h"

NS_RIDER_BEGIN

    class EntityRenderer {
    public:
        explicit EntityRenderer(const SMART_PTR<RenderContext>& context);

        virtual void RenderEntity(Entity& entity) = 0;

    protected:
        SMART_PTR<RenderContext> context_;
        SMART_PTR<ShaderProgram> program_;
    };

NS_RIDER_END

#endif //RIDER3D_ENTITYRENDERER_H
