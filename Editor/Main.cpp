#define DIGIPLANE_NK_PLUGIN

#include "./Editor.hpp"

nk_context* ctx;

void EditorApp::init() {
    setWindowTitle("Digiplane " + std::to_string(DIGIPLANE_MAJOR) + "." + std::to_string(DIGIPLANE_MINOR) + " Forge");
    nk_digiplane_init();
}

void EditorApp::update() {
    //if (nk_begin(ctx, "Test", nk_rect(50, 50, 230, 250),
    //        NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_SCALABLE|
    //        NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE)) {
//
    //    }
    //nk_end(ctx);
}