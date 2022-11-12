#ifndef SCENE_HPP
#define SCENE_HPP

#include <iostream>
#include <vector>
#include <unordered_map>
#include "flecs.h"

#include "Components.h"

namespace DigiPlane::Engine
{
    // The Scene class stores the scene data of the game
    class Scene
    {
        // The scene's name
        std::string name;

        ecs_world_t *ecs;

        friend class SceneManager;
    public:
        Scene(std::string_view sceneName) : name(sceneName) {
            // initialize the ecs world
            ecs = ecs_init();
            std::cerr << "Scene \"" << name << "\" created\n";
        }
        // The scene's destructor
        ~Scene() {
            std::cerr << "Scene \"" << name << "\" destroyed\n";
        }

        // Get the scene's name
        std::string getName() const { return name; }
        // Set the scene's name
        void setName(std::string_view sceneName) { name = sceneName; }

    };

    /* The SceneManager class is responsible for storing the pointer to all scenes
        it must always have at least one scene, and can have as many as the user wants.

        There is no load/unload function, the SceneManager doesn't care about how you
        tinker with your scenes, it just points to them, and gives you ways to modify them.

        Scenes are automatically cleaned up when the scenemanager goes out of scope.
        Additionally one may never get a reference or pointer to a scene.
    */ 
    class SceneManager {
    private:
        std::vector<Scene> scenes;

        // current working scene (automatically updated if a scene behind it is deleted)
        size_t activeScene;

        // find similar scene names with levenshtein distance
        std::vector<std::string> FindSimilarSceneNames(std::string_view sceneName);

    public:
        // constructor, creates a named scene
        // @param sceneName: the name for the initial scene
        SceneManager(Scene scene);
        // constructor, creates a default scene and sets it as the active scene
        SceneManager();
        ~SceneManager(); 


        // Gets a shared_ptr to add a scene to the scene manager.
        // @param scene: the scene to add to the scene manager
        int AddScene(Scene scene);

        // Destroy the active scene.
        void DestroyScene();

        // Destroy a scene by name.
        // @param sceneName: the name of the scene to be removed
        void DestroyScene(std::string_view sceneName);

        // Set the active scene for operations ( e.g. creating entities )
        // @param sceneName: the name of the scene to be set as active
        void SetActiveScene(Scene scene);
        
        const std::vector<Scene> getScenes() { return scenes; }

        const size_t getSceneCount() { return scenes.size(); }

    };

} // namespace DigiPlane::Engine

#endif // SCENE_HPP