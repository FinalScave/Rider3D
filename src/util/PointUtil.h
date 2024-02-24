//
// Created by Scave on 2023/11/9.
//

#ifndef UNKNOWN3D_POINTUTIL_H
#define UNKNOWN3D_POINTUTIL_H

#include "Define.h"
#include "Supposition.h"

UNKNOWN_NS_BEGIN

    class PointUtil {
    public:
        static NdcPoint ScreenPoint2NdcPoint(const ScreenPoint &screen_point, const ScreenRect &screen_rect);

    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_POINTUTIL_H
