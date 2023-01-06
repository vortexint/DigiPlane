#pragma once

/* 
    This file will compile Digiplane's implementation of Nuklear as an integrated part of your application,
    you still need Nuklear itself. See https://github.com/Immediate-Mode-UI/Nuklear
*/

NK_API struct nk_context* nk_digiplane_init();
NK_API void nk_digiplane_font_stash_begin(struct nk_font_atlas **atlas);
NK_API void nk_digiplane_font_stash_end(void);
//NK_API int  nk_digiplane_handle_event()
NK_API void nk_digiplane_render(enum nk_anti_aliasing);
NK_API void nk_digiplane_shutdown(void);

#ifdef DIGIPLANE_NK_PLUGIN

struct nk_dp_device {
    struct nk_buffer cmds;
    struct nk_draw_null_texture tex_null;
    //SDL_Texture *font_tex;
};

struct nk_dp_vertex {
    float position[2];
    float uv[2];
    nk_byte col[4];
};

static struct nk_dp {
    struct nk_context ctx;
    struct nk_font_atlas atlas;
} dp;

NK_API struct nk_context*
nk_digiplane_init(GLFWwindow *win, enum nk_glfw_init_state init_state, int max_vertex_buffer, int max_element_buffer) {
    //glfw.win = win;
    //if (init_state == NK_GLFW3_INSTALL_CALLBACKS) {
    //    glfwSetScrollCallback(win, nk_gflw3_scroll_callback);
    //    glfwSetCharCallback(win, nk_glfw3_char_callback);
    //    glfwSetMouseButtonCallback(win, nk_glfw3_mouse_button_callback);
    //}
    //nk_init_default(&glfw.ctx, 0);
    //glfw.ctx.clip.copy = nk_glfw3_clipboard_copy;
    //glfw.ctx.clip.paste = nk_glfw3_clipboard_paste;
    //glfw.ctx.clip.userdata = nk_handle_ptr(0);
    //glfw.last_button_click = 0;
//
    //{struct nk_glfw_device *dev = &glfw.ogl;
    //dev->max_vertex_buffer = max_vertex_buffer;
    //dev->max_element_buffer = max_element_buffer;
    //nk_glfw3_device_create();}
//
    //glfw.is_double_click_down = nk_false;
    //glfw.double_click_pos = nk_vec2(0, 0);
//
    //return &glfw.ctx;
    return 0;
}

#endif // DIGIPLANE_NK_PLUGIN