package com.rider.component;

public enum ComponentType {
    CAMERA(Camera.class, 1, "Camera"),
    TRANSFORM(Transform.class, 2, "Transform"),
    VERTEX(Vertex.class, 100, "Vertex"),
    VERTICES(Vertices.class, 101, "Vertices"),
    DEBUG_INFO(DebugInfo.class, 200, "DebugInfo"),
    ;

    public final Class<? extends Component> klass;
    public final int type;
    public final String name;
    ComponentType(Class<? extends Component> klass, int type, String name) {
        this.klass = klass;
        this.type = type;
        this.name = name;
    }
}
