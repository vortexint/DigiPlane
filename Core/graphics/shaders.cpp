#include "./shaders.hpp"

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
