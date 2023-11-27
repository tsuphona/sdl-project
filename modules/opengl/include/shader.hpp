#ifndef SHADER_HPP_
#define SHADER_HPP_

#include <glad/glad.h>

#include <string>

class Shader {
 public:
  unsigned int ID;
  Shader(const char* vertexPath, const char* fragmentPath);
  void use();
  void deleteShader();

 private:
  void checkCompileErrors(unsigned int shader, std::string type);
};

#endif  // SHADER_HPP_
