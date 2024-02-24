package com.unknown.core.supposition;

import com.unknown.core.NativeObject;

public class NdcPoint extends NativeObject {

    public NdcPoint(float x, float y, float z) {
        this.nativePtr = nativeMakeNdcPoint(x, y, z);
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

    private static native long nativeMakeNdcPoint(float x, float y, float z);
    private static native void nativeSetX(long ptr, float x);
    private static native void nativeSetY(long ptr, float y);
    private static native void nativeSetZ(long ptr, float z);
    private static native void nativeDestroy(long ptr);
}
