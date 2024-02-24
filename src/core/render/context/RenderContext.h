//
// Created by Scave on 2023/11/9.
//

#ifndef UNKNOWN3D_RENDERCONTEXT_H
#define UNKNOWN3D_RENDERCONTEXT_H

#include "Define.h"
#include "bgfx/bgfx.h"
#include "Scene.h"
#include "bgfx/BufferHandle.h"
#include "render/config/RenderConfig.h"

UNKNOWN_NS_BEGIN

    class SceneRenderer;

    class RenderContext {
        friend SceneRenderer;
    public:
        explicit RenderContext(const RenderConfig& config);

        ~RenderContext();

        BufferHandle* CreateOrUpdateBuffer(const Entity& entity,
                                           bgfx::VertexLayout& vertex_layout,
                                           std::vector<Vertex>& vertex_list,
                                           std::vector<uint32_t>& index_list);

        BufferHandle* GetBufferHandle(const Entity& entity);

        void PutBufferHandle(const Entity& entity, BufferHandle* handle);

        RenderConfig render_config_;
        uint16_t curr_view_id_;
        Scene* scene_ = nullptr;
    private:
        uint16_t main_view_id_;
        SMART_PTR<BufferHandleManager> handle_manager_;
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_RENDERCONTEXT_H
