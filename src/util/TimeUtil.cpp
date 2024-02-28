//
// Created by Scave on 2024/2/28.
//

#include "TimeUtil.h"

NS_RIDER_BEGIN
    UInt64 TimeUtil::MilliTime() {
        auto now = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
    }

    UInt64 TimeUtil::MicroTime() {
        auto now = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()).count();
    }

    UInt64 TimeUtil::NanoTime() {
        auto now = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()).count();
    }

NS_RIDER_END