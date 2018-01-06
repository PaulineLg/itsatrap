#ifndef ITSATRAP_OBJECT_HPP
#define ITSATRAP_OBJECT_HPP

#include <glimac/FilePath.hpp>
#include <glimac/Program.hpp>
#include <glimac/glm.hpp>
#include <GL/glew.h>

class Object

{
public:


    Object(const glimac::FilePath & applicationPath);
    ~Object() = default;
    virtual void setPosition(float x, float y, float z) = 0;
    virtual glm::vec3 getPosition() = 0;



protected:
    int m_id;
    glm::vec3 m_position;
    glimac::Program m_program;
    GLuint m_uMVPMatrix;
    GLuint m_uMVMatrix;
    GLuint m_uNormalMatrix;
    GLuint m_uTexture;
    GLuint m_uKd;
    GLuint m_uKs;
    GLuint m_Shininess;
    GLuint m_uLightPos_vs;
    GLuint m_uLightIntensity;


};

#endif //ITSATRAP_OBJECT_HPP