//
// Created by Scave on 2023/11/10.
//

#include "JNativeConverter.h"

UnknownEngine* ToEngineNativePointer(long address) {
    UnknownEngine* engine = reinterpret_cast<UnknownEngine *>(address);
    return engine;
}

jlong ToEngineJavaObject(UnknownEngine* engine) {
    return reinterpret_cast<jlong>(engine);
}
