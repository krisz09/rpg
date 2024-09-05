//
// Created by antal on 2024. 09. 03..
//

#include "Enemy.hpp"

#include <iostream>


void Enemy::Initialize() {
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineThickness(1);
    boundingRectangle.setOutlineColor(sf::Color::Red);
    size = sf::Vector2i(128,128);
}

void Enemy::Load() {
    if (texture.loadFromFile("../Assets/Enemy/Texture/Idle.png")) {
        std::cout << "Enemy texture loaded succesfully" << std::endl;
        sprite.setTexture(texture);
        int x = 0;
        int y = 0;

        sprite.setTextureRect(sf::IntRect(x * size.x, y * size.y, size.x, size.y));
        boundingRectangle.setSize(sf::Vector2f(sprite.getLocalBounds().width, sprite.getLocalBounds().height));
    }
}

void Enemy::Update() {

}

void Enemy::Draw(sf::RenderWindow &window) {
    window.draw(sprite);
    window.draw(boundingRectangle);
}



