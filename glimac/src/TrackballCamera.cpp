#include "glimac/TrackballCamera.hpp"


namespace glimac {
    TrackballCamera::TrackballCamera(){
        this->m_fDistance = 5.0;
        this->m_fAngleX = 0.0;
        this->m_fAngleY = 0.0;
    }

    TrackballCamera::~TrackballCamera(){

    }

    void TrackballCamera::moveFront(float delta){
        this->m_fDistance += delta;
    }

    void TrackballCamera::rotateLeft(float degrees){
        this->m_fAngleY += degrees;
    }

    void TrackballCamera::rotateUp(float degrees){
        this->m_fAngleX += degrees;
    }

    glm::mat4 TrackballCamera::getViewMatrix() const{
        glm::mat4 matrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0,0.0,-(this->m_fDistance)));
        matrix = glm::rotate(matrix, this->m_fAngleY, glm::vec3(0, 1, 0));
        matrix = glm::rotate(matrix, this->m_fAngleX, glm::vec3(1, 0, 0));
        return matrix;
    }
}

