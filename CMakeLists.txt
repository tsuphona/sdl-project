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

# SDL stuff.
find_package(SDL2 REQUIRED)
include_directories(modules/module_1/include/ modules/module_2/include/
                    ${SDL2_INCLUDE_DIRS})

# Add an executable.
add_executable(cpp-template main.cpp)

# Link the executable with the libraries (modules)
target_link_libraries(cpp-template module_1 module_2 ${SDL2_LIBRARIES})

# Include FetchContent for Google Test
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

enable_testing()
