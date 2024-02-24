//
// Created by Scave on 2023/11/11.
//

#ifndef UNKNOWN3D_JOBJECTHOLDER_H
#define UNKNOWN3D_JOBJECTHOLDER_H

#include "Define.h"

template<typename T>
class JObjectHolder {
public:
    T Get() {
        return this->target;
    }

    void Set(T obj) {
        this->target = obj;
    }
private:
    T target;
};

template<typename T>
class JSmartPtrHolder : public JObjectHolder<SMART_PTR<T>>{
};

#endif //UNKNOWN3D_JOBJECTHOLDER_H
