#include "VAO.h"
#include "renderer.h"
VAO::VAO(){
    glGenVertexArrays(1,&ID);
}
void VAO::deleteV() const{
    glDeleteVertexArrays(1,&ID);
}

void VAO::addBuffer(const VBO& VBO, const layout &layout){
    Bind();
    VBO.Bind();
    unsigned int offset=0;
    const auto& elements = layout.GetElements();
    int total=0;
    for(unsigned int i=0;i<elements.size();i++){
        const auto& element=elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i,element.count,element.type,element.normalised,layout.GetStride(),(const void*)offset);
        std::cout<<element.count<<std::endl;
        /* std::cout<<element.count * VertexBufferElements::GetSizeofType(element.type)<<std::endl; */
        offset+=element.count * VertexBufferElements::GetSizeofType(element.type);

        /* std::cout<<layout.GetStride()<<std::endl; */
    /* std::cout<<offset<<std::endl; */
    }
}
void VAO::Bind() const {
    glBindVertexArray(ID);
}
void VAO::Unbind() const{
    glBindVertexArray(0);
}
