//
// Created by Scave on 2024/2/24.
//

#include <jni.h>
#include "AScene.hpp"
#include "AEntity.hpp"
#include "AColor.hpp"
#include "APoint.hpp"
#include "AUV.hpp"
#include "AVertex.hpp"
#include "ACamera.hpp"
#include "ATransform.hpp"

jint JNI_OnLoad(JavaVM *javaVm, void *) {
    JNIEnv *env = nullptr;
    jint result = javaVm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6);
    if (result != JNI_OK) {
        return -1;
    }
    register_scene_jni(env);
    register_entity_jni(env);
    register_color_jni(env);
    register_point_jni(env);
    register_uv_jni(env);
    register_vertices_jni(env);
    register_camera_jni(env);
    register_transform_jni(env);
    return JNI_VERSION_1_6;
}