package com.unknown.core;

public abstract class NativeObject {
    public final long nativePtr;

    public NativeObject(long nativePtr) {
        this.nativePtr = nativePtr;
    }
}
