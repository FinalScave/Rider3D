package com.unknown.core.entity;

public enum PrimitiveType {
    RECTANGLE(0),
    TRIANGLE(1),
    BOX(10),
    SPHERE(11),
    SKYBOX(12),
    CAPSULE(13),
    CYLINDER(14),
    TORUS(15),
    TRIANGULAR_PYRAMID(16);

    public final int value;
    PrimitiveType(int v) {
        value = v;
    }
}
