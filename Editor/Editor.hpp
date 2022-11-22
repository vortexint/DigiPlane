#ifndef EDITOR_HPP
#define EDITOR_HPP

#include <iostream>
#include <string>

#include "glad/glad.h"
#include "SDL.h"
#include "SDL_opengl.h"


// Application entry point class
// This class is responsible for initializing the editor
class Application {
    /* Maximized size and position that is defined automatically by the OS
    User may have a custom positioned taskbar, so this is the simplest
    workaround for now */
    int maxW, maxH;
    int maxX, maxY;

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_GLContext gl_context;
    struct nk_context *ctx;

    bool is_running;
public:
    float deltaTime;
    Application(void);
    ~Application(void);

    // remove copy constructor and assignment operator to avoid multiple instances of the application
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

    void init(void);
    void Update(void);
    void LateUpdate(void);
    void FixedUpdate(void);
};

#endif // EDITOR_HPP

