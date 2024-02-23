//
// Created by Scave on 2023/11/13.
//

#ifndef UNKNOWN3D_COMMONRENDERSTRATEGY_H
#define UNKNOWN3D_COMMONRENDERSTRATEGY_H

#include "Define.h"
#include "RenderStrategy.h"

UNKNOWN_NS_BEGIN

    class CommonRenderStrategy : public RenderStrategy {
    public:
        explicit CommonRenderStrategy(const SMART_PTR<RenderContext>& context);

        void RenderObject(Object3D &object) override;
    private:
        float vec4_resolution_[4] = {0};
        float model_matrix_[16] = {0};
        float view_matrix_[16] = {0};
        float proj_matrix_[16] = {0};
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_COMMONRENDERSTRATEGY_H
