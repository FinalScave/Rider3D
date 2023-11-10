#include <jni.h>

//
// Created by Scave on 2023/11/10.
//

#include "data/Object3D.h"
#include "JNativeConverter.h"

extern "C" {
JNIEXPORT jlong JNICALL
Java_com_unknown_object_NdcPoint_nativeMakeNdcPoint(JNIEnv *env, jclass clazz, jfloat x, jfloat y,
                                                    jfloat z) {
    auto* point = new NS_UNKNOWN::NdcPoint {x, y, z};
    return ToJavaObject<NS_UNKNOWN::NdcPoint>(point);
}

JNIEXPORT void JNICALL
Java_com_unknown_object_NdcPoint_nativeSetX(JNIEnv *env, jclass clazz, jlong ptr, jfloat x) {
    auto* point = ToNativeObject<NS_UNKNOWN::NdcPoint>(ptr);
    point->x = x;
}

JNIEXPORT void JNICALL
Java_com_unknown_object_NdcPoint_nativeSetY(JNIEnv *env, jclass clazz, jlong ptr, jfloat y) {
    auto* point = ToNativeObject<NS_UNKNOWN::NdcPoint>(ptr);
    point->y = y;
}

JNIEXPORT void JNICALL
Java_com_unknown_object_NdcPoint_nativeSetZ(JNIEnv *env, jclass clazz, jlong ptr, jfloat z) {
    auto* point = ToNativeObject<NS_UNKNOWN::NdcPoint>(ptr);
    point->z = z;
}

JNIEXPORT void JNICALL
Java_com_unknown_object_NdcPoint_nativeDestroy(JNIEnv *env, jclass clazz, jlong ptr) {
    auto* point = ToNativeObject<NS_UNKNOWN::NdcPoint>(ptr);
    DELETE_PTR(point);
}

}