#include <jni.h>

//
// Created by Scave on 2023/11/10.
//

#include "object/Object3D.h"
#include "JNativeConverter.h"

extern "C"
JNIEXPORT jlong JNICALL
Java_com_unknown_object_Object3D_nativeMakeObject3D(JNIEnv *env, jclass clazz, jstring name) {
    const char* obj_name = env->GetStringUTFChars(name, JNI_FALSE);
    auto* object_3d = new NS_UNKNOWN::Object3D(obj_name);
    return ToJavaObject(object_3d);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_unknown_object_Object3D_nativeSetRenderType(JNIEnv *env, jclass clazz, jlong ptr,
                                                     jint type) {
    auto* object_3d = ToNativePointer<NS_UNKNOWN::Object3D>(ptr);
    object_3d->render_type = static_cast<unknown::RenderType>(type);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_unknown_object_Object3D_nativeDestroy(JNIEnv *env, jclass clazz, jlong ptr) {
    auto* object_3d = ToNativePointer<NS_UNKNOWN::Object3D>(ptr);
    DELETE_PTR(object_3d);
}