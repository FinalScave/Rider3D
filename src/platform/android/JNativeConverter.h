//
// Created by Scave on 2023/11/10.
//

#ifndef RIDER3D_JNATIVECONVERTER_H
#define RIDER3D_JNATIVECONVERTER_H

#include <jni.h>
#include "RiderEngine.h"

using namespace NS_UNKNOWN;

UnknownEngine* ToEngineNativePointer(jlong address);

jlong ToEngineJavaObject(UnknownEngine *engine);

template<class T>
inline jlong ToJavaObject(T* ptr) {
    return (jlong) ptr;
}

template<class T>
inline T* ToNativePointer(jlong address) {
    return (T*) address;
}

template<class T>
inline T ToNativeObject(jlong& address) {
    return (T) address;
}

#endif //RIDER3D_JNATIVECONVERTER_H
