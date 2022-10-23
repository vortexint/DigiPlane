#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <glad/glad.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include "entt.hpp"

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#pragma warning(push, 0)
#include "nuklear.h"
#pragma warning(pop)

namespace DigiPlane::Engine
{


} // namespace Digiplane::Engine

#else
#error "Engine.hpp duplicate instance!"
#endif // ENGINE_HPP