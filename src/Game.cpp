//
// Created by super on 18.05.2023.
//

#include "Game.h"

// private functions

void Game::initVariables() {
    // variables
    // window
    this->window = nullptr;
}

void Game::initEnemies() {
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Green);
    this->enemy.setOutlineThickness(3.f);
}


void Game::initWindow() {
    this->videoMode.height = 800;
    this->videoMode.width = 750;
    this->window = new sf::RenderWindow(this->videoMode,
                                        "Pacman",
                                        sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

// constructors / destructors

Game::Game() {
    this->initVariables();
    this->initWindow();
    this->initEnemies();
}

Game::~Game() {
    delete this->window;
}


//accessors
const bool Game::running() const {
    return this->window->isOpen();
}


//Functions

void Game::pollEvents() {
    //Event polling
    while (this->window->pollEvent(this->ev)) {
        switch (this->ev.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            default:
                break;
        }
    }
}

void Game::update() {
    this->pollEvents();
    this->player.update(this->window);
}

void Game::render() {
    /*
     - clear old frame
     - render objects
     - display frame in window

     Renders the game objects.
     */

    this->window->clear();

    //Draw game objects
    this->player.render(this->window);
    //this->window->draw(this->enemy);
    this->window->display();
}







