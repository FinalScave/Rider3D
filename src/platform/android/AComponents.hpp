//
// Created by Scave on 2023/11/10.
//
#pragma once

#include <jni.h>
#include "JNativeConverter.h"
#include "JRefHolder.h"
#include "BasicComponents.h"

class CameraJni {
public:
    static void DestroyCamera(jlong ptr) {
        auto *holder = ToNativePointer<Camera>(ptr);
        DELETE_PTR(holder);
    }

    /*static jlong MakeCamera(jlong pos_ptr, jlong target_ptr, jlong axis_ptr) {
        auto *pos = ToNativePointer<JObjectCopier<NdcPoint>>(pos_ptr);
        auto *target = ToNativePointer<JObjectCopier<NdcPoint>>(target_ptr);
        auto *up_axis = ToNativePointer<JObjectCopier<NdcPoint>>(axis_ptr);
        Camera camera{pos->Get(), target->Get(), up_axis->Get()};
        JObjectCopier<Camera>* holder = new JObjectCopier<Camera>(camera);
        return ToJavaObject(holder);
    }*/

    static void SetCameraPosition(jlong ptr, jlong position_ptr) {
        auto *holder = ToNativePointer<Camera>(ptr);
        holder->position = ToNativePointer<JObjectCopier<NdcPoint>>(position_ptr)->Get();
    }

    static void SetTarget(jlong ptr, jlong target_ptr) {
        auto *holder = ToNativePointer<Camera>(ptr);
        holder->position = ToNativePointer<JObjectCopier<NdcPoint>>(target_ptr)->Get();
    }

    static void SetUpAxis(jlong ptr, jlong axis_ptr) {
        auto *holder = ToNativePointer<Camera>(ptr);
        holder->position = ToNativePointer<JObjectCopier<NdcPoint>>(axis_ptr)->Get();
    }

    static constexpr const char *camera_name = "com/unknown/component/Camera";
    constexpr static const JNINativeMethod camera_methods[] = {
            {"nativeDestroy", "(J)V", (void*) DestroyCamera},
            //{"nativeMakeCamera", "(JJJ)J", (void*) MakeCamera},
            {"nativeSetPosition", "(JJ)V", (void*) SetCameraPosition},
            {"nativeSetTarget", "(JJ)V", (void*) SetTarget},
            {"nativeSetUpAxis", "(JJ)V", (void*) SetUpAxis},
    };

    void RegisterCameraMethods(JNIEnv *env) {
        jclass camera_class = env->FindClass(camera_name);
        env->RegisterNatives(camera_class, camera_methods,
                             sizeof(camera_methods) / sizeof(JNINativeMethod));
    }
};

class TransformJni {
public:
    static void DestroyTransform(jlong ptr) {
        auto *holder = ToNativePointer<Transform>(ptr);
        DELETE_PTR(holder);
    }

    /*static jlong MakeTransform(jlong translation_ptr, jlong rotation_ptr, jlong scale_ptr) {
        auto *translation = ToNativePointer<JObjectCopier<NdcPoint>>(translation_ptr);
        auto *rotation = ToNativePointer<JObjectCopier<NdcPoint>>(rotation_ptr);
        auto *scale = ToNativePointer<JObjectCopier<NdcPoint>>(scale_ptr);
        Transform transform{translation->Get(), rotation->Get(), scale->Get()};
        JObjectCopier<Transform> *holder = new JObjectCopier<Transform>(transform);
        return ToJavaObject(holder);
    }*/

    static void SetTranslation(jlong ptr, jlong translation_ptr) {
        auto *holder = ToNativePointer<Transform>(ptr);
        holder->translation = ToNativePointer<JObjectCopier<NdcPoint>>(
                translation_ptr)->Get();
    }

    static void SetRotation(jlong ptr, jlong rotation_ptr) {
        auto *holder = ToNativePointer<Transform>(ptr);
        holder->rotation = ToNativePointer<JObjectCopier<NdcPoint>>(rotation_ptr)->Get();
    }

    static void SetScale(jlong ptr, jlong scale_ptr) {
        auto *holder = ToNativePointer<Transform>(ptr);
        holder->scale = ToNativePointer<JObjectCopier<NdcPoint>>(scale_ptr)->Get();
    }

    static constexpr const char *transform_name = "com/unknown/component/Transform";
    constexpr static const JNINativeMethod transform_methods[] = {
            {"nativeDestroy",        "(J)V",   (void *) DestroyTransform},
            //{"nativeMakeTransform",  "(JJJ)J", (void *) MakeTransform},
            {"nativeSetTranslation", "(JJ)V",  (void *) SetTranslation},
            {"nativeSetRotation",    "(JJ)V",  (void *) SetRotation},
            {"nativeSetScale",       "(JJ)V",  (void *) SetScale},
    };

    void RegisterTransformMethods(JNIEnv *env) {
        jclass transform_class = env->FindClass(transform_name);
        env->RegisterNatives(transform_class, transform_methods,
                             sizeof(transform_methods) / sizeof(JNINativeMethod));
    }
};

class VertexJni {
public:
    static void DestroyVertex(jlong ptr) {
        auto *holder = ToNativePointer<JObjectCopier<Vertex>>(ptr);
        DELETE_PTR(holder);
    }

    static jlong MakeVertex(jlong point_ptr, jlong uv_ptr, jlong color_ptr) {
        auto *point = ToNativePointer<JObjectCopier<NdcPoint>>(point_ptr);
        auto *uv = ToNativePointer<JObjectCopier<UV>>(uv_ptr);
        auto *color = ToNativePointer<JObjectCopier<Color>>(color_ptr);
        Vertex vertex{point->Get(), uv->Get(), color->Get()};
        JObjectCopier<Vertex>* holder = new JObjectCopier<Vertex>(vertex);
        return ToJavaObject(holder);
    }

    static void SetPosition(jlong ptr, jlong position_ptr) {
        auto *holder = ToNativePointer<JObjectCopier<Vertex>>(ptr);
        holder->Get().position = ToNativePointer<JObjectCopier<NdcPoint>>(position_ptr)->Get();
    }

    static void SetUv(jlong ptr, jlong uv_ptr) {
        auto *holder = ToNativePointer<JObjectCopier<Vertex>>(ptr);
        holder->Get().uv = ToNativePointer<JObjectCopier<UV>>(uv_ptr)->Get();
    }

    static void SetColor(jlong ptr, jlong color_ptr) {
        auto *holder = ToNativePointer<JObjectCopier<Vertex>>(ptr);
        holder->Get().color = ToNativePointer<JObjectCopier<Color>>(color_ptr)->Get();
    }

    static constexpr const char *vertex_name = "com/unknown/component/Vertex";
    constexpr static const JNINativeMethod vertex_methods[] = {
            {"nativeDestroy", "(J)V", (void*) DestroyVertex},
            {"nativeMakeVertex", "(JJJ)J", (void*) MakeVertex},
            {"nativeSetPosition", "(JJ)V", (void*) SetPosition},
            {"nativeSetUv", "(JJ)V", (void*) SetUv},
            {"nativeSetColor", "(JJ)V", (void*) SetColor},
    };

    void RegisterVertexMethods(JNIEnv *env) {
        jclass vertex_class = env->FindClass(vertex_name);
        env->RegisterNatives(vertex_class, vertex_methods,
                             sizeof(vertex_methods) / sizeof(JNINativeMethod));
    }
};

class VerticesJni {
public:
    static void DestroyVertices(jlong ptr) {
        auto *holder = ToNativePointer<Vertices>(ptr);
        DELETE_PTR(holder);
    }

    static jlong MakeVertices() {
        Vertices vertices;
        JObjectCopier<Vertices>* holder = new JObjectCopier<Vertices>(vertices);
        return ToJavaObject(holder);
    }

    static void AddVertex(jlong ptr, jlong vertex_ptr) {
        auto *holder = ToNativePointer<Vertices>(ptr);
        holder->AddVertex(ToNativePointer<JObjectCopier<Vertex>>(vertex_ptr)->Get());
    }

    static void AddFace(jlong ptr, jlong v1_ptr, jlong v2_ptr, jlong v3_ptr, jlong v4_ptr) {
        auto *holder = ToNativePointer<Vertices>(ptr);
        auto v1 = ToNativePointer<JObjectCopier<Vertex>>(v1_ptr)->Get();
        auto v2 = ToNativePointer<JObjectCopier<Vertex>>(v2_ptr)->Get();
        auto v3 = ToNativePointer<JObjectCopier<Vertex>>(v3_ptr)->Get();
        auto v4 = ToNativePointer<JObjectCopier<Vertex>>(v4_ptr)->Get();
        holder->AddFace(v1, v2, v3, v4);
    }

    static void SetVertices(JNIEnv* env, jlong ptr, jlongArray vertex_ptrs) {
        auto vertices =ToNativePointer<Vertices>(ptr);
        jsize size = env->GetArrayLength(vertex_ptrs);
        jlong* ptrs = env->GetLongArrayElements(vertex_ptrs, JNI_FALSE);
        Vertex* new_vertices = new Vertex[size];
        for (int i = 0; i < size; ++i) {
            new_vertices[i] = ToNativePointer<JObjectCopier<Vertex>>(ptrs[i])->Get();
        }
        vertices->SetVertices(size, new_vertices);
    }

    static constexpr const char *vertices_name = "com/unknown/component/Vertices";
    constexpr static const JNINativeMethod vertices_methods[] = {
            {"nativeDestroy", "(J)V", (void*) DestroyVertices},
            {"nativeMakeVertices", "()J", (void*) MakeVertices},
            {"nativeAddVertex", "(JJ)V", (void*) AddVertex},
            {"nativeAddFace", "(JJJJJ)V", (void*) AddFace},
            {"nativeSetVertices", "(J[J)V", (void*) SetVertices},
    };

    void RegisterVerticesJni(JNIEnv *env) {
        jclass vertices_class = env->FindClass(vertices_name);
        env->RegisterNatives(vertices_class, vertices_methods,
                             sizeof(vertices_methods) / sizeof(JNINativeMethod));
    }
};

class DebugInfoJni {
public:
    static void DestroyDebugInfo(jlong ptr) {
        auto *holder = ToNativePointer<DebugInfo>(ptr);
        DELETE_PTR(holder);
    }

    static void SetX(jlong ptr, jint screen_x) {
        auto *holder = ToNativePointer<DebugInfo>(ptr);
        holder->x = screen_x;
    }

    static void SetY(jlong ptr, jint screen_y) {
        auto *holder = ToNativePointer<DebugInfo>(ptr);
        holder->y = screen_y;
    }

    static void SetColor(jlong ptr, jint color) {
        auto *holder = ToNativePointer<DebugInfo>(ptr);
        holder->color = color;
    }

    static void SetText(JNIEnv *env, jclass klass, jlong ptr, jstring text) {
        auto *holder = ToNativePointer<DebugInfo>(ptr);
        const char* chars = env->GetStringUTFChars(text, JNI_FALSE);
        holder->text = chars;
    }

    static constexpr const char *debuginfo_name = "com/unknown/component/DebugInfo";
    constexpr static const JNINativeMethod debuginfo_methods[] = {
            {"nativeSetX",        "(JI)V",   (void *) SetX},
            {"nativeSetY", "(JI)V",  (void *) SetY},
            {"nativeSetColor", "(JI)V",  (void *) SetColor},
            {"nativeSetText", "(JLjava/lang/String;)V",  (void *) SetText},
    };

    void RegisterDebugInfoMethods(JNIEnv *env) {
        jclass debuginfo_class = env->FindClass(debuginfo_name);
        env->RegisterNatives(debuginfo_class, debuginfo_methods,
                             sizeof(debuginfo_methods) / sizeof(JNINativeMethod));
    }
};