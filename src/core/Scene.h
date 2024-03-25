//
// Created by Scave on 2023/11/11.
//

#ifndef RIDER3D_SCENE_H
#define RIDER3D_SCENE_H


#include "Define.h"
#include "entityx/Entity.h"

NS_RIDER_BEGIN

    struct RenderType {
        enum Enum {
            Points = 0,
            Lines,
            LineStrip,
            TrisStrip
        };
    };

    struct PrimitiveType {
        enum Enum {
            Rectangle = 0,
            Triangle = 1,
            Box = 10,
            Sphere = 11,
            SkyBox = 12,
            Capsule = 13,
            Cylinder = 14,
            Torus = 15,
            TriangularPyramid = 16
        };
    };

    class Scene : public Entity {
        friend class SceneManager;

    private:
        Scene(EntityManager* manager, Entity::Id id);

    public:

        ~Scene();

        void AddEntity(Entity& entity);

        void AddEntityAt(ENTITY_SIZE_TYPE index, Entity& entity);

        void RemoveEntity(Entity& entity);

        void RemoveEntityAt(ENTITY_SIZE_TYPE index);

        Entity& GetEntityAt(ENTITY_SIZE_TYPE index);

        Entity& FindEntity(const Name& name);

        ENTITY_SIZE_TYPE Size();
    public:
        static Entity kInvalidEntity;
    private:
        std::vector<Entity> entity_list_;
    };

    class SceneManager {
    public:
        explicit SceneManager(EntityManager& entities, EventManager& events);

        Scene* CreateScene();

        Scene* GetCurrentScene();

        void LoadScene(Scene* scene);

        Entity CreatePrimitiveEntity(PrimitiveType::Enum type);

        Entity CreatePrimitiveEntity(PrimitiveType::Enum type, const Name& name);

    private:
        EntityManager& entities_;
        EventManager& events_;
        Scene* current_scene_ = nullptr;
    };

NS_RIDER_END

#endif //RIDER3D_SCENE_H
