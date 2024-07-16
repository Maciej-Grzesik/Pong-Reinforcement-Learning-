//
// Created by Maciej on 09/07/2024.
//

#ifndef ENGINE_GAME_H
#define ENGINE_GAME_H


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Player.h"

class Game {
private:
    sf::RenderWindow* pWindow;
    sf::Event event;
    sf::VideoMode videoMode;

    sf::RectangleShape gameTile;

    Ball* pBall;
    Player* pPlayerLeft;
    Player* pPlayerRight;

    void initVariables();
    void initWindow();
    void initBall();
    void initPlayers();
    void initTiles();

public:
    Game();
    virtual ~Game();

    int scoreLeft{0};
    int scoreRight{0};

    bool isWindowOpen() const;

    void getEvent();
    void update();
    void updateBall();
    void updatePlayers();

    void render();
    void renderBall();
    void renderPlayers();
    void renderTiles();
};

#endif //ENGINE_GAME_H
