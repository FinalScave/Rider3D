//
// Created by Scave on 2023/11/11.
//

#include "Scene.h"
#include "component/BasicComponents.h"
#include "event/SceneUpdateEvent.h"
#include "LogUtil.h"
#include "VertexUtil.h"

UNKNOWN_NS_BEGIN

    Scene::Scene(EntityManager *manager, Entity::Id id) : Entity(manager, id) {
    }

    Scene::~Scene() {
        destroy();
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

    ENTITY_SIZE_TYPE Scene::Size() {
        return entity_list_.size();
    }

    SceneManager::SceneManager(EntityManager &entities, EventManager &events)
            : entities_(entities), events_(events) {
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
        return scene;
    }

    Scene *SceneManager::GetCurrentScene() {
        return current_scene_;
    }

    void SceneManager::LoadScene(Scene *scene) {
        current_scene_ = scene;
        events_.emit<SceneUpdateEvent>(scene);
    }

    Entity SceneManager::CreatePrimitiveEntity(PrimitiveType::Enum type) {
        Entity entity = entities_.create();
        Vertices& vertices = *entity.assign<Vertices>();
        switch (type) {
            case PrimitiveType::Rectangle:
                VertexUtil::BuildRectangle(vertices, 0.5, 0.5);
                break;
            case PrimitiveType::Triangle:
                VertexUtil::BuildTriangle(vertices, {-0.5f, -0.5f, 0.0f}, {0.5f, -0.5f, 0.0f}, {0.0f,  0.5f, 0.0f});
                break;
            case PrimitiveType::Box:
                VertexUtil::BuildBox(vertices, 0.5, 0.5, 0.5);
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
                Vec3 shape[4] = {
                        {-0.5f, 0.0f, -0.5f},
                        {0.5f, 0.0f, -0.5f},
                        {0.0f, 0.0f, 0.5f},
                        {0.0f, 1.0f, 0.0f}
                };
                VertexUtil::BuildTriangularPyramid(vertices, shape);
                break;
        }
        return entity;
    }

UNKNOWN_NS_END
