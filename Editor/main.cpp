#include <iostream>
#include "Editor.hpp"

#define EDITOR_NAME "DigiPlane"

/* Global variables */

std::unique_ptr<Application> editorApp;


int main(int argc, char *argv[])
{
    editorApp = std::make_unique<Application>();
    editorApp->Initialize(EDITOR_NAME, { 1280, 720 }, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

    // Editor funcitonality found at Editor.cpp

    return 0;   
}