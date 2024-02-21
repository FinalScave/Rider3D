//
// Created by Scave on 2023/11/8.
//

#include "Unknown3DEngine.h"
#include "system/MoveSystem.h"
#include "system/RenderSystem.h"

UNKNOWN_NS_BEGIN

    Unknown3DEngine::Unknown3DEngine(const RenderConfig &config) {
        auto renderer = MAKE_SMART_PTR<UnknownRenderer>(config);
        auto render_system = systems.add<RenderSystem>(renderer);
        systems.add<MoveSystem>();
        systems.configure();
        events.subscribe<SceneUpdateEvent>(*render_system);
    }

    Unknown3DEngine::~Unknown3DEngine() {}

    void Unknown3DEngine::SetScene(Scene* scene) {
        events.emit<SceneUpdateEvent>(scene);
    }

    void Unknown3DEngine::Render() {
        systems.update<RenderSystem>(timer_.elapsed());
    }

UNKNOWN_NS_END

// unknown