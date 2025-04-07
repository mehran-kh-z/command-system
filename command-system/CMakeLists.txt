
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 COMPONENTS Core REQUIRED)

set(PROJECT_SOURCES
    src/command/command_manager.cpp
    src/command/command_history.cpp
    src/command/command_registry.cpp
    src/command/command_invoker.cpp
    src/command/command_info.cpp
)

# Add the library
add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCES})
add_library(${COMPANY_NAMESPACE}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
  PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:src>

  PUBLIC
    $<BUILD_INTERFACE:include ${SPDLOG_INCLUDE_DIRS}>
    $<INSTALL_INTERFACE:include ${SPDLOG_INCLUDE_DIRS}>
)
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt::Core
    ${COMPANY_NAMESPACE}::common
)
target_compile_definitions(${PROJECT_NAME} PRIVATE COMMAND_SYSTEM_LIBRARY)

# Install rules
install(TARGETS ${PROJECT_NAME}
    EXPORT CommandSystemTargets
    RUNTIME DESTINATION bin
    COMPONENT Binaries
)

# Export the package for use from the build tree
export(EXPORT CommandSystemTargets
    FILE "${CMAKE_BINARY_DIR}/command-systemConfig.cmake"
    NAMESPACE ${COMPANY_NAMESPACE}::
)

# Create a Config file for the package
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_BINARY_DIR}/command-systemConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

# Export the package for use from the install tree
export(PACKAGE ${PROJECT_NAME})
