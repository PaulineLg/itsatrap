#pragma once

#include <cstdint>
#include <SDL/SDL.h>
#include <glimac/glm.hpp>
#include "../OBJECT/character.hpp"
#include "Camera.hpp"
namespace glimac {

    class TrackballCamera {
    public:

        TrackballCamera(); //Constructeur
        ~TrackballCamera(); //Destructeur
        void CameraControl();
        void moveFront(float delta);
        void rotateLeft(float degrees);
        void rotateUp(float degrees);
        glm::mat4 getViewMatrix() const;


    private:
        float m_fDistance; //distance par rapport au centre de la scène
        float m_fAngleX; // l'angle effectuée par la caméra autour de l'axe x de la scène (rotation vers le haut ou vers le bas)
        float m_fAngleY; //l'angle effectuée par la caméra autour de l'axe y de la scène (rotation vers la gauche ou vers la droite)
    };

}