//
// Created by Scave on 2023/11/10.
//

#include "JNativeConverter.h"

RiderEngine* ToEngineNativePointer(long address) {
    RiderEngine* engine = reinterpret_cast<RiderEngine *>(address);
    return engine;
}

jlong ToEngineJavaObject(RiderEngine* engine) {
    return reinterpret_cast<jlong>(engine);
}
