#include <jni.h>

//
// Created by Scave on 2023/11/10.
//
#pragma once
#include <android/native_window_jni.h>
#include "UnknownEngine.h"
#include "JNativeConverter.h"
#include "JObjectHolder.h"

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
    JObjectHolder<SceneManager>* holder = new JObjectHolder<SceneManager>(engine->GetScenes());
    return ToJavaObject(holder);
}

JNIEXPORT jlong JNICALL
Java_com_unknown_UnknownEngine_nativeGetEntityManager(JNIEnv *env, jclass clazz, jlong ptr) {
    UnknownEngine *engine = ToEngineNativePointer(ptr);
    return ToJavaObject(&engine->GetEntities());
}

JNIEXPORT void JNICALL
Java_com_unknown_UnknownEngine_nativeRender(JNIEnv *env, jclass clazz, jlong ptr) {
    UnknownEngine *engine = ToEngineNativePointer(ptr);
    engine->Update();
}

JNIEXPORT void JNICALL
Java_com_unknown_UnknownEngine_nativeDestroy(JNIEnv *env, jclass clazz, jlong ptr) {
    UnknownEngine *engine = ToEngineNativePointer(ptr);
    DELETE_PTR(engine);
}

}