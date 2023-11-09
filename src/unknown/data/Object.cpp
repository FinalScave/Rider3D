//
// Created by Scave on 2023/11/10.
//

#include "Object.h"
#include "LogUtil.h"

UNKNOWN_NS_BEGIN
    void ObjectContainer::AddChild(Object &object) {
        if (child_list.size() >= UINT8_MAX) {
            LOGW("ObjectContainer can only add %ud child objects", UINT8_MAX);
            return;
        }
        child_list.push_back(object);
    }

    void ObjectContainer::AddChildAt(uint8_t index, Object &object) {
        if (index > child_list.size() || child_list.size() > UINT8_MAX) {
            LOGW("ObjectContainer can only add %ud child objects", UINT8_MAX);
            return;
        }
        const std::vector<Object, std::allocator<Object>>::const_iterator &end = child_list.cend();
        uint8_t i(0);
        std::vector<Object, std::allocator<Object>>::const_iterator position = end;
        for (auto iterator = child_list.cbegin(); iterator != end; ++iterator) {
            if (index == i++) {
                position = iterator;
                break;
            }
        }
        child_list.insert(position, object);
    }

    void ObjectContainer::RemoveChild(Object &object) {
        const std::vector<Object, std::allocator<Object>>::const_iterator &end = child_list.cend();
        for (auto iterator = child_list.cbegin(); iterator != end; ++iterator) {
            if (&object == &*iterator) {
                child_list.erase(iterator);
                break;
            }
        }
    }

    void ObjectContainer::RemoveChildAt(uint8_t index) {
        if (index > child_list.size() - 1) {
            return;
        }
        const std::vector<Object, std::allocator<Object>>::const_iterator &end = child_list.cend();
        uint8_t i(0);
        std::vector<Object, std::allocator<Object>>::const_iterator position = end;
        for (auto iterator = child_list.cbegin(); iterator != end; ++iterator) {
            if (index == i++) {
                position = iterator;
                break;
            }
        }
        child_list.erase(position);
    }

    uint8_t ObjectContainer::Size() {
        return 0;
    }

    void Sphere::Build() {

    }
UNKNOWN_NS_END
