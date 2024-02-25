package com.unknown;

import android.view.Surface;

import com.unknown.core.entity.EntityManager;
import com.unknown.core.scene.SceneManager;

public final class UnknownEngine {
    private final long nativePtr;
    private SceneManager sceneManager;
    private EntityManager entityManager;

    public UnknownEngine(Surface surface, int renderWidth, int renderHeight) {
        this(surface, renderWidth, renderHeight, false);
    }

    public UnknownEngine(Surface surface, int renderWidth, int renderHeight, boolean debug) {
        this.nativePtr = nativeMakeEngineForSurface(surface, renderWidth, renderHeight, debug);
        this.sceneManager = new SceneManager(nativeGetSceneManager(nativePtr));
        this.entityManager = new EntityManager(nativeGetEntityManager(nativePtr));
    }

    public SceneManager getScenes() {
        return sceneManager;
    }

    public EntityManager getEntities() {
        return entityManager;
    }

    public void update() {
        nativeUpdate(nativePtr);
    }

    public void destroy() {
        nativeDestroy(nativePtr);
    }

    static {
        System.loadLibrary("unknown3d");
    }
    private static native long nativeMakeEngineForSurface(
            Surface surface, int width, int height, boolean debug);
    private static native long nativeGetSceneManager(long ptr);
    private static native long nativeGetEntityManager(long ptr);
    private static native void nativeUpdate(long ptr);
    private static native void nativeDestroy(long ptr);
}
