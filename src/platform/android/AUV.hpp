#include <jni.h>

//
// Created by Scave on 2023/11/10.
//
#pragma once
#include "Supposition.h"
#include "JNativeConverter.h"
#include "JObjectHolder.h"

void DestroyUv(jlong ptr) {
    auto *holder = ToNativePointer<JObjectHolder<NdcPoint>>(ptr);
    DELETE_PTR(holder);
}

jlong MakeUv(jfloat u, jfloat v) {
    UV uv{u, v};
    JObjectHolder<UV>* holder = new JObjectHolder<UV>(uv);
    return ToJavaObject(holder);
}

void SetU(jlong ptr, jfloat u) {
    auto *holder = ToNativePointer<JObjectHolder<UV>>(ptr);
    holder->Get().u = u;
}

void SetV(jlong ptr, jfloat v) {
    auto *holder = ToNativePointer<JObjectHolder<UV>>(ptr);
    holder->Get().v = v;
}

constexpr const char *uv_name = "com/unknown/core/supposition/UV";
static const JNINativeMethod uv_methods[] = {
        {"nativeDestroy", "(J)V", (void*) DestroyUv},
        {"nativeMakeUV", "(FF)J", (void*) MakeUv},
        {"nativeSetU", "(JF)V", (void*) SetU},
        {"nativeSetV", "(JF)V", (void*) SetV},
};

void register_uv_jni(JNIEnv *env) {
    jclass uv_class = env->FindClass(uv_name);
    env->RegisterNatives(uv_class, uv_methods,
                         sizeof(uv_methods) / sizeof(JNINativeMethod));
}