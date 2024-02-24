package com.unknown.core.entity;

import com.unknown.component.Component;
import com.unknown.core.NativeObject;

import java.util.ArrayList;
import java.util.List;

import dalvik.annotation.optimization.CriticalNative;

public class Entity extends NativeObject {
    private List<Component> components;

    public Entity(long nativePtr) {
        super(nativePtr);
    }

    public void addComponent(Component component) {
        nativeAddComponent(nativePtr, component.nativePtr);
        if (components == null) {
            components = new ArrayList<>();
        }
        components.add(component);
    }

    @SuppressWarnings("unchecked")
    public <T extends Component> T getComponent(Class<T> componentClass) {
        if (components == null) {
            return null;
        }
        for (Component component : components) {
            if (component.getClass() == componentClass) {
                return (T) component;
            }
        }
        return null;
    }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        nativeDestroy(nativePtr);
    }

    @CriticalNative
    private static native void nativeAddComponent(long ptr, long component_ptr);

    @CriticalNative
    private static native void nativeDestroy(long ptr);
}
