//
// Created by Maciej on 10/07/2024.
//

#ifndef ENGINE_BALL_H
#define ENGINE_BALL_H


#include "SFML/Graphics/CircleShape.hpp"
#include "Player.h"

class Ball : public sf::CircleShape {
private:
    float xDirection;
    float yDirection{};
    float velocity;


public:
    float angle{};
    float xVelocity{};
    float yVelocity{};
    Ball(float xDirection, float velocity);

    float getxDirection() const;
    float getyDirection() const;
    void setxDirection(float xDirection);
    void setyDirection(float yDirection);

    void calculatexVelocity();
    void calculateyVelocity();
    void calculateAngle(const Player& player);
};


#endif //ENGINE_BALL_H
