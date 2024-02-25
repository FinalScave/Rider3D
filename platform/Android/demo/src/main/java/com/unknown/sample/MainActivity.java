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
    private Entity box;
    private Transform transform;
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

        this.box = scenes.createPrimitiveEntity(PrimitiveType.BOX);
        this.transform = box.addComponent(Transform.class);
        transform.setTranslation(new Vec3(0.1f, 0f, 0f));

        mainScene.addEntity(box);
        Camera camera = mainScene.addComponent(Camera.class);
        camera.setPosition(new Vec3(0.1f, 0.5f, 2f));
        this.debugInfo = mainScene.addComponent(DebugInfo.class);
    }

    @Override
    public void onUpdate() {
        /*Random random = new Random();
        float x = (random.nextInt(100) - 50) / 100f;
        float y = (random.nextInt(100) - 50) / 100f;
        transform.setTranslation(new Vec3(x, y, 0));*/
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
