#include "./Editor.hpp"

void EditorApp::init() {
    // set window title to "Digiplane <version with 1 decimal only>"
    setWindowTitle("Digiplane " + std::to_string(DIGIPLANE_MAJOR) + "." +
                                  std::to_string(DIGIPLANE_MINOR) + " Editor");
}

void EditorApp::update() {

}