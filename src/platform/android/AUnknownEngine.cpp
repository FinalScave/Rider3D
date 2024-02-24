#include <jni.h>

//
// Created by Scave on 2023/11/10.
//

#include <android/native_window_jni.h>
#include "UnknownEngine.h"
#include "JNativeConverter.h"

extern "C" {
JNIEXPORT jlong JNICALL
Java_com_unknown_UnknownEngine_nativeMakeEngineForSurface(JNIEnv *env, jclass clazz,
                                                          jobject surface, jint width,
                                                          jint height) {
    ANativeWindow *native_window = ANativeWindow_fromSurface(env, surface);
    NS_UNKNOWN::RenderConfig render_config = {
            (uint16_t) width, (uint16_t) height, native_window
    };
    NS_UNKNOWN::UnknownEngine *engine = new NS_UNKNOWN::UnknownEngine(render_config);
    return ToEngineJavaObject(engine);
}

JNIEXPORT void JNICALL
Java_com_unknown_UnknownEngine_nativeRender(JNIEnv *env, jclass clazz, jlong ptr) {
    NS_UNKNOWN::UnknownEngine *engine = ToEngineNativePointer(ptr);
    engine->Update();
}

JNIEXPORT void JNICALL
Java_com_unknown_UnknownEngine_nativeDestroy(JNIEnv *env, jclass clazz, jlong ptr) {
    NS_UNKNOWN::UnknownEngine *engine = ToEngineNativePointer(ptr);
    DELETE_PTR(engine);
}

}