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
        static Vertices BuildRectangle(float width, float height, Color color = kDefaultRectColor);

        static Vertices BuildBox(
                float width, float height, float depth, Color colors[6] = const_cast<Color*>(kDefaultBoxColors));

        static Vertices BuildSphere(uint16_t row_count, uint16_t row_height, float radius);
    private:
        const static Color kDefaultRectColor;
        const static Color kDefaultBoxColors[6];
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_VERTEXUTIL_H
