//
// Created by Scave on 2023/11/11.
//

#ifndef UNKNOWN3D_SCENE_H
#define UNKNOWN3D_SCENE_H


#include "Define.h"
#include "Object3D.h"

UNKNOWN_NS_BEGIN

    struct Camera: public Component<Camera> {
        Vec3 position = {0, 0, 0};
        Vec3 target = {0, 0, 0};
        Vec3 up_axis = {0, 1, 0};
    };

    class Scene : public Object3DContainer {
    public:
        Scene();

        ~Scene();

        void SetCamera(Camera* camera);

        Camera *camera_ = nullptr;
        Color *background_color_ = nullptr;
        bool lighting_enabled_;
    private:

    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_SCENE_H
