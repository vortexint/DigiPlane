cmake_minimum_required(VERSION 3.0.0)
project(DigiPlane C CXX)
set(CMAKE_CXX_STANDARD 20)

# Utility function to copy files inside of ${CMAKE_CURRENT_LIST_DIR}/resources to the final executable output directory
function(copy_resources)
    file(GLOB_RECURSE resources RELATIVE ${CMAKE_CURRENT_LIST_DIR}/resources ${CMAKE_CURRENT_LIST_DIR}/resources/*)
    foreach(resource ${resources})
        configure_file(${CMAKE_CURRENT_LIST_DIR}/resources/${resource} ${CMAKE_CURRENT_BINARY_DIR}/Debug/${resource} COPYONLY)
        configure_file(${CMAKE_CURRENT_LIST_DIR}/resources/${resource} ${CMAKE_CURRENT_BINARY_DIR}/Release/${resource} COPYONLY)
    endforeach()
endfunction()

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup") # Use main instead of WinMain
    add_compile_options(/W4)
else()
    # lots of warnings
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# Include directories for all targets
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

# foundation TODO: use find_package instead of add_subdirectory
add_subdirectory(modules/bgfx.cmake)
add_subdirectory(modules/glfw)
add_subdirectory(modules/flecs)
# intermediary
add_subdirectory(core)
# final
add_subdirectory(Editor)
add_subdirectory(Runtime)