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

namespace glimac{
    class Board{
            public :
                Board();
                ~Board() = default;

                void loadMatrix();
                void printMatrix();
                void loadCubes();
                void draw();

            private:
                int m_dimX;
                int m_dimY;
                std::vector< std::vector<int>> m_matrix;
                Cube *m_cube;
    };
}


#endif //ITSATRAP_BOARD_HPP
