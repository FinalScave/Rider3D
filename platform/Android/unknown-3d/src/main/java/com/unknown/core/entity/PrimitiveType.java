package com.unknown.core.entity;

public enum PrimitiveType {
    RECTANGLE(0),
    BOX(1),
    SPHERE(2),
    SKYBOX(3),
    CAPSULE(4),
    CYLINDER(5),
    TORUS(6);

    public final int value;
    PrimitiveType(int v) {
        value = v;
    }
}
