//
// Created by Scave on 2024/2/21.
//

#ifndef UNKNOWN3D_BASICRENDERSYSTEM_H
#define UNKNOWN3D_BASICRENDERSYSTEM_H

#include "Define.h"
#include "entityx/entityx.h"
#include "render/ObjectRenderer.h"
#include "event/SceneUpdateEvent.h"

UNKNOWN_NS_BEGIN

    class BasicRenderSystem : public System<BasicRenderSystem>, public Receiver<SceneUpdateEvent> {
    public:
        explicit BasicRenderSystem(SMART_PTR<ObjectRenderer>& renderer);

        void configure(EntityManager& entities, EventManager& events) override;

        void update(EntityManager& entities, EventManager& events, TimeDelta dt) override;

        void receive(const SceneUpdateEvent& event);
    private:
        SMART_PTR<ObjectRenderer> renderer_;
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_BASICRENDERSYSTEM_H
