//
// Created by Scave on 2023/11/12.
//

#include "BgfxTexture.h"

NS_RIDER_BEGIN

    BgfxTextureHandle::BgfxTextureHandle(bgfx::TextureHandle& handle) : handle_(handle) {
    }

    BgfxTextureHandle::~BgfxTextureHandle() {
        bgfx::destroy(handle_);
    }

    TEXTURE_ID_TYPE BgfxTextureHandle::GetIndex() {
        return handle_.idx;
    }

NS_RIDER_END
