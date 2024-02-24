package com.unknown.core.supposition;

import com.unknown.core.NativeObject;

import dalvik.annotation.optimization.CriticalNative;

public class NdcPoint extends NativeObject {

    public static NdcPoint zero() {
        return new NdcPoint(0, 0, 0);
    }

    public NdcPoint(float x, float y, float z) {
        super(nativeMakeNdcPoint(x, y, z));
    }

    public void setX(float x) {
        nativeSetX(nativePtr, x);
    }

    public void setY(float y) {
        nativeSetY(nativePtr, y);
    }

    public void setZ(float z) {
        nativeSetZ(nativePtr, z);
    }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        nativeDestroy(nativePtr);
    }

    @CriticalNative
    private static native long nativeMakeNdcPoint(float x, float y, float z);
    @CriticalNative
    private static native void nativeSetX(long ptr, float x);
    @CriticalNative
    private static native void nativeSetY(long ptr, float y);
    @CriticalNative
    private static native void nativeSetZ(long ptr, float z);
    @CriticalNative
    private static native void nativeDestroy(long ptr);
}
