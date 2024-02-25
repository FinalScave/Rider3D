package com.unknown.component;

import dalvik.annotation.optimization.CriticalNative;
import dalvik.annotation.optimization.FastNative;

public class DebugInfo extends Component {

    public DebugInfo(long nativePtr) {
        super(nativePtr, ComponentType.DEBUG_INFO);
    }

    public void setX(int screenX) {
        nativeSetX(nativePtr, screenX);
    }

    public void setY(int screenY) {
        nativeSetY(nativePtr, screenY);
    }

    public void setColor(int color) {
        nativeSetColor(nativePtr, color);
    }

    public void setText(String text) {
        nativeSetText(nativePtr, text);
    }

    @CriticalNative
    private static native void nativeSetX(long ptr, int screenX);
    @CriticalNative
    private static native void nativeSetY(long ptr, int screenY);
    @CriticalNative
    private static native void nativeSetColor(long ptr, int color);
    @FastNative
    private static native void nativeSetText(long ptr, String text);
}
