package com.unknown.sample;

import android.os.Bundle;

import androidx.annotation.Nullable;

import com.unknown.UnknownEngine;
import com.unknown.activity.UnknownSurfaceActivity;

public class MainActivity extends UnknownSurfaceActivity {

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
    public void onInit(UnknownEngine engine) {
        boxScene.doInit(engine);
    }

    @Override
    public void onUpdate() {
        boxScene.doUpdate();
    }
}
