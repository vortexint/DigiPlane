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

    // applicationcontext constructor
    ApplicationContext::ApplicationContext() {
        
    }

    bool ApplicationContext::initializeGraphicsEngine() {
        
        return true;
    }

    bool ProcessCommandLine(const char* CmdLine) {
        return true;
    }

    /* Core interfacing definitions */

    const float& getVersion() {return _DPCORE::version;}

}
