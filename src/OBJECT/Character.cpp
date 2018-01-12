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
bool Character::eat(std::list<Item*> &items) {
    std::list<Item*>::iterator it;
    for (it = items.begin(); it != items.end(); it++) {
        if(m_position == (*it)->getPosition()){
            // Supprimer l'élément
            items.erase(it);
            return true; // Retourne true si une pacgomme manger pour update les points
        }
    }
    return false;
}

void Character::transform(glm::mat4 ProjMatrix, glm::mat4 MVMatrix, glm::mat4 NormalMatrix){
    m_ProjMatrix = ProjMatrix;
    m_MVMatrix = MVMatrix;
    m_NormalMatrix = NormalMatrix;
}


