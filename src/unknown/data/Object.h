//
// Created by Scave on 2023/11/9.
//

#ifndef UNKNOWN3D_OBJECT_H
#define UNKNOWN3D_OBJECT_H

#include <vector>
#include "Define.h"
#include "Supposition.h"
#include "Vertex.h"

UNKNOWN_NS_BEGIN

    enum RenderType {
        POINTS,
        LINES,
        LINESTRIP,
        TRISTRIP
    };

    struct Object {
        RenderType render_type = TRISTRIP;
        NdcPoint position = {0, 0, 0};
        NdcPoint rotation = {0, 0, 0};
        NdcPoint scale = {1, 1, 1};
        Vertices vertices;
    };

    struct ObjectContainer {
        void AddChild(Object& object);

        void AddChildAt(uint8_t index, Object& object);

        void RemoveChild(Object& object);

        void RemoveChildAt(uint8_t index);

        uint8_t Size();
    private:
        std::vector<Object> child_list;
    };

    struct Box : Object  {
        float width;
        float height;
        float depth;
    };

    struct Sphere : Object {
        uint16_t row_count;
        uint16_t column_count;
        float radius;

        void Build();
    };

UNKNOWN_NS_END
#endif //UNKNOWN3D_OBJECT_H
