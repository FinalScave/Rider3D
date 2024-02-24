#include <jni.h>

//
// Created by Scave on 2023/11/10.
//
#pragma once
#include "Supposition.h"
#include "JNativeConverter.h"
#include "JObjectHolder.h"

void DestroyColor(jlong ptr) {
    auto *holder = ToNativePointer<JObjectHolder<Color>>(ptr);
    DELETE_PTR(holder);
}

jlong MakeColor(jfloat r, jfloat g, jfloat b, jfloat a) {
    Color color{r, g, b, a};
    JObjectHolder<Color>* holder = new JObjectHolder<Color>(color);
    return ToJavaObject(holder);
}

void SetColorValue(jlong ptr, jfloat r, jfloat g, jfloat b, jfloat a) {
    auto *holder = ToNativePointer<JObjectHolder<Color>>(ptr);
    Color& color = holder->Get();
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
}

constexpr const char *color_name = "com/unknown/core/supposition/Color";
static const JNINativeMethod color_methods[] = {
        {"nativeDestroy", "(J)V", (void*) DestroyColor},
        {"nativeMakeColor", "(FFFF)J", (void*) MakeColor},
        {"nativeSetValue", "(JFFFF)V", (void*) SetColorValue},
};

void register_color_jni(JNIEnv *env) {
    jclass color_class = env->FindClass(color_name);
    env->RegisterNatives(color_class, color_methods,
                         sizeof(color_methods) / sizeof(JNINativeMethod));
}