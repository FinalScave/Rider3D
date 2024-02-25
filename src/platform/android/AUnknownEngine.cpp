//
// Created by Scave on 2023/11/10.
//
#pragma once
#include <jni.h>
#include <android/native_window_jni.h>
#include "UnknownEngine.h"
#include "JNativeConverter.h"
#include "JRefHolder.h"

using namespace unknown;

extern "C" {
JNIEXPORT jlong JNICALL
Java_com_unknown_UnknownEngine_nativeMakeEngineForSurface(JNIEnv *env, jclass clazz,
                                                          jobject surface, jint width,
                                                          jint height) {
    ANativeWindow *native_window = ANativeWindow_fromSurface(env, surface);
    RenderConfig render_config = {
            (uint16_t) width, (uint16_t) height, native_window
    };
    UnknownEngine *engine = new UnknownEngine(render_config);
    return ToEngineJavaObject(engine);
}

JNIEXPORT jlong JNICALL
Java_com_unknown_UnknownEngine_nativeGetSceneManager(JNIEnv *env, jclass clazz, jlong ptr) {
    UnknownEngine *engine = ToEngineNativePointer(ptr);
    JRefHolder<SceneManager>* holder = new JRefHolder<SceneManager>(engine->GetScenes());
    return ToJavaObject(holder);
}

JNIEXPORT jlong JNICALL
Java_com_unknown_UnknownEngine_nativeGetEntityManager(JNIEnv *env, jclass clazz, jlong ptr) {
    UnknownEngine *engine = ToEngineNativePointer(ptr);
    JRefHolder<EntityManager>* holder = new JRefHolder<EntityManager>(engine->GetEntities());
    return ToJavaObject(holder);
}

JNIEXPORT void JNICALL
Java_com_unknown_UnknownEngine_nativeUpdate(JNIEnv *env, jclass clazz, jlong ptr) {
    UnknownEngine *engine = ToEngineNativePointer(ptr);
    engine->Update();
}

JNIEXPORT void JNICALL
Java_com_unknown_UnknownEngine_nativeDestroy(JNIEnv *env, jclass clazz, jlong ptr) {
    UnknownEngine *engine = ToEngineNativePointer(ptr);
    DELETE_PTR(engine);
}

}