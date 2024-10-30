cmake_minimum_required(VERSION 3.29)

# Set the vcpkg toolchain file and C++ standard
#set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_CXX_STANDARD 20)

project(opengl-cpp-engine)

# Find packages
find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(OpenGL REQUIRED COMPONENTS OpenGL)
# Since STB is a header-only library, it doesn't need to be included in this file.

# Add executable
add_executable(opengl-cpp-engine
        src/main.cpp
        src/window.cpp
        src/window.h
        src/Texture2D.cpp
        src/Texture2D.h
        src/ShaderProgram.cpp
        src/ShaderProgram.h
        src/QuadMesh.cpp
        src/QuadMesh.h
        src/Renderer.cpp
        src/Renderer.h
        src/Texture2DRegion.cpp
        src/Texture2DRegion.h
)

# Copy shaders to the build directory
add_custom_command(
        TARGET opengl-cpp-engine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/src/shaders
        ${CMAKE_CURRENT_BINARY_DIR}/shaders)

# Copy assets to the build directory
add_custom_command(
        TARGET opengl-cpp-engine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_CURRENT_BINARY_DIR}/assets)

# Link libraries to the test executable
target_link_libraries(opengl-cpp-engine PRIVATE
        glad::glad
        glfw
        glm::glm-header-only
        OpenGL::GL
)
