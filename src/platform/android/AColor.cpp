#include <jni.h>

//
// Created by Scave on 2023/11/10.
//

#include "Supposition.h"
#include "JNativeConverter.h"

extern "C"
JNIEXPORT jlong JNICALL
Java_com_unknown_core_Color_nativeMakeColor(JNIEnv *env, jclass clazz, jfloat a, jfloat r,
                                              jfloat g, jfloat b) {
    auto *color = new NS_UNKNOWN::Color {r, g, b ,a};
    return ToJavaObject<NS_UNKNOWN::Color>(color);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_unknown_core_Color_nativeSetValue(JNIEnv *env, jclass clazz, jlong ptr, jfloat a,
                                             jfloat r, jfloat g, jfloat b) {
    auto *color = ToNativePointer<NS_UNKNOWN::Color>(ptr);
    color->r = r;
    color->g = g;
    color->b = b;
    color->a = a;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_unknown_core_Color_nativeDestroy(JNIEnv *env, jclass clazz, jlong ptr) {
    auto *color = ToNativePointer<NS_UNKNOWN::Color>(ptr);
    DELETE_PTR(color);
}