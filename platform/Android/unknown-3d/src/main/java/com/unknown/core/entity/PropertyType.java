package com.unknown.core.entity;

public enum PropertyType {
    FACE_COLOR(0),
    VERTEX_COLOR(1),
    ;
    public final int type;
    PropertyType(int type) {
        this.type = type;
    }
}
