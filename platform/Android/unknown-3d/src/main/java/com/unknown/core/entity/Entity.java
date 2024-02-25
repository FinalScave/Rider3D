package com.unknown.core.entity;

import com.unknown.component.Camera;
import com.unknown.component.Component;
import com.unknown.component.ComponentType;
import com.unknown.component.DebugInfo;
import com.unknown.component.Transform;
import com.unknown.component.Vertices;
import com.unknown.core.NativeObject;

import java.util.ArrayList;
import java.util.List;

import dalvik.annotation.optimization.CriticalNative;

public class Entity extends NativeObject {
    private List<Component> components;

    public Entity(long nativePtr) {
        super(nativePtr);
    }

    @SuppressWarnings("unchecked")
    public <T extends Component> T addComponent(ComponentType componentType) {
        long componentPtr = nativeAddComponent(nativePtr, componentType.type);
        if (componentPtr == -1) {
            throw new RuntimeException("Component '" + componentType.name + "' assign failed");
        }
        T component = null;
        switch (componentType) {
            case CAMERA:
                component = (T) new Camera(componentPtr);
                break;
            case TRANSFORM:
                component = (T) new Transform(componentPtr);
                break;
            case VERTICES:
                component = (T) new Vertices(componentPtr);
                break;
            case DEBUG_INFO:
                component = (T) new DebugInfo(componentPtr);
                break;
        }
        if (components == null) {
            components = new ArrayList<>();
        }
        components.add(component);
        return component;
    }

    public <T extends Component> T addComponent(Class<T> clazz) {
        ComponentType[] types = ComponentType.values();
        for (ComponentType type : types) {
            if (type.klass == clazz) {
                return addComponent(type);
            }
        }
        return null;
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
    private static native long nativeAddComponent(long ptr, int component_type);

    @CriticalNative
    private static native void nativeDestroy(long ptr);
}
