#include "./Editor.hpp"

using namespace DigiPlane;

Application::Application(void)
{
    std::cout << "Application constructor called\n";
}

// Destructor
Application::~Application(void)
{
    is_running = false;
}
