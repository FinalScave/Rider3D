#include <jni.h>

//
// Created by Scave on 2023/11/10.
//

#include "data/Vertex.h"
#include "JNativeConverter.h"

extern "C"
JNIEXPORT jlong JNICALL
Java_com_unknown_object_Vertices_nativeMakeVertices(JNIEnv *env, jclass clazz) {
    auto* vertices = new NS_UNKNOWN::Vertices;
    return ToJavaObject(vertices);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_unknown_object_Vertices_nativeAddVertex(JNIEnv *env, jclass clazz, jlong ptr, jlong vertex_ptr) {
    auto* vertices = ToNativeObject<NS_UNKNOWN::Vertices>(ptr);
    auto* vertex = ToNativeObject<NS_UNKNOWN::Vertex>(vertex_ptr);
    vertices->AddVertex(vertex);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_unknown_object_Vertices_nativeSetVertices(JNIEnv *env, jclass clazz,
                                                   jlong ptr, jlongArray vertex_ptr) {
    auto* vertices = ToNativeObject<NS_UNKNOWN::Vertices>(ptr);
    jsize size = env->GetArrayLength(vertex_ptr);
    jlong* ptrs = env->GetLongArrayElements(vertex_ptr, JNI_FALSE);
    NS_UNKNOWN::Vertex* new_vertices[size];
    for (int i = 0; i < size; ++i) {
        new_vertices[i] = ToNativeObject<NS_UNKNOWN::Vertex>(ptrs[i]);
    }
    vertices->SetVertices(size, new_vertices);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_unknown_object_Vertices_nativeDestroy(JNIEnv *env, jclass clazz, jlong ptr) {
    auto* vertices = ToNativeObject<NS_UNKNOWN::Vertices>(ptr);
    DELETE_PTR(vertices);
}