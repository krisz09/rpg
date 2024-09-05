//
// Created by antal on 2024. 09. 03..
//

#ifndef LOGIC_HPP
#define LOGIC_HPP
#include "SFML/Graphics.hpp"


class Logic {
public:
    sf::Vector2f normalize(sf::Vector2f vector);
    static bool CheckCollision(sf::FloatRect rect1, sf::FloatRect rec2);
};



#endif //LOGIC_HPP
