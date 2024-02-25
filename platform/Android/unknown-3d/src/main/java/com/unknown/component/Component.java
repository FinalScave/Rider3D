package com.unknown.component;

import com.unknown.core.NativeObject;

public abstract class Component extends NativeObject {
    public final ComponentType type;

    public Component(long nativePtr, ComponentType componentType) {
        super(nativePtr);
        this.type = componentType;
    }
}
