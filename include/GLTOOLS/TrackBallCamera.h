#pragma once

#include <cstdint>
#include <SDL/SDL.h>
#include "glm.hpp"
#include "../OBJECT/character.hpp"
#include "Camera.h"
namespace glimac {

    class TrackballCamera: public Camera {
    public:

        TrackballCamera(); //Constructeur
        ~TrackballCamera(); //Destructeur
        void CameraControl();


    private:
        float m_fDistance; //distance par rapport au centre de la scène
        float m_fAngleX; // l'angle effectuée par la caméra autour de l'axe x de la scène (rotation vers le haut ou vers le bas)
        float m_fAngleY; //l'angle effectuée par la caméra autour de l'axe y de la scène (rotation vers la gauche ou vers la droite)
    };

}