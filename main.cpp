#include "stdafx.hpp"
#include "Game.hpp"


int main()
{
    Game game;

    //main game loop
    while (game.getWindow().isOpen()) {

        game.update();
        game.render();
    }
    return 0;
}
