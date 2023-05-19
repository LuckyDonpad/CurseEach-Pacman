//
// Created by super on 18.05.2023.
//
#ifndef CMAKESFMLPROJECT_GAME_H
#define CMAKESFMLPROJECT_GAME_H

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "Player.h"

/*
 Class, acts like game engine.
 Wrapper Class.
 */
class Game {
private:
    // variables
    // window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;
    // game objects
    sf::RectangleShape enemy;
    Player player;

    // private functions
    void initVariables();
    void initWindow();
    void initEnemies();

public:
    // constructors / destructors
    Game();
    virtual ~Game();

    //accessors
    const bool running() const;

    // Functions
    void pollEvents();
    void update();
    void render();
};


#endif //CMAKESFMLPROJECT_GAME_H
