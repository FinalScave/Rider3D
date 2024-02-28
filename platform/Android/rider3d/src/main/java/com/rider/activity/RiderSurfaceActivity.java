package com.rider.activity;

import android.app.Activity;
import android.os.Bundle;

import androidx.annotation.Nullable;

import com.rider.RiderEngine;
import com.rider.render.SurfaceRenderLooper;
import com.rider.view.RiderSurfaceView;

public class RiderSurfaceActivity extends Activity implements SurfaceRenderLooper.Callback {
    private RiderSurfaceView unknown3DView;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        this.unknown3DView = new RiderSurfaceView(this);
        setContentView(unknown3DView);
        unknown3DView.setCallback(this);
    }

    protected void setFps(short fps) {
        unknown3DView.setFps(fps);
    }

    @Override
    public boolean isDebug() {
        return false;
    }

    @Override
    public void onInit(RiderEngine engine) {

    }

    @Override
    public void onUpdate() {

    }

    @Override
    public void beforeRender() {

    }

    @Override
    public void afterRender() {

    }
}
