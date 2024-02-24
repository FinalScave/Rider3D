package com.unknown.core.scene;

import com.unknown.core.NativeObject;

import dalvik.annotation.optimization.CriticalNative;

public class Scene extends NativeObject {

    public Scene(long nativePtr) {
        super(nativePtr);
    }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        nativeDestroy(nativePtr);
    }

    @CriticalNative
    private static native void nativeDestroy(long ptr);
}
