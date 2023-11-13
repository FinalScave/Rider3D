//
// Created by Scave on 2023/11/9.
//

#include "RenderContext.h"
#include "bgfx/BgfxUtil.h"

UNKNOWN_NS_BEGIN

    RenderContext::RenderContext(const RenderConfig& config) : curr_view_id_(0), main_view_id_(0) {
        this->handle_manager_ = MAKE_SMART_PTR<BufferHandleManager>();
        this->render_config_ = config;
    }

    RenderContext::~RenderContext() {
        handle_manager_ = nullptr;
    }

    BufferHandle& RenderContext::CreateOrUpdateBuffer(const Name& name,
                                                      bgfx::VertexLayout& vertex_layout,
                                                      std::vector<Vertex*>& vertex_list,
                                                      std::vector<uint32_t>& index_list) {
        return handle_manager_->CreateOrUpdate(name, vertex_layout, vertex_list, index_list);
    }

    BufferHandle& RenderContext::GetBufferHandle(const Name& name) {
        return handle_manager_->GetBufferHandle(name);
    }

    void RenderContext::PutBufferHandle(const Name& name, const BufferHandle& handle) {
        handle_manager_->PutBufferHandle(name, handle);
    }

UNKNOWN_NS_END
