//
// Created by pauli on 08/01/2018.
//

#include "../../include/GLTOOLS/IBO.hpp"

IBO::IBO(){
    glGenBuffers(1, &iboId);
}

void IBO::fill(int size ,const unsigned int* indices){
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

void IBO::bind(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboId);
}

void IBO::debind(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IBO::deleteVbo(){

}
