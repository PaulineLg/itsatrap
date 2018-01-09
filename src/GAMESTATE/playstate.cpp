#include <iostream>
#include <glimac/SDLWindowManager.hpp>
#include "../../include/GAMESTATE/playstate.hpp"
#include "../../include/GAMESTATE/titlestate.hpp"

PlayState PlayState::s_PlayState;

void PlayState::init() {
    std::cout << "Init of play state" << std::endl;
}

void PlayState::cleanup() {}

void PlayState::pause() {}

void PlayState::resume() {}

void PlayState::handleEvents(Game* game) {
    SDL_Event event;
    while (game->getWindow()->pollEvent(event)){
        switch (event.type) {

            case SDL_QUIT:
                game->exit();
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {

                    case SDLK_ESCAPE:
                        game->exit();
                        break;

                    case SDLK_b:
                        game->changeState( TitleState::Instance() );
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

void PlayState::update(Game *game) {}

void PlayState::draw(Game *game) {}
