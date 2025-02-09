
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Core REQUIRED)

set(PROJECT_SOURCES
    src/registry/command_registry.cpp
)

# Add the library
add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core)
target_compile_definitions(${PROJECT_NAME} PRIVATE COMMAND_SYSTEM_LIBRARY)
target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:include src>
    $<INSTALL_INTERFACE:include src>
)

# Install rules
install(TARGETS ${PROJECT_NAME}
    EXPORT CommandSystemTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(DIRECTORY include/ DESTINATION include)

# Export the package for use from the build tree
export(EXPORT CommandSystemTargets
    FILE "${CMAKE_CURRENT_BINARY_DIR}/CommandSystemTargets.cmake"
    NAMESPACE ${PROJECT_NAME}::
)

# Create a Config file for the package
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/CommandSystemConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

# Export the package for use from the install tree
export(PACKAGE ${PROJECT_NAME})
