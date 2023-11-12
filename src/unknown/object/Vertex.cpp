//
// Created by Scave on 2023/11/9.
//

#include "Vertex.h"

UNKNOWN_NS_BEGIN

    Vertex::~Vertex() {
        DELETE_PTR(position);
        DELETE_PTR(uv);
        DELETE_PTR(color);
    }

    Vertices::~Vertices() {
        for (auto& vertex: vertex_data_list) {
            DELETE_PTR(vertex);
        }
        vertex_data_list.clear();
    }

    void Vertices::AddVertex(Vertex* vertex) {
        vertex_data_list.push_back(vertex);
    }

    void Vertices::AddIndex(uint32_t index) {
        vertex_index_list.push_back(index);
    }

    void Vertices::AddFace(Vertex* upper_left, Vertex* upper_right, Vertex* lower_right, Vertex* lower_left) {
        // add vertex data
        vertex_data_list.push_back(upper_left);
        vertex_data_list.push_back(upper_right);
        vertex_data_list.push_back(lower_right);
        vertex_data_list.push_back(lower_left);
        // add vertex indices,2 triangles have 6 vertices,so there is 6 indices
        uint32_t index1 = vertex_index_list.size();
        uint32_t index2 = index1 + 1;
        uint32_t index3 = index2 + 1;
        uint32_t index4 = index3 + 1;
        // first triangle
        vertex_index_list.push_back(index1);
        vertex_index_list.push_back(index2);
        vertex_index_list.push_back(index3);
        // second triangle
        vertex_index_list.push_back(index1);
        vertex_index_list.push_back(index4);
        vertex_index_list.push_back(index3);
    }

    void Vertices::SetVertices(uint16_t vertices_count, Vertex** vertices) {
        for (auto vertex: vertex_data_list) {
            DELETE_PTR(vertex);
        }
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


    bgfx::VertexLayout DefaultVertexLayout::default_vertex_layout_;

    void DefaultVertexLayout::Init() {
        default_vertex_layout_
                .begin()
                .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
                .add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float)
                .add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Float)
                .end();
    }

    bgfx::VertexLayout DefaultVertexLayout::Get() {
        return default_vertex_layout_;
    }

    bgfx::VertexBufferHandle DefaultBgfxHandles::default_vertex_buffer_handle_;
    bgfx::IndexBufferHandle DefaultBgfxHandles::default_index_buffer_handle_;

    void DefaultBgfxHandles::Init() {
        default_vertex_buffer_handle_ = bgfx::createVertexBuffer(
                bgfx::makeRef(kDefaultVertices, sizeof(Vertex) * kDefaultVertexCount),
                DefaultVertexLayout::Get()
        );
        default_index_buffer_handle_ = bgfx::createIndexBuffer(
                bgfx::makeRef(kDefaultIndices, sizeof(Vertex) * kDefaultIndexCount)
        );
    }

    void DefaultBgfxHandles::Destroy() {
        DESTROY_MEMBER_BGFX_HANDLE(default_vertex_buffer_handle_);
        DESTROY_MEMBER_BGFX_HANDLE(default_index_buffer_handle_);
    }

    bgfx::VertexBufferHandle DefaultBgfxHandles::GetVertexBufferHandle() {
        return default_vertex_buffer_handle_;
    }

    bgfx::IndexBufferHandle DefaultBgfxHandles::GetIndexBufferHandle() {
        return default_index_buffer_handle_;
    }

UNKNOWN_NS_END
