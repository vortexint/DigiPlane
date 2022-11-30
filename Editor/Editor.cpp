#include "./Editor.hpp"

using namespace Digiplane;

Application::Application(void)
{
    std::cout << "Application constructor called\n";
}

// Destructor
Application::~Application(void)
{
    is_running = false;
}
