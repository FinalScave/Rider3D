package com.unknown.render;

import android.view.Surface;

/**
 * Created by Scave on 2024/2/28
 */
public final class RenderConfig {
    public Surface surface;
    public int width;
    public int height;
    public boolean debug;

    public RenderConfig() {
    }

    public RenderConfig(Surface surface, int width, int height, boolean debug) {
        this.surface = surface;
        this.width = width;
        this.height = height;
        this.debug = debug;
    }
}
