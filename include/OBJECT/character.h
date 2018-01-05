
#ifndef ITSATRAP_CHARACTER_H
#define ITSATRAP_CHARACTER_H


#include "object.h"
#include "item.h"


class Character : public Object {

public:
    Character();
    ~Character();
    void move();
    void changeSuperState();
    void reset();
    void interact(Character chara);
    void eat(item it);


protected:
    bool m_superState;

};

#endif //ITSATRAP_CHARACTER_H
