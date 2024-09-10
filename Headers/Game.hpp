//
// Created by antal on 2024. 09. 09..
//

#ifndef GAME_HPP
#define GAME_HPP
#include "Player.hpp"


class Game {
private:
    sf::RenderWindow window;
    sf::Event event;
    Player* player;

    //Inits
    void initWindow();
    void initPlayer();

public:
    //Constructor
    Game();

    //Destructor
    ~Game();

    //Functions
    void updatePlayer();
    void updateCollision();
    void update();
    void renderPlayer();
    void render();
    const sf::RenderWindow& getWindow() const;
};



#endif //GAME_HPP
