#pragma once
// Precompiled header file.

// STD

#include <iostream>
#include <filesystem>
#include <fstream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

// We are using GLFW as a window manager of sorts.
#define GLFW_INCLUDE_NONE

// platform specific setup & defines to avoid redundant #ifdef(s)
#ifdef _WIN32 
#define GLFW_EXPOSE_NATIVE_WIN32
#define glfwGetWindowCrossPlatform glfwGetWin32Window
#elif __linux__
#define GLFW_EXPOSE_NATIVE_X11
#define glfwGetWindowCrossPlatform glfwGetX11Window
#else
#error Platform not supported.
#endif

#pragma warning(push, 0)
// graphics
#include "GLFW/glfw3.h"
#include "GLFW/glfw3native.h"
#include "bgfx/bgfx.h"
#include "bgfx/platform.h"

// scene graph
#include "flecs.h"

// network
//#include "asio.hpp"

// localization
//#include "locale.hpp"

#pragma warning(pop)