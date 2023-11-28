# Specify the minimun version for Cmake.
cmake_minimum_required(VERSION 3.26)

# Specify project name.
project(sdldemo VERSION 1.0.0)

# Specify C++ standard.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDRAD_REQUIRED)

# Add modules.
add_subdirectory(modules/connect_the_dots)
add_subdirectory(modules/random_walk)
add_subdirectory(modules/mandelbrot)

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

# ---------- SDL2 stuff ----------
FetchContent_Declare(
  SDL2
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG 15ead9a40d09a1eb9972215cceac2bf29c9b77f6 # Release 2.28.5
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE)

FetchContent_MakeAvailable(SDL2)

# ---------- Main stuff ----------
add_executable(sdldemo main.cpp)
enable_testing()

# ---------- TCLAP stuff ----------
target_include_directories(sdldemo PRIVATE external/tclap/include)
