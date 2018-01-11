

#ifndef ITSATRAP_PACMAN_HPP
#define ITSATRAP_PACMAN_HPP

#include "object.hpp"
#include "character.hpp"
#include "../../glimac/include/glimac/Sphere.hpp"
#include "../../glimac/include/glimac/Program.hpp"
#include "../../glimac/include/glimac/Geometry.hpp"


class Pacman : public Character {

public:
    struct PacProgram {
        glimac::Program m_Program;

        GLint uMVPMatrix;
        GLint uMVMatrix;
        GLint uNormalMatrix;
        GLint uTexture;

        PacProgram(const glimac::FilePath& applicationPath):
                m_Program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                                      applicationPath.dirPath() + "shaders/tex3D.fs.glsl")) {
            uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
            uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
            uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
            uTexture = glGetUniformLocation(m_Program.getGLId(), "uTexture");
        }
    };

    Pacman(char* argv);
    ~Pacman();

    int getNbLife();
    int getPoints();

    glm::vec3 getPosition();
    void setPosition(float x, float y, float z);

    void generate();
    void sendUniform();
    void draw();


private:
    glimac::FilePath m_filepath;
    glimac::FilePath m_mtlBasePath;
    glimac::Geometry m_geometry;
    int m_nbLife = 3;
    int m_points = 0;
    PacProgram *m_pacProgram;
    std::vector<glimac::ShapeVertex> m_vertices;
};


#endif //ITSATRAP_PACMAN_HPP
