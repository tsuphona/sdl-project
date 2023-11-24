#include <GLFW/glfw3.h>

#include <iostream>

int main(int argc, char* argv[]) {
  // Initialize GLFW
  if (!glfwInit()) {
    // Initialization failed
    return -1;
  }

  // Create a windowed mode window and its OpenGL context
  GLFWwindow* window = glfwCreateWindow(640, 480, "Hello GLFW", NULL, NULL);
  if (!window) {
    // Window or OpenGL context creation failed
    glfwTerminate();
    return -1;
  }

  // Make the window's context current
  glfwMakeContextCurrent(window);

  // Main loop
  while (!glfwWindowShouldClose(window)) {
    // Render here

    // Swap front and back buffers
    glfwSwapBuffers(window);

    // Poll for and process events
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
