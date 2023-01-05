#define NK_IMPLEMENTATION
#define NK_DIGIPLANE_IMPLEMENTATION

#include "./Editor.hpp"

#include "nuklear.h"
#include <Digiplane/nuklear_impl.hpp>

void EditorApp::init() {
    setWindowTitle("Digiplane " + std::to_string(DIGIPLANE_MAJOR) + "." + std::to_string(DIGIPLANE_MINOR) + " Forge");
}

void EditorApp::update() {

}