//
// Created by Ugo on 01/01/2018.
//

#ifndef ITSATRAP_TITLESTATE_HPP
#define ITSATRAP_TITLESTATE_HPP

#include "gamestate.hpp"

class TitleState : public GameState {

    public:
        void init();
        void cleanup();
        void pause();
        void resume();
        void handleEvents(Game* game);
        void update(Game* game);
        void draw(Game* game);

        static TitleState* Instance(){
            return &s_TitleState;
        }

    protected:
        TitleState() = default;

private:
        static TitleState s_TitleState;
};

#endif //ITSATRAP_TITLESTATE_HPP
