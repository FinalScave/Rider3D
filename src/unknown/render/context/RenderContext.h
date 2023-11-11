//
// Created by Scave on 2023/11/9.
//

#ifndef UNKNOWN3D_RENDERCONTEXT_H
#define UNKNOWN3D_RENDERCONTEXT_H

#include "Define.h"
#include "bgfx/bgfx.h"
#include "object/Scene.h"

UNKNOWN_NS_BEGIN

    class UnknownRenderer;

    class RenderContext {
        friend UnknownRenderer;
    public:

    private:
        uint16_t main_view_id_;
        SMART_PTR<Scene> scene_;
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_RENDERCONTEXT_H
