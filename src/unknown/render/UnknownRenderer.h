//
// Created by Scave on 2023/11/8.
//

#ifndef UNKNOWN3D_UNKNOWNRENDERER_H
#define UNKNOWN3D_UNKNOWNRENDERER_H

#include <stdint.h>
#include "Define.h"

UNKNOWN_NS_BEGIN

    class UnknownRenderer {
    public:
        /// 离屏渲染，并返回纹理ID
        /// \return 纹理ID
        uint16_t Render();
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_UNKNOWNRENDERER_H
