package com.unknown.sample;

import android.os.Bundle;

import androidx.annotation.Nullable;

import com.unknown.UnknownEngine;
import com.unknown.activity.UnknownSurfaceActivity;
import com.unknown.component.Transform;
import com.unknown.core.entity.Entity;
import com.unknown.core.scene.Scene;
import com.unknown.core.scene.SceneManager;
import com.unknown.core.supposition.NdcPoint;

public class MainActivity extends UnknownSurfaceActivity {

    private final static short FPS = 60;
    private long startTime;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setFps(FPS);
    }

    @Override
    public void onInit(UnknownEngine engine) {
        SceneManager scenes = engine.getScenes();
        Scene mainScene = scenes.createScene();
        scenes.loadScene(mainScene);

        Entity rectangle = engine.getEntities().createEntity();
        NdcPoint translation = NdcPoint.zero();
        NdcPoint rotation = NdcPoint.zero();
        NdcPoint scale = NdcPoint.zero();
        Transform transform = new Transform(translation, rotation, scale);
        rectangle.addComponent(transform);

        mainScene.addEntity(rectangle);
    }

    @Override
    public void onUpdate() {
        super.onUpdate();
    }

    @Override
    public void afterRender() {
        if (startTime > 0) {
            long endTime = System.currentTimeMillis();
            System.out.println("====FPS: " + (1000 / (endTime - startTime)));
        }
        startTime = System.currentTimeMillis();
    }
}
