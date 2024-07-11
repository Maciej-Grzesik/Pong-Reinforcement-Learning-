//
// Created by Maciej on 09/07/2024.
//

#include <iostream>
#include "Game.h"

Game::Game()
    : playerLeft(static_cast<float>(sf::VideoMode::getDesktopMode().height) / 2.f, 100.f),
      playerRight(static_cast<float>(sf::VideoMode::getDesktopMode().height) / 2.f, static_cast<float>(sf::VideoMode::getDesktopMode().width) - 110.f) {
    this->initVariables();
    this->initWindow();
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
        this->playerLeft.setY(playerLeft.getY() - 10.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->playerLeft.setY(playerLeft.getY() + 10.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        this->playerRight.setY(playerRight.getY() - 10.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        this->playerRight.setY(playerRight.getY() + 10.f);
    }
}

void Game::initVariables() {
    this->pWindow = nullptr;
}

void Game::initWindow() {
    this->videoMode = sf::VideoMode::getFullscreenModes()[0];
    this->pWindow = new sf::RenderWindow(this->videoMode, "Engine", sf::Style::Titlebar);
    this->pWindow->setFramerateLimit(60);
}

bool Game::isWindowOpen() const {
    return this->pWindow->isOpen();
}

void Game::initBall() {
    this->ball.setRadius(10.0f);
    this->ball.setFillColor(sf::Color::White);
    this->ball.setPosition(sf::Vector2(static_cast<float>(sf::VideoMode::getDesktopMode().width) / 2.0f, static_cast<float>(sf::VideoMode::getDesktopMode().height) / 2.0f));
}

void Game::updateBall() {
    sf::Vector2f position = this->ball.getPosition();

    if (position.x <= this->playerLeft.getX() + this->ball.getRadius() - 10.f and this->ball.getxDirection() < 0) {

    }

    if (position.x >= this->playerRight.getX() - this->ball.getRadius() + 10.f and position.y >= playerRight.getY() and position.y <= playerRight.getY() + 100.f) {
        this->ball.setxDirection(-1.f);
    }

    if (position.x <= this->playerLeft.getX() + this->ball.getRadius() - 10.f and position.y >= playerLeft.getY() and position.y <= playerLeft.getY() + 100.f) {
        this->ball.setxDirection(1.f);
    }

    if (position.y <= 0 and this->ball.getyDirection() < 0) {
        this->ball.setyDirection(1.f);
    }
    if (position.y >= static_cast<float>(sf::VideoMode::getDesktopMode().height) - 2 * this->ball.getRadius() and this->ball.getyDirection() > 0) {
        this->ball.setyDirection(-1.f);
    }


    position.x += 8.f * this->ball.getxDirection();
    position.y += 8.f * this->ball.getyDirection();

    this->ball.setPosition(position);
}

void Game::renderBall() {
    this->pWindow->draw(this->ball);
}

void Game::initPlayers() {
    this->playerLeft.setSize(sf::Vector2f(10.f, 100.f));
    this->playerLeft.setPosition(sf::Vector2f(this->playerLeft.getX(), this->playerLeft.getY()));
    this->playerRight.setSize(sf::Vector2f(10.f, 100.f));
    this->playerRight.setPosition(sf::Vector2f(this->playerRight.getX(), this->playerRight.getY()));
}

void Game::renderPlayers() {
    this->pWindow->draw(this->playerLeft);
    this->pWindow->draw(this->playerRight);
}

void Game::updatePlayers() {
    this->playerLeft.setPosition(sf::Vector2f(this->playerLeft.getX(), this->playerLeft.getY()));
    this->playerRight.setPosition(sf::Vector2f(this->playerRight.getX(), this->playerRight.getY()));
}