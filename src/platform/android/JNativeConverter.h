//
// Created by Scave on 2023/11/10.
//

#ifndef UNKNOWN3D_JNATIVECONVERTER_H
#define UNKNOWN3D_JNATIVECONVERTER_H

#include <jni.h>
#include "UnknownEngine.h"

NS_UNKNOWN::Unknown3DEngine* To3DEngineNativeObject(jlong address);

jlong To3DEngineJavaObject(NS_UNKNOWN::Unknown3DEngine* engine);

template<class T>
inline jlong ToJavaObject(T* ptr) {
    return (jlong) ptr;
}

template<class T>
inline T* ToNativeObject(jlong address) {
    return (T*) address;
}

#endif //UNKNOWN3D_JNATIVECONVERTER_H
