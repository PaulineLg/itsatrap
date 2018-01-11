//
// Created by pauli on 06/01/2018.
//

#ifndef ITSATRAP_CUBE_HPP
#define ITSATRAP_CUBE_HPP

#define GLEW_STATIC
#include "../../glimac/include/glimac/FilePath.hpp"
#include "../../glimac/include/glimac/Geometry.hpp"
#include "../../glimac/include/glimac/common.hpp"
#include "../../glimac/include/glimac/Program.hpp"
#include "../GLTOOLS/VAO.hpp"
#include "../GLTOOLS/VBO.hpp"
#include "../GLTOOLS/IBO.hpp"
#include "../GLTOOLS/Texture.hpp"

class Cube{
    public:
    // Struct for Cube Shaders
    struct WallProgram {
        glimac::Program m_Program;

        GLint uMVPMatrix;
        GLint uMVMatrix;
        GLint uNormalMatrix;
        GLint uTexture;

        WallProgram(const glimac::FilePath& applicationPath):
                m_Program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                                      applicationPath.dirPath() + "shaders/cube3D.fs.glsl")) {
            uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
            uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
            uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
            uTexture = glGetUniformLocation(m_Program.getGLId(), "uTexture");
        }
    };
        Cube(char* argv);
        ~Cube() = default;

        void generate();
        void draw();
        void transform(glm::mat4 ProjMatrix, glm::mat4 MVMatrix, glm::mat4 NormalMatrix);
        void sendUniform();
    private :
        glimac::FilePath m_filepath;
        glimac::FilePath m_mtlBasePath;
        glimac::Geometry m_geometry;
        VBO<glimac::ShapeVertex> *m_vbo;
        VAO *m_vao;
        IBO m_ibo;
        std::vector<glimac::ShapeVertex> m_vertices;
        WallProgram *m_wallProgram;
        glm::mat4 m_ProjMatrix;
        glm::mat4 m_MVMatrix;
        glm::mat4 m_NormalMatrix;
        Texture *m_tex;
};


#endif //ITSATRAP_CUBE_HPP
