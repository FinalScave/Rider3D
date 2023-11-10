#include <jni.h>
#include "data/Vertex.h"
#include "JNativeConverter.h"

//
// Created by Scave on 2023/11/10.
//

extern "C"
JNIEXPORT jlong JNICALL
Java_com_unknown_object_Vertex_nativeMakeVertex(JNIEnv *env, jclass clazz, jlong ndc_point_ptr,
                                                jlong uv_ptr, jlong color_ptr) {
    auto *position = ToNativeObject<NS_UNKNOWN::NdcPoint>(ndc_point_ptr);
    auto *uv = ToNativeObject<NS_UNKNOWN::TextureUVPoint>(uv_ptr);
    auto *color = ToNativeObject<NS_UNKNOWN::Color>(color_ptr);
    auto *vertex = new NS_UNKNOWN::Vertex{position, uv, color};
    return ToJavaObject(vertex);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_unknown_object_Vertex_nativeSetPosition(JNIEnv *env, jclass clazz, jlong ptr,
                                                 jlong ndc_point_ptr) {
    auto *position = ToNativeObject<NS_UNKNOWN::NdcPoint>(ndc_point_ptr);
    auto *vertex = ToNativeObject<NS_UNKNOWN::Vertex>(ptr);
    DELETE_PTR(vertex->position);
    vertex->position = position;
}
extern "C"
JNIEXPORT void JNICALL
Java_com_unknown_object_Vertex_nativeSetUv(JNIEnv *env, jclass clazz, jlong ptr, jlong uv_ptr) {
    auto *uv = ToNativeObject<NS_UNKNOWN::TextureUVPoint>(uv_ptr);
    auto *vertex = ToNativeObject<NS_UNKNOWN::Vertex>(ptr);
    DELETE_PTR(vertex->uv);
    vertex->uv = uv;
}
extern "C"
JNIEXPORT void JNICALL
Java_com_unknown_object_Vertex_nativeSetColor(JNIEnv *env, jclass clazz, jlong ptr,
                                              jlong color_ptr) {
    auto *color = ToNativeObject<NS_UNKNOWN::Color>(color_ptr);
    auto *vertex = ToNativeObject<NS_UNKNOWN::Vertex>(ptr);
    DELETE_PTR(vertex->color);
    vertex->color = color;
}
extern "C"
JNIEXPORT void JNICALL
Java_com_unknown_object_Vertex_nativeDestroy(JNIEnv *env, jclass clazz, jlong ptr) {
    auto *vertex = ToNativeObject<NS_UNKNOWN::Vertex>(ptr);
    DELETE_PTR(vertex);
}