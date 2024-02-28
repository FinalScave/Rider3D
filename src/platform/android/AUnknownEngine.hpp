//
// Created by Scave on 2023/11/10.
//
#pragma once
#include <jni.h>
#include <android/native_window_jni.h>
#include "RiderEngine.h"
#include "JNativeConverter.h"
#include "JRefHolder.h"

using namespace unknown;

class UnknownEngineJni {
public:
    static void DestroyEngine(jlong ptr) {
        UnknownEngine *engine = ToEngineNativePointer(ptr);
        DELETE_PTR(engine);
    }

    static jlong MakeEngine(JNIEnv* env, jclass klass,
                            jobject surface, jint width,jint height, jboolean debug) {
        ANativeWindow *native_window = ANativeWindow_fromSurface(env, surface);
        RenderConfig render_config = {
                (uint16_t) width, (uint16_t) height,
                native_window, (bool) debug
        };
        UnknownEngine *engine = new UnknownEngine(render_config);
        return ToEngineJavaObject(engine);
    }

    static void Update(jlong ptr) {
        UnknownEngine *engine = ToEngineNativePointer(ptr);
        engine->Update();
    }

    static jlong GetSceneManager(jlong ptr) {
        UnknownEngine *engine = ToEngineNativePointer(ptr);
        JRefHolder<SceneManager>* holder = new JRefHolder<SceneManager>(engine->GetScenes());
        return ToJavaObject(holder);
    }

    static jlong GetEntityManager(jlong ptr) {
        UnknownEngine *engine = ToEngineNativePointer(ptr);
        JRefHolder<EntityManager>* holder = new JRefHolder<EntityManager>(engine->GetEntities());
        return ToJavaObject(holder);
    }

    static constexpr const char *engine_name = "com/unknown/UnknownEngine";
    constexpr static const JNINativeMethod engine_methods[] = {
            {"nativeDestroy", "(J)V", (void*) DestroyEngine},
            {"nativeMakeEngineForSurface", "(Landroid/view/Surface;IIZ)J", (void*) MakeEngine},
            {"nativeUpdate", "(J)V", (void*) Update},
            {"nativeGetSceneManager", "(J)J", (void*) GetSceneManager},
            {"nativeGetEntityManager", "(J)J", (void*) GetEntityManager},
    };

    static void RegisterEngineMethods(JNIEnv *env) {
        jclass engine_class = env->FindClass(engine_name);
        env->RegisterNatives(engine_class, engine_methods,
                             sizeof(engine_methods) / sizeof(JNINativeMethod));
    }
};