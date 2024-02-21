//
// Created by Scave on 2024/2/21.
//

#include "RenderSystem.h"

UNKNOWN_NS_BEGIN

    RenderSystem::RenderSystem(SMART_PTR<UnknownRenderer>& renderer) {
        this->renderer_ = renderer;
    }

    void RenderSystem::configure(EntityManager& entities, EventManager& events) {

    }

    void RenderSystem::update(EntityManager& entities, EventManager& events, TimeDelta dt) {
        renderer_->Render();
    }

    void RenderSystem::receive(const SceneUpdateEvent& event) {
        renderer_->SetScene(SMART_PTR<Scene>(event.scene));
    }

UNKNOWN_NS_END

