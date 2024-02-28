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
        auto *holder = ToNativePointer<JUniqueCopier<NdcPoint>>(ptr);
        DELETE_PTR(holder);
    }

    static jlong MakeNdcPoint(jfloat x, jfloat y, jfloat z) {
        NdcPoint point{x, y, z};
        JUniqueCopier<NdcPoint>* holder = new JUniqueCopier<NdcPoint>(point);
        return ToJavaObject(holder);
    }

    static void SetPointX(jlong ptr, jfloat x) {
        auto *holder = ToNativePointer<JUniqueCopier<NdcPoint>>(ptr);
        holder->Get().x = x;
    }

    static void SetPointY(jlong ptr, jfloat y) {
        auto *holder = ToNativePointer<JUniqueCopier<NdcPoint>>(ptr);
        holder->Get().y = y;
    }

    static void SetPointZ(jlong ptr, jfloat z) {
        auto *holder = ToNativePointer<JUniqueCopier<NdcPoint>>(ptr);
        holder->Get().z = z;
    }

    static jlong Add(jlong p1_ptr, jlong p2_ptr) {
        auto &p1 = ToNativePointer<JUniqueCopier<NdcPoint>>(p1_ptr)->Get();
        auto &p2 = ToNativePointer<JUniqueCopier<NdcPoint>>(p2_ptr)->Get();
        JUniqueCopier<NdcPoint>* r = new JUniqueCopier<NdcPoint>(NdcPoint::Add(p1, p2));
        return ToJavaObject(r);
    }

    static jlong Sub(jlong p1_ptr, jlong p2_ptr) {
        auto &p1 = ToNativePointer<JUniqueCopier<NdcPoint>>(p1_ptr)->Get();
        auto &p2 = ToNativePointer<JUniqueCopier<NdcPoint>>(p2_ptr)->Get();
        JUniqueCopier<NdcPoint>* r = new JUniqueCopier<NdcPoint>(NdcPoint::Sub(p1, p2));
        return ToJavaObject(r);
    }

    static jlong Scalar(jlong p1_ptr, jfloat f) {
        auto &p1 = ToNativePointer<JUniqueCopier<NdcPoint>>(p1_ptr)->Get();
        JUniqueCopier<NdcPoint>* r = new JUniqueCopier<NdcPoint>(NdcPoint::Scalar(p1, f));
        return ToJavaObject(r);
    }

    static jfloat Dot(jlong p1_ptr, jlong p2_ptr) {
        auto &p1 = ToNativePointer<JUniqueCopier<NdcPoint>>(p1_ptr)->Get();
        auto &p2 = ToNativePointer<JUniqueCopier<NdcPoint>>(p2_ptr)->Get();
        return NdcPoint::Dot(p1, p2);
    }

    static jlong Cross(jlong p1_ptr, jlong p2_ptr) {
        auto &p1 = ToNativePointer<JUniqueCopier<NdcPoint>>(p1_ptr)->Get();
        auto &p2 = ToNativePointer<JUniqueCopier<NdcPoint>>(p2_ptr)->Get();
        JUniqueCopier<NdcPoint>* r = new JUniqueCopier<NdcPoint>(NdcPoint::Cross(p1, p2));
        return ToJavaObject(r);
    }

    static jlong Normalize(jlong p_ptr) {
        auto &p1 = ToNativePointer<JUniqueCopier<NdcPoint>>(p_ptr)->Get();
        JUniqueCopier<NdcPoint>* r = new JUniqueCopier<NdcPoint>(NdcPoint::Normalize(p1));
        return ToJavaObject(r);
    }


    static jfloat Length(jlong p_ptr) {
        auto &p1 = ToNativePointer<JUniqueCopier<NdcPoint>>(p_ptr)->Get();
        return NdcPoint::Length(p1);
    }

    static jfloat Distance(jlong p1_ptr, jlong p2_ptr) {
        auto &p1 = ToNativePointer<JUniqueCopier<NdcPoint>>(p1_ptr)->Get();
        auto &p2 = ToNativePointer<JUniqueCopier<NdcPoint>>(p2_ptr)->Get();
        return NdcPoint::Distance(p1, p2);
    }

    constexpr static const char *point_name = "com/rider/core/supposition/NdcPoint";
    constexpr static const JNINativeMethod point_methods[] = {
            {"nativeDestroy", "(J)V", (void*) DestroyNdcPoint},
            {"nativeMakeNdcPoint", "(FFF)J", (void*) MakeNdcPoint},
            {"nativeSetX", "(JF)V", (void*) SetPointX},
            {"nativeSetY", "(JF)V", (void*) SetPointY},
            {"nativeSetZ", "(JF)V", (void*) SetPointZ},
            {"nativeAdd", "(JJ)J", (void*) Add},
            {"nativeSub", "(JJ)J", (void*) Sub},
            {"nativeScalar", "(JF)J", (void*) Scalar},
            {"nativeDot", "(JJ)F", (void*) Dot},
            {"nativeCross", "(JJ)J", (void*) Cross},
            {"nativeNormalize", "(J)J", (void*) Normalize},
            {"nativeLength", "(J)F", (void*) Length},
            {"nativeDistance", "(JJ)F", (void*) Distance},
    };

    static void RegisterNdcPointMethods(JNIEnv *env) {
        jclass point_class = env->FindClass(point_name);
        env->RegisterNatives(point_class, point_methods,
                             sizeof(point_methods) / sizeof(JNINativeMethod));
    }
};

class ColorJni {
public:
    static void DestroyColor(jlong ptr) {
        auto *holder = ToNativePointer<JUniqueCopier<Color>>(ptr);
        DELETE_PTR(holder);
    }

    static jlong MakeColor(jfloat r, jfloat g, jfloat b, jfloat a) {
        Color color{r, g, b, a};
        JUniqueCopier<Color>* holder = new JUniqueCopier<Color>(color);
        return ToJavaObject(holder);
    }

    static void SetColorValue(jlong ptr, jfloat r, jfloat g, jfloat b, jfloat a) {
        auto *holder = ToNativePointer<JUniqueCopier<Color>>(ptr);
        Color& color = holder->Get();
        color.r = r;
        color.g = g;
        color.b = b;
        color.a = a;
    }

    static constexpr const char *color_name = "com/rider/core/supposition/Color";
    constexpr static const JNINativeMethod color_methods[] = {
            {"nativeDestroy", "(J)V", (void*) DestroyColor},
            {"nativeMakeColor", "(FFFF)J", (void*) MakeColor},
            {"nativeSetValue", "(JFFFF)V", (void*) SetColorValue},
    };

    static void RegisterColorMethods(JNIEnv *env) {
        jclass color_class = env->FindClass(color_name);
        env->RegisterNatives(color_class, color_methods,
                             sizeof(color_methods) / sizeof(JNINativeMethod));
    }
};

class UVJni {
public:
    static void DestroyUv(jlong ptr) {
        auto *holder = ToNativePointer<JUniqueCopier<NdcPoint>>(ptr);
        DELETE_PTR(holder);
    }

    static jlong MakeUv(jfloat u, jfloat v) {
        UV uv{u, v};
        JUniqueCopier<UV>* holder = new JUniqueCopier<UV>(uv);
        return ToJavaObject(holder);
    }

    static void SetU(jlong ptr, jfloat u) {
        auto *holder = ToNativePointer<JUniqueCopier<UV>>(ptr);
        holder->Get().u = u;
    }

    static void SetV(jlong ptr, jfloat v) {
        auto *holder = ToNativePointer<JUniqueCopier<UV>>(ptr);
        holder->Get().v = v;
    }

    static constexpr const char *uv_name = "com/rider/core/supposition/UV";
    constexpr static const JNINativeMethod uv_methods[] = {
            {"nativeDestroy", "(J)V", (void*) DestroyUv},
            {"nativeMakeUV", "(FF)J", (void*) MakeUv},
            {"nativeSetU", "(JF)V", (void*) SetU},
            {"nativeSetV", "(JF)V", (void*) SetV},
    };

    static void RegisterUvMethods(JNIEnv *env) {
        jclass uv_class = env->FindClass(uv_name);
        env->RegisterNatives(uv_class, uv_methods,
                             sizeof(uv_methods) / sizeof(JNINativeMethod));
    }
};