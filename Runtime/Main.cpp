#include <iostream>

#include "./Runtime.hpp"

#include <Windows.h>

int main(int argc, char** argv) {
    Digiplane::ApplicationContext context;

    // for each argument
    for (int i = 1; i < argc; i++) {
        if (context.processCmdArg(argv[i])) {
            std::cerr << "Bad command\n";
            return 1; // invalid digiplane command
        }
    }

    flecs::world* scene = context.getWorld();
    

    return 0;
}