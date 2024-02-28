//
// Created by Scave on 2023/11/8.
//

#include "RiderEngine.h"
#include "system/MoveSystem.h"
#include "system/BasicRenderSystem.h"

NS_RIDER_BEGIN

    RiderEngine::RiderEngine(const RenderConfig& config)
            : entities_(events_),
              systems_(entities_, events_),
              scenes_(entities_, events_) {
        SMART_PTR<SceneRenderer> renderer = MAKE_SMART_PTR<SceneRenderer>(config);
        systems_.add<BasicRenderSystem>(renderer);
        systems_.add<MoveSystem>();
        systems_.configure();
    }

    RiderEngine::~RiderEngine() {

    }

    SceneManager& RiderEngine::GetScenes() {
        return scenes_;
    }

    InputManager& RiderEngine::GetInputs() {
        return inputs_;
    }

    FileManager& RiderEngine::GetFiles() {
        return files_;
    }

    EntityManager& RiderEngine::GetEntities() {
        return entities_;
    }

    SystemManager& RiderEngine::GetSystems() {
        return systems_;
    }

    EventManager& RiderEngine::GetEvents() {
        return events_;
    }

    void RiderEngine::Update() {
        systems_.update<BasicRenderSystem>(timer_.elapsed());
    }

NS_RIDER_END

// unknown