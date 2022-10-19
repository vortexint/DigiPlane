// Dear ImGui: standalone example application for SDL2 + OpenGL
// (SDL is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#include "glad/glad.h"
#include <SDL.h>
#include <SDL_opengl.h>
#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_IMPLEMENTATION
#define NK_SDL_GL3_IMPLEMENTATION
// disable warning for header
#pragma warning(push, 0)
#include "nuklear.h"
#pragma warning(pop)
#include "nuklear_sdl_gl3.h"

#include "interface/Interface.hpp"
#include "interface/precompiled_fonts.hpp"

#define MAX_VERTEX_MEMORY 512 * 1024
#define MAX_ELEMENT_MEMORY 128 * 1024

#ifdef _WIN32
#include <Windows.h>
#endif

/* Global variables */
const char* engine_name = "DigiPlane";

int main(int argc, char *argv[])
{
    // alloc console and set output to it

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_GLContext gl_context;
    int win_width, win_height;

    /* Setup graphical user interface */
    nk_context* ctx;
    nk_colorf bg;

    NK_UNUSED(argc);
    NK_UNUSED(argv);

    // create Editor scenestate 
    SceneState editorScene;

    /* Setup SDL */
    SDL_GL_SetAttribute (SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("Error: %s\n", SDL_GetError());
        return -1;
    }
    // Create window with graphics context
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_BORDERLESS | SDL_WINDOW_ALLOW_HIGHDPI);
    window = SDL_CreateWindow("DigiPlane",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                1280, 720, window_flags);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "SDL2 Renderer couldn't be created. Error: "
                  << SDL_GetError()
                  << std::endl;
        exit(1);
    }
    gl_context = SDL_GL_CreateContext(window);
    SDL_GetWindowSize(window, &win_width, &win_height);

    if (!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress)) {
          std::cerr << "Failed to initialize the OpenGL context." << std::endl;
          exit(1);
    }

    glViewport(0, 0, 1280, 720);

    ctx = nk_sdl_init(window);
    struct nk_font_atlas *atlas;
        struct nk_font_config config = nk_font_config(0);
    {
    
        nk_sdl_font_stash_begin(&atlas);
        // fonts data and size are at Engine::fonts::UbuntuMonoR_compressed_data_base85
        // load ubuntu mono font
        nk_font *ubuntuR = nk_font_atlas_add_compressed_base85(atlas, Engine::fonts::UbuntuR_compressed_data_base85, 16, &config);
        nk_font *ubuntuMonoB = nk_font_atlas_add_compressed_base85(atlas, Engine::fonts::UbuntuMonoR_compressed_data_base85, 14, &config);
        nk_font *sourcecodeproR = nk_font_atlas_add_compressed_base85(atlas, Engine::fonts::SourceCodeProRegular_compressed_data_base85, 14, &config);
        nk_sdl_font_stash_end();
        /*nk_style_load_all_cursors(ctx, atlas->cursors);*/
        nk_style_set_font(ctx, &ubuntuR->handle);
        }

    bg.r = 0.10f, bg.g = 0.18f, bg.b = 0.24f, bg.a = 1.0f;
    
    // Main loop
    while (1)
    {
        SDL_Event event;
        nk_input_begin(ctx);
        while (SDL_PollEvent(&event))
        {
            /* Detect close event for shutdown */
            if (event.type == SDL_QUIT || event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(window))
            {
                // Cleanup
                nk_sdl_shutdown();
                SDL_GL_DeleteContext(gl_context);
                SDL_DestroyWindow(window);
                SDL_Quit();
                return 0;
            }
            nk_sdl_handle_event(&event);
        }
        nk_input_end(ctx);

        /* Render order */

        SDL_GetRendererOutputSize(renderer, &win_width, &win_height);
        Engine::doInterface(&editorScene,ctx, &win_width, &win_height);

        /* Draw */

        glViewport(0, 0, win_width, win_height);
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(bg.r, bg.g, bg.b, bg.a);
        nk_sdl_render(NK_ANTI_ALIASING_ON, MAX_VERTEX_MEMORY, MAX_ELEMENT_MEMORY);

        SDL_GL_SwapWindow(window);
    }

    return 0; // Unecessary but to satisfy compiler (not all control paths return a value)
    // END //
}
