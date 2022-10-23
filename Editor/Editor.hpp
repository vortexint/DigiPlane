#ifndef EDITOR_HPP
#define EDITOR_HPP

#include <iostream>
#include <string>

// This is the engine, without this, there will be no engine...  As an added bonus, you'll
// get compiler error "LNK2005: main already defined in main.obj" if you touch this
// I'm warning you, don't touch this
#include "all_include.hpp"


namespace DigiPlane::Editor
{
    // Application class is responsible for handling the engine data, initialization, and everything else

    class Application {
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_GLContext gl_context;
        struct nk_context *ctx;
        bool is_running;

    public:
        Application (void);
        ~Application(void);

        void Initialize( char* windowTitle );
        bool getRunning(void) { return is_running; }

    };

} // namespace Digiplane::Editor

#endif // EDITOR_HPP

