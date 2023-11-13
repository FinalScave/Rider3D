//
// Created by Scave on 2023/11/13.
//

#ifndef UNKNOWN3D_SIMPLERENDERSTRATEGY_H
#define UNKNOWN3D_SIMPLERENDERSTRATEGY_H

#include "Define.h"
#include "RenderStrategy.h"

UNKNOWN_NS_BEGIN

    class SimpleRenderStrategy : public RenderStrategy {
    public:
        explicit SimpleRenderStrategy(const SMART_PTR<RenderContext>& context);

        void RenderObject(Object3D &object) override;
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_SIMPLERENDERSTRATEGY_H
