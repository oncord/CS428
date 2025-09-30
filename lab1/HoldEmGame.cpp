/*
 *  HoldEmGame.cpp
 *  Author: Richard Meyer
 *  Definitions for HoldEmGame class for dealing logic
 */

#include "HoldEmGame.h"
#include <stdexcept>
#include "util.h"

const size_t HOLDEM_HOLE_CARDS = 2;
const size_t HOLDEM_FLOP_CARDS = 3;
const size_t HOLDEM_TURN_CARDS = 1;
const size_t HOLDEM_RIVER_CARDS = 1;
const size_t HOLDEM_HAND_CARDS_PER_LINE = 2;
const size_t HOLDEM_BOARD_CARDS_PER_LINE = 5;
const std::string AFFIRMATIVE_RESPONSE = "yes";

HoldEmGame::HoldEmGame(int argc, const char * argv[]) : Game(argc, argv), state(HoldEmState::preflop)
{
    for (size_t i = 0; i < players.size(); i++)
    {
        hands.emplace_back();
    }
}

void HoldEmGame::deal()
{
    switch (state)
    {
        case HoldEmState::preflop:
            for (int round = 0; round < HOLDEM_HOLE_CARDS; round++)
            {
                for (auto& hand : hands)
                {
                    if (deck.is_empty())
                    {
                        throw std::runtime_error("deck empty during preflop deal.\n");
                    }
                    deck >> hand;
                }
            }
            state = HoldEmState::flop;
            break;

        case HoldEmState::flop:
            for (int i = 0; i < HOLDEM_FLOP_CARDS; i++)
            {
                if (deck.is_empty())
                {
                throw std::runtime_error("deck empty during flop.\n");
                }
                deck >> board;
            }
            state = HoldEmState::turn;
            break;

        case HoldEmState::turn:
            if (deck.is_empty())
            {
                throw std::runtime_error("deck empty during turn deal.\n");
            }
            deck >> board;
            state = HoldEmState::river;
            break;

        case HoldEmState::river:
            if (deck.is_empty())
            {
                throw std::runtime_error("deck empty during river deal.\n");
            }
            deck >> board;
            state = HoldEmState::undefined;
            break;

        case HoldEmState::undefined:
            break;
    }
}

void HoldEmGame::printHands() const
{
    for (size_t i = 0; i < players.size(); i++)
    {
        std::cout << players[i] << "'s hand: ";
        hands[i].print(std::cout, HOLDEM_HAND_CARDS_PER_LINE);
    }
}

void HoldEmGame::printBoard(const std::string& label) const
{
    std::cout << "BOARD (" << label << "): ";
    board.print(std::cout, HOLDEM_BOARD_CARDS_PER_LINE);
    std::cout << std::endl;
}

void HoldEmGame::collectAll()
{
    for (auto& hand : hands)
    {
        deck.collect(hand);
    }
    deck.collect(board);
}

int HoldEmGame::play()
{
    while (true)
    {
        deck.shuffle();
        state = HoldEmState::preflop;

        deal();
        printHands();

        deal();
        printBoard("flop");

        deal();
        printBoard("turn");
    
        deal();
        printBoard("river");

        collectAll();

        std::cout << "end the game? (yes/no): ";
        std::string res;
        std::cin >> res;

        if (res == AFFIRMATIVE_RESPONSE)
        {
            return ExitCode::Success;
        }
    }
}

