//
// Created by Scave on 2024/2/25.
//
#include <stdexcept>
#include <cmath>
#include "Supposition.h"

UNKNOWN_NS_BEGIN

    const Color Colors::Red = Color{1, 0, 0, 1};
    const Color Colors::Green = Color{0, 1, 0, 1};
    const Color Colors::Blue = Color{0, 0, 1, 1};
    const Color Colors::Black = Color{0, 0, 0, 1};
    const Color Colors::White = Color{1, 1, 1, 1};
    const Color Colors::Orange = Color{1, 1, 0, 1};
    const Color Colors::Purple = Color{1, 0, 1, 1};
    const Color Colors::Cyan = Color{0, 1, 1, 1};

    NdcPoint NdcPoint::add(NdcPoint a, NdcPoint b) {
        return {
            a.x + b.x,
            a.y + b.y,
            a.z + b.z
        };
    }

    NdcPoint NdcPoint::sub(NdcPoint a, NdcPoint b) {
        return {
            a.x - b.x,
            a.y - b.y,
            a.z - b.z
        };
    }

    NdcPoint NdcPoint::scalar(NdcPoint a, float b) {
        return {
            a.x * b,
            a.y * b,
            a.z * b
        };
    }

    float NdcPoint::dot(NdcPoint a, NdcPoint b) {
         return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    NdcPoint NdcPoint::cross(NdcPoint a, NdcPoint b) {
        return {
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
        };
    }

    NdcPoint NdcPoint::normalize(NdcPoint a) {
        float length = NdcPoint::length(a);
        if (length == 0.0f) {
            throw std::invalid_argument("Can't normalize a zero-length vector");
        }
        else {
            return NdcPoint::scalar(a, 1.0 / length);
        }
    }

    float NdcPoint::length(NdcPoint a) {
        return std::sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
    }

    float NdcPoint::distance(NdcPoint a, NdcPoint b) {
        NdcPoint c = NdcPoint::sub(a, b);
        return NdcPoint::length(c);
    }


UNKNOWN_NS_END
