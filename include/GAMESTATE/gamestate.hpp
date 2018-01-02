//
// Created by Ugo on 01/01/2018.
//

#ifndef ITSATRAP_GAMESTATE_HPP
#define ITSATRAP_GAMESTATE_HPP


#include "../GAME/game.hpp"

class GameState {
    public:
        virtual void init() = 0;
        virtual void cleanup() = 0;

        virtual void pause() = 0;
        virtual void resume() = 0;

        virtual void handleEvents(Game* game) = 0;
        virtual void update(Game* game) = 0;
        virtual void draw(Game* game) = 0;

        void changeState(Game* game, GameState* state){
            game->changeState(state);
        }

    protected:
        GameState(){}
};


#endif //ITSATRAP_GAMESTATE_HPP
