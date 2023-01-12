#define DIGIPLANE_NK_PLUGIN

#include "./Editor.hpp"

nk_context* ctx;

int main(int argc, char** argv) {
    Digiplane::ApplicationContext* app = new Digiplane::ApplicationContext();
    //app->run();
    delete app;
    return 0;
}