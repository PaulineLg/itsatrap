

#ifndef ITSATRAP_PACMAN_H
#define ITSATRAP_PACMAN_H

#include "object.h"
#include "character.h"


class Pacman : public Character {

public:
    Pacman();
    ~Pacman();


protected:
    int m_nbLife;
    int m_points;

};


#endif //ITSATRAP_PACMAN_H
