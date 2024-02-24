package com.unknown.core;

public abstract class NativeObject {
    protected long nativePtr;

    public NativeObject() {
    }

    public NativeObject(long nativePtr) {
        this.nativePtr = nativePtr;
    }
}
