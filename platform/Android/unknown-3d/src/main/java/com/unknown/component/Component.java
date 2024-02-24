package com.unknown.component;

import com.unknown.core.NativeObject;

public abstract class Component extends NativeObject {
    public Component(long nativePtr) {
        super(nativePtr);
    }
}
