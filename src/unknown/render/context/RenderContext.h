//
// Created by Scave on 2023/11/9.
//

#ifndef UNKNOWN3D_RENDERCONTEXT_H
#define UNKNOWN3D_RENDERCONTEXT_H

#include "Define.h"
#include "bgfx/bgfx.h"
#include "object/Scene.h"
#include "object/bgfx/BufferHandle.h"
#include "render/config/RenderConfig.h"

UNKNOWN_NS_BEGIN

    class UnknownRenderer;

    class RenderContext {
        friend UnknownRenderer;
    public:
        explicit RenderContext(const RenderConfig& config);
        ~RenderContext();

        BufferHandle&
        CreateOrUpdateBuffer(const Name& name, std::vector<Vertex*>& vertex_list, std::vector<uint32_t>& index_list);

        BufferHandle& GetBufferHandle(const Name& name);

        void PutBufferHandle(const Name& name, const BufferHandle& handle);
    private:
        uint16_t main_view_id_;
        SMART_PTR<Scene> scene_;
        SMART_PTR<BufferHandleManager> handle_manager_;

        bgfx::ProgramHandle common_program_ = BGFX_INVALID_HANDLE;
        bgfx::UniformHandle u_resolution_ = BGFX_INVALID_HANDLE;
        uint16_t* vec4_resolution_;
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_RENDERCONTEXT_H
