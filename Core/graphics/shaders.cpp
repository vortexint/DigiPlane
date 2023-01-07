#include "./shaders.hpp"

bgfx::ShaderHandle loadShaderFile(const char *FILENAME)
{
    const char* shaderPath = "???";

    switch(bgfx::getRendererType()) {
        case bgfx::RendererType::Noop:
        case bgfx::RendererType::Direct3D9:  shaderPath = "shaders/dx9/";   break;
        case bgfx::RendererType::Direct3D11:
        case bgfx::RendererType::Direct3D12: shaderPath = "shaders/dx11/";  break;
        case bgfx::RendererType::Gnm:        shaderPath = "shaders/pssl/";  break;
        case bgfx::RendererType::Metal:      shaderPath = "shaders/metal/"; break;
        case bgfx::RendererType::OpenGL:     shaderPath = "shaders/glsl/";  break;
        case bgfx::RendererType::OpenGLES:   shaderPath = "shaders/essl/";  break;
        case bgfx::RendererType::Vulkan:     shaderPath = "shaders/spirv/"; break;
    }

    std::filesystem::path filePath = std::filesystem::path(shaderPath) / FILENAME;
    std::ifstream file(filePath, std::ios::binary | std::ios::ate);
    std::streamsize fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    const bgfx::Memory *mem = bgfx::alloc(fileSize + 1);
    file.read(reinterpret_cast<char*>(mem->data), fileSize);
    mem->data[mem->size - 1] = '\0';
    file.close();

    return bgfx::createShader(mem);
}

bgfx::ShaderHandle loadShaderString(const char *SHADER_STRING) {
    const bgfx::Memory *mem = bgfx::copy(SHADER_STRING, strlen(SHADER_STRING) + 1);
    return bgfx::createShader(mem);
}

const char* nuklear_fs = R"(
$input v_texcoord0, v_color0

SAMPLER2D(s_texture, 0);

void main() {
    gl_FragColor = v_color0 * texture2D(s_texture, v_texcoord0);
})";
const char* nuklear_vs = R"(
$input a_position, a_texcoord0, a_color0
$output v_texcoord0, v_color0

void main() {
    v_texcoord0 = a_texcoord0;
    v_color0 = a_color0;
    gl_Position = mul(u_viewProj, vec4(a_position.xy, 0.0, 1.0));
})";
