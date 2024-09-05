//
// Created by antal on 2024. 09. 05..
//

#ifndef BULLETMANAGER_HPP
#define BULLETMANAGER_HPP
#include "SFML/Graphics.hpp"

#include "Enemy.hpp"
#include "Logic.hpp"
#include "Player.hpp"


class BulletManager {

private:
    std::vector<sf::RectangleShape> bullets;
    sf::Vector2f bulletDirection;
    float bulletSpeed = 0;
public:

private:

public:
    void Update(const Player &player, const Enemy& enemy, Logic &logic);
    void Initialize();
    void Draw(sf::RenderWindow &window);

};



#endif //BULLETMANAGER_HPP
