//
// Created by Scave on 2023/11/11.
//

#ifndef UNKNOWN3D_JREFHOLDER_H
#define UNKNOWN3D_JREFHOLDER_H

#include "Define.h"

template<typename T>
class JRefHolder {
public:
    explicit JRefHolder(T& target) : target(target) {}

    T& Get() {
        return this->target;
    }
private:
    T& target;
};

template<typename T>
class JUniqueCopier {
public:
    explicit JUniqueCopier(T target) : target(target) {}

    T& Get() {
        return this->target;
    }
private:
    T target;
};

#endif //UNKNOWN3D_JREFHOLDER_H
