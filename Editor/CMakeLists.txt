project(DigiPlaneEditor C CXX)

add_executable(DigiPlaneEditor)

target_sources(DigiPlaneEditor PRIVATE
${CMAKE_CURRENT_LIST_DIR}/Main.cpp
${CMAKE_CURRENT_LIST_DIR}/Editor.rc
)

# link Digiplane's core to the editor
target_link_libraries(DigiPlaneEditor DigiPlaneCore)

# copy resources to build directory
copy_resources()
