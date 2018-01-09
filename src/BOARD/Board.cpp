//
// Created by pauli on 03/01/2018.
//

#include "../../include/BOARD/Board.hpp"

Board::Board(){
    dimX = 0;
    dimY = 0;
}

Board::~Board(){

}

Board::loadMatrix(){
    std::cout << "start loadmatrix" << std::endl;

    std::string url = "../../asset/xmlFiles/board.xml";
    tinyxml2::XMLDocument xmlDoc;
    xmlDoc.LoadFile(url.c_str());

    tinyxml2::XMLText * textNode;

    tinyxml2::XMLElement * rowXml = xmlDoc.FirstChildElement("board")->FirstChildElement();
    while(rowXml){
        dimX++;
        std::vector<int> line;
        int tmp;
        tinyxml2::XMLElement * colXML = rowXml->FirstChildElement();
        while(colXML){
            textNode = colXML->FirstChild()->ToText();
            dimY++;
            tmp = atoi(textNode->Value());
            line.push_back(tmp);
            colXML = colXML->NextSiblingElement();
        }
        rowXml = rowXml->NextSiblingElement();
        matrix.push_back(line);
    }

    dimY = dimY / dimX;

    std::cout << "DIM X : " << dimX << std::endl;
    std::cout << "DIM Y : " << dimY << std::endl;
}

Board::printMatrix(){
    int i = 0, j = 0;
    std::vector< std::vector<int> >::iterator row;
    std::vector<int>::iterator col;
    for (row = matrix.begin(); row != matrix.end(); row++) {
        j = 0;
        for (col = row->begin(); col != row->end(); col++) {
            std::cout << matrix[i][j] << "-";
            j++;
        }
        i++;
        std::cout << std::endl;
    }
}