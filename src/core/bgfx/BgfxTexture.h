//
// Created by Scave on 2023/11/12.
//

#ifndef RIDER3D_BGFXTEXTURE_H
#define RIDER3D_BGFXTEXTURE_H

#include "Define.h"
#include "../Texture.h"
#include "bgfx/bgfx.h"

NS_RIDER_BEGIN

    class BgfxTextureHandle : public TextureHandle {
    public:
        explicit BgfxTextureHandle(bgfx::TextureHandle& handle);

        ~BgfxTextureHandle();

        TEXTURE_ID_TYPE GetIndex() override;

    private:
        bgfx::TextureHandle handle_ = BGFX_INVALID_HANDLE;
    };

NS_RIDER_END

#endif //RIDER3D_BGFXTEXTURE_H
