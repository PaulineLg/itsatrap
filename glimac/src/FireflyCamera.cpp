#include "glimac/FireflyCamera.hpp"
#define M_PI  3.14159265358979323846

namespace glimac {
    FireflyCamera::FireflyCamera(){
        this->m_Position = glm::vec3(0.0,0.0,0.0);
        this->m_fPhi = M_PI;
        this->m_fTheta = 0.0;
        computeDirectionVectors(this->m_fPhi, this->m_fTheta);
    }

    FireflyCamera::~FireflyCamera(){
        // Dtor
    }

    void FireflyCamera::moveLeft(float t){
        this->m_Position += t*this->m_LeftVector;
    }
    void FireflyCamera::moveFront(float t){
        this->m_Position += t*this->m_FrontVector;
    }

    void FireflyCamera::rotateLeft(float degrees){
        this->m_fPhi = this->m_fPhi + glm::radians(degrees);
        computeDirectionVectors(this->m_fPhi, this->m_fTheta);
    }

    void FireflyCamera::rotateUp(float degrees){
        this->m_fTheta = this->m_fTheta + glm::radians(degrees);
        computeDirectionVectors(this->m_fPhi, this->m_fTheta);
    }

    glm::mat4 FireflyCamera::getViewMatrix() const{
        return glm::lookAt(this->m_Position, this->m_Position+this->m_FrontVector, this->m_UpVector);
    }

    // Méthode privée :
    void FireflyCamera::computeDirectionVectors(float phi, float teta){
        this->m_FrontVector = glm::vec3(cos(teta)*sin(phi), sin(teta),
                                        cos(teta)*cos(phi));
        this->m_LeftVector = glm::vec3(sin(phi + M_PI/2), 0.0, cos(phi+M_PI/2));
        this->m_UpVector = glm::cross(this->m_FrontVector, this->m_LeftVector);
    }
}

