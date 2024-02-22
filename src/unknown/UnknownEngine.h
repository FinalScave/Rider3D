//
// Created by Scave on 2023/11/8.
//

#ifndef UNKNOWN3D_UNKNOWNENGINE_H
#define UNKNOWN3D_UNKNOWNENGINE_H

#include "Define.h"
#include "render/ObjectRenderer.h"
#include "object/Object3D.h"
#include "entityx/entityx.h"
#include "entityx/help/Timer.h"
#include "event/SceneUpdateEvent.h"

UNKNOWN_NS_BEGIN

    class UnknownEngine : public Receiver<SceneUpdateEvent> {
    public:
        explicit UnknownEngine(const RenderConfig& config);

        ~UnknownEngine();

        EntityManager& GetEntities();

        SystemManager& GetSystems();

        EventManager& GetEvents();

        void Update();

    private:
        static EntityManager default_entities_;
        static SystemManager default_systems_;
        static EventManager default_events_;
        help::Timer timer_;
    };

UNKNOWN_NS_END // unknown

#endif //UNKNOWN3D_UNKNOWNENGINE_H
