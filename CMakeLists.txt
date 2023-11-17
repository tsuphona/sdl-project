# Specify the minimun version for Cmake.
cmake_minimum_required(VERSION 3.10)

# Specify project name.
project(cpp-template)

# Specify C++ standard.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDRAD_REQUIRED)

# Add modules.
add_subdirectory(modules/module_1)
add_subdirectory(modules/module_2)

# Add an executable.
add_executable(cpp-template main.cpp)

# Link the executable with the libraries (modules)
target_link_libraries(cpp-template module_1 module_2)
