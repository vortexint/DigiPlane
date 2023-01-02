#pragma once

#include <Digiplane/core.hpp>

class EditorApp : public Digiplane::ApplicationContext {
    public:
        void init() override;
        void update() override;
};

std::unique_ptr<Digiplane::ApplicationContext> Digiplane::createApp() {
    return std::make_unique<EditorApp>();
}