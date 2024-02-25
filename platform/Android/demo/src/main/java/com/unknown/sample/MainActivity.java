package com.unknown.sample;

import android.os.Bundle;

import androidx.annotation.Nullable;

import com.unknown.UnknownEngine;
import com.unknown.activity.UnknownSurfaceActivity;
import com.unknown.component.ComponentType;
import com.unknown.component.Transform;
import com.unknown.core.entity.Entity;
import com.unknown.core.entity.PrimitiveType;
import com.unknown.core.scene.Scene;
import com.unknown.core.scene.SceneManager;
import com.unknown.core.supposition.NdcPoint;
import com.unknown.core.supposition.Vec3;

public class MainActivity extends UnknownSurfaceActivity {

    private final static short FPS = 60;
    private long startTime;
    private Entity rectangle;
    private Transform transform;
    private int count = 0;

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

        this.rectangle = scenes.createPrimitiveEntity(PrimitiveType.RECTANGLE);
        this.transform = rectangle.addComponent(ComponentType.TRANSFORM);

        mainScene.addEntity(rectangle);
    }

    @Override
    public void onUpdate() {
        transform.setTranslation(new NdcPoint(0.5f, 0, 0));
        /*if (count < 10) {
            transform.translation().setX(0.1f * count);
            count++;
        } else {
            transform.translation().setX(-0.1f * count);
            count--;
        }*/
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
