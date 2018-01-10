//
// Created by pauli on 08/01/2018.
//

#ifndef ITSATRAP_IBO_HPP
#define ITSATRAP_IBO_HPP

#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glut.h>

class IBO{
public :
    IBO();
    ~IBO()= default;

    void fill(int size ,const unsigned int* indices);

    void bind();

    void debind();

    void deleteVbo();

private :
    GLuint iboId;
};

#endif //ITSATRAP_IBO_HPP
