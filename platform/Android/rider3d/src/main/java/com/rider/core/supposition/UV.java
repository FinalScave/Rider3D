package com.rider.core.supposition;

import com.rider.core.NativeObject;

import dalvik.annotation.optimization.CriticalNative;

public class UV extends NativeObject {

    public UV(float u, float v) {
        super(nativeMakeUV(u, v));
    }

    public void setU(float u) {
        nativeSetU(nativePtr, u);
    }

    public void setV(float v) {
        nativeSetV(nativePtr, v);
    }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        nativeDestroy(nativePtr);
    }

    @CriticalNative
    private static native long nativeMakeUV(float u, float v);
    @CriticalNative
    private static native void nativeSetU(long ptr, float u);
    @CriticalNative
    private static native void nativeSetV(long ptr, float v);
    @CriticalNative
    private static native void nativeDestroy(long ptr);
}
