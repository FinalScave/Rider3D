//
// Created by Scave on 2023/11/11.
//

#ifndef UNKNOWN3D_SCENE_H
#define UNKNOWN3D_SCENE_H


#include "Define.h"
#include "entityx/Entity.h"

UNKNOWN_NS_BEGIN

    struct RenderType {
        enum Enum {
            Points = 0,
            Lines,
            LineStrip,
            TrisStrip
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

        ENTITY_SIZE_TYPE Size();

    private:
        std::vector<Entity> entity_list_;
    };

    class SceneManager {
    public:
        explicit SceneManager(EntityManager& entities, EventManager& events);

        Scene* CreateScene();

        Scene* GetCurrentScene();

        void LoadScene(Scene* scene);

    private:
        EntityManager& entities_;
        EventManager& events_;
        Scene* current_scene_ = nullptr;
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_SCENE_H
