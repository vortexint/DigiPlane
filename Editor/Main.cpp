#define NK_IMPLEMENTATION

#include "./Editor.hpp"

#include <Digiplane/nuklear_impl.hpp>
#include "nuklear.h"

void EditorApp::init() {
    setWindowTitle("Digiplane " + std::to_string(DIGIPLANE_MAJOR) + "." + std::to_string(DIGIPLANE_MINOR) + " Forge");
}

void EditorApp::update() {

}