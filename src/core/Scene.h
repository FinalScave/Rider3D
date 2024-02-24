//
// Created by Scave on 2023/11/11.
//

#ifndef UNKNOWN3D_SCENE_H
#define UNKNOWN3D_SCENE_H


#include "Define.h"
#include "entityx/Entity.h"

UNKNOWN_NS_BEGIN
#define ENTITY_SIZE_TYPE uint8_t
#define ENTITY_SIZE_MAX UINT8_MAX

    struct RenderType {
        enum Enum {
            Points = 0,
            Lines,
            LineStrip,
            TrisStrip
        };
    };

    class Scene : public Entity {
    public:
        Scene();

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
