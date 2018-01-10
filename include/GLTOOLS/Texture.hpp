//
// Created by pauli on 06/01/2018.
//

#ifndef ITSATRAP_TEXTURE_HPP
#define ITSATRAP_TEXTURE_HPP

#define GLEW_STATIC
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <../../glimac/include/glimac/Image.hpp>

namespace glimac{
    class Texture{
        public :
            Texture(std::string imgPath);
            ~Texture() = default;

            void bind();
            void send();
            void debind();
            void deleteTex();
            GLuint getId();

        private :
            GLuint texId;
            std::unique_ptr<Image> ptrImage;
    };
}



#endif //ITSATRAP_TEXTURE_HPP
