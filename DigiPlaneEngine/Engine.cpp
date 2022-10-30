#define NK_IMPLEMENTATION
#define NK_SDL_GL3_IMPLEMENTATION
#include "./Engine.hpp"
#include "nuklear_sdl_gl3.h"

#include <iostream>
#include <string>

namespace DigiPlane::Engine
{
    void ApplicationBase::Initialize( char* windowTitle)
    {
        /* Initialize SDL */
        SDL_SetHint(SDL_HINT_VIDEO_HIGHDPI_DISABLED, "0");
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
            exit(1);
        }
        SDL_GL_SetAttribute (SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

        /* Create a maximized window and its OpenGL context */
        window = SDL_CreateWindow(windowTitle,
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                0, 0, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN  | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        gl_context = SDL_GL_CreateContext(window);

        /* Load GL extensions using glad */
        if (!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress)) {
            std::cerr << "Failed to initialize the OpenGL context." << std::endl;
            exit(1);
        }
        
        SceneMgr = std::make_unique<SceneManager>();

        Awake(); // Call user initializer

        // check if any scenes have been added, if not, add a default scene
        if (SceneMgr->getSceneCount() == 0) {
            SceneMgr->CreateScene("DefaultScene");
            SceneMgr->SetActiveScene("DefaultScene");
            std::cerr << "WARNING: No scenes have been added in the Awake() function, therefore \"DefaultScene\" has been created." << std::endl;
        }

        // Create an event handler
        SDL_Event event;
        while (is_running) {
            glClearColor(0, 0, 0, 0);
            glClear(GL_COLOR_BUFFER_BIT);
            // IMPORTANT: `nk_sdl_render` modifies some global OpenGL state
            // with blending, scissor, face culling, depth test and viewport and
            // defaults everything back into a default state.
            // Make sure to either a.) save and restore or b.) reset your own state after
            // rendering the UI. 

            /* Swap front and back buffers */
            SDL_GL_SwapWindow(window);

             /* Poll for and process events */
            SDL_PollEvent(&event);
            switch(event.type) {
            case SDL_QUIT:
                is_running = false;
                break;
            case SDL_KEYDOWN:
                break;
            }
        }
    }
} // namespace Digiplane::Engine