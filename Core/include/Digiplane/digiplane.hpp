#pragma once

#include <string>

#include "../types.hpp"
#include "../geometry/mesh.hpp"
#include "../graphics/shaders.hpp"

#define DIGIPLANE_MAJOR 0
#define DIGIPLANE_MINOR 1

/* Plugins */

#if defined(DIGIPLANE_IMGUI_PLUGIN)
#pragma warning(push, 0)
//#include "imgui.h"
#pragma warning(pop)
#ifndef IMGUI_API
    #error "Unable to include "imgui.h", please make sure it is in your include path."
#endif
#include "../plugins/imgui_impl.hpp"
#endif

// The Digiplane namespace contains classes and functions that are available to the users.
namespace Digiplane {

    // The ApplicationContext is a container for managing and storing application-level objects and resources.
    class ApplicationContext {
    private:
        std::string m_title;
        int m_width, m_height;

        GLFWwindow* m_window;

        nk_diligent_context* m_pNkDlgCtx = nullptr;
        nk_context*          m_pNkCtx    = nullptr;

        flecs::world m_world;

        Diligent::RefCntAutoPtr<Diligent::IRenderDevice>  m_pDevice;           // Render device used to create all other graphics object
        Diligent::RefCntAutoPtr<Diligent::IDeviceContext> m_pImmediateContext; // Immediate context is used to submit commands to the device
        Diligent::RefCntAutoPtr<Diligent::ISwapChain>     m_pSwapChain;        // Swap chain is used to present the rendered image to the screen
        Diligent::RefCntAutoPtr<Diligent::IPipelineState> m_pPSO;              // Pipeline State Object used to render the scene
        Diligent::RENDER_DEVICE_TYPE m_DeviceType = Diligent::RENDER_DEVICE_TYPE_UNDEFINED; // Device type: Vulkan or D3D12

        void Draw();

        static void GLFWResizeCallback(GLFWwindow* window, int width, int height);
        
    public:
        // initialize initParams explicity with Member initializer lists
        ApplicationContext(const char* title, int width, int height);
        ~ApplicationContext();

        Diligent::IEngineFactory* GetEngineFactory() {return m_pDevice->GetEngineFactory();}
        Diligent::IRenderDevice*  GetDevice()        {return m_pDevice;}
        Diligent::IDeviceContext* GetContext()       {return m_pImmediateContext;}
        Diligent::ISwapChain*     GetSwapChain()     {return m_pSwapChain;}

        // Returns a pointer to the world object.
        flecs::world* getWorld() {return &m_world;}

        int init();

        void update();

        bool shouldQuit() {return glfwWindowShouldClose(m_window);}

        // processCmdArg is used to parse command line arguments and set the desired application initialization behavior.
        // If the argument is not using the "-dp" prefix, it is ignored.
        bool processCmdArg(const char* argv);

    };

    /* Core interfacing */

    // Returns a reference the version of the Digiplane library as a float that can be used for version checking.
    const float getVersion();


} // DigiPlane
