//
// Created by antal on 2024. 09. 10..
//

#ifndef TILE_HPP
#define TILE_HPP
#include "stdafx.hpp"


class Tile {
private:
    sf::Sprite sprite;
    const bool damaging;

public:
    Tile(sf::Texture& textureSheet, sf::IntRect textureRect, bool damaging = false);

    const sf::FloatRect getGlobalBounds() const;

    void update();
    void render(sf::RenderTarget& target);
};



#endif //TILE_HPP
