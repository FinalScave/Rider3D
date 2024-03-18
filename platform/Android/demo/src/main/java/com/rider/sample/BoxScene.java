package com.rider.sample;

import com.rider.RiderEngine;
import com.rider.component.Camera;
import com.rider.component.DebugInfo;
import com.rider.component.Transform;
import com.rider.core.entity.Entity;
import com.rider.core.entity.PrimitiveType;
import com.rider.core.scene.Scene;
import com.rider.core.scene.SceneManager;
import com.rider.core.supposition.Vec3;

public class BoxScene implements IScene {
    private DebugInfo debugInfo;
    private long startTime;

    @Override
    public void doInit(RiderEngine engine) {
        SceneManager scenes = engine.getScenes();
        Scene mainScene = scenes.createScene();
        Camera camera = mainScene.addComponent(Camera.class);
        camera.setPosition(new Vec3(1.0f, 1.0f, 4.0f));
        scenes.loadScene(mainScene);

        Entity box1 = scenes.createPrimitiveEntity(PrimitiveType.BOX);
        mainScene.addEntity(box1);

        this.debugInfo = mainScene.addComponent(DebugInfo.class);
        debugInfo.setX(10);
        debugInfo.setY(10);
    }

    @Override
    public void doUpdate() {
        if (startTime > 0) {
            long endTime = System.currentTimeMillis();
            int fps = (int) (1000 / (endTime - startTime));
            debugInfo.setText("FPS: " + fps);
        }
        startTime = System.currentTimeMillis();
    }
}
