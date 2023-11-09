package com.unknown.activity;

import android.app.Activity;
import android.os.Bundle;

import androidx.annotation.Nullable;

import com.unknown.render.SurfaceRenderLooper;
import com.unknown.view.Unknown3DGLSurfaceView;
import com.unknown.view.Unknown3DSurfaceView;

public class Unknown3DActivity extends Activity implements SurfaceRenderLooper.Callback {
    private Unknown3DSurfaceView unknown3DView;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        this.unknown3DView = new Unknown3DSurfaceView(this);
        setContentView(unknown3DView);
        unknown3DView.setCallback(this);
    }

    protected void setFps(short fps) {
        unknown3DView.setFps(fps);
    }

    @Override
    public void onInitScene() {

    }

    @Override
    public void onUpdateScene() {

    }

    @Override
    public void beforeRender() {

    }

    @Override
    public void afterRender() {

    }
}
