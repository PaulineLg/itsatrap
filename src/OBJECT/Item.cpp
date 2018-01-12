//
// Created by pauli on 11/01/2018.
//

#include "../../include/OBJECT/Item.hpp"

Item::Item(){

}

void Item::generate(){
    const glimac::Geometry::Vertex* tmp;
    tmp = m_geometry.getVertexBuffer();
    glimac::ShapeVertex temporaire; // Allow to convert datas for vbo and vao
    for(int i = 0; i < m_geometry.getVertexCount(); i++){
        temporaire.position = tmp[i].m_Position;
        temporaire.normal = tmp[i].m_Normal;
        temporaire.texCoords = tmp[i].m_TexCoords;
        m_vertices.push_back(temporaire);
    }
    m_vbo = new VBO<glimac::ShapeVertex>(m_vertices);
    m_vbo->bind();
    m_vbo->fill(m_geometry.getVertexCount());
    m_vbo->debind();

    m_ibo.bind();
    m_ibo.fill(m_geometry.getIndexCount()*sizeof(uint32_t) ,m_geometry.getIndexBuffer());
    m_ibo.debind();

    m_vao = new VAO(0, 1, 2);

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

void Item::setPosition(float x, float y, float z){
    m_position = glm::vec3(x, y, z);
}

glm::vec3 Item::getPosition(){
    return m_position;
}

void Item::transform(glm::mat4 ProjMatrix, glm::mat4 MVMatrix, glm::mat4 NormalMatrix){
    m_ProjMatrix = ProjMatrix;
    m_MVMatrix = MVMatrix;
    m_NormalMatrix = NormalMatrix;
}

void Item::draw(){

}

