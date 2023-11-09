//
// Created by Scave on 2023/11/10.
//

#ifndef UNKNOWN3D_LOGUTIL_H
#define UNKNOWN3D_LOGUTIL_H

#include "log.h"

#define LOG_TAG "UNKNOWN3D"
#define LOGI(fmt, ...) LogInfo("[" LOG_TAG"] " fmt, __VA_ARGS__)
#define LOGD(fmt, ...) LogDebug("[" LOG_TAG"] " fmt, __VA_ARGS__)
#define LOGW(fmt, ...) LogWarn("[" LOG_TAG"] " fmt, __VA_ARGS__)
#define LOGE(fmt, ...) LogError("[" LOG_TAG"] " fmt, __VA_ARGS__)

#endif //UNKNOWN3D_LOGUTIL_H
