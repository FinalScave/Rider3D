//
// Created by Scave on 2024/2/22.
//

#ifndef UNKNOWN3D_BASICCOMPONENTS_H
#define UNKNOWN3D_BASICCOMPONENTS_H

#include "Define.h"
#include "Supposition.h"

UNKNOWN_NS_BEGIN

    struct Position {
        Vec3 value;
    };

    struct Transform {
        Vec3 translation;
        Vec3 rotation;
        Vec3 scale;
    };

    struct Camera {
        Vec3 position = {0, 0, 0};
        Vec3 target = {0, 0, 0};
        Vec3 up_axis = {0, 1, 0};
    };

    struct EntityProperty {
        bool visible = true;
        bool vertex_colors_enabled = true;
        bool textures_enabled = true;
        bool normals_enabled = true;
        bool ignore_faces = false;
        bool lighting_enabled = true;
        float point_size = 3.f;
        bool point_smoothing = true;
        float line_width = 1.f;
        bool line_smoothing = false;
    };

UNKNOWN_NS_END
#endif //UNKNOWN3D_BASICCOMPONENTS_H
