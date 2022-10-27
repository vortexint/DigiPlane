#include "Editor.hpp"

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
    SDL_GL_SetAttribute (SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    // Maximized window
    window = SDL_CreateWindow(windowTitle,
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            0, 0, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN  | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "SDL2 Renderer couldn't be created. Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    // create OpenGL context
    gl_context = SDL_GL_CreateContext(window);
    // Load GL extensions using glad
    if (!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress)) {
        std::cerr << "Failed to initialize the OpenGL context." << std::endl;
    exit(1);
    }
    // create scenemanager with default scene
    std::unique_ptr<DigiPlane::Engine::SceneManager> sceneManager = std::make_unique<DigiPlane::Engine::SceneManager>("EditorScene");
    // set window title to editor name +  GLVersion.major + GLVersion.minor
    SDL_SetWindowTitle(window, (std::string(windowTitle) + " | GL " + std::to_string(GLVersion.major) + "." + std::to_string(GLVersion.minor)).c_str());
    
    // Create an event handler
    SDL_Event event;
    while (is_running) {
        // Poll for events
        SDL_PollEvent(&event);
        switch(event.type) {
        case SDL_QUIT:
            is_running = false;
            break;
        case SDL_KEYDOWN:
            break;
        }
        glClearColor(0, 0, 0, 1);
        // You'd want to use modern OpenGL here
        
        SDL_GL_SwapWindow(window);
    }
}