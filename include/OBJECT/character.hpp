
#ifndef ITSATRAP_CHARACTER_HPP
#define ITSATRAP_CHARACTER_HPP


#include "object.hpp"
#include "item.hpp"


class Character : public Object {

public:
    Character();
    ~Character() = default;
    virtual void move() = 0;
    virtual void changeSuperState() = 0;
    virtual void reset() = 0;
    virtual void interact(Character* chara) = 0;
    virtual void eat(Item* it) = 0;


protected:
    bool m_superState;

};

#endif //ITSATRAP_CHARACTER_HPP
