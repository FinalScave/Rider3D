//
// Created by Scave on 2023/11/8.
//

#ifndef UNKNOWN3D_UNKNOWN3DENGINE_H
#define UNKNOWN3D_UNKNOWN3DENGINE_H

#include "Define.h"
#include "render/UnknownRenderer.h"
#include "object/Object3D.h"

UNKNOWN_NS_BEGIN

    class Unknown3DEngine {
    public:
        Unknown3DEngine(const RenderConfig &config);
        ~Unknown3DEngine();

        //void AddVertices(uint32_t num_vertices, ScreenPoint* vertices);

        //void SetVertices(uint32_t num_vertices, ScreenPoint* vertices);

        uint16_t Render();

        RenderConfig GetRenderConfig();
    private:
        SMART_PTR<UnknownRenderer> renderer_;

    };

UNKNOWN_NS_END // unknown

#endif //UNKNOWN3D_UNKNOWN3DENGINE_H
