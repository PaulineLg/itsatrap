//
// Created by pauli on 03/01/2018.
//

#include "../../include/BOARD/Board.hpp"
#include "../../include/OBJECT/Pacgomme.hpp"

Board::Board(){
    m_dimX = 0;
    m_dimY = 0;
    m_pacman = new Pacman("../../cmake-build-debug/src/itsatrap.exe");
    m_pacgomme = new Pacgomme("../../cmake-build-debug/src/itsatrap.exe");
    m_pacman->generate();
    m_pacgomme->generate();
}

Board::~Board(){
    delete m_pacgomme;
    delete m_pacman;
    delete m_cube;
}

void Board::loadMatrix(){
    std::cout << "start loadmatrix" << std::endl;

    std::string url = "../../asset/xmlFiles/board.xml";
    tinyxml2::XMLDocument xmlDoc;
    xmlDoc.LoadFile(url.c_str());

    tinyxml2::XMLText * textNode;

    tinyxml2::XMLElement * rowXml = xmlDoc.FirstChildElement("board")->FirstChildElement();
    while(rowXml){
        m_dimX++;
        std::vector<int> line;
        int tmp;
        tinyxml2::XMLElement * colXML = rowXml->FirstChildElement();
        while(colXML){
            textNode = colXML->FirstChild()->ToText();
            m_dimY++;
            tmp = atoi(textNode->Value());
            line.push_back(tmp);
            colXML = colXML->NextSiblingElement();
        }
        rowXml = rowXml->NextSiblingElement();
        m_matrix.push_back(line);
    }

    m_dimY = m_dimY / m_dimX;

    std::cout << "DIM X : " << m_dimX << std::endl;
    std::cout << "DIM Y : " << m_dimY << std::endl;
}

// fonction d'aide au debug
void Board::printMatrix(){
    int i = 0, j = 0;
    std::vector< std::vector<int> >::iterator row;
    std::vector<int>::iterator col;
    for (row = m_matrix.begin(); row !=m_matrix.end(); row++) {
        j = 0;
        for (col = row->begin(); col != row->end(); col++) {
            std::cout << m_matrix[i][j] << "-";
            j++;
        }
        i++;
        std::cout << std::endl;
    }
}

void Board::loadCubes(){
    m_cube = new Cube("../../cmake-build-debug/src/itsatrap.exe");
    m_cube->generate();
}

void Board::loadObjects(){
    // Load l'ensemble des pacgommes
    m_pacman->setPosition(m_dimX / 2, m_dimY / 2, -25.0);
}

void Board::movePacman(bool up, bool down, bool right, bool left) {
    float i = m_pacman->getPosition().x;
    float y = m_pacman->getPosition().y;
    if(up){
        i += 1.0;
        if(m_matrix[i][y] != 0){
            m_pacman->setPosition(i, y, -25.0);
        }
    }
    if(down){
        i -= 1.0;
        if(m_matrix[i][y] != 0){
            m_pacman->setPosition(i, y, -25.0);
        }
    }
    if(right){
        ++y;
        if(m_matrix[i][y] != 0){
            m_pacman->setPosition(i, y, -25.0);
        }
    }
    if(left){
        --y;
        if(m_matrix[i][y] != 0){
            m_pacman->setPosition(i, y, -25.0);
        }
    }
}

void Board::draw(){
    int i = 0, j = 0;
    glm::mat4 ProjMatrix;
    glm::mat4 MVMatrix;
    glm::mat4 NormalMatrix;
    std::vector< std::vector<int> >::iterator row;
    std::vector<int>::iterator col;

    ProjMatrix = glm::perspective(glm::radians(70.f), 1.f, 0.1f, 100.f);
    for (row = m_matrix.begin(); row !=m_matrix.end(); row++) {
        j = 0;
        for (col = row->begin(); col != row->end(); col++) {

            if(m_matrix[i][j] == 0){
                MVMatrix = glm::translate(glm::mat4(1.0f), glm::vec3((float)i,(float)j,-25.0)); // Au depart c'était -5 ici
                MVMatrix = glm::rotate(MVMatrix, 0.f, glm::vec3(0,1,0));
                MVMatrix = glm::scale(MVMatrix, glm::vec3(0.5f));
                NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
                m_cube->transform(ProjMatrix, MVMatrix, NormalMatrix);
                m_cube->draw();
            }
            else{
                MVMatrix = glm::translate(glm::mat4(1.0f), glm::vec3((float)i+0.5,(float)j+6.0,-25.0)); // Au depart c'était -5 ici
                MVMatrix = glm::rotate(MVMatrix, 0.f, glm::vec3(0,1,0));
                MVMatrix = glm::scale(MVMatrix, glm::vec3(0.5f));
                NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
                m_pacgomme->transform(ProjMatrix, MVMatrix, NormalMatrix);
                m_pacgomme->draw();
            }
            j++;
        }
        i++;
    }
    MVMatrix = glm::translate(glm::mat4(1.0f), m_pacman->getPosition());
    MVMatrix = glm::rotate(MVMatrix, -90.f, glm::vec3(0,1,0));
    MVMatrix = glm::scale(MVMatrix, glm::vec3(0.01f, 0.01f, 0.01f));
    NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
    m_pacman->transform( ProjMatrix, MVMatrix, NormalMatrix );
    m_pacman->draw();
}

