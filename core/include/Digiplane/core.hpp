#ifndef CORE_HPP
#define CORE_HPP

#include <string>

#include "../types.hpp"
#include "../geometry/mesh.hpp"

// DPAPI is used to declare public API functions for export as shared library.
#if defined(_WIN32) && defined(_DIGIPLANE_BUILD_DLL)
    // Building as a Win32 DLL
    #define DPAPI __declspec(dllexport)
#elif defined(_WIN32) && defined(DIGIPLANE_DLL)
    // Calling Win32 DLL
    #define DPAPI __declspec(dllimport)
#elif defined(__GNUC__) && defined(_DIGIPLANE_BUILD_DLL)
    //Unix shared library
    #define DPAPI __attribute__((visibility("default")))
#else
    #define DPAPI
#endif

#define DIGIPLANE_MAJOR 0
#define DIGIPLANE_MINOR 1

namespace Digiplane {
    struct window {
        GLFWwindow* window;
        std::string_view title = "New Digiplane Window";
        int width  = 800;
        int height = 600;
    };
    struct time {
        float deltaTime = 0.0f;
        float lastFrame = 0.0f;
    };

    // The ApplicationContext is a container for managing and storing application-level objects and resources.
    class DPAPI ApplicationContext {
        static bool quit;

        // create window and tiem
        window Window;
        time Time;
        
    public:

        //ApplicationContext()  {}
        virtual ~ApplicationContext() = default;

        /* Native application functions */
        virtual void init() = 0;
        virtual void update() = 0;

        void setWindowTitle(std::string_view title);
        void setResolution(int width, int height);

        // get reference to time struct
        time& getTimeInfo();
        window& getWindowInfo();


    };

    extern DPAPI std::unique_ptr<ApplicationContext> createApp();

} // DigiPlane

#endif // CORE_HPP