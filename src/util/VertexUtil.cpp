//
// Created by Scave on 2024/2/24.
//

#include "VertexUtil.h"

UNKNOWN_NS_BEGIN

    Vertices* VertexUtil::BuildRectangle(float width, float height) {
        Color color = {0xff, 0xff, 0xff, 0xff};
        Vertex v1 = {{0, 0, 0}, {0, 0}, color};
        Vertex v2 = {{width, 0, 0}, {1, 0}, color};
        Vertex v3 = {{width, height, 0}, {1, 1}, color};
        Vertex v4 = {{0, height, 0}, {0, 1}, color};
        Vertices* vertices = new Vertices;
        vertices->AddFace(v1, v2, v3, v4);
        return vertices;
    }

    Vertices* VertexUtil::BuildBox(float width, float height, float depth) {
        Vertices* vertices = new Vertices;
        float w = width / 2.f;
        float h = height / 2.f;
        float d = depth / 2.f;

        Color color = {1.0, 1.0, 1.0, 1.0};
        // front
        Vertex front_v1 = {{-w, +h, +d}, {0, 0}, color};
        Vertex front_v2 = {{+w, +h, +d}, {1, 0}, color};
        Vertex front_v3 = {{+w, -h, +d}, {1, 1}, color};
        Vertex front_v4 = {{-w, -h, +d}, {0, 1}, color};
        vertices->AddFace(front_v1, front_v2, front_v3, front_v4);
        // right
        Vertex right_v1 = {{+w, +h, +d}, {0, 0}, color};
        Vertex right_v2 = {{+w, +h, -d}, {1, 0}, color};
        Vertex right_v3 = {{+w, -h, -d}, {1, 1}, color};
        Vertex right_v4 = {{+w, -h, +d}, {0, 1}, color};
        vertices->AddFace(right_v1, right_v2, right_v3, right_v4);
        // back
        Vertex back_v1 = {{+w, +h, -d}, {0, 0}, color};
        Vertex back_v2 = {{-w, +h, -d}, {1, 0}, color};
        Vertex back_v3 = {{-w, -h, -d}, {1, 1}, color};
        Vertex back_v4 = {{+w, -h, -d}, {0, 1}, color};
        vertices->AddFace(back_v1, back_v2, back_v3, back_v4);
        // left
        Vertex left_v1 = {{-w, +h, -d}, {0, 0}, color};
        Vertex left_v2 = {{-w, +h, +d}, {1, 0}, color};
        Vertex left_v3 = {{-w, -h, +d}, {1, 1}, color};
        Vertex left_v4 = {{-w, -h, -d}, {0, 1}, color};
        vertices->AddFace(left_v1, left_v2, left_v3, left_v4);
        // top
        Vertex top_v1 = {{-w, +h, -d}, {0, 0}, color};
        Vertex top_v2 = {{+w, +h, -d}, {1, 0}, color};
        Vertex top_v3 = {{+w, +h, +d}, {1, 1}, color};
        Vertex top_v4 = {{-w, +h, +d}, {0, 1}, color};
        vertices->AddFace(top_v1, top_v2, top_v3, top_v4);
        // bottom
        Vertex bottom_v1 = {{-w, -h, +d}, {0, 0}, color};
        Vertex bottom_v2 = {{+w, -h, +d}, {1, 0}, color};
        Vertex bottom_v3 = {{+w, -h, -d}, {1, 1}, color};
        Vertex bottom_v4 = {{-w, -h, -d}, {0, 1}, color};
        vertices->AddFace(bottom_v1, bottom_v2, bottom_v3, bottom_v4);
        return vertices;
    }

    Vertices* VertexUtil::BuildSphere(uint16_t row_count, uint16_t row_height, float radius) {
        return nullptr;
    }

UNKNOWN_NS_END
