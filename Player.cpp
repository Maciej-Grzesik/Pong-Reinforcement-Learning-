//
// Created by Maciej on 10/07/2024.
//

#include "Player.h"

Player::Player(float yPosition, float xPosition) : yPosition(yPosition), xPosition(xPosition)
{

}

float Player::getX() const {
    return this->xPosition;
}
float Player::getY() const {
    return this->yPosition;
}

void Player::setX(float x) {
    this->xPosition = x;
}

void Player::setY(float y) {
    this->yPosition = y;
}

