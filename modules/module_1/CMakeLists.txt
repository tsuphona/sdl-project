# Create a libreary target for module_1
add_library(module_1 src/module_1.cpp)

# Specify the include directories for module_1.
target_include_directories(module_1 PUBLIC include)
