package com.unknown;

import android.view.Surface;

import com.unknown.core.entity.EntityManager;
import com.unknown.core.scene.SceneManager;
import com.unknown.render.RenderConfig;

import dalvik.annotation.optimization.CriticalNative;
import dalvik.annotation.optimization.FastNative;

public final class UnknownEngine {
    private final long nativePtr;
    private SceneManager sceneManager;
    private EntityManager entityManager;

    public UnknownEngine(RenderConfig config) {
        this.nativePtr = nativeMakeEngineForSurface(
                config.surface,
                config.width,
                config.height,
                config.debug
        );
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

    @FastNative
    private static native long nativeMakeEngineForSurface(
            Surface surface, int width, int height, boolean debug);
    @CriticalNative
    private static native void nativeUpdate(long ptr);
    @CriticalNative
    private static native void nativeDestroy(long ptr);
    @CriticalNative
    private static native long nativeGetSceneManager(long ptr);
    @CriticalNative
    private static native long nativeGetEntityManager(long ptr);
}
