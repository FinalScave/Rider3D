package com.unknown.component;

import com.unknown.core.supposition.NdcPoint;

import dalvik.annotation.optimization.CriticalNative;

public class Transform extends Component {
    private NdcPoint translation;
    private NdcPoint rotation;
    private NdcPoint scale;

    public Transform(NdcPoint translation, NdcPoint rotation, NdcPoint scale) {
        super(nativeMakeTransform(translation.nativePtr, rotation.nativePtr, scale.nativePtr));
        this.translation = translation;
        this.rotation = rotation;
        this.scale = scale;
    }

    public NdcPoint translation() {
        return translation;
    }

    public NdcPoint rotation() {
        return rotation;
    }

    public NdcPoint scale() {
        return scale;
    }

    public void setTranslation(NdcPoint translation) {
        nativeSetTranslation(nativePtr, translation.nativePtr);
        this.translation = translation;
    }

    public void setRotation(NdcPoint rotation) {
        nativeSetRotation(nativePtr, rotation.nativePtr);
        this.rotation = rotation;
    }

    public void setScale(NdcPoint scale) {
        nativeSetScale(nativePtr, scale.nativePtr);
        this.scale = scale;
    }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        nativeDestroy(nativePtr);
    }

    @CriticalNative
    private static native long nativeMakeTransform(long translationPtr, long rotationPtr, long scalePtr);
    @CriticalNative
    private static native void nativeSetTranslation(long ptr, long translationPtr);
    @CriticalNative
    private static native void nativeSetRotation(long ptr, long rotationPtr);
    @CriticalNative
    private static native void nativeSetScale(long ptr, long scalePtr);
    @CriticalNative
    private static native void nativeDestroy(long ptr);
}
