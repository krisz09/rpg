//
// Created by antal on 2024. 09. 05..
//

#include "BulletManager.hpp"


void BulletManager::Initialize() {
        bulletSpeed = 0.5f;
}

void BulletManager::Update(const Player &player, const Enemy &enemy, Logic &logic) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(30, 25)));

        int i = bullets.size() - 1;
        bullets[i].setPosition(player.sprite.getPosition());
    }


    for (int i = 0; i < bullets.size(); i++) {
        bulletDirection = enemy.sprite.getPosition() - bullets[i].getPosition();
        bulletDirection = logic.normalize(bulletDirection);
        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
    }
}

void BulletManager::Draw(sf::RenderWindow &window) {
    for (int i = 0; i < bullets.size(); i++) {
        window.draw(bullets[i]);
    }
}


