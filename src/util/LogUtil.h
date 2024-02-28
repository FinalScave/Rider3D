//
// Created by Scave on 2023/11/10.
//

#ifndef RIDER3D_LOGUTIL_H
#define RIDER3D_LOGUTIL_H

#ifdef ENABLE_LOG

#include "log.h"
#define LOG_TAG "RIDER3D"
#define LOGI(fmt, ...) LogInfo("[" LOG_TAG"] " fmt, __VA_ARGS__)
#define LOGD(fmt, ...) LogDebug("[" LOG_TAG"] " fmt, __VA_ARGS__)
#define LOGW(fmt, ...) LogWarn("[" LOG_TAG"] " fmt, __VA_ARGS__)
#define LOGE(fmt, ...) LogError("[" LOG_TAG"] " fmt, __VA_ARGS__)

#else

#define LOGI(fmt, ...)
#define LOGD(fmt, ...)
#define LOGW(fmt, ...)
#define LOGE(fmt, ...)

#endif

#endif //RIDER3D_LOGUTIL_H
