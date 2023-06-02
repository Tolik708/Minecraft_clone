#ifndef VAO_OPENGL_HPP
#define VAO_OPENGL_HPP

#include "Header.hpp"

#include "VAO.hpp"
#include "VBO.hpp"

namespace Tolik
{
class VAOOpenGL : public VAO
{
public:
  VAOOpenGL() { glGenVertexArrays(1, &m_rendererID); }
  
  virtual void Bind() { glBindVertexAarray(m_rendererID); }
  virtual void Unbind() { glBindVertexAarray(0); }
  virtual void AddBuffer(VBO vbo, uint32_t count, uint32_t type, char normalized);
  virtual void AddBuffer(VBO vbo);

private:
  
};
}

#endif