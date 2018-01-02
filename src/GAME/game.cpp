//
// Created by Ugo on 01/01/2018.
//
#define GLEW_STATIC
#include <iostream>
#include <GL/glew.h>
#include <glimac/SDLWindowManager.hpp>

#include "../../include/GAME/game.hpp"
#include "../../include/GAMESTATE/gamestate.hpp"

Game* Game::s_game;

void Game::init(const char* title, uint32_t width, uint32_t height) {

    glimac::SDLWindowManager windowManager(width, height, title);

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    m_window = windowManager;
}

void Game::clean() {
    while ( !m_states.empty() ) {
        m_states.back()->cleanup();
        m_states.pop_back();
    }
    // Resize here if full screen
}

void Game::changeState(GameState *state) {
    std::cout << "entering change state" << std::endl;
    // Erase the current state
    if ( !m_states.empty() ) {
        m_states.back()->cleanup();
        m_states.pop_back();
    }
    // Add the new state to the stack, then initialize.
    std::cout << "lets add the state" << std::endl;
    m_states.push_back(state);
    m_states.back()->init();
    std::cout << "end of change state" << std::endl;
}

void Game::pushState(GameState *state) {
    // Pause the current state
    if ( !m_states.empty() ) {
        m_states.back()->pause();
    }
    // Add the new state to the stack, then initialize.
    m_states.push_back(state);
    m_states.back()->init();
}

void Game::popState() {
    // Erase the current state
    if ( !m_states.empty() ) {
        m_states.back()->cleanup();
        m_states.pop_back();
    }
    // Resume the previous state
    if ( !m_states.empty() ) {
        m_states.back()->resume();
    }
}

void Game::handleEvents() {
    m_states.back()->handleEvents(this);
}

/*
 * Physics engine
 */
void Game::update() {
    m_states.back()->update(this);
}

/*
 * Render engine
 * */
void Game::draw() {
    m_states.back()->draw(this);
}
