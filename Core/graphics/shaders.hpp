#ifndef SHADERS_HPP
#define SHADERS_HPP

bgfx::ShaderHandle loadShader(const char *FILENAME);
bgfx::ShaderHandle loadShaderString(const char *SHADER_STRING);

extern const char* fs_nuklear;
extern const char* vs_nuklear;

#endif