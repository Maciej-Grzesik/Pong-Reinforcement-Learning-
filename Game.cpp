//
// Created by Maciej on 09/07/2024.
//

#include <iostream>
#include "Game.h"

Game::Game() {
    this->initVariables();
    this->initWindow();
    this->initTiles();
    this->initBall();
    this->initPlayers();
}

Game::~Game() {
    delete this->pWindow;
}

void Game::update() {
    this->getEvent();
    this->updateBall();
    this->updatePlayers();
}

void Game::render() {
    this->pWindow->clear();

    this->renderTiles();
    this->renderBall();
    this->renderPlayers();

    this->pWindow->display();
}

void Game::getEvent() {
    while(this->pWindow->pollEvent(this->event)) {
        switch (this->event.type) {
            case sf::Event::Closed:
                this->pWindow->close();
                break;

            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Escape) {
                    this->pWindow->close();
                }
                break;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        this->pPlayerLeft->moveUp(this->gameTile);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->pPlayerLeft->moveDown(this->gameTile);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        this->pPlayerRight->moveUp(this->gameTile);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        this->pPlayerRight->moveDown(this->gameTile);
    }
}

void Game::initVariables() {
    this->pPlayerLeft = nullptr;
    this->pPlayerRight = nullptr;
    this->pBall = nullptr;
    this->pWindow = nullptr;
}

void Game::initWindow() {
    this->videoMode = sf::VideoMode::getFullscreenModes()[0];
    this->pWindow = new sf::RenderWindow(this->videoMode, "Engine", sf::Style::Default);
    this->pWindow->setFramerateLimit(60);
}

void Game::initBall() {
    this->pBall = new Ball(1.f, 10.f);
    this->pBall->setRadius(10.0f);
    this->pBall->setFillColor(sf::Color::White);
    this->pBall->setPosition(sf::Vector2(static_cast<float>(sf::VideoMode::getDesktopMode().width) / 2.0f, static_cast<float>(sf::VideoMode::getDesktopMode().height) / 2.0f));
}

void Game::initPlayers() {
    this->pPlayerLeft = new Player((this->gameTile.getPosition().y + this->gameTile.getSize().y) / 2.f, this->gameTile.getPosition().x + 50.f);
    this->pPlayerLeft->setSize(sf::Vector2f(10.f, 100.f));
    this->pPlayerLeft->setPosition(sf::Vector2f(this->pPlayerLeft->getX(), this->pPlayerLeft->getY()));

    this->pPlayerRight = new Player((this->gameTile.getPosition().y + this->gameTile.getSize().y) / 2.f, this->gameTile.getPosition().x + this->gameTile.getSize().x- 50.f);
    this->pPlayerRight->setSize(sf::Vector2f(10.f, 100.f));
    this->pPlayerRight->setPosition(sf::Vector2f(this->pPlayerRight->getX(), this->pPlayerRight->getY()));
}

void Game::initTiles() {
    this->gameTile.setSize(sf::Vector2f(this->pWindow->getSize().x * 3 / 4, this->pWindow->getSize().y * 3 / 4));
    this->gameTile.setPosition(sf::Vector2f(this->pWindow->getSize().x / 8, this->pWindow->getSize().y / 16));
    this->gameTile.setFillColor(sf::Color::Black);
    this->gameTile.setOutlineColor(sf::Color::White);
    this->gameTile.setOutlineThickness(2.f);

}

void Game::renderTiles() {
    this->pWindow->draw(gameTile);

}

bool Game::isWindowOpen() const {
    return this->pWindow->isOpen();
}

void Game::updateBall() {
    sf::Vector2f position = this->pBall->getPosition();

    if (position.x >= this->pPlayerRight->getPosition().x - 2 * this->pBall->getRadius()
        and position.x <= this->pPlayerRight->getPosition().x + this->pPlayerRight->getSize().x - 2 * this->pBall->getRadius()
        and position.y >= pPlayerRight->getPosition().y
        and position.y <= pPlayerRight->getPosition().y + 100.f) {
        this->pBall->setxDirection(-1.f);
        this->pBall->calculateAngle(*this->pPlayerRight);
    }

    if (position.x <= this->pPlayerLeft->getPosition().x + this->pBall->getRadius()
        and position.x >= this->pPlayerLeft->getPosition().x
        and position.y >= pPlayerLeft->getPosition().y
        and position.y <= pPlayerLeft->getPosition().y + 100.f) {
        this->pBall->setxDirection(1.f);
        this->pBall->calculateAngle(*this->pPlayerLeft);
    }

    if (position.y <= this->gameTile.getPosition().y and this->pBall->yVelocity < 0) {
        this->pBall->angle *= (-1.f);
    }
    if (position.y >= this->gameTile.getPosition().y + this->gameTile.getSize().y - 2 * this->pBall->getRadius() and this->pBall->yVelocity > 0) {
        this->pBall->angle *= (-1.f);
    }

    this->pBall->calculateyVelocity();
    this->pBall->calculatexVelocity();
    position.x += this->pBall->xVelocity;
    position.y += this->pBall->yVelocity;

    this->pBall->setPosition(position);



    if (position.x <= this->gameTile.getPosition().x) {
        scoreRight++;
        this->pBall->setPosition(sf::Vector2(20.f, 100.f));
    }

    if (position.x >= this->gameTile.getPosition().x + this->gameTile.getSize().x - 2 * this->pBall->getRadius()) {
        scoreLeft++;
        this->pBall->setPosition(sf::Vector2(20.f, 100.f));
    }
}

void Game::renderBall() {
    this->pWindow->draw(*this->pBall);
}

void Game::updatePlayers() {
    this->pPlayerLeft->updatePosition();
    this->pPlayerRight->updatePosition();
}

void Game::renderPlayers() {
    this->pWindow->draw(*this->pPlayerLeft);
    this->pWindow->draw(*this->pPlayerRight);
}
