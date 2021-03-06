#include <GL/glew.h>
#include <SDL/SDL.h>
#include <glimac/SDLWindowManager.hpp>

#include "../include/GAME/game.hpp"
#include "../include/GAMESTATE/titlestate.hpp"


int main(int argc, char** argv) {
    Game *game = Game::Instance("ITSATRAP");

    game->changeState( TitleState::Instance() );

    glClearColor(0.2,0.2,0.2,0.0);

    glEnable(GL_DEPTH_TEST);

    // Application loop:
    while (game->isRunning()){
        game->handleEvents();
        game->update();
        game->draw();
    }

    game->clean();

    Game::kill();

    return 0;

}