#include "triangles.h"
#include <memory>

namespace Shapes{
  Triangle::Triangle()
    :translation(200,0,0)
    {
    GLfloat vertices[]={
      -0.5f,-0.5f,
      0.0f,0.5f, 
      0.5f,-0.5f
    };
    GLuint indices[]={
      0,1,2
    };

    shader = std::make_unique<Shader>("/home/uttkarsh/OpenGL_Library/OpenGL_library/tests/shapes/resources/shaders/shapes/vert.shader",
        "/home/uttkarsh/OpenGL_Library/OpenGL_library/tests/shapes/resources/shaders/shapes/frag.shader");
    vao = std::make_unique<VAO>();
    ebo = std::make_unique<EBO>(indices,3);
    VBO vbo(vertices,3*2*sizeof(float));
    layout Layout;

    Layout.PushFloat(2);

    vbo.Bind();
    vao->addBuffer(vbo,Layout);


    vao->Bind();
    vao->Unbind();
    vbo.Unbind();
  }
  void Triangle::onRender(){
    renderer = std::make_unique<Renderer>();
    /* glClearColor(0.0f,0.0f,0.0f,1.0f); */
    /* glClear(GL_COLOR_BUFFER_BIT); */
    float width = float(windowWidth);
    float height = float(windowHeight);

    glm::mat4 proj = glm::ortho(0.0f,width,0.0f,height,-1.0f,1.0f);
    glm::mat4 view = glm::translate(glm::mat4(1.0f),glm::vec3(0.0f,0.0f,0.0f));
      shader->activate();
      glm::mat4 model = glm::translate(glm::mat4(1.0f),translation);
      glm::mat4 mvp = proj*view*model;

      shader->UseUniformNumber("TexColor",0.5f,0.5f,0.5f,1.0f);
      shader->UseUniformMat4f("u_MVP",mvp);
      ebo->Bind();
      renderer->Draw(*vao,*ebo,*shader);
  }
  Triangle::~Triangle(){

  }
  void Triangle::imGuiRender(){
    ImGui::SliderFloat2("x axis and y axis is controlled by this ",&translation.x,50.0f,320.0f);
  }
}
