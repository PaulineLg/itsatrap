
#ifndef ITSATRAP_ITEM_HPP
#define ITSATRAP_ITEM_HPP


#include "object.hpp"
#include "../../glimac/include/glimac/Geometry.hpp"


class Item : public Object {

public:
    Item();
    ~Item() = default;

    void generate();
    void setPosition(float x, float y, float z);
    glm::vec3 getPosition();
    void transform(glm::mat4 ProjMatrix, glm::mat4 MVMatrix, glm::mat4 NormalMatrix);

protected:
    glimac::FilePath m_filepath;
    glimac::FilePath m_mtlBasePath;
    glimac::Geometry m_geometry;
    std::vector<glimac::ShapeVertex> m_vertices;
};


#endif //ITSATRAP_ITEM_HPP
