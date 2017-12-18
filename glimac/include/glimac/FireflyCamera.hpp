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

    class FireflyCamera {

        public:
            FireflyCamera();
            ~FireflyCamera();

            void moveLeft(float t);
            void moveFront(float t);
            void rotateLeft(float degrees);
            void rotateUp(float degrees);
        glm::mat4 getViewMatrix() const;

    private:
            glm::vec3 m_Position;
            float m_fPhi;
            float m_fTheta;
            glm::vec3 m_FrontVector;
            glm::vec3 m_LeftVector;
            glm::vec3 m_UpVector;

            // Méthode privée :
            void computeDirectionVectors(float phi, float teta);
    };
}