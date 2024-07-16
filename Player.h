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
    void setY(float y);
    void updatePosition();

    void moveUp(const sf::RectangleShape& tile);
    void moveDown(const sf::RectangleShape& tile);

};


#endif //ENGINE_PLAYER_H
