//
// Created by Scave on 2023/11/9.
//

#include "RenderContext.h"
#include "bgfx/BgfxUtil.h"

NS_RIDER_BEGIN

    RenderContext::RenderContext(const RenderConfig& config) : curr_view_id_(0), main_view_id_(0) {
        this->handle_manager_ = MAKE_SMART_PTR<BufferHandleManager>();
        this->render_config_ = config;
    }

    RenderContext::~RenderContext() {
        handle_manager_ = nullptr;
    }

    BufferHandle* RenderContext::CreateOrUpdateBuffer(const Entity& entity,
                                                      bgfx::VertexLayout& vertex_layout,
                                                      std::vector<Vertex>& vertex_list,
                                                      std::vector<uint32_t>& index_list) {
        return handle_manager_->CreateOrUpdate(entity, vertex_layout, vertex_list, index_list);
    }

    BufferHandle* RenderContext::GetBufferHandle(const Entity& entity) {
        return handle_manager_->GetBufferHandle(entity);
    }

    void RenderContext::PutBufferHandle(const Entity& entity, BufferHandle* handle) {
        handle_manager_->PutBufferHandle(entity, handle);
    }

NS_RIDER_END
