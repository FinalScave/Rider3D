package com.unknown.view;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.util.AttributeSet;

import com.unknown.Unknown3DEngine;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class Unknown3DGLSurfaceView extends GLSurfaceView implements GLSurfaceView.Renderer {
    protected Unknown3DEngine engine;

    public Unknown3DGLSurfaceView(Context context) {
        this(context, null);
    }

    public Unknown3DGLSurfaceView(Context context, AttributeSet attrs) {
        super(context, attrs);
        init();
    }

    private void init() {
        setRenderer(this);
    }

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {

    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        if (engine != null) {
            engine.destroy();
        }
        engine = new Unknown3DEngine(width, height);
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        engine.render();
    }
}
