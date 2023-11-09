package com.unknown.render;

import android.os.Handler;
import android.os.HandlerThread;
import android.os.Message;
import android.view.Surface;

import com.unknown.Unknown3DEngine;

import java.util.concurrent.atomic.AtomicBoolean;

public final class SurfaceRenderLooper {
    private final static byte INIT = 0;
    private final static byte RENDER = 1;
    private final static byte DESTROY = 2;
    private final static byte DEFAULT_FPS = 70;

    private Unknown3DEngine engine;
    private final Handler handler;
    private final HandlerThread renderThread = new HandlerThread("Unknown3D");
    private final AtomicBoolean destroyed = new AtomicBoolean(false);
    private short fps = DEFAULT_FPS;
    private Callback callback;

    public SurfaceRenderLooper() {
        this.handler = new Handler(renderThread.getLooper(), this::handleMessage);
    }

    public void setCallback(Callback callback) {
        this.callback = callback;
    }

    public void init(Surface surface, int width, int height) {
        sendMessage(INIT, new Object[] {surface, width, height});
        if (callback != null) {
            callback.onInitScene();
        }
    }

    public void destroy() {
        sendEmptyMessage(DESTROY);
    }

    public void setFps(short fps) {
        this.fps = fps;
    }

    private void sendMessage(int what, Object obj) {
        Message message = Message.obtain();
        message.what = what;
        message.obj = obj;
        handler.sendMessage(message);
    }

    private void sendEmptyMessage(int what) {
        handler.sendEmptyMessage(what);
    }

    private boolean handleMessage(Message message) {
        switch (message.what) {
            case INIT:
                Object[] params = (Object[]) message.obj;
                Surface surface = (Surface) params[0];
                int width = (int) params[1];
                int height = (int) params[2];
                this.engine = new Unknown3DEngine(surface, width, height);
                destroyed.set(false);
                handler.sendEmptyMessageDelayed(RENDER, 1000 / fps);
                break;
            case RENDER:
                if (destroyed.get()) {
                    return true;
                }
                if (callback != null) {
                    callback.onUpdateScene();
                    callback.beforeRender();
                }
                engine.render();
                if (callback != null) {
                    callback.afterRender();
                }
                handler.sendEmptyMessageDelayed(RENDER, 1000 / fps);
                break;
            case DESTROY:
                engine.destroy();
                destroyed.set(true);
                return renderThread.quitSafely();
        }
        return true;
    }

    public interface Callback {
        void onInitScene();
        void onUpdateScene();
        void beforeRender();
        void afterRender();
    }
}
