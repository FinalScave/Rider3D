//
// Created by Scave on 2023/11/10.
//
#pragma once
#include <jni.h>
#include "JNativeConverter.h"
#include "JObjectHolder.h"
#include "BasicComponents.h"

void DestroyTransform(jlong ptr) {
    auto *holder = ToNativePointer<JObjectHolder<Transform>>(ptr);
    DELETE_PTR(holder);
}

jlong MakeTransform(jlong translation_ptr, jlong rotation_ptr, jlong scale_ptr) {
    auto *translation = ToNativePointer<JObjectHolder<NdcPoint>>(translation_ptr);
    auto *rotation = ToNativePointer<JObjectHolder<NdcPoint>>(rotation_ptr);
    auto *scale = ToNativePointer<JObjectHolder<NdcPoint>>(scale_ptr);
    Transform transform{translation->Get(), rotation->Get(), scale->Get()};
    JObjectHolder<Transform>* holder = new JObjectHolder<Transform>(transform);
    return ToJavaObject(holder);
}

void SetTranslation(jlong ptr, jlong translation_ptr) {
    auto *holder = ToNativePointer<JObjectHolder<Transform>>(ptr);
    holder->Get().translation = ToNativePointer<JObjectHolder<NdcPoint>>(translation_ptr)->Get();
}

void SetRotation(jlong ptr, jlong rotation_ptr) {
    auto *holder = ToNativePointer<JObjectHolder<Transform>>(ptr);
    holder->Get().rotation = ToNativePointer<JObjectHolder<NdcPoint>>(rotation_ptr)->Get();
}

void SetScale(jlong ptr, jlong scale_ptr) {
    auto *holder = ToNativePointer<JObjectHolder<Transform>>(ptr);
    holder->Get().scale = ToNativePointer<JObjectHolder<NdcPoint>>(scale_ptr)->Get();
}

constexpr const char *transform_name = "com/unknown/component/Transform";
static const JNINativeMethod transform_methods[] = {
        {"nativeDestroy", "(J)V", (void*) DestroyTransform},
        {"nativeMakeTransform", "(JJJ)J", (jlong*) MakeTransform},
        {"nativeSetTranslation", "(JJ)V", (void*) SetTranslation},
        {"nativeSetRotation", "(JJ)V", (void*) SetRotation},
        {"nativeSetScale", "(JJ)V", (void*) SetScale},
};

void register_transform_jni(JNIEnv *env) {
    jclass transform_class = env->FindClass(transform_name);
    env->RegisterNatives(transform_class, transform_methods,
                         sizeof(transform_methods) / sizeof(JNINativeMethod));
}