//
// Created by pauli on 03/01/2018.
//

#include "../../include/BOARD/Board.hpp"

Board::Board(){
    m_dimX = 0;
    m_dimY = 0;
    m_pacman = new Pacman("../../cmake-build-debug/src/itsatrap.exe");
    m_pacman->generate();
    m_camera.rotateLeft(90.0);
}

Board::~Board(){
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
    m_pacman->setPosition(-2,m_dimX / m_dimY / 2, -25.0);

    // Load pacgommes:
    int i = 0, j = 0;
    std::vector< std::vector<int> >::iterator row;
    std::vector<int>::iterator col;
    for (row = m_matrix.begin(); row !=m_matrix.end(); row++) {
        j = 0;
        for (col = row->begin(); col != row->end(); col++) {
            if(m_matrix[i][j] != 0){
                Pacgomme * p = new Pacgomme("../../cmake-build-debug/src/itsatrap.exe");
                p->setPosition((float)j, (float)i, -20.0);
                p->generate();
                m_pacgomme.push_back(p);
            }
            j++;
        }
        i++;
    }

}

void Board::movePacman(bool up, bool down, bool right, bool left) {
    float i = m_pacman->getPosition().x;
    float y = m_pacman->getPosition().y;
    if(up){
        y += 1.0;
        if(m_matrix[i][y] != 0){
            m_pacman->setPosition(i, y, -20.0);
        }
    }
    if(down){
        y -= 1.0;
        if(m_matrix[i][y] != 0){
            m_pacman->setPosition(i, y, -20.0);
        }
    }
    if(right){
        ++i;
        if(m_matrix[i][y] != 0){
            m_pacman->setPosition(i, y, -20.0);
        }
    }
    if(left){
        --i;
        if(m_matrix[i][y] != 0){
            m_pacman->setPosition(i, y, -20.0);
        }
    }
}

    void Board::draw(){
        int i = 0, j = 0, x = 0, y = 0;
        glm::mat4 ProjMatrix;
        glm::mat4 MVMatrix;
        glm::mat4 NormalMatrix;

        glm::mat4 ViewMatrix = m_camera.getViewMatrix();

        std::vector< std::vector<int> >::iterator row;
        std::vector<int>::iterator col;


    ProjMatrix = glm::perspective(glm::radians(70.f), 1.f, 0.1f, 100.f);
    for (row = m_matrix.begin(); row !=m_matrix.end(); row++) {

        j = 0;
        for (col = row->begin(); col != row->end(); col++) {
            if(m_matrix[i][j] == 0){
                MVMatrix = glm::translate(glm::mat4(1.0f), glm::vec3((float)j,(float)i,-20.0)); // Au depart c'était -5 ici
                MVMatrix = glm::rotate(MVMatrix, 0.f, glm::vec3(0,1,0));
                MVMatrix = glm::scale(MVMatrix, glm::vec3(0.5f));
                MVMatrix = MVMatrix * ViewMatrix;
                NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
                m_cube->transform(ProjMatrix, MVMatrix, NormalMatrix);
                m_cube->draw();
            }
            j++;
        }
        i++;
    }
        // Draw PACMAN
    MVMatrix = glm::translate(glm::mat4(1.0f), m_pacman->getPosition());
    MVMatrix = glm::rotate(MVMatrix, -90.f, glm::vec3(0,1,0));
    MVMatrix = glm::scale(MVMatrix, glm::vec3(0.005f, 0.005f, 0.005f));
    MVMatrix = MVMatrix * ViewMatrix;
    NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
    m_pacman->transform( ProjMatrix, MVMatrix, NormalMatrix );
    m_pacman->draw();

        // Draw Pacgommes :
    std::list<Pacgomme*>::iterator it;
    for (it = m_pacgomme.begin(); it != m_pacgomme.end(); it++) {
        MVMatrix = glm::translate(glm::mat4(1.0f), (*it)->getPosition()); // Au depart c'était -5 ici
        MVMatrix = glm::rotate(MVMatrix, 0.f, glm::vec3(0,1,0));
        MVMatrix = glm::scale(MVMatrix, glm::vec3(0.2f));
        MVMatrix = MVMatrix * ViewMatrix;
        NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
        (*it)->transform(ProjMatrix, MVMatrix, NormalMatrix);
        (*it)->draw();
    }

}

