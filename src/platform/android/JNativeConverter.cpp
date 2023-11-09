//
// Created by Scave on 2023/11/10.
//

#include "JNativeConverter.h"

NS_UNKNOWN::Unknown3DEngine* To3DEngineNativeObject(long address) {
    NS_UNKNOWN::Unknown3DEngine* engine = reinterpret_cast<unknown::Unknown3DEngine *>(address);
    return engine;
}

jlong To3DEngineJavaObject(NS_UNKNOWN::Unknown3DEngine* engine) {
    return reinterpret_cast<jlong>(engine);
}