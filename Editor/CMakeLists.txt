project(DigiPlaneEditor C CXX)
cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)

add_executable(DigiPlaneEditor WIN32)

target_sources(DigiPlaneEditor PRIVATE
${CMAKE_CURRENT_LIST_DIR}/glad.c
${CMAKE_CURRENT_LIST_DIR}/main.cpp
${CMAKE_CURRENT_LIST_DIR}/Editor.cpp
${CMAKE_CURRENT_LIST_DIR}/interface/interface.cpp
${CMAKE_SOURCE_DIR}/modules/imgui/backends/imgui_impl_sdl.cpp
${CMAKE_SOURCE_DIR}/modules/imgui/backends/imgui_impl_opengl3.cpp
${CMAKE_SOURCE_DIR}/modules/imgui/imgui_demo.cpp
${CMAKE_SOURCE_DIR}/modules/imgui/imgui_draw.cpp
${CMAKE_SOURCE_DIR}/modules/imgui/imgui_tables.cpp
${CMAKE_SOURCE_DIR}/modules/imgui/imgui_widgets.cpp
${CMAKE_SOURCE_DIR}/modules/imgui/imgui.cpp

)

# if windows, add Editor.rc
if(WIN32)
target_sources(DigiPlaneEditor PRIVATE ${CMAKE_CURRENT_LIST_DIR}/Editor.rc)
endif()

target_include_directories(DigiPlaneEditor PRIVATE
${CMAKE_SOURCE_DIR}/include
)

# link SDL2 statically
target_link_libraries(DigiPlaneEditor PRIVATE SDL2-static SDL2main opengl32)

# copy resources to build directory
copy_resources()
