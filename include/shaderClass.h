#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include "VAO.h"
#include "../external/glm/glm/glm.hpp"
#include<string>
#include<fstream>
#include<iostream>
#include<cerrno>
#include<unordered_map>
#include<sstream>

std::string get_file_content(const char* filename);

class Shader{
	public:
		Shader(const char* vertexFile,const char* fragmentFile);
		void activate();
    int GetUniformNumber(std::string Uname);
    void UseUniformNumber(std::string name,float v0,float v1,float v2,float v3);
    void UseUniform1f(std::string name,float value);
		void UseUniform1i(std::string name,int value);
    void UseUniformMat4f(std::string name,const glm::mat4& matrix);
    void Delete();
  /* private: */
    GLuint ID;
    std::unordered_map<std::string,int> UniformsMap;
};

