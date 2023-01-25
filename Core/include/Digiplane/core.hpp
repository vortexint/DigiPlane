#pragma once

#include <string>

#include "../types.hpp"
#include "../geometry/mesh.hpp"
#include "../graphics/shaders.hpp"

#define DIGIPLANE_MAJOR 0
#define DIGIPLANE_MINOR 1

/* Plugins */

#if defined(DIGIPLANE_NK_PLUGIN)
#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#pragma warning(push, 0)
#include "nuklear.h"
#pragma warning(pop)
#ifndef NK_NUKLEAR_H_
    #error "Unable to include "nuklear.h", please make sure it is in your include path."
#endif
#include "../plugins/nuklear_impl.hpp"
#endif

#if defined(DIGIPLANE_IMGUI_PLUGIN)
#pragma warning(push, 0)
//#include "imgui.h"
#pragma warning(pop)
#ifndef IMGUI_API
    #error "Unable to include "imgui.h", please make sure it is in your include path."
#endif
#include "../plugins/imgui_impl.hpp"
#endif

// The Digiplane namespace is the root namespace for all Digiplane classes and functions.
// definitions at core.cpp
namespace Digiplane {

    // The ApplicationContext is a container for managing and storing application-level objects and resources.
    class ApplicationContext {
    private:
        static bool quit;

        flecs::world world;

        Diligent::RefCntAutoPtr<Diligent::IPipelineState> m_pPSO; // Pipeline State Object used to render the scene
        
    public:
        ApplicationContext();
        ~ApplicationContext() {}

        // Returns a pointer to the world object.
        flecs::world* getWorld() { return &world; }

        void init();

        // processCmdArg is used to parse command line arguments and set the desired application initialization behavior.
        // If the argument is not using the "-dp" prefix, it is ignored.
        bool processCmdArg(const char* argv);

    };

    /* Core interfacing */

    // Returns a reference the version of the Digiplane library as a float that can be used for version checking.
    const float& getVersion();


} // DigiPlane
