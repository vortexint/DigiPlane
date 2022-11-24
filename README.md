# Digiplane

## Introduction

Digiplane is a 2D Game engine that makes it easy to create high-quality 2D games. It provides simple high-level and low-level access to core features such as using HLSL/GLSL shaders, creating and managing scenes, and uses a entity-component system. Digiplane also supports Linux and Windows.

If you would like to try out the framework, check out the [tutorial](https://digiplane.readthedocs.io/en/latest/tutorial.html).

## Features

- HLSL/GLSL shader support - Create your own shaders and easily use them in Digiplane.
- Entity-component system ([flecs](https://github.com/SanderMertens/flecs)) - Create your game objects in a component-based way.
- Scene management - Make your game logic modular by creating scenes that contain your entities and components.
- Linux and Windows support - The framework is cross-platform, so you can easily build your games to both platforms.

## Getting Started

1. Download and install the [engine](https://github.com/vortexdevsoftware/DigiPlane/releases).
2. Create a new project using the [tutorial](https://digiplane.readthedocs.io/en/latest/tutorial.html).
3. Add your assets to the project using [resources](https://digiplane.readthedocs.io/en/latest/resources.html).
4. Write your code - See the [documentation](https://digiplane.readthedocs.io/en/latest/) for more information.
5. Build and run your game

## Building (Nightly build)
### Dependencies: Visual Studio (MSVC) or MinGW-w64
You may want to test experimental features before release, so
Clone or download the main branch to any directory, if you are using Git, make sure to run:
```git submodule update --init --recursive```.
##### It is recommended to use CMake Gui but you can manually generate the project files for the specified compiler via command-line.
After generating the project files you should be able to build the Engine with the specified build system for most platforms.

If you have any issues for your platform, please open an issue.

### Tested Platforms:
- Windows
- Linux Mint