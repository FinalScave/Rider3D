//
// Created by Scave on 2023/11/13.
//

#ifndef UNKNOWN3D_RENDERSTRATEGY_H
#define UNKNOWN3D_RENDERSTRATEGY_H

#include "Define.h"
#include "shader/Shader.h"
#include "shader/ShaderProgram.h"
#include "object/Object3D.h"
#include "render/context/RenderContext.h"

UNKNOWN_NS_BEGIN

    class RenderStrategy {
    public:
        explicit RenderStrategy(const SMART_PTR<RenderContext>& context);

        virtual void RenderObject(Object3D& object) = 0;

    protected:
        SMART_PTR<RenderContext> context_;
        SMART_PTR<ShaderProgram> program_;
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_RENDERSTRATEGY_H
