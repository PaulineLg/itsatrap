//
// Created by Ugo on 06/01/2018.
//

#include "../../include/OBJECT/pacman.hpp"

Pacman::Pacman(char* argv){
    m_id = 1;

    // Construction de la sphere :
    sphere = new glimac::Sphere(1, 32, 16);

    // Création des matrices :

    //Initialisation du programme :
    glimac::FilePath applicationPath(argv);
    m_pacProgram = new PacProgram(applicationPath);

}

int Pacman::getNbLife() {
    return m_nbLife;
}

int Pacman::getPoints() {
    return m_points;
}
