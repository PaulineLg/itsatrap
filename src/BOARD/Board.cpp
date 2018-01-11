//
// Created by pauli on 03/01/2018.
//

#include "../../include/BOARD/Board.hpp"
#include "../../include/GLTOOLS/TrackBallCamera.hpp"

namespace glimac{
    Board::Board(){
        m_dimX = 0;
        m_dimY = 0;
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
        m_cube = new glimac::Cube("../../cmake-build-debug/src/itsatrap.exe");
        m_cube->generate();
    }

    void Board::draw(){
        int i = 0, j = 0, x = 0, y = 0;
        glm::mat4 ProjMatrix;
        glm::mat4 MVMatrix;
        glm::mat4 NormalMatrix;
        TrackballCamera Camera;
        std::vector< std::vector<int> >::iterator row;
        std::vector<int>::iterator col;
        for (row = m_matrix.begin(); row !=m_matrix.end(); row++) {
            j = 0;
            for (col = row->begin(); col != row->end(); col++) {
                // Calcul des matrice

                // Transform le cube
                // Dessine le cube
                if(m_matrix[i][j] == 0){
                   /* if(i < m_dimX / 2){
                        x = -i;
                        std::cout << "COUCOU MDR" << std::endl;
                    }
                    else{
                        x = i;
                    }
                    if(j < m_dimY / 2){
                        y = -j;
                    }
                    else{
                        y = j;

                    }*/
                    ProjMatrix = glm::perspective(glm::radians(70.f), 1.f, 0.1f, 100.f);
                    MVMatrix = glm::translate(glm::mat4(1.0f), glm::vec3((float)i,(float)j,-5.0)); // Au depart c'était -5 ici
                    MVMatrix = glm::rotate(MVMatrix, 0.f, glm::vec3(0,1,0));
                    MVMatrix = glm::scale(MVMatrix, glm::vec3(0.5f));
                    NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
                    glm::mat4 ViewMatrix = Camera.getViewMatrix();

                    MVMatrix = ViewMatrix * MVMatrix;
                    m_cube->transform(ProjMatrix, MVMatrix, NormalMatrix);
                    m_cube->draw();

                }
                j++;
            }
            i++;
            std::cout << std::endl;

            /*ProjMatrix = glm::perspective(glm::radians(70.f), 1.f, 0.1f, 100.f);
            MVMatrix = glm::translate(glm::mat4(1.0f), glm::vec3((float)i,(float)j,-5.0));
            MVMatrix = glm::rotate(MVMatrix, 0.f, glm::vec3(0,1,0));
            MVMatrix = glm::scale(MVMatrix, glm::vec3(0.01f));
            NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
            m_cube->transform(ProjMatrix, MVMatrix, NormalMatrix);
            m_cube->draw();*/
        }
    }
}
