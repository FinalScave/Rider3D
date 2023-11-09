#include <jni.h>

//
// Created by Scave on 2023/11/10.
//

#include <android/native_window_jni.h>
#include "Unknown3DEngine.h"
#include "JNativeConverter.h"

extern "C" {
JNIEXPORT jlong JNICALL
Java_com_unknown_Unknown3DEngine_nativeMakeEngine(JNIEnv *env, jclass clazz, jint width,
                                                  jint height) {
    NS_UNKNOWN::RenderConfig render_config = {(uint16_t) width, (uint16_t) height};
    NS_UNKNOWN::Unknown3DEngine *engine = new NS_UNKNOWN::Unknown3DEngine(render_config);
    return To3DEngineJavaObject(engine);
}

JNIEXPORT jlong JNICALL
Java_com_unknown_Unknown3DEngine_nativeMakeEngineForSurface(JNIEnv *env, jclass clazz,
                                                            jobject surface, jint width,
                                                            jint height) {
    ANativeWindow *native_window = ANativeWindow_fromSurface(env, surface);
    NS_UNKNOWN::RenderConfig render_config = {
            (uint16_t) width, (uint16_t) height, native_window
    };
    NS_UNKNOWN::Unknown3DEngine *engine = new NS_UNKNOWN::Unknown3DEngine(render_config);
    return To3DEngineJavaObject(engine);
}

JNIEXPORT jint JNICALL
Java_com_unknown_Unknown3DEngine_nativeRender(JNIEnv *env, jclass clazz, jlong ptr) {
    NS_UNKNOWN::Unknown3DEngine *engine = To3DEngineNativeObject(ptr);
    return engine->Render();
}

JNIEXPORT void JNICALL
Java_com_unknown_Unknown3DEngine_nativeDestroy(JNIEnv *env, jclass clazz, jlong ptr) {
    NS_UNKNOWN::Unknown3DEngine *engine = To3DEngineNativeObject(ptr);
    NS_UNKNOWN::RenderConfig render_config = engine->GetRenderConfig();
    if (render_config.native_window_handle != nullptr) {
        ANativeWindow *native_window = (ANativeWindow *) render_config.native_window_handle;
        DELETE_PTR(native_window);
    }
    DELETE_PTR(engine);
}

}