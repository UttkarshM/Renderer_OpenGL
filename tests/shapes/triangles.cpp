#include "triangles.h"
#include <GL/gl.h>
#include <memory>
#include <filesystem>

namespace Shapes{
  Triangle::Triangle()
    :
    mvp(1.0f)
    {
      GLfloat vertices[]={
        -0.25f,0.0f,0.0f, 0.25f,0.0f,  // left part 0
        0.25f,0.0f,0.0f,  0.75f,0.0f,     // right 1
        0.0f,0.0f,0.25f,  0.0f,0.0f,       //front 2
        0.0f,0.0f,-0.25f, 0.50f,0.0f,     //back 3
        0.0f,0.25f,0.0f,  1.0f,1.0f,      //top 4.
        0.0f,0.0f,0.0f,   0.0f,1.0f       // centre 5
      };
      GLuint indices[]={
        0,4,2,
        2,4,1,
        1,4,3,
        3,4,0,

        0,5,2,
        2,5,1,
        1,5,3,
        3,5,0
      };
    //remove the shader part if u dont want a texture.

    shader = std::make_unique<Shader>("/home/uttkarsh/OpenGL_Library/OpenGL_library/tests/shapes/resources/shaders/f1.shader",
        "/home/uttkarsh/OpenGL_Library/OpenGL_library/tests/shapes/resources/shaders/v1.shader");

    texture = std::make_unique<Texture>("/home/uttkarsh/OPENGL/open_gl/include/resources/textures/sky.jpg");
    texture->Bind(0);
    
    shader->UseUniform1i("u_Texture",0);
    
    vao = std::make_unique<VAO>();
    ebo = std::make_unique<EBO>(indices,24);
    VBO vbo(vertices,5*5*sizeof(float));
    
    layout Layout;
    Layout.PushFloat(3);
    Layout.PushFloat(2);

    vbo.Bind();
    vao->addBuffer(vbo,Layout);


    vao->Bind();
    vao->Unbind();
    vbo.Unbind();

    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    camera=std::make_unique<Camera>();
  }
  void Triangle::onRender(){
    renderer = std::make_unique<Renderer>();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      shader->activate();
      shader->UseUniformMat4f("u_MVP",mvp);
      ebo->Bind();
      renderer->Draw(*vao,*ebo,*shader);
  }
  Triangle::~Triangle(){

  }
  void Triangle::imGuiRender(){
    mvp=camera->MATRIX();
  }
}
