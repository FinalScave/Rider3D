//
// Created by Scave on 2023/11/10.
//
#pragma once
#include <jni.h>
#include "Supposition.h"
#include "JNativeConverter.h"
#include "JRefHolder.h"

class NdcPointJni {
public:
    static void DestroyNdcPoint(jlong ptr) {
        auto *holder = ToNativePointer<JObjectCopier<NdcPoint>>(ptr);
        DELETE_PTR(holder);
    }

    static jlong MakeNdcPoint(jfloat x, jfloat y, jfloat z) {
        NdcPoint point{x, y, z};
        JObjectCopier<NdcPoint>* holder = new JObjectCopier<NdcPoint>(point);
        return ToJavaObject(holder);
    }

    static void SetPointX(jlong ptr, jfloat x) {
        auto *holder = ToNativePointer<JObjectCopier<NdcPoint>>(ptr);
        holder->Get().x = x;
    }

    static void SetPointY(jlong ptr, jfloat y) {
        auto *holder = ToNativePointer<JObjectCopier<NdcPoint>>(ptr);
        holder->Get().y = y;
    }

    static void SetPointZ(jlong ptr, jfloat z) {
        auto *holder = ToNativePointer<JObjectCopier<NdcPoint>>(ptr);
        holder->Get().z = z;
    }

    constexpr static const char *point_name = "com/unknown/core/supposition/NdcPoint";
    constexpr static const JNINativeMethod point_methods[] = {
            {"nativeDestroy", "(J)V", (void*) DestroyNdcPoint},
            {"nativeMakeNdcPoint", "(FFF)J", (void*) MakeNdcPoint},
            {"nativeSetX", "(JF)V", (void*) SetPointX},
            {"nativeSetY", "(JF)V", (void*) SetPointY},
            {"nativeSetZ", "(JF)V", (void*) SetPointZ},
    };

    void RegisterNdcPointMethods(JNIEnv *env) {
        jclass point_class = env->FindClass(point_name);
        env->RegisterNatives(point_class, point_methods,
                             sizeof(point_methods) / sizeof(JNINativeMethod));
    }
};

class ColorJni {
public:
    static void DestroyColor(jlong ptr) {
        auto *holder = ToNativePointer<JObjectCopier<Color>>(ptr);
        DELETE_PTR(holder);
    }

    static jlong MakeColor(jfloat r, jfloat g, jfloat b, jfloat a) {
        Color color{r, g, b, a};
        JObjectCopier<Color>* holder = new JObjectCopier<Color>(color);
        return ToJavaObject(holder);
    }

    static void SetColorValue(jlong ptr, jfloat r, jfloat g, jfloat b, jfloat a) {
        auto *holder = ToNativePointer<JObjectCopier<Color>>(ptr);
        Color& color = holder->Get();
        color.r = r;
        color.g = g;
        color.b = b;
        color.a = a;
    }

    static constexpr const char *color_name = "com/unknown/core/supposition/Color";
    constexpr static const JNINativeMethod color_methods[] = {
            {"nativeDestroy", "(J)V", (void*) DestroyColor},
            {"nativeMakeColor", "(FFFF)J", (void*) MakeColor},
            {"nativeSetValue", "(JFFFF)V", (void*) SetColorValue},
    };

    void RegisterColorMethods(JNIEnv *env) {
        jclass color_class = env->FindClass(color_name);
        env->RegisterNatives(color_class, color_methods,
                             sizeof(color_methods) / sizeof(JNINativeMethod));
    }
};

class UVJni {
public:
    static void DestroyUv(jlong ptr) {
        auto *holder = ToNativePointer<JObjectCopier<NdcPoint>>(ptr);
        DELETE_PTR(holder);
    }

    static jlong MakeUv(jfloat u, jfloat v) {
        UV uv{u, v};
        JObjectCopier<UV>* holder = new JObjectCopier<UV>(uv);
        return ToJavaObject(holder);
    }

    static void SetU(jlong ptr, jfloat u) {
        auto *holder = ToNativePointer<JObjectCopier<UV>>(ptr);
        holder->Get().u = u;
    }

    static void SetV(jlong ptr, jfloat v) {
        auto *holder = ToNativePointer<JObjectCopier<UV>>(ptr);
        holder->Get().v = v;
    }

    static constexpr const char *uv_name = "com/unknown/core/supposition/UV";
    constexpr static const JNINativeMethod uv_methods[] = {
            {"nativeDestroy", "(J)V", (void*) DestroyUv},
            {"nativeMakeUV", "(FF)J", (void*) MakeUv},
            {"nativeSetU", "(JF)V", (void*) SetU},
            {"nativeSetV", "(JF)V", (void*) SetV},
    };

    void RegisterUvMethods(JNIEnv *env) {
        jclass uv_class = env->FindClass(uv_name);
        env->RegisterNatives(uv_class, uv_methods,
                             sizeof(uv_methods) / sizeof(JNINativeMethod));
    }
};