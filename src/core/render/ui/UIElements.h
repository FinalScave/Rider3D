//
// Created by Scave on 2024/2/24.
//

#ifndef UNKNOWN3D_UIELEMENTS_H
#define UNKNOWN3D_UIELEMENTS_H

#include <functional>
#include "Define.h"

UNKNOWN_NS_BEGIN

    class UIElement {
    public:
        void SetEventListener(std::function<void()> callback);
    private:
        std::function<void()> callback_{};
    };

    class Label : public UIElement {

    };

    class Button : public Label {

    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_UIELEMENTS_H
