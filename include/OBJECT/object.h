#define GLEW_STATIC
#include <iostream>
#include <fstream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <memory>
#include <SDL/SDL.h>
#include <glimac/Sphere.hpp>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Image.hpp>
#include <glimac/SDLWindowManager.hpp>


using namespace glimac;


class Object:

{
public:

    ~Object();
    Object(const FilePath & applicationPath);
    virtual void setPosition(float x, float y, float z);
    virtual gml::vec3 getPosition();



protected:
    int m_id;
    glm::vec3 m_position;
    Program m_program;
    GLint m_uMVPMatrix;
    GLint m_uMVMatrix;
    GLint m_uNormalMatrix;
    GLint m_uTexture;
    GLint m_uKd;
    GLint m_uKs;
    GLint m_Shininess;
    GLint m_uLightPos_vs;
    GLint m_uLightIntensity;


};




#endif //PROJECT_OBJECT_H
