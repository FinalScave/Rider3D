//
// Created by Scave on 2023/11/9.
//

#ifndef UNKNOWN3D_SUPPOSITION_H
#define UNKNOWN3D_SUPPOSITION_H

#include "Define.h"

UNKNOWN_NS_BEGIN

    /// Point of screen(such as phone screen),
    /// Starting from the top left corner, the range is from 0 to the width(x) or height(y) of the screen
    struct ScreenPoint {
        uint16_t x;
        uint16_t y;
    };

    /// Point of Normalized Device Coordinate,
    /// the range is (-1, 1)
    struct NdcPoint {
        float x;
        float y;
        float z;
    };

    /// Point of screen(such as phone screen),
    /// Starting from the top left corner, the range is (0, 1)
    struct ScreenUVPoint {
        float u;
        float v;
    };

    /// Point of texture,
    /// Starting from the bottom left corner, the range is (0, 1)
    struct TextureUVPoint {
        float u;
        float v;
    };

    struct ScreenRect {
        uint16_t x;
        uint16_t y;
        uint16_t w;
        uint16_t h;
    };

    struct ScreenUVRect {
        float u;
        float v;
        float w;
        float h;
    };

    struct TextureUVRect {
        float u;
        float v;
        float w;
        float h;
    };

    struct NdcRect {
        float x;
        float y;
        float w;
        float h;
    };

    struct Color {
        float r;
        float g;
        float b;
        float a;
    };

    typedef NS_UNKNOWN::NdcPoint Number3D;
    typedef NS_UNKNOWN::NdcPoint Vec3;
    typedef NS_UNKNOWN::TextureUVPoint UV;

UNKNOWN_NS_END

#endif //UNKNOWN3D_SUPPOSITION_H
