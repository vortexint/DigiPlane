#ifndef CORE_HPP
#define CORE_HPP

#include <string>

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
    struct initInfo {
        std::string title = "New DigiPlane Window";
        int width  = 800;
        int height = 600;

    };

    DPAPI int Init(initInfo* config);
} // DigiPlane

#endif // CORE_HPP