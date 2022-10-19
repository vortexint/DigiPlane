/**
 * @file Editor.hpp
 * @brief file responsible for editor functionality declarations
 */

#ifndef EDITOR_HPP
#define EDITOR_HPP

#include "tweeny-3.2.0.h"
#include <iostream>
#include <string>

// Data containers //

// The Component class, which is the base class for all components, e.g. Transform, Camera, SpriteRenderer, etc.
// This class is used to store the data for each component, and to be able to iterate over all components in a scene
class Component
{
    // private:
    std::string name;
    std::string type;

public:
    Component(std::string name, std::string type);
    std::string getName();
    std::string getType();
};

class SceneState
{
    // private:
    std::vector<Component> components;
public:
    SceneState(); // constructor
    void addComponent(Component component);
    std::vector<Component> getComponents();
};

#endif

// Editor Specific //

/**
 * @brief The Editor class is the base class for the editor, it is responsible for handling editor data & functionality.
 * The Editor Class most noticeably contains variables for selected objects, and the sceneState object.
 */
class Editor
{
    // private:
    
};