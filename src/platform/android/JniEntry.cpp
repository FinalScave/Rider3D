//
// Created by Scave on 2024/2/24.
//

#include <jni.h>
#include "ASuppositions.hpp"
#include "AComponents.hpp"
#include "AEntity.hpp"
#include "AScene.hpp"

jint JNI_OnLoad(JavaVM *javaVm, void *) {
    JNIEnv *env = nullptr;
    jint result = javaVm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6);
    if (result != JNI_OK) {
        return -1;
    }
    // suppositions
    NdcPointJni().RegisterNdcPointMethods(env);
    ColorJni().RegisterColorMethods(env);
    UVJni().RegisterUvMethods(env);
    // components
    CameraJni().RegisterCameraMethods(env);
    TransformJni().RegisterTransformMethods(env);
    VertexJni().RegisterVertexMethods(env);
    VerticesJni().RegisterVerticesJni(env);
    // core ecs
    EntityJni().RegisterForEntity(env);
    SceneJni().RegisterForScene(env);
    return JNI_VERSION_1_6;
}