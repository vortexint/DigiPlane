// Core.cpp
#include "./pch.hpp"
#include <Digiplane/core.hpp>

#include "Graphics/GraphicsEngineD3D11/interface/EngineFactoryD3D11.h"
#include "Graphics/GraphicsEngineD3D12/interface/EngineFactoryD3D12.h"

bool devmode = false;

// used to contain all core variables
namespace _DPCORE {
    // current digiplane version in major.minor format
    constexpr float version = DIGIPLANE_MAJOR + 0.1f * DIGIPLANE_MINOR;
    bool initialized;

    Diligent::RENDER_DEVICE_TYPE DevType;
    Diligent::IRenderDevice*  m_pDevice;
    Diligent::IDeviceContext* m_pImmediateContext;
    Diligent::SwapChainDesc   SCDesc;
    Diligent::ISwapChain*     m_pSwapChain;
    
    std::string_view systemLanguage;

    lua_State* luaState;
}

void doArguments(int argc, char** argv);

// Digiplane entry point 
int main(int argc, char** argv) {
    doArguments(argc, argv);

    /* Initialize the library */

    // TODO: proper logging system
    if(!glfwInit()) {
        std::cerr << "Failed to initialize GLFW code " << glfwGetError(nullptr) << "\n";
        return -1;
    }

    /* Initialize Lua */

    _DPCORE::luaState = luaL_newstate();
    luaL_openlibs(_DPCORE::luaState);
    
    auto userApp = Digiplane::createApp();
    Digiplane::windowInfo& windowInfo = userApp->getWindowInfo();
    Digiplane::timeInfo& Time = userApp->getTimeInfo();
    GLFWwindow*& m_window = windowInfo.window;

    /* Create a window */
    
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    
    m_window = glfwCreateWindow(windowInfo.width, windowInfo.height, windowInfo.title.data(), nullptr, nullptr);
    if (!m_window) {
        glfwTerminate();
        return -1;
    }

    glfwSetWindowUserPointer(m_window, userApp.get());

    /* Initialize Diligent Engine */

    #if PLATFORM_WIN32
        Diligent::Win32NativeWindow Window{glfwGetWin32Window(m_window)};
        _DPCORE::DevType = Diligent::RENDER_DEVICE_TYPE_D3D12;
    #endif
    #if PLATFORM_LINUX
        Diligent::LinuxNativeWindow Window;
        Window.WindowId = glfwGetX11Window(m_window);
        Window.pDisplay = glfwGetX11Display();
        _DPCORE::DevType = RENDER_DEVICE_TYPE_GL
        glfwMakeContextCurrent(m_window);
    #endif

    switch (_DPCORE::DevType) {
        case Diligent::RENDER_DEVICE_TYPE_D3D11:
        {
            auto* pFactoryD3D11 = Diligent::GetEngineFactoryD3D11();
            Diligent::EngineD3D11CreateInfo EngineCI;
            pFactoryD3D11->CreateDeviceAndContextsD3D11(EngineCI, &_DPCORE::m_pDevice, &_DPCORE::m_pImmediateContext);
            pFactoryD3D11->CreateSwapChainD3D11(_DPCORE::m_pDevice, _DPCORE::m_pImmediateContext, _DPCORE::SCDesc, Diligent::FullScreenModeDesc{} ,Window, &_DPCORE::m_pSwapChain);
        }
        break;
        case Diligent::RENDER_DEVICE_TYPE_D3D12:
        {
            auto* pFactoryD3D12 = Diligent::GetEngineFactoryD3D12();
            Diligent::EngineD3D12CreateInfo EngineCI;
            pFactoryD3D12->CreateDeviceAndContextsD3D12(EngineCI, &_DPCORE::m_pDevice, &_DPCORE::m_pImmediateContext);
            pFactoryD3D12->CreateSwapChainD3D12(_DPCORE::m_pDevice, _DPCORE::m_pImmediateContext, _DPCORE::SCDesc, Diligent::FullScreenModeDesc{} ,Window, &_DPCORE::m_pSwapChain);
        }
        break;
        default:
            std::cerr << "Invalid device type\n";
            break;
    }

    
    /* Handle plugins */
    #if defined(DIGIPLANE_NK_PLUGIN)

    #endif
    #if defined(DIGIPLANE_IMGUI_PLUGIN)

    #endif

    _DPCORE::systemLanguage = std::locale("").name();

    userApp->init();

    /* Application Loop */
    while (!glfwWindowShouldClose(m_window))
    {
        glfwPollEvents();
        float currentFrame = (float)glfwGetTime();
        Time.deltaTime = currentFrame - Time.lastFrame;
        Time.lastFrame = currentFrame;

        /* update application context */
        userApp->update();

        /* Render here */

        Time.frameCount++;
    }

    glfwTerminate();
    return 0;
}

namespace Digiplane {
    /* Application Context definitions */ 

    void ApplicationContext::setWindowTitle(std::string_view title) {
        Window.title = title;
        glfwSetWindowTitle(Window.window, title.data());
    }

    void ApplicationContext::setResolution(uint16_t width, uint16_t height) {
        Window.width = width;
        Window.height = height;
        glfwSetWindowSize(Window.window, width, height);
    }

    timeInfo& ApplicationContext::getTimeInfo() {return Time;}
    windowInfo& ApplicationContext::getWindowInfo() {return Window;}

    /* Core interfacing definitions */

    const float& getVersion() {
        return _DPCORE::version;
    }
    
    void* getNativeWindowHandle() {
        return nullptr; // TODO: implement
    }

}

void doArguments(int argc, char** argv)  {
#if PLATFORM_LINUX
#define _stricmp strcasecmp
#endif
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--devmode" || arg == "-d") {
            devmode = true;
            continue;
        }
        if (arg == "--dx11") {
            _DPCORE::DevType = Diligent::RENDER_DEVICE_TYPE_D3D11;
            continue;
        }
        if (arg == "--dx12") {
            _DPCORE::DevType = Diligent::RENDER_DEVICE_TYPE_D3D12;
            continue;
        }
    }
}