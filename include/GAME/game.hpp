//
// Created by Ugo on 01/01/2018.
//

#ifndef ITSATRAP_GAME_HPP
#define ITSATRAP_GAME_HPP

#include <vector>

class GameState;

class Game {
    public:

        void init(const char* title, uint32_t width = 640, uint32_t height = 480);
        void clean();

        // State manager
        void changeState(GameState* state);
        void pushState(GameState* state);
        void popState();

        // Game loop
        void handleEvents();
        void update();
        void draw();

        bool isRunning() { return m_running; }
        void exit(){ m_running = false; }

        glimac::SDLWindowManager getWindow(){ return m_window; }

        /*static Game* Instance(){
            return &s_game;
        }*/

    protected:
        //Game() = default;

    private:
        //static Game s_game;
        std::vector<GameState*> m_states;
        glimac::SDLWindowManager m_window;
        bool m_running;
};


#endif //ITSATRAP_GAME_HPP
