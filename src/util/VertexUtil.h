//
// Created by Scave on 2024/2/24.
//

#ifndef RIDER3D_VERTEXUTIL_H
#define RIDER3D_VERTEXUTIL_H

#include "Define.h"
#include "BasicComponents.h"

NS_RIDER_BEGIN

    class VertexUtil {
    public:
        static void BuildRectangle(Vertices& vertices,
                                       float width, float height, Color color = kDefaultRectColor);

        static void BuildTriangle(Vertices& vertices,
                                       Vec3 p1, Vec3 p2, Vec3 p3, Color color = kDefaultRectColor);

        static void BuildBox(Vertices& vertices,
                             float width, float height, float depth, Color colors[6] = const_cast<Color*>(kDefaultBoxColors));

        static void BuildSphere(Vertices& vertices,
                                UInt16 row_count, UInt16 row_height, float radius);

        static void BuildSkyBox(Vertices& vertices, float size, float quality);

        static void BuildCapsule(Vertices& vertices, float radius, float length);

        static void BuildCylinder(Vertices& vertices,
                                      float radius_outer, float radius_inner, float height, int segs);

        static void BuildTorus(Vertices& vertices,
                                   float large_radius, float small_radius, int segments_w, int segments_h);

        static void BuildTriangularPyramid(Vertices& vertices, Vec3 shape[4], Color color[4] = const_cast<Color*>(kDefaultTriangularPyramidColor));
    private:
        const static Color kDefaultRectColor;
        const static Color kDefaultBoxColors[6];
        const static Color kDefaultTriangularPyramidColor[4];
    };

NS_RIDER_END

#endif //RIDER3D_VERTEXUTIL_H
