//
// Created by Scave on 2024/2/24.
//

#include <jni.h>
#include "AScene.cpp"

jint JNI_OnLoad(JavaVM *javaVm, void *) {
    JNIEnv *env = nullptr;
    jint result = javaVm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6);
    if (result != JNI_OK) {
        return -1;
    }
    register_scene_jni(env);
    return JNI_VERSION_1_6;
}