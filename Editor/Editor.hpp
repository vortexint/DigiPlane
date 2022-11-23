#ifndef EDITOR_HPP
#define EDITOR_HPP

#include <iostream>
#include <string>
#include <bgfx/bgfx.h>


// Application entry point class
// This class is responsible for initializing the editor
class Application {

    bool is_running;
public:
    Application(void);
    ~Application(void);

    // remove copy constructor and assignment operator to avoid multiple instances of the application
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

    void init(void){
        std::cout << "Initialized\n";
    }
    //void Update(void);
    //void LateUpdate(void);
    //void FixedUpdate(void);
};

#endif // EDITOR_HPP

