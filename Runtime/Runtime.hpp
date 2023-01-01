#pragma once

#include <Digiplane/core.hpp>

class RuntimeApp : public Digiplane::ApplicationContext {
    public:
        void init() override;
        void update(float deltaTime) override;
        static std::unique_ptr<Digiplane::ApplicationContext> createApp();
};

std::unique_ptr<Digiplane::ApplicationContext> Digiplane::createApp() {
    return std::make_unique<RuntimeApp>();
}