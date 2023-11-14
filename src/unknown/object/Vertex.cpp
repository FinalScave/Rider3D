//
// Created by Scave on 2023/11/9.
//

#include "Vertex.h"

UNKNOWN_NS_BEGIN

    Vertices::~Vertices() {
        vertex_data_list.clear();
    }

    void Vertices::AddVertex(Vertex& vertex) {
        vertex_data_list.push_back(vertex);
    }

    void Vertices::AddIndex(uint32_t index) {
        vertex_index_list.push_back(index);
    }

    void Vertices::AddFace(Vertex& upper_left, Vertex& upper_right, Vertex& lower_right, Vertex& lower_left) {
        // add vertex data
        vertex_data_list.push_back(upper_left);
        vertex_data_list.push_back(upper_right);
        vertex_data_list.push_back(lower_right);
        vertex_data_list.push_back(lower_left);
        // add vertex indices,2 triangles have 6 vertices,so there is 6 indices
        uint32_t index1 = vertex_index_list.size();
        uint32_t index2 = index1 + 1;
        uint32_t index3 = index1 + 2;
        uint32_t index4 = index1 + 3;
        // first triangle
        vertex_index_list.push_back(index1);
        vertex_index_list.push_back(index4);
        vertex_index_list.push_back(index3);
        // second triangle
        vertex_index_list.push_back(index1);
        vertex_index_list.push_back(index3);
        vertex_index_list.push_back(index2);
    }

    void Vertices::SetVertices(uint16_t vertices_count, Vertex*& vertices) {
        vertex_data_list.clear();
        for (uint16_t i = 0; i < vertices_count; ++i) {
            vertex_data_list.push_back(vertices[i]);
        }
    }

    uint16_t Vertices::VertexSize() const {
        return vertex_data_list.size();
    }

    uint32_t Vertices::IndexSize() const {
        return vertex_index_list.size();
    }

    VerticesManager::VerticesManager() = default;

    VerticesManager::~VerticesManager() = default;

UNKNOWN_NS_END
