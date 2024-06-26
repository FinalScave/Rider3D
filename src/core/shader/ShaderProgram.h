﻿//
// Created by Scave on 2023/11/13.
//

#ifndef RIDER3D_SHADERPROGRAM_H
#define RIDER3D_SHADERPROGRAM_H

#include "Define.h"
#include "bgfx/bgfx.h"

NS_RIDER_BEGIN

    constexpr uint8_t MAX_UNIFORM_COUNT = 4;

    /// 着色器程序抽象基础类
    class ShaderProgram {
    public:
        ShaderProgram();

        ~ShaderProgram();

        /// 从二进制数据中载入着色器程序
        /// \param vs_data 顶点着色器代码
        /// \param vs_data_len 顶点着色器代码长度
        /// \param fs_data 片元着色器代码
        /// \param fs_data_len 片元着色器代码长度
        void Load(const unsigned char* vs_data,
                  uint16_t vs_data_len,
                  const unsigned char* fs_data,
                  uint16_t fs_data_len);

        /// 从指定路径加载着色器程序
        /// \param res_path 着色器程序所处目录路径
        /// \param vs_name 顶点着色器文件名
        /// \param fs_name 片元着色器文件名
        void Load(const char* res_path, const char* vs_name, const char* fs_name);

        bgfx::VertexLayout vertex_layout_;
        bgfx::ProgramHandle program_handle_ = BGFX_INVALID_HANDLE;
        bgfx::UniformHandle uniform_handles_[MAX_UNIFORM_COUNT] = {
                BGFX_INVALID_HANDLE,
                BGFX_INVALID_HANDLE,
                BGFX_INVALID_HANDLE,
                BGFX_INVALID_HANDLE
        };
    };

    class SimpleShaderProgram : public ShaderProgram {
    public:
        SimpleShaderProgram();
    };

    class CommonShaderProgram : public ShaderProgram {
    public:
        CommonShaderProgram();
    };

NS_RIDER_END

#endif //RIDER3D_SHADERPROGRAM_H
