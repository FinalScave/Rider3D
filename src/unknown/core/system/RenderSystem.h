//
// Created by Scave on 2024/2/21.
//

#ifndef UNKNOWN3D_RENDERSYSTEM_H
#define UNKNOWN3D_RENDERSYSTEM_H

#include "Define.h"
#include "entityx/entityx.h"
#include "render/UnknownRenderer.h"
#include "event/SceneUpdateEvent.h"

UNKNOWN_NS_BEGIN

    class RenderSystem : public System<RenderSystem>, public Receiver<SceneUpdateEvent> {
    public:
        explicit RenderSystem(SMART_PTR<UnknownRenderer>& renderer);

        void configure(EntityManager& entities, EventManager& events) override;

        void update(EntityManager& entities, EventManager& events, TimeDelta dt) override;

        void receive(const SceneUpdateEvent& event);
    private:
        SMART_PTR<UnknownRenderer> renderer_;
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_RENDERSYSTEM_H
