#include <jni.h>

//
// Created by Scave on 2023/11/10.
//

#include "Supposition.h"
#include "JNativeConverter.h"
#include "JObjectHolder.h"

void DestroyNdcPoint(jlong ptr) {
    auto *holder = ToNativePointer<JObjectHolder<NdcPoint>>(ptr);
    DELETE_PTR(holder);
}

jlong MakeNdcPoint(jfloat x, jfloat y, jfloat z) {
    NdcPoint point{x, y, z};
    JObjectHolder<NdcPoint>* holder = new JObjectHolder<NdcPoint>(point);
    return ToJavaObject(holder);
}

void SetPointX(jlong ptr, jfloat x) {
    auto *holder = ToNativePointer<JObjectHolder<NdcPoint>>(ptr);
    holder->Get().x = x;
}

void SetPointY(jlong ptr, jfloat y) {
    auto *holder = ToNativePointer<JObjectHolder<NdcPoint>>(ptr);
    holder->Get().y = y;
}

void SetPointZ(jlong ptr, jfloat z) {
    auto *holder = ToNativePointer<JObjectHolder<NdcPoint>>(ptr);
    holder->Get().z = z;
}

constexpr const char *point_name = "com/unknown/core/supposition/NdcPoint";
static const JNINativeMethod point_methods[] = {
        {"nativeDestroy", "(J)V", (void*) DestroyNdcPoint},
        {"nativeMakeNdcPoint", "(FFF)J", (void*) MakeNdcPoint},
        {"nativeSetX", "(JF)V", (void*) SetPointX},
        {"nativeSetY", "(JF)V", (void*) SetPointY},
        {"nativeSetZ", "(JF)V", (void*) SetPointZ},
};

void register_point_jni(JNIEnv *env) {
    jclass point_class = env->FindClass(point_name);
    env->RegisterNatives(point_class, point_methods,
                         sizeof(point_methods) / sizeof(JNINativeMethod));
}