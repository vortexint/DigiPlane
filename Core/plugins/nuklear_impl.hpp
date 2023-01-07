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

#if defined(DIGIPLANE_NK_PLUGIN)

struct nk_digiplane_vertex {
    float position[2];
    float uv[2];
    nk_byte col[4];
};

static struct nk_digiplane {
    nk_context ctx;
	nk_font_atlas atlas;
	nk_font* font = nullptr; // memory owned by atlas
	nk_buffer cmds;
	nk_draw_null_texture null;
	bgfx::TextureHandle texture;
	bgfx::ProgramHandle shader;
	bgfx::UniformHandle s_texture;
	bgfx::VertexLayout layout;
} digiplane;

// load shaders static const char* nuklear_fs and tatic const char* nuklear_vs with bgfx


NK_API struct nk_context* nk_digiplane_init() {
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

    //{struct nk_glfw_device *dev = &glfw.ogl;
    //dev->max_vertex_buffer = max_vertex_buffer;
    //dev->max_element_buffer = max_element_buffer;
    //nk_glfw3_device_create();}

    //glfw.is_double_click_down = nk_false;
    //glfw.double_click_pos = nk_vec2(0, 0);

    //return digiplane.ctx;
    return 0;
}

#endif // DIGIPLANE_NK_PLUGIN