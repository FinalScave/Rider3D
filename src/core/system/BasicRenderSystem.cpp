//
// Created by Scave on 2024/2/21.
//

#include "BasicRenderSystem.h"
#include "Scene.h"

UNKNOWN_NS_BEGIN

    BasicRenderSystem::BasicRenderSystem(SMART_PTR<SceneRenderer>& renderer) {
        this->renderer_ = renderer;
    }

    void BasicRenderSystem::configure(EntityManager& entities, EventManager& events) {
        events.subscribe<SceneUpdateEvent>(*this);
    }

    void BasicRenderSystem::update(EntityManager& entities, EventManager& events, TimeDelta dt) {
        renderer_->Render();
    }

    void BasicRenderSystem::receive(const SceneUpdateEvent& event) {
        renderer_->SetScene(event.scene);
    }

UNKNOWN_NS_END

