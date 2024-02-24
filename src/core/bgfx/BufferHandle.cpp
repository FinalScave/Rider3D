//
// Created by Scave on 2023/11/12.
//

#include "BufferHandle.h"

UNKNOWN_NS_BEGIN

    BufferHandle& BufferHandleManager::GetBufferHandle(const Name& name) {
        return name_buffer_handle_map_[name];
    }

    void BufferHandleManager::PutBufferHandle(const Name& name, const BufferHandle& handle) {
        name_buffer_handle_map_[name] = handle;
    }

    BufferHandle& BufferHandleManager::CreateOrUpdate(const Name& name,
                                                      bgfx::VertexLayout& vertex_layout,
                                                      std::vector<Vertex>& vertex_list,
                                                      std::vector<uint32_t>& index_list) {
        if (name_buffer_handle_map_.find(name) == name_buffer_handle_map_.end()) {
            Vertex vertices[vertex_list.size()];
            uint16_t indices[index_list.size()];
            for (int i = 0; i < vertex_list.size(); ++i) {
                vertices[i] = vertex_list[i];
            }
            for (int i = 0; i < index_list.size(); ++i) {
                indices[i] = index_list[i];
            }
            auto vertex_ref = bgfx::makeRef(
                    vertices,
                    sizeof(Vertex) * vertex_list.size()
            );
            auto index_ref = bgfx::makeRef(
                    indices,
                    sizeof(uint32_t) * index_list.size()
            );
            bgfx::DynamicVertexBufferHandle vertex_buffer =
                    bgfx::createDynamicVertexBuffer(vertex_ref,vertex_layout);
            bgfx::DynamicIndexBufferHandle index_buffer = bgfx::createDynamicIndexBuffer(index_ref);
            BufferHandle handle = {vertices, indices, vertex_buffer, index_buffer};
            PutBufferHandle(name, handle);
            return name_buffer_handle_map_[name];
        } else {
            //暂时不做顶点更新
            BufferHandle& exists = name_buffer_handle_map_[name];
            /*DELETE_ARRAY(exists.vertices);
            DELETE_ARRAY(exists.indices);
            exists.vertices = vertices;
            exists.indices = indices;
            bgfx::update(exists.vertex_buffer, 0, vertex_ref);
            bgfx::update(exists.index_buffer, 0, index_ref);*/
            return exists;
        }
    }

UNKNOWN_NS_END