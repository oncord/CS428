#include <iostream>
#include <memory>
#include <string>
#include "Game.h"
#include "PinochleGame.h"
#include "HoldEmGame.h"
#include "util.h"

using namespace std;

shared_ptr<Game> create(int argc, const char * argv[])
{
    shared_ptr<Game> game;

    if (argc > 1)
    {
        string name = argv[1];

        if (name == "Pinochle")
        {
            game = make_shared<PinochleGame>(argc, argv);
        }
        else if (name == "HoldEm")
        {
            game = make_shared<HoldEmGame>(argc, argv);
        }
    }

    return game;
}

int main(int argc, const char * argv[])
{
    if (argc < 2)
    {
        cerr << "Usage:\n"
             << " " << argv[0] << " Pinochle <player1> .. <player4>\n";
             << " " << argv[0] << " HoldEm <player1> ... <player9>\n";
        return ExitCode::UsageError;
    }

    string name = argv[1];

    if (name == "Pinochle")
    {
        if (argc != 6)
        {
            cerr << "Pinochle requires four players.\n";
                 << "Usage: " << argv[0] << " Pinochle <player1> .. <player4>\n";
            return ExitCode::InvalidPlayers;
        }
    }
    else if (name == "HoldEm")
    {
        if (argc < 4 || argc > 11)
        {
            cerr << "HoldEm requires between 2 and 9 players.\n";
                 << "Usage: " << argv[0] << " HoldEm <player1> ... <player9>\n";
            return ExitCode::InvalidPlayers;
        }
    }
    else
    {
        cerr << "Unknown game: " << name << "\n";
             << "Valid options are: Pinochle or HoldEm\n";
        return ExitCode::UnknownGame;
    }

    auto game = create(argc, argv);
    if (game)
    {
        return game->play(); 
    }
    else
    {
        cerr << "error: could not create game object\n";
        return ExitCode::GameCreationError;
    }
}
