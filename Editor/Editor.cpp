#include "Editor.hpp"

// Application constructor

Application::Application(void)
{
    is_running = true;
}

// Destructor
Application::~Application(void)
{
    is_running = false;
}
