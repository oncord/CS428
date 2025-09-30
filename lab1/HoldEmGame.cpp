#include "HoldEmGame.h"
#include <stdexcept>
#include "util.h"

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
            for (int round = 0; round < 2; round++)
            {
                for (auto& hand : hands)
                {
                    deck >> hand;
                }
            }
            state = HoldEmState::flop;
            break;
        case HoldEmState::flop:
            for (int i = 0; i < 3; i++)
            {
                deck >> board;
            }
            state = HoldEmState::turn;
            break;
        case HoldEmState::turn:
            deck >> board;
            state = HoldEmState::river;
            break;
        case HoldEmState::river:
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
        hands[i].print(std::cout, 2);
    }
}

void HoldEmGame::printBoard(const std::string& label) const
{
    std::cout << "BOARD (" << label << "): ";
    board.print(std::cout, 5);
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

        if (res == "yes")
        {
            return ExitCode::Success;
        }
    }
}

