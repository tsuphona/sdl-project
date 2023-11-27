add_executable(opengl src/opengl.cpp src/shader.cpp)

target_link_libraries(opengl glfw glad)

include_directories(include)
