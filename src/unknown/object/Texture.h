//
// Created by Scave on 2023/11/12.
//

#ifndef UNKNOWN3D_TEXTURE_H
#define UNKNOWN3D_TEXTURE_H

#include "Define.h"
#include "entityx/entityx.h"

UNKNOWN_NS_BEGIN

    const static uint16_t kInvalidIndex = UINT16_MAX;

    class TextureHandle : public Component<TextureHandle> {
    public:
        virtual uint16_t GetIndex() = 0;

        bool isValid();
    };

    class TextureManager : public Entity {
    public:
        SMART_PTR<TextureHandle> GetTexture(const Name &name);

        void PutTexture(const Name &name, const SMART_PTR<TextureHandle> &handle);

    private:
        HashMap<Name, SMART_PTR<TextureHandle>> name_texture_map_;
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_TEXTURE_H
