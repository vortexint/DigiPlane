// Core.cpp
#include <Digiplane/core.hpp>
#include "./pch.hpp"

bool devmode = false;

// used to contain all core variables
namespace _DPCORE {
    // current digiplane version in major.minor format
    constexpr float version = DIGIPLANE_MAJOR + 0.1f * DIGIPLANE_MINOR;
    std::string_view systemLanguage;

    bool initialized;
    GLFWwindow* window;
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

    Digiplane::ApplicationContext app;
    app.init();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    /* Create a windowed mode window */
    _DPCORE::window = glfwCreateWindow(800, 600, "Remove this later :0", NULL, NULL);
    if (!_DPCORE::window) {
        glfwTerminate();
        return -1;
    }

    /*Define BGFX platformData object */
    _DPCORE::platformData.nwh = glfwGetWindowCrossPlatform(_DPCORE::window); // function defined in ./pch.hpp

    /* Make the window's context current */
    glfwMakeContextCurrent(_DPCORE::window);

    /* Application Loop */
    while (!glfwWindowShouldClose(_DPCORE::window))
    {
        /* Render here */
        

        /* Swap front and back buffers */
        glfwSwapBuffers(_DPCORE::window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    bgfx::shutdown();
    glfwTerminate();
    return 0;
}