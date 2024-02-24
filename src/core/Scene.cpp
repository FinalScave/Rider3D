//
// Created by Scave on 2023/11/11.
//

#include "Scene.h"
#include "component/BasicComponents.h"
#include "event/SceneUpdateEvent.h"
#include "LogUtil.h"

UNKNOWN_NS_BEGIN

    Scene::Scene() {
        this->assign<Camera>();
    }

    Scene::~Scene() {
        destroy();
    }

    void Scene::AddEntity(Entity& entity) {
        if (entity_list_.size() >= ENTITY_SIZE_MAX) {
            LOGW("Scene can only add %ud entities", ENTITY_SIZE_MAX);
            return;
        }
        entity_list_.push_back(entity);
    }

    void Scene::AddEntityAt(ENTITY_SIZE_TYPE index, Entity& entity) {
        if (index > entity_list_.size() || entity_list_.size() > ENTITY_SIZE_MAX) {
            LOGW("Scene can only add %ud entities", ENTITY_SIZE_MAX);
            return;
        }
        const std::vector<Entity, std::allocator<Entity>>::const_iterator& end = entity_list_.cend();
        ENTITY_SIZE_TYPE i(0);
        for (auto iterator = entity_list_.cbegin(); iterator != end; ++iterator) {
            if (index == i++) {
                entity_list_.insert(iterator, entity);
                break;
            }
        }
    }

    void Scene::RemoveEntity(Entity& entity) {
        const std::vector<Entity, std::allocator<Entity>>::const_iterator& end = entity_list_.cend();
        for (auto iterator = entity_list_.cbegin(); iterator != end; ++iterator) {
            if (&entity == &*iterator) {
                entity_list_.erase(iterator);
                break;
            }
        }
    }

    void Scene::RemoveEntityAt(ENTITY_SIZE_TYPE index) {
        if (index > entity_list_.size() - 1) {
            LOGW("index can not greater than %ud", ENTITY_SIZE_MAX - 1);
            return;
        }
        const std::vector<Entity, std::allocator<Entity>>::const_iterator& end = entity_list_.cend();
        ENTITY_SIZE_TYPE i(0);
        for (auto iterator = entity_list_.cbegin(); iterator != end; ++iterator) {
            if (index == i++) {
                entity_list_.erase(iterator);
                break;
            }
        }
    }

    Entity& Scene::GetEntityAt(ENTITY_SIZE_TYPE index) {
        return entity_list_[index];
    }

    ENTITY_SIZE_TYPE Scene::Size() {
        return entity_list_.size();
    }

    SceneManager::SceneManager(EventManager& events) : events_(events) {
    }

    SMART_PTR<Scene> SceneManager::CreateScene() {
        return MAKE_SMART_PTR<Scene>();
    }

    SMART_PTR<Scene> SceneManager::GetCurrentScene() {
        return current_scene_;
    }

    void SceneManager::LoadScene(SMART_PTR<Scene>& scene) {
        current_scene_ = scene;
        events_.emit<SceneUpdateEvent>(scene);
    }

UNKNOWN_NS_END
