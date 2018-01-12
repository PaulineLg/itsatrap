
#ifndef ITSATRAP_CHARACTER_HPP
#define ITSATRAP_CHARACTER_HPP


#include "object.hpp"
#include "item.hpp"

#include <list>


class Character : public Object {

public:
    Character();
    ~Character() = default;
    void move();
    void changeSuperState();
    void reset();
    void interact(Character* chara);
    bool eat(std::list<Item*> &items);
    void transform(glm::mat4 ProjMatrix, glm::mat4 MVMatrix, glm::mat4 NormalMatrix);


protected:
    bool m_superState;

};

#endif //ITSATRAP_CHARACTER_HPP
