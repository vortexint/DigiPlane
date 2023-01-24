// Core.cpp
#include "./pch.hpp"
#include <Digiplane/core.hpp>

namespace _DPCORE {
    // current digiplane version in major.minor format
    constexpr float version = DIGIPLANE_MAJOR + 0.1f * DIGIPLANE_MINOR;
    std::string_view systemLanguage;
    lua_State* luaState;

    
};

namespace Digiplane {
    /* Application Context definitions */ 

    // ApplicationContext constructor
    ApplicationContext::ApplicationContext() {
        lua_State* L = luaL_newstate();

        // register new entity named Viewport with transform component
        auto viewport = world.entity("Viewport");
        viewport.add<Transform>();
        viewport.set<Transform>({0, 0, 0, 0, 0, 0, 0, 0, 0});
    }

    bool ApplicationContext::processCmdArg(const char* argv) {
        std::string arg = argv;
        if (arg == "-dp_vulkan") {
            // set vulkan as rendering backend
        } else if (arg == "-dp_dx12") {
            // set dx12 as rendering backend
        }
        else if (arg.find("-dp") == 0 && arg != "-dp_vulkan" && arg != "-dp_dx12") {return 1;} // invalid digiplane command
        return 0; // ignored/valid command
    }

    /* Core interfacing definitions */

    const float& getVersion() {return _DPCORE::version;}

}
