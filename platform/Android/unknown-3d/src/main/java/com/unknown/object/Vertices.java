package com.unknown.object;

import java.util.ArrayList;
import java.util.List;

public class Vertices extends NativeObject {
    private List<Vertex> vertexList;

    public Vertices() {
        this.nativePtr = nativeMakeVertices();
    }

    public void addVertex(Vertex vertex) {
        nativeAddVertex(nativePtr, vertex.nativePtr);
        if (vertexList == null) {
            vertexList = new ArrayList<>();
        }
        vertexList.add(vertex);
    }

    public void setVertices(List<Vertex> vertices) {
        long[] ptrs = new long[vertices.size()];
        for (int i = 0; i < vertices.size(); i++) {
            ptrs[i] = vertices.get(i).nativePtr;
        }
        nativeSetVertices(nativePtr, ptrs);
        this.vertexList = vertices;
    }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        nativeDestroy(nativePtr);
    }

    private static native long nativeMakeVertices();
    private static native void nativeAddVertex(long ptr, long vertexPtr);
    private static native void nativeSetVertices(long ptr, long[] vertexPtr);
    private static native void nativeDestroy(long ptr);
}
