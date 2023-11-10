//
// Created by Scave on 2023/11/9.
//

#ifndef UNKNOWN3D_OBJECT3D_H
#define UNKNOWN3D_OBJECT3D_H

#include <vector>
#include "Define.h"
#include "Supposition.h"
#include "Vertex.h"

UNKNOWN_NS_BEGIN

    enum RenderType {
        POINTS = 0,
        LINES = 1,
        LINESTRIP = 2,
        TRISTRIP = 3
    };

    struct Object3D {
        ~Object3D();

        RenderType render_type = TRISTRIP;
        NdcPoint* position = nullptr;
        NdcPoint* rotation = nullptr;
        NdcPoint* scale = nullptr;
        Vertices* vertices;
    };

    struct Object3DContainer {
        void AddChild(Object3D& object);

        void AddChildAt(uint8_t index, Object3D& object);

        void RemoveChild(Object3D& object);

        void RemoveChildAt(uint8_t index);

        uint8_t Size();
    private:
        std::vector<Object3D> child_list;
    };

    struct Box : Object3D  {
        float width;
        float height;
        float depth;
    };

    struct Sphere : Object3D {
        uint16_t row_count;
        uint16_t column_count;
        float radius;

        void Build();
    };

UNKNOWN_NS_END
#endif //UNKNOWN3D_OBJECT3D_H
