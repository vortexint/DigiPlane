#include <iostream>
#include "Editor.hpp"

#define EDITOR_NAME "DigiPlane"

/* Global variables */

std::unique_ptr<DigiPlane::Editor::Application> editorApp;


int main(int argc, char *argv[])
{
    editorApp = std::make_unique<DigiPlane::Editor::Application>();

    editorApp->Initialize(EDITOR_NAME);


    return 0;   
}
