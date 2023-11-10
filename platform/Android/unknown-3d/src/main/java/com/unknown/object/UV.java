package com.unknown.object;

public class UV extends NativeObject {

    public UV(float u, float v) {
        this.nativePtr = nativeMakeUV(u, v);
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

    private static native long nativeMakeUV(float u, float v);
    private static native void nativeSetU(long ptr, float u);
    private static native void nativeSetV(long ptr, float v);
    private static native void nativeDestroy(long ptr);
}
