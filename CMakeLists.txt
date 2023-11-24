# Specify the minimun version for Cmake.
cmake_minimum_required(VERSION 3.26)

# Specify project name.
project(cpp-template VERSION 1.0.0)

# Specify C++ standard.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDRAD_REQUIRED)

# Add modules.
add_subdirectory(modules/module_1)
add_subdirectory(modules/module_2)
add_subdirectory(modules/connect_the_dots)
add_subdirectory(modules/random_walk)
add_subdirectory(modules/mandelbrot)
add_subdirectory(modules/opengl)

# SDL stuff. find_package(SDL2 REQUIRED)

#

# ---------- Google test stuff ----------
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG b10fad38c4026a29ea6561ab15fc4818170d1c10 # release-1.14.0
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE)

# For Google Test, prevent overriding the parent project's compiler/linker
# settings
set(gtest_force_shared_crt
    ON
    CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# ---------- GLFW stuff ----------
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG 7482de6071d21db77a7236155da44c172a7f6c9e # Release 3.3.8
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE)

FetchContent_MakeAvailable(glfw)

# ---------- SDL2 stuff ----------
FetchContent_Declare(
  SDL2
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG 15ead9a40d09a1eb9972215cceac2bf29c9b77f6 # Release 2.28.5
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE)

FetchContent_MakeAvailable(SDL2)

include_directories(modules/module_1/include/ modules/module_2/include/)

# --------- Main stuff ----------
# Add an executable.
add_executable(cpp-template main.cpp)

# Link the executable with the libraries (modules)
target_link_libraries(cpp-template module_1 module_2)

enable_testing()
