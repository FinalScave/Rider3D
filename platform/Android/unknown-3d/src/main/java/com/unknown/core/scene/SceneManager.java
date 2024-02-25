package com.unknown.core.scene;

import com.unknown.core.NativeObject;
import com.unknown.core.entity.Entity;
import com.unknown.core.entity.PrimitiveType;

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

    public Entity createPrimitiveEntity(PrimitiveType type) {
        return new Entity(nativeCreatePrimitiveEntity(nativePtr, type.value));
    }

    @CriticalNative
    private static native long nativeCreateScene(long managerPtr);

    @CriticalNative
    private static native void nativeLoadScene(long managerPtr, long scenePtr);

    @CriticalNative
    private static native long nativeCreatePrimitiveEntity(long managerPtr, int type);
}
