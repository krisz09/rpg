//
// Created by antal on 2024. 09. 03..
//

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML/Graphics.hpp>


class Player {
public:
    sf::Sprite sprite;
private:
    sf::Texture texture;
    sf::RectangleShape boundingRectangle;
    sf::Vector2i size;

public:
    void Initialize();
    void Load();
    void Update();
    void Draw(sf::RenderWindow& window);
};



#endif //PLAYER_HPP
