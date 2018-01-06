#include <GL/glew.h>
#include <SDL/SDL.h>
#include <glimac/SDLWindowManager.hpp>
#include <vector>

#include "../include/GAME/game.hpp"
#include "../include/GAMESTATE/titlestate.hpp"


int main(int argc, char** argv) {

    Game *game = Game::Instance("ITSATRAP");

    game->changeState( TitleState::Instance() );

    glClearColor(0.f,0.f,0.f,1.f);

    // Application loop:
    while (game->isRunning()){
        game->handleEvents();
        game->update();
        game->draw();
    }
    glDeleteTextures(1, &earthMap);
    vbo.deleteVbo();
    //glDeleteVertexArrays(1, &vao);
    vao.deleteVao();

    game->clean();

    return 0;

}