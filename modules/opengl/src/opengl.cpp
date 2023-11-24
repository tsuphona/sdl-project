#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <iostream>

int main(int argc, char* argv[]) {
  // Initialize GLFW
  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW" << std::endl;
    return -1;
  }

  // Create a GLFW window object.
  GLFWwindow* window = glfwCreateWindow(640, 480, "Hello GLFW, OpenGl and GLAD",
                                        nullptr, nullptr);
  if (window == nullptr) {
    // Window or OpenGL context creation failed
    std::cerr << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }

  // Make the window's context current
  glfwMakeContextCurrent(window);

  // Load all OpenGL function pointers with GLAD
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cerr << "Failed to initialize GLAD" << std::endl;
    glfwTerminate();
    return -1;
  }

  // Set the viewport
  glViewport(0, 0, 640, 480);

  // Main loop
  while (!glfwWindowShouldClose(window)) {
    // Poll for and process events
    glfwPollEvents();

    // Rendering commands here.
    glClearColor(0.25f, 0.5f, 0.75f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Swap front and back buffers
    glfwSwapBuffers(window);
  }

  // Clean up and exit.
  glfwTerminate();
  return 0;
}
