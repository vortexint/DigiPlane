#include <Digiplane/core.hpp>

using namespace Digiplane;

class RuntimeApp : public ApplicationContext {
    public:
        void init() override;
        void update(float deltaTime) override;
};

void RuntimeApp::init() {
    std::cout << "Hello from runtime";
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