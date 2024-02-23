//
// Created by Scave on 2023/11/8.
//

#ifndef UNKNOWN3D_UNKNOWNENGINE_H
#define UNKNOWN3D_UNKNOWNENGINE_H

#include "Define.h"
#include "render/ObjectRenderer.h"
#include "Object3D.h"
#include "entityx/entityx.h"
#include "entityx/help/Timer.h"
#include "event/SceneUpdateEvent.h"
#include "Scene.h"
#include "input/Input.h"
#include "file/File.h"

UNKNOWN_NS_BEGIN

    class UnknownEngine : public Receiver<SceneUpdateEvent> {
    public:
        explicit UnknownEngine(const RenderConfig& config);

        ~UnknownEngine();

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

UNKNOWN_NS_END // unknown

#endif //UNKNOWN3D_UNKNOWNENGINE_H
