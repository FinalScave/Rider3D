package com.unknown.sample;

import android.os.Bundle;

import androidx.annotation.Nullable;

import com.unknown.activity.Unknown3DActivity;

import java.util.Calendar;

public class MainActivity extends Unknown3DActivity {

    private final static short FPS = 90;
    private long startTime;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setFps(FPS);
    }

    @Override
    public void onInitScene() {

    }

    @Override
    public void onUpdateScene() {

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
