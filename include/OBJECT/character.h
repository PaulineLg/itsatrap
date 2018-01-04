
#ifndef ITSATRAP_CHARACTER_H
#define ITSATRAP_CHARACTER_H


#include "object.h"

class Character : public Object {

public:
    Character();
    ~Character();
    void move();
    void changeSuperState();
    void reset();
    int interact(Character chara);
    int eat(item it);


protected:
    bool m_superState;

};

#endif //ITSATRAP_CHARACTER_H
