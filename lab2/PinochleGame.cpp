/*
 *  PinochleGame.cpp
 *  Author: Richard Meyer
 *  Definitions for PinochleGame class implementing Pinochle dealing logic
 */

#include "PinochleGame.h"
#include <iostream>
#include <array>
#include <stdexcept>
#include <map>
#include <algorithm>
#include "util.h"

const size_t PINOCHLE_PACKET_SIZE = 3;
const size_t PINOCHLE_CARDS_PER_LINE = 8;
const std::string AFFIRMATIVE_RESPONSE = "yes";

const std::array<unsigned int, 15> PinochleGame::meldPoints = {
    10, 
    20,
    40,
    40,
    40,
    60,
    80,
    100,
    150,
    300,
    400,
    600,
    800,
    1000,
    1500,
};

void PinochleGame::suit_independent_evaluation(const CardSet<PinochleRank, Suit>& hand, std::vector<PinochleMelds>& melds) const
{
    // deep copy of player's hand
    CardSet<PinochleRank, Suit> copy(hand);

    // sort local copy by rank then suit
    std::sort(copy.begin(), copy.end(), cardRankLess<PinochleRank, Suit>);

    // count occurences
    std::map<PinochleRank, std::map<Suit, int>> count;
    for (const auto &card : *CardSet<PinochleRank, Suit>::access(copy))
    {
        count[card.rank][card.suit]++;
    }

    // helper lambdas check meld patterns
    auto hasAllRanks = [&](PinochleRank rank, int countPerSuit)
    {
        return count[rank][Suit::clubs] >= countPerSuit &&
               count[rank][Suit::diamonds] >= countPerSuit &&
               count[rank][Suit::hearts] >= countPerSuit &&
               count[rank][Suit::spades] >= countPerSuit;
    };

    bool has_thousand_aces = false;
    bool has_eighthundred_kings = false;
    bool has_sixhundred_queens = false;
    bool has_fourhundred_jacks = false;
    bool has_double_pinochle = false;
    
    // Thousand Aces
    if (hasAllRanks(PinochleRank::ace, 2)) {
        melds.push_back(PinochleMelds::thousandaces);
        has_thousand_aces = true;
    }

    // Hundred Aces (only if thousandaces not found)
    if (!has_thousand_aces && hasAllRanks(PinochleRank::ace, 1)) {
        melds.push_back(PinochleMelds::hundredaces);
    }

    // Eight Hundred Kings
    if (hasAllRanks(PinochleRank::king, 2)) {
        melds.push_back(PinochleMelds::eighthundredkings);
        has_eighthundred_kings = true;
    }

    // Eighty Kings
    if (!has_eighthundred_kings && hasAllRanks(PinochleRank::king, 1)) {
        melds.push_back(PinochleMelds::eightykings);
    }

    // Six Hundred Queens
    if (hasAllRanks(PinochleRank::queen, 2)) {
        melds.push_back(PinochleMelds::sixhundredqueens);
        has_sixhundred_queens = true;
    }

    // Sixty Queens
    if (!has_sixhundred_queens && hasAllRanks(PinochleRank::queen, 1)) {
        melds.push_back(PinochleMelds::sixtyqueens);
    }

    // Four Hundred Jacks
    if (hasAllRanks(PinochleRank::jack, 2)) {
        melds.push_back(PinochleMelds::fourhundredjacks);
        has_fourhundred_jacks = true;
    }

    // Forty Jacks
    if (!has_fourhundred_jacks && hasAllRanks(PinochleRank::jack, 1)) {
        melds.push_back(PinochleMelds::fortyjacks);
    }

    // Double Pinochle (JfJf Q`Q`)
    if (count[PinochleRank::jack][Suit::diamonds] >= 2 &&
        count[PinochleRank::queen][Suit::spades] >= 2)
    {
        melds.push_back(PinochleMelds::doublepinochle);
        has_double_pinochle = true;
    }

    // Single Pinochle (Jf Q`)
    if (!has_double_pinochle &&
        count[PinochleRank::jack][Suit::diamonds] >= 1 &&
        count[PinochleRank::queen][Suit::spades] >= 1)
    {
        melds.push_back(PinochleMelds::pinochle);
    }
}

std::ostream& operator<<(std::ostream& os, const PinochleMelds& meld)
{
    static const std::array<std::string, 15> meldNames = {
        "dix",
        "offsuitmarriage",
        "fortyjacks",
        "pinochle",
        "insuitmarriage",
        "sixtyqueens",
        "eightykings",
        "hundredaces",
        "insuitrun",
        "doublepinochle",
        "fourhundredjacks",
        "sixhundredqueens",
        "eighthundredkings",
        "thousandaces",
        "insuitdoublerun"
    };

    size_t index = static_cast<size_t>(meld);

    if (index < meldNames.size())
    {
        os << meldNames[index] << " " << PinochleGame::meldPoints[index];
    }
    else
    {
        os << "UnknownMeld 0";
    }

    return os;
}

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
        for (size_t i = 0; i < PINOCHLE_PACKET_SIZE && !deck.is_empty(); i++)
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
            
            for (size_t i = 0; i < players.size(); i++)
            {
                std::cout << players[i] << "'s hand:" << std::endl;
                hands[i].print(std::cout, PINOCHLE_CARDS_PER_LINE);
                std::cout << std::endl;

                std::vector<PinochleMelds> melds;

                suit_independent_evaluation(hands[i], melds);

                if (!melds.empty())
                {
                    std::cout << "Melds found:" << std::endl;
                    for (size_t j = 0; j < melds.size(); j++)
                    {
                        std::cout << " " << melds[j];
                        if (j != melds.size() - 1)
                        {
                            std::cout << std::endl;
                        }
                    }
                }
                else
                {
                    std::cout << "No melds found.";
                }

                std::cout << std::endl << std::endl;
            }

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
