#include "Editor.hpp"

namespace DigiPlane::Editor
{
    // Application class is responsible for handling the engine data, initialization, and everything else

    Application::Application(void)
    {
        std::cout << "Application constructor" << std::endl;
    }

    Application::~Application(void)
    {
        std::cout << "Application destructor" << std::endl;
    }

    void Application::Initialize( char* windowTitle)
    {
        // create maximized SDL window
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
            exit(1);
        }

        window = SDL_CreateWindow(windowTitle,
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                0, 0, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED);

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        if (window == nullptr) {
            std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
            exit(1);
        }

        // create OpenGL context
        gl_context = SDL_GL_CreateContext(window);
        if (gl_context == nullptr) {
            std::cerr << "SDL_GL_CreateContext Error: " << SDL_GetError() << std::endl;
            exit(1);
        }

        // Load GL extensions using glad
        if (!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress)) {
            std::cerr << "Failed to initialize the OpenGL context." << std::endl;
            exit(1);
        }


    }

} // namespace Digiplane::Editor