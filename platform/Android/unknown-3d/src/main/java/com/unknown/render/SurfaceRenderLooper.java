package com.unknown.render;

import android.os.Handler;
import android.os.HandlerThread;
import android.os.Message;
import android.view.Surface;

import com.unknown.UnknownEngine;

import java.util.concurrent.atomic.AtomicBoolean;

public final class SurfaceRenderLooper {
    private final static byte INIT = 0;
    private final static byte UPDATE = 1;
    private final static byte DESTROY = 2;
    public final static byte DEFAULT_FPS = 70;

    private UnknownEngine engine;
    private final Handler handler;
    private final HandlerThread renderThread = new HandlerThread("Unknown3D");
    private final AtomicBoolean destroyed = new AtomicBoolean(false);
    private short fps = DEFAULT_FPS;
    private Callback callback;

    public SurfaceRenderLooper() {
        renderThread.start();
        this.handler = new Handler(renderThread.getLooper(), this::handleMessage);
    }

    public void setCallback(Callback callback) {
        this.callback = callback;
    }

    public void init(Surface surface, int width, int height) {
        sendMessage(INIT, new Object[] {surface, width, height});
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
                this.engine = new UnknownEngine(surface, width, height);
                destroyed.set(false);
                if (callback != null) {
                    callback.onInit(engine);
                }
                handler.sendEmptyMessageDelayed(UPDATE, 1000 / fps);
                break;
            case UPDATE:
                if (destroyed.get()) {
                    return true;
                }
                if (callback != null) {
                    callback.onUpdate();
                    callback.beforeRender();
                }
                engine.update();
                if (callback != null) {
                    callback.afterRender();
                }
                handler.sendEmptyMessageDelayed(UPDATE, 1000 / fps);
                break;
            case DESTROY:
                engine.destroy();
                destroyed.set(true);
                return renderThread.quitSafely();
        }
        return true;
    }

    public interface Callback {
        void onInit(UnknownEngine engine);
        void onUpdate();
        void beforeRender();
        void afterRender();
    }
}
