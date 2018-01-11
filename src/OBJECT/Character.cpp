//
// Created by pauli on 10/01/2018.
//

#include "../../include/OBJECT/Character.hpp"

Character::Character(){
    //
}

void Character::move(){

}
void Character::changeSuperState(){

}
void Character::reset(){

}
void Character::interact(Character* chara){

}
void Character::eat(Item* it) {

}

void Character::transform(glm::mat4 ProjMatrix, glm::mat4 MVMatrix, glm::mat4 NormalMatrix){
    m_ProjMatrix = ProjMatrix;
    m_MVMatrix = MVMatrix;
    m_NormalMatrix = NormalMatrix;
}


