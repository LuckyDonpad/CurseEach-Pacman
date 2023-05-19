//
// Created by super on 18.05.2023.
//

#include "Player.h"

// Constructor\destructor
Player::Player(float x, float y) {
    this->shape.setPosition(x, y);
    this->initVariables();
    this->initShape();
}

Player::~Player() {

}

// Player initialization
void Player::initVariables() {
    this->movementSpeed = 10.f;
}

void Player::initShape() {
    this->shape.setFillColor(sf::Color::Yellow);
    this->shape.setSize(sf::Vector2f(100.f, 100.f));
}

// Player control and collision

void Player::updateInput() {
    // Keyboard input control
    // Left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->shape.move(-this->movementSpeed, 0.f);
    }
        // Right
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->shape.move(this->movementSpeed, -0.f);
    }
    // Up
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        this->shape.move(0.f, -this->movementSpeed);
    }
        // Down
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->shape.move(-0.f, this->movementSpeed);
    }

}

void Player::windowBondsCollision(const sf::RenderTarget *target) {
    // Borders collision
    sf::FloatRect playerBounds = this->shape.getGlobalBounds();
    // Left
    if (playerBounds.left <= 0.f - this->shape.getSize().x) {
        this->shape.setPosition(target->getSize().x + this->shape.getSize().x - playerBounds.width , playerBounds.top);

    }
        // Right
    else if (playerBounds.left + playerBounds.width >= target->getSize().x + 0.f + this->shape.getSize().x) {
        this->shape.setPosition(0.f - this->shape.getSize().x , playerBounds.top);
    }
    // Up
    if (playerBounds.top  <= 0.f - this->shape.getSize().y) {
        this->shape.setPosition(playerBounds.left, target->getSize().y );
    }
        // Down
    else if (playerBounds.top  >= target->getSize().y ) {
        this->shape.setPosition(playerBounds.left, -playerBounds.height);
    }
}

void Player::update(const sf::RenderTarget *target) {
    // Window bounds collision
    this->windowBondsCollision(target);
    this->updateInput();


}

void Player::render(sf::RenderTarget *target) {
    target->draw(this->shape);
}
