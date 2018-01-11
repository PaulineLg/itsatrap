#pragma once
#include "glimac/glm.hpp"
#include "../OBJECT/pacman.hpp"
#include "Camera.hpp"

using namespace glimac;

class FreeFlyCamera: public Camera{

public:
    FreeFlyCamera();
    void computeDirectionVectors();
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

};