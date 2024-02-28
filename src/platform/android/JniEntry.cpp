//
// Created by Scave on 2024/2/24.
//

#include <jni.h>
#include "ARiderEngine.hpp"
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
    // engine
    RiderEngineJni::RegisterEngineMethods(env);
    // suppositions
    NdcPointJni::RegisterNdcPointMethods(env);
    ColorJni::RegisterColorMethods(env);
    UVJni::RegisterUvMethods(env);
    // components
    CameraJni::RegisterCameraMethods(env);
    TransformJni::RegisterTransformMethods(env);
    VertexJni::RegisterVertexMethods(env);
    VerticesJni::RegisterVerticesJni(env);
    DebugInfoJni::RegisterDebugInfoMethods(env);
    // core ecs
    EntityJni::RegisterForEntity(env);
    SceneJni::RegisterForScene(env);
    return JNI_VERSION_1_6;
}