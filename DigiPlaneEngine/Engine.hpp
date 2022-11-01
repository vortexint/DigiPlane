#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <glad/glad.h>
#include <SDL.h>
#include <SDL_opengl.h>

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#pragma warning(push, 0)
#include "nuklear.h"
#include "flecs.h"
#pragma warning(pop)

#include "./Scene.hpp"

namespace DigiPlane::Engine
{
    // Although not fundamentally essential, the application class is the base class for all applications that use the engine,
    // it is responsible for initializing the engine, handling the main loop, as well as handling the window and renderer.
    class ApplicationBase {
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_GLContext gl_context;
        struct nk_context *ctx;

        // Numeric Variables
        double deltaTime;
        bool is_running;
    public:
        // SceneMagr is the ApplicationBase's gateway for editing scenes, adding entities, components, etc.
        std::unique_ptr<SceneManager> SceneMgr;

        // Initializes a Digiplane application window with SDL
        // @param windowTitle: The title of the window
        // @param windowResolution: The initial resolution of the window
        // @param windowflags: The SDL flags for the window
        void Initialize( char* windowTitle, SDL_Point windowResolution , Uint32 windowflags);

        // Awake is Called before the update loop, this is where you should initialize your application
        // such as creating scenes, adding entities, components, etc. Must be overriden.
        virtual void Awake(void) {return;};
        // Called every frame
        virtual void Update(void) {return;};
        // This function is called everytime the physics engine updates
        virtual void FixedUpdate(void) {return;};
        // LateUpdate is called after all updates have been called
        virtual void LateUpdate(void) {return;};

        bool getRunning(void) { return is_running; };

        // DeltaTime is the time in milliseconds since the last frame
        // it is used to calculate the speed of movement, rotation, etc.
        // without it, the speed of movement would be different on different computers
        double getDeltaTime(void) { return deltaTime; };

        SDL_Window* getSDLWindow(void) { return window; };
    
    };

} // namespace Digiplane::Engine

#else
#error "Engine.hpp duplicate include!"
#endif // ENGINE_HPP