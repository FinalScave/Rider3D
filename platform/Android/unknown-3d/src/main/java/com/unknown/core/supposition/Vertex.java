package com.unknown.core.supposition;

import com.unknown.core.NativeObject;

public class Vertex extends NativeObject {
    private NdcPoint position;
    private UV uv;
    private Color color;

    public Vertex(NdcPoint position, UV uv, Color color) {
        this.nativePtr = nativeMakeVertex(position.nativePtr, uv.nativePtr, color.nativePtr);
        this.position = position;
        this.uv = uv;
        this.color = color;
    }

    public NdcPoint position() {
        return position;
    }

    public UV uv() {
        return uv;
    }

    public Color color() {
        return color;
    }

    public void setPosition(NdcPoint position) {
        nativeSetPosition(nativePtr, position.nativePtr);
        this.position = position;
    }

    public void setUv(UV uv) {
        nativeSetUv(nativePtr, uv.nativePtr);
        this.uv = uv;
    }

    public void setColor(Color color) {
        nativeSetColor(nativePtr, color.nativePtr);
        this.color = color;
    }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        nativeDestroy(nativePtr);
    }

    private static native long nativeMakeVertex(long ndcPointPtr, long uvPtr, long colorPtr);
    private static native void nativeSetPosition(long ptr, long ndcPointPtr);
    private static native void nativeSetUv(long ptr, long uvPtr);
    private static native void nativeSetColor(long ptr, long colorPtr);
    private static native void nativeDestroy(long ptr);
}
