package com.unknown.core.scene;

import com.unknown.core.entity.Entity;

import dalvik.annotation.optimization.CriticalNative;

public class Scene extends Entity {

    public Scene(long nativePtr) {
        super(nativePtr);
    }

    public void addEntity(Entity entity) {
        nativeAddEntity(nativePtr, entity.nativePtr);
    }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        nativeDestroy(nativePtr);
    }

    @CriticalNative
    private static native void nativeAddEntity(long ptr, long entity_ptr);

    @CriticalNative
    private static native void nativeDestroy(long ptr);
}
