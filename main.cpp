#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    //-------------------------------- INITIALIZE --------------------------------

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game", sf::Style::Default, settings);
    //-------------------------------- INITIALIZE --------------------------------

    //-------------------------------- LOAD --------------------------------
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if (playerTexture.loadFromFile("../Assets/Player/Textures/Idle.png")) {
        std::cout << "File loaded succesfully" << std::endl;
        playerSprite.setTexture(playerTexture);
        int x = 0;
        int y = 0;

        playerSprite.setTextureRect(sf::IntRect(x * 128, y * 128, 128, 128));
    }
    else {
        std::cout << "File couldn't load" << std::endl;
    }


    //-------------------------------- LOAD --------------------------------



    //main game loop
    while (window.isOpen())
    {
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


        //-------------------------------- UPDATE --------------------------------

        //-------------------------------- DRAW --------------------------------
        window.clear(sf::Color::Black);
        window.draw(playerSprite);
        window.display();
        //-------------------------------- DRAW --------------------------------
    }

    return 0;
}