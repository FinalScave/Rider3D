package com.rider.sample;

import android.os.Bundle;

import androidx.annotation.Nullable;

import com.rider.RiderEngine;
import com.rider.activity.RiderSurfaceActivity;

public class MainActivity extends RiderSurfaceActivity {

    private final static short FPS = 60;
    private BoxScene boxScene = new BoxScene();

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setFps(FPS);
    }

    @Override
    public boolean isDebug() {
        return true;
    }

    @Override
    public void onInit(RiderEngine engine) {
        boxScene.doInit(engine);
    }

    @Override
    public void onUpdate() {
        boxScene.doUpdate();
    }
}
