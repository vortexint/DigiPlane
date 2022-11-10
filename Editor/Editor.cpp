#include "Editor.hpp"

using namespace DigiPlane::Engine;

void Application::Awake() {
    /* Create the editor scene */
    Scene editorScene("Editor");
    SceneMgr->AddScene(editorScene);
    SceneMgr->SetActiveScene(editorScene);
    // set window title to current title + GL version
    SDL_SetWindowTitle(getSDLWindow(), (std::string(SDL_GetWindowTitle(getSDLWindow())) + " | GL " +
                                        std::to_string(GLVersion.major) + "." + std::to_string(GLVersion.minor)).c_str());

    /* Create the editor camera */
    //auto editorCamera = SceneMgr->CreateEntity("EditorCamera");


}

void Application::Update() {
}

void Application::LateUpdate() {
}

void Application::FixedUpdate() {
}