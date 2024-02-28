//
// Created by Scave on 2024/2/28.
//

#ifndef UNKNOWN3D_TIMEUTIL_H
#define UNKNOWN3D_TIMEUTIL_H

#include "Define.h"

UNKNOWN_NS_BEGIN

    class TimeUtil {
    public:
        static UInt64 MilliTime();

        static UInt64 MicroTime();

        static UInt64 NanoTime();
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_TIMEUTIL_H
