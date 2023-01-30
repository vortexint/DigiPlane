cmake_minimum_required(VERSION 3.0.0)
project(DigiPlane C CXX)
set(CMAKE_CXX_STANDARD 20)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  message(STATUS "GCC detected, adding compile options")
  if (CMAKE_BUILD_TYPE MATCHES "Debug")
      message(STATUS "Debug build detected, adding compile options")
      add_compile_options(-Wall -Wextra -Wpedantic -g -O0)
  else()
      message(STATUS "Release build detected, adding compile options")
      add_compile_options(-Wall -Wextra -Wpedantic -O3)
  endif()
elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  message(STATUS "MSVC detected, adding compile options")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup") # Use main instead of WinMain
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        message(STATUS "Debug build detected, adding compile options")
        add_compile_options(/W4 /Od /Zi /EHsc)
    else()
        message(STATUS "Release build detected, adding compile options")
        add_compile_options(/W4 /O2 /EHsc)
    endif()
endif()

# Include directories for all targets
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

# foundation TODO: use find_package instead of add_subdirectory
add_subdirectory(modules/flecs)
#add_subdirectory(modules/openal-soft)
add_subdirectory(modules/glfw)
add_subdirectory(modules/DiligentCore)
add_subdirectory(modules/lua)
# intermediary
add_subdirectory(Core)
# final
add_subdirectory(Editor)
add_subdirectory(Runtime)