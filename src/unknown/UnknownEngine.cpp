//
// Created by Scave on 2023/11/8.
//

#include "UnknownEngine.h"
#include "system/MoveSystem.h"
#include "system/BasicRenderSystem.h"

UNKNOWN_NS_BEGIN
    EventManager UnknownEngine::default_events_;
    EntityManager UnknownEngine::default_entities_(default_events_);
    SystemManager UnknownEngine::default_systems_(default_entities_, default_events_);

    UnknownEngine::UnknownEngine(const RenderConfig& config) {
        auto renderer = MAKE_SMART_PTR<ObjectRenderer>(config);
        default_systems_.add<BasicRenderSystem>(renderer);
        default_systems_.add<MoveSystem>();
        default_systems_.configure();
    }

    UnknownEngine::~UnknownEngine() {

    }

    EntityManager& UnknownEngine::GetEntities() {
        return default_entities_;
    }

    SystemManager& UnknownEngine::GetSystems() {
        return default_systems_;
    }

    EventManager& UnknownEngine::GetEvents() {
        return default_events_;
    }

    void UnknownEngine::Update() {
        default_systems_.update<BasicRenderSystem>(timer_.elapsed());
    }

UNKNOWN_NS_END

// unknown