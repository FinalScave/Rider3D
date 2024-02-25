package com.unknown.component;

import static com.unknown.component.ComponentType.TRANSFORM;

import com.unknown.core.supposition.NdcPoint;

import dalvik.annotation.optimization.CriticalNative;

public class Transform extends Component {

    /*public static Transform makeTranslation(NdcPoint translation) {
        return new Transform(translation, NdcPoint.zero(), NdcPoint.identity());
    }

    public static Transform makeRotation(NdcPoint rotation) {
        return new Transform(NdcPoint.zero(), rotation, NdcPoint.identity());
    }

    public static Transform makeScale(NdcPoint scale) {
        return new Transform(NdcPoint.zero(), NdcPoint.zero(), scale);
    }

    public Transform(NdcPoint translation, NdcPoint rotation, NdcPoint scale) {
        super(nativeMakeTransform(translation.nativePtr, rotation.nativePtr, scale.nativePtr), TRANSFORM);
        this.translation = translation;
        this.rotation = rotation;
        this.scale = scale;
    }*/

    public Transform(long nativePtr) {
        super(nativePtr, TRANSFORM);
    }

    public void setTranslation(NdcPoint translation) {
        nativeSetTranslation(nativePtr, translation.nativePtr);
    }

    public void setRotation(NdcPoint rotation) {
        nativeSetRotation(nativePtr, rotation.nativePtr);
    }

    public void setScale(NdcPoint scale) {
        nativeSetScale(nativePtr, scale.nativePtr);
    }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        nativeDestroy(nativePtr);
    }

    /*@CriticalNative
    private static native long nativeMakeTransform(
            long translationPtr, long rotationPtr, long scalePtr);*/
    @CriticalNative
    private static native void nativeSetTranslation(long ptr, long translationPtr);
    @CriticalNative
    private static native void nativeSetRotation(long ptr, long rotationPtr);
    @CriticalNative
    private static native void nativeSetScale(long ptr, long scalePtr);
    @CriticalNative
    private static native void nativeDestroy(long ptr);
}
