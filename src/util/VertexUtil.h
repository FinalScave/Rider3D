//
// Created by Scave on 2024/2/24.
//

#ifndef UNKNOWN3D_VERTEXUTIL_H
#define UNKNOWN3D_VERTEXUTIL_H
#include "Define.h"
#include "Vertex.h"

UNKNOWN_NS_BEGIN

    class VertexUtil {
    public:
        static Vertices* BuildRectangle(float width, float height);

        static Vertices* BuildBox(float width, float height, float depth);

        static Vertices* BuildSphere(uint16_t row_count, uint16_t row_height, float radius);
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_VERTEXUTIL_H
