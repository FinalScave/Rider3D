//
// Created by Scave on 2024/2/24.
//

#include "VertexUtil.h"

NS_RIDER_BEGIN
    const Color VertexUtil::kDefaultRectColor = {1, 1, 1, 1};
    const Color VertexUtil::kDefaultBoxColors[6] = {
            Colors::Red, Colors::Green, Colors::Blue,
            Colors::Orange, Colors::Purple, Colors::Cyan
    };
    const Color VertexUtil::kDefaultTriangularPyramidColor[4] = {
            Colors::Blue, Colors::Red,
            Colors::Orange, Colors::Purple
    };

    void VertexUtil::BuildRectangle(Vertices& vertices, float width, float height, Color color) {
        float w = width / 2.f;
        float h = height / 2.f;
        Vertex v1 = {{-w, h, 0}, {0, 1}, color};
        Vertex v2 = {{w, h, 0}, {1, 1}, color};
        Vertex v3 = {{w, -h, 0}, {1, 0}, color};
        Vertex v4 = {{-w, -h, 0}, {0, 0}, color};
        vertices.AddQuad(v1, v2, v3, v4);
    }

    void VertexUtil::BuildTriangle(Vertices& vertices, float width, float height, Color color) {
        float w = width / 2.f;
        float h = height / 2.f;
        Vertex v1 = {{0, h, 0}, {0.5, 1}, color};
        Vertex v2 = {{-w, -h, 0}, {0, 0}, color};
        Vertex v3 = {{w, -h, 0}, {1, 0}, color};
        vertices.AddFace(v1, v2, v3);
    }

    void VertexUtil::BuildBox(Vertices& vertices, float width, float height, float depth, Color colors[6]) {
        float w = width / 2.f;
        float h = height / 2.f;
        float d = depth / 2.f;

        // front
        Color color = colors[0];
        Vertex front_v1 = {{+w, +h, +d}, {0, 1}, color};
        Vertex front_v2 = {{-w, +h, +d}, {1, 1}, color};
        Vertex front_v3 = {{-w, -h, +d}, {1, 0}, color};
        Vertex front_v4 = {{+w, -h, +d}, {0, 0}, color};
        vertices.AddQuad(front_v1, front_v2, front_v3, front_v4);
        // right
        color = colors[1];
        Vertex right_v1 = {{-w, +h, +d}, {0, 1}, color};
        Vertex right_v2 = {{-w, +h, -d}, {1, 1}, color};
        Vertex right_v3 = {{-w, -h, -d}, {1, 0}, color};
        Vertex right_v4 = {{-w, -h, +d}, {0, 0}, color};
        vertices.AddQuad(right_v1, right_v2, right_v3, right_v4);
        // back
        color = colors[2];
        Vertex back_v1 = {{+w, +h, -d}, {0, 1}, color};
        Vertex back_v2 = {{-w, +h, -d}, {1, 1}, color};
        Vertex back_v3 = {{-w, -h, -d}, {1, 0}, color};
        Vertex back_v4 = {{+w, -h, -d}, {0, 0}, color};
        vertices.AddQuad(back_v1, back_v2, back_v3, back_v4);
        // left
        color = colors[3];
        Vertex left_v1 = {{+w, +h, -d}, {0, 1}, color};
        Vertex left_v2 = {{+w, +h, +d}, {1, 0}, color};
        Vertex left_v3 = {{+w, -h, +d}, {1, 1}, color};
        Vertex left_v4 = {{+w, -h, -d}, {0, 0}, color};
        vertices.AddQuad(left_v1, left_v2, left_v3, left_v4);
        // top
        color = colors[4];
        Vertex top_v1 = {{+w, +h, -d}, {0, 1}, color};
        Vertex top_v2 = {{-w, +h, -d}, {1, 0}, color};
        Vertex top_v3 = {{-w, +h, +d}, {1, 1}, color};
        Vertex top_v4 = {{+w, +h, +d}, {0, 0}, color};
        vertices.AddQuad(top_v1, top_v2, top_v3, top_v4);
        // bottom
        color = colors[5];
        Vertex bottom_v1 = {{+w, -h, -d}, {0, 1}, color};
        Vertex bottom_v2 = {{-w, -h, -d}, {1, 0}, color};
        Vertex bottom_v3 = {{-w, -h, +d}, {1, 1}, color};
        Vertex bottom_v4 = {{+w, -h, +d}, {0, 0}, color};
        vertices.AddQuad(bottom_v1, bottom_v2, bottom_v3, bottom_v4);
    }

    void VertexUtil::BuildSphere(Vertices& vertices, uint16_t row_count, uint16_t row_height, float radius) {

    }

    void VertexUtil::BuildSkyBox(Vertices& vertices, float size, float quality) {

    }

    void VertexUtil::BuildCapsule(Vertices& vertices, float radius, float length) {

    }

    void VertexUtil::BuildCylinder(Vertices& vertices,
                                   float radius_outer, float radius_inner, float height, int segs) {

    }

    void VertexUtil::BuildTorus(Vertices& vertices,
                                float large_radius, float small_radius, int segments_w, int segments_h) {

    }
    void VertexUtil::BuildTriangularPyramid(Vertices& vertices,
                                            float width, float height, float depth, Color color[4]) {
        float w = width / 2.f;
        float h = height / 2.f;
        float d = depth / 2.f;
        Vertex bottom_left = {{+w, -h, -d}, {0, 0}, color[0]};
        Vertex bottom_right = {{-w, -h, -d}, {0, 0}, color[1]};
        Vertex bottom_front = {{0, -h, +d}, {0, 0}, color[2]};
        Vertex top = {{0, +h, 0}, {0, 0}, color[3]};
        vertices.AddFace(bottom_left, bottom_front, bottom_right);//bottom
        vertices.AddFace(bottom_left, bottom_right, top);//back
        vertices.AddFace(top, bottom_front, bottom_left);//left
        vertices.AddFace(top, bottom_front, bottom_right);//right
    }
NS_RIDER_END
