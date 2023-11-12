//
// Created by Scave on 2023/11/8.
//

#include "UnknownRenderer.h"
#include "bgfx/bgfx.h"
#include "bx/math.h"

UNKNOWN_NS_BEGIN

    UnknownRenderer::UnknownRenderer(const RenderConfig& config) {
        this->render_config_ = config;
        // initialize bgfx
        bgfx::Init init;
#if (defined(WINDOWS))
        init.type = bgfx::RendererType::Enum::OpenGL;
#elif (defined(ANDROID))
        init.type = bgfx::RendererType::Enum::OpenGLES;
#elif (defined(IOS) || defined(MACOS))
        init.type = bgfx::RendererType::Enum::Metal;
#else
        init.type = bgfx::RendererType::Enum::Count;
#endif
        init.vendorId = BGFX_PCI_ID_NONE;
        bgfx::Resolution resolution;
        resolution.width = config.width;
        resolution.height = config.height;
        resolution.reset = BGFX_RESET_VSYNC;
        init.resolution = resolution;
        bgfx::PlatformData platform_data;
        platform_data.context = nullptr;
        platform_data.backBuffer = nullptr;
        platform_data.backBufferDS = nullptr;
        platform_data.ndt = nullptr;
        if (config.native_window_handle != nullptr) {
            platform_data.nwh = config.native_window_handle;
        }
        init.platformData = platform_data;
        bgfx::init(init);
        bgfx::reset(config.width, config.height, BGFX_RESET_VSYNC, init.resolution.format);
        // initialize something defaults
        DefaultVertexLayout::Init();
        DefaultBgfxHandles::Init();

        // initialize context
        this->render_context_ = MAKE_SMART_PTR<RenderContext>(config);
    }

    UnknownRenderer::~UnknownRenderer() {
        render_context_ = nullptr;
        DefaultBgfxHandles::Destroy();
        bgfx::shutdown();
    }

    void UnknownRenderer::SetScene(const SMART_PTR<Scene>& scene) {
        render_context_->scene_ = scene;
    }

    uint16_t UnknownRenderer::Render() {
        bgfx::setViewRect(render_context_->main_view_id_, 0, 0, render_config_.width, render_config_.height);
        bgfx::setViewClear(render_context_->main_view_id_, BGFX_CLEAR_DEPTH | BGFX_CLEAR_COLOR, 0x000000ff);

        this->RenderScene();
        
        bgfx::frame();
        return render_context_->main_view_id_;
    }

    void UnknownRenderer::RenderScene() {
        uint8_t size = render_context_->scene_->Size();
        for (uint8_t i = 0; i < size; ++i) {
            Object3D& object = render_context_->scene_->GetChildAt(i);
            this->RenderObject(object, i);
        }
    }

    void UnknownRenderer::RenderObject(Object3D& object, uint8_t id) {
        if (!object.visible) {
            return;
        }
        BufferHandle& handle = render_context_->CreateOrUpdateBuffer(
                object.GetName(),
                object.vertices->vertex_data_list,
                object.vertices->vertex_index_list
        );
        uint8_t view_id = id + 1;
        //bgfx::setViewRect(view_id, 0, 0, render_config_.width, render_config_.height);
        bgfx::setViewRect(view_id, 0, 0, 50, 50);
        bgfx::setViewClear(view_id, BGFX_CLEAR_DEPTH | BGFX_CLEAR_COLOR, 0x0000ffff);
        bgfx::touch(view_id);
        bgfx::setVertexBuffer(0, handle.vertex_buffer_handle);
        bgfx::setIndexBuffer(handle.index_buffer_handle);
        bgfx::setViewFrameBuffer(0, BGFX_INVALID_HANDLE);
        bgfx::setState(BGFX_STATE_WRITE_RGB | BGFX_STATE_BLEND_ALPHA);
        bgfx::setUniform(render_context_->u_resolution_, render_context_->vec4_resolution_);
        float mtx[16];
        bx::mtxIdentity(mtx);
        bgfx::setViewTransform(view_id, mtx, mtx);
        bgfx::submit(view_id, render_context_->common_program_);
    }

UNKNOWN_NS_END
