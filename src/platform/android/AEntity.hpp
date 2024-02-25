//
// Created by Scave on 2024/2/24.
//
#pragma once
#include <jni.h>
#include "JNativeConverter.h"
#include "JRefHolder.h"
#include "BasicComponents.h"

class EntityJni {
public:
    static void DestroyEntity(jlong ptr) {
        auto *holder = ToNativePointer<JObjectCopier<Entity>>(ptr);
        DELETE_PTR(holder);
    }

    static jlong AddComponent(jlong ptr, jint component_type) {
        Entity &entity = ToNativePointer<JObjectCopier<Entity>>(ptr)->Get();
        jlong component_address = -1;
        switch (component_type) {
            case 1:
                component_address = ToJavaObject(entity.assign<Camera>().get());
                break;
            case 2:
                component_address = ToJavaObject(entity.assign<Transform>().get());
                break;
            case 101:
                component_address = ToJavaObject(entity.assign<Vertices>().get());
                break;
        }
        return component_address;
    }

    static jlong CreateEntity(jlong manager_ptr) {
        auto &manager =
                ToNativePointer<JRefHolder<EntityManager>>(manager_ptr)->Get();
        Entity entity = manager.create();
        JObjectCopier<Entity> *holder = new JObjectCopier<Entity>(entity);
        return ToJavaObject(holder);
    }

    static constexpr const char *entity_name = "com/unknown/core/entity/Entity";
    constexpr static const JNINativeMethod entity_methods[] = {
            {"nativeDestroy",      "(J)V",  (void *) DestroyEntity},
            {"nativeAddComponent", "(JI)J", (void *) AddComponent},
    };
    static constexpr const char *entity_manager_name = "com/unknown/core/entity/EntityManager";
    constexpr static const JNINativeMethod entity_manager_methods[] = {
            {"nativeCreateEntity", "(J)J", (void *) CreateEntity},
    };

    void RegisterForEntity(JNIEnv *env) {
        jclass entity_class = env->FindClass(entity_name);
        env->RegisterNatives(entity_class, entity_methods,
                             sizeof(entity_methods) / sizeof(JNINativeMethod));
        jclass entity_manager_class = env->FindClass(entity_manager_name);
        env->RegisterNatives(entity_manager_class, entity_manager_methods,
                             sizeof(entity_manager_methods) / sizeof(JNINativeMethod));
    }
};