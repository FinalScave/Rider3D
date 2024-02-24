package com.unknown.component;

import com.unknown.core.supposition.Color;
import com.unknown.core.supposition.NdcPoint;
import com.unknown.core.supposition.UV;

import dalvik.annotation.optimization.CriticalNative;

public class Vertex extends Component {
    private NdcPoint position;
    private UV uv;
    private Color color;

    public Vertex(NdcPoint position, UV uv, Color color) {
        super(nativeMakeVertex(position.nativePtr, uv.nativePtr, color.nativePtr));
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

    @CriticalNative
    private static native long nativeMakeVertex(long ndcPointPtr, long uvPtr, long colorPtr);
    @CriticalNative
    private static native void nativeSetPosition(long ptr, long ndcPointPtr);
    @CriticalNative
    private static native void nativeSetUv(long ptr, long uvPtr);
    @CriticalNative
    private static native void nativeSetColor(long ptr, long colorPtr);
    @CriticalNative
    private static native void nativeDestroy(long ptr);
}
