#ifndef ITSATRAP_PLAYSTATE_HPP
#define ITSATRAP_PLAYSTATE_HPP

#include "gamestate.hpp"
#include "../BOARD/Cube.hpp"

class PlayState : public GameState {
    public:
        void init();
        void cleanup();
        void pause();
        void resume();
        void handleEvents(Game* game);
        void update(Game* game);
        void draw(Game* game);

        static PlayState* Instance(){
            return &s_PlayState;
        }

    protected:
        PlayState() = default;

    private:
        static PlayState s_PlayState;
        glimac::Cube* m_cube;

};


#endif //ITSATRAP_PLAYSTATE_HPP
