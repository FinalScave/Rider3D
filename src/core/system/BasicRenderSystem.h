//
// Created by Scave on 2024/2/21.
//

#ifndef RIDER3D_BASICRENDERSYSTEM_H
#define RIDER3D_BASICRENDERSYSTEM_H

#include "Define.h"
#include "entityx/entityx.h"
#include "render/SceneRenderer.h"
#include "event/SceneUpdateEvent.h"

NS_RIDER_BEGIN

    class BasicRenderSystem : public System<BasicRenderSystem>, public Receiver<SceneUpdateEvent> {
    public:
        explicit BasicRenderSystem(SMART_PTR<SceneRenderer>& renderer);

        void configure(EntityManager& entities, EventManager& events) override;

        void update(EntityManager& entities, EventManager& events, TimeDelta dt) override;

        void receive(const SceneUpdateEvent& event);

    private:
        SMART_PTR<SceneRenderer> renderer_;
    };

NS_RIDER_END

#endif //RIDER3D_BASICRENDERSYSTEM_H
