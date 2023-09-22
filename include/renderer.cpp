#include "renderer.h"

void Renderer::Draw(VAO& vao,EBO& ebo,Shader& shader) {
  shader.activate();
  vao.Bind();
  ebo.Bind();
  glDrawElements(GL_TRIANGLES,ebo.count,GL_UNSIGNED_INT,nullptr);
}
void Renderer::ClearBuffer(){
  glClear(GL_COLOR_BUFFER_BIT);
}


