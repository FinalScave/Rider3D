//
// Created by Scave on 2023/11/8.
//

#ifndef UNKNOWN3D_UNKNOWN3DENGINE_H
#define UNKNOWN3D_UNKNOWN3DENGINE_H

#include "Define.h"
#include "render/UnknownRenderer.h"
#include "Object3D.h"
#include "entityx/entityx.h"
#include "entityx/help/Timer.h"
#include "event/SceneUpdateEvent.h"
#include "Scene.h"

UNKNOWN_NS_BEGIN

    class Unknown3DEngine : public EntityX, public Receiver<SceneUpdateEvent> {
    public:
        explicit Unknown3DEngine(const RenderConfig &config);
        ~Unknown3DEngine();

        void SetScene(Scene* scene);

        void Render();

        void receive(const SceneUpdateEvent& event);

    private:
        help::Timer timer_;
    };

UNKNOWN_NS_END // unknown

#endif //UNKNOWN3D_UNKNOWN3DENGINE_H
