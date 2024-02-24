//
// Created by Scave on 2023/11/10.
//
#pragma once
#include <jni.h>
#include "JNativeConverter.h"
#include "JObjectHolder.h"
#include "BasicComponents.h"

void DestroyCamera(jlong ptr) {
    auto *holder = ToNativePointer<JObjectHolder<Camera>>(ptr);
    DELETE_PTR(holder);
}

jlong MakeCamera(jlong pos_ptr, jlong target_ptr, jlong axis_ptr) {
    auto *pos = ToNativePointer<JObjectHolder<NdcPoint>>(pos_ptr);
    auto *target = ToNativePointer<JObjectHolder<NdcPoint>>(target_ptr);
    auto *up_axis = ToNativePointer<JObjectHolder<NdcPoint>>(axis_ptr);
    Camera camera{pos->Get(), target->Get(), up_axis->Get()};
    JObjectHolder<Camera>* holder = new JObjectHolder<Camera>(camera);
    return ToJavaObject(holder);
}

void SetCameraPosition(jlong ptr, jlong position_ptr) {
    auto *holder = ToNativePointer<JObjectHolder<Camera>>(ptr);
    holder->Get().position = ToNativePointer<JObjectHolder<NdcPoint>>(position_ptr)->Get();
}

void SetTarget(jlong ptr, jlong target_ptr) {
    auto *holder = ToNativePointer<JObjectHolder<Camera>>(ptr);
    holder->Get().position = ToNativePointer<JObjectHolder<NdcPoint>>(target_ptr)->Get();
}

void SetUpAxis(jlong ptr, jlong axis_ptr) {
    auto *holder = ToNativePointer<JObjectHolder<Camera>>(ptr);
    holder->Get().position = ToNativePointer<JObjectHolder<NdcPoint>>(axis_ptr)->Get();
}

constexpr const char *camera_name = "com/unknown/component/Camera";
static const JNINativeMethod camera_methods[] = {
        {"nativeDestroy", "(J)V", (void*) DestroyCamera},
        {"nativeMakeCamera", "(JJJ)J", (jlong*) MakeCamera},
        {"nativeSetPosition", "(JJ)V", (void*) SetCameraPosition},
        {"nativeSetTarget", "(JJ)V", (void*) SetTarget},
        {"nativeSetUpAxis", "(JJ)V", (void*) SetUpAxis},
};

void register_camera_jni(JNIEnv *env) {
    jclass camera_class = env->FindClass(camera_name);
    env->RegisterNatives(camera_class, camera_methods,
                         sizeof(camera_methods) / sizeof(JNINativeMethod));
}