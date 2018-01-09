#include <iostream>
#include <glimac/SDLWindowManager.hpp>

#include "../../include/GAMESTATE/titlestate.hpp"
#include "../../include/GAMESTATE/playstate.hpp"

TitleState TitleState::s_TitleState;

void TitleState::init() {
    std::cout << "Init of title state" << std::endl;
}

void TitleState::cleanup() {}

void TitleState::pause() {}

void TitleState::resume() {}

void TitleState::handleEvents(Game* game) {
    SDL_Event event;
    if (game->getWindow()->pollEvent(event)){
        switch (event.type) {

            case SDL_QUIT:
                game->exit();
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {

                    case SDLK_SPACE:
                        game->changeState( PlayState::Instance() );
                        break;

                    case SDLK_ESCAPE:
                        game->exit();
                        break;

                    default:
                        break;
                }
                break;

            default:
                break;
        }
    }
}

void TitleState::update(Game *game) {}

void TitleState::draw(Game *game) {}
