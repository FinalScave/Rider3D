//
// Created by Scave on 2023/11/10.
//
#pragma once
#include <jni.h>
#include "Vertex.h"
#include "JNativeConverter.h"
#include "JObjectHolder.h"

void DestroyVertex(jlong ptr) {
    auto *holder = ToNativePointer<JObjectHolder<Vertex>>(ptr);
    DELETE_PTR(holder);
}

jlong MakeVertex(jlong point_ptr, jlong uv_ptr, jlong color_ptr) {
    auto *point = ToNativePointer<JObjectHolder<NdcPoint>>(point_ptr);
    auto *uv = ToNativePointer<JObjectHolder<UV>>(uv_ptr);
    auto *color = ToNativePointer<JObjectHolder<Color>>(color_ptr);
    Vertex vertex{point->Get(), uv->Get(), color->Get()};
    JObjectHolder<Vertex>* holder = new JObjectHolder<Vertex>(vertex);
    return ToJavaObject(holder);
}

void SetPosition(jlong ptr, jlong position_ptr) {
    auto *holder = ToNativePointer<JObjectHolder<Vertex>>(ptr);
    holder->Get().position = ToNativePointer<JObjectHolder<NdcPoint>>(position_ptr)->Get();
}

void SetUv(jlong ptr, jlong uv_ptr) {
    auto *holder = ToNativePointer<JObjectHolder<Vertex>>(ptr);
    holder->Get().uv = ToNativePointer<JObjectHolder<UV>>(uv_ptr)->Get();
}

void SetColor(jlong ptr, jlong color_ptr) {
    auto *holder = ToNativePointer<JObjectHolder<Vertex>>(ptr);
    holder->Get().color = ToNativePointer<JObjectHolder<Color>>(color_ptr)->Get();
}

void DestroyVertices(jlong ptr) {
    auto *holder = ToNativePointer<JObjectHolder<Vertices>>(ptr);
    DELETE_PTR(holder);
}

jlong MakeVertices() {
    Vertices vertices;
    JObjectHolder<Vertices>* holder = new JObjectHolder<Vertices>(vertices);
    return ToJavaObject(holder);
}

void AddVertex(jlong ptr, jlong vertex_ptr) {
    auto *holder = ToNativePointer<JObjectHolder<Vertices>>(ptr);
    holder->Get().AddVertex(ToNativePointer<JObjectHolder<Vertex>>(vertex_ptr)->Get());
}

void AddFace(jlong ptr, jlong v1_ptr, jlong v2_ptr, jlong v3_ptr, jlong v4_ptr) {
    auto *holder = ToNativePointer<JObjectHolder<Vertices>>(ptr);
    auto v1 = ToNativePointer<JObjectHolder<Vertex>>(v1_ptr)->Get();
    auto v2 = ToNativePointer<JObjectHolder<Vertex>>(v2_ptr)->Get();
    auto v3 = ToNativePointer<JObjectHolder<Vertex>>(v3_ptr)->Get();
    auto v4 = ToNativePointer<JObjectHolder<Vertex>>(v4_ptr)->Get();
    holder->Get().AddFace(v1, v2, v3, v4);
}

void SetVertices(JNIEnv* env, jlong ptr, jlongArray vertex_ptrs) {
    auto vertices =
            ToNativePointer<JObjectHolder<Vertices>>(ptr)->Get();
    jsize size = env->GetArrayLength(vertex_ptrs);
    jlong* ptrs = env->GetLongArrayElements(vertex_ptrs, JNI_FALSE);
    Vertex* new_vertices = new Vertex[size];
    for (int i = 0; i < size; ++i) {
        new_vertices[i] = ToNativePointer<JObjectHolder<Vertex>>(ptrs[i])->Get();
    }
    vertices.SetVertices(size, new_vertices);
}

constexpr const char *vertex_name = "com/unknown/component/Vertex";
static const JNINativeMethod vertex_methods[] = {
        {"nativeDestroy", "(J)V", (void*) DestroyVertex},
        {"nativeMakeVertex", "(JJJ)J", (jlong*) MakeVertex},
        {"nativeSetPosition", "(JJ)V", (void*) SetPosition},
        {"nativeSetUv", "(JJ)V", (void*) SetUv},
        {"nativeSetColor", "(JJ)V", (void*) SetColor},
};
constexpr const char *vertices_name = "com/unknown/component/Vertices";
static const JNINativeMethod vertices_methods[] = {
        {"nativeDestroy", "(J)V", (void*) DestroyVertices},
        {"nativeMakeVertices", "()J", (jlong*) MakeVertices},
        {"nativeAddVertex", "(JJ)V", (void*) AddVertex},
        {"nativeAddFace", "(JJJJJ)V", (void*) AddFace},
        {"nativeSetVertices", "(J[J)V", (void*) SetVertices},
};

void register_vertices_jni(JNIEnv *env) {
    jclass vertex_class = env->FindClass(vertex_name);
    env->RegisterNatives(vertex_class, vertex_methods,
                         sizeof(vertex_methods) / sizeof(JNINativeMethod));
    jclass vertices_class = env->FindClass(vertices_name);
    env->RegisterNatives(vertices_class, vertices_methods,
                         sizeof(vertices_methods) / sizeof(JNINativeMethod));
}