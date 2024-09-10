//
// Created by antal on 2024. 09. 03..
//

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "stdafx.hpp"


class Player {
private:
    sf::Sprite sprite;

    //Textures
    sf::Texture idleTexture;
    sf::Texture runTexture;
    sf::Texture jumpTexture;

    //Animation
    enum AnimationState { IDLE, RUNNING, JUMPING };
    AnimationState currentState;
    sf::IntRect currentFrame;
    sf::Clock animationTimer;

    sf::RectangleShape boundingRectangle;
    sf::Vector2i size;

    //Physics
    float speed;
    float drag;
    float acceleration;
    sf::Vector2f velocity;
    float maxVelocity;
    float minVelocity;
    float gravity;
    float YmaxVelocity;
    bool grounded;
    bool moving;

    //Functions
    void initVariables();
    void initSprite();
    void initTextures();
    void initAnimations();
    void initPhysics();


public:
    Player();


    //Functions
    void updateMovement();
    void updateAnimations();
    void update();
    void render(sf::RenderTarget& target);

    //Accessors
    const sf::FloatRect getGlobalBounds() const;

    //Modifiers
    void resetVelocityY();
    void setPosition(const float x, const float y);

    //Movement
    void move(const float dir_x, const float dir_y);
    void updatePhysics();
};



#endif //PLAYER_HPP
