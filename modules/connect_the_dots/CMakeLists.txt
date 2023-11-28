add_library(connect_the_dots src/connect_the_dots.cpp)

target_include_directories(connect_the_dots PRIVATE include)

target_link_libraries(connect_the_dots PRIVATE SDL2::SDL2)
