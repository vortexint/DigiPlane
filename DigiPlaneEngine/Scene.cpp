#include "./Scene.hpp"

namespace DigiPlane::Engine
{

    SceneManager::SceneManager( std::string sceneName ) {
        // create a new scene, can't start without a scene.
        CreateScene(sceneName);
        SetActiveScene(sceneName);
    }

    SceneManager::~SceneManager() {
        // empty the scenes is probably not necessary, but it should be good practice
        scenes.clear();
    }

    void SceneManager::CreateScene(std::string sceneName) {
        // create scene with name sceneName and emplace it into the vector
        scenes.emplace_back(sceneName);
        // add the scene to the map, with the index of the scene in the vector
        sceneReference[sceneName] = (int)scenes.size() - 1;
    }

    void SceneManager::DestroyScene()
    {
        // if scene is the last scene, don't delete it
        if (scenes.size() == 1) {
            // print warning to console
            std::cerr << "WARNING: Attempted to delete the last scene, this is not allowed." << std::endl;
            return;
        }
        // remove the scene from the map and vector
        sceneReference.erase(scenes[activeScene].name);
        scenes.erase(scenes.begin() + activeScene);
        // change active scene to the last scene
        activeScene = (int)scenes.size() - 1;

    }

    void SceneManager::DestroyScene(std::string sceneName)
    {
        // if scene is the last scene, don't delete it
        if (scenes.size() == 1) {
            std::cerr << "ERROR: Can't delete the only existing scene: \"" << sceneName << "\"\ninfo: When the SceneManager leaves scope, no manual scene deletion is required\n";
            return;
        }
        // if scene is active scene, make another scene active

    }

} // namespace DigiPlane::Engine