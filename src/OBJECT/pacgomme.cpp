
#include "../../include/OBJECT/pacgomme.hpp"

int Pacgomme::nbPacG = 0;
Pacgomme::Pacgomme(char* argv) {
    // Chargement du modèle :
    m_filepath = "../../asset/3DModels/sphere.obj";
    m_geometry.loadOBJ(m_filepath, m_mtlBasePath, false);

    //Initialisation du programme :
    glimac::FilePath applicationPath(argv);
    m_gommeProgram = new GommeProgram(applicationPath);
    nbPacG++;
}

void Pacgomme::sendUniform(){
    // Envoi des matrices au GPU :
    glUniformMatrix4fv(m_gommeProgram->uMVPMatrix, 1, GL_FALSE, glm::value_ptr(m_ProjMatrix * m_MVMatrix));
    glUniformMatrix4fv(m_gommeProgram->uMVMatrix, 1, GL_FALSE, glm::value_ptr(m_MVMatrix));
    glUniformMatrix4fv(m_gommeProgram->uNormalMatrix, 1, GL_FALSE, glm::value_ptr(m_NormalMatrix));
    glUniform1i(m_gommeProgram->uTexture, 0);
}

void Pacgomme::draw(){
    m_vao->bind();
    m_gommeProgram->m_Program.use();
    sendUniform();
    glActiveTexture(GL_TEXTURE0);
    //m_tex->bind();
    glDrawElements(GL_TRIANGLES, m_geometry.getIndexCount(), GL_UNSIGNED_INT, 0);
    glActiveTexture(GL_TEXTURE0);
    //m_tex->debind();
    m_vao->debind();
}



