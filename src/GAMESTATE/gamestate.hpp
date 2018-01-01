//
// Created by Ugo on 01/01/2018.
//

#ifndef ITSATRAP_GAMESTATE_HPP
#define ITSATRAP_GAMESTATE_HPP


#include "../GAME/game.hpp"

class GameState {
    public:
        virtual void Init() = 0;
        virtual void Cleanup() = 0;

        virtual void Pause() = 0;
        virtual void Resume() = 0;

        virtual void HandleEvents() = 0;
        virtual void Update() = 0;
        virtual void Draw() = 0;

        /*void ChangeState(Game* game, GameState* state){
            game->ChangeState(state);
        }*/

    protected:
        GameState(){}
};


#endif //ITSATRAP_GAMESTATE_HPP
