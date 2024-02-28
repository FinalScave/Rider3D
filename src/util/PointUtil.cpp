//
// Created by Scave on 2023/11/9.
//

#include "PointUtil.h"

NS_RIDER_BEGIN

    NdcPoint PointUtil::ScreenPoint2NdcPoint(const ScreenPoint &screen_point,
                                             const ScreenRect &screen_rect) {
        float x = screen_point.x * 2.f - screen_rect.w;
        float y = screen_rect.h - screen_point.y * 2.f;
        return {x, y};
    }

NS_RIDER_END