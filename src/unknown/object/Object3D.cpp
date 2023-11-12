//
// Created by Scave on 2023/11/10.
//

#include "Object3D.h"

#include <utility>
#include "LogUtil.h"

UNKNOWN_NS_BEGIN

    Object3D::Object3D(std::string name) : name(std::move(name)) {
        this->position = new Vec3 {0, 0, 0};
        this->rotation = new Vec3 {0, 0, 0};
        this->scale = new Vec3 {0, 0, 0};
        this->vertices = new Vertices;
    }

    Object3D::~Object3D() {
        DELETE_PTR(position);
        DELETE_PTR(rotation);
        DELETE_PTR(scale);
        DELETE_PTR(vertices);
    }

    std::string Object3D::GetName() {
        return this->name;
    }

    void Object3DContainer::AddChild(Object3D &object) {
        if (child_list.size() >= UINT8_MAX) {
            LOGW("Object3DContainer can only add %ud child objects", UINT8_MAX);
            return;
        }
        child_list.push_back(object);
    }

    void Object3DContainer::AddChildAt(uint8_t index, Object3D &object) {
        if (index > child_list.size() || child_list.size() > UINT8_MAX) {
            LOGW("Object3DContainer can only add %ud child objects", UINT8_MAX);
            return;
        }
        const std::vector<Object3D, std::allocator<Object3D>>::const_iterator &end = child_list.cend();
        uint8_t i(0);
        for (auto iterator = child_list.cbegin(); iterator != end; ++iterator) {
            if (index == i++) {
                child_list.insert(iterator, object);
                break;
            }
        }
    }

    void Object3DContainer::RemoveChild(Object3D &object) {
        const std::vector<Object3D, std::allocator<Object3D>>::const_iterator &end = child_list.cend();
        for (auto iterator = child_list.cbegin(); iterator != end; ++iterator) {
            if (&object == &*iterator) {
                child_list.erase(iterator);
                break;
            }
        }
    }

    void Object3DContainer::RemoveChildAt(uint8_t index) {
        if (index > child_list.size() - 1) {
            LOGW("index can not greater than %ud", UINT8_MAX - 1);
            return;
        }
        const std::vector<Object3D, std::allocator<Object3D>>::const_iterator &end = child_list.cend();
        uint8_t i(0);
        for (auto iterator = child_list.cbegin(); iterator != end; ++iterator) {
            if (index == i++) {
                child_list.erase(iterator);
                break;
            }
        }
    }

    Object3D &Object3DContainer::GetChildAt(uint8_t index) {
        return child_list[index];
    }

    uint8_t Object3DContainer::Size() {
        return child_list.size();
    }

    Box::Box(const Name &name, float width, float height, float depth) : Object3D(name) {
        this->width = width;
        this->height = height;
        this->depth = depth;
        this->Build();
    }

    void Box::Build() {
        float w = width / 2.f;
        float h = height / 2.f;
        float d = depth / 2.f;

        Color* color = new Color{66, 77, 0xff, 0xff};
        // front
        Vertex* front_v1 = new Vertex {new Vec3 {-w, +h , +d}, new UV {0, 0}, color};
        Vertex* front_v2 = new Vertex {new Vec3 {+w, +h , +d}, new UV {1, 0}, color};
        Vertex* front_v3 = new Vertex {new Vec3 {+w, -h , +d}, new UV {1, 1}, color};
        Vertex* front_v4 = new Vertex {new Vec3 {-w, -h , +d}, new UV {0, 1}, color};
        vertices->AddFace(front_v1, front_v2, front_v3, front_v4);
        // right
        Vertex* right_v1 = new Vertex {new Vec3 {+w, +h , +d}, new UV {0, 0}, color};
        Vertex* right_v2 = new Vertex {new Vec3 {+w, +h , -d}, new UV {1, 0}, color};
        Vertex* right_v3 = new Vertex {new Vec3 {+w, -h , -d}, new UV {1, 1}, color};
        Vertex* right_v4 = new Vertex {new Vec3 {+w, -h , +d}, new UV {0, 1}, color};
        vertices->AddFace(right_v1, right_v2, right_v3, right_v4);
        // back
        Vertex* back_v1 = new Vertex {new Vec3 {+w, +h , -d}, new UV {0, 0}, color};
        Vertex* back_v2 = new Vertex {new Vec3 {-w, +h , -d}, new UV {1, 0}, color};
        Vertex* back_v3 = new Vertex {new Vec3 {-w, -h , -d}, new UV {1, 1}, color};
        Vertex* back_v4 = new Vertex {new Vec3 {+w, -h , -d}, new UV {0, 1}, color};
        vertices->AddFace(back_v1, back_v2, back_v3, back_v4);
        // left
        Vertex* left_v1 = new Vertex {new Vec3 {-w, +h , -d}, new UV {0, 0}, color};
        Vertex* left_v2 = new Vertex {new Vec3 {-w, +h , +d}, new UV {1, 0}, color};
        Vertex* left_v3 = new Vertex {new Vec3 {-w, -h , +d}, new UV {1, 1}, color};
        Vertex* left_v4 = new Vertex {new Vec3 {-w, -h , -d}, new UV {0, 1}, color};
        vertices->AddFace(left_v1, left_v2, left_v3, left_v4);
        // top
        Vertex* top_v1 = new Vertex {new Vec3 {-w, +h , -d}, new UV {0, 0}, color};
        Vertex* top_v2 = new Vertex {new Vec3 {+w, +h , -d}, new UV {1, 0}, color};
        Vertex* top_v3 = new Vertex {new Vec3 {+w, +h , +d}, new UV {1, 1}, color};
        Vertex* top_v4 = new Vertex {new Vec3 {-w, +h , +d}, new UV {0, 1}, color};
        vertices->AddFace(top_v1, top_v2, top_v3, top_v4);
        // bottom
        Vertex* bottom_v1 = new Vertex {new Vec3 {-w, -h , +d}, new UV {0, 0}, color};
        Vertex* bottom_v2 = new Vertex {new Vec3 {+w, -h , +d}, new UV {1, 0}, color};
        Vertex* bottom_v3 = new Vertex {new Vec3 {+w, -h , -d}, new UV {1, 1}, color};
        Vertex* bottom_v4 = new Vertex {new Vec3 {-w, -h , -d}, new UV {0, 1}, color};
        vertices->AddFace(bottom_v1, bottom_v2, bottom_v3, bottom_v4);
    }

    Sphere::Sphere(Name name, uint16_t row_count, uint16_t column_count, float radius) : Object3D(std::move(name)) {
        this->row_count = row_count;
        this->column_count = column_count;
        this->radius = radius;
        this->Build();
    }

    void Sphere::Build() {

    }
UNKNOWN_NS_END

