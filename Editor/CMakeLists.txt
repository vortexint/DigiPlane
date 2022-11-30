project(DigiPlaneEditor C CXX)
cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)

add_executable(DigiPlaneEditor ${PLATFORM})

target_sources(DigiPlaneEditor PRIVATE
${CMAKE_CURRENT_LIST_DIR}/Main.cpp
${CMAKE_CURRENT_LIST_DIR}/Editor.cpp
${CMAKE_CURRENT_LIST_DIR}/Editor.rc
)

# link Digiplane's core to the editor
target_link_libraries(DigiPlaneEditor DigiPlaneCore)

# copy resources to build directory
copy_resources()
