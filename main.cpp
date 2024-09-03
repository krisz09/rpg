#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

sf::Vector2f normalize(sf::Vector2f vector) {
    float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);

    sf::Vector2f normalizedVector;

    normalizedVector.x = vector.x /  magnitude;
    normalizedVector.y = vector.y / magnitude;

    return normalizedVector;
}

int main()
{
    //-------------------------------- INITIALIZE --------------------------------

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1360, 768), "RPG Game", sf::Style::Default, settings);

    std::vector<sf::RectangleShape> bullets;
    sf::Vector2f bulletDirection;
    float bulletSpeed = 0.5f;
    //-------------------------------- INITIALIZE --------------------------------

    //-------------------------------- LOAD --------------------------------
    sf::Texture playerTexture;
    sf::Texture enemyTexture;

    sf::Sprite playerSprite;
    sf::Sprite enemySprite;

    //------------------- ENEMY -------------------

    if (enemyTexture.loadFromFile("../Assets/Enemy/Texture/Idle.png")) {
        std::cout << "Enemy texture loaded succesfully" << std::endl;
        enemySprite.setTexture(enemyTexture);
        int x = 0;
        int y = 0;

        enemySprite.setTextureRect(sf::IntRect(x * 128, y * 128, 128, 128));
    }

    //------------------- ENEMY -------------------

    //------------------- PLAYER -------------------
    
    if (playerTexture.loadFromFile("../Assets/Player/Texture/Idle.png")) {
        std::cout << "Player texture loaded succesfully" << std::endl;
        playerSprite.setTexture(playerTexture);
        int x = 0;
        int y = 0;

        playerSprite.setTextureRect(sf::IntRect(x * 128, y * 128, 128, 128));
    }
    else {
        std::cout << "File couldn't load" << std::endl;
    }

    playerSprite.setPosition(sf::Vector2f(800,500   ));
    //------------------- PLAYER -------------------

    //------------------- BULLET -------------------

    //------------------- BULLET -------------------


    //-------------------------------- LOAD --------------------------------



    //main game loop
    while (window.isOpen()) {
        //-------------------------------- UPDATE --------------------------------
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        sf::Vector2f position = playerSprite.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            playerSprite.setPosition(position + sf::Vector2f(0,-1));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            playerSprite.setPosition(position + sf::Vector2f(-1,0));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            playerSprite.setPosition(position + sf::Vector2f(0,1));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            playerSprite.setPosition(position + sf::Vector2f(1,0));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            bullets.push_back(sf::RectangleShape(sf::Vector2f(30, 25)));

            int i = bullets.size() - 1;
            bullets[i].setPosition(playerSprite.getPosition());
        }

        for (int i = 0; i < bullets.size(); i++) {
            bulletDirection = enemySprite.getPosition() - bullets[i].getPosition();
            bulletDirection = normalize(bulletDirection);
            bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
        }



        //-------------------------------- UPDATE --------------------------------

        //-------------------------------- DRAW --------------------------------
        window.clear(sf::Color::Black);
        window.draw(playerSprite);
        window.draw(enemySprite);
        for (int i = 0; i < bullets.size(); i++) {
            window.draw(bullets[i]);
        }
        window.display();
        //-------------------------------- DRAW --------------------------------
    }

    return 0;
}