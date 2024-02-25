package com.unknown.sample;

import android.os.Bundle;

import androidx.annotation.Nullable;

import com.unknown.UnknownEngine;
import com.unknown.activity.UnknownSurfaceActivity;
import com.unknown.component.Camera;
import com.unknown.component.ComponentType;
import com.unknown.component.DebugInfo;
import com.unknown.component.Transform;
import com.unknown.core.entity.Entity;
import com.unknown.core.entity.PrimitiveType;
import com.unknown.core.scene.Scene;
import com.unknown.core.scene.SceneManager;
import com.unknown.core.supposition.Vec3;

import java.util.Random;

public class MainActivity extends UnknownSurfaceActivity {

    private final static short FPS = 60;
    private long startTime;
    private DebugInfo debugInfo;

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
        SceneManager scenes = engine.getScenes();
        Scene mainScene = scenes.createScene();
        scenes.loadScene(mainScene);

        Entity box1 = scenes.createPrimitiveEntity(PrimitiveType.BOX);
        Transform t1 = box1.addComponent(Transform.class);
        t1.setTranslation(new Vec3(-0.5f, 1f, 0));
        t1.setRotation(new Vec3(0.1f, 0.2f, 0.3f));
        Entity box2 = scenes.createPrimitiveEntity(PrimitiveType.BOX);
        Transform t2 = box2.addComponent(Transform.class);
        t1.setTranslation(new Vec3(0.6f, 0.6f, 0));
        t2.setRotation(new Vec3(0.2f, 0.4f, 0.1f));
        Entity box3 = scenes.createPrimitiveEntity(PrimitiveType.BOX);
        Transform t3 = box3.addComponent(Transform.class);
        t3.setTranslation(new Vec3(-0.5f, -0.8f, 0));
        t3.setRotation(new Vec3(0.2f, 0.4f, 0.1f));

        mainScene.addEntity(box1);
        mainScene.addEntity(box2);
        mainScene.addEntity(box3);
        Camera camera = mainScene.addComponent(Camera.class);
        camera.setPosition(new Vec3(0.1f, 0.5f, 3f));
        this.debugInfo = mainScene.addComponent(DebugInfo.class);
    }

    @Override
    public void onUpdate() {
    }

    @Override
    public void afterRender() {
        if (startTime > 0) {
            long endTime = System.currentTimeMillis();
            int fps = (int) (1000 / (endTime - startTime));
            long tmp = System.nanoTime();
            debugInfo.setX(10);
            System.out.println(
                    "==setX invoke finished in " + (System.nanoTime() - tmp) + "ns");
            tmp = System.nanoTime();
            debugInfo.setY(10);
            System.out.println(
                    "==setY invoke finished in " + (System.nanoTime() - tmp) + "ns");
            tmp = System.nanoTime();
            debugInfo.setText("FPS: " + fps);
            System.out.println(
                    "==setText invoke finished in " + (System.nanoTime() - tmp) + "ns");
        }
        startTime = System.currentTimeMillis();
    }
}
