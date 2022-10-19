#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream>
#include <string>

#include "glad/glad.h"
#include "SDL.h"
#include "../Editor.hpp"

namespace Engine {

// Interface Declarations //

/**
 * @brief Draw interface for the editor, this happens after glClear() and before SwapWindow function
 * @param sceneState gets pointer to the sceneState object that is made shared in main.cpp
 */
void doInterface(SceneState* sceneState, nk_context *ctx, int* window_width, int* window_height);

void setupTheme();

} // namespace Engine
#endif // INTERFACE_HPP