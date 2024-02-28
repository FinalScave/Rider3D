package com.rider.core.supposition;

import com.rider.core.NativeObject;

import dalvik.annotation.optimization.CriticalNative;

public class Color extends NativeObject {

    public Color(float a, float r, float g, float b) {
        super(nativeMakeColor(a, r, g, b));
    }

    public void setValue(float a, float r, float g, float b) {
        nativeSetValue(nativePtr, a, r, g, b);
    }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        nativeDestroy(nativePtr);
    }

    @CriticalNative
    private static native long nativeMakeColor(float a, float r, float g, float b);

    @CriticalNative
    private static native void nativeSetValue(long ptr, float a, float r, float g, float b);

    @CriticalNative
    private static native void nativeDestroy(long ptr);
}
