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

}