# Create a library target for module_1
add_library(module_1 src/module_1.cpp)

# Specify the include directories for module_1.
target_include_directories(module_1 PUBLIC include)

# Only add tests if this is the main app Prevents tests from being added in
# projects that include this one as a subproject
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  # Enable testing for this directory and below
  enable_testing()

  # Add a test executable
  add_executable(test_module_1 tests/test_module_1.cpp)

  # Link the test executable with Google Test and the module's library
  target_link_libraries(test_module_1 gtest gtest_main module_1)

  # Add the test to CTest
  add_test(NAME test_module_1 COMMAND test_module_1)
endif()
