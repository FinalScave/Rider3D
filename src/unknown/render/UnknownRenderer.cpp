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
        init.type = bgfx::RendererType::Enum::Count;
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
        bgfx::setDebug(BGFX_DEBUG_TEXT);
        // initialize something defaults
        DefaultVertexLayout::Init();
        DefaultBgfxHandles::Init();

        // initialize context
        this->render_context_ = MAKE_SMART_PTR<RenderContext>();
    }

    UnknownRenderer::~UnknownRenderer() {
        render_context_ = nullptr;
        DefaultBgfxHandles::Destroy();
        bgfx::shutdown();
    }

    uint16_t UnknownRenderer::Render() {
        bgfx::dbgTextClear();
        bgfx::dbgTextPrintf(10, 10, 0x0f,
                            "\x1b[9;mU\x1b[10;mn\x1b[11;mk\x1b[12;mn\x1b[13;mo\x1b[14;mw\x1b[15;mn\x1b[16;m3\x1b[1;mD\x1b[0m");
        bgfx::setViewRect(render_context_->main_view_id_, 0, 0, render_config_.width, render_config_.height);
        bgfx::setViewClear(render_context_->main_view_id_, BGFX_CLEAR_COLOR|BGFX_CLEAR_DEPTH, 0x2196f3ff);
        bgfx::touch(render_context_->main_view_id_);
        bgfx::frame();
        return render_context_->main_view_id_;
    }

UNKNOWN_NS_END
