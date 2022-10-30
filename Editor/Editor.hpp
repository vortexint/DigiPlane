#ifndef EDITOR_HPP
#define EDITOR_HPP

#include <iostream>
#include <string>

// This is the engine, without this, there will be no engine...  As an added bonus, you'll
// get compiler error "LNK2005: main already defined in main.obj" if you touch this
// I'm warning you, don't touch this
#include "all_include.hpp"

// Application class is responsible for using the engine by overriding Awake(), Update(), LateUpdate()...
// this is the class that you will be using to create your own application
class Application final : public DigiPlane::Engine::ApplicationBase {
    /* Maximized size and position that is defined automatically by the OS
    User may have a custom positioned taskbar, so this is the simplest
    workaround for movement of custom
    */
    int maxW, maxH;
    int maxX, maxY;

public:
    Application(void)  {}
    ~Application(void) {}

    void Awake(void)       override;
    void Update(void)      override;
    void LateUpdate(void)  override;
    void FixedUpdate(void) override;
};

#endif // EDITOR_HPP

