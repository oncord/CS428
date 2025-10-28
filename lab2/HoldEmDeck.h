#ifndef HOLDEMDECK_H
#define HOLDEMDECK_H

#include <iostream>
#include <vector>
#include "deck.h"
#include "card.h"
#include "suits.h"

// enum class for Texas Hold'em card ranks
enum class HoldEmRank {
    two,        // 0
    three,      // 1
    four,       // 2
    five,       // 3
    six,        // 4
    seven,      // 5
    eight,      // 6
    nine,       // 7
    ten,        // 8
    jack,       // 9
    queen,      // 10
    king,       // 11
    ace,        // 12
    undefined   // 13 -> MAX
};

// output stream operator for HoldEmRank
std::ostream& operator<<(std::ostream& os, const HoldEmRank& rank);

// prefix increment operator for HoldEmRank
HoldEmRank& operator++(HoldEmRank& rank);

// Texas Hold'em deck class
class HoldEmDeck : public Deck<HoldEmRank, Suit> {
public:
    // default constructor that creates one of each valid card
    HoldEmDeck();
};

#endif // HOLDEMDECK_H
