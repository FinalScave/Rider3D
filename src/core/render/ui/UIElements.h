//
// Created by Scave on 2024/2/24.
//

#ifndef RIDER3D_UIELEMENTS_H
#define RIDER3D_UIELEMENTS_H

#include <functional>
#include "Define.h"

NS_RIDER_BEGIN

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

NS_RIDER_END

#endif //RIDER3D_UIELEMENTS_H
