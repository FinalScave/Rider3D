//
// Created by Scave on 2024/2/21.
//

#ifndef RIDER3D_SCENEUPDATEEVENT_H
#define RIDER3D_SCENEUPDATEEVENT_H

#include "Define.h"
#include "Scene.h"

NS_RIDER_BEGIN
    class SceneUpdateEvent : public Event<SceneUpdateEvent> {
    public:
        explicit SceneUpdateEvent(Scene* scene) : scene(scene) {}

        Scene* scene;
    };

NS_RIDER_END

#endif //RIDER3D_SCENEUPDATEEVENT_H
