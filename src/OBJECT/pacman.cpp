//
// Created by Ugo on 06/01/2018.
//

#include "../../include/OBJECT/pacman.hpp"

Pacman::Pacman(char* argv){
    m_id = 1;
    // Chargement du modèle :
    m_filepath = "../../asset/3DModels/3d-model.obj";
   // m_mtlBasePath = "../../asset/3DModels/3d-model.mtl";
    m_geometry.loadOBJ(m_filepath, m_mtlBasePath, false);

    //Initialisation du programme :
    glimac::FilePath applicationPath(argv);
    m_pacProgram = new PacProgram(applicationPath);
}

void Pacman::generate(){

    const glimac::Geometry::Vertex* tmp;
    tmp = m_geometry.getVertexBuffer();
    glimac::ShapeVertex temporaire; // Allow to convert datas for vbo and vao
    for(int i = 0; i < m_geometry.getVertexCount(); i++){
        temporaire.position = tmp[i].m_Position;
        temporaire.normal = tmp[i].m_Normal;
        temporaire.texCoords = tmp[i].m_TexCoords;
        m_vertices.push_back(temporaire);
    }
    m_vbo = new glimac::VBO<glimac::ShapeVertex>(m_vertices);
    m_vbo->bind();
    m_vbo->fill(m_geometry.getVertexCount());
    m_vbo->debind();

    m_ibo.bind();
    m_ibo.fill(m_geometry.getIndexCount()*sizeof(uint32_t) ,m_geometry.getIndexBuffer());
    m_ibo.debind();

    m_vao = new glimac::VAO(0, 1, 2);

    m_vao->bind();
    m_ibo.bind();
    m_vao->activeAttrib();

    m_vbo->bind();
    m_vao->specificAttrib<glimac::ShapeVertex>();
    m_vbo->debind();
    m_vao->debind();
    m_ibo.debind();

    /*m_tex->bind();
    m_tex->send();
    m_tex->debind();*/
}

void Pacman::sendUniform(){
    // Envoi des matrices au GPU :
    glUniformMatrix4fv(m_pacProgram->uMVPMatrix, 1, GL_FALSE, glm::value_ptr(m_ProjMatrix * m_MVMatrix));
    glUniformMatrix4fv(m_pacProgram->uMVMatrix, 1, GL_FALSE, glm::value_ptr(m_MVMatrix));
    glUniformMatrix4fv(m_pacProgram->uNormalMatrix, 1, GL_FALSE, glm::value_ptr(m_NormalMatrix));
    glUniform1i(m_pacProgram->uTexture, 0);
}

void Pacman::draw(){
    m_vao->bind();
    m_pacProgram->m_Program.use();
    sendUniform();
    glActiveTexture(GL_TEXTURE0);
    //m_tex->bind();
    glDrawElements(GL_TRIANGLES, m_geometry.getIndexCount(), GL_UNSIGNED_INT, 0);
    glActiveTexture(GL_TEXTURE0);
    //m_tex->debind();
    m_vao->debind();
}

int Pacman::getNbLife() {
    return m_nbLife;
}

int Pacman::getPoints() {
    return m_points;
}

void Pacman::setPosition(float x, float y, float z){

}

glm::vec3 Pacman::getPosition(){

}
