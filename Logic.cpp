//
// Created by antal on 2024. 09. 03..
//

#include "Logic.hpp"
#include <cmath>
#include <iostream>

sf::Vector2f Logic::normalize(sf::Vector2f vector) {
    float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);

    sf::Vector2f normalizedVector;

    normalizedVector.x = vector.x /  magnitude;
    normalizedVector.y = vector.y / magnitude;

    return normalizedVector;
}

bool Logic::CheckCollision(sf::FloatRect rect1, sf::FloatRect rec2) {
    if (rect1.intersects(rec2)) {
        std::cout << "Yes" << std::endl;
        return true;
    }

    return false;
}
