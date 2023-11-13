//
// Created by Scave on 2023/11/13.
//

#include "ShaderProgram.h"
#include "Shader.h"
#include "bgfx/BgfxUtil.h"
#include "object/Supposition.h"

UNKNOWN_NS_BEGIN

    ShaderProgram::ShaderProgram() = default;

    ShaderProgram::~ShaderProgram() {
        DESTROY_MEMBER_BGFX_HANDLE(program_handle_);
        for (uint8_t i = 0; i < MAX_UNIFORM_COUNT; ++i) {
            DESTROY_MEMBER_BGFX_HANDLE(uniform_handles_[i]);
        }
    }

    void ShaderProgram::Load(const unsigned char* vs_data,
                             const unsigned int vs_data_len,
                             const unsigned char* fs_data,
                             const unsigned int fs_data_len) {
        this->program_handle_ = loadProgramFromData(
                vs_data, vs_data_len, fs_data, fs_data_len);
    }

    void ShaderProgram::Load(const char* res_path, const char* vs_name, const char* fs_name) {
        this->program_handle_ = loadProgram(vs_name, fs_name, res_path);
    }

    SimpleShaderProgram::SimpleShaderProgram() {
        vertex_layout_
                .begin()
                .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
                .skip(sizeof(TextureUVPoint))
                .add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Float)
                .end();
        this->Load(VS_SIMPLE, VS_SIMPLE_LEN, FS_SIMPLE, FS_SIMPLE_LEN);
    }

    CommonShaderProgram::CommonShaderProgram() {
        vertex_layout_
                .begin()
                .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
                .add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float)
                .add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Float)
                .end();
        this->Load(VS_COMMON, VS_COMMON_LEN, FS_COMMON, FS_COMMON_LEN);
        this->uniform_handles_[0] = bgfx::createUniform("u_resolution", bgfx::UniformType::Enum::Vec4);
    }

UNKNOWN_NS_END
