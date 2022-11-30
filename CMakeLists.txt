cmake_minimum_required(VERSION 3.0.0)
project(DigiPlane C CXX)

# Utility function to copy files inside of ${CMAKE_CURRENT_LIST_DIR}/resources to the final executable output directory
function(copy_resources)
    file(GLOB_RECURSE resources RELATIVE ${CMAKE_CURRENT_LIST_DIR}/resources ${CMAKE_CURRENT_LIST_DIR}/resources/*)
    foreach(resource ${resources})
        configure_file(${CMAKE_CURRENT_LIST_DIR}/resources/${resource} ${CMAKE_CURRENT_BINARY_DIR}/Debug/${resource} COPYONLY)
        configure_file(${CMAKE_CURRENT_LIST_DIR}/resources/${resource} ${CMAKE_CURRENT_BINARY_DIR}/Release/${resource} COPYONLY)
    endforeach()
endfunction()

if (MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup") # Use main instead of WinMain for Windows subsystem
    # set ${PLATFORM} to Windows
    set(PLATFORM WIN32)
    # warning level 4
    add_compile_options(/W4 /WX)
else()
    # lots of warnings
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# Include for all subdirectories
include_directories(
${CMAKE_SOURCE_DIR}/include
)

# foundation
add_subdirectory(modules/bgfx.cmake)
add_subdirectory(modules/glfw)
add_subdirectory(modules/flecs)
# intermediary
add_subdirectory(core)
# final
add_subdirectory(Editor)
add_subdirectory(Runtime)