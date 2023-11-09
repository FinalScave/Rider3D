//
// Created by Scave on 2023/11/8.
//

#include "Unknown3DEngine.h"

UNKNOWN_NS_BEGIN

    Unknown3DEngine::Unknown3DEngine(const RenderConfig &config) {
        this->renderer_ = MAKE_SMART_PTR<UnknownRenderer>(config);
    }

    Unknown3DEngine::~Unknown3DEngine() {
        this->renderer_ = nullptr;
    }

    uint16_t Unknown3DEngine::Render() {
        return renderer_->Render();
    }

    RenderConfig Unknown3DEngine::GetRenderConfig() {
        return renderer_->render_config_;
    }

UNKNOWN_NS_END

// unknown