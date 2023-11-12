//
// Created by Scave on 2023/11/11.
//

#ifndef UNKNOWN3D_SCENE_H
#define UNKNOWN3D_SCENE_H


#include "Define.h"
#include "Object3D.h"

UNKNOWN_NS_BEGIN

    struct Camera {
        Vec3 *position = nullptr;
        Vec3 *target = nullptr;
        Vec3 *up_axis = nullptr;
    };

    class Scene : public Object3DContainer {
    public:
        Scene();

        ~Scene();

        Camera *camera_ = nullptr;
        Color *background_color_ = nullptr;
        bool lighting_enabled_;
    private:

    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_SCENE_H
