//
// Created by Scave on 2023/11/8.
//

#ifndef RIDER3D_DEFINE_H
#define RIDER3D_DEFINE_H

#include <memory>
#include <string>
#include <unordered_map>

#define NS_RIDER rider
#define NS_RIDER_BEGIN namespace NS_RIDER {
#define NS_RIDER_END }

typedef uint64_t UInt64;
typedef uint32_t UInt32;
typedef uint16_t UInt16;
typedef uint8_t UInt8;
typedef std::string Name;
typedef std::string String;

#define ENTITY_SIZE_TYPE uint8_t
#define ENTITY_SIZE_MAX UINT8_MAX
#define TEXTURE_ID_TYPE uint16_t
#define PAIR std::pair
#define HASHMAP std::unordered_map

#define SMART_PTR std::shared_ptr
#define MAKE_SMART_PTR std::make_shared

#define NULL_RETURN(expr) \
if (expr == nullptr) {    \
    return;               \
}

#define DELETE_PTR(ptr) \
if (ptr != nullptr) {   \
    delete ptr;         \
}

#define SAFE_DELETE_PTR(ptr) \
if (ptr != nullptr) {   \
    delete ptr;         \
    ptr = nullptr;      \
}

#define DELETE_ARRAY(array) \
if (array != nullptr) {     \
    delete[] array;         \
}

#define SAFE_DELETE_ARRAY(array) \
if (array != nullptr) {     \
    delete[] array;         \
    array = nullptr;        \
}

#define DESTROY_MEMBER_BGFX_HANDLE(handle) \
if (bgfx::isValid(handle)) {       \
    bgfx::destroy(handle);                 \
    handle = BGFX_INVALID_HANDLE;          \
}

#endif //RIDER3D_DEFINE_H
