package com.unknown.sample;

import com.unknown.UnknownEngine;
import com.unknown.component.Camera;
import com.unknown.component.DebugInfo;
import com.unknown.component.Transform;
import com.unknown.core.entity.Entity;
import com.unknown.core.entity.PrimitiveType;
import com.unknown.core.scene.Scene;
import com.unknown.core.scene.SceneManager;
import com.unknown.core.supposition.Vec3;

public class BoxScene implements IScene {
    private DebugInfo debugInfo;
    private long startTime;

    @Override
    public void doInit(UnknownEngine engine) {
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
        camera.setPosition(new Vec3(0.1f, 0.5f, 2f));
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
