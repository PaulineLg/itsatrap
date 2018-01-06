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

class Board{
    public :
        Board();
        ~Board();

        loadMatrix();
        printMatrix();

    private:
        int dimX;
        int dimY;
        //int matrix[dimX][dimY];
        std::vector< std::vector<int>> matrix;
};

#endif //ITSATRAP_BOARD_HPP
