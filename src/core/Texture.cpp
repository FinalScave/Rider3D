//
// Created by Scave on 2023/11/12.
//

#include "Texture.h"

NS_RIDER_BEGIN

    bool TextureHandle::isValid() {
        return GetIndex() != kInvalidIndex;
    }

    SMART_PTR<TextureHandle> TextureManager::GetTexture(const Name& name) {
        return name_texture_map_[name];
    }

    void TextureManager::PutTexture(const Name& name, const SMART_PTR<TextureHandle>& handle) {
        name_texture_map_[name] = handle;
    }

NS_RIDER_END
