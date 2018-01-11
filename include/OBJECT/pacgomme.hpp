

#ifndef ITSATRAP_PACGOMME_HPP
#define ITSATRAP_PACGOMME_HPP
#include "object.hpp"
#include "item.hpp"

class Pacgomme : public Item {

public:
    struct GommeProgram {
        glimac::Program m_Program;

        GLint uMVPMatrix;
        GLint uMVMatrix;
        GLint uNormalMatrix;
        GLint uTexture;

        GommeProgram(const glimac::FilePath& applicationPath):
                m_Program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                                      applicationPath.dirPath() + "shaders/gom3D.fs.glsl")) {
            uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
            uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
            uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
            uTexture = glGetUniformLocation(m_Program.getGLId(), "uTexture");
        }
    };

    Pacgomme(char* argv);
    ~Pacgomme() = default;

    void sendUniform();
    void draw();

    static int nbPacG;

protected:
    GommeProgram *m_gommeProgram;
};

#endif //ITSATRAP_PACGOMME_HPP
