//
// Created by Maciej on 10/07/2024.
//

#include "Player.h"

Player::Player(float yPosition, float xPosition)
{
    this->yPosition = yPosition;
    this->xPosition = xPosition;
}

float Player::getX() const {
    return this->xPosition;
}
float Player::getY() const {
    return this->yPosition;
}

void Player::setY(float y) {
    this->yPosition = y;
}

void Player::updatePosition() {
    this->setPosition(sf::Vector2f(this->getX(), this->getY()));
}

void Player::moveUp(const sf::RectangleShape &tile) {
    if (this->getPosition().y - 10 > tile.getPosition().y) {
        this->setY(this->getY() - 10.f);
    }
}

void Player::moveDown(const sf::RectangleShape &tile) {
    if (this->getPosition().y < tile.getPosition().y + tile.getSize().y - this->getSize().y) {
        this->setY(this->getY() + 10.f);
    }
}

