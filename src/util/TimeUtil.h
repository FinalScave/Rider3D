//
// Created by Scave on 2024/2/28.
//

#ifndef RIDER3D_TIMEUTIL_H
#define RIDER3D_TIMEUTIL_H

#include "Define.h"

NS_RIDER_BEGIN

    class TimeUtil {
    public:
        static UInt64 MilliTime();

        static UInt64 MicroTime();

        static UInt64 NanoTime();
    };

NS_RIDER_END

#endif //RIDER3D_TIMEUTIL_H
