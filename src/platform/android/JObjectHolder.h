//
// Created by Scave on 2023/11/11.
//

#ifndef UNKNOWN3D_JSMARTPTRHOLDER_H
#define UNKNOWN3D_JSMARTPTRHOLDER_H


#include "Define.h"

template<typename T>
class JSmartPtrHolder {
public:
    SMART_PTR<T> Get() {
        return this->ptr;
    }

    void Set(SMART_PTR<T> ptr) {
        this->ptr = ptr;
    }
private:
    SMART_PTR<T> ptr;
};


#endif //UNKNOWN3D_JSMARTPTRHOLDER_H
