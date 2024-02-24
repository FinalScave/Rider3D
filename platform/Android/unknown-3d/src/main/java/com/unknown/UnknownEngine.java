package com.unknown;

import android.view.Surface;

import com.unknown.core.scene.SceneManager;

public final class UnknownEngine {

    private final long nativePtr;
    private SceneManager sceneManager;

    public UnknownEngine(Surface surface, int renderWidth, int renderHeight) {
        this.nativePtr = nativeMakeEngineForSurface(surface, renderWidth, renderHeight);
    }

    public SceneManager getScenes() {
        return sceneManager;
    }

    public void render() {
        nativeRender(nativePtr);
    }

    public void destroy() {
        nativeDestroy(nativePtr);
    }

    static {
        System.loadLibrary("unknown3d");
    }
    private static native long nativeMakeEngineForSurface(Surface surface, int width, int height);
    private static native void nativeRender(long ptr);
    private static native void nativeDestroy(long ptr);
}
