#include "PinochleGame.h"
#include <iostream>
#include "util.h"

PinochleGame::PinochleGame(int argc, const char * argv[]) : Game(argc, argv)
{
    hands.resize(players.size());
}

void PinochleGame::deal()
{
    size_t playerIndex = 0;
    while (!deck.is_empty())
    {
        for (int i = 0; i < 3 && !deck.is_empty(); i++)
        {
            deck >> hands[playerIndex];
        }
        playerIndex = (playerIndex + 1) % players.size();
    }
}

void PinochleGame::printHands() const 
{
    for (size_t i = 0; i < players.size(); i++)
    {
        std::cout << players[i] << "'s hand: " << std::endl;
        hands[i].print(std::cout, 8);
        std::cout << std::endl;
    }
}

void PinochleGame::collectHands()
{
    for (auto &hand : hands)
    {
        deck.collect(hand);
    }
}

bool PinochleGame::askQuit() const 
{
    std::cout << "end the game? (yes/no): ";
    std::string res;
    std::cin >> res;
    return (res == "yes");
}

int PinochleGame::play()
{
    while (true)
    {
        deck.shuffle();
        deal();
        printHands();
        collectHands();
        
        if (askQuit())
        {
            return ExitCode::Success;
        }
    }
}
