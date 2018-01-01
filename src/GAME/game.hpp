//
// Created by Ugo on 01/01/2018.
//

#ifndef ITSATRAP_GAME_HPP
#define ITSATRAP_GAME_HPP

#include <vector>
#include "../GAMESTATE/gamestate.hpp"

class Game {
    public:
        void Init(int width = 640, int hei);
        void Clean();

        // State manager
        void ChangeState(GameState* state);
        void PushState(GameState* state);
        void PopState();

        // Game loop
        void HandleEvents();
        void Update();
        void Draw();

        bool isRunning() { return m_running; }
        void Exit(){ m_running = false; }

    private:
        std::vector<GameState*> m_states;
        bool m_running;
};


#endif //ITSATRAP_GAME_HPP
