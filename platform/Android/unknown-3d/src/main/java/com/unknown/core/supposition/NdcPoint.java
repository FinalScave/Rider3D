package com.unknown.core.supposition;

import com.unknown.core.NativeObject;

import dalvik.annotation.optimization.CriticalNative;

public class NdcPoint extends NativeObject {

    public static NdcPoint zero() {
        return new NdcPoint(0, 0, 0);
    }

    public static NdcPoint identity() {
        return new NdcPoint(1, 1, 1);
    }

    public static NdcPoint add(NdcPoint a, NdcPoint b) {
        return new NdcPoint(nativeAdd(a.nativePtr, b.nativePtr));
    }

    public static NdcPoint sub(NdcPoint a, NdcPoint b) {
        return new NdcPoint(nativeSub(a.nativePtr, b.nativePtr));
    }

    public static NdcPoint scalar(NdcPoint a, NdcPoint b) {
        return new NdcPoint(nativeScalar(a.nativePtr, b.nativePtr));
    }

    public static float dot(NdcPoint a, NdcPoint b) {
        return nativeDot(a.nativePtr, b.nativePtr);
    }

    public static NdcPoint cross(NdcPoint a, NdcPoint b) {
        return new NdcPoint(nativeCross(a.nativePtr, b.nativePtr));
    }

    public static NdcPoint normalize(NdcPoint a) {
        return new NdcPoint(nativeNormalize(a.nativePtr));
    }

    public static float length(NdcPoint a) {
        return nativeLength(a.nativePtr);
    }

    public static float distance(NdcPoint a, NdcPoint b) {
        return nativeDistance(a.nativePtr, b.nativePtr);
    }

    public NdcPoint(float x, float y, float z) {
        super(nativeMakeNdcPoint(x, y, z));
    }

    public NdcPoint(long nativePtr) {
        super(nativePtr);
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

    @CriticalNative
    private static native long nativeMakeNdcPoint(float x, float y, float z);
    @CriticalNative
    private static native void nativeSetX(long ptr, float x);
    @CriticalNative
    private static native void nativeSetY(long ptr, float y);
    @CriticalNative
    private static native void nativeSetZ(long ptr, float z);
    @CriticalNative
    private static native void nativeDestroy(long ptr);

    @CriticalNative
    private static native long nativeAdd(long p1_ptr, long p2_ptr);
    @CriticalNative
    private static native long nativeSub(long p1_ptr, long p2_ptr);
    @CriticalNative
    private static native long nativeScalar(long p_ptr, float f);
    @CriticalNative
    private static native float nativeDot(long p1_ptr, long p2_ptr);
    @CriticalNative
    private static native long nativeCross(long p1_ptr, long p2_ptr);
    @CriticalNative
    private static native long nativeNormalize(long p_ptr);
    @CriticalNative
    private static native float nativeLength(long p_ptr);
    @CriticalNative
    private static native float nativeDistance(long p1_ptr, long p2_ptr);
}
