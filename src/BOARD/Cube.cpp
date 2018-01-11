//
// Created by pauli on 06/01/2018.
//

#include "../../include/BOARD/Cube.hpp"


Cube::Cube(char* argv){
    m_filepath = "../../asset/3DModels/cube.obj";
    m_mtlBasePath = "../../asset/3DModels/cube.mtl";
    m_geometry.loadOBJ(m_filepath, m_mtlBasePath, false);
    //std::cout << argv[0] << std::endl;
    glimac::FilePath applicationPath(argv);
    m_wallProgram = new WallProgram(applicationPath);
    m_tex = new Texture("../../asset/textures/brick.jpg");
    std::cout << "Identifiant : " << m_wallProgram->m_Program.getGLId() << std::endl;
}

void Cube::generate(){
    std::cout << "cube.generate()"<< std::endl;
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

    m_tex->bind();
    m_tex->send();
    m_tex->debind();

     // Fonction à mettre dans le draw du playstate
}

void Cube::transform(glm::mat4 ProjMatrix, glm::mat4 MVMatrix, glm::mat4 NormalMatrix){
    this->m_ProjMatrix = ProjMatrix;
    this->m_MVMatrix = MVMatrix;
    this->m_NormalMatrix = NormalMatrix;
}

void Cube::sendUniform(){
    // Envoi des matrices au GPU :
    glUniformMatrix4fv(m_wallProgram->uMVPMatrix, 1, GL_FALSE, glm::value_ptr(m_ProjMatrix * m_MVMatrix));
    glUniformMatrix4fv(m_wallProgram->uMVMatrix, 1, GL_FALSE, glm::value_ptr(m_MVMatrix));
    glUniformMatrix4fv(m_wallProgram->uNormalMatrix, 1, GL_FALSE, glm::value_ptr(m_NormalMatrix));
    glUniform1i(m_wallProgram->uTexture, 0);
}

void Cube::draw(){
    m_vao->bind();
    m_wallProgram->m_Program.use();
    sendUniform();
    glActiveTexture(GL_TEXTURE0);
    m_tex->bind();
    glDrawElements(GL_TRIANGLES, m_geometry.getIndexCount(), GL_UNSIGNED_INT, 0);
    glActiveTexture(GL_TEXTURE0);
    m_tex->debind();
    m_vao->debind();
}


