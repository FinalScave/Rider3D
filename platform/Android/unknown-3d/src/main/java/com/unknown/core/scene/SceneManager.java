package com.unknown.core.scene;

import com.unknown.core.NativeObject;
import com.unknown.core.entity.Entity;
import com.unknown.core.entity.PrimitiveType;
import com.unknown.core.entity.PropertyType;

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

    /*public Entity createPrimitiveEntity(
            PrimitiveType primitiveType, PropertyType propertyType, NativeObject[] objects) {
        if (objects == null) {
            throw new IllegalArgumentException("objects cannot be null");
        }
        long[] valuePtrs = new long[objects.length];
        for (int i = 0; i < objects.length; i++) {
            valuePtrs[i] = objects[i].nativePtr;
        }
        return new Entity(nativeCreatePrimitiveEntity2(
                nativePtr, primitiveType.value, propertyType.type, valuePtrs));
    }*/

    @CriticalNative
    private static native long nativeCreateScene(long managerPtr);

    @CriticalNative
    private static native void nativeLoadScene(long managerPtr, long scenePtr);

    @CriticalNative
    private static native long nativeCreatePrimitiveEntity(long managerPtr, int type);

    /*@FastNative
    private static native long nativeCreatePrimitiveEntity2(
            long managerPtr, int type, int property, long[] values);*/
}
