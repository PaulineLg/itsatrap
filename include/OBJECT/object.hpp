#ifndef ITSATRAP_OBJECT_HPP
#define ITSATRAP_OBJECT_HPP

#define GLEW_STATIC
#include <glimac/FilePath.hpp>
#include <glimac/Program.hpp>
#include <glimac/glm.hpp>
#include <GL/glew.h>

#include "../GLTOOLS/VAO.hpp"
#include "../GLTOOLS/VBO.hpp"
#include "../GLTOOLS/IBO.hpp"

class Object {
public:
    Object() = default; //const glimac::FilePath & applicationPath
    virtual ~Object()= default;
    virtual void setPosition(float x, float y, float z) = 0;
    virtual glm::vec3 getPosition() = 0;

protected:
    int m_id;
    glm::vec3 m_position;
    glimac::Program m_program;
    glm::mat4 m_ProjMatrix;
    glm::mat4 m_MVMatrix;
    glm::mat4 m_NormalMatrix;
    GLuint m_uTexture;
    GLuint m_uKd;
    GLuint m_uKs;
    GLuint m_Shininess;
    GLuint m_uLightPos_vs;
    GLuint m_uLightIntensity;

    glimac::VBO<glimac::ShapeVertex> *m_vbo;
    glimac::VAO *m_vao;
    IBO m_ibo;
};

#endif //ITSATRAP_OBJECT_HPP