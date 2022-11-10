#include "./Scene.hpp"
#include "./Utils.hpp"

namespace DigiPlane::Engine
{

    SceneManager::SceneManager( std::string_view sceneName ) {
        CreateScene(sceneName);
        SetActiveScene(sceneName);
    }

    SceneManager::SceneManager() {
        scenes.reserve(1); // allocate space for one scene
    }
    SceneManager::~SceneManager() {
        // emptying the scenes is probably not necessary, but it should be good practice
        for (auto& scene : scenes) {
            ecs_fini(scene.world);
        }
        scenes.clear();
    }

    std::vector<std::string> SceneManager::FindSimilarSceneNames(std::string_view sceneName) {
        std::vector<std::string> similarSceneNames;
        for (auto& scene : scenes) {
            std::cout << "scene name: " << scene.name << std::endl;
            if (Utils::levenshteinDistance(sceneName.data(), sceneName.size(), scene.name.c_str(), scene.name.size()) < 3) { // the 3 means
                similarSceneNames.emplace_back(scene.name);
            }
        }
        return similarSceneNames;
    }

    void SceneManager::CreateScene(std::string_view sceneName) {
        // check if a scene with the same name already exists, if it does, overwrite it, otherwise emplace it and add the scene to the map
        for (auto& scene : scenes) {
            if (scene.name == sceneName) {
                scene = Scene(sceneName.data());
                std::cerr << "Scene named \'" << sceneName << "\' already exists, it has been overwritten." << std::endl;
                return;
            }
        }
        scenes.emplace_back(Scene(sceneName.data()));
    }

    void SceneManager::DestroyScene()
    {
        // if scene is the last scene, don't delete it
        if (scenes.size() == 1) {
            // print warning to console
            std::cerr << "ERROR: Can't delete the only existing scene: \"" << scenes[0].name << "\"\n";
            return;
        }
        // remove the scene from the vector
        scenes.erase(scenes.begin() + activeScene);
        // change active scene to the last scene
        activeScene = (int)scenes.size() - 1;

    }

    void SceneManager::DestroyScene(std::string_view sceneName)
    {
        for (size_t i = 0; i < scenes.size(); i++) {
            if (scenes[i].name == sceneName) {
                if (scenes.size() == 1) { // if scene is the last scene
                    std::cerr << "ERROR: Can't delete the only existing scene: \"" << scenes[0].name << "\"\n";
                    return;
                }
                if (i == activeScene)
                    activeScene = (int)scenes.size() - 1;
                scenes.erase(scenes.begin() + i);
                return;
            }
        }
        // if code reaches here, the scene doesn't exist.
        std::cerr << "ERROR: Scene named \"" << sceneName << "\" doesn't exist, did you mean \"" << FindSimilarSceneNames(sceneName)[0] << "\"?\n";
        return;
    }

    void SceneManager::SetActiveScene(std::string_view sceneName)
    {
        for (size_t i = 0; i < scenes.size(); i++) {
            if (scenes[i].name == sceneName) {
                activeScene = i;
                return;
            }
        }
        // if code reaches here, the scene doesn't exist.
        std::cerr << "ERROR: Scene named \"" << sceneName << "\" doesn't exist, did you mean \"" << FindSimilarSceneNames(sceneName)[0] << "\"?\n";
        return;
    }

} // namespace DigiPlane::Engine