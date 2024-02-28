//
// Created by Scave on 2024/2/21.
//

#ifndef RIDER3D_MOVESYSTEM_H
#define RIDER3D_MOVESYSTEM_H

#include "Define.h"
#include "entityx/entityx.h"

NS_RIDER_BEGIN

    class MoveSystem : public System<MoveSystem> {
    public:
        MoveSystem();

        void configure(EntityManager& entities, EventManager& events) override;

        void update(EntityManager& entities, EventManager& events, TimeDelta dt) override;
    };

NS_RIDER_END

#endif //RIDER3D_MOVESYSTEM_H
