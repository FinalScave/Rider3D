//
// Created by Scave on 2023/11/13.
//

#include "ShaderProgram.h"
#include "Shader.h"
#include "bgfx/BgfxUtil.h"

UNKNOWN_NS_BEGIN

    ShaderProgram::~ShaderProgram() {
        DESTROY_MEMBER_BGFX_HANDLE(program_handle_);
        for (uint8_t i = 0; i < MAX_UNIFORM_COUNT; ++i) {
            DESTROY_MEMBER_BGFX_HANDLE(uniform_handles_[i]);
        }
    }

    void SimpleShaderProgram::Load(const unsigned char* vs_data, const unsigned int vs_data_len,
                                            const unsigned char* fs_data, const unsigned int fs_data_len) {
        this->program_handle_ = loadProgramFromData(
                VS_SIMPLE, VS_SIMPLE_LEN, FS_SIMPLE, FS_SIMPLE_LEN);
    }

    void SimpleShaderProgram::Load(const char *res_path, const char* vs_name, const char* fs_name) {
        this->program_handle_ = loadProgram(vs_name, fs_name, res_path);
    }

    void CommonShaderProgram::Load(const unsigned char* vs_data, const unsigned int vs_data_len,
                                            const unsigned char* fs_data, const unsigned int fs_data_len) {
        this->program_handle_ = loadProgramFromData(
                VS_SIMPLE, VS_SIMPLE_LEN, FS_SIMPLE, FS_SIMPLE_LEN);
        this->uniform_handles_[0] = bgfx::createUniform("u_resolution", bgfx::UniformType::Enum::Vec4);
    }

    void CommonShaderProgram::Load(const char *res_path, const char* vs_name, const char* fs_name) {
        this->program_handle_ = loadProgram(vs_name, fs_name, res_path);
        this->uniform_handles_[0] = bgfx::createUniform("u_resolution", bgfx::UniformType::Enum::Vec4);
    }

UNKNOWN_NS_END
