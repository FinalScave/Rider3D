//
// Created by Scave on 2023/11/8.
//

#ifndef UNKNOWN3D_DEFINE_H
#define UNKNOWN3D_DEFINE_H

#include <memory>

#define NS_UNKNOWN unknown
#define UNKNOWN_NS_BEGIN namespace NS_UNKNOWN {
#define UNKNOWN_NS_END }

#define SMART_PTR std::shared_ptr
#define MAKE_SMART_PTR std::make_shared

#define DELETE_PTR(ptr) \
    delete ptr;         \

#define DELETE_ARRAY(array) \
if (array != nullptr) {     \
    delete[] array;         \
}

#define DESTROY_MEMBER_BGFX_HANDLE(handle) \
if (bgfx::isValid(handle)) {       \
    bgfx::destroy(handle);                 \
    handle = BGFX_INVALID_HANDLE;          \
}

#endif //UNKNOWN3D_DEFINE_H
