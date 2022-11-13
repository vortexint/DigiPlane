#ifndef SCENE_HPP
#define SCENE_HPP

#include <iostream>
#include <vector>
#include <unordered_map>
#include "flecs.h"

#include "Components.hpp"

namespace DigiPlane::Engine
{
    // The Scene class stores the scene data of the game
    class Scene
    {
        // The scene's name
        std::string name;
        flecs::world& ecs; // has to be a pointer as flecs::world has no default constructor
        
        friend class SceneManager;
    public:
        Scene(std::string_view sceneName) : name(sceneName) {
            ecs = flecs::world();
            //e.add<Components::Position>();
            std::cerr << "Scene \"" << name << "\" created\n";
        }
        // The scene's destructor
        ~Scene() {
            //delete ecs;
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

        /* Scene operations */

        // register a struct as a component to the active scene ( this is a wrapper for ecs.entity.add<component>() )
        // @param component: the component to be registered
        template<typename T> void RegisterComponent(T component) {
          //scenes[activeScene].ecs->entity().add<T>();
        }

        // create an entity in the active scene
        // @param name: the name of the entity
        // @return: the entity's id
        flecs::entity CreateEntity(std::string_view name) {
            return scenes[activeScene].ecs.entity(name.data());
        }

    };

} // namespace DigiPlane::Engine

#endif // SCENE_HPP