//
// Created by pauli on 06/01/2018.
//

#include "../../include/BOARD/Cube.hpp"


namespace glimac{

    Cube::Cube(char** argv){
        filepath = "../../asset/3DModels/Crate1.obj";
        mtlBasePath = "../../asset/3DModels/Crate1.mtl";
        geometry.loadOBJ(filepath, mtlBasePath, false);
        FilePath applicationPath(argv[0]);
        wallProgram = new WallProgram(applicationPath);
        tex = new Texture("../../asset/textures/cubeMap.jpg");
        std::cout << "Identifiant : " << wallProgram->m_Program.getGLId() << std::endl;
    }

    void Cube::generate(){
        std::cout << "cube.generate()"<< std::endl;
        const Geometry::Vertex* tmp;
        tmp = geometry.getVertexBuffer();
        ShapeVertex temporaire; // Allow to convert datas for vbo and vao
        for(int i = 0; i < geometry.getVertexCount(); i++){
            temporaire.position = tmp[i].m_Position;
            temporaire.normal = tmp[i].m_Normal;
            temporaire.texCoords = tmp[i].m_TexCoords;
            vertices.push_back(temporaire);
        }

        vbo = new VBO<ShapeVertex>(vertices);
        vbo->bind();
        vbo->fill();
        vbo->debind();
        vao = new VAO(0, 1, 2);

        vao->activeAttrib();
        vao->bind();
        vbo->bind();
        vao->specificAttrib<ShapeVertex>();
        vbo->debind();
        vao->debind();

        tex->bind();
        tex->send();
        tex->debind();

        glEnable(GL_DEPTH_TEST); // Fonction à mettre dans le draw du playstate
    }

    void Cube::transform(){
        ProjMatrix = glm::perspective(glm::radians(70.f), 1.f, 0.1f, 100.f);
        MVMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0,0.0,-5.0));
        MVMatrix = glm::rotate(MVMatrix, 1.f, glm::vec3(0,1,0));
        NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
    }

    void Cube::sendUniform(){
        // Envoi des matrices au GPU :
        glUniformMatrix4fv(wallProgram->uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));
        glUniformMatrix4fv(wallProgram->uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
        glUniformMatrix4fv(wallProgram->uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));
        glUniform1i(wallProgram->uTexture, 0);
    }

    void Cube::draw(){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Fonction à mettre dans le draw du playstate
        //glEnableClientState(GL_VERTEX_ARRAY); // Si ça sert à rien on enlève
        vao->bind();
        transform();
        wallProgram->m_Program.use();
        sendUniform();
        glActiveTexture(GL_TEXTURE0);
        tex->bind();
        glDrawArrays(GL_TRIANGLES,0,geometry.getVertexCount());
        glActiveTexture(GL_TEXTURE0);
        tex->debind();
        vao->debind();
    }
}

