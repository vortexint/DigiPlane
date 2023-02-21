# DigiPlane <img src="https://raw.githubusercontent.com/vortexdevsoftware/DigiPlane/master/Editor/resources/assets/Icon.ico" alt="icon" width="200" height="200" align="right" valign="middle">
![Build](https://github.com/vortexdevsoftware/DigiPlane/actions/workflows/windows.yml/badge.svg)
###### Formerly project SenNight
**DigiPlane is a comprehensive game engine that simplifies the development of 2D and 3D games. It incorporates features such as HLSL/GLSL shader support, scene management, and an entity-component system. DigiPlane is also compatible with both Linux and Windows platforms.**

If you would like to try out the framework, check out the [tutorial](https://digiplane.readthedocs.io/en/latest/tutorial.html).

## Features
- HLSL/GLSL shader support - Create your own shaders and easily use them in Digiplane.
- Entity-component system ([flecs](https://github.com/SanderMertens/flecs)) - Create your game objects in a component-based way.
- Scene management - Make your game logic modular by creating scenes that contain your entities and components.
- Linux and Windows support - The framework is cross-platform, so you can easily build your games to both platforms.
- Version agnostic implementation of popular immediate mode GUI libraries: [Nuklear](https://github.com/Immediate-Mode-UI/Nuklear) and [Dear ImGui](https://github.com/ocornut/imgui)

## Getting Started

1. Download and install the [engine](https://github.com/vortexdevsoftware/DigiPlane/releases).
2. Create a new project using the [tutorial](https://digiplane.readthedocs.io/en/latest/tutorial.html).
3. Add your assets to the project using [resources](https://digiplane.readthedocs.io/en/latest/resources.html).
4. Write your code - See the [documentation](https://digiplane.readthedocs.io/en/latest/) for more information.
5. Build and run your game

## Building (Nightly build)
### Dependencies:

1. CMake Build System
2. Visual Studio (MSVC) / MinGW-w64 / g++
3. Vulkan development SDK packages

You may want to test experimental features before release, so
clone or download the main branch to any directory, if you are using Git, make sure to run:

```git submodule update --init --recursive```

##### It is recommended to use CMake Gui but you can manually generate the project files for the specified compiler via command-line.
After generating the project files you should be able to build the Engine with the specified build system for most platforms.

If you have any issues for your platform, please open an issue.

### Tested Platforms:
- Windows
- Linux Mint
