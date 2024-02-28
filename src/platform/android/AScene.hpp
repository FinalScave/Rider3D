//
// Created by Scave on 2024/2/24.
//
#pragma once
#include <jni.h>
#include "JNativeConverter.h"
#include "JRefHolder.h"

class SceneJni {
public:
    static void DestroyScene(jlong ptr) {
        auto *scene = ToNativePointer<Scene>(ptr);
        DELETE_PTR(scene);
    }

    static void AddEntity(jlong ptr, jlong entity_ptr) {
        auto *scene = ToNativePointer<Scene>(ptr);
        scene->AddEntity(ToNativePointer<JUniqueCopier<Entity>>(entity_ptr)->Get());
    }

    static jlong CreateScene(jlong manager_ptr) {
        auto &manager =
                ToNativePointer<JRefHolder<SceneManager>>(manager_ptr)->Get();
        return ToJavaObject(manager.CreateScene());
    }

    static void LoadScene(jlong manager_ptr, jlong scene_ptr) {
        auto &manager =
                ToNativePointer<JRefHolder<SceneManager>>(manager_ptr)->Get();
        auto *scene = ToNativePointer<Scene>(scene_ptr);
        manager.LoadScene(scene);
    }

    static jlong CreatePrimitiveEntity(jlong manager_ptr, jint type) {
        auto &manager =
                ToNativePointer<JRefHolder<SceneManager>>(manager_ptr)->Get();
        PrimitiveType::Enum primitiveType = (PrimitiveType::Enum) type;
        Entity entity = manager.CreatePrimitiveEntity(primitiveType);
        JUniqueCopier<Entity> *holder = new JUniqueCopier<Entity>(entity);
        return ToJavaObject(holder);
    }

    static constexpr const char *scene_name = "com/rider/core/scene/Scene";
    constexpr static const JNINativeMethod scene_methods[] = {
            {"nativeAddEntity", "(JJ)V", (void *) AddEntity},
            {"nativeDestroy",   "(J)V",  (void *) DestroyScene},
    };
    static constexpr const char *scene_manager_name = "com/rider/core/scene/SceneManager";
    constexpr static const JNINativeMethod scene_manager_methods[] = {
            {"nativeCreateScene",           "(J)J",  (void *) CreateScene},
            {"nativeLoadScene",             "(JJ)V", (void *) LoadScene},
            {"nativeCreatePrimitiveEntity", "(JI)J", (void *) CreatePrimitiveEntity},
    };

    static void RegisterForScene(JNIEnv *env) {
        jclass scene_class = env->FindClass(scene_name);
        env->RegisterNatives(scene_class, scene_methods,
                             sizeof(scene_methods) / sizeof(JNINativeMethod));
        jclass scene_manager_class = env->FindClass(scene_manager_name);
        env->RegisterNatives(scene_manager_class, scene_manager_methods,
                             sizeof(scene_manager_methods) / sizeof(JNINativeMethod));
    }
};