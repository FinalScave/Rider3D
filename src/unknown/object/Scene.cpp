//
// Created by Scave on 2023/11/11.
//

#include "Scene.h"

UNKNOWN_NS_BEGIN

    Scene::Scene() : Object3DContainer(), lighting_enabled_(true) {
    }

    Scene::~Scene() {
        DELETE_PTR(camera_);
        DELETE_PTR(background_color_);
    }

    void Scene::SetCamera(Camera* camera) {
        this->camera_ = camera;
    }

UNKNOWN_NS_END
