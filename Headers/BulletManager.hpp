//
// Created by antal on 2024. 09. 05..
//

#ifndef BULLETMANAGER_HPP
#define BULLETMANAGER_HPP
#include "SFML/Graphics.hpp"

#include "Logic.hpp"
#include "Player.hpp"


class BulletManager {

private:
    std::vector<sf::RectangleShape> bullets;
    sf::Vector2f bulletDirection;
    float bulletSpeed = 0;

    const Player *player;
    Logic *logic;

public:
    BulletManager(const Player* player, Logic *logic);

private:

public:
    void Update(float deltaTime);
    void Initialize();
    void Draw(sf::RenderWindow &window);

};

#endif //BULLETMANAGER_HPP
