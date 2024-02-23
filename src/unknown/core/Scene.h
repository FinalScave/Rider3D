//
// Created by Scave on 2023/11/11.
//

#ifndef UNKNOWN3D_SCENE_H
#define UNKNOWN3D_SCENE_H


#include "Define.h"
#include "entityx/Entity.h"

UNKNOWN_NS_BEGIN

    class Scene : public Entity {
    public:
        Scene();

        ~Scene();
    };

    class SceneManager {
    public:
        explicit SceneManager(EventManager& events);

        SMART_PTR<Scene> CreateScene();

        SMART_PTR<Scene> GetCurrentScene();

        void LoadScene(SMART_PTR<Scene>& scene);

    private:
        EventManager& events_;
        SMART_PTR<Scene> current_scene_ = nullptr;
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_SCENE_H
