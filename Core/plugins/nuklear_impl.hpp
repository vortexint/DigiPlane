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
} digiplane;

// load shaders static const char* nuklear_fs and tatic const char* nuklear_vs with bgfx


NK_API struct nk_context* nk_digiplane_init() {
    return 0;
}

#endif // DIGIPLANE_NK_PLUGIN