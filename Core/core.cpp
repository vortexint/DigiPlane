// Core.cpp
#include "./pch.hpp"
#include <Digiplane/core.hpp>

#include "Graphics/GraphicsEngineD3D11/interface/EngineFactoryD3D11.h"
#include "Graphics/GraphicsEngineD3D12/interface/EngineFactoryD3D12.h"
#include "Graphics/GraphicsEngineVulkan/interface/EngineFactoryVk.h"

using namespace Diligent;

struct _DPCORE {
    // current digiplane version in major.minor format
    constexpr float version = DIGIPLANE_MAJOR + 0.1f * DIGIPLANE_MINOR;
    std::string_view systemLanguage;
    lua_State* luaState;
    
};

namespace Digiplane {
    /* Application Context definitions */ 

    bool ApplicationContext::initializeGraphicsEngine(HWND hWnd)
    {
        SwapChainDesc SCDesc;
        switch (m_DeviceType)
        {
            #if D3D11_SUPPORTED
            case RENDER_DEVICE_TYPE_D3D11:
            {
                EngineD3D11CreateInfo EngineCI;
                auto* pFactoryD3D11 = GetEngineFactoryD3D11();
                pFactoryD3D11->CreateDeviceAndContextsD3D11(EngineCI, &m_pDevice, &m_pImmediateContext);
                Win32NativeWindow Window{hWnd};
                pFactoryD3D11->CreateSwapChainD3D11(m_pDevice, m_pImmediateContext, SCDesc, FullScreenModeDesc{}, Window, &m_pSwapChain);
            }
            break;
            #endif
            #if D3D12_SUPPORTED
            case RENDER_DEVICE_TYPE_D3D12:
            {
                EngineD3D12CreateInfo EngineCI;
                auto* pFactoryD3D12 = GetEngineFactoryD3D12();
                pFactoryD3D12->CreateDeviceAndContextsD3D12(EngineCI, &m_pDevice, &m_pImmediateContext);
                Win32NativeWindow Window{hWnd};
                pFactoryD3D12->CreateSwapChainD3D12(m_pDevice, m_pImmediateContext, SCDesc, FullScreenModeDesc{}, Window, &m_pSwapChain);
            }
            break;
            #endif
            #if VULKAN_SUPPORTED
            case RENDER_DEVICE_TYPE_VULKAN:
            {
                EngineVkCreateInfo EngineCI;
                auto* pFactoryVk = GetEngineFactoryVk();
                pFactoryVk->CreateDeviceAndContextsVk(EngineCI, &m_pDevice, &m_pImmediateContext);

                if (!m_pSwapChain && hWnd != nullptr)
                {
                    Win32NativeWindow Window{hWnd};
                    pFactoryVk->CreateSwapChainVk(m_pDevice, m_pImmediateContext, SCDesc, Window, &m_pSwapChain);
                }
            }
            break;
            #endif
            default:
                std::cerr << "Unknown/unsupported device type";
                return false;
                break;
        }
        return true;
    }

    bool ProcessCommandLine(const char* CmdLine)
    {
        const char* mode = nullptr;

        const char* Keys[] = {"--mode ", "--mode=", "-m "};
        for (size_t i = 0; i < _countof(Keys); ++i) {
            const auto* Key = Keys[i];
            if ((mode = strstr(CmdLine, Key)) != nullptr) {
                mode += strlen(Key);
                break;
            }
        }

        if (mode != nullptr) {
            while (*mode == ' ')
                ++mode;

            if (_stricmp(mode, "D3D11") == 0) {
                #if D3D11_SUPPORTED
                m_DeviceType = RENDER_DEVICE_TYPE_D3D11;
                #else
                std::cerr << "Direct3D11 is not supported. Please select another device type";
                return false;
                #endif
            }
            else if (_stricmp(mode, "D3D12") == 0) {
                #if D3D12_SUPPORTED
                m_DeviceType = RENDER_DEVICE_TYPE_D3D12;
                #else
                std::cerr << "Direct3D12 is not supported. Please select another device type";
                return false;
                #endif
            }
            else if (_stricmp(mode, "VK") == 0) {
                #if VULKAN_SUPPORTED
                m_DeviceType = RENDER_DEVICE_TYPE_VULKAN;
                #else
                std::cerr << "Vulkan is not supported. Please select another device type";
                return false;
                #endif
            }
            else {
                std::cerr << mode << " is not a valid device type. Only the following types are supported: D3D11, D3D12, VK";
                return false;
            }
        }
        else {
            #if D3D12_SUPPORTED
            m_DeviceType = RENDER_DEVICE_TYPE_D3D12;
            #elif VULKAN_SUPPORTED
            m_DeviceType = RENDER_DEVICE_TYPE_VULKAN;
            #elif D3D11_SUPPORTED
            m_DeviceType = RENDER_DEVICE_TYPE_D3D11;
            #endif
        }
        return true;
    }

    /* Core interfacing definitions */

    const float& getVersion() {return _DPCORE::version;}

}
