package com.unknown.sample;

import android.os.Bundle;

import androidx.annotation.Nullable;

import com.unknown.UnknownEngine;
import com.unknown.activity.UnknownSurfaceActivity;
import com.unknown.component.Component;
import com.unknown.component.ComponentType;
import com.unknown.component.DebugInfo;
import com.unknown.component.Transform;
import com.unknown.core.entity.Entity;
import com.unknown.core.entity.PrimitiveType;
import com.unknown.core.scene.Scene;
import com.unknown.core.scene.SceneManager;
import com.unknown.core.supposition.NdcPoint;
import com.unknown.core.supposition.Vec3;

import java.util.Random;

public class MainActivity extends UnknownSurfaceActivity {

    private final static short FPS = 60;
    private long startTime;
    private Entity rectangle;
    private Transform transform;
    private DebugInfo debugInfo;

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
        this.debugInfo = rectangle.addComponent(ComponentType.DEBUG_INFO);
        debugInfo.setX(100);
        debugInfo.setY(100);

        mainScene.addEntity(rectangle);
    }

    @Override
    public void onUpdate() {
        Random random = new Random();
        float x = (random.nextInt(100) - 50) / 100f;
        float y = (random.nextInt(100) - 50) / 100f;
        transform.setTranslation(new Vec3(x, y, 0));
    }

    @Override
    public void afterRender() {
        if (startTime > 0) {
            long endTime = System.currentTimeMillis();
            int fps = (int) (1000 / (endTime - startTime));
            debugInfo.setText("FPS: " + fps);
        }
        startTime = System.currentTimeMillis();
    }
}
