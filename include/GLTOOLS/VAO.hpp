//
// Created by pauli on 05/01/2018.
//

#ifndef ITSATRAP_VAO_HPP
#define ITSATRAP_VAO_HPP

#define GLEW_STATIC
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <vector>

#include "../../glimac/include/glimac/common.hpp"

namespace glimac{
    class VAO{
    public:
        VAO(GLuint vertexAttribPos = -1, GLuint vertexAttribNormal = -1, GLuint vertexAttribTex = -1);
        ~VAO() = default;
        void bind();
        void activeAttrib();

        //void specificAttrib();
        template <typename type>
        void specificAttrib(){
            if(m_vertexAttribPos != -1){
                std::cout << "Here" << std::endl;
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
        }

        void debind();
        void deleteVao();

    private :
        GLuint vaoId;
        GLuint m_vertexAttribPos;
        GLuint m_vertexAttribNormal;
        GLuint m_vertexAttribTex;
    };
}

#endif //ITSATRAP_VAO_HPP
