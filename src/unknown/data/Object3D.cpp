//
// Created by Scave on 2023/11/10.
//

#include "Object3D.h"
#include "LogUtil.h"

UNKNOWN_NS_BEGIN

    Object3D::~Object3D() {
        DELETE_PTR(position);
        DELETE_PTR(rotation);
        DELETE_PTR(scale);
        DELETE_PTR(vertices);
    }

    void Object3DContainer::AddChild(Object3D &object) {
        if (child_list.size() >= UINT8_MAX) {
            LOGW("Object3DContainer can only add %ud child objects", UINT8_MAX);
            return;
        }
        child_list.push_back(object);
    }

    void Object3DContainer::AddChildAt(uint8_t index, Object3D &object) {
        if (index > child_list.size() || child_list.size() > UINT8_MAX) {
            LOGW("Object3DContainer can only add %ud child objects", UINT8_MAX);
            return;
        }
        const std::vector<Object3D, std::allocator<Object3D>>::const_iterator &end = child_list.cend();
        uint8_t i(0);
        std::vector<Object3D, std::allocator<Object3D>>::const_iterator position = end;
        for (auto iterator = child_list.cbegin(); iterator != end; ++iterator) {
            if (index == i++) {
                position = iterator;
                break;
            }
        }
        child_list.insert(position, object);
    }

    void Object3DContainer::RemoveChild(Object3D &object) {
        const std::vector<Object3D, std::allocator<Object3D>>::const_iterator &end = child_list.cend();
        for (auto iterator = child_list.cbegin(); iterator != end; ++iterator) {
            if (&object == &*iterator) {
                child_list.erase(iterator);
                break;
            }
        }
    }

    void Object3DContainer::RemoveChildAt(uint8_t index) {
        if (index > child_list.size() - 1) {
            LOGW("index can not greater than %ud", UINT8_MAX - 1);
            return;
        }
        const std::vector<Object3D, std::allocator<Object3D>>::const_iterator &end = child_list.cend();
        uint8_t i(0);
        std::vector<Object3D, std::allocator<Object3D>>::const_iterator position = end;
        for (auto iterator = child_list.cbegin(); iterator != end; ++iterator) {
            if (index == i++) {
                position = iterator;
                break;
            }
        }
        child_list.erase(position);
    }

    uint8_t Object3DContainer::Size() {
        return child_list.size();
    }

    void Sphere::Build() {

    }
UNKNOWN_NS_END

