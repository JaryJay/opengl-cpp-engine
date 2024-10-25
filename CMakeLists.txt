cmake_minimum_required(VERSION 3.29)
project(test)

# Set the vcpkg toolchain file and C++ standard
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_CXX_STANDARD 20)

# Find packages
find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(OpenGL REQUIRED COMPONENTS OpenGL)
# Since STB is a header-only library, it doesn't need to be included in this file.

# Add executable
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
add_executable(test ${SOURCE_FILES})

# Link libraries to the test executable
target_link_libraries(test PRIVATE
    glad::glad
    glfw
    glm::glm-header-only
    OpenGL::GL
)