package com.unknown.core.entity;

import com.unknown.core.NativeObject;

import dalvik.annotation.optimization.CriticalNative;
import dalvik.annotation.optimization.FastNative;

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
