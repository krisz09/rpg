//
// Created by antal on 2024. 09. 09..
//

#include "Game.hpp"

void Game::initWindow() {
    window.create(sf::VideoMode(1360,768), "RPG game", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(144);
}

void Game::initPlayer() {
    player = new Player();
}

Game::Game() {
    initWindow();
    initPlayer();
}

Game::~Game() {
    delete player;
}

void Game::updatePlayer() {
    player->update();
}

void Game::updateCollision() {
    if (player->getGlobalBounds().top + player->getGlobalBounds().height > window.getSize().y) {
        player->resetVelocityY();
        player->setPosition(player->getGlobalBounds().left, window.getSize().y - player->getGlobalBounds().height);
    }
}

void Game::update() {
    //Polling events
    while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

    updatePlayer();
    updateCollision();
}

void Game::renderPlayer() {
    player->render(window);
}

void Game::render() {
    window.clear(sf::Color::Black);

    renderPlayer();

    window.display();
}

const sf::RenderWindow & Game::getWindow() const {
    return window;
}

