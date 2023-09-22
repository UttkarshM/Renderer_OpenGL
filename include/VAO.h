#pragma once
#include"VBO.h"
#include"layout.h"
/* #include <GLFW/glfw3.h> */
/* #include <glad/glad.h> */

class VAO{
    /* private: */
  public:
    unsigned int ID;

    /* public: */
        VAO();
        void deleteV() const;
        void addBuffer(const VBO& VBO,const layout& layout);
        void Bind() const;
        void Unbind() const;
};

