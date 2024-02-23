//
// Created by Scave on 2023/11/8.
//

#include "UnknownRenderer.h"
#include "bgfx/bgfx.h"
#include "bx/math.h"
#include "LogUtil.h"

UNKNOWN_NS_BEGIN

    UnknownRenderer::UnknownRenderer(const RenderConfig& config) {
        this->render_config_ = config;
        // initialize bgfx
        bgfx::Init init;
#if (defined(WINDOWS) || defined(LINUX) || defined(MACOS))
        init.type = bgfx::RendererType::Enum::Count;
#elif (defined(ANDROID) || defined(HARMONY))
        init.type = bgfx::RendererType::Enum::OpenGLES;
#elif (defined(IOS))
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

        // initialize context
        this->render_context_ = MAKE_SMART_PTR<RenderContext>(config);
        // initialize render strategies
        this->simple_renderer_ = MAKE_SMART_PTR<SimpleRenderStrategy>(render_context_);
        this->common_renderer_ = MAKE_SMART_PTR<CommonRenderStrategy>(render_context_);
    }

    UnknownRenderer::~UnknownRenderer() {
        render_context_ = nullptr;
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
            this->RenderObject(object, i + 1);
        }
    }

    void UnknownRenderer::RenderObject(Object3D& object, uint8_t id) {
        if (!object.visible) {
            return;
        }
        render_context_->curr_view_id_ = id;
        simple_renderer_->RenderObject(object);
    }

UNKNOWN_NS_END
