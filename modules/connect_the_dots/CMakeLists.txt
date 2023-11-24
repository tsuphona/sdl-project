# Add application executable
add_executable(connect_the_dots src/connect_the_dots.cpp)

# Link the executable with SDL2 module's library
target_link_libraries(connect_the_dots SDL2::SDL2)
