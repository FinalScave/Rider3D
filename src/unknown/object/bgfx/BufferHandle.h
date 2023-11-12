//
// Created by Scave on 2023/11/12.
//

#ifndef UNKNOWN3D_BUFFERHANDLE_H
#define UNKNOWN3D_BUFFERHANDLE_H

#include "Define.h"
#include "bgfx/bgfx.h"
#include "object/Vertex.h"

UNKNOWN_NS_BEGIN

    struct BufferHandle {
        bgfx::DynamicVertexBufferHandle vertex_buffer_handle = BGFX_INVALID_HANDLE;
        bgfx::DynamicIndexBufferHandle index_buffer_handle = BGFX_INVALID_HANDLE;
    };

    class BufferHandleManager {
    public:
        BufferHandle&
        CreateOrUpdate(const Name& name, std::vector<Vertex*>& vertex_list, std::vector<uint32_t>& index_list);

        BufferHandle& GetBufferHandle(const Name& name);

        void PutBufferHandle(const Name& name, const BufferHandle& handle);

    private:
        HashMap<Name, BufferHandle> name_buffer_handle_map_;
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_BUFFERHANDLE_H
