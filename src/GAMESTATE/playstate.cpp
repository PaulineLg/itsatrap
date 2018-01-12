#include <iostream>
#include <glimac/SDLWindowManager.hpp>
#include "../../include/GAMESTATE/playstate.hpp"
#include "../../include/GAMESTATE/titlestate.hpp"

PlayState PlayState::s_PlayState;

void PlayState::init() {
    std::cout << "Init of play state" << std::endl;
    m_board = new Board();
    m_board->loadMatrix();
    m_board->loadObjects();
    m_board->loadCubes();
}

void PlayState::cleanup() {
    delete m_board;
}

void PlayState::pause() {}

void PlayState::resume() {}

void PlayState::handleEvents(Game* game) {
    SDL_Event event;
    bool pac_up = false;
    bool pac_down = false;
    bool pac_right = false;
    bool pac_left = false;
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

                    case SDLK_z :
                        pac_up = true;
                        break;
                    case SDLK_q:
                        pac_left = true;
                        break;

                    case SDLK_d:
                        pac_right = true;
                        break;

                    case SDLK_s:
                        pac_down = true;
                        break;

                    default:
                        break;
                }
                break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym) {
                    case SDLK_z :
                        pac_up = false;
                    std:: cout << "up" << std::endl;
                        break;
                    case SDLK_q:
                        pac_left = false;
                        std:: cout << "left" << std::endl;
                        break;

                    case SDLK_d:
                        pac_right = false;
                        std:: cout << "right" << std::endl;
                        break;

                    case SDLK_s:
                        pac_down = false;
                        std:: cout << "down" << std::endl;
                        break;

                    default:
                        break;
                }
                break;


            default:
                break;
        }
        m_board->movePacman(pac_up, pac_down, pac_right, pac_left);
    }
}

void PlayState::update(Game *game) {}

void PlayState::draw(Game *game) {
    m_board->draw();

}
