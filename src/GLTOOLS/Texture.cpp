//
// Created by pauli on 06/01/2018.
//

#include "../../include/GLTOOLS/Texture.hpp"


Texture::Texture(std::string imgPath){
    glGenTextures(1, &texId);
    ptrImage = glimac::loadImage(imgPath);
}

void Texture::bind(){
    glBindTexture(GL_TEXTURE_2D, texId);
}

void Texture::send(){
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ptrImage->getWidth() , ptrImage->getHeight(), 0, GL_RGBA, GL_FLOAT, ptrImage->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void Texture::debind(){
    glBindTexture(GL_TEXTURE_2D, 0);
}
void Texture::deleteTex(){
    glDeleteTextures(1, &texId);
}

GLuint Texture::getId(){
    return texId;
}


