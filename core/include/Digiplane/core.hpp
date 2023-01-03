#pragma once

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

// The Digiplane namespace is the root namespace for all Digiplane classes and functions.
// definitions at core.cpp
namespace Digiplane {
    /* Application */

    struct windowInfo {
        GLFWwindow* window;
        std::string_view title = "New Digiplane Window";
        uint16_t width  = 800, height = 600;
    };
    struct timeInfo {
        float deltaTime = 0.0f;
        float lastFrame = 0.0f;
        int frameCount = 0;
    };

    enum class Platform : std::uint8_t {
        Windows,
        Linux
    };

    // The ApplicationContext is a container for managing and storing application-level objects and resources.

    class DPAPI ApplicationContext {
        static bool quit;

        windowInfo Window;
        timeInfo Time;
        
    public:

        //ApplicationContext()  {}
        virtual ~ApplicationContext() = default;

        /* Native application functions */
        virtual void init() = 0;
        virtual void update() = 0;

        void setWindowTitle(std::string_view title);
        void setResolution(uint16_t width, uint16_t height);

        // get reference to time struct
        timeInfo& getTimeInfo();
        windowInfo& getWindowInfo();


    };

    extern DPAPI std::unique_ptr<ApplicationContext> createApp();

    /* Core interfacing */

    /**
     * @brief Returns the version of the Digiplane library as a float that can be used for version checking.
     * @return float 
     */
    const float& getVersion();


} // DigiPlane
