// Core.cpp
#include <Digiplane/core.hpp>
#include "./pch.hpp"

bool devmode = false;

// used to contain all core variables
namespace _DPCORE {
    // current digiplane version in major.minor format
    constexpr float version = DIGIPLANE_MAJOR + 0.1f * DIGIPLANE_MINOR;
    bool initialized;
    
    std::string_view systemLanguage;

    bgfx::PlatformData platformData;
}

void doArguments(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--devmode" || arg == "-d") {
            devmode = true;
            continue;
        }
    }
}

// Digiplane entry point 
int main(int argc, char** argv) {
    doArguments(argc, argv);
    /* Initialize the library */
    if(!glfwInit()) {
        std::cerr << "Failed to initialize GLFW code " << glfwGetError(nullptr) << "\n";
        return -1;
    }
    bgfx::init();

    _DPCORE::systemLanguage = std::locale("").name();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    auto userApp = Digiplane::createApp();
    Digiplane::window& windowInfo = userApp->getWindowInfo();
    Digiplane::time& Time = userApp->getTimeInfo();
    GLFWwindow*& window = windowInfo.window;

    /* Create a windowed mode window */

    window = glfwCreateWindow(800, 600, windowInfo.title.data(), NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    userApp->init();

    /* Define BGFX platformData object */
    _DPCORE::platformData.nwh = glfwGetWindowCrossPlatform(window); // function defined in ./pch.hpp

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    float lastFrame = 0.0f;

    /* Application Loop */
    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = (float)glfwGetTime();
        Time.deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // update application context
        userApp->update();

        /* Render here */
        
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    bgfx::shutdown();
    glfwTerminate();
    return 0;
}

namespace Digiplane {
    // Application Context definitions

    void ApplicationContext::setWindowTitle(std::string_view title) {
        Window.title = title;
        glfwSetWindowTitle(Window.window, title.data());
    }

    void ApplicationContext::setResolution(int width, int height) {
        Window.width = width;
        Window.height = height;
        glfwSetWindowSize(Window.window, width, height);
    }

    time& ApplicationContext::getTimeInfo() {return Time;}
    window& ApplicationContext::getWindowInfo() { return Window;}
}
