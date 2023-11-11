#include <jni.h>

//
// Created by Scave on 2023/11/10.
//

#include "object/Supposition.h"
#include "JNativeConverter.h"

extern "C"
JNIEXPORT jlong JNICALL
Java_com_unknown_object_UV_nativeMakeUV(JNIEnv *env, jclass clazz, jfloat u, jfloat v) {
    auto *uv = new NS_UNKNOWN::TextureUVPoint {u, v};
    return ToJavaObject<NS_UNKNOWN::TextureUVPoint>(uv);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_unknown_object_UV_nativeSetU(JNIEnv *env, jclass clazz, jlong ptr, jfloat u) {
    auto* uv = ToNativeObject<NS_UNKNOWN::TextureUVPoint>(ptr);
    uv->u = u;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_unknown_object_UV_nativeSetV(JNIEnv *env, jclass clazz, jlong ptr, jfloat v) {
    auto* uv = ToNativeObject<NS_UNKNOWN::TextureUVPoint>(ptr);
    uv->v = v;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_unknown_object_UV_nativeDestroy(JNIEnv *env, jclass clazz, jlong ptr) {
    auto* uv = ToNativeObject<NS_UNKNOWN::TextureUVPoint>(ptr);
    DELETE_PTR(uv);
}