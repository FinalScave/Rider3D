//
// Created by Scave on 2023/11/9.
//

#ifndef UNKNOWN3D_RENDERCONFIG_H
#define UNKNOWN3D_RENDERCONFIG_H

#include "Define.h"

UNKNOWN_NS_BEGIN

    struct RenderConfig {
        uint16_t width = 720;
        uint16_t height = 1280;
        void* native_window_handle = nullptr;
        bool debug = false;
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_RENDERCONFIG_H
