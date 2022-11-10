#define NK_IMPLEMENTATION
#define NK_SDL_GL3_IMPLEMENTATION
#include "./Engine.hpp"
#include "nuklear_sdl_gl3.h"

#include <iostream>
#include <string>

namespace DigiPlane::Engine
{
    void ApplicationBase::Initialize( char* windowTitle, SDL_Point windowResolution , Uint32 windowflags)
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
                                windowResolution.x, windowResolution.y, windowflags);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        gl_context = SDL_GL_CreateContext(window);

        /* Load GL extensions using glad */
        if (!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress)) {
            std::cerr << "Failed to initialize the OpenGL context." << std::endl;
            exit(1);
        }
        
        SceneMgr = std::make_unique<SceneManager>();

        Awake(); // Call user initializer

        // check if any scenes have been added, if not, close the application
        if (SceneMgr->getSceneCount() == 0) {
            std::cerr << "STOP: No scenes have been added during the Awake() function, therefore the application will cease." << std::endl;
            exit(1);
        }

        Uint64 currentTime = SDL_GetPerformanceCounter();
        Uint64 lastTime = 0;
        deltaTime = 0.0;
        // Create an event handler
        SDL_Event event;
        while (is_running) {
            /* Timing */
            lastTime = currentTime;
            currentTime = SDL_GetPerformanceCounter();
            deltaTime = deltaTime = ((currentTime - lastTime)*1000 / (double)SDL_GetPerformanceFrequency() );

            // call fixedUpdate 50 times per second
            static double fixedUpdateTimer = 0.0;
            fixedUpdateTimer += deltaTime;
            if (fixedUpdateTimer >= 20.0) {
                fixedUpdateTimer = 0.0;
                FixedUpdate();
            }

            glClearColor(0, 0, 0, 0);
            glClear(GL_COLOR_BUFFER_BIT);

            /* Render Here */
            
            Update(); // Call user update function

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