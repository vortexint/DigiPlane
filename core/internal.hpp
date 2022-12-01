#ifndef INTERNAL_HPP
#define INTERNAL_HPP

// pch.hpp comes from init.cpp, no need for redundant include, although some IDEs may complain, but not compilers.

// used to contain all mutable state variables
namespace _DPCORE {
    bool initialized;
    GLFWwindow* window;
    bgfx::PlatformData platformData;
    // context



}

#endif // INTERNAL_HPP