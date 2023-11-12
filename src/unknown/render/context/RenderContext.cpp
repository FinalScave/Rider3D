//
// Created by Scave on 2023/11/9.
//

#include "RenderContext.h"
#include "bgfx/BgfxUtil.h"
#include "shader/vs_common.h"
#include "shader/fs_common.h"

UNKNOWN_NS_BEGIN

    RenderContext::RenderContext(const RenderConfig& config): main_view_id_(0) {
        this->handle_manager_ = MAKE_SMART_PTR<BufferHandleManager>();
        this->common_program_ = loadProgramFromData(VS_COMMON, VS_BIN_COUNT, FS_COMMON, FS_BIN_COUNT);
        this->u_resolution_ = bgfx::createUniform("u_resolution", bgfx::UniformType::Enum::Vec4);
        this->vec4_resolution_ = new uint16_t[4]{config.width, config.height, 0, 0};
    }

    RenderContext::~RenderContext() {
        DESTROY_MEMBER_BGFX_HANDLE(common_program_);
        DESTROY_MEMBER_BGFX_HANDLE(u_resolution_);
        DELETE_ARRAY(vec4_resolution_);
    }

    BufferHandle& RenderContext::CreateOrUpdateBuffer(const Name& name, std::vector<Vertex*>& vertex_list,
                                                      std::vector<uint32_t>& index_list) {
        return handle_manager_->CreateOrUpdate(name, vertex_list, index_list);
    }

    BufferHandle& RenderContext::GetBufferHandle(const Name& name) {
        return handle_manager_->GetBufferHandle(name);
    }

    void RenderContext::PutBufferHandle(const Name& name, const BufferHandle& handle) {
        handle_manager_->PutBufferHandle(name, handle);
    }

UNKNOWN_NS_END
