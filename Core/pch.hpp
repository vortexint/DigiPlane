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

#define GLFW_INCLUDE_NONE // We are using GLFW as a window manager.
#define NOMINMAX // Windows headers define min/max as macros, which messes up std functions

// platform specific setup & defines to avoid redundant #ifdef(s)
#ifdef _WIN32 
    #include <Windows.h>
    #include <crtdbg.h> // memory leak detection
    #define GLFW_EXPOSE_NATIVE_WIN32 1
#elif __linux__
    #define GLFW_EXPOSE_NATIVE_X11 1
#elif __APPLE__
    #define GLFW_EXPOSE_NATIVE_COCOA 1
#else
    #error Platform not supported.
#endif

#ifndef ENGINE_DLL
    #define ENGINE_DLL 0
#endif

#pragma warning(push, 0)

// graphics
#include "Graphics/GraphicsEngineD3D12/interface/EngineFactoryD3D12.h"
#include "Graphics/GraphicsEngine/interface/RenderDevice.h"
#include "Graphics/GraphicsEngine/interface/DeviceContext.h"
#include "Graphics/GraphicsEngine/interface/SwapChain.h"

#include "Graphics/GraphicsTools/interface/CommonlyUsedStates.h"
#include "Graphics/GraphicsTools/interface/MapHelper.hpp"

#include "Common/interface/BasicMath.hpp"
#include "Common/interface/RefCntAutoPtr.hpp"

#include "GLFW/glfw3.h"
#include "GLFW/glfw3native.h"

// scene graph
#include "flecs.h"

// scripting
#include  "lua.hpp"

// network
//#include "asio.hpp"

// localization
//#include "locale.hpp"

#pragma warning(pop)