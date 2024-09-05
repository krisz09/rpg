#include "Player.hpp"
#include "Enemy.hpp"
#include "Logic.hpp"
#include <SFML/Graphics.hpp>

#include "BulletManager.hpp"


int main()
{
    //-------------------------------- INITIALIZE --------------------------------

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1360, 768), "RPG Game", sf::Style::Default, settings);


    Player player;
    Enemy enemy;
    Logic logic;
    BulletManager bullet_manager;

    player.Initialize();
    enemy.Initialize();
    bullet_manager.Initialize();

    player.Load();
    enemy.Load();

    //main game loop
    while (window.isOpen()) {
        //-------------------------------- UPDATE --------------------------------
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }



        player.Update();
        enemy.Update();
        bullet_manager.Update(player, enemy, logic);
        logic.CheckCollision(player.sprite.getGlobalBounds(), enemy.sprite.getGlobalBounds());




        //-------------------------------- UPDATE --------------------------------



        //-------------------------------- DRAW --------------------------------
        window.clear(sf::Color::Black);
        player.Draw(window);
        enemy.Draw(window);
        bullet_manager.Draw(window);
        window.display();
        //-------------------------------- DRAW --------------------------------
    }

    return 0;
}
