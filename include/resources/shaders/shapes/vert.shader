#version 330 core

layout(location=0) in vec4 positon;

uniform mat4 u_MVP;

void main(){
    gl_Position = u_MVP*positon;
};
