package com.unknown.component;

import com.unknown.core.supposition.NdcPoint;

import dalvik.annotation.optimization.CriticalNative;

public class Camera extends Component {
    private NdcPoint position;
    private NdcPoint target;
    private NdcPoint upAxis;

    public Camera(NdcPoint position, NdcPoint target, NdcPoint upAxis) {
        super(nativeMakeCamera(position.nativePtr, target.nativePtr, upAxis.nativePtr));
        this.position = position;
        this.target = target;
        this.upAxis = upAxis;
    }

    public NdcPoint position() {
        return position;
    }

    public NdcPoint target() {
        return target;
    }

    public NdcPoint upAxis() {
        return upAxis;
    }

    public void setPosition(NdcPoint position) {
        nativeSetPosition(nativePtr, position.nativePtr);
        this.position = position;
    }

    public void setTarget(NdcPoint point) {
        nativeSetTarget(nativePtr, point.nativePtr);
        this.target = point;
    }

    public void setUpAxis(NdcPoint point) {
        nativeSetUpAxis(nativePtr, point.nativePtr);
        this.upAxis = point;
    }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        nativeDestroy(nativePtr);
    }

    @CriticalNative
    private static native long nativeMakeCamera(long positionPtr, long targetPtr, long upAxisPtr);
    @CriticalNative
    private static native void nativeSetPosition(long ptr, long positionPtr);
    @CriticalNative
    private static native void nativeSetTarget(long ptr, long targetPtr);
    @CriticalNative
    private static native void nativeSetUpAxis(long ptr, long upAxisPtr);
    @CriticalNative
    private static native void nativeDestroy(long ptr);
}
