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

#include "../../include/BOARD/Cube.hpp"
#include "../../include/OBJECT/Character.hpp"
#include "../../include/OBJECT/Pacman.hpp"

namespace glimac{
    class Board{
            public :
                Board();
                ~Board() = default;

                void loadMatrix();
                void printMatrix();
                void loadCubes();
                void loadObjects();
                void draw();

            private:
                int m_dimX;
                int m_dimY;
                std::vector< std::vector<int>> m_matrix;
                Cube *m_cube;
                std::vector<Object*> m_objects;
                Pacman *m_pacman;
    };
}


#endif //ITSATRAP_BOARD_HPP
