//
// Created by Scave on 2023/11/12.
//

#ifndef UNKNOWN3D_BGFXTEXTURE_H
#define UNKNOWN3D_BGFXTEXTURE_H

#include "Define.h"
#include "../Texture.h"
#include "bgfx/bgfx.h"

UNKNOWN_NS_BEGIN

    class BgfxTextureHandle : public TextureHandle {
    public:
        explicit BgfxTextureHandle(bgfx::TextureHandle& handle);

        ~BgfxTextureHandle();

        TEXTURE_ID_TYPE GetIndex() override;

    private:
        bgfx::TextureHandle handle_ = BGFX_INVALID_HANDLE;
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_BGFXTEXTURE_H
