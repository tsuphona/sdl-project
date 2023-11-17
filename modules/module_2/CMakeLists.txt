# Create a library target for module_2.
add_library(module_2 src/module_2.cpp)

# Specify the include directories for module_2
target_include_directories(module_2 PUBLIC include)
