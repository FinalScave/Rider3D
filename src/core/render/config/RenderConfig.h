//
// Created by Scave on 2023/11/9.
//

#ifndef RIDER3D_RENDERCONFIG_H
#define RIDER3D_RENDERCONFIG_H

#include "Define.h"

NS_RIDER_BEGIN

    struct RenderConfig {
        uint16_t width = 720;
        uint16_t height = 1280;
        void* native_window_handle = nullptr;
        bool debug = false;
    };

NS_RIDER_END

#endif //RIDER3D_RENDERCONFIG_H
