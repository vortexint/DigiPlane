#include "./Runtime.hpp"

using namespace Digiplane;

void RuntimeApp::init() {
    std::cout << "Hello from runtime";
    setWindowTitle("Runtime");
}

void RuntimeApp::update(float deltaTime) {
    static int fpsCount = 0;
    fpsCount++;

    static double frameDelta = 0.0;
    frameDelta += deltaTime;

    if (frameDelta > 1.0) {
        std::cout << "FPS: " << fpsCount << std::endl;
        fpsCount = 0;
        frameDelta = 0.0;
    }
}