

#ifndef ITSATRAP_PACMAN_HPP
#define ITSATRAP_PACMAN_HPP

#include "object.hpp"
#include "character.hpp"


class Pacman : public Character {

public:
    Pacman();
    ~Pacman() = default;

    int getNbLife();
    int getPoints();


private:
    int m_nbLife = 3;
    int m_points = 0;

};


#endif //ITSATRAP_PACMAN_HPP
