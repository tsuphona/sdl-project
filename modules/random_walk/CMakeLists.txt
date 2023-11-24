# Add executable for this application.
add_executable(random_walk src/random_walk.cpp)

# Link necessary libraries to the target.
target_link_libraries(random_walk SDL2::SDL2)
