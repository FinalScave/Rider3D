//
// Created by Scave on 2024/2/25.
//
#include <stdexcept>
#include <cmath>
#include "Supposition.h"

NS_RIDER_BEGIN

    const Color Colors::Red = Color{1, 0, 0, 1};
    const Color Colors::Green = Color{0, 1, 0, 1};
    const Color Colors::Blue = Color{0, 0, 1, 1};
    const Color Colors::Black = Color{0, 0, 0, 1};
    const Color Colors::White = Color{1, 1, 1, 1};
    const Color Colors::Orange = Color{1, 1, 0, 1};
    const Color Colors::Purple = Color{1, 0, 1, 1};
    const Color Colors::Cyan = Color{0, 1, 1, 1};

    NdcPoint NdcPoint::Add(const NdcPoint& a, const NdcPoint& b) {
        return {
            a.x + b.x,
            a.y + b.y,
            a.z + b.z
        };
    }

    NdcPoint NdcPoint::Sub(const NdcPoint& a, const NdcPoint& b) {
        return {
            a.x - b.x,
            a.y - b.y,
            a.z - b.z
        };
    }

    NdcPoint NdcPoint::Scalar(const NdcPoint& a, const float b) {
        return {
            a.x * b,
            a.y * b,
            a.z * b
        };
    }

    float NdcPoint::Dot(const NdcPoint& a, const NdcPoint& b) {
         return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    NdcPoint NdcPoint::Cross(const NdcPoint& a, const NdcPoint& b) {
        return {
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
        };
    }

    NdcPoint NdcPoint::Normalize(const NdcPoint& a) {
        float length = NdcPoint::Length(a);
        if (length == 0.0f) {
            throw std::invalid_argument("Can't normalize a zero-length vector");
        }
        else {
            return NdcPoint::Scalar(a, 1.0 / length);
        }
    }

    float NdcPoint::Length(const NdcPoint& a) {
        return std::sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
    }

    float NdcPoint::Distance(const NdcPoint& a, const NdcPoint& b) {
        NdcPoint c = NdcPoint::Sub(a, b);
        return NdcPoint::Length(c);
    }


NS_RIDER_END
