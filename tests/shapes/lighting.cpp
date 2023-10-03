#include "lighting.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace Shapes{
  Lighting::Lighting()
  :
  mvp(1.0f),
  BackColor{1.0f,1.0f,1.0f,1.0f}
  {
    /* GLfloat vertices[]={ */
    /*   0.1f,0.1f,0.1f, //0 -right top front */
    /*   0.1f,0.1f,-0.1f,//1 - right top back */
    /*   0.1f,-0.1f,0.1f,//2 - right down front */
    /*   0.1f,-0.1f,-0.1f,//3  - right down back */
    /*   -0.1f,0.1f,0.1f,//4  - left top front */
    /*   -0.1f,-0.1f,0.1f,//5 - left down front */
    /*   -0.1f,0.1f,-0.1f,//6 - left top back */
    /*   -0.1f,-0.1f,-0.1f,//7 - left down back */
    /* }; */
    /* GLuint indices[]={ */
    /*   0,4,5, */
    /*   2,0,5, */
    /*   4,7,5, */
    /*   7,6,4, */
    /*   6,3,7, */
    /*   3,1,6, */
    /*   1,3,0, */
    /*   0,2,3, */
    /* }; */
GLfloat vertices[] =
{ //     COORDINATES     //
	-0.01f, -0.01f,  0.01f,
	-0.01f, -0.01f, -0.01f,
	 0.01f, -0.01f, -0.01f,
	 0.01f, -0.01f,  0.01f,
	-0.01f,  0.01f,  0.01f,
	-0.01f,  0.01f, -0.01f,
	 0.01f,  0.01f, -0.01f,
	 0.01f,  0.01f,  0.01f
};

GLuint indices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};
    
    shader = std::make_unique<Shader>("/home/uttkarsh/OpenGL_Library/OpenGL_library/tests/shapes/resources/shaders/basic.shader",
        "/home/uttkarsh/OpenGL_Library/OpenGL_library/tests/shapes/resources/shaders/basic1.shader");

    
    vao = std::make_unique<VAO>();
    ebo = std::make_unique<EBO>(indices,sizeof(indices)/sizeof(GLuint));
    VBO vbo(vertices,sizeof(vertices));
    
    layout Layout;
    Layout.PushFloat(3);
    /* Layout.PushFloat(2); */
    vbo.Bind();
    vao->addBuffer(vbo,Layout);

    vao->Bind();
    vao->Unbind();
    vbo.Unbind();
    camera=std::make_unique<Camera>();
  }
  void Lighting::onRender(){
    renderer = std::make_unique<Renderer>();
    /* glClear(GL_COLOR_BUFFER_BIT); */
      shader->activate();
      shader->UseUniformMat4f("u_MVP",mvp);
      shader->UseUniformNumber("u_color",BackColor[0],BackColor[1],BackColor[2],1.0f);
      ebo->Bind();
      renderer->Draw(*vao,*ebo,*shader);
  }
  void Lighting::imGuiRender(){
    mvp=camera->MATRIX();
    ImGui::ColorEdit3("color of the lighting",BackColor);
  }

}
