//
// Created by pauli on 05/01/2018.
//

#ifndef ITSATRAP_VAO_H
#define ITSATRAP_VAO_H

#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glut.h>
#include <vector>

#include <iostream>

#include "../../glimac/include/glimac/common.hpp"

namespace glimac{
    class VAO{
    public:
        VAO(GLuint vertexAttribPos = -1, GLuint vertexAttribNormal = -1, GLuint vertexAttribTex = -1);
        ~VAO();
        void bind();
        void activeAttrib();

        template <typename type>
        void specificAttrib(){
            if(vertexAttribPos != -1){
                std::cout << "Here" << std::endl;
                //glVertexAttribPointer(vertexAttribPos, 3,GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*) offsetof(ShapeVertex, position));
                glVertexAttribPointer(vertexAttribPos, 3,GL_FLOAT, GL_FALSE, sizeof(type), (const GLvoid*)0);
            }
            if(vertexAttribNormal != -1){
                //glVertexAttribPointer(vertexAttribNormal, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*) offsetof(ShapeVertex, normal));
                glVertexAttribPointer(vertexAttribNormal, 3,GL_FLOAT, GL_FALSE, sizeof(type), (const GLvoid*)(sizeof(glm::vec3)));
            }
            if(vertexAttribTex != -1){
                //glVertexAttribPointer(vertexAttribTex, 2, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*) offsetof(ShapeVertex, texCoords));
                glVertexAttribPointer(vertexAttribTex, 2,GL_FLOAT, GL_FALSE, sizeof(type), (const GLvoid*)(2*sizeof(glm::vec3)));
            }
        }

        void debind();
        void deleteVao();

    private :
        GLuint vaoId;
        GLuint vertexAttribPos;
        GLuint vertexAttribNormal;
        GLuint vertexAttribTex;
    };
}

#endif //ITSATRAP_VAO_H
