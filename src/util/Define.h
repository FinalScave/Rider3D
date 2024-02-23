//
// Created by Scave on 2023/11/8.
//

#ifndef UNKNOWN3D_DEFINE_H
#define UNKNOWN3D_DEFINE_H

#include <memory>
#include <string>
#include <unordered_map>

#define NS_UNKNOWN unknown
#define UNKNOWN_NS_BEGIN namespace NS_UNKNOWN {
#define UNKNOWN_NS_END }

typedef uint64_t UInt64;
typedef uint32_t UInt32;
typedef uint16_t UInt16;
typedef uint8_t UInt8;
typedef std::string Name;
typedef std::string String;
typedef std::byte Byte;
#define PAIR std::pair
#define HASHMAP std::unordered_map

#define SMART_PTR std::shared_ptr
#define MAKE_SMART_PTR std::make_shared

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

#endif //UNKNOWN3D_DEFINE_H
