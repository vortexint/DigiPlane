#define DIGIPLANE_NK_PLUGIN

#include "./Editor.hpp"

nk_context* ctx;

int main(int argc, char** argv) {
    // 
    Digiplane::ApplicationContext context(("Digiplane " + std::to_string(DIGIPLANE_MAJOR) + "." +
                                                          std::to_string(DIGIPLANE_MINOR) + " Editor").c_str(), 1280, 720);
    for (int i = 1; i < argc; i++) {
        if (context.processCmdArg(argv[i]) == 1) {
            std::cout << "Bad command\n";
            return 1; // invalid digiplane command
        }
    }
    
    flecs::world* sceneGraph = context.getWorld();

    flecs::entity cube = sceneGraph->entity("Cube").set<Digiplane::Transform>({
        // vec3 position
        {0,0,0},
        // Quaternion rotation
        {0,0,0,1},
        // vec3 scale
        {1,1,1}
    });

    context.init(); // initialize the application context

    while (!context.shouldQuit()) {
        context.update();
    }

    return 0;
}