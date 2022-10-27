#include "./Scene.hpp"
#include "./Utils.hpp"

namespace DigiPlane::Engine
{

    SceneManager::SceneManager( std::string sceneName ) {
        CreateScene(sceneName);
        SetActiveScene(sceneName);
    }

    SceneManager::SceneManager() {
        CreateScene("DefaultScene");
        SetActiveScene("DefaultScene");
    }

    SceneManager::~SceneManager() {
        // emptying the scenes is probably not necessary, but it should be good practice
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
            std::cerr << "ERROR: Can't delete the only existing scene: \"" << sceneReference.begin()->first << "\"\n";
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
        // check if scene exists
        if (sceneReference.find(sceneName) == sceneReference.end()) {
            // find most similar match to sceneName in the map with levenshtein_distance
            std::string closestMatch = "";
            size_t closestMatchDistance = 0;
            for (auto& scene : sceneReference) {
                size_t distance = DigiPlane::Utils::levenshteinDistance(sceneName.c_str(), sceneName.size(), scene.first.c_str(), scene.first.size());
                if (closestMatchDistance == 0 || distance < closestMatchDistance) {
                    closestMatch = scene.first;
                    closestMatchDistance = distance;
                }
            }
            std::cerr << "ERROR: Scene \"" << sceneName << "\" doesn't exist, did you mean \"" << closestMatch << "\"?\n";

            return;
        }
        // if scene is the last scene, don't delete it
        if (scenes.size() == 1) {
            std::cerr << "ERROR: Can't delete the only existing scene: \"" << sceneName << "\"\ninfo: When the SceneManager leaves scope, no manual scene deletion is required\n";
            return;
        }
        // if scene is active scene, make another scene active

    }

} // namespace DigiPlane::Engine