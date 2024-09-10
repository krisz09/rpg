//
// Created by antal on 2024. 09. 10..
//
#include "Tile.hpp"

Tile::Tile(sf::Texture &textureSheet, sf::IntRect textureRect, bool damaging) : damaging(damaging) {
    sprite.setTexture(textureSheet);
    sprite.setTextureRect(textureRect);
}

const sf::FloatRect Tile::getGlobalBounds() const {
    return sprite.getGlobalBounds();
}

void Tile::update() {

}
void Tile::render(sf::RenderTarget &target) {
    target.draw(sprite);
}



