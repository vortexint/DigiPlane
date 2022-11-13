#ifndef EDITOR_HPP
#define EDITOR_HPP

#include <iostream>
#include <string>

// Application class is responsible for using the engine by overriding Awake(), Update(), LateUpdate()...
// this is the class that you will be using to create your own application
class Application {
    /* Maximized size and position that is defined automatically by the OS
    User may have a custom positioned taskbar, so this is the simplest
    workaround for now */
    int maxW, maxH;
    int maxX, maxY;

public:
    Application(void)  {}
    ~Application(void) {}

    // remove copy constructor and assignment operator to avoid multiple instances of the application
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

    void Awake(void);
    void Update(void);
    void LateUpdate(void);
    void FixedUpdate(void);
};

#endif // EDITOR_HPP

