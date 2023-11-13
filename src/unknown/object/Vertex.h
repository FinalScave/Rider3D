//
// Created by Scave on 2023/11/9.
//

#ifndef UNKNOWN3D_VERTEX_H
#define UNKNOWN3D_VERTEX_H

#include <vector>
#include "Define.h"
#include "unknown/object/bgfx/BgfxTexture.h"
#include "Supposition.h"

UNKNOWN_NS_BEGIN

    struct Vertex {
        ~Vertex();

        Vec3* position;
        UV* uv;
        Color* color;
    };

    struct Vertices {
        ~Vertices();

        void AddVertex(Vertex* vertex);

        void AddIndex(uint32_t index);

        void AddFace(Vertex* upper_left, Vertex* upper_right, Vertex* lower_right, Vertex* lower_left);

        void SetVertices(uint16_t vertices_count, Vertex** vertices);

        [[nodiscard("Get vertices size but no any usage")]] uint16_t VertexSize() const;

        [[nodiscard("Get indices size but no any usage")]] uint32_t IndexSize() const;

        std::vector<Vertex*> vertex_data_list;
        std::vector<uint32_t> vertex_index_list;
    };

    class VerticesManager {
    public:
        VerticesManager();

        ~VerticesManager();

        HashMap<Name, int> map;
    private:

    };

    const static uint8_t kDefaultVertexCount = 4;
    const static uint8_t kDefaultIndexCount = 6;
#if (defined(ANDROID) || defined(LINUX) || defined(HARMONY) || defined(WINDOWS))
    const static Vertex kDefaultVertices[kDefaultVertexCount] = {
            {
                    new NdcPoint {-1.0f, 1.0f,  0.0f},
                    new TextureUVPoint {1.0f, 0.0f},
                    new Color {0xff, 0, 0, 0}
            },
            {
                    new NdcPoint {1.0f,  1.0f,  0.0f},
                    new TextureUVPoint {0.0f, 0.0f},
                    new Color {0xff, 0, 0, 0}
            },
            {
                    new NdcPoint {-1.0f, -1.0f, 0.0f},
                    new TextureUVPoint {0.0f, 1.0f},
                    new Color {0xff, 0, 0, 0}
            },
            {
                    new NdcPoint {1.0f,  -1.0f, 0.0f},
                    new TextureUVPoint {1.0f, 1.0f},
                    new Color {0xff, 0, 0, 0}
            }
    };
#else
    const static Vertex kDefaultVertices[kDefaultVertexCount] = {
            {
                    new NdcPoint{-1.0f, 1.0f, 0.0f},
                    new TextureUVPoint{1.0f, 1.0f},
                    new Color{0, 0, 0, 0}
            },
            {
                    new NdcPoint{1.0f, 1.0f, 0.0f},
                    new TextureUVPoint{0.0f, 1.0f},
                    new Color{0, 0, 0, 0}
            },
            {
                    new NdcPoint{-1.0f, -1.0f, 0.0f},
                    new TextureUVPoint{0.0f, 0.0f},
                    new Color{0, 0, 0, 0}
            },
            {
                    new NdcPoint{1.0f, -1.0f, 0.0f},
                    new TextureUVPoint{1.0f, 0.0f},
                    new Color{0, 0, 0, 0}
            }
    };
#endif

    const static uint8_t kDefaultIndices[kDefaultIndexCount] = {
            1, 0, 2,
            1, 2, 3
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_VERTEX_H
