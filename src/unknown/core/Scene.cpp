//
// Created by Scave on 2023/11/11.
//

#include "Scene.h"
#include "component/BasicComponents.h"
#include "event/SceneUpdateEvent.h"

UNKNOWN_NS_BEGIN

    Scene::Scene() {
        this->assign<Camera>();
    }

    Scene::~Scene() {
        destroy();
    }

    SceneManager::SceneManager(EventManager& events): events_(events) {
    }

    SMART_PTR<Scene> SceneManager::CreateScene() {
        return MAKE_SMART_PTR<Scene>();
    }

    SMART_PTR<Scene> SceneManager::GetCurrentScene() {
        return std::shared_ptr<Scene>();
    }

    void SceneManager::LoadScene(SMART_PTR<Scene>& scene) {
        current_scene_ = scene;
        events_.emit<SceneUpdateEvent>(scene);
    }

UNKNOWN_NS_END
