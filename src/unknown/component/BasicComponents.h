//
// Created by Scave on 2024/2/22.
//

#ifndef UNKNOWN3D_BASICCOMPONENTS_H
#define UNKNOWN3D_BASICCOMPONENTS_H

#include "Define.h"
#include "object/Supposition.h"

UNKNOWN_NS_BEGIN

    struct Position {
        Vec3 value;
    };

    struct Transform {
        Vec3 translation;
        Vec3 rotation;
        Vec3 scale;
    };

UNKNOWN_NS_END
#endif //UNKNOWN3D_BASICCOMPONENTS_H
