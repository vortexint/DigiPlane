// Core.cpp
#include <Digiplane/core.hpp>
#include "./pch.hpp"
#include "./internal.hpp"

namespace Digiplane {

    DPAPI int Init(initInfo* config) {
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

        /* Initialize the library */
        if(!glfwInit()) {
            std::cerr << "Failed to initialize GLFW code " << glfwGetError(nullptr) << "\n";
            return -1;
        }
        bgfx::init();

        /* Create a windowed mode window */
        _DPCORE::window = glfwCreateWindow(config->width, config->height, config->title.c_str(), NULL, NULL);
        if (!_DPCORE::window) {
            glfwTerminate();
            return -1;
        }

        /*Define BGFX platformData object */
        _DPCORE::platformData.nwh = glfwGetWindowCrossPlatform(_DPCORE::window); // function defined in ./pch.hpp

        /* Make the window's context current */
        glfwMakeContextCurrent(_DPCORE::window);

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(_DPCORE::window))
        {
            /* Render here */

            /* Swap front and back buffers */
            glfwSwapBuffers(_DPCORE::window);

            /* Poll for and process events */
            glfwPollEvents();
        }

        glfwTerminate();
        return 0;
    }
} // DigiPlane