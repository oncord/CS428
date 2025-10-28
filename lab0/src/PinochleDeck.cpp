#include "PinochleDeck.h"
#include <iostream>

const int PINOCHLE_CUTOFF = 8;

// output stream operator for PinochleRank
std::ostream& operator<<(std::ostream& os, const PinochleRank& rank) {
    switch(rank) {
        case PinochleRank::nine:
            os << "9";
            break;
        case PinochleRank::jack:
            os << "J";
            break;
        case PinochleRank::queen:
            os << "Q";
            break;
        case PinochleRank::king:
            os << "K";
            break;
        case PinochleRank::ten:
            os << "10";
            break;
        case PinochleRank::ace:
            os << "A";
            break;
        case PinochleRank::undefined:
        default:
            os << "?";
            break;
    }

    return os;
}

// prefix increment operator for PinochleRank
PinochleRank& operator++(PinochleRank& rank) {
    // type casting to int to compare
    if (static_cast<int>(rank) < static_cast<int>(PinochleRank::undefined)) {
        rank = static_cast<PinochleRank>(static_cast<int>(rank) + 1);
    }

    return rank;
}

// PinochleDeck constructor that creates two of each valid card
PinochleDeck::PinochleDeck() {
    // iterate through all valid ranks and suits
    for (PinochleRank rank = PinochleRank::nine; rank != PinochleRank::undefined; ++rank) {
        for (Suit suit = Suit::clubs; suit != Suit::undefined; ++suit) {
            // add two cards of each rank/suit combination
            cards.push_back(Card<PinochleRank, Suit>(rank, suit));
            cards.push_back(Card<PinochleRank, Suit>(rank, suit));
        }
    }
}

// print method 
void PinochleDeck::print(std::ostream& os) {
    int cardCount = 0;
    for (const auto& card : cards) {
        os << card << " ";
        cardCount++;
        // add line break every 8 cards 
        if (cardCount % PINOCHLE_CUTOFF == 0) {
            os << std::endl;
        }
    }
    // add final newline if the last line not complete
    if (cardCount % PINOCHLE_CUTOFF != 0) {
        os << std::endl;
    }
}
