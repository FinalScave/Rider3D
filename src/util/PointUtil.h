//
// Created by Scave on 2023/11/9.
//

#ifndef RIDER3D_POINTUTIL_H
#define RIDER3D_POINTUTIL_H

#include "Define.h"
#include "Supposition.h"

NS_RIDER_BEGIN

    class PointUtil {
    public:
        static NdcPoint ScreenPoint2NdcPoint(const ScreenPoint &screen_point, const ScreenRect &screen_rect);

    };

NS_RIDER_END

#endif //RIDER3D_POINTUTIL_H
