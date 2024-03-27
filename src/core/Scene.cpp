//
// Created by Scave on 2023/11/11.
//

#include "Scene.h"
#include "component/BasicComponents.h"
#include "event/SceneUpdateEvent.h"
#include "LogUtil.h"
#include "VertexUtil.h"

NS_RIDER_BEGIN

    Entity Scene::kInvalidEntity;

    Scene::Scene(EntityManager *manager, Entity::Id id) : Entity(manager, id) {
        kInvalidEntity = Entity(manager, Entity::INVALID);
    }

    Scene::~Scene() {
        destroy();
        for(auto& entity : entity_list_) {
            entity.destroy();
        }
        entity_list_.clear();
    }

    void Scene::AddEntity(Entity &entity) {
        if (entity_list_.size() >= ENTITY_SIZE_MAX) {
            LOGW("Scene can only add %ud entities", ENTITY_SIZE_MAX);
            return;
        }
        entity_list_.push_back(entity);
    }

    void Scene::AddEntityAt(ENTITY_SIZE_TYPE index, Entity &entity) {
        if (index > entity_list_.size() || entity_list_.size() > ENTITY_SIZE_MAX) {
            LOGW("Scene can only add %ud entities", ENTITY_SIZE_MAX);
            return;
        }
        const std::vector<Entity, std::allocator<Entity>>::const_iterator &end = entity_list_.cend();
        ENTITY_SIZE_TYPE i(0);
        for (auto iterator = entity_list_.cbegin(); iterator != end; ++iterator) {
            if (index == i++) {
                entity_list_.insert(iterator, entity);
                break;
            }
        }
    }

    void Scene::RemoveEntity(Entity &entity) {
        const std::vector<Entity, std::allocator<Entity>>::const_iterator &end = entity_list_.cend();
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
        const std::vector<Entity, std::allocator<Entity>>::const_iterator &end = entity_list_.cend();
        ENTITY_SIZE_TYPE i(0);
        for (auto iterator = entity_list_.cbegin(); iterator != end; ++iterator) {
            if (index == i++) {
                entity_list_.erase(iterator);
                break;
            }
        }
    }

    Entity &Scene::GetEntityAt(ENTITY_SIZE_TYPE index) {
        return entity_list_[index];
    }

    Entity& Scene::FindEntity(const Name& name) {
        for(auto& entity : entity_list_) {
            if (entity.has_component<EntityIdentifier>() && entity.component<EntityIdentifier>()->name == name) {
                return entity;
            }
        }
        return kInvalidEntity;
    }

    Entity& Scene::operator[](ENTITY_SIZE_TYPE index) {
        return GetEntityAt(index);
    }

    Entity& Scene::operator[](const Name& name) {
        return FindEntity(name);
    }

    ENTITY_SIZE_TYPE Scene::Size() {
        return entity_list_.size();
    }

    SceneManager::SceneManager(EntityManager &entities, EventManager &events)
            : entities_(entities), events_(events) {
    }

    SceneManager::~SceneManager() {
        SAFE_DELETE_PTR(current_scene_);
        for(auto* scene : scene_list_) {
            SAFE_DELETE_PTR(scene);
        }
        scene_list_.clear();
    }

    Scene *SceneManager::CreateScene() {
        uint32_t index, version;
        if (entities_.free_list_.empty()) {
            index = entities_.index_counter_++;
            entities_.accomodate_entity(index);
            version = entities_.entity_version_[index] = 1;
        } else {
            index = entities_.free_list_.back();
            entities_.free_list_.pop_back();
            version = entities_.entity_version_[index];
        }
        Scene *scene = new Scene(&entities_, Entity::Id(index, version));
        events_.emit<EntityCreatedEvent>(*scene);
        scene_list_.push_back(scene);
        return scene;
    }

    Scene* SceneManager::CreateScene(const Name& name) {
        Scene* scene = CreateScene();
        scene->assign_from_copy(EntityIdentifier{name});
        return scene;
    }

    Scene *SceneManager::GetCurrentScene() {
        return current_scene_;
    }

    Scene* SceneManager::FindScene(const Name& name) {
        for(auto* scene : scene_list_) {
            if (scene->has_component<EntityIdentifier>() && scene->component<EntityIdentifier>()->name == name) {
                return scene;
            }
        }
        return nullptr;
    }

    Scene* SceneManager::operator[](const Name& name) {
        return FindScene(name);
    }

    void SceneManager::LoadScene(Scene *scene) {
        current_scene_ = scene;
        events_.emit<SceneUpdateEvent>(scene);
    }

    void SceneManager::LoadScene(const Name& name) {
        auto* scene = FindScene(name);
        if (scene != nullptr) {
            LoadScene(scene);
        }
    }

    Entity SceneManager::CreatePrimitiveEntity(PrimitiveType::Enum type) {
        Entity entity = entities_.create();
        Vertices& vertices = *entity.assign<Vertices>();
        switch (type) {
            case PrimitiveType::Rectangle:
                VertexUtil::BuildRectangle(vertices, 1, 1);
                break;
            case PrimitiveType::Triangle:
                VertexUtil::BuildTriangle(vertices, 1, 1);
                break;
            case PrimitiveType::Box:
                VertexUtil::BuildBox(vertices, 1, 1, 1);
                break;
            case PrimitiveType::Sphere:
                VertexUtil::BuildSphere(vertices, 100, 100, 0.5);
                break;
            case PrimitiveType::SkyBox:
                VertexUtil::BuildSkyBox(vertices, 1, 1);
                break;
            case PrimitiveType::Capsule:
                VertexUtil::BuildCapsule(vertices, 0.5, 0.5);
                break;
            case PrimitiveType::Cylinder:
                VertexUtil::BuildCylinder(vertices,
                                          0.5, 0.4, 0.5, 100);
                break;
            case PrimitiveType::Torus:
                VertexUtil::BuildTorus(vertices,
                                       0.5, 0.4, 100, 100);
                break;
            case PrimitiveType::TriangularPyramid:
                VertexUtil::BuildTriangularPyramid(vertices, 1, 1, 1);
                break;
        }
        return entity;
    }

    Entity SceneManager::CreatePrimitiveEntity(PrimitiveType::Enum type, const Name& name) {
        Entity entity = CreatePrimitiveEntity(type);
        entity.assign_from_copy(EntityIdentifier{name});
        return entity;
    }

NS_RIDER_END
