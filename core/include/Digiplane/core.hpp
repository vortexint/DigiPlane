#ifndef DP_CORE_HPP
#define DP_CORE_HPP

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

namespace DigiPlane {
    DPAPI int Init_DigiPlane(int width, int height, WindowMode mode);
} // DigiPlane