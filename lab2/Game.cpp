#include "Game.h"
#include <iostream>

Game::Game(int argc, const char * argv[])
{
    for (int i = 2; i < argc; i++)
    {
        players.emplace_back(argv[i]);
    }
}
