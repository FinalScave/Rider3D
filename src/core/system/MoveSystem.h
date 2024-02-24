//
// Created by Scave on 2024/2/21.
//

#ifndef UNKNOWN3D_MOVESYSTEM_H
#define UNKNOWN3D_MOVESYSTEM_H
#include "Define.h"
#include "entityx/entityx.h"

UNKNOWN_NS_BEGIN

    class MoveSystem : public System<MoveSystem> {
    public:
        MoveSystem();

        void configure(EntityManager &entities, EventManager &events) override;

        void update(EntityManager &entities, EventManager &events, TimeDelta dt) override;
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_MOVESYSTEM_H
