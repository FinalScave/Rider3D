package com.unknown.core.supposition;

import com.unknown.core.NativeObject;

public class Object3D extends NativeObject {
    private RenderType renderType = RenderType.TRISTRP;
    private NdcPoint position = new NdcPoint(0, 0, 0);
    private NdcPoint rotation = new NdcPoint(0, 0, 0);
    private NdcPoint scale = new NdcPoint(0, 0, 0);
    private Vertices vertices = new Vertices();

    public Object3D(String name) {
        this.nativePtr = nativeMakeObject3D(name);
    }

    public void setRenderType(RenderType renderType) {
        nativeSetRenderType(nativePtr, renderType.value);
    }

    public NdcPoint position() {
        return position;
    }

    public NdcPoint rotation() {
        return rotation;
    }

    public NdcPoint scale() {
        return scale;
    }

    public Vertices vertices() {
        return vertices;
    }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        nativeDestroy(nativePtr);
    }

    private static native long nativeMakeObject3D(String name);
    private static native void nativeSetRenderType(long ptr, int type);
    private static native void nativeDestroy(long ptr);
}
