//
// Created by pauli on 05/01/2018.
//

#ifndef ITSATRAP_VBO_HPP
#define ITSATRAP_VBO_HPP


#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glut.h>
#include <vector>

#include "../../glimac/include/glimac/common.hpp"

namespace glimac{
    template<typename type>
    class VBO{
        public :
            VBO(std::vector<type>vertices):vertices(vertices){
                glGenBuffers(1, &vboId);
            }

            ~VBO() = default;

            void fill(int size){
                glBufferData(GL_ARRAY_BUFFER, size*sizeof(type), vertices.data(), GL_STATIC_DRAW);
            }

            void bind(){
                glBindBuffer(GL_ARRAY_BUFFER, vboId);
            }

            void debind(){
                glBindBuffer(GL_ARRAY_BUFFER, 0);
            }

            void deleteVbo(){
                glDeleteBuffers(1, &vboId);
            }

        private :
            GLuint vboId;
            std::vector<type> vertices;
    };
}

#endif //ITSATRAP_VBO_HPP
