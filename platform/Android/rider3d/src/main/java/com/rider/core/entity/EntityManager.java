package com.rider.core.entity;

import com.rider.core.NativeObject;

import dalvik.annotation.optimization.CriticalNative;

public class EntityManager extends NativeObject {
    public EntityManager(long nativePtr) {
        super(nativePtr);
    }

    public Entity createEntity() {
        return new Entity(nativeCreateEntity(nativePtr));
    }

    @CriticalNative
    private static native long nativeCreateEntity(long managerPtr);
}
