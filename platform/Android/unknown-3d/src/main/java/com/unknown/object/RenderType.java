package com.unknown.object;

public enum RenderType {
    POINTS(0),
    LINES(1),
    LINESTRIP(2),
    TRISTRP(3);

    final int value;

    RenderType(int value) {
        this.value = value;
    }
}
