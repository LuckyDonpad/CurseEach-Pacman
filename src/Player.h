//
// Created by super on 18.05.2023.
//

#ifndef CMAKESFMLPROJECT_PLAYER_H
#define CMAKESFMLPROJECT_PLAYER_H

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

class Player {
private:
    sf::RectangleShape shape;
    float movementSpeed = 10.f;

    void initVariables();

    void initShape();

public:
    // Constructor\destructor
    explicit Player(float x = 0.f, float y = 0.f);

    virtual ~Player();

    void updateInput();
    void windowBondsCollision(const sf::RenderTarget* target);
    void update(const sf::RenderTarget* target);

    void render(sf::RenderTarget *target);

};


#endif //CMAKESFMLPROJECT_PLAYER_H
