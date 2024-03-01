#pragma once
#include "RiderEngine.h"
#define NATIVE_PTR long long

using namespace NS_RIDER;

RiderEngine* ToEngineNativePointer(NATIVE_PTR address);

NATIVE_PTR ToEngineJsObject(RiderEngine* engine);

template<class T>
inline NATIVE_PTR ToJsObject(T* ptr) {
    return (NATIVE_PTR) ptr;
}

template<class T>
inline T* ToNativePointer(NATIVE_PTR address) {
    return (T*) address;
}