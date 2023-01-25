#define DIGIPLANE_NK_PLUGIN

#include "./Editor.hpp"

nk_context* ctx;

int main(int argc, char** argv) {
    Digiplane::ApplicationContext context("Digiplane Editor", 1280, 720, NULL);
    // for each argument
    for (int i = 1; i < argc; i++) {
        if (context.processCmdArg(argv[i]) == 1) {
            std::cout << "Bad command\n";
            return 1; // invalid digiplane command
        }
    }

    flecs::world* scene = context.getWorld();

    flecs::entity cube = scene->entity("Cube").set<Digiplane::Transform>({
        // vec3 position
        {0,0,0},
        // Quaternion rotation
        {0,0,0,1},
        // vec3 scale
        {1,1,1}
    });

    context.init();

    while (!context.shouldClose()) {
        context.update();
    }

    return 0;
}