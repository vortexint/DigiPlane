// Core.cpp
#include "./pch.hpp"
#include <Digiplane/core.hpp>
#include <nvrhi/d3d12.h>

using namespace nvrhi;
using namespace nvrhi::d3d12;

namespace _DPCORE {
    // current digiplane version in major.minor format
    constexpr float version = DIGIPLANE_MAJOR + 0.1f * DIGIPLANE_MINOR;
    std::string_view systemLanguage;
    lua_State* luaState;

    class MyMessageCallback : public IMessageCallback
    {
    public:
    void message(MessageSeverity severity, const char* messageText) override
    {
        // ADD LOGGING HERE
        std::cerr << "ERROR, Severity " <<  static_cast<uint8_t>(severity) << ": " << messageText << std::endl;
    }
    };
    
};

namespace Digiplane {
    /* Application Context definitions */ 

    // applicationcontext constructor
    ApplicationContext::ApplicationContext()
    {
        
        _DPCORE::MyMessageCallback myMessageCallback;
        deviceDesc.errorCB = &myMessageCallback;
        deviceDesc.pDevice = d3d12Device;
        deviceDesc.pGraphicsCommandQueue = d3d12GraphicsCommandQueue;

        nvrhi::DeviceHandle nvrhiDevice = nvrhi::d3d12::createDevice(deviceDesc);
    }

    bool ApplicationContext::initializeGraphicsEngine()
    {
        
        return true;
    }

    bool ProcessCommandLine(const char* CmdLine)
    {
        return true;
    }

    /* Core interfacing definitions */

    const float& getVersion() {return _DPCORE::version;}

}
