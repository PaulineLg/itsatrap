//
// Created by pauli on 03/01/2018.
//

#ifndef ITSATRAP_BOARD_HPP
#define ITSATRAP_BOARD_HPP

#include "tinyxml2.h"

#include <string>

#include <iostream>
#include <fstream>
#include <vector>
#include <list>

#include "../../include/BOARD/Cube.hpp"
#include "../../include/OBJECT/Character.hpp"
#include "../../include/OBJECT/Pacman.hpp"
#include "../../include/OBJECT/pacgomme.hpp"
#include "../../include/GLTOOLS/TrackBallCamera.hpp"
#include "../../include/GLTOOLS/FreeFlyCamera.hpp"

class Board{
        public :
            Board();
            ~Board();

            void loadMatrix();
            void printMatrix();
            void loadCubes();
            void loadObjects();
            void movePacman(bool up, bool down, bool right, bool left);
            void draw();

        private:
            int m_dimX;
            int m_dimY;
            std::vector< std::vector<int>> m_matrix;
            Cube *m_cube;
            std::list<Item*> m_item;
            Pacman *m_pacman;
            FreeFlyCamera m_camera;
};

#endif //ITSATRAP_BOARD_HPP
