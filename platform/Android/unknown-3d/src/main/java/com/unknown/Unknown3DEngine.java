package com.unknown;

import android.view.Surface;

public final class Unknown3DEngine {

    private final long nativePtr;

    public Unknown3DEngine(int renderWidth, int renderHeight) {
        this.nativePtr = nativeMakeEngine(renderWidth, renderHeight);
    }

    public Unknown3DEngine(Surface surface, int renderWidth, int renderHeight) {
        this.nativePtr = nativeMakeEngineForSurface(surface, renderWidth, renderHeight);
    }

    public int render() {
        return nativeRender(nativePtr);
    }

    public void destroy() {
        nativeDestroy(nativePtr);
    }

    static {
        System.loadLibrary("unknown3d");
    }

    private static native long nativeMakeEngine(int width, int height);
    private static native long nativeMakeEngineForSurface(Surface surface, int width, int height);
    private static native int nativeRender(long ptr);
    private static native void nativeDestroy(long ptr);
}
