#pragma once
#if defined(DIGIPLANE_NK_PLUGIN)
/* 
    This file will compile Digiplane's implementation of Nuklear as an integrated part of your application,
    you still need Nuklear itself. See https://github.com/Immediate-Mode-UI/Nuklear
*/
#pragma message("Compiling Digiplane Nuklear Plugin")

namespace Diligent
{

struct IRenderDevice;
struct IDeviceContext;
enum TEXTURE_FORMAT : uint16_t;

} // namespace Diligent

NK_API struct nk_diligent_context* nk_diligent_init(Diligent::IRenderDevice* device,
                                                    unsigned int             width,
                                                    unsigned int             height,
                                                    Diligent::TEXTURE_FORMAT BackBufferFmt,
                                                    Diligent::TEXTURE_FORMAT DepthBufferFmt,
                                                    unsigned int             max_vertex_buffer_size,
                                                    unsigned int             max_index_buffer_size);

NK_API struct nk_context* nk_diligent_get_nk_ctx(struct nk_diligent_context* nk_dlg_ctx);

NK_API void nk_diligent_font_stash_begin(struct nk_diligent_context* nk_dlg_ctx,
                                         struct nk_font_atlas**      atlas);

NK_API void nk_diligent_font_stash_end(struct nk_diligent_context* nk_dlg_ctx,
                                       Diligent::IDeviceContext*   device_ctx);

NK_API void nk_diligent_render(struct nk_diligent_context* nk_dlg_ctx,
                               Diligent::IDeviceContext*   device_ctx,
                               enum nk_anti_aliasing       AA);

NK_API void nk_diligent_resize(struct nk_diligent_context* nk_dlg_ctx,
                               Diligent::IDeviceContext*   device_ctx,
                               unsigned int                width,
                               unsigned int                height);

NK_API void nk_diligent_shutdown(struct nk_diligent_context* nk_dlg_ctx);

#endif // DIGIPLANE_NK_PLUGIN