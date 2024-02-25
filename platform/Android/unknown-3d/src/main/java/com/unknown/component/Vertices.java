package com.unknown.component;

import static com.unknown.component.ComponentType.VERTICES;

import java.util.ArrayList;
import java.util.List;

import dalvik.annotation.optimization.CriticalNative;
import dalvik.annotation.optimization.FastNative;

public class Vertices extends Component {
    private List<Vertex> vertexList;

    public Vertices(long nativePtr) {
        super(nativePtr, VERTICES);
    }

    private Vertices() {
        super(nativeMakeVertices(), VERTICES);
    }

    public void addVertex(Vertex vertex) {
        nativeAddVertex(nativePtr, vertex.nativePtr);
        if (vertexList == null) {
            vertexList = new ArrayList<>();
        }
        vertexList.add(vertex);
    }

    public void addFace(Vertex v1, Vertex v2, Vertex v3, Vertex v4) {
        nativeAddFace(nativePtr, v1.nativePtr, v2.nativePtr, v3.nativePtr, v4.nativePtr);
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

    @CriticalNative
    private static native long nativeMakeVertices();
    @CriticalNative
    private static native void nativeAddVertex(long ptr, long vertexPtr);
    @CriticalNative
    private static native void nativeAddFace(long ptr, long v1Ptr, long v2Ptr, long v3Ptr, long v4Ptr);
    @FastNative
    private static native void nativeSetVertices(long ptr, long[] vertexPtr);
    @CriticalNative
    private static native void nativeDestroy(long ptr);
}
