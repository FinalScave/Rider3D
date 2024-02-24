//
// Created by Scave on 2023/11/8.
//

#include "UnknownEngine.h"
#include "system/MoveSystem.h"
#include "system/BasicRenderSystem.h"

UNKNOWN_NS_BEGIN

    UnknownEngine::UnknownEngine(const RenderConfig& config)
            : entities_(events_),
              systems_(entities_, events_),
              scenes_(entities_, events_) {
        SMART_PTR<SceneRenderer> renderer = MAKE_SMART_PTR<SceneRenderer>(config);
        systems_.add<BasicRenderSystem>(renderer);
        systems_.add<MoveSystem>();
        systems_.configure();
    }

    UnknownEngine::~UnknownEngine() {

    }

    SceneManager& UnknownEngine::GetScenes() {
        return scenes_;
    }

    InputManager& UnknownEngine::GetInputs() {
        return inputs_;
    }

    FileManager& UnknownEngine::GetFiles() {
        return files_;
    }

    EntityManager& UnknownEngine::GetEntities() {
        return entities_;
    }

    SystemManager& UnknownEngine::GetSystems() {
        return systems_;
    }

    EventManager& UnknownEngine::GetEvents() {
        return events_;
    }

    void UnknownEngine::Update() {
        systems_.update<BasicRenderSystem>(timer_.elapsed());
    }

UNKNOWN_NS_END

// unknown