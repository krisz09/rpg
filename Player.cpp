//
// Created by antal on 2024. 09. 03..
//

#include "Player.hpp"
#include <iostream>

void Player::initVariables() {
    moving = false;
}

void Player::initSprite() {
    sprite.setTexture(idleTexture);
    currentFrame = sf::IntRect(0,0,42,42);
    sprite.setTextureRect(currentFrame);
}

    void Player::initTextures() {
        if (idleTexture.loadFromFile("../Assets/Player/Texture/Idle.png")) {
            std::cout << "Idle texture loaded successfully" << std::endl;
        } else {
            std::cout << "Failed to load idle texture" << std::endl;
        }

        if (runTexture.loadFromFile("../Assets/Player/Texture/Run.png")) {
            std::cout << "Run texture loaded successfully" << std::endl;
        } else {
            std::cout << "Failed to load run texture" << std::endl;
        }

        if (jumpTexture.loadFromFile("../Assets/Player/Texture/Jump.png")) {
            std::cout << "Jump texture loaded successfully" << std::endl;
        } else {
            std::cout << "Failed to load jump texture" << std::endl;
        }

        // Set default state (e.g., idle state)
        sprite.setTexture(idleTexture);
        currentState = IDLE;
    }

void Player::initAnimations() {
    animationTimer.restart();
}

void Player::initPhysics() {
    speed = 100.f;
    drag = 0.96f;
    gravity = 4.f;
    acceleration = 5.f;
    minVelocity = 1.f;
    maxVelocity = 3.f;
    YmaxVelocity = 3.f;
    grounded = false;
}


Player::Player() {
    initVariables();
    initTextures();
    initSprite();
    initAnimations();
    initPhysics();
}

void Player::updateMovement() {
    moving = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->move(-1.f, 0.f);
        moving = true;
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->move(1.f, 0.f);
        moving = true;
    }
}

void Player::updateAnimations() {
    if (animationTimer.getElapsedTime().asSeconds() >= 0.1f) {
        if (moving) {
            if (currentState != RUNNING) {
                currentState = RUNNING;
                sprite.setTexture(runTexture);
                currentFrame = sf::IntRect(0,0,42, 42);
            }
                currentFrame.left += 42.f;
                if (currentFrame.left >= 210.f) {
                    currentFrame.left = 0.f;
                }
        }
        else {
            if (currentState != IDLE) {
                currentState = IDLE;
                sprite.setTexture(idleTexture);
                currentFrame = sf::IntRect(0,0,42,42);
            }
            currentFrame.left += 42.f;
            if (currentFrame.left >= 126.f) {
                currentFrame.left = 0.f;
            }
        }
        animationTimer.restart();
        sprite.setTextureRect(currentFrame);
    }

}

void Player::update() {
    updateMovement();
    updateAnimations();
    //boundingRectangle.setPosition(sprite.getPosition());
    updatePhysics();
}

void Player::render(sf::RenderTarget& target) {
    target.draw(sprite);
}

const sf::FloatRect Player::getGlobalBounds() const {
    return sprite.getGlobalBounds();
}

void Player::resetVelocityY() {
    velocity.y = 0.f;
}

void Player::setPosition(const float x, const float y) {
    sprite.setPosition(x, y);
}


void Player::move(const float dir_x, const float dir_y) {
    //Acceleration
    velocity.x += dir_x * acceleration;

    //Limit velocity
    if (std::abs(velocity.x) > maxVelocity) {
        velocity.x = maxVelocity * (velocity.x < 0.f ? -1.0f : 1.0f);
    }
}

void Player::updatePhysics() {
    //Gravity
    velocity.y += 1.0 * gravity;
    if (std::abs(velocity.y) > YmaxVelocity) {
        velocity.y = YmaxVelocity * (velocity.y < 0.f ? -1.0f : 1.0f);
    }
    //Deceleration
    velocity *= drag;

    //Limit deceleration
    if (std::abs(velocity.x) < minVelocity) {
        velocity.x = 0.f;
    }
    if (std::abs(velocity.y) < minVelocity) {
        velocity.y = 0.f;
    }

    sprite.move(velocity);
}






