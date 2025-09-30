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
    if (argc < 3)
    {
        cerr << "Usage: " << endl;
        cerr << " " << argv[0] << " Pinochle <player1> .. <player4>" << endl;
        cerr << " " << argv[0] << " HoldEm <player1> ... <player9>" << endl;
        return ExitCode::UsageError;
    }

    string name = argv[1];

    if (name == "Pinochle")
    {
        if (argc != 6)
        {
            cerr << "Pinochle requires four players." << endl;
            cerr << "Usage: " << argv[0] << "Pinochle <player1> .. <player4>" << endl;
            return ExitCode::UsageError;
        }
    }
    else if (name == "HoldEm")
    {
        if (argc < 4 || argc > 10)
        {
            cerr << "HoldEm requires between 2 and 9 players." << endl;
            cerr << "Usage: " << argv[0] << " HoldEm <player1> ... <player9>" << endl;
            return 3;
        }
    }
    else
    {
        cerr << "Unknown game: " << name << endl;
        cerr << "Valid options are: Pinochle or HoldEm" << endl;
        return 4;
    }

    auto game = create(argc, argv);

    if (game)
    {
        return game->play();
    }
    else
    {
        cerr << "error: could not create game object" << endl;
        return 5;
    }
}
