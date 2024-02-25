package com.unknown.component;

public enum ComponentType {
    CAMERA(Camera.class, 1, "Camera"),
    TRANSFORM(Transform.class, 2, "Transform"),
    VERTEX(Vertex.class, 100, "Vertex"),
    VERTICES(Vertices.class, 101, "Vertices"),
    ;

    public final Class<?> klass;
    public final int type;
    public final String name;
    ComponentType(Class<?> klass, int type, String name) {
        this.klass = klass;
        this.type = type;
        this.name = name;
    }
}
