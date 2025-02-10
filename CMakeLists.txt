cmake_minimum_required(VERSION 3.16)

project("command-system" VERSION 0.1 LANGUAGES CXX)

if (NOT TARGET common)
    add_subdirectory(libs/common)
endif()

add_subdirectory("command-system")
