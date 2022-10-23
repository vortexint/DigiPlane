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

# foundation
add_subdirectory(modules/SDL)
# intermediary
add_subdirectory(DigiPlaneEngine)
# final
add_subdirectory(Editor)
add_subdirectory(Game)