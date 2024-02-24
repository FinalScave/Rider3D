//
// Created by Scave on 2024/2/24.
//
#pragma once
#include <jni.h>
#include "JNativeConverter.h"
#include "JObjectHolder.h"

void DestroyScene(jlong ptr) {
    auto *scene = ToNativePointer<Scene>(ptr);
    DELETE_PTR(scene);
}

void AddEntity(jlong ptr, jlong entity_ptr) {
    auto *scene = ToNativePointer<Scene>(ptr);
    scene->AddEntity(ToNativePointer<JObjectHolder<Entity>>(entity_ptr)->Get());
}

jlong CreateScene(jlong manager_ptr) {
    auto *manager = ToNativePointer<SceneManager>(manager_ptr);
    return ToJavaObject(manager->CreateScene());
}

constexpr const char *scene_name = "com/unknown/core/scene/Scene";
static const JNINativeMethod scene_methods[] = {
        {"nativeAddEntity", "(JJ)V", (void*) AddEntity},
        {"nativeDestroy", "(J)V", (void*) DestroyScene},
};
constexpr const char *scene_manager_name = "com/unknown/core/scene/SceneManager";
static const JNINativeMethod scene_manager_methods[] = {
        {"nativeCreateScene", "(J)J", (jlong*) CreateScene},
};

void register_scene_jni(JNIEnv *env) {
    jclass scene_class = env->FindClass(scene_name);
    env->RegisterNatives(scene_class, scene_methods,
                         sizeof(scene_methods) / sizeof(JNINativeMethod));
    jclass scene_manager_class = env->FindClass(scene_manager_name);
    env->RegisterNatives(scene_manager_class, scene_manager_methods,
                         sizeof(scene_manager_methods) / sizeof(JNINativeMethod));
}