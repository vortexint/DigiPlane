#ifndef SCENE_HPP
#define SCENE_HPP

#include <iostream>
#include <vector>
#include <map>
#include "flecs.h"

namespace DigiPlane::Engine
{
    // The Scene struct stores the scene data of the game
    // it is a class instead of a struct because it has functions for 
    struct Scene
    {
        // The scene's name
        std::string name;
        // Where all entities of the scene are stored
        ecs_world_t* world;

        // Cameras are important and thus passed to a vector, this is so the
        // first camera in the vector is recgonized as the active camera
        std::vector<ecs_entity_t> cameras;
    };

    /* The SceneManager class is responsible for storing the scenes.
        it must always have at least one scene, and can have as many as the user wants.

        There is no load/unload function, the SceneManager doesn't care about how you
        tinker with your scenes, it just stores them, and gives you ways to modify them.

        Scenes are automatically cleaned up when the scenemanager goes out of scope.
        Additionally one may never get a reference or pointer to a scene.
    */ 
    class SceneManager
    {
    private:
        /* Editor's note:
        "scenes" was previously std::map since it's simpler to get a scene by name, but it's not very efficient.
        To address this, there is a vector and a map, with the map storing the index of the scene in the vector,
        so we can find the scene by name and index in O(1) time. Externally, the user should use the name rather
        than the index; the index is only utilized internally and is not exposed. 
        */
        std::vector<Scene> scenes;
        std::map<std::string, int> sceneReference;

        // current working scene (automatically updated if a scene behind it is deleted)
        int activeScene;

    public:
        // constructor, creates a named scene
        // @param sceneName: the name for the initial scene
        SceneManager(std::string sceneName);
        // constructor, creates a default scene and sets it as the active scene
        SceneManager();
        ~SceneManager(); 


        // Create a new scene, if a scene with the same name exists, it will be overwritten
        // @param sceneName: the name for the new scene
        void CreateScene(std::string sceneName);

        // Destroy the active scene.
        void DestroyScene();

        // Destroy a scene by name.
        // @param sceneName: the name of the scene to be removed
        void DestroyScene(std::string sceneName);

        // Set the active scene for operations ( e.g. creating entities )
        // @param sceneName: the name of the scene to be set as active
        void SetActiveScene(std::string sceneName) { activeScene = sceneReference[sceneName]; }

        std::vector<Scene> getScenes() { return scenes; }

        size_t getSceneCount() { return scenes.size(); }

    };

} // namespace DigiPlane::Engine

#endif // SCENE_HPP