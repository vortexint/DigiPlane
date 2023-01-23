#define DIGIPLANE_NK_PLUGIN

#include "./Editor.hpp"

nk_context* ctx;

int main(int argc, char** argv) {
    Digiplane::ApplicationContext context;
    // for each argument
    for (int i = 1; i < argc; i++) {
        if (context.processCmdArg(argv[i])) {
            return 1; // invalid digiplane command
        }
    }

    context.run();

    return 0;
}