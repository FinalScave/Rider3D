package com.unknown.core.entity;

import com.unknown.core.NativeObject;

import dalvik.annotation.optimization.FastNative;

public class EntityManager extends NativeObject {
    public EntityManager(long nativePtr) {
        super(nativePtr);
    }

    public Entity createEntity() {
        return new Entity(nativeCreateEntity(nativePtr));
    }

    @FastNative
    private static native long nativeCreateEntity(long managerPtr);
}
