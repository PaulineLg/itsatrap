//
// Created by pauli on 05/01/2018.
//

#ifndef ITSATRAP_CYLINDER_H
#define ITSATRAP_CYLINDER_H
#define GLEW_STATIC
#include "../../glimac/include/glimac/FilePath.hpp"
#include "../../glimac/include/glimac/Geometry.hpp"
#include "../../glimac/include/glimac/common.hpp"
#include "../../include/GLTOOLS/VAO.h"
#include "../../include/GLTOOLS/VBO.h"

namespace glimac{
    class Cylinder{
        public:
            Cylinder();
            ~Cylinder();

            void generate();
            void draw();
        private :
            FilePath filepath;
            FilePath mtlBasePath;
            Geometry geometry;
            VBO<ShapeVertex> *vbo;
            VAO *vao;
            std::vector<ShapeVertex> vertices;
    };
}

#endif //ITSATRAP_CYLINDER_H
