//
// Created by Scave on 2023/11/12.
//

#ifndef UNKNOWN3D_BUFFERHANDLE_H
#define UNKNOWN3D_BUFFERHANDLE_H

#include "Define.h"
#include "bgfx/bgfx.h"
#include "Vertex.h"
#include "entityx/Entity.h"

UNKNOWN_NS_BEGIN

    struct BufferHandle {
        Vertex* vertices = nullptr;
        uint16_t* indices = nullptr;
        bgfx::DynamicVertexBufferHandle vertex_buffer = BGFX_INVALID_HANDLE;
        bgfx::DynamicIndexBufferHandle index_buffer = BGFX_INVALID_HANDLE;
    };

    class BufferHandleManager {
    public:
        BufferHandle* CreateOrUpdate(const Entity& entity,
                                     bgfx::VertexLayout& vertex_layout,
                                     std::vector<Vertex>& vertex_list,
                                     std::vector<uint32_t>& index_list);

        BufferHandle* GetBufferHandle(const Entity& entity);

        void PutBufferHandle(const Entity& entity, BufferHandle* handle);

    private:
        HASHMAP<Entity, BufferHandle*> name_buffer_handle_map_;
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_BUFFERHANDLE_H
