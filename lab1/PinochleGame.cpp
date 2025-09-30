/*
 *  PinochleGame.cpp
 *  Author: Richard Meyer
 *  Definitions for PinochleGame class implementing Pinochle dealing logic
 */

#include "PinochleGame.h"
#include <iostream>
#include <stdexcept>
#include "util.h"

const size_t PINOCHLE_PACKET_SIZE = 3;
const size_t PINOCHLE_CARDS_PER_LINE = 8;
const std::string AFFIRMATIVE_RESPONSE = "yes";

PinochleGame::PinochleGame(int argc, const char * argv[]) : Game(argc, argv)
{
    hands.resize(players.size());
}

void PinochleGame::deal()
{
    size_t playerIndex = 0;
    try {
    while (!deck.is_empty())
    {
        for (int i = 0; i < PINOCHLE_PACKET_SIZE && !deck.is_empty(); i++)
        {
            deck >> hands[playerIndex];
        }
        playerIndex = (playerIndex + 1) % players.size();
    }
    } catch (const std::runtime_error& e)
    {
        std::cerr << "error during deal: " << e.what() << std::endl;
        throw;
    }
}

void PinochleGame::printHands() const 
{
    for (size_t i = 0; i < players.size(); i++)
    {
        std::cout << players[i] << "'s hand: " << std::endl;
        hands[i].print(std::cout, PINOCHLE_CARDS_PER_LINE);
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
    return (res == AFFIRMATIVE_RESPONSE);
}

int PinochleGame::play()
{
    while (true)
    {
        try {
        deck.shuffle();
        deal();
        printHands();
        collectHands();
        
        if (askQuit())
        {
            return ExitCode::Success;
        }
        } catch (const std::runtime_error& e)
        {
            std::cerr << "error during play: " << e.what() << std::endl;
            return ExitCode::RuntimeError;
        }
    }
}
