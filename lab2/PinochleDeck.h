#ifndef PINOCHLEDECK_H
#define PINOCHLEDECK_H

#include <iostream>
#include <vector>
#include "deck.h"
#include "card.h"
#include "suits.h"

// enum class for Pinochle card ranks
enum class PinochleRank {
    nine,       // 0
    jack,       // 1
    queen,      // 2
    king,       // 3
    ten,        // 4
    ace,        // 5
    undefined   // 6 -> MAX
};

// output stream operator for PinochleRank
std::ostream& operator<<(std::ostream& os, const PinochleRank& rank);

// prefix increment operator for PinochleRank
PinochleRank& operator++(PinochleRank& rank);

class PinochleDeck : public Deck<PinochleRank, Suit> {
public:
    // default constructor that creates two of each valid card
    PinochleDeck();
};

#endif // PINOCHLEDECK_H
