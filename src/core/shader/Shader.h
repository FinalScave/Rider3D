//
// Created by Scave on 2023/11/13.
//

#ifndef UNKNOWN3D_SHADER_H
#define UNKNOWN3D_SHADER_H

#if (defined(ANDROID) || defined(HARMONY) || defined(FORCE_GLFW))

#include "glsl/vs_common.h"
#include "glsl/fs_common.h"
#include "glsl/vs_simple.h"
#include "glsl/fs_simple.h"

#elif (defined(IOS) || defined(MACOS))

#include "metal/vs_common.h"
#include "metal/fs_common.h"
#include "metal/vs_simple.h"
#include "metal/fs_simple.h"

#elif (defined(WINDOWS))

#include "hlsl/vs_common.h"
#include "hlsl/fs_common.h"
#include "hlsl/vs_simple.h"
#include "hlsl/fs_simple.h"

#else

#include "glsl/vs_common.h"
#include "glsl/fs_common.h"
#include "glsl/vs_simple.h"
#include "glsl/fs_simple.h"

#endif

#endif //UNKNOWN3D_SHADER_H
