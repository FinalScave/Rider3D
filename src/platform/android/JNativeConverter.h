//
// Created by Scave on 2023/11/10.
//

#ifndef UNKNOWN3D_JNATIVECONVERTER_H
#define UNKNOWN3D_JNATIVECONVERTER_H

#include <jni.h>
#include "Unknown3DEngine.h"

NS_UNKNOWN::Unknown3DEngine* To3DEngineNativeObject(jlong address);

jlong To3DEngineJavaObject(NS_UNKNOWN::Unknown3DEngine* engine);

#endif //UNKNOWN3D_JNATIVECONVERTER_H
