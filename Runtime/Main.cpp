#include <iostream>

#include "./Runtime.hpp"

int main(int argc, char** argv) {

    // TODO: replace with loaded default parameters
    Digiplane::ApplicationContext context("Runtime", 1280, 720);

    // for each argument
    for (int i = 1; i < argc; i++) {
        if (context.processCmdArg(argv[i])) {
            std::cerr << "Bad command\n";
            return 1; // invalid digiplane command
        }
    }

    //flecs::world* sceneGraph = context.getWorld();
    
    context.init(); // initialize the application context

    while (!context.shouldQuit()) {
        context.update();
    }

    return 0;
}