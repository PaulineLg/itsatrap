//
// Created by pauli on 05/01/2018.
//

#include "../../include/BOARD/Cylinder.hpp"

namespace glimac{
    Cylinder::Cylinder(){
        filepath = "../../asset/3DModels/Wood.obj";
        mtlBasePath = "../../asset/3DModels/Wood.mtl";
        geometry.loadOBJ(filepath, mtlBasePath, true);

    }
    Cylinder::~Cylinder(){

    }

    void Cylinder::generate(){
        // Create VBO ;
            // Get the vertices;
        const Geometry::Vertex* tmp;
        tmp = geometry.getVertexBuffer();
        ShapeVertex temporaire;
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

        vbo->bind();
        vao->specificAttrib<ShapeVertex>();
        vbo->debind();
        vao->debind();
    }
    void Cylinder::draw(){
        vao->bind();
        glDrawArrays(GL_TRIANGLES,0,geometry.getVertexCount());
        vao->debind();
    }
}


