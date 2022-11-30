#pragma once
// Precompiled header file.

// STD

#include <iostream>
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

#define GLFW_INCLUDE_NONE // We are using GLFW as a window manager of sorts.

#pragma warning(push, 0)

#include "GLFW/glfw3native.h"
#include "GLFW/glfw3.h"

#include "bgfx/bgfx.h"
#include "bgfx/platform.h"

#include "flecs.h"

#pragma warning(pop)