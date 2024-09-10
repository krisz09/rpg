//
// Created by antal on 2024. 09. 05..
//

#include "BulletManager.hpp"
/*
BulletManager::BulletManager(const Player *player, Logic *logic) :
    player(player), logic(logic), bulletSpeed(350) {}


void BulletManager::Update(float deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(30, 25)));

        int i = bullets.size() - 1;
        bullets[i].setPosition(player->sprite.getPosition());
    }


    for (int i = 0; i < bullets.size(); i++) {
        //bulletDirection TODO make the bullet shoot where player is facing
        bulletDirection = logic->normalize(bulletDirection);
        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed * deltaTime);
    }
}

void BulletManager::Draw(sf::RenderWindow &window) {
    for (int i = 0; i < bullets.size(); i++) {
        window.draw(bullets[i]);
    }
}
*/