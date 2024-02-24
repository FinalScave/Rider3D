//
// Created by Scave on 2024/2/21.
//

#ifndef UNKNOWN3D_SCENEUPDATEEVENT_H
#define UNKNOWN3D_SCENEUPDATEEVENT_H

#include "Define.h"
#include "Scene.h"

UNKNOWN_NS_BEGIN
    class SceneUpdateEvent : public Event<SceneUpdateEvent> {
    public:
        explicit SceneUpdateEvent(Scene* scene) : scene(scene) {}

        Scene* scene;
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_SCENEUPDATEEVENT_H
