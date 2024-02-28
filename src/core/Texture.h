//
// Created by Scave on 2023/11/12.
//

#ifndef RIDER3D_TEXTURE_H
#define RIDER3D_TEXTURE_H

#include "Define.h"

NS_RIDER_BEGIN

    const static TEXTURE_ID_TYPE kInvalidIndex = UINT16_MAX;

    class TextureHandle {
    public:
        virtual TEXTURE_ID_TYPE GetIndex() = 0;

        bool isValid();
    };

    class TextureManager {
    public:
        SMART_PTR<TextureHandle> GetTexture(const Name& name);

        void PutTexture(const Name& name, const SMART_PTR<TextureHandle>& handle);

    private:
        HASHMAP<Name, SMART_PTR<TextureHandle>> name_texture_map_;
    };

NS_RIDER_END

#endif //RIDER3D_TEXTURE_H
