//
// Created by Scave on 2024/2/24.
//

#include "UIElements.h"

#include <utility>

UNKNOWN_NS_BEGIN

    void UIElement::SetEventListener(std::function<void()> callback) {
        this->callback_ = std::move(callback);
    }
UNKNOWN_NS_END
