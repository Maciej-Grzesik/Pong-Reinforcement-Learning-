//
// Created by Maciej on 10/07/2024.
//

#ifndef ENGINE_BALL_H
#define ENGINE_BALL_H


#include "SFML/Graphics/CircleShape.hpp"

class Ball : public sf::CircleShape {
private:
    float xDirection{1.f};
    float yDirection{1.f};

public:
    float getxDirection() const;
    float getyDirection() const;
    void setxDirection(float xDirection);
    void setyDirection(float yDirection);

};


#endif //ENGINE_BALL_H
