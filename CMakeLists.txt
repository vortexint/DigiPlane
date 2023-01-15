cmake_minimum_required(VERSION 3.0.0)
project(DigiPlane C CXX)
set(CMAKE_CXX_STANDARD 20)

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
add_subdirectory(modules/nvrhi)
add_subdirectory(modules/flecs)
add_subdirectory(modules/lua)
# intermediary
add_subdirectory(Core)
# final
add_subdirectory(Editor)
add_subdirectory(Runtime)