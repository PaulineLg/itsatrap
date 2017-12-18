#pragma once
#include <iostream>
#include <fstream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <memory>
#include <SDL/SDL.h>
#include <glimac/Sphere.hpp>
#include <glimac/Program.hpp>
#include <glimac/Image.hpp>
#include <glimac/SDLWindowManager.hpp>

namespace glimac {

class TrackballCamera {

    public:
        TrackballCamera();
        ~TrackballCamera();

        void moveFront(float delta);
        void rotateLeft(float degrees);
        void rotateUp(float degrees);

        glm::mat4 getViewMatrix() const;

    private:
        float m_fDistance;
        float m_fAngleX;
        float m_fAngleY;
};
    
}