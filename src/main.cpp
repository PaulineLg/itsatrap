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

#include "../include/GLTOOLS/VBO.h"
#include "../include/GLTOOLS/VAO.h"


using namespace glimac;

int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 800, "GLImac");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    std::unique_ptr<Image> ptrImage = loadImage("D:/IMAC2/S3/SI/OpenGL/TPS/asset/textures/EarthMap.jpg");
    std::unique_ptr<Image> ptrImage2 = loadImage("D:/IMAC2/S3/SI/OpenGL/TPS/asset/textures/MoonMap.jpg");


    FilePath applicationPath(argv[0]);
    Program program = loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                                  applicationPath.dirPath() + "shaders/tex3D.fs.glsl");
    program.use();

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    // Génération des textures terre :
    GLuint earthMap;
    glGenTextures(1, &earthMap);
    glBindTexture(GL_TEXTURE_2D, earthMap);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ptrImage->getWidth() , ptrImage->getHeight(), 0, GL_RGBA, GL_FLOAT, ptrImage->getPixels());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);

    // Texture lune :
    GLuint luneMap;
    glGenTextures(1, &luneMap);
    glBindTexture(GL_TEXTURE_2D, luneMap);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ptrImage2->getWidth() , ptrImage2->getHeight(), 0, GL_RGBA, GL_FLOAT, ptrImage2->getPixels());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);

    // Création de la sphère :
    Sphere sphere(1, 32, 16);

    // Récupérer les coordonnées :
    const ShapeVertex* tmp_vertices;
    tmp_vertices = sphere.getDataPointer();
    std::vector<ShapeVertex> vertices;
    for(int i = 0; i < sphere.getVertexCount(); i++){
        vertices.push_back(tmp_vertices[i]);
    }

    // Création du VBO :
    VBO<ShapeVertex> vbo(vertices);
    vbo.bind();
    /*GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);*/

    // Récupération des coordonées :
    //GLuint nbSommets = sphere.getVertexCount();
    //const glimac::ShapeVertex *vertices = sphere.getDataPointer();

    /*glBufferData(GL_ARRAY_BUFFER, nbSommets*sizeof(ShapeVertex), sphere.getDataPointer(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);*/

    vbo.fill();
    vbo.debind();

    // Création du VAO :
    //GLuint vao;
    /*const GLuint VERTEX_ATTR_POSITION = 0;
    const GLuint VERTEX_ATTR_NORMAL = 1;
    const GLuint VERTEX_ATTR_TEX= 2;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
    glEnableVertexAttribArray(VERTEX_ATTR_TEX);*/

    VAO vao(0,1,2);
    vao.activeAttrib();

    //glBindBuffer(GL_ARRAY_BUFFER, vbo);
    vbo.bind();
    /*glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*) offsetof(ShapeVertex, position));
    glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*) offsetof(ShapeVertex, normal));
    glVertexAttribPointer(VERTEX_ATTR_TEX, 2, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*) offsetof(ShapeVertex, texCoords));*/
    vao.specificAttrib<ShapeVertex>();

    //glBindBuffer(GL_ARRAY_BUFFER, 0);
    vbo.debind();

    //glBindVertexArray(0);
    vao.debind();

    // Récupération des locations des variables uniformes :
    GLint loc1 = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    GLint loc2 = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    GLint loc3 = glGetUniformLocation(program.getGLId(), "uNormalMatrix");

    GLint locTex = glGetUniformLocation(program.getGLId(), "uTexture");

    glEnable(GL_DEPTH_TEST);

    //Créez 3 variables de type glm::mat4: ProjMatrix, MVMatrix et NormalMatrix.
    glm::mat4 ProjMatrix;
    glm::mat4 MVMatrix;
    glm::mat4 NormalMatrix;


    /* END INITIALIZATION CODE */

    std::vector<glm::vec3> vecAxisRotation;
    for(int i = 0; i < 32; ++i){
        vecAxisRotation.push_back(glm::sphericalRand(1.5f));
    }


    // Application loop:
    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //glBindVertexArray(vao);
        vao.bind();

        ProjMatrix = glm::perspective(glm::radians(70.f), 1.f, 0.1f, 100.f);
        MVMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0,0.0,-5.0)); // Translation
        MVMatrix = glm::rotate(MVMatrix, windowManager.getTime(), glm::vec3(0,1,0));
        NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

        // Envoi des matrices au GPU :
        glUniformMatrix4fv(loc1, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));
        glUniformMatrix4fv(loc2, 1, GL_FALSE, glm::value_ptr(MVMatrix));
        glUniformMatrix4fv(loc3, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

        glUniform1i(locTex, 0);

        glBindTexture(GL_TEXTURE_2D, earthMap);
        glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());
        glBindTexture(GL_TEXTURE_2D, 0);

        // Dessin de la lune :

        for(int i = 0; i < 32 ; ++i){
            MVMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0,0.0,-5.0)); // Translation
            MVMatrix = glm::rotate(MVMatrix, windowManager.getTime()/10, glm::vec3(0,1,0)); // Translation * Rotation
            MVMatrix = glm::translate(MVMatrix, vecAxisRotation[i]); // Translation * Rotation * Translation
            MVMatrix = glm::scale(MVMatrix, glm::vec3(0.2, 0.2, 0.2)); // Translation * Rotation * Translation * Scale

            NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

            glUniformMatrix4fv(loc1, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));
            glUniformMatrix4fv(loc2, 1, GL_FALSE, glm::value_ptr(MVMatrix));
            glUniformMatrix4fv(loc3, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

            glBindTexture(GL_TEXTURE_2D, luneMap);
            glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());
            glBindTexture(GL_TEXTURE_2D, 0);
        }


        //glBindVertexArray(0);
        vao.debind();


        // Update the display
        windowManager.swapBuffers();
    }
    glDeleteTextures(1, &earthMap);
    vbo.deleteVbo();
    vao.deleteVao();

    return EXIT_SUCCESS;
}
