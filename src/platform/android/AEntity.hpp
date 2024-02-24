//
// Created by Scave on 2024/2/24.
//
#include <jni.h>
#include "JNativeConverter.h"
#include "JObjectHolder.h"

void DestroyEntity(jlong ptr) {
    auto *holder = ToNativePointer<JObjectHolder<Entity>>(ptr);
    DELETE_PTR(holder);
}

void AddComponent(jlong ptr, jlong component_ptr) {
    auto *holder = ToNativePointer<JObjectHolder<Entity>>(ptr);
    auto component = ToNativePointer<JObjectHolder<void*>>(component_ptr);
    holder->Get().assign_from_copy(component->Get());
}

jlong CreateEntity(jlong manager_ptr) {
    auto *manager = ToNativePointer<EntityManager>(manager_ptr);
    Entity entity = manager->create();
    JObjectHolder<Entity>* holder = new JObjectHolder<Entity>(entity);
    return ToJavaObject(holder);
}

constexpr const char *entity_name = "com/unknown/core/entity/Entity";
static const JNINativeMethod entity_methods[] = {
        {"nativeDestroy", "(J)V", (void*) DestroyEntity},
        {"nativeAddComponent", "(JJ)V", (void*) AddComponent},
};
constexpr const char *entity_manager_name = "com/unknown/core/entity/EntityManager";
static const JNINativeMethod entity_manager_methods[] = {
        {"nativeCreateEntity", "(J)J", (jlong*) CreateEntity},
};

void register_entity_jni(JNIEnv *env) {
    jclass entity_class = env->FindClass(entity_name);
    env->RegisterNatives(entity_class, entity_methods,
                         sizeof(entity_methods) / sizeof(JNINativeMethod));
    jclass entity_manager_class = env->FindClass(entity_manager_name);
    env->RegisterNatives(entity_manager_class, entity_manager_methods,
                         sizeof(entity_manager_methods) / sizeof(JNINativeMethod));
}