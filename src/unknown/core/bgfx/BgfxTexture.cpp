//
// Created by Scave on 2023/11/12.
//

#include "BgfxTexture.h"

UNKNOWN_NS_BEGIN

    BgfxTextureHandle::BgfxTextureHandle(bgfx::TextureHandle &handle) : handle_(handle) {
    }

    BgfxTextureHandle::~BgfxTextureHandle() {
        bgfx::destroy(handle_);
    }

    uint16_t BgfxTextureHandle::GetIndex() {
        return handle_.idx;
    }

UNKNOWN_NS_END
