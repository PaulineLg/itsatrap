#define GLEW_STATIC
#include <iostream>
#include <fstream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <memory>
#include <SDL/SDL.h>
#include <glimac/Sphere.hpp>
#include <glimac/Program.hpp>
#include <glimac/Image.hpp>
#include <glimac/SDLWindowManager.hpp>
#include <vector>


class Cube{
    public :
        Cube();
        ~Cube();

        create();
        print();

    private:
    int cube_triangleCount;
    /*int cube_triangleList[];
    float cube_uvs[];
    float cube_vertices[];
    float cube_normals[];*/
    std::vector<int> cube_triangleList;
    std::vector<float> cube_uvs;
    std::vector<float> cube_vertices;
    std::vector<float> cube_normals;
    GLuint vbo[4];
    GLuint vao;
        // Texture tex;


};