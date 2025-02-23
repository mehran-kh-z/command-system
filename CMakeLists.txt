cmake_minimum_required(VERSION 3.16)
project("command-system" VERSION 0.1 LANGUAGES CXX)

if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    include(${CMAKE_SOURCE_DIR}/libs/common/common/cmake/project_scaffold.cmake)
    if (NOT TARGET common)
        add_subdirectory(libs/common)
    endif()
endif()

add_subdirectory("command-system")
