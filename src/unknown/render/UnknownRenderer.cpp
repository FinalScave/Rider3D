//
// Created by Scave on 2023/11/8.
//

#include "UnknownRenderer.h"
#include "bgfx/bgfx.h"

UNKNOWN_NS_BEGIN

    UnknownRenderer::UnknownRenderer(const RenderConfig &config) {
        this->render_config_ = config;
        // initialize bgfx
        bgfx::Init init;
        init.type = bgfx::RendererType::Count;
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
        bgfx::reset(config.width, config.height, BGFX_CLEAR_DEPTH | BGFX_CLEAR_COLOR);
        // initialize something defaults
        DefaultVertexLayout::Init();
        DefaultBgfxHandles::Init();
    }

    UnknownRenderer::~UnknownRenderer() {
        render_context_ = nullptr;
        DefaultBgfxHandles::Destroy();
        bgfx::shutdown();
    }

    uint16_t UnknownRenderer::Render() {
        bgfx::frame();
        return render_context_->main_view_id_;
    }

UNKNOWN_NS_END
