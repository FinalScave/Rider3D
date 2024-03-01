#include "WNativeConverter.h"

RiderEngine* ToEngineNativePointer(NATIVE_PTR address) {
    RiderEngine* engine = reinterpret_cast<RiderEngine *>(address);
    return engine;
}

NATIVE_PTR ToEngineJsObject(RiderEngine* engine) {
    return reinterpret_cast<NATIVE_PTR>(engine);
}