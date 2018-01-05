//
// Created by pauli on 05/01/2018.
//
#include "../../include/GLTOOLS/VAO.h"
#include <iostream>

namespace glimac{
    VAO::VAO(GLuint vertexAttribPos, GLuint vertexAttribNormal, GLuint vertexAttribTex){
        glGenVertexArrays(1, &vaoId);
        this->vertexAttribPos = vertexAttribPos;
        this->vertexAttribNormal = vertexAttribNormal;
        this->vertexAttribTex = vertexAttribTex;
    }

    VAO::~VAO(){

    }

    void VAO::bind(){
        glBindVertexArray(vaoId);
    }

    void VAO::activeAttrib(){
        if(vertexAttribPos != -1){
            glEnableVertexAttribArray(vertexAttribPos);
        }
        if(vertexAttribNormal != -1){
            glEnableVertexAttribArray(vertexAttribNormal);
        }
        if(vertexAttribTex != -1){
            glEnableVertexAttribArray(vertexAttribTex);
        }
    }


    void VAO::debind(){
        glBindVertexArray(0);
    }

    void VAO::deleteVao(){
        glDeleteVertexArrays(1, &vaoId);
    }

}
