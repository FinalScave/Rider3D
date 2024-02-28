//
// Created by Scave on 2023/11/8.
//

#include "SceneRenderer.h"
#include "bgfx/bgfx.h"
#include "BasicComponents.h"

NS_RIDER_BEGIN

    SceneRenderer::SceneRenderer(const RenderConfig& config) {
        this->render_config_ = config;
        // initialize bgfx
        bgfx::Init init;
#if (defined(FORCE_GLFW))
        init.type = bgfx::RendererType::Enum::OpenGL;
#elif (defined(ANDROID) || defined(HARMONY))
        init.type = bgfx::RendererType::Enum::OpenGLES;
#elif (defined(IOS) || defined(MACOS))
        init.type = bgfx::RendererType::Enum::Metal;
#elif (defined(WINDOWS))
        init.type = bgfx::RendererType::Enum::Direct3D12;
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
        if (config.debug) {
            bgfx::setDebug(BGFX_DEBUG_TEXT);
        }

        // initialize context
        this->context_ = MAKE_SMART_PTR<RenderContext>(config);
        // initialize render strategies
        this->renderer_2d_ = MAKE_SMART_PTR<Graph2DRenderer>(context_);
        this->renderer_3d_ = MAKE_SMART_PTR<Graph3DRenderer>(context_);
        this->renderer_test_ = MAKE_SMART_PTR<TestRenderer>(context_);
    }

    SceneRenderer::~SceneRenderer() {
        context_ = nullptr;
        bgfx::shutdown();
    }

    void SceneRenderer::SetScene(Scene* scene) {
        context_->scene_ = scene;
    }

    TEXTURE_ID_TYPE SceneRenderer::Render() {
        bgfx::setViewRect(context_->main_view_id_, 0, 0, render_config_.width, render_config_.height);
        bgfx::setViewClear(context_->main_view_id_, BGFX_CLEAR_DEPTH | BGFX_CLEAR_COLOR, 0x000000ff);

        this->RenderScene();
        
        if (context_->scene_->has_component<DebugInfo>()) {
            auto debugInfo = context_->scene_->component<DebugInfo>();
            if (debugInfo->text != nullptr) {
                bgfx::touch(context_->main_view_id_);
                bgfx::dbgTextClear();
                bgfx::dbgTextPrintf(debugInfo->x, debugInfo->y, debugInfo->color, debugInfo->text);
            }
        }

        bgfx::frame();
        return context_->main_view_id_;
    }

    void SceneRenderer::RenderScene() {
        NULL_RETURN(context_->scene_);
        ENTITY_SIZE_TYPE size = context_->scene_->Size();
        for (ENTITY_SIZE_TYPE i = 0; i < size; ++i) {
            Entity& entity = context_->scene_->GetEntityAt(i);
            this->RenderEntity(entity, i + 1);
        }
    }

    void SceneRenderer::RenderEntity(Entity& entity, ENTITY_SIZE_TYPE order) {
        if (entity.has_component<EntityConfig>() && !entity.component<EntityConfig>()->visible) {
            return;
        }
        context_->curr_view_id_ = order;
        renderer_test_->RenderEntity(entity);
    }

NS_RIDER_END
