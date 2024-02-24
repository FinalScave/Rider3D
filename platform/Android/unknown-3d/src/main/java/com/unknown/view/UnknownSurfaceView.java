package com.unknown.view;

import android.content.Context;
import android.util.AttributeSet;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import androidx.annotation.NonNull;

import com.unknown.render.SurfaceRenderLooper;

public class UnknownSurfaceView extends SurfaceView {
    private SurfaceRenderLooper renderLooper;
    private SurfaceRenderLooper.Callback callback;
    private short fps = SurfaceRenderLooper.DEFAULT_FPS;

    public UnknownSurfaceView(Context context) {
        this(context, null);
    }

    public UnknownSurfaceView(Context context, AttributeSet attrs) {
        this(context, attrs, 0);
    }

    public UnknownSurfaceView(Context context, AttributeSet attrs, int defStyleAttr) {
        this(context, attrs, defStyleAttr, 0);
    }

    public UnknownSurfaceView(Context context, AttributeSet attrs, int defStyleAttr, int defStyleRes) {
        super(context, attrs, defStyleAttr, defStyleRes);
        init();
    }

    private void init() {
        getHolder().addCallback(new SurfaceHolder.Callback() {
            @Override
            public void surfaceCreated(@NonNull SurfaceHolder holder) {
                Surface surface = holder.getSurface();
                if (surface != null) {
                    int width = getWidth();
                    int height = getHeight();
                    renderLooper = new SurfaceRenderLooper();
                    renderLooper.init(surface, width, height);
                    if (callback != null) {
                        renderLooper.setCallback(callback);
                    }
                    renderLooper.setFps(fps);
                }
            }

            @Override
            public void surfaceChanged(@NonNull SurfaceHolder holder, int format, int width, int height) {

            }

            @Override
            public void surfaceDestroyed(@NonNull SurfaceHolder holder) {
                if (renderLooper != null) {
                    renderLooper.destroy();
                }
            }
        });
    }

    public void setFps(short fps) {
        this.fps = fps;
        if (renderLooper != null) {
            renderLooper.setFps(fps);
        }
    }

    public void setCallback(SurfaceRenderLooper.Callback callback) {
        this.callback = callback;
        if (renderLooper != null) {
            renderLooper.setCallback(callback);
        }
    }
}
