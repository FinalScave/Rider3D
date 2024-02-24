package com.unknown.core.scene;

import com.unknown.core.NativeObject;

import dalvik.annotation.optimization.FastNative;

public class SceneManager extends NativeObject {

    public SceneManager(long nativePtr) {
        super(nativePtr);
    }

    public Scene createScene() {
        return new Scene(nativeCreateScene(nativePtr));
    }

    @FastNative
    private static native long nativeCreateScene(long managerPtr);
}
