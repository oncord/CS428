#include "HoldEmDeck.h"
#include <iostream>

// output stream operator for HoldEmRank
std::ostream& operator<<(std::ostream& os, const HoldEmRank& rank) {
    switch(rank) {
        case HoldEmRank::two:
            os << "2";
            break;
        case HoldEmRank::three:
            os << "3";
            break;
        case HoldEmRank::four:
            os << "4";
            break;
        case HoldEmRank::five:
            os << "5";
            break;
        case HoldEmRank::six:
            os << "6";
            break;
        case HoldEmRank::seven:
            os << "7";
            break;
        case HoldEmRank::eight:
            os << "8";
            break;
        case HoldEmRank::nine:
            os << "9";
            break;
        case HoldEmRank::ten:
            os << "10";
            break;
        case HoldEmRank::jack:
            os << "J";
            break;
        case HoldEmRank::queen:
            os << "Q";
            break;
        case HoldEmRank::king:
            os << "K";
            break;
        case HoldEmRank::ace:
            os << "A";
            break;
        case HoldEmRank::undefined:
        default:
            os << "?";
            break;
    }
    return os;
}

// prefix increment operator for HoldEmRank
HoldEmRank& operator++(HoldEmRank& rank) {
    if (static_cast<int>(rank) < static_cast<int>(HoldEmRank::undefined)) {
        rank = static_cast<HoldEmRank>(static_cast<int>(rank) + 1);
    }
    return rank;
}

// HoldEmDeck constructor that creates one of each valid card
HoldEmDeck::HoldEmDeck() {
    // iterate through all valid ranks and suits
    for (HoldEmRank rank = HoldEmRank::two; rank != HoldEmRank::undefined; ++rank) {
        for (Suit suit = Suit::clubs; suit != Suit::undefined; ++suit) {
            // add one card of each rank/suit combination
            cards.push_back(Card<HoldEmRank, Suit>(rank, suit));
        }
    }
}

// print method 
void HoldEmDeck::print(std::ostream& os) {
    int cardCount = 0;
    for (const auto& card : cards) {
        os << card << " ";
        cardCount++;
        // add line break every 13 cards 
        if (cardCount % 13 == 0) {
            os << std::endl;
        }
    }
    // add final newline if the last line not complete
    if (cardCount % 13 != 0) {
        os << std::endl;
    }
}
