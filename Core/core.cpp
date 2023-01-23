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
        // initialize world with ecs_init();
        world = ecs_init();

        /* Declare core components */
        ECS_COMPONENT(world, Transform);
        ECS_COMPONENT(world, Velocity);
    }


    bool ProcessCommandLine(const char* CmdLine) {
        return true;
    }

    /* Core interfacing definitions */

    const float& getVersion() {return _DPCORE::version;}

}
