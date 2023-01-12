// Core.cpp
#include "./pch.hpp"
#include <Digiplane/core.hpp>

#include "Graphics/GraphicsEngineD3D11/interface/EngineFactoryD3D11.h"
#include "Graphics/GraphicsEngineD3D12/interface/EngineFactoryD3D12.h"

// used to contain all information variables
namespace _DPCORE {
    // current digiplane version in major.minor format
    constexpr float version = DIGIPLANE_MAJOR + 0.1f * DIGIPLANE_MINOR;
    
    std::string_view systemLanguage;

    lua_State* luaState;
}



namespace Digiplane {
    /* Application Context definitions */ 

    /* Core interfacing definitions */

    const float& getVersion() {return _DPCORE::version;}

}
