//
// Created by Scave on 2024/2/22.
//

#ifndef UNKNOWN3D_BASICCOMPONENTS_H
#define UNKNOWN3D_BASICCOMPONENTS_H

#include <vector>
#include "Define.h"
#include "Supposition.h"

UNKNOWN_NS_BEGIN

    struct Position {
        Vec3 value;
    };

    struct Transform {
        Vec3 translation = {0, 0, 0};
        Vec3 rotation = {0, 0, 0};
        Vec3 scale = {1, 1, 1};
    };

    struct Camera {
        Vec3 position = {0, 0, 5};
        Vec3 target = {0, 0, 0};
        Vec3 up_axis = {0, 0, 0};
    };

    struct EntityConfig {
        bool visible = true;
        bool vertex_colors_enabled = true;
        bool textures_enabled = true;
        bool normals_enabled = true;
        bool ignore_faces = false;
        bool lighting_enabled = true;
        float point_size = 3.f;
        bool point_smoothing = true;
        float line_width = 1.f;
        bool line_smoothing = false;
        Color background_color = {0, 0, 0, 0};
    };

    struct Vertex {
        Vec3 position = {0, 0, 0};
        UV uv = {0, 0};
        Color color = {1, 1, 1, 1};
    };

    struct Vertices {
        Vertices();
        ~Vertices();

        void AddVertex(Vertex& vertex);

        void AddIndex(uint32_t index);

        void AddFace(Vertex& upper_left, Vertex& upper_right, Vertex& lower_right, Vertex& lower_left);

        void SetVertices(uint16_t vertices_count, Vertex*& vertices);

        uint16_t VertexSize() const;

        uint32_t IndexSize() const;

        std::vector<Vertex> vertex_data_list{};
        std::vector<uint32_t> vertex_index_list{};
    };

    class VerticesManager {
    public:
        VerticesManager();

        ~VerticesManager();

        HASHMAP<Name, int> map;
    private:

    };

    const static uint8_t kDefaultVertexCount = 4;
    const static uint8_t kDefaultIndexCount = 6;
#if (defined(ANDROID) || defined(LINUX) || defined(HARMONY) || defined(WINDOWS))
    const static Vertex kDefaultVertices[kDefaultVertexCount] = {
            {
                    {-1.0f, 1.0f,  0.0f},
                    {1.0f, 0.0f},
                    {0xff, 0, 0, 0}
            },
            {
                    {1.0f,  1.0f,  0.0f},
                    {0.0f, 0.0f},
                    {0xff, 0, 0, 0}
            },
            {
                    {-1.0f, -1.0f, 0.0f},
                    {0.0f, 1.0f},
                    {0xff, 0, 0, 0}
            },
            {
                    {1.0f,  -1.0f, 0.0f},
                    {1.0f, 1.0f},
                    {0xff, 0, 0, 0}
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

    struct DebugInfo {
        UInt16 x = 0, y = 0;
        UInt8 color = 0xff;
        const char* text = nullptr;
    };

UNKNOWN_NS_END
#endif //UNKNOWN3D_BASICCOMPONENTS_H
