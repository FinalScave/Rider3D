//
// Created by Scave on 2023/11/9.
//

#ifndef UNKNOWN3D_VERTEX_H
#define UNKNOWN3D_VERTEX_H

#include <vector>
#include "Define.h"
#include "bgfx/bgfx.h"
#include "Supposition.h"

UNKNOWN_NS_BEGIN

    struct Vertex {
        ~Vertex();

        NdcPoint* position;
        TextureUVPoint* uv;
        Color* color;
    };

    struct Vertices {
        ~Vertices();

        void AddVertex(Vertex* vertex);

        void SetVertices(uint16_t vertices_count, Vertex** vertices);

        uint16_t Size() const;

        std::vector<Vertex*> vertex_list;
    };

    class DefaultVertexLayout {
    public:
        static void Init();

        static bgfx::VertexLayout Get();

    private:
        static bgfx::VertexLayout default_vertex_layout_;
    };

    class DefaultBgfxHandles {
    public:
        static void Init();

        static void Destroy();

        static bgfx::VertexBufferHandle GetVertexBufferHandle();

        static bgfx::IndexBufferHandle GetIndexBufferHandle();

    private:
        static bgfx::VertexBufferHandle default_vertex_buffer_handle_;
        static bgfx::IndexBufferHandle default_index_buffer_handle_;
    };

    const static uint8_t kDefaultVertexCount = 4;
    const static uint8_t kDefaultIndexCount = 6;
#ifdef ANDROID
    const static Vertex kDefaultVertices[kDefaultVertexCount] = {
            {
                    new NdcPoint {-1.0f, 1.0f,  0.0f},
                    new TextureUVPoint {1.0f, 0.0f},
                    new Color {0, 0, 0, 0}
            },
            {
                    new NdcPoint {1.0f,  1.0f,  0.0f},
                    new TextureUVPoint {0.0f, 0.0f},
                    new Color {0, 0, 0, 0}
            },
            {
                    new NdcPoint {-1.0f, -1.0f, 0.0f},
                    new TextureUVPoint {0.0f, 1.0f},
                    new Color {0, 0, 0, 0}
            },
            {
                    new NdcPoint {1.0f,  -1.0f, 0.0f},
                    new TextureUVPoint {1.0f, 1.0f},
                    new Color {0, 0, 0, 0}
            }
    };
#else
    const static Vertex kDefaultVertices[kDefaultVertexCount] = {
            {
                    {-1.0f, 1.0f, 0.0f},
                    {1.0f, 1.0f},
                    {0, 0, 0, 0}
            },
            {
                    {1.0f, 1.0f, 0.0f},
                    {0.0f, 1.0f},
                    {0, 0, 0, 0}
            },
            {
                    {-1.0f, -1.0f, 0.0f},
                    {0.0f, 0.0f},
                    {0, 0, 0, 0}
            },
            {
                    {1.0f, -1.0f, 0.0f},
                    {1.0f, 0.0f},
                    {0, 0, 0, 0}
            }
    };
#endif

    const static uint8_t kDefaultIndices[kDefaultIndexCount] = {
            1, 0, 2,
            1, 2, 3
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_VERTEX_H
