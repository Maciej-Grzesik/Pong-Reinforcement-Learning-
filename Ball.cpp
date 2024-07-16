//
// Created by Maciej on 10/07/2024.
//

#include "Ball.h"
#include <cmath>
#include <iostream>

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

Ball::Ball(float xDirection, float velocity) {
    this->xDirection = xDirection;
    this->velocity = velocity;
}

void Ball::calculatexVelocity() {
    this->xVelocity = this->velocity * std::cos(this->angle) * this->xDirection;
}

void Ball::calculateyVelocity() {
    std::cout << this->angle << std::endl;
    this->yVelocity = this->velocity * std::sin(this->angle);
}

void Ball::calculateAngle(const Player& player) {
    float yPlayer{player.getPosition().y};
    float distance{50.f - (Ball::getPosition().y - yPlayer)};

    this->angle = std::atan2(distance, 100.f);
}
