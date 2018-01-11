//
// Created by pauli on 05/01/2018.
//
#include "../../include/GLTOOLS/VAO.hpp"
#include <iostream>

VAO::VAO(GLuint vertexAttribPos, GLuint vertexAttribNormal, GLuint vertexAttribTex){
    glGenVertexArrays(1, &vaoId);
    m_vertexAttribPos = vertexAttribPos;
    m_vertexAttribNormal = vertexAttribNormal;
    m_vertexAttribTex = vertexAttribTex;
}

//VAO::~VAO(){}

void VAO::bind(){
    glBindVertexArray(vaoId);
}

void VAO::activeAttrib(){
    if(m_vertexAttribPos != -1){
        glEnableVertexAttribArray(m_vertexAttribPos);
    }
    if(m_vertexAttribNormal != -1){
        glEnableVertexAttribArray(m_vertexAttribNormal);
    }
    if(m_vertexAttribTex != -1){
        glEnableVertexAttribArray(m_vertexAttribTex);
    }
}

/*void VAO::specificAttrib(){
    if(m_vertexAttribPos != -1){
        glVertexAttribPointer(m_vertexAttribPos, 3,GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*) offsetof(ShapeVertex, position));
        //glVertexAttribPointer(m_vertexAttribPos, 3,GL_FLOAT, GL_FALSE, sizeof(type), (const GLvoid*)0);
    }
    if(m_vertexAttribNormal != -1){
        glVertexAttribPointer(m_vertexAttribNormal, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*) offsetof(ShapeVertex, normal));
        //glVertexAttribPointer(m_vertexAttribNormal, 3,GL_FLOAT, GL_FALSE, sizeof(type), (const GLvoid*)(sizeof(glm::vec3)));
    }
    if(m_vertexAttribTex != -1){
        glVertexAttribPointer(m_vertexAttribTex, 2, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*) offsetof(ShapeVertex, texCoords));
        //glVertexAttribPointer(m_vertexAttribTex, 2,GL_FLOAT, GL_FALSE, sizeof(type), (const GLvoid*)(2*sizeof(glm::vec3)));
    }
}*/

void VAO::debind(){
    glBindVertexArray(0);
}

void VAO::deleteVao(){
    glDeleteVertexArrays(1, &vaoId);
}