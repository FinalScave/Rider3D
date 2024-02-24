package com.unknown;

import android.view.Surface;

import com.unknown.core.entity.EntityManager;
import com.unknown.core.scene.SceneManager;

public final class UnknownEngine {

    private final long nativePtr;
    private SceneManager sceneManager;
    private EntityManager entityManager;

    public UnknownEngine(Surface surface, int renderWidth, int renderHeight) {
        this.nativePtr = nativeMakeEngineForSurface(surface, renderWidth, renderHeight);
        this.sceneManager = new SceneManager(nativeGetSceneManager(nativePtr));
        this.entityManager = new EntityManager(nativeGetEntityManager(nativePtr));
    }

    public SceneManager getScenes() {
        return sceneManager;
    }

    public EntityManager getEntities() {
        return entityManager;
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
    private static native long nativeGetSceneManager(long ptr);
    private static native long nativeGetEntityManager(long ptr);
    private static native void nativeRender(long ptr);
    private static native void nativeDestroy(long ptr);
}
