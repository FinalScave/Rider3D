package com.unknown.core.scene;

import com.unknown.core.NativeObject;

import dalvik.annotation.optimization.CriticalNative;
import dalvik.annotation.optimization.FastNative;

public class SceneManager extends NativeObject {
    private Scene currentScene;

    public SceneManager(long nativePtr) {
        super(nativePtr);
    }

    public Scene createScene() {
        return new Scene(nativeCreateScene(nativePtr));
    }

    public void loadScene(Scene scene) {
        nativeLoadScene(nativePtr, scene.nativePtr);
        currentScene = scene;
    }

    public Scene getCurrentScene() {
        return currentScene;
    }

    @CriticalNative
    private static native long nativeCreateScene(long managerPtr);

    @CriticalNative
    private static native void nativeLoadScene(long managerPtr, long scenePtr);
}
