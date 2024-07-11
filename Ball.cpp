//
// Created by Maciej on 10/07/2024.
//

#include "Ball.h"

float Ball::getxDirection() const {
    return this->xDirection;
}

void Ball::setxDirection(float direction) {
    this->xDirection = direction;
}

float Ball::getyDirection() const {
    return this->yDirection;
}

void Ball::setyDirection(float direction) {
    this->yDirection = direction;
}