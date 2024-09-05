//
// Created by antal on 2024. 09. 03..
//

#include "Player.hpp"
#include <iostream>

void Player::Initialize() {
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineThickness(1);
    boundingRectangle.setOutlineColor(sf::Color::Red);
    size = sf::Vector2i(128,128);
}

void Player::Load() {
    if (texture.loadFromFile("../Assets/Player/Texture/Idle.png")) {
        std::cout << "Player texture loaded succesfully" << std::endl;
        sprite.setTexture(texture);
        int x = 0;
        int y = 0;

        sprite.setTextureRect(sf::IntRect(x * size.x, y * size.y, size.x, size.y));
        boundingRectangle.setSize(sf::Vector2f(sprite.getLocalBounds().width, sprite.getLocalBounds().height));
    }
    else {
        std::cout << "File couldn't load" << std::endl;
    }

    sprite.setPosition(sf::Vector2f(800,500));
}

void Player::Update() {
    sf::Vector2f position = sprite.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        sprite.setPosition(position + sf::Vector2f(0,-1));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        sprite.setPosition(position + sf::Vector2f(-1,0));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        sprite.setPosition(position + sf::Vector2f(0,1));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        sprite.setPosition(position + sf::Vector2f(1,0));
    }

    boundingRectangle.setPosition(sprite.getPosition());
}


void Player::Draw(sf::RenderWindow &window) {
    window.draw(sprite);
    window.draw(boundingRectangle);
}


