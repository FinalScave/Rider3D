//
// Created by Scave on 2024/2/24.
//

#include "UIElements.h"

#include <utility>

NS_RIDER_BEGIN

    void UIElement::SetEventListener(std::function<void()> callback) {
        this->callback_ = std::move(callback);
    }
NS_RIDER_END
