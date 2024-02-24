package com.unknown.core.supposition;

import com.unknown.core.NativeObject;

public class Color extends NativeObject {

    public Color(float a, float r, float g, float b) {
        this.nativePtr = nativeMakeColor(a, r, g, b);
    }

    public void setValue(float a, float r, float g, float b) {
        nativeSetValue(nativePtr, a, r, g, b);
    }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        nativeDestroy(nativePtr);
    }

    private static native long nativeMakeColor(float a, float r, float g, float b);

    private static native void nativeSetValue(long ptr, float a, float r, float g, float b);

    private static native void nativeDestroy(long ptr);
}
