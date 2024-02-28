//
// Created by Scave on 2023/11/8.
//

#ifndef RIDER3D_RIDERENGINE_H
#define RIDER3D_RIDERENGINE_H

#include "Define.h"
#include "render/SceneRenderer.h"
#include "entityx/entityx.h"
#include "entityx/help/Timer.h"
#include "event/SceneUpdateEvent.h"
#include "Scene.h"
#include "input/Input.h"
#include "file/File.h"

NS_RIDER_BEGIN

    class RiderEngine : public Receiver<SceneUpdateEvent> {
    public:
        explicit RiderEngine(const RenderConfig& config);

        ~RiderEngine();

        SceneManager& GetScenes();

        InputManager& GetInputs();

        FileManager& GetFiles();

        EntityManager& GetEntities();

        SystemManager& GetSystems();

        EventManager& GetEvents();

        void Update();

    private:
        SceneManager scenes_;
        InputManager inputs_;
        FileManager files_;
        EntityManager entities_;
        SystemManager systems_;
        EventManager events_;
        help::Timer timer_;
    };

NS_RIDER_END

#endif //RIDER3D_RIDERENGINE_H
