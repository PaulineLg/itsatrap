#pragma once

#include <cstdint>
#include <SDL/SDL.h>
#include <glimac/glm.hpp>
#include "../OBJECT/pacman.hpp"


namespace glimac {

    class Camera {

    public:
        virtual void moveFront(float delta) =0; //permettant d'avancer / reculer la caméra. Lorsque delta est positif la caméra doit avancer, sinon elle doit reculer.
        virtual void rotateLeft(float degrees)=0; //permettant de tourner latéralement autour du centre de vision.
        virtual void rotateUp(float degrees)=0; //permettant de tourner verticalement autour du centre de vision.
        glm::mat4 getViewMatrix() const;

    private:

    };
}