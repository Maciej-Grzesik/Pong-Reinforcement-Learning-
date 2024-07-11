//
// Created by Maciej on 10/07/2024.
//

#ifndef ENGINE_PLAYER_H
#define ENGINE_PLAYER_H

#include <SFML/Graphics.hpp>

class Player : public sf::RectangleShape {
private:
    float yPosition;
    float xPosition;

public:
    Player(float yPosition, float xPosition);
    float getX() const;
    float getY() const;
    void setX(float x);
    void setY(float y);
};


#endif //ENGINE_PLAYER_H
