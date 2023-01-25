// Core.cpp
#include "./pch.hpp"
#include <Digiplane/core.hpp>

namespace _DPCORE {
    // current digiplane version in major.minor format
    constexpr float version = DIGIPLANE_MAJOR + 0.1f * DIGIPLANE_MINOR;
    std::string_view systemLanguage;
    
};

namespace Digiplane {
    /* Application Context definitions */ 

    // ApplicationContext constructor
    ApplicationContext::ApplicationContext() {
        lua_State* L = luaL_newstate();

        // add camera entity
        flecs::entity camera = world.entity("Camera").set<Transform>({
            // vec3 position
            {7,-7,5},
            // Quaternion rotation
            {0.4840999f, -0.2005207f, 0.3259418f, 0.7868931f},
            // vec3 scale
            {1,1,1}
        }).add<Viewport>();;
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
