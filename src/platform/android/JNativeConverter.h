//
// Created by Scave on 2023/11/10.
//

#ifndef UNKNOWN3D_JNATIVECONVERTER_H
#define UNKNOWN3D_JNATIVECONVERTER_H

#include <jni.h>
#include "UnknownEngine.h"

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

#endif //UNKNOWN3D_JNATIVECONVERTER_H
