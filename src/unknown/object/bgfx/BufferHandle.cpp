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

    BufferHandle& BufferHandleManager::CreateOrUpdate(const Name& name, std::vector<Vertex*>& vertex_list,
                                                      std::vector<uint32_t>& index_list) {
        Vertex** vertex_arr = vertex_list.data();
        uint32_t* index_arr = index_list.data();
        auto vertex_ref = bgfx::makeRef(
                vertex_arr,
                sizeof(Vertex) * vertex_list.size()
        );
        auto index_ref = bgfx::makeRef(
                index_arr,
                sizeof(uint32_t) * index_list.size()
        );
        if (name_buffer_handle_map_.find(name) == name_buffer_handle_map_.end()) {
            bgfx::DynamicVertexBufferHandle vertex_buffer = bgfx::createDynamicVertexBuffer(
                    vertex_ref,
                    DefaultVertexLayout::Get()
            );
            bgfx::DynamicIndexBufferHandle index_buffer = bgfx::createDynamicIndexBuffer(index_ref);
            BufferHandle handle = {vertex_buffer, index_buffer};
            PutBufferHandle(name, handle);
    
            return name_buffer_handle_map_[name];
        } else {
            BufferHandle& exists = name_buffer_handle_map_[name];
            bgfx::update(exists.vertex_buffer_handle, 0, vertex_ref);
            bgfx::update(exists.index_buffer_handle, 0, index_ref);
            return exists;
        }
    }

UNKNOWN_NS_END