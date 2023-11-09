package com.unknown.activity;

import android.app.Activity;
import android.os.Bundle;

import androidx.annotation.Nullable;

import com.unknown.view.Unknown3DGLSurfaceView;

public class Unknown3DGLActivity extends Activity {
    private Unknown3DGLSurfaceView unknown3DView;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        this.unknown3DView = new Unknown3DGLSurfaceView(this);
        setContentView(unknown3DView);
    }

    @Override
    protected void onPause() {
        super.onPause();
        unknown3DView.onPause();
    }

    @Override
    protected void onRestart() {
        super.onRestart();
        unknown3DView.onResume();
    }
}
