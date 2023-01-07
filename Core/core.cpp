// Core.cpp
#include "./pch.hpp"
#include <Digiplane/core.hpp>

bool devmode = false;

// used to contain all core variables
namespace _DPCORE {
    // current digiplane version in major.minor format
    constexpr float version = DIGIPLANE_MAJOR + 0.1f * DIGIPLANE_MINOR;
    bool initialized;
    
    std::string_view systemLanguage;

    lua_State* luaState;
}

void doArguments(int argc, char** argv);

// Digiplane entry point 
int main(int argc, char** argv) {
    doArguments(argc, argv);

    /* Initialize the library */

    // TODO: proper logging system
    if(!glfwInit()) {
        std::cerr << "Failed to initialize GLFW code " << glfwGetError(nullptr) << "\n";
        return -1;
    }

    _DPCORE::systemLanguage = std::locale("").name();
    _DPCORE::luaState = luaL_newstate();
    luaL_openlibs(_DPCORE::luaState);
    
    auto userApp = Digiplane::createApp();
    Digiplane::windowInfo& windowInfo = userApp->getWindowInfo();
    Digiplane::timeInfo& Time = userApp->getTimeInfo();
    GLFWwindow*& window = windowInfo.window;

    /* Create a window */
    
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    
    window = glfwCreateWindow(windowInfo.width, windowInfo.height, windowInfo.title.data(), nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    
    /* Handle plugins */
    #if defined(DIGIPLANE_NK_PLUGIN)

    #endif
    #if defined(DIGIPLANE_IMGUI_PLUGIN)

    #endif

    userApp->init();

    /* Application Loop */
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        float currentFrame = (float)glfwGetTime();
        Time.deltaTime = currentFrame - Time.lastFrame;
        Time.lastFrame = currentFrame;

        /* update application context */
        userApp->update();

        /* Render here */

        Time.frameCount++;
    }

    glfwTerminate();
    return 0;
}

namespace Digiplane {
    /* Application Context definitions */ 

    void ApplicationContext::setWindowTitle(std::string_view title) {
        Window.title = title;
        glfwSetWindowTitle(Window.window, title.data());
    }

    void ApplicationContext::setResolution(uint16_t width, uint16_t height) {
        Window.width = width;
        Window.height = height;
        glfwSetWindowSize(Window.window, width, height);
    }

    timeInfo& ApplicationContext::getTimeInfo() {return Time;}
    windowInfo& ApplicationContext::getWindowInfo() {return Window;}

    /* Core interfacing definitions */

    const float& getVersion() {
        return _DPCORE::version;
    }
    
    void* getNativeWindowHandle() {
        return nullptr; // TODO: implement
    }

}

void doArguments(int argc, char** argv)  {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--devmode" || arg == "-d") {
            devmode = true;
            continue;
        }
    }
}